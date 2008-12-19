/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REVOLVE_H__
#define __MayaDM_REVOLVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class Revolve : public AbstractBaseCreate
{
public:
public:
	Revolve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "revolve"){}
	virtual ~Revolve(){}
	void setStartSweep(double ssw)
	{
		if(ssw == 0) return;
		fprintf(mFile,"setAttr \".ssw\" %f;\n", ssw);

	}
	void setEndSweep(double esw)
	{
		if(esw == 6.2831853) return;
		fprintf(mFile,"setAttr \".esw\" %f;\n", esw);

	}
	void setUseTolerance(bool ut)
	{
		if(ut == false) return;
		fprintf(mFile,"setAttr \".ut\" %i;\n", ut);

	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setSections(int s)
	{
		if(s == 8) return;
		fprintf(mFile,"setAttr \".s\" %i;\n", s);

	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void setAxis(const double3& ax)
	{
		fprintf(mFile,"setAttr \".ax\" -type \"double3\" ");
		ax.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAxisX(double axx)
	{
		if(axx == 1) return;
		fprintf(mFile,"setAttr \".ax.axx\" %f;\n", axx);

	}
	void setAxisY(double axy)
	{
		if(axy == 0) return;
		fprintf(mFile,"setAttr \".ax.axy\" %f;\n", axy);

	}
	void setAxisZ(double axz)
	{
		if(axz == 0) return;
		fprintf(mFile,"setAttr \".ax.axz\" %f;\n", axz);

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
	void setAutoCorrectNormal(bool acn)
	{
		if(acn == false) return;
		fprintf(mFile,"setAttr \".acn\" %i;\n", acn);

	}
	void setComputePivotAndAxis(unsigned int cpa)
	{
		if(cpa == 0) return;
		fprintf(mFile,"setAttr \".cpa\" %i;\n", cpa);

	}
	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setRadiusAnchor(double ra)
	{
		if(ra == -1) return;
		fprintf(mFile,"setAttr \".ra\" %f;\n", ra);

	}
	void setAxisChoice(unsigned int aco)
	{
		if(aco == 0) return;
		fprintf(mFile,"setAttr \".aco\" %i;\n", aco);

	}
	void setBridge(bool br)
	{
		if(br == false) return;
		fprintf(mFile,"setAttr \".br\" %i;\n", br);

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getStartSweep()
	{
		fprintf(mFile,"\"%s.ssw\"",mName.c_str());

	}
	void getEndSweep()
	{
		fprintf(mFile,"\"%s.esw\"",mName.c_str());

	}
	void getUseTolerance()
	{
		fprintf(mFile,"\"%s.ut\"",mName.c_str());

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getSections()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getAxis()
	{
		fprintf(mFile,"\"%s.ax\"",mName.c_str());

	}
	void getAxisX()
	{
		fprintf(mFile,"\"%s.ax.axx\"",mName.c_str());

	}
	void getAxisY()
	{
		fprintf(mFile,"\"%s.ax.axy\"",mName.c_str());

	}
	void getAxisZ()
	{
		fprintf(mFile,"\"%s.ax.axz\"",mName.c_str());

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
	void getAutoCorrectNormal()
	{
		fprintf(mFile,"\"%s.acn\"",mName.c_str());

	}
	void getComputePivotAndAxis()
	{
		fprintf(mFile,"\"%s.cpa\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getRadiusAnchor()
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());

	}
	void getAxisChoice()
	{
		fprintf(mFile,"\"%s.aco\"",mName.c_str());

	}
	void getBridge()
	{
		fprintf(mFile,"\"%s.br\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getBridgeCurve()
	{
		fprintf(mFile,"\"%s.bc\"",mName.c_str());

	}
	void getCompAxis()
	{
		fprintf(mFile,"\"%s.ca\"",mName.c_str());

	}
	void getCompAxisX()
	{
		fprintf(mFile,"\"%s.ca.cax\"",mName.c_str());

	}
	void getCompAxisY()
	{
		fprintf(mFile,"\"%s.ca.cay\"",mName.c_str());

	}
	void getCompAxisZ()
	{
		fprintf(mFile,"\"%s.ca.caz\"",mName.c_str());

	}
	void getCompPivot()
	{
		fprintf(mFile,"\"%s.cp\"",mName.c_str());

	}
	void getCompPivotX()
	{
		fprintf(mFile,"\"%s.cp.cpx\"",mName.c_str());

	}
	void getCompPivotY()
	{
		fprintf(mFile,"\"%s.cp.cpy\"",mName.c_str());

	}
	void getCompPivotZ()
	{
		fprintf(mFile,"\"%s.cp.cpz\"",mName.c_str());

	}
	void getCompAxisChoice()
	{
		fprintf(mFile,"\"%s.cac\"",mName.c_str());

	}
	void getCompAnchor()
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());

	}
	void getCompAnchorX()
	{
		fprintf(mFile,"\"%s.cn.cnx\"",mName.c_str());

	}
	void getCompAnchorY()
	{
		fprintf(mFile,"\"%s.cn.cny\"",mName.c_str());

	}
	void getCompAnchorZ()
	{
		fprintf(mFile,"\"%s.cn.cnz\"",mName.c_str());

	}
protected:
	Revolve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_REVOLVE_H__
