/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYBLINDDATA_H__
#define __MayaDM_POLYBLINDDATA_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class PolyBlindData : public DependNode
{
public:
public:
	PolyBlindData():DependNode(){}
	PolyBlindData(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "polyBlindData"){}
	virtual ~PolyBlindData(){}
	void setTypeId(int tid)
	{
		if(tid == 0) return;
		fprintf(mFile,"\tsetAttr \".tid\" %i;\n", tid);

	}
	void setBlindDataEntriesAreNew(bool bdn)
	{
		if(bdn == false) return;
		fprintf(mFile,"\tsetAttr \".bdn\" %i;\n", bdn);

	}
	void getTypeId()
	{
		fprintf(mFile,"\"%s.tid\"",mName.c_str());

	}
	void getInMesh()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getOutMesh()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	PolyBlindData(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYBLINDDATA_H__
