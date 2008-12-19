/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISTANCEDIMSHAPE_H__
#define __MayaDM_DISTANCEDIMSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDimensionShape.h"
namespace MayaDM
{
class DistanceDimShape : public DimensionShape
{
public:
public:
	DistanceDimShape(FILE* file,const std::string& name,const std::string& parent=""):DimensionShape(file, name, parent, "distanceDimShape"){}
	virtual ~DistanceDimShape(){}
	void setStartPoint(const double3& sp)
	{
		fprintf(mFile,"setAttr \".sp\" -type \"double3\" ");
		sp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStartPointX(double spx)
	{
		if(spx == 0) return;
		fprintf(mFile,"setAttr \".sp.spx\" %f;\n", spx);

	}
	void setStartPointY(double spy)
	{
		if(spy == 0) return;
		fprintf(mFile,"setAttr \".sp.spy\" %f;\n", spy);

	}
	void setStartPointZ(double spz)
	{
		if(spz == 0) return;
		fprintf(mFile,"setAttr \".sp.spz\" %f;\n", spz);

	}
	void setEndPoint(const double3& ep)
	{
		fprintf(mFile,"setAttr \".ep\" -type \"double3\" ");
		ep.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEndPointX(double epx)
	{
		if(epx == 0) return;
		fprintf(mFile,"setAttr \".ep.epx\" %f;\n", epx);

	}
	void setEndPointY(double epy)
	{
		if(epy == 0) return;
		fprintf(mFile,"setAttr \".ep.epy\" %f;\n", epy);

	}
	void setEndPointZ(double epz)
	{
		if(epz == 0) return;
		fprintf(mFile,"setAttr \".ep.epz\" %f;\n", epz);

	}
	void getStartPoint()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getStartPointX()
	{
		fprintf(mFile,"\"%s.sp.spx\"",mName.c_str());

	}
	void getStartPointY()
	{
		fprintf(mFile,"\"%s.sp.spy\"",mName.c_str());

	}
	void getStartPointZ()
	{
		fprintf(mFile,"\"%s.sp.spz\"",mName.c_str());

	}
	void getEndPoint()
	{
		fprintf(mFile,"\"%s.ep\"",mName.c_str());

	}
	void getEndPointX()
	{
		fprintf(mFile,"\"%s.ep.epx\"",mName.c_str());

	}
	void getEndPointY()
	{
		fprintf(mFile,"\"%s.ep.epy\"",mName.c_str());

	}
	void getEndPointZ()
	{
		fprintf(mFile,"\"%s.ep.epz\"",mName.c_str());

	}
	void getDistance()
	{
		fprintf(mFile,"\"%s.dist\"",mName.c_str());

	}
protected:
	DistanceDimShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DimensionShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DISTANCEDIMSHAPE_H__
