/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAStreamWriter.h"
#include "COLLADASource.h"
#include "COLLADABaseInputElement.h"
#include "COLLADAPrimitves.h"
#include "COLLADAUtils.h"

#include "COLLADAMaxGeometryExporter.h"
#include "COLLADAMaxMaterialExporter.h"
#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxControllerList.h"

#include "COLLADAMaxGeometryExtra.h"

#include "COLLADAMaxMultiMtl.h"

#include <algorithm>

#include <max.h>
#include <modstack.h>
#include <MeshNormalSpec.h>
#include <iparamb2.h>
#include <iparamm2.h>


// ST - TODO: Check where we should be sticking these defines..

// Defined in EditTriObj, in the 3dsMax samples
#define ET_MASTER_CONTROL_REF 0
#define ET_VERT_BASE_REF  1

// Defined in PolyEdit, in the 3dsMax samples
#define EPOLY_PBLOCK 0
#define EPOLY_MASTER_CONTROL_REF  1
#define EPOLY_VERT_BASE_REF 2


namespace COLLADAMax
{


    typedef std::vector<size_t> MaterialIDList;

    inline bool isFinite ( const Point3& p )
    {
        return _finite ( p.x ) && _finite ( p.y ) && _finite ( p.z );
    }


    const String GeometryExporter::COLOR_MATERIAL_SYMBOL = "ColorMaterial";


    const String GeometryExporter::SYMBOL_NAME_PREFIX = "channel";



    //---------------------------------------------------------------
    GeometryExporter::GeometryExporter ( ExportNode * exportNode, GeometriesExporter * geometriesExporter, DocumentExporter * documentExporter )
            : mExportNode ( exportNode ),
            mGeometriesExporter ( geometriesExporter ),
            mDocumentExporter ( documentExporter ),
			mMaterialChannelPairParamBlockMap(documentExporter->getEffectExporter()->getMaterialChannelPairParamBlockMap()),
            mPolyObject ( 0 ),
            mTriObject ( 0 ),
            mGeomObject ( 0 ),
            mDeleteObject ( false )
    {}



    //---------------------------------------------------------------
    String GeometryExporter::getTextureSourceIdSuffix ( int channel )
    {
        std::ostringstream idSuffix;
        idSuffix << COLLADA::LibraryGeometries::TEXTURE_CHANNEL_SOURCE_ID_SUFFIX << channel;
        return idSuffix.str();
    }




    //---------------------------------------------------------------
    void GeometryExporter::getBaseObjectAndID ( Object*& object, SClass_ID& sid )
    {
        if ( object == NULL )
            return ;

        sid = object->SuperClassID();

        if ( sid == WSM_DERIVOB_CLASS_ID || sid == DERIVOB_CLASS_ID || sid == GEN_DERIVOB_CLASS_ID )
        {
            IDerivedObject * derivedObject = ( IDerivedObject* ) object;

            if ( derivedObject->NumModifiers() > 0 )
            {
                // Remember that 3dsMax has the mod stack reversed in its internal structures.
                // So that evaluating the zero'th modifier implies evaluating the whole modifier stack.
                ObjectState state = derivedObject->Eval ( 0, 0 );
                object = state.obj;
            }

            else
            {
                object = derivedObject->GetObjRef();
            }

            sid = object->SuperClassID();
        }
    }



