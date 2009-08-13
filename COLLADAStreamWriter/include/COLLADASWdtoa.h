#ifndef __COLLADASW_DTOA_H__
#define __COLLADASW_DTOA_H__

#include "COLLADASWPrerequisites.h"

#include <stdlib.h>

namespace COLLADASW
{

	//From Common Repo: Rev 31

	/** The minimum size of the buffer, passed to dtoa.*/
	static const size_t DTOA_BUFFERSIZE = 30;


	/** Returns the number of bytes written in to the buffer.
	@param buffer The buffer the string representation of the number will be written to. Its size must be at 
	least DTOA_BUFFERSIZE.
	@param doublePrecision If set to true, up to 16 significant digits are written, otherwise 6*/
	int dtoa(double f, char* buffer, bool doublePrecision = false);

} // namespace COLLADASW

#endif // __COLLADASW_DTOA_H__
