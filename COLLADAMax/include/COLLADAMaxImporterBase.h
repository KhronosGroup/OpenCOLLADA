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

#ifndef __COLLADAMAX_IMPORTERBASE_H__
#define __COLLADAMAX_IMPORTERBASE_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxTypes.h"

#include "COLLADAMaxDocumentImporter.h"
#include "COLLADAFWLight.h"

class Interface;
class ImpInterface;
class INode;
class DummyObject;

namespace COLLADAFW
{
	class UniqueId;
	class LibraryNodes;
	class Node;
	class Material;
	class Effect;
}

namespace COLLADAMax
{

	class DocumentImporter;

    /** The base class of all importer classes. It provides methods  used by all importer classes.*/
	class ImporterBase 	
	{
	public:
		static const String EMPTY_STRING;

	private:
		/** The collada importer the importer belongs to.*/
		DocumentImporter* mDocumentImporter;
	
	protected:

        /** Constructor. 
		@param colladaImporter The collada importer the importer belongs to.
		@param maxInterface The max interface.*/
		ImporterBase(DocumentImporter* colladaImporter);

        /** Destructor. */
		virtual ~ImporterBase();

		/** Returns the document importer.*/
		DocumentImporter* getDocumentImporter() { return mDocumentImporter; }

		/** Creates a new max object with @a superClassId and @a classId. If the object could not be created, 
		null is returned.*/
		void* createMaxObject(SClass_ID superClassId, Class_ID classId);

		/** Returns the max interface.*/
		Interface* getMaxInterface();

		/** Returns the max import interface.*/
		ImpInterface* getMaxImportInterface();

		/** Prints a message in the max gui. Only for debugging purposes.*/
		void printMessage( const String& message);

		/* Returns the time elapsed the instantiation of the importer.*/
		double getElapsedTime() const;

		/** Returns the dummy object used for nodes that do not have an object assigned to.*/
		DummyObject* getDummyObject();

		/** Returns collada importer the importer belongs to.*/
		DocumentImporter* getColladaImporter() { return mDocumentImporter; }

		/** Performs all operations to ensure that the object is referenced by the all nodes
		that need to reference it.
		@tparam FWObject The framework object class of the framework object that became object */
		template<class FWObject>
		bool handleObjectReferences( FWObject* fWobject, Object* object );

		/** Adds an UniqueId-Object INode pair to the UniqueIdObjectINodeMap.  An Object INode 
		is an INode that references an object. For nodes that reference an object that has 
		not already been loaded this method should be called.*/
		void addUniqueIdObjectINodePair(const COLLADAFW::UniqueId& uniqueId, INode* node);

		/** Adds an UniqueId-Referencing INode pair to the UniqueIdReferencingINodeMap. An Referencing INode 
		is an INode that references an INode. For nodes that reference an INode that has 
		not already been loaded this method should be called.*/
		void addUniqueIdReferencingImpNodePair(const COLLADAFW::UniqueId& uniqueId, ImpNode* node);

		/** Removes the UniqueId-Referencing INode pair from the UniqueIdReferencingINodeMap. Remove pairs
		before you start resolving the reference.*/
		void removeUniqueIdReferencingImpNodePair( const COLLADAFW::UniqueId& uniqueId, ImpNode* node );

		/** Fills @a nodeList with all INodes that reference the object with UniqueId @a uniqueId.*/
		void getObjectINodesByUniqueId( const COLLADAFW::UniqueId& uniqueId, INodeList& nodelist );

		/** Returns the the iterator pointing to the first element in the map of Unique id and object nodes.*/
		DocumentImporter::UniqueIdINodeMultiMapConstIterator getUniqueIdObjectINodesBegin() const;

		/** Returns the the iterator pointing beyond the last element in the map of Unique id and object nodes.*/
		DocumentImporter::UniqueIdINodeMultiMapConstIterator getUniqueIdObjectINodesEnd() const;

		/** Returns an INodes that reference the node with UniqueId @a uniqueId or zero if no such node is 
		in the map. */
		ImpNode* getReferencingImpNodesByUniqueId( const COLLADAFW::UniqueId& uniqueId );

