/*
    Copyright (c) 2015 Starbreeze

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_PHYSICS_SCENE_EXPORTER_H__
#define __COLLADA_MAYA_PHYSICS_SCENE_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADASWLibraryPhysicsScenes.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWInstanceRigidBody.h"

#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"

#include "COLLADABUIDList.h"

#include <maya/MDagPath.h>
#include <maya/MFnTransform.h>
#include <maya/MFnMesh.h>


class DocumentExporter;

namespace COLLADAMaya
{

    /**
     * Exports the transform data of the visual scene.
     * 
     * All transform components with units will be in maya's internal units 
     * (radians for rotations and centimeters for translations).
     * We have to translate them into the working units of the current scene!
     */
	class PhysicsSceneExporter : public COLLADASW::LibraryPhysicsScenes
    {

    private:

		/** The id of the current scene. */
		String mSceneId;

		/** Pointer to the document exporter. */
		DocumentExporter* mDocumentExporter;


    public:

        /**
         * Constructor
         * @param streamWriter Pointer to the collada stream writer.
         * @param documentExporter Pointer to the main document exporter.
         * @param sceneId Name of the current scene to export. Has an empty string as default value.
         */
        PhysicsSceneExporter ( COLLADASW::StreamWriter* streamWriter,
                              DocumentExporter* documentExporter,
                              const String& sceneId = EMPTY_STRING );
        /**
         * Destructor.
         */
        virtual ~PhysicsSceneExporter() {};

        /** 
         * Exports the visual scene with the transforms of all included elements 
         */
		bool exportPhysicsScenes();
    };

}

#endif //__COLLADA_MAYA_VISUAL_SCENE_EXPORTER_H__
