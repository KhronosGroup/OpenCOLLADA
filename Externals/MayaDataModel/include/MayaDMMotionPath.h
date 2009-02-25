/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MOTIONPATH_H__
#define __MayaDM_MOTIONPATH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class MotionPath : public DependNode
{
public:
public:
	MotionPath():DependNode(){}
	MotionPath(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:DependNode(file, name, parent, "motionPath", create){}
	virtual ~MotionPath(){}
	void setUValue(double u)
	{
		if(u == 0) return;
		fprintf(mFile,"\tsetAttr \".u\" %f;\n", u);

	}
	void setFrontTwist(double ft)
	{
		if(ft == 0) return;
		fprintf(mFile,"\tsetAttr \".ft\" %f;\n", ft);

	}
	void setUpTwist(double ut)
	{
		if(ut == 0) return;
		fprintf(mFile,"\tsetAttr \".ut\" %f;\n", ut);

	}
	void setSideTwist(double st)
	{
		if(st == 0) return;
		fprintf(mFile,"\tsetAttr \".st\" %f;\n", st);

	}
	void setRotateOrder(unsigned int ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"\tsetAttr \".ro\" %i;\n", ro);

	}
	void setFollow(bool f)
	{
		if(f == false) return;
		fprintf(mFile,"\tsetAttr \".f\" %i;\n", f);

	}
	void setNormal(bool nr)
	{
		if(nr == false) return;
		fprintf(mFile,"\tsetAttr \".nr\" %i;\n", nr);

	}
	void setInverseUp(bool iu)
	{
		if(iu == false) return;
		fprintf(mFile,"\tsetAttr \".iu\" %i;\n", iu);

	}
	void setInverseFront(bool if_)
	{
		if(if_ == false) return;
		fprintf(mFile,"\tsetAttr \".if\" %i;\n", if_);

	}
	void setFrontAxis(unsigned int fa)
	{
		if(fa == 1) return;
		fprintf(mFile,"\tsetAttr \".fa\" %i;\n", fa);

	}
	void setUpAxis(unsigned int ua)
	{
		if(ua == 2) return;
		fprintf(mFile,"\tsetAttr \".ua\" %i;\n", ua);

	}
	void setWorldUpType(unsigned int wut)
	{
		if(wut == 3) return;
		fprintf(mFile,"\tsetAttr \".wut\" %i;\n", wut);

	}
	void setWorldUpVector(const double3& wu)
	{
		fprintf(mFile,"\tsetAttr \".wu\" -type \"double3\" ");
		wu.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWorldUpVectorX(double wux)
	{
		if(wux == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wu.wux\" %f;\n", wux);

	}
	void setWorldUpVectorY(double wuy)
	{
		if(wuy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".wu.wuy\" %f;\n", wuy);

	}
	void setWorldUpVectorZ(double wuz)
	{
		if(wuz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wu.wuz\" %f;\n", wuz);

	}
	void setWorldUpMatrix(const matrix& wum)
	{
		if(wum == identity) return;
		fprintf(mFile,"\tsetAttr \".wum\" -type \"matrix\" ");
		wum.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBank(bool b)
	{
		if(b == false) return;
		fprintf(mFile,"\tsetAttr \".b\" %i;\n", b);

	}
	void setBankScale(double bs)
	{
		if(bs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bs\" %f;\n", bs);

	}
	void setBankLimit(double bl)
	{
		if(bl == 9) return;
		fprintf(mFile,"\tsetAttr \".bl\" %f;\n", bl);

	}
	void setFractionMode(bool fm)
	{
		if(fm == false) return;
		fprintf(mFile,"\tsetAttr \".fm\" %i;\n", fm);

	}
	void getUValue()const
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());

	}
	void getFrontTwist()const
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());

	}
	void getUpTwist()const
	{
		fprintf(mFile,"\"%s.ut\"",mName.c_str());

	}
	void getSideTwist()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getAllCoordinates()const
	{
		fprintf(mFile,"\"%s.ac\"",mName.c_str());

	}
	void getXCoordinate()const
	{
		fprintf(mFile,"\"%s.ac.xc\"",mName.c_str());

	}
	void getYCoordinate()const
	{
		fprintf(mFile,"\"%s.ac.yc\"",mName.c_str());

	}
	void getZCoordinate()const
	{
		fprintf(mFile,"\"%s.ac.zc\"",mName.c_str());

	}
	void getOrientMatrix()const
	{
		fprintf(mFile,"\"%s.om\"",mName.c_str());

	}
	void getRotate()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getRotateX()const
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());

	}
	void getRotateY()const
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());

	}
	void getRotateZ()const
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());

	}
	void getRotateOrder()const
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getFlowNode()const
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());

	}
	void getGeometryPath()const
	{
		fprintf(mFile,"\"%s.gp\"",mName.c_str());

	}
	void getPositionMarkerTime(size_t pmt_i)const
	{
		fprintf(mFile,"\"%s.pmt[%i]\"",mName.c_str(),pmt_i);

	}
	void getPositionMarkerTime()const
	{

		fprintf(mFile,"\"%s.pmt\"",mName.c_str());

	}
	void getOrientationMarkerTime(size_t omt_i)const
	{
		fprintf(mFile,"\"%s.omt[%i]\"",mName.c_str(),omt_i);

	}
	void getOrientationMarkerTime()const
	{

		fprintf(mFile,"\"%s.omt\"",mName.c_str());

	}
	void getNormal()const
	{
		fprintf(mFile,"\"%s.nr\"",mName.c_str());

	}
	void getInverseUp()const
	{
		fprintf(mFile,"\"%s.iu\"",mName.c_str());

	}
	void getInverseFront()const
	{
		fprintf(mFile,"\"%s.if\"",mName.c_str());

	}
	void getFrontAxis()const
	{
		fprintf(mFile,"\"%s.fa\"",mName.c_str());

	}
	void getUpAxis()const
	{
		fprintf(mFile,"\"%s.ua\"",mName.c_str());

	}
	void getWorldUpType()const
	{
		fprintf(mFile,"\"%s.wut\"",mName.c_str());

	}
	void getWorldUpVector()const
	{
		fprintf(mFile,"\"%s.wu\"",mName.c_str());

	}
	void getWorldUpVectorX()const
	{
		fprintf(mFile,"\"%s.wu.wux\"",mName.c_str());

	}
	void getWorldUpVectorY()const
	{
		fprintf(mFile,"\"%s.wu.wuy\"",mName.c_str());

	}
	void getWorldUpVectorZ()const
	{
		fprintf(mFile,"\"%s.wu.wuz\"",mName.c_str());

	}
	void getWorldUpMatrix()const
	{
		fprintf(mFile,"\"%s.wum\"",mName.c_str());

	}
	void getBank()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getBankScale()const
	{
		fprintf(mFile,"\"%s.bs\"",mName.c_str());

	}
	void getBankLimit()const
	{
		fprintf(mFile,"\"%s.bl\"",mName.c_str());

	}
protected:
	MotionPath(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:DependNode(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MOTIONPATH_H__
