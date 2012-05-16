/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "GeneratedSaxParserUtils.h"
#include <math.h>
#include <memory>
#include <string.h>
#include <limits>

namespace GeneratedSaxParser
{

	//--------------------------------------------------------------------
	StringHash Utils::calculateStringHash( const ParserChar* text, size_t textLength )
	{
		StringHash h = 0;
		StringHash g;

		while (textLength--) {
			h = (h << 4) + *text++;
			if ((g = (h & 0xf0000000)) != 0)
				h ^= g >> 24;
			h &= ~g;
		}
		return h;
	}

    //--------------------------------------------------------------------
    StringHash Utils::calculateStringHash( const ParserChar** text, const ParserChar* bufferEnd, bool& failed )
    {
        failed = false;
        StringHash h = 0;
        StringHash g;
        const ParserChar* bufferPos = *text;

        if ( !bufferPos )
        {
            failed = true;
            *text = bufferPos;
            return 0;
        }

        if ( bufferPos == bufferEnd )
        {
            failed = true;
            *text = bufferPos;
            return 0;
        }
        // Skip leading white spaces
        while ( isWhiteSpace(*bufferPos) )
        {
            ++bufferPos;
            if ( bufferPos == bufferEnd )
            {
                failed = true;
                *text = bufferPos;
                return 0;
            }
        }

        while ( bufferPos != bufferEnd ) {
            if ( isWhiteSpace(*bufferPos) )
            {
                *text = bufferPos;
                return h;
            }
            h = (h << 4) + *bufferPos++;
            if ((g = (h & 0xf0000000)) != 0)
                h ^= g >> 24;
            h &= ~g;
        }
        *text = bufferPos;
        return h;
    }

	//--------------------------------------------------------------------
	StringHash Utils::calculateStringHash( StringHash prefixHash, const char* separator, const ParserChar* text )
	{
		StringHash h = prefixHash;
		StringHash g;
		const char* separatorPos = separator;

		while (*separatorPos != 0) {
			h = (h << 4) + *separatorPos++;
			if ((g = (h & 0xf0000000)) != 0)
				h ^= g >> 24;
			h &= ~g;
		}

		const ParserChar* textPos = text;
		while (*textPos != 0) {
			h = (h << 4) + *textPos++;
			if ((g = (h & 0xf0000000)) != 0)
				h ^= g >> 24;
			h &= ~g;
		}
		return h;
	}


	//--------------------------------------------------------------------
	StringHash Utils::calculateStringHash( const ParserChar* text )
	{
		StringHash h = 0;
		StringHash g;
		const ParserChar* pos = text;

		while (*pos != 0) {
			h = (h << 4) + *pos++;
			if ((g = (h & 0xf0000000)) != 0)
				h ^= g >> 24;
			h &= ~g;
		}
		return h;
	}

    //--------------------------------------------------------------------
    StringHashPair Utils::calculateStringHashWithNamespace( const ParserChar* text )
    {
        StringHash h = 0;
        StringHash g;
        const ParserChar* pos = text;
        StringHashPair pair;
        pair.first = 0;

        while (*pos != 0) {
            if (*pos == ':' && pos[1] != 0) {
                pair.first = h;
                h = 0;
                pos++;
            }
            h = (h << 4) + *pos++;
            if ((g = (h & 0xf0000000)) != 0)
                h ^= g >> 24;
            h &= ~g;
        }
        pair.second = h;
        return pair;
    }

    //--------------------------------------------------------------------
	GeneratedSaxParser::StringHash Utils::calculateStringHash( const ParserChar* text, bool& failed )
	{
		failed = false;
		return calculateStringHash(text);
	}


    //--------------------------------------------------------------------
    bool Utils::isWhiteSpaceOnly(const ParserChar* buffer, size_t length)
    {
        for (size_t i=0; i<length; ++i)
        {
            if ( !isWhiteSpace(buffer[i]) )
            {
                return false;
            }
        }
        return true;
    }

