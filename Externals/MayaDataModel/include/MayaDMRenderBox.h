/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	RenderBox():ImplicitBox(){}
	RenderBox(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ImplicitBox(file, name, parent, "renderBox", shared, create){}
	virtual ~RenderBox(){}

protected:
	RenderBox(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ImplicitBox(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERBOX_H__
