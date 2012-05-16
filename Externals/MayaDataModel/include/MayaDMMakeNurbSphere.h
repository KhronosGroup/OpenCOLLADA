/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBSPHERE_H__
#define __MayaDM_MAKENURBSPHERE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRevolvedPrimitive.h"
namespace MayaDM
{
class MakeNurbSphere : public RevolvedPrimitive
{
public:

	MakeNurbSphere():RevolvedPrimitive(){}
	MakeNurbSphere(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:RevolvedPrimitive(file, name, parent, "makeNurbSphere", shared, create){}
	virtual ~MakeNurbSphere(){}

protected:
	MakeNurbSphere(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:RevolvedPrimitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBSPHERE_H__
