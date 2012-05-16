/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISTANCEBETWEEN_H__
#define __MayaDM_DISTANCEBETWEEN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DistanceBetween : public DependNode
{
public:
public:

	DistanceBetween():DependNode(){}
	DistanceBetween(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "distanceBetween", shared, create){}
	virtual ~DistanceBetween(){}

	void setPoint1(const double3& p1)
	{
		fprintf(mFile,"\tsetAttr \".p1\" -type \"double3\" ");
		p1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPoint1X(double p1x)
	{
		if(p1x == 0) return;
		fprintf(mFile,"\tsetAttr \".p1.p1x\" %f;\n", p1x);
	}
	void setPoint1Y(double p1y)
	{
		if(p1y == 0) return;
		fprintf(mFile,"\tsetAttr \".p1.p1y\" %f;\n", p1y);
	}
	void setPoint1Z(double p1z)
	{
		if(p1z == 0) return;
		fprintf(mFile,"\tsetAttr \".p1.p1z\" %f;\n", p1z);
	}
	void setInMatrix1(const matrix& im1)
	{
		if(im1 == identity) return;
		fprintf(mFile,"\tsetAttr \".im1\" -type \"matrix\" ");
		im1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPoint2(const double3& p2)
	{
		fprintf(mFile,"\tsetAttr \".p2\" -type \"double3\" ");
		p2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPoint2X(double p2x)
	{
		if(p2x == 0) return;
		fprintf(mFile,"\tsetAttr \".p2.p2x\" %f;\n", p2x);
	}
	void setPoint2Y(double p2y)
	{
		if(p2y == 0) return;
		fprintf(mFile,"\tsetAttr \".p2.p2y\" %f;\n", p2y);
	}
	void setPoint2Z(double p2z)
	{
		if(p2z == 0) return;
		fprintf(mFile,"\tsetAttr \".p2.p2z\" %f;\n", p2z);
	}
	void setInMatrix2(const matrix& im2)
	{
		if(im2 == identity) return;
		fprintf(mFile,"\tsetAttr \".im2\" -type \"matrix\" ");
		im2.write(mFile);
		fprintf(mFile,";\n");
	}
	void getPoint1()const
	{
		fprintf(mFile,"\"%s.p1\"",mName.c_str());
	}
	void getPoint1X()const
	{
		fprintf(mFile,"\"%s.p1.p1x\"",mName.c_str());
	}
	void getPoint1Y()const
	{
		fprintf(mFile,"\"%s.p1.p1y\"",mName.c_str());
	}
	void getPoint1Z()const
	{
		fprintf(mFile,"\"%s.p1.p1z\"",mName.c_str());
	}
	void getInMatrix1()const
	{
		fprintf(mFile,"\"%s.im1\"",mName.c_str());
	}
	void getPoint2()const
	{
		fprintf(mFile,"\"%s.p2\"",mName.c_str());
	}
	void getPoint2X()const
	{
		fprintf(mFile,"\"%s.p2.p2x\"",mName.c_str());
	}
	void getPoint2Y()const
	{
		fprintf(mFile,"\"%s.p2.p2y\"",mName.c_str());
	}
	void getPoint2Z()const
	{
		fprintf(mFile,"\"%s.p2.p2z\"",mName.c_str());
	}
	void getInMatrix2()const
	{
		fprintf(mFile,"\"%s.im2\"",mName.c_str());
	}
	void getDistance()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
protected:
	DistanceBetween(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DISTANCEBETWEEN_H__
