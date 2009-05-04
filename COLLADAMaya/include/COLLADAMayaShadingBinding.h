/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_SHADINGBINDING_H__
#define __COLLADAMAYA_SHADINGBINDING_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWMaterial.h"

#include "MayaDMGroupId.h"


namespace COLLADAMaya
{

    /**
    * The binding for a geometry, transform node and shading engine. 
    */
    class ShadingBinding
    {
    private:

        COLLADAFW::UniqueId mGeometryId;
        COLLADAFW::UniqueId mTransformId;
        COLLADAFW::MaterialId mShadingEngineId;

    public:

        ShadingBinding ();

        ShadingBinding ( 
            const COLLADAFW::UniqueId& geometryId, 
            const COLLADAFW::UniqueId& transformId, 
            const COLLADAFW::MaterialId& shadingEngineId );

        virtual ~ShadingBinding ();

        const COLLADAFW::UniqueId& getGeometryId () const { return mGeometryId; }
        void setGeometryId ( const COLLADAFW::UniqueId& val ) { mGeometryId = val; }

        const COLLADAFW::UniqueId& getTransformId () const { return mTransformId; }
        void setTransformId ( const COLLADAFW::UniqueId& val ) { mTransformId = val; }

        const COLLADAFW::MaterialId& getShadingEngineId () const { return mShadingEngineId; }
        void setShadingEngineId ( const COLLADAFW::MaterialId& val ) { mShadingEngineId = val; }

        bool operator<(const ShadingBinding& rhs) const;
        bool operator==(const ShadingBinding& uid) const;
    };
    /** 
    * The material binding per primitive element for a geometry, transform node and shading engine. 
    */
    typedef std::map< ShadingBinding, std::vector<COLLADAFW::UniqueId> > ShadingBindingMaterialMap;


    class GroupInfo
    {
    private:
        MayaDM::GroupId mGroupId;
        COLLADAFW::MaterialId mShadingEngineId;
        size_t mTransformInstanceIndex;
        size_t mPrimitiveIndex;

    public:
        GroupInfo () 
            : mTransformInstanceIndex (0)
            , mPrimitiveIndex (0)
        {}

        GroupInfo ( 
            const MayaDM::GroupId& groupId, 
            const COLLADAFW::MaterialId& shadingEngineId, 
            const size_t transformInstanceIndex, 
            const size_t primitiveIndex ) 
            : mGroupId ( groupId )
            , mShadingEngineId ( shadingEngineId )
            , mTransformInstanceIndex ( transformInstanceIndex )
            , mPrimitiveIndex ( primitiveIndex )
        {}
        virtual ~GroupInfo () {}

        const MayaDM::GroupId& getGroupId () const { return mGroupId; }
        void setGroupId ( const MayaDM::GroupId& val ) { mGroupId = val; }

        const COLLADAFW::MaterialId& getShadingEngineId () const { return mShadingEngineId; }
        void setShadingEngineId ( const COLLADAFW::MaterialId& val ) { mShadingEngineId = val; }

        const size_t getTransformInstanceIndex () const { return mTransformInstanceIndex; }
        void setTransformInstanceIndex ( const size_t val ) { mTransformInstanceIndex = val; }

        const size_t getPrimitiveIndex () const { return mPrimitiveIndex; }
        void setPrimitiveIndex ( const size_t val ) { mPrimitiveIndex = val; }
    };

    /**
    * The group binding per primitive element for a geometry, transform node and shading engine. 
    */
    typedef std::map< ShadingBinding, std::vector<GroupInfo> > ShadingBindingGroupInfoMap;


} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_SHADINGBINDING_H__
