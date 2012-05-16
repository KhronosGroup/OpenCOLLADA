/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMIRROR_H__
#define __MayaDM_POLYMIRROR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyMirror : public PolyModifierWorld
{
public:
public:

	PolyMirror():PolyModifierWorld(){}
	PolyMirror(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polyMirror", shared, create){}
	virtual ~PolyMirror(){}

	void setPivot(const double3& p)
	{
		if(p == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".p\" -type \"double3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPivotX(double px)
	{
		if(px == 0) return;
		fprintf(mFile,"\tsetAttr \".p.px\" %f;\n", px);
	}
	void setPivotY(double py)
	{
		if(py == 0) return;
		fprintf(mFile,"\tsetAttr \".p.py\" %f;\n", py);
	}
	void setPivotZ(double pz)
	{
		if(pz == 0) return;
		fprintf(mFile,"\tsetAttr \".p.pz\" %f;\n", pz);
	}
	void setDirection(unsigned int d)
	{
		if(d == 0) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setMergeMode(unsigned int mm)
	{
		if(mm == 0) return;
		fprintf(mFile,"\tsetAttr \".mm\" %i;\n", mm);
	}
	void setMergeThreshold(double mt)
	{
		if(mt == 0) return;
		fprintf(mFile,"\tsetAttr \".mt\" %f;\n", mt);
	}
	void getPivot()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPivotX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPivotY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPivotZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getDirection()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getMergeMode()const
	{
		fprintf(mFile,"\"%s.mm\"",mName.c_str());
	}
	void getMergeThreshold()const
	{
		fprintf(mFile,"\"%s.mt\"",mName.c_str());
	}
protected:
	PolyMirror(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMIRROR_H__
