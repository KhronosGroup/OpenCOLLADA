#include "COLLADASWdtoa.h"
#include "COLLADASWitoa.h"

#include <math.h>

namespace COLLADASW
{

	//From Common Repo: Rev 31

	typedef union {
		long long	LL;
		double	D;
	}		LLD_t;



	static const long long MASK1 = 0x1FFFFFFFFFFFFFLL; // 53 ones in binary
	static const long long MASK2 = 0x10000000000000LL; // 1 one followed by 52 zeros

	inline bool isPositiveInfinity(double v)
	{
		LLD_t x;
		x.D = v;
		return x.LL == 0x7FF0000000000000LL;

	}

	inline bool isNegativeInfinity(double v)
	{
		LLD_t x;
		x.D = v;
		return x.LL == (long long)0xFFF0000000000000LL;
	}

	inline bool isNaN(double v)
	{
		return v!=v;
	}


	double roundingSummand(double d, int maxLength, int& dezmialPointPos)
	{
		double fabs = abs(d);
		dezmialPointPos = 0;

		if ( fabs < 0.00000000000001 )
			dezmialPointPos = -15;
		if ( fabs < 0.0000000000001 )
			dezmialPointPos = -14;
		if ( fabs < 0.000000000001 )
			dezmialPointPos = -13;
		if ( fabs < 0.00000000001 )
			dezmialPointPos = -12;
		if ( fabs < 0.0000000001 )
			dezmialPointPos = -11;
		if ( fabs < 0.000000001 )
			dezmialPointPos = -10;
		if ( fabs < 0.00000001 )
			dezmialPointPos = -9;
		if ( fabs < 0.0000001 )
			dezmialPointPos = -8;
		if ( fabs < 0.000001 )
			dezmialPointPos = -7;
		if ( fabs < 0.00001 )
			dezmialPointPos = -6;
		else if ( fabs < 0.0001 )
			dezmialPointPos = -5;
		else if ( fabs < 0.001 )
			dezmialPointPos = -4;
		else if ( fabs < 0.01 )
			dezmialPointPos = -3;
		else if ( fabs < 0.1 )
			dezmialPointPos = -2;
		else if ( fabs < 1 )
			dezmialPointPos = -1;
		else if ( fabs < 10 )
			dezmialPointPos = 0;
		else if ( fabs < 100 )
			dezmialPointPos = 1;
		else if ( fabs < 1000 )
			dezmialPointPos = 2;
		else if ( fabs < 10000 )
			dezmialPointPos = 3;
		else if ( fabs < 100000 )
			dezmialPointPos = 4;
		else if ( fabs < 1000000 )
			dezmialPointPos = 5;

		static const double roundingSummands[] = {   
			0.5e-20,      // < 0.00001 
			0.5e-19,      // < 0.00001 
			0.5e-18,      // < 0.00001 
			0.5e-17,      // < 0.00001 
			0.5e-16,      // < 0.00001 
			0.5e-15,      // < 0.00001 
			0.5e-14,      // < 0.00001 
			0.5e-13,      // < 0.00001 
			0.5e-12,      // < 0.00001 
			0.5e-11,      // < 0.00001 
			0.5e-10,      // 0.00001 - 0.0001 
			0.5e-9,      // 0.0001 - 0.001
			0.5e-8,      // 0.001 - 0.01
			0.5e-7,      // 0.01 - 0.1
			0.5e-6,      // 0.1 - 1     
			0.5e-5,      // 1 - 10    : 0.000005
			0.5e-4,      // 10 - 100 
			0.5e-3,      // 100 - 1000 
			0.5e-2,      // 1000 - 10000 
			0.5e-1,      // 10000 - 100000 
			0.5e0,      // 100000 - 1000000 
		};

		const double& rS = roundingSummands[dezmialPointPos + 21 - maxLength];

		return (d > 0) ? rS : -rS;
	}

