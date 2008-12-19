/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Flow(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "flow"){}
	virtual ~Flow(){}
	void setLatticeOnObject(bool lo)
	{
		if(lo == false) return;
		fprintf(mFile,"setAttr \".lo\" %i;\n", lo);

	}
	void setParmValue(double pv)
	{
		if(pv == 0) return;
		fprintf(mFile,"setAttr \".pv\" %f;\n", pv);

	}
	void setSDivisions(short sdv)
	{
		if(sdv == 2) return;
		fprintf(mFile,"setAttr \".sdv\" %i;\n", sdv);

	}
	void setTDivisions(short tdv)
	{
		if(tdv == 5) return;
		fprintf(mFile,"setAttr \".tdv\" %i;\n", tdv);

	}
	void setUDivisions(short udv)
	{
		if(udv == 2) return;
		fprintf(mFile,"setAttr \".udv\" %i;\n", udv);

	}
	void setInBaseMatrix(const matrix& ibm)
	{
		if(ibm == identity) return;
		fprintf(mFile,"setAttr \".ibm\" -type \"matrix\" ");
		ibm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDefMatrixInv(const matrix& dmi)
	{
		if(dmi == identity) return;
		fprintf(mFile,"setAttr \".dmi\" -type \"matrix\" ");
		dmi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSetFrontAxis(unsigned int sfa)
	{
		if(sfa == 1) return;
		fprintf(mFile,"setAttr \".sfa\" %i;\n", sfa);

	}
	void setSetUpAxis(unsigned int sua)
	{
		if(sua == 2) return;
		fprintf(mFile,"setAttr \".sua\" %i;\n", sua);

	}
	void setOrientMatrix(const matrix& omx)
	{
		if(omx == identity) return;
		fprintf(mFile,"setAttr \".omx\" -type \"matrix\" ");
		omx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAllCoords(const double3& ac)
	{
		if(ac == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"setAttr \".ac\" -type \"double3\" ");
		ac.write(mFile);
		fprintf(mFile,";\n");

	}
	void setXCoord(double xc)
	{
		if(xc == 0) return;
		fprintf(mFile,"setAttr \".ac.xc\" %f;\n", xc);

	}
	void setYCoord(double yc)
	{
		if(yc == 0) return;
		fprintf(mFile,"setAttr \".ac.yc\" %f;\n", yc);

	}
	void setZCoord(double zc)
	{
		if(zc == 0) return;
		fprintf(mFile,"setAttr \".ac.zc\" %f;\n", zc);

	}
	void setCenter(size_t ctr_i,const double3& ctr)
	{
		if(ctr == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"setAttr \".ctr[%i]\" -type \"double3\" ",ctr_i);
		ctr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCenter(size_t ctr_start,size_t ctr_end,double* ctr)
	{
		fprintf(mFile,"setAttr \".ctr[%i:%i]\" ", ctr_start,ctr_end);
		size_t size = (ctr_end-ctr_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ctr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void setCenterX(size_t ctr_i,double ctx)
	{
		if(ctx == 0) return;
		fprintf(mFile,"setAttr \".ctr[%i].ctx\" %f;\n", ctr_i,ctx);

	}
	void setCenterY(size_t ctr_i,double cty)
	{
		if(cty == 0) return;
		fprintf(mFile,"setAttr \".ctr[%i].cty\" %f;\n", ctr_i,cty);

	}
	void setCenterZ(size_t ctr_i,double ctz)
	{
		if(ctz == 0) return;
		fprintf(mFile,"setAttr \".ctr[%i].ctz\" %f;\n", ctr_i,ctz);

	}
	void setObjectWorldMatrix(size_t owmx_i,const matrix& owmx)
	{
		if(owmx == identity) return;
		fprintf(mFile,"setAttr \".owmx[%i]\" -type \"matrix\" ",owmx_i);
		owmx.write(mFile);
		fprintf(mFile,";\n");

	}
	void getMotionPath()
	{
		fprintf(mFile,"\"%s.mp\"",mName.c_str());

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
	void getOutBaseMatrix()
	{
		fprintf(mFile,"\"%s.obm\"",mName.c_str());

	}
	void getDefPts()
	{
		fprintf(mFile,"\"%s.dpt\"",mName.c_str());

	}
protected:
	Flow(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FLOW_H__
