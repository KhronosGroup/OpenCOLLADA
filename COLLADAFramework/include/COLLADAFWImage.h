/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_IMAGE_H__
#define __COLLADAFW_IMAGE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"

#include "COLLADABUURI.h"


namespace COLLADAFW
{

    /** 
    Declares the storage for the graphical representation of an object.
    Digital imagery comes in three main forms of data: raster, vector, and hybrid. Raster imagery comprises a
    sequence of brightness or color values, called picture elements(pixels), that together form the complete
    picture. Vector imagery uses mathematical formulae for curves, lines, and shapes to describe a picture or
    drawing. Hybrid imagery combines both raster and vector information, leveraging their respective strengths,
    to describe the picture.
    The <image> element best describes raster image data, but can conceivably handle other forms of
    imagery. Raster imagery data is organized in n-dimensional arrays. This array organization can be leveraged
    by texture look-up functions to access noncolor values such as displacement, normal, or height field
    values.
    */
	class Image : public ObjectTemplate < COLLADA_TYPE::IMAGE >
    {
	public:
		enum SourceType
		{
			SOURCE_TYPE_URI,
			SOURCE_TYPE_DATA, 
			SOURCE_TYPE_UNKNOWN
		};

		typedef ArrayPrimitiveType<char> CharacterArray;

	private:

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

        /** The source type of the image. */
		SourceType mSourceType;

		/** The name of the image*/
        String mName;

        /** A text string value that indicates the image format. It describes the encoding of the
        image in <data> or the format of the image referenced by <init_from> if it is in a
        nonstandard format that cannot be identified by its file extension. For example, if
        <data> in a COLLADA document contains the digital contents of a JPEG file, then set
        this attribute to "JPG". Optional. */
        String mFormat; 

        /** The height of the image in pixels. */
        unsigned int mHeight; 

		/** The width of the image in pixels. */
        unsigned int mWidth;

        /** The depth of the image in pixels. A 2-D image has a depth of 1, which is the default. Optional. */
        unsigned int mDepth; 

        /** This specifies either embedded image data or an external image file. One of the 
        following must appear:
        • <data>: Contains a sequence of hexadecimal encoded binary octets composing the embedded
        image data. This element has no attributes or child elements.
        • <init_from>: Contains a string of type xs:anyURI that specifies an external image file.
        This element has no attributes or child elements. */

		/** The URI of the image. */
		COLLADABU::URI mImageURI;

		/** Contains a sequence of hexadecimal encoded binary octets composing the embedded
		image data.*/
		// Disable until we really need it to avoid problems with copy/assignemnet operators
		//CharacterArray mData;

	public:

		/** @param objectId The object id of the image.*/
		Image( const UniqueId& uniqueId );

        /** Destructor. */
        virtual ~Image();

        /**
        * The original object id, if it in the original file format exist. 
        */
        const String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const String& val ) { mOriginalId = val; }

		/** Returns the source type of the image. */
		SourceType getSourceType() const { return mSourceType; }

		/** Sets the source type of the image. */
		void setSourceType(SourceType sourceType ) { mSourceType = sourceType; }

        /** Returns the name of the image*/
        const String& getName() const { return mName; }

		/** Returns the name of the image*/
        void setName( const String& name ) { mName = name; }

        /** A text string value that indicates the image format. It describes the encoding of the
        image in <data> or the format of the image referenced by <init_from> if it is in a
        nonstandard format that cannot be identified by its file extension. For example, if
        <data> in a COLLADA document contains the digital contents of a JPEG file, then set
        this attribute to "JPG". Optional. */
        const String& getFormat() const { return mFormat; }

        /** A text string value that indicates the image format. It describes the encoding of the
        image in <data> or the format of the image referenced by <init_from> if it is in a
        nonstandard format that cannot be identified by its file extension. For example, if
        <data> in a COLLADA document contains the digital contents of a JPEG file, then set
        this attribute to "JPG". Optional. */
        void setFormat( const String& format ) { mFormat = format; }

		/** Returns the height of the image in pixels. */
        unsigned int getHeight() const { return mHeight; }

		/** Sets the height of the image in pixels. */
        void setHeight( unsigned int height ) { mHeight = height; }

		/** Returns the width of the image in pixels. */
        unsigned int getWidth() const { return mWidth; }

		/** Sets the width of the image in pixels. */
        void setWidth( unsigned int width ) { mWidth = width; }

		/** Returns the depth of the image in pixels. A 2-D image has a depth of 1, which is the default.*/
        unsigned int getDepth() const { return mDepth; }

		/** Sets the depth of the image in pixels. A 2-D image has a depth of 1, which is the default.*/
        void setDepth( unsigned int depth ) { mDepth = depth; }

		/** Returns the URI of the Image */
		const COLLADABU::URI& getImageURI() const { return mImageURI; }

		/** Returns the URI of the Image */
		void setImageURI( const COLLADABU::URI& imageURI ) { mImageURI = imageURI; }

		/** Returns a sequence of hexadecimal encoded binary octets composing the embedded
		image data.*/
//		const CharacterArray& getData() const { return mData; }

		/** Returns a sequence of hexadecimal encoded binary octets composing the embedded
		image data.*/
//		CharacterArray& getData() { return mData; }


	};

} // namespace COLLADAFW

#endif // __COLLADAFW_IMAGE_H__
