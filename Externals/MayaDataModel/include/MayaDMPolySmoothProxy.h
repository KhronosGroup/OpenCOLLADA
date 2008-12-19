/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSMOOTHPROXY_H__
#define __MayaDM_POLYSMOOTHPROXY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolySmoothProxy : public PolyModifier
{
public:
public:
	PolySmoothProxy(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polySmoothProxy"){}
	virtual ~PolySmoothProxy(){}
	void setMethod(unsigned int mth)
	{
		if(mth == 0) return;
		fprintf(mFile,"setAttr \".mth\" %i;\n", mth);

	}
	void setExponentialLevel(short el)
	{
		if(el == 1) return;
		fprintf(mFile,"setAttr \".el\" %i;\n", el);

	}
	void setContinuity(float c)
	{
		if(c == 1) return;
		fprintf(mFile,"setAttr \".c\" %f;\n", c);

	}
	void setSmoothUVs(bool suv)
	{
		if(suv == false) return;
		fprintf(mFile,"setAttr \".suv\" %i;\n", suv);

	}
	void setKeepBorder(bool kb)
	{
		if(kb == true) return;
		fprintf(mFile,"setAttr \".kb\" %i;\n", kb);

	}
	void setKeepHardEdge(bool khe)
	{
		if(khe == false) return;
		fprintf(mFile,"setAttr \".khe\" %i;\n", khe);

	}
	void setPropagateEdgeHardness(bool peh)
	{
		if(peh == false) return;
		fprintf(mFile,"setAttr \".peh\" %i;\n", peh);

	}
	void setKeepMapBorders(unsigned int kmb)
	{
		if(kmb == 1) return;
		fprintf(mFile,"setAttr \".kmb\" %i;\n", kmb);

	}
	void setLinearLevel(short ll)
	{
		if(ll == 1) return;
		fprintf(mFile,"setAttr \".ll\" %i;\n", ll);

	}
	void setDivisionsPerEdge(int dpe)
	{
		if(dpe == 1) return;
		fprintf(mFile,"setAttr \".dpe\" %i;\n", dpe);

	}
	void setDegree(int deg)
	{
		if(deg == 3) return;
		fprintf(mFile,"setAttr \".deg\" %i;\n", deg);

	}
	void setPushStrength(float ps)
	{
		if(ps == 0.0) return;
		fprintf(mFile,"setAttr \".ps\" %f;\n", ps);

	}
	void setRoundness(float ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"setAttr \".ro\" %f;\n", ro);

	}
	void setMultiEdgeCrease(bool mec)
	{
		if(mec == true) return;
		fprintf(mFile,"setAttr \".mec\" %i;\n", mec);

	}
	void setMaya65Above(bool ma)
	{
		if(ma == false) return;
		fprintf(mFile,"setAttr \".ma\" %i;\n", ma);

	}
	void setMaya2008Above(bool mn)
	{
		if(mn == false) return;
		fprintf(mFile,"setAttr \".mn\" %i;\n", mn);

	}
	void getCachedSmoothMesh()
	{
		fprintf(mFile,"\"%s.csm\"",mName.c_str());

	}
	void getMethod()
	{
		fprintf(mFile,"\"%s.mth\"",mName.c_str());

	}
	void getExponentialLevel()
	{
		fprintf(mFile,"\"%s.el\"",mName.c_str());

	}
	void getContinuity()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getSmoothUVs()
	{
		fprintf(mFile,"\"%s.suv\"",mName.c_str());

	}
	void getKeepBorder()
	{
		fprintf(mFile,"\"%s.kb\"",mName.c_str());

	}
	void getKeepHardEdge()
	{
		fprintf(mFile,"\"%s.khe\"",mName.c_str());

	}
	void getPropagateEdgeHardness()
	{
		fprintf(mFile,"\"%s.peh\"",mName.c_str());

	}
	void getKeepMapBorders()
	{
		fprintf(mFile,"\"%s.kmb\"",mName.c_str());

	}
	void getLinearLevel()
	{
		fprintf(mFile,"\"%s.ll\"",mName.c_str());

	}
	void getDivisionsPerEdge()
	{
		fprintf(mFile,"\"%s.dpe\"",mName.c_str());

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.deg\"",mName.c_str());

	}
	void getPushStrength()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getRoundness()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getMultiEdgeCrease()
	{
		fprintf(mFile,"\"%s.mec\"",mName.c_str());

	}
	void getMaya65Above()
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());

	}
	void getMaya2008Above()
	{
		fprintf(mFile,"\"%s.mn\"",mName.c_str());

	}
protected:
	PolySmoothProxy(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSMOOTHPROXY_H__
