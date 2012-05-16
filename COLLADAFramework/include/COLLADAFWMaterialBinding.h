/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MATERIALBINDING_H__
#define __COLLADAFW_MATERIALBINDING_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTypes.h"
#include "COLLADAFWTextureCoordinateBinding.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAFW
{

    /** Holds informations how to bind a material to a mesh primitive.
    The material with UniqueId @a mReferencedMaterial gets bind to all mesh primitives 
    with material id @a mMaterialId.*/
    class MaterialBinding
    {
    private:

        /** The MaterialId of the mesh primitives that should get bind to a material.*/
        MaterialId mMaterialId;

        /** Unique id of the material that should get bind to the mesh primitives.*/
        UniqueId mReferencedMaterial;

        /** The name of the shading engine. */
        String mName;

        /** A list of bindings of texture maps .*/
        TextureCoordinateBindingArray mTextureCoordinateBindingArray;

    public:

        MaterialBinding ( const MaterialId& materialId, const UniqueId& referencedMaterial )
            : mMaterialId ( materialId )
            , mReferencedMaterial ( referencedMaterial )
        {}

        /** @return MaterialId of the mesh primitives that should get bind to a material.*/
        MaterialId getMaterialId() const { return mMaterialId; }

        /** Sets the MaterialId of the mesh primitives that should get bind to a material.*/
        void setMaterialId(MaterialId val) { mMaterialId = val; }

        /** @return Unique id of the material that should get bind to the mesh primitives.*/
        const UniqueId& getReferencedMaterial() const { return mReferencedMaterial; }

        /** Sets the Unique id of the material that should get bind to the mesh primitives.*/
        void setReferencedMaterial(const UniqueId& val) { mReferencedMaterial = val; }

        /** The comparison operator that only compares the material ids.*/
        bool operator<( const MaterialBinding& rhs) const { return mMaterialId < rhs.mMaterialId; }

        /** The name of the shading engine. */
        const String& getName () const { return mName; }
        void setName ( const String& val ) { mName = val; }

        /** Returns the list of bindings of texture maps .*/
        TextureCoordinateBindingArray& getTextureCoordinateBindingArray() { return  mTextureCoordinateBindingArray; }

        /** Returns the list of bindings of texture maps .*/
        const TextureCoordinateBindingArray& getTextureCoordinateBindingArray() const { return  mTextureCoordinateBindingArray; }

        /** Disable default copy ctor. */
        MaterialBinding( const MaterialBinding& pre )
            : mMaterialId ( pre.mMaterialId )
            , mReferencedMaterial ( pre.mReferencedMaterial )
            , mName ( pre.mName )
            , mTextureCoordinateBindingArray ()
        {
            pre.mTextureCoordinateBindingArray.cloneArray ( mTextureCoordinateBindingArray );
        }

        /** Disable default assignment operator. */
        const MaterialBinding& operator= ( const MaterialBinding& pre )
        {
            mMaterialId = pre.mMaterialId;
            mReferencedMaterial = pre.mReferencedMaterial;
            mName = pre.mName;
            pre.mTextureCoordinateBindingArray.cloneArray ( mTextureCoordinateBindingArray );
            return *this;
        }

    private:
        friend class Array<MaterialBinding>;
        MaterialBinding(){} 

    };

    typedef Array<MaterialBinding> MaterialBindingArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_MATERIALBINDING_H__
