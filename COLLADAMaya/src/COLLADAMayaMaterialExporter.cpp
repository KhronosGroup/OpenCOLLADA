/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaMaterialExporter.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaConversion.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaHwShaderExporter.h"

#include "COLLADASWNode.h"
#include "COLLADASWParamTemplate.h"
#include "COLLADASWConstants.h"


#include <maya/MItMeshPolygon.h>
#include <maya/MItDag.h>
#include <maya/MFnSet.h>
#include <maya/MFnMesh.h>

#if defined(WIN64) && MAYA_API_VERSION >= 201600 && !defined(WIN32)
/* define WIN32 to work around CFGX WIN64 compilation */
#define WIN32
#endif

#include "cgfxShaderNode.h"

#include <cgfxFindImage.h>

namespace COLLADAMaya
{

	MaterialExporter::SidSet MaterialExporter::mSurfaceSidList;

    //---------------------------------------------------------------
    MaterialExporter::MaterialExporter ( COLLADASW::StreamWriter* streamWriter,
                                         DocumentExporter* documentExporter )
            : COLLADASW::LibraryMaterials ( streamWriter ),
            mDocumentExporter ( documentExporter ),
            mExportedMaterials ( NULL ),
            mWriteMaterials ( false ),
            materialMapInitialized ( false )
    {}

    //---------------------------------------------------------------
    MaterialMap* MaterialExporter::exportMaterials ( bool writeMaterials )
    {
        mWriteMaterials = writeMaterials;

        // Should we only export the selected elements?
        bool exportSelectedOnly = mDocumentExporter->getExportSelectedOnly ();

        // Should we only export the referenced (used) materials?
        bool exportReferencedOnly = ExportOptions::exportReferencedMaterials ();

        if ( !exportSelectedOnly && !exportReferencedOnly ) 
        {
            // Get all shaders, which are in the default shader list.
            // Unfortunately, you will not get the default initialShadingGroup elements, which are
            // directly connected to an object, if no other material (shader) is connected to the object.
            exportMaterialsByShaderPlug ();
        }

        // Now go through scene graph and find all shaders, connected to the meshes.
        // So you can find the default shaders of an object.
        exportMaterialsBySceneGraph ();

        // Set the flag, that the material std::map is initialised
        materialMapInitialized = true;

        // Close the tags in the collada document
        closeLibrary();

        // Return the material list
        return &mMaterialMap;
    }

    //------------------------------------------------------
    void MaterialExporter::exportMaterialsByShaderPlug()
    {
        // Get all shaders, which are in the default shader list.
        MObject defaultShaderList = DagHelper::getNode ( ATTR_DEFAULT_SHADER_LIST1 );
        MPlug defaultShadersPlug = MFnDependencyNode ( defaultShaderList ).findPlug ( ATTR_SHADERS );

        uint shaderCount = defaultShadersPlug.evaluateNumElements();
        for ( uint i = 0; i < shaderCount; ++i )
        {
            MObject shader = DagHelper::getNodeConnectedTo ( defaultShadersPlug.elementByPhysicalIndex ( i ) );
            MFnDependencyNode shadingEngineFn ( shader );

            // Get the name of the current material (this is the maya material id)
            String mayaMaterialId = DocumentExporter::mayaNameToColladaName ( shadingEngineFn.name(), true );

            bool doExportMaterial = true;
            bool isFromReferencedFile = shadingEngineFn.isFromReferencedFile();
//            bool isDefaulNode = shadingEngineFn.isDefaultNode();
//             if ( isDefaulNode ) 
//             {
//                 doExportMaterial = false;
//             }
//             else if ( isFromReferencedFile )
            if ( isFromReferencedFile )
            {
                if ( ExportOptions::exportXRefs() && ExportOptions::dereferenceXRefs() ) doExportMaterial = true;
                else doExportMaterial = false;
            }

            if ( doExportMaterial )
            {
                MObject shadingEngine = ShaderHelper::getShadingEngine ( shader );
                exportMaterial ( shadingEngine );
            }
        }
    }

