/*
Copyright (c) 2008 NetAllied Systems GmbH

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

#ifndef __COLLADAMAX_DOCUMENTIMPORTER_H__
#define __COLLADAMAX_DOCUMENTIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWMaterial.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWColor.h"
#include "COLLADAFWImage.h"
#include "COLLADAFWInstanceGeometry.h"

#include <list>

//#include "dummy.h"


class Interface;
class ImpInterface;
class DummyObject;

namespace COLLADAFW
{
	class VisualScene;
	class Geometry;
	class UniqueId;
	class LibraryNodes;
	class Node;
	class Camera;
}

namespace COLLADAMax
{
	class DocumentImporter 	: COLLADAFW::IWriter
	{
	public:
		/** Maps Unique id to INodes.*/
		typedef std::multimap<COLLADAFW::UniqueId, INode*> UniqueIdINodeMultiMap;

		/** Maps Unique id to ImpNodes.*/
		typedef std::multimap<COLLADAFW::UniqueId, ImpNode*> UniqueIdImpNodeMultiMap;

		/** Maps Unique id to INodes.*/
		typedef std::map<COLLADAFW::UniqueId, INode*> UniqueIdINodeMap;

		/** Maps Unique id to Objects.*/
		typedef std::map<COLLADAFW::UniqueId, Object*> UniqueIdObjectMap;

		/** Maps objects to Unique id to.*/
		typedef std::map< INode*, COLLADAFW::UniqueId> ObjectINodeUniqueIdMap;

		/** List of library nodes.*/
		typedef std::list<const COLLADAFW::LibraryNodes*> LibraryNodesList;

		/** Maps Unique id to framework nodes.*/
		typedef std::map<COLLADAFW::UniqueId, const COLLADAFW::Node*> UniqueIdFWNodeMap;

		/** Maps unique ids of framework materials to the corresponding framework material.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Material> UniqueIdFWMaterialMap;

		/** Maps unique ids of framework images to the corresponding framework image.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Image> UniqueIdFWImageMap;

		/** Maps unique ids of framework effects to the corresponding framework material.*/
		typedef std::map<COLLADAFW::UniqueId, COLLADAFW::Effect> UniqueIdFWEffectMap;

		/** Vector of material bindings.*/
		typedef std::vector<COLLADAFW::InstanceGeometry::MaterialBinding> MaterialBindingVector;

		/** Pair of nodes an the instantiated materials.*/
		struct NodeMaterialBindingsPair
		{
			INode* maxNode;
			MaterialBindingVector materialBindings;
		};

		/** List of all max nodes that reference a material and their material bindings.*/
		typedef std::list<NodeMaterialBindingsPair> NodeMaterialBindingsList;

		/** Maps frame work material ids to max material ids.*/
		typedef std::map<COLLADAFW::MaterialId,	MtlID > FWMaterialIdMaxMtlIdMap;

		/** Maps the unique id of a geometry to the material id mapping.*/
		typedef std::map<COLLADAFW::UniqueId, FWMaterialIdMaxMtlIdMap > GeometryMaterialIdMapMap;

		/** List of inode inode pairs.*/
		typedef std::vector<std::pair<INode*, INode*>> INodeINodePairList;

		/** Maps an object to its name.*/
		typedef std::map<Object*, String > ObjectObjectNameMap;

		struct FileInfo
		{
			COLLADABU::URI absoluteFileUri;

		};

	private:
		/** Max interface.*/
		Interface* mMaxInterface;

		/** Max import interface.*/
		ImpInterface* mMaxImportInterface;

		/** File path of the COLLADA document to import.*/
		NativeString mImportFilePath;

		/** The accumulated ambient color.*/
		COLLADAFW::Color mAmbientColor;

		/** The number of ambient colors already added.*/
		size_t mNumberOfAmbientColors;

		/** A dummy helper, that is used for nodes that do not have an object assigned to.*/
		DummyObject* mDummyObject;
		
		/** Maps the unique ids of objects (geometries, controllers,...) that are referenced by INodes to 
		these referencing INodes. This map is being filled while importing the visual scene. It is 
		required for objects that are referenced before they are imported.*/
		UniqueIdINodeMultiMap mUniqueIdObjectINodeMap;

		/** Maps the unique ids of objects (geometries, controllers,...) to the created max object. This map 
		is being filled while importing geometries. */
		UniqueIdObjectMap mUniqueIdObjectMap;

		/** Maps the unique ids of nodes to the created max INode. This map is being filled while importing 
		the visual scene. It is required when ever nodes are referenced, after they have been imported.*/
		UniqueIdINodeMap mUniqueIdINodeMap;

		/** Maps the unique ids of nodes that are instantiated to the created instantiating max INode. This 
		map is being filled while importing the visual scene. It is required when ever nodes are referenced, 
		before they have been imported.*/
		UniqueIdImpNodeMultiMap mUniqueIdReferencingImpNodeMap;

		/** Maps each already imported object to its Unique id. When ever a new object is created it 
		should be added to this map. .*/
		ObjectINodeUniqueIdMap mObjectINodeUniqueIdMap;

		/** Maps Unique ids of nodes that are in a library nodes but not already in the max scene graph to
		the frame word node itself. Each frame work node, that is in a library nodes but not immediately added 
		to the max scene graph should be added to that map. When looking for referenced nodes check this map if
		the referenced node is not already in the max scene graph.*/
		UniqueIdFWNodeMap mUniqueIdFWNodeMap;

		/** This vector contains all library nodes already received by the importer.*/
		LibraryNodesList mLibraryNodesList;

		/** Maps unique ids of framework materials to the corresponding framework material.*/
		UniqueIdFWMaterialMap mUniqueIdFWMaterialMap;

		/** Maps unique ids of framework effects to the corresponding framework effect.*/
		UniqueIdFWEffectMap mUniqueIdFWEffectMap;

		/** Maps unique ids of framework images to the corresponding framework image.*/
		UniqueIdFWImageMap mUniqueIdFWImageMap;

		/** of all max nodes that reference a material and their material bindings.*/
		NodeMaterialBindingsList mNodeMaterialBindingsList;

		/** Maps the unique id of a geometry to the material id mapping.*/
		GeometryMaterialIdMapMap mGeometryMaterialIdMapMap;

		/** List of pairs of cloned nodes and their originals. This is used to assign materials. When ever
		an inode is cloned, the cloned one and itself should be added to that list.*/
		INodeINodePairList mClonedINodeOriginalINodePairList;

		/** Maps an object to its name. Whenever an object is created, add it with its name to this map.*/
		ObjectObjectNameMap mObjectObjectNameMap;

		/** Holds informations about the entire file being loaded.*/
		FileInfo mFileInfo;

	public:
		/** Constructor .
		@param maxInterface The max interface.
		@param the file name of the file to import.*/
		DocumentImporter(Interface * maxInterface, ImpInterface* maxImportInterface, const NativeString &filepath);

		virtual ~DocumentImporter();

		/** Start the import of the model.
		@return True on success, false otherwise. */
		bool import();

		/** Returns the max interface.*/
		Interface* getMaxInterface() { return mMaxInterface; }

		/** Returns the max interface.*/
		ImpInterface* getMaxImportInterface() { return mMaxImportInterface; }

		/** Returns the accumulated ambient color.*/
		const COLLADAFW::Color& getAmbientColor() const { return mAmbientColor; }

		/** Returns the number of accumulated ambient colors.*/
		size_t getNumberOfAmbientColors() const { return mNumberOfAmbientColors; }

		/** Adds @a ambientColor to the total ambient color.*/
		void addAmbientColor( const COLLADAFW::Color& ambientColor);

		/** Deletes the entire scene.
		@param errorMessage A message containing informations about the error that occurred.
		*/
		void cancel(const String& errorMessage){};

		/** Prepare to receive data.*/
		void start(){};

		/** Remove all objects that don't have an object. Deletes unused visual scenes.*/
		void finish(){};

		/** When this method is called, the writer must write the global document asset.
		@return The writer should return true, if writing succeeded, false otherwise.*/
		virtual bool writeGlobalAsset ( const COLLADAFW::FileInfo* asset );;

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

	private:
        /** Disable default copy ctor. */
		DocumentImporter( const DocumentImporter& pre );
        /** Disable default assignment operator. */
		const DocumentImporter& operator= ( const DocumentImporter& pre );

		/** Creates all the materials that are instantiated/referenced in the scene.*/
		bool createAndAssignMaterials();

		/** Returns the dummy object used for nodes that do not have an object assigned to.*/
		DummyObject* getDummyObject(){ return mDummyObject; }

		/** Returns the UniqueId Object INode Mapping.*/
		UniqueIdINodeMultiMap& getUniqueIdObjectINodeMap(){ return mUniqueIdObjectINodeMap; }

		/** Returns the UniqueId Referencing INode Mapping.*/
		UniqueIdImpNodeMultiMap& getUniqueIdReferencingImpNodeMap(){ return mUniqueIdReferencingImpNodeMap; }

		/** Returns the UniqueId object Mapping.*/
		UniqueIdObjectMap& getUniqueIdObjectMap(){ return mUniqueIdObjectMap; }

		/** Returns the UniqueId INode Mapping.*/
		UniqueIdINodeMap& getUniqueIdINodeMap(){ return mUniqueIdINodeMap; }

		/** Returns the object UniqueId Mapping.*/
		ObjectINodeUniqueIdMap& getObjectINodeUniqueIdMap(){ return mObjectINodeUniqueIdMap; }

		/** Returns the Unique id framework node map.*/
		UniqueIdFWNodeMap& getUniqueIdFWNodeMap() { return mUniqueIdFWNodeMap; }

		/** Returns the list of library nodes.*/
		LibraryNodesList& getLibraryNodesList(){ return mLibraryNodesList; }

		/** Returns the UniqueIdFWMaterialMap.*/
		UniqueIdFWMaterialMap& getUniqueIdFWMaterialMap() { return mUniqueIdFWMaterialMap; }

		/** Returns the UniqueIdFWEffectMap.*/
		UniqueIdFWEffectMap& getUniqueIdFWEffectMap() { return mUniqueIdFWEffectMap; }

		/** Returns the UniqueIdFWImageMap.*/
		UniqueIdFWImageMap& getUniqueIdFWImageMap() { return mUniqueIdFWImageMap; }

		/** Returns the NodeMaterialBindingsList.*/
		NodeMaterialBindingsList& getNodeMaterialBindingsList() { return mNodeMaterialBindingsList; }

		/** Return the GeometryMaterialIdMapMap.*/
		GeometryMaterialIdMapMap& getGeometryMaterialIdMapMap() { return  mGeometryMaterialIdMapMap; }

		/**Returns the list of pairs of cloned nodes and their originals. This is used to assign materials. 
		When ever an inode is cloned, the cloned one and itself should be added to that list.*/
		INodeINodePairList& getClonedINodeOriginalINodePairList() { return mClonedINodeOriginalINodePairList; }

		/** Returns the map, that maps an object to its name. Whenever an object is created, add it with 
		its name to this map.*/
		ObjectObjectNameMap& getObjectObjectNameMap() { return mObjectObjectNameMap; }

		/** Returns informations about the entire file being loaded.*/
		const FileInfo& getFileInfo() const { return mFileInfo; }

		friend class ImporterBase;

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_DOCUMENTIMPORTER_H__
