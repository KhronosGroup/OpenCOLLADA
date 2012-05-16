#include "MathMLSolverStableHeaders.h"
#include "MathMLSymbolTable.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLError.h"

#include <string.h>

namespace MathML
{
    //---------------------------------------------------------------------------------
    SymbolTable::SymbolTable( ErrorHandler* errorHandler )
        : mErrorHandler( errorHandler )
    {}

    //-----------------------------------------------------------------------
	SymbolTable::SymbolTable( const SymbolTable& symbolTable )
	{
		mVariables = symbolTable.mVariables;
		mFunctions = symbolTable.mFunctions;
        mErrorHandler = symbolTable.mErrorHandler;
	}
    //---------------------------------------------------------------------------------
    SymbolTable::~SymbolTable()
    {}

    //---------------------------------------------------------------------------------
    AST::INode* SymbolTable::getVariable( const String& name ) const
    {
        SymbolTable::VariableMap::const_iterator it = findVariable(name);
        if ( it != mVariables.end() )
        {
            return it->second;
		}
		
        //variable not found
		return 0;
    }

    //---------------------------------------------------------------------------------
    AST::INode* SymbolTable::removeVariable( const String& name )
    {
		SymbolTable::VariableMap::iterator it = findVariable(name);

        if ( it != mVariables.end() )
        {
            AST::INode* node = ( *it ).second;
            mVariables.erase( it );
            return node;
        }

        //variable not found
        return 0;
    }

    //---------------------------------------------------------------------------------
    const SymbolTable::VariableMap& SymbolTable::getVariables() const
    {
        return mVariables;
    }

    //---------------------------------------------------------------------------------
    void SymbolTable::setVariable( const String& name, AST::INode* value )
    {		
		VariableMap::iterator iter = findVariable(name);
		if (iter == mVariables.end())
		{
			mVariables[ name ] = value;
		}
		else
		{
			mVariables[iter->first] = value;
		}
    }
	//-----------------------------------------------------------------------
	void SymbolTable::setVariable( const String& name, double value )
	{
        // TODO avoid mem leak
        setVariable(name, new AST::ConstantExpression(value));
	}
	//-----------------------------------------------------------------------
	void SymbolTable::setVariable( const String& name, long value )
	{
        // TODO avoid mem leak
		setVariable(name, new AST::ConstantExpression(value));
	}
	//-----------------------------------------------------------------------
	void SymbolTable::setVariable( const String& name, bool value )
	{
        // TODO avoid mem leak
		setVariable(name, new AST::ConstantExpression(value));
	}
	//---------------------------------------------------------------------------------
    const SymbolTable::FunctionInfo* SymbolTable::getFunction( const String& name ) const
    {
        SymbolTable::FunctionMap::const_iterator it = findFunction(name);
        if ( it != mFunctions.end() )
        {
            return &( *it ).second;
        }

        //@todo: BAD_FUNCTION_CALL
        if ( mErrorHandler )
        {
            Error error( Error::ERR_INVALIDPARAMS, "function: " + name + " not found" );
            mErrorHandler->handleError( &error );
        }
        return 0;
    }

	//---------------------------------------------------------------------------------
	bool SymbolTable::existsFunction( const String& name ) const
	{
		SymbolTable::FunctionMap::const_iterator it = findFunction( name );

		if ( it != mFunctions.end() )
		{
			return true;
		}

		return false;
	}

    //---------------------------------------------------------------------------------
    const SymbolTable::FunctionMap& SymbolTable::getFunctions() const
    {
        return mFunctions;
    }

    //---------------------------------------------------------------------------------
    void SymbolTable::addFunction( const String& name, FunctionInfo function )
    {
		FunctionMap::iterator iter = findFunction(name);
		if (iter == mFunctions.end())
		{
			mFunctions[ name ] = function;
		}
		else
		{
			mFunctions[iter->first] = function;
		}
    }

    //---------------------------------------------------------------------------------
    void SymbolTable::addFunction( const String& name, int argc, FunctionPtr function )
    {
        FunctionInfo info( argc, function );
        mFunctions[ name ] = info;
    }

