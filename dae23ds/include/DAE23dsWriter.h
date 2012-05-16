/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_WRITER_H__
#define __DAE23DS_WRITER_H__

#include "DAE23dsPrerequisites.h"
#include "DAE23dsChunkIDs.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWVisualScene.h"
#include "COLLADAFWLibraryNodes.h"
#include "COLLADAFWMaterial.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWImage.h"

#include "COLLADABUURI.h"
#include "Math/COLLADABUMathMatrix4.h"

#include <stack>
#include <list>
#include <map>


namespace Common
{
	class Buffer;
}


namespace DAE23ds
{

	typedef unsigned int ChunkLength;
	typedef unsigned short CountType;
	typedef unsigned short IndexType;

	/** Number used to uniquely identify material in the .3ds file.*/
	typedef unsigned long MaterialNumber;

	/** The name of an object name including null termination.*/
	static const size_t OBJECT_NAME_LENGTH = 8;


	// The length of an empty chunk
	static const ChunkLength EMPTY_CHUNK_LENGTH = sizeof(ChunkID) + sizeof(ChunkLength);


	// .3ds support only indices up to 65535
	static const IndexType MAX_INDEX_COUNT = 65535;
//	static const IndexType MAX_INDEX_COUNT = 5;

	static const IndexType MAX_TRIANGLES_PER_BLOCK = MAX_INDEX_COUNT/3;

	// the flags used for faces
	static const CountType FACES_FLAGS = 6;

	// the length of a color chunk that uses rgb byte
	static const ChunkLength COLOR_CHUNK_LENGTH_RGB_BYTE = 15;

	// the length of a rgb byte chunk
	static const ChunkLength CHUNK_RGB_BYTE_LENGTH = 9;

	// the length of the mesh version chunk
	static const ChunkLength MESH_VERSION_CHUNK_LENGTH = EMPTY_CHUNK_LENGTH + sizeof(ChunkLength);

	// mesh version. taken from max export
	static const ChunkLength MESH_VERSION = 3;

	// the length of the M3D_VERSION version chunk
	static const ChunkLength M3D_VERSION_CHUNK_LENGTH = EMPTY_CHUNK_LENGTH + sizeof(ChunkLength);

	// the length of the master scale chunk chunk
	static const ChunkLength EDIT_MASTERSCALE_CHUNK_LENGTH = EMPTY_CHUNK_LENGTH + sizeof(float);

	// M3D_VERSION version. taken from max export
	static const ChunkLength M3D_VERSION = 3;

	// length of a mesh object node pivot
	static const ChunkLength PIVOT_LENGTH = EMPTY_CHUNK_LENGTH + 3*sizeof(float);

	// length of a potion track chunk with one frame
	static const ChunkLength POS_TRACK_TAG_LENGTH = 0x26;

	// length of a rotation track chunk with one frame
	static const ChunkLength ROT_TRACK_TAG_LENGTH = 0x2A;

	// length of a rotation track chunk with one frame
	static const ChunkLength SCL_TRACK_TAG_LENGTH = 0x26;

	// length of a local matrix
	static const ChunkLength TRI_LOCAL_LENGTH = EMPTY_CHUNK_LENGTH + 4*3*sizeof(float);


	static const char MATERIAL_NAME_PREFIX[]  ="Mat"; 



	class Writer : public COLLADAFW::IWriter
	{
	public:
		enum Runs
		{
			SCENEGRAPH_RUN,
			GEOMETRY_RUN
		};

		typedef std::list<const COLLADAFW::LibraryNodes> LibraryNodesList;

		struct InstanceGeometryInfo
		{
			InstanceGeometryInfo( const COLLADAFW::InstanceGeometry* _fwInstanceGeometry, 
				const COLLADABU::Math::Matrix4& _worldMatrix, 
				size_t _instanceNumber)
				:  fwInstanceGeometry(_fwInstanceGeometry)
				, worldMatrix(_worldMatrix)
				, instanceNumber(_instanceNumber) {}
			const COLLADAFW::InstanceGeometry* fwInstanceGeometry;

			COLLADABU::Math::Matrix4 worldMatrix;

			/** the consecutive number of the instance. It is used to assign the correct mesh when instantiating it in the scene graph.*/
			size_t instanceNumber;

			bool operator<( const InstanceGeometryInfo& rhs ) const;
		};


