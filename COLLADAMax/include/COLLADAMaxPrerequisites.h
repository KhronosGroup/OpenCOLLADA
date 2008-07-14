/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
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
