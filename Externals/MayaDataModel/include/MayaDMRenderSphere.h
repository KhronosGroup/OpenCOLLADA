/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERSPHERE_H__
#define __MayaDM_RENDERSPHERE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMImplicitSphere.h"
namespace MayaDM
{
class RenderSphere : public ImplicitSphere
{
public:
	RenderSphere(FILE* file,const std::string& name,const std::string& parent=""):ImplicitSphere(file, name, parent, "renderSphere"){}
	virtual ~RenderSphere(){}
protected:
	RenderSphere(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ImplicitSphere(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERSPHERE_H__
