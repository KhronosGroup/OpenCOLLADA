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

#ifndef __MATHMLSOLVER_STABLE_HEADERS_H__
#define __MATHMLSOLVER_STABLE_HEADERS_H__


#include "MathMLSolverPrerequisites.h"

#include <sstream>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <exception>
#include <cmath>
#include <stack>

/*
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
*/

#include "MathMLPlatform.h"
#include "MathMLString.h"
#include "MathMLASTNode.h"
#include "MathMLSymbolTable.h"
#include "MathMLASTArithmeticExpression.h"
#include "MathMLASTBinaryComparisionExpression.h"
#include "MathMLASTConstantExpression.h"
#include "MathMLASTFragmentExpression.h"
#include "MathMLASTFunctionExpression.h"
#include "MathMLASTLogicExpression.h"
#include "MathMLASTUnaryArithmeticExpression.h"
#include "MathMLASTVariableExpression.h"
#include "MathMLASTVisitor.h"
#include "MathMLASTStringVisitor.h"
#include "MathMLEvaluatorVisitor.h"
#include "MathMLSerializationVisitor.h"
#include "MathMLSerializationUtil.h"
#include "MathMLParserConstants.h"
#include "MathMLSolverFunctionExtensions.h"
#include "MathMLError.h"
/*
#include "MathMLParser.h"
*/

#endif //__MATHMLSOLVER_STABLE_HEADERS_H__
