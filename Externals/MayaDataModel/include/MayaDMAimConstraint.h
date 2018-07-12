/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AIMCONSTRAINT_H__
#define __MayaDM_AIMCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
class AimConstraint : public Constraint
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

	AimConstraint():Constraint(){}
	AimConstraint(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Constraint(file, name, parent, "aimConstraint", shared, create){}
	virtual ~AimConstraint(){}

	void setTarget(size_t tg_i,const Target& tg)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i]\" ",tg_i);
		tg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTarget(size_t tg_start,size_t tg_end,Target* tg)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i:%i]\" ", tg_start,tg_end);
		size_t size = (tg_end-tg_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			tg[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startTarget(size_t tg_start,size_t tg_end)const
	{
		fprintf(mFile,"\tsetAttr \".tg[%i:%i]\"",tg_start,tg_end);
		fprintf(mFile," -type \"Target\" ");
	}
	void appendTarget(const Target& tg)const
	{
		fprintf(mFile," ");
		tg.write(mFile);
	}
	void endTarget()const
	{
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
	void setAimVector(const double3& a)
	{
		if(a == double3(1.0,0.0,0.0)) return;
		fprintf(mFile,"\tsetAttr \".a\" -type \"double3\" ");
		a.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAimVectorX(double ax)
	{
		if(ax == 1.0) return;
		fprintf(mFile,"\tsetAttr \".a.ax\" %f;\n", ax);
	}
	void setAimVectorY(double ay)
	{
		if(ay == 0.0) return;
		fprintf(mFile,"\tsetAttr \".a.ay\" %f;\n", ay);
	}
	void setAimVectorZ(double az)
	{
		if(az == 0.0) return;
		fprintf(mFile,"\tsetAttr \".a.az\" %f;\n", az);
	}
	void setUpVector(const double3& u)
	{
		if(u == double3(0.0,1.0,0.0)) return;
		fprintf(mFile,"\tsetAttr \".u\" -type \"double3\" ");
		u.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUpVectorX(double ux)
	{
		if(ux == 0.0) return;
		fprintf(mFile,"\tsetAttr \".u.ux\" %f;\n", ux);
	}
	void setUpVectorY(double uy)
	{
		if(uy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".u.uy\" %f;\n", uy);
	}
	void setUpVectorZ(double uz)
	{
		if(uz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".u.uz\" %f;\n", uz);
	}
	void setWorldUpVector(const double3& wu)
	{
		if(wu == double3(0.0,1.0,0.0)) return;
		fprintf(mFile,"\tsetAttr \".wu\" -type \"double3\" ");
		wu.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWorldUpVectorX(double wux)
	{
		if(wux == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wu.wux\" %f;\n", wux);
	}
	void setWorldUpVectorY(double wuy)
	{
		if(wuy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".wu.wuy\" %f;\n", wuy);
	}
	void setWorldUpVectorZ(double wuz)
	{
		if(wuz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wu.wuz\" %f;\n", wuz);
	}
	void setWorldUpMatrix(const matrix& wum)
	{
		if(wum == identity) return;
		fprintf(mFile,"\tsetAttr \".wum\" -type \"matrix\" ");
		wum.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWorldUpType(unsigned int wut)
	{
		if(wut == 3) return;
		fprintf(mFile,"\tsetAttr \".wut\" %i;\n", wut);
	}
	void setConstraintTranslate(const double3& ct)
	{
		fprintf(mFile,"\tsetAttr \".ct\" -type \"double3\" ");
		ct.write(mFile);
		fprintf(mFile,";\n");
	}
	void setConstraintTranslateX(double ctx)
	{
		if(ctx == 0) return;
		fprintf(mFile,"\tsetAttr \".ct.ctx\" %f;\n", ctx);
	}
	void setConstraintTranslateY(double cty)
	{
		if(cty == 0) return;
		fprintf(mFile,"\tsetAttr \".ct.cty\" %f;\n", cty);
	}
	void setConstraintTranslateZ(double ctz)
	{
		if(ctz == 0) return;
		fprintf(mFile,"\tsetAttr \".ct.ctz\" %f;\n", ctz);
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
	void setConstraintRotateOrder(unsigned int cro)
	{
		if(cro == 0) return;
		fprintf(mFile,"\tsetAttr \".cro\" %i;\n", cro);
	}
	void setConstraintJointOrient(const double3& cjo)
	{
		fprintf(mFile,"\tsetAttr \".cjo\" -type \"double3\" ");
		cjo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setConstraintJointOrientX(double cjox)
	{
		if(cjox == 0) return;
		fprintf(mFile,"\tsetAttr \".cjo.cjox\" %f;\n", cjox);
	}
	void setConstraintJointOrientY(double cjoy)
	{
		if(cjoy == 0) return;
		fprintf(mFile,"\tsetAttr \".cjo.cjoy\" %f;\n", cjoy);
	}
	void setConstraintJointOrientZ(double cjoz)
	{
		if(cjoz == 0) return;
		fprintf(mFile,"\tsetAttr \".cjo.cjoz\" %f;\n", cjoz);
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
	void setRestRotate(const double3& rsrr)
	{
		fprintf(mFile,"\tsetAttr \".rsrr\" -type \"double3\" ");
		rsrr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRestRotateX(double rrx)
	{
		if(rrx == 0) return;
		fprintf(mFile,"\tsetAttr \".rsrr.rrx\" %f;\n", rrx);
	}
	void setRestRotateY(double rry)
	{
		if(rry == 0) return;
		fprintf(mFile,"\tsetAttr \".rsrr.rry\" %f;\n", rry);
	}
	void setRestRotateZ(double rrz)
	{
		if(rrz == 0) return;
		fprintf(mFile,"\tsetAttr \".rsrr.rrz\" %f;\n", rrz);
	}
	void setUseOldOffsetCalculation(bool uooc)
	{
		if(uooc == false) return;
		fprintf(mFile,"\tsetAttr \".uooc\" %i;\n", uooc);
	}
	void getTarget(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i]\"",mName.c_str(),tg_i);
	}
	void getTarget()const
	{

		fprintf(mFile,"\"%s.tg\"",mName.c_str());
	}
	void getTargetTranslate(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tt\"",mName.c_str(),tg_i);
	}
	void getTargetTranslate()const
	{

		fprintf(mFile,"\"%s.tg.tt\"",mName.c_str());
	}
	void getTargetTranslateX(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tt.ttx\"",mName.c_str(),tg_i);
	}
	void getTargetTranslateX()const
	{

		fprintf(mFile,"\"%s.tg.tt.ttx\"",mName.c_str());
	}
	void getTargetTranslateY(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tt.tty\"",mName.c_str(),tg_i);
	}
	void getTargetTranslateY()const
	{

		fprintf(mFile,"\"%s.tg.tt.tty\"",mName.c_str());
	}
	void getTargetTranslateZ(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tt.ttz\"",mName.c_str(),tg_i);
	}
	void getTargetTranslateZ()const
	{

		fprintf(mFile,"\"%s.tg.tt.ttz\"",mName.c_str());
	}
	void getTargetRotatePivot(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].trp\"",mName.c_str(),tg_i);
	}
	void getTargetRotatePivot()const
	{

		fprintf(mFile,"\"%s.tg.trp\"",mName.c_str());
	}
	void getTargetRotatePivotX(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].trp.trpx\"",mName.c_str(),tg_i);
	}
	void getTargetRotatePivotX()const
	{

		fprintf(mFile,"\"%s.tg.trp.trpx\"",mName.c_str());
	}
	void getTargetRotatePivotY(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].trp.trpy\"",mName.c_str(),tg_i);
	}
	void getTargetRotatePivotY()const
	{

		fprintf(mFile,"\"%s.tg.trp.trpy\"",mName.c_str());
	}
	void getTargetRotatePivotZ(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].trp.trpz\"",mName.c_str(),tg_i);
	}
	void getTargetRotatePivotZ()const
	{

		fprintf(mFile,"\"%s.tg.trp.trpz\"",mName.c_str());
	}
	void getTargetRotateTranslate(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].trt\"",mName.c_str(),tg_i);
	}
	void getTargetRotateTranslate()const
	{

		fprintf(mFile,"\"%s.tg.trt\"",mName.c_str());
	}
	void getTargetRotateTranslateX(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].trt.trtx\"",mName.c_str(),tg_i);
	}
	void getTargetRotateTranslateX()const
	{

		fprintf(mFile,"\"%s.tg.trt.trtx\"",mName.c_str());
	}
	void getTargetRotateTranslateY(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].trt.trty\"",mName.c_str(),tg_i);
	}
	void getTargetRotateTranslateY()const
	{

		fprintf(mFile,"\"%s.tg.trt.trty\"",mName.c_str());
	}
	void getTargetRotateTranslateZ(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].trt.trtz\"",mName.c_str(),tg_i);
	}
	void getTargetRotateTranslateZ()const
	{

		fprintf(mFile,"\"%s.tg.trt.trtz\"",mName.c_str());
	}
	void getTargetParentMatrix(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tpm\"",mName.c_str(),tg_i);
	}
	void getTargetParentMatrix()const
	{

		fprintf(mFile,"\"%s.tg.tpm\"",mName.c_str());
	}
	void getTargetWeight(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tw\"",mName.c_str(),tg_i);
	}
	void getTargetWeight()const
	{

		fprintf(mFile,"\"%s.tg.tw\"",mName.c_str());
	}
	void getConstraintParentInverseMatrix()const
	{
		fprintf(mFile,"\"%s.cpim\"",mName.c_str());
	}
	void getAimVector()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getAimVectorX()const
	{
		fprintf(mFile,"\"%s.a.ax\"",mName.c_str());
	}
	void getAimVectorY()const
	{
		fprintf(mFile,"\"%s.a.ay\"",mName.c_str());
	}
	void getAimVectorZ()const
	{
		fprintf(mFile,"\"%s.a.az\"",mName.c_str());
	}
	void getUpVector()const
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());
	}
	void getUpVectorX()const
	{
		fprintf(mFile,"\"%s.u.ux\"",mName.c_str());
	}
	void getUpVectorY()const
	{
		fprintf(mFile,"\"%s.u.uy\"",mName.c_str());
	}
	void getUpVectorZ()const
	{
		fprintf(mFile,"\"%s.u.uz\"",mName.c_str());
	}
	void getWorldUpVector()const
	{
		fprintf(mFile,"\"%s.wu\"",mName.c_str());
	}
	void getWorldUpVectorX()const
	{
		fprintf(mFile,"\"%s.wu.wux\"",mName.c_str());
	}
	void getWorldUpVectorY()const
	{
		fprintf(mFile,"\"%s.wu.wuy\"",mName.c_str());
	}
	void getWorldUpVectorZ()const
	{
		fprintf(mFile,"\"%s.wu.wuz\"",mName.c_str());
	}
	void getWorldUpMatrix()const
	{
		fprintf(mFile,"\"%s.wum\"",mName.c_str());
	}
	void getWorldUpType()const
	{
		fprintf(mFile,"\"%s.wut\"",mName.c_str());
	}
	void getConstraintTranslate()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getConstraintTranslateX()const
	{
		fprintf(mFile,"\"%s.ct.ctx\"",mName.c_str());
	}
	void getConstraintTranslateY()const
	{
		fprintf(mFile,"\"%s.ct.cty\"",mName.c_str());
	}
	void getConstraintTranslateZ()const
	{
		fprintf(mFile,"\"%s.ct.ctz\"",mName.c_str());
	}
	void getConstraintRotatePivot()const
	{
		fprintf(mFile,"\"%s.crp\"",mName.c_str());
	}
	void getConstraintRotatePivotX()const
	{
		fprintf(mFile,"\"%s.crp.crpx\"",mName.c_str());
	}
	void getConstraintRotatePivotY()const
	{
		fprintf(mFile,"\"%s.crp.crpy\"",mName.c_str());
	}
	void getConstraintRotatePivotZ()const
	{
		fprintf(mFile,"\"%s.crp.crpz\"",mName.c_str());
	}
	void getConstraintRotateTranslate()const
	{
		fprintf(mFile,"\"%s.crt\"",mName.c_str());
	}
	void getConstraintRotateTranslateX()const
	{
		fprintf(mFile,"\"%s.crt.crtx\"",mName.c_str());
	}
	void getConstraintRotateTranslateY()const
	{
		fprintf(mFile,"\"%s.crt.crty\"",mName.c_str());
	}
	void getConstraintRotateTranslateZ()const
	{
		fprintf(mFile,"\"%s.crt.crtz\"",mName.c_str());
	}
	void getConstraintRotateOrder()const
	{
		fprintf(mFile,"\"%s.cro\"",mName.c_str());
	}
	void getConstraintJointOrient()const
	{
		fprintf(mFile,"\"%s.cjo\"",mName.c_str());
	}
	void getConstraintJointOrientX()const
	{
		fprintf(mFile,"\"%s.cjo.cjox\"",mName.c_str());
	}
	void getConstraintJointOrientY()const
	{
		fprintf(mFile,"\"%s.cjo.cjoy\"",mName.c_str());
	}
	void getConstraintJointOrientZ()const
	{
		fprintf(mFile,"\"%s.cjo.cjoz\"",mName.c_str());
	}
	void getConstraintRotate()const
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getConstraintRotateX()const
	{
		fprintf(mFile,"\"%s.cr.crx\"",mName.c_str());
	}
	void getConstraintRotateY()const
	{
		fprintf(mFile,"\"%s.cr.cry\"",mName.c_str());
	}
	void getConstraintRotateZ()const
	{
		fprintf(mFile,"\"%s.cr.crz\"",mName.c_str());
	}
	void getConstraintVector()const
	{
		fprintf(mFile,"\"%s.cv\"",mName.c_str());
	}
	void getConstraintVectorX()const
	{
		fprintf(mFile,"\"%s.cv.cvx\"",mName.c_str());
	}
	void getConstraintVectorY()const
	{
		fprintf(mFile,"\"%s.cv.cvy\"",mName.c_str());
	}
	void getConstraintVectorZ()const
	{
		fprintf(mFile,"\"%s.cv.cvz\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getOffsetX()const
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());
	}
	void getOffsetY()const
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());
	}
	void getOffsetZ()const
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());
	}
	void getRestRotate()const
	{
		fprintf(mFile,"\"%s.rsrr\"",mName.c_str());
	}
	void getRestRotateX()const
	{
		fprintf(mFile,"\"%s.rsrr.rrx\"",mName.c_str());
	}
	void getRestRotateY()const
	{
		fprintf(mFile,"\"%s.rsrr.rry\"",mName.c_str());
	}
	void getRestRotateZ()const
	{
		fprintf(mFile,"\"%s.rsrr.rrz\"",mName.c_str());
	}
	void getUseOldOffsetCalculation()const
	{
		fprintf(mFile,"\"%s.uooc\"",mName.c_str());
	}
protected:
	AimConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Constraint(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_AIMCONSTRAINT_H__
