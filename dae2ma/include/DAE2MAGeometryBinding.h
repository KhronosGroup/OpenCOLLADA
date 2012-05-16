/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_GEOMETRYBINDING_H__
#define __DAE2MA_GEOMETRYBINDING_H__

#include "DAE2MAPrerequisites.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWMaterial.h"
#include "COLLADAFWInstanceGeometry.h"


namespace DAE2MA
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


    /** 
    * Used to store for a geometry under a transform node all shadingEngineIds with the 
    * corresponding materialId. 
    */
    typedef std::map<GeometryBinding, const COLLADAFW::MaterialBindingArray*> GeometryMaterialBindingsMap;

} // namespace DAE2MA

#endif // __DAE2MA_GEOMETRYBINDING_H__
