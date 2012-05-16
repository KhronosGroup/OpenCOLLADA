/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MAExtraDataCallbackHandler.h"

#include "generated14/COLLADASaxFWLColladaParserAutoGen14Attributes.h"


namespace DAE2MA
{

    //------------------------------
    ExtraDataCallbackHandler::ExtraDataCallbackHandler() 
        : mIsOriginalIdField (false)
	{
	}
	
    //------------------------------
	ExtraDataCallbackHandler::~ExtraDataCallbackHandler()
	{
	}

    //------------------------------
    const ExtraInfo* ExtraDataCallbackHandler::findExtraInfo ( 
        const COLLADAFW::UniqueId& uniqueId, 
        const StringHash& hashElement ) const
    {
        ExtraInfosMap::const_iterator it = mExtraInfos.find ( uniqueId );
        if ( it != mExtraInfos.end () )
        {
            const std::vector<ExtraInfo>& extraInfos = it->second;
            size_t numInfos = extraInfos.size ();
            for ( size_t i=0; i<numInfos; ++i )
            {
                if ( extraInfos[i].getElementHash () == hashElement )
                    return &extraInfos[i];
            }
        }
        return 0;
    }

    //------------------------------
    bool ExtraDataCallbackHandler::parseElement ( 
        const GeneratedSaxParser::ParserChar* profileName, 
        const StringHash& elementHash, 
        const COLLADAFW::UniqueId& uniqueId ) 
    {
        if ( COLLADABU::Utils::equals ( PROFILE_MAYA, profileName ) ) 
        {
            mCurrentExtraInfo.setElementHash ( elementHash );
            mCurrentExtraInfo.setUniqueId ( uniqueId );
            return true;
        }

        return false;
    }

    //------------------------------
    bool ExtraDataCallbackHandler::elementBegin ( const GeneratedSaxParser::ParserChar* elementName, const GeneratedSaxParser::xmlChar** attributes ) 
    {
        if ( COLLADABU::Utils::equals ( PARAMETER_MAYA_ID, String (elementName) ) )
        {
            mIsOriginalIdField = true;
        }

        return true;
    }

    //------------------------------
    bool ExtraDataCallbackHandler::elementEnd ( const GeneratedSaxParser::ParserChar* elementName ) 
    {
        if ( mIsOriginalIdField )
        {
            mIsOriginalIdField = false;
            mExtraInfos [mCurrentExtraInfo.getUniqueId ()].push_back ( mCurrentExtraInfo );
            mCurrentExtraInfo.setOriginalMayaId ( EMPTY_STRING );
        }

        return true;
    }

    //------------------------------
    bool ExtraDataCallbackHandler::textData ( const GeneratedSaxParser::ParserChar* text, size_t textLength ) 
    {
        if ( mIsOriginalIdField )
        {
            mCurrentExtraInfo.setOriginalMayaId ( text, textLength );
        }
        return true;
    }

} // namespace DAE2MA
