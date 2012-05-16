/*
    Copyright (c) 2010 yaoyansi<yaoyansi2@yahoo.com.cn>

    This file is part of dae23ds_lib3ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_PREREQUISITES_H__
#define __DAE23DS_PREREQUISITES_H__

#include <string>

namespace DAE23ds
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



#endif //__DAE23DS_PREREQUISITES_H__


