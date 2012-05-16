/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMERGEFACE_H__
#define __MayaDM_POLYMERGEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyMergeFace : public PolyModifier
{
public:
public:

	PolyMergeFace():PolyModifier(){}
	PolyMergeFace(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyMergeFace", shared, create){}
	virtual ~PolyMergeFace(){}

	void setMergeMode(unsigned int mm)
	{
		if(mm == 6) return;
		fprintf(mFile,"\tsetAttr \".mm\" %i;\n", mm);
	}
	void setUseAreaTolerance(bool uat)
	{
		if(uat == true) return;
		fprintf(mFile,"\tsetAttr \".uat\" %i;\n", uat);
	}
	void setFirstFacet(int ff)
	{
		if(ff == -1) return;
		fprintf(mFile,"\tsetAttr \".ff\" %i;\n", ff);
	}
	void setSecondFacet(int sf)
	{
		if(sf == -1) return;
		fprintf(mFile,"\tsetAttr \".sf\" %i;\n", sf);
	}
	void getMergeMode()const
	{
		fprintf(mFile,"\"%s.mm\"",mName.c_str());
	}
	void getFirstFacet()const
	{
		fprintf(mFile,"\"%s.ff\"",mName.c_str());
	}
	void getSecondFacet()const
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());
	}
protected:
	PolyMergeFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMERGEFACE_H__
