/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CGFXSHADER_H__
#define __MayaDM_CGFXSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMHwShader.h"
namespace MayaDM
{
class CgfxShader : public HwShader
{
public:
public:
	CgfxShader(FILE* file,const std::string& name,const std::string& parent=""):HwShader(file, name, parent, "cgfxShader"){}
	virtual ~CgfxShader(){}
protected:
	CgfxShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):HwShader(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CGFXSHADER_H__
