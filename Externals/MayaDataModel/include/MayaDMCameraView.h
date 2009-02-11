/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CAMERAVIEW_H__
#define __MayaDM_CAMERAVIEW_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class CameraView : public DependNode
{
public:
public:
	CameraView():DependNode(){}
	CameraView(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "cameraView"){}
	virtual ~CameraView(){}
	void setEye(const double3& e)
	{
		if(e == double3(60.0, 45.0, 60.0)) return;
		fprintf(mFile,"\tsetAttr \".e\" -type \"double3\" ");
		e.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEyeX(double ex)
	{
		if(ex == 0) return;
		fprintf(mFile,"\tsetAttr \".e.ex\" %f;\n", ex);

	}
	void setEyeY(double ey)
	{
		if(ey == 0) return;
		fprintf(mFile,"\tsetAttr \".e.ey\" %f;\n", ey);

	}
	void setEyeZ(double ez)
	{
		if(ez == 0) return;
		fprintf(mFile,"\tsetAttr \".e.ez\" %f;\n", ez);

	}
	void setCenterOfInterest(const double3& coi)
	{
		if(coi == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".coi\" -type \"double3\" ");
		coi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCenterOfInterestX(double cx)
	{
		if(cx == 0) return;
		fprintf(mFile,"\tsetAttr \".coi.cx\" %f;\n", cx);

	}
	void setCenterOfInterestY(double cy)
	{
		if(cy == 0) return;
		fprintf(mFile,"\tsetAttr \".coi.cy\" %f;\n", cy);

	}
	void setCenterOfInterestZ(double cz)
	{
		if(cz == 0) return;
		fprintf(mFile,"\tsetAttr \".coi.cz\" %f;\n", cz);

	}
	void setUp(const double3& u)
	{
		if(u == double3(0.0, 1.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".u\" -type \"double3\" ");
		u.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUpX(double ux)
	{
		if(ux == 0) return;
		fprintf(mFile,"\tsetAttr \".u.ux\" %f;\n", ux);

	}
	void setUpY(double uy)
	{
		if(uy == 0) return;
		fprintf(mFile,"\tsetAttr \".u.uy\" %f;\n", uy);

	}
	void setUpZ(double uz)
	{
		if(uz == 0) return;
		fprintf(mFile,"\tsetAttr \".u.uz\" %f;\n", uz);

	}
	void setTumblePivot(const double3& tp)
	{
		if(tp == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".tp\" -type \"double3\" ");
		tp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTumblePivotX(double tpx)
	{
		if(tpx == 0) return;
		fprintf(mFile,"\tsetAttr \".tp.tpx\" %f;\n", tpx);

	}
	void setTumblePivotY(double tpy)
	{
		if(tpy == 0) return;
		fprintf(mFile,"\tsetAttr \".tp.tpy\" %f;\n", tpy);

	}
	void setTumblePivotZ(double tpz)
	{
		if(tpz == 0) return;
		fprintf(mFile,"\tsetAttr \".tp.tpz\" %f;\n", tpz);

	}
	void setHorizontalAperture(double ha)
	{
		if(ha == 3) return;
		fprintf(mFile,"\tsetAttr \".ha\" %f;\n", ha);

	}
	void setVerticalAperture(double va)
	{
		if(va == 2) return;
		fprintf(mFile,"\tsetAttr \".va\" %f;\n", va);

	}
	void setFocalLength(double fl)
	{
		if(fl == 35.0) return;
		fprintf(mFile,"\tsetAttr \".fl\" %f;\n", fl);

	}
	void setOrthographicWidth(double ow)
	{
		if(ow == 1) return;
		fprintf(mFile,"\tsetAttr \".ow\" %f;\n", ow);

	}
	void setOrthographic(bool o)
	{
		if(o == false) return;
		fprintf(mFile,"\tsetAttr \".o\" %i;\n", o);

	}
	void setDescription(const string& d)
	{
		if(d == "NULL") return;
		fprintf(mFile,"\tsetAttr \".d\" -type \"string\" ");
		d.write(mFile);
		fprintf(mFile,";\n");

	}
	void getEye()
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());

	}
	void getEyeX()
	{
		fprintf(mFile,"\"%s.e.ex\"",mName.c_str());

	}
	void getEyeY()
	{
		fprintf(mFile,"\"%s.e.ey\"",mName.c_str());

	}
	void getEyeZ()
	{
		fprintf(mFile,"\"%s.e.ez\"",mName.c_str());

	}
	void getCenterOfInterest()
	{
		fprintf(mFile,"\"%s.coi\"",mName.c_str());

	}
	void getCenterOfInterestX()
	{
		fprintf(mFile,"\"%s.coi.cx\"",mName.c_str());

	}
	void getCenterOfInterestY()
	{
		fprintf(mFile,"\"%s.coi.cy\"",mName.c_str());

	}
	void getCenterOfInterestZ()
	{
		fprintf(mFile,"\"%s.coi.cz\"",mName.c_str());

	}
	void getUp()
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());

	}
	void getUpX()
	{
		fprintf(mFile,"\"%s.u.ux\"",mName.c_str());

	}
	void getUpY()
	{
		fprintf(mFile,"\"%s.u.uy\"",mName.c_str());

	}
	void getUpZ()
	{
		fprintf(mFile,"\"%s.u.uz\"",mName.c_str());

	}
	void getTumblePivot()
	{
		fprintf(mFile,"\"%s.tp\"",mName.c_str());

	}
	void getTumblePivotX()
	{
		fprintf(mFile,"\"%s.tp.tpx\"",mName.c_str());

	}
	void getTumblePivotY()
	{
		fprintf(mFile,"\"%s.tp.tpy\"",mName.c_str());

	}
	void getTumblePivotZ()
	{
		fprintf(mFile,"\"%s.tp.tpz\"",mName.c_str());

	}
	void getHorizontalAperture()
	{
		fprintf(mFile,"\"%s.ha\"",mName.c_str());

	}
	void getVerticalAperture()
	{
		fprintf(mFile,"\"%s.va\"",mName.c_str());

	}
	void getFocalLength()
	{
		fprintf(mFile,"\"%s.fl\"",mName.c_str());

	}
	void getOrthographicWidth()
	{
		fprintf(mFile,"\"%s.ow\"",mName.c_str());

	}
	void getOrthographic()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getDescription()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
protected:
	CameraView(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CAMERAVIEW_H__
