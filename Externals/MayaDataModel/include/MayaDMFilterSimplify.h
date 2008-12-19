/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	FilterSimplify(FILE* file,const std::string& name,const std::string& parent=""):Filter(file, name, parent, "filterSimplify"){}
	virtual ~FilterSimplify(){}
	void setTolerance(double tol)
	{
		if(tol == 0.001) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void setTimeTolerance(double tt)
	{
		if(tt == 0.00) return;
		fprintf(mFile,"setAttr \".tt\" %f;\n", tt);

	}
	void setMinTimeStep(double mnt)
	{
		if(mnt == 0.0) return;
		fprintf(mFile,"setAttr \".mnt\" %f;\n", mnt);

	}
	void setMaxTimeStep(double mxt)
	{
		if(mxt == 3600) return;
		fprintf(mFile,"setAttr \".mxt\" %f;\n", mxt);

	}
	void setAllowDuplicates(bool ad)
	{
		if(ad == true) return;
		fprintf(mFile,"setAttr \".ad\" %i;\n", ad);

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getTimeTolerance()
	{
		fprintf(mFile,"\"%s.tt\"",mName.c_str());

	}
	void getMinTimeStep()
	{
		fprintf(mFile,"\"%s.mnt\"",mName.c_str());

	}
	void getMaxTimeStep()
	{
		fprintf(mFile,"\"%s.mxt\"",mName.c_str());

	}
	void getAllowDuplicates()
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());

	}
protected:
	FilterSimplify(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Filter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FILTERSIMPLIFY_H__
