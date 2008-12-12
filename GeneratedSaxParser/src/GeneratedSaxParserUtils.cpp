/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "GeneratedSaxParserUtils.h"
#include <math.h>
#include <memory>

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

	GeneratedSaxParser::StringHash Utils::calculateStringHash( const ParserChar* text, bool& failed )
	{
		failed = false;
		return calculateStringHash(text);
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

		FloatingPointType decimals = 0.0;
		int exponent = 0;
		bool infinity = false;
		bool charBeforeDecimalPoint = false;
		while ( true )
		{
			if ( s == bufferEnd )
			{
				failed = true;
				*buffer = bufferEnd;
				return 0.0f;
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
				failed = true;
				*buffer = bufferEnd;
				return 0.0f;
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
			int exponent = toInt(&s, bufferEnd, intFailed);
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

		FloatingPointType decimals = 0.0;
		int exponent = 0;
		bool infinity = false;
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
			int exponent = toInt(s, intFailed);
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
				failed = true;
				*buffer = bufferEnd;
				return 0;
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
	char Utils::toChar( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<char, true>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	char Utils::toChar( const ParserChar* buffer, bool& failed )
	{
		return toInteger<char, true>(buffer, failed);
	}

	//--------------------------------------------------------------------
	unsigned char Utils::toUnsignedChar( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<unsigned char, false>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned char Utils::toUnsignedChar( const ParserChar* buffer, bool& failed )
	{
		return toInteger<unsigned char, false>(buffer, failed);
	}

	//--------------------------------------------------------------------
	short Utils::toShort( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<short, true>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	short Utils::toShort( const ParserChar* buffer, bool& failed )
	{
		return toInteger<short, true>(buffer, failed);
	}

	//--------------------------------------------------------------------
	unsigned short Utils::toUnsignedShort( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<unsigned short, false>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned short Utils::toUnsignedShort( const ParserChar* buffer, bool& failed )
	{
		return toInteger<unsigned short, false>(buffer, failed);
	}

	//--------------------------------------------------------------------
	int Utils::toInt( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<int, true>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	int Utils::toInt( const ParserChar* buffer, bool& failed )
	{
		return toInteger<int, true>(buffer, failed);
	}

	//--------------------------------------------------------------------
	unsigned int Utils::toUnsignedInt( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<unsigned int, false>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned int Utils::toUnsignedInt( const ParserChar* buffer, bool& failed )
	{
		return toInteger<unsigned int, false>(buffer, failed);
	}

	//--------------------------------------------------------------------
	long Utils::toLong( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<long, true>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	long Utils::toLong( const ParserChar* buffer, bool& failed )
	{
		return toInteger<long, true>(buffer, failed);
	}

	//--------------------------------------------------------------------
	unsigned long Utils::toUnsignedLong( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<unsigned long, false>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned long Utils::toUnsignedLong( const ParserChar* buffer, bool& failed )
	{
		return toInteger<unsigned long, false>(buffer, failed);
	}

	//--------------------------------------------------------------------
	long long Utils::toLongLong( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<long long, true>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	long long Utils::toLongLong( const ParserChar* buffer, bool& failed )
	{
		return toInteger<long long, true>(buffer, failed);
	}

	//--------------------------------------------------------------------
	unsigned long long Utils::toUnsignedLongLong( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toInteger<unsigned long long, false>(buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned long long Utils::toUnsignedLongLong( const ParserChar* buffer, bool& failed )
	{
		return toInteger<unsigned long long, false>(buffer, failed);
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


} // namespace GeneratedSaxParser
