/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2OGRE_PREREQUISITES_H__
#define __DAE2OGRE_PREREQUISITES_H__

#include <string>

namespace DAE2Ogre
{
	typedef std::string String;
}


// Endian Settings
// check for BIG_ENDIAN config flag, set CPF_ENDIAN correctly
#ifdef CPF_CONFIG_BIG_ENDIAN
#    define CPF_ENDIAN CPF_ENDIAN_BIG
#else
#    define CPF_ENDIAN CPF_ENDIAN_LITTLE
#endif

// Integer formats of fixed bit width
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;



#endif //__DAE2OGRE_PREREQUISITES_H__