    //---------------------------------------------------------------
    void GeometryExporter::classifyObject ( Object* object /*, bool affectsControllers*/ )
    {
        SClass_ID sid;
        getBaseObjectAndID ( object, sid );

        Class_ID id = object->ClassID();

        bool exportEPolyAsTriangles = mDocumentExporter->getOptions().getExportEPolyAsTriangles();

        if ( !exportEPolyAsTriangles )
        {
            // Check for the possibility of an editable poly object.

            if ( sid == GEOMOBJECT_CLASS_ID && ( id == EPOLYOBJ_CLASS_ID || id.PartA() == POLYOBJ_CLASS_ID ) )
            {
                mPolyObject = ( PolyObject* ) object;
            }
        }

        if ( !mPolyObject )
        {
            // Check for the possibility of an editable mesh object.

            if ( sid == GEOMOBJECT_CLASS_ID && ( id.PartA() == EDITTRIOBJ_CLASS_ID || id.PartA() == TRIOBJ_CLASS_ID ) )
            {
                mTriObject = ( TriObject* ) object;
            }

            if ( !mTriObject )
            {
#if 0
                // Check for geometry primitives (Box, Cylinder, Torus, etc.) and convert them to TriObject
                // since they don't export well as PolyObject (controllers are messed up)

                if ( affectsControllers &&
                        ( id == Class_ID ( BOXOBJ_CLASS_ID, 0 ) ||
                          id == Class_ID ( SPHERE_CLASS_ID, 0 ) ||
                          id == Class_ID ( CYLINDER_CLASS_ID, 0 ) ||
#if (MAX_VERSION_MAJOR >= 8)
#ifndef NO_OBJECT_STANDARD_PRIMITIVES
                          id == PLANE_CLASS_ID ||
                          id == PYRAMID_CLASS_ID ||
                          id == GSPHERE_CLASS_ID ||
#endif // NO_OBJECT_STANDARD_PRIMITIVES
#endif // USE_MAX_8
                          id == Class_ID ( CONE_CLASS_ID, 0 ) ||
                          id == Class_ID ( TORUS_CLASS_ID, 0 ) ||
                          id == Class_ID ( TUBE_CLASS_ID, 0 ) ||
                          id == Class_ID ( HEDRA_CLASS_ID, 0 ) ||
                          id == Class_ID ( BOOLOBJ_CLASS_ID, 0 ) ) )
                {
                    if ( object->CanConvertToType ( Class_ID ( TRIOBJ_CLASS_ID, 0 ) ) )
                    {
                        mTriObject = ( TriObject* ) object->ConvertToType ( TIME_EXPORT_START, Class_ID ( TRIOBJ_CLASS_ID, 0 ) );
                        mDeleteObject = true;
                    }
                }

#endif

                if ( !mTriObject && !exportEPolyAsTriangles && object->CanConvertToType ( Class_ID ( POLYOBJ_CLASS_ID, 0 ) ) )
                {
                    mPolyObject = ( PolyObject* ) object->ConvertToType ( TIME_EXPORT_START, Class_ID ( POLYOBJ_CLASS_ID, 0 ) );
                    mDeleteObject = true;
                }

                if ( !mTriObject && !mPolyObject && object->CanConvertToType ( Class_ID ( TRIOBJ_CLASS_ID, 0 ) ) )
                {
                    mTriObject = ( TriObject* ) object->ConvertToType ( TIME_EXPORT_START, Class_ID ( TRIOBJ_CLASS_ID, 0 ) );
                    // ST - Copy over animated vertices, this is not done by default

                    if ( id == EPOLYOBJ_CLASS_ID || id.PartA() == POLYOBJ_CLASS_ID )
                    {
                        // Copy over any animated vertices, because that is not done by default.
                        int numVertControllers = object->NumRefs() - EPOLY_VERT_BASE_REF;

                        if ( numVertControllers > 0 )
                        {
                            // Initialize our triObj to recieve vert controllers.
                            mTriObject->ReplaceReference ( ET_VERT_BASE_REF, NULL );

                            // Assert we now have the same count
#ifdef _DEBUG

                            assert ( ( mTriObject->NumRefs() - ET_VERT_BASE_REF ) == numVertControllers );
#endif

                            for ( int i = 0; i < numVertControllers; ++i )
                            {
                                mTriObject->AssignController ( object->GetReference ( EPOLY_VERT_BASE_REF + i ), ET_VERT_BASE_REF + i );
                            }
                        }
                    }

                    mDeleteObject = true;
                }

                if ( !mTriObject && exportEPolyAsTriangles )
                {
                    // Last possibility: do check for an editable poly type that does not convert to a TriObject on its own.
                    //[untested].

                    if ( object->CanConvertToType ( Class_ID ( POLYOBJ_CLASS_ID, 0 ) ) )
                    {
                        PolyObject * tempPolyObject = ( PolyObject* ) object->ConvertToType ( TIME_EXPORT_START, Class_ID ( POLYOBJ_CLASS_ID, 0 ) );
                        mTriObject = ( TriObject* ) tempPolyObject->ConvertToType ( TIME_EXPORT_START, Class_ID ( TRIOBJ_CLASS_ID, 0 ) );
                        tempPolyObject->DeleteMe();
                        mDeleteObject = true;
                    }
                }
            }
        }

        mGeomObject = ( mPolyObject ) ? ( GeomObject* ) mPolyObject : ( GeomObject* ) mTriObject;
    }




    //---------------------------------------------------------------
    void GeometryExporter::doExport()
    {
        String id = mExportNode->getId();
        INode * iNode = mExportNode->getINode();

		mExportNode->createControllerList();

		Object * object = mExportNode->getInitialPose();
        //Object * object = mExportNode->getINode()->GetObjectRef();
       // Object * object = iNode->EvalWorldState ( 0 ).obj;

        if ( object )
        {

            // Retrieve the TriObject or PolyObject representation of this geometric object.
            classifyObject ( object /*, affectsControllers*/ );

            if ( !mGeomObject || ( !mTriObject && !mPolyObject ) )
			{	
				mExportNode->setTypeToUnknown();
                return ;
			}

            //Mesh & mesh = mTriObject->GetMesh();
			mId = GeometriesExporter::getGeometryId(*mExportNode);

            mGeometriesExporter->openMesh ( mId, COLLADA::Utils::checkNCName ( iNode->GetName() ) );

            exportPositions();

            exportNormals();

            ChannelList channelList;

            if ( isEditablePoly() )
            {
                MNMesh & mnMesh = mPolyObject->GetMesh();
                int chanNum = mnMesh.MNum();

                for ( int i = -NUM_HIDDENMAPS; i < chanNum; ++i )
                {
                    MNMap *map = mnMesh.M ( i );

                    if ( map == NULL )
                        continue;

                    if ( !map->GetFlag ( MN_DEAD ) )
                        channelList.push_back ( i );
                }
            }

            else
            {
                Mesh &triMesh = mTriObject->GetMesh();
                // according to SPARKS... valid maps = 0 (color) to MAX_MESHMAPS

                for ( int i = -NUM_HIDDENMAPS; i < MAX_MESHMAPS; ++i )
                {
                    if ( triMesh.mapSupport ( i ) )
                        channelList.push_back ( i );
                }
            }


            // Retrieve the list of materials assigned to the different polygons of this mesh
            Mtl* mat = iNode->GetMtl();

			exportTextures ( channelList, mat );

            MaterialList materials;

            if ( mat )
            {
                flattenMaterials ( mat, materials );
            }

            MaterialIDList materialIDs;

            size_t numMaterials = materials.size();

            //map<Matid, number of faces>
            std::map<size_t, size_t> facesPerMaterialIdMap;
            //map<Matid, COLLADA::Polylist>
            typedef std::map<size_t, COLLADA::Polylist> PolylistListPerMaterialIdMap;
            PolylistListPerMaterialIdMap polylistListPerMaterialIdMap;

            if ( isEditablePoly() )
            {
                if ( numMaterials > 1 )
                {
                    MNMesh & mnMesh = mPolyObject->GetMesh();
                    int numberOfFaces = mnMesh.FNum();

                    for ( int i = 0; i < numberOfFaces; ++i )
                    {
                        MNFace *face = mnMesh.F ( i );
                        size_t materialId = face->material % numMaterials;
                        PolylistListPerMaterialIdMap::iterator it = polylistListPerMaterialIdMap.find ( materialId );

                        if ( it == polylistListPerMaterialIdMap.end() )
                            it = ( polylistListPerMaterialIdMap.insert ( std::pair<size_t, COLLADA::Polylist> ( materialId, COLLADA::Polylist ( mGeometriesExporter->mSW ) ) ) ).first;

                        it->second.getVCountList().push_back ( face->deg );

                        if ( find ( materialIDs.begin(), materialIDs.end(), materialId ) == materialIDs.end() )
                            materialIDs.push_back ( materialId );
                    }
                }

                else
                {
                    polylistListPerMaterialIdMap.insert ( std::pair<size_t, COLLADA::Polylist> ( 0, COLLADA::Polylist ( mGeometriesExporter->mSW ) ) );
                    MNMesh &mnMesh = mPolyObject->GetMesh();
                    int numberOfFaces = mnMesh.FNum();

                    for ( int i = 0; i < numberOfFaces; ++i )
                    {
                        MNFace *face = mnMesh.F ( i );
                        polylistListPerMaterialIdMap[ 0 ].getVCountList().push_back ( face->deg );
                    }

                    materialIDs.push_back ( 0 );
                }
            }

            else
            {
                if ( numMaterials > 1 )
                {
                    Mesh & mesh = mTriObject->GetMesh();
                    int numberOfFaces = mesh.getNumFaces();

                    for ( int i = 0; i < numberOfFaces; ++i )
                    {
                        Face& face = mesh.faces[ i ];
                        size_t materialId = face.getMatID() % numMaterials;
                        facesPerMaterialIdMap[ materialId ] ++;

                        if ( find ( materialIDs.begin(), materialIDs.end(), materialId ) == materialIDs.end() )
                            materialIDs.push_back ( materialId );
                    }
                }

                else
                {
                    facesPerMaterialIdMap[ 0 ] = mTriObject->GetMesh().getNumFaces();
                    materialIDs.push_back ( 0 );
                }

            }

            exportVertices ( mId );

            // Create one COLLADA polygon set for each material used in the mesh
            //   FCDMaterial* blackMtl = NULL;

            for ( MaterialIDList::iterator it = materialIDs.begin(); it != materialIDs.end(); ++it )
            {
                size_t matID = *it;

                String symbol;

                if ( !mat )
                {
                    symbol = COLOR_MATERIAL_SYMBOL;
                }

                else
                {
                    Mtl* subMaterial = materials[ matID % numMaterials ];

                    if ( subMaterial )
                    {

                        // check for XRefs
                        /*      if (XRefFunctions::IsXRefMaterial(subMaterial))
                              {
                               if (!OPTS->ExportXRefs())
                               {
                                // resolve the source
                                subMaterial = XRefFunctions::GetXRefMaterialSource(subMaterial);
                               }
                               // else do nothing, this is only a material instance
                              }
                        */
                        // if this is a XRef it'll return NULL
                        symbol = mExportNode->getSymbolByMaterialAndSetAsUsed ( subMaterial );

                    }

                    else
                    {
                        assert ( false );
                        /*if (blackMtl == NULL)*/
                    }
                }

                // Add the polygons set input and its tessellation indices

                if ( isEditablePoly() )
                    exportPolylist ( symbol, polylistListPerMaterialIdMap[ matID ], numMaterials <= 1 ? -1 : ( int ) matID, numMaterials, channelList );
                else
                    exportTriangles ( symbol, ( unsigned long ) facesPerMaterialIdMap[ matID ], numMaterials <= 1 ? -1 : ( int ) matID, numMaterials, channelList );
            }


            mGeometriesExporter->closeMesh();

            GeometryExtra geometryExtra ( mGeometriesExporter->mSW, object );

            geometryExtra.doExport();



            mGeometriesExporter->closeGeometry();
        }

    }



    //---------------------------------------------------------------
    void GeometryExporter::exportPositions()
    {
        COLLADA::FloatSource source ( mGeometriesExporter->mSW );
        source.setId ( mId + COLLADA::LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX );
        source.setArrayId ( mId + COLLADA::LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX + COLLADA::LibraryGeometries::ARRAY_ID_SUFFIX );
        source.setAccessorStride ( 3 );
        source.getParameterNameList().push_back ( "X" );
        source.getParameterNameList().push_back ( "Y" );
        source.getParameterNameList().push_back ( "Z" );

        if ( isEditablePoly() )
        {
            // editable poly. case
            MNMesh & mnMesh = mPolyObject->GetMesh();
            int vertexCount = mnMesh.VNum();
            source.setAccessorCount ( vertexCount );
            source.prepareToAppendValues();

            for ( int i = 0; i < vertexCount; ++i )
            {
                Point3 &position = mnMesh.V ( i ) ->p;
                source.appendValues ( position.x, position.y, position.z );
            }
        }

        else
        {
            Mesh & mesh = mTriObject->GetMesh();
            int vertexCount = mesh.numVerts;
            source.setAccessorCount ( vertexCount );
            source.prepareToAppendValues();

            for ( int i = 0; i < vertexCount; ++i )
            {
                Point3 & position = mesh.verts[ i ];
                source.appendValues ( position.x, position.y, position.z );
            }
        }

        source.finish();
    }


    //---------------------------------------------------------------
    void GeometryExporter::exportNormals()
    {
        if ( isEditablePoly() )
            exportEditablePolyNormals();
        else
            exportTriangleMeshNormals();
    }

    //---------------------------------------------------------------
    void GeometryExporter::exportTriangleMeshNormals()
    {
        Mesh & mesh = mTriObject->GetMesh();
        MeshNormalSpec *normalSpec = mesh.GetSpecifiedNormals();

        if ( normalSpec == NULL )
        {
            mesh.SpecifyNormals();
            normalSpec = mesh.GetSpecifiedNormals();
        }

        if ( normalSpec->GetNumNormals() == 0 )
        {
            normalSpec->SetParent ( &mesh );
            normalSpec->CheckNormals();
        }

        if ( normalSpec == NULL )
            return ;

        if ( normalSpec->GetNumNormals() == 0 )
        {
            normalSpec->SetParent ( &mesh );
            normalSpec->CheckNormals();
        }

        int normalCount = normalSpec->GetNumNormals();

        COLLADA::FloatSource source ( mGeometriesExporter->mSW );
        source.setId ( mId + COLLADA::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX );
        source.setArrayId ( mId + COLLADA::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX + COLLADA::LibraryGeometries::ARRAY_ID_SUFFIX );
        source.setAccessorStride ( 3 );
        source.setAccessorCount ( normalCount );
        source.getParameterNameList().push_back ( "X" );
        source.getParameterNameList().push_back ( "Y" );
        source.getParameterNameList().push_back ( "Z" );
        source.prepareToAppendValues();

        for ( int i = 0; i < normalCount; ++i )
        {
            Point3 & normal = normalSpec->Normal ( i );
            // TODO: find a better solution for the case of not existing normals

            if ( isFinite ( normal ) )
                source.appendValues ( normal.x, normal.y, normal.z );
            else
                source.appendValues ( 0, 0, 1 );
        }

        source.finish();
    }


    //---------------------------------------------------------------
    void GeometryExporter::exportEditablePolyNormals()
    {
        MNMesh & mnMesh = mPolyObject->GetMesh();
        MNNormalSpec *mnNormalSpec = mnMesh.GetSpecifiedNormals();

        if ( mnNormalSpec == NULL )
        {
            mnMesh.SpecifyNormals();
            mnNormalSpec = mnMesh.GetSpecifiedNormals();
        }

        if ( mnNormalSpec == NULL )
            return ;

        // rebuild as needed
        mnNormalSpec->CheckNormals();

        int normalCount = mnNormalSpec->GetNumNormals();

        if ( normalCount == 0 )
            return ;

        COLLADA::FloatSource source ( mGeometriesExporter->mSW );

        source.setId ( mId + COLLADA::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX );

        source.setArrayId ( mId + COLLADA::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX + COLLADA::LibraryGeometries::ARRAY_ID_SUFFIX );

        source.setAccessorStride ( 3 );

        source.setAccessorCount ( normalCount );

        source.getParameterNameList().push_back ( "X" );

        source.getParameterNameList().push_back ( "Y" );

        source.getParameterNameList().push_back ( "Z" );

        source.prepareToAppendValues();

        for ( int i = 0; i < normalCount; ++i )
        {
            Point3 & normal = mnNormalSpec->Normal ( i );
            // TODO: find a better solution for the case of not existing normals

            if ( isFinite ( normal ) )
                source.appendValues ( normal.x, normal.y, normal.z );
            else
                source.appendValues ( 0, 0, 1 );
        }

        source.finish();
    }



