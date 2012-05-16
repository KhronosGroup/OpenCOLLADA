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

#ifndef __MATHML_PARSER_H__
#define __MATHML_PARSER_H__

#include "MathMLSolverPrerequisites.h"
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "MathMLParserHandler.h"
#include "MathMLASTConstantExpression.h"

namespace MathML
{
    /** Parses a MathML file and creates an AST.
       @todo: Convenience method returning lists, strings, etc. created within, should be created
       in the calling method and passed as reference (-> no copying of strings, lists, etc).
       E.g.:
         - IS: ElementList getChildElements ( xercesc::DOMElement* element )
         - SHOULD BE: void getChildElements ( ElementList& result, xercesc::DOMElement* element )

       */

    class _MATHML_SOLVER_EXPORT Parser
    {

    private:

        /** The file path/url. */
        String mFile;

        /** The xml parser. */
        xercesc::XercesDOMParser* xmlParser;
        /** The parser handler for notification. */
        MathML::ParserHandler* mParserHandler;
        /** Temporary list of variable names. */
        ParserHandler::VariableList mVariableList;

    public:
        /** Type definition for a list DOM nodes of type 'element'. */
        typedef std::vector<xercesc::DOMElement*> ElementList;
        /** Type definition for a list DOM nodes of type 'text'. */
        typedef std::vector<xercesc::DOMText*> TextNodeList;

        /** C-tor.
        @param handler The parser handler being notifiied.
        */
        Parser( MathML::ParserHandler* handler = 0 );

        /** D-tor. */
        virtual ~Parser();

        /** Getter for path/url of parsing document. */
        virtual const String& getFile();

        /** Methode for starting a parse-process.
        @param fileName The string of a file path or url.
        */
        virtual void parse( const String& fileName );

    private:
        /** Getter for retrieving the parser handler. */
        virtual MathML::ParserHandler* getParserHandler();

        /** Convenience method for creating (double) constant expression
        from a xercesc character pointer.
        @param xmlValue The xercesc character pointer.
        @return The AST::ConstantExpression for the given string.
        */
        virtual AST::ConstantExpression* createConstant( const XMLCh* xmlValue );

        /** Convenience method for retrieving DOM child nodes of type
        'element' for the given DOMElement.
        @param element The element for retrieving its child elements.
        */
        virtual ElementList getChildElements ( xercesc::DOMElement* element );

        /** Convenience method for checking if given child node is
        of the given name.
        @param node The DOMNode to be checked.
        @param name The name to check against.
        @return True if node is of given name, otherwise false.
        */
        virtual bool isElementOfName( xercesc::DOMNode* node, String name );

        /** Convenience method for retrieving a element from a document
        by its id-attribute.
        @param doc The DOMDocument to be searched.
        @param elementId The id to search for.
        @return The found DOMElement or 0.
        */
        virtual xercesc::DOMElement* getElementById( xercesc::DOMDocument* doc, const String& elementId );

        /** Convenience method for retrieving the attribute value for
        the given attribute name.
        @param element The DOMElement to be search for the attribute.
        @param attributeName The name of the attribute to search for.
        @return The string representation of its value if found, otherwise an empty string.
        */
        virtual String getAttributeValue ( xercesc::DOMElement* element, String attributeName );

        /** Convenience method for retrieving child text nodes from a given DOMElement.
        @param element The DOMElement to be search for the text nodes.
        @return A list of found text nodes, otherwise an empty list.
        */
        virtual TextNodeList getTextNodes ( xercesc::DOMElement* element );


        /** Method for retrieving a unary operator from the given
        (MathML) DOMElement.
        @param element The element to be check for a unary operator.
        @return The string representation for a correct unary operator,
        otherwise the string constant 'NO_OPERATOR'.
        */
        virtual const String& getUnaryOperator ( xercesc::DOMElement* element );

        /** Method for retrieving a binary operator from the given
        (MathML) DOMElement.
        @param element The element to be check for a binary operator.
        @return The string representation for a correct binary operator,
        otherwise the string constant 'NO_OPERATOR'.
        */
        virtual const String& getBinaryOperator ( xercesc::DOMElement* element );

        /** Method for retrieving a relation operator from the given
        (MathML) DOMElement.
        @param element The element to be check for a relation operator.
        @return The string representation for a correct relation operator,
        otherwise the string constant 'NO_OPERATOR'.
        */
        virtual const String& getRelationOperator ( xercesc::DOMElement* element );

