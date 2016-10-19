/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_STRINGUTILS_H__
#define __COLLADABU_STRINGUTILS_H__

#include "COLLADABUPrerequisites.h"
#include "COLLADABUNativeString.h"

#include <sstream>
#include <fstream>
#include <map>

namespace COLLADABU
{

	/** A class that holds some static COLLADA utility functions*/
	class StringUtils
    {


    public:
       /**
         * Returns true, if both strings are equal. The comparison is case sensitive.
         */
		template<class StringType>
		static bool equals ( const StringType &str1, const StringType &str2 )
		{
			if ( str1.length() != str2.length() )
				return false;
			return ( strcmp ( str1.c_str(), str2.c_str() ) == 0 );
		}

        /**
        * Returns true, if both strings are equal. The comparison is case intensitive.
        */
        static bool equalsIgnoreCase ( const WideString& s1, const WideString& s2 );

		/** Checks for a valid xs:NCName.
		1. replaces all not allowed characters
		2. forces that the string begins with a letter or an _
		@param ncName The string to convert to a valid xs:NCName.
		@return The checked string
		*/
		static WideString checkNCName(const WideString &ncName, bool encodingColon);
		//		static UTF8String checkNCName ( const UTF8String &ncName ){return UTF8String();};


		/** Checks for a valid xs:NCName.
		1. replaces all not allowed characters
		2. Any XML name character that does not conform to the XML 1.0 spec (fourth edition) recommendation is escaped as _xHHHH_.
		   The HHHH string stands for the four-digit hexadecimal UCS-2 code for the character in most significant bit first order.
		   For example, the name Order Details is encoded as Order_x0020_Details.
		@param ncName The string to convert to a valid xs:NCName.
		@return The checked string
		*/
		static WideString checkNCNameWithUCS2Encoding(const WideString &ncName, bool encodingColon);


		/** Checks for a valid xs:ID.
		1. replaces all not allowed characters
		2. forces that the string begins with a letter or an _
		@param ncName The string to convert to a valid xs:ID.
		@return The checked string
		*/
        static WideString checkID ( const WideString &id );
		static WideString checkIDWithUC2Encoding(const WideString &id);
		

//		static UTF8String checkID ( const UTF8String &id ){return UTF8String();};

		/** Checks if @a c is followed by a character sequence that together with the underscore can be misinterpreted as an escape sequence when decoding the name
			For example, Order_Details is not encoded, but Order_x0020_ is encoded as Order_x005f_x0020_. 
		*/
		static bool Prepass(const WideString &ncName, int i);

		static bool isNameStartCharExcludingColon(wchar_t c);

		/** Checks if @a c is name start character according to http://www.w3.org/TR/xml11/#NT-NameStartChar */
		static bool isNameStartChar(wchar_t c, bool encodingColon);

		/** Checks if @a c is name character according to http://www.w3.org/TR/xml11/#NT-NameChar */
		static bool isNameChar(wchar_t c, bool encodingColon);

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

        /** Checks if @a c is an ASCII character*/
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

		/** If @a c is a lower case ascii character, the corresponding upper character is returned.*/
		static char toUpperASCIIChar( char c );

        static String uriEncode ( const String & sSrc );
		static String ucs2Encode(const String & sSrc);
		static WideString ucs2Encode(const WideString & sSrc);

		/** Escapes all the characters not allowed in xml text elements.
		@param srcString The string to translate.
		@return The translated string.*/
		static String translateToXML ( const String &srcString );

		/** Escapes all the characters not allowed in xml text elements.
		@param srcString The string to translate.
		@return The translated string.*/
		static WideString translateToXML ( const WideString &srcString );


		/**  Returns @a text with all dots replaced by underlines*/
        static String replaceDot ( const String &text );

		/** Converts @a value to a NativeString.
		@param T The type of the value to convert.
		@param value The value of type @a T to convert to a NativeString.
		*/
        template<class T>
        static NativeString toNativeString ( const T & value )
        {
            std::stringstream stream;
            stream << value;
            return NativeString(stream.str());
        }


		/** Converts @a value to a UTF8String.
		@param T The type of the value to convert.
		@param value The value of type @a T to convert to a UTF8String.
		*/
		template<class T>
		static String toUTF8String( const T & value )
		{
			std::stringstream stream;
			stream << value;
			return String(stream.str());
		}


		/** Converts @a value to a String.
		@param T The type of the value to convert.
		@param value The value of type @a T to convert to a string.
		*/
		template<class T>
		static WideString toWideString ( const T & value )
		{
			std::wstringstream stream;
			stream << value;
			return WideString(stream.str());
		}


		/**
		* Searches all search strings in the source string and replace it with the replaceString.
		* @param source Reference to the source string.
		* @param searchString The search string.
		* @param replaceString The replace string.
		*/
		template<class StringType>
		static void stringFindAndReplace ( StringType &source, const StringType searchString, const StringType replaceString )
		{
			size_t found = source.find ( searchString );
			if ( found != StringType::npos )
			{
				size_t searchStrLength = searchString.length();
				size_t replaceStrLength = replaceString.length();
				do
				{
					source.replace ( found, searchStrLength, replaceString );
					found = source.find (searchString, found + replaceStrLength );
				} while ( found != StringType::npos );
			}

		}


		/** Converts the utf8 encoded string @a utf8String to a unicode encoded widestring.*/
		static WideString utf8String2WideString( const String& utf8String );

		/** Converts the unicode encoded string @a wideString to a UTF encoded string.*/
		static String wideString2utf8String( const WideString& wideString );

    };
}

#endif // __COLLADABU_STRINGUTILS_H__
