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

namespace COLLADAFW
{
	class UniqueId;
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

		/** Returns collada importer the importer belongs to.*/
		DocumentImporter* getColladaImporter() { return mDocumentImporter; }

		/** Adds an UniqueId-Object INode pair to the UniqueIdObjectINodeMap.  An Object INode 
		is an INode that references an object. For nodes that reference an object that has 
		not already been loaded this method should be called.*/
		void addUniqueIdObjectINodePair(const COLLADAFW::UniqueId& uniqueId, INode* node);

		/** Adds an UniqueId-Referencing INode pair to the UniqueIdReferencingINodeMap. An Referencing INode 
		is an INode that references an INode. For nodes that reference an INode that has 
		not already been loaded this method should be called.*/
		void addUniqueIdReferencingINodePair(const COLLADAFW::UniqueId& uniqueId, INode* node);

		/** Fills @a nodeList with all INodes that reference the object with UniqueId @a uniqueId.*/
		void getObjectINodesByUniqueId( const COLLADAFW::UniqueId& uniqueId, INodeList& nodelist );

		/** Fills @a nodeList with all INodes that reference the node with UniqueId @a uniqueId.*/
		void getReferencingINodesByUniqueId( const COLLADAFW::UniqueId& uniqueId, INodeList& nodelist );

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

		/** Returns the object that was created from the imported object with UniqueId @a uniqueId. If 
		@a uniqueId has not been added using addUniqueIdObjectPair, null is returned.*/
		Object* getObjectByUniqueId( const COLLADAFW::UniqueId& uniqueId);

		/** Returns the INode that was created from the imported node with UniqueId @a uniqueId. If 
		@a uniqueId has not been added using addUniqueIdINodePair, null is returned.*/
		INode* getINodeByUniqueId( const COLLADAFW::UniqueId& uniqueId );

		/** Returns the unique id of the framework object that was  used to create @a object. If 
		@a object  not been added using addObjectINodeUniqueIdPair, an invalid unique id is returned.*/
		const COLLADAFW::UniqueId& getUniqueIdByObjectINode( INode* object );

	private:

        /** Disable default copy ctor. */
		ImporterBase( const ImporterBase& pre );

        /** Disable default assignment operator. */
		const ImporterBase& operator= ( const ImporterBase& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_IMPORTERBASE_H__
