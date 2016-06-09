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


#ifndef __COLLADAMAX_STABLE_HEADERS_H__
#define __COLLADAMAX_STABLE_HEADERS_H__


#include "COLLADAMaxPrerequisites.h"

#ifdef MAX_7
#	pragma message ("Compling for Max7")
#elif defined MAX_8
#	pragma message ("Compling for Max8")
#elif defined MAX_9
#	pragma message ("Compling for Max9")
#elif defined MAX_2008
#	pragma message ("Compling for Max2008")
#elif defined MAX_2009
#	pragma message ("Compling for Max2009")
#elif defined MAX_2010
#	pragma message ("Compling for Max2010")
#elif defined MAX_2011
#	pragma message ("Compiling for Max2011")
#elif defined MAX_2012
#	pragma message ("Compiling for Max2012")
#elif defined MAX_2013
#	pragma message ("Compiling for Max2013")
#elif defined MAX_2014
#	pragma message ("Compiling for Max2014")
#elif defined MAX_2015
#	pragma message ("Compiling for Max2015")
#elif defined MAX_2016
#	pragma message ("Compiling for Max2016")
#elif defined MAX_2017
#	pragma message ("Compiling for Max2017")
#else
#	error( "Unsupported Max version" )
#endif

#include <Max.h>
#include <istdplug.h>
#include <iparamb2.h>	// for IparamBlock2
#include <iparamm2.h>    // for IparamBlock2
#include <bitmap.h>    //for bitmap info
#include <triobj.h>
#include <MeshNormalSpec.h>
#include <modstack.h>   // for IDerivedObject
#include <cs/bipexp.h>   // for BipIface
#include <matrix3.h>
#include <stdmat.h>       // for standard material
#include <shaders.h>   // for shaders
#include <decomp.h>    // for decomposition of transformations
#include <simpobj.h>   //for SimpleObject2
#include <imtl.h>      // for UVGen
#include <custcont.h>  //for dialog

#include <IDxMaterial.h>  // for IDxMaterial

#include "MorphR3.h"		//for morph controller MorphR3 

#include <surf_api.h>    //for shapes


#include "COLLADAMaxXRefIncludes.h"


//STL
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>


#endif //__COLLADAMAX_STABLE_HEADERS_H__
