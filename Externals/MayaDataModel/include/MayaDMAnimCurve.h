/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	AnimCurve():DependNode(){}
	AnimCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "animCurve", shared, create){}
	virtual ~AnimCurve(){}

	void setTangentType(unsigned int tan)
	{
		if(tan == 4) return;
		fprintf(mFile,"\tsetAttr \".tan\" %i;\n", tan);
	}
	void setWeightedTangents(bool wgt)
	{
		if(wgt == true) return;
		fprintf(mFile,"\tsetAttr \".wgt\" %i;\n", wgt);
	}
	void setKeyTanLocked(size_t ktl_i,bool ktl)
	{
		if(ktl == true) return;
		fprintf(mFile,"\tsetAttr \".ktl[%i]\" %i;\n", ktl_i,ktl);
	}
	void setKeyTanLocked(size_t ktl_start,size_t ktl_end,bool* ktl)
	{
		fprintf(mFile,"\tsetAttr \".ktl[%i:%i]\" ", ktl_start,ktl_end);
		size_t size = (ktl_end-ktl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ktl[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyTanLocked(size_t ktl_start,size_t ktl_end)const
	{
		fprintf(mFile,"\tsetAttr \".ktl[%i:%i]\"",ktl_start,ktl_end);
	}
	void appendKeyTanLocked(bool ktl)const
	{
		fprintf(mFile," %i",ktl);
	}
	void endKeyTanLocked()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyWeightLocked(size_t kwl_i,bool kwl)
	{
		if(kwl == true) return;
		fprintf(mFile,"\tsetAttr \".kwl[%i]\" %i;\n", kwl_i,kwl);
	}
	void setKeyWeightLocked(size_t kwl_start,size_t kwl_end,bool* kwl)
	{
		fprintf(mFile,"\tsetAttr \".kwl[%i:%i]\" ", kwl_start,kwl_end);
		size_t size = (kwl_end-kwl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kwl[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyWeightLocked(size_t kwl_start,size_t kwl_end)const
	{
		fprintf(mFile,"\tsetAttr \".kwl[%i:%i]\"",kwl_start,kwl_end);
	}
	void appendKeyWeightLocked(bool kwl)const
	{
		fprintf(mFile," %i",kwl);
	}
	void endKeyWeightLocked()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyTanInX(size_t kix_i,double kix)
	{
		if(kix == 0.0) return;
		fprintf(mFile,"\tsetAttr \".kix[%i]\" %f;\n", kix_i,kix);
	}
	void setKeyTanInX(size_t kix_start,size_t kix_end,double* kix)
	{
		fprintf(mFile,"\tsetAttr \".kix[%i:%i]\" ", kix_start,kix_end);
		size_t size = (kix_end-kix_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",kix[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyTanInX(size_t kix_start,size_t kix_end)const
	{
		fprintf(mFile,"\tsetAttr \".kix[%i:%i]\"",kix_start,kix_end);
	}
	void appendKeyTanInX(double kix)const
	{
		fprintf(mFile," %f",kix);
	}
	void endKeyTanInX()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyTanInY(size_t kiy_i,double kiy)
	{
		if(kiy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".kiy[%i]\" %f;\n", kiy_i,kiy);
	}
	void setKeyTanInY(size_t kiy_start,size_t kiy_end,double* kiy)
	{
		fprintf(mFile,"\tsetAttr \".kiy[%i:%i]\" ", kiy_start,kiy_end);
		size_t size = (kiy_end-kiy_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",kiy[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyTanInY(size_t kiy_start,size_t kiy_end)const
	{
		fprintf(mFile,"\tsetAttr \".kiy[%i:%i]\"",kiy_start,kiy_end);
	}
	void appendKeyTanInY(double kiy)const
	{
		fprintf(mFile," %f",kiy);
	}
	void endKeyTanInY()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyTanOutX(size_t kox_i,double kox)
	{
		if(kox == 0.0) return;
		fprintf(mFile,"\tsetAttr \".kox[%i]\" %f;\n", kox_i,kox);
	}
	void setKeyTanOutX(size_t kox_start,size_t kox_end,double* kox)
	{
		fprintf(mFile,"\tsetAttr \".kox[%i:%i]\" ", kox_start,kox_end);
		size_t size = (kox_end-kox_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",kox[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyTanOutX(size_t kox_start,size_t kox_end)const
	{
		fprintf(mFile,"\tsetAttr \".kox[%i:%i]\"",kox_start,kox_end);
	}
	void appendKeyTanOutX(double kox)const
	{
		fprintf(mFile," %f",kox);
	}
	void endKeyTanOutX()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyTanOutY(size_t koy_i,double koy)
	{
		if(koy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".koy[%i]\" %f;\n", koy_i,koy);
	}
	void setKeyTanOutY(size_t koy_start,size_t koy_end,double* koy)
	{
		fprintf(mFile,"\tsetAttr \".koy[%i:%i]\" ", koy_start,koy_end);
		size_t size = (koy_end-koy_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",koy[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyTanOutY(size_t koy_start,size_t koy_end)const
	{
		fprintf(mFile,"\tsetAttr \".koy[%i:%i]\"",koy_start,koy_end);
	}
	void appendKeyTanOutY(double koy)const
	{
		fprintf(mFile," %f",koy);
	}
	void endKeyTanOutY()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyTanInType(size_t kit_i,unsigned int kit)
	{
		if(kit == 4) return;
		fprintf(mFile,"\tsetAttr \".kit[%i]\" %i;\n", kit_i,kit);
	}
	void setKeyTanInType(size_t kit_start,size_t kit_end,unsigned int* kit)
	{
		fprintf(mFile,"\tsetAttr \".kit[%i:%i]\" ", kit_start,kit_end);
		size_t size = (kit_end-kit_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kit[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyTanInType(size_t kit_start,size_t kit_end)const
	{
		fprintf(mFile,"\tsetAttr \".kit[%i:%i]\"",kit_start,kit_end);
	}
	void appendKeyTanInType(unsigned int kit)const
	{
		fprintf(mFile," %i",kit);
	}
	void endKeyTanInType()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyTanOutType(size_t kot_i,unsigned int kot)
	{
		if(kot == 4) return;
		fprintf(mFile,"\tsetAttr \".kot[%i]\" %i;\n", kot_i,kot);
	}
	void setKeyTanOutType(size_t kot_start,size_t kot_end,unsigned int* kot)
	{
		fprintf(mFile,"\tsetAttr \".kot[%i:%i]\" ", kot_start,kot_end);
		size_t size = (kot_end-kot_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kot[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyTanOutType(size_t kot_start,size_t kot_end)const
	{
		fprintf(mFile,"\tsetAttr \".kot[%i:%i]\"",kot_start,kot_end);
	}
	void appendKeyTanOutType(unsigned int kot)const
	{
		fprintf(mFile," %i",kot);
	}
	void endKeyTanOutType()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyBreakdown(size_t kbd_i,bool kbd)
	{
		if(kbd == false) return;
		fprintf(mFile,"\tsetAttr \".kbd[%i]\" %i;\n", kbd_i,kbd);
	}
	void setKeyBreakdown(size_t kbd_start,size_t kbd_end,bool* kbd)
	{
		fprintf(mFile,"\tsetAttr \".kbd[%i:%i]\" ", kbd_start,kbd_end);
		size_t size = (kbd_end-kbd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kbd[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyBreakdown(size_t kbd_start,size_t kbd_end)const
	{
		fprintf(mFile,"\tsetAttr \".kbd[%i:%i]\"",kbd_start,kbd_end);
	}
	void appendKeyBreakdown(bool kbd)const
	{
		fprintf(mFile," %i",kbd);
	}
	void endKeyBreakdown()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyTickDrawSpecial(size_t kyts_i,bool kyts)
	{
		if(kyts == false) return;
		fprintf(mFile,"\tsetAttr \".kyts[%i]\" %i;\n", kyts_i,kyts);
	}
	void setKeyTickDrawSpecial(size_t kyts_start,size_t kyts_end,bool* kyts)
	{
		fprintf(mFile,"\tsetAttr \".kyts[%i:%i]\" ", kyts_start,kyts_end);
		size_t size = (kyts_end-kyts_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",kyts[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeyTickDrawSpecial(size_t kyts_start,size_t kyts_end)const
	{
		fprintf(mFile,"\tsetAttr \".kyts[%i:%i]\"",kyts_start,kyts_end);
	}
	void appendKeyTickDrawSpecial(bool kyts)const
	{
		fprintf(mFile," %i",kyts);
	}
	void endKeyTickDrawSpecial()const
	{
		fprintf(mFile,";\n");
	}
	void setRotationInterpolation(unsigned int roti)
	{
		if(roti == 1) return;
		fprintf(mFile,"\tsetAttr \".roti\" %i;\n", roti);
	}
	void setPreInfinity(unsigned int pre)
	{
		if(pre == 0) return;
		fprintf(mFile,"\tsetAttr \".pre\" %i;\n", pre);
	}
	void setPostInfinity(unsigned int pst)
	{
		if(pst == 0) return;
		fprintf(mFile,"\tsetAttr \".pst\" %i;\n", pst);
	}
	void setStipplePattern(unsigned int sp)
	{
		if(sp == 6) return;
		fprintf(mFile,"\tsetAttr \".sp\" %i;\n", sp);
	}
	void setOutStippleThreshold(double ot)
	{
		if(ot == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ot\" %f;\n", ot);
	}
	void setOutStippleRange(const doubleArray& osr)
	{
		if(osr.size == 0) return;
		fprintf(mFile,"\tsetAttr \".osr\" -type \"doubleArray\" ");
		osr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInStippleRange(const doubleArray& isr)
	{
		if(isr.size == 0) return;
		fprintf(mFile,"\tsetAttr \".isr\" -type \"doubleArray\" ");
		isr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStippleReverse(bool sr)
	{
		if(sr == false) return;
		fprintf(mFile,"\tsetAttr \".sr\" %i;\n", sr);
	}
	void setUseCurveColor(bool ucc)
	{
		if(ucc == false) return;
		fprintf(mFile,"\tsetAttr \".ucc\" %i;\n", ucc);
	}
	void setCurveColor(const float3& cc)
	{
		fprintf(mFile,"\tsetAttr \".cc\" -type \"float3\" ");
		cc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCurveColorR(float ccr)
	{
		if(ccr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cc.ccr\" %f;\n", ccr);
	}
	void setCurveColorG(float ccg)
	{
		if(ccg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cc.ccg\" %f;\n", ccg);
	}
	void setCurveColorB(float ccb)
	{
		if(ccb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cc.ccb\" %f;\n", ccb);
	}
	void getApply()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getStipplePattern()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getOutStippleThreshold()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getOutStippleRange()const
	{
		fprintf(mFile,"\"%s.osr\"",mName.c_str());
	}
	void getInStippleRange()const
	{
		fprintf(mFile,"\"%s.isr\"",mName.c_str());
	}
	void getStippleReverse()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getUseCurveColor()const
	{
		fprintf(mFile,"\"%s.ucc\"",mName.c_str());
	}
	void getCurveColor()const
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());
	}
	void getCurveColorR()const
	{
		fprintf(mFile,"\"%s.cc.ccr\"",mName.c_str());
	}
	void getCurveColorG()const
	{
		fprintf(mFile,"\"%s.cc.ccg\"",mName.c_str());
	}
	void getCurveColorB()const
	{
		fprintf(mFile,"\"%s.cc.ccb\"",mName.c_str());
	}
protected:
	AnimCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCURVE_H__
