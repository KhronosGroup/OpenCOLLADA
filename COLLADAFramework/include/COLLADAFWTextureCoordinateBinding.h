/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TEXTURECOORDINATEBINDING_H__
#define __COLLADAFW_TEXTURECOORDINATEBINDING_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** Contains informations which set of texture coordinates is used by which texture, 
    when a common effect containing textures is binded to the material.*/
    class TextureCoordinateBinding
    {	
    private:

        /** The id of a texture map. This id is used with EffectCommon to specify which texture coordinates
        should be used by which texture, especially if different parameters (diffuse, emission...) use different 
        texture coordinates. The TextureCoordinateBinding struct binds this  TextureMapId to the texture coordinates
        of the mesh, using setIndex. See also Texture*/
        TextureMapId mTextureMapId;

        /** The set index of the set of texture coordinates uses by the effect for parameter
        with parameter id. */
        size_t mSetIndex;
        
        /** The semantic used for this texture coordinate binding (<bind_vertex_input> attribute semantic) */
        String mSemantic;

    public:

        /** Constructor. */
        TextureCoordinateBinding() {}

        /** Destructor. */
        virtual ~TextureCoordinateBinding() {}

        /** The id of a texture map. This id is used with EffectCommon to specify which texture coordinates
        should be used by which texture, especially if different parameters (diffuse, emission...) use different 
        texture coordinates. The TextureCoordinateBinding struct binds this  TextureMapId to the texture coordinates
        of the mesh, using setIndex. See also Texture*/
        const TextureMapId& getTextureMapId () const { return mTextureMapId; }
        void setTextureMapId ( const TextureMapId& val ) { mTextureMapId = val; }

        /** The set index of the set of texture coordinates uses by the effect for parameter
        with parameter id. */
        const size_t& getSetIndex () const { return mSetIndex; }
        void setSetIndex ( const size_t& val ) { mSetIndex = val; }
        
        const String& getSemantic() const { return mSemantic; }
        void setSemantic( const String& val ) { mSemantic = val; }

        /** Operator overloading. */
        bool operator<( const TextureCoordinateBinding& rhs) const
        {
            if ( mTextureMapId < rhs.mTextureMapId )
                return true;

            if ( mTextureMapId > rhs.mTextureMapId )
                return false;

            if ( mSetIndex < rhs.mSetIndex )
                return true;

            if ( mSetIndex > rhs.mSetIndex )
                return false;

            return false;
        }


    };
    typedef Array<TextureCoordinateBinding> TextureCoordinateBindingArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_TEXTURECOORDINATEBINDING_H__
