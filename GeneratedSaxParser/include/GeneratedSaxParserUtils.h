/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_UTILS_H__
#define __GENERATEDSAXPARSER_UTILS_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"

#include <utility>

namespace GeneratedSaxParser
{
	class Utils 	
	{
	public:
	


		static StringHash calculateStringHash(const ParserChar* text, size_t textLength);

        static StringHash calculateStringHash( const ParserChar** text, const ParserChar* bufferEnd, bool& );

        static StringHash calculateStringHash( StringHash prefixHash, const char* separator, const ParserChar* text);

		static StringHash calculateStringHash(const ParserChar* text);

		static StringHash calculateStringHash(const ParserChar* text, bool& failed);

		static bool isWhiteSpace(ParserChar c)
		{
			return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
		}

		static bool isdigit(ParserChar c)
		{
			return (c >= '0' && c <= '9');
		}



		/** Converts the first string representing a floating point number within a ParserChar buffer to a 
		FloatingPointType and advances the character pointer to the first position after the last interpreted 
		character. If buffer is set to bufferEnd, the end of the buffer was reached during conversion., i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		template<class FloatingPointType>
		static FloatingPointType toFloatingPoint(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing a floating point number within a ParserChar buffer to a float.
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		template<class FloatingPointType>
		static FloatingPointType toFloatingPoint(const ParserChar* buffer, bool& failed);

        /** Combination of the two above functions. Converts first string and advances the pointer.
        Buffer end is determined by null termination.
        @tparam FloatingPointType C++ type of parsing result, i.e. float or double.
        @param buffer Pointer to the first character in the buffer. Will be set to the first 
        character after the last interpreted.
        @param  failed False if conversion succeeded, true on failure.*/
        template<class FloatingPointType>
        static FloatingPointType toFloatingPoint(const ParserChar** buffer, bool& failed);

        /** Converts the first string representing a float within a ParserChar buffer to a float and 
		advances the character pointer to the first position after the last interpreted character. If 
		buffer is set to bufferEnd, the end of the buffer was reached during conversion. In this case 
		failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static float toFloat(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing a float within a ParserChar buffer to a float.
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static float toFloat(const ParserChar* buffer, bool& failed);

        /** @see toFloatingPoint(const ParserChar** buffer, bool& failed). */
        static float toFloat(const ParserChar** buffer, bool& failed);

        /** Converts the first string representing a double within a ParserChar buffer to a double and 
		advances the character pointer to the first position after the last interpreted character. If 
		buffer is set to bufferEnd, the end of the buffer was reached during conversion. In this case 
		failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static double toDouble(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing a double within a ParserChar buffer to a double.
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static double toDouble(const ParserChar* buffer, bool& failed);

        /** @see toFloatingPoint(const ParserChar** buffer, bool& failed). */
        static double toDouble(const ParserChar** buffer, bool& failed);

		/** Converts the first string representing an integer within a ParserChar buffer to an int and 
		advances the character pointer to the first position after the last interpreted character. If 
		buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param IntegerType Type of the integer.
		@param signedInteger Indicates, if the integer type is signed or unsigned.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		template<class IntegerType, bool signedInteger>
		static IntegerType toInteger(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an integer within a ParserChar buffer to an int. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		template<class IntegerType, bool signedInteger>
		static IntegerType toInteger(const ParserChar* buffer, bool& failed);

        /** Combination of the two above functions. Converts first string and advances the pointer.
        Buffer end is determined by null termination.
        @tparam IntegerType C++ type of parsing result, i.e. int, short, long, ... .
        @tparam signedInteger Indicates, if the integer type is signed or unsigned.
        @param buffer Pointer to the first character in the buffer. Will be set to the first 
        character after the last interpreted.
        @param  failed False if conversion succeeded, true on failure.*/
        template<class IntegerType, bool signedInteger>
        static IntegerType toInteger(const ParserChar** buffer, bool& failed);

