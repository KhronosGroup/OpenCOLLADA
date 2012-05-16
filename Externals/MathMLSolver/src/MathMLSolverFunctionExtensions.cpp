#include "MathMLSolverStableHeaders.h"
#include "MathMLSolverFunctionExtensions.h"
#include "MathMLError.h"

namespace MathML
{
    //-----------------------------------------------------------------------
    void SolverFunctionExtentions::addAllExtensionFunctions( MathML::SymbolTable& symbolTable )
    {
        //@todo split functions to specific public sub functions
        symbolTable.addFunction( FUNCTION_SIN, 1, MathML::SolverFunctionExtentions::sin );
        symbolTable.addFunction( FUNCTION_COS, 1, MathML::SolverFunctionExtentions::cos );
        symbolTable.addFunction( FUNCTION_TAN, 1, MathML::SolverFunctionExtentions::tan );
        symbolTable.addFunction( FUNCTION_ABS, 1, MathML::SolverFunctionExtentions::abs );
        symbolTable.addFunction( FUNCTION_EXP, 1, MathML::SolverFunctionExtentions::exp );
        symbolTable.addFunction( FUNCTION_POW, 2, MathML::SolverFunctionExtentions::pow );
        symbolTable.addFunction( FUNCTION_LOGN, 1, MathML::SolverFunctionExtentions::logn );

        symbolTable.addFunction( FUNCTION_SEC, 1, MathML::SolverFunctionExtentions::sec );
        symbolTable.addFunction( FUNCTION_CSC, 1, MathML::SolverFunctionExtentions::cosec );
        symbolTable.addFunction( FUNCTION_COT, 1, MathML::SolverFunctionExtentions::cotan );
        symbolTable.addFunction( FUNCTION_SINH, 1, MathML::SolverFunctionExtentions::sinh );
        symbolTable.addFunction( FUNCTION_COSH, 1, MathML::SolverFunctionExtentions::cosh );
        symbolTable.addFunction( FUNCTION_TANH, 1, MathML::SolverFunctionExtentions::tanh );
        symbolTable.addFunction( FUNCTION_SECH, 1, MathML::SolverFunctionExtentions::sech );
        symbolTable.addFunction( FUNCTION_CSCH, 1, MathML::SolverFunctionExtentions::cosech );
        symbolTable.addFunction( FUNCTION_COTH, 1, MathML::SolverFunctionExtentions::cotanh );

        symbolTable.addFunction( FUNCTION_ARCSIN, 1, MathML::SolverFunctionExtentions::arcsin );
        symbolTable.addFunction( FUNCTION_ARCCOS, 1, MathML::SolverFunctionExtentions::arccos );
        symbolTable.addFunction( FUNCTION_ARCTAN, 1, MathML::SolverFunctionExtentions::arctan );
        symbolTable.addFunction( FUNCTION_ARCSEC, 1, MathML::SolverFunctionExtentions::arcsec );
        symbolTable.addFunction( FUNCTION_ARCCSC, 1, MathML::SolverFunctionExtentions::arccsc );
        symbolTable.addFunction( FUNCTION_ARCCOT, 1, MathML::SolverFunctionExtentions::arccotan );
        symbolTable.addFunction( FUNCTION_ARCSINH, 1, MathML::SolverFunctionExtentions::arcsinh );
        symbolTable.addFunction( FUNCTION_ARCCOSH, 1, MathML::SolverFunctionExtentions::arccosh );
        symbolTable.addFunction( FUNCTION_ARCTANH, 1, MathML::SolverFunctionExtentions::arctanh );
        symbolTable.addFunction( FUNCTION_ARCSECH, 1, MathML::SolverFunctionExtentions::arcsech );
        symbolTable.addFunction( FUNCTION_ARCCSCH, 1, MathML::SolverFunctionExtentions::arccsch );
        symbolTable.addFunction( FUNCTION_ARCCOTH, 1, MathML::SolverFunctionExtentions::arccotanh );

        symbolTable.addFunction( FUNCTION_FLOOR, 1, MathML::SolverFunctionExtentions::floor );
        symbolTable.addFunction( FUNCTION_CEILING, 1, MathML::SolverFunctionExtentions::ceiling );
        symbolTable.addFunction( FUNCTION_MIN, -1, MathML::SolverFunctionExtentions::min );
        symbolTable.addFunction( FUNCTION_MAX, -1, MathML::SolverFunctionExtentions::max );
        symbolTable.addFunction( FUNCTION_GCD, -1, MathML::SolverFunctionExtentions::gcd );
        symbolTable.addFunction( FUNCTION_LCM, -1, MathML::SolverFunctionExtentions::lcm );
        symbolTable.addFunction( FUNCTION_REM, 2, MathML::SolverFunctionExtentions::rem );
        symbolTable.addFunction( FUNCTION_FACTORIAL, 1, MathML::SolverFunctionExtentions::factorial );

        symbolTable.addFunction( FUNCTION_ROOT, 2, MathML::SolverFunctionExtentions::root );
        symbolTable.addFunction( FUNCTION_LOG, 2, MathML::SolverFunctionExtentions::log );

        //symbolTable.addFunction( FUNCTION_SASS, 3, MathML::SolverFunctionExtentions::sass );
        //symbolTable.addFunction( FUNCTION_SASA, 3, MathML::SolverFunctionExtentions::sasa );
        //symbolTable.addFunction( FUNCTION_SSSA, 3, MathML::SolverFunctionExtentions::sssa );
        //symbolTable.addFunction( FUNCTION_DOF, 1, MathML::SolverFunctionExtentions::dof );
    }

    //-----------------------------------------------------------------------
    void SolverFunctionExtentions::factorial( MathML::AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler )
	{
		long para = paramlist.at( 0 ).getLongValue();

		if ( para < 0 )
		{
            if ( errorHandler )
            {
                Error err( Error::ERR_INTERNAL_ERROR, "negative value for factorial not allowed!" );
                errorHandler->handleError( &err );
            }
		}

		if ( para > 1 )
		{
			long n = 1;

			for ( long i = 2; i <= para; ++i )
			{
				n = n * i;
			}

			result.setValue( n );
			return ;
		}

		//default 0 or 1: result 1
		result.setValue( ( long ) 1 );
	}
}
