/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryImagesLoader.h"
#include "COLLADASaxFWLLoader.h"

#include "COLLADAFWImage.h"
#include "COLLADAFWIWriter.h"


namespace COLLADASaxFWL
{

    //------------------------------
	LibraryImagesLoader::LibraryImagesLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentImage(0)
	{

	}

    //------------------------------
	LibraryImagesLoader::~LibraryImagesLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& LibraryImagesLoader::getUniqueId()
    {
        if ( mCurrentImage )
            return mCurrentImage->getUniqueId();
        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	bool LibraryImagesLoader::end__library_images()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

	//------------------------------
	bool LibraryImagesLoader::begin__image( const image__AttributeData& attributeData )
	{
		mCurrentImage = FW_NEW COLLADAFW::Image( createUniqueIdFromId( attributeData.id, COLLADAFW::Image::ID()) );

		if ( attributeData.name )
			mCurrentImage->setName( (const char*) attributeData.name );
		else if ( attributeData.id )
			mCurrentImage->setName( (const char*) attributeData.id );

        if ( attributeData.id )
            mCurrentImage->setOriginalId ( (const char*)attributeData.id );

		if ( attributeData.format )
			mCurrentImage->setFormat( attributeData.format );
		
		mCurrentImage->setHeight( (unsigned long)attributeData.height );
		mCurrentImage->setWidth( (unsigned long)attributeData.width );
		mCurrentImage->setDepth( (unsigned long)attributeData.depth );

		return true;
	}

	//------------------------------
	bool LibraryImagesLoader::end__image()
	{
		bool success = true;
		if ( (getObjectFlags() & Loader::IMAGE_FLAG) != 0 )
		{
		    success = writer()->writeImage(mCurrentImage);
		}
		FW_DELETE mCurrentImage;
		mCurrentImage = 0;
		return success;
	}

	//------------------------------
	bool LibraryImagesLoader::begin__init_from____anyURI()
	{
		mCurrentImage->setSourceType( COLLADAFW::Image::SOURCE_TYPE_URI );
		return true;
	}

	//------------------------------
	bool LibraryImagesLoader::end__init_from____anyURI()
	{
		// we don't need to do anything here
		return true;
	}

	//------------------------------
	bool LibraryImagesLoader::data__init_from____anyURI( COLLADABU::URI value )
	{
		mCurrentImage->setImageURI( value );
		return true;
	}

	//------------------------------
	bool LibraryImagesLoader::begin__data()
	{
		// disabled see COLALDAFW::Image
		//mCurrentImage->setSourceType( COLLADAFW::Image::SOURCE_TYPE_DATA);
		return true;
	}

	//------------------------------
	bool LibraryImagesLoader::data__data( const uint8* data, size_t length )
	{
		// disabled see COLALDAFW::Image
		//COLLADAFW::Image::CharacterArray& dataArray = mCurrentImage->getData();
		//dataArray.appendValues( (char *)data, length );
		return true;
	}

} // namespace COLLADASaxFWL
