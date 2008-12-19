/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDDEVICE_H__
#define __MayaDM_BLENDDEVICE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBlend.h"
namespace MayaDM
{
class BlendDevice : public Blend
{
public:
public:
	BlendDevice(FILE* file,const std::string& name,const std::string& parent=""):Blend(file, name, parent, "blendDevice"){}
	virtual ~BlendDevice(){}
	void setInputAngle(size_t ia_i,double ia)
	{
		if(ia == 0) return;
		fprintf(mFile,"setAttr \".ia[%i]\" %f;\n", ia_i,ia);

	}
	void setInputLinear(size_t il_i,double il)
	{
		if(il == 0) return;
		fprintf(mFile,"setAttr \".il[%i]\" %f;\n", il_i,il);

	}
	void getTime()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getDeviceValue()
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());

	}
	void getDeviceBlender()
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());

	}
	void getInputAngle(size_t ia_i)
	{
		fprintf(mFile,"\"%s.ia[%i]\"",mName.c_str(),ia_i);

	}
	void getOutputAngle()
	{
		fprintf(mFile,"\"%s.oa\"",mName.c_str());

	}
	void getInputLinear(size_t il_i)
	{
		fprintf(mFile,"\"%s.il[%i]\"",mName.c_str(),il_i);

	}
	void getOutputLinear()
	{
		fprintf(mFile,"\"%s.ol\"",mName.c_str());

	}
	void getBlender()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getMinTime()
	{
		fprintf(mFile,"\"%s.mnt\"",mName.c_str());

	}
	void getPeriod()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getTimeStamp()
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());

	}
	void getData()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getStride()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.off\"",mName.c_str());

	}
protected:
	BlendDevice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Blend(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLENDDEVICE_H__
