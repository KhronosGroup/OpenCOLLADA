/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POINTCONSTRAINT_H__
#define __MayaDM_POINTCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
class PointConstraint : public Constraint
{
public:
	struct Target{
		double3 targetTranslate;
		double3 targetRotatePivot;
		double3 targetRotateTranslate;
		matrix targetParentMatrix;
		double targetWeight;
		void write(FILE* file) const
		{
			targetTranslate.write(file);
			fprintf(file, " ");
			targetRotatePivot.write(file);
			fprintf(file, " ");
			targetRotateTranslate.write(file);
			fprintf(file, " ");
			targetParentMatrix.write(file);
			fprintf(file, " ");
			fprintf(file,"%f", targetWeight);
		}
	};
public:
	PointConstraint():Constraint(){}
	PointConstraint(FILE* file,const std::string& name,const std::string& parent=""):Constraint(file, name, parent, "pointConstraint"){}
	virtual ~PointConstraint(){}
	void setTarget(size_t tg_i,const Target& tg)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i]\" ",tg_i);
		tg.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTargetTranslate(size_t tg_i,const double3& tt)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i].tt\" -type \"double3\" ",tg_i);
		tt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTargetTranslateX(size_t tg_i,double ttx)
	{
		if(ttx == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tt.ttx\" %f;\n", tg_i,ttx);

	}
	void setTargetTranslateY(size_t tg_i,double tty)
	{
		if(tty == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tt.tty\" %f;\n", tg_i,tty);

	}
	void setTargetTranslateZ(size_t tg_i,double ttz)
	{
		if(ttz == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tt.ttz\" %f;\n", tg_i,ttz);

	}
	void setTargetRotatePivot(size_t tg_i,const double3& trp)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i].trp\" -type \"double3\" ",tg_i);
		trp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTargetRotatePivotX(size_t tg_i,double trpx)
	{
		if(trpx == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].trp.trpx\" %f;\n", tg_i,trpx);

	}
	void setTargetRotatePivotY(size_t tg_i,double trpy)
	{
		if(trpy == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].trp.trpy\" %f;\n", tg_i,trpy);

	}
	void setTargetRotatePivotZ(size_t tg_i,double trpz)
	{
		if(trpz == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].trp.trpz\" %f;\n", tg_i,trpz);

	}
	void setTargetRotateTranslate(size_t tg_i,const double3& trt)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i].trt\" -type \"double3\" ",tg_i);
		trt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTargetRotateTranslateX(size_t tg_i,double trtx)
	{
		if(trtx == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].trt.trtx\" %f;\n", tg_i,trtx);

	}
	void setTargetRotateTranslateY(size_t tg_i,double trty)
	{
		if(trty == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].trt.trty\" %f;\n", tg_i,trty);

	}
	void setTargetRotateTranslateZ(size_t tg_i,double trtz)
	{
		if(trtz == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].trt.trtz\" %f;\n", tg_i,trtz);

	}
	void setTargetParentMatrix(size_t tg_i,const matrix& tpm)
	{
		if(tpm == identity) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tpm\" -type \"matrix\" ",tg_i);
		tpm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTargetWeight(size_t tg_i,double tw)
	{
		if(tw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tw\" %f;\n", tg_i,tw);

	}
	void setConstraintParentInverseMatrix(const matrix& cpim)
	{
		if(cpim == identity) return;
		fprintf(mFile,"\tsetAttr \".cpim\" -type \"matrix\" ");
		cpim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setConstraintRotatePivot(const double3& crp)
	{
		fprintf(mFile,"\tsetAttr \".crp\" -type \"double3\" ");
		crp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setConstraintRotatePivotX(double crpx)
	{
		if(crpx == 0) return;
		fprintf(mFile,"\tsetAttr \".crp.crpx\" %f;\n", crpx);

	}
	void setConstraintRotatePivotY(double crpy)
	{
		if(crpy == 0) return;
		fprintf(mFile,"\tsetAttr \".crp.crpy\" %f;\n", crpy);

	}
	void setConstraintRotatePivotZ(double crpz)
	{
		if(crpz == 0) return;
		fprintf(mFile,"\tsetAttr \".crp.crpz\" %f;\n", crpz);

	}
	void setConstraintRotateTranslate(const double3& crt)
	{
		fprintf(mFile,"\tsetAttr \".crt\" -type \"double3\" ");
		crt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setConstraintRotateTranslateX(double crtx)
	{
		if(crtx == 0) return;
		fprintf(mFile,"\tsetAttr \".crt.crtx\" %f;\n", crtx);

	}
	void setConstraintRotateTranslateY(double crty)
	{
		if(crty == 0) return;
		fprintf(mFile,"\tsetAttr \".crt.crty\" %f;\n", crty);

	}
	void setConstraintRotateTranslateZ(double crtz)
	{
		if(crtz == 0) return;
		fprintf(mFile,"\tsetAttr \".crt.crtz\" %f;\n", crtz);

	}
	void setOffset(const double3& o)
	{
		fprintf(mFile,"\tsetAttr \".o\" -type \"double3\" ");
		o.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffsetX(double ox)
	{
		if(ox == 0) return;
		fprintf(mFile,"\tsetAttr \".o.ox\" %f;\n", ox);

	}
	void setOffsetY(double oy)
	{
		if(oy == 0) return;
		fprintf(mFile,"\tsetAttr \".o.oy\" %f;\n", oy);

	}
	void setOffsetZ(double oz)
	{
		if(oz == 0) return;
		fprintf(mFile,"\tsetAttr \".o.oz\" %f;\n", oz);

	}
	void setConstraintOffsetPolarity(double cop)
	{
		if(cop == 1) return;
		fprintf(mFile,"\tsetAttr \".cop\" %f;\n", cop);

	}
	void setRestTranslate(const double3& rst)
	{
		if(rst == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".rst\" -type \"double3\" ");
		rst.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRestTranslateX(double rtx)
	{
		if(rtx == 0) return;
		fprintf(mFile,"\tsetAttr \".rst.rtx\" %f;\n", rtx);

	}
	void setRestTranslateY(double rty)
	{
		if(rty == 0) return;
		fprintf(mFile,"\tsetAttr \".rst.rty\" %f;\n", rty);

	}
	void setRestTranslateZ(double rtz)
	{
		if(rtz == 0) return;
		fprintf(mFile,"\tsetAttr \".rst.rtz\" %f;\n", rtz);

	}
	void getTarget(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i]\"",mName.c_str(),tg_i);

	}
	void getTargetTranslate(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].tt\"",mName.c_str(),tg_i);

	}
	void getTargetTranslateX(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].tt.ttx\"",mName.c_str(),tg_i);

	}
	void getTargetTranslateY(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].tt.tty\"",mName.c_str(),tg_i);

	}
	void getTargetTranslateZ(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].tt.ttz\"",mName.c_str(),tg_i);

	}
	void getTargetRotatePivot(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].trp\"",mName.c_str(),tg_i);

	}
	void getTargetRotatePivotX(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].trp.trpx\"",mName.c_str(),tg_i);

	}
	void getTargetRotatePivotY(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].trp.trpy\"",mName.c_str(),tg_i);

	}
	void getTargetRotatePivotZ(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].trp.trpz\"",mName.c_str(),tg_i);

	}
	void getTargetRotateTranslate(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].trt\"",mName.c_str(),tg_i);

	}
	void getTargetRotateTranslateX(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].trt.trtx\"",mName.c_str(),tg_i);

	}
	void getTargetRotateTranslateY(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].trt.trty\"",mName.c_str(),tg_i);

	}
	void getTargetRotateTranslateZ(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].trt.trtz\"",mName.c_str(),tg_i);

	}
	void getTargetParentMatrix(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].tpm\"",mName.c_str(),tg_i);

	}
	void getTargetWeight(size_t tg_i)
	{
		fprintf(mFile,"\"%s.tg[%i].tw\"",mName.c_str(),tg_i);

	}
	void getConstraintParentInverseMatrix()
	{
		fprintf(mFile,"\"%s.cpim\"",mName.c_str());

	}
	void getConstraintRotatePivot()
	{
		fprintf(mFile,"\"%s.crp\"",mName.c_str());

	}
	void getConstraintRotatePivotX()
	{
		fprintf(mFile,"\"%s.crp.crpx\"",mName.c_str());

	}
	void getConstraintRotatePivotY()
	{
		fprintf(mFile,"\"%s.crp.crpy\"",mName.c_str());

	}
	void getConstraintRotatePivotZ()
	{
		fprintf(mFile,"\"%s.crp.crpz\"",mName.c_str());

	}
	void getConstraintRotateTranslate()
	{
		fprintf(mFile,"\"%s.crt\"",mName.c_str());

	}
	void getConstraintRotateTranslateX()
	{
		fprintf(mFile,"\"%s.crt.crtx\"",mName.c_str());

	}
	void getConstraintRotateTranslateY()
	{
		fprintf(mFile,"\"%s.crt.crty\"",mName.c_str());

	}
	void getConstraintRotateTranslateZ()
	{
		fprintf(mFile,"\"%s.crt.crtz\"",mName.c_str());

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOffsetX()
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());

	}
	void getOffsetY()
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());

	}
	void getOffsetZ()
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());

	}
	void getConstraintOffsetPolarity()
	{
		fprintf(mFile,"\"%s.cop\"",mName.c_str());

	}
	void getConstraintTranslate()
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());

	}
	void getConstraintTranslateX()
	{
		fprintf(mFile,"\"%s.ct.ctx\"",mName.c_str());

	}
	void getConstraintTranslateY()
	{
		fprintf(mFile,"\"%s.ct.cty\"",mName.c_str());

	}
	void getConstraintTranslateZ()
	{
		fprintf(mFile,"\"%s.ct.ctz\"",mName.c_str());

	}
	void getRestTranslate()
	{
		fprintf(mFile,"\"%s.rst\"",mName.c_str());

	}
	void getRestTranslateX()
	{
		fprintf(mFile,"\"%s.rst.rtx\"",mName.c_str());

	}
	void getRestTranslateY()
	{
		fprintf(mFile,"\"%s.rst.rty\"",mName.c_str());

	}
	void getRestTranslateZ()
	{
		fprintf(mFile,"\"%s.rst.rtz\"",mName.c_str());

	}
protected:
	PointConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Constraint(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POINTCONSTRAINT_H__
