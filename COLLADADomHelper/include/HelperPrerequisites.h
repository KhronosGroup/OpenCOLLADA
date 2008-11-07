/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_HELPER_PREREQUISITES_H__
#define __COLLADA_HELPER_PREREQUISITES_H__

#ifdef WIN32
# ifdef COLLADA_COLLADA_BREP_HELPER_EXPORTS
#  define _HelperExport __declspec(dllexport)
# else
#  define _HelperExport __declspec(dllimport)
# endif
#else
# define _HelperExport
#endif

typedef std::string String;

#endif //__COLLADA_HELPER_PREREQUISITES_H__
