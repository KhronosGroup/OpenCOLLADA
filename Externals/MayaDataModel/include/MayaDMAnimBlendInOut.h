/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	AnimBlendInOut():AnimBlend(){}
	AnimBlendInOut(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AnimBlend(file, name, parent, "animBlendInOut", shared, create){}
	virtual ~AnimBlendInOut(){}

	void setRotationBlend(unsigned int rb)
	{
		if(rb == 0) return;
		fprintf(mFile,"\tsetAttr \".rb\" %i;\n", rb);
	}
	void getRotationBlend()const
	{
		fprintf(mFile,"\"%s.rb\"",mName.c_str());
	}
protected:
	AnimBlendInOut(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AnimBlend(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMBLENDINOUT_H__
