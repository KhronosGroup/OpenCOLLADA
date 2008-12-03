/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_IMAGE_H__
#define __COLLADAFW_IMAGE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWImageSource.h"


namespace COLLADAFW
{

    /** 
    Declares the storage for the graphical representation of an object.
    Digital imagery comes in three main forms of data: raster, vector, and hybrid. Raster imagery comprises a
    sequence of brightness or color values, called picture elements (pixels), that together form the complete
    picture. Vector imagery uses mathematical formulae for curves, lines, and shapes to describe a picture or
    drawing. Hybrid imagery combines both raster and vector information, leveraging their respective strengths,
    to describe the picture.
    The <image> element best describes raster image data, but can conceivably handle other forms of
    imagery. Raster imagery data is organized in n-dimensional arrays. This array organization can be leveraged
    by texture look-up functions to access noncolor values such as displacement, normal, or height field
    values.
    */
	class Image 	
    {
	private:
	
        /** A text string containing the unique identifier of the <image> element. This value must
        be unique within the instance document. Optional. */
        String mId; 

        /** The text string name of this element. Optional. */
        String mName;

        /** A text string value that indicates the image format. It describes the encoding of the
        image in <data> or the format of the image referenced by <init_from> if it is in a
        nonstandard format that cannot be identified by its file extension. For example, if
        <data> in a COLLADA document contains the digital contents of a JPEG file, then set
        this attribute to "JPG". Optional. */
        String mFormat; 

        /** An integer value that indicates the height of the image in pixels. Optional. */
        unsigned int mHeight; 

        /** An integer value that indicates the width of the image in pixels. Optional. */
        unsigned int mWidth;

        /** An integer value that indicates the depth of the image in pixels. A 2-D image has a
        depth of 1, which is the default. Optional. */
        unsigned int mDepth; 

        /** This specifies either embedded image data or an external image file. One of the 
        following must appear:
        • <data>: Contains a sequence of hexadecimal encoded binary octets composing the embedded
        image data. This element has no attributes or child elements.
        • <init_from>: Contains a string of type xs:anyURI that specifies an external image file.
        This element has no attributes or child elements. */
        ImageSource mImageSource;

	public:

        /** Constructor. */
        Image() {}

        /** Destructor. */
        virtual ~Image() {}

        /** A text string containing the unique identifier of the <image> element. This value must
        be unique within the instance document. Optional. */
        const String getId () const { return mId; }

        /** A text string containing the unique identifier of the <image> element. This value must
        be unique within the instance document. Optional. */
        void setId ( const String Id ) { mId = Id; }

        /** The text string name of this element. Optional. */
        const String getName () const { return mName; }

        /** The text string name of this element. Optional. */
        void setName ( const String Name ) { mName = Name; }

        /** A text string value that indicates the image format. It describes the encoding of the
        image in <data> or the format of the image referenced by <init_from> if it is in a
        nonstandard format that cannot be identified by its file extension. For example, if
        <data> in a COLLADA document contains the digital contents of a JPEG file, then set
        this attribute to "JPG". Optional. */
        const String getFormat () const { return mFormat; }

        /** A text string value that indicates the image format. It describes the encoding of the
        image in <data> or the format of the image referenced by <init_from> if it is in a
        nonstandard format that cannot be identified by its file extension. For example, if
        <data> in a COLLADA document contains the digital contents of a JPEG file, then set
        this attribute to "JPG". Optional. */
        void setFormat ( const String Format ) { mFormat = Format; }

        /** An integer value that indicates the height of the image in pixels. Optional. */
        const unsigned int getHeight () const { return mHeight; }

        /** An integer value that indicates the height of the image in pixels. Optional. */
        void setHeight ( const unsigned int Height ) { mHeight = Height; }

        /** An integer value that indicates the width of the image in pixels. Optional. */
        const unsigned int getWidth () const { return mWidth; }

        /** An integer value that indicates the width of the image in pixels. Optional. */
        void setWidth ( const unsigned int Width ) { mWidth = Width; }

        /** An integer value that indicates the depth of the image in pixels. A 2-D image has a
        depth of 1, which is the default. Optional. */
        const unsigned int getDepth () const { return mDepth; }

        /** An integer value that indicates the depth of the image in pixels. A 2-D image has a
        depth of 1, which is the default. Optional. */
        void setDepth ( const unsigned int Depth ) { mDepth = Depth; }

	private:

        /** Disable default copy ctor. */
		Image( const Image& pre );

        /** Disable default assignment operator. */
		const Image& operator= ( const Image& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_IMAGE_H__
