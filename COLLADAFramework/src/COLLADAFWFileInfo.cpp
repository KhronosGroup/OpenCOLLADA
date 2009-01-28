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

    //------------------------------
    FileInfo::FileInfo() 
        : mUpAxisType ( Y_UP )
	{
        mUnit.mLinearUnit = "centimeter";
        mUnit.mAngularUnit = "degree";
        mUnit.mTimeUnit = "film";	
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
} // namespace COLLADAFW