		struct InstanceGeometryIdentifier
		{
			InstanceGeometryIdentifier( const COLLADAFW::InstanceGeometry* _fwInstanceGeometry, 
				size_t _instanceNumber)
				:  fwInstanceGeometry(_fwInstanceGeometry)
				, instanceNumber(_instanceNumber) {}
			const COLLADAFW::InstanceGeometry* fwInstanceGeometry;
			/** the consecutive number of the instance. It is used to assign the correct mesh when instantiating it in the scene graph.*/
			size_t instanceNumber;

			bool operator<( const InstanceGeometryIdentifier& rhs ) const;
		};

		typedef std::map<COLLADAFW::MaterialId /* material id used by mesh primitives*/, COLLADAFW::UniqueId /* Material UniqueId*/ > MaterialBindingMap;


		/** Use to uniquely identify equal meshes, if same geometry with same material binding.*/
		struct GeometryMaterialBinding
		{
			const COLLADAFW::InstanceGeometry* fwInstanceGeometry;

			/** Stores the material binding in a map for faster comparison.*/
			mutable MaterialBindingMap bindingMap;
		};

		/** Maps each unique mesh to its file name. Used to avoid duplication of identical meshes.*/
		typedef std::map< GeometryMaterialBinding, String, bool(*)(const GeometryMaterialBinding& lhs, const GeometryMaterialBinding& rhs)> GeometryMaterialBindingFileNameMap;

		/** Set of GeometryMaterialBinding.*/
		typedef std::set<GeometryMaterialBinding, bool(*)(const GeometryMaterialBinding& lhs, const GeometryMaterialBinding& rhs)> GeometryMaterialBindingSet;

		/** Maps each mesh to the number of occurrences of the mesh, i.e. how often it has been used with diferen material binding.*/
		typedef std::map<COLLADAFW::UniqueId /*mesh unique id*/, size_t /*occurrences */> MeshOccurencesMap;

		typedef std::multimap<COLLADAFW::UniqueId, InstanceGeometryInfo> GeometryUniqueIdInstanceGeometryInfoMap;

		typedef std::set<InstanceGeometryInfo> InstanceGeometryInfoSet;

		/** Id of an object created in a .3ds file. This id is used to create a name of the object.*/
		typedef unsigned long long ObjectId;

		typedef std::vector<ObjectId> ObjectIdList;


		typedef std::map<InstanceGeometryIdentifier, ObjectIdList> InstanceGeometryObjectIdMap;

		/** Maps unique ids of framework materials to the corresponding framework material.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Material> UniqueIdFWMaterialMap;

		/** Maps unique ids of framework images to the corresponding framework image.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Image> UniqueIdFWImageMap;

		/** Maps unique ids of framework effects to the corresponding framework material.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Effect> UniqueIdFWEffectMap;

		enum Severity
		{
			SEVERITY_INFORMATION,
			SEVERITY_WARNING,
			_SEVERITY_ERROR
		};

		struct MeshData
		{
			COLLADAFW::UniqueId meshUniqueId;
			size_t trianglesCount;
			size_t positionsCount;
			String name;
		};

		typedef std::map< COLLADAFW::UniqueId, MeshData > MeshDataMap;

		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Node*> UniqueIdNodeMap;

		typedef std::map< COLLADAFW::UniqueId, MaterialNumber> UniqueMaterialNumberMap;

	private:
		COLLADABU::URI mInputFile;
		COLLADABU::URI mOutputFile;

		/** If true, all the transformations will be applied to meshes and the scene graph will not contain any meshes.*/
		bool mApplyTransformationsToMeshes;

		Common::Buffer* mBuffer;

		Runs mCurrentRun;

		COLLADAFW::VisualScene* mVisualScene;
		LibraryNodesList mLibraryNodesList;
		UniqueIdNodeMap mUniqueIdNodeMap;


		GeometryUniqueIdInstanceGeometryInfoMap mGeometryUniqueIdInstanceGeometryInfoMap;

		/** This set is used to ensure that each instance geometry appears only once in mGeometryUniqueIdInstanceGeometryInfoMap.*/
		InstanceGeometryInfoSet mInstanceGeometryInfoSet;

		MeshOccurencesMap mMeshOccurencesMap;

		GeometryMaterialBindingFileNameMap mGeometryMaterialBindingFileNameMap;

		/** Maps the InstanceGeometry to a list of the object id of the object created for the object. The 
		list contains more than one item if the object is a mesh that needed to be split.*/
		InstanceGeometryObjectIdMap mInstanceGeometryObjectIdMap;

