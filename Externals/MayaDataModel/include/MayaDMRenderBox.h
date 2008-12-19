/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERBOX_H__
#define __MayaDM_RENDERBOX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMImplicitBox.h"
namespace MayaDM
{
class RenderBox : public ImplicitBox
{
public:
	RenderBox(FILE* file,const std::string& name,const std::string& parent=""):ImplicitBox(file, name, parent, "renderBox"){}
	virtual ~RenderBox(){}
protected:
	RenderBox(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ImplicitBox(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERBOX_H__
