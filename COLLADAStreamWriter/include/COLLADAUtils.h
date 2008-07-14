/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_UTIL_H__
#define __COLLADASTREAMWRITER_UTIL_H__

#include "COLLADAPrerequisites.h"

#include <sstream>

namespace COLLADA
{

	/** A class that holds some static COLLADA utility functions*/
	class Utils
    {

    public:


        static const String FILE_PROTOCOL;


		/** Checks for a valid xs:NCName.
		1. replaces all not allowed characters
		2. forces that the string begins with a letter or an _
		@param ncName The string to convert to a valid xs:NCName.
		@return The checked string
		*/
		static String checkNCName ( const String &ncName );

		/** Checks for a valid xs:ID.
		1. replaces all not allowed characters
		2. forces that the string begins with a letter or an _
		@param ncName The string to convert to a valid xs:ID.
		@return The checked string
		*/
        static String checkID ( const String &id );


        /** Checks if @a c is an upper ASCII character*/
        static bool isUpperAsciiChar ( char c )
        {
            return ( c >= 'A' ) && ( c <= 'Z' ) ;
        }

        /** Checks if @a c is a lower ASCII character*/
        static bool isLowerAsciiChar ( char c )
        {
            return ( c >= 'a' ) && ( c <= 'z' ) ;
        }

        /** Checks if @a c is a ASCII character*/
        static bool isAsciiAlphaChar ( char c )
        {
            return isLowerAsciiChar ( c ) || isUpperAsciiChar ( c ) ;
        }

        /** Checks if @a c is a digit*/
        static bool isDigit ( char c )
        {
            return ( c >= '0' ) && ( c <= '9' ) ;
        }

        /** Checks if @a c is an xs:id character, but not alpha numeric*/
        static bool isIDExtraChar ( char c )
        {
            return ( c == '.' ) || ( c == '-' ) || ( c == '_' ) ;
        }

        /** Checks if @a c is an xs:id character, but not alpha numeric*/
        static bool isIDChar ( char c )
        {
            return isAsciiAlphaChar ( c ) || isDigit ( c ) || isIDExtraChar ( c ) ;
        }

        static String UriEncode ( const String & sSrc );

		/**  Returns @a text with all dots replaced by underlines*/
        static String replaceDot ( const String &text );

		/** Converts @a value to a string.
		@param T The type of the value to convert.
		@param value The value of type @a T to convert to a string.
		*/
        template<class T>
        static String toString ( const T & value )
        {
            std::stringstream stream;
            stream << value;
            return stream.str();
        }
    };

}

#endif // #define __COLLADASTREAMWRITER_UTIL_H__
