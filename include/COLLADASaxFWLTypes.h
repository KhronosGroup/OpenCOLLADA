/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADASaxFrameworkLoader.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_TYPES_H__
#define __COLLADASAXFWL_TYPES_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWTypes.h"

#include "GeneratedSaxParser.h"

#include <list>

namespace COLLADAFW
{
	class Node;
}

namespace COLLADASaxFWL
{

    typedef GeneratedSaxParser::sint8 sint8;
    typedef GeneratedSaxParser::sint16 sint16;
    typedef GeneratedSaxParser::sint32 sint32;
    typedef GeneratedSaxParser::sint64 sint64;
    typedef GeneratedSaxParser::uint8 uint8;
    typedef GeneratedSaxParser::uint16 uint16;
    typedef GeneratedSaxParser::uint32 uint32;
    typedef GeneratedSaxParser::uint64 uint64;

    typedef GeneratedSaxParser::StringHash StringHash;
    typedef GeneratedSaxParser::ParserChar ParserChar;
    typedef GeneratedSaxParser::ParserString ParserString;
    typedef GeneratedSaxParser::ParserAttributes ParserAttributes;
    typedef GeneratedSaxParser::Utils Utils;
    typedef GeneratedSaxParser::ParserError ParserError;
    typedef GeneratedSaxParser::StringHashPair StringHashPair;


    struct AnimationInfo
	{
		static const AnimationInfo INVALID;
		/** The unique id of the animation*/
		COLLADAFW::UniqueId uniqueId;

		/** The class of the animation.*/
		COLLADAFW::AnimationList::AnimationClass animationClass;
	};



#ifdef COLLADASAXFWL_REAL_IS_FLOAT
	typedef COLLADAFW::FloatArray RealArray;
#else
	typedef COLLADAFW::DoubleArray RealArray;
#endif

	typedef std::vector<COLLADAFW::Node*> NodeList;



} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_TYPES_H__
