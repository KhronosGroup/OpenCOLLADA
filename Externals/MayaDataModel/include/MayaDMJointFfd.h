/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_JOINTFFD_H__
#define __MayaDM_JOINTFFD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFfd.h"
namespace MayaDM
{
class JointFfd : public Ffd
{
public:
public:

	JointFfd():Ffd(){}
	JointFfd(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Ffd(file, name, parent, "jointFfd", shared, create){}
	virtual ~JointFfd(){}

	void setBaseLattice2Matrix(const matrix& b2)
	{
		if(b2 == identity) return;
		fprintf(mFile,"\tsetAttr \".b2\" -type \"matrix\" ");
		b2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUseComponentCache(bool uc)
	{
		if(uc == true) return;
		fprintf(mFile,"\tsetAttr \".uc\" %i;\n", uc);
	}
	void getBaseLattice2Matrix()const
	{
		fprintf(mFile,"\"%s.b2\"",mName.c_str());
	}
	void getGroupIdUpperBindSkin(size_t gu_i)const
	{
		fprintf(mFile,"\"%s.gu[%i]\"",mName.c_str(),gu_i);
	}
	void getGroupIdUpperBindSkin()const
	{

		fprintf(mFile,"\"%s.gu\"",mName.c_str());
	}
	void getGroupIdLowerBindSkin(size_t gl_i)const
	{
		fprintf(mFile,"\"%s.gl[%i]\"",mName.c_str(),gl_i);
	}
	void getGroupIdLowerBindSkin()const
	{

		fprintf(mFile,"\"%s.gl\"",mName.c_str());
	}
	void getUpperBindSkinNode()const
	{
		fprintf(mFile,"\"%s.ub\"",mName.c_str());
	}
	void getLowerBindSkinNode()const
	{
		fprintf(mFile,"\"%s.lb\"",mName.c_str());
	}
	void getUseComponentCache()const
	{
		fprintf(mFile,"\"%s.uc\"",mName.c_str());
	}
protected:
	JointFfd(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Ffd(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_JOINTFFD_H__
