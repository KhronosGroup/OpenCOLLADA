/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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
#include "COLLADAMayaControllerLibrary.h"
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
    bool SourceInput::containsSourceBase ( Sources* sources, COLLADA::SourceBase* searchedSourceBase )
    {
        bool sourceFound = false;

        Sources::iterator sourcesIter = sources->begin();

        for ( ; sourcesIter!=sources->end() && !sourceFound; ++sourcesIter )
        {
            SourceInput& sourceInput = *sourcesIter;
            COLLADA::SourceBase& sourceBase = sourceInput.mSource;

            if ( strcmp ( sourceBase.getId().c_str(), searchedSourceBase->getId().c_str() ) == 0 )
                sourceFound = true;
        }

        return sourceFound;
    }

    // --------------------------------------------------------
    bool SourceInput::eraseSourceBase ( Sources* sources, COLLADA::SourceBase* searchedSourceBase )
    {
        bool sourceFound = false;

        Sources::iterator sourcesIter = sources->begin();

        for ( ; sourcesIter!=sources->end() && !sourceFound; ++sourcesIter )
        {
            SourceInput& sourceInput = *sourcesIter;
            COLLADA::SourceBase& sourceBase = sourceInput.mSource;

            if ( strcmp ( sourceBase.getId().c_str(), searchedSourceBase->getId().c_str() ) == 0 )
            {
                sourceFound = true;
            }
        }

        if ( sourceFound )
        {
            sources->erase ( sourcesIter );
        }

        return sourceFound;
    }

    // --------------------------------------------------------
    GeometryExporter::GeometryExporter ( COLLADA::StreamWriter* streamWriter,
                                         DocumentExporter* documentExporter )
            : COLLADA::LibraryGeometries ( streamWriter ),
            mDocumentExporter ( documentExporter ),
            mExportedGeometries ( NULL )
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
        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        uint length = exportNodesTree->size();
        for ( uint i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];

#ifdef _DEBUG
            cout << "   Start export " << sceneElement->getNodeName() << endl;
#endif
           exportGeometries ( sceneElement );
        }

        endExport();
    }

    // --------------------------------------------------------
    void GeometryExporter::exportGeometries ( SceneElement* sceneElement )
    {
        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Check if it is a mesh and an export node

        if ( sceneElement->getType() == SceneElement::MESH &&
                sceneElement->getIsExportNode() )
        {
            // Get the controller library
            ControllerLibrary* controller = mDocumentExporter->getControllerLibrary();

            // Add the controller and/or geometry to our libraries
            bool hasSkinController =
                ExportOptions::exportJointsAndSkin() &&
                controller->hasSkinController ( dagPath.node() );
            sceneElement->setHasSkinController(hasSkinController);

            bool hasMorphController = controller->hasMorphController ( dagPath.node() );
            sceneElement->setHasMorphController(hasMorphController);

//             // Handle the controllers
//             if ( hasSkinController || hasMorphController )
//             {
//                 // TODO This isn't ready...
//                 // Create a skin/morph transform object and export the geometry
//                 clock_t startClock, endClock;
//                 startClock = clock();
//                 controller->exportController ( sceneElement, hasSkinController );
//                 endClock = clock();
//                 cout << "   Export controller: " << endClock - startClock << endl;
//             }
//             else
            {
                // Export the geometry directly in the collada document
#ifdef _DEBUG
                clock_t startClock, endClock;
                startClock = clock();
#endif
                exportGeometry ( dagPath );
#ifdef _DEBUG
                endClock = clock();
                cout << "   End export " << sceneElement->getNodeName() << ": " << endClock - startClock << endl;
#endif
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
    void GeometryExporter::exportGeometry ( const MDagPath& dagPath )
    {
        //  Get the node of the current mesh
        MObject meshNode = dagPath.node();

        // Attach a function set to the mesh node.
        // We access all of the meshes data through the function set
        MStatus status;
        MFnMesh fnMesh ( meshNode, &status );
        if ( status != MStatus::kSuccess ) return;

        // Create the unique ID
        MString nodeNameMaya = fnMesh.name();
        String nodeNameCollada = mDocumentExporter->mayaNameToColladaName ( nodeNameMaya, true );
        String meshId = /*GEOMETRY_ID_PRAEFIX +*/ nodeNameCollada;
//        String meshId = mDocumentExporter->dagPathToColladaId(dagPath);
  
        // Get the mesh name
        String meshName = mDocumentExporter->dagPathToColladaName(dagPath);

        // Write the mesh data
        exportMesh ( fnMesh, meshId, meshName );
    }

    // --------------------------------------------------------
    void GeometryExporter::exportMesh ( MFnMesh& fnMesh, String meshId, String &meshName )
    {
        // Check if the geometry isn't already exported
        std::vector<String>::iterator geometryIter;
        geometryIter = find ( mExportedGeometries.begin(), mExportedGeometries.end(), meshId );

        if ( geometryIter != mExportedGeometries.end() ) return;

        // Push the exported geometry in the export list
        mExportedGeometries.push_back ( meshId );

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

#ifdef _DEBUG
        clock_t startClock, endClock;
#endif

        // Export the vertex positions
#ifdef _DEBUG
        startClock = clock();
#endif
        exportVertexPositions ( fnMesh, meshId );
#ifdef _DEBUG
        endClock = clock();
        cout << "       Export vertex-positions: " << endClock - startClock << endl;
#endif

        // Export the vertex normals
#ifdef _DEBUG
        startClock = clock();
#endif
        bool hasFaceVertexNormals = exportVertexNormals ( fnMesh, meshId );
#ifdef _DEBUG
        endClock = clock();
        cout << "       Export vertex-normals: " << endClock - startClock << endl;
#endif
        
        // Export the texture coordinates
#ifdef _DEBUG
        startClock = clock();
#endif
        exportTextureCoords ( fnMesh, meshId, uvSetNames, texcoordIds );
#ifdef _DEBUG
        endClock = clock();
        cout << "       Export texture coordinates: " << endClock - startClock << endl;
#endif
        
        // exportVertexBlindData(fnMesh);
        
        // Export the color sets
#ifdef _DEBUG
        startClock = clock();
#endif
        exportColorSets ( fnMesh, meshId, colorSets );
#ifdef _DEBUG
        endClock = clock();
        cout << "       Export color sets: " << endClock - startClock << endl;
#endif
        
        // Export the vertexes
#ifdef _DEBUG
        startClock = clock();
#endif
        exportVertices ( meshId );
#ifdef _DEBUG
        endClock = clock();
        cout << "       Export vertexes: " << endClock - startClock << endl;
#endif


        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
        GeometryPolygonExporter polygonExporter ( streamWriter, mDocumentExporter );
#ifdef _DEBUG
        startClock = clock();
#endif
        polygonExporter.exportPolygonSources ( fnMesh, meshId,
                                         uvSetNames,
                                         colorSets,
                                         &mPolygonSources,
                                         &mVertexSources,
                                         hasFaceVertexNormals );
#ifdef _DEBUG
        endClock = clock();
        cout << "       Export polygons: " << endClock - startClock << endl;
#endif

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
        techniqueSource.openTechnique ( MAYA_PROFILE );
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
        fnMesh.getPoints ( vertexArray, MSpace::kObject );
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

            MFloatPoint positionTweak;
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
                animExporter->addPlugAnimation ( childPlug, VERTEX_SID, XYZW_PARAMETERS, kSingle | kLength );
            }
        }

        for ( uint i = 0; i < vertexCount; ++i )
        {
            MPoint &pointData = vertexArray[i];
            vertexSource.appendValues ( pointData.x, pointData.y, pointData.z );
        }

        vertexSource.finish();


        // Add input to the mesh <vertices> node
        mPolygonSources.push_back ( SourceInput ( vertexSource, COLLADA::VERTEX ) );
    }

    //---------------------------------------------------------------
    bool GeometryExporter::exportVertexNormals ( const MFnMesh& fnMesh, const String& meshId )
    {
        if ( !ExportOptions::exportNormals() ) return false;

        // --------------------------------------------------
        // Implement NormalSource

        COLLADA::FloatSource normalSource ( mSW );

        normalSource.setId ( meshId + NORMALS_SOURCE_ID_SUFFIX );
        normalSource.setNodeName ( meshId + NORMALS_SOURCE_ID_SUFFIX );
        normalSource.setArrayId ( meshId + NORMALS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        normalSource.setAccessorStride ( 3 );

        // Check for all smooth normals
        uint normalCount = fnMesh.numNormals();

        normalSource.setAccessorCount ( normalCount );
        normalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[0] );
        normalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[1] );
        normalSource.getParameterNameList().push_back ( XYZW_PARAMETERS[2] );
        normalSource.prepareToAppendValues();

        MFloatVectorArray normals ( normalCount );

        uint verticesCount = ( uint ) fnMesh.numVertices();

        bool perVertexNormals = ( normalCount == verticesCount );
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
            normalSource.appendValues ( normal.x, normal.y, normal.z );

            // TODO: find a better solution for the case of not existing normals
            //  if (isFinite(normal))
            //   normalSource.add(normal.x, normal.y, normal.z);
            //  else
            //   source.add(0, 0, 1);

        }

        normalSource.finish();


        // --------------------------------------------------
        // Implement TangentSource and BinormalSource

        if ( ExportOptions::exportTangents() )
        {
            uint normalCount = fnMesh.numNormals();

            // Geo-tangent and -binormal
            COLLADA::FloatSource tangentSource ( mSW );
            COLLADA::FloatSource binormalSource ( mSW );

            MVectorArray tangents ( normalCount ), binormals ( normalCount );

            if ( perVertexNormals )
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

                    if ( vertexNeighbors.length() == 0 || vertexNeighbors[0] >= ( int ) vertexCount || vertexIndex >= ( int ) vertexCount )
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

                if ( !SourceInput::containsSourceBase ( &mVertexSources, &tangentSource ) )
                    mVertexSources.push_back ( SourceInput ( tangentSource, COLLADA::GEOTANGENT ) );

                if ( !SourceInput::containsSourceBase ( &mVertexSources, &binormalSource ) )
                    mVertexSources.push_back ( SourceInput ( binormalSource, COLLADA::GEOBINORMAL ) );
            }

            else
            {
                // Calculate and export the geometric tangents and binormals(T/Bs)
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
                tangentSource.appendValues ( tangent.x, tangent.y, tangent.z );
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
                binormalSource.appendValues ( binormal.x, binormal.y, binormal.z );
            }

            binormalSource.finish();
        }

        return !perVertexNormals;
    }

    /**
     * Returns a list of names for each tex-coord id that corresponds to the equivalent
     * Maya uv set name, as returned by MFnMesh.getUVSetNames().
     */
    std::vector<String> GeometryExporter::generateTexCoordIds ( const MStringArray& uvSetNames,
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
    void GeometryExporter::exportColorSets ( const MFnMesh& fnMesh,
            const String& meshId,
            ColourSetList& colorSets )
    {
        if ( !ExportOptions::exportVertexColors() ) return;

        // Retrieve all the color set header information
        MeshHelper::getMeshValidColorSets ( fnMesh.object(), colorSets );

        // Process the color sets
        uint colorSetCount = colorSets.size();

        for ( uint i = 0; i < colorSetCount; ++i )
        {
            ColourSet& colorSet = *colorSets[i];
            String colorSetName = colorSet.name.asChar();

            if ( colorSet.name.length() == 0 ) continue;

            // Retrieve the color set data
            std::vector<float> meshColorSet;
            getMeshColorSet ( fnMesh.object(), meshColorSet, colorSet );

            // If we don't have a mesh color set, we don't need to implement a color source.
            uint numMeshColorSets = meshColorSet.size();
            if ( numMeshColorSets == 0 ) continue;

            // Create the id of the color source
            String colorSourceId = meshId + "-" + colorSetName;

            uint stride = 4;

            // Create the source
            COLLADA::FloatSourceF colorSource ( mSW );
            colorSource.setId ( colorSourceId );
            colorSource.setNodeName ( colorSourceId );
            colorSource.setArrayId ( colorSourceId + ARRAY_ID_SUFFIX );
            colorSource.setAccessorStride ( stride );
            colorSource.setAccessorCount ( numMeshColorSets/stride );
            for ( uint p=0; p<stride; ++p )
                colorSource.getParameterNameList().push_back ( RGBA_PARAMETERS[p] );
            colorSource.prepareToAppendValues();

            // Push the data from the meshColorSet into the color source of the collada document.
            colorSource.appendValues ( meshColorSet );
            colorSource.finish();


            if ( colorSet.isVertexColor )
            {
                // Insert a per-vertex color set input
                mVertexSources.push_back ( SourceInput ( colorSource, COLLADA::COLOR ) );
            }
            else
            {
                // Insert a per-face-vertex color set input
                mPolygonSources.push_back ( SourceInput ( colorSource, COLLADA::COLOR, i ) );
            }
        }
    }

    // --------------------------------------------------------------------
    void GeometryExporter::exportVertices ( const String& meshId )
    {
        COLLADA::Vertices vertices ( mSW );
        vertices.setId ( meshId + VERTICES_ID_SUFFIX );
        vertices.setNodeName ( meshId + VERTICES_ID_SUFFIX );

        // Get the input list
        COLLADA::InputList* inputList = &vertices.getInputList();

        // Always push the vertex positions in the vertices element
        // (we have to create a vertices element with a reference)
        inputList->push_back ( COLLADA::Input ( COLLADA::POSITION, "#" + meshId + POSITIONS_SOURCE_ID_SUFFIX ) );

        // Push all other vertex sources into the vertices element
        Sources::iterator it = mVertexSources.begin();

        for ( ; it!=mVertexSources.end(); ++it )
        {
            // Get the current vertices source and read the id
            SourceInput& sourceInput = *it;
            COLLADA::SourceBase& source = sourceInput.mSource;
            String sourceId = source.getId();

            // Get the type of the current vertex source
            COLLADA::Semantics& type = sourceInput.mType;

            // Push the vertex source to the collada vertices
            inputList->push_back ( COLLADA::Input ( type, "#" + sourceId ) );
        }

        vertices.add();
    }

    // --------------------------------------------------------------------
    /**
     * Export the texture coordinates listed in the two arrays given in argument,
     * that correspond respectively to the Maya uv set name and the collada texcoord id.
     */
    void GeometryExporter::exportTextureCoords ( const MFnMesh& fnMesh,
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
                texCoordSource.appendValues ( uArray[j], vArray[j] );
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
    void GeometryExporter::getMeshColorSet ( const MObject &mesh,
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

                // TODO TEST!
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

                MIntArray polygonOffsets ( polygonCount );

                polygonVertexIndices.resize ( polygonCount );

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

                size_t maxValueCount = max ( ( size_t ) elementCount, ( size_t ) vertexCount ) * 16; // * 16 to give enough space and avoid a resize that would break the export of animations..
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

    // --------------------------------------------------------
    void GeometryExporter::endExport()
    {
        closeLibrary();
    }

}