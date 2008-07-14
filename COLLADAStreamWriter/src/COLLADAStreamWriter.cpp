/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAStreamWriter.h"

#include <string>
#include <fstream>
#include <assert.h>

#include "COLLADASWC.h"

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



    //---------------------------------------------------------------
    StreamWriter::StreamWriter ( const String & fileName )
            : mLevel ( 0 )
            ,mIndent ( 2 )
            ,mBuffer ( NULL )
    {
#ifdef USE_FPRINTF
        fopen_s ( &mStream, fileName.c_str(), "w" );
#else
        mBuffer = new char[2097152];
        mOutFile.rdbuf() ->pubsetbuf ( mBuffer, sizeof ( mBuffer ) );
        mOutFile.open ( fileName.c_str() );
#endif
    }

    //---------------------------------------------------------------
    StreamWriter::~StreamWriter()
    {
        endDocument();
#ifdef USE_FPRINTF
        fclose ( mStream );
#else
        mOutFile.close();
#endif
        delete[] mBuffer;
    }

    //---------------------------------------------------------------
    void StreamWriter::startDocument()
    {
        appendString ( CSWC::XML_START_ELEMENT );
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
    void StreamWriter::appendAttribute ( const String &name, const String &value )
    {
        assert ( !mOpenTags.top().mHasContents );

        if ( !value.empty() )
        {
            appendChar ( ' ' );
            appendString ( name );
            appendChar ( '=' );
            appendChar ( '\"' );
            appendString ( value );
            appendChar ( '\"' );
        }
    }

    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, double value )
    {
        assert ( !mOpenTags.top().mHasContents );

        appendChar ( ' ' );
        appendString ( name );
        appendChar ( '=' );
        appendChar ( '\"' );
        appendNumber ( value );
        appendChar ( '\"' );
    }


    //---------------------------------------------------------------
    void StreamWriter::appendAttribute ( const String &name, unsigned long value )
    {
        assert ( !mOpenTags.top().mHasContents );

        appendChar ( ' ' );
        appendString ( name );
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
    void StreamWriter::appendValues ( double number )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number );

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( double number1, double number2 )
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
    void StreamWriter::appendValues ( double number1, double number2, double number3 )
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
    void StreamWriter::appendValues ( double number1, double number2, double number3, double number4 )
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
    void StreamWriter::appendValues ( unsigned long number )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number );

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( int number )
    {
        prepareToAddContents();

        if ( mOpenTags.top().mHasText )
            appendChar ( ' ' );

        appendNumber ( number );

        mOpenTags.top().mHasText = true;
    }

    //---------------------------------------------------------------
    void StreamWriter::appendValues ( unsigned long number1, unsigned long number2 )
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
    void StreamWriter::appendValues ( unsigned long number1, unsigned long number2, unsigned long number3 )
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
    void StreamWriter::appendValues ( unsigned long number1, unsigned long number2, unsigned long number3, unsigned long number4 )
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
    void StreamWriter::appendValues ( bool value )
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
        appendString ( name );
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
            appendString ( *mOpenTags.top().mName );
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
    void StreamWriter::addWhiteSpace ( size_t number )
    {
#ifdef USE_FPRINTF

        for ( int i = 0; i<number; ++i )
            appendChar ( ' ' );

#else
        size_t numberOfWholeStrings = number / WHITESPACESTRINGLENGTH;

        size_t remainder = number % WHITESPACESTRINGLENGTH;

        for ( size_t i = 0; i < numberOfWholeStrings; ++i )
            appendString ( mWhiteSpaceString );

        appendString ( mWhiteSpaceString, remainder );

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