		/** Adds an UniqueId-Object pair to the UniqueIdObjectMap. For every imported object this method should 
		be called to ensure that elements that are imported later and instance this object can set the object 
		as reference.*/
		void addUniqueIdObjectPair(const COLLADAFW::UniqueId& uniqueId, Object* object);

		/** Adds an UniqueId-INode pair to the UniqueIdINodeMap. For every imported INode this method should 
		be called to ensure that this node can be referenced later .*/
		void addUniqueIdINodePair( const COLLADAFW::UniqueId& uniqueId, INode* iNode );

		/** Adds an object INode (an INode that references an object) UniqueId pair to the ObjectUniqueIdMap. 
		For every imported INode that references an object this method should be called to ensure that its 
		unique id can be retrieved from the created INode. This is required for instance node handling.*/
		void addObjectINodeUniqueIdPair( INode* object, const COLLADAFW::UniqueId& uniqueId );

		/** Adds UniqueId frame work node pair to the UniqueIdFWNodeMap. 
		For every received node that is in a library nodes and not immediately imported into th max scene graph
		this method should be called. This is required for instance node handling of nodes in a library nodes.*/
		void addUniqueIdFWNodePair( const COLLADAFW::UniqueId& uniqueId, const COLLADAFW::Node* node );

		/** Adds UniqueId frame work material pair to the UniqueIdFWMaterialMap. 
		For every received material that is in a library materials this method should be called. */
		void addUniqueIdFWMaterialPair( const COLLADAFW::UniqueId& uniqueId, const COLLADAFW::Material& material );

		/** Adds UniqueId frame work effect pair to the UniqueIdFWEffectMap. 
		For every received effect that is in a library effect this method should be called. */
		void addUniqueIdFWEffectPair( const COLLADAFW::UniqueId& uniqueId, const COLLADAFW::Effect& effect );

		/** Adds UniqueId frame work image pair to the UniqueIdFWImageMap. 
		For every received image that is in a library image this method should be called. */
		void addUniqueIdFWImagePair( const COLLADAFW::UniqueId& uniqueId, const COLLADAFW::Image& image );

		/** Creates a new NodeMaterialBindingsPair with maxNode set to @a node and an empty material bindings 
		vector and adds it to the NodeMaterialBindingsList. 
		For every max node that references a geometry with set material this method should be called. */
		DocumentImporter::NodeMaterialBindingsPair& createAndAddNodeMaterialBindingsPair( INode* node );

		/** Adds @a libraryNodes to the list of library nodes.*/
		void addLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes );

		/** Adds @a visualScene to the map of visual scenes. @a visualScene will be deleted by the DocumentImporter.*/
		void addVisualScene( const COLLADAFW::VisualScene* visualScene );

		/** Adds the @pair clonedNode and @a originalNode to the list of cloned and original inodes.*/
		void addClonedINodeOriginalINodePair(INode* clonedNode, INode* originalNode);

		/** Adds an object object-name pair  to the ObejctObjectNameMap. Whenever an object is created, 
		add it using this method.*/
		void addObjectObjectNamePair( Object* object, const String& name);

		/** Adds @a vertexColorObjectuniqueId to the list of unique ids of objects that use vertex color. 
		When ever a geometry that uses vertex color is created,	its unique id should be added to this list.*/
		void addVertexColorObjects(const COLLADAFW::UniqueId& vertexColorObjectuniqueId);

		/** Add @a maxController to the list of float controllers created from framework animation with unique id 
		@a animationUniqueId.*/
		void addMaxControllerToAnimationUniqueId( const COLLADAFW::UniqueId& animationUniqueId, Control* maxController);

		/** Add @a animationList to the map of all animation list.*/
		void addAnimationList(  const COLLADAFW::AnimationList& animationList);

		/** Returns the object that was created from the imported object with UniqueId @a uniqueId. If 
		@a uniqueId has not been added using addUniqueIdObjectPair, null is returned.*/
		Object* getObjectByUniqueId( const COLLADAFW::UniqueId& uniqueId);

		/** Returns the INode that was created from the imported node with UniqueId @a uniqueId. If 
		@a uniqueId has not been added using addUniqueIdINodePair, null is returned.*/
		INode* getINodeByUniqueId( const COLLADAFW::UniqueId& uniqueId );

