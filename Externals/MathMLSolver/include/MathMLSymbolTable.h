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

#ifndef __MATHML_SYMBOL_TABLE_H___
#define __MATHML_SYMBOL_TABLE_H___

#include "MathMLSolverPrerequisites.h"
#include "MathMLString.h"
#include "MathMLASTNode.h"
#include "MathMLASTConstantExpression.h"

#include <map>

namespace MathML
{
    /** Forward Declaration. */
    class ErrorHandler;

    /** ScalarList type definition. */
    typedef std::vector< AST::ConstantExpression > ScalarList;

    /** Contains a mapping of variables and functions that may appear in an AST. */

    class _MATHML_SOLVER_EXPORT SymbolTable
    {

    public:
        /** Function pointer type definition. @todo more explaination */
        typedef void ( *FunctionPtr ) ( AST::ConstantExpression& result, const ScalarList& paramlist, ErrorHandler* errorHandler );

        /** Struct FunctionInfo.
        @par Holds the count of arguments and the function pointer.
        */

        struct FunctionInfo
        {
            /** Count of arguments. */
            int argc;

            /** The function pointer. */
            FunctionPtr func;

            /** C-tor.
            @param _arguments The count of arguments.
            @param _func The function pointer.
            */
            FunctionInfo( int _arguments = 0, FunctionPtr _func = 0 )
                    : argc( _arguments ), func( _func )
            {}

        }

        ;

        /** Map type definition holding function infos. */
        typedef std::map< String, FunctionInfo > FunctionMap;
        /** Map type definition holding INode(s). */
        typedef std::map< String, AST::INode* > VariableMap;

    private:
        /** Variables map holding INode as value for its name-key. */
        VariableMap mVariables;
        /** Functions map holding FunctionInfo as value for its name-key. */
        FunctionMap mFunctions;

        /** Error handler. */
        ErrorHandler* mErrorHandler;

    public:
        /** C-tor. */
        SymbolTable( ErrorHandler* errorHandler );
        /** D-tor. */
        virtual ~SymbolTable();

		SymbolTable(const SymbolTable& symbolTable);
		SymbolTable& operator=(const SymbolTable& symbolTable);

		/** Appends a SymbolTable to this SymbolTable. Variables or functions
		with the same name were overridden.
		@param symbolTable The SymbolTable to append.
		*/
		virtual void appendSymbolTable(const SymbolTable& symbolTable);

        /** Method for erasing a variable from map for the given mapping name.
        @par Is the key is found the INode is returned, otherwise zero.
        @param name The name key to search for in variable map.
        @return The found INode of the variable or zero.
        */
        virtual AST::INode* removeVariable( const String& name );

        /** Method for retrieving a variable from map for the given mapping name.
        @param name The name key to search for in variable map.
        @return The found INode of the variable or zero.
        */
        virtual AST::INode* getVariable( const String& name ) const;

        /** Getter of the variables map.
        @return The mapping of variables.
        */
        virtual const VariableMap& getVariables() const;

        /** Method for setting a variable in the map.
        @param name The name of the variable.
        @param value The INode representing its value (constant or any other expression).
        @todo: returning old mapping value if there is one
        */
        virtual void setVariable( const String& name, AST::INode* value );
		virtual void setVariable( const String& name, double value );
		virtual void setVariable( const String& name, long value );
		virtual void setVariable( const String& name, bool value );

        /** Method for retrieving the function info from map for the given mapping name.
        @param name The name key to search for in function map.
        @return The found FunctionInfo or 0.
		@throws InvalidParametersException if no function with the fiven name is found.
        */
        virtual const FunctionInfo* getFunction( const String& name ) const;

        /** Getter of the functions map.
        @return The mapping of functions.
        */
        virtual const FunctionMap& getFunctions() const;

        /** Method for adding a function in the map.
        @param name The name of the function.
        @param argc The count of arguments (for FunctionInfo).
        @param function The function pointer (for FunctionInfo).
        @todo: returning old mapping value if there is one
        */
        virtual void addFunction( const String& name, int argc, FunctionPtr function );

        /** Method for adding a function in the map.
        @param name The name of the function.
        @param function The function info to add to mapping.
        @todo: returning old mapping value if there is one
        */
        virtual void addFunction( const String& name, FunctionInfo function );

        /** Method for evaluating functions with given arguments.
        @param result The ConstantExpression reference for storing evaluation value.
        @param name The name of the function to evaluate.
        @param evaluatedArgs List of ConstantExpression values as arguments for the function.
        */
        virtual void evaluateFunction( AST::ConstantExpression& result, const String& name, const ScalarList& evaluatedArgs );

		/** Checks if a function exits in this symbol table.
		@param name The name of the function to evaluate.
		@return If a function with the given name exists in this symbol table.
		*/
		virtual	bool existsFunction( const String& name ) const;

		private:
			VariableMap::const_iterator findVariable(const String& name) const;
			FunctionMap::const_iterator findFunction(const String& name) const;
			VariableMap::iterator findVariable(const String& name);
			FunctionMap::iterator findFunction(const String& name);
	};
}

#endif //__MATHML_SYMBOL_TABLE_H___
