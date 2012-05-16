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

#ifndef __MATHML_AST_CONSTANT_EXPRESSION_H___
#define __MATHML_AST_CONSTANT_EXPRESSION_H___

#include "MathMLSolverPrerequisites.h"
#include "MathMLASTNode.h"
#include "MathMLASTArithmeticExpression.h"
#include "MathMLASTUnaryArithmeticExpression.h"
#include "MathMLASTBinaryComparisionExpression.h"
#include "MathMLASTLogicExpression.h"
#include "MathMLError.h"


namespace MathML
{

    /** Forward Declaration. */
    class ErrorHandler;

    namespace AST
    {

        /** Specialized constant node implementing INode. */

        class _MATHML_SOLVER_EXPORT ConstantExpression : public INode
        {

        public:
            /** The type of scalar value. */
            enum Type
            {
                SCALAR_INVALID,
                SCALAR_BOOL,
                SCALAR_LONG,
                SCALAR_DOUBLE
            };

        private:
            /** Type of scalar. */
            Type mType;

            /** Value of scalar. */
            double mValue;

            /** The string value... */
            String mStringValue;

            /** Error handler. */
            ErrorHandler* mErrorHandler;

        public:
            /** Enable copy construction to avoid expensive deep copies of big trees.
            */
            ConstantExpression( const ConstantExpression& ref );

            // see INode::accept(IVisitor* )
            virtual void accept( IVisitor* visitor ) const;

			// see INode::getType()
			virtual NodeType getNodeType() const { return CONSTANT; }

            /** @return a copy of this node. */
            virtual INode* clone(CloneFlags cloneFlags) const;

            /** Default C-tor. */
            ConstantExpression();

            /** D-tor. */
            virtual ~ConstantExpression();

            /** Assignment from the string received from the parser.
            @param str The string containing the constant value.
            @param type The scalar type to set.
            */
            ConstantExpression( const MathML::String& str, Type type );

            /** constructor for folded constant values.
            @param str The string containing the string value (NOT for scalar value).
            */
            ConstantExpression( const MathML::String& str );

            /** Initializing constructor.
            @param val The double value to initialize with.
            */
            ConstantExpression( double val );

            /** Initializing constructor.
            @param val The long value to initialize with.
            */
            ConstantExpression( long val );

            /** Initializing constructor.
            @param val The bool value to initialize with.
            */
            ConstantExpression( bool val );

            /** Setter for double value.
            @param str The string to set as value.
            @param type The type of scalar value.
            */
            virtual void setValue( const String& str, Type type );

            /** Setter for double value.
            @param val The double value to set.
            */
            virtual void setValue( double val );

            /** Setter for double value.
            @param val The double value to set.
            */
            virtual void setValue( long val );

            /** Setter for bool value.
            @param val The bool value to set.
            */
            virtual void setValue( bool val );

            /** Getting the type of the scalar.
            @return The type of the scalar value.
            */
            virtual Type getType() const;

            /** Getting the double value.
            @return The double value of scalar.
            */
            virtual double getDoubleValue() const;

            /** Getting the long value.
            @return The long value of scalar.
            */
            virtual long getLongValue() const;

            /** Getting the unsigned long value.
            @return The unsigned long value of scalar.
            */
            virtual unsigned long getUnsignedLongValue() const;

            /** Getting the bool value.
            @return The bool value of scalar.
            */
            virtual bool getBoolValue() const;

            /** Returns the string value. */
            virtual const MathML::String& getStringValue() const;

            /** Sets the string value. */
            virtual void setStringValue( const MathML::String& );

            /** Returns the ConstantExpression string. */
            virtual MathML::String toString() const;


            /** @return Currently set error handler. */
            virtual ErrorHandler* getErrorHandler() {return mErrorHandler;}
            /** Sets error handler to be used. */
            virtual void setErrorHandler( ErrorHandler* errorHandler){mErrorHandler = errorHandler;}

