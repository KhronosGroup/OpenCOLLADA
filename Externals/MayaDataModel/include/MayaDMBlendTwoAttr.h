/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDTWOATTR_H__
#define __MayaDM_BLENDTWOATTR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBlend.h"
namespace MayaDM
{
class BlendTwoAttr : public Blend
{
public:
public:
	BlendTwoAttr():Blend(){}
	BlendTwoAttr(FILE* file,const std::string& name,const std::string& parent=""):Blend(file, name, parent, "blendTwoAttr"){}
	virtual ~BlendTwoAttr(){}
	void setAttributesBlender(float ab)
	{
		if(ab == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ab\" %f;\n", ab);

	}
	void getAttributesBlender()
	{
		fprintf(mFile,"\"%s.ab\"",mName.c_str());

	}
protected:
	BlendTwoAttr(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Blend(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLENDTWOATTR_H__
