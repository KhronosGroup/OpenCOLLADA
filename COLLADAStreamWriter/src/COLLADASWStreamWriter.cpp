/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"

#include "COLLADASWConstants.h"
#include "COLLADASWException.h"

#include "COLLADABUStringUtils.h"

#include "CommonCharacterBuffer.h"
#include "CommonFWriteBufferFlusher.h"

#include <string>
#include <fstream>

namespace COLLADASW
{

    //---------------------------------------------------------------
    TagCloser::TagCloser ( StreamWriter * streamWriter, ElementIndexType elementIndex )
            : mStreamWriter( streamWriter ),
			mElementIndex(elementIndex)
    {
		COLLADABU_ASSERT ( mStreamWriter != 0 );
    }

    //---------------------------------------------------------------
    TagCloser::TagCloser()
		: mStreamWriter( 0 ),
		mElementIndex(0)
    {}

    //---------------------------------------------------------------
    TagCloser::~TagCloser()
    {
    }

    //---------------------------------------------------------------
    TagCloser & TagCloser::operator= ( const TagCloser & other )
    {
		mStreamWriter = other.mStreamWriter;
		mElementIndex= other.mElementIndex;
        return *this;
    }


    //---------------------------------------------------------------
    void TagCloser::close()
    {
		mStreamWriter->closeElements( mElementIndex );
    }

    const String StreamWriter::mWhiteSpaceString ( WHITESPACESTRINGLENGTH,' ' );

	const int StreamWriter::FWRITEBUFFERSIZE = 1024*64;
	const int StreamWriter::CHARACTERBUFFERSIZE = 1024*64*64;


    //---------------------------------------------------------------
    StreamWriter::StreamWriter ( const NativeString & fileName, bool doublePrecision /*= false*/, COLLADAVersion cOLLADAVersion /*= COLLADA_1_4_1*/ )
            : mBufferFlusher( new Common::FWriteBufferFlusher(fileName.c_str(), FWRITEBUFFERSIZE))
			, mCharacterBuffer( new Common::CharacterBuffer(CHARACTERBUFFERSIZE, mBufferFlusher) )
			, mLevel ( 0 )
            , mIndent ( 2 )
            , mDoublePrecision (doublePrecision)
			, mCOLLADAVersion(cOLLADAVersion)
			, mNextElementIndex(0)
    {
		int error = mBufferFlusher->getError();
		if ( error != 0 )
		{
			throw StreamWriterException(StreamWriterException::ERROR_FILE_OPEN, "Could not open file \"" + fileName + "\" for writing. errno_t = " + Utils::toString(error) );
		}
    }

    //---------------------------------------------------------------
    StreamWriter::~StreamWriter()
    {
        endDocument();
		delete mCharacterBuffer;
		delete mBufferFlusher;
    }

    //---------------------------------------------------------------
    void StreamWriter::startDocument()
    {
        appendNCNameString ( CSWC::XML_START_ELEMENT );
        openElement ( CSWC::CSW_ELEMENT_COLLADA );
		if ( getCOLLADAVersion() == COLLADA_1_4_1 )
		{
			appendAttribute ( CSWC::CSW_ATTRIBUTE_XMLNS, CSWC::CSW_NAMESPACE_1_4_1 );
			appendAttribute ( CSWC::CSW_ATTRIBUTE_VERSION, CSWC::CSW_VERSION_1_4_1 );
		}
		else if ( getCOLLADAVersion() == COLLADA_1_5_0 )
		{
			appendAttribute ( CSWC::CSW_ATTRIBUTE_XMLNS, CSWC::CSW_NAMESPACE_1_5_0 );
			appendAttribute ( CSWC::CSW_ATTRIBUTE_VERSION, CSWC::CSW_VERSION_1_5_0 );
			appendAttribute ( CSWC::CSW_ATTRIBUTE_XSI_SCHEMALOCATION, CSWC::CSW_SCHEMALOCATION_1_5_0 );
			appendAttribute ( CSWC::CSW_ATTRIBUTE_XMLNS_XSI, CSWC::CSW_XMLNS_XSI_1_5_0 );
		}
		else
		{
			COLLADABU_ASSERT(false);
		}
    }

    //---------------------------------------------------------------
    void StreamWriter::endDocument()
    {
        while ( !mOpenTags.empty() )
            closeElement();
    }

