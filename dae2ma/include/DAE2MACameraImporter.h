/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_CAMERA_IMPORTER_H__
#define __DAE2MA_CAMERA_IMPORTER_H__

#include "DAE2MAStableHeaders.h"
#include "DAE2MABaseImporter.h"

#include <MayaDMCamera.h>


namespace DAE2MA
{

    /** Declares xy */
    class CameraImporter : BaseImporter
    {
    private:

        /** The standard name for camera without name. */
        static const String CAMERA_NAME;

    private:

        /** 
        * The map holds the unique ids of the camera nodes to the maya specific nodes. 
        */
        UniqueIdMayaNodeMap mMayaCameraNodesMap;

    public:

        /** Constructor. */
        CameraImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~CameraImporter ();

        /**
         * Imports the data of the current camera.
         */
        void importCamera ( const COLLADAFW::Camera* camera );

    private:

        /**
        * Imports the data of the current camera.
        */
        void createCamera ( 
            const COLLADAFW::Camera* camera,  
            MayaNode* mayaTransformNode );

        void setPerspectiveCameraAttributes ( 
            const COLLADAFW::Camera* camera, 
            MayaNode* mayaCameraNode, 
            MayaDM::Camera& mayaCamera );

        void setOrthographicCameraAttributes ( 
            const COLLADAFW::Camera* camera, 
            MayaNode* mayaCameraNode, 
            MayaDM::Camera& mayaCamera );
        
        MayaNode* findMayaCameraNode ( const COLLADAFW::UniqueId& cameraId );


    };
}

#endif // __DAE2MA_CAMERA_IMPORTER_H__