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
		typedef std::multimap<COLLADAFW::UniqueId, INode*> UniqueIdINodeMap;

		/** Maps Unique id to Objects.*/
		typedef std::map<COLLADAFW::UniqueId, Object*> UniqueIdObjectMap;

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
		UniqueIdINodeMap mUniqueIdObjectINodeMap;

		/** Maps the unique ids of objects (geometries, controllers,...) to the created max object. This map 
		is being filled while importing geometries. */
		UniqueIdObjectMap mUniqueIdObjectMap;

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

		/** Writes the geometry.
		@return True on succeeded, false otherwise.*/
		bool writeGeometry ( const COLLADAFW::Geometry* geometry );

	
	private:
        /** Disable default copy ctor. */
		DocumentImporter( const DocumentImporter& pre );
        /** Disable default assignment operator. */
		const DocumentImporter& operator= ( const DocumentImporter& pre );

		/** Returns the UniqueId INode Mapping.*/
		UniqueIdINodeMap& getUniqueIdINodeMap(){ return mUniqueIdObjectINodeMap; }

		/** Returns the UniqueId object Mapping.*/
		UniqueIdObjectMap& getUniqueIdObjectMap(){ return mUniqueIdObjectMap; }

		friend class ImporterBase;

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_DOCUMENTIMPORTER_H__
