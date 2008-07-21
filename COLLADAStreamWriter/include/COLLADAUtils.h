/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __COLLADASTREAMWRITER_UTIL_H__
#define __COLLADASTREAMWRITER_UTIL_H__

#include "COLLADAPrerequisites.h"

#include <sstream>
#include <fstream>

namespace COLLADA
{

	/** A class that holds some static COLLADA utility functions*/
	class Utils
    {

    public:


        static const String FILE_PROTOCOL;
        static const String FILE_DELIMITER;
        static const char FILE_DELIMITER_CHAR;


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

        /**
         * Returns the absolute path of the current absolute filename.
         * For example, if the absolute filename is C:\foo\bar\text.txt,
         * the function will return C:\foo\bar.
         * @param absoluteFilename The current absolute filename
         * @return COLLADA::String Returns the absolute path of the current absolute filename.
         */
        static String getAbsolutePathFromFile( const String& absoluteFilename );

        /**
         * Returns the filename from the absolute filename (= filename + path).
         * For example, if the absolute filename is C:\foo\bar\text.txt,
         * the function will return text.txt.
         * @param absoluteFilename The current absolute filename.
         * @return COLLADA::String The single filename without the path.
         */
        static String getFileNameFromFile( const String& absoluteFilename );

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
         * Copies the file from the source to the destination.
         * @param src The source file.
         * @param dest The destination file.
         */
        static bool copyFile( const String& src, const String& dest );
        static bool copyFile( std::ifstream& src, std::ofstream& dest );

    };

}

#endif // #define __COLLADASTREAMWRITER_UTIL_H__
