/*
	Copyright (c) 2010 yaoyansi<yaoyansi2@yahoo.com.cn>

	This file is part of dae23ds_lib3ds.

	Licensed under the MIT Open Source License, 
	for details please see LICENSE file or the website
	http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_WRITER_H__
#define __DAE23DS_WRITER_H__

#include "DAE23dsPrerequisites.h"

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
class Lib3dsFile;
class Lib3dsMesh;
class Lib3dsTextureMap;

namespace DAE23ds
{

	typedef unsigned short CountType;
	typedef unsigned short IndexType;

	// .3ds support only indices up to 65535
	//static const IndexType MAX_INDEX_COUNT = 65535;

	//static const IndexType MAX_TRIANGLES_PER_BLOCK = MAX_INDEX_COUNT/3;

	// the flags used for faces
	//static const CountType FACES_FLAGS = 6;

	class TempMaterialIndex
	{
	public:
		TempMaterialIndex(){}
		virtual ~TempMaterialIndex(){}
		size_t add(const String& name)
		{
			//std::vector<String>::iterator it = m_materialname.find(name);
			std::vector<String>::iterator it =
				std::find(m_materialname.begin(), m_materialname.end(), name);
			if( it==m_materialname.end() ){
				m_materialname.push_back(name);
				return m_materialname.size()-1;
			}
			return std::distance(m_materialname.begin(), it);
		}
		int getIndex(const String& name)
		{
			//std::vector<String>::iterator it = m_materialname.find(name);
			std::vector<String>::iterator it =
				std::find(m_materialname.begin(), m_materialname.end(), name);
			if( it==m_materialname.end() ){
				return -1;
			}
			return std::distance(m_materialname.begin(), it);
		}
		const size_t getSize()const { return m_materialname.size(); }
		const String& getName(const size_t index)const 
		{
			assert( index<getSize() );
			return m_materialname.at(index);
		}
		void print(const String& tip)const 
		{
			std::cout<< tip <<std::endl;
			for(std::vector<String>::const_iterator i=m_materialname.begin();
				i!=m_materialname.end(); ++i)
			{
				std::cout <<"\t\t:"<< *i<< std::endl;
			}
		}

	protected:
		std::vector<String> m_materialname;

	};

	//////////////////////////////////////////////////////////////////////////
	class Writer : public COLLADAFW::IWriter
	{
	public:

		typedef std::list<const COLLADAFW::LibraryNodes> LibraryNodesList;

		struct InstanceGeometryInfo
		{
			InstanceGeometryInfo( const COLLADAFW::InstanceGeometry* _fwInstanceGeometry, 
				const COLLADABU::Math::Matrix4& _worldMatrix)
				:  fwInstanceGeometry(_fwInstanceGeometry)
				, worldMatrix(_worldMatrix)
			{

			}
			const COLLADAFW::InstanceGeometry* fwInstanceGeometry;

			COLLADABU::Math::Matrix4 worldMatrix;

			bool operator<( const InstanceGeometryInfo& rhs ) const;
		};


		typedef std::multimap<COLLADAFW::UniqueId, InstanceGeometryInfo> GeometryUniqueIdInstanceGeometryInfoMap;

		typedef std::set<InstanceGeometryInfo> InstanceGeometryInfoSet;

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

		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Node*> UniqueIdNodeMap;

	private:
		COLLADABU::URI mInputFile;
		COLLADABU::URI mOutputFile;

		/** If true, all the transformations will be applied to meshes and the scene graph will not contain any meshes.*/
		bool mApplyTransformationsToMeshes;

		COLLADAFW::VisualScene* mVisualScene;
		LibraryNodesList mLibraryNodesList;
		UniqueIdNodeMap mUniqueIdNodeMap;


		GeometryUniqueIdInstanceGeometryInfoMap mGeometryUniqueIdInstanceGeometryInfoMap;

		/** This set is used to ensure that each instance geometry appears only once in mGeometryUniqueIdInstanceGeometryInfoMap.*/
		InstanceGeometryInfoSet mInstanceGeometryInfoSet;

		UniqueIdFWMaterialMap mUniqueIdFWMaterialMap;
		UniqueIdFWImageMap mUniqueIdFWImageMap;
		UniqueIdFWEffectMap mUniqueIdFWEffectMap;

	public:
		void init( const COLLADABU::URI& inputFile,const COLLADABU::URI& outputFile,bool applyTransformationsToMeshes );

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
		GeometryUniqueIdInstanceGeometryInfoMap& getGeometryUniqueIdInstanceGeometryInfoMap() { return mGeometryUniqueIdInstanceGeometryInfoMap; }

		/** This set is used to ensure that each instance geometry appears only once in mGeometryUniqueIdInstanceGeometryInfoMap.*/
		InstanceGeometryInfoSet& getInstanceGeometryInfoSet() { return mInstanceGeometryInfoSet; }

		UniqueIdFWMaterialMap& getUniqueIdFWMaterialMap() { return mUniqueIdFWMaterialMap; }

		UniqueIdFWImageMap& getUniqueIdFWImageMap() { return mUniqueIdFWImageMap; }

		UniqueIdFWEffectMap& getUniqueIdFWEffectMap() { return mUniqueIdFWEffectMap; }

		const COLLADABU::URI& getInputFile() const { return mInputFile; }

		const COLLADABU::URI& getOutputFile() const { return mOutputFile; }

	public:
		UniqueIdNodeMap& getUniqueIdNodeMap() { return mUniqueIdNodeMap; }

		void createUniqueIdNodeMap( COLLADAFW::Node* node );

		void createUniqueIdNodeMap( const COLLADAFW::NodePointerArray& nodes );

		void createUniqueIdNodeMap();

	public:
		bool getApplyTransformationsToMeshes() const { return mApplyTransformationsToMeshes; }


	private:
		/** Disable default copy ctor. */
		Writer( const Writer& pre );
		/** Disable default assignment operator. */
		const Writer& operator= ( const Writer& pre );

	public:
		Lib3dsFile *_3dsfile;
		std::map<COLLADAFW::UniqueId, Lib3dsMesh*> _3dsmeshMap;

		Lib3dsMesh* find3dsMesh(const COLLADAFW::UniqueId &uid);
		Lib3dsFile* get3dsFile(){ return _3dsfile; }

		void printMaps();
		void printMaterialBindingArray(const String&tip, const COLLADAFW::MaterialBindingArray& array);
		void printCommonEffectPointerArray(const String&tip, const COLLADAFW::CommonEffectPointerArray& array);
		int getMaterialIndex(const COLLADAFW::UniqueId& uid);

		void writeMaterial_lib3ds();
		void writeMesh_lib3ds();
		void writeInstanceMesh_lib3ds();
	
		void _writeMaterial_lib3ds( const COLLADAFW::Material* material );
		void _writeGeometry_lib3ds(const COLLADAFW::Geometry* geometry);
		void _writeInstanceMesh_lib3ds(const COLLADAFW::UniqueId& meshUniqueId);

		//we use the order of tempMaterialIndex to write materials.
		TempMaterialIndex tempMaterialIndex;//e.g.blinn1SG,lambert2SG,phong1SG,initialShadingGroup,
	
public:
		const TempMaterialIndex& getTempMaterialIndex() const{ return tempMaterialIndex; }

		std::map<COLLADAFW::UniqueId, const COLLADAFW::Light*> lightMap;

		void assignTextureName(Lib3dsTextureMap* _3dsTexMap, const COLLADAFW::ColorOrTexture &texture, const COLLADAFW::EffectCommon *effectcommon);
		const COLLADAFW::EffectCommon* getEffectCommon( const COLLADAFW::Material* material);
		const COLLADAFW::Effect* getFWEffectByUniqueId( const COLLADAFW::UniqueId& effectUniqueId );

		std::set<const COLLADAFW::UniqueId> meshUID;
	public:
		Writer();
		static Writer* getInstance();
	protected:
		static Writer *m_instance;

	};
#define min(x, y) ( (x)<(y)? (x):(y) )
} // namespace DAE23ds

#endif // __DAE23DS_WRITER_H__
