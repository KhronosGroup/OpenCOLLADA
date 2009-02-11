/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBTORUS_H__
#define __MayaDM_MAKENURBTORUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRevolvedPrimitive.h"
namespace MayaDM
{
class MakeNurbTorus : public RevolvedPrimitive
{
public:
public:
	MakeNurbTorus():RevolvedPrimitive(){}
	MakeNurbTorus(FILE* file,const std::string& name,const std::string& parent=""):RevolvedPrimitive(file, name, parent, "makeNurbTorus"){}
	virtual ~MakeNurbTorus(){}
	void setMinorSweep(double msw)
	{
		if(msw == 6.2831853) return;
		fprintf(mFile,"\tsetAttr \".msw\" %f;\n", msw);

	}
	void getMinorSweep()
	{
		fprintf(mFile,"\"%s.msw\"",mName.c_str());

	}
protected:
	MakeNurbTorus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:RevolvedPrimitive(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBTORUS_H__