    //---------------------------------------------------------------
    void GeometryExporter::exportTextures ( const ChannelList & channelList, Mtl* material )
    {
        // Export the map channel sources (valid indices are from -2 to 99)
        // Offset the negative map channels indices by MAX_MESHMAPS, in order to bring
        // the -2,-1 channels into non-negative range and not clash with the valid map channels.

        for ( size_t i = 0; i < channelList.size(); ++i )
        {
            exportTextureChannel ( channelList[ i ], material );
        }
    }


    //---------------------------------------------------------------
    void GeometryExporter::exportTextureChannel ( int channelIndex, Mtl* material )
    {
        // return if channel index is invalid
        /* if (channelIndex >= mesh.getNumMaps() || channelIndex < -NUM_HIDDENMAPS)
          return;*/

        COLLADA::FloatSource source ( mGeometriesExporter->mSW );
        String sourceId = mId + getTextureSourceIdSuffix ( channelIndex );
        source.setId ( sourceId );
        source.setArrayId ( sourceId + COLLADA::LibraryGeometries::ARRAY_ID_SUFFIX );
        source.setAccessorStride ( 3 );

        if ( channelIndex <= 0 )
        {
            source.getParameterNameList().push_back ( "R" );
            source.getParameterNameList().push_back ( "G" );
            source.getParameterNameList().push_back ( "B" );
        }

        else
        {
            source.getParameterNameList().push_back ( "S" );
            source.getParameterNameList().push_back ( "T" );
            source.getParameterNameList().push_back ( "P" );
        }

		/* start testing */

		bool applyUVTransformation = false;
		Matrix3 uvTransfomationMatrix;

		if ( material )
		{
			int numSubTexMaps = material->NumSubTexmaps();

			Texmap* map = 0;
			for ( int i = 0; (i < numSubTexMaps) && !map; i++ )
			{
				map = material->GetSubTexmap ( i );
			}

			if ( map )
			{
				map->GetUVTransform(uvTransfomationMatrix);
				applyUVTransformation = !uvTransfomationMatrix.IsIdentity();
			}
		}

/*		EffectExporter::MaterialChannelPairParamBlockMap::const_iterator it = mMaterialChannelPairParamBlockMap.find(EffectExporter::MaterialChannelPair(material, channelIndex));

		IParamBlock * uVGenParamBlock = 0;

		if ( it != mMaterialChannelPairParamBlockMap.end() ) 
			uVGenParamBlock = it->second;

		float wAngle = 0;
		if ( uVGenParamBlock )
			wAngle = uVGenParamBlock->GetFloat(StdUVGenEnums::w_angle, TIME_EXPORT_START);

			*/
		/* end testing*/

        if ( isEditablePoly() )
        {
            MNMesh & mnMesh = mPolyObject->GetMesh();
            MNMap *mnMap = mnMesh.M ( channelIndex );

            if ( !mnMap )
                return ;

            int mapVertexCount = mnMap->numv;

            source.setAccessorCount ( mapVertexCount );

            source.prepareToAppendValues();

            for ( int i = 0; i < mapVertexCount; ++i )
            {
                UVVert texCoord = mnMap->V ( i );

                // TODO: find a better solution for the case of not existing texture coordinates

                if ( isFinite ( texCoord ) )
				{
					if ( applyUVTransformation )
						texCoord = uvTransfomationMatrix * texCoord;
                    source.appendValues ( texCoord.x, texCoord.y, texCoord.z );
				}
                else
				{
                    source.appendValues ( 0, 0, 1 );
				}
            }
        }

        else
        {
            MeshMap& meshMap = mTriObject->GetMesh().Map ( channelIndex );
            int mapVertexCount = meshMap.getNumVerts();
            source.setAccessorCount ( mapVertexCount );
            source.prepareToAppendValues();

            for ( int i = 0; i < mapVertexCount; ++i )
            {
                Point3& texCoord = meshMap.tv[ i ];

                // TODO: find a better solution for the case of not existing texture coordinates

                if ( isFinite ( texCoord ) )
				{
					if ( applyUVTransformation )
						texCoord = uvTransfomationMatrix * texCoord;
                    source.appendValues ( texCoord.x, texCoord.y, texCoord.z );
				}
                else
				{
                    source.appendValues ( 0, 0, 1 );
				}
            }

        }

        source.finish();
    }