		/** Returns the unique id of the framework object that was  used to create @a object. If 
		@a object  not been added using addObjectINodeUniqueIdPair, an invalid unique id is returned.*/
		const COLLADAFW::UniqueId& getUniqueIdByObjectINode( INode* object );

		/** Returns the frame work node with unique id @a uniqueId, if this node is in an already 
		received library nodes, null otherwise.*/
		const COLLADAFW::Node* getFWNodeByUniqueId( const COLLADAFW::UniqueId& uniqueId );
		
		/** Returns  mUniqueIdFWNodeMap.*/
		const DocumentImporter::UniqueIdFWNodeMap& ImporterBase::getUniqueIdFWNodeMap( );

		/** Returns the frame work material with unique id @a uniqueId, if this node is in an already 
		received material, null otherwise.*/
		const COLLADAFW::Material* getFWMaterialByUniqueId( const COLLADAFW::UniqueId& uniqueId );

		/** Returns the frame work effect with unique id @a uniqueId, if this node is in an already 
		received effect, null otherwise.*/
		const COLLADAFW::Effect* getFWEffectByUniqueId( const COLLADAFW::UniqueId& uniqueId );

		/** Returns the frame work image with unique id @a uniqueId, if this node is in an already 
		received image, null otherwise.*/
		const COLLADAFW::Image* getFWImageByUniqueId( const COLLADAFW::UniqueId& uniqueId );

		/** Returns the list of all nodes that have a material and their material bindings.*/ 
		const DocumentImporter::NodeMaterialBindingsList& getNodeMaterialBindings();

		/** Returns the material id map of geometry with @a uniqueId. If it is not already in the map, a new
		one is created.*/ 
		DocumentImporter::FWMaterialIdMaxMtlIdMap& getMaterialIdMapByGeometryUniqueId( const COLLADAFW::UniqueId& uniqueId);

		/** Returns the SetMapChannelMap of geometry with @a uniqueId. If it is not already in the map, a new
		one is created.*/ 
		DocumentImporter::SetMapChannelMap& getSetMapChannelByGeometryUniqueId( const COLLADAFW::UniqueId& uniqueId );

		/** Returns visual scene with unique id @a visualSceneUniqueId. If not found, null is returned.*/
		const COLLADAFW::VisualScene* getVisualSceneByUniqueId( const COLLADAFW::UniqueId& visualSceneUniqueId);

		/**Returns the list of pairs of cloned nodes and their originals. This is used to assign materials. 
		When ever an inode is cloned, the cloned one and itself should be added to that list.*/ 
		const DocumentImporter::INodeINodePairList& getClonedINodeOriginalINodePairList();

		/** Returns the list of unique ids of objects that use vertex color. */
		const DocumentImporter::UniqueIdList& getVertexColorObjects();

		/** Returns the name of @a object.*/
		const String& getObjectNameByObject( Object* object ) const;

		/** Retrieves the list of max controller created from frame work animation with unique id @a animationUniqueId.
		An empty list is returned, if no controller has been created from the animation. */
		const DocumentImporter::MaxControllerList& getMaxControllerListByAnimationUniqueId( const COLLADAFW::UniqueId& animationUniqueId) const;

		/** Retrieves the animation list with @a uniqueId. If not found, 0 is returned.*/
		const COLLADAFW::AnimationList* getAnimationListByUniqueId(const COLLADAFW::UniqueId& animationListUniqueId) const ;

		/** Retrieves the animation list referenced by @a animatable. If not found, 0 is returned.*/
		const COLLADAFW::AnimationList* getAnimationList( const COLLADAFW::Animatable* animatable );

		/** Functors used to convert values from frame work units into max units.*/
		const DocumentImporter::UnitConversionFunctors& getUnitConversionFunctors() const { return mDocumentImporter->getUnitConversionFunctors(); }

		/** Maps unique ids of controller data to the corresponding controller.*/
		const DocumentImporter::UniqueIdControllerMultiMap& getUniqueIdControllerMap() const { return mDocumentImporter->getUniqueIdControllerMap(); }

		/** Adds the pair @a controllerData, @a controller to the UniqueIdControllerMultiMap.*/
		void addUniqueIdControllerPair( const COLLADAFW::UniqueId& controllerData, const COLLADAFW::Controller* controller);

