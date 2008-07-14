/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_MATERIAL_EXPORTER_H__
#define __COLLADAMAX_MATERIAL_EXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryMaterials.h"

#include "COLLADAMaxDocumentExporter.h"
#include "COLLADAMaxEffectExporter.h"
#include "COLLADAMaxTypes.h"

namespace COLLADAMax
{

    class ExportSceneGraph;

    class ExportNode;

    /** This class writes the @a \<library_materials\>. It uses informations created my an effect exporter*/

    class MaterialExporter : public COLLADA::LibraryMaterials
    {

    private:
        /** maps already exported wire frame colors to the corresponding COLLADA effect id*/
        const WireFrameColorEffectList * mWireFrameColorEffectList;

        /** The document exporter*/
        DocumentExporter * mDocumentExporter;

        /** List of the the ids used by all of the effects*/
        ExportedEffectIdList mExportedEffectIdList;

    public:
        /**
        @param streamWriter The stream the output will be written to.
        @param documentExporter The document exporter this material exporter is used in.*/
        MaterialExporter ( COLLADA::StreamWriter * streamWriter, DocumentExporter * documentExporter );

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
        ExportedEffectIdList & getEffectIdList()
        {
            return mExportedEffectIdList;
        }

    private:
        MaterialExporter ( const MaterialExporter & materialExporter );
        MaterialExporter & operator= ( const MaterialExporter & materialExporter );

    };

}

#endif //__COLLADAMAX_MATERIAL_EXPORTER_H__
