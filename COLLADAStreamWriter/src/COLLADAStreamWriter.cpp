/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAStreamWriter.h"

#include <string>
#include <fstream>
#include <assert.h>

#include "COLLADASWC.h"
#include "COLLADAURI.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    TagCloser::TagCloser ( StreamWriter * streamWriter )
            : mNumberOfOpenElements ( 1 ), mStreamWriter ( streamWriter )
    {
        assert ( mStreamWriter != 0 );

        mStreamWriter->addTagCloser ( this );
    }

    //---------------------------------------------------------------
    TagCloser::TagCloser()
            : mNumberOfOpenElements ( 0 ), mStreamWriter ( 0 )
    {}

    //---------------------------------------------------------------
    TagCloser::~TagCloser()
    {
        if ( mStreamWriter )
            mStreamWriter->removeTagCloser ( this );
    }

    //---------------------------------------------------------------
    TagCloser & TagCloser::operator= ( const TagCloser & other )
    {
        if ( &other != this )
        {
            mStreamWriter = other.mStreamWriter;
            mNumberOfOpenElements = other.mNumberOfOpenElements;

            if ( mStreamWriter )
                mStreamWriter->addTagCloser ( this );
        }

        return *this;
    }


    //---------------------------------------------------------------
    void TagCloser::close()
    {
        while ( mNumberOfOpenElements > 0 )
            mStreamWriter->closeElement();
    }



    const String StreamWriter::mWhiteSpaceString ( WHITESPACESTRINGLENGTH,' ' );

	const int StreamWriter::BUFFERSIZE = 2097152;


    //---------------------------------------------------------------
    StreamWriter::StreamWriter ( const String & fileName )
            : mLevel ( 0 )
            ,mIndent ( 2 )
            ,mBuffer ( NULL )
    {
		mBuffer = new char[BUFFERSIZE];
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
		String mLocale = setlocale(LC_NUMERIC, 0);
		setlocale(LC_NUMERIC, "C");
        errno_t error = fopen_s ( &mStream, fileName.c_str(), "w" );
        if ( error != 0 )
        {
            fprintf ( stderr, "Failure open file. errno_t = %d", error );
        }
		setvbuf ( mStream , mBuffer, _IOFBF, BUFFERSIZE );
#else
        mOutFile.rdbuf() ->pubsetbuf ( mBuffer, /*sizeof ( mBuffer )*/BUFFERSIZE );
        mOutFile.open ( fileName.c_str() );
#endif
    }

    //---------------------------------------------------------------
    StreamWriter::~StreamWriter()
    {
        endDocument();
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
        fclose ( mStream );
		setlocale(LC_NUMERIC, mLocale.c_str());
#else
        mOutFile.close();
#endif
        delete[] mBuffer;

    }

    //---------------------------------------------------------------
    void StreamWriter::startDocument()
    {
        appendNCNameString ( CSWC::XML_START_ELEMENT );
        openElement ( CSWC::COLLADA_ELEMENT_COLLADA );
        appendAttribute ( CSWC::COLLADA_ATTRIBUTE_XMLNS, CSWC::COLLADA_NAMESPACE );
        appendAttribute ( CSWC::COLLADA_ATTRIBUTE_VERSION, CSWC::COLLADA_VERSION );
    }

    //---------------------------------------------------------------
    void StreamWriter::endDocument()
    {
        while ( !mOpenTags.empty() )
            closeElement();
    }

    //---------------------------------------------------------------
    void StreamWriter::appendURLAttribute ( const String &name, const URI &uri )
    {
        assert ( !mOpenTags.top().mHasContents );

		appendChar ( ' ' );
		appendNCNameString ( name );
		appendChar ( '=' );
		appendChar ( '\"' );
		appendString ( uri.getURIString() );
		appendChar ( '\"' );
    }

    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, const String &value )
    {
        assert ( !mOpenTags.top().mHasContents );

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
        assert ( !mOpenTags.top().mHasContents );

        appendChar ( ' ' );
        appendNCNameString ( name );
        appendChar ( '=' );
        appendChar ( '\"' );
        appendNumber ( value );
        appendChar ( '\"' );
    }


    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, const unsigned long value )
    {
        assert ( !mOpenTags.top().mHasContents );

        appendChar ( ' ' );
        appendNCNameString ( name );
        appendChar ( '=' );
        appendChar ( '\"' );
        appendNumber ( value );
        appendChar ( '\"' );
    }

    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, const unsigned int value )
    {
        assert ( !mOpenTags.top().mHasContents );

        appendChar ( ' ' );
        appendNCNameString ( name );
        appendChar ( '=' );
        appendChar ( '\"' );
        appendNumber ( value );
        appendChar ( '\"' );
    }

    //---------------------------------------------------------------
    void StreamWriter::appendText ( const String &text )
    {
        prepareToAddContents();
        appendString ( text );
        mOpenTags.top().mHasText = true;
    }


    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double number )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number );

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double number1, const double number2 )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );

        mOpenTags.top().mHasText = true;
    }


    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double number1, const double number2, const double number3 )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );
        appendChar ( ' ' );
        appendNumber ( number3 );

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double number1, const double number2, const double number3, const double number4 )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );
        appendChar ( ' ' );
        appendNumber ( number3 );
        appendChar ( ' ' );
        appendNumber ( number4 );

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const float values[], const size_t length )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );

        for ( size_t i=0; i<length; ++i )
        {
            appendNumber ( values[i] );
            appendChar ( ' ' );
        }

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const float matrix[4][4] )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
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

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double values[], const size_t length )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );

        for ( size_t i=0; i<length; ++i )
        {
            appendNumber ( values[i] );
            appendChar ( ' ' );
        }

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const double matrix[4][4] )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
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

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const std::vector<float> &values )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );

        std::vector<float>::const_iterator it = values.begin();
        for ( ; it!=values.end(); ++it )
        {
            appendNumber ( *it );
            appendChar ( ' ' );
        }

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const std::vector<double> &values )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );

        std::vector<double>::const_iterator it = values.begin();
        for ( ; it!=values.end(); ++it )
        {
            appendNumber ( *it );
            appendChar ( ' ' );
        }

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const std::vector<String> &values )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );

        std::vector<String>::const_iterator it = values.begin();
        for ( ; it!=values.end(); ++it )
        {
            appendString ( *it );
            appendChar ( ' ' );
        }

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const std::vector<unsigned long> &values )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );

        std::vector<unsigned long>::const_iterator it = values.begin();
        for ( ; it!=values.end(); ++it )
        {
            appendNumber ( *it );
            appendChar ( ' ' );
        }

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const int number )
    {
        prepareToAddContents();
        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );
        appendNumber ( number );
        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const unsigned int number )
    {
        prepareToAddContents();
        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );
        appendNumber ( number );
        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const long number )
    {
        prepareToAddContents();
        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );
        appendNumber ( number );
        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const unsigned long number )
    {
        prepareToAddContents();
        if ( mOpenTags.top().mHasText ) appendChar ( ' ' );
        appendNumber ( number );
        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const unsigned long number1, const unsigned long number2 )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );

        mOpenTags.top().mHasText = true;
    }


    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const unsigned long number1, const unsigned long number2, const unsigned long number3 )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );
        appendChar ( ' ' );
        appendNumber ( number3 );

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const unsigned long number1, const unsigned long number2, const unsigned long number3, const unsigned long number4 )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number1 );
        appendChar ( ' ' );
        appendNumber ( number2 );
        appendChar ( ' ' );
        appendNumber ( number3 );
        appendChar ( ' ' );
        appendNumber ( number4 );

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const bool value )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendBoolean ( value );

        mOpenTags.top().mHasText = true;
    }


    //---------------------------------------------------------------
    void StreamWriter::appendValues ( const String & text )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendString ( text );

        mOpenTags.top().mHasText = true;
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
        mOpenTags.push ( OpenTag ( &name ) );

        for ( TagCloserList::iterator it = mTagClosers.begin(); it != mTagClosers.end(); it++ )
            ( *it )->increaseOpenElements();

        return TagCloser ( this );
    }


    //---------------------------------------------------------------
    void StreamWriter::closeElement()
    {
        assert ( !mOpenTags.empty() );

        mLevel--;

        if ( mOpenTags.top().mHasContents )
        {
            if ( !mOpenTags.top().mHasText )
            {
                appendNewLine();
                addWhiteSpace ( mLevel * mIndent );
            }

            appendChar ( '<' );

            appendChar ( '/' );
            appendNCNameString ( *mOpenTags.top().mName );
            appendChar ( '>' );
        }

        else
        {
            appendChar ( '/' );
            appendChar ( '>' );
        }

        mOpenTags.pop();

        for ( TagCloserList::iterator it = mTagClosers.begin(); it != mTagClosers.end(); it++ )
            ( *it )->decreaseOpenElements();
    }


    //---------------------------------------------------------------
    void StreamWriter::appendTextElement ( const String & elementName, const String & text )
    {
        openElement ( elementName );
        appendText ( text );
        closeElement();
    }


    //---------------------------------------------------------------
    void StreamWriter::prepareToAddContents()
    {
        if ( !mOpenTags.empty() && !mOpenTags.top().mHasContents )
        {
            appendChar ( '>' );
            mOpenTags.top().mHasContents = true;
        }
    }



    //---------------------------------------------------------------
    void StreamWriter::addWhiteSpace ( const size_t number )
    {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S

        for ( size_t i = 0; i<number; ++i )
            appendChar ( ' ' );

#else
        size_t numberOfWholeStrings = number / WHITESPACESTRINGLENGTH;

        size_t remainder = number % WHITESPACESTRINGLENGTH;

        for ( size_t i = 0; i < numberOfWholeStrings; ++i )
            appendNCNameString ( mWhiteSpaceString );

        appendNCNameString ( mWhiteSpaceString, remainder );

#endif

    }


    //---------------------------------------------------------------
    void StreamWriter::addTagCloser ( TagCloser * tagCloser )
    {
        mTagClosers.push_back ( tagCloser );
    }


    //---------------------------------------------------------------
    void StreamWriter::removeTagCloser ( TagCloser * tagCloser )
    {
        mTagClosers.remove ( tagCloser );
    }


} //namespace COLLADA
