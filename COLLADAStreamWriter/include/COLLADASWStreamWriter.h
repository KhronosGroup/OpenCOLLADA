/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_H__
#define __COLLADASTREAMWRITER_H__

#include <COLLADABUPlatform.h>

#include "COLLADASWPrerequisites.h"
#include "COLLADASWColor.h"

#if defined(COLLADABU_OS_WIN) && !defined(COLLADASTREAMWRITER_USE_FPRINTF_S)
#	define COLLADASTREAMWRITER_USE_FPRINTF_S
#	include "Math/COLLADABUMathUtils.h"
#	include "COLLADABUUtils.h"
#endif

#include <fstream>
#include <stack>
#include <list>
#include <vector>
#include <limits>
#include <algorithm>

#define WHITESPACESTRINGLENGTH 1000

namespace COLLADABU
{
    class NativeString;
}

// namespace COLLADABU
// {
//     namespace Math
//     {
//         class Utils;
//     }
// }
// 
// namespace COLLADABU
// {
//     class URI;
// }

namespace COLLADASW
{

    class StreamWriter;


    /** Class that simplifies closes open elements*/

    class TagCloser
    {

    public:
        TagCloser();
		TagCloser ( const TagCloser & other );
        ~TagCloser();

        /** Closes all elements that have been open and not closed, since this object has been instantiated*/
        void close();

        TagCloser & operator= ( const TagCloser & other );

    private:
        friend class StreamWriter;
        TagCloser ( StreamWriter * streamWriter );

        inline void increaseOpenElements()
        {
            if ( mNumberOfOpenElements != 0 ) mNumberOfOpenElements++;
        };

        inline void decreaseOpenElements()
        {
            if ( mNumberOfOpenElements != 0 ) mNumberOfOpenElements--;
        };

        size_t mNumberOfOpenElements;
        StreamWriter * mStreamWriter;

    };


    /** A class to write a COLLADASW document directly to a file, without storing the data in an internal data model*/

    class StreamWriter
    {
    private:

        /** Contains information about an open tag*/
        struct OpenTag
        {
            OpenTag ( const String* name ) : mName ( name ), mHasContents ( false ), mHasText ( false ) {}

            const String* mName;      //!< The name of the tag
            bool mHasContents;    //!< true, if contents, i.e. elements or text has been added to the element
            bool mHasText;     //!< true, if text has been added to the element
        };

    private:

#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
        FILE* mStream;        //!< The stream the Collada file will be written to.
        String mLocale;			//!< The LC_NUMERIC locale that was set before the Streamwriter was instantiated.
#else
        std::ofstream mOutFile;         //!< The stream the Collada file will be written to.
#endif

        /** If true, the float and double values will be exported with a maximum precision of 20 digits. */
        bool mDoublePrecision;

        /** For e, E and f specifiers: this is the number of digits to be printed after the decimal point.
        For g and G specifiers: This is the maximum number of significant digits to be printed. */
        int mPrecisionNumber;

        std::stack<OpenTag> mOpenTags;  //!< A stack that holds all the open tags.

        size_t mLevel;

        size_t mIndent;

        char* mBuffer; // 2MB Puffer!!

        static const int BUFFERSIZE;

        static const String mWhiteSpaceString;

        friend class TagCloser;

        typedef std::list<TagCloser*> TagCloserList;
        TagCloserList mTagClosers;

    public:
        /** Creates a stream writer that writes to file @a fileName*/
        StreamWriter ( const NativeString& fileName, bool doublePrecision = false );

        /** Closes all open tags and closes the stream*/
        ~StreamWriter();

        /** Writes the document start, including the opening @a \<COLLADASW\> element.
        This member must be called, before any other member function can be called.*/
        void startDocument();

        /** Closes all open tags*/
        void endDocument();

        /** Adds the attribute @a name with value "#" plus @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendURIAttribute ( const String& name, const URI& value );

        /** Adds the attribute @a name with value @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendAttribute ( const String& name, const String& value );

        /** Adds the attribute @a name with value @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendAttribute ( const String& name, const double value );

        /** Adds the attribute @a name with value @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendAttribute ( const String& name, const unsigned long value );

        /** Adds the attribute @a name with value @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendAttribute ( const String& name, const unsigned int value );

        /** Adds the attribute @a name with value @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendAttribute ( const String& name, const int value );

        /** Adds @a text to the COLLADASW file.
        No checks are performed, if @a text contains forbidden characters. */
        void appendText ( const String& text );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( const double number );

