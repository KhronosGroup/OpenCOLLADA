/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLEXORSHAPE_H__
#define __MayaDM_FLEXORSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class FlexorShape : public Shape
{
public:
public:
	FlexorShape(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "flexorShape"){}
	virtual ~FlexorShape(){}
	void setCurrentDriver(short cdr)
	{
		if(cdr == -1) return;
		fprintf(mFile,"setAttr \".cdr\" %i;\n", cdr);

	}
	void getCurrentDriver()
	{
		fprintf(mFile,"\"%s.cdr\"",mName.c_str());

	}
protected:
	FlexorShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FLEXORSHAPE_H__
