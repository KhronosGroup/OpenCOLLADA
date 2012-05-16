/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_IMAGESOURCE_H__
#define __COLLADAFW_IMAGESOURCE_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** 
    This specifies either embedded image data or an external image file. One of the 
    following must appear:
    • <data>: Contains a sequence of hexadecimal encoded binary octets composing the embedded
    image data. This element has no attributes or child elements.
    • <init_from>: Contains a string of type xs:anyURI that specifies an external image file.
    This element has no attributes or child elements.
    */
	class ImageSource 	
    {
    public:

        enum SourceType
        {
            SOURCE_TYPE_URI,
            SOURCE_TYPE_DATA, 
            SOURCE_TYPE_UNKNOWN
        };

	private:
	
        /** The source type of the current image source element. */
        SourceType mSourceType;

        /** Contains a string of type xs:anyURI that specifies an external image file.
        This element has no attributes or child elements. */
        COLLADABU::URI mInitFrom;

        /** Contains a sequence of hexadecimal encoded binary octets composing the embedded
        image data. This element has no attributes or child elements. */
        String mData;

	public:

        /** Constructor. */
        ImageSource() : mSourceType ( SOURCE_TYPE_UNKNOWN ) {}

        /** Constructor. */
        ImageSource( const String& data ) 
            : mSourceType ( SOURCE_TYPE_DATA )
            , mData ( data )
        {}

        /** Constructor. */
        ImageSource( const COLLADABU::URI& initialURL ) 
            : mSourceType ( SOURCE_TYPE_URI )
            , mInitFrom ( initialURL )
        {}

        /** Destructor. */
		virtual ~ImageSource();

        /** Contains a string of type xs:anyURI that specifies an external image file.
        This element has no attributes or child elements. */
        const COLLADABU::URI getInitFrom () const { return mInitFrom; }

        /** Contains a string of type xs:anyURI that specifies an external image file.
        This element has no attributes or child elements. */
        void setInitFrom ( const COLLADABU::URI InitFrom ) { mInitFrom = InitFrom; }

        /** Contains a sequence of hexadecimal encoded binary octets composing the embedded
        image data. This element has no attributes or child elements. */
        const String getData () const { return mData; }

        /** Contains a sequence of hexadecimal encoded binary octets composing the embedded
        image data. This element has no attributes or child elements. */
        void setData ( const String Data ) { mData = Data; }

	private:

        /** Disable default copy ctor. */
		ImageSource( const ImageSource& pre );

        /** Disable default assignment operator. */
		const ImageSource& operator= ( const ImageSource& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_IMAGESOURCE_H__
