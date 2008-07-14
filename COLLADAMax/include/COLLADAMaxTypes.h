/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_TYPES_H__
#define __COLLADAMAX_TYPES_H__

#include "COLLADAMaxPrerequisites.h"

#include <vector>
#include <map>


namespace COLLADAMax
{

    /** A list of ids of effects that are exported*/
    typedef std::vector<String> ExportedEffectIdList;

    /** A list of wire frame colors that are exported*/
    typedef std::vector<DWORD> WireFrameColorEffectList;

    /** Maps material pointers to effect ids*/
    typedef std::map<Mtl*, String> EffectMap;

    /**map<filename,imageID>*/
    typedef std::map<String, String> ExportedImageMap;

}


#endif //__COLLADAMAX_TYPES_H__
