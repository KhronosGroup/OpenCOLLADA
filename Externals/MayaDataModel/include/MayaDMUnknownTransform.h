/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNKNOWNTRANSFORM_H__
#define __MayaDM_UNKNOWNTRANSFORM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class UnknownTransform : public Transform
{
public:
	UnknownTransform():Transform(){}
	UnknownTransform(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:Transform(file, name, parent, "unknownTransform", create){}
	virtual ~UnknownTransform(){}
protected:
	UnknownTransform(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:Transform(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_UNKNOWNTRANSFORM_H__
