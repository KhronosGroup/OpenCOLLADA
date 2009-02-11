/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GEOCONNECTOR_H__
#define __MayaDM_GEOCONNECTOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class GeoConnector : public DependNode
{
public:
	struct IdMapping{
		void write(FILE* file) const
		{
		}
	};
public:
	GeoConnector():DependNode(){}
	GeoConnector(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "geoConnector"){}
	virtual ~GeoConnector(){}
	void setWorldMatrix(const matrix& wm)
	{
		if(wm == identity) return;
		fprintf(mFile,"\tsetAttr \".wm\" -type \"matrix\" ");
		wm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGroupId(size_t gri_i,int gri)
	{
		if(gri == -1) return;
		fprintf(mFile,"\tsetAttr \".gri[%i]\" %i;\n", gri_i,gri);

	}
	void setGroupId(size_t gri_start,size_t gri_end,int* gri)
	{
		fprintf(mFile,"\tsetAttr \".gri[%i:%i]\" ", gri_start,gri_end);
		size_t size = (gri_end-gri_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",gri[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startGroupId(size_t gri_start,size_t gri_end)
	{
		fprintf(mFile,"\tsetAttr \".gri[%i:%i]\"",gri_start,gri_end);

	}
	void appendGroupId(int gri)
	{
		fprintf(mFile," %i",gri);

	}
	void endGroupId()
	{
		fprintf(mFile,";\n");

	}
	void setTessellationFactor(int tf)
	{
		if(tf == 200) return;
		fprintf(mFile,"\tsetAttr \".tf\" %i;\n", tf);

	}
	void setUvSetName(const string& guv)
	{
		if(guv == "NULL") return;
		fprintf(mFile,"\tsetAttr \".guv\" -type \"string\" ");
		guv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setResilience(double res)
	{
		if(res == 1) return;
		fprintf(mFile,"\tsetAttr \".res\" %f;\n", res);

	}
	void setFriction(double fri)
	{
		if(fri == 0) return;
		fprintf(mFile,"\tsetAttr \".fri\" %f;\n", fri);

	}
	void setOffset(double off)
	{
		if(off == 0.01) return;
		fprintf(mFile,"\tsetAttr \".off\" %f;\n", off);

	}
	void getCurrentTime()
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());

	}
	void getOwner()
	{
		fprintf(mFile,"\"%s.own\"",mName.c_str());

	}
	void getInputGeometryMsg()
	{
		fprintf(mFile,"\"%s.igm\"",mName.c_str());

	}
	void getLocalGeometry()
	{
		fprintf(mFile,"\"%s.lge\"",mName.c_str());

	}
	void getWorldMatrix()
	{
		fprintf(mFile,"\"%s.wm\"",mName.c_str());

	}
	void getOwnerPositions()
	{
		fprintf(mFile,"\"%s.pos\"",mName.c_str());

	}
	void getOwnerVelocities()
	{
		fprintf(mFile,"\"%s.vel\"",mName.c_str());

	}
	void getOwnerMasses()
	{
		fprintf(mFile,"\"%s.mas\"",mName.c_str());

	}
	void getIdMapping()
	{
		fprintf(mFile,"\"%s.idm\"",mName.c_str());

	}
	void getSortedId()
	{
		fprintf(mFile,"\"%s.idm.sid\"",mName.c_str());

	}
	void getIdIndex()
	{
		fprintf(mFile,"\"%s.idm.idix\"",mName.c_str());

	}
	void getInputForce(size_t ifc_i)
	{
		fprintf(mFile,"\"%s.ifc[%i]\"",mName.c_str(),ifc_i);

	}
	void getOwnerCentroid()
	{
		fprintf(mFile,"\"%s.ocd\"",mName.c_str());

	}
	void getOwnerCentroidX()
	{
		fprintf(mFile,"\"%s.ocd.ocx\"",mName.c_str());

	}
	void getOwnerCentroidY()
	{
		fprintf(mFile,"\"%s.ocd.ocy\"",mName.c_str());

	}
	void getOwnerCentroidZ()
	{
		fprintf(mFile,"\"%s.ocd.ocz\"",mName.c_str());

	}
	void getOwnerCentroidLocal()
	{
		fprintf(mFile,"\"%s.ocl\"",mName.c_str());

	}
	void getOwnerCentroidLocalX()
	{
		fprintf(mFile,"\"%s.ocl.olcx\"",mName.c_str());

	}
	void getOwnerCentroidLocalY()
	{
		fprintf(mFile,"\"%s.ocl.ocly\"",mName.c_str());

	}
	void getOwnerCentroidLocalZ()
	{
		fprintf(mFile,"\"%s.ocl.oclz\"",mName.c_str());

	}
	void getGroupId(size_t gri_i)
	{
		fprintf(mFile,"\"%s.gri[%i]\"",mName.c_str(),gri_i);

	}
	void getComponentPositions(size_t cpp_i)
	{
		fprintf(mFile,"\"%s.cpp[%i]\"",mName.c_str(),cpp_i);

	}
	void getComponentVelocities(size_t cpv_i)
	{
		fprintf(mFile,"\"%s.cpv[%i]\"",mName.c_str(),cpv_i);

	}
	void getComponentCentroid(size_t cpc_i)
	{
		fprintf(mFile,"\"%s.cpc[%i]\"",mName.c_str(),cpc_i);

	}
	void getComponentCentroidX(size_t cpc_i)
	{
		fprintf(mFile,"\"%s.cpc[%i].ccx\"",mName.c_str(),cpc_i);

	}
	void getComponentCentroidY(size_t cpc_i)
	{
		fprintf(mFile,"\"%s.cpc[%i].ccy\"",mName.c_str(),cpc_i);

	}
	void getComponentCentroidZ(size_t cpc_i)
	{
		fprintf(mFile,"\"%s.cpc[%i].ccz\"",mName.c_str(),cpc_i);

	}
	void getComponentCentroidLocal(size_t ccl_i)
	{
		fprintf(mFile,"\"%s.ccl[%i]\"",mName.c_str(),ccl_i);

	}
	void getComponentCentroidLocalX(size_t ccl_i)
	{
		fprintf(mFile,"\"%s.ccl[%i].cclx\"",mName.c_str(),ccl_i);

	}
	void getComponentCentroidLocalY(size_t ccl_i)
	{
		fprintf(mFile,"\"%s.ccl[%i].clcy\"",mName.c_str(),ccl_i);

	}
	void getComponentCentroidLocalZ(size_t ccl_i)
	{
		fprintf(mFile,"\"%s.ccl[%i].clcz\"",mName.c_str(),ccl_i);

	}
	void getSweptGeometry()
	{
		fprintf(mFile,"\"%s.swg\"",mName.c_str());

	}
	void getLocalSweptGeometry()
	{
		fprintf(mFile,"\"%s.lsg\"",mName.c_str());

	}
	void getRatePPIn(size_t rpi_i)
	{
		fprintf(mFile,"\"%s.rpi[%i]\"",mName.c_str(),rpi_i);

	}
	void getRatePPOut()
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());

	}
	void getMatrixModified()
	{
		fprintf(mFile,"\"%s.mtm\"",mName.c_str());

	}
	void getGeometryModified()
	{
		fprintf(mFile,"\"%s.gmd\"",mName.c_str());

	}
	void getUvSetName()
	{
		fprintf(mFile,"\"%s.guv\"",mName.c_str());

	}
	void getResilience()
	{
		fprintf(mFile,"\"%s.res\"",mName.c_str());

	}
	void getFriction()
	{
		fprintf(mFile,"\"%s.fri\"",mName.c_str());

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.off\"",mName.c_str());

	}
protected:
	GeoConnector(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_GEOCONNECTOR_H__
