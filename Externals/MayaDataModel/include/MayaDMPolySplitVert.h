/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSPLITVERT_H__
#define __MayaDM_POLYSPLITVERT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
<p><pre> Split one or more vertices so that each face that shared the vertex
 acquires its own copy of the vertex. This operation will affect all the
 edges and faces that shared the vertex. Also, this operation may create
 non-manifold geometry as a part of this operation. You can use
 Polygons->Cleanup afterwards to to clean up any non-manifold geometry.

</pre></p>
*/
class PolySplitVert : public PolyModifierWorld
{
public:
public:
	PolySplitVert(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polySplitVert"){}
	virtual ~PolySplitVert(){}
protected:
	PolySplitVert(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSPLITVERT_H__
