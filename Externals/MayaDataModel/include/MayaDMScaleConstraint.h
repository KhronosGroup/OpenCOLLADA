/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SCALECONSTRAINT_H__
#define __MayaDM_SCALECONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
class ScaleConstraint : public Constraint
{
public:
	struct Target{
		double3 targetScale;
		matrix targetParentMatrix;
		double targetWeight;
		void write(FILE* file) const
		{
			targetScale.write(file);
			fprintf(file, " ");
			targetParentMatrix.write(file);
			fprintf(file, " ");
			fprintf(file,"%f", targetWeight);
		}
	};
public:

	ScaleConstraint():Constraint(){}
	ScaleConstraint(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Constraint(file, name, parent, "scaleConstraint", shared, create){}
	virtual ~ScaleConstraint(){}

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
	void setOffset(const double3& o)
	{
		fprintf(mFile,"\tsetAttr \".o\" -type \"double3\" ");
		o.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOffsetX(double ox)
	{
		if(ox == 1.0) return;
		fprintf(mFile,"\tsetAttr \".o.ox\" %f;\n", ox);
	}
	void setOffsetY(double oy)
	{
		if(oy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".o.oy\" %f;\n", oy);
	}
	void setOffsetZ(double oz)
	{
		if(oz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".o.oz\" %f;\n", oz);
	}
	void getTarget(size_t tg_i)const
	{
		fprintf(mFile,"\"%s.tg[%i]\"",mName.c_str(),tg_i);
	}
	void getTarget()const
	{

		fprintf(mFile,"\"%s.tg\"",mName.c_str());
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
	void getConstraintScale()const
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
	void getConstraintScaleX()const
	{
		fprintf(mFile,"\"%s.cs.csx\"",mName.c_str());
	}
	void getConstraintScaleY()const
	{
		fprintf(mFile,"\"%s.cs.csy\"",mName.c_str());
	}
	void getConstraintScaleZ()const
	{
		fprintf(mFile,"\"%s.cs.csz\"",mName.c_str());
	}
	void getRestScale()const
	{
		fprintf(mFile,"\"%s.rs\"",mName.c_str());
	}
	void getRestScaleX()const
	{
		fprintf(mFile,"\"%s.rs.rsx\"",mName.c_str());
	}
	void getRestScaleY()const
	{
		fprintf(mFile,"\"%s.rs.rsy\"",mName.c_str());
	}
	void getRestScaleZ()const
	{
		fprintf(mFile,"\"%s.rs.rsz\"",mName.c_str());
	}
protected:
	ScaleConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Constraint(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SCALECONSTRAINT_H__