        /** Method for retrieving a logic operator from the given
        (MathML) DOMElement.
        @param element The element to be check for a logic operator.
        @return The string representation for a correct logic operator,
        otherwise the string constant 'NO_OPERATOR'.
        */
        virtual const String& getLogicOperator ( xercesc::DOMElement* element );

        /** Method for retrieving the name of a function from the given
        (MathML) DOMElement.
        @param element The element to be check for a function name.
        @return The string representation for a correct function name,
        otherwise the string constant 'NO_FUNCTION'.
        */
        virtual const String& getFunction ( xercesc::DOMElement* element );

        /** Methode for handling the given DOMElement.
        @param element The element to be further processed for its name (and attributes).
        @return The common interface of the underlying expression.
        */
        virtual AST::INode* handleElement ( xercesc::DOMElement* element );

        /** Methode for handling (MathML) <apply>-elements.
        @param element The element to be further processed for its children and attributes.
        @return The common interface of the underlying expression.
        */
        virtual AST::INode* handleElementApply( xercesc::DOMElement* element );

        /** Methode for handling (MathML) <declare>-elements.
        @param element The element to be further processed for its children and attributes).
        @param siblings The list of siblings holding the parameter arguments for this declaration-construct.
        @return The interface of an AST::FragmentExpression -node.
        */
        virtual AST::INode* handleElementDeclare( xercesc::DOMElement* element, const ElementList& siblings );

        /** Methode for handling 'external' defined fragments
        (or code) referenced by (MathML) <csymbol>-elements.
        @param firstChild The identified<csymbol>-element of the given list.
        @param childList The ElementList containing the <csymbol..>-element and its siblings.
        @return The interface of an AST::FragmentExpression -node.
        */
        virtual AST::INode* handleExternalReferenceByCSymbol( xercesc::DOMElement* firstChild, ElementList& childList );

        /** Methode for handling (MathML) <cn>-elements.
        @param element The <cn> -DOMElement..
        @return The interface of an AST::ConstantExpression -node.
        */
        virtual AST::INode* handleElementCN( xercesc::DOMElement* element );

        /** Methode for handling (MathML) <ci>-elements.
        @param element The <ci> -DOMElement..
        @return The interface of an AST::VariableExpression -node.
        */
        virtual AST::INode* handleElementCI( xercesc::DOMElement* element );

        /** Methode for handling (MathML) <logbase>-elements.
        @param element The <logbase> -DOMElement..
        @return The interface of an AST-node representening the base for a logarithm.
        */
        virtual AST::INode* handleElementLogbase( xercesc::DOMElement* element );

        /** Methode for handling (MathML) <pi>-elements.
        @param element The <pi> -DOMElement..
        @return The interface of an AST::ConstantExpression -node for the constant 'PI'.
        */
        virtual AST::INode* handleElementPI( xercesc::DOMElement* element );

        /** Methode for handling (MathML) <exponentiale>-elements.
        @param element The <exponentiale> -DOMElement..
        @return The interface of an AST::ConstantExpression -node for the constant 'e'.
        */
        virtual AST::INode* handleElementExponentiale( xercesc::DOMElement* element );

        /** Methode for handling (MathML) <true>-elements.
        @param element The <true> -DOMElement..
        @return The interface of an AST::ConstantExpression -node for the boolean constant 'true'.
        */
        virtual AST::INode* handleElementTrue( xercesc::DOMElement* element );

        /** Methode for handling (MathML) <false>-elements.
        @param element The <false> -DOMElement..
        @return The interface of an AST::ConstantExpression -node for the boolean constant 'false'.
        */
        virtual AST::INode* handleElementFalse( xercesc::DOMElement* element );


        /** Methode for handling unary operations.
        @param elements The list of elements containing operator and operand(s).
        @return The interface of an AST::UnaryExpression -node.
        */
        virtual AST::INode* handleUnaryOperation( ElementList& elements );

        /** Methode for handling operations with two operands.
        @param elements The list of elements containing operator and operand(s).
        @return The interface of an specialized AST::ExpressionNode (arithmetic, logic, ..).
        */
        virtual AST::INode* handleBinaryOperation( ElementList& elements );

        /** Methode for handling operations with more than two operands.
        @param elements The list of elements containing operator and operands.
        @return The interface of an specialized AST::ExpressionNode (arithmetic, logic, ..)
        but no AST::BinaryComparisionExpression (relations).
        */
        virtual AST::INode* handleMultiOperandOperation( ElementList& elements );


        /** todo: description */
        virtual String getContainer( const String& url );
        /** todo: description */
        virtual String getId( const String& url );
    };

} //namespace MathML

#endif //__MATHML_PARSER_H__
