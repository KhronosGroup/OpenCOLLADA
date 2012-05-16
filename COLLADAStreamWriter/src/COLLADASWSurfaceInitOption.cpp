/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWSurfaceInitOption.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    // ----------------------------------------
    void SurfaceInitOption::add ( StreamWriter* sw ) const
    {
        switch ( mType )
        {
        case INIT_AS_TARGET:
            addInitAsTarget ( sw );
            break;
        case INIT_CUBE:
            addInitCube ( sw );
            break;
        case INIT_VOLUME:
            addInitVolume ( sw );
            break;
        case INIT_PLANAR:
            addInitPlanar ( sw );
            break;
        case INIT_FROM:
            addInitFrom ( sw );
            break;
        case INIT_AS_NULL: 
        default:
            addInitAsNull ( sw );
            break;
        }
    }

    // ----------------------------------------
    void SurfaceInitOption::addInitAsTarget ( StreamWriter* sw ) const
    {
        sw->openElement( CSWC::CSW_ELEMENT_INIT_AS_TARGET );
        sw->closeElement ();
    }

    // ----------------------------------------
    void SurfaceInitOption::addInitCube ( StreamWriter* sw ) const
    {
        sw->openElement( CSWC::CSW_ELEMENT_INIT_CUBE );

        if ( !mAllRef.empty() )
        {
            sw->openElement( CSWC::CSW_ELEMENT_ALL );
            sw->appendAttribute( CSWC::CSW_ATTRIBUTE_REF, mAllRef );
            sw->closeElement ();
        }
        
        if ( !mPrimaryRef.empty() )
        {
            sw->openElement( CSWC::CSW_ELEMENT_PRIMARY );
            sw->appendAttribute( CSWC::CSW_ATTRIBUTE_REF, mPrimaryRef );
            for ( size_t i=0; i<mPrimaryOrders.size(); ++i )
            {
                sw->openElement( CSWC::CSW_ELEMENT_ORDER );
                sw->appendValues ( getFaceString ( mPrimaryOrders[i] ) );
                sw->closeElement ();
            }
            sw->closeElement ();
        }

        for ( size_t i=0; i<mFaceRefs.size(); ++i )
        {
            sw->openElement( CSWC::CSW_ELEMENT_FACE );
            sw->appendAttribute( CSWC::CSW_ATTRIBUTE_REF, mFaceRefs[i] );
            sw->closeElement ();
        }

        sw->closeElement ();
    }

    // ----------------------------------------
    void SurfaceInitOption::addInitVolume ( StreamWriter* sw ) const
    {
        sw->openElement( CSWC::CSW_ELEMENT_INIT_VOLUME );

        if ( !mAllRef.empty() )
        {
            sw->openElement( CSWC::CSW_ELEMENT_ALL );
            sw->appendAttribute( CSWC::CSW_ATTRIBUTE_REF, mAllRef );
            sw->closeElement ();
        }

        if ( !mPrimaryRef.empty() )
        {
            sw->openElement( CSWC::CSW_ELEMENT_PRIMARY );
            sw->appendAttribute( CSWC::CSW_ATTRIBUTE_REF, mPrimaryRef );
            sw->closeElement ();
        }

        sw->closeElement ();
    }

    // ----------------------------------------
    void SurfaceInitOption::addInitPlanar ( StreamWriter* sw ) const
    {
        sw->openElement( CSWC::CSW_ELEMENT_INIT_PLANAR );

        if ( !mAllRef.empty() )
        {
            sw->openElement( CSWC::CSW_ELEMENT_ALL );
            sw->appendAttribute( CSWC::CSW_ATTRIBUTE_REF, mAllRef );
            sw->closeElement ();
        }

        sw->closeElement ();
    }

    // ----------------------------------------
    void SurfaceInitOption::addInitFrom ( StreamWriter* sw ) const
    {
        sw->openElement( CSWC::CSW_ELEMENT_INIT_FROM );

        if ( mMipLevel!= 0 )
            sw->appendAttribute( CSWC::CSW_ATTRIBUTE_MIP, mMipLevel );
        if ( mSlice!= 0 )
            sw->appendAttribute( CSWC::CSW_ATTRIBUTE_SLICE, mSlice );
        if ( mFace != POSITIVE_X )
            sw->appendAttribute( CSWC::CSW_ATTRIBUTE_FACE, getFaceString ( mFace ) );

        if ( !mImageReference.empty() )
            sw->appendValues( mImageReference );

        sw->closeElement ();
    }

    // ----------------------------------------
    void SurfaceInitOption::addInitAsNull ( StreamWriter* sw ) const
    {
        sw->openElement( CSWC::CSW_ELEMENT_INIT_AS_NULL );
        sw->closeElement ();
    }

    // ----------------------------------------
    const String& SurfaceInitOption::getFaceString( const Face& face ) 
    {
        switch ( face )
        {
        case POSITIVE_X: return CSWC::CSW_FACE_POSITIVE_X;
        case NEGATIVE_X: return CSWC::CSW_FACE_NEGATIVE_X;
        case POSITIVE_Y: return CSWC::CSW_FACE_POSITIVE_Y;
        case NEGATIVE_Y: return CSWC::CSW_FACE_NEGATIVE_Y; 
        case POSITIVE_Z: return CSWC::CSW_FACE_POSITIVE_Z;
        case NEGATIVE_Z: return CSWC::CSW_FACE_NEGATIVE_Z;
        default:
            return CSWC::CSW_FACE_POSITIVE_X;
        }
    }
    
}
