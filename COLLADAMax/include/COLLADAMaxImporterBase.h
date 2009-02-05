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

#ifndef __COLLADAMAX_IMPORTERBASE_H__
#define __COLLADAMAX_IMPORTERBASE_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxTypes.h"

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

		/** Returns the max interface.*/
		Interface* getMaxInterface();

		/** Returns the max import interface.*/
		ImpInterface* getMaxImportInterface();

		/** Returns the dummy object used for nodes that do not have an object assigned to.*/
		DummyObject* getDummyObject();

		/** Returns collada importer the importer belongs to.*/
		DocumentImporter* getColladaImporter() { return mDocumentImporter; }

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

		/** Adds @a libraryNodes to the list of library nodes.*/
		void addLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes );

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

		/** Returns the frame work material with unique id @a uniqueId, if this node is in an already 
		received material, null otherwise.*/
		const COLLADAFW::Material* getFWMaterialByUniqueId( const COLLADAFW::UniqueId& uniqueId );

		/** Returns the frame work effect with unique id @a uniqueId, if this node is in an already 
		received effect, null otherwise.*/
		const COLLADAFW::Effect* getFWEffectByUniqueId( const COLLADAFW::UniqueId& uniqueId );


	private:

        /** Disable default copy ctor. */
		ImporterBase( const ImporterBase& pre );

        /** Disable default assignment operator. */
		const ImporterBase& operator= ( const ImporterBase& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_IMPORTERBASE_H__
