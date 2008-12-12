/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYDELVERTEX_H__
#define __MayaDM_POLYDELVERTEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Deletes vertices. Only vertices which are connected to
 exactly two edges (so-called "winged vertices") can be deleted.<p/>
*/
class PolyDelVertex : public PolyModifier
{
public:
public:
	PolyDelVertex(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyDelVertex"){}
	virtual ~PolyDelVertex(){}
protected:
	PolyDelVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYDELVERTEX_H__
