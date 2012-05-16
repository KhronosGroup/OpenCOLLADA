#include "MathMLSolverStableHeaders.h"
#include "MathMLSerializationUtil.h"

namespace MathML
{
    //-------------------------------------------------------------------------------------------
    const String& SerializationUtil::getArithmeticOperatorElementName( AST::ArithmeticExpression::Operator op )
    {
        switch ( op )
        {

        case AST::ArithmeticExpression::ADD:
            return ELEMENT_PLUS_NAME;
            break;

        case AST::ArithmeticExpression::SUB:
            return ELEMENT_MINUS_NAME;
            break;

        case AST::ArithmeticExpression::MUL:
            return ELEMENT_TIMES_NAME;
            break;

        case AST::ArithmeticExpression::DIV:
            return ELEMENT_DIVIDE_NAME;
            break;

        default:
            return UNKNOWN_ELEMENT;
        }
    }

    //-------------------------------------------------------------------------------------------
    const String& SerializationUtil::getComparisionOperatorElementName( AST::BinaryComparisonExpression::Operator op )
    {
        switch ( op )
        {

        case AST::BinaryComparisonExpression::EQ:
            return ELEMENT_EQ_NAME;
            break;

        case AST::BinaryComparisonExpression::NEQ:
            return ELEMENT_NEQ_NAME;
            break;

        case AST::BinaryComparisonExpression::LT:
            return ELEMENT_LT_NAME;
            break;

        case AST::BinaryComparisonExpression::GT:
            return ELEMENT_GT_NAME;
            break;

        case AST::BinaryComparisonExpression::LTE:
            return ELEMENT_LEQ_NAME;
            break;

        case AST::BinaryComparisonExpression::GTE:
            return ELEMENT_GEQ_NAME;
            break;

        default:
            return UNKNOWN_ELEMENT;
        }
    }

    //-------------------------------------------------------------------------------------------
    const String& SerializationUtil::getLogicOperatorElementName( AST::LogicExpression::Operator op )
    {
        switch ( op )
        {

        case AST::LogicExpression::AND:
            return ELEMENT_AND_NAME;
            break;

        case AST::LogicExpression::OR:
            return ELEMENT_OR_NAME;
            break;

        case AST::LogicExpression::XOR:
            return ELEMENT_XOR_NAME;
            break;

        default:
            return UNKNOWN_ELEMENT;
        }
    }

    //-------------------------------------------------------------------------------------------
    const String& SerializationUtil::getUnaryOperatorElementName( AST::UnaryExpression::Operator op )
    {
        switch ( op )
        {

        case AST::UnaryExpression::ADD:
            return ELEMENT_PLUS_NAME;
            break;

        case AST::UnaryExpression::SUB:
            return ELEMENT_MINUS_NAME;
            break;

        case AST::UnaryExpression::NOT:
            return ELEMENT_NOT_NAME;
            break;

        default:
            return UNKNOWN_ELEMENT;
        }
    }

