/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWFormatHint.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    // ----------------------------------------
    FormatHint::FormatHint( ) 
        : ElementWriter ( NULL )
        , BaseExtraTechnique () 
        , mIsInitialized ( false )
        , mPrecision ( UNKNOWN_PRECISION )
    {

    }

    // ----------------------------------------
    FormatHint::FormatHint( StreamWriter* streamWriter, Channels channels, Range range ) 
        : ElementWriter ( streamWriter )
        , BaseExtraTechnique () 
        , mIsInitialized ( true )
        , mChannels ( channels )
        , mRange ( range )
        , mPrecision ( UNKNOWN_PRECISION )
    {

    }

    // ----------------------------------------
    void FormatHint::addOption( Option option )
    {
        mOptions.push_back ( option );
    }

    // ----------------------------------------
    void FormatHint::setPrecision( Precision precision )
    {
        mPrecision = precision;
    }

    // ----------------------------------------
    const String& FormatHint::getChannelsString( Channels channel )
    {
        switch ( channel )
        {
        case RGB: return CSWC::CSW_CHANNEL_RGB; break;
        case RGBA: return CSWC::CSW_CHANNEL_RGBA; break;
        case L: return CSWC::CSW_CHANNEL_L; break;
        case LA: return CSWC::CSW_CHANNEL_LA; break;
        case D:  return CSWC::CSW_CHANNEL_D; break;
        case XYZ:  return CSWC::CSW_CHANNEL_XYZ; break;
        case XYZW: return CSWC::CSW_CHANNEL_XYZW; break;
        default:
            fprintf ( stderr, "Unknown channel! Cannot proceed!" );
            return CSWC::EMPTY_STRING;
        }
    }

    // ----------------------------------------
    const String& FormatHint::getRangeString( Range range )
    {
        switch ( range )
        {
        case SNORM: return CSWC::CSW_RANGE_SNORM; break;
        case UNORM: return CSWC::CSW_RANGE_UNORM; break;
        case SINT: return CSWC::CSW_RANGE_SINT; break;
        case UINT: return CSWC::CSW_RANGE_UINT; break;
        case FLOAT:  return CSWC::CSW_RANGE_FLOAT; break;
        default:
            fprintf ( stderr, "Unknown range! Cannot proceed!" );
            return CSWC::EMPTY_STRING;
        }
    }

    // ----------------------------------------
    const String& FormatHint::getPrecisionString( Precision precision )
    {
        switch ( precision )
        {
        case LOW: return CSWC::CSW_PRECISION_LOW; break;
        case MID: return CSWC::CSW_PRECISION_MID; break;
        case HIGH: return CSWC::CSW_PRECISION_HIGH; break;
        default:
            fprintf ( stderr, "Unknown precision! Cannot proceed!" );
            return CSWC::EMPTY_STRING;
        }
    }

    // ----------------------------------------
    const String& FormatHint::getOptionString( Option option )
    {
        switch ( option )
        {
        case SRGB_GAMMA: return CSWC::CSW_OPTION_SRGB_GAMMA; break;
        case NORMALIZED3: return CSWC::CSW_OPTION_NORMALIZED3; break;
        case NORMALIZED4: return CSWC::CSW_OPTION_NORMALIZED4; break;
        case COMPRESSABLE: return CSWC::CSW_OPTION_COMPRESSABLE; break;
        default:
            fprintf ( stderr, "Unknown option! Cannot proceed!" );
            return CSWC::EMPTY_STRING;
        }
    }

    // ----------------------------------------
    void FormatHint::add() const
    {
        if ( mIsInitialized )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_FORMAT_HINT );

            mSW->openElement ( CSWC::CSW_ELEMENT_CHANNELS );
            mSW->appendValues ( getChannelsString ( mChannels ) );
            mSW->closeElement();

            mSW->openElement ( CSWC::CSW_ELEMENT_RANGE );
            mSW->appendValues ( getRangeString ( mRange ) );
            mSW->closeElement();

            if ( mPrecision != UNKNOWN_PRECISION )
            {
                mSW->openElement ( CSWC::CSW_ELEMENT_PRECISION );
                mSW->appendValues ( getPrecisionString ( mPrecision ) );
                mSW->closeElement();
            }

            for ( size_t i=0; i<mOptions.size(); ++i )
            {
                mSW->openElement ( CSWC::CSW_ELEMENT_OPTION );
                mSW->appendValues ( getOptionString ( mOptions[i] ) );
                mSW->closeElement();
            }

            mSW->closeElement ();
        }
    }

}
