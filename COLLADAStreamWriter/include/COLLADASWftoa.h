#ifndef __COLLADASW_FTOA_H__
#define __COLLADASW_FTOA_H__

#include "COLLADASWPrerequisites.h"

#include <stdlib.h>

namespace COLLADASW
{

	//From Common Repo: Rev 31

	/** The minimum size of the buffer, passed to ftoa.*/
	static const size_t FTOA_BUFFERSIZE = 30;


	/** Returns the number of bytes written in to the buffer.
	@param buffer The buffer the string representation of the number will be written to. Its size must be at 
	least FTOA_BUFFERSIZE.*/
	int ftoa(float f, char* buffer);


} // namespace COLLADASW

#endif // __COLLADASW_FTOA_H__
