/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_SHADINGBINDING_H__
#define __DAE2MA_SHADINGBINDING_H__

#include "DAE2MAPrerequisites.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWMaterial.h"

#include "MayaDMGroupId.h"
#include "MayaDMGroupParts.h"


namespace DAE2MA
{

    class GroupInfo
    {
    private:
        MayaDM::GroupId mGroupId;
        MayaDM::GroupParts mGroupParts;
        bool mHasGroupParts;
        COLLADAFW::MaterialId mShadingEngineId;
        size_t mTransformInstanceIndex;
        size_t mPrimitiveIndex;

    public:
        GroupInfo () 
            : mTransformInstanceIndex (0)
            , mPrimitiveIndex (0)
            , mHasGroupParts (false)
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
            , mHasGroupParts (false)
        {}

        virtual ~GroupInfo () {}

        const MayaDM::GroupId& getGroupId () const { return mGroupId; }
        void setGroupId ( const MayaDM::GroupId& val ) { mGroupId = val; }

        const bool getHasGroupParts () const { return mHasGroupParts; }
        const MayaDM::GroupParts& getGroupParts () const { return mGroupParts; }
        void setGroupParts ( MayaDM::GroupParts& val ) { mGroupParts = val; mHasGroupParts = true; }

        const COLLADAFW::MaterialId& getShadingEngineId () const { return mShadingEngineId; }
        void setShadingEngineId ( const COLLADAFW::MaterialId& val ) { mShadingEngineId = val; }

        const size_t getTransformInstanceIndex () const { return mTransformInstanceIndex; }
        void setTransformInstanceIndex ( const size_t val ) { mTransformInstanceIndex = val; }

        const size_t getPrimitiveIndex () const { return mPrimitiveIndex; }
        void setPrimitiveIndex ( const size_t val ) { mPrimitiveIndex = val; }
    };

    /**
    * The binding for a geometry, transform node and shading engine. 
    */
    class ShadingBinding
    {
    private:

        COLLADAFW::UniqueId mGeometryId;
        COLLADAFW::UniqueId mTransformId;
        COLLADAFW::MaterialId mShadingEngineId;
        COLLADAFW::UniqueId mControllerId;

        size_t mNumInstances;
        size_t mInstanceIndex;

    public:

        ShadingBinding ();

        ShadingBinding ( 
            const COLLADAFW::UniqueId& geometryId, 
            const COLLADAFW::UniqueId& transformId, 
            const COLLADAFW::MaterialId& shadingEngineId,
            const COLLADAFW::UniqueId& controllerId = COLLADAFW::UniqueId () );

        virtual ~ShadingBinding ();

        const COLLADAFW::UniqueId& getGeometryId () const { return mGeometryId; }
        void setGeometryId ( const COLLADAFW::UniqueId& val ) { mGeometryId = val; }

        const COLLADAFW::UniqueId& getTransformId () const { return mTransformId; }
        void setTransformId ( const COLLADAFW::UniqueId& val ) { mTransformId = val; }

        const COLLADAFW::MaterialId& getShadingEngineId () const { return mShadingEngineId; }
        void setShadingEngineId ( const COLLADAFW::MaterialId& val ) { mShadingEngineId = val; }

        const COLLADAFW::UniqueId& getControllerId () const { return mControllerId; }
        void setControllerId ( const COLLADAFW::UniqueId& val ) { mControllerId = val; }

        const size_t& getNumInstances () const { return mNumInstances; }
        void setNumInstances ( const size_t& val ) { mNumInstances = val; }

        const size_t& getInstanceIndex () const { return mInstanceIndex; }
        void setInstanceIndex ( const size_t& val ) { mInstanceIndex = val; }

        bool operator<(const ShadingBinding& rhs) const;
        bool operator==(const ShadingBinding& uid) const;
    };


    /**
    * The group binding per primitive element for a geometry, transform node and shading engine. 
    */
    typedef std::map< ShadingBinding, std::vector<GroupInfo> > ShadingBindingGroupInfoMap;


} // namespace DAE2MA

#endif // __DAE2MA_SHADINGBINDING_H__
