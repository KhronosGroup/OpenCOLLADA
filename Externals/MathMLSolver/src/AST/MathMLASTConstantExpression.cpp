#include "MathMLSolverStableHeaders.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLError.h"

#include "MathMLString.h"

namespace MathML
{

    namespace AST
    {

        /** String constant for a Scalar with an invalid value. */
        const static String SCALAR_INVALID_VALUE = "INVALID";
        /** String constant for a Scalar with the boolean value false. */
        const static String SCALAR_FALSE_VALUE = "false";
        /** String constant for a Scalar with the boolean value true. */
        const static String SCALAR_TRUE_VALUE = "true";


        //---------------------------------------------------------------------------------
        void ConstantExpression::accept( IVisitor* visitor ) const
        {
            visitor->visit( this );
        }

        //---------------------------------------------------------------------------------
        ConstantExpression::ConstantExpression( const ConstantExpression& ref )
                : mType ( ref.mType )
                , mValue ( ref.mValue )
                , mStringValue ( ref.mStringValue )
                , mErrorHandler( 0 )
        {}

        //---------------------------------------------------------------------------------
        ConstantExpression::ConstantExpression()
                : mType ( SCALAR_INVALID )
                , mErrorHandler( 0 )
        {}

        //---------------------------------------------------------------------------------
        ConstantExpression::~ConstantExpression()
        {}

        //---------------------------------------------------------------------------------
        ConstantExpression::ConstantExpression( const MathML::String& str, Type type )
                : mType ( type )
                , mErrorHandler( 0 )
        {

            switch ( type )
            {

            case SCALAR_INVALID:
                break;

            case SCALAR_DOUBLE:
                mValue = StringUtil::parseDouble( str );
                //mValue = 1.0;
                break;

            case SCALAR_LONG:
                mValue = StringUtil::parseLong( str );
                break;

            case SCALAR_BOOL:
                mValue = ( str.size() > 0 && ( str[ 0 ] == 'f' || str[ 0 ] == 'F' ) ) ? 0. : 1.;
                break;

            default:
                //@todo: exception
                break;
            }

        }

        //---------------------------------------------------------------------------------
        ConstantExpression::ConstantExpression( const MathML::String& str )
                : mStringValue ( str )
                , mErrorHandler( 0 )
        {}

        //-------------------------------------------------------------------------
        ConstantExpression::ConstantExpression( double val )
        {
            setValue( val );
        }

        //-------------------------------------------------------------------------
        ConstantExpression::ConstantExpression( long val )
        {
            setValue( val );
        }

        //-------------------------------------------------------------------------
        ConstantExpression::ConstantExpression( bool val )
        {
            setValue( val );
        }

        //-------------------------------------------------------------------------
        void ConstantExpression::setValue( const String& str, Type type )
        {
            switch ( type )
            {

            case SCALAR_INVALID:
                break;

            case SCALAR_DOUBLE:
                mValue = StringUtil::parseDouble( str );
                mType = SCALAR_DOUBLE;
                //mValue = 1.0;
                break;

            case SCALAR_LONG:
                mValue = StringUtil::parseLong( str );
                mType = SCALAR_LONG;
                break;

            case SCALAR_BOOL:
                mValue = ( str.size() > 0 && ( str[ 0 ] == 'f' || str[ 0 ] == 'F' ) ) ? 0. : 1.;
                mType = SCALAR_BOOL;
                break;

            default:
                //@todo: exception
                break;
            }
        }

        //-------------------------------------------------------------------------
        void ConstantExpression::setValue( double val )
        {
            mType = SCALAR_DOUBLE;
            mValue = val;
        }

        //-------------------------------------------------------------------------
        void ConstantExpression::setValue( long val )
        {
            mType = SCALAR_LONG;
            mValue = static_cast<double>( val );
        }

        //-------------------------------------------------------------------------
        void ConstantExpression::setValue( bool val )
        {
            mType = SCALAR_BOOL;
            mValue = val ? 1. : 0.;
        }

        //-------------------------------------------------------------------------
        ConstantExpression::Type ConstantExpression::getType() const
        {
            return mType;
        }

        //-------------------------------------------------------------------------
        double ConstantExpression::getDoubleValue() const
        {
            return mValue;
        }

        //-------------------------------------------------------------------------
        long ConstantExpression::getLongValue() const
        {
            return static_cast<long>( mValue );
        }

