/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSMOOTHFACE_H__
#define __MayaDM_POLYSMOOTHFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolySmoothFace : public PolyModifier
{
public:
public:

	PolySmoothFace():PolyModifier(){}
	PolySmoothFace(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polySmoothFace", shared, create){}
	virtual ~PolySmoothFace(){}

	void setMethod(unsigned int mth)
	{
		if(mth == 0) return;
		fprintf(mFile,"\tsetAttr \".mth\" %i;\n", mth);
	}
	void setContinuity(float c)
	{
		if(c == 1) return;
		fprintf(mFile,"\tsetAttr \".c\" %f;\n", c);
	}
	void setDivisions(short dv)
	{
		if(dv == 1) return;
		fprintf(mFile,"\tsetAttr \".dv\" %i;\n", dv);
	}
	void setSmoothUVs(bool suv)
	{
		if(suv == false) return;
		fprintf(mFile,"\tsetAttr \".suv\" %i;\n", suv);
	}
	void setKeepBorder(bool kb)
	{
		if(kb == true) return;
		fprintf(mFile,"\tsetAttr \".kb\" %i;\n", kb);
	}
	void setKeepSelectionBorder(bool ksb)
	{
		if(ksb == true) return;
		fprintf(mFile,"\tsetAttr \".ksb\" %i;\n", ksb);
	}
	void setKeepHardEdge(bool khe)
	{
		if(khe == false) return;
		fprintf(mFile,"\tsetAttr \".khe\" %i;\n", khe);
	}
	void setPropagateEdgeHardness(bool peh)
	{
		if(peh == false) return;
		fprintf(mFile,"\tsetAttr \".peh\" %i;\n", peh);
	}
	void setKeepMapBorders(unsigned int kmb)
	{
		if(kmb == 1) return;
		fprintf(mFile,"\tsetAttr \".kmb\" %i;\n", kmb);
	}
	void setKeepTessellation(bool kt)
	{
		if(kt == true) return;
		fprintf(mFile,"\tsetAttr \".kt\" %i;\n", kt);
	}
	void setSubdivisionLevels(int sl)
	{
		if(sl == 1) return;
		fprintf(mFile,"\tsetAttr \".sl\" %i;\n", sl);
	}
	void setDivisionsPerEdge(int dpe)
	{
		if(dpe == 1) return;
		fprintf(mFile,"\tsetAttr \".dpe\" %i;\n", dpe);
	}
	void setDegree(int deg)
	{
		if(deg == 3) return;
		fprintf(mFile,"\tsetAttr \".deg\" %i;\n", deg);
	}
	void setPushStrength(float ps)
	{
		if(ps == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ps\" %f;\n", ps);
	}
	void setRoundness(float ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"\tsetAttr \".ro\" %f;\n", ro);
	}
	void setMaya65Above(bool ma)
	{
		if(ma == false) return;
		fprintf(mFile,"\tsetAttr \".ma\" %i;\n", ma);
	}
	void setMaya2008Above(bool m08)
	{
		if(m08 == false) return;
		fprintf(mFile,"\tsetAttr \".m08\" %i;\n", m08);
	}
	void getMethod()const
	{
		fprintf(mFile,"\"%s.mth\"",mName.c_str());
	}
	void getContinuity()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getDivisions()const
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());
	}
	void getSmoothUVs()const
	{
		fprintf(mFile,"\"%s.suv\"",mName.c_str());
	}
	void getKeepBorder()const
	{
		fprintf(mFile,"\"%s.kb\"",mName.c_str());
	}
	void getKeepSelectionBorder()const
	{
		fprintf(mFile,"\"%s.ksb\"",mName.c_str());
	}
	void getKeepHardEdge()const
	{
		fprintf(mFile,"\"%s.khe\"",mName.c_str());
	}
	void getPropagateEdgeHardness()const
	{
		fprintf(mFile,"\"%s.peh\"",mName.c_str());
	}
	void getKeepMapBorders()const
	{
		fprintf(mFile,"\"%s.kmb\"",mName.c_str());
	}
	void getKeepTessellation()const
	{
		fprintf(mFile,"\"%s.kt\"",mName.c_str());
	}
	void getSubdivisionLevels()const
	{
		fprintf(mFile,"\"%s.sl\"",mName.c_str());
	}
	void getDivisionsPerEdge()const
	{
		fprintf(mFile,"\"%s.dpe\"",mName.c_str());
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.deg\"",mName.c_str());
	}
	void getPushStrength()const
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());
	}
	void getRoundness()const
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());
	}
	void getMaya65Above()const
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());
	}
	void getMaya2008Above()const
	{
		fprintf(mFile,"\"%s.m08\"",mName.c_str());
	}
protected:
	PolySmoothFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSMOOTHFACE_H__
