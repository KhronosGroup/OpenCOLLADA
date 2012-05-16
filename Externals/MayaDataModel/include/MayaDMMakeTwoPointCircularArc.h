/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKETWOPOINTCIRCULARARC_H__
#define __MayaDM_MAKETWOPOINTCIRCULARARC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMMakeCircularArc.h"
namespace MayaDM
{
class MakeTwoPointCircularArc : public MakeCircularArc
{
public:
public:

	MakeTwoPointCircularArc():MakeCircularArc(){}
	MakeTwoPointCircularArc(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:MakeCircularArc(file, name, parent, "makeTwoPointCircularArc", shared, create){}
	virtual ~MakeTwoPointCircularArc(){}

	void setPoint1(const double3& pt1)
	{
		fprintf(mFile,"\tsetAttr \".pt1\" -type \"double3\" ");
		pt1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPoint1X(double p1x)
	{
		if(p1x == 1) return;
		fprintf(mFile,"\tsetAttr \".pt1.p1x\" %f;\n", p1x);
	}
	void setPoint1Y(double p1y)
	{
		if(p1y == 0) return;
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
		if(p2x == 1) return;
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
	void setDirectionVector(const double3& dv)
	{
		fprintf(mFile,"\tsetAttr \".dv\" -type \"double3\" ");
		dv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDirectionVectorX(double dvx)
	{
		if(dvx == 0) return;
		fprintf(mFile,"\tsetAttr \".dv.dvx\" %f;\n", dvx);
	}
	void setDirectionVectorY(double dvy)
	{
		if(dvy == 0) return;
		fprintf(mFile,"\tsetAttr \".dv.dvy\" %f;\n", dvy);
	}
	void setDirectionVectorZ(double dvz)
	{
		if(dvz == 1) return;
		fprintf(mFile,"\tsetAttr \".dv.dvz\" %f;\n", dvz);
	}
	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"\tsetAttr \".r\" %f;\n", r);
	}
	void setToggleArc(bool tac)
	{
		if(tac == false) return;
		fprintf(mFile,"\tsetAttr \".tac\" %i;\n", tac);
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
	void getDirectionVector()const
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());
	}
	void getDirectionVectorX()const
	{
		fprintf(mFile,"\"%s.dv.dvx\"",mName.c_str());
	}
	void getDirectionVectorY()const
	{
		fprintf(mFile,"\"%s.dv.dvy\"",mName.c_str());
	}
	void getDirectionVectorZ()const
	{
		fprintf(mFile,"\"%s.dv.dvz\"",mName.c_str());
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getToggleArc()const
	{
		fprintf(mFile,"\"%s.tac\"",mName.c_str());
	}
protected:
	MakeTwoPointCircularArc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:MakeCircularArc(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKETWOPOINTCIRCULARARC_H__
