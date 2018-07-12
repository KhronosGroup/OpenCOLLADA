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
	GeoConnector(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "geoConnector", shared, create){}
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
	void startGroupId(size_t gri_start,size_t gri_end)const
	{
		fprintf(mFile,"\tsetAttr \".gri[%i:%i]\"",gri_start,gri_end);
	}
	void appendGroupId(int gri)const
	{
		fprintf(mFile," %i",gri);
	}
	void endGroupId()const
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
	void getCurrentTime()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getOwner()const
	{
		fprintf(mFile,"\"%s.own\"",mName.c_str());
	}
	void getInputGeometryMsg()const
	{
		fprintf(mFile,"\"%s.igm\"",mName.c_str());
	}
	void getLocalGeometry()const
	{
		fprintf(mFile,"\"%s.lge\"",mName.c_str());
	}
	void getWorldMatrix()const
	{
		fprintf(mFile,"\"%s.wm\"",mName.c_str());
	}
	void getOwnerPositions()const
	{
		fprintf(mFile,"\"%s.pos\"",mName.c_str());
	}
	void getOwnerVelocities()const
	{
		fprintf(mFile,"\"%s.vel\"",mName.c_str());
	}
	void getOwnerMasses()const
	{
		fprintf(mFile,"\"%s.mas\"",mName.c_str());
	}
	void getIdMapping()const
	{
		fprintf(mFile,"\"%s.idm\"",mName.c_str());
	}
	void getSortedId()const
	{
		fprintf(mFile,"\"%s.idm.sid\"",mName.c_str());
	}
	void getIdIndex()const
	{
		fprintf(mFile,"\"%s.idm.idix\"",mName.c_str());
	}
	void getInputForce(size_t ifc_i)const
	{
		fprintf(mFile,"\"%s.ifc[%i]\"",mName.c_str(),ifc_i);
	}
	void getInputForce()const
	{

		fprintf(mFile,"\"%s.ifc\"",mName.c_str());
	}
	void getOwnerCentroid()const
	{
		fprintf(mFile,"\"%s.ocd\"",mName.c_str());
	}
	void getOwnerCentroidX()const
	{
		fprintf(mFile,"\"%s.ocd.ocx\"",mName.c_str());
	}
	void getOwnerCentroidY()const
	{
		fprintf(mFile,"\"%s.ocd.ocy\"",mName.c_str());
	}
	void getOwnerCentroidZ()const
	{
		fprintf(mFile,"\"%s.ocd.ocz\"",mName.c_str());
	}
	void getOwnerCentroidLocal()const
	{
		fprintf(mFile,"\"%s.ocl\"",mName.c_str());
	}
	void getOwnerCentroidLocalX()const
	{
		fprintf(mFile,"\"%s.ocl.olcx\"",mName.c_str());
	}
	void getOwnerCentroidLocalY()const
	{
		fprintf(mFile,"\"%s.ocl.ocly\"",mName.c_str());
	}
	void getOwnerCentroidLocalZ()const
	{
		fprintf(mFile,"\"%s.ocl.oclz\"",mName.c_str());
	}
	void getGroupId(size_t gri_i)const
	{
		fprintf(mFile,"\"%s.gri[%i]\"",mName.c_str(),gri_i);
	}
	void getGroupId()const
	{

		fprintf(mFile,"\"%s.gri\"",mName.c_str());
	}
	void getComponentPositions(size_t cpp_i)const
	{
		fprintf(mFile,"\"%s.cpp[%i]\"",mName.c_str(),cpp_i);
	}
	void getComponentPositions()const
	{

		fprintf(mFile,"\"%s.cpp\"",mName.c_str());
	}
	void getComponentVelocities(size_t cpv_i)const
	{
		fprintf(mFile,"\"%s.cpv[%i]\"",mName.c_str(),cpv_i);
	}
	void getComponentVelocities()const
	{

		fprintf(mFile,"\"%s.cpv\"",mName.c_str());
	}
	void getComponentCentroid(size_t cpc_i)const
	{
		fprintf(mFile,"\"%s.cpc[%i]\"",mName.c_str(),cpc_i);
	}
	void getComponentCentroid()const
	{

		fprintf(mFile,"\"%s.cpc\"",mName.c_str());
	}
	void getComponentCentroidX(size_t cpc_i)const
	{
		fprintf(mFile,"\"%s.cpc[%i].ccx\"",mName.c_str(),cpc_i);
	}
	void getComponentCentroidX()const
	{

		fprintf(mFile,"\"%s.cpc.ccx\"",mName.c_str());
	}
	void getComponentCentroidY(size_t cpc_i)const
	{
		fprintf(mFile,"\"%s.cpc[%i].ccy\"",mName.c_str(),cpc_i);
	}
	void getComponentCentroidY()const
	{

		fprintf(mFile,"\"%s.cpc.ccy\"",mName.c_str());
	}
	void getComponentCentroidZ(size_t cpc_i)const
	{
		fprintf(mFile,"\"%s.cpc[%i].ccz\"",mName.c_str(),cpc_i);
	}
	void getComponentCentroidZ()const
	{

		fprintf(mFile,"\"%s.cpc.ccz\"",mName.c_str());
	}
	void getComponentCentroidLocal(size_t ccl_i)const
	{
		fprintf(mFile,"\"%s.ccl[%i]\"",mName.c_str(),ccl_i);
	}
	void getComponentCentroidLocal()const
	{

		fprintf(mFile,"\"%s.ccl\"",mName.c_str());
	}
	void getComponentCentroidLocalX(size_t ccl_i)const
	{
		fprintf(mFile,"\"%s.ccl[%i].cclx\"",mName.c_str(),ccl_i);
	}
	void getComponentCentroidLocalX()const
	{

		fprintf(mFile,"\"%s.ccl.cclx\"",mName.c_str());
	}
	void getComponentCentroidLocalY(size_t ccl_i)const
	{
		fprintf(mFile,"\"%s.ccl[%i].clcy\"",mName.c_str(),ccl_i);
	}
	void getComponentCentroidLocalY()const
	{

		fprintf(mFile,"\"%s.ccl.clcy\"",mName.c_str());
	}
	void getComponentCentroidLocalZ(size_t ccl_i)const
	{
		fprintf(mFile,"\"%s.ccl[%i].clcz\"",mName.c_str(),ccl_i);
	}
	void getComponentCentroidLocalZ()const
	{

		fprintf(mFile,"\"%s.ccl.clcz\"",mName.c_str());
	}
	void getSweptGeometry()const
	{
		fprintf(mFile,"\"%s.swg\"",mName.c_str());
	}
	void getLocalSweptGeometry()const
	{
		fprintf(mFile,"\"%s.lsg\"",mName.c_str());
	}
	void getRatePPIn(size_t rpi_i)const
	{
		fprintf(mFile,"\"%s.rpi[%i]\"",mName.c_str(),rpi_i);
	}
	void getRatePPIn()const
	{

		fprintf(mFile,"\"%s.rpi\"",mName.c_str());
	}
	void getRatePPOut()const
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());
	}
	void getMatrixModified()const
	{
		fprintf(mFile,"\"%s.mtm\"",mName.c_str());
	}
	void getGeometryModified()const
	{
		fprintf(mFile,"\"%s.gmd\"",mName.c_str());
	}
	void getUvSetName()const
	{
		fprintf(mFile,"\"%s.guv\"",mName.c_str());
	}
	void getResilience()const
	{
		fprintf(mFile,"\"%s.res\"",mName.c_str());
	}
	void getFriction()const
	{
		fprintf(mFile,"\"%s.fri\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.off\"",mName.c_str());
	}
protected:
	GeoConnector(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_GEOCONNECTOR_H__
