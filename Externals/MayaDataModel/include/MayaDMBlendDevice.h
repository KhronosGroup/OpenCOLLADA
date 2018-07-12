/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	BlendDevice():Blend(){}
	BlendDevice(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Blend(file, name, parent, "blendDevice", shared, create){}
	virtual ~BlendDevice(){}

	void setInputAngle(size_t ia_i,double ia)
	{
		if(ia == 0) return;
		fprintf(mFile,"\tsetAttr \".ia[%i]\" %f;\n", ia_i,ia);
	}
	void setInputAngle(size_t ia_start,size_t ia_end,double* ia)
	{
		fprintf(mFile,"\tsetAttr \".ia[%i:%i]\" ", ia_start,ia_end);
		size_t size = (ia_end-ia_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ia[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInputAngle(size_t ia_start,size_t ia_end)const
	{
		fprintf(mFile,"\tsetAttr \".ia[%i:%i]\"",ia_start,ia_end);
	}
	void appendInputAngle(double ia)const
	{
		fprintf(mFile," %f",ia);
	}
	void endInputAngle()const
	{
		fprintf(mFile,";\n");
	}
	void setInputLinear(size_t il_i,double il)
	{
		if(il == 0) return;
		fprintf(mFile,"\tsetAttr \".il[%i]\" %f;\n", il_i,il);
	}
	void setInputLinear(size_t il_start,size_t il_end,double* il)
	{
		fprintf(mFile,"\tsetAttr \".il[%i:%i]\" ", il_start,il_end);
		size_t size = (il_end-il_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",il[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInputLinear(size_t il_start,size_t il_end)const
	{
		fprintf(mFile,"\tsetAttr \".il[%i:%i]\"",il_start,il_end);
	}
	void appendInputLinear(double il)const
	{
		fprintf(mFile," %f",il);
	}
	void endInputLinear()const
	{
		fprintf(mFile,";\n");
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getDeviceValue()const
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());
	}
	void getDeviceBlender()const
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());
	}
	void getInputAngle(size_t ia_i)const
	{
		fprintf(mFile,"\"%s.ia[%i]\"",mName.c_str(),ia_i);
	}
	void getInputAngle()const
	{

		fprintf(mFile,"\"%s.ia\"",mName.c_str());
	}
	void getOutputAngle()const
	{
		fprintf(mFile,"\"%s.oa\"",mName.c_str());
	}
	void getInputLinear(size_t il_i)const
	{
		fprintf(mFile,"\"%s.il[%i]\"",mName.c_str(),il_i);
	}
	void getInputLinear()const
	{

		fprintf(mFile,"\"%s.il\"",mName.c_str());
	}
	void getOutputLinear()const
	{
		fprintf(mFile,"\"%s.ol\"",mName.c_str());
	}
	void getBlender()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getMinTime()const
	{
		fprintf(mFile,"\"%s.mnt\"",mName.c_str());
	}
	void getPeriod()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getTimeStamp()const
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());
	}
	void getData()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getStride()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.off\"",mName.c_str());
	}
protected:
	BlendDevice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Blend(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLENDDEVICE_H__