        //-------------------------------------------------------------------------
        unsigned long ConstantExpression::getUnsignedLongValue() const
        {
            if ( mValue < 0 )
            {
                if ( mErrorHandler )
                {
                    Error error( Error::ERR_INTERNAL_ERROR, "could not convert to unsigned cause value is negative!" );
                    mErrorHandler->handleError( &error );
                    return 0;
                }
            }

            return static_cast<long>( mValue );
        }

        //-------------------------------------------------------------------------
        bool ConstantExpression::getBoolValue() const
        {
            return ( mValue == 0. ) ? false : true;
        }

        //-------------------------------------------------------------------------
        void ConstantExpression::arithmeticalBinaryOperation( ConstantExpression& result, const ConstantExpression& rhs, AST::ArithmeticExpression::Operator op ) const
        {
            if ( this->getType() == SCALAR_INVALID || rhs.getType() == SCALAR_INVALID )
            {
                if ( mErrorHandler )
                {
                    Error error( Error::ERR_INVALIDPARAMS, "uninitilized operand(s)" );
                    mErrorHandler->handleError( &error );
                }
                result.setValue( 0. );
                return;
            }

            else if ( (this->getType() == SCALAR_BOOL && rhs.getType() == SCALAR_LONG) || (this->getType() == SCALAR_LONG && rhs.getType() == SCALAR_BOOL) )
            {				
				long val1 = this->getLongValue();
				long val2 = rhs.getLongValue();
				arithmeticalBinaryOperation( result, val1, val2, op );
            }

            else if ( this->getType() == SCALAR_LONG && rhs.getType() == SCALAR_LONG )
            {
                long val1 = this->getLongValue();
                long val2 = rhs.getLongValue();
                arithmeticalBinaryOperation( result, val1, val2, op );
            }

            else
            {
                double val1 = this->getDoubleValue();
                double val2 = rhs.getDoubleValue();
                arithmeticalBinaryOperation( result, val1, val2, op );
            }
        }

        //-------------------------------------------------------------------------
        void ConstantExpression::unaryOperation( ConstantExpression& result, AST::UnaryExpression::Operator op ) const
        {
            if ( this->getType() == SCALAR_INVALID )
            {
                if ( mErrorHandler )
                {
                    Error err( Error::ERR_INVALIDPARAMS, "uninitilized operand" );
                    mErrorHandler->handleError( &err );
                }
                result.setValue( 0. );
                return;
            }

            else if ( this->getType() == SCALAR_BOOL && op != AST::UnaryExpression::NOT )
            {
                if ( mErrorHandler )
                {
                    Error err( Error::ERR_INVALIDPARAMS, "boolean operand in arithmetical operation" );
                    mErrorHandler->handleError( &err );
                }
                result.setValue( 0. );
                return;
            }

            else if ( this->getType() == SCALAR_BOOL && op == AST::UnaryExpression::NOT )
            {
                result.setValue( !this->getBoolValue() );
            }

            else if ( this->getType() == SCALAR_LONG )
            {
                result.setValue( unaryOperation( this->getLongValue(), op ) );
            }

            else
            {
                result.setValue( unaryOperation( this->getDoubleValue(), op ) );
            }
        }

