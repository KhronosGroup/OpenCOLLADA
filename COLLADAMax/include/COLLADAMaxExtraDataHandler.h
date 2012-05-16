/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_EXTRADATAHANDLER_H__
#define __COLLADAMAX_EXTRADATAHANDLER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"

#include "COLLADASaxFWLIExtraDataCallbackHandler.h"

namespace COLLADAMax
{

	class ExtraDataHandler : public COLLADASaxFWL::IExtraDataCallbackHandler, public ImporterBase
	{
	private:
		enum ExtraTagType
		{
			EXTRA_TAG_TYPE_UNKNOWN,
			EXTRA_TAG_TYPE_SKYLIGHT,
		};
	private:
		String mTextBuffer;
		ExtraTagType mExtraTagType;
		COLLADAFW::UniqueId mCurrentElementUniqueId;

		union 
		{
			SkyLightParameters skyLightParameters;
		} mExtraParameters;

	public:
		ExtraDataHandler(DocumentImporter* colladaImporter);
		~ExtraDataHandler();
		bool elementBegin( const COLLADASaxFWL::ParserChar* elementName, const GeneratedSaxParser::xmlChar** attributes);
		bool elementEnd(const COLLADASaxFWL::ParserChar* elementName );
		bool textData(const COLLADASaxFWL::ParserChar* text, size_t textLength);

		bool parseElement( const COLLADASaxFWL::ParserChar* profileName, const COLLADASaxFWL::StringHash& elementHash, const COLLADAFW::UniqueId& uniqueId );

	};

}


#endif //__COLLADAMAX_EXTRADATAHANDLER_H__

