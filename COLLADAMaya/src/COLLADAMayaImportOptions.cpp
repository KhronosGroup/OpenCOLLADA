/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaImportOptions.h"

namespace COLLADAMaya
{
    
    bool ImportOptions::mIsOpenCall = false;
    bool ImportOptions::mIsReferenceCall = false;
    bool ImportOptions::mHasError = false;

    bool ImportOptions::mImportUpAxis = true;
    bool ImportOptions::mImportUnits = true;
    bool ImportOptions::mImportNormals = true;
    
    
    /** Parse the options String */
    void ImportOptions::set ( const MString& optionsString, MPxFileTranslator::FileAccessMode mode )
    {
        // Default option values
        mImportUpAxis = true;
        mImportUnits = true;
        mImportNormals = true;

        mHasError = false;

        /**
        * MPxFileTranslator::kUnknownAccessMode unknown file access mode
        * MPxFileTranslator::kReferenceAccessMode reference data into current scene
        * MPxFileTranslator::kImportAccessMode import data into current scene
        * MPxFileTranslator::kOpenAccessMode import data into new scene
        * MPxFileTranslator::kSaveAccessMode save data
        * MPxFileTranslator::kExportAccessMode export data
        * MPxFileTranslator::kExportActiveAccessMode export active (selected) data 
         */
        switch ( mode )
        {

        case MPxFileTranslator::kOpenAccessMode:
            mIsOpenCall = true;
            mIsReferenceCall = false;
            break;
#if MAYA_API_VERSION >= 650

        case MPxFileTranslator::kReferenceAccessMode:
            mIsOpenCall = false;
            mIsReferenceCall = true;
            break;
#endif

        case MPxFileTranslator::kImportAccessMode:
            mIsOpenCall = false;
            mIsReferenceCall = false;
            break;

        default:
            mIsOpenCall = false;
            break;
        }

        // Parse option String
        if ( optionsString.length() > 0 )
        {
            MStringArray optionList;
            optionsString.split ( ';', optionList );
            uint optionCount = optionList.length();

            for ( uint i = 0; i < optionCount; ++i )
            {
                MString& currentOption = optionList[i];

                // Process option name and values.
                MStringArray decomposedOption;
                currentOption.split ( '=', decomposedOption );
                MString& optionName = decomposedOption[0];

                // For boolean values, the value is assumed to be true if omitted.
                bool value = true;

                if ( decomposedOption.length() > 1 && decomposedOption[1] != "true" && decomposedOption[1] != "1" )
                {
                    value = false;
                }

                // Process options.
                if ( optionName == "importUpAxis" ) mImportUpAxis = value;
                else if ( optionName == "importUnits" ) mImportUnits = value;
                else if ( optionName == "importNormals" ) mImportNormals = value;
            }
        }
    }

    bool ImportOptions::isOpenMode()
    {
        return mIsOpenCall;
    }

    bool ImportOptions::isReferenceMode()
    {
        return mIsReferenceCall;
    }

    bool ImportOptions::hasError()
    {
        return mHasError;
    }

    bool ImportOptions::importUpAxis()
    {
        return mImportUpAxis;
    }

    bool ImportOptions::importUnits()
    {
        return mImportUnits;
    }

    bool ImportOptions::importNormals()
    {
        return mImportNormals;
    }

    void ImportOptions::setErrorFlag()
    {
        mHasError = true;
    }
}