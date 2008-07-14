/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryControllers.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    const String LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX = "-skin";
    const String LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX = "-morph";
    const String LibraryControllers::ARRAY_ID_SUFFIX = "-array";
    const String LibraryControllers::JOINTS_SOURCE_ID_SUFFIX = "-joints";
    const String LibraryControllers::BIND_POSES_SOURCE_ID_SUFFIX = "-bind_poses";
    const String LibraryControllers::WEIGHTS_SOURCE_ID_SUFFIX = "-weights";
    

    //---------------------------------------------------------------
    LibraryControllers::LibraryControllers ( COLLADA::StreamWriter *streamWriter )
            : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_CONTROLLERS )
    {}

    //---------------------------------------------------------------
    void LibraryControllers::openSkin ( 
        const String &controllerId, const String &controllerName, const String &skinTarget )
    {
        openController ( controllerId, controllerName );

        mSkinCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_SKIN );

        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SOURCE, skinTarget );
    }

    //---------------------------------------------------------------
    void LibraryControllers::closeSkin()
    {
        mSkinCloser.close();
    }

    //---------------------------------------------------------------
    void LibraryControllers::openController ( const String &controllerId, const String &controllerName )
    {
        openLibrary();

        mControllerCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_CONTROLLER );

        if ( !controllerId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, controllerId );

        if ( !controllerName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, controllerName );
    }

    //---------------------------------------------------------------
    void LibraryControllers::closeController()
    {
        mControllerCloser.close();
    }

    //---------------------------------------------------------------
    void LibraryControllers::addBindShapeTransform ( const double matrix[][4] ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_BIND_SHAPE_MATRIX );

        mSW->appendValues ( matrix );

        mSW->closeElement();
    }


} //namespace COLLADA
