/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class PolyCreaseEdge : public PolyCrease
{
public:

	PolyCreaseEdge():PolyCrease(){}
	PolyCreaseEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyCrease(file, name, parent, "polyCreaseEdge", shared, create){}
	virtual ~PolyCreaseEdge(){}

protected:
	PolyCreaseEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyCrease(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCREASEEDGE_H__
