/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Extrude():AbstractBaseCreate(){}
	Extrude(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "extrude", shared, create){}
	virtual ~Extrude(){}

	void setExtrudeType(unsigned int et)
	{
		if(et == 2) return;
		fprintf(mFile,"\tsetAttr \".et\" %i;\n", et);
	}
	void setFixedPath(bool fpt)
	{
		if(fpt == false) return;
		fprintf(mFile,"\tsetAttr \".fpt\" %i;\n", fpt);
	}
	void setUseComponentPivot(unsigned int ucp)
	{
		if(ucp == 0) return;
		fprintf(mFile,"\tsetAttr \".ucp\" %i;\n", ucp);
	}
	void setUseProfileNormal(bool upn)
	{
		if(upn == false) return;
		fprintf(mFile,"\tsetAttr \".upn\" %i;\n", upn);
	}
	void setDirection(const double3& d)
	{
		fprintf(mFile,"\tsetAttr \".d\" -type \"double3\" ");
		d.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDirectionX(double dx)
	{
		if(dx == 0) return;
		fprintf(mFile,"\tsetAttr \".d.dx\" %f;\n", dx);
	}
	void setDirectionY(double dy)
	{
		if(dy == 1) return;
		fprintf(mFile,"\tsetAttr \".d.dy\" %f;\n", dy);
	}
	void setDirectionZ(double dz)
	{
		if(dz == 0) return;
		fprintf(mFile,"\tsetAttr \".d.dz\" %f;\n", dz);
	}
	void setLength(double l)
	{
		if(l == 1) return;
		fprintf(mFile,"\tsetAttr \".l\" %f;\n", l);
	}
	void setPivot(const double3& p)
	{
		fprintf(mFile,"\tsetAttr \".p\" -type \"double3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPivotX(double px)
	{
		if(px == 0) return;
		fprintf(mFile,"\tsetAttr \".p.px\" %f;\n", px);
	}
	void setPivotY(double py)
	{
		if(py == 0) return;
		fprintf(mFile,"\tsetAttr \".p.py\" %f;\n", py);
	}
	void setPivotZ(double pz)
	{
		if(pz == 0) return;
		fprintf(mFile,"\tsetAttr \".p.pz\" %f;\n", pz);
	}
	void setRotation(double ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"\tsetAttr \".ro\" %f;\n", ro);
	}
	void setScale(double sc)
	{
		if(sc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sc\" %f;\n", sc);
	}
	void setReverseSurfaceIfPathReversed(bool rsp)
	{
		if(rsp == false) return;
		fprintf(mFile,"\tsetAttr \".rsp\" %i;\n", rsp);
	}
	void setDegreeAlongLength(short dl)
	{
		if(dl == 1) return;
		fprintf(mFile,"\tsetAttr \".dl\" %i;\n", dl);
	}
	void setSubCurveSubSurface(bool scs)
	{
		if(scs == false) return;
		fprintf(mFile,"\tsetAttr \".scs\" %i;\n", scs);
	}
	void getProfile()const
	{
		fprintf(mFile,"\"%s.pr\"",mName.c_str());
	}
	void getPath()const
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());
	}
	void getExtrudeType()const
	{
		fprintf(mFile,"\"%s.et\"",mName.c_str());
	}
	void getFixedPath()const
	{
		fprintf(mFile,"\"%s.fpt\"",mName.c_str());
	}
	void getUseComponentPivot()const
	{
		fprintf(mFile,"\"%s.ucp\"",mName.c_str());
	}
	void getUseProfileNormal()const
	{
		fprintf(mFile,"\"%s.upn\"",mName.c_str());
	}
	void getDirection()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getDirectionX()const
	{
		fprintf(mFile,"\"%s.d.dx\"",mName.c_str());
	}
	void getDirectionY()const
	{
		fprintf(mFile,"\"%s.d.dy\"",mName.c_str());
	}
	void getDirectionZ()const
	{
		fprintf(mFile,"\"%s.d.dz\"",mName.c_str());
	}
	void getLength()const
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getPivot()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPivotX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPivotY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPivotZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getRotation()const
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getReverseSurfaceIfPathReversed()const
	{
		fprintf(mFile,"\"%s.rsp\"",mName.c_str());
	}
	void getDegreeAlongLength()const
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getSubCurveSubSurface()const
	{
		fprintf(mFile,"\"%s.scs\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
protected:
	Extrude(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_EXTRUDE_H__
