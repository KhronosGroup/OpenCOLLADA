/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBCYLINDER_H__
#define __MayaDM_MAKENURBCYLINDER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRevolvedPrimitive.h"
namespace MayaDM
{
class MakeNurbCylinder : public RevolvedPrimitive
{
public:

	MakeNurbCylinder():RevolvedPrimitive(){}
	MakeNurbCylinder(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:RevolvedPrimitive(file, name, parent, "makeNurbCylinder", shared, create){}
	virtual ~MakeNurbCylinder(){}

protected:
	MakeNurbCylinder(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:RevolvedPrimitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBCYLINDER_H__
