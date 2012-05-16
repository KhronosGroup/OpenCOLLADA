#include "MathMLSolverStableHeaders.h"
#include "MathMLASTFunctionExpression.h"

namespace MathML
{

    namespace AST
    {
        //---------------------------------------------------------------------------------
        FunctionExpression::FunctionExpression( const String& name )
            : mName( name )
        {}

        //---------------------------------------------------------------------------------
        FunctionExpression::~FunctionExpression()
        {
            for (size_t i=0; i<mParameterList.size(); ++i)
            {
                delete mParameterList.at( i );
            }
        }

        //---------------------------------------------------------------------------------
        void FunctionExpression::accept( IVisitor* visitor ) const
        {
            visitor->visit( this );
        }

        //---------------------------------------------------------------------------------
        const String& FunctionExpression::getName() const
        {
            return mName;
        }

		//---------------------------------------------------------------------------------
		const NodeList& FunctionExpression::getParameterList() const
		{
			return mParameterList;
		}

		//---------------------------------------------------------------------------------
		NodeList& FunctionExpression::getParameterList()
		{
			return mParameterList;
		}

        //---------------------------------------------------------------------------------
        void FunctionExpression::setParameterList( const NodeList& parameterList )
        {
            mParameterList = parameterList;
        }

        //---------------------------------------------------------------------------------
        void FunctionExpression::addParameter( INode* parameter )
        {
            mParameterList.push_back( parameter );
        }

        //-----------------------------------------------------------------
        INode* FunctionExpression::clone(CloneFlags cloneFlags) const
        {
            FunctionExpression* copy = new FunctionExpression( mName );
            for (size_t i=0; i<mParameterList.size(); ++i)
            {
                copy->mParameterList.push_back( mParameterList.at( i )->clone(cloneFlags) );
            }
            return copy;
        }

    } //namespace AST

} //namespace MathML
