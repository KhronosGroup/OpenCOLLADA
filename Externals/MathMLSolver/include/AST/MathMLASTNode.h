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

#ifndef __MATHML_AST_NODE_H___
#define __MATHML_AST_NODE_H___

#include "MathMLSolverPrerequisites.h"
#include "MathMLString.h"
#include <vector>
#include <map>

namespace MathML
{
    namespace AST
    {
        /** Forward declaration. */
        class IVisitor;

        /** Interface of AST node. */
        class _MATHML_SOLVER_EXPORT INode
        {
		public:
			enum NodeType {
				CONSTANT, UNARY, VARIABLE, LOGICAL, COMPARISON, ARITHMETIC, FUNCTION, FRAGMENT, USERDEFINED
			};

			enum CloneFlags 
			{
				CLONEFLAG_NO                            =     0,
				CLONEFLAG_DEEPCOPY_FRAGMENT             =  1<<0,    //Enforces deep copies of fragments
				CLONEFLAG_DEEPCOPY_FRAGMENT_PARAMS      =  1<<1,    //Enforces deep copies of fragments

				CLONEFLAG_DEFAULT                = CLONEFLAG_NO
			};

        private:
            /** Disable copy construction to avoid expensive deep copies of big trees.
            */
            INode( const INode& );
            INode& operator=( const INode& );

        public:
            /** C-tor. */
            INode()
            {}

            ;
            /** D-tor. */
            virtual ~INode()
            {}

            /** AST node accepting visitors of interface IVisitor.
            @param visitor The visitor for inspection of this node.
            */
            virtual void accept( IVisitor* visitor ) const = 0;

			/** @return The type of the AST node. */
			virtual NodeType getNodeType() const = 0;

            /** @return a copy of this node. */
            virtual INode* clone(CloneFlags cloneFlags = CLONEFLAG_DEFAULT) const = 0;
        };
		
		/** Typedef for list of AST nodes. */
		typedef std::vector<INode*> NodeList;

        /** Typedef for map of string to AST nodes. */
		typedef std::map<String, INode*> NodeMap;

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_NODE_H___
