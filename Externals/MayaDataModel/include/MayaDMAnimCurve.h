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
	void setKeyTanLocked(size_t ktl_start,size_t ktl_end,bool* ktl)
	{
		fprintf(mFile,"setAttr \".ktl[%i:%i]\" ", ktl_start,ktl_end);
		size_t size = (ktl_end-ktl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ktl[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyTanLocked(size_t ktl_start,size_t ktl_end)
	{
		fprintf(mFile,"setAttr \".ktl[%i:%i]\"",ktl_start,ktl_end);

	}
	void appendKeyTanLocked(bool ktl)
	{
		fprintf(mFile," %i",ktl);

	}
	void endKeyTanLocked()
	{
		fprintf(mFile,";\n");

	}
	void setKeyWeightLocked(size_t kwl_i,bool kwl)
	{
		if(kwl == true) return;
		fprintf(mFile,"setAttr \".kwl[%i]\" %i;\n", kwl_i,kwl);

	}
	void setKeyWeightLocked(size_t kwl_start,size_t kwl_end,bool* kwl)
	{
		fprintf(mFile,"setAttr \".kwl[%i:%i]\" ", kwl_start,kwl_end);
		size_t size = (kwl_end-kwl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kwl[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyWeightLocked(size_t kwl_start,size_t kwl_end)
	{
		fprintf(mFile,"setAttr \".kwl[%i:%i]\"",kwl_start,kwl_end);

	}
	void appendKeyWeightLocked(bool kwl)
	{
		fprintf(mFile," %i",kwl);

	}
	void endKeyWeightLocked()
	{
		fprintf(mFile,";\n");

	}
	void setKeyTanInX(size_t kix_i,double kix)
	{
		if(kix == 0.0) return;
		fprintf(mFile,"setAttr \".kix[%i]\" %f;\n", kix_i,kix);

	}
	void setKeyTanInX(size_t kix_start,size_t kix_end,double* kix)
	{
		fprintf(mFile,"setAttr \".kix[%i:%i]\" ", kix_start,kix_end);
		size_t size = (kix_end-kix_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",kix[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyTanInX(size_t kix_start,size_t kix_end)
	{
		fprintf(mFile,"setAttr \".kix[%i:%i]\"",kix_start,kix_end);

	}
	void appendKeyTanInX(double kix)
	{
		fprintf(mFile," %f",kix);

	}
	void endKeyTanInX()
	{
		fprintf(mFile,";\n");

	}
	void setKeyTanInY(size_t kiy_i,double kiy)
	{
		if(kiy == 0.0) return;
		fprintf(mFile,"setAttr \".kiy[%i]\" %f;\n", kiy_i,kiy);

	}
	void setKeyTanInY(size_t kiy_start,size_t kiy_end,double* kiy)
	{
		fprintf(mFile,"setAttr \".kiy[%i:%i]\" ", kiy_start,kiy_end);
		size_t size = (kiy_end-kiy_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",kiy[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyTanInY(size_t kiy_start,size_t kiy_end)
	{
		fprintf(mFile,"setAttr \".kiy[%i:%i]\"",kiy_start,kiy_end);

	}
	void appendKeyTanInY(double kiy)
	{
		fprintf(mFile," %f",kiy);

	}
	void endKeyTanInY()
	{
		fprintf(mFile,";\n");

	}
	void setKeyTanOutX(size_t kox_i,double kox)
	{
		if(kox == 0.0) return;
		fprintf(mFile,"setAttr \".kox[%i]\" %f;\n", kox_i,kox);

	}
	void setKeyTanOutX(size_t kox_start,size_t kox_end,double* kox)
	{
		fprintf(mFile,"setAttr \".kox[%i:%i]\" ", kox_start,kox_end);
		size_t size = (kox_end-kox_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",kox[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyTanOutX(size_t kox_start,size_t kox_end)
	{
		fprintf(mFile,"setAttr \".kox[%i:%i]\"",kox_start,kox_end);

	}
	void appendKeyTanOutX(double kox)
	{
		fprintf(mFile," %f",kox);

	}
	void endKeyTanOutX()
	{
		fprintf(mFile,";\n");

	}
	void setKeyTanOutY(size_t koy_i,double koy)
	{
		if(koy == 0.0) return;
		fprintf(mFile,"setAttr \".koy[%i]\" %f;\n", koy_i,koy);

	}
	void setKeyTanOutY(size_t koy_start,size_t koy_end,double* koy)
	{
		fprintf(mFile,"setAttr \".koy[%i:%i]\" ", koy_start,koy_end);
		size_t size = (koy_end-koy_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",koy[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyTanOutY(size_t koy_start,size_t koy_end)
	{
		fprintf(mFile,"setAttr \".koy[%i:%i]\"",koy_start,koy_end);

	}
	void appendKeyTanOutY(double koy)
	{
		fprintf(mFile," %f",koy);

	}
	void endKeyTanOutY()
	{
		fprintf(mFile,";\n");

	}
	void setKeyTanInType(size_t kit_i,unsigned int kit)
	{
		if(kit == 4) return;
		fprintf(mFile,"setAttr \".kit[%i]\" %i;\n", kit_i,kit);

	}
	void setKeyTanInType(size_t kit_start,size_t kit_end,unsigned int* kit)
	{
		fprintf(mFile,"setAttr \".kit[%i:%i]\" ", kit_start,kit_end);
		size_t size = (kit_end-kit_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kit[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyTanInType(size_t kit_start,size_t kit_end)
	{
		fprintf(mFile,"setAttr \".kit[%i:%i]\"",kit_start,kit_end);

	}
	void appendKeyTanInType(unsigned int kit)
	{
		fprintf(mFile," %i",kit);

	}
	void endKeyTanInType()
	{
		fprintf(mFile,";\n");

	}
	void setKeyTanOutType(size_t kot_i,unsigned int kot)
	{
		if(kot == 4) return;
		fprintf(mFile,"setAttr \".kot[%i]\" %i;\n", kot_i,kot);

	}
	void setKeyTanOutType(size_t kot_start,size_t kot_end,unsigned int* kot)
	{
		fprintf(mFile,"setAttr \".kot[%i:%i]\" ", kot_start,kot_end);
		size_t size = (kot_end-kot_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kot[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyTanOutType(size_t kot_start,size_t kot_end)
	{
		fprintf(mFile,"setAttr \".kot[%i:%i]\"",kot_start,kot_end);

	}
	void appendKeyTanOutType(unsigned int kot)
	{
		fprintf(mFile," %i",kot);

	}
	void endKeyTanOutType()
	{
		fprintf(mFile,";\n");

	}
	void setKeyBreakdown(size_t kbd_i,bool kbd)
	{
		if(kbd == false) return;
		fprintf(mFile,"setAttr \".kbd[%i]\" %i;\n", kbd_i,kbd);

	}
	void setKeyBreakdown(size_t kbd_start,size_t kbd_end,bool* kbd)
	{
		fprintf(mFile,"setAttr \".kbd[%i:%i]\" ", kbd_start,kbd_end);
		size_t size = (kbd_end-kbd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kbd[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyBreakdown(size_t kbd_start,size_t kbd_end)
	{
		fprintf(mFile,"setAttr \".kbd[%i:%i]\"",kbd_start,kbd_end);

	}
	void appendKeyBreakdown(bool kbd)
	{
		fprintf(mFile," %i",kbd);

	}
	void endKeyBreakdown()
	{
		fprintf(mFile,";\n");

	}
	void setKeyTickDrawSpecial(size_t kyts_i,bool kyts)
	{
		if(kyts == false) return;
		fprintf(mFile,"setAttr \".kyts[%i]\" %i;\n", kyts_i,kyts);

	}
	void setKeyTickDrawSpecial(size_t kyts_start,size_t kyts_end,bool* kyts)
	{
		fprintf(mFile,"setAttr \".kyts[%i:%i]\" ", kyts_start,kyts_end);
		size_t size = (kyts_end-kyts_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kyts[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeyTickDrawSpecial(size_t kyts_start,size_t kyts_end)
	{
		fprintf(mFile,"setAttr \".kyts[%i:%i]\"",kyts_start,kyts_end);

	}
	void appendKeyTickDrawSpecial(bool kyts)
	{
		fprintf(mFile," %i",kyts);

	}
	void endKeyTickDrawSpecial()
	{
		fprintf(mFile,";\n");

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
