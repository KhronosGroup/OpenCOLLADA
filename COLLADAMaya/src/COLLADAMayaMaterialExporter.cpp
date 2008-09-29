/*
    Copyright (c) 2008 NetAllied Systems GmbH

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

#include "COLLADANode.h"
#include "COLLADAParamTemplate.h"
#include "COLLADASWC.h"

#include "cgfxShaderNode.h"

#include <maya/MItMeshPolygon.h>
#include <maya/MItDag.h>
#include <maya/MFnSet.h>
#include <maya/MFnMesh.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    MaterialExporter::MaterialExporter ( COLLADA::StreamWriter* streamWriter,
                                         DocumentExporter* _documentExporter )
            : COLLADA::LibraryMaterials ( streamWriter ),
            mDocumentExporter ( _documentExporter ),
            mExportedMaterials ( NULL ),
            mWriteMaterials ( false ),
            materialMapInitialized ( false )
    {}

    //---------------------------------------------------------------
    MaterialMap* MaterialExporter::exportMaterials ( bool writeMaterials )
    {
        mWriteMaterials = writeMaterials;

        // Get all shaders, which are in the default shader list.
        // Unfortunately, you will not get the default initialShadingGroup elements, which are
        // directly connected to an object, if no other material (shader) is connected to the object.
        exportMaterialsByShaderPlug();

        // Now go through scene graph and find all shaders, connected to the meshes.
        // So you can find the default shaders of an object.
        exportMaterialsBySceneGraph();

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

            bool isFromReferencedFile = shadingEngineFn.isFromReferencedFile();
            bool isDefaulNode = shadingEngineFn.isDefaultNode();

            if ( !isFromReferencedFile && !isDefaulNode )
            {
                MObject shadingEngine = ShaderHelper::getShadingEngine ( shader );
                exportMaterial ( shadingEngine );
            }
        }
    }

    //------------------------------------------------------
    // Now go through scene graph and find all shaders, connected to the meshes.
    // So you can find the default shaders of an object.
    void MaterialExporter::exportMaterialsBySceneGraph()
    {
        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        size_t length = exportNodesTree->size();
        for ( size_t i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            const MDagPath dagPath = sceneElement->getPath();

            size_t childCount = sceneElement->getChildCount();
            for ( size_t i=0; i<childCount; ++i )
            {
                SceneElement* childSceneElement = sceneElement->getChild ( i );

                exportConnectedMaterials ( childSceneElement );
            }
        }
    }

    //---------------------------------------------------------------
    void MaterialExporter::exportConnectedMaterials ( SceneElement* sceneElement )
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;

        // Check if it is a mesh object and an export node
        if ( sceneElement->getType() == SceneElement::MESH &&
             sceneElement->getIsExportNode() )
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
            uint numShaders = ( uint ) max ( ( size_t ) 1, ( size_t ) shaders.length() );
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

    //---------------------------------------------------------------
    // Writes the material of the shading engine into the collada document
    // and adds the material into the materials list.
    //
    void MaterialExporter::exportMaterial ( MObject shadingEngine )
    {
        MObject shader = DagHelper::getSourceNodeConnectedTo ( shadingEngine, ATTR_SURFACE_SHADER );

        // Find the actual shader node, since this function received shading sets as input
        MStatus status;
        MFnDependencyNode shaderNode ( shader, &status );
        if ( status != MStatus::kSuccess ) return;

        // Get the name of the current material
        String materialId = mDocumentExporter->mayaNameToColladaName ( shaderNode.name(), true );

        // Have we seen this shader before?
        MaterialMap::iterator materialMapIter;
        materialMapIter = mMaterialMap.find ( materialId );
        if ( materialMapIter == mMaterialMap.end() )
        {
            // This is a new shading engine
            mMaterialMap[materialId] = shader;
        }

        // Check if the material should be written
        if ( mWriteMaterials )
        {
            // Have we exported this shader already?
            std::vector<String>::iterator exportedMaterialsIter;
            exportedMaterialsIter = find ( mExportedMaterials.begin(), mExportedMaterials.end(), materialId );

            if ( exportedMaterialsIter == mExportedMaterials.end() )
            {
                // Open a tag for the current material in the collada document
                openMaterial ( materialId, materialId );

                // Export the reference to the effect and the hardware shader components.
                exportEffectInstance ( materialId, shader );

                // Closes the current effect tag
                closeMaterial();

                // Push the if of the exported material into the list for the exported materials
                mExportedMaterials.push_back ( materialId );
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
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        String attributeName = attribute->fName.asChar();

        cgfxAttrDef::cgfxAttrType attributeType = attribute->fType;
        switch ( attributeType )
        {
        case cgfxAttrDef::kAttrTypeBool:
            {
                COLLADA::SetParamBool setParam ( streamWriter );
                setParam.openParam ( attributeName );
                setParam.appendValues ( attribute->fNumericDef && attribute->fNumericDef[0] );
                setParam.closeParam ();
                break;
            }
        case cgfxAttrDef::kAttrTypeInt:
            {
                COLLADA::SetParamInt setParam ( streamWriter );
                setParam.openParam ( attributeName );
                setParam.appendValues ( (int) attribute->fNumericDef[0] );
                setParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeString:
            {
                COLLADA::SetParamString setParam ( streamWriter );
                setParam.openParam ( attributeName );
                if ( attribute->fStringDef != NULL ) 
                    setParam.appendValues ( String ( attribute->fStringDef.asChar() ) );
                setParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeFloat:
            {
                COLLADA::SetParamFloat setParam ( streamWriter );
                setParam.openParam ( attributeName );
                if ( attribute->fNumericDef!=NULL && attribute->fNumericDef[0]!=NULL )  
                    setParam.appendValues ( attribute->fNumericDef[0] );
                setParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeVector2:
            {
                COLLADA::SetParamFloat2 setParam ( streamWriter );
                setParam.openParam ( attributeName );
                for ( int i=0; i<attribute->fSize; ++i )
                {
                    if ( attribute->fNumericDef!=NULL && attribute->fNumericDef[i]!=NULL )  
                    {
                        double val = attribute->fNumericDef[i];
                        setParam.appendValues( val );
                    }
                }
                setParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeVector3:
        case cgfxAttrDef::kAttrTypeColor3:
            {
                COLLADA::SetParamFloat3 setParam ( streamWriter );
                setParam.openParam ( attributeName );
                for ( int i=0; i<attribute->fSize; ++i )
                {
                    if ( attribute->fNumericDef!=NULL && attribute->fNumericDef[i]!=NULL )  
                    {
                        double val = attribute->fNumericDef[i];
                        setParam.appendValues( val );
                    }
                }
                setParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeVector4:
        case cgfxAttrDef::kAttrTypeColor4:
            {
                COLLADA::SetParamFloat4 setParam ( streamWriter );
                setParam.openParam ( attributeName );
                for ( int i=0; i<attribute->fSize; ++i )
                {
                    if ( attribute->fNumericDef!=NULL && attribute->fNumericDef[i]!=NULL )  
                    {
                        double val = attribute->fNumericDef[i];
                        setParam.appendValues( val );
                    }
                }
                setParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeWorldDir:
        case cgfxAttrDef::kAttrTypeWorldPos:
            {
                // Read the value
                double tmp[4];
                for ( int i=0; i<attribute->fSize; ++i )
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

                if ( base == cgfxAttrDef::kAttrTypeFirstPos )
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

                COLLADA::SetParamFloat4 setParam ( streamWriter );
                setParam.openParam ( attributeName );
                setParam.appendValues( tmp[0], tmp[1], tmp[2], tmp[3] );
                setParam.closeParam();
                break;
            }
        case cgfxAttrDef::kAttrTypeMatrix:
        case cgfxAttrDef::kAttrTypeWorldMatrix:
        case cgfxAttrDef::kAttrTypeViewMatrix:
        case cgfxAttrDef::kAttrTypeProjectionMatrix:
        case cgfxAttrDef::kAttrTypeWorldViewMatrix:
        case cgfxAttrDef::kAttrTypeWorldViewProjectionMatrix:
            {
                COLLADA::SetParamFloat4x4 setParam ( streamWriter );
                setParam.openParam ( attributeName );

                MMatrix mayaMatrix;
                double* p = &mayaMatrix.matrix[0][0];
                for ( int k=0; k<attribute->fSize; ++k )
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
                    w  = vpt[2];
                    h  = vpt[3];
                    d  = depth[1] - z0;

                    // Make a reference to ease the typing
                    //
                    double* s = &sMatrix.matrix[0][0];

                    s[ 0] = w/2;	s[ 1] = 0.0;	s[ 2] = 0.0;	s[ 3] = 0.0;
                    s[ 4] = 0.0;	s[ 5] = h/2;	s[ 6] = 0.0;	s[ 7] = 0.0;
                    s[ 8] = 0.0;	s[ 9] = 0.0;	s[10] = d/2;	s[11] = 0.0;
                    s[12] = x0+w/2;	s[13] = y0+h/2;	s[14] = z0+d/2;	s[15] = 1.0;

                    wvpsMatrix = wvpMatrix * sMatrix;
                }		

                switch ( attribute->fType )
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
                convertMMatrixToDouble4x4 ( matrix, mayaMatrix );
                setParam.appendValues( matrix );
                setParam.closeParam();
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
                String imageName = attribute->fStringDef.asChar();

                // -------------------------------
                MObject oNode = shaderNodeCgfx->thisMObject();
                MFnDependencyNode oNodeFn ( oNode );
                String oNodeName = oNodeFn.name().asChar(); // cgfxShader1

                MPlug plug;
                if ( DagHelper::getPlugConnectedTo( oNode, attributeName, plug ) )
                {
                    String plugName = plug.name().asChar(); // file1.outColor
                    MObject textureNode = plug.node();

                    COLLADA::Surface::SurfaceType surfaceType;
                    COLLADA::Sampler::SamplerType samplerType;
                    COLLADA::ValueType::ColladaType samplerValueType;

                    switch ( attributeType )
                    {
                    case cgfxAttrDef::kAttrTypeColor1DTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_1D;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_1D;
                        samplerValueType = COLLADA::ValueType::SAMPLER_1D;
                        break;
                    case cgfxAttrDef::kAttrTypeColor2DTexture:
                    case cgfxAttrDef::kAttrTypeNormalTexture:
                    case cgfxAttrDef::kAttrTypeBumpTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_2D;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_2D;
                        samplerValueType = COLLADA::ValueType::SAMPLER_2D;
                        break;
                    case cgfxAttrDef::kAttrTypeColor3DTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_3D;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_3D;
                        samplerValueType = COLLADA::ValueType::SAMPLER_3D;
                        break;
                    case cgfxAttrDef::kAttrTypeColor2DRectTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_RECT;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_RECT;
                        samplerValueType = COLLADA::ValueType::SAMPLER_RECT;
                        break;
                    case cgfxAttrDef::kAttrTypeCubeTexture:
                    case cgfxAttrDef::kAttrTypeEnvTexture:
                    case cgfxAttrDef::kAttrTypeNormalizationTexture:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_CUBE;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_CUBE;
                        samplerValueType = COLLADA::ValueType::SAMPLER_CUBE;
                        break;
                    default:
                        surfaceType = COLLADA::Surface::SURFACE_TYPE_UNTYPED;
                        samplerType = COLLADA::Sampler::SAMPLER_TYPE_UNSPECIFIED;
                        samplerValueType = COLLADA::ValueType::VALUE_TYPE_UNSPECIFIED;
                    }

                    // Write the params elements
                    setSetParamTexture( attribute, textureNode, surfaceType, samplerType, samplerValueType );

                }
            }
        }
    }

    //---------------------------------------
    void MaterialExporter::setSetParamTexture (
        const cgfxAttrDef* attribute, 
        MObject textureNode, 
        COLLADA::Surface::SurfaceType surfaceType, 
        COLLADA::Sampler::SamplerType samplerType, 
        COLLADA::ValueType::ColladaType samplerValueType )
    {
        // Get a pointer to the current stream writer.
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Get the image id
        MFnDependencyNode pluNodeFn ( textureNode );
        String plugName = pluNodeFn.name().asChar(); // file1

        // Get the file texture name
        MPlug filenamePlug = pluNodeFn.findPlug ( ATTR_FILE_TEXTURE_NAME );
        MString mayaFileName;
        filenamePlug.getValue ( mayaFileName );
        if ( mayaFileName.length() == 0 ) return;
        String fileName = mayaFileName.asChar ();
        
        // Get the image path
        COLLADA::URI shaderFxFileUri = getShaderFxFileUri ();

        // Take the filename for the unique image name 
        COLLADA::URI sourceUri ( shaderFxFileUri, fileName );
        String imageId = sourceUri.getPathFileBase();

        // Export the image
        EffectTextureExporter* textureExporter = 
            mDocumentExporter->getEffectExporter()->getTextureExporter();
        COLLADA::Image* colladaImage = textureExporter->exportImage ( imageId, sourceUri.getURIString() );

        // Get the image id of the exported collada image 
        imageId = colladaImage->getImageId();

        // Create the surface
        String surfaceSid = imageId + COLLADA::Surface::SURFACE_SID_SUFFIX;
        COLLADA::Surface surface ( surfaceType, surfaceSid );
        surface.setFormat ( "A8R8G8B8" );

        // Create the sampler and add the sampler <newparam>
        COLLADA::Sampler sampler ( samplerType, surfaceSid );
        String suffix = COLLADA::Sampler::SAMPLER_SID_SUFFIX;
        String samplerSid = imageId + COLLADA::Sampler::SAMPLER_SID_SUFFIX;
        COLLADA::SetParamSampler paramSampler ( streamWriter );
        paramSampler.setParamType( samplerValueType );
        paramSampler.openParam ( samplerSid );
        sampler.add ( streamWriter );
        paramSampler.closeParam ();

        // Create the surface init option
        COLLADA::SurfaceInitOption initOption ( COLLADA::SurfaceInitOption::INIT_FROM );
        initOption.setImageReference ( colladaImage->getImageId() );
        surface.setInitOption ( initOption );

        // Add the surface <newparam>
        COLLADA::SetParamSurface paramSurface ( streamWriter );
        paramSurface.openParam ( surfaceSid );
        surface.add ( streamWriter );
        paramSurface.closeParam ();

    }

    //---------------------------------------
    void MaterialExporter::exportCustomHwShaderNode( 
        COLLADA::InstanceEffect &effectInstance, 
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
        COLLADA::InstanceEffect& effectInstance, 
        cgfxShaderNode* shaderNodeCgfx )
    {
        // Get the filename of the current cgfx file
        MString shaderFxFile = shaderNodeCgfx->shaderFxFile();
        String shaderFxFileName = shaderFxFile.asChar(); // check3d.cgfx
        setShaderFxFileUri ( COLLADA::URI ( COLLADA::URI::nativePathToUri ( shaderFxFileName ) ) );

        // Get the current technique name
        String techniqueName = shaderNodeCgfx->getTechnique().asChar(); // techniqueName.asChar()

        // Add the technique hint to the collada document.
        effectInstance.addTechniqueHint ( techniqueName, COLLADA::CSWC::COLLADA_PLATFORM_PC_OGL );

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
    }

    // --------------------------------------
    void MaterialExporter::setShaderFxFileUri( const COLLADA::URI& shaderFxFileName )
    {
        mShaderFxFileUri = shaderFxFileName;
    }

    // --------------------------------------
    const COLLADA::URI& MaterialExporter::getShaderFxFileUri() const
    {
        return mShaderFxFileUri;
    }

    // --------------------------------------
    void MaterialExporter::exportEffectInstance( String materialId, MObject &shader )
    {
        // Create the effect instance
        String effectURL = materialId + EffectExporter::EFFECT_ID_SUFFIX;
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        COLLADA::InstanceEffect effectInstance ( streamWriter, COLLADA::URI ( "", effectURL ) );

        // Opens the current effect instance. 
        effectInstance.open();

        // Custom hardware shaders derived from MPxHardwareShader (the new stuff)
        if ( shader.hasFn ( MFn::kPluginHwShaderNode ) )
        {
            // Export the effect technique reference and the hardware shader parameters.
            exportCustomHwShaderNode ( effectInstance, shader );
        }

        // Close the current effect element.
        effectInstance.close();
    }
}