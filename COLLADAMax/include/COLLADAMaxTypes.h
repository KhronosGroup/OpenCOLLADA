/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_TYPES_H__
#define __COLLADAMAX_TYPES_H__

#include "COLLADAMaxPrerequisites.h"

#include <vector>
#include <map>
#include <set>

class INode;
class ExportNode;

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

	/** List of INodes*/
	typedef std::vector<INode*> INodeList;

	typedef std::set<ExportNode*> ExportNodeSet;

}


#endif //__COLLADAMAX_TYPES_H__