		UniqueIdFWMaterialMap mUniqueIdFWMaterialMap;
		UniqueIdFWImageMap mUniqueIdFWImageMap;
		UniqueIdFWEffectMap mUniqueIdFWEffectMap;

		/** The chunk length of all object block and material blocks.*/
		ChunkLength mObjectAndMaterialBlockLength;

		/** The mesh data of all the meshes parsed at the first run.*/
		MeshDataMap mMeshDataMap;

		/** The Object Id of the next object that will be exported.*/
		ObjectId mNextObjectId;

		/** Maps the effect unique id to the material number used to generate a unique name.*/
		UniqueMaterialNumberMap mUniqueMaterialNumberMap;

		/** The Material number of the next material that will be exported.*/
		MaterialNumber mNextMaterialNumber;

	public:
		Writer( const COLLADABU::URI& inputFile, const COLLADABU::URI& outputFile, bool applyTransformationsToMeshes );
		virtual ~Writer();

	public:
		static void reportError(const String& method, const String& message, Severity severity);

	public:

		bool write();

		/** Deletes the entire scene.
		@param errorMessage A message containing informations about the error that occurred.
		*/
		void cancel(const String& errorMessage);;

		/** Prepare to receive data.*/
		void start();;

		/** Remove all objects that don't have an object. Deletes unused visual scenes.*/
		void finish();;

		/** When this method is called, the writer must write the global document asset.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeGlobalAsset ( const COLLADAFW::FileInfo* asset );

		/** When this method is called, the writer must write the scene.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeScene ( const COLLADAFW::Scene* scene ){ return true;}

		/** Writes the entire visual scene.
		@return True on succeeded, false otherwise.*/
		virtual bool writeVisualScene ( const COLLADAFW::VisualScene* visualScene );

		/** Handles all nodes in the library nodes.
		@return True on succeeded, false otherwise.*/
		virtual bool writeLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes );

		/** Writes the geometry.
		@return True on succeeded, false otherwise.*/
		virtual bool writeGeometry ( const COLLADAFW::Geometry* geometry );

		/** Writes the material.
		@return True on succeeded, false otherwise.*/
		virtual bool writeMaterial( const COLLADAFW::Material* material );

		/** Writes the effect.
		@return True on succeeded, false otherwise.*/
		virtual bool writeEffect( const COLLADAFW::Effect* effect );

		/** Writes the camera.
		@return True on succeeded, false otherwise.*/
		virtual bool writeCamera( const COLLADAFW::Camera* camera );

		/** Writes the image.
		@return True on succeeded, false otherwise.*/
		virtual bool writeImage( const COLLADAFW::Image* image );

		/** Writes the light.
		@return True on succeeded, false otherwise.*/
		virtual bool writeLight( const COLLADAFW::Light* light );

		/** Writes the animation.
		@return True on succeeded, false otherwise.*/
		virtual bool writeAnimation( const COLLADAFW::Animation* animation );

		/** Writes the animation.
		@return True on succeeded, false otherwise.*/
		virtual bool writeAnimationList( const COLLADAFW::AnimationList* animationList );

		/** When this method is called, the writer must write the skin controller data.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeSkinControllerData( const COLLADAFW::SkinControllerData* skinControllerData ){ return true;}

		/** When this method is called, the writer must write the controller.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeController( const COLLADAFW::Controller* controller ) { return true;}

		/** When this method is called, the writer must write the formulas. All the formulas of the entire
		COLLADA file are contained in @a formulas.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeFormulas( const COLLADAFW::Formulas* formulas ){ return true;}

		/** When this method is called, the writer must write the kinematics scene. 
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeKinematicsScene( const COLLADAFW::KinematicsScene* kinematicsScene ){ return true;}
	public:
		/** Compares two GeometryMaterialBinding if the geometries look the same, i.e. mesh and material binding are equal.*/
		static bool compare(const GeometryMaterialBinding& lhs, const GeometryMaterialBinding& rhs);

		/** Returns the string representation of ObjectId @a objectId. This representation is used as the name of the object.
		Do not use in threads!!!!
		*/
		static const char* calculateObjectNameFromObjectId( const ObjectId& objectId);

		/** Returns the string representation of MaterialNumber @a materialNumber. This representation is used as 
		the name of the material.
		Do not use in threads!!!!
		*/
		static const char* calculateMaterialNameFromMaterialNumer( const MaterialNumber& materialNumber);

		/** Returns the length of an object name including null termination. This length is equal for all objects.*/
		static ChunkLength getObjectNameLength();

