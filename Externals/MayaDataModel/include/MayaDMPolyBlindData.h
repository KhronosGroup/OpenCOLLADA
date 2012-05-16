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
	PolyBlindData(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "polyBlindData", shared, create){}
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
	void getTypeId()const
	{
		fprintf(mFile,"\"%s.tid\"",mName.c_str());
	}
	void getInMesh()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutMesh()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	PolyBlindData(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYBLINDDATA_H__
