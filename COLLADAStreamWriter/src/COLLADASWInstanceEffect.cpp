/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWInstanceEffect.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    // -----------------------------------
    void TechniqueHint::add( StreamWriter* sw )
    {
        sw->openElement( CSWC::CSW_ELEMENT_TECHNIQUE_HINT );

        if ( !mPlatform.empty() )
            sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_PLATFORM, mPlatform );

        sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_REF, mRefNC );

        if ( !mProfileNC.empty() )
            sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_PROFILE, mProfileNC );

        sw->closeElement ();
    }

    // -----------------------------------
    InstanceEffect::InstanceEffect( 
        StreamWriter* streamWriter, 
        const URI& targetURI, 
        const String& sid /*= "" */, 
        const String& name /*= "" */ ) 
    : ElementWriter ( streamWriter )
    , mTargetURI ( targetURI ) 
    , mSid ( sid )
    , mName ( name )
    {}

    // -----------------------------------
    void InstanceEffect::open (  )
    {
        mTagCloser = mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_EFFECT );

        if ( !mSid.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, mSid );

        if ( !mName.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, mName );

        mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, mTargetURI );
    }

    // -----------------------------------
    void InstanceEffect::addTechniqueHint( const String &refe, const String &platform /*= "" */ )
    {
        TechniqueHint techniqueHint ( refe, platform );
        techniqueHint.add ( mSW );
    }

    // -----------------------------------
    void InstanceEffect::addTechniqueHint( const String &refe, const String &platform, const String &profile )
    {
        TechniqueHint techniqueHint ( refe, platform, profile );
        techniqueHint.add ( mSW );
    }

    // -----------------------------------
    void InstanceEffect::close()
    {
        mTagCloser.close ();
    }

    // -----------------------------------
    const String& InstanceEffect::getSid() const
    {
        return mSid;
    }

    // -----------------------------------
    const URI& InstanceEffect::getTargetURI() const
    {
        return mTargetURI;
    }

    // -----------------------------------
    

} //namespace COLLADASW
