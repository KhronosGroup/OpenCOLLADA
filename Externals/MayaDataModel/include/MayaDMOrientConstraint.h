/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ORIENTCONSTRAINT_H__
#define __MayaDM_ORIENTCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
class OrientConstraint : public Constraint
{
public:
	struct Target{
		double3 targetRotate;
		unsigned int targetRotateOrder;
		double3 targetJointOrient;
		matrix targetParentMatrix;
		double targetWeight;
		double3 targetRotateCached;
		void write(FILE* file) const
		{
			targetRotate.write(file);
			fprintf(file, " ");
			fprintf(file,"%i ", targetRotateOrder);
			targetJointOrient.write(file);
			fprintf(file, " ");
			targetParentMatrix.write(file);
			fprintf(file, " ");
			fprintf(file,"%f ", targetWeight);
			targetRotateCached.write(file);
		}
	};
public:

	OrientConstraint():Constraint(){}
	OrientConstraint(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Constraint(file, name, parent, "orientConstraint", shared, create){}
	virtual ~OrientConstraint(){}

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
	void setConstraintParentInverseMatrix(const matrix& cpim)
	{
		if(cpim == identity) return;
		fprintf(mFile,"\tsetAttr \".cpim\" -type \"matrix\" ");
		cpim.write(mFile);
		fprintf(mFile,";\n");
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
	void getConstraintParentInverseMatrix()const
	{
		fprintf(mFile,"\"%s.cpim\"",mName.c_str());
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
	void getInterpType()const
	{
		fprintf(mFile,"\"%s.int\"",mName.c_str());
	}
	void getInterpCache()const
	{
		fprintf(mFile,"\"%s.inc\"",mName.c_str());
	}
	void getUseOldOffsetCalculation()const
	{
		fprintf(mFile,"\"%s.uooc\"",mName.c_str());
	}
protected:
	OrientConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Constraint(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ORIENTCONSTRAINT_H__
