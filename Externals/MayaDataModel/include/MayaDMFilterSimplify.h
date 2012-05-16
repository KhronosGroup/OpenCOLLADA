/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTERSIMPLIFY_H__
#define __MayaDM_FILTERSIMPLIFY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFilter.h"
namespace MayaDM
{
class FilterSimplify : public Filter
{
public:
public:

	FilterSimplify():Filter(){}
	FilterSimplify(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Filter(file, name, parent, "filterSimplify", shared, create){}
	virtual ~FilterSimplify(){}

	void setTolerance(double tol)
	{
		if(tol == 0.001) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void setTimeTolerance(double tt)
	{
		if(tt == 0.00) return;
		fprintf(mFile,"\tsetAttr \".tt\" %f;\n", tt);
	}
	void setMinTimeStep(double mnt)
	{
		if(mnt == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mnt\" %f;\n", mnt);
	}
	void setMaxTimeStep(double mxt)
	{
		if(mxt == 3600) return;
		fprintf(mFile,"\tsetAttr \".mxt\" %f;\n", mxt);
	}
	void setAllowDuplicates(bool ad)
	{
		if(ad == true) return;
		fprintf(mFile,"\tsetAttr \".ad\" %i;\n", ad);
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getTimeTolerance()const
	{
		fprintf(mFile,"\"%s.tt\"",mName.c_str());
	}
	void getMinTimeStep()const
	{
		fprintf(mFile,"\"%s.mnt\"",mName.c_str());
	}
	void getMaxTimeStep()const
	{
		fprintf(mFile,"\"%s.mxt\"",mName.c_str());
	}
	void getAllowDuplicates()const
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());
	}
protected:
	FilterSimplify(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Filter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FILTERSIMPLIFY_H__