        /** Adds @a number1 and @a number2 to the COLLADASW file.*/
        void appendValues ( const double number1, const double number2 );

        /** Adds @a number1, @a number2 and @a number3 to the COLLADASW file.*/
        void appendValues ( const double number1, const double number2, const double number3 );

        /** Adds @a number1, @a number2, @a number3 and @a number4 to the COLLADASW file.*/
        void appendValues ( const double number1, const double number2, const double number3, const double number4 );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( const float number );

        /** Adds @a number1 and @a number2 to the COLLADASW file.*/
        void appendValues ( const float number1, const float number2 );

        /** Adds @a number1, @a number2 and @a number3 to the COLLADASW file.*/
        void appendValues ( const float number1, const float number2, const float number3 );

        /** Adds @a number1, @a number2, @a number3 and @a number4 to the COLLADASW file.*/
        void appendValues ( const float number1, const float number2, const float number3, const float number4 );

        /** Adds all values in the array to the COLLADASW file.*/
        void appendValues ( const float values[], const size_t length );

        /** Adds all values in the array to the COLLADASW file.*/
        void appendValues ( const int values[], const size_t length );

        /** Adds all values in the array to the COLLADASW file.*/
        void appendValues ( const double values[], const size_t length );

        /** Adds all values in the array to the COLLADASW file.*/
        void appendValues ( const float matrix[4][4] );

        /** Adds all values in the array to the COLLADASW file.*/
        void appendValues ( const double matrix[4][4] );

        /** Adds all values in the array to the COLLADASW file.*/
        void appendValues ( const std::vector<float>& values );

        /** Adds all values in the array to the COLLADASW file.*/
        void appendValues ( const std::vector<double>& values );

        /** Adds all values in the array to the COLLADASW file.*/
        void appendValues ( const std::vector<String>& values );

        /** Adds all values in the array to the COLLADASW file.*/
        void appendValues ( const std::vector<unsigned long>& values );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( const int number );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( const int number, const int number2 );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( const unsigned int number );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( const unsigned int number, const unsigned int number2 );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( const long number );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( const unsigned long number );

        /** Adds @a number1 and @a number2 to the COLLADASW file.*/
        void appendValues ( const unsigned long number1, const unsigned long number2 );

        /** Adds @a number1, @a number2 and @a number3 to the COLLADASW file.*/
        void appendValues ( const unsigned long number1, const unsigned long number2, const unsigned long number3 );

        /** Adds @a number1, @a number2, @a number3 and @a number4 to the COLLADASW file.*/
        void appendValues ( const unsigned long number1, const unsigned long number2, const unsigned long number3, const unsigned long number4 );

        /** Adds the float @a number to the COLLADASW file.*/
        void appendValues ( const bool value );

        /** Adds the float @a number to the COLLADASW file.*/
        void appendValues ( const Color value );

        /** Adds @a text to the COLLADASW file.
        No checks are performed, if @a text contains forbidden characters. */
        void appendValues ( const String& text );

        /** Opens a new element with the name @a name.
        The string must persist at least until the corresponding closeElement() member is called.*/
        TagCloser openElement ( const String& name );

        /** Closes the previously opened element. */
        void closeElement();

        /** Adds an element with name @a elementName that contains only @a text.*/
        void appendTextElement ( const String& elementName, const String& text );

        /** Adds an element with name @a elementName that contains only @a text.*/
        void appendURIElement ( const String& elementName, const URI& text );


    private:

        /** Adds the string @a str to the stream*/
        inline void appendString ( String & str )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            String searchString = "%", replaceString = "%%";
            Utils::stringFindAndReplace( str, searchString, replaceString );
            fprintf_s ( mStream, str.c_str() );
#else
            mOutFile.write ( str.c_str(), ( std::streamsize ) str.length() );
#endif
        }