    //-------------------------------------------------------------------------------------------
    const String& SerializationUtil::getFunctionElementName( const String& function )
    {
        if ( function == FUNCTION_SIN )
        {
            return ELEMENT_SIN_NAME;
        }

        else if ( function == FUNCTION_COS )
        {
            return ELEMENT_COS_NAME;
        }

        else if ( function == FUNCTION_TAN )
        {
            return ELEMENT_TAN_NAME;
        }

        else if ( function == FUNCTION_SEC )
        {
            return ELEMENT_SEC_NAME;
        }

        else if ( function == FUNCTION_CSC )
        {
            return ELEMENT_CSC_NAME;
        }

        else if ( function == FUNCTION_COT )
        {
            return ELEMENT_COT_NAME;
        }

        else if ( function == FUNCTION_SINH )
        {
            return ELEMENT_SINH_NAME;
        }

        else if ( function == FUNCTION_COSH )
        {
            return ELEMENT_COSH_NAME;
        }

        else if ( function == FUNCTION_TANH )
        {
            return ELEMENT_TANH_NAME;
        }

        else if ( function == FUNCTION_SECH )
        {
            return ELEMENT_SECH_NAME;
        }

        else if ( function == FUNCTION_CSCH )
        {
            return ELEMENT_CSCH_NAME;
        }

        else if ( function == FUNCTION_COTH )
        {
            return ELEMENT_COTH_NAME;
        }

        else if ( function == FUNCTION_ABS )
        {
            return ELEMENT_ABS_NAME;
        }

        else if ( function == FUNCTION_EXP )
        {
            return ELEMENT_EXP_NAME;
        }

        else if ( function == FUNCTION_LOGN )
        {
            return ELEMENT_LN_NAME;
        }

        else if ( function == FUNCTION_POW )
        {
            return ELEMENT_POWER_NAME;
        }

        else if ( function == FUNCTION_ARCSIN )
        {
            return ELEMENT_ARCSIN_NAME;
        }

        else if ( function == FUNCTION_ARCCOS )
        {
            return ELEMENT_ARCCOS_NAME;
        }

        else if ( function == FUNCTION_ARCTAN )
        {
            return ELEMENT_ARCTAN_NAME;
        }

        else if ( function == FUNCTION_ARCSEC )
        {
            return ELEMENT_ARCSEC_NAME;
        }

        else if ( function == FUNCTION_ARCCSC )
        {
            return ELEMENT_ARCCSC_NAME;
        }

        else if ( function == FUNCTION_ARCCOT )
        {
            return ELEMENT_ARCCOT_NAME;
        }

        else if ( function == FUNCTION_ARCSINH )
        {
            return ELEMENT_ARCSINH_NAME;
        }

        else if ( function == FUNCTION_ARCCOSH )
        {
            return ELEMENT_ARCCOSH_NAME;
        }

        else if ( function == FUNCTION_ARCTANH )
        {
            return ELEMENT_ARCTANH_NAME;
        }

        else if ( function == FUNCTION_ARCSECH )
        {
            return ELEMENT_ARCSECH_NAME;
        }

        else if ( function == FUNCTION_ARCCSCH )
        {
            return ELEMENT_ARCCSCH_NAME;
        }

        else if ( function == FUNCTION_ARCCOTH )
        {
            return ELEMENT_ARCCOTH_NAME;
        }

        else if ( function == FUNCTION_MIN )
        {
            return ELEMENT_MIN_NAME;
        }

        else if ( function == FUNCTION_MAX )
        {
            return ELEMENT_MAX_NAME;
        }

        else if ( function == FUNCTION_GCD )
        {
            return ELEMENT_GCD_NAME;
        }

        else if ( function == FUNCTION_LCM )
        {
            return ELEMENT_LCM_NAME;
        }

        else if ( function == FUNCTION_REM )
        {
            return ELEMENT_REM_NAME;
        }

        else if ( function == FUNCTION_FLOOR )
        {
            return ELEMENT_FLOOR_NAME;
        }

        else if ( function == FUNCTION_CEILING )
        {
            return ELEMENT_CEILING_NAME;
        }

        else if ( function == FUNCTION_FACTORIAL )
        {
            return ELEMENT_FACTORIAL_NAME;
        }

        else if ( function == FUNCTION_ROOT )
        {
            return ELEMENT_ROOT_NAME;
        }

        else if ( function == FUNCTION_LOG )
        {
            return ELEMENT_LOG_NAME;
        }

        else
        {
            return UNKNOWN_ELEMENT;
        }
    }

    //-------------------------------------------------------------------------------------------
    const String& SerializationUtil::getConstantElementName( const String& value )
    {
        if ( value == ELEMENT_TRUE_NAME )
        {
            return ELEMENT_TRUE_NAME;
        }

        else if ( value == ELEMENT_FALSE_NAME )
        {
            return ELEMENT_FALSE_NAME;
        }

        if ( value == PI_STRING_VALUE )
        {
            return ELEMENT_PI_NAME;
        }

        else if ( value == EULER_STRING_VALUE )
        {
            return ELEMENT_EXPONENTIALE_NAME;
        }

        else
        {
            return UNKNOWN_ELEMENT;
        }
    }
}
