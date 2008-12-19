/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	HairConstraint(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "hairConstraint"){}
	virtual ~HairConstraint(){}
	void setCurveIndices(size_t cin_i,int cin)
	{
		if(cin == 0) return;
		fprintf(mFile,"setAttr \".cin[%i]\" %i;\n", cin_i,cin);

	}
	void setConstraintMethod(unsigned int cm)
	{
		if(cm == 1) return;
		fprintf(mFile,"setAttr \".cm\" %i;\n", cm);

	}
	void setPointMethod(unsigned int pmt)
	{
		if(pmt == 0) return;
		fprintf(mFile,"setAttr \".pmt\" %i;\n", pmt);

	}
	void setStiffness(double stf)
	{
		if(stf == 0.5) return;
		fprintf(mFile,"setAttr \".stf\" %f;\n", stf);

	}
	void setGlueStrength(double gst)
	{
		if(gst == 1.0) return;
		fprintf(mFile,"setAttr \".gst\" %f;\n", gst);

	}
	void setUParameter(double upr)
	{
		if(upr == 1.0) return;
		fprintf(mFile,"setAttr \".upr\" %f;\n", upr);

	}
	void setUDistance(double udi)
	{
		if(udi == 1.0) return;
		fprintf(mFile,"setAttr \".udi\" %f;\n", udi);

	}
	void getCurveIndices(size_t cin_i)
	{
		fprintf(mFile,"\"%s.cin[%i]\"",mName.c_str(),cin_i);

	}
	void getConstraintMethod()
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());

	}
	void getPointMethod()
	{
		fprintf(mFile,"\"%s.pmt\"",mName.c_str());

	}
	void getStiffness()
	{
		fprintf(mFile,"\"%s.stf\"",mName.c_str());

	}
	void getGlueStrength()
	{
		fprintf(mFile,"\"%s.gst\"",mName.c_str());

	}
	void getUParameter()
	{
		fprintf(mFile,"\"%s.upr\"",mName.c_str());

	}
	void getUDistance()
	{
		fprintf(mFile,"\"%s.udi\"",mName.c_str());

	}
	void getOutPin(size_t opn_i)
	{
		fprintf(mFile,"\"%s.opn[%i]\"",mName.c_str(),opn_i);

	}
protected:
	HairConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HAIRCONSTRAINT_H__
