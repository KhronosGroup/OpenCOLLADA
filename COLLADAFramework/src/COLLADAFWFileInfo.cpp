/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWFileInfo.h"

#include "COLLADABUUtils.h"
#include "Math/COLLADABUMathUtils.h"


namespace COLLADAFW
{

    const String FileInfo::X_UP_STRING = "X_UP";
    const String FileInfo::Y_UP_STRING = "Y_UP";
    const String FileInfo::Z_UP_STRING = "Z_UP";

    const double FileInfo::Unit::LINEAR_UNIT_KILOMETER = 1000;
    const double FileInfo::Unit::LINEAR_UNIT_METER = 1;
    const double FileInfo::Unit::LINEAR_UNIT_DECIMETER = 0.1;
    const double FileInfo::Unit::LINEAR_UNIT_CENTIMETER = 0.01;
    const double FileInfo::Unit::LINEAR_UNIT_MILLIMETER = 0.001;
    const double FileInfo::Unit::LINEAR_UNIT_FOOT = 0.3048;
    const double FileInfo::Unit::LINEAR_UNIT_INCH = 0.0254; 
    const double FileInfo::Unit::LINEAR_UNIT_YARD = 0.9144;

    const String FileInfo::Unit::LINEAR_UNIT_KILOMETER_NAME = "kilometer";
    const String FileInfo::Unit::LINEAR_UNIT_METER_NAME = "meter";
    const String FileInfo::Unit::LINEAR_UNIT_DECIMETER_NAME = "decimeter";
    const String FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME = "centimeter";
    const String FileInfo::Unit::LINEAR_UNIT_MILLIMETER_NAME = "millimeter";
    const String FileInfo::Unit::LINEAR_UNIT_FOOT_NAME = "foot";
    const String FileInfo::Unit::LINEAR_UNIT_INCH_NAME = "inch"; 
    const String FileInfo::Unit::LINEAR_UNIT_YARD_NAME = "yard";

    const String FileInfo::Unit::ANGULAR_UNIT_DEGREES_NAME = "degree";
    const String FileInfo::Unit::ANGULAR_UNIT_RADIANS_NAME = "radian";

    const String FileInfo::Unit::TIME_UNIT_FILM_NAME = "film";


    //------------------------------
    FileInfo::FileInfo() 
        : mUpAxisType ( Y_UP )
        , mValuePairArray ( )
		, mAbsoluteFileUri()
	{
    }
	
    //------------------------------
	FileInfo::~FileInfo()
	{
	}

    //------------------------------
    void FileInfo::setUpAxisType ( const String& upAxis )
    {
        if ( COLLADABU::Utils::equalsIgnoreCase ( upAxis, X_UP_STRING ))
            mUpAxisType = X_UP;
        else if  ( COLLADABU::Utils::equalsIgnoreCase ( upAxis, Y_UP_STRING ))
            mUpAxisType = Y_UP;
        else if  ( COLLADABU::Utils::equalsIgnoreCase ( upAxis, Z_UP_STRING ))
            mUpAxisType = Z_UP;
        else
            mUpAxisType = NONE;
    }

    //------------------------------
    void FileInfo::appendValuePair ( ValuePair* valuePair )
    {
        mValuePairArray.append ( valuePair );
    }

    //------------------------------
    void FileInfo::appendValuePair ( const String& value1, const String& value2 )
    {
        mValuePairArray.append ( new ValuePair ( value1, value2 ) );
    }

    //------------------------------
    void FileInfo::Unit::setAngularUnitName ( const String& val )
    {
        mAngularUnitName = val; 

        initializeAngularUnitUnitByName ( mAngularUnitName );
    }

    //------------------------------
    void FileInfo::Unit::setLinearUnitName ( const String& val )
    {
        mLinearUnitName = val;
    }

    //------------------------------
    void FileInfo::Unit::setTimeUnitName ( const String& val )
    {
        mTimeUnitName = val; 

        initializeTimeUnitUnitByName ( mTimeUnitName );
    }

    //------------------------------
    void FileInfo::Unit::initializeLinearUnitUnit ( const double linearUnitMeter )
    {
        if ( COLLADABU::Math::Utils::equals ( linearUnitMeter, LINEAR_UNIT_KILOMETER ) )
            mLinearUnitUnit = KILOMETER;
        else if ( COLLADABU::Math::Utils::equals ( linearUnitMeter, LINEAR_UNIT_METER ) )
            mLinearUnitUnit = METER;
        else if ( COLLADABU::Math::Utils::equals ( linearUnitMeter, LINEAR_UNIT_DECIMETER ) )
            mLinearUnitUnit = DECIMETER;
        else if ( COLLADABU::Math::Utils::equals ( linearUnitMeter, LINEAR_UNIT_CENTIMETER ) )
            mLinearUnitUnit = CENTIMETER;
        else if ( COLLADABU::Math::Utils::equals ( linearUnitMeter, LINEAR_UNIT_MILLIMETER ) )
            mLinearUnitUnit = MILLIMETER;
        else if ( COLLADABU::Math::Utils::equals ( linearUnitMeter, LINEAR_UNIT_FOOT ) )
            mLinearUnitUnit = FOOT;
        else if ( COLLADABU::Math::Utils::equals ( linearUnitMeter, LINEAR_UNIT_INCH ) )
            mLinearUnitUnit = INCH;
        else if ( COLLADABU::Math::Utils::equals ( linearUnitMeter, LINEAR_UNIT_YARD ) )
            mLinearUnitUnit = YARD;
        else mLinearUnitUnit = UNKNOWN_LINEAR_UNIT;
    }

    //------------------------------
    void FileInfo::Unit::initializeAngularUnitUnitByName ( const String& angularUnitName )
    {
        if ( COLLADABU::Utils::equalsIgnoreCase ( angularUnitName, ANGULAR_UNIT_DEGREES_NAME ) )
            mAngularUnitUnit = DEGREES;
        else if ( COLLADABU::Utils::equalsIgnoreCase ( angularUnitName, ANGULAR_UNIT_RADIANS_NAME ) )
            mAngularUnitUnit = RADIANS;
        else mAngularUnitUnit = UNKNOWN_ANGULAR_UNIT;
    }

    //------------------------------
    void FileInfo::Unit::initializeTimeUnitUnitByName ( const String& timeUnitName )
    {
        if ( COLLADABU::Utils::equalsIgnoreCase ( timeUnitName, TIME_UNIT_FILM_NAME ) )
            mTimeUnitUnit = FILM;
        else mTimeUnitUnit = UNKNOWN_TIME_UNIT;
    }

    //------------------------------
    void FileInfo::Unit::setLinearUnitMeter ( const double val )
    {
        mLinearUnitMeter = val;

        initializeLinearUnitUnit ( val );
    }

} // namespace COLLADAFW
