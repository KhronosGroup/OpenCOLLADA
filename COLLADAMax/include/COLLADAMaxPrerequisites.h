/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_PREREQUISITES_H__
#define __COLLADAMAX_PREREQUISITES_H__

#define UNUSED(a) /**< Removes a piece of code during the pre-process. This macro is useful for these pesky unused variable warnings. */



// Max 2009 requires RTTI to be enabled
#ifdef MAX_2009
#ifndef _CPPRTTI
#error "Max 2009 requires RTTI to be enabled. Please enable and try again..."
#endif
#endif


#define TIME_INITIAL_POSE  0
#define TIME_EXPORT_START  0//OPTS->AnimStart()


#include <string>

namespace COLLADAMax
{
    typedef std::string String;

}



#endif //__COLLADAMAX_PREREQUISITES_H__