    void GeometryExporter::exportVertices ( const String & meshId )
    {
        COLLADA::Vertices vertices ( mGeometriesExporter->mSW );
        vertices.setId ( meshId + COLLADA::LibraryGeometries::VERTICES_ID_SUFFIX );
        vertices.getInputList().push_back ( COLLADA::Input ( COLLADA::POSITION, "#" + meshId + COLLADA::LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX ) );
        vertices.add();
    }



    //---------------------------------------------------------------
    void GeometryExporter::exportTriangles ( const String & symbol, unsigned long numberOfFaces, int matId, size_t numMaterials, const ChannelList & channelList )
    {

        Mesh & mesh = mTriObject->GetMesh();

        MeshNormalSpec *norms = mesh.GetSpecifiedNormals();

        int offset = 0;
        COLLADA::Triangles triangles ( mGeometriesExporter->mSW );
        triangles.setCount ( numberOfFaces );
        triangles.setMaterial ( symbol );
        triangles.getInputList().push_back ( COLLADA::Input ( COLLADA::VERTEX, "#" + mId + COLLADA::LibraryGeometries::VERTICES_ID_SUFFIX, offset++ ) );
        triangles.getInputList().push_back ( COLLADA::Input ( COLLADA::NORMAL, "#" + mId + COLLADA::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX, offset++ ) );

        for ( ChannelList::const_iterator it = channelList.begin(); it != channelList.end(); ++it )
        {
            triangles.getInputList().push_back ( COLLADA::Input ( ( *it <= 0 ) ? COLLADA::COLOR : COLLADA::TEXCOORD, "#" + mId + getTextureSourceIdSuffix ( *it ), offset++, *it ) );
        }

        triangles.prepareToAppendValues();

        for ( int faceIndex = 0; faceIndex < mesh.numFaces; ++faceIndex )
        {
            Face& face = mesh.faces[ faceIndex ];

            if ( numMaterials <= 1 || face.getMatID() % numMaterials == matId )
            {
                for ( int vertexIndex = 0; vertexIndex < 3; ++vertexIndex )
                {
                    triangles.appendValues ( face.v[ vertexIndex ], norms->GetNormalIndex ( faceIndex, vertexIndex ) );

                    for ( ChannelList::const_iterator it = channelList.begin(); it != channelList.end(); ++it )
                    {
                        int channel = *it;

                        if ( channel < mesh.getNumMaps() && channel >= -NUM_HIDDENMAPS )
                        {
                            MeshMap & tmap = mesh.Map ( channel );
                            TVFace& tvFace = tmap.tf[ faceIndex ];
                            triangles.appendValues ( tvFace.t[ vertexIndex ] );
                        }
                    }
                }
            }

        }

        triangles.finish();
    }


