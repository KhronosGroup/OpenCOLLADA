/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYIMAGESLOADER_H__
#define __COLLADASAXFWL_LIBRARYIMAGESLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLXmlTypes.h"


namespace COLLADAFW
{
	class Image;
}


namespace COLLADASaxFWL
{

	/** Loads all the images in a library images.  */
	class LibraryImagesLoader : public FilePartLoader
	{
	private:
		/** The current image.*/
		COLLADAFW::Image* mCurrentImage;

	public:

        /** Constructor. */
		LibraryImagesLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryImagesLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

        
        /** Finishes loading a library images.*/
		virtual bool end__library_images();

		
		/** Creates a new image.*/
		virtual bool begin__image( const image__AttributeData& attributeData );

		/** Sends image to the writer.*/
		virtual bool end__image();


		/** Set source type.*/
		virtual bool begin__init_from____anyURI();

		/** Set the image uri.*/
		virtual bool end__init_from____anyURI();

		/** Set the image uri.*/
		virtual bool data__init_from____anyURI( COLLADABU::URI value );


		/** Set source type.*/
		virtual bool begin__data();

		/** We don't need to do anything here.*/
		virtual bool end__data(){return true;}

		/** Store data in current image.*/
		virtual bool data__data( const uint8* data, size_t length );

	private:

        /** Disable default copy ctor. */
		LibraryImagesLoader( const LibraryImagesLoader& pre );

        /** Disable default assignment operator. */
		const LibraryImagesLoader& operator= ( const LibraryImagesLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYIMAGESLOADER_H__
