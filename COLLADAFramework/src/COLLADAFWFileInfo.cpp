/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWFileInfo.h"

#include "COLLADABUUtils.h"


namespace COLLADAFW
{

    const String FileInfo::X_UP_STRING = "X_UP";
    const String FileInfo::Y_UP_STRING = "Y_UP";
    const String FileInfo::Z_UP_STRING = "Z_UP";

    const double FileInfo::Unit::LINEAR_UNIT_KILOMETER = 1000;
    const double FileInfo::Unit::LINEAR_UNIT_METER = 1;
    const double FileInfo::Unit::LINEAR_UNIT_DECIMETER = 0.01;
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
        , mValuePairArray ( ValuePairArray::OWNER )
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
    void FileInfo::Unit::setLinearUnit ( const String& val )
    {
        mLinearUnitName = val;

        initializeLinearUnitUnitByName ( mLinearUnitName );
    }

    //------------------------------
    void FileInfo::Unit::setTimeUnitName ( const String& val )
    {
        mTimeUnitName = val; 

        initializeTimeUnitUnitByName ( mTimeUnitName );
    }

    //------------------------------
    void FileInfo::Unit::initializeLinearUnitUnitByName ( const String& linearUnitName )
    {
        if ( COLLADABU::Utils::equalsIgnoreCase ( linearUnitName, LINEAR_UNIT_KILOMETER_NAME ) )
            mLinearUnitUnit = KILOMETER;
        else if ( COLLADABU::Utils::equalsIgnoreCase ( linearUnitName, LINEAR_UNIT_METER_NAME ) )
            mLinearUnitUnit = METER;
        else if ( COLLADABU::Utils::equalsIgnoreCase ( linearUnitName, LINEAR_UNIT_METER_NAME ) )
            mLinearUnitUnit = METER;
        else if ( COLLADABU::Utils::equalsIgnoreCase ( linearUnitName, LINEAR_UNIT_DECIMETER_NAME ) )
            mLinearUnitUnit = DECIMETER;
        else if ( COLLADABU::Utils::equalsIgnoreCase ( linearUnitName, LINEAR_UNIT_CENTIMETER_NAME ) )
            mLinearUnitUnit = CENTIMETER;
        else if ( COLLADABU::Utils::equalsIgnoreCase ( linearUnitName, LINEAR_UNIT_MILLIMETER_NAME ) )
            mLinearUnitUnit = MILLIMETER;
        else if ( COLLADABU::Utils::equalsIgnoreCase ( linearUnitName, LINEAR_UNIT_FOOT_NAME ) )
            mLinearUnitUnit = FOOT;
        else if ( COLLADABU::Utils::equalsIgnoreCase ( linearUnitName, LINEAR_UNIT_INCH_NAME ) )
            mLinearUnitUnit = INCH;
        else if ( COLLADABU::Utils::equalsIgnoreCase ( linearUnitName, LINEAR_UNIT_METER_NAME ) )
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

} // namespace COLLADAFW
