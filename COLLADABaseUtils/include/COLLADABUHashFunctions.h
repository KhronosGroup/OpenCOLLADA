/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

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
