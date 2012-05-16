/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE23dsStableHeaders.h"
#include "DAE23dsBaseWriter.h"

#include "DAE23dsWriter.h"
#include "DAE23dsChunkIDs.h"


namespace DAE23ds
{

	static const size_t MAX_NODE_NAME_LENGTH = 10;

	ChunkLength getNodeNameLength( const COLLADAFW::Node* node )
	{
		return (ChunkLength)(min(node->getName().length(), MAX_NODE_NAME_LENGTH) + 1);
	}

	//------------------------------
	BaseWriter::BaseWriter( Writer* writer3ds )
		: mWriter(writer3ds)
	{
	}

	//------------------------------
	BaseWriter::~BaseWriter()
	{
	}

	//------------------------------
	void BaseWriter::reportError( const String& method, const String& message, Writer::Severity severity )
	{
		Writer::reportError(method, message, severity);
	}

	//------------------------------
	const Writer::GeometryUniqueIdInstanceGeometryInfoMap& BaseWriter::getGeometryUniqueIdInstanceGeometryInfoMap()
	{
		return mWriter->getGeometryUniqueIdInstanceGeometryInfoMap();
	}

	//------------------------------
	void BaseWriter::addInstanceGeometryInstanceGeometryInfoPair( const COLLADAFW::UniqueId& geoId, const Writer::InstanceGeometryInfo& instanceGeoInfo )
	{
		if ( !getApplyTransformationsToMeshes() )
		{
			// if we apply transformations to meshes, we need each instance as often as it occurs
			Writer::InstanceGeometryInfoSet& set = mWriter->getInstanceGeometryInfoSet();
			if ( set.count(instanceGeoInfo) != 0 )
			{
				return;
			}
			else
			{
				set.insert( instanceGeoInfo );
			}
		}

		Writer::GeometryUniqueIdInstanceGeometryInfoMap& map = mWriter->getGeometryUniqueIdInstanceGeometryInfoMap();
		map.insert(std::make_pair(geoId, instanceGeoInfo));
	}

	//------------------------------
	void BaseWriter::addInstanceGeometryObjectId( const Writer::InstanceGeometryIdentifier& instanceGeometryIdentifier, const Writer::ObjectId& objectId )
	{
		mWriter->getInstanceGeometryObjectIdMap()[instanceGeometryIdentifier].push_back( objectId );
	}

	//------------------------------
	const Writer::ObjectIdList& BaseWriter::getInstanceGeometryObjectIds( const Writer::InstanceGeometryIdentifier& instanceGeometryIdentifier )
	{
		return mWriter->getInstanceGeometryObjectIdMap()[instanceGeometryIdentifier];
	}

	//------------------------------
	const COLLADAFW::Material* BaseWriter::getFWMaterialByUniqueId(const COLLADAFW::UniqueId& materialUniqueId)
	{
		const Writer::UniqueIdFWMaterialMap& map = mWriter->getUniqueIdFWMaterialMap();
		Writer::UniqueIdFWMaterialMap::const_iterator it = map.find(materialUniqueId);
		if ( it == map.end() )
		{
			return 0;
		}
		else
		{
			return &it->second;
		}
	}

	//------------------------------
	const COLLADAFW::Effect* BaseWriter::getFWEffectByUniqueId( const COLLADAFW::UniqueId& effectUniqueId )
	{
		const Writer::UniqueIdFWEffectMap& map = mWriter->getUniqueIdFWEffectMap();
		Writer::UniqueIdFWEffectMap::const_iterator it = map.find(effectUniqueId);
		if ( it == map.end() )
		{
			return 0;
		}
		else
		{
			return &it->second;
		}
	}

	//------------------------------
	const String& BaseWriter::getFileNameByGeometryMaterialBinding( const Writer::GeometryMaterialBinding& binding ) const
	{
		const Writer::GeometryMaterialBindingFileNameMap& map = mWriter->getGeometryMaterialBindingFileNameMap();
		Writer::GeometryMaterialBindingFileNameMap::const_iterator it = map.find(binding);
		if ( it == map.end())
		{
			//binding not found
			return COLLADABU::Utils::EMPTY_STRING;
		}
		else
		{
			// binding is in map. return the file name
			return it->second;
		}

	}

	//------------------------------
	void BaseWriter::addGeometryMaterialBindingFileNamePair( const Writer::GeometryMaterialBinding& binding, const String& fileName )
	{
		Writer::GeometryMaterialBindingFileNameMap& map = mWriter->getGeometryMaterialBindingFileNameMap();
		map.insert(std::make_pair(binding, fileName));
	}

	//------------------------------
	size_t BaseWriter::getAndIncreaseMeshOccurence( const COLLADAFW::UniqueId& meshUniqueId)
	{
		Writer::MeshOccurencesMap& map = mWriter->getMeshOccurencesMap();
		Writer::MeshOccurencesMap::iterator it = map.find(meshUniqueId);
		if ( it == map.end() )
		{
			// mesh has no occurrences. Add to map
			map.insert(std::make_pair(meshUniqueId, 1));
			return 0;
		}
		else
		{
			size_t oldOcurrence = it->second;
			it->second++;
			return oldOcurrence;
		}

	}

	//------------------------------
	void BaseWriter::addToObjectAndMaterialBlockLength( ChunkLength val )
	{
		mWriter->setObjectAndMaterialBlockLength( mWriter->getObjectAndMaterialBlockLength() + val );
	}

	//------------------------------
	void BaseWriter::addMeshData( const Writer::MeshData& meshData )
	{
		mWriter->getMeshDataMap().insert( std::make_pair( meshData.meshUniqueId, meshData ) );
	}

	//------------------------------
	const Writer::MeshData& BaseWriter::getMeshData( const COLLADAFW::UniqueId& meshUniqueId ) const
	{
		return mWriter->getMeshDataMap()[meshUniqueId];
	}

	//------------------------------
	Writer::ObjectId BaseWriter::getAndIncreaseNextObjectId() const
	{
		Writer::ObjectId nextObjectId = mWriter->getNextObjectId();
		mWriter->setNextObjectId( nextObjectId + 1);
		return nextObjectId;
	}

	//------------------------------
	MaterialNumber BaseWriter::getAndIncreaseNextMaterialNumber() const
	{
		MaterialNumber nextMaterialNumber = mWriter->getNextMaterialNumber();
		mWriter->setNextMaterialNumber( nextMaterialNumber + 1);
		return nextMaterialNumber;
	}

	//------------------------------
	void BaseWriter::addUniqueIdMaterialNumberPair( const COLLADAFW::UniqueId& materialUniqueId, MaterialNumber materialNumber )
	{
		mWriter->getUniqueMaterialNumberMap().insert(std::make_pair(materialUniqueId, materialNumber));
	}

	//------------------------------
	DAE23ds::MaterialNumber BaseWriter::getMaterialNumberByUniqueId( const COLLADAFW::UniqueId& materialUniqueId )
	{
		const Writer::UniqueMaterialNumberMap& map = mWriter->getUniqueMaterialNumberMap();
		Writer::UniqueMaterialNumberMap::const_iterator it = map.find(materialUniqueId);
		if ( it == map.end() )
		{
			return 0;
		}
		else
		{
			return it->second;
		}
	}

} // namespace DAE23ds
