/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SQUARESRF_H__
#define __MayaDM_SQUARESRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBoundaryBase.h"
namespace MayaDM
{
class SquareSrf : public BoundaryBase
{
public:
public:

	SquareSrf():BoundaryBase(){}
	SquareSrf(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:BoundaryBase(file, name, parent, "squareSrf", shared, create){}
	virtual ~SquareSrf(){}

	void setCurveFitCheckpoints(int cfc)
	{
		if(cfc == 5) return;
		fprintf(mFile,"\tsetAttr \".cfc\" %i;\n", cfc);
	}
	void setContinuityType1(unsigned int ct1)
	{
		if(ct1 == 2) return;
		fprintf(mFile,"\tsetAttr \".ct1\" %i;\n", ct1);
	}
	void setContinuityType2(unsigned int ct2)
	{
		if(ct2 == 2) return;
		fprintf(mFile,"\tsetAttr \".ct2\" %i;\n", ct2);
	}
	void setContinuityType3(unsigned int ct3)
	{
		if(ct3 == 2) return;
		fprintf(mFile,"\tsetAttr \".ct3\" %i;\n", ct3);
	}
	void setContinuityType4(unsigned int ct4)
	{
		if(ct4 == 2) return;
		fprintf(mFile,"\tsetAttr \".ct4\" %i;\n", ct4);
	}
	void setRebuildCurve1(bool rc1)
	{
		if(rc1 == false) return;
		fprintf(mFile,"\tsetAttr \".rc1\" %i;\n", rc1);
	}
	void setRebuildCurve2(bool rc2)
	{
		if(rc2 == false) return;
		fprintf(mFile,"\tsetAttr \".rc2\" %i;\n", rc2);
	}
	void setRebuildCurve3(bool rc3)
	{
		if(rc3 == false) return;
		fprintf(mFile,"\tsetAttr \".rc3\" %i;\n", rc3);
	}
	void setRebuildCurve4(bool rc4)
	{
		if(rc4 == false) return;
		fprintf(mFile,"\tsetAttr \".rc4\" %i;\n", rc4);
	}
	void getCurveFitCheckpoints()const
	{
		fprintf(mFile,"\"%s.cfc\"",mName.c_str());
	}
	void getContinuityType1()const
	{
		fprintf(mFile,"\"%s.ct1\"",mName.c_str());
	}
	void getContinuityType2()const
	{
		fprintf(mFile,"\"%s.ct2\"",mName.c_str());
	}
	void getContinuityType3()const
	{
		fprintf(mFile,"\"%s.ct3\"",mName.c_str());
	}
	void getContinuityType4()const
	{
		fprintf(mFile,"\"%s.ct4\"",mName.c_str());
	}
	void getRebuildCurve1()const
	{
		fprintf(mFile,"\"%s.rc1\"",mName.c_str());
	}
	void getRebuildCurve2()const
	{
		fprintf(mFile,"\"%s.rc2\"",mName.c_str());
	}
	void getRebuildCurve3()const
	{
		fprintf(mFile,"\"%s.rc3\"",mName.c_str());
	}
	void getRebuildCurve4()const
	{
		fprintf(mFile,"\"%s.rc4\"",mName.c_str());
	}
	void getContinuityPassed1()const
	{
		fprintf(mFile,"\"%s.cp1\"",mName.c_str());
	}
	void getContinuityPassed2()const
	{
		fprintf(mFile,"\"%s.cp2\"",mName.c_str());
	}
	void getContinuityPassed3()const
	{
		fprintf(mFile,"\"%s.cp3\"",mName.c_str());
	}
	void getContinuityPassed4()const
	{
		fprintf(mFile,"\"%s.cp4\"",mName.c_str());
	}
protected:
	SquareSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:BoundaryBase(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SQUARESRF_H__
