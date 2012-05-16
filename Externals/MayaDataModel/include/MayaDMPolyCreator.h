/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCREATOR_H__
#define __MayaDM_POLYCREATOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyBase.h"
namespace MayaDM
{
class PolyCreator : public PolyBase
{
public:

	PolyCreator():PolyBase(){}
	PolyCreator(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyBase(file, name, parent, "polyCreator", shared, create){}
	virtual ~PolyCreator(){}

protected:
	PolyCreator(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyBase(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCREATOR_H__
