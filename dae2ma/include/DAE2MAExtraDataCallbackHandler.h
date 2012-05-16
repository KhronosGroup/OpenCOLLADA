/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_EXTRADATACALLBACKHANDLER_H__
#define __DAE2MA_EXTRADATACALLBACKHANDLER_H__

#include "DAE2MAPrerequisites.h"

#include "COLLADASaxFWLIExtraDataCallbackHandler.h"


namespace DAE2MA
{

    class ExtraInfo
    { 
    private:

        /** The hash value of the currently parsed extra data element. */
        StringHash mElementHash; 

        /** The uniqueId of the currently parsed extra data element. */
        COLLADAFW::UniqueId mUniqueId;

        /** The text value of the current original maya id. */
        String mOriginalMayaId;

    public:

        /** Constructor. */
        ExtraInfo () {}

        /** Destructor. */
        virtual ~ExtraInfo () {}

        /** The hash value of the currently parsed extra data element. */
        const StringHash& getElementHash () const { return mElementHash; }
        void setElementHash ( const StringHash& val ) { mElementHash = val; }

        /** The uniqueId of the currently parsed extra data element. */
        const COLLADAFW::UniqueId& getUniqueId () const { return mUniqueId; }
        void setUniqueId ( const COLLADAFW::UniqueId& val ) { mUniqueId = val; }

        /** The text value of the current original maya id. */
        const String& getOriginalMayaId () const { return mOriginalMayaId; }
        void setOriginalMayaId ( const String& val ) { mOriginalMayaId = val; }
        void setOriginalMayaId ( const GeneratedSaxParser::ParserChar* text, size_t textLength ) 
        { 
            mOriginalMayaId.assign ( text, textLength ); 
        }

    };

    /** Implementation of an extra data callback handler with the callback handler interface. */
	class ExtraDataCallbackHandler : public COLLADASaxFWL::IExtraDataCallbackHandler
    {
    private:

        typedef std::map<COLLADAFW::UniqueId, std::vector<ExtraInfo> > ExtraInfosMap;

	private:
	
        /** True, if the current text field is the original id field. */
        bool mIsOriginalIdField;

        ExtraInfo mCurrentExtraInfo;

        ExtraInfosMap mExtraInfos;

	public:

        /** Constructor. */
		ExtraDataCallbackHandler();

        /** Destructor. */
		virtual ~ExtraDataCallbackHandler();

        /** Returns the extra info with the searched id and hash string value. */
        const ExtraInfo* findExtraInfo ( 
            const COLLADAFW::UniqueId& uniqueId, 
            const StringHash& hashElement ) const;

        /** Method to ask, if the current callback handler want to read the data of the given extra element. */
        virtual bool parseElement ( 
            const GeneratedSaxParser::ParserChar* profileName, 
            const StringHash& elementHash, 
            const COLLADAFW::UniqueId& uniqueId );

        /** The methods to get the extra data tags to the registered callback handlers. */
        virtual bool elementBegin( const GeneratedSaxParser::ParserChar* elementName, const GeneratedSaxParser::xmlChar** attributes);
        virtual bool elementEnd(const GeneratedSaxParser::ParserChar* elementName );
        virtual bool textData(const GeneratedSaxParser::ParserChar* text, size_t textLength);

	private:

        /** Disable default copy ctor. */
		ExtraDataCallbackHandler( const ExtraDataCallbackHandler& pre );

        /** Disable default assignment operator. */
		const ExtraDataCallbackHandler& operator= ( const ExtraDataCallbackHandler& pre );

	};

} // namespace DAE2MA

#endif // __DAE2MA_EXTRADATACALLBACKHANDLER_H__
