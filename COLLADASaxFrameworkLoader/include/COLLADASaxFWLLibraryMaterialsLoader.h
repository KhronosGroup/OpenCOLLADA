/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYMATERIALSLOADER_H__
#define __COLLADASAXFWL_LIBRARYMATERIALSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLXmlTypes.h"


namespace COLLADAFW
{
	class Material;
}


namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class LibraryMaterialsLoader : public FilePartLoader
	{
	private:
		/** The material currently being parsed.*/
		COLLADAFW::Material* mCurrentMaterial;

        /** True, if the parser is in the instance_effect element. */
        bool mInInstanceEffect;

	public:

        /** Constructor. */
		LibraryMaterialsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryMaterialsLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();


		/** Create new current material.*/
		virtual bool begin__material( const material__AttributeData& attributeData );

		/** Sends current material to the writer an deletes it afterwards.*/
		virtual bool end__material();

		/** Set the referenced effect in the current material.*/
		virtual bool begin__instance_effect( const instance_effect__AttributeData& attributeData );

		/** We don't need to do anything here.*/
		virtual bool end__instance_effect();

		/** Finishes the material loader.*/
		virtual bool end__library_materials();

	private:

        /** Disable default copy ctor. */
		LibraryMaterialsLoader( const LibraryMaterialsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryMaterialsLoader& operator= ( const LibraryMaterialsLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYMATERIALSLOADER_H__
