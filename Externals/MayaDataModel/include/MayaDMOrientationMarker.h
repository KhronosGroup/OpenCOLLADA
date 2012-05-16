/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ORIENTATIONMARKER_H__
#define __MayaDM_ORIENTATIONMARKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPositionMarker.h"
namespace MayaDM
{
class OrientationMarker : public PositionMarker
{
public:
public:

	OrientationMarker():PositionMarker(){}
	OrientationMarker(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PositionMarker(file, name, parent, "orientationMarker", shared, create){}
	virtual ~OrientationMarker(){}

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
protected:
	OrientationMarker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PositionMarker(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ORIENTATIONMARKER_H__
