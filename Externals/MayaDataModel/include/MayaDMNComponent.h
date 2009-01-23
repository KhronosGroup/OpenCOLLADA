/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NCOMPONENT_H__
#define __MayaDM_NCOMPONENT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class NComponent : public DependNode
{
public:
public:
	NComponent(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "nComponent"){}
	virtual ~NComponent(){}
	void setComponentGroupId(int cid)
	{
		if(cid == 0) return;
		fprintf(mFile,"setAttr \".cid\" %i;\n", cid);

	}
	void setComponentType(unsigned int ct)
	{
		if(ct == 0) return;
		fprintf(mFile,"setAttr \".ct\" %i;\n", ct);

	}
	void setElements(unsigned int el)
	{
		if(el == 0) return;
		fprintf(mFile,"setAttr \".el\" %i;\n", el);

	}
	void setStrength(double stn)
	{
		if(stn == 1.0) return;
		fprintf(mFile,"setAttr \".stn\" %f;\n", stn);

	}
	void setStrengthMap(float stnm)
	{
		if(stnm == 1.0) return;
		fprintf(mFile,"setAttr \".stnm\" %f;\n", stnm);

	}
	void setStrengthPerVertex(const doubleArray& spv)
	{
		if(spv.size == 0) return;
		fprintf(mFile,"setAttr \".spv\" -type \"doubleArray\" ");
		spv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGlueStrength(double gst)
	{
		if(gst == 1.0) return;
		fprintf(mFile,"setAttr \".gst\" %f;\n", gst);

	}
	void setGlueStrengthMap(float gstm)
	{
		if(gstm == 1.0) return;
		fprintf(mFile,"setAttr \".gstm\" %f;\n", gstm);

	}
	void setGlueStrengthPerVertex(const doubleArray& gspv)
	{
		if(gspv.size == 0) return;
		fprintf(mFile,"setAttr \".gspv\" -type \"doubleArray\" ");
		gspv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWeight(double wgh)
	{
		if(wgh == 1.0) return;
		fprintf(mFile,"setAttr \".wgh\" %f;\n", wgh);

	}
	void setWeightMap(float wemp)
	{
		if(wemp == 1.0) return;
		fprintf(mFile,"setAttr \".wemp\" %f;\n", wemp);

	}
	void setWeightPerVertex(const doubleArray& wpv)
	{
		if(wpv.size == 0) return;
		fprintf(mFile,"setAttr \".wpv\" -type \"doubleArray\" ");
		wpv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTangentStrength(double tst)
	{
		if(tst == 0.5) return;
		fprintf(mFile,"setAttr \".tst\" %f;\n", tst);

	}
	void setComponentIndices(size_t ci_i,int ci)
	{
		if(ci == 0) return;
		fprintf(mFile,"setAttr \".ci[%i]\" %i;\n", ci_i,ci);

	}
	void setComponentIndices(size_t ci_start,size_t ci_end,int* ci)
	{
		fprintf(mFile,"setAttr \".ci[%i:%i]\" ", ci_start,ci_end);
		size_t size = (ci_end-ci_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ci[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startComponentIndices(size_t ci_start,size_t ci_end)
	{
		fprintf(mFile,"setAttr \".ci[%i:%i]\"",ci_start,ci_end);

	}
	void appendComponentIndices(int ci)
	{
		fprintf(mFile," %i",ci);

	}
	void endComponentIndices()
	{
		fprintf(mFile,";\n");

	}
	void setStrengthMapType(unsigned int smt)
	{
		if(smt == 2) return;
		fprintf(mFile,"setAttr \".smt\" %i;\n", smt);

	}
	void setGlueStrengthMapType(unsigned int gsmt)
	{
		if(gsmt == 2) return;
		fprintf(mFile,"setAttr \".gsmt\" %i;\n", gsmt);

	}
	void setWeightMapType(unsigned int wmt)
	{
		if(wmt == 2) return;
		fprintf(mFile,"setAttr \".wmt\" %i;\n", wmt);

	}
	void getSurface()
	{
		fprintf(mFile,"\"%s.srf\"",mName.c_str());

	}
	void getComponentGroupId()
	{
		fprintf(mFile,"\"%s.cid\"",mName.c_str());

	}
	void getComponentType()
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());

	}
	void getElements()
	{
		fprintf(mFile,"\"%s.el\"",mName.c_str());

	}
	void getStrength()
	{
		fprintf(mFile,"\"%s.stn\"",mName.c_str());

	}
	void getStrengthMap()
	{
		fprintf(mFile,"\"%s.stnm\"",mName.c_str());

	}
	void getStrengthPerVertex()
	{
		fprintf(mFile,"\"%s.spv\"",mName.c_str());

	}
	void getGlueStrength()
	{
		fprintf(mFile,"\"%s.gst\"",mName.c_str());

	}
	void getGlueStrengthMap()
	{
		fprintf(mFile,"\"%s.gstm\"",mName.c_str());

	}
	void getGlueStrengthPerVertex()
	{
		fprintf(mFile,"\"%s.gspv\"",mName.c_str());

	}
	void getWeight()
	{
		fprintf(mFile,"\"%s.wgh\"",mName.c_str());

	}
	void getWeightMap()
	{
		fprintf(mFile,"\"%s.wemp\"",mName.c_str());

	}
	void getWeightPerVertex()
	{
		fprintf(mFile,"\"%s.wpv\"",mName.c_str());

	}
	void getTangentStrength()
	{
		fprintf(mFile,"\"%s.tst\"",mName.c_str());

	}
	void getObjectId()
	{
		fprintf(mFile,"\"%s.obid\"",mName.c_str());

	}
	void getComponentIndices(size_t ci_i)
	{
		fprintf(mFile,"\"%s.ci[%i]\"",mName.c_str(),ci_i);

	}
	void getOutComponent()
	{
		fprintf(mFile,"\"%s.ocp\"",mName.c_str());

	}
	void getStrengthMapType()
	{
		fprintf(mFile,"\"%s.smt\"",mName.c_str());

	}
	void getGlueStrengthMapType()
	{
		fprintf(mFile,"\"%s.gsmt\"",mName.c_str());

	}
	void getWeightMapType()
	{
		fprintf(mFile,"\"%s.wmt\"",mName.c_str());

	}
protected:
	NComponent(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_NCOMPONENT_H__
