/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLExtraDataLoader.h"
#include "COLLADASaxFWLExtraDataElementHandler.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLIExtraDataCallbackHandler.h"


namespace COLLADASaxFWL
{

    //------------------------------
	ExtraDataLoader::ExtraDataLoader() 
	{
	}
	
    //------------------------------
	ExtraDataLoader::~ExtraDataLoader()
	{
	}

    //------------------------------
    bool ExtraDataLoader::base__begin__technique ( 
        const technique__AttributeData& attributeData, 
        const COLLADAFW::UniqueId& uniqueId )
    {
        // Get the extra data element handler.
        ExtraDataElementHandler& extraDataElementHandler = getFileLoader ()->getExtraDataElementHandler ();

        // Ask all handlers, if they want to have the data of the current extra tag.
        // (profile name, element name ("optics"), id (cameraId)) 
        const ExtraDataCallbackHandlerList& extraDataCallbackHandlerList = extraDataElementHandler.getExtraDataCallbackHandlerList ();
        size_t numHandlers = extraDataCallbackHandlerList.size ();
        for ( size_t i=0; i<numHandlers; ++i )
        {
            IExtraDataCallbackHandler* extraDataCallbackHandler = extraDataCallbackHandlerList[i];

            // Get the hash value of the current element.
            size_t level = 1;
            StringHash elementHash = getFileLoader ()->getElementHash ( level );

            // Get the profile name.
            const ParserChar* profileName = attributeData.profile;

            // Ask, if the current handler should parse the extra tags of the current element.
            bool parseElement = extraDataCallbackHandler->parseElement ( profileName, elementHash, uniqueId );

            // Store the flag in the list.
            extraDataElementHandler.setExtraDataCallbackHandlerCalling ( i, parseElement );
        }
        return true;
    }

} // namespace COLLADASaxFWL