		/** Converts the first string representing an integer within a ParserChar buffer to an char and 
		advances the character pointer to the first position after the last interpreted character. If 
		buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static char toChar(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an integer within a ParserChar buffer to an char. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static char toChar(const ParserChar* buffer, bool& failed);

        static char toChar(const ParserChar** buffer, bool& failed);

        /** Converts the first string representing an unsigned integer within a ParserChar buffer to 
		an char and advances the character pointer to the first position after the last interpreted 
		character. If buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned char toUnsignedChar(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);

		/** Converts the first string representing an unsigned integer within a ParserChar buffer to an 
		unsigned char. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned char toUnsignedChar(const ParserChar* buffer, bool& failed);

        static unsigned char toUnsignedChar(const ParserChar** buffer, bool& failed);

		/** Converts the first string representing an integer within a ParserChar buffer to an short and 
		advances the character pointer to the first position after the last interpreted character. If 
		buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static short toShort(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an integer within a ParserChar buffer to an short. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static short toShort(const ParserChar* buffer, bool& failed);

        static short toShort(const ParserChar** buffer, bool& failed);


		/** Converts the first string representing an unsigned integer within a ParserChar buffer to 
		an short and advances the character pointer to the first position after the last interpreted 
		character. If buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned short toUnsignedShort(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an unsigned integer within a ParserChar buffer to an 
		unsigned short. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned short toUnsignedShort(const ParserChar* buffer, bool& failed);

        static unsigned short toUnsignedShort(const ParserChar** buffer, bool& failed);


		/** Converts the first string representing an integer within a ParserChar buffer to an int and 
		advances the character pointer to the first position after the last interpreted character. If 
		buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static int toInt(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an integer within a ParserChar buffer to an int. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static int toInt(const ParserChar* buffer, bool& failed);

        static int toInt(const ParserChar** buffer, bool& failed);


		/** Converts the first string representing an unsigned integer within a ParserChar buffer to 
		an int and advances the character pointer to the first position after the last interpreted 
		character. If buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned int toUnsignedInt(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an unsigned integer within a ParserChar buffer to an 
		unsigned int. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned int toUnsignedInt(const ParserChar* buffer, bool& failed);


        static unsigned int toUnsignedInt(const ParserChar** buffer, bool& failed);

		/** Converts the first string representing an integer within a ParserChar buffer to an int and 
		advances the character pointer to the first position after the last interpreted character. If 
		buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static long toLong(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an integer within a ParserChar buffer to an int. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static long toLong(const ParserChar* buffer, bool& failed);

        static long toLong(const ParserChar** buffer, bool& failed);


		/** Converts the first string representing an unsigned integer within a ParserChar buffer to 
		an int and advances the character pointer to the first position after the last interpreted 
		character. If buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned long toUnsignedLong(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an unsigned integer within a ParserChar buffer to an 
		unsigned int. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned long toUnsignedLong(const ParserChar* buffer, bool& failed);

        static unsigned long toUnsignedLong(const ParserChar** buffer, bool& failed);


		/** Converts the first string representing an integer within a ParserChar buffer to an long long and 
		advances the character pointer to the first position after the last interpreted character. If 
		buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static long long toLongLong(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an integer within a ParserChar buffer to an int. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static long long toLongLong(const ParserChar* buffer, bool& failed);

        static long long toLongLong(const ParserChar** buffer, bool& failed);


		/** Converts the first string representing an unsigned integer within a ParserChar buffer to 
		a long long and advances the character pointer to the first position after the last interpreted 
		character. If buffer is set to bufferEnd, the end of the buffer was reached during conversion, i.e. all characters 
		from buffer to bufferEnd are parsed. In this case failed is set to false if all these characters represent 
		a valid integer.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned long long toUnsignedLongLong(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


		/** Converts the first string representing an unsigned integer within a ParserChar buffer to an 
		unsigned long long. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static unsigned long long toUnsignedLongLong(const ParserChar* buffer, bool& failed);

        static unsigned long long toUnsignedLongLong(const ParserChar** buffer, bool& failed);


		/** Converts the first string representing an enum of type @EnumType within a ParserChar buffer to an 
		enum. 
		@param EnumType The type of the enumeration
		@param BaseType The base type the enumeration was derived from as a restriction
		@param EnumMapCount The count of @a EnumType. Must follow last C++ enum value
        representing last value in XSD enumeration (__COUNT in generated code with default config).
		The first member must be set to 0.
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.
		@param enumMap Maps BaseType to EnumType.
		@param baseConversionFunctionPtr Function used to convert from ParserChar buffer to BaseType.*/
		template<class EnumType, class BaseType, EnumType EnumMapCount>
		static EnumType toEnum( const ParserChar* buffer, 
								bool& failed, 
								const std::pair<BaseType, EnumType>* enumMap,
								BaseType (*baseConversionFunctionPtr)(const ParserChar* buffer, bool& failed) );