    //--------------------------------------------------------------------
    void Utils::fillErrorMsg(ParserChar* dest, const ParserChar* src, size_t maxLen)
    {
        size_t bufferLength = 0;
        while (src[bufferLength])
            ++bufferLength;
        size_t length = std::min(maxLen, bufferLength);
        memcpy(dest, src, length);
        dest[length] = '\0';
    }

    //--------------------------------------------------------------------
	template<class FloatingPointType>
	FloatingPointType Utils::toFloatingPoint(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
	{
		const ParserChar* s = *buffer;
		if ( !s )
		{
			failed = true;
			return 0.0f;
		}

		if ( s == bufferEnd )
		{
			failed = true;
			*buffer = bufferEnd;
			return 0.0f;
		}

		// Skip leading white spaces
		while ( isWhiteSpace(*s) )
		{
			++s;
			if ( s == bufferEnd )
			{
				failed = true;
				*buffer = bufferEnd;
				return 0.0f;
			}
		}

        // check for 'NaN'
        if ( s[0] == 'N' && s[1] == 'a' && s[2] == 'N' )
        {
            if ( &s[3] == bufferEnd || isWhiteSpace(s[3]) )
            {
                *buffer = s + 3;
                failed = false;
                return std::numeric_limits<FloatingPointType>::quiet_NaN();
            }
            else
            {
                *buffer = s;
                failed = true;
                return 0;
            }
        }

        double value = 0.0;
		FloatingPointType sign = 1.0;
		if (*s == '-')
		{
			++s;
			sign = -1.0;
		}
		else if (*s == '+')
		{
			++s;
		}

        // check for 'INF', '+INF', '-INF'
        if ( s[0] == 'I' && s[1] == 'N' && s[2] == 'F' )
        {
            if ( &s[3] == bufferEnd || isWhiteSpace(s[3]) )
            {
                *buffer = s + 3;
                failed = false;
                return sign * std::numeric_limits<FloatingPointType>::infinity();
            }
            else
            {
                *buffer = s;
                failed = true;
                return 0;
            }
        }

		bool charBeforeDecimalPoint = false;
		while ( true )
		{
			if ( s == bufferEnd )
			{
				if (charBeforeDecimalPoint)
				{
					failed = false;
					*buffer = s;
					return sign * (FloatingPointType)value;
				}
				else
				{
					failed = true;
					*buffer = s;
					return 0.0f;
				}
			}

			if ( isdigit(*s) )
			{
				value = value * 10 + (*s - '0');
				charBeforeDecimalPoint = true;
			}
			else
				break;
			++s;
		}

		if ( (*s=='.') )
			++s;

		int power = 0;
		bool charAfterDecimalPoint = false;
		while ( true )
		{
			if ( s == bufferEnd )
			{
				if ( charBeforeDecimalPoint || charAfterDecimalPoint )
				{
					failed = false;
					*buffer = s;
					return (FloatingPointType)value * pow((FloatingPointType)10, (FloatingPointType)power) * sign;
				}
				else
				{
					failed = true;
					*buffer = s;
					return 0.0f;
				}
			}

			if ( isdigit(*s) )
			{
				value = value * 10 + (*s - '0');
				--power;
				charAfterDecimalPoint = true;
			}
			else
				break;
			++s;
		}

		if ( !charBeforeDecimalPoint && !charAfterDecimalPoint )
		{
			failed = true;
			*buffer = s;
			return 0.0f;
		}

		if ( (*s == 'e') || (*s == 'E') )
		{
			++s;
			bool intFailed = false;
			sint32 exponent = toSint32(&s, bufferEnd, intFailed);
			if ( intFailed )
			{
				failed = true;
				*buffer = s;
				return 0.0f;
			}
			power += exponent;
		}

		failed = false;
		*buffer = s;
		return (FloatingPointType)value * pow((FloatingPointType)10, (FloatingPointType)power) * sign;
	}



	//--------------------------------------------------------------------
	template<class FloatingPointType>
	FloatingPointType Utils::toFloatingPoint(const ParserChar* buffer, bool& failed)
	{
		const ParserChar* s = buffer;
		if ( !s )
		{
			failed = true;
			return 0.0f;
		}

		if ( *s == '\0' )
		{
			failed = true;
			return 0.0f;
		}

		// Skip leading white spaces
		while ( isWhiteSpace(*s) )
		{
			++s;
			if ( *s == '\0' )
			{
				failed = true;
				return 0.0f;
			}
		}

        // check for 'NaN'
        if ( s[0] == 'N' && s[1] == 'a' && s[2] == 'N' )
        {
            if ( s[3] == '\0' || isWhiteSpace(s[3]) )
            {
                failed = false;
                return std::numeric_limits<FloatingPointType>::quiet_NaN();
            }
            else
            {
                failed = true;
                return 0;
            }
        }

        double value = 0.0;
		FloatingPointType sign = 1.0;
		if (*s == '-')
		{
			++s;
			sign = -1.0;
		}
		else if (*s == '+')
		{
			++s;
		}

        // check for 'INF', '+INF', '-INF'
        if ( s[0] == 'I' && s[1] == 'N' && s[2] == 'F' )
        {
            if ( s[3] == '\0' || isWhiteSpace(s[3]) )
            {
                failed = false;
                return sign * std::numeric_limits<FloatingPointType>::infinity();
            }
            else
            {
                failed = true;
                return 0;
            }
        }

		bool charBeforeDecimalPoint = false;
		while ( true )
		{
			if ( *s == '\0' )
			{
				failed = false;
				return (FloatingPointType)value * sign;
			}

			if ( isdigit(*s) )
			{
				value = value * 10 + (*s - '0');
				charBeforeDecimalPoint = true;
			}
			else
				break;
			++s;
		}

		if ( (*s=='.') )
			++s;

		int power = 0;
		bool charAfterDecimalPoint = false;
		while ( true )
		{
			if ( *s == '\0' )
			{
				if ( !charBeforeDecimalPoint && !charAfterDecimalPoint )
				{
					failed = true;
					return 0.0f;
				}
				else
				{
					failed = false;
					return (FloatingPointType)value * pow((FloatingPointType)10, (FloatingPointType)power) * sign;
				}
			}

			if ( isdigit(*s) )
			{
				value = value * 10 + (*s - '0');
				--power;
				charAfterDecimalPoint = true;
			}
			else
				break;
			++s;
		}

		if ( !charBeforeDecimalPoint && !charAfterDecimalPoint )
		{
			failed = true;
			return 0.0f;
		}

		if ( (*s == 'e') || (*s == 'E') )
		{
			++s;
			bool intFailed = false;
			sint32 exponent = toSint32(s, intFailed);
			if ( intFailed )
			{
				failed = true;
				return 0.0f;
			}
			power += exponent;
		}

		failed = false;
		return (FloatingPointType)value * pow((FloatingPointType)10, (FloatingPointType)power) * sign;
	}


    //--------------------------------------------------------------------
    template<class FloatingPointType>
    FloatingPointType Utils::toFloatingPoint(const ParserChar** buffer, bool& failed)
    {
        const ParserChar* s = *buffer;
        if ( !s )
        {
            failed = true;
            return 0.0f;
        }

        if ( *s == '\0' )
        {
            failed = true;
            *buffer = s;
            return 0.0f;
        }

        // Skip leading white spaces
        while ( isWhiteSpace(*s) )
        {
            ++s;
            if ( *s == '\0' )
            {
                failed = true;
                *buffer = s;
                return 0.0f;
            }
        }

        // check for 'NaN'
        if ( s[0] == 'N' && s[1] == 'a' && s[2] == 'N' )
        {
            if ( s[3] == '\0' || isWhiteSpace(s[3]) )
            {
                *buffer = s + 3;
                failed = false;
                return std::numeric_limits<FloatingPointType>::quiet_NaN();
            }
            else
            {
                *buffer = s;
                failed = true;
                return 0;
            }
        }

        double value = 0.0;
        FloatingPointType sign = 1.0;
        if (*s == '-')
        {
            ++s;
            sign = -1.0;
        }
        else if (*s == '+')
        {
            ++s;
        }

        // check for 'INF', '+INF', '-INF'
        if ( s[0] == 'I' && s[1] == 'N' && s[2] == 'F' )
        {
            if ( s[3] == '\0' || isWhiteSpace(s[3]) )
            {
                *buffer = s + 3;
                failed = false;
                return sign * std::numeric_limits<FloatingPointType>::infinity();
            }
            else
            {
                *buffer = s;
                failed = true;
                return 0;
            }
        }

        bool charBeforeDecimalPoint = false;
        while ( true )
        {
            if ( *s == '\0' )
            {
                if (charBeforeDecimalPoint)
                {
                    failed = false;
                    *buffer = s;
                    return sign * (FloatingPointType)value;
                }
                else
                {
                    failed = true;
                    *buffer = s;
                    return 0.0f;
                }
            }

            if ( isdigit(*s) )
            {
                value = value * 10 + (*s - '0');
                charBeforeDecimalPoint = true;
            }
            else
                break;
            ++s;
        }

        if ( (*s=='.') )
            ++s;

        int power = 0;
        bool charAfterDecimalPoint = false;
        while ( true )
        {
            if ( *s == '\0' )
            {
                if ( charBeforeDecimalPoint || charAfterDecimalPoint )
                {
                    failed = false;
                    *buffer = s;
                    return (FloatingPointType)value * pow((FloatingPointType)10, (FloatingPointType)power) * sign;
                }
                else
                {
                    failed = true;
                    *buffer = s;
                    return 0.0f;
                }
            }

            if ( isdigit(*s) )
            {
                value = value * 10 + (*s - '0');
                --power;
                charAfterDecimalPoint = true;
            }
            else
                break;
            ++s;
        }

        if ( !charBeforeDecimalPoint && !charAfterDecimalPoint )
        {
            failed = true;
            *buffer = s;
            return 0.0f;
        }

        if ( (*s == 'e') || (*s == 'E') )
        {
            ++s;
            bool intFailed = false;
            sint32 exponent = toSint32(&s, intFailed);
            if ( intFailed )
            {
                failed = true;
                *buffer = s;
                return 0.0f;
            }
            power += exponent;
        }

        failed = false;
        *buffer = s;
        return (FloatingPointType)value * pow((FloatingPointType)10, (FloatingPointType)power) * sign;
    }


	//--------------------------------------------------------------------
	float Utils::toFloat( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toFloatingPoint<float>(buffer, bufferEnd, failed);
	}


	//--------------------------------------------------------------------
	float Utils::toFloat( const ParserChar* buffer, bool& failed )
	{
		return toFloatingPoint<float>(buffer, failed);
	}


    //--------------------------------------------------------------------
    float Utils::toFloat( const ParserChar** buffer, bool& failed )
    {
        return toFloatingPoint<float>(buffer, failed);
    }


	//--------------------------------------------------------------------
	double Utils::toDouble( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toFloatingPoint<double>(buffer, bufferEnd, failed);
	}


	//--------------------------------------------------------------------
	double Utils::toDouble( const ParserChar* buffer, bool& failed )
	{
		return toFloatingPoint<double>(buffer, failed);
	}


    //--------------------------------------------------------------------
    double Utils::toDouble( const ParserChar** buffer, bool& failed )
    {
        return toFloatingPoint<double>(buffer, failed);
    }

    //--------------------------------------------------------------------
    ParserString Utils::toStringListItem(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
    {
        ParserString value;

        const ParserChar* s = *buffer;
        if ( !s )
        {
            failed = true;
            return value;
        }

        if ( s == bufferEnd )
        {
            failed = true;
            *buffer = bufferEnd;
            return value;
        }

        // Skip leading white spaces
        while ( isWhiteSpace(*s) )
        {
            ++s;
            if ( s == bufferEnd )
            {
                failed = true;
                *buffer = bufferEnd;
                return value;
            }
        }

        bool characterFound = false;
        while (true)
        {
            if ( s == bufferEnd )
            {
                if (characterFound)
                {
                    failed = false;
                    *buffer = s;
                    return value;
                }
                else
                {
                    failed = true;
                    *buffer = s;
                    value.str = 0;
                    value.length = 0;
                    return value;
                }
            }

            if ( !isWhiteSpace(*s) )
            {
                if (!characterFound)
                {
                    value.str = s;
                    characterFound = true;
                }
                value.length++;
            }
            else
                break;
            ++s;
        }
        if ( characterFound )
        {
            *buffer = s;
            failed = false;
            return value;
        }
        else
        {
            failed = true;
            *buffer = s;
            value.str = 0;
            value.length = 0;
            return value;
        }
    }

    //--------------------------------------------------------------------
    ParserString Utils::toStringListItem(const ParserChar** buffer, bool& failed)
    {
        ParserString value;

        const ParserChar* s = *buffer;
        if ( !s )
        {
            failed = true;
            return value;
        }

        if ( *s == '\0' )
        {
            failed = true;
            *buffer = s;
            return value;
        }

        // Skip leading white spaces
        while ( isWhiteSpace(*s) )
        {
            ++s;
            if ( *s == '\0' )
            {
                failed = true;
                *buffer = s;
                return value;
            }
        }

        bool characterFound = false;
        while (true)
        {
            if ( *s == '\0' )
            {
                if (characterFound)
                {
                    failed = false;
                    *buffer = s;
                    return value;
                }
                else
                {
                    failed = true;
                    *buffer = s;
                    value.str = 0;
                    value.length = 0;
                    return value;
                }
            }

            if ( !isWhiteSpace(*s) )
            {
                if (!characterFound)
                {
                    value.str = s;
                    characterFound = true;
                }
                value.length++;
            }
            else
                break;
            ++s;
        }
        if ( characterFound )
        {
            *buffer = s;
            failed = false;
            return value;
        }
        else
        {
            failed = true;
            *buffer = s;
            value.str = 0;
            value.length = 0;
            return value;
        }
    }


    //--------------------------------------------------------------------
    COLLADABU::URI Utils::toURI(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
    {
        if ( *buffer == bufferEnd )
        {
            failed = false;
            return COLLADABU::URI(0);
        }
        const ParserString& string = toStringListItem(buffer, bufferEnd, failed);
        return COLLADABU::URI(string.str, string.length);
    }

    //--------------------------------------------------------------------
    COLLADABU::URI Utils::toURI(const ParserChar** buffer, bool& failed)
    {
        if ( **buffer == '\0' )
        {
            failed = false;
            return COLLADABU::URI(0);
        }
        const ParserString& string = toStringListItem(buffer, failed);
        return COLLADABU::URI(string.str, string.length);
    }


    //--------------------------------------------------------------------
	template<class IntegerType, bool signedInteger>
	IntegerType Utils::toInteger(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
	{
		const ParserChar* s = *buffer;
		if ( !s )
		{
			failed = true;
			return 0;
		}

		if ( s == bufferEnd )
		{
			failed = true;
			*buffer = bufferEnd;
			return 0;
		}

		// Skip leading white spaces
		while ( isWhiteSpace(*s) )
		{
			++s;
			if ( s == bufferEnd )
			{
				failed = true;
				*buffer = bufferEnd;
				return 0;
			}
		}

		IntegerType value = 0;
		IntegerType sign = 1;
		if ( signedInteger )
		{
			if (*s == '-')
			{
				++s;
				sign = -1;
			}
			else if (*s == '+')
			{
				++s;
			}
		}

		bool digitFound = false;
		while (true)
		{
			if ( s == bufferEnd )
			{
				if (digitFound)
				{
					failed = false;
					*buffer = s;
					if ( signedInteger )
						return value * sign;
					else
						return value;
				}
				else
				{
					failed = true;
					*buffer = s;
					return 0;
				}
			}

			if ( isdigit(*s) )
			{
				value = value * 10 + (*s - '0');
				digitFound = true;
			}
			else
				break;
			++s;
		}
		if ( digitFound )
		{
			*buffer = s;
			failed = false;
			if ( signedInteger )
				return value * sign;
			else
				return value;
		}
		else
		{
			failed = true;
			*buffer = s;
			return 0;
		}
	}


	//--------------------------------------------------------------------
	template<class IntegerType, bool signedInteger>
	IntegerType Utils::toInteger(const ParserChar* buffer, bool& failed)
	{
		const ParserChar* s = buffer;
		if ( !s )
		{
			failed = true;
			return 0;
		}

		if ( *s == '\0' )
		{
			failed = true;
			return 0;
		}

		// Skip leading white spaces
		while ( isWhiteSpace(*s) )
		{
			++s;
			if ( *s == '\0' )
			{
				failed = true;
				return 0;
			}
		}

		IntegerType value = 0;
		IntegerType sign = 1;
		if ( signedInteger )
		{
			if (*s == '-')
			{
				++s;
				sign = -1;
			}
			else if (*s == '+')
			{
				++s;
			}
		}

		bool digitFound = false;
		while (true)
		{
			if ( *s == '\0' )
			{
				failed = false;
				return value * sign;
			}

			if ( isdigit(*s) )
			{
				value = value * 10 + (*s - '0');
				digitFound = true;
			}
			else
			{
				break;
			}
			++s;
		}
		if ( digitFound )
		{
			failed = false;
			if ( signedInteger )
				return value * sign;
			else
				return value;
		}
		else
		{
			failed = true;
			return 0;
		}
	}

    //--------------------------------------------------------------------
    template<class IntegerType, bool signedInteger>
    IntegerType Utils::toInteger(const ParserChar** buffer, bool& failed)
    {
        const ParserChar* s = *buffer;
        if ( !s )
        {
            failed = true;
            return 0;
        }

        if ( *s == '\0' )
        {
            failed = true;
            *buffer = s;
            return 0;
        }

        // Skip leading white spaces
        while ( isWhiteSpace(*s) )
        {
            ++s;
            if ( *s == '\0' )
            {
                failed = true;
                *buffer = s;
                return 0;
            }
        }

        IntegerType value = 0;
        IntegerType sign = 1;
        if ( signedInteger )
        {
            if (*s == '-')
            {
                ++s;
                sign = -1;
            }
            else if (*s == '+')
            {
                ++s;
            }
        }

        bool digitFound = false;
        while (true)
        {
            if ( *s == '\0' )
            {
                if (digitFound)
                {
                    failed = false;
                    *buffer = s;
                    if ( signedInteger )
                        return value * sign;
                    else
                        return value;
                }
                else
                {
                    failed = true;
                    *buffer = s;
                    return 0;
                }
            }

            if ( isdigit(*s) )
            {
                value = value * 10 + (*s - '0');
                digitFound = true;
            }
            else
                break;
            ++s;
        }
        if ( digitFound )
        {
            *buffer = s;
            failed = false;
            if ( signedInteger )
                return value * sign;
            else
                return value;
        }
        else
        {
            failed = true;
            *buffer = s;
            return 0;
        }
    }

	//--------------------------------------------------------------------
	sint8 Utils::toSint8( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<sint8, true>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	sint8 Utils::toSint8( const ParserChar* buffer, bool& failed )
	{
		return toInteger<sint8, true>(buffer, failed);
	}

    //--------------------------------------------------------------------
    sint8 Utils::toSint8( const ParserChar** buffer, bool& failed )
    {
        return toInteger<sint8, true>(buffer, failed);
    }

	//--------------------------------------------------------------------
	uint8 Utils::toUint8( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<uint8, false>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	uint8 Utils::toUint8( const ParserChar* buffer, bool& failed )
	{
		return toInteger<uint8, false>(buffer, failed);
	}

    //--------------------------------------------------------------------
    uint8 Utils::toUint8( const ParserChar** buffer, bool& failed )
    {
        return toInteger<uint8, false>(buffer, failed);
    }

	//--------------------------------------------------------------------
	sint16 Utils::toSint16( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<sint16, true>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	sint16 Utils::toSint16( const ParserChar* buffer, bool& failed )
	{
		return toInteger<sint16, true>(buffer, failed);
	}

    //--------------------------------------------------------------------
    sint16 Utils::toSint16( const ParserChar** buffer, bool& failed )
    {
        return toInteger<sint16, true>(buffer, failed);
    }

	//--------------------------------------------------------------------
	uint16 Utils::toUint16( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<uint16, false>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	uint16 Utils::toUint16( const ParserChar* buffer, bool& failed )
	{
		return toInteger<uint16, false>(buffer, failed);
	}

    //--------------------------------------------------------------------
    uint16 Utils::toUint16( const ParserChar** buffer, bool& failed )
    {
        return toInteger<uint16, false>(buffer, failed);
    }

	//--------------------------------------------------------------------
	sint32 Utils::toSint32( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<sint32, true>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	sint32 Utils::toSint32( const ParserChar* buffer, bool& failed )
	{
		return toInteger<sint32, true>(buffer, failed);
	}

    //--------------------------------------------------------------------
    sint32 Utils::toSint32( const ParserChar** buffer, bool& failed )
    {
        return toInteger<sint32, true>(buffer, failed);
    }

    //--------------------------------------------------------------------
    uint32 Utils::toUint32( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
    {
        return toInteger<uint32, false>(buffer, bufferEnd, failed);
    }

    //--------------------------------------------------------------------
    uint32 Utils::toUint32( const ParserChar* buffer, bool& failed )
    {
        return toInteger<uint32, false>(buffer, failed);
    }

    //--------------------------------------------------------------------
    uint32 Utils::toUint32( const ParserChar** buffer, bool& failed )
    {
        return toInteger<uint32, false>(buffer, failed);
    }

    //--------------------------------------------------------------------
    sint64 Utils::toSint64( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
    {
        return toInteger<sint64, true>(buffer, bufferEnd, failed);
    }

    //--------------------------------------------------------------------
    sint64 Utils::toSint64( const ParserChar* buffer, bool& failed )
    {
        return toInteger<sint64, true>(buffer, failed);
    }

    //--------------------------------------------------------------------
    sint64 Utils::toSint64( const ParserChar** buffer, bool& failed )
    {
        return toInteger<sint64, true>(buffer, failed);
    }

    //--------------------------------------------------------------------
    uint64 Utils::toUint64( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
    {
        return toInteger<uint64, false>(buffer, bufferEnd, failed);
    }

    //--------------------------------------------------------------------
    uint64 Utils::toUint64( const ParserChar* buffer, bool& failed )
    {
        return toInteger<uint64, false>(buffer, failed);
    }

    //--------------------------------------------------------------------
    uint64 Utils::toUint64( const ParserChar** buffer, bool& failed )
    {
        return toInteger<uint64, false>(buffer, failed);
    }

	//--------------------------------------------------------------------
	bool Utils::toBool( const ParserChar* buffer, bool& failed  )
	{
		if ( (strcmp((char*)buffer, "1") == 0) || (strcmp((char*)buffer, "true") == 0) )
		{
			failed = false;
			return true;
		}

		if ( (strcmp((char*)buffer, "0") == 0) || (strcmp((char*)buffer, "false") == 0) )
		{
			failed = false;
			return false;
		}

		failed = true;
		return false;
	}

	//--------------------------------------------------------------------
	bool Utils::toBool( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed  )
	{
		const ParserChar* s = *buffer;
		if ( s == bufferEnd )
		{
			failed = true;
			return true;
		}

		// Skip leading white spaces
		while ( isWhiteSpace(*s) )
		{
			++s;
			if ( s == bufferEnd )
			{
				failed = true;
				*buffer = bufferEnd;
				return true;
			}
		}


		if ( *s == '1' )
		{
			failed = false;
			*buffer = s + 1;
			return true;
		}
		else if ( *s == '0' )
		{
			failed = false;
			*buffer = s + 1;
			return false;
		}
		else if ( *s == 't' )
		{
			s++;
			static const char* trueString = "rue";
			const ParserChar* c = (const ParserChar* )trueString;
			while (true)
			{
				if ( *c == '\0' )
				{
					failed = false;
					*buffer = s;
					return true;
				}
				if ( s == bufferEnd )
				{
					failed = true;
					*buffer = bufferEnd;
					return true;
				}
				if ( *s == *c)
				{
					s++;
					c++;
				}
				else
				{
					failed = true;
					*buffer = s;
					return true;
				}
			}
		}
		else if ( *s == 'f' )
		{
			s++;
			static const char* trueString = "alse";
			const ParserChar* c = (const ParserChar* )trueString;
			while (true)
			{
				if ( *c == '\0' )
				{
					failed = false;
					*buffer = s;
					return false;
				}
				if ( s == bufferEnd )
				{
					failed = true;
					*buffer = bufferEnd;
					return true;
				}
				if ( *s == *c)
				{
					s++;
					c++;
				}
				else
				{
					failed = true;
					*buffer = s;
					return true;
				}
			}
		}

		failed = true;
		return false;
	}

    //--------------------------------------------------------------------
    bool Utils::toBool( const ParserChar** buffer, bool& failed  )
    {
        const ParserChar* s = *buffer;
        if ( *s == '\0' )
        {
            failed = true;
            return true;
        }

        // Skip leading white spaces
        while ( isWhiteSpace(*s) )
        {
            ++s;
            if ( *s == '\0' )
            {
                failed = true;
                *buffer = s;
                return true;
            }
        }


        if ( *s == '1' )
        {
            failed = false;
            *buffer = s + 1;
            return true;
        }
        else if ( *s == '0' )
        {
            failed = false;
            *buffer = s + 1;
            return false;
        }
        else if ( *s == 't' )
        {
            s++;
            static const char* trueString = "rue";
            const ParserChar* c = (const ParserChar* )trueString;
            while (true)
            {
                if ( *c == '\0' )
                {
                    failed = false;
                    *buffer = s;
                    return true;
                }
                if ( *s == '\0' )
                {
                    failed = true;
                    *buffer = s;
                    return true;
                }
                if ( *s == *c)
                {
                    s++;
                    c++;
                }
                else
                {
                    failed = true;
                    *buffer = s;
                    return true;
                }
            }
        }
        else if ( *s == 'f' )
        {
            s++;
            static const char* trueString = "alse";
            const ParserChar* c = (const ParserChar* )trueString;
            while (true)
            {
                if ( *c == '\0' )
                {
                    failed = false;
                    *buffer = s;
                    return false;
                }
                if ( *s == '\0' )
                {
                    failed = true;
                    *buffer = s;
                    return true;
                }
                if ( *s == *c)
                {
                    s++;
                    c++;
                }
                else
                {
                    failed = true;
                    *buffer = s;
                    return true;
                }
            }
        }

        failed = true;
        return false;
    }

    //--------------------------------------------------------------------
    template<typename T>
    bool GeneratedSaxParser::Utils::isInf( T value )
    {
        return value == std::numeric_limits<T>::infinity();
    }

    //--------------------------------------------------------------------
    template<typename T>
    bool GeneratedSaxParser::Utils::isNegativeInf( T value )
    {
        return value == -std::numeric_limits<T>::infinity();
    }

    //--------------------------------------------------------------------
    template<typename T>
    bool GeneratedSaxParser::Utils::isNaN( T value )
    {
#if defined(COLLADABU_OS_WIN) && !defined(__MINGW32__)
        return _isnan( value ) ? true : false;
#else
        using namespace std;
        return isnan( value );
#endif
    }

    //--------------------------------------------------------------------
    bool Utils::isInf( float value )
    {
        return isInf<float>( value );
    }

    //--------------------------------------------------------------------
    bool Utils::isInf( double value )
    {
        return isInf<double>( value );
    }

    //--------------------------------------------------------------------
    bool Utils::isNegativeInf( float value )
    {
        return isNegativeInf<float>( value );
    }

    //--------------------------------------------------------------------
    bool Utils::isNegativeInf( double value )
    {
        return isNegativeInf<double>( value );
    }

    //--------------------------------------------------------------------
    bool Utils::isNaN( float value )
    {
        return isNaN<float>( value );
    }

    //--------------------------------------------------------------------
    bool Utils::isNaN( double value )
    {
        return isNaN<double>( value );
    }

} // namespace GeneratedSaxParser