		/** Returns the length of a material name including null termination. This length is equal for all materials.*/
		static ChunkLength getMaterialNameLength();

	protected:
		friend class BaseWriter;

		GeometryUniqueIdInstanceGeometryInfoMap& getGeometryUniqueIdInstanceGeometryInfoMap() { return mGeometryUniqueIdInstanceGeometryInfoMap; }

		/** This set is used to ensure that each instance geometry appears only once in mGeometryUniqueIdInstanceGeometryInfoMap.*/
		InstanceGeometryInfoSet& getInstanceGeometryInfoSet() { return mInstanceGeometryInfoSet; }

		GeometryMaterialBindingFileNameMap& getGeometryMaterialBindingFileNameMap() { return mGeometryMaterialBindingFileNameMap; }
		const GeometryMaterialBindingFileNameMap& getGeometryMaterialBindingFileNameMap() const { return mGeometryMaterialBindingFileNameMap; }

		MeshOccurencesMap& getMeshOccurencesMap() { return mMeshOccurencesMap; }
		const MeshOccurencesMap& getMeshOccurencesMap() const { return mMeshOccurencesMap; }

		UniqueIdFWMaterialMap& getUniqueIdFWMaterialMap() { return mUniqueIdFWMaterialMap; }

		UniqueIdFWImageMap& getUniqueIdFWImageMap() { return mUniqueIdFWImageMap; }

		UniqueIdFWEffectMap& getUniqueIdFWEffectMap() { return mUniqueIdFWEffectMap; }

		/** Maps the unique id of a mesh to a list of the object names of the object created for this mesh. The 
		list contains more than one item if the mesh needed to be split.*/
		InstanceGeometryObjectIdMap& getInstanceGeometryObjectIdMap() { return mInstanceGeometryObjectIdMap; }

		const COLLADABU::URI& getInputFile() const { return mInputFile; }

		const COLLADABU::URI& getOutputFile() const { return mOutputFile; }

		Common::Buffer& getBuffer() { return *mBuffer; }

		/** The chunk length of all object block and material blocks.*/
		ChunkLength getObjectAndMaterialBlockLength() const { return mObjectAndMaterialBlockLength; }

		/** The chunk length of all object block and material blocks.*/
		void setObjectAndMaterialBlockLength(ChunkLength val) { mObjectAndMaterialBlockLength = val; }

		/** The mesh data of all the meshes parsed at the first run.*/
		MeshDataMap& getMeshDataMap() { return mMeshDataMap; }

		/** Calculates the length of all meshes.*/
		void calculateMeshesLength();

		/** Calculates the length of all material blocks.*/
		void calculateMaterialsBlockLength();

		/** Writes all material blocks.*/
		void writeMaterialsBlocks();

		UniqueIdNodeMap& getUniqueIdNodeMap() { return mUniqueIdNodeMap; }

		/** Maps the effect unique id to the material number used to generate a unique name.*/
		UniqueMaterialNumberMap& getUniqueMaterialNumberMap() { return mUniqueMaterialNumberMap; }

		void createUniqueIdNodeMap( COLLADAFW::Node* node );

		void createUniqueIdNodeMap( const COLLADAFW::NodePointerArray& nodes );

		void createUniqueIdNodeMap();

		/** The Object Id of the next object that will be exported.*/
		ObjectId getNextObjectId() const { return mNextObjectId; }

		/** The Object Id of the next object that will be exported.*/
		void setNextObjectId(ObjectId nextObjectId) { mNextObjectId = nextObjectId; }

		/** The Material number of the next material that will be exported.*/
		MaterialNumber getNextMaterialNumber() const { return mNextMaterialNumber; }

		/** The Material number of the next material that will be exported.*/
		void setNextMaterialNumber(MaterialNumber nextMaterialNumber) { mNextMaterialNumber = nextMaterialNumber; }
		
		bool getApplyTransformationsToMeshes() const { return mApplyTransformationsToMeshes; }


	private:
		/** Disable default copy ctor. */
		Writer( const Writer& pre );
		/** Disable default assignment operator. */
		const Writer& operator= ( const Writer& pre );

		/** Fills the bindingMap of @a materialBinding.*/
		static void fillMaterialBindingMap(const GeometryMaterialBinding& materialBinding);

		bool writeHeader( ChunkLength sceneGraphLength );

		template<class NumberType, char prefix>
		static const char* calculateNameFromNumber( const NumberType& number);
	};

} // namespace DAE23ds

#endif // __DAE23DS_WRITER_H__
