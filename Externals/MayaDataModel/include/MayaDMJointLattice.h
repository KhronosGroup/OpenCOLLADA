/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_JOINTLATTICE_H__
#define __MayaDM_JOINTLATTICE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class JointLattice : public GeometryFilter
{
public:
public:

	JointLattice():GeometryFilter(){}
	JointLattice(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, "jointLattice", shared, create){}
	virtual ~JointLattice(){}

	void setCreasing(double cr)
	{
		if(cr == 0) return;
		fprintf(mFile,"\tsetAttr \".cr\" %f;\n", cr);
	}
	void setRounding(double ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"\tsetAttr \".ro\" %f;\n", ro);
	}
	void setLengthIn(double li)
	{
		if(li == 0) return;
		fprintf(mFile,"\tsetAttr \".li\" %f;\n", li);
	}
	void setLengthOut(double lo)
	{
		if(lo == 0) return;
		fprintf(mFile,"\tsetAttr \".lo\" %f;\n", lo);
	}
	void setWidthLeft(double wl)
	{
		if(wl == 0) return;
		fprintf(mFile,"\tsetAttr \".wl\" %f;\n", wl);
	}
	void setWidthRight(double wr)
	{
		if(wr == 0) return;
		fprintf(mFile,"\tsetAttr \".wr\" %f;\n", wr);
	}
	void setUpperMatrix(const matrix& um)
	{
		if(um == identity) return;
		fprintf(mFile,"\tsetAttr \".um\" -type \"matrix\" ");
		um.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLowerMatrix(const matrix& lm)
	{
		if(lm == identity) return;
		fprintf(mFile,"\tsetAttr \".lm\" -type \"matrix\" ");
		lm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInitialUpperMatrix(const matrix& iu)
	{
		if(iu == identity) return;
		fprintf(mFile,"\tsetAttr \".iu\" -type \"matrix\" ");
		iu.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInitialLowerMatrix(const matrix& il)
	{
		if(il == identity) return;
		fprintf(mFile,"\tsetAttr \".il\" -type \"matrix\" ");
		il.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDeformedLatticeMatrix(const matrix& md)
	{
		if(md == identity) return;
		fprintf(mFile,"\tsetAttr \".md\" -type \"matrix\" ");
		md.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBaseLatticeMatrix(const matrix& mb)
	{
		if(mb == identity) return;
		fprintf(mFile,"\tsetAttr \".mb\" -type \"matrix\" ");
		mb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBendVector(const float3& bv)
	{
		fprintf(mFile,"\tsetAttr \".bv\" -type \"float3\" ");
		bv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBendVectorX(float bx)
	{
		if(bx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bv.bx\" %f;\n", bx);
	}
	void setBendVectorY(float by)
	{
		if(by == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bv.by\" %f;\n", by);
	}
	void setBendVectorZ(float bz)
	{
		if(bz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bv.bz\" %f;\n", bz);
	}
	void setBendMagnitude(double bm)
	{
		if(bm == 0) return;
		fprintf(mFile,"\tsetAttr \".bm\" %f;\n", bm);
	}
	void getCreasing()const
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getRounding()const
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());
	}
	void getLengthIn()const
	{
		fprintf(mFile,"\"%s.li\"",mName.c_str());
	}
	void getLengthOut()const
	{
		fprintf(mFile,"\"%s.lo\"",mName.c_str());
	}
	void getWidthLeft()const
	{
		fprintf(mFile,"\"%s.wl\"",mName.c_str());
	}
	void getWidthRight()const
	{
		fprintf(mFile,"\"%s.wr\"",mName.c_str());
	}
	void getUpperMatrix()const
	{
		fprintf(mFile,"\"%s.um\"",mName.c_str());
	}
	void getLowerMatrix()const
	{
		fprintf(mFile,"\"%s.lm\"",mName.c_str());
	}
	void getInitialUpperMatrix()const
	{
		fprintf(mFile,"\"%s.iu\"",mName.c_str());
	}
	void getInitialLowerMatrix()const
	{
		fprintf(mFile,"\"%s.il\"",mName.c_str());
	}
	void getDeformedLatticeMatrix()const
	{
		fprintf(mFile,"\"%s.md\"",mName.c_str());
	}
	void getBaseLatticeMatrix()const
	{
		fprintf(mFile,"\"%s.mb\"",mName.c_str());
	}
	void getAdjustedUpperBaseLatticeMatrix()const
	{
		fprintf(mFile,"\"%s.au\"",mName.c_str());
	}
	void getAdjustedLowerBaseLatticeMatrix()const
	{
		fprintf(mFile,"\"%s.al\"",mName.c_str());
	}
	void getBendVector()const
	{
		fprintf(mFile,"\"%s.bv\"",mName.c_str());
	}
	void getBendVectorX()const
	{
		fprintf(mFile,"\"%s.bv.bx\"",mName.c_str());
	}
	void getBendVectorY()const
	{
		fprintf(mFile,"\"%s.bv.by\"",mName.c_str());
	}
	void getBendVectorZ()const
	{
		fprintf(mFile,"\"%s.bv.bz\"",mName.c_str());
	}
	void getBendMagnitude()const
	{
		fprintf(mFile,"\"%s.bm\"",mName.c_str());
	}
protected:
	JointLattice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_JOINTLATTICE_H__
