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
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaGeometryPolygonExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaAnimationHelper.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaControllerExporter.h"
#include <algorithm>

#include <maya/MItDependencyNodes.h>
#include <maya/MFnMesh.h>
#include <maya/MItMeshPolygon.h>
#include <maya/MItMeshVertex.h>
#include <maya/MItDag.h>
#include <maya/MFnNumericData.h>

#include "COLLADASource.h"
#include "COLLADABaseInputElement.h"
#include "COLLADAInputList.h"
#include "COLLADAExtraTechnique.h"
#include "COLLADAExtra.h"

namespace COLLADAMaya
{

    // --------------------------------------------------------
    GeometryExporter::GeometryExporter ( COLLADA::StreamWriter* streamWriter,
                                         DocumentExporter* documentExporter )
    : COLLADA::LibraryGeometries ( streamWriter )
    , mDocumentExporter ( documentExporter )
    {
    }

    // --------------------------------------------------------
    GeometryExporter::~GeometryExporter ( void )
    {
        mPolygonSources.clear();
        mVertexSources.clear();
    }

    // --------------------------------------------------------
    void GeometryExporter::exportGeometries()
    {
        if ( !ExportOptions::exportPolygonMeshes() ) return;

        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        size_t length = exportNodesTree->size();
        for ( size_t i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            exportGeometries ( sceneElement );
        }

        endExport();
    }

    // --------------------------------------------------------
    void GeometryExporter::exportGeometries ( SceneElement* sceneElement )
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Get the scene graph 
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        
        // Check for instance
        bool isInstance = ( dagPath.isInstanced() && dagPath.instanceNumber() > 0 );

