/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsWriter.h"
#include "DAE23dsMeshWriter.h"
#include "DAE23dsMeshHandler.h"
#include "DAE23dsMeshLengthCalculator.h"
#include "DAE23dsSceneGraphWriter.h"
#include "DAE23dsSceneGraphHandler.h"
#include "DAE23dsMaterialsLengthCalculator.h"
#include "DAE23dsMaterialsWriter.h"

#include "COLLADASaxFWLLoader.h"

#include "COLLADAFWRoot.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWVisualScene.h"
#include "COLLADAFWInstanceGeometry.h"


#include "CommonFWriteBufferFlusher.h"
#include "CommonCharacterBuffer.h"

namespace DAE23ds
{

	static size_t FLUSHERBUFFERSIZE = 1024*1024*4;
	static size_t BUFFERSIZE = 1024*1024*2;

	static const size_t RESERVED_OBJECTIDS_COUNT = 0;
	static const size_t RESERVED_MATERIALNUMBERS_COUNT = 1;


	//--------------------------------------------------------------------
	bool Writer::InstanceGeometryInfo::operator<( const InstanceGeometryInfo& rhs ) const
	{
		if (fwInstanceGeometry < rhs.fwInstanceGeometry)
			return true;
		if (fwInstanceGeometry > rhs.fwInstanceGeometry)
			return false;

		return false;
	}

	//--------------------------------------------------------------------
	bool Writer::InstanceGeometryIdentifier::operator<( const InstanceGeometryIdentifier& rhs ) const
	{
		if (fwInstanceGeometry < rhs.fwInstanceGeometry)
			return true;
		if (fwInstanceGeometry > rhs.fwInstanceGeometry)
			return false;

		if (instanceNumber < rhs.instanceNumber)
			return true;
		if (instanceNumber > rhs.instanceNumber)
			return false;

		return false;
	}

	//--------------------------------------------------------------------
	Writer::Writer( const COLLADABU::URI& inputFile, const COLLADABU::URI& outputFile, bool applyTransformationsToMeshes )
		: mInputFile(inputFile)
		, mOutputFile(outputFile)
		, mApplyTransformationsToMeshes(applyTransformationsToMeshes)
		, mBuffer(0)
		, mCurrentRun(SCENEGRAPH_RUN)
		, mVisualScene(0)
		, mGeometryMaterialBindingFileNameMap(compare)
		, mObjectAndMaterialBlockLength(0)
		, mNextObjectId( RESERVED_OBJECTIDS_COUNT )
		, mNextMaterialNumber( RESERVED_MATERIALNUMBERS_COUNT )
	{
	}

	//--------------------------------------------------------------------
	Writer::~Writer()
	{
		delete mVisualScene;
	}

	//--------------------------------------------------------------------
	void Writer::reportError( const String& method, const String& message, Severity severity )
	{
		switch ( severity )
		{
		case SEVERITY_INFORMATION:
			std::cout << "Information"; 
			break;
		case SEVERITY_WARNING:
			std::cout << "Warning"; 
			break;
		case _SEVERITY_ERROR:
			std::cout << "Error"; 
			break;
		}
		if ( !method.empty() )
			std::cout << " in " << method;
		std::cout << ": ";
		std::cout << message << std::endl;
	}

	//--------------------------------------------------------------------
	bool Writer::write()
	{
		COLLADASaxFWL::Loader loader;
		COLLADAFW::Root root(&loader, this);

		Common::FWriteBufferFlusher bufferFlusher( getOutputFile().toNativePath().c_str(), FLUSHERBUFFERSIZE );
		Common::Buffer buffer( BUFFERSIZE, &bufferFlusher);

		mBuffer = &buffer;

		// Load scene graph 
		loader.setObjectFlags(   COLLADASaxFWL::Loader::ASSET_FLAG 
							   | COLLADASaxFWL::Loader::EFFECT_FLAG
							   | COLLADASaxFWL::Loader::MATERIAL_FLAG
							   | COLLADASaxFWL::Loader::LIBRARY_NODES_FLAG
							   | COLLADASaxFWL::Loader::VISUAL_SCENES_FLAG
							   | COLLADASaxFWL::Loader::SCENE_FLAG
							   | COLLADASaxFWL::Loader::GEOMETRY_FLAG);
		if ( !root.loadDocument(mInputFile.toNativePath()) )
			return false;

		createUniqueIdNodeMap();

		SceneGraphHandler sceneGraphHandler(this, mVisualScene, mLibraryNodesList);
		sceneGraphHandler.handle();

		calculateMaterialsBlockLength();
		calculateMeshesLength();

		writeHeader( sceneGraphHandler.getScenegraphLength() );
		writeMaterialsBlocks();

		// load and write geometries
		mCurrentRun = GEOMETRY_RUN;
		if ( !root.loadDocument(mInputFile.toNativePath()) )
			return false;

		SceneGraphWriter sceneGraphWriter(this, mVisualScene, mLibraryNodesList);
		sceneGraphWriter.write( sceneGraphHandler.getScenegraphLength() );

		return true;
	}

