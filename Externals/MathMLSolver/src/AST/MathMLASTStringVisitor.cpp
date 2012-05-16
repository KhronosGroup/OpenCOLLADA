
#include "MathMLSolverStableHeaders.h"
#include "MathMLASTStringVisitor.h"


namespace MathML
{

    namespace AST
    {
        //----------------------------------------------------------------------------
        StringVisitor::StringVisitor( std::ostream* out )
                : mOut ( out )
        {}

        //----------------------------------------------------------------------------
        StringVisitor::~StringVisitor()
        {}

        //----------------------------------------------------------------------------
        void StringVisitor::visit( const ArithmeticExpression* const node )
        {
            String op = node->getOperatorString();
            *mOut << "(";
            NodeList operands = node->getOperands();
            NodeList::iterator it;
            it = operands.begin();

            //first child accept visitor
            ( *it ) ->accept( this );
            ++it;

            while ( it != operands.end() )
            {
                *mOut << " " << op << " ";
                //child accept visitor
                ( *it ) ->accept( this );

                ++it;
            }

            *mOut << ")";
        }

        //----------------------------------------------------------------------------
        void StringVisitor::visit( const BinaryComparisonExpression* const node )
        {
            *mOut << "(";
            node->getLeftOperand() ->accept( this );
            *mOut << " " << node->getOperatorString() << " ";
            node->getRightOperand() ->accept( this );
            *mOut << ")";
        }

        //----------------------------------------------------------------------------
        void StringVisitor::visit( const FragmentExpression* const node )
        {
            *mOut << node->getName() << "(";
#ifdef VERBOSE
            //fragment visiting
            node->getFragment() ->accept( this );
#endif

            FragmentExpression::ParameterMap parameters = node->getParameterMap();
            FragmentExpression::ParameterMap::iterator it;

            for (it = parameters.begin(); it != parameters.end(); ++it )
            {
				if(it != parameters.begin())
				{
					*mOut << ", ";
				}
                String paramName = ( *it ).first;
                *mOut << paramName << "=";
                //child accept visitor
                ( *it ).second->accept( this );
            }

            *mOut << ")";
        }

        //----------------------------------------------------------------------------
        void StringVisitor::visit( const LogicExpression* const node )
        {
            String op = node->getOperatorString();
            *mOut << "(";
            NodeList operands = node->getOperands();
            NodeList::iterator it;
            it = operands.begin();

            //first child accept visitor
            ( *it ) ->accept( this );
            ++it;

            while ( it != operands.end() )
            {
                *mOut << " " << op << " ";
                //child accept visitor
                ( *it ) ->accept( this );

                ++it;
            }

            *mOut << ")";
        }

        //----------------------------------------------------------------------------
        void StringVisitor::visit( const ConstantExpression* const node )
        {
            *mOut << node->toString();
        }

        //----------------------------------------------------------------------------
        void StringVisitor::visit( const FunctionExpression* const node )
        {
            *mOut << node->getName() << "(";

            NodeList parameters = node->getParameterList();
            NodeList::iterator it;

            it = parameters.begin();

            if ( it != parameters.end() )
            {
                //child accept visitor
                ( *it ) ->accept( this );
                ++it;
            }

            for ( ; it != parameters.end(); ++it )
            {
                *mOut << ", ";
                //child accept visitor
                ( *it ) ->accept( this );
            }

            *mOut << ")";
        }

        //----------------------------------------------------------------------------
        void StringVisitor::visit( const UnaryExpression* const node )
        {
            *mOut << "(";

            *mOut << node->getOperatorString();

            // visit (child) node
            node->getOperand() ->accept( this );

            *mOut << ")";
        }

        //----------------------------------------------------------------------------
        void StringVisitor::visit( const VariableExpression* const node )
        {
            *mOut << node->getName();
        }

    } //namespace AST

} //namespace MathML

