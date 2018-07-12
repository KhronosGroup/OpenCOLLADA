/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	AnimClip():DependNode(){}
	AnimClip(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "animClip", shared, create){}
	virtual ~AnimClip(){}

	void setEnable(bool ea)
	{
		if(ea == 1) return;
		fprintf(mFile,"\tsetAttr \".ea\" %i;\n", ea);
	}
	void setAbsoluteChannel(size_t ac_i,bool ac)
	{
		if(ac == false) return;
		fprintf(mFile,"\tsetAttr \".ac[%i]\" %i;\n", ac_i,ac);
	}
	void setAbsoluteChannel(size_t ac_start,size_t ac_end,bool* ac)
	{
		fprintf(mFile,"\tsetAttr \".ac[%i:%i]\" ", ac_start,ac_end);
		size_t size = (ac_end-ac_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ac[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startAbsoluteChannel(size_t ac_start,size_t ac_end)const
	{
		fprintf(mFile,"\tsetAttr \".ac[%i:%i]\"",ac_start,ac_end);
	}
	void appendAbsoluteChannel(bool ac)const
	{
		fprintf(mFile," %i",ac);
	}
	void endAbsoluteChannel()const
	{
		fprintf(mFile,";\n");
	}
	void setChannelOffset(size_t co_i,double co)
	{
		if(co == 0.0) return;
		fprintf(mFile,"\tsetAttr \".co[%i]\" %f;\n", co_i,co);
	}
	void setChannelOffset(size_t co_start,size_t co_end,double* co)
	{
		fprintf(mFile,"\tsetAttr \".co[%i:%i]\" ", co_start,co_end);
		size_t size = (co_end-co_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",co[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startChannelOffset(size_t co_start,size_t co_end)const
	{
		fprintf(mFile,"\tsetAttr \".co[%i:%i]\"",co_start,co_end);
	}
	void appendChannelOffset(double co)const
	{
		fprintf(mFile," %f",co);
	}
	void endChannelOffset()const
	{
		fprintf(mFile,";\n");
	}
	void setStartFrame(double sf)
	{
		if(sf == 0) return;
		fprintf(mFile,"\tsetAttr \".sf\" %f;\n", sf);
	}
	void setScale(double sc)
	{
		if(sc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sc\" %f;\n", sc);
	}
	void setHold(double h)
	{
		if(h == 0) return;
		fprintf(mFile,"\tsetAttr \".h\" %f;\n", h);
	}
	void setPreCycle(double cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cb\" %f;\n", cb);
	}
	void setPostCycle(double ca)
	{
		if(ca == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ca\" %f;\n", ca);
	}
	void setWeight(double w)
	{
		if(w == 1.0) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setWeightStyle(unsigned int ws)
	{
		if(ws == 0) return;
		fprintf(mFile,"\tsetAttr \".ws\" %i;\n", ws);
	}
	void setPose(bool ps)
	{
		if(ps == false) return;
		fprintf(mFile,"\tsetAttr \".ps\" %i;\n", ps);
	}
	void setSourceStart(double ss)
	{
		if(ss == 0) return;
		fprintf(mFile,"\tsetAttr \".ss\" %f;\n", ss);
	}
	void setSourceEnd(double se)
	{
		if(se == 0) return;
		fprintf(mFile,"\tsetAttr \".se\" %f;\n", se);
	}
	void setClipInstance(bool ci)
	{
		if(ci == 1) return;
		fprintf(mFile,"\tsetAttr \".ci\" %i;\n", ci);
	}
	void setTimeWarp(double tw)
	{
		if(tw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tw\" %f;\n", tw);
	}
	void setTimeWarpEnable(bool twe)
	{
		if(twe == false) return;
		fprintf(mFile,"\tsetAttr \".twe\" %i;\n", twe);
	}
	void setCycle(double cy)
	{
		if(cy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cy\" %f;\n", cy);
	}
	void getEnable()const
	{
		fprintf(mFile,"\"%s.ea\"",mName.c_str());
	}
	void getAbsoluteChannel(size_t ac_i)const
	{
		fprintf(mFile,"\"%s.ac[%i]\"",mName.c_str(),ac_i);
	}
	void getAbsoluteChannel()const
	{

		fprintf(mFile,"\"%s.ac\"",mName.c_str());
	}
	void getChannelOffset(size_t co_i)const
	{
		fprintf(mFile,"\"%s.co[%i]\"",mName.c_str(),co_i);
	}
	void getChannelOffset()const
	{

		fprintf(mFile,"\"%s.co\"",mName.c_str());
	}
	void getStartFrame()const
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getHold()const
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getPreCycle()const
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());
	}
	void getPostCycle()const
	{
		fprintf(mFile,"\"%s.ca\"",mName.c_str());
	}
	void getWeight()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getWeightStyle()const
	{
		fprintf(mFile,"\"%s.ws\"",mName.c_str());
	}
	void getPose()const
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());
	}
	void getSourceStart()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getSourceEnd()const
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());
	}
	void getClip()const
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getClipInstance()const
	{
		fprintf(mFile,"\"%s.ci\"",mName.c_str());
	}
	void getTimeWarp()const
	{
		fprintf(mFile,"\"%s.tw\"",mName.c_str());
	}
	void getTimeWarpEnable()const
	{
		fprintf(mFile,"\"%s.twe\"",mName.c_str());
	}
	void getStart()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getDuration()const
	{
		fprintf(mFile,"\"%s.du\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getAbsoluteRotations()const
	{
		fprintf(mFile,"\"%s.abro\"",mName.c_str());
	}
	void getCycle()const
	{
		fprintf(mFile,"\"%s.cy\"",mName.c_str());
	}
	void getStartTrim()const
	{
		fprintf(mFile,"\"%s.str\"",mName.c_str());
	}
	void getStartPercent()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
protected:
	AnimClip(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCLIP_H__