        //-------------------------------------------------------------------------
        void ConstantExpression::relationalBinaryOperation( ConstantExpression& result, const ConstantExpression& rhs, AST::BinaryComparisonExpression::Operator op ) const
        {
            if ( this->getType() == SCALAR_INVALID || rhs.getType() == SCALAR_INVALID )
            {
                if ( mErrorHandler )
                {
                    Error err( Error::ERR_INVALIDPARAMS, "uninitilized operand(s)" );
                    mErrorHandler->handleError( &err );
                }
                result.setValue( 0. );
                return;
            }

            else if ( this->getType() == SCALAR_BOOL || rhs.getType() == SCALAR_BOOL )
            {
                //check if both bool

                if ( this->getType() != rhs.getType() )
                {
                    if ( mErrorHandler )
                    {
                        Error err( Error::ERR_INVALIDPARAMS, "not both operands of type boolean for binary comparison operation" );
                        mErrorHandler->handleError( &err );
                    }
                    result.setValue( 0. );
                    return;
                }

                // valid ==
                if ( op == AST::BinaryComparisonExpression::EQ )
                {
                    result.setValue( this->getLongValue() == rhs.getLongValue() );
                    return ;
                }

                // valid !=
                else if ( op == AST::BinaryComparisonExpression::NEQ )
                {
                    result.setValue( this->getLongValue() != rhs.getLongValue() );
                    return ;
                }

                //invalid: <, <=, >, ..
                if ( mErrorHandler )
                {
                    Error err( Error::ERR_INVALIDPARAMS, "boolean operand(s) not allowed for this kind of binary comparision operation" );
                    mErrorHandler->handleError( &err );
                }
                result.setValue( 0. );
                return;
            }

            //only double or long values
            else
            {
                double val1 = this->getDoubleValue();
                double val2 = rhs.getDoubleValue();

                switch ( op )
                {

                case AST::BinaryComparisonExpression::EQ:
                    result.setValue( val1 == val2 );
                    return ;

                case AST::BinaryComparisonExpression::NEQ:
                    result.setValue( val1 != val2 );
                    return ;

                case AST::BinaryComparisonExpression::LT:
                    result.setValue( val1 < val2 );
                    return ;

                case AST::BinaryComparisonExpression::LTE:
                    result.setValue( val1 <= val2 );
                    return ;

                case AST::BinaryComparisonExpression::GT:
                    result.setValue( val1 > val2 );
                    return ;

                case AST::BinaryComparisonExpression::GTE:
                    result.setValue( val1 >= val2 );
                    return ;

                default:
                    if ( mErrorHandler )
                    {
                        Error err( Error::ERR_INVALIDPARAMS, "invalid operator: " + AST::BinaryComparisonExpression::operatorString( op ) );
                        mErrorHandler->handleError( &err );
                    }
                    result.setValue( 0. );
                    return;
                }
            }
        }

        //-------------------------------------------------------------------------
        void ConstantExpression::logicalBinaryOperation( ConstantExpression& result, const ConstantExpression& rhs, AST::LogicExpression::Operator op ) const
        {
            // accept non bool values !
            //if ( this->getType() != SCALAR_BOOL || rhs.getType() != SCALAR_BOOL )
            //{
            //    MML_EXCEPT( MathML::Exception::ERR_INVALIDPARAMS, "boolean operand in arithmetical operation", "ConstantExpression::logicalBinaryOperation" );
            //}
            switch ( op )
            {

            case AST::LogicExpression::AND:
                result.setValue( this->getBoolValue() && rhs.getBoolValue() );
                return ;

            case AST::LogicExpression::OR:
                result.setValue( this->getBoolValue() || rhs.getBoolValue() );
                return ;

            case AST::LogicExpression::XOR:
                result.setValue( ( bool ) ( this->getBoolValue() ^ rhs.getBoolValue() ) );
                return ;

            default:
                if ( mErrorHandler )
                {
                    Error err( Error::ERR_INVALIDPARAMS, "invalid operator: " + AST::LogicExpression::operatorString( op ) );
                    mErrorHandler->handleError( &err );
                }
                result.setValue( 0. );
                return;

            }
        }

        //---------------------------------------------------------------------------------
        const MathML::String& ConstantExpression::getStringValue() const
        {
            return mStringValue;
        }

        //---------------------------------------------------------------------------------
        void ConstantExpression::setStringValue( const MathML::String& value )
        {
            mStringValue = value;
        }

        //---------------------------------------------------------------------------------
        MathML::String ConstantExpression::toString() const
        {
            std::stringstream ss;

            if ( mStringValue.size() > 0 && mType == SCALAR_INVALID )
            {
                return mStringValue;
            }

            //check type
            switch ( mType )
            {

            case SCALAR_BOOL:
                return ( mValue == 0. ) ? SCALAR_FALSE_VALUE : SCALAR_TRUE_VALUE;

            case SCALAR_LONG:
                //return StringUtil::valueOf( static_cast<long>( mValue ) );
                ss << static_cast<long>( mValue );
                return ss.str();

            case SCALAR_DOUBLE:
                //return StringUtil::valueOf( mValue );
                ss << mValue;
                return ss.str();

            default:
                return SCALAR_INVALID_VALUE;
            }
        }

        //-----------------------------------------------------------------
        INode* ConstantExpression::clone(CloneFlags cloneFlags) const
        {
            ConstantExpression* copy = new ConstantExpression();
            copy->mType = mType;
            copy->mValue = mValue;
            copy->mStringValue = mStringValue;
            return copy;
        }

    } //namespace AST

} //namespace MathML
