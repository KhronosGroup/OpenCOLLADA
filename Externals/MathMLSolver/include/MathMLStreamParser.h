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

#ifndef __MATHML_STREAM_PARSER_H__
#define __MATHML_STREAM_PARSER_H__

#include "MathMLSolverPrerequisites.h"
#include <libxml/xmlreader.h>
#include "MathMLStreamParserHandler.h"
#include "MathMLParserHandler.h"
#include "MathMLASTConstantExpression.h"

#include <stack>

namespace MathML
{
    /** String representation for enum State::STATE_EMPTY. */
    const static String STATE_EMPTY_VALUE = "";
    /** String representation for enum State::STATE_INVALID. */
    const static String STATE_INVALID_VALUE = "state_invalid";
    /** String representation for enum State::STATE_DOCUMENT. */
    const static String STATE_DOCUMENT_VALUE = "document";
    /** String representation for enum State::STATE_MATH. */
    const static String STATE_MATH_VALUE = "math";


    /** Parses a MathML file and creates an AST.
    */

    class _MATHML_SOLVER_EXPORT StreamParser : public StreamParserHandler
    {

    public:
        /** States for parsing. */
        enum State
        {
            STATE_EMPTY,
            STATE_INVALID,

            STATE_DOCUMENT,
            STATE_MATH,
            STATE_APPLY,
            STATE_DECLARE,
            STATE_CN,
            STATE_CN_RATIONAL,
            STATE_CI,
            STATE_CSYMBOL
        };


        /** Type definition for a stack of node lists. */
        typedef std::stack<AST::NodeList*> NodeListStack;
        /** Type definition for a stack of operator strings. */
        typedef std::stack<String> OperatorStack;
        /** Type definition for a stack of states. */
        typedef std::stack<State> StateStack;

    private:

        /** The file path/url. */
        String mFile;

        /** NodeList stack. */
        NodeListStack mStackNodeList;

        /** Operator stack. */
        OperatorStack mStackOperator;

        /** State stack. */
        StateStack mStackState;

        /** FLAG for storing variable names for evaluating. */
        bool mStoreVariables;

        /** FLAG for APPLY check for operator (element). */
        bool mApplyOperatorChecked;


        /** The parser handler for notification. */
        MathML::ParserHandler* mParserHandler;
        /** Temporary list of variable names. */
        ParserHandler::VariableList mVariableList;

    public:
        /** C-tor. */
        StreamParser( MathML::ParserHandler* handler );

        /** D-tor. */
        virtual ~StreamParser();

        /** Getter for path/url of parsing document. */
        virtual const String& getFile();

        /** Methode for starting a parse-process.
        @param fileName The string of a file path or url.
        */
        virtual void parse( const String& fileName );

    public:
        /** Parsing a string to a State representation.
        @param name The string to retrieve the mapped state representation for.
        @return The state representation. STATE_INVALID is returned if no valid
        state could be found.
        */
        static State parseState( const String& name );
        /** Retrieving the string representation for a given state.
        @param state The state to retrieve the mapped string representation for.
        @return The string representation. The constant STATE_INVALID_VALUE is
        returned if no valid string representation could be found.
        */
        static const String& stateToString( State state );


    public:
        //overwriting of default stream parser handler method interested in.

