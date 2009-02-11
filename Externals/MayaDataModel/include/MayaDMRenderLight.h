/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERLIGHT_H__
#define __MayaDM_RENDERLIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLight.h"
namespace MayaDM
{
class RenderLight : public Light
{
public:
public:
	RenderLight():Light(){}
	RenderLight(FILE* file,const std::string& name,const std::string& parent=""):Light(file, name, parent, "renderLight"){}
	virtual ~RenderLight(){}
	void getRayInstance()
	{
		fprintf(mFile,"\"%s.ryi\"",mName.c_str());

	}
protected:
	RenderLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Light(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERLIGHT_H__
