#include "MathMLSolverStableHeaders.h"
#include "MathMLASTVariableExpression.h"

namespace MathML
{

    namespace AST
    {
        //---------------------------------------------------------------------------------
        VariableExpression::VariableExpression( const String& name )
                : mName( name )
                , mValue( 0 )
        {}

        //---------------------------------------------------------------------------------
        VariableExpression::~VariableExpression()
        {
            delete mValue;
        }

        //---------------------------------------------------------------------------------
        void VariableExpression::accept( IVisitor* visitor ) const
        {
            visitor->visit( this );
        }

        //---------------------------------------------------------------------------------
        const String& VariableExpression::getName() const
        {
            return mName;
        }

        //---------------------------------------------------------------------------------
        const ConstantExpression* VariableExpression::getValue() const
        {
            return mValue;
        }

        //---------------------------------------------------------------------------------
        void VariableExpression::setValue( ConstantExpression* value )
        {
            mValue = value;
        }
		//-----------------------------------------------------------------------
		void VariableExpression::setValue( int value )
		{
			setValue(new ConstantExpression((long)value));
		}
		//-----------------------------------------------------------------------
		void VariableExpression::setValue( long value )
		{
			setValue(new ConstantExpression(value));
		}
		//-----------------------------------------------------------------------
		void VariableExpression::setValue( double value )
		{
			setValue(new ConstantExpression(value));
		}	
		//-----------------------------------------------------------------------
		void VariableExpression::setValue( bool value )
		{
			setValue(new ConstantExpression(value));
		}

        //-----------------------------------------------------------------
        INode* VariableExpression::clone(CloneFlags cloneFlags) const
        {
            VariableExpression* copy = new VariableExpression( mName );

            if ( mValue )
                copy->mValue = static_cast<MathML::AST::ConstantExpression *>( mValue->clone(cloneFlags) );
            else
                copy->mValue = 0;

            return copy;
        }

    } //namespace AST

} //namespace MathML
