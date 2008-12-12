/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCOLLAPSEEDGE_H__
#define __MayaDM_POLYCOLLAPSEEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
<p><pre> Turns each selected edge into a point.
</pre></p>
*/
class PolyCollapseEdge : public PolyModifier
{
public:
public:
	PolyCollapseEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyCollapseEdge"){}
	virtual ~PolyCollapseEdge(){}
protected:
	PolyCollapseEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOLLAPSEEDGE_H__
