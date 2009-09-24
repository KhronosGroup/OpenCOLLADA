/******************************************************************************
Copyright (c) 2007 netAllied GmbH, Tettnang

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

#ifndef __MATHML_SOLVER_FUNCTION_EXTENTIONS_H__
#define __MATHML_SOLVER_FUNCTION_EXTENTIONS_H__

#include "MathMLSolverPrerequisites.h"
#include "MathMLParserConstants.h"

#include <cmath>

#include "MathMLSymbolTable.h"

namespace MathML
{
    /** Forward Declarations. */
    class Error;
    class ErrorHandler;

    /** Extensions for additional functions for the solver */
    class _MATHML_SOLVER_EXPORT SolverFunctionExtentions
    {
    public:
        /** C-tor. */
        SolverFunctionExtentions()
        {}

        /** D-tor. */
        virtual ~SolverFunctionExtentions()
        {}

    private:
        /** Method for retrieving information about the sign of a value.
        @return Returns 1 for values > 0 or -1 for values < 0, otherwise 0.
        */
        inline static double sign ( double value )
        {
            if ( value > 0 )
            {
                return 1;
            }

            if ( value < 0 )
            {
                return -1;
            }

            return 0;
        }

    public:
        /** Adds all trigonometric and basic functions to the given symbolTable.
        @param symbolTable The symbol table for adding functions.
        */
        static void addAllExtensionFunctions( MathML::SymbolTable& symbolTable );

    public:

        //-------------------------------------------------------------------------------------------
        inline static void sin( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            result.setValue( ::sin( paramlist.at( 0 ).getDoubleValue() ) );
        }

        //-------------------------------------------------------------------------------------------
        inline static void cos( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            result.setValue( ::cos( paramlist.at( 0 ).getDoubleValue() ) );
        }

        //-------------------------------------------------------------------------------------------
        inline static void tan( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            result.setValue( ::tan( paramlist.at( 0 ).getDoubleValue() ) );
        }

        //-------------------------------------------------------------------------------------------
        inline static void abs( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            result.setValue( ( double ) ::abs( paramlist.at( 0 ).getDoubleValue() ) );
        }

        //-------------------------------------------------------------------------------------------
        inline static void logn( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            result.setValue( ::log( paramlist.at( 0 ).getDoubleValue() ) );
        }

        //-------------------------------------------------------------------------------------------
        inline static void exp( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            result.setValue( ::exp( paramlist.at( 0 ).getDoubleValue() ) );
        }

        //-------------------------------------------------------------------------------------------
        inline static void pow( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            result.setValue( ::pow( paramlist.at( 0 ).getDoubleValue(), paramlist.at( 1 ).getDoubleValue() ) );
        }

        /** Reciprocal value of cosinus ( 1 / cosinus ). */
        inline static void sec( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double cosinus = ::cos( paramlist.at( 0 ).getDoubleValue() );
            result.setValue( 1. / cosinus );
        }

        /** Reciprocal value of sinus ( 1 / sinus ). */
        inline static void cosec( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double sinus = ::sin( paramlist.at( 0 ).getDoubleValue() );
            result.setValue( 1. / sinus );
        }

        /** Reciprocal value of tangens ( 1 / tangens ). */
        inline static void cotan( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double tangens = ::tan( paramlist.at( 0 ).getDoubleValue() );
            result.setValue( 1. / tangens );
        }

        /** Inverse function of sinus. */
        inline static void arcsin( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::asin( para ) );
        }

        /** Inverse function of cosinus. */
        inline static void arccos( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::acos( para ) );
        }

        /** Inverse function of tangens. */
        inline static void arctan( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::atan( para ) );
        }

        /** Reciprocal value of secant ( arctan(x / sqrt(x * x - 1)) + sign(x - 1) * (2 * arctan(1)) ). */
        inline static void arcsec( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::atan( ( double ) ( x / ::sqrt( x * x - 1 ) ) ) + sign( x - 1 ) * ( 2 * ::atan( ( double ) 1 ) ) );
        }

        /** Reciprocal value of cosecant ( arctan(x / sqrt(x * x - 1)) + (sign(x) - 1) * (2 * arctan(1)) ). */
        inline static void arccsc( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::atan( ( double ) ( x / ::sqrt( x * x - 1 ) ) ) + ( sign( x ) - 1 ) * ( 2 * ::atan( ( double ) 1 ) ) );
        }

        /** Reciprocal value of cotangens ( arctan(x) + 2 * arctan(1) ). */
        inline static void arccotan( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::atan( x ) + 2 * ::atan( ( double ) 1 ) );
        }



        /** Sinus hyperbolicus. */
        inline static void sinh( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::sinh( para ) );
        }

        /** Cosinus hyperbolicus. */
        inline static void cosh( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::cosh( para ) );
        }

        /** Tangens hyperbolicus. */
        inline static void tanh( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler)
        {
            double para = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::tanh( para ) );
        }

        /** Hyperbolicus of reciprocal value of cosinus ( 2 / (exp(x) + exp(-x)) ). */
        inline static void sech( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( 2 / ( ::exp( x ) + ::exp( -x ) ) );
        }

        /** Hyperbolicus of reciprocal value of sinus ( 2 / (exp(x) - exp(-x)) ). */
        inline static void cosech( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( 2 / ( ::exp( x ) - ::exp( -x ) ) );
        }

        /** Hyperbolicus of reciprocal value of tangens ( (exp(x) + exp(-x)) / (exp(x) - exp(-x)) ). */
        inline static void cotanh( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ( ::exp( x ) + ::exp( -x ) ) / ( ::exp( x ) - ::exp( -x ) ) );
        }


        /** Hyperbolicus of inverse function of sinus. ( log(x + sqrt(x * x + 1)) ) */
        inline static void arcsinh( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::log( x + ::sqrt( x * x + 1 ) ) );
        }

        /** Hyperbolicus of inverse function of cosinus. ( log(x + sqrt(x * x - 1)) ) */
        inline static void arccosh( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::log( x + ::sqrt( x * x - 1 ) ) );
        }

        /** Hyperbolicus of inverse function of tangens. ( log((1 + x) / (1 - x)) / 2 ) */
        inline static void arctanh( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::log( ( 1 + x ) / ( 1 - x ) ) / 2 );
        }

        /** Hyperbolicus of reciprocal value of secant. ( log((sqrt(-x * x + 1) + 1) / x) ) */
        inline static void arcsech( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::log( ( ::sqrt( -x * x + 1 ) + 1 ) / x ) );
        }

        /** Hyperbolicus of reciprocal value of cosecant. ( log((sign(x) * sqrt(x * x + 1) + 1) / x) ) */
        inline static void arccsch( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::log( ( sign( x ) * ::sqrt( x * x + 1 ) + 1 ) / x ) );
        }

        /** Hyperbolicus of reciprocal value of cotangens. ( log((x + 1) / (x - 1)) / 2 ) */
        inline static void arccotanh( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double x = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::log( ( x + 1 ) / ( x - 1 ) ) / 2 );
        }



        /** Modulo: Remaining of a / b. */
        inline static void rem( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para1 = paramlist.at( 0 ).getDoubleValue();
            double para2 = paramlist.at( 1 ).getDoubleValue();
            result.setValue( ( long ) para1 % ( long ) para2 );
        }

        /** GCD (greatest common divisor): see _gcd(..) -> eucidean algorithm. */
        inline static void gcd( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double current = paramlist.at( 0 ).getDoubleValue();

            for ( unsigned int i = 1; i < paramlist.size(); ++i )
            {
                double paraI = paramlist.at( i ).getDoubleValue();
                current = _gcd( ( long ) paraI, ( long ) current );
            }

            result.setValue( current );
        }

        /** LCM (least common multiple): see _lcm(..) -> lcm(a,b) = (a * b) / gcd(a,b). */
        inline static void lcm( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double current = paramlist.at( 0 ).getDoubleValue();

            for ( unsigned int i = 1; i < paramlist.size(); ++i )
            {
                double paraI = paramlist.at( i ).getDoubleValue();
                current = _lcm( paraI, current );
            }

            result.setValue( current );
        }

        //-------------------------------------------------------------------------------------------
        inline static void floor( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::floor( para ) );
        }

        //-------------------------------------------------------------------------------------------
        inline static void ceiling( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para = paramlist.at( 0 ).getDoubleValue();
            result.setValue( ::ceil( para ) );
        }

        //-------------------------------------------------------------------------------------------
        inline static void min( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double current = paramlist.at( 0 ).getDoubleValue();

            for ( unsigned int i = 1; i < paramlist.size(); ++i )
            {
                double paraI = paramlist.at( i ).getDoubleValue();
                current = std::min( current, paraI );
            }

            result.setValue( current );
        }

        //-------------------------------------------------------------------------------------------
        inline static void max( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double current = paramlist.at( 0 ).getDoubleValue();

            for ( unsigned int i = 1; i < paramlist.size(); ++i )
            {
                double paraI = paramlist.at( i ).getDoubleValue();
                current = std::max( current, paraI );
            }

            result.setValue( current );
        }

        //-------------------------------------------------------------------------------------------
        static void factorial( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler );
        
        //-------------------------------------------------------------------------------------------
        inline static void root( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double r = paramlist.at( 0 ).getDoubleValue();
            double x = paramlist.at( 1 ).getDoubleValue();

            if ( r == 2.0 )
            {
                result.setValue( std::sqrt( x ) );
            }

            else
            {
                result.setValue( ::pow( x, 1 / r ) );
            }
        }

        //-------------------------------------------------------------------------------------------
        inline static void log( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double base = paramlist.at( 0 ).getDoubleValue();
            double x = paramlist.at( 1 ).getDoubleValue();
            result.setValue( std::log( x ) / std::log( base ) );
        }

        //-------------------------------------------------------------------------------------------
        inline static void _xor( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            bool a = paramlist.at( 0 ).getBoolValue();
            bool b = paramlist.at( 1 ).getBoolValue();
            result.setValue( ( bool ) ( a ^ b ) );
        }


        //-------------------------------------------------------------------------------------------
		/**
		@see sas(..)
		@return The side of the sas result.
		*/
        inline static void sass( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para1 = paramlist.at( 0 ).getDoubleValue();
            double para2 = paramlist.at( 1 ).getDoubleValue();
            double para3 = paramlist.at( 2 ).getDoubleValue();
            SASResult sasRresult;
            sas( sasRresult, para1, para2, para3 );
            result.setValue( sasRresult.c );
        }
		/**
		@see sas(..)
		@return The side of the sas result.
		*/
		inline static double sass(double a, double gamma, double b)
		{
			SASResult sasRresult = sas( a, gamma, b );			
			return sasRresult.c;
		}

        /**
		@see sas(..)
		@return The alpha angle of the sas result.
		*/
        inline static void sasa( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para1 = paramlist.at( 0 ).getDoubleValue();
            double para2 = paramlist.at( 1 ).getDoubleValue();
            double para3 = paramlist.at( 2 ).getDoubleValue();
            SASResult sasRresult;
            sas( sasRresult, para1, para2, para3 );
            result.setValue( sasRresult.alpha );
        }

		/**
		@see sas(..)
		@return The alpha angle of the sas result.
		*/
		inline static double sasa(double a, double gamma, double b)
		{
			SASResult sasRresult = sas( a, gamma, b );			
			return sasRresult.alpha;
		}

		/**
		@see sas(..)
		@return The alpha angle value of the sss result.
		*/
        inline static void sssa( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
        {
            double para1 = paramlist.at( 0 ).getDoubleValue();
            double para2 = paramlist.at( 1 ).getDoubleValue();
            double para3 = paramlist.at( 2 ).getDoubleValue();
            SSSResult sssResult;
            sss(sssResult, para1, para2, para3 );
            result.setValue( sssResult.alpha );
        }
		
		/**
		@see sas(..)
		@return The alpha angle value of the sss result.
		*/
		inline static double sssa(double a, double b, double c)
		{
			SSSResult sssResult = sss(a, b, c);
			return sssResult.alpha;
		}

		/**
		@todo dof implementation
		@param i The index of the DOF to return the axis angle.
		@return The current axis angle of the specified DOF.
		*/
		inline static void dof(MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler)
		{			
			result.setValue(paramlist.at( 0 ).getDoubleValue());
		}
		
		/**
		@todo dof implementation
		@param i The index of the DOF to return the axis angle.
		@return The current axis angle of the specified DOF.
		*/
		inline static double dof(unsigned int i)
		{			
			return i;
		}


    private:
        /** GCD (euclidean algorithm). */
        inline static long _gcd( long a, long b )
        {
            if ( b == 0 )
            {
                return a;
            }

            else
                return _gcd( b, ( a % b ) );
        }

        /** LCM (least common multiple): lcm(a,b) = (a * b) / gcd(a,b). */
        inline static double _lcm( double a, double b )
        {
            return ( a * b ) / _gcd( ( long ) a, ( long ) b );
        }


        //------------------------------------
        //--- typedefs for SSS, SAS methods
        //------------------------------------

        struct SASResult
        {
            double alpha;
            double beta;
            double c;
        };

        struct SSSResult
        {
            double alpha;
            double beta;
            double gamma;
        };


        /**
        * Trigonemtry function for not orthogonal triangles. Takes two sides and
        * one angle as input and calculates all missing data.
        * <ol>
        * <li>Calculates the opposite side (c) of the given angle gamma.</li>
        * <li>Calculates the angle alpha.</li>
        * <li>Calculates the angle beta.</li>
        * </ol>
        * 
        * @param result Result values by reference: c, alpha and beta
        * @param a in mm
        * @param gamma in rad
        * @param b in mm
        */
        inline static void sas( SASResult& result, double a, double gamma, double b )
        {
            result.c = ::sqrt( ::pow( a, 2 ) + ::pow( b, 2 ) - 2 * a * b * ::cos( gamma ) );
            result.alpha = ::asin( a * ::sin( gamma ) / result.c );
            result.beta = PI_NUMBER - result.alpha - gamma;
        }

		/**
		* Trigonemtry function for not orthogonal triangles. Takes two sides and
		* one angle as input and calculates all missing data.
		* <ol>
		* <li>Calculates the opposite side (c) of the given angle gamma.</li>
		* <li>Calculates the angle alpha.</li>
		* <li>Calculates the angle beta.</li>
		* </ol>
		* 
		* @param a in mm
		* @param gamma in rad
		* @param b in mm
		* @return Result values by value: c, alpha and beta
		*/
		inline static SASResult sas(double a, double gamma, double b)
		{
			SASResult result;
			sas(result, a, gamma, b);
			return result;
		}

        /**
        * Trigonemtry function for not orthogonal triangles. Takes three sides as
        * input and calculates all angles.
        * 
        * @param result Result values by reference: alpha, beta, and gamma
        * @param a first side in mm
        * @param b second side in mm
        * @param c third side in mm
        */
        inline static void sss( SSSResult& result, double a, double b, double c )
        {
            // alpha = acos( (b≤ + c≤ - a≤) / 2 * b * c )
            result.alpha = ::acos( ( ::pow( b, 2 ) + ::pow( c, 2 ) - ::pow( a, 2 ) ) / ( 2 * b * c ) );
            // beta = asin( b * sin(alpha) / a )
            result.beta = ::asin( b * ::sin( result.alpha ) / a );
            // gamma = PI - alpha - beta
            result.gamma = PI_NUMBER - result.alpha - result.beta;
        }

		/**
		* Trigonemtry function for not orthogonal triangles. Takes three sides as
		* input and calculates all angles.
		* 
		* @param a first side in mm
		* @param b second side in mm
		* @param c third side in mm
		* @return Result values by value: alpha, beta, and gamma
		*/
		inline static SSSResult sss(double a, double b, double c)
		{
			SSSResult result;
			sss(result, a, b, c);
			return result;
		}
    };


} // namespace MathML

#endif // __MATHML_SOLVER_FUNCTION_EXTENTIONS_H__
