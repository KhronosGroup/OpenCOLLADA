/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADABaseUtils.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "COLLADABUStringUtils.h"
#include "COLLADABUException.h"
#include "ConvertUTF.h"

#include <cassert>


/* Maximum number of bytes a unicode character can have in UTF8 encoding*/
#define MAX_UTF8_CHAR_LENGTH 4


namespace COLLADABU
{


    //---------------------------------
	WideString StringUtils::checkNCName(const WideString &ncName, bool encodingColon)
	{
		WideString result;
		result.reserve(ncName.length());

		// check if first character is an alpha character
		const wchar_t& firstCharacter = ncName[0];

		if (isNameStartChar((firstCharacter), encodingColon))
			result.append(1, firstCharacter);
		else
			result.append(1, '_');

		//replace all spaces and colons by underlines
		for (size_t i = 1; i<ncName.length(); ++i)
		{
			const wchar_t& character = ncName[i];

			if (isNameChar(character, encodingColon))
				result.append(1, character);
			else
				result.append(1, '_');
		}

		return result;
	}

	//---------------------------------
	WideString StringUtils::checkNCNameWithUCS2Encoding(const WideString &ncName, bool encodingColon)
	{
		WideString result;
		result.reserve(ncName.length());

		// check if first character is an alpha character
		const wchar_t& firstCharacter = ncName[0];

		if (isNameStartChar((firstCharacter), encodingColon))
			result.append(1, firstCharacter);
		else
		{
			result.append(ucs2Encode((WideString(&firstCharacter, 1))));
		}

		for (size_t i = 1; i<ncName.length(); ++i)
		{
			const wchar_t& character = ncName[i];

			if (Prepass(ncName, i))
				result.append(ucs2Encode(WideString(&character, 1)));
			else
			{
				if (isNameChar(character, encodingColon))
					result.append(1, character);
				else
					result.append(ucs2Encode(WideString(&character, 1)));
			}
		}

		return result;
	}

	/*
	The underscore character does not need to be escaped unless it is followed by a character sequence
	that together with the underscore can be misinterpreted as an escape sequence when decoding the name.
	For example, Order_Details is not encoded, but Order_x0020_ is encoded as Order_x005f_x0020_
	*/
	//--------------------------------
	bool StringUtils::Prepass(const WideString &ncName, int i)
	{
		const wchar_t& character = ncName[i];

		if (ncName.length() >= i + 7)
		{
			const wchar_t& character2 = ncName[i + 1];
			const wchar_t& character3 = ncName[i + 2];
			const wchar_t& character4 = ncName[i + 3];
			const wchar_t& character5 = ncName[i + 4];
			const wchar_t& character6 = ncName[i + 5];
			const wchar_t& character7 = ncName[i + 6];

			if ((character == '_') &&
				(character2 == 'x') &&
				(isAsciiAlphaChar(character3) || isDigit(character3)) &&
				(isAsciiAlphaChar(character4) || isDigit(character4)) &&
				(isAsciiAlphaChar(character5) || isDigit(character5)) &&
				(isAsciiAlphaChar(character6) || isDigit(character6)) &&
				(character7 == '_'))
				return true;
			else
				return false;
		}
		else
			return false;
	}


    //---------------------------------
    WideString StringUtils::checkID ( const WideString &id )
    {
        return checkNCName ( id, false);
    }

	WideString StringUtils::checkIDWithUC2Encoding(const WideString &id)
	{
		return checkNCNameWithUCS2Encoding(id,false);
	}

    //---------------------------------
    String StringUtils::translateToXML ( const String &srcString )
    {
        String returnString; 

        for ( unsigned int i=0; i<srcString.length(); ++i )
        {
            switch ( srcString[i])
            {
//             case '\r':  
//                 returnString += String("&#13");
//                 break;
            case '<':  
                returnString += String("&lt;");
                break;
            case '>': 
                returnString += String("&gt;");
                break;
            case '&':  
                returnString += String("&amp;");
                break;
            case '"':  
                returnString += String("&quot;");
                break;
            case '\'':  
                returnString += String("&apos;");
                break;
            default :   
                returnString += srcString[i];
            }
        }

        return returnString;
    }


	//---------------------------------
	WideString StringUtils::translateToXML ( const WideString &srcString )
	{
		WideString returnString; 

		for ( unsigned int i=0; i<srcString.length(); ++i )
		{
			switch ( srcString[i])
			{
// 			case '\r':  
// 				returnString += L"&#13";
// 				break;
			case '<':  
				returnString += L"&lt;";
				break;
			case '>': 
				returnString += L"&gt;";
				break;
			case '&':  
				returnString += L"&amp;";
				break;
			case '"':  
				returnString += L"&quot;";
				break;
			case '\'':  
				returnString += L"&apos;";
				break;
			default :   
				returnString += srcString[i];
			}
		}

		return returnString;
	}



