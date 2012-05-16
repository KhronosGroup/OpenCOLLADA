#include "MathMLSolverStableHeaders.h"
#include "MathMLSerializationVisitor.h"

namespace MathML
{
    //-------------------------------------------------------------------------------------------
    SerializationVisitor::SerializationVisitor( std::ostream& output,
            bool writeXMLHeader, bool writeClosingRootElement )
            : mOutput( output ), mWriteXMLHeader( writeXMLHeader ),
            mWriteClosingRootElement( writeClosingRootElement )
    {
        if ( mWriteXMLHeader )
        {
            writeText( MATHML_HEADER_LINE_ONE );
            writeLineBreak();
            writeText( MATHML_HEADER_LINE_TWO );
            writeLineBreak();
        }
    }

    //-------------------------------------------------------------------------------------------
    SerializationVisitor::~SerializationVisitor()
    {
        if ( mWriteClosingRootElement )
        {
            writeText( MATHML_CLOSING_ROOT_ELEMENT );
            writeLineBreak();
        }
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::visit( const AST::ArithmeticExpression* const node )
    {
        writeStartElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
        writeEmptyElement( SerializationUtil::getArithmeticOperatorElementName( node->getOperator() ) );
        writeLineBreak();
        const AST::NodeList& children = node->getOperands();

        for ( unsigned int i = 0; i < children.size(); ++i )
        {
            children.at( i ) ->accept( this );
        }

        writeEndElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::visit( const AST::BinaryComparisonExpression* const node )
    {
        writeStartElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
        writeEmptyElement( SerializationUtil::getComparisionOperatorElementName( node->getOperator() ) );
        writeLineBreak();
        node->getLeftOperand() ->accept( this );
        node->getRightOperand() ->accept( this );
        writeEndElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::visit( const AST::FragmentExpression* const node )
    {
        // declare
        AttributeList declareAttributes;
        declareAttributes[ &ATTRIBUTE_ID_NAME ] = &node->getName();
        declareAttributes[ &ATTRIBUTE_TYPE_NAME ] = &ATTRIBUTE_TYPE_VAL_FUNCTION;
        const String& nargs = StringUtil::valueOfUnfinalized(
                            static_cast< int >( node->getParameterList().size() ) );
        declareAttributes[ &ATTRIBUTE_NARGS_NAME ] = &nargs;
        writeStartElementWithAttributes( ELEMENT_DECLARE_NAME, declareAttributes );
        writeLineBreak();

        writeStartElement( ELEMENT_CI_NAME );
        writeText( node->getName() );
        writeEndElement( ELEMENT_CI_NAME );
        writeLineBreak();

        node->getFragment() ->accept( this );

        writeEndElement( ELEMENT_DECLARE_NAME );
        writeLineBreak();

        // csymbol
        writeStartElement( ELEMENT_APPLY_NAME );
        writeLineBreak();

        AttributeList csymbolAttributes;
        csymbolAttributes[ &ATTRIBUTE_ENCODING_NAME ] = &ATTRIBUTE_ENCODING_VAL_DEFAULT;
        String url = CHAR_URL_FRAGMENT_DELIMITER;
        url += node->getName();
        csymbolAttributes[ &ATTRIBUTE_DEFINITION_URL_NAME ] = &url;
        writeStartElementWithAttributes( ELEMENT_CSYMBOL_NAME, csymbolAttributes );

        writeText( node->getName() );
        writeEndElement( ELEMENT_CSYMBOL_NAME );
        writeLineBreak();

        const AST::FragmentExpression::ParameterList& children = node->getParameterList();
        AST::FragmentExpression::ParameterList::const_iterator it;

        for ( it = children.begin(); it != children.end(); ++it )
        {
            (*it)->accept( this );
        }

        writeEndElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::visit( const AST::LogicExpression* const node )
    {
        writeStartElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
        writeEmptyElement( SerializationUtil::getLogicOperatorElementName( node->getOperator() ) );
        writeLineBreak();
        const AST::NodeList& children = node->getOperands();

        for ( unsigned int i = 0; i < children.size(); ++i )
        {
            children.at( i ) ->accept( this );
        }

        writeEndElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::visit( const AST::ConstantExpression* const node )
    {
        const String & value = node->toString();
        const String& element = SerializationUtil::getConstantElementName( value );

        if ( element != UNKNOWN_ELEMENT )
        {
            writeEmptyElement( element );
        }

        else
        {
            writeStartElement( ELEMENT_CN_NAME );
            writeText( value );
            writeEndElement( ELEMENT_CN_NAME );
        }

        writeLineBreak();
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::visit( const AST::FunctionExpression* const node )
    {
        writeStartElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
        const String& functionName = SerializationUtil::getFunctionElementName( node->getName() );
        writeEmptyElement( functionName );
        writeLineBreak();
        const AST::NodeList& children = node->getParameterList();

        for ( unsigned int i = 0; i < children.size(); ++i )
        {
            if ( functionName == ELEMENT_LOG_NAME && i == 0 )
            {
                writeStartElement( ELEMENT_LOGBASE_NAME );
                writeLineBreak();
            }

            children.at( i ) ->accept( this );

            if ( functionName == ELEMENT_LOG_NAME && i == 0 )
            {
                writeEndElement( ELEMENT_LOGBASE_NAME );
                writeLineBreak();
            }
        }

        writeEndElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::visit( const AST::UnaryExpression* const node )
    {
        writeStartElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
        writeEmptyElement( SerializationUtil::getUnaryOperatorElementName( node->getOperator() ) );
        writeLineBreak();
        node->getOperand() ->accept( this );
        writeEndElement( ELEMENT_APPLY_NAME );
        writeLineBreak();
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::visit( const AST::VariableExpression* const node )
    {
        writeStartElement( ELEMENT_CI_NAME );
        writeText( node->getName() );
        writeEndElement( ELEMENT_CI_NAME );
        writeLineBreak();
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::writeStartElement( const String& elementName )
    {
        mOutput << CHAR_LT;
        mOutput << elementName;
        mOutput << CHAR_GT;
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::writeEndElement( const String& elementName )
    {
        mOutput << CHAR_LT;
        mOutput << CHAR_SLASH;
        mOutput << elementName;
        mOutput << CHAR_GT;
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::writeEmptyElement( const String& elementName )
    {
        mOutput << CHAR_LT;
        mOutput << elementName;
        mOutput << CHAR_SLASH;
        mOutput << CHAR_GT;
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::writeText( const String& text )
    {
        mOutput << text;
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::writeLineBreak()
    {
        mOutput << std::endl;
    }

    //-------------------------------------------------------------------------------------------
    void SerializationVisitor::writeStartElementWithAttributes( const String& elementName, const AttributeList& attributes )
    {
        mOutput << CHAR_LT;
        mOutput << elementName;

        AttributeList::const_iterator it;

        for ( it = attributes.begin(); it != attributes.end(); ++it )
        {
            mOutput << " ";
            mOutput << *( it->first );
            mOutput << "=\"";
            mOutput << *( it->second );
            mOutput << "\"";
        }

        mOutput << CHAR_GT;
    }
}
