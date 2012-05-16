/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libftoa.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMON_ITOA_H__
#define __COMMON_ITOA_H__


#include <stdlib.h>

namespace Common
{


	/* Functions to convert the different integer types to their ascii representation
	 These function directly write in to a given buffer. The minimum buffer size for each type 
	 is given the MINIMUM_BUFFERSIZE_10 member of the Itoa template class.*/




	/** Template function to retrieve the minimum size of the buffer that has to be provided to integerToAscii.
	The only apply to radix = 10.*/
	template<class IntegerType> class Itoa{};


	template<> class Itoa<char               > { public: static const size_t MINIMUM_BUFFERSIZE_10 =  5; };  // sign plus 3 digits plus null termination
	template<> class Itoa<unsigned char      > { public: static const size_t MINIMUM_BUFFERSIZE_10 =  4; };  // 3 digits plus null termination
	template<> class Itoa<short              > { public: static const size_t MINIMUM_BUFFERSIZE_10 =  7; };  // sign plus 5 digits plus null termination
	template<> class Itoa<unsigned short     > { public: static const size_t MINIMUM_BUFFERSIZE_10 =  6; };  // 5 digits plus null termination
	template<> class Itoa<int                > { public: static const size_t MINIMUM_BUFFERSIZE_10 = 12; };  // sign plus 10 digits plus null termination
	template<> class Itoa<unsigned int       > { public: static const size_t MINIMUM_BUFFERSIZE_10 = 11; };  // 10 digits plus null termination
	template<> class Itoa<long               > { public: static const size_t MINIMUM_BUFFERSIZE_10 = 12; };  // sign plus 10 digits plus null termination
	template<> class Itoa<unsigned long      > { public: static const size_t MINIMUM_BUFFERSIZE_10 = 11; };  // 10 digits plus null termination
	template<> class Itoa<long long          > { public: static const size_t MINIMUM_BUFFERSIZE_10 = 22; };  // sign plus 20 digits plus null termination
	template<> class Itoa<unsigned long long > { public: static const size_t MINIMUM_BUFFERSIZE_10 = 21; };  // 20 digits plus null termination


	/** Writes the string representation value into @a buffer. @a value hast be positive, even for signed types.*/
	template<class IntegerType>
	size_t itoaImpl( IntegerType value, char* buffer, unsigned char radix)
	{
		typedef unsigned char DigitType;
		char *p = buffer;                

		// We convert to a string in reversed order and store the position of the first digit

		char *firstDigitPos = p;      

		do {
			DigitType digit = (DigitType) (value % radix);
			value /= radix;       

			if (digit > 9)
			{
				*p++ = (char) (digit - 10 + 'a'); 
			}
			else
			{
				*p++ = (char) (digit + '0');      
			}
		} while (value > 0);

		// determine the bytes written, without null termination
		size_t bytesWritten = p - buffer;

		// null termination, and step back to the last digit
		*p-- = 0;

		// we need to revert the string
		do {
			char temp = *p;
			*p = *firstDigitPos;
			*firstDigitPos = temp;   
			--p;
			++firstDigitPos;         
		} while (firstDigitPos < p); 

		return bytesWritten;
	}


	template<class IntegerType>
	size_t itoaImplSigned( IntegerType value, char* buffer, unsigned char radix)
	{
		char *p = buffer;

		if ( value < 0 )
		{
			*p++ = '-';
			return itoaImpl( -value, p, radix) + 1;
		}
		else
		{
			return itoaImpl( value, p, radix);
		}
	}

	
	size_t itoa( signed char value       , char* buffer, unsigned char radix);
	size_t itoa( unsigned char value     , char* buffer, unsigned char radix);
	size_t itoa( signed short value      , char* buffer, unsigned char radix);
	size_t itoa( unsigned short value    , char* buffer, unsigned char radix);
	size_t itoa( signed int value        , char* buffer, unsigned char radix);
	size_t itoa( unsigned int value      , char* buffer, unsigned char radix);
	size_t itoa( signed long value       , char* buffer, unsigned char radix);
	size_t itoa( unsigned long value     , char* buffer, unsigned char radix);
	size_t itoa( signed long long value  , char* buffer, unsigned char radix);
	size_t itoa( unsigned long long value, char* buffer, unsigned char radix);



} // namespace COMMON

#endif // __COMMON_ITOA_H__
