/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMERGEEDGE_H__
#define __MayaDM_POLYMERGEEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyMergeEdge : public PolyModifier
{
public:
public:

	PolyMergeEdge():PolyModifier(){}
	PolyMergeEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyMergeEdge", shared, create){}
	virtual ~PolyMergeEdge(){}

	void setMergeMode(unsigned int mm)
	{
		if(mm == 1) return;
		fprintf(mFile,"\tsetAttr \".mm\" %i;\n", mm);
	}
	void setFirstEdge(int fe)
	{
		if(fe == -1) return;
		fprintf(mFile,"\tsetAttr \".fe\" %i;\n", fe);
	}
	void setSecondEdge(int se)
	{
		if(se == -1) return;
		fprintf(mFile,"\tsetAttr \".se\" %i;\n", se);
	}
	void setMergeTexture(bool mt)
	{
		if(mt == false) return;
		fprintf(mFile,"\tsetAttr \".mt\" %i;\n", mt);
	}
	void getMergeMode()const
	{
		fprintf(mFile,"\"%s.mm\"",mName.c_str());
	}
	void getFirstEdge()const
	{
		fprintf(mFile,"\"%s.fe\"",mName.c_str());
	}
	void getSecondEdge()const
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());
	}
	void getMergeTexture()const
	{
		fprintf(mFile,"\"%s.mt\"",mName.c_str());
	}
protected:
	PolyMergeEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMERGEEDGE_H__
