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

#ifndef __MATHML_SERIALIZATION_UTIL_H__
#define __MATHML_SERIALIZATION_UTIL_H__

#include "MathMLSolverPrerequisites.h"

#include "MathMLASTNode.h"
#include "MathMLASTArithmeticExpression.h"
#include "MathMLASTLogicExpression.h"
#include "MathMLASTBinaryComparisionExpression.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLASTUnaryArithmeticExpression.h"
#include "MathMLASTFragmentExpression.h"
#include "MathMLASTVariableExpression.h"
#include "MathMLASTFunctionExpression.h"
#include "MathMLASTVisitor.h"

namespace MathML
{
    /** Utility for serializing an AST as MathML.
    */

    class _MATHML_SOLVER_EXPORT SerializationUtil
    {

    private:
        /** C-tor.
        Disabled because this class contains only static methods 
        and doesn't need to be instantiated.
        */
        SerializationUtil();

    public:
        /** D-tor. */
        virtual ~SerializationUtil()
        {}

        /** Convert operator enum to element name.
        @param op Operator to be converted.
        @return MathML element name.
        */
        static const String& getArithmeticOperatorElementName( AST::ArithmeticExpression::Operator op );

        /** Convert operator enum to element name.
        @param op Operator to be converted.
        @return MathML element name.
        */
        static const String& getComparisionOperatorElementName( AST::BinaryComparisonExpression::Operator op );

        /** Convert operator enum to element name.
        @param op Operator to be converted.
        @return MathML element name.
        */
        static const String& getLogicOperatorElementName( AST::LogicExpression::Operator op );

        /** Convert operator enum to element name.
        @param op Operator to be converted.
        @return MathML element name.
        */
        static const String& getUnaryOperatorElementName( AST::UnaryExpression::Operator op );

        /** Convert function name to element name.
        @param function Function to be converted.
        @return MathML element name.
        */
        static const String& getFunctionElementName( const String& function );

        /** Convert value to element name.
        Values are e.g. true and false.
        @param value Value to be checked.
        @return MathML element name or constant UNKNOWN_ELEMENT.
        */
        static const String& getConstantElementName( const String& value );
    };

} //namespace MathML

#endif //__MATHML_SERIALIZATION_UTIL_H__
