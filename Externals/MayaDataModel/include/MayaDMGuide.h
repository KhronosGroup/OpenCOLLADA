/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Guide(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "guide"){}
	virtual ~Guide(){}
	void setJointAboveMatrix(const matrix& am)
	{
		if(am == identity) return;
		fprintf(mFile,"setAttr \".am\" -type \"matrix\" ");
		am.write(mFile);
		fprintf(mFile,";\n");

	}
	void setJointXformMatrix(const matrix& jm)
	{
		fprintf(mFile,"setAttr \".jm\" -type \"matrix\" ");
		jm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setJointBelowMatrix(const matrix& bm)
	{
		if(bm == identity) return;
		fprintf(mFile,"setAttr \".bm\" -type \"matrix\" ");
		bm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setJointGuideAxis(unsigned int ga)
	{
		if(ga == 0) return;
		fprintf(mFile,"setAttr \".ga\" %i;\n", ga);

	}
	void getJointAboveMatrix()
	{
		fprintf(mFile,"\"%s.am\"",mName.c_str());

	}
	void getJointXformMatrix()
	{
		fprintf(mFile,"\"%s.jm\"",mName.c_str());

	}
	void getJointBelowMatrix()
	{
		fprintf(mFile,"\"%s.bm\"",mName.c_str());

	}
	void getJointGuideAxis()
	{
		fprintf(mFile,"\"%s.ga\"",mName.c_str());

	}
	void getBendVector()
	{
		fprintf(mFile,"\"%s.bv\"",mName.c_str());

	}
	void getBendVectorX()
	{
		fprintf(mFile,"\"%s.bv.bx\"",mName.c_str());

	}
	void getBendVectorY()
	{
		fprintf(mFile,"\"%s.bv.by\"",mName.c_str());

	}
	void getBendVectorZ()
	{
		fprintf(mFile,"\"%s.bv.bz\"",mName.c_str());

	}
	void getBendAngle()
	{
		fprintf(mFile,"\"%s.ba\"",mName.c_str());

	}
	void getBendMagnitude()
	{
		fprintf(mFile,"\"%s.mg\"",mName.c_str());

	}
	void getRotateX()
	{
		fprintf(mFile,"\"%s.rx\"",mName.c_str());

	}
	void getRotateY()
	{
		fprintf(mFile,"\"%s.ry\"",mName.c_str());

	}
	void getRotateZ()
	{
		fprintf(mFile,"\"%s.rz\"",mName.c_str());

	}
	void getMaxXYZ()
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());

	}
	void getAutoGuide()
	{
		fprintf(mFile,"\"%s.ag\"",mName.c_str());

	}
protected:
	Guide(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_GUIDE_H__
