/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_TEXTURE_H__
#define __COLLADASTREAMWRITER_TEXTURE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWColor.h"
#include "COLLADASWSampler.h"
#include <vector>
#include <map>


namespace COLLADASW
{

    class Texture : public BaseExtraTechnique
    {

    private:

        String mSid;

        /** the ID of the image element assigned to the texture. Required. */
        String mImageID;

        /** The surface. For possible type values see domFx_surface_type_enum in domTypes.h. Required. */
//        Surface mSurface;

        /** Declares the storage for the graphical representation of an object. */
        Sampler mSampler;

        /** texcoord.*/
        String mTexcoord;

        /** The name of the profile, if we want to add the texture as an extra technique tag. */
        String mProfileName;

        /** The name of the child element, if we have set a profile name and we want
        to add the texture as an extra technique tag under a child element.*/
        String mChildElementName;

    public:

        /**Constructor that sets all required attributes and the default values for optional attributes.*/
        Texture ( const String &imageID, const String &sid="" );

        /**Constructor that creates an invalid texture.*/
        Texture();

        /** Destructor */
        ~Texture() {};

        /** Chick, if the Texture is valid*/
        bool isValid() const;

        /** Sets the texcoord. */
        void setTexcoord ( const String texcoord );

        /** Returns the texcoord*/
        const String& getTexcoord() const;

        /** Returns the image ID*/
        const String& getImageID() const;

        /** Returns the image ID*/
        const String& getImageId() const;

        void setImageId ( String imageId );

        /** Returns the surface. */
//        const Surface& getSurface() const;

        /** Returns the surface. */
//        void setSurface ( const Surface& surface );

        /** Declares the storage for the graphical representation of an object. */
        const Sampler& getSampler () const;

        /** Declares the storage for the graphical representation of an object. */
        void setSampler ( const Sampler& val );

        /** Returns the sid of the sampler used by this texture*/
        String getSamplerSid() const;

        /** Returns the sid of the surface used by this texture*/
        String getSurfaceSid() const;

        /** comparison operator*/
        bool operator== ( const Texture& other ) const;

        /**
        * Set the name of the profile, if we want to add the texture as an extra technique tag.
        * @param profileName Name of the extra technique profile.
        */
        void setProfileName(const String& profileName)  { mProfileName = profileName; }
        /**
        * Get the name of the profile, if we want to add the texture as an extra technique tag.
        * @return mProfileName Name of the extra technique profile.
        */
        const String& getProfileName() const { return mProfileName; }

        /**
        * Set the name of the child element, if we have set a profile name and we want
        * to add the texture as an extra technique tag under a child element.
        * @param childElementName Name of the child element.
        */
        void setChildElementName(const String& childElementName)  { mChildElementName = childElementName; }
        /**
        * Get the name of the child element, if we have set a profile name and we want
        * to add the texture as an extra technique tag under a child element.
        * @return childElementName Name of the child element.
        */
        const String& getChildElementName() const { return mChildElementName; }

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_TEXTURE_H__