	//--------------------------------------------------------------------
	void Writer::calculateMeshesLength()
	{
		MeshDataMap::const_iterator it = mMeshDataMap.begin();
		for ( ; it != mMeshDataMap.end(); ++it)
		{
			const MeshData& meshData = it->second;
			MeshLengthCalculator meshLengthCalculator( this, meshData );
			meshLengthCalculator.handle();
		}
	}

	//--------------------------------------------------------------------
	void Writer::calculateMaterialsBlockLength()
	{
		MaterialsLengthCalculator materialsLengthCalculator(this);
		materialsLengthCalculator.calculate();
	}

	//--------------------------------------------------------------------
	void Writer::writeMaterialsBlocks()
	{
		MaterialsWriter materialsWriter(this);
		materialsWriter.write();
	}

	//------------------------------
	void Writer::createUniqueIdNodeMap( COLLADAFW::Node* node )
	{
		mUniqueIdNodeMap[node->getUniqueId()] = node;
		createUniqueIdNodeMap( node->getChildNodes() );
	}

	//------------------------------
	void Writer::createUniqueIdNodeMap( const COLLADAFW::NodePointerArray& nodes )
	{
		for ( size_t i = 0, cout = nodes.getCount(); i < cout; ++i)
		{
			COLLADAFW::Node* node = nodes[i];
			createUniqueIdNodeMap( node );
		}
	}

	//------------------------------
	void Writer::createUniqueIdNodeMap()
	{
		createUniqueIdNodeMap( mVisualScene->getRootNodes() );
		Writer::LibraryNodesList::const_iterator it = mLibraryNodesList.begin();
		for ( ; it != mLibraryNodesList.end(); ++it )
		{
			const COLLADAFW::LibraryNodes& libraryNodes = *it;
			createUniqueIdNodeMap( libraryNodes.getNodes() );
		}
	}


	//--------------------------------------------------------------------
	void Writer::cancel( const String& errorMessage )
	{
	}

	//--------------------------------------------------------------------
	void Writer::start()
	{
	}

	//--------------------------------------------------------------------
	void Writer::finish()
	{
	}

	//--------------------------------------------------------------------
	bool Writer::writeGlobalAsset( const COLLADAFW::FileInfo* asset )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeVisualScene( const COLLADAFW::VisualScene* visualScene )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		mVisualScene = new COLLADAFW::VisualScene(*visualScene);
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		mLibraryNodesList.push_back(*libraryNodes);
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeGeometry( const COLLADAFW::Geometry* geometry )
	{
		if ( geometry->getType() != COLLADAFW::Geometry::GEO_TYPE_MESH )
			return true;

		switch ( mCurrentRun )
		{
		case SCENEGRAPH_RUN:
			{
				MeshHandler meshHandler( this, (COLLADAFW::Mesh*)geometry );
				return meshHandler.handle();
				break;
			}
		case GEOMETRY_RUN:
			{
				MeshWriter meshWriter( this, (COLLADAFW::Mesh*)geometry );
				return meshWriter.handle();
				break;
			}
		default:
			return true;
		}
	}