    //---------------------------------------------------------------
    void GeometryExporter::exportPolylist ( const String & symbol, COLLADA::Polylist & polylist, int matId, size_t numMaterials, const ChannelList & channelList )
    {
        MNMesh & mnMesh = mPolyObject->GetMesh();

        MNNormalSpec *normmalSpec = mnMesh.GetSpecifiedNormals();

        int offset = 0;
        polylist.setCount ( ( unsigned long ) polylist.getVCountList().size() );
        polylist.setMaterial ( symbol );
        polylist.getInputList().push_back ( COLLADA::Input ( COLLADA::VERTEX, "#" + mId + COLLADA::LibraryGeometries::VERTICES_ID_SUFFIX, offset++ ) );
        polylist.getInputList().push_back ( COLLADA::Input ( COLLADA::NORMAL, "#" + mId + COLLADA::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX, offset++ ) );

        for ( ChannelList::const_iterator it = channelList.begin(); it != channelList.end(); ++it )
        {
            polylist.getInputList().push_back ( COLLADA::Input ( ( *it <= 0 ) ? COLLADA::COLOR : COLLADA::TEXCOORD, "#" + mId + getTextureSourceIdSuffix ( *it ), offset++, *it ) );
        }

        polylist.prepareToAppendValues();

        int numberOfFaces = mnMesh.FNum();

        for ( int faceIndex = 0; faceIndex < numberOfFaces; ++faceIndex )
        {
            MNFace * mnFace = mnMesh.F ( faceIndex );

            if ( numMaterials <= 1 || mnFace->material % numMaterials == matId )
            {
                int vertexCount = mnFace->deg;

                for ( int vertexIndex = 0; vertexIndex < vertexCount; ++vertexIndex )
                {
                    polylist.appendValues ( mnFace->vtx[ vertexIndex ], normmalSpec->GetNormalIndex ( faceIndex, vertexIndex ) );

                    for ( ChannelList::const_iterator it = channelList.begin(); it != channelList.end(); ++it )
                    {
                        int channel = *it;
                        MNMap * mnMap = mnMesh.M ( channel );
                        assert ( mnMap != 0 );
                        MNMapFace * mnMapFace = mnMap->F ( faceIndex );
                        assert ( mnMapFace != 0 );
                        polylist.appendValues ( mnMapFace->tv[ vertexIndex ] );
                    }
                }
            }

        }

        polylist.finish();
    }



    // from fcollada
    //---------------------------------------------------------------
    void GeometryExporter::flattenMaterials ( Mtl* material, MaterialList& materialMap, int materialIndex )
    {
        // check for XRefs
        /* if (material != NULL && XRefFunctions::IsXRefMaterial(material))
         {
          material = XRefFunctions::GetXRefMaterialSource(material);
         }
        */
        // KEEP THE NULL POINTER! Null pointers are actually allowed in max, and we need to
        // maintain the material list.
        Class_ID matId = ( material == NULL ) ?
                         Class_ID ( STANDIN_CLASS_ID, STANDIN_CLASS_ID ) :
                         material->ClassID();

        if ( matId == Class_ID ( MULTI_CLASS_ID, 0 ) )
        {
            if ( materialIndex < 0 )
            {
                // Read in the sub-materials
                int nbSubMtl = material->NumSubMtls();

                for ( int i = 0; i < nbSubMtl; ++i )
                {
                    Mtl *subMtl = material->GetSubMtl ( i );
                    flattenMaterials ( subMtl, materialMap, i );
                }
            }

            else
            {
                // If we are in a recursive multi-material, read in the correctly indexed sub-material
                Mtl* subMtl = MaterialExporter::GetSubMaterialById ( material, materialIndex );

                if ( subMtl )
                    flattenMaterials ( subMtl, materialMap );
                else
                    subMtl = material->GetSubMtl ( 0 );
            }
        }

        else if ( matId == Class_ID ( BAKE_SHELL_CLASS_ID, 0 ) )
        {
            // Read in the first sub-material only
            flattenMaterials ( material->GetSubMtl ( 1 ), materialMap );
        }

        /*else if (XRefFunctions::IsXRefMaterial(material))
        {
        // Add this material as a leaf
        materialMap.push_back(material);
        } */

        else
        {
            // Add this material as a leaf
            materialMap.push_back ( material );
        }
    }

}
