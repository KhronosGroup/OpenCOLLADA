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

#ifndef __MATHML_STREAM_PARSER_HANDLER_H__
#define __MATHML_STREAM_PARSER_HANDLER_H__

#include "MathMLSolverPrerequisites.h"
#include <libxml/xmlreader.h>
#include "MathMLParserHandler.h"
#include "MathMLASTConstantExpression.h"

#include <stack>

namespace MathML
{
    /** Common interface for handling xmlreader.
    */

    class _MATHML_SOLVER_EXPORT IStreamParserHandler
    {

    public:
        /** C-tor. */
        IStreamParserHandler()
        {}

        ;

        /** D-tor. */
        virtual ~IStreamParserHandler()
        {}

        ;

    public:

        /** Handle method for type 'XML_READER_TYPE_NONE'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_NONE'.
        */
        virtual void handleTypeNone( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_ELEMENT'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_ELEMENT'.
        */
        virtual void handleTypeElement( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_ATTRIBUTE'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_ATTRIBUTE'.
        */
        virtual void handleTypeAttribute( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_TEXT'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_TEXT'.
        */
        virtual void handleTypeText( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_CDATA'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_CDATA'.
        */
        virtual void handleTypeCData( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_ENTITY_REFERENCE'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_ENTITY_REFERENCE'.
        */
        virtual void handleTypeEntityReference( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_ENTITY'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_ENTITY'.
        */
        virtual void handleTypeEntity( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_PROCESSING_INSTRUCTION'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_PROCESSING_INSTRUCTION'.
        */
        virtual void handleTypeProcessingInstruction( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_COMMENT'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_COMMENT'.
        */
        virtual void handleTypeComment( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_DOCUMENT'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_DOCUMENT'.
        */
        virtual void handleTypeDocument( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_DOCUMENT_TYPE'.
        @param reader The text reader currently pointing to a node of type 'DOCUMENT_TYPE'.
        */
        virtual void handleTypeDocumentType( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_DOCUMENT_FRAGMENT'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_DOCUMENT_FRAGMENT'.
        */
        virtual void handleTypeDocumentFragment( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_NOTATION'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_NOTATION'.
        */
        virtual void handleTypeNotation( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_WHITESPACE'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_WHITESPACE'.
        */
        virtual void handleTypeWhitespace( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_SIGNIFICANT_WHITESPACE'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_SIGNIFICANT_WHITESPACE'.
        */
        virtual void handleTypeSignificantWhitespace( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_END_ELEMENT'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_END_ELEMENT'.
        */
        virtual void handleTypeEndElement( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_END_ENTITY'.
        @param reader The text reader currently pointing to a node of type 'XML_READER_TYPE_END_ENTITY'.
        */
        virtual void handleTypeEndEntity( xmlTextReaderPtr& reader ) = 0;
        /** Handle method for type 'XML_READER_TYPE_DECLARATION'.
        @param reader The text reader currently pointing to a node of type 'DECLARATION'.
        */
        virtual void handleTypeXMLDeclaration( xmlTextReaderPtr& reader ) = 0;

    };


    /** Default handler for xmlreader -interface.
    @par Empty implementations of handle methods. Specialized classes have to implement/override
    the method interested in.
    */

    class _MATHML_SOLVER_EXPORT StreamParserHandler : public IStreamParserHandler
    {

    public:
        /** C-tor. */
        StreamParserHandler()
        {}

        ;

        /** D-tor. */
        virtual ~StreamParserHandler()
        {}

        ;

    public:

        //see IStreamParserHandler::handleTypeNone( xmlTextReaderPtr& );
        virtual void handleTypeNone( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeElement( xmlTextReaderPtr& );
        virtual void handleTypeElement( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeAttribute( xmlTextReaderPtr& );
        virtual void handleTypeAttribute( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeText( xmlTextReaderPtr& );
        virtual void handleTypeText( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeCData( xmlTextReaderPtr& );
        virtual void handleTypeCData( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeEntityReference( xmlTextReaderPtr& );
        virtual void handleTypeEntityReference( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeEntity( xmlTextReaderPtr& );
        virtual void handleTypeEntity( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeProcessingInstruction( xmlTextReaderPtr& );
        virtual void handleTypeProcessingInstruction( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeComment( xmlTextReaderPtr& );
        virtual void handleTypeComment( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeDocument( xmlTextReaderPtr& );
        virtual void handleTypeDocument( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeDocumentType( xmlTextReaderPtr& );
        virtual void handleTypeDocumentType( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeDocumentFragment( xmlTextReaderPtr& );
        virtual void handleTypeDocumentFragment( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeNotation( xmlTextReaderPtr& );
        virtual void handleTypeNotation( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeWhitespace( xmlTextReaderPtr& );
        virtual void handleTypeWhitespace( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeSignificantWhitespace( xmlTextReaderPtr& );
        virtual void handleTypeSignificantWhitespace( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeEndElement( xmlTextReaderPtr& );
        virtual void handleTypeEndElement( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeEndEntity( xmlTextReaderPtr& );
        virtual void handleTypeEndEntity( xmlTextReaderPtr& reader )
        {}

        //see IStreamParserHandler::handleTypeXMLDeclaration( xmlTextReaderPtr& );
        virtual void handleTypeXMLDeclaration( xmlTextReaderPtr& reader )
        {}

    public:
        //---------------------------------------------------------------------
        //--- Wrapper methods for c-methods from xml-reader -------------------
        //---------------------------------------------------------------------

        /** Utility method for retrieving the name of current node.
        @param result String reference to store name.
        @param reader Reader to retrieve node name from.
        */
        static void getNodeName( String& result, xmlTextReaderPtr& reader );

        /** Find out if current element is declared like <a/>.
        @param reader The Reader checking whether the node is empty or not.
        @return true if element is empty, otherwise false.
        */
        static bool isNodeEmpty( xmlTextReaderPtr& reader );

        /** Find out if current element has text nodes as children.
        @param reader The Reader checking whether the node has a value or not.
        @return true if node has values, otherwise false.
              e.g. TextNodes: string of text nodes is the value of the node
        */
        static bool hasNodeValue( xmlTextReaderPtr& reader );

        /** Get value of current node.
        @param result String reference to set value.
        @param reader Reader to retrieve node value from.
        */
        static void getNodeValue( String& result, xmlTextReaderPtr& reader );

        /** Get value of attribute node with given name.
        @param result String reference to store attribute value.
        @param name The name of the attribute to get value from.
        @param reader Reader to retrieve attribute value from.
        */
        static void StreamParserHandler::getAttributeValue( String& result, const String& name, xmlTextReaderPtr& reader );

    public:
        //---------------------------------------------------------------------
        //--- MATHML parsing helper methods -----------------------------------
        //---------------------------------------------------------------------

        /** Helper method for checking for possible unary operator.
        @param name The name string to check for unary operator.
        @return Returns true if string could be mapped to a unary operator,
        otherwise false.
        */
        static bool isUnaryOperator( const String& name );

        /** Helper method for checking for possible binary operator.
        @param name The name string to check for binary operator.
        @return Returns true if string could be mapped to a binary operator,
        otherwise false.
        */
        static bool isBinaryOperator( const String& name );

        /** Helper method for checking for possible relation operator.
        @param name The name string to check for relation operator.
        @return Returns true if string could be mapped to a relation operator,
        otherwise false.
        */
        static bool isRelationOperator( const String& name );

        /** Helper method for checking for possible logic operator.
        @param name The name string to check for logic operator.
        @return Returns true if string could be mapped to a logic operator,
        otherwise false.
        */
        static bool isLogicOperator( const String& name );

        /** Helper method for checking for possible function name.
        @param name The name string to check for function name.
        @return Returns true if string could be mapped to a function name,
        otherwise false.
        */
        static bool isFunction( const String& name );

        /** Helper method for checking for possible operator or function.
        @param name The name string to check for operator or function name.
        @return Returns true if string could be mapped to a operator or function name,
        otherwise false.
        */
        static bool isOperatorOrFunction( const String& name );


        /** Method for retrieving a unary operator from the given
        (MathML) element.
        @param xmlString The xmlString to check for unary operator.
        @return The constant string representation for a correct unary operator,
        otherwise the string constant 'NO_OPERATOR'.
        */
        virtual const String& getUnaryOperator ( const String& xmlString );

        /** Method for retrieving a binary operator from the given
        (MathML) element.
        @param xmlString The xmlString to check for binary operator.
        @return The constant string representation for a correct binary operator,
        otherwise the string constant 'NO_OPERATOR'.
        */
        virtual const String& getBinaryOperator ( const String& xmlString );

        /** Method for retrieving a relation operator from the given
        (MathML) element.
        @param xmlString The xmlString to check for relation operator.
        @return The constant string representation for a correct relation operator,
        otherwise the string constant 'NO_OPERATOR'.
        */
        virtual const String& getRelationOperator ( const String& xmlString );

        /** Method for retrieving a logic operator from the given
        (MathML) element.
        @param xmlString The xmlString to check for logic operator.
        @return The constant string representation for a correct logic operator,
        otherwise the string constant 'NO_OPERATOR'.
        */
        virtual const String& getLogicOperator ( const String& xmlString );

        /** Method for retrieving the name of a function from the given
        (MathML) element.
        @param xmlString The xmlString to check for function name.
        @return The constant string representation for a correct function name,
        otherwise the string constant 'NO_FUNCTION'.
        */
        virtual const String& getFunction ( const String& xmlString );

    };

} //namespace MathML

#endif //__MATHML_STREAM_PARSER_HANDLER_H__