	char* dtoa_no_exponent(double d, char* buffer, int maxLength)
	{
		long long mantissa, int_part, frac_part;
		short exp2;
		LLD_t x;
		char *p = buffer;

		int dezmialPointPos = 0;
		double rS = roundingSummand(d, maxLength, dezmialPointPos);
		if ( dezmialPointPos < 0 )
		{
			maxLength = maxLength - dezmialPointPos; 
		}

		x.D = d + rS;

		exp2 = (unsigned short)((x.LL >> 52) & 0x7FF) - 1023;
		mantissa = (x.LL & MASK1) | MASK2;
		frac_part = 0;
		int_part = 0;


		// handle numbers in non exponential representation
		if (exp2 >= 52)
			int_part = mantissa << (exp2 - 52);
		else if (exp2 >= 0) 
		{
			int_part = mantissa >> (52 - exp2);
			frac_part = (mantissa << (exp2 + 1)) & MASK1;
		}
		else /* if (exp2 < 0) */
			frac_part = (mantissa  & MASK1) >> -(exp2 + 1);

		p = buffer;

		if (x.LL < 0)
		{
			*p++ = '-';
			maxLength++;
		}

		if (int_part == 0)
			*p++ = '0';
		else
		{
			size_t bytesWritten = itoa( int_part, p, 10);
			p += bytesWritten;
		}

		char m = (char)(p - buffer);

		if ((frac_part != 0) && (maxLength > m))
		{
			*p++ = '.';
			char max;

			max = (char)(DTOA_BUFFERSIZE - (p - buffer) - 1);
			if (max > maxLength)
				max = maxLength;
			/* print BCD */
			for (; m < max; m++)
			{
				/* frac_part *= 10;	*/
				frac_part *= 10;// (frac_part << 3) + (frac_part << 1);    

				*p++ = (char)(frac_part >> 53) + '0';
				frac_part &= MASK1;
			}
			/* delete ending zeros and decimal point if necessary */
			for (--p; p[0] == '0' ; --p)
			{
				if ( p[-1] == '.' )
				{
					p -= 2;
					break;
				}
			}

			if ( p[0] == '.' )
			{
				--p;
			}

			++p;
		}

		return p;
	}

	int dtoa(double d, char* buffer, bool doublePrecision )
	{
		static const double lowerLimitForNonExponetialNotation  = 0.001f;    // Positive numbers smaller will be expressed in exponential representation
		static const double upperLimitForNonExponetialNotation  = 999999;    // Positive numbers bigger will be expressed in exponential representation
		static const double negativeLowerLimitForNonExponetialNotation  = - upperLimitForNonExponetialNotation;    // Negative numbers smaller will be expressed in exponential representation
		static const double negativeUpperLimitForNonExponetialNotation  = - lowerLimitForNonExponetialNotation;    // Negative numbers bigger will be expressed in exponential representation
		int exp10 = 0;
		char *p = 0;

		if (d == 0.0)
		{
			buffer[0] = '0';
			buffer[1] = 0;
			return 1;
		}
		else if ( isNaN(d) )
		{
			buffer[0] = 'N';
			buffer[1] = 'a';
			buffer[2] = 'N';
			buffer[3] = 0;
			return 3;
		}
		else if ( isPositiveInfinity(d) )
		{
			buffer[0] = 'I';
			buffer[1] = 'N';
			buffer[2] = 'F';
			buffer[3] = 0;
			return 3;
		}
		else if ( isNegativeInfinity(d) )
		{
			buffer[0] = '-';
			buffer[1] = 'I';
			buffer[2] = 'N';
			buffer[3] = 'F';
			buffer[4] = 0;
			return 4;
		}

		if ( ((d > 0) && ((d > upperLimitForNonExponetialNotation) || (d < lowerLimitForNonExponetialNotation))) 
			|| ((d < 0) && ((d > negativeUpperLimitForNonExponetialNotation) || (d < negativeLowerLimitForNonExponetialNotation))) )
		{
			// handle big numbers in exponential representation
			// we determine the exponent in exponential representation
			exp10 = (int)log10(d > 0 ? d : -d);

			if ( exp10 < 0)
				exp10--;

			// check if this is faster if we cast exp10
			double factor = pow((double)10, -exp10);

			p = dtoa_no_exponent(d*factor, buffer, doublePrecision ? 16 : 6);

			*p++ = 'e';
			size_t bytesWritten = itoa( exp10, p, 10);
			p += bytesWritten;
		}
		else
		{
			p = dtoa_no_exponent(d, buffer, doublePrecision ? 16 : 7);
		}

		*p = 0;

		return (int)(p - buffer);
	}


} // namespace COLLADASW
