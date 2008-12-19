/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	MotionPath(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "motionPath"){}
	virtual ~MotionPath(){}
	void setUValue(double u)
	{
		if(u == 0) return;
		fprintf(mFile,"setAttr \".u\" %f;\n", u);

	}
	void setFrontTwist(double ft)
	{
		if(ft == 0) return;
		fprintf(mFile,"setAttr \".ft\" %f;\n", ft);

	}
	void setUpTwist(double ut)
	{
		if(ut == 0) return;
		fprintf(mFile,"setAttr \".ut\" %f;\n", ut);

	}
	void setSideTwist(double st)
	{
		if(st == 0) return;
		fprintf(mFile,"setAttr \".st\" %f;\n", st);

	}
	void setRotateOrder(unsigned int ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"setAttr \".ro\" %i;\n", ro);

	}
	void setFollow(bool f)
	{
		if(f == false) return;
		fprintf(mFile,"setAttr \".f\" %i;\n", f);

	}
	void setNormal(bool nr)
	{
		if(nr == false) return;
		fprintf(mFile,"setAttr \".nr\" %i;\n", nr);

	}
	void setInverseUp(bool iu)
	{
		if(iu == false) return;
		fprintf(mFile,"setAttr \".iu\" %i;\n", iu);

	}
	void setInverseFront(bool if_)
	{
		if(if_ == false) return;
		fprintf(mFile,"setAttr \".if\" %i;\n", if_);

	}
	void setFrontAxis(unsigned int fa)
	{
		if(fa == 1) return;
		fprintf(mFile,"setAttr \".fa\" %i;\n", fa);

	}
	void setUpAxis(unsigned int ua)
	{
		if(ua == 2) return;
		fprintf(mFile,"setAttr \".ua\" %i;\n", ua);

	}
	void setWorldUpType(unsigned int wut)
	{
		if(wut == 3) return;
		fprintf(mFile,"setAttr \".wut\" %i;\n", wut);

	}
	void setWorldUpVector(const double3& wu)
	{
		fprintf(mFile,"setAttr \".wu\" -type \"double3\" ");
		wu.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWorldUpVectorX(double wux)
	{
		if(wux == 0.0) return;
		fprintf(mFile,"setAttr \".wu.wux\" %f;\n", wux);

	}
	void setWorldUpVectorY(double wuy)
	{
		if(wuy == 1.0) return;
		fprintf(mFile,"setAttr \".wu.wuy\" %f;\n", wuy);

	}
	void setWorldUpVectorZ(double wuz)
	{
		if(wuz == 0.0) return;
		fprintf(mFile,"setAttr \".wu.wuz\" %f;\n", wuz);

	}
	void setWorldUpMatrix(const matrix& wum)
	{
		if(wum == identity) return;
		fprintf(mFile,"setAttr \".wum\" -type \"matrix\" ");
		wum.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBank(bool b)
	{
		if(b == false) return;
		fprintf(mFile,"setAttr \".b\" %i;\n", b);

	}
	void setBankScale(double bs)
	{
		if(bs == 1.0) return;
		fprintf(mFile,"setAttr \".bs\" %f;\n", bs);

	}
	void setBankLimit(double bl)
	{
		if(bl == 9) return;
		fprintf(mFile,"setAttr \".bl\" %f;\n", bl);

	}
	void setFractionMode(bool fm)
	{
		if(fm == false) return;
		fprintf(mFile,"setAttr \".fm\" %i;\n", fm);

	}
	void getUValue()
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());

	}
	void getFrontTwist()
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());

	}
	void getUpTwist()
	{
		fprintf(mFile,"\"%s.ut\"",mName.c_str());

	}
	void getSideTwist()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getAllCoordinates()
	{
		fprintf(mFile,"\"%s.ac\"",mName.c_str());

	}
	void getXCoordinate()
	{
		fprintf(mFile,"\"%s.ac.xc\"",mName.c_str());

	}
	void getYCoordinate()
	{
		fprintf(mFile,"\"%s.ac.yc\"",mName.c_str());

	}
	void getZCoordinate()
	{
		fprintf(mFile,"\"%s.ac.zc\"",mName.c_str());

	}
	void getOrientMatrix()
	{
		fprintf(mFile,"\"%s.om\"",mName.c_str());

	}
	void getRotate()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getRotateX()
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());

	}
	void getRotateY()
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());

	}
	void getRotateZ()
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());

	}
	void getRotateOrder()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getFlowNode()
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());

	}
	void getGeometryPath()
	{
		fprintf(mFile,"\"%s.gp\"",mName.c_str());

	}
	void getPositionMarkerTime(size_t pmt_i)
	{
		fprintf(mFile,"\"%s.pmt[%i]\"",mName.c_str(),pmt_i);

	}
	void getOrientationMarkerTime(size_t omt_i)
	{
		fprintf(mFile,"\"%s.omt[%i]\"",mName.c_str(),omt_i);

	}
	void getNormal()
	{
		fprintf(mFile,"\"%s.nr\"",mName.c_str());

	}
	void getInverseUp()
	{
		fprintf(mFile,"\"%s.iu\"",mName.c_str());

	}
	void getInverseFront()
	{
		fprintf(mFile,"\"%s.if\"",mName.c_str());

	}
	void getFrontAxis()
	{
		fprintf(mFile,"\"%s.fa\"",mName.c_str());

	}
	void getUpAxis()
	{
		fprintf(mFile,"\"%s.ua\"",mName.c_str());

	}
	void getWorldUpType()
	{
		fprintf(mFile,"\"%s.wut\"",mName.c_str());

	}
	void getWorldUpVector()
	{
		fprintf(mFile,"\"%s.wu\"",mName.c_str());

	}
	void getWorldUpVectorX()
	{
		fprintf(mFile,"\"%s.wu.wux\"",mName.c_str());

	}
	void getWorldUpVectorY()
	{
		fprintf(mFile,"\"%s.wu.wuy\"",mName.c_str());

	}
	void getWorldUpVectorZ()
	{
		fprintf(mFile,"\"%s.wu.wuz\"",mName.c_str());

	}
	void getWorldUpMatrix()
	{
		fprintf(mFile,"\"%s.wum\"",mName.c_str());

	}
	void getBank()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getBankScale()
	{
		fprintf(mFile,"\"%s.bs\"",mName.c_str());

	}
	void getBankLimit()
	{
		fprintf(mFile,"\"%s.bl\"",mName.c_str());

	}
protected:
	MotionPath(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MOTIONPATH_H__