            inline ConstantExpression& operator=( const ConstantExpression &a )
            {
                // check if we are to assign ourself

                if ( this == &a )
                    return * this;

                mType = a.mType;

                switch ( mType )
                {

                case SCALAR_INVALID:
                    //assert(0);
                    break;

                default:
                    mValue = a.mValue;
                    break;
                }

                return *this;
            }

            inline ConstantExpression operator==( const ConstantExpression &a ) const
            {
                ConstantExpression result;
                relationalBinaryOperation( result, a, AST::BinaryComparisonExpression::EQ );
                return result;
            }

            inline ConstantExpression operator!=( const ConstantExpression &a ) const
            {
                ConstantExpression result;
                relationalBinaryOperation( result, a, AST::BinaryComparisonExpression::NEQ );
                return result;
            }

            inline ConstantExpression operator<( const ConstantExpression &a ) const
            {
                ConstantExpression result;
                relationalBinaryOperation( result, a, AST::BinaryComparisonExpression::LT );
                return result;
            }

            inline ConstantExpression operator>( const ConstantExpression &a ) const
            {
                ConstantExpression result;
                relationalBinaryOperation( result, a, AST::BinaryComparisonExpression::GT );
                return result;
            }

            inline ConstantExpression operator<=( const ConstantExpression &a ) const
            {
                ConstantExpression result;
                relationalBinaryOperation( result, a, AST::BinaryComparisonExpression::LTE );
                return result;
            }

            inline ConstantExpression operator>=( const ConstantExpression &a ) const
            {
                ConstantExpression result;
                relationalBinaryOperation( result, a, AST::BinaryComparisonExpression::GTE );
                return result;
            }

            inline ConstantExpression operator+() const
            {
                ConstantExpression result;
                unaryOperation( result, AST::UnaryExpression::ADD );
                return result;
            }

            inline ConstantExpression operator-() const
            {
                ConstantExpression result;
                unaryOperation( result, AST::UnaryExpression::SUB );
                return result;
            }

            inline ConstantExpression operator!() const
            {
                ConstantExpression result;
                unaryOperation( result, AST::UnaryExpression::NOT );
                return result;
            }

            inline ConstantExpression operator+( const ConstantExpression &b ) const
            {
                ConstantExpression result;
                arithmeticalBinaryOperation( result, b, AST::ArithmeticExpression::ADD );
                return result;
            }

            inline ConstantExpression operator-( const ConstantExpression &b ) const
            {
                ConstantExpression result;
                arithmeticalBinaryOperation( result, b, AST::ArithmeticExpression::SUB );
                return result;
            }

            inline ConstantExpression operator*( const ConstantExpression &b ) const
            {
                ConstantExpression result;
                arithmeticalBinaryOperation( result, b, AST::ArithmeticExpression::MUL );
                return result;
            }

            inline ConstantExpression operator/( const ConstantExpression &b ) const
            {
                ConstantExpression result;
                arithmeticalBinaryOperation( result, b, AST::ArithmeticExpression::DIV );
                return result;
            }

            inline ConstantExpression operator&&( const ConstantExpression &b ) const
            {
                ConstantExpression result;
                logicalBinaryOperation( result, b, AST::LogicExpression::AND );
                return result;
            }

            inline ConstantExpression operator||( const ConstantExpression &b ) const
            {
                ConstantExpression result;
                logicalBinaryOperation( result, b, AST::LogicExpression::OR );
                return result;
            }

            inline ConstantExpression operator^( const ConstantExpression &b ) const
            {
                ConstantExpression result;
                logicalBinaryOperation( result, b, AST::LogicExpression::XOR );
                return result;
            }


        private:
            /** Called by operators to perform operations: +,-,*,/.
            Does type checking and calls template method to perform the operation.
            @param result The ConstantExpression reference for storing the result of the operation.
            @param rhs The second operand (the first is 'this').
            @param op The operator to use.
            */
            void arithmeticalBinaryOperation( ConstantExpression& result, const ConstantExpression& rhs, ArithmeticExpression::Operator op ) const;

