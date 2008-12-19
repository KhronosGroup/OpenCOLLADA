/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	RebuildSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseNurbsConversion(file, name, parent, "rebuildSurface"){}
	virtual ~RebuildSurface(){}
	void setRebuildType(unsigned int rt)
	{
		if(rt == 0) return;
		fprintf(mFile,"setAttr \".rt\" %i;\n", rt);

	}
	void setDirection(unsigned int dir)
	{
		if(dir == 2) return;
		fprintf(mFile,"setAttr \".dir\" %i;\n", dir);

	}
	void setSpansU(int su)
	{
		if(su == 4) return;
		fprintf(mFile,"setAttr \".su\" %i;\n", su);

	}
	void setSpansV(int sv)
	{
		if(sv == 4) return;
		fprintf(mFile,"setAttr \".sv\" %i;\n", sv);

	}
	void setDegreeU(unsigned int du)
	{
		if(du == 3) return;
		fprintf(mFile,"setAttr \".du\" %i;\n", du);

	}
	void setDegreeV(unsigned int dv)
	{
		if(dv == 3) return;
		fprintf(mFile,"setAttr \".dv\" %i;\n", dv);

	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void setEndKnots(unsigned int end)
	{
		if(end == 0) return;
		fprintf(mFile,"setAttr \".end\" %i;\n", end);

	}
	void setKeepCorners(bool kc)
	{
		if(kc == true) return;
		fprintf(mFile,"setAttr \".kc\" %i;\n", kc);

	}
	void setKeepRange(unsigned int kr)
	{
		if(kr == 1) return;
		fprintf(mFile,"setAttr \".kr\" %i;\n", kr);

	}
	void setKeepControlPoints(bool kcp)
	{
		if(kcp == false) return;
		fprintf(mFile,"setAttr \".kcp\" %i;\n", kcp);

	}
	void setFitRebuild(unsigned int fr)
	{
		if(fr == 0) return;
		fprintf(mFile,"setAttr \".fr\" %i;\n", fr);

	}
	void setOldRebuildRational(bool orr)
	{
		if(orr == false) return;
		fprintf(mFile,"setAttr \".orr\" %i;\n", orr);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getMatchSurface()
	{
		fprintf(mFile,"\"%s.ms\"",mName.c_str());

	}
	void getRebuildType()
	{
		fprintf(mFile,"\"%s.rt\"",mName.c_str());

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.dir\"",mName.c_str());

	}
	void getSpansU()
	{
		fprintf(mFile,"\"%s.su\"",mName.c_str());

	}
	void getSpansV()
	{
		fprintf(mFile,"\"%s.sv\"",mName.c_str());

	}
	void getDegreeU()
	{
		fprintf(mFile,"\"%s.du\"",mName.c_str());

	}
	void getDegreeV()
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getEndKnots()
	{
		fprintf(mFile,"\"%s.end\"",mName.c_str());

	}
	void getKeepCorners()
	{
		fprintf(mFile,"\"%s.kc\"",mName.c_str());

	}
	void getKeepRange()
	{
		fprintf(mFile,"\"%s.kr\"",mName.c_str());

	}
	void getKeepControlPoints()
	{
		fprintf(mFile,"\"%s.kcp\"",mName.c_str());

	}
	void getFitRebuild()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getOldRebuildRational()
	{
		fprintf(mFile,"\"%s.orr\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	RebuildSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseNurbsConversion(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_REBUILDSURFACE_H__
