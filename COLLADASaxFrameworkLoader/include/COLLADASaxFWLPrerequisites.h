/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_PREREQUISITES_H__
#define __COLLADASAXFWL_PREREQUISITES_H__

#include <string>
#include <cassert>
#include "COLLADABUPlatform.h"

namespace COLLADASaxFWL
{
    typedef std::string String;

}


#ifndef NDEBUG
	// Uncomment this line, if you want to check, that the sax parser functions are virtual functions of the base class
	// This a only a compile time check. Comment this line if you want to run the frame work loader;
//#	define MakeVirtualFunctionTest
#endif //NDEBUG

	// This macro should be used in every reimplementation of one of the virtual functions of ColladaParserAutoGen
	// When MakeVirtualFunctionTest is defined, this macro checks, if this function exist as a method in ColladaParserAutoGen
	// The parameter is the name of the function, i.e. every reimplementation of a class called C should looke like:
	// C::begin__elementName( SaxVirtualFunctionTest(begin__elementName) .... )
	// 
#ifdef MakeVirtualFunctionTest
#	define SaxVirtualFunctionTest(f) assert(false); static_cast<ColladaParserAutoGen*>(this)->f; 
#else
#	define SaxVirtualFunctionTest(f)
#endif //MakeVirtualFunctionTest



#endif //__COLLADASAXFWL_PREREQUISITES_H__