            /** Called by operators to perform operations: +,-,*,/.
            Performs the operation without type checking.
            Intended type parameters are long and double.
            @param result The ConstantExpression reference for storing the result of the operation.
            @param lhs The first operand.
            @param rhs The second operand.
            @param op The operator to use.
            */

            template < typename T >
            void arithmeticalBinaryOperation( ConstantExpression& result, const T& lhs, const T& rhs, ArithmeticExpression::Operator op ) const;

            /** Called by operators to perform unary operations: +,-,!.
            Does type checking and calls template method to perform the operation.
            Logical not is performed directly.
            @param result The ConstantExpression reference for storing the result of the operation.
            @param op The operator to use.
            */
            void unaryOperation( ConstantExpression& result, UnaryExpression::Operator op ) const;

            /** Called by operators to perform unary operations: +,-.
            Performs the operation without type checking.
            Intended type parameters are long and double.
            @param operand The operand.
            @param op The operator to use.
            @return Returns the result of the operation as primitive type.
            */
            template < typename T >
            T unaryOperation( const T& operand, UnaryExpression::Operator op ) const;

            /** Called by operators to perform operations: ==,!=,<,>,<=,>=.
            Does type checking and performs the operation.
            @param result The ConstantExpression reference for storing the result of the operation.
            @param rhs The second operand (the first is 'this').
            @param op The operator to use.
            */
            void relationalBinaryOperation( ConstantExpression& result, const ConstantExpression& rhs, BinaryComparisonExpression::Operator op ) const;

            /** Called by operators to perform operations: &&,||,^.
            Does type checking and performs the operation.
            @param result The ConstantExpression reference for storing the result of the operation.
            @param rhs The second operand (the first is 'this').
            @param op The operator to use.
            */
            void logicalBinaryOperation( ConstantExpression& result, const ConstantExpression& rhs, LogicExpression::Operator op ) const;
        };


        //-------------------------------------------------------------------------

        template < typename T >
        void ConstantExpression::arithmeticalBinaryOperation( ConstantExpression& result, const T& lhs, const T& rhs, ArithmeticExpression::Operator op ) const
        {
            switch ( op )
            {

            case AST::ArithmeticExpression::ADD:
                result.setValue( lhs + rhs );
                return ;

            case AST::ArithmeticExpression::SUB:
                result.setValue( lhs - rhs );
                break;

            case AST::ArithmeticExpression::MUL:
                result.setValue( lhs * rhs );
                break;

            case AST::ArithmeticExpression::DIV:

                if ( rhs == 0 )
                {
                    if ( mErrorHandler )
                    {
                        Error error( Error::ERR_INVALIDPARAMS, "division by zero" );
                        mErrorHandler->handleError( &error );
                        result.setValue( 0. );
                        return;
                    }
                }

                result.setValue( lhs / rhs );
                break;

            default:
                if ( mErrorHandler )
                {
                    Error error( Error::ERR_INVALIDPARAMS, "invalid operator: " + ArithmeticExpression::operatorString( op ) );
                    mErrorHandler->handleError( &error );
                    result.setValue( 0. );
                    return;
                }
            }
        }

        //-------------------------------------------------------------------------
        template < typename T >
        T ConstantExpression::unaryOperation( const T& operand, UnaryExpression::Operator op ) const
        {
            switch ( op )
            {

            case AST::UnaryExpression::ADD:
                //do nothing
                return operand;

            case AST::UnaryExpression::SUB:
                return ( -operand );

            case AST::UnaryExpression::NOT:
                return ( !operand );

            default:
                std::ostringstream oss;
                oss << "invalid operator: " << AST::UnaryExpression::operatorString( op ) << ", cause operand not of type 'bool' [f, t]";
                if ( mErrorHandler )
                {
                    Error error( Error::ERR_INVALIDPARAMS, oss.str() );
                    mErrorHandler->handleError( &error );
                    return operand;
                }
            }
            return operand;
        }

    } //namespace AST

} //namespace MathML

#endif //__MATHML_AST_CONSTANT_EXPRESSION_H___