	/*
	The escape character is "_". Any XML name character that does not conform to the XML 1.0 spec (fourth edition) recommendation is escaped as _xHHHH_.
	The HHHH string stands for the four-digit hexadecimal UCS-2 code for the character in most significant bit first order.
	For example, the name Order Details is encoded as Order_x0020_Details.
	*/
	WideString StringUtils::ucs2Encode(const WideString  & sSrc)
	{
		const char DEC2HEX[16 + 1] = "0123456789ABCDEF";
		wchar_t * pSrc = (wchar_t *)sSrc.c_str();
		const int SRC_LEN = (const int)sSrc.length();
		wchar_t * const pStart = new wchar_t[SRC_LEN * 7];
		wchar_t * pEnd = pStart;
		wchar_t * const SRC_END = pSrc + SRC_LEN;

		for (; pSrc < SRC_END; ++pSrc)
		{
			*pEnd++ = '_';
			*pEnd++ = 'x';
			*pEnd++ = DEC2HEX[(*pSrc >> 12) & 0x0F];
			*pEnd++ = DEC2HEX[(*pSrc >> 8) & 0x0F];
			*pEnd++ = DEC2HEX[(*pSrc >> 4) & 0x0F];
			*pEnd++ = DEC2HEX[*pSrc & 0x0F];
			*pEnd++ = '_';
		}

		WideString sResult((wchar_t *)pStart, (wchar_t *)pEnd);

		delete[] pStart;
		return sResult;
	}


	String StringUtils::ucs2Encode(const String  & sSrc)
	{
		const char DEC2HEX[16 + 1] = "0123456789ABCDEF";
		const unsigned char * pSrc = (const unsigned char *)sSrc.c_str();
		const int SRC_LEN = (const int)sSrc.length();
		unsigned char * const pStart = new unsigned char[SRC_LEN * 7];
		unsigned char * pEnd = pStart;
		const unsigned char * const SRC_END = pSrc + SRC_LEN;

		for (; pSrc < SRC_END; ++pSrc)
		{
			*pEnd++ = '_';
			*pEnd++ = 'x';
			*pEnd++ = '0';
			*pEnd++ = '0';
			*pEnd++ = DEC2HEX[*pSrc >> 4];
			*pEnd++ = DEC2HEX[*pSrc & 0x0F];
			*pEnd++ = '_';
		}

		String sResult((char *)pStart, (char *)pEnd);

		delete[] pStart;
		return sResult;
	}


    //---------------------------------
    String StringUtils::uriEncode ( const String  & sSrc )
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

    //---------------------------------
    String StringUtils::replaceDot ( const String& text )
    {
        std::stringstream stream;

        for ( size_t i = 0; i < text.length(); ++i )
        {
            if ( text[i] == '.' )
                stream << '_';
            else
                stream << text[i];
        }

        return String(stream.str());
    }



	//--------------------------------
	bool StringUtils::equalsIgnoreCase ( const WideString& s1, const WideString& s2 ) 
	{
		if ( s1.length() != s2.length() )
			return false;

		WideString::const_iterator it1=s1.begin();
		WideString::const_iterator it2=s2.begin();

		// has the end of at least one of the strings been reached?
		while ( (it1!=s1.end()) && (it2!=s2.end()) ) 
		{ 
			if(::toupper(*it1) != ::toupper(*it2)) //letters differ?
				return false; 
			// proceed to the next character in each string
			++it1;
			++it2;
		}
		return true;
	}

	bool StringUtils::isNameStartCharExcludingColon(wchar_t c)
	{
		return ((c >= 'A' && c <= 'Z')
			|| (c == '_')
			|| (c >= 'a' && c <= 'z')
			|| (c >= 0xC0 && c <= 0xD6)
			|| (c >= 0xD8 && c <= 0xF6)
			|| (c >= 0xF8 && c <= 0x2FF)
			|| (c >= 0x370 && c <= 0x37D)
			|| (c >= 0x37F && c <= 0x1FFF)
			|| (c >= 0x200C && c <= 0x200D)
			|| (c >= 0x2070 && c <= 0x218F)
			|| (c >= 0x2C00 && c <= 0x2FEF)
			|| (c >= 0x3001 && c <= 0xD7FF)
			|| (c >= 0xF900 && c <= 0xFDCF)
			|| (c >= 0xFDF0 && c <= 0xFFFD)
			|| (c >= 0x10000 && c <= 0xEFFFF));
	}

	//--------------------------------
	bool StringUtils::isNameStartChar(wchar_t c, bool encodingColon)
	{
		// The Namespaces in XML Recommendation [XML Names] assigns a meaning to names containing colon characters.
		// Therefore, authors should not use the colon in XML names except for namespace purposes, but XML processors must accept the colon as a name character.
					
		if (!encodingColon)
		{
			return ((c == ':') || isNameStartCharExcludingColon(c));
		}
		else
		{
			return (isNameStartCharExcludingColon(c));
		}
	}


