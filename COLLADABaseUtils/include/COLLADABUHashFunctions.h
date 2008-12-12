#ifndef __COLLADABU_HASHFUNCTIONS_H__
#define __COLLADABU_HASHFUNCTIONS_H__

#include "COLLADABUPrerequisites.h"



namespace COLLADABU
{
	class URI;


	unsigned long calculateHash(const String& str);

	unsigned long calculateHash(const char* str);

	unsigned long calculateHash(const URI& uri);




} // namespace COLLADABU

#endif // __COLLADABU_HASHFUNCTIONS_H__
