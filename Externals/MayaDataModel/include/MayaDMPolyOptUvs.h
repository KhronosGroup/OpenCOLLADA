/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolyOptUvs(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyOptUvs"){}
	virtual ~PolyOptUvs(){}
	void setIterations(int i)
	{
		if(i == 100) return;
		fprintf(mFile,"setAttr \".i\" %i;\n", i);

	}
	void setStoppingThreshold(float ss)
	{
		if(ss == .001) return;
		fprintf(mFile,"setAttr \".ss\" %f;\n", ss);

	}
	void setAreaWeight(float aw)
	{
		if(aw == 1.) return;
		fprintf(mFile,"setAttr \".aw\" %f;\n", aw);

	}
	void setUseScale(bool us)
	{
		if(us == false) return;
		fprintf(mFile,"setAttr \".us\" %i;\n", us);

	}
	void setScale(float s)
	{
		if(s == 1.) return;
		fprintf(mFile,"setAttr \".s\" %f;\n", s);

	}
	void setPinUvBorder(bool pub)
	{
		if(pub == 0) return;
		fprintf(mFile,"setAttr \".pub\" %i;\n", pub);

	}
	void setPinSelected(bool ps)
	{
		if(ps == 0) return;
		fprintf(mFile,"setAttr \".ps\" %i;\n", ps);

	}
	void setApplyToShell(bool as)
	{
		if(as == 0) return;
		fprintf(mFile,"setAttr \".as\" %i;\n", as);

	}
	void setOptimizeAxis(unsigned int oa)
	{
		if(oa == 0) return;
		fprintf(mFile,"setAttr \".oa\" %i;\n", oa);

	}
	void setGlobalBlend(float gb)
	{
		if(gb == 0.0) return;
		fprintf(mFile,"setAttr \".gb\" %f;\n", gb);

	}
	void setGlobalMethodBlend(float gmb)
	{
		if(gmb == 0.5) return;
		fprintf(mFile,"setAttr \".gmb\" %f;\n", gmb);

	}
	void getIterations()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getStoppingThreshold()
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getAreaWeight()
	{
		fprintf(mFile,"\"%s.aw\"",mName.c_str());

	}
	void getUseScale()
	{
		fprintf(mFile,"\"%s.us\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getPinUvBorder()
	{
		fprintf(mFile,"\"%s.pub\"",mName.c_str());

	}
	void getPinSelected()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getApplyToShell()
	{
		fprintf(mFile,"\"%s.as\"",mName.c_str());

	}
	void getOptimizeAxis()
	{
		fprintf(mFile,"\"%s.oa\"",mName.c_str());

	}
	void getGlobalBlend()
	{
		fprintf(mFile,"\"%s.gb\"",mName.c_str());

	}
	void getGlobalMethodBlend()
	{
		fprintf(mFile,"\"%s.gmb\"",mName.c_str());

	}
protected:
	PolyOptUvs(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYOPTUVS_H__
