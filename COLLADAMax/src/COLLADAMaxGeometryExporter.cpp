/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAMaxStableHeaders.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWSource.h"
#include "COLLADASWBaseInputElement.h"
#include "COLLADASWPrimitves.h"
#include "COLLADASWControlVertices.h"

#include "COLLADAMaxGeometryExporter.h"
#include "COLLADAMaxMaterialExporter.h"
#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxControllerList.h"

#include "COLLADAMaxGeometryExtra.h"

#include "COLLADAMaxMultiMtl.h"

#include "COLLADAMaxXRefFunctions.h"

#include "COLLADAMaxMeshAccess.h"
#include "COLLADAMaxTexTangentCalculator.h"

#include <algorithm>

#include <max.h>
#include <modstack.h>
#include <MeshNormalSpec.h>
#include <iparamb2.h>
#include <iparamm2.h>

#include <patch.h>

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



	inline bool isFinite( const Point3& p )
	{
		return _finite( p.x ) && _finite( p.y ) && _finite( p.z );
	}


	const String GeometryExporter::COLOR_MATERIAL_SYMBOL = "ColorMaterial";


	const String GeometryExporter::SYMBOL_NAME_PREFIX = "channel";



	//---------------------------------------------------------------
	GeometryExporter::GeometryExporter( ExportNode * exportNode, GeometriesExporter * geometriesExporter, DocumentExporter * documentExporter )
		: mExportNode( exportNode ),
		mMorphControllerHelperGeometry(0),
		mGeometriesExporter( geometriesExporter ),
		mDocumentExporter( documentExporter ),
		mMaterialChannelPairParamBlockMap(documentExporter->getEffectExporter()->getMaterialChannelPairParamBlockMap()),
		mPolyObject( 0 ),
		mTriObject( 0 ),
		mGeomObject( 0 ),
		mDeleteObject( false ), 
		mExportNormals( documentExporter->getOptions().getExportNormals() ),
		mExportTextangentsAndNormals( mExportNormals && documentExporter->getOptions().getExportTangents() )
	{}

	//---------------------------------------------------------------
	GeometryExporter::GeometryExporter( const MorphControllerHelperGeometry * helperGeometry, GeometriesExporter * geometriesExporter, DocumentExporter * documentExporter )
		: mExportNode( helperGeometry->exportNode ),
		mMorphControllerHelperGeometry(helperGeometry),
		mGeometriesExporter( geometriesExporter ),
		mDocumentExporter( documentExporter ),
		mMaterialChannelPairParamBlockMap(documentExporter->getEffectExporter()->getMaterialChannelPairParamBlockMap()),
		mPolyObject( 0 ),
		mTriObject( 0 ),
		mGeomObject( 0 ),
		mDeleteObject( false )	, 
		mExportNormals( documentExporter->getOptions().getExportNormals() ),
		mExportTextangentsAndNormals( mExportNormals && documentExporter->getOptions().getExportTangents() )
	{}



	bool GeometryExporter::isNURBS(Object* object)
	{
		if( !object ) 
			return false;
		Class_ID objId = object->ClassID();

		if (!(	objId == EDITABLE_CVCURVE_CLASS_ID ||
			objId == EDITABLE_FPCURVE_CLASS_ID ||
			objId == EDITABLE_SURF_CLASS_ID    ||
			objId == FITPOINT_PLANE_CLASS_ID))
		{
			return false;
		}

		return true;
	}


	//---------------------------------------------------------------
	String GeometryExporter::getTextureSourceIdSuffix( int channel )
	{
		std::ostringstream idSuffix;
		idSuffix << COLLADASW::LibraryGeometries::TEXCOORDS_SOURCE_ID_SUFFIX << channel;
		return idSuffix.str();
	}

	//---------------------------------------------------------------
	String GeometryExporter::getTextangentSourceIdSuffix( int channel )
	{
		return getTextureSourceIdSuffix( channel) + COLLADASW::LibraryGeometries::TEXTANGENT_SOURCE_ID_SUFFIX;
	}

	//---------------------------------------------------------------
	String GeometryExporter::getTexbinormalSourceIdSuffix( int channel )
	{
		return getTextureSourceIdSuffix( channel) + COLLADASW::LibraryGeometries::TEXBINORMAL_SOURCE_ID_SUFFIX;
	}

	//---------------------------------------------------------------
	void GeometryExporter::getBaseObjectAndID( Object*& object, SClass_ID& sid )
	{
		if( object == NULL )
			return ;

		sid = object->SuperClassID();

		if( sid == WSM_DERIVOB_CLASS_ID || sid == DERIVOB_CLASS_ID || sid == GEN_DERIVOB_CLASS_ID )
		{
			IDerivedObject * derivedObject =( IDerivedObject* ) object;

			if( derivedObject->NumModifiers() > 0 )
			{
				// Remember that 3dsMax has the mod stack reversed in its internal structures.
				// So that evaluating the zero'th modifier implies evaluating the whole modifier stack.
				ObjectState state = derivedObject->Eval( 0, 0 );
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
	void GeometryExporter::classifyObject( Object* object /*, bool affectsControllers*/ )
	{
		SClass_ID sid;
		getBaseObjectAndID( object, sid );

		TimeValue animationStart = mDocumentExporter->getOptions().getAnimationStart();

		Class_ID id = object->ClassID();

		bool exportEPolyAsTriangles = mDocumentExporter->getOptions().getExportEPolyAsTriangles() || mExportTextangentsAndNormals;

		if( !exportEPolyAsTriangles )
		{
			// Check for the possibility of an editable poly object.

			if( sid == GEOMOBJECT_CLASS_ID &&( id == EPOLYOBJ_CLASS_ID || id.PartA() == POLYOBJ_CLASS_ID ) )
			{
				mPolyObject =( PolyObject* ) object;
			}
		}

		if( !mPolyObject )
		{
			// Check for the possibility of an editable mesh object.

			if( sid == GEOMOBJECT_CLASS_ID &&( id.PartA() == EDITTRIOBJ_CLASS_ID || id.PartA() == TRIOBJ_CLASS_ID ) )
			{
				mTriObject =( TriObject* ) object;
			}

			if( !mTriObject )
			{
#if 0
				// Check for geometry primitives (Box, Cylinder, Torus, etc.) and convert them to TriObject
				// since they don't export well as PolyObject (controllers are messed up)

				if( affectsControllers &&
					( id == Class_ID( BOXOBJ_CLASS_ID, 0 ) ||
					id == Class_ID( SPHERE_CLASS_ID, 0 ) ||
					id == Class_ID( CYLINDER_CLASS_ID, 0 ) ||
#if (MAX_VERSION_MAJOR >= 8)
#ifndef NO_OBJECT_STANDARD_PRIMITIVES
					id == PLANE_CLASS_ID ||
					id == PYRAMID_CLASS_ID ||
					id == GSPHERE_CLASS_ID ||
#endif // NO_OBJECT_STANDARD_PRIMITIVES
#endif // USE_MAX_8
					id == Class_ID( CONE_CLASS_ID, 0 ) ||
					id == Class_ID( TORUS_CLASS_ID, 0 ) ||
					id == Class_ID( TUBE_CLASS_ID, 0 ) ||
					id == Class_ID( HEDRA_CLASS_ID, 0 ) ||
					id == Class_ID( BOOLOBJ_CLASS_ID, 0 ) ) )
				{
					if( object->CanConvertToType( Class_ID( TRIOBJ_CLASS_ID, 0 ) ) )
					{
						mTriObject =( TriObject* ) object->ConvertToType( animationStart, Class_ID( TRIOBJ_CLASS_ID, 0 ) );
						mDeleteObject = true;
					}
				}

#endif

				if( !mTriObject && !exportEPolyAsTriangles && object->CanConvertToType( Class_ID( POLYOBJ_CLASS_ID, 0 ) ) )
				{
					mPolyObject =( PolyObject* ) object->ConvertToType( animationStart, Class_ID( POLYOBJ_CLASS_ID, 0 ) );
					mDeleteObject = true;
				}

				if( !mTriObject && !mPolyObject && object->CanConvertToType( Class_ID( TRIOBJ_CLASS_ID, 0 ) ) )
				{
					mTriObject =( TriObject* ) object->ConvertToType( animationStart, Class_ID( TRIOBJ_CLASS_ID, 0 ) );
					// ST - Copy over animated vertices, this is not done by default

					if( id == EPOLYOBJ_CLASS_ID || id.PartA() == POLYOBJ_CLASS_ID )
					{
						// Copy over any animated vertices, because that is not done by default.
						int numVertControllers = object->NumRefs() - EPOLY_VERT_BASE_REF;

						if( numVertControllers > 0 )
						{
							// Initialize our triObj to recieve vert controllers.
							mTriObject->ReplaceReference( ET_VERT_BASE_REF, NULL );

							// Assert we now have the same count
#ifdef _DEBUG

							assert( ( mTriObject->NumRefs() - ET_VERT_BASE_REF ) == numVertControllers );
#endif

							for( int i = 0; i < numVertControllers; ++i )
							{
								mTriObject->AssignController( object->GetReference( EPOLY_VERT_BASE_REF + i ), ET_VERT_BASE_REF + i );
							}
						}
					}

					mDeleteObject = true;
				}

				if( !mTriObject && exportEPolyAsTriangles )
				{
					// Last possibility: do check for an editable poly type that does not convert to a TriObject on its own.
					//[untested].

					if( object->CanConvertToType( Class_ID( POLYOBJ_CLASS_ID, 0 ) ) )
					{
						PolyObject * tempPolyObject =( PolyObject* ) object->ConvertToType( animationStart, Class_ID( POLYOBJ_CLASS_ID, 0 ) );
						mTriObject =( TriObject* ) tempPolyObject->ConvertToType( animationStart, Class_ID( TRIOBJ_CLASS_ID, 0 ) );
						tempPolyObject->DeleteMe();
						mDeleteObject = true;
					}
				}
			}
		}

		mGeomObject =( mPolyObject ) ?( GeomObject* ) mPolyObject :( GeomObject* ) mTriObject;
	}


	//---------------------------------------------------------------
	void GeometryExporter::doExport()
	{
		switch (mExportNode->getType())
		{
		case ExportNode::MESH:
			doExportMesh();
			break;
		case ExportNode::SPLINE:
			doExportSpline();
			break;
		}
	}


	//---------------------------------------------------------------
	void GeometryExporter::doExportMesh()
	{

		if( !mMorphControllerHelperGeometry && !(mExportNode->getIsInVisualScene() || mExportNode->getIsReferenced()) )
			return;

		INode * iNode = mExportNode->getINode();

		Object * object;
		// Max does not apply any controller to morph targets. Therefore we need the base geometry if we export helper geometries.
		if( mMorphControllerHelperGeometry )
			object = mExportNode->getINode()->GetObjectRef();
		else
			object = mExportNode->getInitialPose();


		if( !object )
			return;

		if( object )
		{

			// Retrieve the list of materials assigned to the different polygons of this mesh
			Mtl* nodeMaterial = iNode->GetMtl();

			MaterialList materials;

			if( nodeMaterial )
			{
				flattenMaterials( nodeMaterial, materials );
			}

			GeometriesExporter::MaterialIDList& materialIDs = mGeometriesExporter->getExportedObjectMaterialIDListMap()[object];

			ExportNode* exportedObjectExportNode = mDocumentExporter->getExportedObjectExportNode(ObjectIdentifier(object));

			if( !mMorphControllerHelperGeometry && exportedObjectExportNode )
			{
				// We only need to set the required material symbols as used.
				setSymbolsAsUsed(mExportNode, exportedObjectExportNode, materialIDs, materials);
				return;
			}

			// Retrieve the TriObject or PolyObject representation of this geometric object.
			classifyObject( object /*, affectsControllers*/ );

			if( !mGeomObject ||( !mTriObject && !mPolyObject ) )
			{	
				mExportNode->setTypeToUnknown();
				return ;
			}

			if( mMorphControllerHelperGeometry )
				//assert(false); // solve id problem in mDocumentExporter->insertExportedObject(ObjectIdentifier(object), mExportNode);
				mId = ExportSceneGraph::getMorphControllerHelperId(*mMorphControllerHelperGeometry);
			else
				mId = GeometriesExporter::getGeometryId(*mExportNode);

			if( !mMorphControllerHelperGeometry )
				mDocumentExporter->insertExportedObject(ObjectIdentifier( object ), mExportNode);

			mGeometriesExporter->openMesh( mId, COLLADASW::Utils::checkNCName( NativeString(iNode->GetName()) ) );

			if( mMorphControllerHelperGeometry )
				exportMorphHelperPositions();
			else
				exportPositions();

			if( mExportNormals )
			{
				exportNormals();
			}

			ChannelList channelList;

			if( isEditablePoly() )
			{
				MNMesh & mnMesh = mPolyObject->GetMesh();
				int chanNum = mnMesh.MNum();

				for( int i = -NUM_HIDDENMAPS; i < chanNum; ++i )
				{
					MNMap *map = mnMesh.M( i );

					if( map == NULL )
						continue;

					if( !map->GetFlag( MN_DEAD ) )
						channelList.push_back( i );
				}
			}
			else
			{
				Mesh &triMesh = mTriObject->GetMesh();
				// according to SPARKS... valid maps = 0 (color) to MAX_MESHMAPS

				for( int i = -NUM_HIDDENMAPS; i < MAX_MESHMAPS; ++i )
				{
					if( triMesh.mapSupport( i ) )
						channelList.push_back( i );
				}
			}

			exportTextures( channelList, nodeMaterial );

			size_t numMaterials = materials.size();

			//map<Matid, number of faces>
			std::map<size_t, size_t> facesPerMaterialIdMap;
			//map<Matid, COLLADASW::Polylist>
			typedef std::map<size_t, COLLADASW::Polylist> PolylistListPerMaterialIdMap;
			PolylistListPerMaterialIdMap polylistListPerMaterialIdMap;

			if( isEditablePoly() )
			{
				if( numMaterials > 1 )
				{
					MNMesh & mnMesh = mPolyObject->GetMesh();
					int numberOfFaces = mnMesh.FNum();

					for( int i = 0; i < numberOfFaces; ++i )
					{
						MNFace *face = mnMesh.F( i );
						size_t materialId = face->material % numMaterials;
						PolylistListPerMaterialIdMap::iterator it = polylistListPerMaterialIdMap.find( materialId );

						if( it == polylistListPerMaterialIdMap.end() )
							it =( polylistListPerMaterialIdMap.insert( std::pair<size_t, COLLADASW::Polylist>( materialId, COLLADASW::Polylist( mGeometriesExporter->mSW ) ) ) ).first;

						it->second.getVCountList().push_back( face->deg );

						if( find( materialIDs.begin(), materialIDs.end(), materialId ) == materialIDs.end() )
							materialIDs.push_back( materialId );
					}
				}
				else
				{
					polylistListPerMaterialIdMap.insert( std::pair<size_t, COLLADASW::Polylist>( 0, COLLADASW::Polylist( mGeometriesExporter->mSW ) ) );
					MNMesh &mnMesh = mPolyObject->GetMesh();
					int numberOfFaces = mnMesh.FNum();

					for( int i = 0; i < numberOfFaces; ++i )
					{
						MNFace *face = mnMesh.F( i );
						polylistListPerMaterialIdMap[ 0 ].getVCountList().push_back( face->deg );
					}

					if( find( materialIDs.begin(), materialIDs.end(), 0 ) == materialIDs.end() )
						materialIDs.push_back( 0 );
				}
			}
			else
			{
				if( mExportTextangentsAndNormals )
				{
					exportTriangleMeshTextangentsAndTexbinormals(channelList);
				}

				if( numMaterials > 1 )
				{
					Mesh & mesh = mTriObject->GetMesh();
					int numberOfFaces = mesh.getNumFaces();

					for( int i = 0; i < numberOfFaces; ++i )
					{
						Face& face = mesh.faces[ i ];
						size_t materialId = face.getMatID() % numMaterials;
						facesPerMaterialIdMap[ materialId ] ++;

						if( find( materialIDs.begin(), materialIDs.end(), materialId ) == materialIDs.end() )
							materialIDs.push_back( materialId );
					}
				}

				else
				{
					facesPerMaterialIdMap[ 0 ] = mTriObject->GetMesh().getNumFaces();
					if( find( materialIDs.begin(), materialIDs.end(), 0 ) == materialIDs.end() )
						materialIDs.push_back( 0 );
				}

			}

			exportVertices( mId );

			// Create one COLLADASW polygon set for each material used in the mesh
			//   FCDMaterial* blackMtl = NULL;

			for( GeometriesExporter::MaterialIDList::iterator it = materialIDs.begin(); it != materialIDs.end(); ++it )
			{
				size_t matID = *it;

				String symbol;

				if( !nodeMaterial )
				{
					symbol = COLOR_MATERIAL_SYMBOL;
				}

				else
				{
					Mtl* subMaterial = materials[ matID % numMaterials ];

					if( subMaterial )
					{
						// check for XRefs
						if (XRefFunctions::isXRefMaterial(subMaterial))
						{
							if( mDocumentExporter->getOptions().getIncludeXRefs() )
							{
								// resolve the source
								subMaterial = XRefFunctions::getXRefMaterialSource(subMaterial);
							}
							// else do nothing, this is only a material instance
						}
						symbol = mExportNode->getSymbolByMaterialAndSetAsUsed( subMaterial );
					}

					else
					{
						assert( false );
						/*if (blackMtl == NULL)*/
					}
				}

				// Add the polygons set input and its tessellation indices

				if( isEditablePoly() )
				{
					exportPolylist( symbol, polylistListPerMaterialIdMap[ matID ], numMaterials <= 1 ? -1 :( int ) matID, numMaterials, channelList );
				}
				else
				{
					exportTriangles( symbol,( unsigned long ) facesPerMaterialIdMap[ matID ], numMaterials <= 1 ? -1 :( int ) matID, numMaterials, channelList );
				}
			}



			mGeometriesExporter->closeMesh();

			GeometryExtra geometryExtra( mGeometriesExporter->mSW, mDocumentExporter, object, mId );

			geometryExtra.doExport();



			mGeometriesExporter->closeGeometry();
		}

	}



	//---------------------------------------------------------------
	void GeometryExporter::setSymbolsAsUsed(ExportNode* exportNode, ExportNode* exportedObjectExportNode, const GeometriesExporter::MaterialIDList& materialIDs, const MaterialList& materials)
	{
		Mtl* nodeMaterial = exportNode->getINode()->GetMtl();

		size_t numMaterials = materials.size();


		MaterialList exportedObjectMaterials;

		Mtl* exportedObjectMaterial = exportedObjectExportNode->getINode()->GetMtl();

		if( exportedObjectMaterial )
		{
			flattenMaterials( exportedObjectMaterial, exportedObjectMaterials );
		}

		size_t numExportedObjectMaterials = exportedObjectMaterials.size();

		ExportNode::MeshSymbolMap & exportedObjectMeshSymbolMap = exportedObjectExportNode->getMeshSymbolMap();

		ExportNode::MeshSymbolMap & meshSymbolMap = exportNode->getMeshSymbolMap();
		// We need construct the mesh symbol map completely new, since we need the material symbols from the already exported 
		// object
		meshSymbolMap.clear();

		for( GeometriesExporter::MaterialIDList::const_iterator it = materialIDs.begin(); it != materialIDs.end(); ++it )
		{
			size_t matID = *it;

			if( nodeMaterial )
			{
				Mtl* subMaterial = materials[ matID % numMaterials ];

				if( subMaterial )
				{
					// check for XRefs
					/*      if (XRefFunctions::IsXRefMaterial(subMaterial))
					{
					if (!OPTS->ExportXRefs())
					{
					// resolve the source
					subMaterial = XRefFunctions::getXRefMaterialSource(subMaterial);
					}
					// else do nothing, this is only a material instance
					}
					*/
					// if this is a XRef it'll return NULL


					ExportNode::Symbol& symbol = meshSymbolMap[subMaterial];

					Mtl* exportedObjectSubMaterial = exportedObjectMaterials[ matID % numExportedObjectMaterials ];

					symbol.name = exportedObjectMeshSymbolMap[exportedObjectSubMaterial].name;
					symbol.used = true;


					//					mExportNode->getSymbolByMaterialAndSetAsUsed( subMaterial );

				}
			}

		}

	}



	//---------------------------------------------------------------
	void GeometryExporter::exportPositions()
	{
		COLLADASW::FloatSource source( mGeometriesExporter->mSW );
		source.setId( mId + COLLADASW::LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX );
		source.setArrayId( mId + COLLADASW::LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
		source.setAccessorStride( 3 );
		source.getParameterNameList().push_back( "X" );
		source.getParameterNameList().push_back( "Y" );
		source.getParameterNameList().push_back( "Z" );

		if( isEditablePoly() )
		{
			// editable poly. case
			MNMesh & mnMesh = mPolyObject->GetMesh();
			int vertexCount = mnMesh.VNum();
			source.setAccessorCount( vertexCount );
			source.prepareToAppendValues();

			for( int i = 0; i < vertexCount; ++i )
			{
				Point3 &position = mnMesh.V( i ) ->p;
				source.appendValues( position.x, position.y, position.z );
			}
		}

		else
		{
			Mesh & mesh = mTriObject->GetMesh();
			int vertexCount = mesh.numVerts;
			source.setAccessorCount( vertexCount );
			source.prepareToAppendValues();

			for( int i = 0; i < vertexCount; ++i )
			{
				Point3 & position = mesh.verts[ i ];
				source.appendValues( position.x, position.y, position.z );
			}
		}

		source.finish();
	}



	//---------------------------------------------------------------
	void GeometryExporter::exportMorphHelperPositions()
	{
		COLLADASW::FloatSource source( mGeometriesExporter->mSW );
		source.setId( mId + COLLADASW::LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX );
		source.setArrayId( mId + COLLADASW::LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
		source.setAccessorStride( 3 );
		source.getParameterNameList().push_back( "X" );
		source.getParameterNameList().push_back( "Y" );
		source.getParameterNameList().push_back( "Z" );

		morphChannel& channel = mMorphControllerHelperGeometry->morphController->getMorph()->chanBank[mMorphControllerHelperGeometry->channelBankindex];

		source.setAccessorCount( channel.mNumPoints );
		source.prepareToAppendValues();

		for (int i = 0; i < channel.mNumPoints; ++i)
		{
			const Point3& point = channel.mPoints[i];
			source.appendValues(point.x, point.y, point.z);
		}
		source.finish();
	}



	//---------------------------------------------------------------
	void GeometryExporter::exportNormals()
	{
		if( isEditablePoly() )
			exportEditablePolyNormals();
		else
			exportTriangleMeshNormals();
	}

	//---------------------------------------------------------------
	void GeometryExporter::exportTriangleMeshNormals()
	{
		Mesh & mesh = mTriObject->GetMesh();
		MeshNormalSpec *normalSpec = mesh.GetSpecifiedNormals();

		if( normalSpec == NULL )
		{
			mesh.SpecifyNormals();
			normalSpec = mesh.GetSpecifiedNormals();
		}

		if( normalSpec->GetNumNormals() == 0 )
		{
			normalSpec->SetParent( &mesh );
			normalSpec->CheckNormals();
		}

		if( normalSpec == NULL )
			return ;

		if( normalSpec->GetNumNormals() == 0 )
		{
			normalSpec->SetParent( &mesh );
			normalSpec->CheckNormals();
		}

		int normalCount = normalSpec->GetNumNormals();

		COLLADASW::FloatSource source( mGeometriesExporter->mSW );
		source.setId( mId + COLLADASW::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX );
		source.setArrayId( mId + COLLADASW::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
		source.setAccessorStride( 3 );
		source.setAccessorCount( normalCount );
		source.getParameterNameList().push_back( "X" );
		source.getParameterNameList().push_back( "Y" );
		source.getParameterNameList().push_back( "Z" );
		source.prepareToAppendValues();

		for( int i = 0; i < normalCount; ++i )
		{
			Point3 & normal = normalSpec->Normal( i );
			// TODO: find a better solution for the case of not existing normals

			if( isFinite( normal ) )
				source.appendValues( normal.x, normal.y, normal.z );
			else
				source.appendValues( 0, 0, 1 );
		}

		source.finish();
	}


	//---------------------------------------------------------------
	void GeometryExporter::exportEditablePolyNormals()
	{
		MNMesh & mnMesh = mPolyObject->GetMesh();
		MNNormalSpec *mnNormalSpec = mnMesh.GetSpecifiedNormals();

		if( mnNormalSpec == NULL )
		{
			mnMesh.SpecifyNormals();
			mnNormalSpec = mnMesh.GetSpecifiedNormals();
		}

		if( mnNormalSpec == NULL )
			return ;

		// rebuild as needed
		mnNormalSpec->CheckNormals();

		int normalCount = mnNormalSpec->GetNumNormals();

		if( normalCount == 0 )
			return ;

		COLLADASW::FloatSource source( mGeometriesExporter->mSW );

		source.setId( mId + COLLADASW::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX );

		source.setArrayId( mId + COLLADASW::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );

		source.setAccessorStride( 3 );

		source.setAccessorCount( normalCount );

		source.getParameterNameList().push_back( "X" );

		source.getParameterNameList().push_back( "Y" );

		source.getParameterNameList().push_back( "Z" );

		source.prepareToAppendValues();

		for( int i = 0; i < normalCount; ++i )
		{
			Point3 & normal = mnNormalSpec->Normal( i );
			// TODO: find a better solution for the case of not existing normals

			if( isFinite( normal ) )
				source.appendValues( normal.x, normal.y, normal.z );
			else
				source.appendValues( 0, 0, 1 );
		}

		source.finish();
	}



	//---------------------------------------------------------------
	void GeometryExporter::exportTextures( const ChannelList & channelList, Mtl* material )
	{
		// Export the map channel sources (valid indices are from -2 to 99)
		// Offset the negative map channels indices by MAX_MESHMAPS, in order to bring
		// the -2,-1 channels into non-negative range and not clash with the valid map channels.

		for( size_t i = 0; i < channelList.size(); ++i )
		{
			exportTextureChannel( channelList[ i ], material );
		}
	}


	//---------------------------------------------------------------
	void GeometryExporter::exportTextureChannel( int channelIndex, Mtl* material )
	{
		// return if channel index is invalid
		/* if (channelIndex >= mesh.getNumMaps() || channelIndex < -NUM_HIDDENMAPS)
		return;*/

		COLLADASW::FloatSource source( mGeometriesExporter->mSW );
		String sourceId = mId + getTextureSourceIdSuffix( channelIndex );
		source.setId( sourceId );
		source.setArrayId( sourceId + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
		source.setAccessorStride( 3 );

		if( channelIndex <= 0 )
		{
			source.getParameterNameList().push_back( "R" );
			source.getParameterNameList().push_back( "G" );
			source.getParameterNameList().push_back( "B" );
		}

		else
		{
			source.getParameterNameList().push_back( "S" );
			source.getParameterNameList().push_back( "T" );
			source.getParameterNameList().push_back( "P" );
		}

		/* start testing */

		bool applyUVTransformation = false;
		Matrix3 uvTransfomationMatrix;

		if( material )
		{
			int numSubTexMaps = material->NumSubTexmaps();

			Texmap* map = 0;
			for( int i = 0; (i < numSubTexMaps) && !map; i++ )
			{
				map = material->GetSubTexmap( i );
			}

			if( map )
			{
				map->GetUVTransform(uvTransfomationMatrix);
				applyUVTransformation = !uvTransfomationMatrix.IsIdentity();
			}
		}

		/*		EffectExporter::MaterialChannelPairParamBlockMap::const_iterator it = mMaterialChannelPairParamBlockMap.find(EffectExporter::MaterialChannelPair(material, channelIndex));

		IParamBlock * uVGenParamBlock = 0;

		if( it != mMaterialChannelPairParamBlockMap.end() ) 
		uVGenParamBlock = it->second;

		float wAngle = 0;
		if( uVGenParamBlock )
		wAngle = uVGenParamBlock->GetFloat(StdUVGenEnums::w_angle, TIME_EXPORT_START);

		*/
		/* end testing*/

		if( isEditablePoly() )
		{
			MNMesh & mnMesh = mPolyObject->GetMesh();
			MNMap *mnMap = mnMesh.M( channelIndex );

			if( !mnMap )
				return ;

			int mapVertexCount = mnMap->numv;

			source.setAccessorCount( mapVertexCount );

			source.prepareToAppendValues();

			for( int i = 0; i < mapVertexCount; ++i )
			{
				UVVert texCoord = mnMap->V( i );

				// TODO: find a better solution for the case of not existing texture coordinates

				if( isFinite( texCoord ) )
				{
					if( applyUVTransformation )
						texCoord = uvTransfomationMatrix * texCoord;
					source.appendValues( texCoord.x, texCoord.y, texCoord.z );
				}
				else
				{
					source.appendValues( 0, 0, 1 );
				}
			}
		}

		else
		{
			MeshMap& meshMap = mTriObject->GetMesh().Map( channelIndex );
			int mapVertexCount = meshMap.getNumVerts();
			source.setAccessorCount( mapVertexCount );
			source.prepareToAppendValues();

			for( int i = 0; i < mapVertexCount; ++i )
			{
				Point3& texCoord = meshMap.tv[ i ];

				// TODO: find a better solution for the case of not existing texture coordinates

				if( isFinite( texCoord ) )
				{
					if( applyUVTransformation )
						texCoord = uvTransfomationMatrix * texCoord;
					source.appendValues( texCoord.x, texCoord.y, texCoord.z );
				}
				else
				{
					source.appendValues( 0, 0, 1 );
				}
			}
		}
		source.finish();
	}


	//---------------------------------------------------------------
	void GeometryExporter::exportTriangleMeshTextangentsAndTexbinormals(const ChannelList & channelList)
	{
		Point3List texTangents;
		Point3List texBinormals;

		for( size_t i = 0; i < channelList.size(); ++i )
		{
			int channelIndex = channelList[i];
			
			// check that it is not a color channel
			if( channelIndex <= 0 )
			{
				continue;
			}
			
			MeshAccess mesh( mTriObject->GetMesh(), channelIndex);
			TexTangentCalculator* texTangentCalculator = new TexTangentCalculator( &mesh ); 
			mChannelIndexTexTangentCalculatorMap.insert(std::make_pair(channelIndex, texTangentCalculator));

			texTangentCalculator->calculateTriangleMeshTextangents();

	//		calculateTriangleMeshTextangents( channelIndex, texTangents, texBinormals);

			const TexTangentCalculator::VertexTexTangentInfoList& texTangents =  texTangentCalculator->getTexTangents();
			// textangents
			size_t texTangentsCount = texTangents.size();
			COLLADASW::FloatSource texTangentSource( mGeometriesExporter->mSW );
			String texTangentSourceId = mId + getTextangentSourceIdSuffix( channelIndex );
			texTangentSource.setId( texTangentSourceId );
			texTangentSource.setArrayId( texTangentSourceId + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
			texTangentSource.setAccessorStride( 3 );
			texTangentSource.setAccessorCount( (unsigned long)texTangentsCount );

			texTangentSource.getParameterNameList().push_back( "X" );
			texTangentSource.getParameterNameList().push_back( "Y" );
			texTangentSource.getParameterNameList().push_back( "Z" );

			texTangentSource.prepareToAppendValues();

			for( size_t j = 0; j < texTangentsCount; ++j)
			{
				COLLADABU::Math::Vector3& texTangent = texTangents[j]->tangent;
				texTangentSource.appendValues( texTangent.x, texTangent.y, texTangent.z );
			}
			texTangentSource.finish();


			// texbinormals
			size_t texBinormalsCount = texTangentsCount;
			COLLADASW::FloatSource texBinormalSource( mGeometriesExporter->mSW );
			String texBinormalSourceId = mId + getTexbinormalSourceIdSuffix( channelIndex );
			texBinormalSource.setId( texBinormalSourceId );
			texBinormalSource.setArrayId( texBinormalSourceId + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
			texBinormalSource.setAccessorStride( 3 );
			texBinormalSource.setAccessorCount( (unsigned long)texBinormalsCount );

			texBinormalSource.getParameterNameList().push_back( "X" );
			texBinormalSource.getParameterNameList().push_back( "Y" );
			texBinormalSource.getParameterNameList().push_back( "Z" );

			texBinormalSource.prepareToAppendValues();

			for( size_t j = 0; j < texBinormalsCount; ++j)
			{
				COLLADABU::Math::Vector3& texBinormal = texTangents[j]->biTangent;
				texBinormalSource.appendValues( texBinormal.x, texBinormal.y, texBinormal.z );
			}

			texBinormalSource.finish();
			texTangentCalculator->clearTexTangentData();
		}

	}


	//---------------------------------------------------------------
	void GeometryExporter::exportVertices( const String & meshId )
	{
		COLLADASW::VerticesElement vertices( mGeometriesExporter->mSW );
		vertices.setId( meshId + COLLADASW::LibraryGeometries::VERTICES_ID_SUFFIX );
		vertices.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::POSITION, "#" + meshId + COLLADASW::LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX ) );
		vertices.add();
	}


	//---------------------------------------------------------------
	void GeometryExporter::exportTriangles( const String & symbol, unsigned long numberOfFaces, int matId, size_t numMaterials, const ChannelList & channelList )
	{

		Mesh & mesh = mTriObject->GetMesh();

		MeshNormalSpec *norms = mesh.GetSpecifiedNormals();

		int offset = 0;
		COLLADASW::Triangles triangles( mGeometriesExporter->mSW );
		triangles.setCount( numberOfFaces );
		triangles.setMaterial( symbol );
		triangles.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::VERTEX, "#" + mId + COLLADASW::LibraryGeometries::VERTICES_ID_SUFFIX, offset++ ) );
		if( mExportNormals )
		{
			triangles.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::NORMAL, "#" + mId + COLLADASW::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX, offset++ ) );
		}

		for( ChannelList::const_iterator it = channelList.begin(); it != channelList.end(); ++it )
		{
			int channelIndex = *it;

			if ( channelIndex <= 0)
			{
                if ( channelIndex == 0 )
                {
                    triangles.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::COLOR, "#" + mId + getTextureSourceIdSuffix( channelIndex ), offset++, channelIndex ) );
                }
                //:NOTE: we removed the negative channel indices handling because they generate invalid input sets in exported DAE
                //:TODO: handle channel indices -1 and -2 if support of MAP_SHADING and MAP_ALPHA is needed (see mesh.h)
			}
			else
			{
				// max starts with 1 to index the texture maps. To start with 0 in COLLADA, we always substract one from the channel to get the set
				// This is also relevant when exporting bind_vertex_input
				triangles.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::TEXCOORD, "#" + mId + getTextureSourceIdSuffix( channelIndex ), offset++, channelIndex - 1 ) );
			}

			if( mExportTextangentsAndNormals &&( channelIndex > 0 ) )
			{
				triangles.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::TEXTANGENT, "#" + mId + getTextangentSourceIdSuffix( channelIndex ), offset, channelIndex ) );
				triangles.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::TEXBINORMAL, "#" + mId + getTexbinormalSourceIdSuffix( channelIndex ), offset++, channelIndex ) );
			}
		}

		triangles.prepareToAppendValues();

		for( int faceIndex = 0; faceIndex < mesh.numFaces; ++faceIndex )
		{
			Face& face = mesh.faces[ faceIndex ];

			if( numMaterials <= 1 || face.getMatID() % numMaterials == matId )
			{
				for( int vertexIndex = 0; vertexIndex < 3; ++vertexIndex )
				{
					triangles.appendValues( face.v[ vertexIndex ] );

					if( mExportNormals )
					{
						triangles.appendValues( norms->GetNormalIndex( faceIndex, vertexIndex ) );
					}

					for( ChannelList::const_iterator it = channelList.begin(); it != channelList.end(); ++it )
					{
						int channel = *it;

						if ( channel < 0 )
							continue; // see :TODO: above (MAP_SHADING & MAP_ALPHA)

						if( channel < mesh.getNumMaps() && channel >= -NUM_HIDDENMAPS )
						{
							MeshMap & tmap = mesh.Map( channel );
							TVFace& tvFace = tmap.tf[ faceIndex ];
							triangles.appendValues( tvFace.t[ vertexIndex ] );

							if( mExportTextangentsAndNormals &&( channel > 0 ) )
							{
								const TexTangentCalculator* texTangentCalculator = mChannelIndexTexTangentCalculatorMap[channel];
								const TexTangentCalculator::IndicesList& indices = texTangentCalculator->getIndices();
								triangles.appendValues( indices[ 3*faceIndex + vertexIndex ] );
							}
						}
					}
				}
			}

		}

		triangles.finish();
	}


	//---------------------------------------------------------------
	void GeometryExporter::exportPolylist( const String & symbol, COLLADASW::Polylist & polylist, int matId, size_t numMaterials, const ChannelList & channelList )
	{
		MNMesh & mnMesh = mPolyObject->GetMesh();

		MNNormalSpec *normmalSpec = mnMesh.GetSpecifiedNormals();

		int offset = 0;
		polylist.setCount( ( unsigned long ) polylist.getVCountList().size() );
		polylist.setMaterial( symbol );
		polylist.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::VERTEX, "#" + mId + COLLADASW::LibraryGeometries::VERTICES_ID_SUFFIX, offset++ ) );
		if( mExportNormals )
		{
			polylist.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::NORMAL, "#" + mId + COLLADASW::LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX, offset++ ) );
		}

		for( ChannelList::const_iterator it = channelList.begin(); it != channelList.end(); ++it )
		{
			const int& channelIndex = *it;

			if ( channelIndex <= 0)
			{
                if ( channelIndex == 0 )
                {
                    polylist.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::COLOR, "#" + mId + getTextureSourceIdSuffix( channelIndex ), offset++, channelIndex ) );
                }
                //:NOTE: we removed the negative channel indices handling because they generate invalid input sets in exported DAE
                //:TODO: handle channel indices -1 and -2 if support of MAP_SHADING and MAP_ALPHA is needed (see mesh.h)
			}
			else
			{
				// max starts with 1 to index the texture maps. To start with 0 in COLLADA, we always substract one from the channel to get the set
				// This is also relevant when exporting bind_vertex_input
				polylist.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::TEXCOORD, "#" + mId + getTextureSourceIdSuffix( channelIndex ), offset++, channelIndex - 1 ) );
			}
		}

		polylist.prepareToAppendValues();

		int numberOfFaces = mnMesh.FNum();

		for( int faceIndex = 0; faceIndex < numberOfFaces; ++faceIndex )
		{
			MNFace * mnFace = mnMesh.F( faceIndex );

			if( numMaterials <= 1 || mnFace->material % numMaterials == matId )
			{
				int vertexCount = mnFace->deg;

				for( int vertexIndex = 0; vertexIndex < vertexCount; ++vertexIndex )
				{
					polylist.appendValues( mnFace->vtx[ vertexIndex ] );

					if( mExportNormals )
					{
						polylist.appendValues( normmalSpec->GetNormalIndex( faceIndex, vertexIndex ) );
					}

					for( ChannelList::const_iterator it = channelList.begin(); it != channelList.end(); ++it )
					{
						int channel = *it;

						if ( channel < 0 )
							continue; // see :TODO: above (MAP_SHADING & MAP_ALPHA)

						MNMap * mnMap = mnMesh.M( channel );
						assert( mnMap != 0 );
						MNMapFace * mnMapFace = mnMap->F( faceIndex );
						assert( mnMapFace != 0 );
						polylist.appendValues( mnMapFace->tv[ vertexIndex ] );
					}
				}
			}
		}
		polylist.finish();
	}

	//---------------------------------------------------------------
	void GeometryExporter::flattenMaterials( Mtl* material, MaterialList& materialMap, int materialIndex )
	{
		// check for XRefs
		if( material && XRefFunctions::isXRefMaterial(material))
		{
			material = XRefFunctions::getXRefMaterialSource(material);
		}

		// KEEP THE NULL POINTER! Null pointers are actually allowed in max, and we need to
		// maintain the material list.
		Class_ID matId =  !material ? Class_ID( STANDIN_CLASS_ID, STANDIN_CLASS_ID ) : material->ClassID();

		if( matId == Class_ID( MULTI_CLASS_ID, 0 ) )
		{
			if( materialIndex < 0 )
			{
				// Read in the sub-materials
				int nbSubMtl = material->NumSubMtls();

				for( int i = 0; i < nbSubMtl; ++i )
				{
					Mtl *subMtl = material->GetSubMtl( i );
					flattenMaterials( subMtl, materialMap, i );
				}
			}

			else
			{
				// If we are in a recursive multi-material, read in the correctly indexed sub-material
				Mtl* subMtl = MaterialExporter::GetSubMaterialById( material, materialIndex );

				if( subMtl )
					flattenMaterials( subMtl, materialMap );
				else
					subMtl = material->GetSubMtl( 0 );
			}
		}

		else if( matId == Class_ID( BAKE_SHELL_CLASS_ID, 0 ) )
		{
			// Read in the first sub-material only
			flattenMaterials( material->GetSubMtl( 1 ), materialMap );
		}

		/*else if (XRefFunctions::IsXRefMaterial(material))
		{
		// Add this material as a leaf
		materialMap.push_back(material);
		} */

		else
		{
			// Add this material as a leaf
			materialMap.push_back( material );
		}
	}

	//---------------------------------------------------------------
	void GeometryExporter::doExportSpline()
	{

		INode * iNode = mExportNode->getINode();


		Object* object = mExportNode->getInitialPose();

		SClass_ID sid;
		getBaseObjectAndID( object, sid );

		if (sid != SHAPE_CLASS_ID) 
			return;

		if (XRefFunctions::isXRefObject(object)) 
			return;

		// NURBS or spline?
		// doing this test here since spline->InitializeData may CRASH on a NURBS object.
		if (isNURBS(object)) 
			return;

		ShapeObject* maxobj = (ShapeObject*) object;

		if (!maxobj->CanMakeBezier()) 
			return;

		BezierShape shape;
		maxobj->MakeBezier(0, shape);

		// for each curve
		int splinesCount = min(shape.SplineCount(), maxobj->NumberOfCurves());
		
		if( splinesCount < 1 )
		{
			// no spline to export
			return;
		}
		
		// we only export the first spline
		// TODO: Think about a way to export multiple plines
		Spline3D* spline = shape.GetSpline(0);
		if( !spline ) 
		{
			// No spline
			return;
		}

		bool isClosedSpline = (maxobj->CurveClosed(0,0) == TRUE);

		mId = GeometriesExporter::getGeometryId(*mExportNode);

		if( !mMorphControllerHelperGeometry )
			mDocumentExporter->insertExportedObject(ObjectIdentifier( object ), mExportNode);

		mGeometriesExporter->openSpline( isClosedSpline, mId, COLLADASW::Utils::checkNCName( NativeString(iNode->GetName()) ) );

		// for each knot of the spline3D
		int knotsCount = spline->KnotCount();

		String positionsId =  mId + COLLADASW::LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX;
		COLLADASW::FloatSource positionsSource( mGeometriesExporter->mSW );
		positionsSource.setId( positionsId );
		positionsSource.setArrayId( positionsId + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
		positionsSource.setAccessorStride( 3 );
		positionsSource.getParameterNameList().push_back( "X" );
		positionsSource.getParameterNameList().push_back( "Y" );
		positionsSource.getParameterNameList().push_back( "Z" );

		positionsSource.setAccessorCount( knotsCount );
		positionsSource.prepareToAppendValues();

		for (int j = 0; j < knotsCount; ++j)
		{
			SplineKnot k = spline->GetKnot(j);
			Point3 position;

			// always add the knot position as a control vertex
			position = k.Knot();
			positionsSource.appendValues( position.x, position.y, position.z );
		}
		positionsSource.finish();


		String inTangentId =  mId + COLLADASW::LibraryGeometries::INTANGENT_SOURCE_ID_SUFFIX;
		COLLADASW::FloatSource inTangentSource( mGeometriesExporter->mSW );
		inTangentSource.setId( inTangentId );
		inTangentSource.setArrayId( inTangentId + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
		inTangentSource.setAccessorStride( 3 );
		inTangentSource.getParameterNameList().push_back( "X" );
		inTangentSource.getParameterNameList().push_back( "Y" );
		inTangentSource.getParameterNameList().push_back( "Z" );

		inTangentSource.setAccessorCount( knotsCount );
		inTangentSource.prepareToAppendValues();

		for (int j = 0; j < knotsCount; ++j)
		{
			SplineKnot k = spline->GetKnot(j);
			Point3 position;

			position = k.InVec();
			inTangentSource.appendValues( position.x, position.y, position.z );
		}
		inTangentSource.finish();


		String outTangentId =  mId + COLLADASW::LibraryGeometries::OUTTANGENT_SOURCE_ID_SUFFIX;
		COLLADASW::FloatSource outTangentSource( mGeometriesExporter->mSW );
		outTangentSource.setId( outTangentId );
		outTangentSource.setArrayId( outTangentId + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
		outTangentSource.setAccessorStride( 3 );
		outTangentSource.getParameterNameList().push_back( "X" );
		outTangentSource.getParameterNameList().push_back( "Y" );
		outTangentSource.getParameterNameList().push_back( "Z" );

		outTangentSource.setAccessorCount( knotsCount );
		outTangentSource.prepareToAppendValues();

		for (int j = 0; j < knotsCount; ++j)
		{
			SplineKnot k = spline->GetKnot(j);
			Point3 position;

			position = k.OutVec();
			outTangentSource.appendValues( position.x, position.y, position.z );
		}
		outTangentSource.finish();


		String interpolationId =  mId + COLLADASW::LibraryGeometries::INTERPOLATION_SOURCE_ID_SUFFIX;
		COLLADASW::NameSource interpolationSource( mGeometriesExporter->mSW );
		interpolationSource.setId( interpolationId );
		interpolationSource.setArrayId( interpolationId + COLLADASW::LibraryGeometries::ARRAY_ID_SUFFIX );
		interpolationSource.setAccessorStride( 1 );
		interpolationSource.getParameterNameList().push_back( "INTERPOLATION" );

		interpolationSource.setAccessorCount( knotsCount );
		interpolationSource.prepareToAppendValues();

		for (int j = 0; j < knotsCount; ++j)
		{
			SplineKnot k = spline->GetKnot(j);
			Point3 position;

			position = k.OutVec();
			interpolationSource.appendValues( "BEZIER" );
		}
		interpolationSource.finish();


		COLLADASW::ControlVertices controlVertices( mGeometriesExporter->mSW );
		controlVertices.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::POSITION, "#" + positionsId ) );
		controlVertices.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::IN_TANGENT, "#" + inTangentId ) );
		controlVertices.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::OUT_TANGENT, "#" + outTangentId ) );
		controlVertices.getInputList().push_back( COLLADASW::Input( COLLADASW::InputSemantic::INTERPOLATION, "#" + interpolationId ) );
		controlVertices.add();

		mGeometriesExporter->closeSpline();

		GeometryExtra geometryExtra( mGeometriesExporter->mSW, mDocumentExporter, object, mId );

		geometryExtra.doExport();

		mGeometriesExporter->closeGeometry();

	}

}
