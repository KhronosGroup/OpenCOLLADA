/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
Closes open borders of objects. A new face is created for
 each hole in the poly object. Non-holed border edges can
 also be closed. Closes borders if any of the edges
 on the border are in the input group.<p/>
*/
class PolyCloseBorder : public PolyModifier
{
public:
public:
	PolyCloseBorder(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyCloseBorder"){}
	virtual ~PolyCloseBorder(){}
protected:
	PolyCloseBorder(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCLOSEBORDER_H__