		/** Returns the morph controller with unique id @a morphControllerUniqueId. Null if not found. */
		const COLLADAFW::MorphController* getMorphControllerByUniqueId( const COLLADAFW::UniqueId& morphControllerUniqueId ) const;

		/** Adds @a morphController to map of all morph controllers found during the first pass. The morph controller will
		be deleted at the end of the import.*/
		void addMorphController( const COLLADAFW::MorphController* morphController );

		/** Returns the skin controller with unique id @a skinControllerUniqueId. Null if not found. */
		const COLLADAFW::SkinController* getSkinControllerByUniqueId( const COLLADAFW::UniqueId& skinControllerUniqueId ) const;

		/** Adds @a skinController to map of all skin controllers found during the first pass. The skin controller will
		be deleted at the end of the import.*/
		void addSkinController( const COLLADAFW::SkinController* skinController );

		/** Maps unique ids of controller data to the corresponding controller.*/
		INode* getINodeBySkinController( const COLLADAFW::UniqueId& skinController ) const { return mDocumentImporter->getSkinControllerINodeMap()[skinController]; }

		/** Adds the pair @a controllerData, @a controller to the UniqueIdControllerMultiMap.*/
		void addSkinControllerINodePair( const COLLADAFW::UniqueId& skinController, INode* inode) { mDocumentImporter->getSkinControllerINodeMap()[skinController] = inode;}

		/** Adds  @a fwLight to the LightList.*/
		void addLight( const COLLADAFW::Light& fwLight) { mDocumentImporter->getLightList().push_back(fwLight);}

		/** Returns the list of framework lights and max lights.*/
		const DocumentImporter::LightList& getLightList() const { return mDocumentImporter->getLightList(); }

		/** Maps the unique ids of  morph controllers that are NOT instantiated in the scene graph but 
		used as source by a skin controller to the INode that references this skin controller.*/
		const DocumentImporter::UniqueIdINodeMap& getMorphUniqueIdINodeMap( ) const { return mDocumentImporter->getMorphUniqueIdINodeMap(); }

		/** Maps the unique ids of  morph controllers that are NOT instantiated in the scene graph but 
		used as source by a skin controller to the INode that references this skin controller.*/
		void addMorphControllerINodePair( const COLLADAFW::UniqueId& morphController, INode* inode) { mDocumentImporter->getMorphUniqueIdINodeMap()[morphController] = inode;}

		/** Returns informations about the entire file being loaded.*/
		const DocumentImporter::FileInfo& getFileInfo() const { return mDocumentImporter->getFileInfo(); }

		/** Converts @a originalValue in units provided by file info to units currently set in max.*/
		float convertSpaceUnit( float originalValue );

		/** Converts a COLLADAFW Matrix4 into a max Matrix3.*/
		void Matrix4ToMaxMatrix3 ( Matrix3 & copy,  const COLLADABU::Math::Matrix4& original  );

		const SkyLightParameters* getSkyLightParametersByUniqueId( const COLLADAFW::UniqueId& uniqueId );

		void addUniqueIdSkyLightParametersPair( const COLLADAFW::UniqueId& lihgtUniqueId, const SkyLightParameters& skyLightParameters);

	private:

        /** Disable default copy ctor. */
		ImporterBase( const ImporterBase& pre );

        /** Disable default assignment operator. */
		const ImporterBase& operator= ( const ImporterBase& pre );
	};



	//------------------------------
	template<class FWObject>
	bool ImporterBase::handleObjectReferences( FWObject* fWobject, Object* object )
	{
		const COLLADAFW::UniqueId& uniqueID = fWobject->getUniqueId();

		const String& objectName = fWobject->getName();
		addUniqueIdObjectPair(uniqueID, object);
		if ( !objectName.empty() )
			addObjectObjectNamePair(object, objectName);

#if 0
		INodeList objectNodeList;
		getObjectINodesByUniqueId(uniqueID, objectNodeList);
		for ( size_t i = 0, count = objectNodeList.size(); i<count; ++i)
		{
			INode* maxNode = objectNodeList[i];
			TCHAR* name = maxNode->GetName();
			if ( !name || !(*name) )
				maxNode->SetName( (char *)objectName.c_str());
			maxNode->SetObjectRef(object);
		}
#endif
		return true;
	}




} // namespace COLLADAMAX

#endif // __COLLADAMAX_IMPORTERBASE_H__
