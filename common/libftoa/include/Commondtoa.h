/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libftoa.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMON_DTOA_H__
#define __COMMON_DTOA_H__

#include <stdlib.h>

namespace Common
{

	/** The minimum size of the buffer, passed to dtoa.*/
	static const size_t DTOA_BUFFERSIZE = 30;


	/** Returns the number of bytes written in to the buffer.
	@param buffer The buffer the string representation of the number will be written to. Its size must be at 
	least DTOA_BUFFERSIZE.
	@param doublePrecision If set to true, up to 16 significant digits are written, otherwise 6*/
	int dtoa(double f, char* buffer, bool doublePrecision = false);

}

#endif // __COMMON_DTOA_H__