    //------------------------------------------------------
    void MaterialExporter::exportMaterialsBySceneGraph ()
    {
        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Now go through scene graph and find all shaders, connected to the meshes.
        // So you can find the default shaders of an object.
        size_t length = exportNodesTree->size();
        for ( size_t i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            if ( !sceneElement->getIsLocal() ) continue;
            if ( !sceneElement->getIsExportNode () ) continue;

            size_t childCount = sceneElement->getChildCount();
            for ( size_t i=0; i<childCount; ++i )
            {
                SceneElement* childSceneElement = sceneElement->getChild ( i );

                exportConnectedMaterials ( childSceneElement );
            }
        }
    }

    //------------------------------
    void MaterialExporter::exportConnectedMaterials ( SceneElement* sceneElement )
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;
        if ( !sceneElement->getIsExportNode () ) return;

        // Check if it is a mesh object and an export node
        if ( sceneElement->getType() == SceneElement::MESH )
        {
            MDagPath dagPath = sceneElement->getPath();

            // Attach a function set
            MStatus status;
            MFnMesh fnMesh ( dagPath.node(), &status );
            if ( status != MStatus::kSuccess ) return;

            // Find how many shaders are used by this instance of the mesh
            MObjectArray shaders;
            MIntArray shaderIndices;
            unsigned instanceNumber = dagPath.instanceNumber();
            fnMesh.getConnectedShaders ( instanceNumber, shaders, shaderIndices );

            // Find the polygons that correspond to each materials and export them
            uint realShaderCount = ( uint ) shaders.length();
            uint numShaders = ( uint ) std::max ( ( size_t ) 1, ( size_t ) shaders.length() );
            for ( uint shaderPosition = 0; shaderPosition < numShaders; ++shaderPosition )
            {
                if ( shaderPosition < realShaderCount )
                {
                    // Add shader-specific parameters (TexCoords sets).
                    // Add symbolic name for the material used on this polygon set.
                    MObject shadingEngine = shaders[shaderPosition];
                    exportMaterial ( shadingEngine );
                }
            }
        }

        // recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportConnectedMaterials ( childElement );
        }
    }

    //--------------------------------
    void MaterialExporter::exportMaterial ( MObject shadingEngine )
    {
        // Get the shader object.
        MObject shader = DagHelper::getSourceNodeConnectedTo ( shadingEngine, ATTR_SURFACE_SHADER );

        // Find the actual shader node, since this function received shading sets as input
        MStatus status;
        MFnDependencyNode shaderNode ( shader, &status );
        if ( status != MStatus::kSuccess ) return;

        // Get the name of the current material (this is the maya material id)
        String mayaMaterialId = DocumentExporter::mayaNameToColladaName ( shaderNode.name(), true );

        // Have we seen this shader before, is it already exported?
        MaterialMap::iterator materialMapIter;
        materialMapIter = mMaterialMap.find ( mayaMaterialId );
        if ( materialMapIter != mMaterialMap.end() ) return;

        // This is a new shading engine
        mMaterialMap [mayaMaterialId] = shader;

        // Generate a COLLADA id for the new object
        String colladaMaterialId;

        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( shader, COLLADA_MATERIAL_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            colladaMaterialId = DocumentExporter::mayaNameToColladaName ( attributeValue, false );
        }
        else
        {
            // Generate a COLLADA id for the new object
            colladaMaterialId = DocumentExporter::mayaNameToColladaName ( shaderNode.name(), true );
        }
        // Make the id unique and store it.
        colladaMaterialId = mMaterialIdList.addId ( colladaMaterialId );
        mMayaIdColladaMaterialIdMap [mayaMaterialId] = colladaMaterialId;

//         MFnDependencyNode shadingEngineNode ( shadingEngine, &status );
//         if ( status != MStatus::kSuccess ) return;
//         String shadingEngineNodeName = shadingEngineNode.name ().asChar (); // initialParticleSE
//         String shaderNodeName = shaderNode.name ().asChar (); // lambert1
       
        // Check if the material should be written
        if ( mWriteMaterials )
        {
            // Have we exported this shader already?
            std::vector<String>::iterator exportedMaterialsIter;
            exportedMaterialsIter = find ( mExportedMaterials.begin(), mExportedMaterials.end(), colladaMaterialId );

            if ( exportedMaterialsIter == mExportedMaterials.end() )
            {
                // Open a tag for the current material in the collada document
                openMaterial ( colladaMaterialId, mayaMaterialId );

                // Export the reference to the effect and the hardware shader components.
                exportEffectInstance ( mayaMaterialId, colladaMaterialId, shader );

//                 // TODO Export the user defined material extra data from import (extra preservation).
//                 mDocumentExporter->exportExtraData ( shader, COLLADAFW::ExtraKeys::MATERIAL );

                // Closes the current effect tag
                closeMaterial();

                // Push the id of the exported material into the list for the exported materials
                mExportedMaterials.push_back ( colladaMaterialId );
            }
        }
    }

    //---------------------------------------
    MaterialMap* MaterialExporter::getExportedMaterialsMap()
    {
        if ( !materialMapInitialized ) exportMaterials ( false );

        return &mMaterialMap;
    }

    //---------------------------------------
    void MaterialExporter::setSetParam ( const cgfxShaderNode* shaderNodeCgfx, const cgfxAttrDef* attribute )
    {
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        String attributeName = attribute->fName.asChar();

        cgfxAttrDef::cgfxAttrType attributeType = attribute->fType;
        switch ( attributeType )
        {
        case cgfxAttrDef::kAttrTypeBool:
            {
				if (attribute->fNumericDef)
				{
					COLLADASW::SetParamBool setParam ( streamWriter );
					setParam.openParam ( attributeName );
					setParam.appendValues ( attribute->fNumericDef[0] != 0.0 );
					setParam.closeParam ();
				}
                break;
            }
        case cgfxAttrDef::kAttrTypeInt:
            {
				if (attribute->fNumericDef)
				{
					COLLADASW::SetParamInt setParam(streamWriter);
					setParam.openParam(attributeName);
					setParam.appendValues(static_cast<int>(attribute->fNumericDef[0]));
					setParam.closeParam();
				}
                break;
            }
        case cgfxAttrDef::kAttrTypeString:
            {
				MGlobal::displayWarning(("CG String Parameter type: ") + MString(attributeName.c_str()) + MString(" not supported!")  );

				/*
				if (attribute->fStringDef.length() > 0)
				{
					COLLADASW::SetParamString setParam(streamWriter);
					setParam.openParam(attributeName);
					setParam.appendValues(String(attribute->fStringDef.asChar()));
					setParam.closeParam();
				}
                break;
				*/
            }
        case cgfxAttrDef::kAttrTypeFloat:
            {
				if (attribute->fNumericDef)
				{
					COLLADASW::SetParamFloat setParam(streamWriter);
					setParam.openParam(attributeName);
					setParam.appendValues(attribute->fNumericDef[0]);
					setParam.closeParam();
				}
                break;
            }
        case cgfxAttrDef::kAttrTypeVector2:
            {
				if (attribute->fNumericDef)
				{
					COLLADASW::SetParamFloat2 setParam(streamWriter);
					setParam.openParam(attributeName);
					for (int i = 0; i < attribute->fSize; ++i)
					{
						setParam.appendValues(attribute->fNumericDef[i]);
					}
					setParam.closeParam();
				}
                break;
            }
        case cgfxAttrDef::kAttrTypeVector3:
        case cgfxAttrDef::kAttrTypeColor3:
            {
				if (attribute->fNumericDef)
				{
					COLLADASW::SetParamFloat3 setParam ( streamWriter );
					setParam.openParam ( attributeName );
					for ( int i=0; i<attribute->fSize; ++i )
					{
						setParam.appendValues(attribute->fNumericDef[i]);
					}
					setParam.closeParam();
				}
                break;
            }
        case cgfxAttrDef::kAttrTypeVector4:
        case cgfxAttrDef::kAttrTypeColor4:
            {
				if (attribute->fNumericDef)
				{
					COLLADASW::SetParamFloat4 setParam(streamWriter);
					setParam.openParam(attributeName);
					for (int i = 0; i < attribute->fSize; ++i)
					{
						setParam.appendValues(attribute->fNumericDef[i]);
					}
					setParam.closeParam();
				}
                break;
            }
        case cgfxAttrDef::kAttrTypeWorldDir:
        case cgfxAttrDef::kAttrTypeWorldPos:
            {
				if (attribute->fNumericDef)
				{
					// Read the value
					double tmp[4];
					for (int i = 0; i < attribute->fSize; ++i)
					{
						tmp[i] = attribute->fNumericDef[i];
					}
					if (attribute->fSize == 3) tmp[3] = 1.0;

					// Find the coordinate space, and whether it is a point or a vector
					int base = cgfxAttrDef::kAttrTypeFirstPos;
					if (attribute->fType <= cgfxAttrDef::kAttrTypeLastDir)
						base = cgfxAttrDef::kAttrTypeFirstDir;
					int space = attribute->fType - base;

					// Compute the transform matrix
					MMatrix mat;
					switch (space)
					{
						/* case 0:	object space, handled in view dependent method */
					case 1:	/* world space  - do nothing, identity */ break;
						/* case 2: eye space, unsupported yet */
						/* case 3: clip space, unsupported yet */
						/* case 4: screen space, unsupported yet */
					}

					if (base == cgfxAttrDef::kAttrTypeFirstPos)
					{
						MPoint point(tmp[0], tmp[1], tmp[2], tmp[3]);
						point *= mat;
						tmp[0] = point.x;
						tmp[1] = point.y;
						tmp[2] = point.z;
						tmp[3] = point.w;
					}
					else
					{
						MVector vec(tmp[0], tmp[1], tmp[2]);
						vec *= mat;
						tmp[0] = vec.x;
						tmp[1] = vec.y;
						tmp[2] = vec.z;
						tmp[3] = 1;
					}

					COLLADASW::SetParamFloat4 setParam(streamWriter);
					setParam.openParam(attributeName);
					setParam.appendValues(tmp[0], tmp[1], tmp[2], tmp[3]);
					setParam.closeParam();
				}
                break;
            }
        case cgfxAttrDef::kAttrTypeMatrix:
        case cgfxAttrDef::kAttrTypeWorldMatrix:
        case cgfxAttrDef::kAttrTypeViewMatrix:
        case cgfxAttrDef::kAttrTypeProjectionMatrix:
        case cgfxAttrDef::kAttrTypeWorldViewMatrix:
        case cgfxAttrDef::kAttrTypeWorldViewProjectionMatrix:
            {
				if (attribute->fNumericDef)
				{
					COLLADASW::SetParamFloat4x4 setParam(streamWriter);
					setParam.openParam(attributeName);

					MMatrix mayaMatrix;
					double* p = &mayaMatrix.matrix[0][0];
					for (int k = 0; k < attribute->fSize; ++k)
					{
						p[k] = attribute->fNumericDef[k];
					}

					MMatrix wMatrix, vMatrix, pMatrix, sMatrix;
					MMatrix wvMatrix, wvpMatrix, wvpsMatrix;
					{
						float tmp[4][4];

						wMatrix.setToIdentity();

						glGetFloatv(GL_MODELVIEW_MATRIX, &tmp[0][0]);
						wvMatrix = MMatrix(tmp);

						vMatrix = wMatrix.inverse() * wvMatrix;

						glGetFloatv(GL_PROJECTION_MATRIX, &tmp[0][0]);
						pMatrix = MMatrix(tmp);

						wvpMatrix = wvMatrix * pMatrix;

						float vpt[4];
						float depth[2];

						glGetFloatv(GL_VIEWPORT, vpt);
						glGetFloatv(GL_DEPTH_RANGE, depth);

						// Construct the NDC -> screen space matrix
						//
						float x0, y0, z0, w, h, d;

						x0 = vpt[0];
						y0 = vpt[1];
						z0 = depth[0];
						w = vpt[2];
						h = vpt[3];
						d = depth[1] - z0;

						// Make a reference to ease the typing
						//
						double* s = &sMatrix.matrix[0][0];

						s[0] = w / 2;	s[1] = 0.0;	s[2] = 0.0;	s[3] = 0.0;
						s[4] = 0.0;	s[5] = h / 2;	s[6] = 0.0;	s[7] = 0.0;
						s[8] = 0.0;	s[9] = 0.0;	s[10] = d / 2;	s[11] = 0.0;
						s[12] = x0 + w / 2;	s[13] = y0 + h / 2;	s[14] = z0 + d / 2;	s[15] = 1.0;

						wvpsMatrix = wvpMatrix * sMatrix;
					}

					switch (attribute->fType)
					{
					case cgfxAttrDef::kAttrTypeWorldMatrix:
						mayaMatrix = wMatrix; break;
					case cgfxAttrDef::kAttrTypeViewMatrix:
						mayaMatrix = vMatrix; break;
					case cgfxAttrDef::kAttrTypeProjectionMatrix:
						mayaMatrix = pMatrix; break;
					case cgfxAttrDef::kAttrTypeWorldViewMatrix:
						mayaMatrix = wvMatrix; break;
					case cgfxAttrDef::kAttrTypeWorldViewProjectionMatrix:
						mayaMatrix = wvpMatrix; break;
					default:
						break;
					}

					if (attribute->fInvertMatrix)
						mayaMatrix = mayaMatrix.inverse();

					if (!attribute->fTransposeMatrix)
						mayaMatrix = mayaMatrix.transpose();

					double matrix[4][4];
					convertMayaMatrixToTransposedDouble4x4(matrix, mayaMatrix, getTolerance());
					setParam.appendValues(matrix);
					setParam.closeParam();
				}
                break;
            }
        case cgfxAttrDef::kAttrTypeColor1DTexture:
        case cgfxAttrDef::kAttrTypeColor2DTexture:
        case cgfxAttrDef::kAttrTypeColor3DTexture:
        case cgfxAttrDef::kAttrTypeColor2DRectTexture:
        case cgfxAttrDef::kAttrTypeNormalTexture:
        case cgfxAttrDef::kAttrTypeBumpTexture:
        case cgfxAttrDef::kAttrTypeCubeTexture:
        case cgfxAttrDef::kAttrTypeEnvTexture:
        case cgfxAttrDef::kAttrTypeNormalizationTexture:
            {
                CGparameter cgParameter = attribute->fParameterHandle;
                HwShaderExporter hwShaderExporter ( mDocumentExporter );
                hwShaderExporter.setShaderFxFileUri ( getShaderFxFileUri () );

                MObject shaderNode = shaderNodeCgfx->thisMObject();
                hwShaderExporter.exportSampler ( shaderNode, cgParameter, false );


                // -------------------------------
//                 String imageName = attribute->fStringDef.asChar();
// 
//                 MObject oNode = shaderNodeCgfx->thisMObject();
//                 MFnDependencyNode oNodeFn ( oNode );
//                 String oNodeName = oNodeFn.name().asChar(); // cgfxShader1
// 
//                 MPlug plug;
//                 if ( DagHelper::getPlugConnectedTo( oNode, attributeName, plug ) )
//                 {
//                     String plugName = plug.name().asChar(); // file1.outColor
//                     MObject textureNode = plug.node();
// 
//                     //COLLADASW::Surface::SurfaceType surfaceType;
//                     COLLADASW::Sampler::SamplerType samplerType;
//                     COLLADASW::ValueType::ColladaType samplerValueType;
// 
//                     switch ( attributeType )
//                     {
//                     case cgfxAttrDef::kAttrTypeColor1DTexture:
//                         //surfaceType = COLLADASW::Surface::SURFACE_TYPE_1D;
//                         samplerType = COLLADASW::Sampler::SAMPLER_TYPE_1D;
//                         samplerValueType = COLLADASW::ValueType::SAMPLER_1D;
//                         break;
//                     case cgfxAttrDef::kAttrTypeColor2DTexture:
//                     case cgfxAttrDef::kAttrTypeNormalTexture:
//                     case cgfxAttrDef::kAttrTypeBumpTexture:
//                         //surfaceType = COLLADASW::Surface::SURFACE_TYPE_2D;
//                         samplerType = COLLADASW::Sampler::SAMPLER_TYPE_2D;
//                         samplerValueType = COLLADASW::ValueType::SAMPLER_2D;
//                         break;
//                     case cgfxAttrDef::kAttrTypeColor3DTexture:
//                         //surfaceType = COLLADASW::Surface::SURFACE_TYPE_3D;
//                         samplerType = COLLADASW::Sampler::SAMPLER_TYPE_3D;
//                         samplerValueType = COLLADASW::ValueType::SAMPLER_3D;
//                         break;
//                     case cgfxAttrDef::kAttrTypeColor2DRectTexture:
//                         //surfaceType = COLLADASW::Surface::SURFACE_TYPE_RECT;
//                         samplerType = COLLADASW::Sampler::SAMPLER_TYPE_RECT;
//                         samplerValueType = COLLADASW::ValueType::SAMPLER_RECT;
//                         break;
//                     case cgfxAttrDef::kAttrTypeCubeTexture:
//                     case cgfxAttrDef::kAttrTypeEnvTexture:
//                     case cgfxAttrDef::kAttrTypeNormalizationTexture:
//                         //surfaceType = COLLADASW::Surface::SURFACE_TYPE_CUBE;
//                         samplerType = COLLADASW::Sampler::SAMPLER_TYPE_CUBE;
//                         samplerValueType = COLLADASW::ValueType::SAMPLER_CUBE;
//                         break;
//                     default:
//                         //surfaceType = COLLADASW::Surface::SURFACE_TYPE_UNTYPED;
//                         samplerType = COLLADASW::Sampler::SAMPLER_TYPE_UNSPECIFIED;
//                         samplerValueType = COLLADASW::ValueType::VALUE_TYPE_UNSPECIFIED;
//                     }
// 
//                     // Write the params elements
//                     setSetParamTexture ( attribute, textureNode, samplerType, samplerValueType );
//                }
            }
        }
    }

    //---------------------------------------
    void MaterialExporter::setSetParamTexture (
        const cgfxAttrDef* attribute, 
        MObject texture, 
        COLLADASW::Sampler::SamplerType samplerType, 
        COLLADASW::ValueType::ColladaType samplerValueType )
    {
        // Get a pointer to the current stream writer.
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the image id
        MFnDependencyNode textureNode ( texture );
        String plugName = textureNode.name().asChar(); // file1

        // Get the file texture name
        MPlug filenamePlug = textureNode.findPlug ( ATTR_FILE_TEXTURE_NAME );
        MString mayaFileName;
        filenamePlug.getValue ( mayaFileName );
        if ( mayaFileName.length() == 0 ) return;
        String fileName = mayaFileName.asChar ();
        
        // Get the image path
        // Take the filename for the unique image name 
        COLLADASW::URI sourceFileUri(COLLADASW::URI::nativePathToUri(fileName));
        if ( sourceFileUri.getScheme ().empty () )
            sourceFileUri.setScheme ( COLLADASW::URI::SCHEME_FILE );
        String mayaImageId = DocumentExporter::mayaNameToColladaName ( sourceFileUri.getPathFileBase().c_str () );

        // Get the image id of the maya image 
        EffectExporter* effectExporter = mDocumentExporter->getEffectExporter ();
        String colladaImageId = effectExporter->findColladaImageId ( mayaImageId );
        if ( colladaImageId.empty () )
        {
            // Check if there is an extra attribute "colladaId" and use this as export id.
            MString attributeValue;
            DagHelper::getPlugValue ( texture, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
            if ( attributeValue != EMPTY_CSTRING )
            {
                // Generate a valid collada name, if necessary.
                colladaImageId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
            }
            else
            {
                // Generate a COLLADA id for the new light object
                colladaImageId = DocumentExporter::mayaNameToColladaName ( textureNode.name() );
            }
            // Make the id unique and store it in a map for refernences.
            EffectTextureExporter* textureExporter = effectExporter->getTextureExporter ();
            colladaImageId = textureExporter->getImageIdList ().addId ( colladaImageId );
            textureExporter->getMayaIdColladaImageId () [mayaImageId] = colladaImageId;
        }

        // Export the image
        EffectTextureExporter* textureExporter = mDocumentExporter->getEffectExporter()->getTextureExporter();
        COLLADASW::Image* colladaImage = textureExporter->exportImage ( mayaImageId, colladaImageId, sourceFileUri );
        mayaImageId = colladaImage->getImageId();

        // Create the sampler and surface sid
        String samplerSid = mayaImageId + COLLADASW::Sampler::SAMPLER_SID_SUFFIX;
        String surfaceSid = mayaImageId + COLLADASW::Sampler::SURFACE_SID_SUFFIX;

        // Avoid export of dublicate sampler params
        if ( mSamplers.find ( samplerSid ) != mSamplers.end () ) return;
        mSamplers.insert ( samplerSid );

        // Create the sampler and add the sampler <setparam>
        COLLADASW::Sampler sampler ( samplerType, samplerSid, surfaceSid );
        sampler.setFormat ( EffectTextureExporter::FORMAT );
        sampler.setImageId ( colladaImage->getImageId() );
        sampler.addInSetParam ( streamWriter );
    }

    //---------------------------------------
    void MaterialExporter::exportCustomHwShaderNode( 
        COLLADASW::InstanceEffect &effectInstance, 
        MObject shader )
    {
        MFnDependencyNode fnNode ( shader );
        if ( fnNode.typeId() == cgfxShaderNode::sId ) 
        {
            // Add the technique hint and the effect attributes to the collada document.
            exportCgfxShaderNode ( effectInstance, (cgfxShaderNode*) fnNode.userNode () );
        }

    }

    //---------------------------------------
    void MaterialExporter::exportCgfxShaderNode ( 
        COLLADASW::InstanceEffect& effectInstance, 
        cgfxShaderNode* shaderNodeCgfx )
    {
        // Get the filename of the current cgfx file
		MString shaderFxFile = cgfxFindFile(shaderNodeCgfx->shaderFxFile());
        String shaderFxFileName = shaderFxFile.asChar(); // check3d.cgfx
        setShaderFxFileUri ( COLLADASW::URI ( COLLADASW::URI::nativePathToUri ( shaderFxFileName ) ) );

        // Get the current technique name
        String techniqueName = shaderNodeCgfx->getTechnique().asChar(); // techniqueName.asChar()

        // Add the technique hint to the collada document.
        effectInstance.addTechniqueHint ( techniqueName, COLLADASW::CSWC::CSW_PLATFORM_PC_OGL );

        // Clear the samplers setParam list.
        mSamplers.clear ();

#if MAYA_API_VERSION < 201200
        // Get the setParams attributes
        CGeffect cgEffect = shaderNodeCgfx->effect();
        CGtechnique cgTechnique = cgGetNamedTechnique( cgEffect, techniqueName.c_str() );
        cgfxAttrDefList* effectAttributes = cgfxAttrDef::attrsFromEffect ( cgEffect, cgTechnique );
        MString sResult, sTemp;
        cgfxAttrDefList::iterator effectIt;
        for ( effectIt=effectAttributes->begin(); effectIt; ++effectIt )
        {
            cgfxAttrDef* effectAttribute = *effectIt;
            setSetParam ( shaderNodeCgfx, effectAttribute );
        }
#else // MAYA_API_VERSION < 201200
        // Get the setParams attributes
        const cgfxRCPtr<const cgfxEffect>& cgEffect = shaderNodeCgfx->effect();
        if( cgEffect.isNull() )
        {
            MGlobal::displayError ( "cgEffect is null." );
            return;
        }

        cgfxRCPtr<cgfxAttrDefList> effectAttributes = cgEffect->attrsFromEffect();

        MString sResult, sTemp;
        cgfxAttrDefList::iterator effectIt;

		MaterialExporter::mSurfaceSidList.clear();

        for ( effectIt=effectAttributes->begin(); effectIt; ++effectIt )
        {
            cgfxAttrDef* effectAttribute = *effectIt;
            setSetParam ( shaderNodeCgfx, effectAttribute );
        }
#endif // MAYA_API_VERSION < 201200
    }

    // --------------------------------------
    void MaterialExporter::setShaderFxFileUri( const COLLADASW::URI& shaderFxFileName )
    {
        mShaderFxFileUri = shaderFxFileName;
    }

    // --------------------------------------
    const COLLADASW::URI& MaterialExporter::getShaderFxFileUri() const
    {
        return mShaderFxFileUri;
    }

    // --------------------------------------
    void MaterialExporter::exportEffectInstance ( 
        const String& mayaMaterialId, 
        const String& colladaMaterialId, 
        MObject &shader )
    {
        // Generate a COLLADA id for the new object
        String colladaEffectId;

        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( shader, COLLADA_EFFECT_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            colladaEffectId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
        }
        else
        {
            // Generate a COLLADA id for the new object
            colladaEffectId = colladaMaterialId + EffectExporter::EFFECT_ID_SUFFIX;
        }
        // Make the id unique and store it in a map.
        colladaEffectId = mEffectIdList.addId ( colladaEffectId );
        mMayaIdColladaEffectIdMap [ mayaMaterialId ] = colladaEffectId;

        // Create the effect instance
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        COLLADASW::InstanceEffect effectInstance ( streamWriter, COLLADASW::URI ( EMPTY_STRING, colladaEffectId ) );

        // Opens the current effect instance. 
        effectInstance.open();

        // Custom hardware shaders derived from MPxHardwareShader (the new stuff)
        if ( shader.hasFn ( MFn::kPluginHwShaderNode ) )
        {
            // Export the effect technique reference and the hardware shader parameters.
            exportCustomHwShaderNode ( effectInstance, shader );
        }

        // TODO
//         // Export the user defined instance_effect extra data from import (extra preservation).
//         mDocumentExporter->exportExtraData ( shader, COLLADAFW::ExtraKeys::INSTANCE_EFFECT );

        // Close the current effect element.
        effectInstance.close();
    }

    // --------------------------------------
    const String MaterialExporter::findColladaEffectId ( const String& mayaMaterialId )
    {
        const StringToStringMap::const_iterator it = mMayaIdColladaEffectIdMap.find ( mayaMaterialId );
        if ( it != mMayaIdColladaEffectIdMap.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }

    // --------------------------------------
    const String MaterialExporter::findColladaMaterialId ( const String& mayaMaterialId )
    {
        const StringToStringMap::const_iterator it = mMayaIdColladaMaterialIdMap.find ( mayaMaterialId );
        if ( it != mMayaIdColladaMaterialIdMap.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }


}