        /** 
         * Converts a string representing one value to an enum. Recognizes end of 
         * string by a pointer. To be used to convert character data with variety atomic.
         */
        template<class EnumType, class BaseType, EnumType EnumMapCount>
        static EnumType toEnum( const ParserChar** buffer, 
            const ParserChar* bufferEnd,
            bool& failed, 
            const std::pair<BaseType, EnumType>* enumMap,
            BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed) );


        /** Converts the first string representing a boolean within a ParserChar buffer to a bool. 
		@param buffer Pointer to the first character in the buffer. 
		@param failed False if conversion succeeded, true on failure.*/
		static bool toBool(const ParserChar* buffer, bool& failed);

		/** TODO Test this method. Converts the first string representing a bool within a ParserChar buffer to 
		a bool and advances the character pointer to the first position after the last interpreted 
		character. If buffer is set to bufferEnd, the end of the buffer was reached during conversion. 
		In this case failed is always set to true.
		@param buffer Pointer to the first character in the buffer. Will be set to the first 
		character after the last interpreted. 
		@param bufferEnd the first character after the last in the buffer
		@param failed False if conversion succeeded, true on failure.*/
		static bool toBool(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed);


        static bool toBool( const ParserChar** buffer, bool& failed  );


	private:
        /** Disable default copy ctor. */
		Utils( const Utils& pre );
        /** Disable default assignment operator. */
		const Utils& operator= ( const Utils& pre );

	};

	template<class EnumType, class BaseType, EnumType EnumMapCount>
	EnumType GeneratedSaxParser::Utils::toEnum( const ParserChar* buffer, 
											  bool& failed, 
											  const std::pair<BaseType, EnumType>* enumMap,
											  BaseType (*baseConversionFunctionPtr)(const ParserChar* buffer, bool& failed) )
	{
		// convert string to base type
		bool baseConversionFailed = false;
		BaseType baseValue = baseConversionFunctionPtr(buffer, failed);
		if ( baseConversionFailed )
		{
			failed = true;
			return EnumMapCount;
		}

		// convert base type to enum
		for ( size_t i = 0; i < EnumMapCount; ++i )
		{
			const std::pair<BaseType, EnumType>& enumPair = enumMap[i];
			if ( enumPair.first ==  baseValue )
			{
				failed = false;
				return enumPair.second;
			}
		}
		
		// no matching enum found
		failed = true;
		return EnumMapCount;
	}

    template<class EnumType, class BaseType, EnumType EnumMapCount>
    EnumType GeneratedSaxParser::Utils::toEnum( const ParserChar** buffer, 
        const ParserChar* bufferEnd,
        bool& failed, 
        const std::pair<BaseType, EnumType>* enumMap,
        BaseType (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed) )
    {
        // convert string to base type
        bool baseConversionFailed = false;
        BaseType baseValue = baseConversionFunctionPtr(buffer, bufferEnd, failed);
        if ( baseConversionFailed )
        {
            failed = true;
            return EnumMapCount;
        }

        // convert base type to enum
        for ( size_t i = 0; i < EnumMapCount; ++i )
        {
            const std::pair<BaseType, EnumType>& enumPair = enumMap[i];
            if ( enumPair.first ==  baseValue )
            {
                failed = false;
                return enumPair.second;
            }
        }

        // no matching enum found
        failed = true;
        return EnumMapCount;
    }


} // namespace COLLADASAXPARSER

#endif // __GENERATEDSAXPARSER_UTILS_H__
