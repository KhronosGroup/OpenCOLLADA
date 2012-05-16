/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_BASEWRITER_H__
#define __DAE23DS_BASEWRITER_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsWriter.h"


namespace DAE23ds
{

	static const char FILENAME[] = "MAXSCENE";

	class BaseWriter 	
	{
	public:

	private:
		Writer* mWriter;

	public:
		BaseWriter( Writer* writer3ds);

		virtual ~BaseWriter();

		static void reportError(const String& method, const String& message, Writer::Severity severity);

		const Writer::GeometryUniqueIdInstanceGeometryInfoMap& getGeometryUniqueIdInstanceGeometryInfoMap();

		void addInstanceGeometryInstanceGeometryInfoPair(const COLLADAFW::UniqueId& geoId, const Writer::InstanceGeometryInfo& instanceGeoInfo);

		void addInstanceGeometryObjectId( const Writer::InstanceGeometryIdentifier& instanceGeometryIdentifier, const Writer::ObjectId& objectId );

		const Writer::ObjectIdList& getInstanceGeometryObjectIds( const Writer::InstanceGeometryIdentifier& instanceGeometryIdentifier );

		const Writer::UniqueIdFWMaterialMap& getUniqueIdFWMaterialMap() { return mWriter->getUniqueIdFWMaterialMap(); }

		const COLLADAFW::Material* getFWMaterialByUniqueId(const COLLADAFW::UniqueId& materialUniqueId);

		const Writer::UniqueIdFWImageMap& getUniqueIdFWImageMap() { return mWriter->getUniqueIdFWImageMap(); }

		const Writer::UniqueIdFWEffectMap& getUniqueIdFWEffectMap() { return mWriter->getUniqueIdFWEffectMap(); }

		const COLLADAFW::Effect* getFWEffectByUniqueId(const COLLADAFW::UniqueId& effectUniqueId);

		void addUniqueIdMaterialNumberPair( const COLLADAFW::UniqueId& materialUniqueId, MaterialNumber materialNumber );

		MaterialNumber getMaterialNumberByUniqueId( const COLLADAFW::UniqueId& materialUniqueId );

		const String& getFileNameByGeometryMaterialBinding(const Writer::GeometryMaterialBinding& binding) const;

		void addGeometryMaterialBindingFileNamePair(const Writer::GeometryMaterialBinding& binding, const String& fileName);

		size_t getAndIncreaseMeshOccurence(const COLLADAFW::UniqueId& meshUniqueId);

		const COLLADABU::URI& getInputFile() const { return mWriter->getInputFile(); }

		const COLLADABU::URI& getOutputFile() const { return mWriter->getOutputFile(); }

		Common::Buffer& getBuffer() { return mWriter->getBuffer(); }

		/** The chunk length of all object block and material blocks.*/
		ChunkLength getObjectAndMaterialBlockLength() const { return mWriter->getObjectAndMaterialBlockLength(); }

		/** The chunk length of all object block and material blocks.*/
		void setObjectAndMaterialBlockLength(ChunkLength val) { mWriter->setObjectAndMaterialBlockLength(val); }

		void addToObjectAndMaterialBlockLength(ChunkLength val);

		void addMeshData( const Writer::MeshData& meshData );

		const Writer::MeshData& getMeshData( const COLLADAFW::UniqueId& meshUniqueId ) const;

		Writer::UniqueIdNodeMap& getUniqueIdNodeMap() { return mWriter->getUniqueIdNodeMap(); }

		/** The Object Id of the next object that will be exported.*/
		Writer::ObjectId getNextObjectId() const { return mWriter->getNextObjectId(); }

		/** Returns and increases the Object Id of the next object that will be exported.*/
		Writer::ObjectId getAndIncreaseNextObjectId() const;

		/** The Object Id of the next object that will be exported.*/
		MaterialNumber getNextMaterialNumber() const { return mWriter->getNextMaterialNumber(); }

		/** Returns and increases the Object Id of the next object that will be exported.*/
		MaterialNumber getAndIncreaseNextMaterialNumber() const;

		/** If true, all the transformations will be applied to meshes and the scene graph will not contain any meshes.*/
		bool getApplyTransformationsToMeshes() const { return mWriter->getApplyTransformationsToMeshes(); }



	private:

		/** Disable default copy ctor. */
		BaseWriter( const BaseWriter& pre );

		/** Disable default assignment operator. */
		const BaseWriter& operator= ( const BaseWriter& pre );

	};


	// do not use in threads!!!!!
	template<size_t MAX_LENGTH>
	const char* calculateNameWithIndex( ChunkLength index, const String& name )
	{
		// we do not support to big meshes here
		assert(index < 10000);
		static char buffer[MAX_LENGTH + 1];
		size_t basePartLength = min( name.length(), MAX_LENGTH - 4);
		char* p = buffer;
		memcpy( p, name.c_str(), basePartLength);
		p += basePartLength;
		if ( index < 1000) *(p++) = '0';
		if ( index < 100) *(p++) = '0';
		if ( index < 10) *(p++) = '0';
		p += Common::itoa( index, p, 10);
		*(p++) = 0;
		return buffer;
	}


	template<class T>
	T min(T a, T b)
	{
		return (a<b) ? a : b;
	}


	ChunkLength getNodeNameLength( const COLLADAFW::Node* node );


} // namespace DAE23ds

#endif // __DAE23DS_BASEWRITER_H__