    //---------------------------------------------------------------
    void StreamWriter::appendURIAttribute ( const String &name, const COLLADABU::URI &uri )
    {
        COLLADABU_ASSERT ( !mOpenTags.back().mHasContents );

		appendChar ( ' ' );
		appendNCNameString ( name );
		appendChar ( '=' );
		appendChar ( '\"' );
		appendString ( COLLADABU::StringUtils::translateToXML(uri.getURIString()) );
		appendChar ( '\"' );
    }

    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, const String &value )
    {
        COLLADABU_ASSERT ( !mOpenTags.back().mHasContents );

        if ( !value.empty() )
        {
            appendChar ( ' ' );
            appendNCNameString ( name );
            appendChar ( '=' );
            appendChar ( '\"' );
            appendString ( value );
            appendChar ( '\"' );
        }
    }

    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, const double value )
    {
        COLLADABU_ASSERT ( !mOpenTags.back().mHasContents );

        appendChar ( ' ' );
        appendNCNameString ( name );
        appendChar ( '=' );
        appendChar ( '\"' );
        appendNumber ( value );
        appendChar ( '\"' );
    }


    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, const unsigned long val )
    {
        COLLADABU_ASSERT ( !mOpenTags.back().mHasContents );

        appendChar ( ' ' );
        appendNCNameString ( name );
        appendChar ( '=' );
        appendChar ( '\"' );
        appendNumber ( val );
        appendChar ( '\"' );
    }

    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, const unsigned int val )
    {
        COLLADABU_ASSERT ( !mOpenTags.back().mHasContents );

        appendChar ( ' ' );
        appendNCNameString ( name );
        appendChar ( '=' );
        appendChar ( '\"' );
        appendNumber ( val );
        appendChar ( '\"' );
    }

    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, const int val )
    {
        COLLADABU_ASSERT ( !mOpenTags.back().mHasContents );

        appendChar ( ' ' );
        appendNCNameString ( name );
        appendChar ( '=' );
        appendChar ( '\"' );
        appendNumber ( val );
        appendChar ( '\"' );
    }

    //---------------------------------------------------------------
    void StreamWriter::appendText ( const String &text )
    {
        prepareToAddContents();
        appendString ( text );
        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendTextBlock ( const String &text )
    {
        if ( text.empty () ) return;

        prepareToAddContents();
        appendNewLine();
        addWhiteSpace ( mLevel * mIndent );
        appendString ( text );
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double number )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( number );

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double number1, const double number2 )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );

        mOpenTags.back().mHasText = true;
    }


    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double number1, const double number2, const double number3 )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );
        appendChar ( ' ' );
        appendNumber ( number3 );

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double number1, const double number2, const double number3, const double number4 )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );
        appendChar ( ' ' );
        appendNumber ( number3 );
        appendChar ( ' ' );
        appendNumber ( number4 );

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const float number )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( number );

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const float number1, const float number2 )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );

        mOpenTags.back().mHasText = true;
    }


    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const float number1, const float number2, const float number3 )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );
        appendChar ( ' ' );
        appendNumber ( number3 );

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( 
        const float number1, const float number2, const float number3, const float number4 )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );
        appendChar ( ' ' );
        appendNumber ( number3 );
        appendChar ( ' ' );
        appendNumber ( number4 );

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const float values[], const size_t length )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );

        for ( size_t i=0; i<length; ++i )
        {
            appendNumber ( values[i] );
            appendChar ( ' ' );
        }

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const int values[], const size_t length )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );

        for ( size_t i=0; i<length; ++i )
        {
            appendNumber ( values[i] );
            appendChar ( ' ' );
        }

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const float matrix[4][4] )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( matrix[0][0] );
        appendChar ( ' ' );
        appendNumber ( matrix[0][1] );
        appendChar ( ' ' );
        appendNumber ( matrix[0][2] );
        appendChar ( ' ' );
        appendNumber ( matrix[0][3] );
        appendChar ( ' ' );

        appendNumber ( matrix[1][0] );
        appendChar ( ' ' );
        appendNumber ( matrix[1][1] );
        appendChar ( ' ' );
        appendNumber ( matrix[1][2] );
        appendChar ( ' ' );
        appendNumber ( matrix[1][3] );
        appendChar ( ' ' );

        appendNumber ( matrix[2][0] );
        appendChar ( ' ' );
        appendNumber ( matrix[2][1] );
        appendChar ( ' ' );
        appendNumber ( matrix[2][2] );
        appendChar ( ' ' );
        appendNumber ( matrix[2][3] );
        appendChar ( ' ' );

        appendNumber ( matrix[3][0] );
        appendChar ( ' ' );
        appendNumber ( matrix[3][1] );
        appendChar ( ' ' );
        appendNumber ( matrix[3][2] );
        appendChar ( ' ' );
        appendNumber ( matrix[3][3] );

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double values[], const size_t length )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );

        for ( size_t i=0; i<length; ++i )
        {
            appendNumber ( values[i] );
            appendChar ( ' ' );
        }

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double matrix[4][4] )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( matrix[0][0] );
        appendChar ( ' ' );
        appendNumber ( matrix[0][1] );
        appendChar ( ' ' );
        appendNumber ( matrix[0][2] );
        appendChar ( ' ' );
        appendNumber ( matrix[0][3] );
        appendChar ( ' ' );

        appendNumber ( matrix[1][0] );
        appendChar ( ' ' );
        appendNumber ( matrix[1][1] );
        appendChar ( ' ' );
        appendNumber ( matrix[1][2] );
        appendChar ( ' ' );
        appendNumber ( matrix[1][3] );
        appendChar ( ' ' );

        appendNumber ( matrix[2][0] );
        appendChar ( ' ' );
        appendNumber ( matrix[2][1] );
        appendChar ( ' ' );
        appendNumber ( matrix[2][2] );
        appendChar ( ' ' );
        appendNumber ( matrix[2][3] );
        appendChar ( ' ' );

        appendNumber ( matrix[3][0] );
        appendChar ( ' ' );
        appendNumber ( matrix[3][1] );
        appendChar ( ' ' );
        appendNumber ( matrix[3][2] );
        appendChar ( ' ' );
        appendNumber ( matrix[3][3] );

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const std::vector<float> &values )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );

        std::vector<float>::const_iterator it = values.begin();
        for ( ; it!=values.end(); ++it )
        {
            appendNumber ( *it );
            appendChar ( ' ' );
        }

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const std::vector<double> &values )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );

        std::vector<double>::const_iterator it = values.begin();
        for ( ; it!=values.end(); ++it )
        {
            appendNumber ( *it );
            appendChar ( ' ' );
        }

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const std::vector<String> &values )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );

        std::vector<String>::const_iterator it = values.begin();
        for ( ; it!=values.end(); ++it )
        {
            appendString ( *it );
            appendChar ( ' ' );
        }

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const std::vector<unsigned long> &values )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );

        std::vector<unsigned long>::const_iterator it = values.begin();
        for ( ; it!=values.end(); ++it )
        {
            appendNumber ( *it );
            appendChar ( ' ' );
        }

        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( int number )
    {
        prepareToAddContents();
        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );
        appendNumber ( number );
        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( int number, int number2 )
    {
        prepareToAddContents();
        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );
        appendNumber ( number );
        appendChar ( ' ' );
        appendNumber ( number2 );
        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( unsigned int number )
    {
        prepareToAddContents();
        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );
        appendNumber ( number );
        mOpenTags.back().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( unsigned int number, unsigned int number2 )
    {
        prepareToAddContents();
        if ( mOpenTags.back().mHasText ) appendChar ( ' ' );
        appendNumber ( number );
        appendChar ( ' ' );
        appendNumber ( number2 );
        mOpenTags.back().mHasText = true;
    }

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( long number )
	{
		prepareToAddContents();
		if ( mOpenTags.back().mHasText ) appendChar ( ' ' );
		appendNumber ( number );
		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( long number1, long number2 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );

		mOpenTags.back().mHasText = true;
	}


	//---------------------------------------------------------------
	void StreamWriter::appendValues ( long number1, long number2, long number3 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );
		appendChar ( ' ' );
		appendNumber ( number3 );

		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( long number1, long number2, long number3, long number4 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );
		appendChar ( ' ' );
		appendNumber ( number3 );
		appendChar ( ' ' );
		appendNumber ( number4 );

		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( unsigned long number )
	{
		prepareToAddContents();
		if ( mOpenTags.back().mHasText ) appendChar ( ' ' );
		appendNumber ( number );
		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( unsigned long number1, unsigned long number2 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );

		mOpenTags.back().mHasText = true;
	}


	//---------------------------------------------------------------
	void StreamWriter::appendValues ( unsigned long number1, unsigned long number2, unsigned long number3 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );
		appendChar ( ' ' );
		appendNumber ( number3 );

		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( unsigned long number1, unsigned long number2, unsigned long number3, unsigned long number4 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );
		appendChar ( ' ' );
		appendNumber ( number3 );
		appendChar ( ' ' );
		appendNumber ( number4 );

		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( long long number )
	{
		prepareToAddContents();
		if ( mOpenTags.back().mHasText ) appendChar ( ' ' );
		appendNumber ( number );
		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( long long number1, long long number2 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );

		mOpenTags.back().mHasText = true;
	}


	//---------------------------------------------------------------
	void StreamWriter::appendValues ( long long number1, long long number2, long long number3 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );
		appendChar ( ' ' );
		appendNumber ( number3 );

		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( long long number1, long long number2, long long number3, long long number4 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );
		appendChar ( ' ' );
		appendNumber ( number3 );
		appendChar ( ' ' );
		appendNumber ( number4 );

		mOpenTags.back().mHasText = true;
	}


	//---------------------------------------------------------------
	void StreamWriter::appendValues ( unsigned long long number )
	{
		prepareToAddContents();
		if ( mOpenTags.back().mHasText ) appendChar ( ' ' );
		appendNumber ( number );
		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( unsigned long long number1, unsigned long long number2 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );

		mOpenTags.back().mHasText = true;
	}


	//---------------------------------------------------------------
	void StreamWriter::appendValues ( unsigned long long number1, unsigned long long number2, unsigned long long number3 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );
		appendChar ( ' ' );
		appendNumber ( number3 );

		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( unsigned long long number1, unsigned long long number2, unsigned long long number3, unsigned long long number4 )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendNumber ( number1 );
		appendChar ( ' ' );
		appendNumber ( number2 );
		appendChar ( ' ' );
		appendNumber ( number3 );
		appendChar ( ' ' );
		appendNumber ( number4 );

		mOpenTags.back().mHasText = true;
	}

    //---------------------------------------------------------------
    void StreamWriter::appendValues( const Color& val )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendNumber ( val.getRed() );
        appendChar ( ' ' );
        appendNumber ( val.getGreen() );
        appendChar ( ' ' );
        appendNumber ( val.getBlue() );
        appendChar ( ' ' );
        appendNumber ( val.getAlpha() );

        mOpenTags.back().mHasText = true;
    }


    //---------------------------------------------------------------
    void StreamWriter::appendValues (  bool value )
    {
        prepareToAddContents();

        if ( mOpenTags.back().mHasText )
            appendChar ( ' ' );

        appendBoolean ( value );

        mOpenTags.back().mHasText = true;
    }


	//---------------------------------------------------------------
	void StreamWriter::appendValues ( const String& text )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendString ( text );

		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( const char* text )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendString ( text );

		mOpenTags.back().mHasText = true;
	}

	//---------------------------------------------------------------
	void StreamWriter::appendValues ( const char* text, size_t length )
	{
		prepareToAddContents();

		if ( mOpenTags.back().mHasText )
			appendChar ( ' ' );

		appendString ( text, length );

		mOpenTags.back().mHasText = true;
	}

    //---------------------------------------------------------------
    TagCloser StreamWriter::openElement ( const String & name )
    {
        prepareToAddContents();
        appendNewLine();
        addWhiteSpace ( mLevel * mIndent );
        mLevel++;
        appendChar ( '<' );
        appendNCNameString ( name );
		ElementIndexType nextElementIndex = mNextElementIndex++;
        mOpenTags.push_back( OpenTag ( &name, nextElementIndex ) );

        return TagCloser ( this, nextElementIndex );
    }


    //---------------------------------------------------------------
    void StreamWriter::closeElement()
    {
        COLLADABU_ASSERT ( !mOpenTags.empty() );

        mLevel--;

        if ( mOpenTags.back().mHasContents )
        {
            if ( !mOpenTags.back().mHasText )
            {
                appendNewLine();
                addWhiteSpace ( mLevel * mIndent );
            }

            appendChar ( '<' );

            appendChar ( '/' );
            appendNCNameString ( *mOpenTags.back().mName );
            appendChar ( '>' );
        }

        else
        {
            appendChar ( '/' );
            appendChar ( '>' );
        }

        mOpenTags.pop_back();
    }

	//---------------------------------------------------------------
	void StreamWriter::closeElements( ElementIndexType elementIndex )
	{
		// we need to determine how many elements need to be close
		// we search from the end until we find the first element index  <= elementIndex and count the elements
		// If this is == elementIndex, we need close elmentsToClose elements
		// If it is < elementIndex, the element has been close before, nothing to do 
		ElementIndexType elmentsToClose = 0;
		OpenTagStack::reverse_iterator it = mOpenTags.rbegin();
		for ( ; it != mOpenTags.rend(); ++it)
		{
			elmentsToClose++;
			const ElementIndexType& currentTagIndex = it->mElementIndex;
			if ( currentTagIndex < elementIndex)
			{
				// the element is not in the stack, i.e. has already been closed
				return;
			}
			if ( currentTagIndex == elementIndex)
			{
				// we need to close elmentsToClose elements
				for ( ElementIndexType i = 0; i < elmentsToClose; ++i)
				{
					closeElement();
				}
				return;
			}
		}
		// if we reach this point, the searched element is not in the stack, i.e. already, nothing to do
	}

    //---------------------------------------------------------------
    void StreamWriter::appendTextElement ( const String& elementName, const String& text )
    {
        openElement ( elementName );
        appendText ( COLLADABU::StringUtils::translateToXML(text) );
        closeElement();
    }

    //---------------------------------------------------------------
    void StreamWriter::appendURIElement ( const String& elementName, const COLLADABU::URI& uri )
    {
        openElement ( elementName );
		appendText ( COLLADABU::StringUtils::translateToXML(uri.getURIString()) );
        closeElement();
    }

    //---------------------------------------------------------------
    void StreamWriter::prepareToAddContents()
    {
        if ( !mOpenTags.empty() && !mOpenTags.back().mHasContents )
        {
            appendChar ( '>' );
            mOpenTags.back().mHasContents = true;
        }
    }



    //---------------------------------------------------------------
    void StreamWriter::addWhiteSpace ( size_t number )
    {
        size_t numberOfWholeStrings = number / WHITESPACESTRINGLENGTH;

        size_t remainder = number % WHITESPACESTRINGLENGTH;

        for ( size_t i = 0; i < numberOfWholeStrings; ++i )
            appendNCNameString ( mWhiteSpaceString );

        appendNCNameString ( mWhiteSpaceString, remainder );
    }

	//---------------------------------------------------------------
	void StreamWriter::appendString( const char* text, size_t length )
	{
		mCharacterBuffer->copyToBuffer( text, length );
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNCNameString( const String & str )
	{
		appendNCNameString(str, str.length());
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNCNameString( const String & str, size_t n )
	{
		mCharacterBuffer->copyToBuffer( str.c_str(), n);
	}

	//---------------------------------------------------------------
	void StreamWriter::appendChar( char c )
	{
		mCharacterBuffer->copyToBuffer( c );
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNumber( double number )
	{
		if ( COLLADABU::Math::Utils::equals<double>(number, 0, std::numeric_limits<double>::epsilon()) )
		{
			appendChar('0');
		}
		else
		{
			mCharacterBuffer->copyToBufferAsChar( number, mDoublePrecision );
		}
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNumber( float number )
	{
		if ( COLLADABU::Math::Utils::equals<float>(number, 0, std::numeric_limits<float>::epsilon()) )
		{
			appendChar('0');
		}
		else
		{
			mCharacterBuffer->copyToBufferAsChar( number );
		}
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNumber( int number )
	{
		mCharacterBuffer->copyToBufferAsChar( number );
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNumber( unsigned int number )
	{
		mCharacterBuffer->copyToBufferAsChar( number );
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNumber( long number )
	{
		mCharacterBuffer->copyToBufferAsChar( number );
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNumber( unsigned long number )
	{
		mCharacterBuffer->copyToBufferAsChar( number );
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNumber( long long number )
	{
		mCharacterBuffer->copyToBufferAsChar( number );
	}

	//---------------------------------------------------------------
	void StreamWriter::appendNumber( unsigned long long number )
	{
		mCharacterBuffer->copyToBufferAsChar( number );
	}

	//---------------------------------------------------------------
	void StreamWriter::appendBoolean( bool value )
	{
		mCharacterBuffer->copyToBufferAsChar( value );
	}
} //namespace COLLADASW
