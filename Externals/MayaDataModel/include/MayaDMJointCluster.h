/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_JOINTCLUSTER_H__
#define __MayaDM_JOINTCLUSTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCluster.h"
namespace MayaDM
{
class JointCluster : public Cluster
{
public:
	struct ChildJointClusterXforms{
		void write(FILE* file) const
		{
		}
	};
	struct NextJointClusterXforms{
		void write(FILE* file) const
		{
		}
	};
	struct DistanceList{
		void write(FILE* file) const
		{
		}
	};
public:

	JointCluster():Cluster(){}
	JointCluster(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Cluster(file, name, parent, "jointCluster", shared, create){}
	virtual ~JointCluster(){}

	void setChildEnabled(size_t che_i,bool che)
	{
		if(che == 0) return;
		fprintf(mFile,"\tsetAttr \".che[%i]\" %i;\n", che_i,che);
	}
	void setChildEnabled(size_t che_start,size_t che_end,bool* che)
	{
		fprintf(mFile,"\tsetAttr \".che[%i:%i]\" ", che_start,che_end);
		size_t size = (che_end-che_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",che[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startChildEnabled(size_t che_start,size_t che_end)const
	{
		fprintf(mFile,"\tsetAttr \".che[%i:%i]\"",che_start,che_end);
	}
	void appendChildEnabled(bool che)const
	{
		fprintf(mFile," %i",che);
	}
	void endChildEnabled()const
	{
		fprintf(mFile,";\n");
	}
	void setJointMidplaneAxis(const double3& jma)
	{
		fprintf(mFile,"\tsetAttr \".jma\" -type \"double3\" ");
		jma.write(mFile);
		fprintf(mFile,";\n");
	}
	void setJointMidplaneAxisX(double jmx)
	{
		if(jmx == 0) return;
		fprintf(mFile,"\tsetAttr \".jma.jmx\" %f;\n", jmx);
	}
	void setJointMidplaneAxisY(double jmy)
	{
		if(jmy == 0) return;
		fprintf(mFile,"\tsetAttr \".jma.jmy\" %f;\n", jmy);
	}
	void setJointMidplaneAxisZ(double jmz)
	{
		if(jmz == 0) return;
		fprintf(mFile,"\tsetAttr \".jma.jmz\" %f;\n", jmz);
	}
	void setChildJointMidplaneAxis(size_t cjm_i,const double3& cjm)
	{
		fprintf(mFile,"\tsetAttr \".cjm[%i]\" -type \"double3\" ",cjm_i);
		cjm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setChildJointMidplaneAxis(size_t cjm_start,size_t cjm_end,double* cjm)
	{
		fprintf(mFile,"\tsetAttr \".cjm[%i:%i]\" ", cjm_start,cjm_end);
		size_t size = (cjm_end-cjm_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cjm[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startChildJointMidplaneAxis(size_t cjm_start,size_t cjm_end)const
	{
		fprintf(mFile,"\tsetAttr \".cjm[%i:%i]\"",cjm_start,cjm_end);
	}
	void appendChildJointMidplaneAxis(double cjm)const
	{
		fprintf(mFile," %f",cjm);
	}
	void endChildJointMidplaneAxis()const
	{
		fprintf(mFile,";\n");
	}
	void setChildjointMidplaneAxisX(size_t cjm_i,double cmx)
	{
		if(cmx == 0) return;
		fprintf(mFile,"\tsetAttr \".cjm[%i].cmx\" %f;\n", cjm_i,cmx);
	}
	void setChildjointMidplaneAxisY(size_t cjm_i,double cmy)
	{
		if(cmy == 0) return;
		fprintf(mFile,"\tsetAttr \".cjm[%i].cmy\" %f;\n", cjm_i,cmy);
	}
	void setChildjointMidplaneAxisZ(size_t cjm_i,double cmz)
	{
		if(cmz == 0) return;
		fprintf(mFile,"\tsetAttr \".cjm[%i].cmz\" %f;\n", cjm_i,cmz);
	}
	void setBoneLength(float bl)
	{
		if(bl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bl\" %f;\n", bl);
	}
	void setUpperBound(float ub)
	{
		if(ub == 10) return;
		fprintf(mFile,"\tsetAttr \".ub\" %f;\n", ub);
	}
	void setUpperValue(float uv)
	{
		if(uv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".uv\" %f;\n", uv);
	}
	void setLowerBound(float lb)
	{
		if(lb == 10.0) return;
		fprintf(mFile,"\tsetAttr \".lb\" %f;\n", lb);
	}
	void setLowerValue(float lv)
	{
		if(lv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lv\" %f;\n", lv);
	}
	void setUpperDropoffType(unsigned int udt)
	{
		if(udt == 0) return;
		fprintf(mFile,"\tsetAttr \".udt\" %i;\n", udt);
	}
	void setLowerDropoffType(unsigned int ldt)
	{
		if(ldt == 0) return;
		fprintf(mFile,"\tsetAttr \".ldt\" %i;\n", ldt);
	}
	void setUpperEnabled(bool upe)
	{
		if(upe == 0) return;
		fprintf(mFile,"\tsetAttr \".upe\" %i;\n", upe);
	}
	void setConvertedTo2(bool ct2)
	{
		if(ct2 == 0) return;
		fprintf(mFile,"\tsetAttr \".ct2\" %i;\n", ct2);
	}
	void getRedoLowerWeights()const
	{
		fprintf(mFile,"\"%s.rlw\"",mName.c_str());
	}
	void getRedoUpperWeights()const
	{
		fprintf(mFile,"\"%s.ruw\"",mName.c_str());
	}
	void getChildJointClusterXforms(size_t cjx_i)const
	{
		fprintf(mFile,"\"%s.cjx[%i]\"",mName.c_str(),cjx_i);
	}
	void getChildJointClusterXforms()const
	{

		fprintf(mFile,"\"%s.cjx\"",mName.c_str());
	}
	void getChildJointPreMatrix(size_t cjx_i)const
	{
		fprintf(mFile,"\"%s.cjx[%i].cpr\"",mName.c_str(),cjx_i);
	}
	void getChildJointPreMatrix()const
	{

		fprintf(mFile,"\"%s.cjx.cpr\"",mName.c_str());
	}
	void getChildJointWeightedMatrix(size_t cjx_i)const
	{
		fprintf(mFile,"\"%s.cjx[%i].cjw\"",mName.c_str(),cjx_i);
	}
	void getChildJointWeightedMatrix()const
	{

		fprintf(mFile,"\"%s.cjx.cjw\"",mName.c_str());
	}
	void getChildJointPostMatrix(size_t cjx_i)const
	{
		fprintf(mFile,"\"%s.cjx[%i].cpo\"",mName.c_str(),cjx_i);
	}
	void getChildJointPostMatrix()const
	{

		fprintf(mFile,"\"%s.cjx.cpo\"",mName.c_str());
	}
	void getChildJointPreCompensationMatrix(size_t cjpr_i)const
	{
		fprintf(mFile,"\"%s.cjpr[%i]\"",mName.c_str(),cjpr_i);
	}
	void getChildJointPreCompensationMatrix()const
	{

		fprintf(mFile,"\"%s.cjpr\"",mName.c_str());
	}
	void getChildJointWeightedCompensationMatrix(size_t cjwc_i)const
	{
		fprintf(mFile,"\"%s.cjwc[%i]\"",mName.c_str(),cjwc_i);
	}
	void getChildJointWeightedCompensationMatrix()const
	{

		fprintf(mFile,"\"%s.cjwc\"",mName.c_str());
	}
	void getChildJointPostCompensationMatrix(size_t cjps_i)const
	{
		fprintf(mFile,"\"%s.cjps[%i]\"",mName.c_str(),cjps_i);
	}
	void getChildJointPostCompensationMatrix()const
	{

		fprintf(mFile,"\"%s.cjps\"",mName.c_str());
	}
	void getBindPose()const
	{
		fprintf(mFile,"\"%s.bp\"",mName.c_str());
	}
	void getNextJointBindPose()const
	{
		fprintf(mFile,"\"%s.njb\"",mName.c_str());
	}
	void getChildJointBindPose(size_t cjb_i)const
	{
		fprintf(mFile,"\"%s.cjb[%i]\"",mName.c_str(),cjb_i);
	}
	void getChildJointBindPose()const
	{

		fprintf(mFile,"\"%s.cjb\"",mName.c_str());
	}
	void getJointMidplaneAxis()const
	{
		fprintf(mFile,"\"%s.jma\"",mName.c_str());
	}
	void getJointMidplaneAxisX()const
	{
		fprintf(mFile,"\"%s.jma.jmx\"",mName.c_str());
	}
	void getJointMidplaneAxisY()const
	{
		fprintf(mFile,"\"%s.jma.jmy\"",mName.c_str());
	}
	void getJointMidplaneAxisZ()const
	{
		fprintf(mFile,"\"%s.jma.jmz\"",mName.c_str());
	}
	void getNextJointClusterXforms()const
	{
		fprintf(mFile,"\"%s.njx\"",mName.c_str());
	}
	void getNextJointPreMatrix()const
	{
		fprintf(mFile,"\"%s.njx.npr\"",mName.c_str());
	}
	void getNextJointWeightedMatrix()const
	{
		fprintf(mFile,"\"%s.njx.njw\"",mName.c_str());
	}
	void getNextJointPostMatrix()const
	{
		fprintf(mFile,"\"%s.njx.npo\"",mName.c_str());
	}
	void getNextJointPreCompensationMatrix()const
	{
		fprintf(mFile,"\"%s.njpr\"",mName.c_str());
	}
	void getNextJointWeightedCompensationMatrix()const
	{
		fprintf(mFile,"\"%s.njwc\"",mName.c_str());
	}
	void getNextJointPostCompensationMatrix()const
	{
		fprintf(mFile,"\"%s.njps\"",mName.c_str());
	}
	void getNextJointMidplaneAxis()const
	{
		fprintf(mFile,"\"%s.njm\"",mName.c_str());
	}
	void getNextjointMidplaneAxisX()const
	{
		fprintf(mFile,"\"%s.njm.nmx\"",mName.c_str());
	}
	void getNextjointMidplaneAxisY()const
	{
		fprintf(mFile,"\"%s.njm.nmy\"",mName.c_str());
	}
	void getNextjointMidplaneAxisZ()const
	{
		fprintf(mFile,"\"%s.njm.nmz\"",mName.c_str());
	}
	void getChildJointMidplaneAxis(size_t cjm_i)const
	{
		fprintf(mFile,"\"%s.cjm[%i]\"",mName.c_str(),cjm_i);
	}
	void getChildJointMidplaneAxis()const
	{

		fprintf(mFile,"\"%s.cjm\"",mName.c_str());
	}
	void getChildjointMidplaneAxisX(size_t cjm_i)const
	{
		fprintf(mFile,"\"%s.cjm[%i].cmx\"",mName.c_str(),cjm_i);
	}
	void getChildjointMidplaneAxisX()const
	{

		fprintf(mFile,"\"%s.cjm.cmx\"",mName.c_str());
	}
	void getChildjointMidplaneAxisY(size_t cjm_i)const
	{
		fprintf(mFile,"\"%s.cjm[%i].cmy\"",mName.c_str(),cjm_i);
	}
	void getChildjointMidplaneAxisY()const
	{

		fprintf(mFile,"\"%s.cjm.cmy\"",mName.c_str());
	}
	void getChildjointMidplaneAxisZ(size_t cjm_i)const
	{
		fprintf(mFile,"\"%s.cjm[%i].cmz\"",mName.c_str(),cjm_i);
	}
	void getChildjointMidplaneAxisZ()const
	{

		fprintf(mFile,"\"%s.cjm.cmz\"",mName.c_str());
	}
	void getDistanceList(size_t dl_i)const
	{
		fprintf(mFile,"\"%s.dl[%i]\"",mName.c_str(),dl_i);
	}
	void getDistanceList()const
	{

		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getDistances(size_t dl_i,size_t cd_i)const
	{
		fprintf(mFile,"\"%s.dl[%i].cd[%i]\"",mName.c_str(),dl_i,cd_i);
	}
	void getDistances(size_t cd_i)const
	{

		fprintf(mFile,"\"%s.dl.cd[%i]\"",mName.c_str(),cd_i);
	}
	void getBoneLength()const
	{
		fprintf(mFile,"\"%s.bl\"",mName.c_str());
	}
	void getUpperBound()const
	{
		fprintf(mFile,"\"%s.ub\"",mName.c_str());
	}
	void getUpperValue()const
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());
	}
	void getLowerBound()const
	{
		fprintf(mFile,"\"%s.lb\"",mName.c_str());
	}
	void getLowerValue()const
	{
		fprintf(mFile,"\"%s.lv\"",mName.c_str());
	}
	void getClusterFlexorSet()const
	{
		fprintf(mFile,"\"%s.cfs\"",mName.c_str());
	}
protected:
	JointCluster(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Cluster(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_JOINTCLUSTER_H__