    //---------------------------------------------------------------------------------
    void SymbolTable::evaluateFunction( AST::ConstantExpression& result, const String& name, const ScalarList& evaluatedArgs )
    {
        String funcname = name;

        const FunctionInfo* fi = getFunction( funcname );

        if ( !fi )
        {
            // note: getFunction( funcname ); calls errorHandler
            return;
        }

        if ( fi->argc >= -1 )    // -1 means any parameter count
        {

            if ( fi->argc == 0 && evaluatedArgs.size() != 0 )
            {
                //@todo BadFunctionCallException
                if ( mErrorHandler )
                {
                    Error err( Error::ERR_INVALIDPARAMS, "Function " + funcname + "() does not take any parameter." );
                    mErrorHandler->handleError( &err );
                }
            }

            else if ( fi->argc == 1 && evaluatedArgs.size() != 1 )
            {
                //@todo BadFunctionCallException
                if ( mErrorHandler )
                {
                    Error err( Error::ERR_INVALIDPARAMS, "Function " + funcname + "() takes exactly one parameter." );
                    mErrorHandler->handleError( &err );
                }
            }

            else if ( fi->argc == -1 )
            {
                // ok
            }

            else if ( static_cast<unsigned int>( fi->argc ) != evaluatedArgs.size() )
            {
                std::ostringstream oss;
                oss << "Function " << funcname << "() takes exactly " << fi->argc << " parameters.";
                //@todo BadFunctionCallException
                if ( mErrorHandler )
                {
                    Error err( Error::ERR_INVALIDPARAMS, oss.str() );
                    mErrorHandler->handleError( &err );
                }
            }

            fi->func( result, evaluatedArgs, mErrorHandler );
            return ;
        }


        //@todo UnknownSymbolException(std::string("Unknown function ") + funcname + "()"));
        if ( mErrorHandler )
        {
            Error err( Error::ERR_INVALIDPARAMS, "Unknown function " + funcname + "()" );
            mErrorHandler->handleError( &err );
        }
    }
	//-----------------------------------------------------------------------
	SymbolTable& SymbolTable::operator=( const SymbolTable& symbolTable )
	{
		mVariables = symbolTable.mVariables;
		mFunctions = symbolTable.mFunctions;
		return *this;
	}
	//-----------------------------------------------------------------------
	SymbolTable::VariableMap::const_iterator SymbolTable::findVariable( const String& name )const
	{
		VariableMap::const_iterator it = mVariables.find( name );

		if ( it != mVariables.end() )
		{
			return it;
		}

		for(it = mVariables.begin();it != mVariables.end(); ++it)
		{
			String key = it->first;
			if(key == name)
			{
				return it;
			}
			else if(strcmp(key.c_str(), name.c_str()) == 0)
			{
				return it;
			}
		}

		return mVariables.end();
	}
	//-----------------------------------------------------------------------
	SymbolTable::VariableMap::iterator SymbolTable::findVariable( const String& name )
	{
		VariableMap::iterator it = mVariables.find( name );

		if ( it != mVariables.end() )
		{
			return it;
		}

		for(it = mVariables.begin();it != mVariables.end(); ++it)
		{
			String key = it->first;
			if(key == name)
			{
				return it;
			}
			else if(strcmp(key.c_str(), name.c_str()) == 0)
			{
				return it;
			}
		}

		return mVariables.end();
	}
	//-----------------------------------------------------------------------
	SymbolTable::FunctionMap::const_iterator SymbolTable::findFunction( const String& name )const
	{
		FunctionMap::const_iterator it = mFunctions.find( name );

		if ( it != mFunctions.end() )
		{
			return it;
		}

		for(it = mFunctions.begin();it != mFunctions.end(); ++it)
		{
			String key = it->first;
			if(key == name)
			{
				return it;
			}
			else if(strcmp(key.c_str(), name.c_str()) == 0)
			{
				return it;
			}
		}

		return mFunctions.end();
	}
	//-----------------------------------------------------------------------
	SymbolTable::FunctionMap::iterator SymbolTable::findFunction( const String& name )
	{
		FunctionMap::iterator it = mFunctions.find( name );

		if ( it != mFunctions.end() )
		{
			return it;
		}

		for(it = mFunctions.begin();it != mFunctions.end(); ++it)
		{
			String key = it->first;
			if(key == name)
			{
				return it;
			}
			else if(strcmp(key.c_str(), name.c_str()) == 0)
			{
				return it;
			}
		}

		return mFunctions.end();
	}
	//-----------------------------------------------------------------------
	void SymbolTable::appendSymbolTable( const SymbolTable& symbolTable )
	{
		VariableMap::const_iterator itVar = symbolTable.mVariables.begin();
		for (; itVar != symbolTable.mVariables.end(); ++itVar)
		{
			setVariable(itVar->first, itVar->second);
		}

		FunctionMap::const_iterator itFunc = symbolTable.mFunctions.begin();
		for (; itFunc != symbolTable.mFunctions.end(); ++itFunc)
		{
			addFunction(itFunc->first, itFunc->second);
		}
	}
} //namespace MathML
