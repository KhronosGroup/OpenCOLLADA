/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

#include <XRef/iXRefObjMgr8.h>
#include <XRef/iXRefMaterial.h>
#include <XRef/iXRefObj.h>

#else

//#error "This header has not been tested with max version prior to Max 8"

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

