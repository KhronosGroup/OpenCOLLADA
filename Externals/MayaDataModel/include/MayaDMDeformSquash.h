/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMSQUASH_H__
#define __MayaDM_DEFORMSQUASH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
class DeformSquash : public DeformFunc
{
public:
public:

	DeformSquash():DeformFunc(){}
	DeformSquash(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, "deformSquash", shared, create){}
	virtual ~DeformSquash(){}

	void setLowBound(double lb)
	{
		if(lb == -1.0) return;
		fprintf(mFile,"\tsetAttr \".lb\" %f;\n", lb);
	}
	void setHighBound(double hb)
	{
		if(hb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hb\" %f;\n", hb);
	}
	void setStartSmoothness(double ss)
	{
		if(ss == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ss\" %f;\n", ss);
	}
	void setEndSmoothness(double es)
	{
		if(es == 0.0) return;
		fprintf(mFile,"\tsetAttr \".es\" %f;\n", es);
	}
	void setMaxExpandPos(double mp)
	{
		if(mp == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mp\" %f;\n", mp);
	}
	void setExpand(double exp)
	{
		if(exp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".exp\" %f;\n", exp);
	}
	void setFactor(double fac)
	{
		if(fac == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fac\" %f;\n", fac);
	}
	void getLowBound()const
	{
		fprintf(mFile,"\"%s.lb\"",mName.c_str());
	}
	void getHighBound()const
	{
		fprintf(mFile,"\"%s.hb\"",mName.c_str());
	}
	void getStartSmoothness()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getEndSmoothness()const
	{
		fprintf(mFile,"\"%s.es\"",mName.c_str());
	}
	void getMaxExpandPos()const
	{
		fprintf(mFile,"\"%s.mp\"",mName.c_str());
	}
	void getExpand()const
	{
		fprintf(mFile,"\"%s.exp\"",mName.c_str());
	}
	void getFactor()const
	{
		fprintf(mFile,"\"%s.fac\"",mName.c_str());
	}
protected:
	DeformSquash(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMSQUASH_H__
