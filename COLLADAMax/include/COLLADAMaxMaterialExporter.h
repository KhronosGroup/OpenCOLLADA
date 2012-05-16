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


#ifndef __COLLADAMAX_MATERIAL_EXPORTER_H__
#define __COLLADAMAX_MATERIAL_EXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryMaterials.h"

#include "COLLADAMaxDocumentExporter.h"
#include "COLLADAMaxEffectExporter.h"
#include "COLLADAMaxTypes.h"

namespace COLLADAMax
{

    class ExportSceneGraph;

    class ExportNode;

    /** This class writes the @a \<library_materials\>. It uses informations created my an effect exporter*/

    class MaterialExporter : public COLLADASW::LibraryMaterials
    {

    private:
        /** maps already exported wire frame colors to the corresponding COLLADASW effect id*/
        const WireFrameColorEffectList * mWireFrameColorEffectList;

        /** The document exporter*/
        DocumentExporter * mDocumentExporter;

        /** List of the the ids used by all of the effects*/
        ExportedEffectIdAndNameList mExportedEffectIdAndNameList;

    public:
        /**
        @param streamWriter The stream the output will be written to.
        @param documentExporter The document exporter this material exporter is used in.*/
        MaterialExporter ( COLLADASW::StreamWriter * streamWriter, DocumentExporter * documentExporter );

        /** Destructor*/
        virtual ~MaterialExporter()
        {}


        /** Export the library materials.*/
        void doExport();

        /** Creates an id that should be used as id for a material that instantiates the effect that has id @a id.*/
        static String getMaterialIdFromEffectId ( const String & effectId );

        /** Returns a pointer to the material with matID @a materialId.*/
        static Mtl* GetSubMaterialById ( Mtl* mtl, int materialId );

        /** Returns a reference to the Effect ID list.*/
        ExportedEffectIdAndNameList & getEffectIdList()
        {
            return mExportedEffectIdAndNameList;
        }

    private:
        MaterialExporter ( const MaterialExporter & materialExporter );
        MaterialExporter & operator= ( const MaterialExporter & materialExporter );

    };

}

#endif //__COLLADAMAX_MATERIAL_EXPORTER_H__
