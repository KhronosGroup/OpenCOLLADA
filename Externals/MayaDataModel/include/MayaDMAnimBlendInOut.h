/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMBLENDINOUT_H__
#define __MayaDM_ANIMBLENDINOUT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAnimBlend.h"
namespace MayaDM
{
class AnimBlendInOut : public AnimBlend
{
public:
public:
	AnimBlendInOut(FILE* file,const std::string& name,const std::string& parent=""):AnimBlend(file, name, parent, "animBlendInOut"){}
	virtual ~AnimBlendInOut(){}
	void setRotationBlend(unsigned int rb)
	{
		if(rb == 0) return;
		fprintf(mFile,"setAttr \".rb\" %i;\n", rb);

	}
	void getRotationBlend()
	{
		fprintf(mFile,"\"%s.rb\"",mName.c_str());

	}
protected:
	AnimBlendInOut(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AnimBlend(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMBLENDINOUT_H__
