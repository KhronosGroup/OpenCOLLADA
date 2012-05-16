/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAMaxStableHeaders.h"

#include "COLLADAMaxMaterialExporter.h"
#include "COLLADASWNode.h"

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
    MaterialExporter::MaterialExporter ( COLLADASW::StreamWriter * streamWriter, DocumentExporter * documentExporter )
            : COLLADASW::LibraryMaterials ( streamWriter ),
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

            openMaterial ( materialId, materialId );
            addInstanceEffect ( "#" + effectURL );
            closeMaterial ();
        }

        // export all ordinary materials

        for ( ExportedEffectIdAndNameList::const_iterator it = mExportedEffectIdAndNameList.begin(); it != mExportedEffectIdAndNameList.end(); ++it )
        {
			const EffectIdAndName & effectIdAndName= *it;
			const String & effectURL = effectIdAndName.effectId;
            String materialId = getMaterialIdFromEffectId ( effectURL );

			const String & effectName = effectIdAndName.effectName;
			openMaterial ( materialId, COLLADABU::Utils::checkNCName(effectName) );
            addInstanceEffect ( "#" + effectURL );
            closeMaterial ();
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
            return 0;

        IParamBlock2* subMaterialParameters = ( IParamBlock2* ) mtl->GetReference ( MultiMaterial::PBLOCK_REF );

        if ( !subMaterialParameters )
            return mtl->GetSubMtl ( materialId );

        // check if we ever reach this point
        assert ( false );

        int subMaterialCount = mtl->NumSubMtls();

        for ( int subMaterialIndex = 0; subMaterialIndex < subMaterialCount; ++subMaterialIndex )
        {
            int subMatId = subMaterialParameters->GetInt ( MultiMaterial::multi_ids,0 , subMaterialIndex );

            if ( subMatId == materialId )
            {
                Mtl * material = mtl->GetSubMtl ( subMaterialIndex );

                if ( material )
                    return material;
            }
        }

        return 0;
    }

}
