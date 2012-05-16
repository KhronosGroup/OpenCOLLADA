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

#ifndef __MATHML_PARSER_CONSTANTS_H__
#define __MATHML_PARSER_CONSTANTS_H__

namespace MathML
{
    const static char URL_CONTAINER_ID_DELIMITER = '#';
    const static String FILE_PROTOCOL = "file:///";

    // CONSTANTS FOR XML PARSING AND REPRESENTATION
    const static String UNKNOWN_ELEMENT = "UNKNOWN_ELEMENT";
    const static String ELEMENT_APPLY_NAME = "apply";
    const static String ELEMENT_DECLARE_NAME = "declare";
    const static String ELEMENT_CN_NAME = "cn";
    const static String ELEMENT_CI_NAME = "ci";
    const static String ELEMENT_CSYMBOL_NAME = "csymbol";
    const static String ELEMENT_SEP_NAME = "sep";
    const static String ATTRIBUTE_TYPE_NAME = "type";
    const static String ATTRIBUTE_BASE_NAME = "base";
    const static String ATTRIBUTE_TYPE_VAL_RATIONAL = "rational";
    const static String ATTRIBUTE_DEFINITION_URL_NAME = "definitionURL";
    const static String ATTRIBUTE_NARGS_NAME = "nargs";
    const static String ATTRIBUTE_TYPE_VAL_FUNCTION = "function";
    const static String ATTRIBUTE_ID_NAME = "id";
    const static String ATTRIBUTE_ENCODING_NAME = "encoding";
    const static String ATTRIBUTE_ENCODING_VAL_DEFAULT = "text/xml";

    const static String ELEMENT_PI_NAME = "pi";
    const static double PI_NUMBER = 3.14159265358979;
    const static String PI_STRING_VALUE = "3.14159";
    const static String ELEMENT_EXPONENTIALE_NAME = "exponentiale";
    const static double EULERS_NUMBER = 2.718281828459;
    const static String EULER_STRING_VALUE = "2.71828";
    const static String ELEMENT_TRUE_NAME = "true";
    const static String ELEMENT_FALSE_NAME = "false";

    const static String ELEMENT_PLUS_NAME = "plus";
    const static String ELEMENT_SUM_NAME = "sum";
    const static String ELEMENT_MINUS_NAME = "minus";
    const static String ELEMENT_TIMES_NAME = "times";
    const static String ELEMENT_PRODUCT_NAME = "product";
    const static String ELEMENT_QUOTIENT_NAME = "quotient";
    const static String ELEMENT_DIVIDE_NAME = "divide";

    const static String NO_OPERATOR = "NO_OPERATOR";
    const static String OPERATOR_ADD = "+";
    const static String OPERATOR_SUB = "-";
    const static String OPERATOR_MUL = "*";
    const static String OPERATOR_DIV = "/";

    const static String ELEMENT_EQ_NAME = "eq";
    const static String ELEMENT_NEQ_NAME = "neq";
    const static String ELEMENT_LEQ_NAME = "leq";
    const static String ELEMENT_GEQ_NAME = "geq";
    const static String ELEMENT_LT_NAME = "lt";
    const static String ELEMENT_GT_NAME = "gt";
    const static String ELEMENT_EQUIVALENT_NAME = "equivalent";

    const static String NO_REL_OPERATOR = "NO_REL_OPERATOR";
    const static String REL_OPERATOR_EQ = "==";
    const static String REL_OPERATOR_NEQ = "!=";
    const static String REL_OPERATOR_LEQ = "<=";
    const static String REL_OPERATOR_GEQ = ">=";
    const static String REL_OPERATOR_LT = "<";
    const static String REL_OPERATOR_GT = ">";

    const static String ELEMENT_NOT_NAME = "not";
    const static String ELEMENT_AND_NAME = "and";
    const static String ELEMENT_OR_NAME = "or";
    const static String ELEMENT_XOR_NAME = "xor";

    const static String NO_LOGIC_OPERATOR = "NO_LOGIC_OPERATOR";
    const static String LOGIC_OPERATOR_NOT = "!";
    const static String LOGIC_OPERATOR_AND = "&&";
    const static String LOGIC_OPERATOR_OR = "||";
    const static String LOGIC_OPERATOR_XOR = "^";

