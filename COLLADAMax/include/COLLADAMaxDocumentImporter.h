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


class Interface;
class ImpInterface;

namespace COLLADAFW
{
	class VisualScene;
	class Geometry;
	class UniqueId;
}

namespace COLLADAMax
{
	class DocumentImporter 	: COLLADAFW::IWriter
	{
	public:
		/** Maps Unique id to INodes.*/
		typedef std::multimap<COLLADAFW::UniqueId, INode*> UniqueIdINodeMultiMap;

		/** Maps Unique id to INodes.*/
		typedef std::map<COLLADAFW::UniqueId, INode*> UniqueIdINodeMap;

		/** Maps Unique id to Objects.*/
		typedef std::map<COLLADAFW::UniqueId, Object*> UniqueIdObjectMap;

		/** Maps objects to Unique id to.*/
		typedef std::map< INode*, COLLADAFW::UniqueId> ObjectINodeUniqueIdMap;

	private:
		/** Max interface.*/
		Interface* mMaxInterface;

		/** Max import interface.*/
		ImpInterface* mMaxImportInterface;

		/** File path of the COLLADA document to import.*/
		NativeString mImportFilePath;
		
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
		UniqueIdINodeMultiMap mUniqueIdReferencingINodeMap;

		/** Maps each already imported object to its Unique id. When ever a new object is created it 
		should be added to this map. .*/
		ObjectINodeUniqueIdMap mObjectINodeUniqueIdMap;

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

		/** Deletes the entire scene.
		@param errorMessage A message containing informations about the error that occurred.
		*/
		void cancel(const String& errorMessage){};

		/** Prepare to receive data.*/
		void start(){};

		/** Remove all objects that don't have an object. Deletes unused visual scenes.*/
		void finish(){};

		/** Writes the entire visual scene.
		@return True on succeeded, false otherwise.*/
		bool writeVisualScene ( const COLLADAFW::VisualScene* visualScene );

		/** Handles all nodes in the library nodes.
		@return True on succeeded, false otherwise.*/
		bool writeLibraryNodes( const COLLADAFW::LibraryNodes* libraryNodes );

		/** Writes the geometry.
		@return True on succeeded, false otherwise.*/
		bool writeGeometry ( const COLLADAFW::Geometry* geometry );

	
	private:
        /** Disable default copy ctor. */
		DocumentImporter( const DocumentImporter& pre );
        /** Disable default assignment operator. */
		const DocumentImporter& operator= ( const DocumentImporter& pre );

		/** Returns the UniqueId Object INode Mapping.*/
		UniqueIdINodeMultiMap& getUniqueIdObjectINodeMap(){ return mUniqueIdObjectINodeMap; }

		/** Returns the UniqueId Referencing INode Mapping.*/
		UniqueIdINodeMultiMap& getUniqueIdReferencingINodeMap(){ return mUniqueIdReferencingINodeMap; }

		/** Returns the UniqueId object Mapping.*/
		UniqueIdObjectMap& getUniqueIdObjectMap(){ return mUniqueIdObjectMap; }


		/** Returns the UniqueId INode Mapping.*/
		UniqueIdINodeMap& getUniqueIdINodeMap(){ return mUniqueIdINodeMap; }


		/** Returns the object UniqueId Mapping.*/
		ObjectINodeUniqueIdMap& getObjectINodeUniqueIdMap(){ return mObjectINodeUniqueIdMap; }

		friend class ImporterBase;

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_DOCUMENTIMPORTER_H__
