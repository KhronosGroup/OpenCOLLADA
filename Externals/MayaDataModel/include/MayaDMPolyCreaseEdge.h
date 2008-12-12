/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCREASEEDGE_H__
#define __MayaDM_POLYCREASEEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyCrease.h"
namespace MayaDM
{
/*
<p><pre> Selectively assigns weights to edges.

</pre></p>
*/
class PolyCreaseEdge : public PolyCrease
{
public:
public:
	PolyCreaseEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyCrease(file, name, parent, "polyCreaseEdge"){}
	virtual ~PolyCreaseEdge(){}
protected:
	PolyCreaseEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyCrease(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCREASEEDGE_H__
