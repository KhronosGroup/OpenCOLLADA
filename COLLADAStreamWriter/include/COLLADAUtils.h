/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_UTIL_H__
#define __COLLADASTREAMWRITER_UTIL_H__

#include "COLLADAPrerequisites.h"

#include <sstream>

namespace COLLADA
{

    // A class that holds some static COLLADA utility functions

    class Utils
    {

    public:


        static const String FILE_PROTOCOL;


        /** Checks for a valid xs:NCName.
         1. string is one word
         2. begins with a letter or an _
        */
        static String checkNCName ( const String &ncName );

        /** Checks for a valid xs:ID.
        1. string is one word
        2. begins with a letter or an _
        */
        static String checkID ( const String &id );


        /** Checks if @c is an upper ASCII character*/
        static bool isUpperAsciiChar ( char c )
        {
            return ( c >= 'A' ) && ( c <= 'Z' ) ;
        }

        /** Checks if @c is a lower ASCII character*/
        static bool isLowerAsciiChar ( char c )
        {
            return ( c >= 'a' ) && ( c <= 'z' ) ;
        }

        /** Checks if @c is a ASCII character*/
        static bool isAsciiAlphaChar ( char c )
        {
            return isLowerAsciiChar ( c ) || isUpperAsciiChar ( c ) ;
        }

        /** Checks if @c is a digit*/
        static bool isDigit ( char c )
        {
            return ( c >= '0' ) && ( c <= '9' ) ;
        }

        /** Checks if @c is an xs:id character, but not alpha numeric*/
        static bool isIDExtraChar ( char c )
        {
            return ( c == '.' ) || ( c == '-' ) || ( c == '_' ) ;
        }

        /** Checks if @c is an xs:id character, but not alpha numeric*/
        static bool isIDChar ( char c )
        {
            return isAsciiAlphaChar ( c ) || isDigit ( c ) || isIDExtraChar ( c ) ;
        }

        static String UriEncode ( const String & sSrc );

        static String replaceDot ( const String &text );


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