        // Check if it is a mesh and an export node
        SceneElement::Type type = sceneElement->getType();
        if ( type == SceneElement::MESH &&
             sceneElement->getIsExportNode() && !isInstance )
        {
            bool exported = false;
            
            // Get the controller library
            ControllerExporter* controller = mDocumentExporter->getControllerExporter();

            // Add the controller and/or geometry to our libraries
            bool hasSkinController =
                ExportOptions::exportJointsAndSkin() &&
                controller->hasSkinController ( dagPath.node() );
            bool hasMorphController = controller->hasMorphController ( dagPath.node() );

            // Handle the controllers
            if ( hasSkinController || hasMorphController )
            {
                // The stacks of the controllers for the affected nodes.
                ControllerStack stack;
                ControllerMeshStack meshStack;
                
                // Iterate upstream finding all the nodes which affect the mesh.
                if ( !ControllerExporter::findAffectedNodes( dagPath.node(), stack, meshStack ) ) return;

//                 // Disable the blend shape influences.
//                 ControllerExporter::disableBlendShape( stack );
                // Disable any effects on the nodes.
                ControllerExporter::setControllerNodeStatesToNoEffect ( stack );
                // Set all meshes as visible and not intermediate.
                ControllerExporter::setValidMeshParameters ( meshStack );
                
                // Export the geometry 
                exported = exportGeometry ( sceneElement );

                // Push it in the list of exported elements.
                if ( exported )
                    sceneGraph->addExportedElement( sceneElement );

                // Export the controllerStack items
                for ( size_t i=0; i<meshStack.size(); ++i )
                {
                    ControllerMeshItem item = meshStack[i];
                    MDagPath currentDagPath = MDagPath::getAPathTo ( item.mesh );
                    MFnDagNode dagFn ( currentDagPath );
                    bool isIntermediate = dagFn.isIntermediateObject();
                    String currentPath = currentDagPath.fullPathName().asChar();

                    if ( sceneGraph->findExportedElement( currentDagPath ) == NULL )
                    {
                        SceneElement* meshSceneElement = sceneGraph->findElement( currentDagPath );
                        if ( meshSceneElement != NULL && meshSceneElement->getHasJoint() ) 
                        {
                            // Export the geometry 
                            exportGeometry ( meshSceneElement );

                            // Push it in the list of exported elements.
                            if ( exported )
                                sceneGraph->addExportedElement( meshSceneElement );
                        }
                    }
                }
                
                // Reset all the controller node states.
                ControllerExporter::resetControllerNodeStates ( stack );
//                 // Enable the blend shape influences.
//                 ControllerExporter::enableBlendShape ( stack );
                // Reset the meshes as visible and not intermediate.
                ControllerExporter::resetMeshParameters ( meshStack );
                // Delete the controller stack items and clear the stack.
                ControllerExporter::deleteControllerStackItems ( stack );
            }
            else
            {
                // Export the geometry 
                exported = exportGeometry ( sceneElement );

                // Push it in the list of exported elements.
                if ( exported )
                    sceneGraph->addExportedElement( sceneElement );
            }

        }

        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportGeometries ( childElement );
        }
    }

    // --------------------------------------------------------
    bool GeometryExporter::exportGeometry ( SceneElement* sceneElement )
    {
        if ( !ExportOptions::exportPolygonMeshes() ) return false;

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        //  Get the node of the current mesh
        MObject meshNode = dagPath.node();

        // Attach a function set to the mesh node.
        // We access all of the meshes data through the function set
        MStatus status;
        MFnMesh fnMesh ( meshNode, &status );
        if ( status != MStatus::kSuccess ) return false;

        // Create the unique ID
        String meshId1 = mDocumentExporter->dagPathToColladaId( dagPath );
        String meshId = mDocumentExporter->mayaNameToColladaName ( fnMesh.name() );
        
        bool isInstanced = dagPath.isInstanced();
        uint instanceNumber = dagPath.instanceNumber();

        // Get the mesh name
        String meshName = mDocumentExporter->dagPathToColladaName( dagPath );

//         // Check if the geometry isn't already exported
//         std::vector<String>::iterator geometryIter;
//         geometryIter = find ( mExportedGeometries.begin(), mExportedGeometries.end(), meshId );
//         if ( geometryIter != mExportedGeometries.end() ) return false;
// 
//         // Push the geometry in the list of exported geometries
//         mExportedGeometries.push_back ( meshId );

        // Set a new mesh id in the list of unique exported mesh geometries.
        meshId = mExportedGeometries.addId ( meshId );
        sceneElement->setNodeId ( meshId );

        // Write the mesh data
        return exportMesh ( fnMesh, meshId, meshName );
    }

    // --------------------------------------------------------
    bool GeometryExporter::exportMesh ( MFnMesh& fnMesh, String meshId, String &meshName )
    {
        // Clear the list with the current polygons and the list with the vertexes
        mPolygonSources.clear();
        mVertexSources.clear();

        // Retrieve all uv set names for this mesh.
        MStringArray uvSetNames;
        getUVSetNames(fnMesh, uvSetNames);

        // Generate corresponding textureCoordinateIds.
        std::vector<String> texcoordIds = generateTexCoordIds ( uvSetNames, meshId );

        // Opens the mesh tag in the collada document
        openMesh ( meshId, meshName );

        // The list for the color sets. We have to clean!
        ColourSetList colorSets;

        // Export the vertex positions
        exportVertexPositions ( fnMesh, meshId );

        // Export the vertex normals
        bool hasFaceVertexNormals = exportVertexNormals ( fnMesh, meshId );
        
        // Export the texture coordinates
        exportTextureCoords ( fnMesh, meshId, uvSetNames, texcoordIds );
        
        // exportVertexBlindData(fnMesh);
        
        // Export the color sets
        exportColorSets ( fnMesh, meshId, colorSets );
        
        // Export the vertexes
        exportVertices ( meshId );

        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        GeometryPolygonExporter polygonExporter ( streamWriter, mDocumentExporter );
        polygonExporter.exportPolygonSources ( 
            fnMesh, meshId,
            uvSetNames,
            colorSets,
            &mPolygonSources,
            &mVertexSources,
            hasFaceVertexNormals );

        // Delete the created color sets
        ColourSetList::iterator it = colorSets.begin();
        for ( ; it!=colorSets.end(); ++it )
        {
            ColourSet* colourSet = *it;
            delete colourSet;
        }
        colorSets.clear();

        // --------------------------------------------------------
        // TODO
        // This is not part of this exporter, cause all informations to generate the TexTangents
        // are already exported!!

        // For texturing std::map channels, export the texture tangents and bi-normals, on request

        if ( ExportOptions::exportTexTangents() )
        {
            //   Sources::iterator sourceIter = mPolygonSources.begin();
            //   for (; sourceIter!=mPolygonSources.end(); ++sourceIter)
            //   {
            //    SourceInput &source = *sourceIter;
            //    if (source.type == COLLADA::TEXCOORD)
            //    {
            // //    FCDGeometryPolygonsTools::GenerateTextureTangentBasis(colladaMesh, source, true);
            //    }
            //   }
        }

        closeMesh();

        exportExtra ( fnMesh );

        closeGeometry();

        return true;
    }

    // --------------------------------------------------------
    void GeometryExporter::getUVSetNames( MFnMesh &fnMesh, MStringArray &uvSetNames )
    {
        MPlug uvSetPlug = fnMesh.findPlug ( ATTR_UV_SET );
        for ( uint i = 0; i < uvSetPlug.numElements(); i++ )
        {
            // get uvSet[<index>] and uvSet[<index>].uvSetName
            MPlug uvSetElememtPlug = uvSetPlug.elementByPhysicalIndex ( i );
            MPlug uvSetNamePlug = uvSetElememtPlug.child ( 0 );

            // get value of plug (uvSet's name)
            MString uvSetName;
            uvSetNamePlug.getValue ( uvSetName );
            uvSetNames.append ( uvSetName );
        }
    }

    // --------------------------------------------------------
    void GeometryExporter::exportExtra ( const MFnMesh &fnMesh )
    {
        bool doubleSided = isDoubleSided ( fnMesh );

        COLLADA::Extra extraSource ( mSW );
        extraSource.openExtra();

        COLLADA::Technique techniqueSource ( mSW );
        techniqueSource.openTechnique ( COLLADA::CSWC::COLLADA_PROFILE_MAYA );
        techniqueSource.addParameter ( DOUBLE_SIDED_PARAMETER, doubleSided );
        techniqueSource.closeTechnique();

        extraSource.closeExtra();
    }

    // --------------------------------------------------------
    // Are the faces double-sided?
    //
    bool GeometryExporter::isDoubleSided ( const MFnMesh &fnMesh )
    {
        MPlug doubleSidedPlug = fnMesh.findPlug ( ATTR_DOUBLE_SIDED );
        bool doubleSided;
        doubleSidedPlug.getValue ( doubleSided );

        if ( doubleSided )
        {
            // Also check the backfaceCulling plug
            MPlug backfaceCullingPlug = fnMesh.findPlug ( ATTR_BACKFACE_CULLING );
            int enumValue = 0;
            backfaceCullingPlug.getValue ( enumValue );

            if ( enumValue != 0 ) doubleSided = false;
        }

        return doubleSided;
    }

    //---------------------------------------------------------------
    void GeometryExporter::exportVertexPositions ( const MFnMesh &fnMesh, const String &meshId )
    {
        COLLADA::FloatSource vertexSource ( mSW );
        vertexSource.setId ( meshId + POSITIONS_SOURCE_ID_SUFFIX );
        vertexSource.setNodeName ( meshId + POSITIONS_SOURCE_ID_SUFFIX );
        vertexSource.setArrayId ( meshId + POSITIONS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        vertexSource.setAccessorStride ( 3 );

        // Retrieves the vertex positions. 
        MPointArray vertexArray;
        fnMesh.getPoints ( vertexArray, MSpace::kObject ); // With the meteorite-example, 10MB will be allocated!
        uint vertexCount = vertexArray.length();
        vertexSource.setAccessorCount ( vertexCount );

        vertexSource.getParameterNameList().push_back ( XYZW_PARAMETERS[0] );
        vertexSource.getParameterNameList().push_back ( XYZW_PARAMETERS[1] );
        vertexSource.getParameterNameList().push_back ( XYZW_PARAMETERS[2] );
        vertexSource.prepareToAppendValues();

        // Remove the vertex position tweaks that will be exported as animations
        MPlug positionTweakArrayPlug = fnMesh.findPlug ( ATTR_VERTEX_POSITION_TWEAKS );
        uint positionTweakCount = positionTweakArrayPlug.numElements();
        for ( uint i = 0; i < positionTweakCount; ++i )
        {
            MPlug positionTweakPlug = positionTweakArrayPlug.elementByPhysicalIndex ( i );
            MPlug positionTweakPlugX = positionTweakPlug.child ( 0 );
            MPlug positionTweakPlugY = positionTweakPlug.child ( 1 );
            MPlug positionTweakPlugZ = positionTweakPlug.child ( 2 );

            AnimationSampleCache* animCache = mDocumentExporter->getAnimationCache();
            bool xAnimated = AnimationHelper::isAnimated ( animCache, positionTweakPlugX ) != kISANIM_None;
            bool yAnimated = AnimationHelper::isAnimated ( animCache, positionTweakPlugY ) != kISANIM_None;
            bool zAnimated = AnimationHelper::isAnimated ( animCache, positionTweakPlugZ ) != kISANIM_None;

            if ( !xAnimated && !yAnimated && !zAnimated ) continue;

            uint logicalIndex = positionTweakPlug.logicalIndex();
            if ( logicalIndex >= vertexCount ) continue;

            MPoint &pointData = vertexArray[logicalIndex];

            MObject vectorObject;
            positionTweakPlug.getValue ( vectorObject );
            MFnNumericData data ( vectorObject );

            MPoint positionTweak;
            data.getData ( positionTweak.x, positionTweak.y, positionTweak.z );

            pointData -= positionTweak;
            vertexArray[logicalIndex] = pointData;

            // Export the Point3 animation - note that this is a relative animation.
            for ( uint k=0; k<3; ++k )
            {
                MPlug childPlug = positionTweakPlug.child ( k );

                //    FCDAnimated* animated = vertexSource->GetSourceData().GetAnimated(3 * logicalIndex + k);
                //    animated->SetRelativeAnimationFlag();
                //    ANIM->AddPlugAnimation(positionTweakPlug.child(k), animated, kSingle | kLength);

                // TODO Parameters??? TEST!
                AnimationExporter* animExporter = mDocumentExporter->getAnimationExporter();
                animExporter->addPlugAnimation ( childPlug, VERTEX_SID, kSingle | kLength, XYZW_PARAMETERS, true );
            }
        }

        for ( uint i = 0; i < vertexCount; ++i )
        {
            // Convert the  maya internal unit type from centimeters 
            // into the working units of the current scene!
            MPoint &pointData = vertexArray[i];
            vertexSource.appendValues ( 
                COLLADA::MathUtils::equalsZero ( vertexArray[i].x ) ? 0 : MDistance::internalToUI ( vertexArray[i].x ), 
                COLLADA::MathUtils::equalsZero ( vertexArray[i].y ) ? 0 : MDistance::internalToUI ( vertexArray[i].y ), 
                COLLADA::MathUtils::equalsZero ( vertexArray[i].z ) ? 0 : MDistance::internalToUI ( vertexArray[i].z ) );
        }
        vertexSource.finish();

        // Add input to the mesh <vertices> node
        mPolygonSources.push_back ( SourceInput ( vertexSource, COLLADA::VERTEX ) );
    }

    //---------------------------------------------------------------
    bool GeometryExporter::exportVertexNormals ( 
        const MFnMesh& fnMesh, 
        const String& meshId )
    {
        if ( !ExportOptions::exportNormals() ) return false;

        // Export the normals
        uint normalCount = fnMesh.numNormals();
        MFloatVectorArray normals ( normalCount );
        bool perVertexNormals = exportNormals( fnMesh, meshId, normals );

        // Export the tangents
        exportTangents( fnMesh, meshId, perVertexNormals, normals );

        return !perVertexNormals;
    }

    // ----------------------------------------------------
    std::vector<String> GeometryExporter::generateTexCoordIds ( 
        const MStringArray& uvSetNames,
        const String& meshId )
    {
        std::vector<String> texcoordIds;

        int texCoordsCount = uvSetNames.length();
        texcoordIds.resize ( texCoordsCount );

        for ( int i = 0; i < texCoordsCount; i++ )
        {
            texcoordIds[i] = meshId + "-" + uvSetNames[i].asChar();
        }

        return texcoordIds;
    }

    // ----------------------------------------------------
    // Export per-vertex blind data

    /*
    Comment from Feeling-Software:

    Per-Vertex Blind Data
    The plug-in now supports the import/export of per-vertex blind data. Unfortunately, we are ahead
    of the COLLADA specifications once again. A new semantic was therefore added, unofficially, to
    the mesh <vertices><input> node: "EXTRA", which points towards the source of per-vertex blind data.
    */
    void GeometryExporter::exportVertexBlindData ( const MFnMesh& fnMesh )
    {
        /*
        uint meshVertexCount = fnMesh.numVertices();
        MIntArray blindDataTemplateIndices;
        fnMesh.getBlindDataTypes(MFn::kMeshVertComponent, blindDataTemplateIndices);

        uint blindDataTemplateCount = blindDataTemplateIndices.length();
        for (uint i = 0; i < blindDataTemplateCount; ++i)
        {
         uint blindDataTemplateIndex = blindDataTemplateIndices[i];

         MStringArray longNames, shortNames, typeNames;
         fnMesh.getBlindDataAttrNames(blindDataTemplateIndex, longNames, shortNames, typeNames);

         uint valueCount = typeNames.length();
         for (uint j = 0; j < valueCount; ++j)
         {
          MString typeName = typeNames[j];

        #define EXPORT_TYPE(typeStr, meshFunction, dataArrayType) \
        if (typeName == typeStr) \
          { \
          FCDGeometrySource* source = colladaMesh->AddSource(FUDaeGeometryInput::EXTRA); \
          source->SetName(MConvert::ToFChar(longNames[j])); \
          source->SetStride(1); \
          FUSStringBuilder sourceId(colladaMesh->GetDaeId()); sourceId.append("-blind"); sourceId.append(blindDataTemplateIndex); sourceId.append("-"); sourceId.append(shortNames[j].asChar()); \
          source->SetDaeId(colladaMesh->GetDaeId() + "-blind"); \
          \
          MIntArray indices; dataArrayType indexedData; \
          source->SetDataCount(meshVertexCount); \
          float* data = source->GetData(); \
          memset(data, 0, meshVertexCount * sizeof(float)); \
          meshFn.meshFunction(MFn::kMeshVertComponent, blindDataTemplateIndex, longNames[j], indices, indexedData); \
          uint indexCount = indices.length(); \
          for (uint k = 0; k < indexCount; ++k) data[indices[k]] = (float) indexedData[k]; \
          FCDExtra* extra = source->GetExtra(); \
          FCDETechnique* technique = extra->GetDefaultType()->AddTechnique(DAEMAYA_MAYA_PROFILE); \
          technique->AddParameter(DAEMAYA_BLINDTYPEID_PARAMETER, blindDataTemplateIndex); \
          technique->AddParameter(DAEMAYA_LONGNAME_PARAMETER, MConvert::ToFChar(longNames[j])); \
          technique->AddParameter(DAEMAYA_SHORTNAME_PARAMETER, MConvert::ToFChar(shortNames[j])); \
          }

          EXPORT_TYPE("int", getIntBlindData, MIntArray)
        else EXPORT_TYPE("float", getFloatBlindData, MFloatArray)
          else EXPORT_TYPE("double", getDoubleBlindData, MDoubleArray)
          else EXPORT_TYPE("boolean", getBoolBlindData, MIntArray)

        #undef EXPORT_TYPE
         }
        }
        */
    }

    // --------------------------------------------------------------------
    // Export the color sets
    // Returns true if we should proceed to export the given color set Ids.
    void GeometryExporter::exportColorSets ( 
        const MFnMesh& fnMesh,
        const String& meshId,
        ColourSetList& colorSets )
    {
        if ( !ExportOptions::exportVertexColors() ) return;

        // Retrieve all the color set header information
        MeshHelper::getMeshValidColorSets ( fnMesh.object(), colorSets );

        // Process the color sets
        size_t colorSetCount = colorSets.size();
        for ( size_t i=0; i<colorSetCount; ++i )
        {
            ColourSet& colorSet = *colorSets[i];
            String colorSetName = colorSet.name.asChar();

            if ( colorSet.name.length() == 0 ) continue;

            // Retrieve the color set data
            std::vector<float> meshColorSet;
            getMeshColorSet ( fnMesh.object(), meshColorSet, colorSet );

            // If we don't have a mesh color set, we don't need to implement a color source.
            size_t numMeshColorSets = meshColorSet.size();
            if ( numMeshColorSets == 0 ) continue;

            // Create the id of the color source
            String colorSourceId = meshId + "-" + colorSetName;

            size_t stride = 4;

            // Create the source
            COLLADA::FloatSourceF colorSource ( mSW );
            colorSource.setId ( colorSourceId );
            colorSource.setNodeName ( colorSourceId );
            colorSource.setArrayId ( colorSourceId + ARRAY_ID_SUFFIX );
            colorSource.setAccessorStride ( ( unsigned long ) stride );
            colorSource.setAccessorCount ( ( unsigned long ) ( numMeshColorSets / stride ) );
            for ( size_t p=0; p<stride; ++p )
                colorSource.getParameterNameList().push_back ( RGBA_PARAMETERS[p] );
            colorSource.prepareToAppendValues();

            // Push the data from the meshColorSet into the color source of the collada document.
            colorSource.appendValues ( meshColorSet );
            colorSource.finish();
            
            // TODO Don't put the source into the vertex sources, 
            // put it into the polygon sources.
            // That's about the other plug-ins, they don't support this.
            bool exportPerVertex = ExportOptions::exportVertexColorsPerVertex();
            if ( exportPerVertex && colorSet.isVertexColor )
            {
                // Insert a per-vertex color set input
                mVertexSources.push_back ( SourceInput ( colorSource, COLLADA::COLOR ) );
            }
            else
            {
                // Insert a per-face-vertex color set input
                mPolygonSources.push_back ( SourceInput ( colorSource, COLLADA::COLOR, ( int ) i ) );
            }
        }
    }

    // --------------------------------------------------------------------
    void GeometryExporter::exportVertices ( const String& meshId )
    {
        COLLADA::VerticesElement vertices ( mSW );
        vertices.setId ( meshId + VERTICES_ID_SUFFIX );
        vertices.setNodeName ( meshId + VERTICES_ID_SUFFIX );

        // Get the input list
        COLLADA::InputList* inputList = &vertices.getInputList();

        // Always push the vertex positions in the vertices element
        // (we have to create a vertices element with a reference)
        inputList->push_back ( COLLADA::Input ( COLLADA::POSITION, COLLADA::URI ( "", meshId + POSITIONS_SOURCE_ID_SUFFIX ) ) );

        // Push all other vertex sources into the vertices element
        Sources::iterator it = mVertexSources.begin();
        for ( ; it!=mVertexSources.end(); ++it )
        {
            // Get the current vertices source and read the id
            const SourceInput& sourceInput = *it;
            const COLLADA::SourceBase& source = sourceInput.getSource();
            String sourceId = source.getId();

            // Get the type of the current vertex source
            const COLLADA::Semantics& type = sourceInput.getType();

            // Push the vertex source to the collada vertices
            inputList->push_back ( COLLADA::Input ( type, COLLADA::URI ( "", sourceId ) ) );
        }

        vertices.add();
    }

    // --------------------------------------------------------------------
    void GeometryExporter::exportTextureCoords ( 
        const MFnMesh& fnMesh,
        const String& meshId,
        const MStringArray& uvSetNames,
        const std::vector<String>& texcoordIds )
    {
        if ( !ExportOptions::exportTexCoords() ) return;

        uint texCoordsCount = uvSetNames.length();
        for ( uint i=0; i<texCoordsCount; ++i )
        {
            MFloatArray uArray, vArray;
            MString uvSetName = uvSetNames[i];
            String uvSetNameStr = uvSetName.asChar();
            fnMesh.getUVs ( uArray, vArray, &uvSetName );
            uint uvCount = uArray.length();

            if ( uvCount == 0 || vArray.length() != uvCount ) continue;

            // Get the current id
            String texCoordinateId = texcoordIds[i];

            // Get the stride
            uint stride = 2;

            COLLADA::FloatSource texCoordSource ( mSW );
            texCoordSource.setId ( texCoordinateId );
            texCoordSource.setNodeName ( texCoordinateId );
            texCoordSource.setArrayId ( texCoordinateId + ARRAY_ID_SUFFIX );
            texCoordSource.setAccessorStride ( stride );
            texCoordSource.setAccessorCount ( uvCount );

            for ( uint i=0; i<stride; ++i )
            {
                texCoordSource.getParameterNameList().push_back ( STPQ_PARAMETERS[i] );
            }

            texCoordSource.prepareToAppendValues();

            for ( uint j = 0; j < uvCount; ++j )
            {
                texCoordSource.appendValues ( 
                    COLLADA::MathUtils::equalsZero ( uArray[j] ) ? 0 : uArray[j], 
                    COLLADA::MathUtils::equalsZero ( vArray[j] ) ? 0 : vArray[j] );
            }

            // Figure out the real index for this texture coordinate set
            MPlug uvSetPlug = fnMesh.findPlug ( ATTR_UV_SET );
            uint numElements = uvSetPlug.numElements();
            uint realIndex=0;
            for ( ; realIndex<numElements; ++realIndex )
            {
                // get uvSet[<index>] and uvSet[<index>].uvSetName
                MPlug uvSetElememtPlug = uvSetPlug.elementByPhysicalIndex ( realIndex );
                MPlug uvSetNamePlug = uvSetElememtPlug.child ( 0 );

                // get value of plug (uvSet's name)
                MString uvSetNamePlugValue;
                uvSetNamePlug.getValue ( uvSetNamePlugValue );

                if ( uvSetName == uvSetNamePlugValue ) break;
            }

            texCoordSource.finish();

            mPolygonSources.push_back ( SourceInput ( texCoordSource, COLLADA::TEXCOORD, realIndex ) );
        }
    }

    // --------------------------------------------------------
    void GeometryExporter::getMeshColorSet ( 
        const MObject &mesh,
        std::vector<float> &meshColorSet,
        ColourSet &colorSet )
    {
        // Is this a mesh?
        if ( !mesh.hasFn ( MFn::kMesh ) ) return;

        MFnMesh meshFn ( mesh );

        // r g b a
        int colorElements = 4;

        colorSet.isVertexColor = false;

#if MAYA_API_VERSION >= 700
        // Fill out the color set information list
        uint setPlugElementCount = colorSet.arrayPlug.numElements();

        // TODO
        /*
        if (CExportOptions::ExportVertexColorAnimations())
         source->GetAnimatedValues().reserve(setPlugElementCount);
        */

        if ( setPlugElementCount > 0 )
        {
            bool opaqueWhiteFound = false;

            //  source->SetValueCount(setPlugElementCount + 1); // +1 to account for the potential white color.
            //  float* data = source->GetData();
            meshColorSet.resize ( ( setPlugElementCount + 1 ) *colorElements ); // +1 to account for the potential white color.

            int pos = 0;

            for ( uint j = 0; j < setPlugElementCount; ++j )
            {
                MPlug colorPlug = colorSet.arrayPlug.elementByPhysicalIndex ( j );

                MColor c;
                DagHelper::getPlugValue ( colorPlug, c );
                //   (*data++) = c.r; (*data++) = c.g; (*data++) = c.b; (*data++) = c.a;
                meshColorSet[pos] = c.r;
                ++pos;
                meshColorSet[pos] = c.g;
                ++pos;
                meshColorSet[pos] = c.b;
                ++pos;
                meshColorSet[pos] = c.a;
                ++pos;

                if ( c == MColor ( 1.0f, 1.0f, 1.0f, 1.0f ) )
                {
                    colorSet.whiteColorIndex = j;
                    opaqueWhiteFound = true;
                }

                // TODO ???!
                // Add the animation curve, if there's any (not supported according to the API docs)
                if ( ExportOptions::exportVertexColorAnimations() )
                {
                    //     ANIM->AddPlugAnimation(colorPlug.child(0), source->GetSourceData().GetAnimated(4*j+0), kSingle);
                    //     ANIM->AddPlugAnimation(colorPlug.child(1), source->GetSourceData().GetAnimated(4*j+1), kSingle);
                    //     ANIM->AddPlugAnimation(colorPlug.child(2), source->GetSourceData().GetAnimated(4*j+2), kSingle);
                    //     ANIM->AddPlugAnimation(colorPlug.child(3), source->GetSourceData().GetAnimated(4*j+3), kSingle);

                    // TODO
                    AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
                    //    animationExporter->addPlugAnimation(colorPlug.child(0), kSingle);
                }
            }

            if ( !opaqueWhiteFound )
            {
                // Push white at the end of the color set.
                //   (*data++) = 1.0f; (*data++) = 1.0f; (*data++) = 1.0f; (*data++) = 1.0f;
                meshColorSet[pos] = 1.0f;
                ++pos;
                meshColorSet[pos] = 1.0f;
                ++pos;
                meshColorSet[pos] = 1.0f;
                ++pos;
                meshColorSet[pos] = 1.0f;
                ++pos;
                colorSet.whiteColorIndex = setPlugElementCount;
            }

            //  else source->SetValueCount(setPlugElementCount);

            else meshColorSet.resize ( setPlugElementCount * colorElements );
        }
        else
#endif
        {
            // TODO
            //  source->GetAnimatedValues().reserve((size_t) meshFn.numVertices());

            // If requested, bake lighting information into per-vertex colors.
            MFnDependencyNode bakeLightingFn;
            if ( colorSet.isBlankSet && ExportOptions::bakeLighting() )
            {
                MGlobal::executeCommand ( "undoInfo -state on -infinity on", false, true );

                bakeLightingFn.create ( "vertexBakeSet" );

                MObjectArray shaderGroups;
                MObjectArray compositions;
                meshFn.getConnectedSetsAndMembers ( 0, shaderGroups, compositions, true );

                MString melCommand ( "convertLightmap -vm -sh -co 1 -bo " );
                melCommand += bakeLightingFn.name();
                melCommand += " ";

                uint shaderCount = shaderGroups.length();
                for ( uint i = 0; i < shaderCount; ++i )
                {
                    MFnDependencyNode fn ( shaderGroups[i] );
                    melCommand += fn.name();
                    melCommand += " ";
                    melCommand += meshFn.fullPathName();
                    melCommand += " ";
                }

                MGlobal::executeCommand ( melCommand, false, true );

                meshFn.syncObject();
            }

            if ( ExportOptions::exportVertexColorAnimations() )
            {
                // Prepare an array for the vertex colours, in that we use those instead
                MColorArray vertexColours;
                uint vertexCount = meshFn.numVertices();
                vertexColours.setLength ( vertexCount );

                for ( uint i = 0; i < vertexCount; ++i )
                {
                    MColor& c = vertexColours[i];
                    c.r = 1.0f;
                    c.g = 1.0f;
                    c.b = 1.0f;
                    c.a = -1.0f;
                }

                const int invalidColorIndex = -1;

                // Gather the per-face-vertex information
                uint polygonCount = meshFn.numPolygons();

                std::vector<MIntArray> polygonVertexIndices;
                polygonVertexIndices.resize ( polygonCount );

                MIntArray polygonOffsets ( polygonCount );
                uint faceVertexCount = 0;
                for ( uint i = 0; i < polygonCount; ++i )
                {
                    polygonOffsets[i] = faceVertexCount;
                    MIntArray& faceVertices = polygonVertexIndices[i];
                    meshFn.getPolygonVertices ( i, faceVertices );
                    faceVertexCount += faceVertices.length();
                }

                // Initialize the output index array
                colorSet.indices.setLength ( faceVertexCount );
                for ( uint i = 0; i < faceVertexCount; ++i )
                {
                    colorSet.indices[i] = invalidColorIndex;
                }

                // Grab all the color information from the vertex color node
                MFnDependencyNode nodeFn ( colorSet.polyColorPerVertexNode );
                MPlug globalPlug = nodeFn.findPlug ( ATTR_COLOR_PER_VERTEX );
                globalPlug = DagHelper::getChildPlug ( globalPlug, ATTR_VERTEX_COLOR ); // "vertexColor"

                uint elementCount = globalPlug.numElements();
                if ( elementCount == 0 )
                {
                    colorSet.indices.clear();
                    return;
                }

                colorSet.isVertexColor = true; // assume true then get proved wrong..

                size_t maxValueCount = std::max ( ( size_t ) elementCount, ( size_t ) vertexCount ) * 16; // * 16 to give enough space and avoid a resize that would break the export of animations..
                //   source->SetDataCount(maxValueCount);
                meshColorSet.resize ( maxValueCount*colorElements );

                size_t valueCount = 0;
                for ( uint i = 0; i < elementCount; ++i )
                {
                    // The logical index may be out-of-order.
                    MPlug vertexPlug = globalPlug.elementByPhysicalIndex ( i );
                    int vertexId = vertexPlug.logicalIndex();
                    if ( vertexId < 0 || vertexId >= ( int ) vertexCount ) continue;

                    MColor& vertexColor = vertexColours[vertexId];

                    // Read the face's per-vertex color values
                    MPlug perFaceVertexPlug = DagHelper::getChildPlug ( vertexPlug, ATTR_VERTEX_FACE_COLOR ); // "vertexFaceColor"

                    uint childElementCount = perFaceVertexPlug.numElements();
                    for ( uint j = 0; j < childElementCount; ++j )
                    {
                        // Get the information about this polygon
                        MPlug faceVertexColorPlug = perFaceVertexPlug.elementByPhysicalIndex ( j );
                        uint polyIndex = faceVertexColorPlug.logicalIndex();
                        if ( polyIndex >= polygonCount ) continue;

                        MIntArray& faceVertices = polygonVertexIndices[polyIndex];
                        uint offset = polygonOffsets[polyIndex];

                        // Look for the vertex index in the known mesh face-vertex array
                        uint vertexOffset = 0;
                        for ( ; vertexOffset < polygonCount; ++vertexOffset )
                        {
                            if ( vertexId == faceVertices[vertexOffset] ) break;
                        }
                        if ( vertexOffset == polygonCount ) continue;

                        offset += vertexOffset;

                        // Now that the vertex-face std::pair is identified, get its color
                        MColor faceVertexColor;
                        MPlug actualColorPlug = DagHelper::getChildPlug ( faceVertexColorPlug, ATTR_VERTEX_FACE_COLOR_RGB ); // "vertexFaceColorRGB"
                        MPlug actualAlphaPlug = DagHelper::getChildPlug ( faceVertexColorPlug, ATTR_VERTEX_FACE_ALPHA ); // "vertexFaceAlpha"

                        DagHelper::getPlugValue ( actualColorPlug, faceVertexColor );
                        DagHelper::getPlugValue ( actualAlphaPlug, faceVertexColor.a );

                        if ( valueCount >= maxValueCount ) break;

                        //     source->SetValue(valueCount, MConvert::ToFMVector4(faceVertexColor));
                        meshColorSet[valueCount*colorElements] = faceVertexColor.r;
                        meshColorSet[valueCount*colorElements+1] = faceVertexColor.g;
                        meshColorSet[valueCount*colorElements+2] = faceVertexColor.b;
                        meshColorSet[valueCount*colorElements+3] = faceVertexColor.a;

//                         AnimationExporter* animExpo = mDocumentExporter->getAnimationExporter();
//                         animExpo->addPlugAnimation( actualColorPlug.child(0), ATTR_VERTEX_COLOR, )
                        // TODO
                        /*
                        ANIM->AddPlugAnimation(actualColorPlug.child(0), source->GetSourceData().GetAnimated(4 * valueCount + 0), kSingle);
                        ANIM->AddPlugAnimation(actualColorPlug.child(1), source->GetSourceData().GetAnimated(4 * valueCount + 1), kSingle);
                        ANIM->AddPlugAnimation(actualColorPlug.child(2), source->GetSourceData().GetAnimated(4 * valueCount + 2), kSingle);
                        ANIM->AddPlugAnimation(actualAlphaPlug, source->GetSourceData().GetAnimated(4 * valueCount + 3), kSingle);
                        */
                        colorSet.indices[offset] = ( int ) valueCount++;

                        // Check if per-face, per-vertex color is necessary
                        if ( vertexColor.a == -1.0f ) vertexColor = faceVertexColor;
                        else colorSet.isVertexColor &= vertexColor == faceVertexColor;

                        colorSet.isVertexColor &= !DagHelper::hasConnection ( actualColorPlug, false, true ) && !DagHelper::hasConnection ( actualAlphaPlug, false, true );
                    }
                }

                if ( colorSet.isVertexColor )
                {
                    colorSet.indices.clear();

                    // Use per-vertex color instead
                    const MColor invalid ( MColor::kRGB, 0.0f, 0.0f, 0.0f, 1.0f );
                    for ( uint i = 0; i < elementCount; ++i )
                    {
                        MPlug vertexPlug = globalPlug.elementByPhysicalIndex ( i );

                        if ( vertexPlug.numChildren() > 0 )
                        {
                            int vertexId = vertexPlug.logicalIndex();
                            if ( vertexId >= ( int ) vertexCount ) continue;

                            // Get the color plug, don't use its color (SourceForge #1283335) if it is (0,0,0,1).
                            // but always check for an animation.
                            MColor c;
                            MPlug colorPlug = DagHelper::getChildPlug ( vertexPlug, ATTR_VERTEX_COLOR_RGB ); // "vertexColorRGB"
                            MPlug alphaPlug = DagHelper::getChildPlug ( vertexPlug, ATTR_VERTEX_ALPHA ); // "vertexAlpha"
                            DagHelper::getPlugValue ( colorPlug, c );
                            DagHelper::getPlugValue ( alphaPlug, c.a );

                            if ( c != invalid || vertexColours[vertexId].a == -1.0f )
                            {
                                vertexColours[vertexId] = c;

                                // TODO
                                /*
                                ANIM->AddPlugAnimation(colorPlug.child(0), source->GetSourceData().GetAnimated(4 * vertexId + 0), kColour);
                                ANIM->AddPlugAnimation(colorPlug.child(1), source->GetSourceData().GetAnimated(4 * vertexId + 1), kColour);
                                ANIM->AddPlugAnimation(colorPlug.child(2), source->GetSourceData().GetAnimated(4 * vertexId + 2), kColour);
                                ANIM->AddPlugAnimation(alphaPlug, source->GetSourceData().GetAnimated(4 * vertexId + 3), kSingle);
                                */
                            }
                        }
                    }

                    valueCount = vertexCount;
                    colorSet.whiteColorIndex = 0;
                    for ( uint cc = 0; cc < valueCount; ++cc )
                    {
                        MColor& color = vertexColours[cc];
                        if ( color.a < 0.0f )
                        {
                            color.a = 1.0f; // This is triggered only for missing vertex colors. Use white.
                            colorSet.whiteColorIndex = cc;
                        }

                        // TODO
                        //     source->SetValue(cc, MConvert::ToFMVector4(c));
                        meshColorSet[cc*colorElements] = color.r;
                        meshColorSet[cc*colorElements+1] = color.g;
                        meshColorSet[cc*colorElements+2] = color.b;
                        meshColorSet[cc*colorElements+3] = color.a;
                    }
                }

                else
                {
                    // Check all the per-vertex colors for valid ones.
                    // If we have invalid per-vertex-face colors, we'll assign them a valid per-vertex colors.

                    // Re-index any invalid colors into white
                    if ( valueCount < maxValueCount )
                    {
                        uint indexCount = colorSet.indices.length();
                        uint whiteColorIndex = ( uint ) valueCount;
                        bool needsWhiteColor = false;

                        for ( uint i = 0; i < indexCount; ++i )
                        {
                            if ( colorSet.indices[i] == invalidColorIndex )
                            {
                                colorSet.indices[i] = whiteColorIndex;
                                needsWhiteColor = true;
                            }
                        }

                        if ( needsWhiteColor )
                        {
                            //      source->SetValue(whiteColorIndex, FMVector4::One);
                            meshColorSet[whiteColorIndex*colorElements] = 1;
                            meshColorSet[whiteColorIndex*colorElements+1] = 1;
                            meshColorSet[whiteColorIndex*colorElements+2] = 1;
                            meshColorSet[whiteColorIndex*colorElements+3] = 1;

                            colorSet.whiteColorIndex = whiteColorIndex;
                            ++valueCount;
                        }
                    }
                }

                //   source->SetValueCount(valueCount);
                meshColorSet.resize ( valueCount*colorElements );
            }

            else
            {
                MColorArray colours;
#if MAYA_API_VERSION >= 700

                if ( !colorSet.isBlankSet )
                {
                    meshFn.getColors ( colours, &colorSet.name );
                }
                else
#endif
                {
                    meshFn.getFaceVertexColors ( colours );
                }

                if ( colours.length() > 0 )
                {
                    //    colorSource->setAccessorStride(4);
                    //    colorSource->SetValueCount(colours.length() + 1);
                    meshColorSet.resize ( ( colours.length() +1 ) *colorElements );

                    bool opaqueWhiteFound = false;

                    for ( uint j = 0; j < colours.length(); ++j )
                    {
                        //FMVector4 v = MConvert::ToFMVector4(colours[j]);
                        //if (IsEquivalent(v, FMVector4::One))
                        if ( colours[j].r == 1 && colours[j].g == 1 && colours[j].b == 1 && colours[j].a == 1 )
                        {
                            opaqueWhiteFound = true;
                            colorSet.whiteColorIndex = j;
                        }

                        //colorSource->SetValue(j, v);
                        meshColorSet[j*colorElements] = colours[j].r;
                        meshColorSet[j*colorElements+1] = colours[j].g;
                        meshColorSet[j*colorElements+2] = colours[j].b;
                        meshColorSet[j*colorElements+3] = colours[j].a;
                    }

                    if ( !opaqueWhiteFound )
                    {
                        //colorSource->SetValue(colours.length(), FMVector4::One); // put white at the end.
                        meshColorSet[colours.length() *colorElements] = 1;
                        meshColorSet[colours.length() *colorElements+1] = 1;
                        meshColorSet[colours.length() *colorElements+2] = 1;
                        meshColorSet[colours.length() *colorElements+3] = 1;
                        colorSet.whiteColorIndex = colours.length();
                    }

                    //    else colorSource->SetValueCount(colours.length());

                    else meshColorSet.resize ( colours.length() *colorElements );
                }
            }

            if ( colorSet.isBlankSet && ExportOptions::bakeLighting() )
            {
                // Delete the bake Lighting temporary per-vertex color node
                MGlobal::executeCommand ( MString ( "delete " ) + bakeLightingFn.name() );
            }
        }
    }

    // --------------------------------------------------
    void GeometryExporter::endExport()
    {
        closeLibrary();
    }

    // --------------------------------------------------
    bool GeometryExporter::exportNormals( 
        const MFnMesh &fnMesh, 
        const String &meshId,
        MFloatVectorArray &normals )
    {
        uint normalCount = normals.length();

        // Implement NormalSource
        COLLADA::FloatSource normalSource ( mSW );
        normalSource.setId ( meshId + NORMALS_SOURCE_ID_SUFFIX );
        normalSource.setNodeName ( meshId + NORMALS_SOURCE_ID_SUFFIX );
        normalSource.setArrayId ( meshId + NORMALS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        normalSource.setAccessorStride ( 3 );
        normalSource.setAccessorCount ( normalCount );
        normalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[0] );
        normalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[1] );
        normalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[2] );
        normalSource.prepareToAppendValues();

        uint verticesCount = ( uint ) fnMesh.numVertices();

        // TODO Don't put the source into the vertex sources, 
        // put it into the polygon sources.
        // That's about the other plugins, they don't support this.

        bool perVertexNormals = false;
        if ( ExportOptions::exportNormalsPerVertex() )
        {
            perVertexNormals = ( normalCount == verticesCount ); 
        }

        if ( perVertexNormals )
        {
            // Get the unindexed normals in a separate buffer
            MFloatVectorArray unindexedNormals;
            fnMesh.getNormals ( unindexedNormals, MSpace::kObject );

            // Index the normals to match the vertex indices
            for ( MItMeshPolygon meshPolygonIter ( fnMesh.object() ); 
                !meshPolygonIter.isDone(); meshPolygonIter.next() )
            {
                uint vertexCount = meshPolygonIter.polygonVertexCount();
                for ( uint i = 0; i < vertexCount; ++i )
                {
                    int normalIndex = meshPolygonIter.normalIndex ( i );
                    int vertexIndex = meshPolygonIter.vertexIndex ( i );
                    normals[vertexIndex] = unindexedNormals[normalIndex];
                }
            }

            if ( !SourceInput::containsSourceBase ( &mVertexSources, &normalSource ) )
                mVertexSources.push_back ( SourceInput ( normalSource, COLLADA::NORMAL ) );
        }
        else
        {
            // Retrieve the per-face, per-vertex normals
            fnMesh.getNormals ( normals, MSpace::kObject );

            mPolygonSources.push_back ( SourceInput ( normalSource, COLLADA::NORMAL ) );

            // Erase the normal source from the list of vertex sources, if it is inside
            SourceInput::eraseSourceBase ( &mVertexSources, &normalSource );
        }

        for ( uint i = 0; i < normalCount; ++i )
        {
            MFloatVector &normal = normals[i];
            normalSource.appendValues ( 
                COLLADA::MathUtils::equalsZero ( normal.x ) ? 0 : normal.x, 
                COLLADA::MathUtils::equalsZero ( normal.y ) ? 0 : normal.y, 
                COLLADA::MathUtils::equalsZero ( normal.z ) ? 0 : normal.z );
        }

        normalSource.finish();

        return perVertexNormals;
    }

    // --------------------------------------------------
    void GeometryExporter::exportTangents( 
        const MFnMesh &fnMesh, 
        const String &meshId, 
        const bool perVertexNormals,
        const MFloatVectorArray &normals )
    {
        // Implement TangentSource and BinormalSource
       if ( ExportOptions::exportTangents() )
        {
            // Geo-tangent and -binormal
            COLLADA::FloatSource tangentSource ( mSW );
            COLLADA::FloatSource binormalSource ( mSW );

            uint normalCount = fnMesh.numNormals();
            MVectorArray tangents ( normalCount ), binormals ( normalCount );

            if ( perVertexNormals )
            {
                // Calculate the geometric tangents and binormals(T/Bs)
                getPerVertexNormalsTangents(fnMesh, normals, tangents, binormals );

               if ( !SourceInput::containsSourceBase ( &mVertexSources, &tangentSource ) )
                   mVertexSources.push_back ( SourceInput ( tangentSource, COLLADA::GEOTANGENT ) );

               if ( !SourceInput::containsSourceBase ( &mVertexSources, &binormalSource ) )
                   mVertexSources.push_back ( SourceInput ( binormalSource, COLLADA::GEOBINORMAL ) );
            }
            else
            {
                // Calculate the geometric tangents and binormals(T/Bs)
                getTangents(fnMesh, normals, normalCount, binormals, tangents);

                // Erase the normal source from the list of vertex sources, if it is inside
                SourceInput::eraseSourceBase ( &mVertexSources, &tangentSource );
                SourceInput::eraseSourceBase ( &mVertexSources, &binormalSource );

                // Push them in the polygon sources list.
                mPolygonSources.push_back ( SourceInput ( tangentSource, COLLADA::GEOTANGENT ) );
                mPolygonSources.push_back ( SourceInput ( binormalSource, COLLADA::GEOBINORMAL ) );
            }

            // Geo-tangent
            tangentSource.setId ( meshId + GEOTANGENT_ID_SUFFIX );
            tangentSource.setNodeName ( meshId + GEOTANGENT_ID_SUFFIX );
            tangentSource.setArrayId ( meshId + GEOTANGENT_ID_SUFFIX + ARRAY_ID_SUFFIX );
            tangentSource.setAccessorStride ( 3 );
            tangentSource.getParameterNameList().push_back ( XYZW_PARAMETERS[0] );
            tangentSource.getParameterNameList().push_back ( XYZW_PARAMETERS[1] );
            tangentSource.getParameterNameList().push_back ( XYZW_PARAMETERS[2] );
            tangentSource.prepareToAppendValues();

            uint tangentCount = tangents.length();
            tangentSource.setAccessorCount ( tangentCount );
            for ( uint i = 0; i < tangentCount; ++i )
            {
                MVector &tangent = tangents[i];
                tangentSource.appendValues ( 
                    COLLADA::MathUtils::equalsZero ( tangent.x ) ? 0 : tangent.x, 
                    COLLADA::MathUtils::equalsZero ( tangent.y ) ? 0 : tangent.y, 
                    COLLADA::MathUtils::equalsZero ( tangent.z ) ? 0 : tangent.z );
            }
            tangentSource.finish();

            // Geo-binormal
            binormalSource.setId ( meshId + GEOBINORMAL_ID_SUFFIX );
            binormalSource.setNodeName ( meshId + GEOBINORMAL_ID_SUFFIX );
            binormalSource.setArrayId ( meshId + GEOBINORMAL_ID_SUFFIX + ARRAY_ID_SUFFIX );
            binormalSource.setAccessorStride ( 3 );
            binormalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[0] );
            binormalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[1] );
            binormalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[2] );
            binormalSource.prepareToAppendValues();

            uint binormalCount = binormals.length();
            binormalSource.setAccessorCount ( binormalCount );

            for ( uint i = 0; i < binormalCount; ++i )
            {
                MVector &binormal = binormals[i];
                binormalSource.appendValues ( 
                    COLLADA::MathUtils::equalsZero ( binormal.x ) ? 0 : binormal.x, 
                    COLLADA::MathUtils::equalsZero ( binormal.y ) ? 0 : binormal.y, 
                    COLLADA::MathUtils::equalsZero ( binormal.z ) ? 0 : binormal.z );
            }
            binormalSource.finish();
        }
    }

    // --------------------------------------------------
    void GeometryExporter::getPerVertexNormalsTangents( 
        const MFnMesh &fnMesh, 
        const MFloatVectorArray &normals, 
        MVectorArray &tangents, 
        MVectorArray &binormals )
    {
        // Calculate and export the geometric tangents and binormals(T/Bs)
        // Retrieve all the vertex positions for our calculations
        MPointArray vertexPositions;
        fnMesh.getPoints ( vertexPositions );
        uint vertexCount = vertexPositions.length();
        MObject meshObject ( fnMesh.object() );

        for ( MItMeshVertex vertexIt ( meshObject ); !vertexIt.isDone(); vertexIt.next() )
        {
            MIntArray vertexNeighbors;
            int vertexIndex = vertexIt.index();
            vertexIt.getConnectedVertices ( vertexNeighbors );

            if ( vertexNeighbors.length() == 0 || 
                vertexNeighbors[0] >= ( int ) vertexCount || 
                vertexIndex >= ( int ) vertexCount )
            {
                tangents[vertexIndex] = MFloatVector::yAxis;
                binormals[vertexIndex] = MFloatVector::zAxis;
                continue;
            }

            // Calculate the T/Bs (code repeated below)
            MPoint& neighborPosition = vertexPositions[vertexNeighbors[0]];
            MVector directionV = neighborPosition - vertexPositions[vertexIndex];
            tangents[vertexIndex] = ( directionV ^ normals[vertexIndex] ).normal();
            binormals[vertexIndex] = ( normals[vertexIndex] ^ tangents[vertexIndex] ).normal();
        }
    }

    // --------------------------------------------------
    void GeometryExporter::getTangents( 
        const MFnMesh &fnMesh, 
        const MFloatVectorArray &normals, 
        uint normalCount, 
        MVectorArray &binormals, 
        MVectorArray &tangents )
    {
        // Retrieve all the vertex positions for our calculations
        MPointArray vertexPositions;
        fnMesh.getPoints ( vertexPositions );
        uint vertexCount = vertexPositions.length();
        for ( uint i = 0; i < normalCount; ++i )
        {
            binormals[i] = tangents[i] = MFloatVector::zero;
        }

        for ( MItMeshPolygon faceIt ( fnMesh.object() ); !faceIt.isDone(); faceIt.next() )
        {
            int faceVertexCount = faceIt.polygonVertexCount();
            for ( int i = 0; i < faceVertexCount; ++i )
            {
                int normalIndex = faceIt.normalIndex ( i );
                if ( normalIndex >= ( int ) normalCount ) continue;

                // Don't recalculate T/Bs
                if ( !tangents[normalIndex].isEquivalent ( MFloatVector::zero ) ) continue;

                // Retrieve the vertex position and the position of its closest neighbor within the face
                int vertexIndex = faceIt.vertexIndex ( i );
                int neighborVertexIndex = faceIt.vertexIndex ( ( i == 0 ) ? faceVertexCount - 1 : i - 1 );
                if ( neighborVertexIndex >= ( int ) vertexCount || vertexIndex >= ( int ) vertexCount ) continue;

                MPoint& vertexPosition = vertexPositions[vertexIndex];
                MPoint& neighborPosition = vertexPositions[neighborVertexIndex];

                // Calculate the T/Bs (code repeated above)
                MFloatVector directionV = MFloatVector ( neighborPosition - vertexPosition );

                tangents[normalIndex] = ( directionV ^ normals[normalIndex] ).normal();
                binormals[normalIndex] = ( normals[normalIndex] ^ tangents[normalIndex] ).normal();
            }
        }
    }
}