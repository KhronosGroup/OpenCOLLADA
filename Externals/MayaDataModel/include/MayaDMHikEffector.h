/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HIKEFFECTOR_H__
#define __MayaDM_HIKEFFECTOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class HikEffector : public Transform
{
public:
public:
	HikEffector():Transform(){}
	HikEffector(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "hikEffector"){}
	virtual ~HikEffector(){}
	void setPinning(unsigned int pin)
	{
		if(pin == 0) return;
		fprintf(mFile,"\tsetAttr \".pin\" %i;\n", pin);

	}
	void setEffectorID(int ei)
	{
		if(ei == 0) return;
		fprintf(mFile,"\tsetAttr \".ei\" %i;\n", ei);

	}
	void setPivotOffset(const double3& po)
	{
		fprintf(mFile,"\tsetAttr \".po\" -type \"double3\" ");
		po.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPivotOffsetX(double px)
	{
		if(px == 0) return;
		fprintf(mFile,"\tsetAttr \".po.px\" %f;\n", px);

	}
	void setPivotOffsetY(double py)
	{
		if(py == 0) return;
		fprintf(mFile,"\tsetAttr \".po.py\" %f;\n", py);

	}
	void setPivotOffsetZ(double pz)
	{
		if(pz == 0) return;
		fprintf(mFile,"\tsetAttr \".po.pz\" %f;\n", pz);

	}
	void setReachTranslation(double rt)
	{
		if(rt == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rt\" %f;\n", rt);

	}
	void setReachRotation(double rr)
	{
		if(rr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rr\" %f;\n", rr);

	}
	void setRadius(double radi)
	{
		if(radi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".radi\" %f;\n", radi);

	}
	void setAuxEffector(bool aeff)
	{
		if(aeff == false) return;
		fprintf(mFile,"\tsetAttr \".aeff\" %i;\n", aeff);

	}
	void setPreRotation(const double3& pr)
	{
		fprintf(mFile,"\tsetAttr \".pr\" -type \"double3\" ");
		pr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPreRotationX(double prx)
	{
		if(prx == 0) return;
		fprintf(mFile,"\tsetAttr \".pr.prx\" %f;\n", prx);

	}
	void setPreRotationY(double pry)
	{
		if(pry == 0) return;
		fprintf(mFile,"\tsetAttr \".pr.pry\" %f;\n", pry);

	}
	void setPreRotationZ(double prz)
	{
		if(prz == 0) return;
		fprintf(mFile,"\tsetAttr \".pr.prz\" %f;\n", prz);

	}
	void setColor(const float3& col)
	{
		fprintf(mFile,"\tsetAttr \".col\" -type \"float3\" ");
		col.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(float clr)
	{
		if(clr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".col.clr\" %f;\n", clr);

	}
	void setColorG(float clg)
	{
		if(clg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".col.clg\" %f;\n", clg);

	}
	void setColorB(float clb)
	{
		if(clb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".col.clb\" %f;\n", clb);

	}
	void setAlpha(float alp)
	{
		if(alp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".alp\" %f;\n", alp);

	}
	void setMarkerLook(unsigned int mkl)
	{
		if(mkl == 3) return;
		fprintf(mFile,"\tsetAttr \".mkl\" %i;\n", mkl);

	}
	void getJoint()
	{
		fprintf(mFile,"\"%s.jt\"",mName.c_str());

	}
	void getFkjoint()
	{
		fprintf(mFile,"\"%s.fj\"",mName.c_str());

	}
	void getPinning()
	{
		fprintf(mFile,"\"%s.pin\"",mName.c_str());

	}
	void getHandle(size_t ha_i)
	{
		fprintf(mFile,"\"%s.ha[%i]\"",mName.c_str(),ha_i);

	}
	void getEffectorID()
	{
		fprintf(mFile,"\"%s.ei\"",mName.c_str());

	}
	void getPivots(size_t pvt_i)
	{
		fprintf(mFile,"\"%s.pvt[%i]\"",mName.c_str(),pvt_i);

	}
	void getPivotOffset()
	{
		fprintf(mFile,"\"%s.po\"",mName.c_str());

	}
	void getPivotOffsetX()
	{
		fprintf(mFile,"\"%s.po.px\"",mName.c_str());

	}
	void getPivotOffsetY()
	{
		fprintf(mFile,"\"%s.po.py\"",mName.c_str());

	}
	void getPivotOffsetZ()
	{
		fprintf(mFile,"\"%s.po.pz\"",mName.c_str());

	}
	void getReachTranslation()
	{
		fprintf(mFile,"\"%s.rt\"",mName.c_str());

	}
	void getReachRotation()
	{
		fprintf(mFile,"\"%s.rr\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.radi\"",mName.c_str());

	}
	void getAuxEffector()
	{
		fprintf(mFile,"\"%s.aeff\"",mName.c_str());

	}
	void getPreRotation()
	{
		fprintf(mFile,"\"%s.pr\"",mName.c_str());

	}
	void getPreRotationX()
	{
		fprintf(mFile,"\"%s.pr.prx\"",mName.c_str());

	}
	void getPreRotationY()
	{
		fprintf(mFile,"\"%s.pr.pry\"",mName.c_str());

	}
	void getPreRotationZ()
	{
		fprintf(mFile,"\"%s.pr.prz\"",mName.c_str());

	}
	void getColor()
	{
		fprintf(mFile,"\"%s.col\"",mName.c_str());

	}
	void getColorR()
	{
		fprintf(mFile,"\"%s.col.clr\"",mName.c_str());

	}
	void getColorG()
	{
		fprintf(mFile,"\"%s.col.clg\"",mName.c_str());

	}
	void getColorB()
	{
		fprintf(mFile,"\"%s.col.clb\"",mName.c_str());

	}
	void getAlpha()
	{
		fprintf(mFile,"\"%s.alp\"",mName.c_str());

	}
	void getMarkerLook()
	{
		fprintf(mFile,"\"%s.mkl\"",mName.c_str());

	}
protected:
	HikEffector(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Transform(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HIKEFFECTOR_H__
