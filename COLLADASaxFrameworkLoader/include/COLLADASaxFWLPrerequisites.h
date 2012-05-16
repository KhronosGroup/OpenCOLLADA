/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_PREREQUISITES_H__
#define __COLLADASAXFWL_PREREQUISITES_H__

#include <cstddef>
#include <limits>

#include <string>
#include <cassert>
#include "COLLADABUPlatform.h"

namespace COLLADASaxFWL
{
    typedef std::string String;


	enum COLLADAVersion
	{  
		COLLADA_UNKNOWN,
		COLLADA_14,
		COLLADA_15
	};


#define COLLADASAXFWL_REAL_IS_FLOAT

#ifdef COLLADASAXFWL_REAL_IS_FLOAT
	typedef float Real;
#else
	typedef float Double;
#endif

}


#ifndef NDEBUG
	// Uncomment this line, if you want to check, that the sax parser functions are virtual functions of the base class
	// This a only a compile time check. Comment this line if you want to run the frame work loader;
#	define MakeVirtualFunctionTest
#endif //NDEBUG

	// This macro should be used in every reimplementation of one of the virtual functions of ColladaParserAutoGen
	// When MakeVirtualFunctionTest is defined, this macro checks, if this function exist as a method in ColladaParserAutoGen
	// The parameter is the name of the function, i.e. every reimplementation of a class called C should looke like:
	// C::begin__elementName( SaxVirtualFunctionTest(begin__elementName) .... )
	// 
#ifdef MakeVirtualFunctionTest
#	define SaxVirtualFunctionTest14(f) if (false) static_cast<ColladaParserAutoGen14*>(this)->f; 
#else
#	define SaxVirtualFunctionTest14(f)
#endif //MakeVirtualFunctionTest

#ifdef MakeVirtualFunctionTest
#	define SaxVirtualFunctionTest15(f) if (false) static_cast<ColladaParserAutoGen15*>(this)->f; 
#else
#	define SaxVirtualFunctionTest15(f)
#endif //MakeVirtualFunctionTest



#endif //__COLLADASAXFWL_PREREQUISITES_H__
