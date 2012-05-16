/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GUIDE_H__
#define __MayaDM_GUIDE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Guide : public DependNode
{
public:
public:

	Guide():DependNode(){}
	Guide(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "guide", shared, create){}
	virtual ~Guide(){}

	void setJointAboveMatrix(const matrix& am)
	{
		if(am == identity) return;
		fprintf(mFile,"\tsetAttr \".am\" -type \"matrix\" ");
		am.write(mFile);
		fprintf(mFile,";\n");
	}
	void setJointXformMatrix(const matrix& jm)
	{
		fprintf(mFile,"\tsetAttr \".jm\" -type \"matrix\" ");
		jm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setJointBelowMatrix(const matrix& bm)
	{
		if(bm == identity) return;
		fprintf(mFile,"\tsetAttr \".bm\" -type \"matrix\" ");
		bm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setJointGuideAxis(unsigned int ga)
	{
		if(ga == 0) return;
		fprintf(mFile,"\tsetAttr \".ga\" %i;\n", ga);
	}
	void getJointAboveMatrix()const
	{
		fprintf(mFile,"\"%s.am\"",mName.c_str());
	}
	void getJointXformMatrix()const
	{
		fprintf(mFile,"\"%s.jm\"",mName.c_str());
	}
	void getJointBelowMatrix()const
	{
		fprintf(mFile,"\"%s.bm\"",mName.c_str());
	}
	void getJointGuideAxis()const
	{
		fprintf(mFile,"\"%s.ga\"",mName.c_str());
	}
	void getBendVector()const
	{
		fprintf(mFile,"\"%s.bv\"",mName.c_str());
	}
	void getBendVectorX()const
	{
		fprintf(mFile,"\"%s.bv.bx\"",mName.c_str());
	}
	void getBendVectorY()const
	{
		fprintf(mFile,"\"%s.bv.by\"",mName.c_str());
	}
	void getBendVectorZ()const
	{
		fprintf(mFile,"\"%s.bv.bz\"",mName.c_str());
	}
	void getBendAngle()const
	{
		fprintf(mFile,"\"%s.ba\"",mName.c_str());
	}
	void getBendMagnitude()const
	{
		fprintf(mFile,"\"%s.mg\"",mName.c_str());
	}
	void getRotateX()const
	{
		fprintf(mFile,"\"%s.rx\"",mName.c_str());
	}
	void getRotateY()const
	{
		fprintf(mFile,"\"%s.ry\"",mName.c_str());
	}
	void getRotateZ()const
	{
		fprintf(mFile,"\"%s.rz\"",mName.c_str());
	}
	void getMaxXYZ()const
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());
	}
	void getAutoGuide()const
	{
		fprintf(mFile,"\"%s.ag\"",mName.c_str());
	}
protected:
	Guide(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_GUIDE_H__
