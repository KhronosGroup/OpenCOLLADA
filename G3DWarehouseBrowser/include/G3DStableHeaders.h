/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __G3D_STABLE_HEADERS_H__
#define __G3D_STABLE_HEADERS_H__

#include "G3DPrerequisites.h"
#include <windows.h>
#include <oleidl.h>
#include <assert.h>
#include <ExDisp.h>
#include <mshtml.h>
#include <mshtmhst.h>
#include <commctrl.h>
#include <SYS\Stat.h>
#include <direct.h>


//zzip
#include "zzip/zzip.h"


//stl
#include <string>
#include <map>


#define NOTIMPLEMENTED assert(0); return(E_NOTIMPL)

#endif //__G3D_STABLE_HEADERS_H__