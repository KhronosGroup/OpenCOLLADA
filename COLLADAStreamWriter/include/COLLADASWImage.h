/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_IMAGE_H__
#define __COLLADASTREAMWRITER_IMAGE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADABUURI.h"

namespace COLLADASW
{

    /** 
    Declares the storage for the graphical representation of an object. 
    Parent elements:
    library_images, effect, profile_CG, profile_GLSL, profile_COMMON,
    profile_GLES, technique (FX) (in profile_CG, profile_COMMON, profile_GLES,
    profile_GLSL)
    */
    class Image : public BaseExtraTechnique
    {

    private:

        /** Contains a string of type xs:anyURI that specifies an external 
        image file. This element has no attributes or child elements.*/
        URI mFileURI;

        /** Contains a sequence of hexadecimal encoded binary octets composing 
        the embedded image data. This element has no attributes or child
        elements. */
        String mData;

        /** A text string containing the unique identifier of the <image> 
        element. This value must be unique within the instance document. 
        Optional. */
        String mId;

        /** The text string name of this element. Optional.*/
        String mNameNC;

        /** A text string value that indicates the image format. It describes 
        the encoding of the image in <data> or the format of the image 
        referenced by <init_from> if it is in a nonstandard format that cannot 
        be identified by its file extension. For example, if <data> in a 
        COLLADASW document contains the digital contents of a JPEG file, then set
        this attribute to "JPG". Optional. */
        String mFormat;

        /** An integer value that indicates the height of the image in pixels. Optional. */
        int mHeight;

        /** An integer value that indicates the width of the image in pixels. Optional. */
        int mWeight;

        /** An integer value that indicates the depth of the image in pixels. 
        A 2-D image has a depth of 1, which is the default. Optional. */
        int mDepth;

    public:

        /** Constructor
        @param fileName The file name of the image.
        @param imageId The id of the image.
        @param imageName The name of the image.
        */
        Image ( 
            const URI& fileURI,
            const String& imageId,
            const String& imageName = ElementWriter::EMPTY_STRING );

        /** Destructor*/
        virtual ~Image() {}

        /** Adds the declaration of the storage for the graphical representation of an object. */
        void add ( StreamWriter* sw ) const;

        /** Returns a reference to the file name*/
        const URI& getFileURI() const { return mFileURI; }

        /** Returns a reference to the image id*/
        const String& getImageId() const { return mId; }

        /** Returns a reference to the image name*/
        const String& getImageName() const { return mNameNC; }

        /** A text string value that indicates the image format. It describes 
        the encoding of the image in <data> or the format of the image 
        referenced by <init_from> if it is in a nonstandard format that cannot 
        be identified by its file extension. For example, if <data> in a 
        COLLADASW document contains the digital contents of a JPEG file, then set
        this attribute to "JPG". Optional. */
        const COLLADASW::String& getFormat () const { return mFormat; }
        void setFormat ( const COLLADASW::String &val ) { mFormat = val; }

    };

}

#endif // __COLLADASTREAMWRITER_IMAGE_H__
