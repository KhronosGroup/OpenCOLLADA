#include "MathMLSolverStableHeaders.h"
#include "MathMLASTFragmentExpression.h"

namespace MathML
{

    namespace AST
    {
        //---------------------------------------------------------------------------------
        FragmentExpression::FragmentExpression( const String& name, CloneFlags cloneFlags  )
                : 
                  mFragment( 0 )
				, mName( name )
				, mCloneFlags( cloneFlags )
        {}

        //---------------------------------------------------------------------------------
        FragmentExpression::~FragmentExpression()
        {
			if ( mCloneFlags & CLONEFLAG_DEEPCOPY_FRAGMENT )
			{
				delete mFragment;
			}

            // Parameters have to be deleted here
			if ( mCloneFlags & CLONEFLAG_DEEPCOPY_FRAGMENT_PARAMS )
			{
				for (size_t i=0, count = mParameterList.size(); i<count; ++i)
				{
					delete mParameterList.at( i );
				}
			}
        }

        //---------------------------------------------------------------------------------
        void FragmentExpression::accept( IVisitor* visitor ) const
        {
            visitor->visit( this );
        }

        //---------------------------------------------------------------------------------
        const String& FragmentExpression::getName() const
        {
            return mName;
        }

        //---------------------------------------------------------------------------------
        unsigned int FragmentExpression::getArgc() const
        {
            return mArgc;
        }

        //---------------------------------------------------------------------------------
        void FragmentExpression::setArgc( unsigned int argc )
        {
            mArgc = argc;
        }

        //---------------------------------------------------------------------------------
        INode* FragmentExpression::getFragment() const
        {
            return mFragment;
        }

        //---------------------------------------------------------------------------------
        void FragmentExpression::setFragment( INode* fragment )
        {
            mFragment = fragment;
        }

        //---------------------------------------------------------------------------------
        const FragmentExpression::ParameterList& FragmentExpression::getParameterList() const
        {
            return mParameterList;
        }

        //---------------------------------------------------------------------------------
        /*void FragmentExpression::setParameterList( const ParameterList& parameterList )
        {
            mParameterMap = parameterList;
        }*/

        //---------------------------------------------------------------------------------
        void FragmentExpression::addParameter( const String& parameterName, INode* parameter )
        {
            mParameterMap[parameterName] = parameter;
			mParameterList.push_back(parameter);
			if (mParameterSymbolSet.find(parameterName) == mParameterSymbolSet.end())
				mParameterSymbolList.push_back(parameterName);
        }
		//-----------------------------------------------------------------------
		const FragmentExpression::ParameterMap& FragmentExpression::getParameterMap() const
		{
			return mParameterMap;
		}
		//-----------------------------------------------------------------------
		void FragmentExpression::addParameterSymbol( const String& parameterSymbol )
		{	
			if (mParameterSymbolSet.find(parameterSymbol) == mParameterSymbolSet.end())
				mParameterSymbolList.push_back(parameterSymbol);
		}
		//-----------------------------------------------------------------------
		const FragmentExpression::ParameterSymbolList& FragmentExpression::getParameterSymbolList() const
		{
			return mParameterSymbolList;
		}

        //-----------------------------------------------------------------
        INode* FragmentExpression::clone(CloneFlags cloneFlags) const
        {
            FragmentExpression* copy = new FragmentExpression( mName, cloneFlags );
            copy->mArgc = mArgc;
            if ( mFragment )
			{
				copy->mFragment = cloneFlags & CLONEFLAG_DEEPCOPY_FRAGMENT ?  mFragment->clone(cloneFlags) : mFragment;
			}
            else
			{
                copy->mFragment = 0;
			}

			if ( cloneFlags & CLONEFLAG_DEEPCOPY_FRAGMENT_PARAMS )
			{
				// A deep copy of the parameter nodes is required
				copy->mParameterList.reserve(mParameterList.size());
				ParameterMap::const_iterator it = mParameterMap.begin();
				for ( ; it != mParameterMap.end(); ++it )
				{
					const String& parameterName = it->first;
					const INode* parameterNode = it->second;
					INode* clonedParameterNode = parameterNode->clone(cloneFlags);
					copy->mParameterMap.insert(std::make_pair(parameterName, clonedParameterNode));
					copy->mParameterList.push_back(clonedParameterNode);
				}
			}
			else
			{
				copy->mParameterMap = mParameterMap;
				copy->mParameterList = mParameterList;
			}
            copy->mParameterSymbolList = mParameterSymbolList;
            copy->mParameterSymbolSet = mParameterSymbolSet;

            return copy;
        }

    } //namespace AST

} //namespace MathML
