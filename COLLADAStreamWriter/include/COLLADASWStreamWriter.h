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

#include <fstream>
#include <stack>
#include <list>
#include <vector>
#include <limits>
#include <algorithm>
#include <string.h>

#define WHITESPACESTRINGLENGTH 1000

namespace COLLADABU
{
    class NativeString;
}

namespace Common
{
	class FWriteBufferFlusher;
	class CharacterBuffer;
}

namespace COLLADASW
{

    class StreamWriter;

	typedef unsigned long ElementIndexType;


    /** Class that simplifies closes open elements*/
    class TagCloser
    {

    public:
        TagCloser();

		/** We use the default copy ctor.*/
        ~TagCloser();

        /** Closes all elements that have been open and not closed, since this object has been instantiated*/
        void close();

        TagCloser & operator= ( const TagCloser & other );

    private:
        friend class StreamWriter;
        TagCloser ( StreamWriter * streamWriter, ElementIndexType elementIndex );

        StreamWriter * mStreamWriter;
		ElementIndexType mElementIndex; //!< the index of the open tag
    };


    /** A class to write a COLLADASW document directly to a file, without storing the data in an internal data model*/
    class StreamWriter
    {
	public:
		enum COLLADAVersion
		{
			COLLADA_1_4_1,
			COLLADA_1_5_0
		};
    private:

        /** Contains information about an open tag*/
        struct OpenTag
        {
            OpenTag ( const String* name, ElementIndexType elementIndex ) 
				: mName ( name )
				, mElementIndex( elementIndex )
				, mHasContents( false )
				, mHasText ( false ) 
			{}

            const String* mName;            //!< The name of the tag
			ElementIndexType mElementIndex; //!< the index of the open tag
            bool mHasContents;              //!< true, if contents, i.e. elements or text has been added to the element
            bool mHasText;                  //!< true, if text has been added to the element
        };

		typedef std::deque<OpenTag> OpenTagStack;

    private:
		Common::FWriteBufferFlusher* mBufferFlusher;

		Common::CharacterBuffer* mCharacterBuffer;

        /** If true, the double values will be exported with a maximum precision of 20 digits. */
        bool mDoublePrecision;

        OpenTagStack mOpenTags;  //!< A stack that holds all the open tags.

        size_t mLevel;

        size_t mIndent;

		static const int FWRITEBUFFERSIZE;

		static const int CHARACTERBUFFERSIZE;

        static const String mWhiteSpaceString;

        friend class TagCloser;

		/** Each element gets a continuous index. This is the index the next opened element gets.*/
		ElementIndexType mNextElementIndex;

		/** The version of the COLLADA file.*/
		COLLADAVersion mCOLLADAVersion;

    public:
        /** Creates a stream writer that writes to file @a fileName*/
        StreamWriter ( const NativeString& fileName, bool doublePrecision = false, COLLADAVersion cOLLADAVersion = COLLADA_1_4_1);

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

        /** Adds @a text to the COLLADASW file in a new line.
        No checks are performed, if @a text contains forbidden characters. */
        void appendTextBlock ( const String& text );

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
        void appendValues ( int number );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( int number, int number2 );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( unsigned int number );

        /** Adds @a number to the COLLADASW file.*/
        void appendValues ( unsigned int number, unsigned int number2 );

		/** Adds @a number to the COLLADASW file.*/
		void appendValues ( long number );

		/** Adds @a number1 and @a number2 to the COLLADASW file.*/
		void appendValues ( long  number1, long  number2 );

		/** Adds @a number1, @a number2 and @a number3 to the COLLADASW file.*/
		void appendValues ( long  number1, long  number2, long  number3 );

		/** Adds @a number1, @a number2, @a number3 and @a number4 to the COLLADASW file.*/
		void appendValues ( long  number1, long  number2, long  number3, long  number4 );

		/** Adds @a number to the COLLADASW file.*/
		void appendValues ( unsigned long number );

		/** Adds @a number1 and @a number2 to the COLLADASW file.*/
		void appendValues ( unsigned long number1, unsigned long number2 );

		/** Adds @a number1, @a number2 and @a number3 to the COLLADASW file.*/
		void appendValues ( unsigned long number1, unsigned long number2, unsigned long number3 );

		/** Adds @a number1, @a number2, @a number3 and @a number4 to the COLLADASW file.*/
		void appendValues ( unsigned long number1, unsigned long number2, unsigned long number3, unsigned long number4 );

		/** Adds @a number to the COLLADASW file.*/
		void appendValues ( long long number );

