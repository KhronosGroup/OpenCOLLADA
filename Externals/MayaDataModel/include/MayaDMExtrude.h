/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXTRUDE_H__
#define __MayaDM_EXTRUDE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class Extrude : public AbstractBaseCreate
{
public:
public:
	Extrude(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "extrude"){}
	virtual ~Extrude(){}
	void setExtrudeType(unsigned int et)
	{
		if(et == 2) return;
		fprintf(mFile,"setAttr \".et\" %i;\n", et);

	}
	void setFixedPath(bool fpt)
	{
		if(fpt == false) return;
		fprintf(mFile,"setAttr \".fpt\" %i;\n", fpt);

	}
	void setUseComponentPivot(unsigned int ucp)
	{
		if(ucp == 0) return;
		fprintf(mFile,"setAttr \".ucp\" %i;\n", ucp);

	}
	void setUseProfileNormal(bool upn)
	{
		if(upn == false) return;
		fprintf(mFile,"setAttr \".upn\" %i;\n", upn);

	}
	void setDirection(const double3& d)
	{
		fprintf(mFile,"setAttr \".d\" -type \"double3\" ");
		d.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDirectionX(double dx)
	{
		if(dx == 0) return;
		fprintf(mFile,"setAttr \".d.dx\" %f;\n", dx);

	}
	void setDirectionY(double dy)
	{
		if(dy == 1) return;
		fprintf(mFile,"setAttr \".d.dy\" %f;\n", dy);

	}
	void setDirectionZ(double dz)
	{
		if(dz == 0) return;
		fprintf(mFile,"setAttr \".d.dz\" %f;\n", dz);

	}
	void setLength(double l)
	{
		if(l == 1) return;
		fprintf(mFile,"setAttr \".l\" %f;\n", l);

	}
	void setPivot(const double3& p)
	{
		fprintf(mFile,"setAttr \".p\" -type \"double3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPivotX(double px)
	{
		if(px == 0) return;
		fprintf(mFile,"setAttr \".p.px\" %f;\n", px);

	}
	void setPivotY(double py)
	{
		if(py == 0) return;
		fprintf(mFile,"setAttr \".p.py\" %f;\n", py);

	}
	void setPivotZ(double pz)
	{
		if(pz == 0) return;
		fprintf(mFile,"setAttr \".p.pz\" %f;\n", pz);

	}
	void setRotation(double ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"setAttr \".ro\" %f;\n", ro);

	}
	void setScale(double sc)
	{
		if(sc == 1.0) return;
		fprintf(mFile,"setAttr \".sc\" %f;\n", sc);

	}
	void setReverseSurfaceIfPathReversed(bool rsp)
	{
		if(rsp == false) return;
		fprintf(mFile,"setAttr \".rsp\" %i;\n", rsp);

	}
	void setDegreeAlongLength(short dl)
	{
		if(dl == 1) return;
		fprintf(mFile,"setAttr \".dl\" %i;\n", dl);

	}
	void setSubCurveSubSurface(bool scs)
	{
		if(scs == false) return;
		fprintf(mFile,"setAttr \".scs\" %i;\n", scs);

	}
	void getProfile()
	{
		fprintf(mFile,"\"%s.pr\"",mName.c_str());

	}
	void getPath()
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());

	}
	void getExtrudeType()
	{
		fprintf(mFile,"\"%s.et\"",mName.c_str());

	}
	void getFixedPath()
	{
		fprintf(mFile,"\"%s.fpt\"",mName.c_str());

	}
	void getUseComponentPivot()
	{
		fprintf(mFile,"\"%s.ucp\"",mName.c_str());

	}
	void getUseProfileNormal()
	{
		fprintf(mFile,"\"%s.upn\"",mName.c_str());

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getDirectionX()
	{
		fprintf(mFile,"\"%s.d.dx\"",mName.c_str());

	}
	void getDirectionY()
	{
		fprintf(mFile,"\"%s.d.dy\"",mName.c_str());

	}
	void getDirectionZ()
	{
		fprintf(mFile,"\"%s.d.dz\"",mName.c_str());

	}
	void getLength()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getPivot()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getPivotX()
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());

	}
	void getPivotY()
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());

	}
	void getPivotZ()
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());

	}
	void getRotation()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getReverseSurfaceIfPathReversed()
	{
		fprintf(mFile,"\"%s.rsp\"",mName.c_str());

	}
	void getDegreeAlongLength()
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());

	}
	void getSubCurveSubSurface()
	{
		fprintf(mFile,"\"%s.scs\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	Extrude(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_EXTRUDE_H__
