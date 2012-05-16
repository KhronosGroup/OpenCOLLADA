/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryControllers.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    const String LibraryControllers::ARRAY_ID_SUFFIX                    = "-array";
    const String LibraryControllers::BIND_POSES_SOURCE_ID_SUFFIX        = "-bind_poses";
    const String LibraryControllers::JOINTS_SOURCE_ID_SUFFIX            = "-joints";
    const String LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX         = "-morph";
    const String LibraryControllers::MORPH_WEIGHTS_SOURCE_ID_SUFFIX     = "-morph_weights";
    const String LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX          = "-skin";
    const String LibraryControllers::TARGETS_SOURCE_ID_SUFFIX           = "-targets";
    const String LibraryControllers::WEIGHTS_SOURCE_ID_SUFFIX           = "-weights";
    
    const String LibraryControllers::ATTRIBUTE_METHOD_NORMALIZED        = "NORMALIZED";
    const String LibraryControllers::ATTRIBUTE_METHOD_RELATIVE          = "RELATIVE";
    

    //---------------------------------------------------------------
    LibraryControllers::LibraryControllers ( COLLADASW::StreamWriter *streamWriter )
            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_CONTROLLERS )
    {}

    //---------------------------------------------------------------
    void LibraryControllers::openSkin ( 
        const String &controllerId, const String &controllerName, const URI &skinSource )
    {
        openController ( controllerId, controllerName );

        mSkinCloser = mSW->openElement ( CSWC::CSW_ELEMENT_SKIN );

        mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_SOURCE, skinSource );
    }

    //---------------------------------------------------------------
    void LibraryControllers::closeSkin()
    {
        mSkinCloser.close();
    }

    //---------------------------------------------------------------
    void LibraryControllers::openMorph ( 
        const String &controllerId, 
        const String &controllerName, 
        const URI &morphSource, 
        const String &morphMethod )
    {
        openController ( controllerId, controllerName );

        mMorphCloser = mSW->openElement ( CSWC::CSW_ELEMENT_MORPH );

        mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_SOURCE, morphSource );

        // Which blending technique to use. Valid values are NORMALIZED and
        // RELATIVE. The default is NORMALIZED.
        mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_METHOD, morphMethod );
    }

    //---------------------------------------------------------------
    void LibraryControllers::closeMorph()
    {
        mMorphCloser.close();
    }

    //---------------------------------------------------------------
    void LibraryControllers::openController ( const String &controllerId, const String &controllerName )
    {
        openLibrary();

        mControllerCloser = mSW->openElement ( CSWC::CSW_ELEMENT_CONTROLLER );

        if ( !controllerId.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, controllerId );

        if ( !controllerName.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, controllerName );
    }

    //---------------------------------------------------------------
    void LibraryControllers::closeController()
    {
        mControllerCloser.close();
    }

    //---------------------------------------------------------------
    void LibraryControllers::addBindShapeTransform ( const double matrix[][4] ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_BIND_SHAPE_MATRIX );

        mSW->appendValues ( matrix );

        mSW->closeElement();
    }


} //namespace COLLADASW
