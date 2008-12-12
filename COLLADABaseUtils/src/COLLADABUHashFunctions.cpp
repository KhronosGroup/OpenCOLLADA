#include "COLLADABUStableHeaders.h"
#include "COLLADABUHashFunctions.h"
#include "COLLADABUURI.h"

namespace COLLADABU
{
	unsigned long calculateHash( const String& str )
	{
		return calculateHash(str.c_str());
	}

	unsigned long calculateHash( const char* str )
	{
		unsigned long h = 0;
		unsigned long g;
		const char* pos = str;

		while (*pos != 0) {
			h = (h << 4) + *pos++;
			if ((g = (h & 0xf0000000)) != 0)
				h ^= g >> 24;
			h &= ~g;
		}
		return h;
	}

	unsigned long calculateHash( const URI& uri )
	{
		return calculateHash(uri.getURIString());
	}



} // namespace COLLADABU
