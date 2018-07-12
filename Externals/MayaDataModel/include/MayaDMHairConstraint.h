/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HAIRCONSTRAINT_H__
#define __MayaDM_HAIRCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class HairConstraint : public Shape
{
public:
public:

	HairConstraint():Shape(){}
	HairConstraint(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "hairConstraint", shared, create){}
	virtual ~HairConstraint(){}

	void setCurveIndices(size_t cin_i,int cin)
	{
		if(cin == 0) return;
		fprintf(mFile,"\tsetAttr \".cin[%i]\" %i;\n", cin_i,cin);
	}
	void setCurveIndices(size_t cin_start,size_t cin_end,int* cin)
	{
		fprintf(mFile,"\tsetAttr \".cin[%i:%i]\" ", cin_start,cin_end);
		size_t size = (cin_end-cin_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",cin[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startCurveIndices(size_t cin_start,size_t cin_end)const
	{
		fprintf(mFile,"\tsetAttr \".cin[%i:%i]\"",cin_start,cin_end);
	}
	void appendCurveIndices(int cin)const
	{
		fprintf(mFile," %i",cin);
	}
	void endCurveIndices()const
	{
		fprintf(mFile,";\n");
	}
	void setConstraintMethod(unsigned int cm)
	{
		if(cm == 1) return;
		fprintf(mFile,"\tsetAttr \".cm\" %i;\n", cm);
	}
	void setPointMethod(unsigned int pmt)
	{
		if(pmt == 0) return;
		fprintf(mFile,"\tsetAttr \".pmt\" %i;\n", pmt);
	}
	void setStiffness(double stf)
	{
		if(stf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".stf\" %f;\n", stf);
	}
	void setGlueStrength(double gst)
	{
		if(gst == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gst\" %f;\n", gst);
	}
	void setUParameter(double upr)
	{
		if(upr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".upr\" %f;\n", upr);
	}
	void setUDistance(double udi)
	{
		if(udi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".udi\" %f;\n", udi);
	}
	void getCurveIndices(size_t cin_i)const
	{
		fprintf(mFile,"\"%s.cin[%i]\"",mName.c_str(),cin_i);
	}
	void getCurveIndices()const
	{

		fprintf(mFile,"\"%s.cin\"",mName.c_str());
	}
	void getConstraintMethod()const
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());
	}
	void getPointMethod()const
	{
		fprintf(mFile,"\"%s.pmt\"",mName.c_str());
	}
	void getStiffness()const
	{
		fprintf(mFile,"\"%s.stf\"",mName.c_str());
	}
	void getGlueStrength()const
	{
		fprintf(mFile,"\"%s.gst\"",mName.c_str());
	}
	void getUParameter()const
	{
		fprintf(mFile,"\"%s.upr\"",mName.c_str());
	}
	void getUDistance()const
	{
		fprintf(mFile,"\"%s.udi\"",mName.c_str());
	}
	void getOutPin(size_t opn_i)const
	{
		fprintf(mFile,"\"%s.opn[%i]\"",mName.c_str(),opn_i);
	}
	void getOutPin()const
	{

		fprintf(mFile,"\"%s.opn\"",mName.c_str());
	}
protected:
	HairConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HAIRCONSTRAINT_H__