	//--------------------------------
	bool StringUtils::isNameChar(wchar_t c, bool encodingColon)
	{
		return	isNameStartChar( c, encodingColon )	
			||	( c == '-' ) 
			||  ( c == '.' )
			||  ( c >= '0' && c <= '9' )
			||  ( c == 0xB7 )
			||  ( c >= 0x0300 && c <= 0x036F ) 
			||	( c >= 0x203F && c <= 0x2040 );
	}

	//--------------------------------
	WideString StringUtils::utf8String2WideString( const String& utf8String )
	{
		size_t widesize = utf8String.length();
		WideString returnWideString;

		if ( sizeof( wchar_t ) == sizeof(UTF16) )
		{
			returnWideString.resize( widesize + 1, L'\0' );
			const UTF8* sourcestart = reinterpret_cast<const UTF8*>( utf8String.c_str() );
			const UTF8* sourceend = sourcestart + widesize;
			UTF16* targetstart = reinterpret_cast<UTF16*>( &((returnWideString)[ 0 ]) );
			UTF16* thisFirstWChar = targetstart;
			UTF16* targetend = targetstart + widesize;
			ConversionResult res = ConvertUTF8toUTF16( &sourcestart, sourceend, &targetstart, targetend, strictConversion );
			returnWideString.resize(targetstart - thisFirstWChar);

			if ( res != conversionOK )
			{
				throw Exception(Exception::ERROR_UTF8_2_WIDE, String("Could not convert from UTF8 to wide string."));
			}

			*targetstart = 0;
		}
		else if ( sizeof( wchar_t ) == sizeof(UTF32) )
		{
			returnWideString.resize( widesize + 1, L'\0' );
			const UTF8* sourcestart = reinterpret_cast<const UTF8*>( utf8String.c_str() );
			const UTF8* sourceend = sourcestart + widesize;
			UTF32* targetstart = reinterpret_cast<UTF32*>( &((returnWideString)[ 0 ]) );
			UTF32* thisFirstWChar = targetstart;
			UTF32* targetend = targetstart + widesize;
			ConversionResult res = ConvertUTF8toUTF32( &sourcestart, sourceend, &targetstart, targetend, strictConversion );
			returnWideString.resize(targetstart - thisFirstWChar);

			if ( res != conversionOK )
			{
				throw Exception(Exception::ERROR_UTF8_2_WIDE, String("Could not convert from UTF8 to wide string."));
			}

			*targetstart = 0;
		}
		else
		{
			COLLADABU_ASSERT(false);
		}
		return returnWideString;
	}

	//--------------------------------
	String StringUtils::wideString2utf8String( const WideString& wideString )
	{
		size_t widesize = wideString.length();
		String returnString;

		if ( sizeof( wchar_t ) == sizeof(UTF16) )
		{
			size_t utf8size = MAX_UTF8_CHAR_LENGTH * widesize + 1;
			returnString.resize( utf8size, '\0' );
			const UTF16* sourcestart = reinterpret_cast<const UTF16*>( wideString.c_str() );
			const UTF16* sourceend = sourcestart + widesize;
			UTF8* targetstart = reinterpret_cast<UTF8*>( &((returnString)[ 0 ]) );
			UTF8* thisFirstWChar = targetstart;
			UTF8* targetend = targetstart + utf8size;
			ConversionResult res = ConvertUTF16toUTF8( &sourcestart, sourceend, &targetstart, targetend, strictConversion );

			if ( res != conversionOK )
			{
				throw Exception(Exception::ERROR_WIDE_2_UTF8, String("Could not convert from wide string to UTF8."));
			}

			returnString.resize(targetstart - thisFirstWChar);
		}
		else if ( sizeof( wchar_t ) == sizeof(UTF32) )
		{
			size_t utf8size = MAX_UTF8_CHAR_LENGTH * widesize + 1;
			returnString.resize( utf8size, '\0' );
			const UTF32* sourcestart = reinterpret_cast<const UTF32*>( wideString.c_str() );
			const UTF32* sourceend = sourcestart + widesize;
			UTF8* targetstart = reinterpret_cast<UTF8*>( &((returnString)[ 0 ]) );
			UTF8* thisFirstWChar = targetstart;
			UTF8* targetend = targetstart + utf8size;
			ConversionResult res = ConvertUTF32toUTF8( &sourcestart, sourceend, &targetstart, targetend, strictConversion );

			if ( res != conversionOK )
			{
				throw Exception(Exception::ERROR_WIDE_2_UTF8, String("Could not convert from wide string to UTF8."));
			}

			returnString.resize(targetstart - thisFirstWChar);
		}
		else
		{
			COLLADABU_ASSERT(false);
		}
		return returnString;
	}

	//------------------------------
	char StringUtils::toUpperASCIIChar( char c )
	{
		if ( isLowerAsciiChar(c) )
		{
			return c + 'A' - 'a';
		}
		return c;
	}




}
