/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMCURVE_H__
#define __MayaDM_ANIMCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class AnimCurve : public DependNode
{
public:
public:
	AnimCurve(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "animCurve"){}
	virtual ~AnimCurve(){}
	void setTangentType(unsigned int tan)
	{
		if(tan == 4) return;
		fprintf(mFile,"setAttr \".tan\" %i;\n", tan);

	}
	void setWeightedTangents(bool wgt)
	{
		if(wgt == true) return;
		fprintf(mFile,"setAttr \".wgt\" %i;\n", wgt);

	}
	void setKeyTanLocked(size_t ktl_i,bool ktl)
	{
		if(ktl == true) return;
		fprintf(mFile,"setAttr \".ktl[%i]\" %i;\n", ktl_i,ktl);

	}
	void setKeyWeightLocked(size_t kwl_i,bool kwl)
	{
		if(kwl == true) return;
		fprintf(mFile,"setAttr \".kwl[%i]\" %i;\n", kwl_i,kwl);

	}
	void setKeyTanInX(size_t kix_i,double kix)
	{
		if(kix == 0.0) return;
		fprintf(mFile,"setAttr \".kix[%i]\" %f;\n", kix_i,kix);

	}
	void setKeyTanInY(size_t kiy_i,double kiy)
	{
		if(kiy == 0.0) return;
		fprintf(mFile,"setAttr \".kiy[%i]\" %f;\n", kiy_i,kiy);

	}
	void setKeyTanOutX(size_t kox_i,double kox)
	{
		if(kox == 0.0) return;
		fprintf(mFile,"setAttr \".kox[%i]\" %f;\n", kox_i,kox);

	}
	void setKeyTanOutY(size_t koy_i,double koy)
	{
		if(koy == 0.0) return;
		fprintf(mFile,"setAttr \".koy[%i]\" %f;\n", koy_i,koy);

	}
	void setKeyTanInType(size_t kit_i,unsigned int kit)
	{
		if(kit == 4) return;
		fprintf(mFile,"setAttr \".kit[%i]\" %i;\n", kit_i,kit);

	}
	void setKeyTanOutType(size_t kot_i,unsigned int kot)
	{
		if(kot == 4) return;
		fprintf(mFile,"setAttr \".kot[%i]\" %i;\n", kot_i,kot);

	}
	void setKeyBreakdown(size_t kbd_i,bool kbd)
	{
		if(kbd == false) return;
		fprintf(mFile,"setAttr \".kbd[%i]\" %i;\n", kbd_i,kbd);

	}
	void setKeyTickDrawSpecial(size_t kyts_i,bool kyts)
	{
		if(kyts == false) return;
		fprintf(mFile,"setAttr \".kyts[%i]\" %i;\n", kyts_i,kyts);

	}
	void setRotationInterpolation(unsigned int roti)
	{
		if(roti == 1) return;
		fprintf(mFile,"setAttr \".roti\" %i;\n", roti);

	}
	void setPreInfinity(unsigned int pre)
	{
		if(pre == 0) return;
		fprintf(mFile,"setAttr \".pre\" %i;\n", pre);

	}
	void setPostInfinity(unsigned int pst)
	{
		if(pst == 0) return;
		fprintf(mFile,"setAttr \".pst\" %i;\n", pst);

	}
	void setStipplePattern(unsigned int sp)
	{
		if(sp == 6) return;
		fprintf(mFile,"setAttr \".sp\" %i;\n", sp);

	}
	void setOutStippleThreshold(double ot)
	{
		if(ot == 0.0) return;
		fprintf(mFile,"setAttr \".ot\" %f;\n", ot);

	}
	void setOutStippleRange(const doubleArray& osr)
	{
		if(osr.size == 0) return;
		fprintf(mFile,"setAttr \".osr\" -type \"doubleArray\" ");
		osr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInStippleRange(const doubleArray& isr)
	{
		if(isr.size == 0) return;
		fprintf(mFile,"setAttr \".isr\" -type \"doubleArray\" ");
		isr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStippleReverse(bool sr)
	{
		if(sr == false) return;
		fprintf(mFile,"setAttr \".sr\" %i;\n", sr);

	}
	void setUseCurveColor(bool ucc)
	{
		if(ucc == false) return;
		fprintf(mFile,"setAttr \".ucc\" %i;\n", ucc);

	}
	void setCurveColor(const float3& cc)
	{
		fprintf(mFile,"setAttr \".cc\" -type \"float3\" ");
		cc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCurveColorR(float ccr)
	{
		if(ccr == 0.0) return;
		fprintf(mFile,"setAttr \".cc.ccr\" %f;\n", ccr);

	}
	void setCurveColorG(float ccg)
	{
		if(ccg == 0.0) return;
		fprintf(mFile,"setAttr \".cc.ccg\" %f;\n", ccg);

	}
	void setCurveColorB(float ccb)
	{
		if(ccb == 0.0) return;
		fprintf(mFile,"setAttr \".cc.ccb\" %f;\n", ccb);

	}
	void getApply()
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());

	}
	void getStipplePattern()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getOutStippleThreshold()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getOutStippleRange()
	{
		fprintf(mFile,"\"%s.osr\"",mName.c_str());

	}
	void getInStippleRange()
	{
		fprintf(mFile,"\"%s.isr\"",mName.c_str());

	}
	void getStippleReverse()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getUseCurveColor()
	{
		fprintf(mFile,"\"%s.ucc\"",mName.c_str());

	}
	void getCurveColor()
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());

	}
	void getCurveColorR()
	{
		fprintf(mFile,"\"%s.cc.ccr\"",mName.c_str());

	}
	void getCurveColorG()
	{
		fprintf(mFile,"\"%s.cc.ccg\"",mName.c_str());

	}
	void getCurveColorB()
	{
		fprintf(mFile,"\"%s.cc.ccb\"",mName.c_str());

	}
protected:
	AnimCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCURVE_H__
