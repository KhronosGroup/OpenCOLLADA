/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LEASTSQUARESMODIFIER_H__
#define __MayaDM_LEASTSQUARESMODIFIER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class LeastSquaresModifier : public AbstractBaseCreate
{
public:
	struct AttributeCollection{
		matrix worldSpaceToObjectSpace;
		struct PointConstraint{
			double3 pointPositionXYZ;
			double3 pointConstraintUVW;
			double pointWeight;
			void write(FILE* file) const
			{
				pointPositionXYZ.write(file);
				fprintf(file, " ");
				pointConstraintUVW.write(file);
				fprintf(file, " ");
				fprintf(file,"%f", pointWeight);
			}
		}* pointConstraint;
		size_t nbPointConstraint;
		void write(FILE* file) const
		{
			worldSpaceToObjectSpace.write(file);
			fprintf(file, " ");
			for (size_t i = 0; i<nbPointConstraint; ++i)
			{
				pointConstraint[i].write(file);
				fprintf(file, " ");
				if (i + 1<nbPointConstraint) fprintf(file, " ");
			}
		}
	};
	struct PointSymbolicIndex{
	};
public:

	LeastSquaresModifier():AbstractBaseCreate(){}
	LeastSquaresModifier(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "leastSquaresModifier", shared, create){}
	virtual ~LeastSquaresModifier(){}

	void setAttributeCollection(const AttributeCollection& ac)
	{
		fprintf(mFile,"\tsetAttr \".ac\" ");
		ac.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWorldSpaceToObjectSpace(const matrix& wto)
	{
		if(wto == identity) return;
		fprintf(mFile,"\tsetAttr \".ac.wto\" -type \"matrix\" ");
		wto.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointConstraint(size_t pc_i,const AttributeCollection::PointConstraint& pc)
	{
		fprintf(mFile,"\tsetAttr \".ac.pc[%i]\" ",pc_i);
		pc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointConstraint(size_t pc_start,size_t pc_end,AttributeCollection::PointConstraint* pc)
	{
		fprintf(mFile,"\tsetAttr \".ac.pc[%i:%i]\" ", pc_start,pc_end);
		size_t size = (pc_end-pc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			pc[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startPointConstraint(size_t pc_start,size_t pc_end)const
	{
		fprintf(mFile,"\tsetAttr \".ac.pc[%i:%i]\"",pc_start,pc_end);
		fprintf(mFile," -type \"AttributeCollection::PointConstraint\" ");
	}
	void appendPointConstraint(const AttributeCollection::PointConstraint& pc)const
	{
		fprintf(mFile," ");
		pc.write(mFile);
	}
	void endPointConstraint()const
	{
		fprintf(mFile,";\n");
	}
	void setPointPositionXYZ(size_t pc_i,const double3& xyz)
	{
		fprintf(mFile,"\tsetAttr \".ac.pc[%i].xyz\" -type \"double3\" ",pc_i);
		xyz.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointPositionX(size_t pc_i,double ppx)
	{
		if(ppx == 1) return;
		fprintf(mFile,"\tsetAttr \".ac.pc[%i].xyz.ppx\" %f;\n", pc_i,ppx);
	}
	void setPointPositionY(size_t pc_i,double ppy)
	{
		if(ppy == 1) return;
		fprintf(mFile,"\tsetAttr \".ac.pc[%i].xyz.ppy\" %f;\n", pc_i,ppy);
	}
	void setPointPositionZ(size_t pc_i,double ppz)
	{
		if(ppz == 1) return;
		fprintf(mFile,"\tsetAttr \".ac.pc[%i].xyz.ppz\" %f;\n", pc_i,ppz);
	}
	void setPointConstraintUVW(size_t pc_i,const double3& puv)
	{
		fprintf(mFile,"\tsetAttr \".ac.pc[%i].puv\" -type \"double3\" ",pc_i);
		puv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointConstraintU(size_t pc_i,double pcu)
	{
		if(pcu == -100000.0) return;
		fprintf(mFile,"\tsetAttr \".ac.pc[%i].puv.pcu\" %f;\n", pc_i,pcu);
	}
	void setPointConstraintV(size_t pc_i,double pcv)
	{
		if(pcv == -100000.0) return;
		fprintf(mFile,"\tsetAttr \".ac.pc[%i].puv.pcv\" %f;\n", pc_i,pcv);
	}
	void setPointConstraintW(size_t pc_i,double pcw)
	{
		if(pcw == -100000.0) return;
		fprintf(mFile,"\tsetAttr \".ac.pc[%i].puv.pcw\" %f;\n", pc_i,pcw);
	}
	void setPointWeight(size_t pc_i,double pw)
	{
		if(pw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ac.pc[%i].pw\" %f;\n", pc_i,pw);
	}
	void getInputNurbsObject()const
	{
		fprintf(mFile,"\"%s.ac.ino\"",mName.c_str());
	}
	void getWorldSpaceToObjectSpace()const
	{
		fprintf(mFile,"\"%s.ac.wto\"",mName.c_str());
	}
	void getPointPositionXYZ(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.ac.pc[%i].xyz\"",mName.c_str(),pc_i);
	}
	void getPointPositionX(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.ac.pc[%i].xyz.ppx\"",mName.c_str(),pc_i);
	}
	void getPointPositionY(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.ac.pc[%i].xyz.ppy\"",mName.c_str(),pc_i);
	}
	void getPointPositionZ(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.ac.pc[%i].xyz.ppz\"",mName.c_str(),pc_i);
	}
	void getPointConstraintUVW(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.ac.pc[%i].puv\"",mName.c_str(),pc_i);
	}
	void getPointConstraintU(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.ac.pc[%i].puv.pcu\"",mName.c_str(),pc_i);
	}
	void getPointConstraintV(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.ac.pc[%i].puv.pcv\"",mName.c_str(),pc_i);
	}
	void getPointConstraintW(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.ac.pc[%i].puv.pcw\"",mName.c_str(),pc_i);
	}
	void getPointWeight(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.ac.pc[%i].pw\"",mName.c_str(),pc_i);
	}
	void getOutputNurbsObject()const
	{
		fprintf(mFile,"\"%s.ac.ono\"",mName.c_str());
	}
protected:
	LeastSquaresModifier(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LEASTSQUARESMODIFIER_H__
