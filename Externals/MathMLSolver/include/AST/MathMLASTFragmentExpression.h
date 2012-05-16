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

#ifndef __MATHML_AST_FRAGMENT_EXPRESSION_H___
#define __MATHML_AST_FRAGMENT_EXPRESSION_H___

#include "MathMLSolverPrerequisites.h"
#include "MathMLASTNode.h"

#include <map>
#include <set>

namespace MathML
{

    namespace AST
    {

        /** Specialized ast fragment node implementing INode. */

        class _MATHML_SOLVER_EXPORT FragmentExpression : public INode
        {

        public:
            /** Fragments may have parameters which consist of a name and a value. */
            typedef std::map<String, INode* > ParameterMap;
			typedef std::vector<INode*> ParameterList;
			typedef std::vector<String> ParameterSymbolList;
			typedef std::set<String> ParameterSymbolSet;

        private:
            /** External defined fragment. */
            INode* mFragment;
            /** Parameters of this fragment. */
            ParameterMap mParameterMap;
			ParameterList mParameterList;
			ParameterSymbolList mParameterSymbolList;
			ParameterSymbolSet mParameterSymbolSet;
            /** Name of this fragment. */
            String mName;

			/** The clone flags used when this FragmentExpression was created ore cloned.*/
			CloneFlags mCloneFlags;

            /** count of arguments */
            unsigned int mArgc;


            /** Disable copy construction to avoid expensive deep copies of big trees.
            */
            FragmentExpression( const FragmentExpression& );
            FragmentExpression& operator=( const FragmentExpression& );

        public:
            /** C-tor. */
            FragmentExpression( const String& name, CloneFlags cloneFlags = CLONEFLAG_DEFAULT );

            /** D-tor. */
            virtual ~FragmentExpression();

            // see INode::accept(IVisitor* )
            virtual void accept( IVisitor* visitor ) const;

			// see INode::getType()
			virtual NodeType getNodeType() const { return FRAGMENT; }

            /** @return a copy of this node. */
            virtual INode* clone(CloneFlags cloneFlags) const;

            /** Returns name of this fragment. */
            virtual const String& getName() const;

            /** Returns fragment itself. */
            virtual INode* getFragment() const;

            /** Sets fragment itself. */
            virtual void setFragment( INode* fragment );

            /** Returns the count of arguments. */
            virtual unsigned int getArgc() const;

            /** Sets the count of arguments. */
            virtual void setArgc( unsigned int argc );

            /** Returns all parameters of this fragment. */
            virtual const ParameterList& getParameterList() const;
			virtual const ParameterSymbolList& getParameterSymbolList() const;
			virtual const ParameterMap& getParameterMap() const;

            /** Sets all parameters of this fragment. */
            //virtual void setParameterList( const ParameterList& parameterList );

			/** Adds a symbol name for a parameter Name */
			virtual void addParameterSymbol(const String& parameterSymbol);

            /** Adds one parameter to this fragment. */
            virtual void addParameter( const String& parameterName, INode* parameter );
        };

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_FRAGMENT_EXPRESSION_H___
