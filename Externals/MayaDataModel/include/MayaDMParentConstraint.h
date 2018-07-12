/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARENTCONSTRAINT_H__
#define __MayaDM_PARENTCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
class ParentConstraint : public Constraint
{
public:
	struct Target{
		matrix targetParentMatrix;
		double targetWeight;
		double3 targetRotateCached;
		double3 targetTranslate;
		double3 targetRotatePivot;
		double3 targetRotateTranslate;
		double3 targetOffsetTranslate;
		double3 targetRotate;
		unsigned int targetRotateOrder;
		double3 targetJointOrient;
		double3 targetOffsetRotate;
		double3 targetScale;
		void write(FILE* file) const
		{
			targetParentMatrix.write(file);
			fprintf(file, " ");
			fprintf(file,"%f ", targetWeight);
			targetRotateCached.write(file);
			fprintf(file, " ");
			targetTranslate.write(file);
			fprintf(file, " ");
			targetRotatePivot.write(file);
			fprintf(file, " ");
			targetRotateTranslate.write(file);
			fprintf(file, " ");
			targetOffsetTranslate.write(file);
			fprintf(file, " ");
			targetRotate.write(file);
			fprintf(file, " ");
			fprintf(file,"%i ", targetRotateOrder);
			targetJointOrient.write(file);
			fprintf(file, " ");
			targetOffsetRotate.write(file);
			fprintf(file, " ");
			targetScale.write(file);
		}
	};
public:

