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
#include "COLLADASWLibraryNodes.h"
#include "COLLADAMayaDocumentExporter.h"

namespace COLLADAMaya
{

    /** This class writes the <library_nodes>. */
	class LODExporter : public COLLADASW::LibraryNodes
    {

    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

    public:

        /**
        * @param streamWriter The stream the output will be written to
        * @param documentExporter The document exporter this material exporter is used in
        */
		LODExporter(COLLADASW::StreamWriter* streamWriter, DocumentExporter* documentExporter);
        virtual ~LODExporter() {};

        /** Exports the nodes in <library_nodes> and add extra techniques with <proxy> to instance_node. */
		void exportLODs(VisualSceneExporter* mVisualSceneExporter);

		void exportLOD(VisualSceneExporter* mVisualSceneExporter, SceneElement* sceneElement);
    };

}

#endif //__COLLADA_MAYA_LOD_EXPORTER_H__
