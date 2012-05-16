/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REBUILDSURFACE_H__
#define __MayaDM_REBUILDSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseNurbsConversion.h"
namespace MayaDM
{
class RebuildSurface : public AbstractBaseNurbsConversion
{
public:
public:

	RebuildSurface():AbstractBaseNurbsConversion(){}
	RebuildSurface(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseNurbsConversion(file, name, parent, "rebuildSurface", shared, create){}
	virtual ~RebuildSurface(){}

	void setRebuildType(unsigned int rt)
	{
		if(rt == 0) return;
		fprintf(mFile,"\tsetAttr \".rt\" %i;\n", rt);
	}
	void setDirection(unsigned int dir)
	{
		if(dir == 2) return;
		fprintf(mFile,"\tsetAttr \".dir\" %i;\n", dir);
	}
	void setSpansU(int su)
	{
		if(su == 4) return;
		fprintf(mFile,"\tsetAttr \".su\" %i;\n", su);
	}
	void setSpansV(int sv)
	{
		if(sv == 4) return;
		fprintf(mFile,"\tsetAttr \".sv\" %i;\n", sv);
	}
	void setDegreeU(unsigned int du)
	{
		if(du == 3) return;
		fprintf(mFile,"\tsetAttr \".du\" %i;\n", du);
	}
	void setDegreeV(unsigned int dv)
	{
		if(dv == 3) return;
		fprintf(mFile,"\tsetAttr \".dv\" %i;\n", dv);
	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void setEndKnots(unsigned int end)
	{
		if(end == 0) return;
		fprintf(mFile,"\tsetAttr \".end\" %i;\n", end);
	}
	void setKeepCorners(bool kc)
	{
		if(kc == true) return;
		fprintf(mFile,"\tsetAttr \".kc\" %i;\n", kc);
	}
	void setKeepRange(unsigned int kr)
	{
		if(kr == 1) return;
		fprintf(mFile,"\tsetAttr \".kr\" %i;\n", kr);
	}
	void setKeepControlPoints(bool kcp)
	{
		if(kcp == false) return;
		fprintf(mFile,"\tsetAttr \".kcp\" %i;\n", kcp);
	}
	void setFitRebuild(unsigned int fr)
	{
		if(fr == 0) return;
		fprintf(mFile,"\tsetAttr \".fr\" %i;\n", fr);
	}
	void setOldRebuildRational(bool orr)
	{
		if(orr == false) return;
		fprintf(mFile,"\tsetAttr \".orr\" %i;\n", orr);
	}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getMatchSurface()const
	{
		fprintf(mFile,"\"%s.ms\"",mName.c_str());
	}
	void getRebuildType()const
	{
		fprintf(mFile,"\"%s.rt\"",mName.c_str());
	}
	void getDirection()const
	{
		fprintf(mFile,"\"%s.dir\"",mName.c_str());
	}
	void getSpansU()const
	{
		fprintf(mFile,"\"%s.su\"",mName.c_str());
	}
	void getSpansV()const
	{
		fprintf(mFile,"\"%s.sv\"",mName.c_str());
	}
	void getDegreeU()const
	{
		fprintf(mFile,"\"%s.du\"",mName.c_str());
	}
	void getDegreeV()const
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getEndKnots()const
	{
		fprintf(mFile,"\"%s.end\"",mName.c_str());
	}
	void getKeepCorners()const
	{
		fprintf(mFile,"\"%s.kc\"",mName.c_str());
	}
	void getKeepRange()const
	{
		fprintf(mFile,"\"%s.kr\"",mName.c_str());
	}
	void getKeepControlPoints()const
	{
		fprintf(mFile,"\"%s.kcp\"",mName.c_str());
	}
	void getFitRebuild()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
	void getOldRebuildRational()const
	{
		fprintf(mFile,"\"%s.orr\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
protected:
	RebuildSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseNurbsConversion(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_REBUILDSURFACE_H__