        /** Adds the string @a str to the stream.
            We replace all "%" with "%%" if we write with printf.
            Do a copy of the const string to proceed. */
        inline void appendString ( const String & str )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            String searchString = "%";
            size_t found = str.find ( searchString );
            if ( found != String::npos )
            {
                String strCopy ( str );
                String replaceString = "%%";
                Utils::stringFindAndReplace( strCopy, searchString, replaceString );
                fprintf_s ( mStream, strCopy.c_str() );
            }
            else
            {
                fprintf_s ( mStream, str.c_str() );
            }
#else
            mOutFile.write ( str.c_str(), ( std::streamsize ) str.length() );
#endif
        }

        /** Adds the string @a str to the stream.
            The string have to be a valid ncname. */
        inline void appendNCNameString ( const String & str )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            fprintf_s ( mStream, str.c_str() );
#else
            mOutFile.write ( str.c_str(), ( std::streamsize ) str.length() );
#endif
        }

        /** Adds the first @n characters of string @a str to the stream.
        @a n must not be larger than the length of @a str.*/
#ifndef COLLADASTREAMWRITER_USE_FPRINTF_S
        inline void appendNCNameString ( const String & str, size_t n )
        {
            mOutFile.write ( str.c_str(), ( std::streamsize ) n );
        }

#endif

        /** Adds the char @a c to the stream*/
        inline void appendChar ( const char c )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            fprintf_s ( mStream, "%c", c );
#else
            mOutFile.put ( c );
#endif
        }

        /** Adds the double @a number to the stream*/
        inline void appendNumber ( const double number )
        {
			if ( COLLADABU::Math::Utils::equals<double>(number, 0, std::numeric_limits<double>::epsilon()) )
			{
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
				fprintf_s ( mStream, "0");
#else
				mOutFile << "0";
#endif
			}
			else
			{
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
                if ( mDoublePrecision )
                    fprintf_s ( mStream, "%.*g", mPrecisionNumber, number );
                else
    				fprintf_s ( mStream, "%g", number );
#else
				mOutFile << number;
#endif
			}
        }

        /** Adds the float @a number to the stream*/
        inline void appendNumber ( const float number )
        {
			if ( COLLADABU::Math::Utils::equals<float>(number, 0, std::numeric_limits<float>::epsilon()) )
			{
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
				fprintf_s ( mStream, "0");
#else
				mOutFile << "0";
#endif
			}
			else
			{
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
                if ( mDoublePrecision )
                    fprintf_s ( mStream, "%.*g", mPrecisionNumber, number );
                else
                    fprintf_s ( mStream, "%g", number );
#else
                mOutFile << number;
#endif
			}
        }

        /** Adds the long @a number to the stream*/
        inline void appendNumber ( const int number )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            fprintf_s ( mStream, "%d", number );
#else
            mOutFile << number;
#endif
        }

        /** Adds the long @a number to the stream*/
        inline void appendNumber ( const unsigned int number )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            fprintf_s ( mStream, "%u", number );
#else
            mOutFile << number;
#endif
        }

        /** Adds the long @a number to the stream*/
        inline void appendNumber ( const long number )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            fprintf_s ( mStream, "%li", number );
#else
            mOutFile << number;
#endif
        }

        /** Adds the long @a number to the stream*/
        inline void appendNumber ( const unsigned long number )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
			fprintf_s ( mStream, "%lu", number );
#else
            mOutFile << number;
#endif
        }

        /** Adds the bool @a value to the stream*/
        void appendBoolean ( const bool value )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            fprintf_s ( mStream, "%i", ( int ) value );
#else
            mOutFile << value;
#endif
        }

        /** Adds a new line to the stream*/
        inline void appendNewLine()
        {
            appendChar ( '\n' );
        }

        /** Adds @a number white spaces to the stream*/
        void addWhiteSpace ( const size_t number );

    private:

        /** This function prepares the last opened tag to add contents to it.
        This function must be called before any contents is added to an element. After this function
        has been calles, conttents should be added, but if not, the xml file will still be valid*/
        void prepareToAddContents();

        /** Add @a tagCloser to the list of tag closers*/
        void addTagCloser ( TagCloser * tagCloser );

        /** Removes @a tagCloser to the list of tag closers*/
        void removeTagCloser ( TagCloser * tagCloser );

    };


} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_H__
