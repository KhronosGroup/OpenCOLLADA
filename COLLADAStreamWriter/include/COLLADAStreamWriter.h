/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_H__
#define __COLLADASTREAMWRITER_H__


//#define COLLADASTREAMWRITER_USE_FPRINTF_S

#include "COLLADAPrerequisites.h"
#include "COLLADAMathUtils.h"
#include <fstream>
#include <stack>
#include <list>
#include <vector>
#include <limits>


#define WHITESPACESTRINGLENGTH 1000

namespace COLLADA
{

    class StreamWriter;

    /** Class that simplifies closes open elements*/

    class TagCloser
    {

    public:
        TagCloser();
        ~TagCloser();

        /** Closes all elements that have been open and not closed, since this object has been instantiated*/
        void close();

        TagCloser & operator= ( const TagCloser & other );

    private:
        friend StreamWriter;
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


    /** A class to write a COLLADA document directly to a file, without storing the data in an internal data model*/

    class StreamWriter
    {

    public:
        /** Creates a stream writer that writes to file @a fileName*/
        StreamWriter ( const String& fileName );

        /** Closes all open tags and closes the stream*/
        ~StreamWriter();


        /** Writes the document start, including the opening @a \<COLLADA\> element.
        This member must be called, before any other member function can be called.*/
        void startDocument();

        /** Closes all open tags*/
        void endDocument();

        /** Adds the attribute @a name with value @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendAttribute ( const String& name, const String & value );

        /** Adds the attribute @a name with value @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendAttribute ( const String& name, double value );

        /** Adds the attribute @a name with value @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendAttribute ( const String& name, unsigned long value );

        /** Adds the attribute @a name with value @a value to the last opened element.
        This function can only be called after openElement() before any content is written.*/
        void appendAttribute ( const String& name, unsigned int value );

        /** Adds @a text to the COLLADA file.
        No checks are performed, if @a text contains forbidden characters. */
        void appendText ( const String& text );

        /** Adds @a number to the COLLADA file.*/
        void appendValues ( double number );

        /** Adds @a number1 and @a number2 to the COLLADA file.*/
        void appendValues ( double number1, double number2 );

        /** Adds @a number1, @a number2 and @a number3 to the COLLADA file.*/
        void appendValues ( double number1, double number2, double number3 );

        /** Adds @a number1, @a number2, @a number3 and @a number4 to the COLLADA file.*/
        void appendValues ( double number1, double number2, double number3, double number4 );

        /** Adds all values in the array to the COLLADA file.*/
        void appendValues ( const float values[], const size_t length );

        /** Adds all values in the array to the COLLADA file.*/
        void appendValues ( const double values[], const size_t length );

        /** Adds all values in the array to the COLLADA file.*/
        void appendValues ( const float matrix[4][4] );

        /** Adds all values in the array to the COLLADA file.*/
        void appendValues ( const double matrix[4][4] );

        /** Adds all values in the array to the COLLADA file.*/
        void appendValues ( const std::vector<float>& values );

        /** Adds all values in the array to the COLLADA file.*/
        void appendValues ( const std::vector<double>& values );

        /** Adds all values in the array to the COLLADA file.*/
        void appendValues ( const std::vector<String>& values );

        /** Adds all values in the array to the COLLADA file.*/
        void appendValues ( const std::vector<unsigned long>& values );

        /** Adds @a number to the COLLADA file.*/
        void appendValues ( int number );

        /** Adds @a number to the COLLADA file.*/
        void appendValues ( unsigned long number );

        /** Adds @a number1 and @a number2 to the COLLADA file.*/
        void appendValues ( unsigned long number1, unsigned long number2 );

        /** Adds @a number1, @a number2 and @a number3 to the COLLADA file.*/
        void appendValues ( unsigned long number1, unsigned long number2, unsigned long number3 );

        /** Adds @a number1, @a number2, @a number3 and @a number4 to the COLLADA file.*/
        void appendValues ( unsigned long number1, unsigned long number2, unsigned long number3, unsigned long number4 );