	ParentConstraint():Constraint(){}
	ParentConstraint(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Constraint(file, name, parent, "parentConstraint", shared, create){}
	virtual ~ParentConstraint(){}

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
	void setTargetRotateCached(size_t tg_i,const double3& ctr)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i].ctr\" -type \"double3\" ",tg_i);
		ctr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetRotateCachedX(size_t tg_i,double ctrx)
	{
		if(ctrx == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].ctr.ctrx\" %f;\n", tg_i,ctrx);
	}
	void setTargetRotateCachedY(size_t tg_i,double ctry)
	{
		if(ctry == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].ctr.ctry\" %f;\n", tg_i,ctry);
	}
	void setTargetRotateCachedZ(size_t tg_i,double ctrz)
	{
		if(ctrz == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].ctr.ctrz\" %f;\n", tg_i,ctrz);
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
	void setTargetOffsetTranslate(size_t tg_i,const double3& tot)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i].tot\" -type \"double3\" ",tg_i);
		tot.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetOffsetTranslateX(size_t tg_i,double totx)
	{
		if(totx == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tot.totx\" %f;\n", tg_i,totx);
	}
	void setTargetOffsetTranslateY(size_t tg_i,double toty)
	{
		if(toty == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tot.toty\" %f;\n", tg_i,toty);
	}
	void setTargetOffsetTranslateZ(size_t tg_i,double totz)
	{
		if(totz == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tot.totz\" %f;\n", tg_i,totz);
	}
	void setTargetRotate(size_t tg_i,const double3& tr)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i].tr\" -type \"double3\" ",tg_i);
		tr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetRotateX(size_t tg_i,double trx)
	{
		if(trx == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tr.trx\" %f;\n", tg_i,trx);
	}
	void setTargetRotateY(size_t tg_i,double try_)
	{
		if(try_ == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tr.try\" %f;\n", tg_i,try_);
	}
	void setTargetRotateZ(size_t tg_i,double trz)
	{
		if(trz == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tr.trz\" %f;\n", tg_i,trz);
	}
	void setTargetRotateOrder(size_t tg_i,unsigned int tro)
	{
		if(tro == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tro\" %i;\n", tg_i,tro);
	}
	void setTargetJointOrient(size_t tg_i,const double3& tjo)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i].tjo\" -type \"double3\" ",tg_i);
		tjo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetJointOrientX(size_t tg_i,double tjox)
	{
		if(tjox == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tjo.tjox\" %f;\n", tg_i,tjox);
	}
	void setTargetJointOrientY(size_t tg_i,double tjoy)
	{
		if(tjoy == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tjo.tjoy\" %f;\n", tg_i,tjoy);
	}
	void setTargetJointOrientZ(size_t tg_i,double tjoz)
	{
		if(tjoz == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tjo.tjoz\" %f;\n", tg_i,tjoz);
	}
	void setTargetOffsetRotate(size_t tg_i,const double3& tor)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i].tor\" -type \"double3\" ",tg_i);
		tor.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetOffsetRotateX(size_t tg_i,double torx)
	{
		if(torx == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tor.torx\" %f;\n", tg_i,torx);
	}
	void setTargetOffsetRotateY(size_t tg_i,double tory)
	{
		if(tory == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tor.tory\" %f;\n", tg_i,tory);
	}
	void setTargetOffsetRotateZ(size_t tg_i,double torz)
	{
		if(torz == 0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].tor.torz\" %f;\n", tg_i,torz);
	}
	void setTargetScale(size_t tg_i,const double3& ts)
	{
		fprintf(mFile,"\tsetAttr \".tg[%i].ts\" -type \"double3\" ",tg_i);
		ts.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetScaleX(size_t tg_i,double tsx)
	{
		if(tsx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].ts.tsx\" %f;\n", tg_i,tsx);
	}
	void setTargetScaleY(size_t tg_i,double tsy)
	{
		if(tsy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].ts.tsy\" %f;\n", tg_i,tsy);
	}
	void setTargetScaleZ(size_t tg_i,double tsz)
	{
		if(tsz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tg[%i].ts.tsz\" %f;\n", tg_i,tsz);
	}
	void setConstraintParentInverseMatrix(const matrix& cpim)
	{
		if(cpim == identity) return;
		fprintf(mFile,"\tsetAttr \".cpim\" -type \"matrix\" ");
		cpim.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLastTargetRotate(const double3& lr)
	{
		fprintf(mFile,"\tsetAttr \".lr\" -type \"double3\" ");
		lr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLastTargetRotateX(double lrx)
	{
		if(lrx == 0) return;
		fprintf(mFile,"\tsetAttr \".lr.lrx\" %f;\n", lrx);
	}
	void setLastTargetRotateY(double lry)
	{
		if(lry == 0) return;
		fprintf(mFile,"\tsetAttr \".lr.lry\" %f;\n", lry);
	}
	void setLastTargetRotateZ(double lrz)
	{
		if(lrz == 0) return;
		fprintf(mFile,"\tsetAttr \".lr.lrz\" %f;\n", lrz);
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
	void setInterpType(unsigned int int_)
	{
		if(int_ == 1) return;
		fprintf(mFile,"\tsetAttr \".int\" %i;\n", int_);
	}
	void setInterpCache(int inc)
	{
		if(inc == 0) return;
		fprintf(mFile,"\tsetAttr \".inc\" %i;\n", inc);
	}
	void getTarget(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i]\"",mName.c_str(),tg_i);
	}
	void getTarget()const
	{

		fprintf(mFile,"\"%s.tg\"",mName.c_str());
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
	void getTargetRotateCached(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].ctr\"",mName.c_str(),tg_i);
	}
	void getTargetRotateCached()const
	{

		fprintf(mFile,"\"%s.tg.ctr\"",mName.c_str());
	}
	void getTargetRotateCachedX(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].ctr.ctrx\"",mName.c_str(),tg_i);
	}
	void getTargetRotateCachedX()const
	{

		fprintf(mFile,"\"%s.tg.ctr.ctrx\"",mName.c_str());
	}
	void getTargetRotateCachedY(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].ctr.ctry\"",mName.c_str(),tg_i);
	}
	void getTargetRotateCachedY()const
	{

		fprintf(mFile,"\"%s.tg.ctr.ctry\"",mName.c_str());
	}
	void getTargetRotateCachedZ(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].ctr.ctrz\"",mName.c_str(),tg_i);
	}
	void getTargetRotateCachedZ()const
	{

		fprintf(mFile,"\"%s.tg.ctr.ctrz\"",mName.c_str());
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
	void getTargetOffsetTranslate(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tot\"",mName.c_str(),tg_i);
	}
	void getTargetOffsetTranslate()const
	{

		fprintf(mFile,"\"%s.tg.tot\"",mName.c_str());
	}
	void getTargetOffsetTranslateX(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tot.totx\"",mName.c_str(),tg_i);
	}
	void getTargetOffsetTranslateX()const
	{

		fprintf(mFile,"\"%s.tg.tot.totx\"",mName.c_str());
	}
	void getTargetOffsetTranslateY(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tot.toty\"",mName.c_str(),tg_i);
	}
	void getTargetOffsetTranslateY()const
	{

		fprintf(mFile,"\"%s.tg.tot.toty\"",mName.c_str());
	}
	void getTargetOffsetTranslateZ(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tot.totz\"",mName.c_str(),tg_i);
	}
	void getTargetOffsetTranslateZ()const
	{

		fprintf(mFile,"\"%s.tg.tot.totz\"",mName.c_str());
	}
	void getTargetRotate(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tr\"",mName.c_str(),tg_i);
	}
	void getTargetRotate()const
	{

		fprintf(mFile,"\"%s.tg.tr\"",mName.c_str());
	}
	void getTargetRotateX(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tr.trx\"",mName.c_str(),tg_i);
	}
	void getTargetRotateX()const
	{

		fprintf(mFile,"\"%s.tg.tr.trx\"",mName.c_str());
	}
	void getTargetRotateY(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tr.try\"",mName.c_str(),tg_i);
	}
	void getTargetRotateY()const
	{

		fprintf(mFile,"\"%s.tg.tr.try\"",mName.c_str());
	}
	void getTargetRotateZ(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tr.trz\"",mName.c_str(),tg_i);
	}
	void getTargetRotateZ()const
	{

		fprintf(mFile,"\"%s.tg.tr.trz\"",mName.c_str());
	}
	void getTargetRotateOrder(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tro\"",mName.c_str(),tg_i);
	}
	void getTargetRotateOrder()const
	{

		fprintf(mFile,"\"%s.tg.tro\"",mName.c_str());
	}
	void getTargetJointOrient(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tjo\"",mName.c_str(),tg_i);
	}
	void getTargetJointOrient()const
	{

		fprintf(mFile,"\"%s.tg.tjo\"",mName.c_str());
	}
	void getTargetJointOrientX(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tjo.tjox\"",mName.c_str(),tg_i);
	}
	void getTargetJointOrientX()const
	{

		fprintf(mFile,"\"%s.tg.tjo.tjox\"",mName.c_str());
	}
	void getTargetJointOrientY(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tjo.tjoy\"",mName.c_str(),tg_i);
	}
	void getTargetJointOrientY()const
	{

		fprintf(mFile,"\"%s.tg.tjo.tjoy\"",mName.c_str());
	}
	void getTargetJointOrientZ(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tjo.tjoz\"",mName.c_str(),tg_i);
	}
	void getTargetJointOrientZ()const
	{

		fprintf(mFile,"\"%s.tg.tjo.tjoz\"",mName.c_str());
	}
	void getTargetOffsetRotate(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tor\"",mName.c_str(),tg_i);
	}
	void getTargetOffsetRotate()const
	{

		fprintf(mFile,"\"%s.tg.tor\"",mName.c_str());
	}
	void getTargetOffsetRotateX(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tor.torx\"",mName.c_str(),tg_i);
	}
	void getTargetOffsetRotateX()const
	{

		fprintf(mFile,"\"%s.tg.tor.torx\"",mName.c_str());
	}
	void getTargetOffsetRotateY(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tor.tory\"",mName.c_str(),tg_i);
	}
	void getTargetOffsetRotateY()const
	{

		fprintf(mFile,"\"%s.tg.tor.tory\"",mName.c_str());
	}
	void getTargetOffsetRotateZ(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].tor.torz\"",mName.c_str(),tg_i);
	}
	void getTargetOffsetRotateZ()const
	{

		fprintf(mFile,"\"%s.tg.tor.torz\"",mName.c_str());
	}
	void getTargetScale(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].ts\"",mName.c_str(),tg_i);
	}
	void getTargetScale()const
	{

		fprintf(mFile,"\"%s.tg.ts\"",mName.c_str());
	}
	void getTargetScaleX(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].ts.tsx\"",mName.c_str(),tg_i);
	}
	void getTargetScaleX()const
	{

		fprintf(mFile,"\"%s.tg.ts.tsx\"",mName.c_str());
	}
	void getTargetScaleY(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].ts.tsy\"",mName.c_str(),tg_i);
	}
	void getTargetScaleY()const
	{

		fprintf(mFile,"\"%s.tg.ts.tsy\"",mName.c_str());
	}
	void getTargetScaleZ(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i].ts.tsz\"",mName.c_str(),tg_i);
	}
	void getTargetScaleZ()const
	{

		fprintf(mFile,"\"%s.tg.ts.tsz\"",mName.c_str());
	}
	void getConstraintParentInverseMatrix()const
	{
		fprintf(mFile,"\"%s.cpim\"",mName.c_str());
	}
	void getLastTargetRotate()const
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());
	}
	void getLastTargetRotateX()const
	{
		fprintf(mFile,"\"%s.lr.lrx\"",mName.c_str());
	}
	void getLastTargetRotateY()const
	{
		fprintf(mFile,"\"%s.lr.lry\"",mName.c_str());
	}
	void getLastTargetRotateZ()const
	{
		fprintf(mFile,"\"%s.lr.lrz\"",mName.c_str());
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
	void getRestTranslate()const
	{
		fprintf(mFile,"\"%s.rst\"",mName.c_str());
	}
	void getRestTranslateX()const
	{
		fprintf(mFile,"\"%s.rst.rtx\"",mName.c_str());
	}
	void getRestTranslateY()const
	{
		fprintf(mFile,"\"%s.rst.rty\"",mName.c_str());
	}
	void getRestTranslateZ()const
	{
		fprintf(mFile,"\"%s.rst.rtz\"",mName.c_str());
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
	void getInterpType()const
	{
		fprintf(mFile,"\"%s.int\"",mName.c_str());
	}
	void getInterpCache()const
	{
		fprintf(mFile,"\"%s.inc\"",mName.c_str());
	}
protected:
	ParentConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Constraint(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARENTCONSTRAINT_H__
