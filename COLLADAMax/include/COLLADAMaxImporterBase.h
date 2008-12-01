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

		/** Adds an UniqueId-INode pair to the UniqueIdINodeMap. For nodes that reference an object that has 
		not already been loaded this method should be called.*/
		void addUniqueIdINodePair(const COLLADAFW::UniqueId& uniqueId, INode* node);

	private:

        /** Disable default copy ctor. */
		ImporterBase( const ImporterBase& pre );

        /** Disable default assignment operator. */
		const ImporterBase& operator= ( const ImporterBase& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_IMPORTERBASE_H__
