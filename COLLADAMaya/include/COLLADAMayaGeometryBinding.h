/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_GEOMETRYBINDING_H__
#define __COLLADAMAYA_GEOMETRYBINDING_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWMaterial.h"


namespace COLLADAMaya
{

    /**
    * The binding for a geometry and transform node. 
    */
    class GeometryBinding
    {
    private:
        COLLADAFW::UniqueId mSourceId;
        COLLADAFW::UniqueId mTransformId;

        /** Not null, if the current geometry is under the current 
        transformation referenced over a controller element. */
        const COLLADAFW::UniqueId* mControllerId;

    public:
        GeometryBinding () : mControllerId (0) {}

        GeometryBinding ( 
            const COLLADAFW::UniqueId& geometryId, 
            const COLLADAFW::UniqueId& transformId,
            const COLLADAFW::UniqueId* controllerId ) 
            : mSourceId (geometryId)
            , mTransformId (transformId)
            , mControllerId (controllerId)
        {}

        virtual ~GeometryBinding () {}

        /**
         * Can be either a geometry or a controller.
         */
        const COLLADAFW::UniqueId& getSourceId () const { return mSourceId; }
        /**
        * Can be either a geometry or a controller.
        */
        void setSourceId ( const COLLADAFW::UniqueId& val ) { mSourceId = val; }

        const COLLADAFW::UniqueId& getTransformId () const { return mTransformId; }
        void setTransformId ( const COLLADAFW::UniqueId& val ) { mTransformId = val; }

        /** Not null, if the current geometry is under the current 
        transformation referenced over a controller element. */
        const COLLADAFW::UniqueId* getControllerId () const { return mControllerId; }
        void setControllerId ( const COLLADAFW::UniqueId* val ) { mControllerId = val; }

        bool operator<(const GeometryBinding& rhs) const;
        bool operator==(const GeometryBinding& uid) const;
    };



    class MaterialInformation
    {
    private:
        COLLADAFW::UniqueId mMaterialId;
        COLLADAFW::MaterialId mShadingEngineId;

    public:
        MaterialInformation () {}
        MaterialInformation ( 
            const COLLADAFW::UniqueId& materialId, 
            const COLLADAFW::MaterialId& shadingEngineId ) 
            : mMaterialId (materialId)
            , mShadingEngineId (shadingEngineId)
        {}
        virtual ~MaterialInformation () {}

        const COLLADAFW::UniqueId& getMaterialId () const { return mMaterialId; }
        void setMaterialId ( const COLLADAFW::UniqueId& val ) { mMaterialId = val; }

        const COLLADAFW::MaterialId& getShadingEngineId () const { return mShadingEngineId; }
        void setShadingEngineId ( const COLLADAFW::MaterialId& val ) { mShadingEngineId = val; }
    };
    typedef std::map< GeometryBinding, std::vector<MaterialInformation> > GeometryBindingMaterialInfosMap;



} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_GEOMETRYBINDING_H__
