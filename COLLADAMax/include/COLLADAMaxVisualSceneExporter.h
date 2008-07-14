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


#ifndef __COLLADAMAX_VISUALSCENEEXPORTER_H__
#define __COLLADAMAX_VISUALSCENEEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADAMaxEffectExporter.h"
#include "COLLADALibraryVisualScenes.h"
#include "COLLADAMaxDocumentExporter.h"

namespace COLLADA
{

    class Node;
}

namespace COLLADAMax
{

    class ExportSceneGraph;

    class ExportNode;

    /** Class to export the visual scene.*/

    class VisualSceneExporter : public COLLADA::LibraryVisualScenes
    {

    public:
        /** Constructor
        @param streamWriter The stream to write the visual seen to.
        @param exportSceneGraph The scene graph of all the nodes that should be exported.
        @param sceneId The id of the scene.
        @param documentExporter
        */
        VisualSceneExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, const String & sceneId, DocumentExporter * documentExporter );
        virtual ~VisualSceneExporter()
        {}

        ;

        /** Exports the library visual scene.*/
        void doExport();

        static const String TRANSLATE_SID;
        static const String ROTATE_SID;
        static const String ROTATE_X_SID;
        static const String ROTATE_Y_SID;
        static const String ROTATE_Z_SID;
        static const String ROTATE_SCALE_AXIS_SID;
        static const String ROTATE_SCALE_AXIS_INVERSE_SID;
        static const String SCALE_SID;

        static const String TRANSLATION_PARAMETERS[ 3 ];
        static const String ROTATION_PARAMETER[ 1 ];
        static const String ROTATION_PARAMETERS[ 4 ];


    private:
        ExportSceneGraph * mExportSceneGraph;

        const EffectMap & mEffectMap;

        /** The id of the visual scene.*/
        const String & mVisualSceneId;

        DocumentExporter * mDocumentExporter;

        /** The praefix used for node ids.*/
        static const String NODE_ID_PRAEFIX;

        /** Exports all the nodes in @a node and all its child nodes.*/
        void doExport ( ExportNode* exportNode );

        /** Exports all the transformations of a node.*/
        void exportTransformations ( ExportNode * exportNode, const COLLADA::Node & colladaNode );


        /** Fills the two dimensional array @a copy with the values contained in @a original.*/
        static void Matrix3ToDouble4x4 ( double copy[][ 4 ], const Matrix3 & original );


    };

}

#endif //__COLLADAMAX_VISUALSCENEEXPORTER_H__
