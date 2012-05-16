/******************************************************************************
Copyright (c) 2007 netAllied GmbH, Tettnang

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

#ifndef __MATHML_STRING_H__
#define __MATHML_STRING_H__

#include "MathMLSolverPrerequisites.h"

#include <iostream>
#include <vector>
#include <string>

namespace MathML
{
    /** The standard string implementation.
    */
    typedef std::string String;

    /** CIS string implementation.
    */
    typedef std::wstring WideString;

    /** If wchar_t treated as native type we need an alternative for
    for third party libs or plug-ins that aren't compiled with wchar_t 
    as native type. Usually wchar_t is mapped to unsigned short.
    @see http://msdn2.microsoft.com/en-us/library/dh8che7s(VS.80).aspx
    */
    typedef std::basic_string < unsigned short, std::char_traits<unsigned short>,
    std::allocator<unsigned short> > WideString2;

    /** A vector of strings.
    */
    typedef std::vector<String> StringVector;

    /** A vector of wide strings.
    */
    typedef std::vector<WideString> WStringVector;

    class _MATHML_SOLVER_EXPORT StringUtil
    {

    public:

        /** @todo lastIndexOf documentation
         @param str
         @param pattern
         @return
        */
        static String::size_type lastIndexOf( const String& str, const String& pattern );
        /** @todo lastIndexOf documentation
         @param str
         @param character
         @return
        */
        static String::size_type lastIndexOf( const String& str, const char character );

        /** @todo startsWith documentation
         @param str
         @param pattern
         @return
        */
        static bool startsWith( const String& str, const String& pattern );
        /** @todo startsWith documentation
         @param str
         @param character
         @return
        */
        static bool startsWith( const String& str, char character );

        /** Searches the given string, and checks if the pattern is found at the end of it.
        @param str The string to be searched.
        @param pattern The pattern to search for.
        @return true If pattern is found at the end of the string, otherwise false.
        */
        static bool endsWith( const String& str, const String& pattern );
        /** Searches the given string, and checks if the character is found at the end of it.
        @param str The string to be searched.
        @param character The character to search for.
        @return true If pattern is found at the end of the string, otherwise false.
        */
        static bool endsWith( const String& str, char character );

        /** Replaces parts of the given string.
        @param str The string to be searched.
        @param character The character to search for.
        @param replacement The replacement string.
        @return The new processed string.
        */
        static String replaceAll( const String& str, char character, const String& replacement );
        /** Replaces parts of the given string.
        @param str The string to be searched.
        @param pattern The pattern to search for.
        @param replacement The replacement string.
        @return The new processed string.
        */
        static String replaceAll( const String& str, const String& pattern, const String& replacement );
        /** Replaces parts of the given string.
        @param str The string to be searched.
        @param pattern The pattern to search for.
        @param replacement The replacement character.
        @return The new processed string.
        */
        static String replaceAll( const String& str, const String& pattern, char replacement );

        static String replaceAll( const String& str, char pattern, char replacement );


        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( unsigned char value );
        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( unsigned short value );
        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( unsigned int value );
        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( unsigned long value );
        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( unsigned long long value );
        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( char value );
        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( short value );
        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( int value );
        /** @todo valueOf documentation
         @param value
         @return
        */
        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( long value );

        /** @todo valueOf documentation
        @param value
        @return
        */
        static String valueOf( long long value );

        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( float value );
        /** @todo valueOf documentation
         @param value
         @return
        */
        static String valueOf( double value );

        /** Converts an integer to a String.
        Does not finalize the string with std::ends to avoid a trailing blank.
        @param value Integer to parse.
        @return string Representation.
        */
        static String valueOfUnfinalized( int value );

        /**
         Compare two strings case-insensitively using full case folding.
         @param str1 First string to compare.
         @param str2 Second string to compare.
         @return A negative, zero, or positive integer indicating the comparison result.    
        */
        static int caseCompare( const String& str1, const String& str2 );

        /** @todo toLowerCase documentation
         @param str
         @return
        */
        static void toLowerCase( String& str );
        /** @todo toUpperCase documentation
         @param str
         @return
        */
        static void toUpperCase( String& str );

        /** @todo parseUnsignedShort documentation
         @param str
         @return
        */
        static unsigned short parseUnsignedShort( const String& str );
        /** @todo parseUnsignedInt documentation
         @param str
         @return
        */
        static unsigned int parseUnsignedInt( const String& str );
        /** @todo parseUnsignedLong documentation
         @param str
         @return
        */
        static unsigned long parseUnsignedLong( const String& str );
        /** @todo parseShort documentation
         @param str
         @return
        */
        static short parseShort( const String& str );
        /** @todo parseInt documentation
         @param str
         @return
        */
        static int parseInt( const String& str );
        /** @todo parseLong documentation
         @param str
         @return
        */
        static long parseLong( const String& str );

        static double parseDouble( const String& str );

        /** @todo description */
        static String removeWhitespaces( const String &string );

    private:
        StringUtil();
        StringUtil( const StringUtil& util );
        const StringUtil& operator=( const StringUtil& util );
    };
}

#endif //__MATHML_STRING_H__
