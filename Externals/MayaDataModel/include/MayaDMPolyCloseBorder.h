/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCLOSEBORDER_H__
#define __MayaDM_POLYCLOSEBORDER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyCloseBorder : public PolyModifier
{
public:
	PolyCloseBorder():PolyModifier(){}
	PolyCloseBorder(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyCloseBorder"){}
	virtual ~PolyCloseBorder(){}
protected:
	PolyCloseBorder(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:PolyModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCLOSEBORDER_H__
