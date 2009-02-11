/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ARCLENGTHDIMENSION_H__
#define __MayaDM_ARCLENGTHDIMENSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNurbsDimShape.h"
namespace MayaDM
{
class ArcLengthDimension : public NurbsDimShape
{
public:
public:
	ArcLengthDimension():NurbsDimShape(){}
	ArcLengthDimension(FILE* file,const std::string& name,const std::string& parent=""):NurbsDimShape(file, name, parent, "arcLengthDimension"){}
	virtual ~ArcLengthDimension(){}
	void getArcLength()
	{
		fprintf(mFile,"\"%s.al\"",mName.c_str());

	}
	void getArcLengthInV()
	{
		fprintf(mFile,"\"%s.alv\"",mName.c_str());

	}
protected:
	ArcLengthDimension(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:NurbsDimShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ARCLENGTHDIMENSION_H__
