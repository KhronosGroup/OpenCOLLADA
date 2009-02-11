/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYBOOLOP_H__
#define __MayaDM_POLYBOOLOP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyUnite.h"
namespace MayaDM
{
class PolyBoolOp : public PolyUnite
{
public:
public:
	PolyBoolOp():PolyUnite(){}
	PolyBoolOp(FILE* file,const std::string& name,const std::string& parent=""):PolyUnite(file, name, parent, "polyBoolOp"){}
	virtual ~PolyBoolOp(){}
	void setOperation(unsigned int op)
	{
		if(op == 0) return;
		fprintf(mFile,"\tsetAttr \".op\" %i;\n", op);

	}
	void setUseThresholds(bool uth)
	{
		if(uth == false) return;
		fprintf(mFile,"\tsetAttr \".uth\" %i;\n", uth);

	}
	void setVertexDistanceThreshold(double vdt)
	{
		if(vdt == 0) return;
		fprintf(mFile,"\tsetAttr \".vdt\" %f;\n", vdt);

	}
	void setFaceAreaThreshold(double fat)
	{
		if(fat == 0) return;
		fprintf(mFile,"\tsetAttr \".fat\" %f;\n", fat);

	}
	void getOperation()
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());

	}
	void getUseThresholds()
	{
		fprintf(mFile,"\"%s.uth\"",mName.c_str());

	}
	void getVertexDistanceThreshold()
	{
		fprintf(mFile,"\"%s.vdt\"",mName.c_str());

	}
	void getFaceAreaThreshold()
	{
		fprintf(mFile,"\"%s.fat\"",mName.c_str());

	}
protected:
	PolyBoolOp(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:PolyUnite(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYBOOLOP_H__
