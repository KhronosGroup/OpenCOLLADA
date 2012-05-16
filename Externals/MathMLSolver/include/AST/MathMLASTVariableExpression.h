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

#ifndef __MATHML_AST_VARIABLE_EXPRESSION_H___
#define __MATHML_AST_VARIABLE_EXPRESSION_H___

#include "MathMLSolverPrerequisites.h"
#include "MathMLString.h"
#include "MathMLASTNode.h"
#include "MathMLASTConstantExpression.h"

namespace MathML
{

    namespace AST
    {

        /** Specialized variable node implementing INode. */

        class _MATHML_SOLVER_EXPORT VariableExpression : public INode
        {

        private:
            /** The name of the variable. */
            String mName;

            /** The value of the variable. */
            ConstantExpression* mValue;

        public:
            /** Initializing constructor.
            @param name The name of the variable
            */
            VariableExpression( const String& name );

            /** D-tor. */
            virtual ~VariableExpression();

            // see INode::accept(IVisitor* )
            virtual void accept( IVisitor* visitor ) const;

			// see INode::getType()
			virtual NodeType getNodeType() const { return VARIABLE; }

            /** @return a copy of this node. */
            virtual INode* clone(CloneFlags cloneFlags) const;

            /** Getter for the name of the variable.
            @return The name of the variable.	
            */
            virtual const String& getName() const;

            /** Getter for value of the variable.
            @par If variable is not initialized, the scalar holding the value is
            of type 'SCALAR_INVALID'.
            @return The ConstantExpression holding the value of the variable.
            */
            virtual const ConstantExpression* getValue() const;

            /** Setter for the value of the variable.
            @param value The ConstantExpression to set as value.
            */
            virtual void setValue( ConstantExpression* value ) ;
			virtual void setValue( int value ) ;
			virtual void setValue( long value ) ;
			virtual void setValue( double value ) ;
			virtual void setValue( bool value ) ;
        };

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_VARIABLE_EXPRESSION_H___
