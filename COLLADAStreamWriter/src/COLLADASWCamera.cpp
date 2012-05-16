/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWCamera.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    // ---------------------------------------------------
    Camera::Camera ( 
        StreamWriter* streamWriter, 
        BaseOptic* optics, 
        const String& cameraId, 
        const String& cameraName )
    : ElementWriter ( streamWriter )
    , BaseExtraTechnique ( )
    , mOptics ( optics )
    , mCameraId ( cameraId )
    , mCameraName ( cameraName )
    {}

    // ---------------------------------------------------
    void Camera::add () const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_CAMERA );

        if ( !getCameraId().empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, getCameraId() );
        
        if ( !getCameraName().empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, getCameraName() );

        // Write the optics element
        mOptics->add ();

        addExtraTechniques ( mSW );

        mSW->closeElement(); // COLLADASW_ELEMENT_CAMERA

    }


} //namespace COLLADASW
