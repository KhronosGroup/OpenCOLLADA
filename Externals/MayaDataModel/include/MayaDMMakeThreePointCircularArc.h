/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKETHREEPOINTCIRCULARARC_H__
#define __MayaDM_MAKETHREEPOINTCIRCULARARC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMMakeCircularArc.h"
namespace MayaDM
{
class MakeThreePointCircularArc : public MakeCircularArc
{
public:
public:

	MakeThreePointCircularArc():MakeCircularArc(){}
	MakeThreePointCircularArc(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:MakeCircularArc(file, name, parent, "makeThreePointCircularArc", shared, create){}
	virtual ~MakeThreePointCircularArc(){}

	void setPoint1(const double3& pt1)
	{
		fprintf(mFile,"\tsetAttr \".pt1\" -type \"double3\" ");
		pt1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPoint1X(double p1x)
	{
		if(p1x == 0) return;
		fprintf(mFile,"\tsetAttr \".pt1.p1x\" %f;\n", p1x);
	}
	void setPoint1Y(double p1y)
	{
		if(p1y == 1) return;
		fprintf(mFile,"\tsetAttr \".pt1.p1y\" %f;\n", p1y);
	}
	void setPoint1Z(double p1z)
	{
		if(p1z == 0) return;
		fprintf(mFile,"\tsetAttr \".pt1.p1z\" %f;\n", p1z);
	}
	void setPoint2(const double3& pt2)
	{
		fprintf(mFile,"\tsetAttr \".pt2\" -type \"double3\" ");
		pt2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPoint2X(double p2x)
	{
		if(p2x == 0) return;
		fprintf(mFile,"\tsetAttr \".pt2.p2x\" %f;\n", p2x);
	}
	void setPoint2Y(double p2y)
	{
		if(p2y == 0) return;
		fprintf(mFile,"\tsetAttr \".pt2.p2y\" %f;\n", p2y);
	}
	void setPoint2Z(double p2z)
	{
		if(p2z == 0) return;
		fprintf(mFile,"\tsetAttr \".pt2.p2z\" %f;\n", p2z);
	}
	void setPoint3(const double3& pt3)
	{
		fprintf(mFile,"\tsetAttr \".pt3\" -type \"double3\" ");
		pt3.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPoint3X(double p3x)
	{
		if(p3x == 1) return;
		fprintf(mFile,"\tsetAttr \".pt3.p3x\" %f;\n", p3x);
	}
	void setPoint3Y(double p3y)
	{
		if(p3y == 0) return;
		fprintf(mFile,"\tsetAttr \".pt3.p3y\" %f;\n", p3y);
	}
	void setPoint3Z(double p3z)
	{
		if(p3z == 0) return;
		fprintf(mFile,"\tsetAttr \".pt3.p3z\" %f;\n", p3z);
	}
	void getPoint1()const
	{
		fprintf(mFile,"\"%s.pt1\"",mName.c_str());
	}
	void getPoint1X()const
	{
		fprintf(mFile,"\"%s.pt1.p1x\"",mName.c_str());
	}
	void getPoint1Y()const
	{
		fprintf(mFile,"\"%s.pt1.p1y\"",mName.c_str());
	}
	void getPoint1Z()const
	{
		fprintf(mFile,"\"%s.pt1.p1z\"",mName.c_str());
	}
	void getPoint2()const
	{
		fprintf(mFile,"\"%s.pt2\"",mName.c_str());
	}
	void getPoint2X()const
	{
		fprintf(mFile,"\"%s.pt2.p2x\"",mName.c_str());
	}
	void getPoint2Y()const
	{
		fprintf(mFile,"\"%s.pt2.p2y\"",mName.c_str());
	}
	void getPoint2Z()const
	{
		fprintf(mFile,"\"%s.pt2.p2z\"",mName.c_str());
	}
	void getPoint3()const
	{
		fprintf(mFile,"\"%s.pt3\"",mName.c_str());
	}
	void getPoint3X()const
	{
		fprintf(mFile,"\"%s.pt3.p3x\"",mName.c_str());
	}
	void getPoint3Y()const
	{
		fprintf(mFile,"\"%s.pt3.p3y\"",mName.c_str());
	}
	void getPoint3Z()const
	{
		fprintf(mFile,"\"%s.pt3.p3z\"",mName.c_str());
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
protected:
	MakeThreePointCircularArc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:MakeCircularArc(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKETHREEPOINTCIRCULARARC_H__
