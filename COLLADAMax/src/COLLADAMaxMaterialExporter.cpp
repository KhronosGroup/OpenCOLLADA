/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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
