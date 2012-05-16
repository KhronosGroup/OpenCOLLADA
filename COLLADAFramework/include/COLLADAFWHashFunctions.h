/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_HASHFUNCTIONS_H__
#define __COLLADAFW_HASHFUNCTIONS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADABUhash_map.h"

namespace COLLADABU_HASH_NAMESPACE_OPEN
{
    template<>
    struct COLLADABU_HASH_FUN<COLLADAFW::UniqueId>
    {
        size_t operator() (const COLLADAFW::UniqueId& uniqueId) const { return uniqueId; }

#if defined(_MSC_VER) && _MSC_VER==1400
        static const size_t bucket_size=4;
        static const size_t min_buckets=8;

        bool operator() (const COLLADAFW::UniqueId& uniqueId1, const COLLADAFW::UniqueId& uniqueId2) const { return uniqueId1<uniqueId2; }
#endif
    };
} COLLADABU_HASH_NAMESPACE_CLOSE

#endif // __COLLADAFW_HASHFUNCTIONS_H__
