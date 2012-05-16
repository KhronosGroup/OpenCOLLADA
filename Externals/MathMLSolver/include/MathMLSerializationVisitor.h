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

#ifndef __MATHML_SERIALIZATION_VISITOR_H__
#define __MATHML_SERIALIZATION_VISITOR_H__

#include "MathMLSolverPrerequisites.h"

#include <ostream>

#include "MathMLASTNode.h"
#include "MathMLASTArithmeticExpression.h"
#include "MathMLASTLogicExpression.h"
#include "MathMLASTBinaryComparisionExpression.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLASTUnaryArithmeticExpression.h"
#include "MathMLASTFragmentExpression.h"
#include "MathMLASTVariableExpression.h"
#include "MathMLASTFunctionExpression.h"
#include "MathMLASTVisitor.h"

namespace MathML
{
    /** String constant for less than character. */
    static const String CHAR_LT = "<";
    /** String constant for greater than character. */
    static const String CHAR_GT = ">";
    /** String constant for slash character. */
    static const String CHAR_SLASH = "/";
    /** String constant for the delimiter of the fragment part of a URL. */
    static const String CHAR_URL_FRAGMENT_DELIMITER = "#";
    /** String constant for XML header. */
    static const String MATHML_HEADER_LINE_ONE = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    /** String constant for XML header. */
    static const String MATHML_HEADER_LINE_TWO = "<math xmlns=\"http://www.w3.org/1998/Math/MathML\">";
    /** String constant for closing root element. */
    static const String MATHML_CLOSING_ROOT_ELEMENT = "</math>";

    /** Expression node visitor for serializing MathML.
    */

    class _MATHML_SOLVER_EXPORT SerializationVisitor : public AST::IVisitor
    {

    private:
        /** MathML data is written to this stream. */
        std::ostream& mOutput;
        /** If set the MathML XML header is written to output on construction. */
        bool mWriteXMLHeader;
        /** If set the closing MathML tag is written to output on destruction. */
        bool mWriteClosingRootElement;

    public:
        /** A map containing attribute names and values. */
        typedef std::map< const String*, const String* > AttributeList;

        /** C-tor.
        If writeClosingRootElement is set, the passed output stream must 
        be valid when this object is destroyed.
        @param output Stream which receives MathML data.
        @param writeXMLHeader Should be set to true if a new MathML file is started.
        @param writeClosingRootElement Should be set to true if a MathML file is ended.
        */
        SerializationVisitor( std::ostream& output, bool writeXMLHeader,
                              bool writeClosingRootElement );

        /** D-tor. */
        virtual ~SerializationVisitor();

        // see IVisitor::visit(const ArithmeticExpression&)
        virtual void visit( const AST::ArithmeticExpression* const node );

        // see IVisitor::visit(const BinaryComparisionExpression&)
        virtual void visit( const AST::BinaryComparisonExpression* const node );

        // see IVisitor::visit(const FragmentExpression&)
        virtual void visit( const AST::FragmentExpression* const node );

        // see IVisitor::visit(const LogicExpression&)
        virtual void visit( const AST::LogicExpression* const node );

        // see IVisitor::visit(const ConstantExpression&)
        virtual void visit( const AST::ConstantExpression* const node );

        // see IVisitor::visit(const FunctionExpression&)
        virtual void visit( const AST::FunctionExpression* const node );

        // see IVisitor::visit(const UnaryArithmeticExpression&)
        virtual void visit( const AST::UnaryExpression* const node );

        // see IVisitor::visit(const VariableExpression&)
        virtual void visit( const AST::VariableExpression* const node );

    private:

        /** Writes passed element name with
        surrounding angle brackets to output.
        @param elementName Element name to write.
        */
        void writeStartElement( const String& elementName );

        /** Writes passed element name with
        surrounding angle brackets and passed attributes to output.
        @param elementName Element name to write.
        @param attributes Name value list of attributes.
        */
        void writeStartElementWithAttributes( const String& elementName, const AttributeList& attributes );

        /** Writes passed element name
        with surrounding angle brackets and leading slash to output.
        @param elementName Element name to write.
        */
        void writeEndElement( const String& elementName );

        /** Writes passed element name
        with surrounding angle brackets and trailing slash to output.
        @param elementName Element name to write.
        */
        void writeEmptyElement( const String& elementName );

        /** Writes a string to output.
        @param text Text to write.
        */
        void writeText( const String& text );

        /** Writes a line break character to output. */
        void writeLineBreak();
    };

} //namespace MathML

#endif //__MATHML_SERIALIZATION_VISITOR_H__
