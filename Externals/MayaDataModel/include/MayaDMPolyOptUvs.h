/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYOPTUVS_H__
#define __MayaDM_POLYOPTUVS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
class PolyOptUvs : public PolyModifierUV
{
public:
public:

	PolyOptUvs():PolyModifierUV(){}
	PolyOptUvs(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, "polyOptUvs", shared, create){}
	virtual ~PolyOptUvs(){}

	void setIterations(int i_)
	{
		if(i_ == 100) return;
		fprintf(mFile,"\tsetAttr \".i\" %i;\n", i_);
	}
	void setStoppingThreshold(float ss)
	{
		if(ss == .001) return;
		fprintf(mFile,"\tsetAttr \".ss\" %f;\n", ss);
	}
	void setAreaWeight(float aw)
	{
		if(aw == 1.) return;
		fprintf(mFile,"\tsetAttr \".aw\" %f;\n", aw);
	}
	void setUseScale(bool us)
	{
		if(us == false) return;
		fprintf(mFile,"\tsetAttr \".us\" %i;\n", us);
	}
	void setScale(float s)
	{
		if(s == 1.) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void setPinUvBorder(bool pub)
	{
		if(pub == 0) return;
		fprintf(mFile,"\tsetAttr \".pub\" %i;\n", pub);
	}
	void setPinSelected(bool ps)
	{
		if(ps == 0) return;
		fprintf(mFile,"\tsetAttr \".ps\" %i;\n", ps);
	}
	void setApplyToShell(bool as)
	{
		if(as == 0) return;
		fprintf(mFile,"\tsetAttr \".as\" %i;\n", as);
	}
	void setOptimizeAxis(unsigned int oa)
	{
		if(oa == 0) return;
		fprintf(mFile,"\tsetAttr \".oa\" %i;\n", oa);
	}
	void setGlobalBlend(float gb)
	{
		if(gb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gb\" %f;\n", gb);
	}
	void setGlobalMethodBlend(float gmb)
	{
		if(gmb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".gmb\" %f;\n", gmb);
	}
	void getIterations()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getStoppingThreshold()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getAreaWeight()const
	{
		fprintf(mFile,"\"%s.aw\"",mName.c_str());
	}
	void getUseScale()const
	{
		fprintf(mFile,"\"%s.us\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getPinUvBorder()const
	{
		fprintf(mFile,"\"%s.pub\"",mName.c_str());
	}
	void getPinSelected()const
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());
	}
	void getApplyToShell()const
	{
		fprintf(mFile,"\"%s.as\"",mName.c_str());
	}
	void getOptimizeAxis()const
	{
		fprintf(mFile,"\"%s.oa\"",mName.c_str());
	}
	void getGlobalBlend()const
	{
		fprintf(mFile,"\"%s.gb\"",mName.c_str());
	}
	void getGlobalMethodBlend()const
	{
		fprintf(mFile,"\"%s.gmb\"",mName.c_str());
	}
protected:
	PolyOptUvs(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYOPTUVS_H__
