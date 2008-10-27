/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_VISUAL_SCENE_IMPORTER_H__
#define __COLLADA_MAYA_VISUAL_SCENE_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"

namespace COLLADAMaya
{

    /** Declares the importer implementation to import the visual scene nodes. */
    class VisualSceneImporter : public BaseImporter
    {

    private:

//         DaeDoc* doc;
//         DaeEntity* element;
//         FCDSceneNode* colladaNode;

        MObject transform;
        MTransformationMatrix transformation;
//        DaeTransformPresence presence;

        // Import-specific: used when attempting to bucket the COLLADA transforms
        int rotationOrder[9];
        int rotationOrderCount;
        bool noRotationOrder;
        bool isJoint;

        enum
        {
            TRANSLATION = 0, 
            ROTATE_PIVOT_TRANSLATION, 
            ROTATE_PIVOT,
            JOINT_ORIENT_1, 
            JOINT_ORIENT_2, 
            JOINT_ORIENT_3, 
            ROTATE_1, 
            ROTATE_2, 
            ROTATE_3, 
            ROTATE_A,
            ROTATE_AXIS_1, 
            ROTATE_AXIS_2, 
            ROTATE_AXIS_3, 
            ROTATE_PIVOT_R, 
            SCALE_PIVOT_TRANSLATION, 
            SCALE_PIVOT, 
            SKEW_XY,
            SKEW_XZ, 
            SKEW_YZ, 
            SCALE, 
            SCALE_PIVOT_R,
            BUCKET_COUNT
        };

        //const FCDTransform* buckets[BUCKET_COUNT];
        int bucketDepth;

    public:

        /** Constructor. */
        VisualSceneImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~VisualSceneImporter () {}

        /** Imports all visual scenes of the current dae element. */
        void importVisualScenes ();

        /** Imports the given dom node into maya. */
        bool importVisualSceneNode ( domNode& node, int level );

        /** Imports the current transformations. */
        bool importTransforms ( MObject& transformObject, domNode& node );

    private:

        /** Imports the current visual scene dae element. */
        void importVisualScene ( domVisual_scene& visualScene );

        bool bucketTransforms ( MObject& transformObject );

    };
}

#endif // __COLLADA_MAYA_VISUAL_SCENE_IMPORTER_H__