		/** Adds @a number1 and @a number2 to the COLLADASW file.*/
		void appendValues ( long long number1, long long number2 );

		/** Adds @a number1, @a number2 and @a number3 to the COLLADASW file.*/
		void appendValues ( long long number1, long long number2, long long number3 );

		/** Adds @a number1, @a number2, @a number3 and @a number4 to the COLLADASW file.*/
		void appendValues ( long long number1, long long number2, long long number3, long long number4 );

		/** Adds @a number to the COLLADASW file.*/
		void appendValues ( unsigned long long number );

		/** Adds @a number1 and @a number2 to the COLLADASW file.*/
		void appendValues ( unsigned long long number1, unsigned long long number2 );

		/** Adds @a number1, @a number2 and @a number3 to the COLLADASW file.*/
		void appendValues ( unsigned long long number1, unsigned long long number2, unsigned long long number3 );

		/** Adds @a number1, @a number2, @a number3 and @a number4 to the COLLADASW file.*/
		void appendValues ( unsigned long long number1, unsigned long long number2, unsigned long long number3, unsigned long long number4 );

        /** Adds the float @a number to the COLLADASW file.*/
        void appendValues ( bool value );

        /** Adds the float @a number to the COLLADASW file.*/
        void appendValues ( const Color& value );

		/** Adds @a text to the COLLADASW file.
		No checks are performed, if @a text contains forbidden characters. */
		void appendValues ( const String& text );

		/** Adds @a text to the COLLADASW file.
		No checks are performed, if @a text contains forbidden characters. */
		void appendValues ( const char* text );

		/** Adds @a text to the COLLADASW file.
		No checks are performed, if @a text contains forbidden characters. */
		void appendValues ( const char* text, size_t length );

        /** Opens a new element with the name @a name.
        The string must persist at least until the corresponding closeElement() member is called.*/
        TagCloser openElement ( const String& name );

        /** Closes the previously opened element. */
        void closeElement();

        /** Adds an element with name @a elementName that contains only @a text.*/
        void appendTextElement ( const String& elementName, const String& text );

        /** Adds an element with name @a elementName that contains only @a text.*/
        void appendURIElement ( const String& elementName, const URI& text );

		/** Returns the version of the COLLADA file that ias written by the StreamWriter.*/
		COLLADAVersion getCOLLADAVersion() const { return mCOLLADAVersion; } 

    private:

		/** Closes all elements opened since the element with index @a elementIndex has been open, 
		including the element itself. */
		void closeElements( ElementIndexType elementIndex );

		/** Adds the string @a str to the stream.*/
		inline void appendString ( const String & str )
		{
			appendNCNameString(str);
		}

		/** Adds the string @a str to the stream.*/
		inline void appendString ( const char* text )
		{
			appendString(text, strlen(text));
		}

		/** Adds the string @a str to the stream.*/
		void appendString ( const char* text, size_t length );

        /** Adds the string @a str to the stream.
            The string have to be a valid ncname. */
        void appendNCNameString ( const String & str );

        /** Adds the first @n characters of string @a str to the stream.
        @a n must not be larger than the length of @a str.*/
        void appendNCNameString ( const String & str, size_t n );


        /** Adds the char @a c to the stream*/
        void appendChar ( char c );

        /** Adds the double @a number to the stream*/
        void appendNumber ( double number );

        /** Adds the float @a number to the stream*/
        void appendNumber ( float number );

        /** Adds the long @a number to the stream*/
        void appendNumber ( int number );

        /** Adds the long @a number to the stream*/
        void appendNumber ( unsigned int number );

		/** Adds the long @a number to the stream*/
		void appendNumber ( long number );

		/** Adds the long @a number to the stream*/
		void appendNumber ( unsigned long number );

		/** Adds the long long @a number to the stream*/
		void appendNumber ( long long number );

		/** Adds the long long @a number to the stream*/
		void appendNumber ( unsigned long long number );

        /** Adds the bool @a value to the stream*/
        void appendBoolean ( bool value );

        /** Adds a new line to the stream*/
        inline void appendNewLine()
        {
            appendChar ( '\n' );
        }

        /** Adds @a number white spaces to the stream*/
        void addWhiteSpace (  size_t number );

    private:

        /** This function prepares the last opened tag to add contents to it.
        This function must be called before any contents is added to an element. After this function
        has been calls, contents should be added, but if not, the xml file will still be valid*/
        void prepareToAddContents();

    };


} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_H__
