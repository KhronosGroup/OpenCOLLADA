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

#ifndef __MATHML_AST_FUNCTION_EXPRESSION_H___
#define __MATHML_AST_FUNCTION_EXPRESSION_H___

#include "MathMLSolverPrerequisites.h"
#include "MathMLASTNode.h"

namespace MathML
{

    namespace AST
    {

        /** Specialized function node implementing INode. */

        class _MATHML_SOLVER_EXPORT FunctionExpression : public INode
        {

        private:
            /** Name of the function. */
            String mName;

            /** Argument list of the function. */
            NodeList mParameterList;

            /** Disable copy construction to avoid expensive deep copies of big trees.
            */
            FunctionExpression( const FunctionExpression& );
            FunctionExpression& operator=( const FunctionExpression& );

        public:

            /** D-tor. */
            virtual ~FunctionExpression();

            /** Initializing constructor.
            @param name The name of the function to initialize with.
            */
            FunctionExpression( const String& name );

            // see INode::accept(IVisitor* )
            virtual void accept( IVisitor* visitor ) const;

			// see INode::getType()
			virtual NodeType getNodeType() const { return FUNCTION; }

            /** @return a copy of this node. */
            virtual INode* clone(CloneFlags cloneFlags) const;

            /** Getter for the function name.
            @return Name of function.
            */
            virtual const String& getName() const;

			/** Getter of function parameterList.
			@return NodeList of function parameters.
			*/
			virtual const NodeList& getParameterList() const;

			/** Getter of function parameterList.
			@return NodeList of function parameters.
			*/
			virtual NodeList& getParameterList();

            /** Setter for the parameter list.
            @param parameterList The list to set as function arguments.
            */
            virtual void setParameterList( const NodeList& parameterList );

            /** Adding a parameter to the function argument list.
            @param parameter Node to add as parameter to the function argument list.
            */
            virtual void addParameter( INode* parameter );
        };

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_FUNCTION_EXPRESSION_H___