        /** Adds the float @a number to the COLLADA file.*/
        void appendValues ( bool value );

        /** Adds @a text to the COLLADA file.
        No checks are performed, if @a text contains forbidden characters. */
        void appendValues ( const String& text );

        /** Opens a new element with the name @a name.
        The string must persist at least until the corresponding closeElement() member is called.*/
        TagCloser openElement ( const String& name );

        /** Closes the previously opened element*/
        void closeElement();

        /** Adds an element with name @a elementName that contains only @a text.*/
        void appendTextElement ( const String& elementName, const String& text );




    protected:
        /** Adds the string @a str to the stream*/
        inline void appendString ( const String & str )
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
        inline void appendString ( const String & str, size_t n )
        {
            mOutFile.write ( str.c_str(), ( std::streamsize ) n );
        }

#endif

        /** Adds the char @a c to the stream*/
        inline void appendChar ( char c )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            fprintf_s ( mStream, "%c", c );
#else
            mOutFile.put ( c );
#endif
        }

        /** Adds the double @a number to the stream*/
        inline void appendNumber ( double number )
        {
			if ( MathUtils::equals<double>(number, 0, std::numeric_limits<double>::epsilon()) )
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
				fprintf_s ( mStream, "%g", number );
#else
				mOutFile << number;
#endif
			}
        }

        /** Adds the float @a number to the stream*/
        inline void appendNumber ( float number )
        {
			if ( MathUtils::equals<float>(number, 0, std::numeric_limits<float>::epsilon()) )
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
            fprintf_s ( mStream, "%g", number );
#else
            mOutFile << number;
#endif
			}
        }

        /** Adds the long @a number to the stream*/
        inline void appendNumber ( int number )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
            fprintf_s ( mStream, "%f", number );
#else
            mOutFile << number;
#endif
        }

        /** Adds the long @a number to the stream*/
        inline void appendNumber ( unsigned int number )
        {
#ifdef USE_FPRINTF
            fprintf_s ( mStream, "%f", number );
#else
            mOutFile << number;
#endif
        }

        /** Adds the long @a number to the stream*/
        inline void appendNumber ( unsigned long number )
        {
#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
			fprintf_s ( mStream, "%lu", number );
#else
            mOutFile << number;
#endif
        }

        /** Adds the bool @a value to the stream*/
        void appendBoolean ( bool value )
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
        void addWhiteSpace ( size_t number );

    private:

        /** This function prepares the last opened tag to add contents to it.
        This function must be called before any contents is added to an element. After this function
        has been calles, conttents should be added, but if not, the xml file will still be valid*/
        void prepareToAddContents();

        /** Contains information about an open tag*/

        struct OpenTag
        {
            OpenTag ( const String * name ) : mName ( name ), mHasContents ( false ), mHasText ( false ) {}

            const String * mName;      //!< The name of the tag
            bool mHasContents;    //!< true, if contents, i.e. elements or text has been added to the element
            bool mHasText;     //!< true, if text has been added to the element
        };

#ifdef COLLADASTREAMWRITER_USE_FPRINTF_S
        FILE *mStream;        //!< The stream the Collada file will be written to.
		String mLocale;			//!< The LC_NUMERIC locale that was set before the Streamwriter was instantiated.
#else
        std::ofstream mOutFile;         //!< The stream the Collada file will be written to.
#endif

        std::stack<OpenTag> mOpenTags;  //!< A stack that holds all the open tags.

        size_t mLevel;

        size_t mIndent;

        char *mBuffer; // 2MB Puffer!!

		static const int BUFFERSIZE; 

        static const String mWhiteSpaceString;

        friend TagCloser;

        typedef std::list<TagCloser*> TagCloserList;
        TagCloserList mTagClosers;

        /** Add @a tagCloser to the list of tag closers*/
        void addTagCloser ( TagCloser * tagCloser );

        /** Removes @a tagCloser to the list of tag closers*/
        void removeTagCloser ( TagCloser * tagCloser );


    };


} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_H__
