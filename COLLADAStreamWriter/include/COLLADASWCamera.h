/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_CAMERA_H__
#define __COLLADASTREAMWRITER_CAMERA_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWConstants.h"
#include "COLLADASWCameraOptic.h"

namespace COLLADASW
{

    /** A class that hold all information about an @a \<camera\> element.*/
    class Camera : public ElementWriter, public BaseExtraTechnique
    {

    private:

        // LibraryCameras should be able to call the add() method.
        friend class LibraryCameras;

        /** Describes the field of view and viewing frustum using canonical parameters. */
        BaseOptic* mOptics;

        /** The id of the camera.*/
        String mCameraId;

        /** The name of the camera.*/
        String mCameraName;

    protected:

        /** Adds the camera information. */
        void add() const;

    public:

        /**
        * Constructor
        * @param cameraId The id of the camera.
        * @param cameraName The name of the camera.
        */
        Camera (
            StreamWriter* streamWriter,
            BaseOptic* optics,
            const String& cameraId = ElementWriter::EMPTY_STRING,
            const String& cameraName = ElementWriter::EMPTY_STRING );

        /** Destructor */
        virtual ~Camera()
        { }

        /** Returns a reference to the camera id */
        const String& getCameraId() const { return mCameraId; }

        /** Returns a reference to the camera name */
        const String& getCameraName() const { return mCameraName; }

        /** Describes the field of view and viewing frustum using canonical parameters. */
        const BaseOptic* getOptics() const { return mOptics; }

    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_CAMERA_H__
