/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLOW_H__
#define __MayaDM_FLOW_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Flow : public DependNode
{
public:
public:
	Flow():DependNode(){}
	Flow(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "flow"){}
	virtual ~Flow(){}
	void setLatticeOnObject(bool lo)
	{
		if(lo == false) return;
		fprintf(mFile,"\tsetAttr \".lo\" %i;\n", lo);

	}
	void setParmValue(double pv)
	{
		if(pv == 0) return;
		fprintf(mFile,"\tsetAttr \".pv\" %f;\n", pv);

	}
	void setSDivisions(short sdv)
	{
		if(sdv == 2) return;
		fprintf(mFile,"\tsetAttr \".sdv\" %i;\n", sdv);

	}
	void setTDivisions(short tdv)
	{
		if(tdv == 5) return;
		fprintf(mFile,"\tsetAttr \".tdv\" %i;\n", tdv);

	}
	void setUDivisions(short udv)
	{
		if(udv == 2) return;
		fprintf(mFile,"\tsetAttr \".udv\" %i;\n", udv);

	}
	void setInBaseMatrix(const matrix& ibm)
	{
		if(ibm == identity) return;
		fprintf(mFile,"\tsetAttr \".ibm\" -type \"matrix\" ");
		ibm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDefMatrixInv(const matrix& dmi)
	{
		if(dmi == identity) return;
		fprintf(mFile,"\tsetAttr \".dmi\" -type \"matrix\" ");
		dmi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSetFrontAxis(unsigned int sfa)
	{
		if(sfa == 1) return;
		fprintf(mFile,"\tsetAttr \".sfa\" %i;\n", sfa);

	}
	void setSetUpAxis(unsigned int sua)
	{
		if(sua == 2) return;
		fprintf(mFile,"\tsetAttr \".sua\" %i;\n", sua);

	}
	void setOrientMatrix(const matrix& omx)
	{
		if(omx == identity) return;
		fprintf(mFile,"\tsetAttr \".omx\" -type \"matrix\" ");
		omx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAllCoords(const double3& ac)
	{
		if(ac == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".ac\" -type \"double3\" ");
		ac.write(mFile);
		fprintf(mFile,";\n");

	}
	void setXCoord(double xc)
	{
		if(xc == 0) return;
		fprintf(mFile,"\tsetAttr \".ac.xc\" %f;\n", xc);

	}
	void setYCoord(double yc)
	{
		if(yc == 0) return;
		fprintf(mFile,"\tsetAttr \".ac.yc\" %f;\n", yc);

	}
	void setZCoord(double zc)
	{
		if(zc == 0) return;
		fprintf(mFile,"\tsetAttr \".ac.zc\" %f;\n", zc);

	}
	void setCenter(size_t ctr_i,const double3& ctr)
	{
		if(ctr == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".ctr[%i]\" -type \"double3\" ",ctr_i);
		ctr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCenter(size_t ctr_start,size_t ctr_end,double* ctr)
	{
		fprintf(mFile,"\tsetAttr \".ctr[%i:%i]\" ", ctr_start,ctr_end);
		size_t size = (ctr_end-ctr_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ctr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startCenter(size_t ctr_start,size_t ctr_end)
	{
		fprintf(mFile,"\tsetAttr \".ctr[%i:%i]\"",ctr_start,ctr_end);

	}
	void appendCenter(double ctr)
	{
		fprintf(mFile," %f",ctr);

	}
	void endCenter()
	{
		fprintf(mFile,";\n");

	}
	void setCenterX(size_t ctr_i,double ctx)
	{
		if(ctx == 0) return;
		fprintf(mFile,"\tsetAttr \".ctr[%i].ctx\" %f;\n", ctr_i,ctx);

	}
	void setCenterY(size_t ctr_i,double cty)
	{
		if(cty == 0) return;
		fprintf(mFile,"\tsetAttr \".ctr[%i].cty\" %f;\n", ctr_i,cty);

	}
	void setCenterZ(size_t ctr_i,double ctz)
	{
		if(ctz == 0) return;
		fprintf(mFile,"\tsetAttr \".ctr[%i].ctz\" %f;\n", ctr_i,ctz);

	}
	void setObjectWorldMatrix(size_t owmx_i,const matrix& owmx)
	{
		if(owmx == identity) return;
		fprintf(mFile,"\tsetAttr \".owmx[%i]\" -type \"matrix\" ",owmx_i);
		owmx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setObjectWorldMatrix(size_t owmx_start,size_t owmx_end,matrix* owmx)
	{
		fprintf(mFile,"\tsetAttr \".owmx[%i:%i]\" ", owmx_start,owmx_end);
		size_t size = (owmx_end-owmx_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			owmx[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startObjectWorldMatrix(size_t owmx_start,size_t owmx_end)
	{
		fprintf(mFile,"\tsetAttr \".owmx[%i:%i]\"",owmx_start,owmx_end);
		fprintf(mFile," -type \"matrix\" ");

	}
	void appendObjectWorldMatrix(const matrix& owmx)
	{
		fprintf(mFile,"\n");
		owmx.write(mFile);

	}
	void endObjectWorldMatrix()
	{
		fprintf(mFile,";\n");

	}
	void getMotionPath()
	{
		fprintf(mFile,"\"%s.mp\"",mName.c_str());

	}
	void getCurve()
	{
		fprintf(mFile,"\"%s.crv\"",mName.c_str());

	}
	void getParmValue()
	{
		fprintf(mFile,"\"%s.pv\"",mName.c_str());

	}
	void getSDivisions()
	{
		fprintf(mFile,"\"%s.sdv\"",mName.c_str());

	}
	void getTDivisions()
	{
		fprintf(mFile,"\"%s.tdv\"",mName.c_str());

	}
	void getUDivisions()
	{
		fprintf(mFile,"\"%s.udv\"",mName.c_str());

	}
	void getInBaseMatrix()
	{
		fprintf(mFile,"\"%s.ibm\"",mName.c_str());

	}
	void getDefMatrixInv()
	{
		fprintf(mFile,"\"%s.dmi\"",mName.c_str());

	}
	void getSetFrontAxis()
	{
		fprintf(mFile,"\"%s.sfa\"",mName.c_str());

	}
	void getSetUpAxis()
	{
		fprintf(mFile,"\"%s.sua\"",mName.c_str());

	}
	void getOrientMatrix()
	{
		fprintf(mFile,"\"%s.omx\"",mName.c_str());

	}
	void getAllCoords()
	{
		fprintf(mFile,"\"%s.ac\"",mName.c_str());

	}
	void getXCoord()
	{
		fprintf(mFile,"\"%s.ac.xc\"",mName.c_str());

	}
	void getYCoord()
	{
		fprintf(mFile,"\"%s.ac.yc\"",mName.c_str());

	}
	void getZCoord()
	{
		fprintf(mFile,"\"%s.ac.zc\"",mName.c_str());

	}
	void getCenter(size_t ctr_i)
	{
		fprintf(mFile,"\"%s.ctr[%i]\"",mName.c_str(),ctr_i);

	}
	void getCenterX(size_t ctr_i)
	{
		fprintf(mFile,"\"%s.ctr[%i].ctx\"",mName.c_str(),ctr_i);

	}
	void getCenterY(size_t ctr_i)
	{
		fprintf(mFile,"\"%s.ctr[%i].cty\"",mName.c_str(),ctr_i);

	}
	void getCenterZ(size_t ctr_i)
	{
		fprintf(mFile,"\"%s.ctr[%i].ctz\"",mName.c_str(),ctr_i);

	}
	void getObjectWorldMatrix(size_t owmx_i)
	{
		fprintf(mFile,"\"%s.owmx[%i]\"",mName.c_str(),owmx_i);

	}
	void getOutBaseMatrix()
	{
		fprintf(mFile,"\"%s.obm\"",mName.c_str());

	}
	void getDefPts()
	{
		fprintf(mFile,"\"%s.dpt\"",mName.c_str());

	}
protected:
	Flow(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FLOW_H__
