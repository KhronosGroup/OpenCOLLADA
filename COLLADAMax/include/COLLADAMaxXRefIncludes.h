/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_XREFINCLUDE_H__
#define __COLLADAMAX_XREFINCLUDE_H__

#include "COLLADAMaxPrerequisites.h"


#ifdef MAX_8_OR_NEWER

#pragma warning(disable:4100)
#pragma warning(disable:4238)
#pragma warning(disable:4267)

#include <XRef/iXRefObjMgr8.h>
#include <XRef/iXRefMaterial.h>
#include <XRef/iXRefObj.h>

#pragma warning(default:4267)
#pragma warning(default:4238)
#pragma warning(default:4100)

#else

#error "This header ahs not been tested with max version prior to Max 8"

#include <ixref.h>

// re-define a class took from the debug build
class XRefObject_REDEFINITION : public IXRefObject {
public:
	TSTR xrefFile;
	TSTR xrefObj;
	TSTR xrefFileProxy;
	TSTR xrefObjProxy;
	Object *obj;
	DWORD flags;

	// don't care about the rest...
};

#endif // MAX_8_OR_NEWER else



#endif //__COLLADAMAX_XREFINCLUDE_H__

