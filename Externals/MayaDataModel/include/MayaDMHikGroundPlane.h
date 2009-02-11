/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HIKGROUNDPLANE_H__
#define __MayaDM_HIKGROUNDPLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class HikGroundPlane : public Transform
{
public:
public:
	HikGroundPlane():Transform(){}
	HikGroundPlane(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "hikGroundPlane"){}
	virtual ~HikGroundPlane(){}
	void setLength(double leng)
	{
		if(leng == 1.0) return;
		fprintf(mFile,"\tsetAttr \".leng\" %f;\n", leng);

	}
	void getLength()
	{
		fprintf(mFile,"\"%s.leng\"",mName.c_str());

	}
protected:
	HikGroundPlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Transform(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HIKGROUNDPLANE_H__
