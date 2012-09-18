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

#include "COLLADASWSource.h"
#include "COLLADASWBaseInputElement.h"
#include "COLLADASWInputList.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWExtra.h"

namespace COLLADAMaya
{

    // --------------------------------------------------------
    GeometryExporter::GeometryExporter ( COLLADASW::StreamWriter* streamWriter,
                                         DocumentExporter* documentExporter )
    : COLLADASW::LibraryGeometries ( streamWriter )
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
            exportGeometries ( sceneElement, sceneElement->getIsVisible () );
        }

        endExport();
    }

    // --------------------------------------------------------
    void GeometryExporter::exportGeometries ( SceneElement* sceneElement, bool isVisible )
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;

        bool exportSceneElement = false;
        SceneElement::Type sceneElementType = sceneElement->getType();
        if ( sceneElementType == SceneElement::MESH ) 
        {
            if ( sceneElement->getIsExportNode () ) exportSceneElement = true;
            else 
            {
                if ( sceneElement->getIsForced () ) exportSceneElement = true;
                else if ( !isVisible && ExportOptions::exportInvisibleNodes () ) exportSceneElement = true;
            }
        }

        if ( exportSceneElement )
        {
            // Get the current dag path
            MDagPath dagPath = sceneElement->getPath();

            // Check if the current scene element isn't already exported.
            SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
            if ( sceneGraph->findExportedElement ( dagPath ) ) return;

            // Check if the current element is an instance. 
            // We don't need to export instances, because we export the original instanced element.
            bool isInstance = ( dagPath.isInstanced() && dagPath.instanceNumber() > 0 );

            // If the original instanced element isn't already exported, we have to export it now.
            if ( isInstance )
            {
                // Get the original instanced element.
                MDagPath instancedPath;
                dagPath.getPath ( instancedPath, 0 );

                // Check if the original instanced element is already exported.
                SceneElement* exportedElement = sceneGraph->findExportedElement ( instancedPath );
                if ( exportedElement == 0 )
                {
                    // Export the original instanced element.
                    SceneElement* instancedSceneElement = sceneGraph->findElement ( instancedPath );
                    exportControllerOrGeometry ( instancedSceneElement );
                }
            }
            else
            {
                // Handle the geometry in depend on it is a controller or not.
                exportControllerOrGeometry ( sceneElement );
            }
        }

        // Check if the element is visible (inherit visibility to children)
        if ( isVisible ) isVisible = sceneElement->getIsVisible ();

        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportGeometries ( childElement, isVisible );
        }
    }

    // --------------------------------------------------------
    void GeometryExporter::exportControllerOrGeometry ( 
        SceneElement* sceneElement )
    {
        // Get the controller library
        ControllerExporter* controller = mDocumentExporter->getControllerExporter();

        // Get the current node element.
        MObject node = sceneElement->getPath ().node();

        // Add the controller and/or geometry to our libraries
        bool hasSkinController = ExportOptions::exportJointsAndSkin() && controller->hasSkinController ( node );
        bool hasMorphController = controller->hasMorphController ( node );
        if ( hasSkinController || hasMorphController )
        {
            // Handle the controllers
            handleControllers ( sceneElement );
        }
        else
        {
            // Export the element and push it in the exported scene graph. 
            if ( exportGeometry ( sceneElement ) )
            {
                SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
                sceneGraph->addExportedElement( sceneElement );
            }
        }
    }

    // --------------------------------------------------------
    bool GeometryExporter::exportGeometry ( SceneElement* sceneElement )
    {
        if ( !ExportOptions::exportPolygonMeshes() ) return false;

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();
        String pathName = dagPath.fullPathName ().asChar ();

        // Generate the unique collada mesh id.
        const String& colladaMeshId = generateColladaMeshId ( dagPath );
        if ( colladaMeshId.empty () ) return false;

        // Set the node id.
        sceneElement->setNodeId ( colladaMeshId );

        bool isInstanced = dagPath.isInstanced();
        uint instanceNumber = dagPath.instanceNumber();

        //  Get the node of the current mesh
        MObject meshNode = dagPath.node();

        // Attach a function set to the mesh node.
        // We access all of the meshes data through the function set
        MStatus status;
        MFnMesh fnMesh ( meshNode, &status );
        if ( status != MStatus::kSuccess ) return false;

        // Write the mesh data
        String meshName = mDocumentExporter->dagPathToColladaName ( dagPath );
        return exportMesh ( fnMesh, colladaMeshId, meshName );
    }

    // --------------------------------------------------------
    const String GeometryExporter::generateColladaMeshId ( const MDagPath dagPath )
    {
        // Get the maya mesh id.
        String mayaMeshId = mDocumentExporter->dagPathToColladaId ( dagPath );

        // Generate a COLLADA id for the new object.
        String colladaMeshId = findColladaGeometryId ( mayaMeshId );

        // Check, if the unique id for the current geometry is already generated.
        if ( !colladaMeshId.empty () ) return colladaMeshId;

        // Get the node of the current mesh
        MObject meshNode = dagPath.node();

        // Attach a function set to the mesh node.
        // We access all of the meshes data through the function set
        MStatus status;
        MFnMesh fnMesh ( meshNode, &status );
        if ( status != MStatus::kSuccess ) return colladaMeshId;

        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( meshNode, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            colladaMeshId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
        }
        else
        {
            // Generate a COLLADA id for the new object
            colladaMeshId = DocumentExporter::mayaNameToColladaName ( fnMesh.name() );
        }

        // Make the id unique and store it in a map.
        colladaMeshId = mGeometryIdList.addId ( colladaMeshId );
        mMayaIdColladaIdMap [ mayaMeshId ] = colladaMeshId;

        return colladaMeshId;
    }

    // --------------------------------------------------------
    bool GeometryExporter::exportMesh ( 
        MFnMesh& fnMesh, 
        const String& colladaMeshId, 
        const String& mayaMeshName )
    {
        // Clear the list with the current polygons and the list with the vertexes
        mPolygonSources.clear();
        mVertexSources.clear();

        // Retrieve all uv set names for this mesh.
        MStringArray uvSetNames;
        getUVSetNames ( fnMesh, uvSetNames );

        // Opens the mesh tag in the collada document
        openMesh ( colladaMeshId, mayaMeshName );

        // Export the vertex positions
        exportVertexPositions ( fnMesh, colladaMeshId );

        // Export the vertex normals
        bool hasFaceVertexNormals = exportVertexNormals ( fnMesh, colladaMeshId );
        
        // Export the texture coordinates
        exportTextureCoords ( fnMesh, colladaMeshId, uvSetNames );
        
        // The list for the color sets. We have to clean!
        MStringArray colorSetNames;

        // Export the color sets
        exportColorSets ( fnMesh, colladaMeshId, colorSetNames );
        
        // Export the texture tangents and binormals.
        // For texturing std::map channels, export the texture tangents and bi-normals, on request
        if ( ExportOptions::exportTexTangents() )
        {
            exportTextureTangentsAndBinormals ( fnMesh, colladaMeshId );
        }

        // Export the vertexes
        exportVertices ( colladaMeshId );

        // Create a polygon exporter and export the polygon sources.
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        GeometryPolygonExporter polygonExporter ( streamWriter, mDocumentExporter );
        polygonExporter.exportPolygonSources ( fnMesh, colladaMeshId, uvSetNames, colorSetNames, &mPolygonSources, &mVertexSources, hasFaceVertexNormals );

        closeMesh();

        // Export the original maya name and the double sided value in an extra tag.
        exportExtraTechniqueParameters ( fnMesh, mayaMeshName );

        closeGeometry();

        return true;
    }

    // --------------------------------------------------------
    void GeometryExporter::getUVSetNames ( const MFnMesh& fnMesh, MStringArray& uvSetNames )
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
    void GeometryExporter::exportExtraTechniqueParameters ( 
        const MFnMesh& fnMesh, 
        const String& mayaMeshName )
    {
        bool doubleSided = isDoubleSided ( fnMesh );

        COLLADASW::Extra extraSource ( mSW );
        extraSource.openExtra();

        COLLADASW::Technique techniqueSource ( mSW );
        techniqueSource.openTechnique ( PROFILE_MAYA );
        techniqueSource.addParameter ( PARAMETER_MAYA_ID, mayaMeshName );
        techniqueSource.addParameter ( PARAMETER_DOUBLE_SIDED, doubleSided );
        techniqueSource.closeTechnique();

        extraSource.closeExtra();
    }

    // --------------------------------------------------------
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
        COLLADASW::FloatSource vertexSource ( mSW );
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
                animExporter->addPlugAnimation ( childPlug, VERTEX_SID, kSingle | kLength, XYZW_PARAMETERS, true, -1, true );
            }
        }

        for ( uint i = 0; i < vertexCount; ++i )
        {
            // Convert the  maya internal unit type from centimeters 
            // into the working units of the current scene!
            MPoint &pointData = vertexArray[i];
            vertexSource.appendValues ( 
                COLLADABU::Math::Utils::equalsZero ( vertexArray[i].x, getTolerance () ) ? 0 : MDistance::internalToUI ( vertexArray[i].x ), 
                COLLADABU::Math::Utils::equalsZero ( vertexArray[i].y, getTolerance () ) ? 0 : MDistance::internalToUI ( vertexArray[i].y ), 
                COLLADABU::Math::Utils::equalsZero ( vertexArray[i].z, getTolerance () ) ? 0 : MDistance::internalToUI ( vertexArray[i].z ) );
        }
        vertexSource.finish();

        // Add input to the mesh <vertices> node
        mPolygonSources.push_back ( SourceInput ( vertexSource, COLLADASW::InputSemantic::VERTEX ) );
    }

    //---------------------------------------------------------------
    bool GeometryExporter::exportVertexNormals ( 
        const MFnMesh& fnMesh, 
        const String& meshId )
    {
        if ( !ExportOptions::exportNormals () ) return false;

        // Export the normals
        uint normalCount = fnMesh.numNormals ();
        MFloatVectorArray normals ( normalCount );
        bool perVertexNormals = exportNormals ( fnMesh, meshId, normals );

        // Export the tangents
        exportTangentsAndBinormals ( fnMesh, meshId, perVertexNormals, normals );

        return !perVertexNormals;
    }

    // -------------------------------------------------------
    void GeometryExporter::exportColorSets ( 
        const MFnMesh& fnMesh,
        const String& meshId,
        MStringArray& colorSetNames )
    {
        if ( !ExportOptions::exportVertexColors() ) return;

        //MStringArray colorSetNames;
        fnMesh.getColorSetNames ( colorSetNames );
        size_t numColorSets = colorSetNames.length ();

        // Process the color sets
        for ( unsigned int i=0; i<numColorSets; ++i )
        {
            const MString mColorSetName = colorSetNames [i];
            String colorSetName = mColorSetName.asChar ();
            if ( colorSetName.length() == 0 ) continue;

            // Retrieve the color set data
            MColorArray colorArray;
            fnMesh.getColors ( colorArray, &mColorSetName );
            size_t numColorValues = colorArray.length ();
            if ( numColorValues == 0 ) continue;

            size_t stride = 4;
            String colorId = meshId + "-" + colorSetName;

            // Create the source
            COLLADASW::FloatSourceF colorSource ( mSW );
            colorSource.setId ( colorId );
            colorSource.setNodeName ( colorId );
            colorSource.setArrayId ( colorId + ARRAY_ID_SUFFIX );
            colorSource.setAccessorStride ( ( unsigned long ) stride );
            colorSource.setAccessorCount ( ( unsigned long ) numColorValues );
            for ( size_t p=0; p<stride; ++p )
                colorSource.getParameterNameList().push_back ( RGBA_PARAMETERS[p] );
            colorSource.prepareToAppendValues();

            // Push the data from the colorSet into the color source of the collada document.
            for ( unsigned int j=0; j<numColorValues; ++j )
            {
                MColor color = colorArray[j];
                colorSource.appendValues ( color.r, color.g, color.b, color.a );
            }

            colorSource.finish();
            
            // Don't put the source into the vertex sources, put it into the polygon sources.
            // That's about the other plug-ins, they don't support this.
            bool perVertexColor = false;
            if ( ExportOptions::exportVertexColorsPerVertex() )
            {
                uint verticesCount = ( uint ) fnMesh.numVertices();
                perVertexColor = ( numColorValues == verticesCount ); 
            }

            if ( perVertexColor )
            {
                // Insert a per-vertex color set input
                mVertexSources.push_back ( SourceInput ( colorSource, COLLADASW::InputSemantic::COLOR, i ) );
            }
            else
            {
                // Insert a per-face-vertex color set input
                mPolygonSources.push_back ( SourceInput ( colorSource, COLLADASW::InputSemantic::COLOR, i ) );
            }
        }
    }

    // --------------------------------------------------------------------
    void GeometryExporter::exportVertices ( const String& meshId )
    {
        COLLADASW::VerticesElement vertices ( mSW );
        vertices.setId ( meshId + VERTICES_ID_SUFFIX );
        vertices.setNodeName ( meshId + VERTICES_ID_SUFFIX );

        // Get the input list
        COLLADASW::InputList* inputList = &vertices.getInputList();

        // Always push the vertex positions in the vertices element
        // (we have to create a vertices element with a reference)
        inputList->push_back ( COLLADASW::Input ( COLLADASW::InputSemantic::POSITION, COLLADASW::URI ( EMPTY_STRING, meshId + POSITIONS_SOURCE_ID_SUFFIX ) ) );

        // Push all other vertex sources into the vertices element
        Sources::iterator it = mVertexSources.begin();
        for ( ; it!=mVertexSources.end(); ++it )
        {
            // Get the current vertices source and read the id
            const SourceInput& sourceInput = *it;
            const COLLADASW::SourceBase& source = sourceInput.getSource();
            String sourceId = source.getId();

            // Get the type of the current vertex source
            const COLLADASW::InputSemantic::Semantics& type = sourceInput.getType();

            // Push the vertex source to the collada vertices
            inputList->push_back ( COLLADASW::Input ( type, COLLADASW::URI ( EMPTY_STRING, sourceId ) ) );
        }

        vertices.add();
    }

    // --------------------------------------------------------------------
    void GeometryExporter::exportTextureCoords ( 
        const MFnMesh& fnMesh,
        const String& meshId,
        const MStringArray& uvSetNames )
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

            // Get the stride
            uint stride = 2;
            String texCoordId = meshId + "-" + uvSetNameStr;

            COLLADASW::FloatSource texCoordSource ( mSW );
            texCoordSource.setId ( texCoordId );
            texCoordSource.setNodeName ( texCoordId );
            texCoordSource.setArrayId ( texCoordId + ARRAY_ID_SUFFIX );
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
                    COLLADABU::Math::Utils::equalsZero ( uArray[j], getTolerance () ) ? 0 : uArray[j], 
                    COLLADABU::Math::Utils::equalsZero ( vArray[j], getTolerance () ) ? 0 : vArray[j] );
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

            mPolygonSources.push_back ( SourceInput ( texCoordSource, COLLADASW::InputSemantic::TEXCOORD, realIndex ) );
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
        COLLADASW::FloatSource normalSource ( mSW );
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

        // Don't put the source into the vertex sources, put it into the polygon sources.
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
                mVertexSources.push_back ( SourceInput ( normalSource, COLLADASW::InputSemantic::NORMAL ) );
        }
        else
        {
            // Retrieve the per-face, per-vertex normals
            fnMesh.getNormals ( normals, MSpace::kObject );

            // Erase the normal source from the list of vertex sources, if it is inside
            mPolygonSources.push_back ( SourceInput ( normalSource, COLLADASW::InputSemantic::NORMAL ) );
            SourceInput::eraseSourceBase ( &mVertexSources, &normalSource );
        }

        for ( uint i = 0; i < normalCount; ++i )
        {
            MFloatVector &normal = normals[i];
            normalSource.appendValues ( 
                COLLADABU::Math::Utils::equalsZero ( normal.x, getTolerance () ) ? 0 : normal.x, 
                COLLADABU::Math::Utils::equalsZero ( normal.y, getTolerance () ) ? 0 : normal.y, 
                COLLADABU::Math::Utils::equalsZero ( normal.z, getTolerance () ) ? 0 : normal.z );
        }

        normalSource.finish();

        return perVertexNormals;
    }

    // --------------------------------------------------------
    void GeometryExporter::exportTextureTangentsAndBinormals (
        const MFnMesh &fnMesh,
        const String& meshId ) 
    {
        // Get the names of the used uv sets.
        MStringArray uvSetNames;
        fnMesh.getUVSetNames ( uvSetNames );
        unsigned int numUvSets = uvSetNames.length ();
        
        // Write the texture tangents
        for ( unsigned int i=0; i<numUvSets; ++i )
        {
            MString uvSetName = uvSetNames [i];

            // Texture Tangents
            MFloatVectorArray texTangents;
            fnMesh.getTangents ( texTangents, MSpace::kObject, &uvSetName );

            // Just export, if the tangents exist.
            unsigned int texTangentsCount = texTangents.length ();
            if ( texTangentsCount != 0 )
            {
                COLLADASW::FloatSource texTangentSource ( mSW );
                String texTangentSourceId = meshId + TEXTANGENT_SOURCE_ID_SUFFIX;
                if ( numUvSets > 1 ) texTangentSourceId += COLLADABU::Utils::toString (i+1);
                texTangentSource.setId ( texTangentSourceId );
                texTangentSource.setArrayId ( texTangentSourceId + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
                texTangentSource.setAccessorStride ( 3 );
                texTangentSource.setAccessorCount( (unsigned long)texTangentsCount );

                texTangentSource.getParameterNameList().push_back ( XYZW_PARAMETERS[0] );
                texTangentSource.getParameterNameList().push_back ( XYZW_PARAMETERS[1] );
                texTangentSource.getParameterNameList().push_back ( XYZW_PARAMETERS[2] );

                texTangentSource.prepareToAppendValues();
                for ( unsigned int j=0; j<texTangentsCount; ++j )
                {
                    MFloatVector& texTangent = texTangents [j];
                    texTangentSource.appendValues ( 
                        COLLADABU::Math::Utils::equalsZero ( texTangent.x, getTolerance () ) ? 0.0 : texTangent.x, 
                        COLLADABU::Math::Utils::equalsZero ( texTangent.y, getTolerance () ) ? 0.0 : texTangent.y, 
                        COLLADABU::Math::Utils::equalsZero ( texTangent.z, getTolerance () ) ? 0.0 : texTangent.z ); 
                }
                texTangentSource.finish();

                // Add input to the mesh polygon's node.
                mPolygonSources.push_back ( SourceInput ( texTangentSource, COLLADASW::InputSemantic::TEXTANGENT, (int) i ) );
            }

            // Texture Binormals
            MFloatVectorArray texBinormals;
            fnMesh.getBinormals ( texBinormals, MSpace::kObject, &uvSetName );

            // Just export, if the tangents exist.
            unsigned int texBinormalsCount = texBinormals.length ();
            if ( texBinormalsCount != 0 )
            {
                COLLADASW::FloatSource texBinormalSource ( mSW );
                String texBinormalSourceId = meshId + TEXBINORMAL_SOURCE_ID_SUFFIX;
                if ( numUvSets > 1 ) texBinormalSourceId += COLLADABU::Utils::toString (i+1);
                texBinormalSource.setId ( texBinormalSourceId );
                texBinormalSource.setArrayId ( texBinormalSourceId + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
                texBinormalSource.setAccessorStride ( 3 );
                texBinormalSource.setAccessorCount( (unsigned long)texBinormalsCount );

                texBinormalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[0] );
                texBinormalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[1] );
                texBinormalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[2] );

                texBinormalSource.prepareToAppendValues();
                for ( unsigned int j=0; j<texBinormalsCount; ++j )
                {
                    MFloatVector& texBinormal = texBinormals [j];
                    texBinormalSource.appendValues ( 
                        COLLADABU::Math::Utils::equalsZero ( texBinormal.x, getTolerance () ) ? 0 : texBinormal.x, 
                        COLLADABU::Math::Utils::equalsZero ( texBinormal.y, getTolerance () ) ? 0 : texBinormal.y, 
                        COLLADABU::Math::Utils::equalsZero ( texBinormal.z, getTolerance () ) ? 0 : texBinormal.z ); 
                }
                texBinormalSource.finish();

                // Add input to the mesh polygon's node.
                mPolygonSources.push_back ( SourceInput ( texBinormalSource, COLLADASW::InputSemantic::TEXBINORMAL, (int) i ) );
            }
        }
    }

    // --------------------------------------------------
    void GeometryExporter::exportTangentsAndBinormals ( 
        const MFnMesh &fnMesh, 
        const String &meshId, 
        const bool perVertexNormals,
        const MFloatVectorArray &normals )
    {
        // Implement TangentSource and BinormalSource
       if ( ExportOptions::exportTangents() )
       {
            // Geo-tangent and -binormal
            COLLADASW::FloatSource tangentSource ( mSW );
            COLLADASW::FloatSource binormalSource ( mSW );

            // Geo-tangent
            tangentSource.setId ( meshId + TANGENT_ID_SUFFIX );
            tangentSource.setNodeName ( meshId + TANGENT_ID_SUFFIX );
            tangentSource.setArrayId ( meshId + TANGENT_ID_SUFFIX + ARRAY_ID_SUFFIX );
            tangentSource.setAccessorStride ( 3 );
            tangentSource.getParameterNameList().push_back ( XYZW_PARAMETERS[0] );
            tangentSource.getParameterNameList().push_back ( XYZW_PARAMETERS[1] );
            tangentSource.getParameterNameList().push_back ( XYZW_PARAMETERS[2] );

            // Geo-binormal
            binormalSource.setId ( meshId + BINORMAL_ID_SUFFIX );
            binormalSource.setNodeName ( meshId + BINORMAL_ID_SUFFIX );
            binormalSource.setArrayId ( meshId + BINORMAL_ID_SUFFIX + ARRAY_ID_SUFFIX );
            binormalSource.setAccessorStride ( 3 );
            binormalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[0] );
            binormalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[1] );
            binormalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[2] );

            uint normalCount = fnMesh.numNormals();
            MVectorArray tangents ( normalCount ), binormals ( normalCount );

            if ( perVertexNormals )
            {
                // Calculate the geometric tangents and binormals(T/Bs)
                getPerVertexNormalsTangents ( fnMesh, normals, tangents, binormals );

               if ( !SourceInput::containsSourceBase ( &mVertexSources, &tangentSource ) )
                   mVertexSources.push_back ( SourceInput ( tangentSource, COLLADASW::InputSemantic::TANGENT ) );

               if ( !SourceInput::containsSourceBase ( &mVertexSources, &binormalSource ) )
                   mVertexSources.push_back ( SourceInput ( binormalSource, COLLADASW::InputSemantic::BINORMAL ) );
            }
            else
            {
                // Calculate the geometric tangents and binormals(T/Bs)
                getTangents ( fnMesh, normals, normalCount, binormals, tangents );

                // Erase the normal source from the list of vertex sources, if it is inside
                SourceInput::eraseSourceBase ( &mVertexSources, &tangentSource );
                SourceInput::eraseSourceBase ( &mVertexSources, &binormalSource );

                // Push them in the polygon sources list.
                mPolygonSources.push_back ( SourceInput ( tangentSource, COLLADASW::InputSemantic::TANGENT ) );
                mPolygonSources.push_back ( SourceInput ( binormalSource, COLLADASW::InputSemantic::BINORMAL ) );
            }

            // Geo-tangent
            uint tangentCount = tangents.length();
            tangentSource.setAccessorCount ( tangentCount );
            tangentSource.prepareToAppendValues();
            for ( uint i = 0; i < tangentCount; ++i )
            {
                MVector &tangent = tangents[i];
                tangentSource.appendValues ( 
                    COLLADABU::Math::Utils::equalsZero ( tangent.x, getTolerance () ) ? 0 : tangent.x, 
                    COLLADABU::Math::Utils::equalsZero ( tangent.y, getTolerance () ) ? 0 : tangent.y, 
                    COLLADABU::Math::Utils::equalsZero ( tangent.z, getTolerance () ) ? 0 : tangent.z );
            }
            tangentSource.finish();

            // Geo-binormal
            uint binormalCount = binormals.length();
            binormalSource.setAccessorCount ( binormalCount );
            binormalSource.prepareToAppendValues();
            for ( uint i = 0; i < binormalCount; ++i )
            {
                MVector &binormal = binormals[i];
                binormalSource.appendValues ( 
                    COLLADABU::Math::Utils::equalsZero ( binormal.x, getTolerance () ) ? 0 : binormal.x, 
                    COLLADABU::Math::Utils::equalsZero ( binormal.y, getTolerance () ) ? 0 : binormal.y, 
                    COLLADABU::Math::Utils::equalsZero ( binormal.z, getTolerance () ) ? 0 : binormal.z );
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
    void GeometryExporter::getTangents ( 
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

    // ------------------------------------
    const String& GeometryExporter::findColladaGeometryId ( const String& mayaMeshId )
    {
        const StringToStringMap::const_iterator it = mMayaIdColladaIdMap.find ( mayaMeshId );
        if ( it != mMayaIdColladaIdMap.end () )
        {
            return it->second;
        }
        return EMPTY_STRING;
    }

    // ------------------------------------
    void GeometryExporter::handleControllers ( 
        SceneElement* sceneElement )
    {
        // Get the scene graph 
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();

        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // The stacks of the controllers for the affected nodes.
        ControllerStack stack;
        ControllerMeshStack meshStack;

        // Iterate upstream finding all the nodes which affect the mesh.
        if ( !ControllerExporter::findAffectedNodes( dagPath.node(), stack, meshStack ) ) return;

//         // Disable the blend shape influences.
//         ControllerExporter::disableBlendShape( stack );
        // Disable any effects on the nodes.
        ControllerExporter::setControllerNodeStatesToNoEffect ( stack );
        // Set all meshes as visible and not intermediate.
        ControllerExporter::setValidMeshParameters ( meshStack );

        // Export the element and push it in the exported scene graph. 
        if ( exportGeometry ( sceneElement ) )
        {
            sceneGraph->addExportedElement( sceneElement );
        }

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
                    if ( exportGeometry ( meshSceneElement ) )
                    {
                        // Push it in the list of exported elements.
                        sceneGraph->addExportedElement( meshSceneElement );
                    }
                }
            }
        }

        // Reset all the controller node states.
        ControllerExporter::resetControllerNodeStates ( stack );
//         // Enable the blend shape influences.
//         ControllerExporter::enableBlendShape ( stack );
        // Reset the meshes as visible and not intermediate.
        ControllerExporter::resetMeshParameters ( meshStack );
        // Delete the controller stack items and clear the stack.
        ControllerExporter::deleteControllerStackItems ( stack );
    }


    // ------------------------------------
    const String& GeometryExporter::getColladaGeometryId ( MDagPath dagPath )
    {
        // Get the node of the current mesh
        MObject meshNode = dagPath.node();
        if ( !meshNode.hasFn ( MFn::kMesh ) ) 
        {
            MGlobal::displayError ( "No mesh object!" );
            return EMPTY_STRING;
        }

        // Attach a function set to the mesh node.
        // We access all of the meshes data through the function set
        MStatus status;
        MFnMesh fnMesh ( meshNode, &status );
        if ( status != MStatus::kSuccess ) 
        {
            MGlobal::displayError ( "No mesh object!" );
            return EMPTY_STRING;
        }

        // Get the maya mesh id.
        String mayaMeshId = mDocumentExporter->dagPathToColladaId ( dagPath );

        // Check for instances.
        bool isInstanced = fnMesh.isInstanced ( true );
        if ( isInstanced )
        {
            // Take the first instance.
            MDagPathArray dagPathes;
            fnMesh.getAllPaths ( dagPathes );
            mayaMeshId = mDocumentExporter->dagPathToColladaId ( dagPathes[0] );
        }

        // Get the geometry collada id.
        const String& colladaMeshId = findColladaGeometryId ( mayaMeshId );

        return colladaMeshId;
    }

}