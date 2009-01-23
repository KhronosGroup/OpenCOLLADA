/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMCLIP_H__
#define __MayaDM_ANIMCLIP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class AnimClip : public DependNode
{
public:
public:
	AnimClip(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "animClip"){}
	virtual ~AnimClip(){}
	void setEnable(bool ea)
	{
		if(ea == 1) return;
		fprintf(mFile,"setAttr \".ea\" %i;\n", ea);

	}
	void setAbsoluteChannel(size_t ac_i,bool ac)
	{
		if(ac == false) return;
		fprintf(mFile,"setAttr \".ac[%i]\" %i;\n", ac_i,ac);

	}
	void setAbsoluteChannel(size_t ac_start,size_t ac_end,bool* ac)
	{
		fprintf(mFile,"setAttr \".ac[%i:%i]\" ", ac_start,ac_end);
		size_t size = (ac_end-ac_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ac[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startAbsoluteChannel(size_t ac_start,size_t ac_end)
	{
		fprintf(mFile,"setAttr \".ac[%i:%i]\"",ac_start,ac_end);

	}
	void appendAbsoluteChannel(bool ac)
	{
		fprintf(mFile," %i",ac);

	}
	void endAbsoluteChannel()
	{
		fprintf(mFile,";\n");

	}
	void setChannelOffset(size_t co_i,double co)
	{
		if(co == 0.0) return;
		fprintf(mFile,"setAttr \".co[%i]\" %f;\n", co_i,co);

	}
	void setChannelOffset(size_t co_start,size_t co_end,double* co)
	{
		fprintf(mFile,"setAttr \".co[%i:%i]\" ", co_start,co_end);
		size_t size = (co_end-co_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",co[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startChannelOffset(size_t co_start,size_t co_end)
	{
		fprintf(mFile,"setAttr \".co[%i:%i]\"",co_start,co_end);

	}
	void appendChannelOffset(double co)
	{
		fprintf(mFile," %f",co);

	}
	void endChannelOffset()
	{
		fprintf(mFile,";\n");

	}
	void setScale(double sc)
	{
		if(sc == 1.0) return;
		fprintf(mFile,"setAttr \".sc\" %f;\n", sc);

	}
	void setPreCycle(double cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"setAttr \".cb\" %f;\n", cb);

	}
	void setPostCycle(double ca)
	{
		if(ca == 0.0) return;
		fprintf(mFile,"setAttr \".ca\" %f;\n", ca);

	}
	void setWeight(double w)
	{
		if(w == 1.0) return;
		fprintf(mFile,"setAttr \".w\" %f;\n", w);

	}
	void setWeightStyle(unsigned int ws)
	{
		if(ws == 0) return;
		fprintf(mFile,"setAttr \".ws\" %i;\n", ws);

	}
	void setPose(bool ps)
	{
		if(ps == false) return;
		fprintf(mFile,"setAttr \".ps\" %i;\n", ps);

	}
	void setClipInstance(bool ci)
	{
		if(ci == 1) return;
		fprintf(mFile,"setAttr \".ci\" %i;\n", ci);

	}
	void setTimeWarp(double tw)
	{
		if(tw == 0.0) return;
		fprintf(mFile,"setAttr \".tw\" %f;\n", tw);

	}
	void setTimeWarpEnable(bool twe)
	{
		if(twe == false) return;
		fprintf(mFile,"setAttr \".twe\" %i;\n", twe);

	}
	void setCycle(double cy)
	{
		if(cy == 1.0) return;
		fprintf(mFile,"setAttr \".cy\" %f;\n", cy);

	}
	void getEnable()
	{
		fprintf(mFile,"\"%s.ea\"",mName.c_str());

	}
	void getAbsoluteChannel(size_t ac_i)
	{
		fprintf(mFile,"\"%s.ac[%i]\"",mName.c_str(),ac_i);

	}
	void getChannelOffset(size_t co_i)
	{
		fprintf(mFile,"\"%s.co[%i]\"",mName.c_str(),co_i);

	}
	void getStartFrame()
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getHold()
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());

	}
	void getPreCycle()
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());

	}
	void getPostCycle()
	{
		fprintf(mFile,"\"%s.ca\"",mName.c_str());

	}
	void getWeight()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getWeightStyle()
	{
		fprintf(mFile,"\"%s.ws\"",mName.c_str());

	}
	void getPose()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getSourceStart()
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getSourceEnd()
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());

	}
	void getClip()
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());

	}
	void getClipInstance()
	{
		fprintf(mFile,"\"%s.ci\"",mName.c_str());

	}
	void getTimeWarp()
	{
		fprintf(mFile,"\"%s.tw\"",mName.c_str());

	}
	void getTimeWarpEnable()
	{
		fprintf(mFile,"\"%s.twe\"",mName.c_str());

	}
	void getStart()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getDuration()
	{
		fprintf(mFile,"\"%s.du\"",mName.c_str());

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getAbsoluteRotations()
	{
		fprintf(mFile,"\"%s.abro\"",mName.c_str());

	}
	void getCycle()
	{
		fprintf(mFile,"\"%s.cy\"",mName.c_str());

	}
	void getStartTrim()
	{
		fprintf(mFile,"\"%s.str\"",mName.c_str());

	}
	void getStartPercent()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
protected:
	AnimClip(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCLIP_H__
