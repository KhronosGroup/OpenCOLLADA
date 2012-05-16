/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MAImportOptions.h"

namespace DAE2MA
{
    
    bool ImportOptions::mHasError = false;

    bool ImportOptions::mImportUpAxis = true;
    bool ImportOptions::mImportUnits = true;
    bool ImportOptions::mImportNormals = true;
    
    
    /** Parse the options String */
    void ImportOptions::set ( String& optionsString )
    {
        // Default option values
        mImportUpAxis = true;
        mImportUnits = true;
        mImportNormals = true;

        mHasError = false;

        // Parse option String
        if ( optionsString.length() > 0 )
        {
            std::vector<String> optionList;
            COLLADABU::Utils::split ( optionsString, String(";"), optionList );
            size_t optionCount = optionList.size();

            for ( size_t i = 0; i < optionCount; ++i )
            {
                String& currentOption = optionList[i];

                // Process option name and values.
                std::vector<String> decomposedOption;
                COLLADABU::Utils::split ( currentOption, String("="), decomposedOption );
                String& optionName = decomposedOption[0];

                // For boolean values, the value is assumed to be true if omitted.
                bool value = true;

                if ( decomposedOption.size() > 1 && decomposedOption[1] != "true" && decomposedOption[1] != "1" )
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