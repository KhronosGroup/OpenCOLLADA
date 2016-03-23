/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_LOD_EXPORTER_H__
#define __COLLADA_MAYA_LOD_EXPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADASWStreamWriter.h"
//#include "COLLADASWLibraryLOD.h"
#include "COLLADASWLibraryNodes.h"
#include "COLLADAMayaDocumentExporter.h"

namespace COLLADAMaya
{

    /** This class writes the <library_lod>. */
    class LODExporter : public COLLADASW::LibraryNodes
    {
    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /**
        * The list of the unique collada ids.
        */
//        COLLADABU::IDList mLightIdList;

        /**
        * A collada id for every maya id.
        */
 //       StringToStringMap mMayaIdColladaIdMap;

    public:

        /**
        * @param streamWriter The stream the output will be written to
        * @param documentExporter The document exporter this material exporter is used in
        */
		LODExporter(COLLADASW::StreamWriter* streamWriter, DocumentExporter* documentExporter);
        virtual ~LODExporter() {};

        /** Exports the lights in the scene graph. */
        void exportLODs( );

        /** Exports the current scene element and all it's children. */
        void exportLODs ( SceneElement* sceneElement );

        /**
        * A collada id for every maya id.
        */
  //      const String findColladaLightId ( const String& mayaLightId );

    private:

        /** Exports the geometry data of the current object, if it is a valid mesh object to export. */
        bool exportLOD ( const MDagPath& dagPath );

   //     void exportExtraAttributes(const SceneElement* sceneElement, COLLADASW::Light* light);

    };

}

#endif //__COLLADA_MAYA_LOD_EXPORTER_H__
