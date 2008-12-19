/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSPLITRING_H__
#define __MayaDM_POLYSPLITRING_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolySplitRing : public PolyModifierWorld
{
public:
	struct ProfileCurve{
		float profileCurve_Position;
		float profileCurve_FloatValue;
		unsigned int profileCurve_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", profileCurve_Position);
			fprintf(file,"%f ", profileCurve_FloatValue);
			fprintf(file,"%i", profileCurve_Interp);
		}
	};
public:
	PolySplitRing(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polySplitRing"){}
	virtual ~PolySplitRing(){}
	void setWeight(float wt)
	{
		if(wt == 0.5) return;
		fprintf(mFile,"setAttr \".wt\" %f;\n", wt);

	}
	void setDirection(bool dr)
	{
		if(dr == true) return;
		fprintf(mFile,"setAttr \".dr\" %i;\n", dr);

	}
	void setRootEdge(int re)
	{
		if(re == -1) return;
		fprintf(mFile,"setAttr \".re\" %i;\n", re);

	}
	void setSmoothingAngle(double sma)
	{
		if(sma == 1) return;
		fprintf(mFile,"setAttr \".sma\" %f;\n", sma);

	}
	void setSplitType(unsigned int stp)
	{
		if(stp == 1) return;
		fprintf(mFile,"setAttr \".stp\" %i;\n", stp);

	}
	void setDivisions(int div)
	{
		if(div == 2) return;
		fprintf(mFile,"setAttr \".div\" %i;\n", div);

	}
	void setEnableProfileCurve(bool epc)
	{
		if(epc == true) return;
		fprintf(mFile,"setAttr \".epc\" %i;\n", epc);

	}
	void setProfileCurve(size_t p_i,const ProfileCurve& p)
	{
		fprintf(mFile,"setAttr \".p[%i]\" ",p_i);
		p.write(mFile);
		fprintf(mFile,";\n");

	}
	void setProfileCurve_Position(size_t p_i,float pp)
	{
		if(pp == 0.0) return;
		fprintf(mFile,"setAttr \".p[%i].pp\" %f;\n", p_i,pp);

	}
	void setProfileCurve_FloatValue(size_t p_i,float pfv)
	{
		if(pfv == 0.0) return;
		fprintf(mFile,"setAttr \".p[%i].pfv\" %f;\n", p_i,pfv);

	}
	void setProfileCurve_Interp(size_t p_i,unsigned int pi)
	{
		if(pi == 0) return;
		fprintf(mFile,"setAttr \".p[%i].pi\" %i;\n", p_i,pi);

	}
	void setProfileCurveInputOffset(float pio)
	{
		if(pio == 0.0f) return;
		fprintf(mFile,"setAttr \".pio\" %f;\n", pio);

	}
	void setProfileCurveInputScale(float pis)
	{
		if(pis == 1.0f) return;
		fprintf(mFile,"setAttr \".pis\" %f;\n", pis);

	}
	void setUseFaceNormalsAtEnds(bool fne)
	{
		if(fne == true) return;
		fprintf(mFile,"setAttr \".fne\" %i;\n", fne);

	}
	void setUseEqualMultiplier(bool uem)
	{
		if(uem == true) return;
		fprintf(mFile,"setAttr \".uem\" %i;\n", uem);

	}
	void setFixQuads(bool fq)
	{
		if(fq == false) return;
		fprintf(mFile,"setAttr \".fq\" %i;\n", fq);

	}
	void getWeight()
	{
		fprintf(mFile,"\"%s.wt\"",mName.c_str());

	}
	void getAbsoluteWeight()
	{
		fprintf(mFile,"\"%s.ab\"",mName.c_str());

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());

	}
	void getRootEdge()
	{
		fprintf(mFile,"\"%s.re\"",mName.c_str());

	}
	void getSmoothingAngle()
	{
		fprintf(mFile,"\"%s.sma\"",mName.c_str());

	}
	void getSplitType()
	{
		fprintf(mFile,"\"%s.stp\"",mName.c_str());

	}
	void getDivisions()
	{
		fprintf(mFile,"\"%s.div\"",mName.c_str());

	}
	void getEnableProfileCurve()
	{
		fprintf(mFile,"\"%s.epc\"",mName.c_str());

	}
	void getProfileCurve(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);

	}
	void getProfileCurve_Position(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].pp\"",mName.c_str(),p_i);

	}
	void getProfileCurve_FloatValue(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].pfv\"",mName.c_str(),p_i);

	}
	void getProfileCurve_Interp(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].pi\"",mName.c_str(),p_i);

	}
	void getProfileCurveInputOffset()
	{
		fprintf(mFile,"\"%s.pio\"",mName.c_str());

	}
	void getProfileCurveInputScale()
	{
		fprintf(mFile,"\"%s.pis\"",mName.c_str());

	}
	void getUseFaceNormalsAtEnds()
	{
		fprintf(mFile,"\"%s.fne\"",mName.c_str());

	}
	void getUseEqualMultiplier()
	{
		fprintf(mFile,"\"%s.uem\"",mName.c_str());

	}
	void getFixQuads()
	{
		fprintf(mFile,"\"%s.fq\"",mName.c_str());

	}
protected:
	PolySplitRing(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSPLITRING_H__