	//--------------------------------------------------------------------
	bool Writer::writeMaterial( const COLLADAFW::Material* material )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		mUniqueIdFWMaterialMap.insert(std::make_pair(material->getUniqueId(),*material ));
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeEffect( const COLLADAFW::Effect* effect )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		mUniqueIdFWEffectMap.insert(std::make_pair(effect->getUniqueId(),*effect ));
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeCamera( const COLLADAFW::Camera* camera )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeImage( const COLLADAFW::Image* image )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		mUniqueIdFWImageMap.insert(std::make_pair(image->getUniqueId(),*image ));
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeLight( const COLLADAFW::Light* light )
	{
		if ( mCurrentRun != SCENEGRAPH_RUN )
			return true;
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeAnimation( const COLLADAFW::Animation* animation )
	{
		return true;
	}

	//--------------------------------------------------------------------
	bool Writer::writeAnimationList( const COLLADAFW::AnimationList* animationList )
	{
		return true;
	}

	//--------------------------------------------------------------------
	void Writer::fillMaterialBindingMap(const GeometryMaterialBinding& materialBinding)
	{
		const COLLADAFW::MaterialBindingArray& fwBindings = materialBinding.fwInstanceGeometry->getMaterialBindings();
		size_t fwBindingCount = fwBindings.getCount();
		
		if ( fwBindingCount == materialBinding.bindingMap.size() )
		{
			//both container have already equal size. Nothing to do
			return;
		}

		for ( size_t i = 0; i< fwBindingCount; ++i)
		{
			const COLLADAFW::MaterialBinding& fwBinding = fwBindings[i];
			materialBinding.bindingMap.insert(std::make_pair(fwBinding.getMaterialId(), fwBinding.getReferencedMaterial()));
		}
	}

	//--------------------------------------------------------------------
	bool Writer::compare( const GeometryMaterialBinding& lhs, const GeometryMaterialBinding& rhs )
	{
		const COLLADAFW::UniqueId& lhsGeometryUniqueId = lhs.fwInstanceGeometry->getInstanciatedObjectId();
		const COLLADAFW::UniqueId& rhsGeometryUniqueId = rhs.fwInstanceGeometry->getInstanciatedObjectId();
		
		if ( lhsGeometryUniqueId < rhsGeometryUniqueId )
			return true;

		if ( lhsGeometryUniqueId > rhsGeometryUniqueId )
			return false;

		const COLLADAFW::MaterialBindingArray& lhsFwBinding = lhs.fwInstanceGeometry->getMaterialBindings();
		const COLLADAFW::MaterialBindingArray& rhsFwBinding = rhs.fwInstanceGeometry->getMaterialBindings();

		if ( lhsFwBinding.getCount() < rhsFwBinding.getCount() )
			return true;

		if ( lhsFwBinding.getCount() > rhsFwBinding.getCount() )
			return false;

		fillMaterialBindingMap(lhs);
		fillMaterialBindingMap(rhs);

		const MaterialBindingMap& lhsBindingMap = lhs.bindingMap;
		const MaterialBindingMap& rhsBindingMap = rhs.bindingMap;

		assert(lhsBindingMap.size() == rhsBindingMap.size());

		MaterialBindingMap::const_iterator lhsIt = lhsBindingMap.begin();
		MaterialBindingMap::const_iterator rhsIt = rhsBindingMap.begin();

		for ( ; lhsIt != lhsBindingMap.end(); ++lhsIt, ++rhsIt)
		{
			if ( lhsIt->first < rhsIt->first )
				return true;

			if ( lhsIt->first > rhsIt->first )
				return false;

			if ( lhsIt->second < rhsIt->second )
				return true;

			if ( lhsIt->second > rhsIt->second )
				return false;
		}

		return false;
	}

	//--------------------------------------------------------------------
	bool Writer::writeHeader( ChunkLength sceneGraphLength )
	{
		// triangle mesh 
		//plus material blocks
		//plus plus empty chunk
		ChunkLength edit3DSLength = mObjectAndMaterialBlockLength + EMPTY_CHUNK_LENGTH ;

		// add mesh version size
		edit3DSLength += MESH_VERSION_CHUNK_LENGTH;

		// add EDIT_MASTERSCALE version length
		edit3DSLength += EDIT_MASTERSCALE_CHUNK_LENGTH;


		// edit 3ds plus empty chunk
		ChunkLength mainLength = edit3DSLength + EMPTY_CHUNK_LENGTH;

		// add M3D3DS_VERSION version length and scene graph length
		mainLength += M3D_VERSION_CHUNK_LENGTH+ sceneGraphLength;


		//  write header
 
		//Main chunk
 		mBuffer->copyToBuffer(MAIN3DS);
 		mBuffer->copyToBuffer(mainLength);
 
 
		// M3D_VERSION version
		mBuffer->copyToBuffer(M3D3DS_VERSION);
		mBuffer->copyToBuffer(M3D_VERSION_CHUNK_LENGTH);
		mBuffer->copyToBuffer(M3D_VERSION);

		//3d editor chunk
 		mBuffer->copyToBuffer(EDIT3DS);
 		mBuffer->copyToBuffer(edit3DSLength);
 
		// mesh version
 		mBuffer->copyToBuffer(MESH3DS_VERSION);
 		mBuffer->copyToBuffer(MESH_VERSION_CHUNK_LENGTH);
 		mBuffer->copyToBuffer(MESH_VERSION);

		// master scale
		mBuffer->copyToBuffer(EDIT_MASTERSCALE);
		mBuffer->copyToBuffer(EDIT_MASTERSCALE_CHUNK_LENGTH);
		mBuffer->copyToBuffer((float)1);

		return true;
	}

	//--------------------------------------------------------------------
	ChunkLength Writer::getObjectNameLength()
	{
		return OBJECT_NAME_LENGTH;
	}

	//--------------------------------------------------------------------
	ChunkLength Writer::getMaterialNameLength()
	{
		return OBJECT_NAME_LENGTH;
	}

	//--------------------------------------------------------------------
	template<class NumberType, char prefix>
	const char* Writer::calculateNameFromNumber( const NumberType& number)
	{
		// we do not support to big meshes here
		assert(number < 100000);
		static char buffer[OBJECT_NAME_LENGTH];
		char* p = buffer;
		*(p++) = prefix;
		if ( number < 1000000) *(p++) = '0';
		if ( number < 100000) *(p++) = '0';
		if ( number < 10000) *(p++) = '0';
		if ( number < 100) *(p++) = '0';
		if ( number < 10) *(p++) = '0';
		p += Common::itoa( number, p, 10);
		return buffer;

	}


	//--------------------------------------------------------------------
	const char* Writer::calculateMaterialNameFromMaterialNumer( const MaterialNumber& materialNumber)
	{
		return calculateNameFromNumber<MaterialNumber, 'M'>(materialNumber);
	}

	//--------------------------------------------------------------------
	const char* Writer::calculateObjectNameFromObjectId( const ObjectId& objectId)
	{
		return calculateNameFromNumber<ObjectId, 'G'>(objectId);
	}
		
} // namespace DAE23ds
