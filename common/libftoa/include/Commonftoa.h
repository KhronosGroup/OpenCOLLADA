/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libftoa.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMON_FTOA_H__
#define __COMMON_FTOA_H__

#include <stdlib.h>

namespace Common
{

	/** The minimum size of the buffer, passed to ftoa.*/
	static const size_t FTOA_BUFFERSIZE = 30;


	/** Returns the number of bytes written in to the buffer.
	@param buffer The buffer the string representation of the number will be written to. Its size must be at 
	least FTOA_BUFFERSIZE.*/
	int ftoa(float f, char* buffer);

}

#endif // __COMMON_FTOA_H__
