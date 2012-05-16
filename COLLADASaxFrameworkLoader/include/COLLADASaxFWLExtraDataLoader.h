/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_IROOTPARSER_H__
#define __COLLADASAXFWL_IROOTPARSER_H__

#include "COLLADASaxFWLPrerequisites.h"


namespace COLLADASaxFWL
{
    class FileLoader;

    /** Root class for the parsers. */
	class ExtraDataLoader 	
    {

    public:

        /** Constructor. */
		ExtraDataLoader ();

        /** Destructor. */
		virtual ~ExtraDataLoader();

        /** Returns a pointer to the file loader. */
        virtual FileLoader* getFileLoader() = 0;

        /** Returns a pointer to the file loader. */
        virtual const FileLoader* getFileLoader() const = 0;

        /** Starts loading an extra tag. */
        virtual bool base__begin__technique ( 
            const technique__AttributeData& attributeData, 
            const COLLADAFW::UniqueId& uniqueId );

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId() { return COLLADAFW::UniqueId::INVALID; }

	private:

        /** Disable default copy ctor. */
		ExtraDataLoader( const ExtraDataLoader& pre );

        /** Disable default assignment operator. */
		const ExtraDataLoader& operator= ( const ExtraDataLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_IROOTPARSER_H__
