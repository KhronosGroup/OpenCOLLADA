/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAUtils.h"

#include <sstream>

namespace COLLADA
{


    const String Utils::FILE_PROTOCOL = "file:///";

	//---------------------------------------------------------------
    String Utils::checkNCName ( const String &ncName )
    {

        String result;
        result.reserve ( ncName.length() );

        // check if first character is an alpha character
        char firstCharacter = ncName[0];

        if ( isAsciiAlphaChar ( firstCharacter )  )
            result.append ( 1, firstCharacter );
        else
            result.append ( 1, '_' );

        //replace all spaces and colons by underlines
        for ( size_t i = 1; i<ncName.length(); ++i )
        {
            char character = ncName[i];

            if ( isIDChar ( character ) )
                result.append ( 1, character );
            else
                result.append ( 1, '_' );
        }

        return result;
    }

	//---------------------------------------------------------------
    String Utils::checkID ( const String &id )
    {
        return checkNCName ( id );
    }


	//---------------------------------------------------------------
    String Utils::UriEncode ( const String & sSrc )
    {
        const char DEC2HEX[16 + 1] = "0123456789ABCDEF";
        const unsigned char * pSrc = ( const unsigned char * ) sSrc.c_str();
        const int SRC_LEN = ( const int ) sSrc.length();
        unsigned char * const pStart = new unsigned char[SRC_LEN * 3];
        unsigned char * pEnd = pStart;
        const unsigned char * const SRC_END = pSrc + SRC_LEN;

        for ( ; pSrc < SRC_END; ++pSrc )
        {
            if ( *pSrc > 32 )
                *pEnd++ = ( *pSrc == 0x5c ) ? 0x2f : *pSrc;
            else
            {
                // escape this char
                *pEnd++ = '%';
                *pEnd++ = DEC2HEX[*pSrc >> 4];
                *pEnd++ = DEC2HEX[*pSrc & 0x0F];
            }
        }

        String sResult ( ( char * ) pStart, ( char * ) pEnd );

        delete [] pStart;
        return sResult;
    }

	//---------------------------------------------------------------
    String Utils::replaceDot ( const String &text )
    {
        std::stringstream stream;

        for ( size_t i = 0; i < text.length(); ++i )
        {
            if ( text[i] == '.' )
                stream << '_';
            else
                stream << text[i];
        }

        return stream.str();
    }



}