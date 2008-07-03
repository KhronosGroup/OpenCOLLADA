/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxMaterialExporter.h"
#include "COLLADANode.h"

#include "COLLADAMaxExportSceneGraph.h"

#include <iparamm2.h>

namespace COLLADAMax
{


    // The information from this file comes from the MaxSDK sample: /material/multi.cpp.

    namespace MultiMaterial
    {
        const Class_ID classID ( MULTI_CLASS_ID, 0 );
        // Reference #s.
        const unsigned int PBLOCK_REF = 0;
        const unsigned int MTL_REF = 1;

        // multi_params param IDs
        enum
        {
            multi_mtls,
            multi_ons,
            multi_names,
            multi_ids,
        };
    };


    //---------------------------------------------------------------
    MaterialExporter::MaterialExporter ( COLLADA::StreamWriter * streamWriter, DocumentExporter * documentExporter )
            : COLLADA::LibraryMaterials ( streamWriter ),
            mDocumentExporter ( documentExporter )
    {}


    //---------------------------------------------------------------
    void MaterialExporter::doExport()
    {

        // set mWireFrameColorEffectList
        mWireFrameColorEffectList = & ( mDocumentExporter->getEffectExporter() ->getWireFrameColorEffectMap() );

        // export all wire frame color materials

        for ( WireFrameColorEffectList::const_iterator it = mWireFrameColorEffectList->begin(); it != mWireFrameColorEffectList->end(); ++it )
        {
            const String & effectURL = EffectExporter::getEffectId ( *it );
            String materialId = getMaterialIdFromEffectId ( effectURL );
            addInstanceEffect ( "#" + effectURL, materialId, materialId );
        }

        // export all ordinary materials

        for ( ExportedEffectIdList::const_iterator it = mExportedEffectIdList.begin(); it != mExportedEffectIdList.end(); ++it )
        {
            const String & effectURL = *it;
            String materialId = getMaterialIdFromEffectId ( effectURL );
            addInstanceEffect ( "#" + effectURL, materialId, materialId );
        }

        closeLibrary();
    }


    //---------------------------------------------------------------
    String MaterialExporter::getMaterialIdFromEffectId ( const String & effectId )
    {
        return effectId + MATERIAL_ID_SUFFIX;
    }


    //---------------------------------------------------------------
    Mtl* MaterialExporter::GetSubMaterialById ( Mtl* mtl, int materialId )
    {
        if ( !mtl->IsMultiMtl() )
            return NULL;

        IParamBlock2* subMaterialParameters = ( IParamBlock2* ) mtl->GetReference ( MultiMaterial::PBLOCK_REF );

        if ( subMaterialParameters == NULL )
            return mtl->GetSubMtl ( materialId );

        // check if we ever reach this point
        assert ( false );

        int subMaterialCount = mtl->NumSubMtls();

        for ( int subMaterialIndex = 0; subMaterialIndex < subMaterialCount; ++subMaterialIndex )
        {
            int subMatId = subMaterialParameters->GetInt ( MultiMaterial::multi_ids, TIME_EXPORT_START, subMaterialIndex );

            if ( subMatId == materialId )
            {
                Mtl * material = mtl->GetSubMtl ( subMaterialIndex );

                if ( material != NULL )
                    return material;
            }
        }

        return NULL;
    }

}
