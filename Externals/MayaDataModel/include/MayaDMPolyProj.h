/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPROJ_H__
#define __MayaDM_POLYPROJ_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyProj : public PolyModifierWorld
{
public:
public:
	PolyProj(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyProj"){}
	virtual ~PolyProj(){}
	void setProjType(short t)
	{
		if(t == 1) return;
		fprintf(mFile,"setAttr \".t\" %i;\n", t);

	}
	void setWorldInverseMatrix(const matrix& wim)
	{
		if(wim == identity) return;
		fprintf(mFile,"setAttr \".wim\" -type \"matrix\" ");
		wim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setProjectionCenter(const double3& pc)
	{
		if(pc == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"setAttr \".pc\" -type \"double3\" ");
		pc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setProjectionCenterX(double pcx)
	{
		if(pcx == 0) return;
		fprintf(mFile,"setAttr \".pc.pcx\" %f;\n", pcx);

	}
	void setProjectionCenterY(double pcy)
	{
		if(pcy == 0) return;
		fprintf(mFile,"setAttr \".pc.pcy\" %f;\n", pcy);

	}
	void setProjectionCenterZ(double pcz)
	{
		if(pcz == 0) return;
		fprintf(mFile,"setAttr \".pc.pcz\" %f;\n", pcz);

	}
	void setImageCenter(const double2& ic)
	{
		if(ic == double2(0.5, 0.5)) return;
		fprintf(mFile,"setAttr \".ic\" -type \"double2\" ");
		ic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImageCenterX(double icx)
	{
		if(icx == 0) return;
		fprintf(mFile,"setAttr \".ic.icx\" %f;\n", icx);

	}
	void setImageCenterY(double icy)
	{
		if(icy == 0) return;
		fprintf(mFile,"setAttr \".ic.icy\" %f;\n", icy);

	}
	void setRotate(const double3& ro)
	{
		if(ro == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"setAttr \".ro\" -type \"double3\" ");
		ro.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRotateX(double rx)
	{
		if(rx == 0) return;
		fprintf(mFile,"setAttr \".ro.rx\" %f;\n", rx);

	}
	void setRotateY(double ry)
	{
		if(ry == 0) return;
		fprintf(mFile,"setAttr \".ro.ry\" %f;\n", ry);

	}
	void setRotateZ(double rz)
	{
		if(rz == 0) return;
		fprintf(mFile,"setAttr \".ro.rz\" %f;\n", rz);

	}
	void setProjectionScale(const double2& ps)
	{
		if(ps == double2(180.0, 1.0)) return;
		fprintf(mFile,"setAttr \".ps\" -type \"double2\" ");
		ps.write(mFile);
		fprintf(mFile,";\n");

	}
	void setProjectionScaleU(double psu)
	{
		if(psu == 0) return;
		fprintf(mFile,"setAttr \".ps.psu\" %f;\n", psu);

	}
	void setProjectionScaleV(double psv)
	{
		if(psv == 0) return;
		fprintf(mFile,"setAttr \".ps.psv\" %f;\n", psv);

	}
	void setImageScale(const double2& is)
	{
		if(is == double2(1.0, 1.0)) return;
		fprintf(mFile,"setAttr \".is\" -type \"double2\" ");
		is.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImageScaleU(double isu)
	{
		if(isu == 0) return;
		fprintf(mFile,"setAttr \".is.isu\" %f;\n", isu);

	}
	void setImageScaleV(double isv)
	{
		if(isv == 0) return;
		fprintf(mFile,"setAttr \".is.isv\" %f;\n", isv);

	}
	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setRotationAngle(double ra)
	{
		if(ra == 0) return;
		fprintf(mFile,"setAttr \".ra\" %f;\n", ra);

	}
	void getProjType()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getWorldInverseMatrix()
	{
		fprintf(mFile,"\"%s.wim\"",mName.c_str());

	}
	void getProjectionCenter()
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());

	}
	void getProjectionCenterX()
	{
		fprintf(mFile,"\"%s.pc.pcx\"",mName.c_str());

	}
	void getProjectionCenterY()
	{
		fprintf(mFile,"\"%s.pc.pcy\"",mName.c_str());

	}
	void getProjectionCenterZ()
	{
		fprintf(mFile,"\"%s.pc.pcz\"",mName.c_str());

	}
	void getImageCenter()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getImageCenterX()
	{
		fprintf(mFile,"\"%s.ic.icx\"",mName.c_str());

	}
	void getImageCenterY()
	{
		fprintf(mFile,"\"%s.ic.icy\"",mName.c_str());

	}
	void getRotate()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getRotateX()
	{
		fprintf(mFile,"\"%s.ro.rx\"",mName.c_str());

	}
	void getRotateY()
	{
		fprintf(mFile,"\"%s.ro.ry\"",mName.c_str());

	}
	void getRotateZ()
	{
		fprintf(mFile,"\"%s.ro.rz\"",mName.c_str());

	}
	void getProjectionScale()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getProjectionScaleU()
	{
		fprintf(mFile,"\"%s.ps.psu\"",mName.c_str());

	}
	void getProjectionScaleV()
	{
		fprintf(mFile,"\"%s.ps.psv\"",mName.c_str());

	}
	void getImageScale()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getImageScaleU()
	{
		fprintf(mFile,"\"%s.is.isu\"",mName.c_str());

	}
	void getImageScaleV()
	{
		fprintf(mFile,"\"%s.is.isv\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getRotationAngle()
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());

	}
protected:
	PolyProj(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPROJ_H__
