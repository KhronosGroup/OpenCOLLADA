/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADABaseUtils.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_UTILS_H__
#define __COLLADABU_UTILS_H__

#include "COLLADABUPrerequisites.h"

#include <sstream>
#include <fstream>
#include <map>
#include <vector>


namespace COLLADABU
{

	/** A class that holds some static COLLADASW utility functions*/
	class Utils
    {

	public:

		// System type info. We only need to distinguish between Posix and Winodws for now.
		enum SystemType 
        {
			POSIX,
			WINDOWS
		};

        typedef std::map<String, unsigned int> EntityNameMap;
        typedef std::pair<String, unsigned int> EntityNamePair;
        static EntityNameMap entityNames;


    public:


        static const String FILE_PROTOCOL;
        static const String FILE_DELIMITER;
        static const char FILE_DELIMITER_CHAR;

		static const String EMPTY_STRING;


		// Get the system type at runtime.
		static SystemType getSystemType();


        /**
         * Returns true, if both strings are equal. The comparison is case sensitive.
         */
        static bool equals ( const String &str1, const String &str2 );

        /**
        * Returns true, if both strings are equal. The comparison is case intensitive.
        */
        static bool equalsIgnoreCase ( const String& s1, const String& s2 );

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

        /** Encodes the current URI (replace the special characters with %hexadecimal value). */
   //     static String uriEncode ( const String & sSrc );



        static String translateToXML ( const String &srcString );

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

        /**
         * Given the absolute current directory and an absolute file name, 
         * returns a relative file name.
         * For example, if the current directory is C:\foo\bar and the  
         * filename C:\foo\whee\text.txt is given, getRelativeFilename will 
         * return ..\whee\text.txt.
         * @param currentDirectory The current directory.
         * @param absoluteFilename The absolute filename.
         * @return char* The relative path of the file.
         */
        static String getRelativeFilename(const String currentDirectory, const String absoluteFilename);

        /**
         * Searches all search strings in the source string and replace it with the replaceString.
         * @param source Reference to the source string.
         * @param searchString The search string.
         * @param replaceString The replace string.
         */
        static void stringFindAndReplace ( String& source, const String searchString, const String replaceString );

        /**
         * Splits a string by the given seperator string and push the 
         * parts in a vector.
         * @param String & text
         * @param String & separators
         * @param std::vector<String> & words
         */
        static void split ( const String& text, const String& separators, std::vector<String>& words );


    };
}

#endif // #define __COLLADABU_UTILS_H__
