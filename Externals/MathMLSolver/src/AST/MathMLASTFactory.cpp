#include "MathMLSolverStableHeaders.h"
#include "MathMLASTFactory.h"
#include "MathMLParserConstants.h"
#include "MathMLASTArithmeticExpression.h"
#include "MathMLASTFunctionExpression.h"
#include "MathMLASTVariableExpression.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLASTBinaryComparisionExpression.h"
#include "MathMLASTLogicExpression.h"
#include "MathMLASTVariableExpression.h"

#include <stdarg.h>

namespace MathML 
{
	namespace AST
	{
		/**
		Helper function to add operands from a valist to a ArithmeticExpression.
		The list must be terminated with NULL!
		@param argptr The pointer to the initialized variable argument list.
		@param expr The expression to add the operands.
		*/
		void addOperands( va_list argptr, ArithmeticExpressionPtr expr )
		{
			for(NodePtr opx= va_arg( argptr, NodePtr ); !opx.isNull(); opx = va_arg( argptr, NodePtr ))
			{
				expr->addOperand(opx);
			}
		}
		void addOperands( va_list argptr, LogicExpressionPtr expr )
		{
			for(NodePtr opx= va_arg( argptr, NodePtr ); !opx.isNull(); opx = va_arg( argptr, NodePtr ))
			{
				expr->addOperand(opx);
			}
		}
		//-----------------------------------------------------------------------
		NodePtr Factory::pow( NodePtr base, NodePtr exponent )
		{
			FunctionExpressionPtr expr (new FunctionExpression(FUNCTION_POW));
			expr->addParameter(base);
			expr->addParameter(exponent);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::pow( NodePtr base, long exponent )
		{
			return pow(base, constant(exponent));
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::pow( NodePtr base, double exponent )
		{
			return pow(base, constant(exponent));
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::pow( NodePtr base, int exponent )
		{
			return pow(base, constant(exponent));
		}
		//-----------------------------------------------------------------------
		NodePtr Factory::sqrt( NodePtr value )
		{
			FunctionExpressionPtr expr( new FunctionExpression(FUNCTION_ROOT) );
			expr->addParameter(constant(2.0));
			expr->addParameter(value);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::sin( NodePtr angle )
		{
			FunctionExpressionPtr expr ( new FunctionExpression(FUNCTION_SIN) );
			expr->addParameter(angle);
			return expr;
		}
		//-----------------------------------------------------------------------
		NodePtr Factory::cos( NodePtr angle )
		{
			FunctionExpressionPtr expr ( new FunctionExpression(FUNCTION_COS) );
			expr->addParameter(angle);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::tan( NodePtr angle )
		{
			FunctionExpressionPtr expr ( new FunctionExpression(FUNCTION_TAN) );
			expr->addParameter(angle);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::asin( NodePtr angle )
		{
			FunctionExpressionPtr expr ( new FunctionExpression(FUNCTION_ARCSIN) );
			expr->addParameter(angle);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::acos( NodePtr angle )
		{
			FunctionExpressionPtr expr ( new FunctionExpression(FUNCTION_ARCCOS) );
			expr->addParameter(angle);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::atan( NodePtr angle )
		{
			FunctionExpressionPtr expr ( new FunctionExpression(FUNCTION_ARCTAN) );
			expr->addParameter(angle);
			return expr;
		}
		//-----------------------------------------------------------------------
		NodePtr Factory::plus(NodePtr op1, NodePtr op2, ...)
		{
			ArithmeticExpressionPtr expr( new ArithmeticExpression() );
			expr->setOperator(ArithmeticExpression::ADD);
			expr->addOperand(op1);
			expr->addOperand(op2);

			va_list argptr;
			va_start(argptr, op2);
			addOperands(argptr, expr);
			va_end(argptr);
			return expr;
		}
		//-----------------------------------------------------------------------
		NodePtr Factory::minus( NodePtr op1, NodePtr op2, ... )
		{
			ArithmeticExpressionPtr expr ( new ArithmeticExpression() );
			expr->setOperator(ArithmeticExpression::SUB);
			expr->addOperand(op1);
			expr->addOperand(op2);

			va_list argptr;
			va_start(argptr, op2);
			addOperands(argptr, expr);
			va_end(argptr);
			return expr;
		}
		//-----------------------------------------------------------------------
		NodePtr Factory::mul(NodePtr op1, NodePtr op2, ...)
		{
			ArithmeticExpressionPtr expr ( new ArithmeticExpression() );
			expr->setOperator(ArithmeticExpression::MUL);
			expr->addOperand(op1);
			expr->addOperand(op2);

			va_list argptr;
			va_start(argptr, op2);
			addOperands(argptr, expr);
			va_end(argptr);
			return expr;
		}
		//-----------------------------------------------------------------------
		NodePtr Factory::div(NodePtr op1, NodePtr op2, ...)
		{
			ArithmeticExpressionPtr expr ( new ArithmeticExpression() );
			expr->setOperator(ArithmeticExpression::DIV);
			expr->addOperand(op1);
			expr->addOperand(op2);

			va_list argptr;
			va_start(argptr, op2);
			addOperands(argptr, expr);
			va_end(argptr);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::constant( double d )
		{
			return NodePtr(new ConstantExpression(d));
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::constant( long d )
		{
			return NodePtr(new ConstantExpression(d));
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::constant( bool d )
		{
			return NodePtr(new ConstantExpression(d));
		}		
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::constant( int i )
		{
			return NodePtr(new ConstantExpression((long)i));
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::or( NodePtr op1, NodePtr op2, ... )
		{
			LogicExpressionPtr expr( new LogicExpression() );
			expr->setOperator(LogicExpression::OR);
			expr->addOperand(op1);
			expr->addOperand(op2);

			va_list argptr;
			va_start(argptr, op2);
			addOperands(argptr, expr);
			va_end(argptr);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::and( NodePtr op1, NodePtr op2, ... )
		{
			LogicExpressionPtr expr( new LogicExpression() );
			expr->setOperator(LogicExpression::AND);
			expr->addOperand(op1);
			expr->addOperand(op2);

			va_list argptr;
			va_start(argptr, op2);
			addOperands(argptr, expr);
			va_end(argptr);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::eq( NodePtr lhs, NodePtr rhs )
		{
			BinaryComparisonExpressionPtr expr( new BinaryComparisonExpression() );
			expr->setOperator(BinaryComparisonExpression::EQ);
			expr->setLeftOperand(lhs);
			expr->setRightOperand(rhs);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::neq( NodePtr lhs, NodePtr rhs )
		{
			BinaryComparisonExpressionPtr expr( new BinaryComparisonExpression() );
			expr->setOperator(BinaryComparisonExpression::NEQ);
			expr->setLeftOperand(lhs);
			expr->setRightOperand(rhs);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::lt( NodePtr lhs, NodePtr rhs )
		{
			BinaryComparisonExpressionPtr expr( new BinaryComparisonExpression() );
			expr->setOperator(BinaryComparisonExpression::LT);
			expr->setLeftOperand(lhs);
			expr->setRightOperand(rhs);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::gt( NodePtr lhs, NodePtr rhs )
		{
			BinaryComparisonExpressionPtr expr( new BinaryComparisonExpression() );
			expr->setOperator(BinaryComparisonExpression::GT);
			expr->setLeftOperand(lhs);
			expr->setRightOperand(rhs);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::lte( NodePtr lhs, NodePtr rhs )
		{
			BinaryComparisonExpressionPtr expr( new BinaryComparisonExpression() );
			expr->setOperator(BinaryComparisonExpression::LTE);
			expr->setLeftOperand(lhs);
			expr->setRightOperand(rhs);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::gte( NodePtr lhs, NodePtr rhs )
		{
			BinaryComparisonExpressionPtr expr( new BinaryComparisonExpression() );
			expr->setOperator(BinaryComparisonExpression::GTE);			
			expr->setLeftOperand(lhs);
			expr->setRightOperand(rhs);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::var( const String& name, double d )
		{
			VariableExpressionPtr expr ( new VariableExpression(name) );
			expr->setValue(d);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::var( const String& name, long l )
		{
			VariableExpressionPtr expr ( new VariableExpression(name) );
			expr->setValue(l);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::var( const String& name, bool b )
		{
			VariableExpressionPtr expr ( new VariableExpression(name) );
			expr->setValue(b);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::var( const String& name, int i )
		{
			VariableExpressionPtr expr ( new VariableExpression(name) );
			expr->setValue(i);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr Factory::var( const String& name, ConstantExpressionPtr value )
		{
			VariableExpressionPtr expr ( new VariableExpression(name) );
			expr->setValue(value);
			return expr;
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator+( const NodePtr& lhs, const NodePtr& rhs )
		{
			return Factory().plus(lhs, rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator+( bool lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.plus(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator+( long lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.plus(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator+( double lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.plus(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator+( const NodePtr& lhs, bool rhs )
		{
			Factory factory;
			return factory.plus(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator+( const NodePtr& lhs, long rhs )
		{
			Factory factory;
			return factory.plus(lhs, factory.constant(rhs), END);

		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator+( const NodePtr& lhs, double rhs )
		{
			Factory factory;
			return factory.plus(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator+( int lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.plus(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator+( const NodePtr& lhs, int rhs )
		{
			Factory factory;
			return factory.plus(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator-( const NodePtr& lhs, const NodePtr& rhs )
		{
			return Factory().minus(lhs, rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator-( bool lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.minus(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator-( long lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.minus(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator-( double lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.minus(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator-( const NodePtr& lhs, bool rhs )
		{
			Factory factory;
			return factory.minus(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator-( const NodePtr& lhs, long rhs )
		{
			Factory factory;
			return factory.minus(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator-( const NodePtr& lhs, double rhs )
		{
			Factory factory;
			return factory.minus(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator/( const NodePtr& lhs, const NodePtr& rhs )
		{
			return Factory().div(lhs, rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator/( bool lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.div(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator/( long lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.div(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator/( double lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.div(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator/( const NodePtr& lhs, bool rhs )
		{
			Factory factory;
			return factory.div(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator/( const NodePtr& lhs, long rhs )
		{
			Factory factory;
			return factory.div(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator/( const NodePtr& lhs, double rhs )
		{
			Factory factory;
			return factory.div(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator/( int lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.div(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator/( const NodePtr& lhs, int rhs )
		{
			Factory factory;
			return factory.div(lhs,factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator*( const NodePtr& lhs, const NodePtr& rhs )
		{
			return Factory().mul(lhs, rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator*( bool lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.mul(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator*( long lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.mul(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator*( double lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.mul(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator*( const NodePtr& lhs, bool rhs )
		{
			Factory factory;
			return factory.mul(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator*( const NodePtr& lhs, long rhs )
		{
			Factory factory;
			return factory.mul(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator*( const NodePtr& lhs, double rhs )
		{
			Factory factory;
			return factory.mul(lhs, factory.constant(rhs), END);
		}		
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator*( int lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.mul(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator*( const NodePtr& lhs, int rhs )
		{
			Factory factory;
			return factory.mul(lhs, factory.constant(rhs), END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator-( int lhs, const NodePtr& rhs )
		{
			Factory factory;
			return factory.minus(factory.constant(lhs), rhs, END);
		}
		//-----------------------------------------------------------------------
		MathML::AST::NodePtr operator-( const NodePtr& lhs, int rhs )
		{
			Factory factory;
			return factory.minus(lhs, factory.constant(rhs), END);
		}
	}
}