    const static String ELEMENT_POWER_NAME = "power";
    const static String ELEMENT_ROOT_NAME = "root";
    const static String ELEMENT_MIN_NAME = "min";
    const static String ELEMENT_MAX_NAME = "max";
    const static String ELEMENT_GCD_NAME = "gcd";
    const static String ELEMENT_LCM_NAME = "lcm";
    const static String ELEMENT_REM_NAME = "rem";
    const static String ELEMENT_FLOOR_NAME = "floor";
    const static String ELEMENT_CEILING_NAME = "ceiling";
    const static String ELEMENT_FACTORIAL_NAME = "factorial";
    const static String ELEMENT_ABS_NAME = "abs";

    const static String ELEMENT_EXP_NAME = "exp";
    const static String ELEMENT_LN_NAME = "ln";
    const static String ELEMENT_LOG_NAME = "log";
    const static String ELEMENT_LOGBASE_NAME = "logbase";

    const static String ELEMENT_SIN_NAME = "sin";
    const static String ELEMENT_COS_NAME = "cos";
    const static String ELEMENT_TAN_NAME = "tan";
    const static String ELEMENT_SEC_NAME = "sec";
    const static String ELEMENT_CSC_NAME = "csc";
    const static String ELEMENT_COT_NAME = "cot";

    const static String ELEMENT_ARCSIN_NAME = "arcsin";
    const static String ELEMENT_ARCCOS_NAME = "arccos";
    const static String ELEMENT_ARCTAN_NAME = "arctan";
    const static String ELEMENT_ARCSEC_NAME = "arcsec";
    const static String ELEMENT_ARCCSC_NAME = "arccsc";
    const static String ELEMENT_ARCCOT_NAME = "arccot";

    const static String ELEMENT_SINH_NAME = "sinh";
    const static String ELEMENT_COSH_NAME = "cosh";
    const static String ELEMENT_TANH_NAME = "tanh";
    const static String ELEMENT_SECH_NAME = "sech";
    const static String ELEMENT_CSCH_NAME = "csch";
    const static String ELEMENT_COTH_NAME = "coth";

    const static String ELEMENT_ARCCOSH_NAME = "arccosh";
    const static String ELEMENT_ARCCOTH_NAME = "arccoth";
    const static String ELEMENT_ARCCSCH_NAME = "arccsch";
    const static String ELEMENT_ARCSECH_NAME = "arcsech";
    const static String ELEMENT_ARCSINH_NAME = "arcsinh";
    const static String ELEMENT_ARCTANH_NAME = "arctanh";



    const static String NO_FUNCTION = "NO_FUNCTION";
    const static String FUNCTION_PI = "pi";
    const static String FUNCTION_SIN = "sin";
    const static String FUNCTION_COS = "cos";
    const static String FUNCTION_TAN = "tan";
    const static String FUNCTION_SEC = "sec";
    const static String FUNCTION_CSC = "cosec";
    const static String FUNCTION_COT = "cotan";
    const static String FUNCTION_SINH = "sinh";
    const static String FUNCTION_COSH = "cosh";
    const static String FUNCTION_TANH = "tanh";
    const static String FUNCTION_SECH = "sech";
    const static String FUNCTION_CSCH = "cosech";
    const static String FUNCTION_COTH = "cotanh";
    const static String FUNCTION_ABS = "abs";
    const static String FUNCTION_EXP = "exp";
    const static String FUNCTION_LOGN = "logn";
    const static String FUNCTION_POW = "power";

    const static String FUNCTION_ARCSIN = "arcsin";
    const static String FUNCTION_ARCCOS = "arccos";
    const static String FUNCTION_ARCTAN = "arctan";
    const static String FUNCTION_ARCSEC = "arcsec";
    const static String FUNCTION_ARCCSC = "arccsc";
    const static String FUNCTION_ARCCOT = "arccotan";
    const static String FUNCTION_ARCSINH = "arcsinh";
    const static String FUNCTION_ARCCOSH = "arccosh";
    const static String FUNCTION_ARCTANH = "arctanh";
    const static String FUNCTION_ARCSECH = "arcsech";
    const static String FUNCTION_ARCCSCH = "arccsch";
    const static String FUNCTION_ARCCOTH = "arccotanh";
    const static String FUNCTION_MIN = "min";
    const static String FUNCTION_MAX = "max";
    const static String FUNCTION_GCD = "gcd";
    const static String FUNCTION_LCM = "lcm";
    const static String FUNCTION_REM = "rem";
    const static String FUNCTION_FLOOR = "floor";
    const static String FUNCTION_CEILING = "ceiling";
    const static String FUNCTION_FACTORIAL = "factorial";

    const static String FUNCTION_ROOT = "root";
    const static String FUNCTION_LOG = "log";

} //namespace MathML

#endif //__MATHML_PARSER_CONSTANTS_H__
