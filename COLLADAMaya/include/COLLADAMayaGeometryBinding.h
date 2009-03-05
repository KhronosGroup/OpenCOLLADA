/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
        COLLADAFW::UniqueId mGeometryId;
        COLLADAFW::UniqueId mTransformId;

    public:
        GeometryBinding ();
        GeometryBinding ( 
            const COLLADAFW::UniqueId& geometryId, 
            const COLLADAFW::UniqueId& transformId ) 
            : mGeometryId (geometryId)
            , mTransformId (transformId)
        {}
        virtual ~GeometryBinding ();

        const COLLADAFW::UniqueId& getGeometryId () const { return mGeometryId; }
        void setGeometryId ( const COLLADAFW::UniqueId& val ) { mGeometryId = val; }

        const COLLADAFW::UniqueId& getTransformId () const { return mTransformId; }
        void setTransformId ( const COLLADAFW::UniqueId& val ) { mTransformId = val; }

        bool operator<(const GeometryBinding& rhs) const;
        bool operator==(const GeometryBinding& uid) const;
    };



    class MaterialInfo
    {
    private:
        COLLADAFW::UniqueId mMaterialId;
        COLLADAFW::MaterialId mShadingEngineId;

    public:
        MaterialInfo () {}
        MaterialInfo ( 
            const COLLADAFW::UniqueId& materialId, 
            const COLLADAFW::MaterialId& shadingEngineId ) 
            : mMaterialId (materialId)
            , mShadingEngineId (shadingEngineId)
        {}
        virtual ~MaterialInfo () {}

        const COLLADAFW::UniqueId& getMaterialId () const { return mMaterialId; }
        void setMaterialId ( const COLLADAFW::UniqueId& val ) { mMaterialId = val; }

        const COLLADAFW::MaterialId& getShadingEngineId () const { return mShadingEngineId; }
        void setShadingEngineId ( const COLLADAFW::MaterialId& val ) { mShadingEngineId = val; }
    };
    typedef std::map< GeometryBinding, std::vector<MaterialInfo> > GeometryBindingMaterialInfosMap;



} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_GEOMETRYBINDING_H__