        //see IStreamParserHandler::handleTypeNone( xmlTextReaderPtr& );
        virtual void handleTypeNone( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeElement( xmlTextReaderPtr& );
        virtual void handleTypeElement( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeAttribute( xmlTextReaderPtr& );
        //virtual void handleTypeAttribute( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeText( xmlTextReaderPtr& );
        virtual void handleTypeText( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeCData( xmlTextReaderPtr& );
        //virtual void handleTypeCData( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeEntityReference( xmlTextReaderPtr& );
        //virtual void handleTypeEntityReference( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeEntity( xmlTextReaderPtr& );
        //virtual void handleTypeEntity( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeProcessingInstruction( xmlTextReaderPtr& );
        //virtual void handleTypeProcessingInstruction( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeComment( xmlTextReaderPtr& );
        //virtual void handleTypeComment( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeDocument( xmlTextReaderPtr& );
        //virtual void handleTypeDocument( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeDocumentType( xmlTextReaderPtr& );
        //virtual void handleTypeDocumentType( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeDocumentFragment( xmlTextReaderPtr& );
        //virtual void handleTypeDocumentFragment( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeNotation( xmlTextReaderPtr& );
        //virtual void handleTypeNotation( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeWhitespace( xmlTextReaderPtr& );
        //virtual void handleTypeWhitespace( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeSignificantWhitespace( xmlTextReaderPtr& );
        //virtual void handleTypeSignificantWhitespace( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeEndElement( xmlTextReaderPtr& );
        virtual void handleTypeEndElement( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeEndEntity( xmlTextReaderPtr& );
        //virtual void handleTypeEndEntity( xmlTextReaderPtr& reader );

        //see IStreamParserHandler::handleTypeXMLDeclaration( xmlTextReaderPtr& );
        //virtual void handleTypeXMLDeclaration( xmlTextReaderPtr& reader )


    private:
        /** Getter for retrieving the parser handler. */
        virtual MathML::ParserHandler* getParserHandler();

        /** Main methode for handling the current xml node read from stream. */
        virtual void processNode ( xmlTextReaderPtr& reader );

        /** Handle current node and its subtree.
        */
        virtual int handleSubTree( xmlTextReaderPtr& reader );


        /** Method for finding element by id.
        @param reader The reader pointing to the current node in the xml stream.
        @param elementId The id to search for.
        @result 1 == success; -1 == error; 0 == not found
        */
        int findNodeById( xmlTextReaderPtr& reader, const String& elementId );

    private:
        /** Push new created AST-Node to current list of operands in the stack.
        @par Is stack empty the handler is notificated, otherwise node is stored as operand.
        */
        virtual void pushToListOrResult ( AST::NodePtr node );
		virtual void pushToListOrResult ( AST::INode* node );

    private:
        //-------------------------------------------------------------------------------------------
        //--- MATHML handling methods ---------------------------------------------------------------
        //-------------------------------------------------------------------------------------------

        /** Handling start of mathml apply-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementApplyStart ( xmlTextReaderPtr& reader );
        /** Handling end of mathml apply-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementApplyEnd ( xmlTextReaderPtr& reader );

        /** Handling start of mathml declare-elements.
        @param reader The reader pointing to the node representing the xml-element.
        */
        virtual void handleElementDeclareStart ( xmlTextReaderPtr& reader );
        /** Handling end of mathml declare-elements.
        @param reader The reader pointing to the node representing the xml-element.
        */
        virtual void handleElementDeclareEnd ( xmlTextReaderPtr& reader );

        /** Handling start of mathml cn-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementCNStart( xmlTextReaderPtr& reader );
        /** Handling end of mathml cn-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementCNEnd( xmlTextReaderPtr& reader );

        /** Handling start of mathml ci-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementCIStart( xmlTextReaderPtr& reader );
        /** Handling end of mathml ci-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementCIEnd( xmlTextReaderPtr& reader );

        /** Handling start of mathml csymbo-elements.
        @param reader The reader pointing to the node representing the xml-element.
        */
        virtual void handleElementCSymbolStart( xmlTextReaderPtr& reader );
        /** Handling end of mathml csymbo-elements.
        @param reader The reader pointing to the node representing the xml-element.
        */
        virtual void handleElementCSymbolEnd( xmlTextReaderPtr& reader );

        /** Handling start of mathml logbase-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementLogbaseStart( xmlTextReaderPtr& reader );
        /** Handling end of mathml logbase-elements.
              @param reader The reader pointing to the node representing the xml-element.
        @todo: handle something other than AST::ConstantExpression
              */
        virtual void handleElementLogbaseEnd( xmlTextReaderPtr& reader );

        /** Handling start of mathml pi-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementPIStart( xmlTextReaderPtr& reader );
        /** Handling end of mathml pi-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementPIEnd( xmlTextReaderPtr& reader );

        /** Handling start of mathml exponential-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementExponentialeStart( xmlTextReaderPtr& reader );
        /** Handling end of mathml exponential-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementExponentialeEnd( xmlTextReaderPtr& reader );

        /** Handling start of mathml true-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementTrueStart( xmlTextReaderPtr& reader );
        /** Handling end of mathml true-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementTrueEnd( xmlTextReaderPtr& reader );

        /** Handling start of mathml false-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementFalseStart( xmlTextReaderPtr& reader );
        /** Handling end of mathml false-elements.
              @param reader The reader pointing to the node representing the xml-element.
              */
        virtual void handleElementFalseEnd( xmlTextReaderPtr& reader );

    private:
        /** Handling of unary operations.
        @param operatorOrFunction The operator or function name.
        @param nodes The nodeslist of operand(s).
        */
        AST::NodePtr StreamParser::handleUnaryOperation( const String& operatorOrFunction, AST::NodeList* nodes );

        /** Handling of binary operations.
        @param operatorOrFunction The operator or function name.
        @param nodes The nodeslist of operands.
        */
        AST::NodePtr StreamParser::handleBinaryOperation( const String& operatorOrFunction, AST::NodeList* nodes );

        /** Handling of multi operand operations.
        @param operatorOrFunction The operator or function name.
        @param nodes The nodeslist of operands.
        */
        AST::NodePtr StreamParser::handleMultiOperandOperation( const String& operatorOrFunction, AST::NodeList* nodes );

        /** todo: description */
        virtual String getContainer( const String& url );
        /** todo: description */
        virtual String getId( const String& url );

    };

} //namespace MathML

#endif //__MATHML_STREAM_PARSER_H__
