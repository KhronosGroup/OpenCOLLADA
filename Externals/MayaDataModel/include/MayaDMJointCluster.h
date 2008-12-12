/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
The jointCluster node provides a high-level way to control a cluster
node's percentage values around a joint.
JointClusters are one way to create smooth bending behavior on skin as
joints rotate.
<pre>
            --- clusterHandle1 (parented to J1)
           |
           |      u       l
           V______u_______l________  <---- clusterHandle2 (parented to J2)
                  u       l        \
          J1      u       l      J2 \
           _______u_______l______    \
         upper    u       l    lower  \
         value    u       l     value  \
                upper   lower      \    \
                bound   bound       \    \
</pre>
The attributes most of interest to control the behavior are:
<ul>
  <li>upperBound</li>
  <li>upperValue</li>
  <li>lowerBound</li>
  <li>lowerValue</li>
  <li>upperDropoffType</li>
  <li>lowerDropoffType</li>
</ul>
*/
class JointCluster : public Cluster
{
public:
	/*The bundled cluster transforms for the child joint.*/
	struct ChildJointClusterXforms{
		void write(FILE* file) const
		{
		}
	};
	/*The bundled cluster transforms for the next joint.*/
	struct NextJointClusterXforms{
		void write(FILE* file) const
		{
		}
	};
	/*List of cached distances to nearest bone, one per input geometry.*/
	struct DistanceList{
		void write(FILE* file) const
		{
		}
	};
public:
	JointCluster(FILE* file,const std::string& name,const std::string& parent=""):Cluster(file, name, parent, "jointCluster"){}
	virtual ~JointCluster(){}
	/*
	Message attribute used internally to indicate that
	lower bone weights are dirty.
	*/
	void setRedoLowerWeights(const MessageID& rlw){fprintf_s(mFile,"connectAttr \"");rlw.write(mFile);fprintf_s(mFile,"\" \"%s.rlw\";\n",mName.c_str());}
	/*
	Message attribute used internally to indicate that
	the upper bone weights are dirty.
	*/
	void setRedoUpperWeights(const MessageID& ruw){fprintf_s(mFile,"connectAttr \"");ruw.write(mFile);fprintf_s(mFile,"\" \"%s.ruw\";\n",mName.c_str());}
	/*The bundled cluster transforms for the child joint.*/
	void setChildJointClusterXforms(size_t cjx_i,const ChildJointClusterXformsID& cjx){fprintf_s(mFile,"connectAttr \"");cjx.write(mFile);fprintf_s(mFile,"\" \"%s.cjx[%i]\";\n",mName.c_str(),cjx_i);}
	/*WorldSpace matrix above cluster weighted matrix for child joint.*/
	void setChildJointPreMatrix(size_t cjx_i,const MatrixID& cpr){fprintf_s(mFile,"connectAttr \"");cpr.write(mFile);fprintf_s(mFile,"\" \"%s.cjx[%i].cpr\";\n",mName.c_str(),cjx_i);}
	/*Cluster weighted matrix for child joint.*/
	void setChildJointWeightedMatrix(size_t cjx_i,const MatrixID& cjw){fprintf_s(mFile,"connectAttr \"");cjw.write(mFile);fprintf_s(mFile,"\" \"%s.cjx[%i].cjw\";\n",mName.c_str(),cjx_i);}
	/*WorldSpace matrix below cluster weighted matrix for child joint.*/
	void setChildJointPostMatrix(size_t cjx_i,const MatrixID& cpo){fprintf_s(mFile,"connectAttr \"");cpo.write(mFile);fprintf_s(mFile,"\" \"%s.cjx[%i].cpo\";\n",mName.c_str(),cjx_i);}
	/*WorldSpace matrix above next joints weighted matrix comp (-bs)*/
	void setChildJointPreCompensationMatrix(size_t cjpr_i,const MatrixID& cjpr){fprintf_s(mFile,"connectAttr \"");cjpr.write(mFile);fprintf_s(mFile,"\" \"%s.cjpr[%i]\";\n",mName.c_str(),cjpr_i);}
	/*Cluster weighted matrix compensation*/
	void setChildJointWeightedCompensationMatrix(size_t cjwc_i,const MatrixID& cjwc){fprintf_s(mFile,"connectAttr \"");cjwc.write(mFile);fprintf_s(mFile,"\" \"%s.cjwc[%i]\";\n",mName.c_str(),cjwc_i);}
	/*WorldSpace matrix below child joint's handle.*/
	void setChildJointPostCompensationMatrix(size_t cjps_i,const MatrixID& cjps){fprintf_s(mFile,"connectAttr \"");cjps.write(mFile);fprintf_s(mFile,"\" \"%s.cjps[%i]\";\n",mName.c_str(),cjps_i);}
	/*
	The matrix of the clustered joint,
	at the time it was bound.
	*/
	void setBindPose(const MatrixID& bp){fprintf_s(mFile,"connectAttr \"");bp.write(mFile);fprintf_s(mFile,"\" \"%s.bp\";\n",mName.c_str());}
	/*
	The matrix of the joint after the clustered joint,
	at the time it was bound.
	*/
	void setNextJointBindPose(const MatrixID& njb){fprintf_s(mFile,"connectAttr \"");njb.write(mFile);fprintf_s(mFile,"\" \"%s.njb\";\n",mName.c_str());}
	/*
	The matrix of the child of the clustered joint
	at the time it was bound.
	*/
	void setChildJointBindPose(size_t cjb_i,const MatrixID& cjb){fprintf_s(mFile,"connectAttr \"");cjb.write(mFile);fprintf_s(mFile,"\" \"%s.cjb[%i]\";\n",mName.c_str(),cjb_i);}
	/*Whether or not the lower part is enabled.*/
	void setChildEnabled(size_t che_i,bool che){if(che == 0) return; fprintf_s(mFile, "setAttr \".che[%i]\" %i;\n", che_i,che);}
	/*
	Axis that averages the bindPose axes above and below this joint.
	Used when a joint has more than one child joint.
	*/
	void setJointMidplaneAxis(const double3& jma){fprintf_s(mFile, "setAttr \".jma\" -type \"double3\" ");jma.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Axis that averages the bindPose axes above and below this joint.
	Used when a joint has more than one child joint.
	*/
	void setJointMidplaneAxis(const Double3ID& jma){fprintf_s(mFile,"connectAttr \"");jma.write(mFile);fprintf_s(mFile,"\" \"%s.jma\";\n",mName.c_str());}
	/*
	X value of the axis that averages the bindPose axes above
	and below this joint.
	*/
	void setJointMidplaneAxisX(double jmx){if(jmx == 0) return; fprintf_s(mFile, "setAttr \".jma.jmx\" %f;\n", jmx);}
	/*
	X value of the axis that averages the bindPose axes above
	and below this joint.
	*/
	void setJointMidplaneAxisX(const DoubleID& jmx){fprintf_s(mFile,"connectAttr \"");jmx.write(mFile);fprintf_s(mFile,"\" \"%s.jma.jmx\";\n",mName.c_str());}
	/*
	Y value of the axis that averages the bindPose axes above
	and below this joint.
	*/
	void setJointMidplaneAxisY(double jmy){if(jmy == 0) return; fprintf_s(mFile, "setAttr \".jma.jmy\" %f;\n", jmy);}
	/*
	Y value of the axis that averages the bindPose axes above
	and below this joint.
	*/
	void setJointMidplaneAxisY(const DoubleID& jmy){fprintf_s(mFile,"connectAttr \"");jmy.write(mFile);fprintf_s(mFile,"\" \"%s.jma.jmy\";\n",mName.c_str());}
	/*
	Z value of the axis that averages the bindPose axes above
	and below this joint.
	*/
	void setJointMidplaneAxisZ(double jmz){if(jmz == 0) return; fprintf_s(mFile, "setAttr \".jma.jmz\" %f;\n", jmz);}
	/*
	Z value of the axis that averages the bindPose axes above
	and below this joint.
	*/
	void setJointMidplaneAxisZ(const DoubleID& jmz){fprintf_s(mFile,"connectAttr \"");jmz.write(mFile);fprintf_s(mFile,"\" \"%s.jma.jmz\";\n",mName.c_str());}
	/*The bundled cluster transforms for the next joint.*/
	void setNextJointClusterXforms(const NextJointClusterXformsID& njx){fprintf_s(mFile,"connectAttr \"");njx.write(mFile);fprintf_s(mFile,"\" \"%s.njx\";\n",mName.c_str());}
	/*WorldSpace matrix above cluster weighted matrix for next joint.*/
	void setNextJointPreMatrix(const MatrixID& npr){fprintf_s(mFile,"connectAttr \"");npr.write(mFile);fprintf_s(mFile,"\" \"%s.njx.npr\";\n",mName.c_str());}
	/*Cluster weighted matrix for next joint.*/
	void setNextJointWeightedMatrix(const MatrixID& njw){fprintf_s(mFile,"connectAttr \"");njw.write(mFile);fprintf_s(mFile,"\" \"%s.njx.njw\";\n",mName.c_str());}
	/*WorldSpace matrix below cluster weighted matrix for next joint.*/
	void setNextJointPostMatrix(const MatrixID& npo){fprintf_s(mFile,"connectAttr \"");npo.write(mFile);fprintf_s(mFile,"\" \"%s.njx.npo\";\n",mName.c_str());}
	/*WorldSpace matrix above next joint's weighted matrix compensation.*/
	void setNextJointPreCompensationMatrix(const MatrixID& njpr){fprintf_s(mFile,"connectAttr \"");njpr.write(mFile);fprintf_s(mFile,"\" \"%s.njpr\";\n",mName.c_str());}
	/*Cluster weighted matrix compensation.*/
	void setNextJointWeightedCompensationMatrix(const MatrixID& njwc){fprintf_s(mFile,"connectAttr \"");njwc.write(mFile);fprintf_s(mFile,"\" \"%s.njwc\";\n",mName.c_str());}
	/*WorldSpace matrix below next joint's handle.*/
	void setNextJointPostCompensationMatrix(const MatrixID& njps){fprintf_s(mFile,"connectAttr \"");njps.write(mFile);fprintf_s(mFile,"\" \"%s.njps\";\n",mName.c_str());}
	/*Axis that averages the bindPose axes above and below the next joint.*/
	void setNextJointMidplaneAxis(const Double3ID& njm){fprintf_s(mFile,"connectAttr \"");njm.write(mFile);fprintf_s(mFile,"\" \"%s.njm\";\n",mName.c_str());}
	/*X value of the axis that averages the bindPose axes above and below the next joint.*/
	void setNextjointMidplaneAxisX(const DoubleID& nmx){fprintf_s(mFile,"connectAttr \"");nmx.write(mFile);fprintf_s(mFile,"\" \"%s.njm.nmx\";\n",mName.c_str());}
	/*Y value of the axis that averages the bindPose axes above and below the next joint.*/
	void setNextjointMidplaneAxisY(const DoubleID& nmy){fprintf_s(mFile,"connectAttr \"");nmy.write(mFile);fprintf_s(mFile,"\" \"%s.njm.nmy\";\n",mName.c_str());}
	/*Z value of the axis that averages the bindPose axes above and below the next joint.*/
	void setNextjointMidplaneAxisZ(const DoubleID& nmz){fprintf_s(mFile,"connectAttr \"");nmz.write(mFile);fprintf_s(mFile,"\" \"%s.njm.nmz\";\n",mName.c_str());}
	/*Axis that averages the bindPose axes above and below the child joint.*/
	void setChildJointMidplaneAxis(size_t cjm_i,const double3& cjm){fprintf_s(mFile, "setAttr \".cjm[%i]\" -type \"double3\" ",cjm_i);cjm.write(mFile);fprintf_s(mFile,";\n");}
	/*Axis that averages the bindPose axes above and below the child joint.*/
	void setChildJointMidplaneAxis(size_t cjm_start,size_t cjm_end,double* cjm){fprintf_s(mFile,"setAttr \".cjm[%i:%i]\" ", cjm_start,cjm_end);size_t size = (cjm_end-cjm_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",cjm[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Axis that averages the bindPose axes above and below the child joint.*/
	void setChildJointMidplaneAxis(size_t cjm_i,const Double3ID& cjm){fprintf_s(mFile,"connectAttr \"");cjm.write(mFile);fprintf_s(mFile,"\" \"%s.cjm[%i]\";\n",mName.c_str(),cjm_i);}
	/*
	X value of the axis that averages the bindPose axes above
	and below the child joint.
	*/
	void setChildjointMidplaneAxisX(size_t cjm_i,double cmx){if(cmx == 0) return; fprintf_s(mFile, "setAttr \".cjm[%i].cmx\" %f;\n", cjm_i,cmx);}
	/*
	X value of the axis that averages the bindPose axes above
	and below the child joint.
	*/
	void setChildjointMidplaneAxisX(size_t cjm_i,const DoubleID& cmx){fprintf_s(mFile,"connectAttr \"");cmx.write(mFile);fprintf_s(mFile,"\" \"%s.cjm[%i].cmx\";\n",mName.c_str(),cjm_i);}
	/*
	Y value of the axis that averages the bindPose axes above
	and below the child joint.
	*/
	void setChildjointMidplaneAxisY(size_t cjm_i,double cmy){if(cmy == 0) return; fprintf_s(mFile, "setAttr \".cjm[%i].cmy\" %f;\n", cjm_i,cmy);}
	/*
	Y value of the axis that averages the bindPose axes above
	and below the child joint.
	*/
	void setChildjointMidplaneAxisY(size_t cjm_i,const DoubleID& cmy){fprintf_s(mFile,"connectAttr \"");cmy.write(mFile);fprintf_s(mFile,"\" \"%s.cjm[%i].cmy\";\n",mName.c_str(),cjm_i);}
	/*
	Z value of the axis that averages the bindPose axes above
	and below the child joint.
	*/
	void setChildjointMidplaneAxisZ(size_t cjm_i,double cmz){if(cmz == 0) return; fprintf_s(mFile, "setAttr \".cjm[%i].cmz\" %f;\n", cjm_i,cmz);}
	/*
	Z value of the axis that averages the bindPose axes above
	and below the child joint.
	*/
	void setChildjointMidplaneAxisZ(size_t cjm_i,const DoubleID& cmz){fprintf_s(mFile,"connectAttr \"");cmz.write(mFile);fprintf_s(mFile,"\" \"%s.cjm[%i].cmz\";\n",mName.c_str(),cjm_i);}
	/*List of cached distances to nearest bone, one per input geometry.*/
	void setDistanceList(size_t dl_i,const DistanceListID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl[%i]\";\n",mName.c_str(),dl_i);}
	/*Cached distances to nearest bone for one geometry.*/
	void setDistances(size_t dl_i,size_t cd_i,const FloatID& cd){fprintf_s(mFile,"connectAttr \"");cd.write(mFile);fprintf_s(mFile,"\" \"%s.dl[%i].cd[%i]\";\n",mName.c_str(),dl_i,cd_i);}
	/*% of the length of the bone; used when joint has more than one child.*/
	void setBoneLength(float bl){if(bl == 0.0) return; fprintf_s(mFile, "setAttr \".bl\" %f;\n", bl);}
	/*% of the length of the bone; used when joint has more than one child.*/
	void setBoneLength(const FloatID& bl){fprintf_s(mFile,"connectAttr \"");bl.write(mFile);fprintf_s(mFile,"\" \"%s.bl\";\n",mName.c_str());}
	/*% of the length of the bone along which the top joint dropoff occurs.*/
	void setUpperBound(float ub){if(ub == 10) return; fprintf_s(mFile, "setAttr \".ub\" %f;\n", ub);}
	/*% of the length of the bone along which the top joint dropoff occurs.*/
	void setUpperBound(const FloatID& ub){fprintf_s(mFile,"connectAttr \"");ub.write(mFile);fprintf_s(mFile,"\" \"%s.ub\";\n",mName.c_str());}
	/*Initial dropoff Value in direction of upper joint*/
	void setUpperValue(float uv){if(uv == 1.0) return; fprintf_s(mFile, "setAttr \".uv\" %f;\n", uv);}
	/*Initial dropoff Value in direction of upper joint*/
	void setUpperValue(const FloatID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*% of the length of the bone along which the next joint dropoff occurs.*/
	void setLowerBound(float lb){if(lb == 10.0) return; fprintf_s(mFile, "setAttr \".lb\" %f;\n", lb);}
	/*% of the length of the bone along which the next joint dropoff occurs.*/
	void setLowerBound(const FloatID& lb){fprintf_s(mFile,"connectAttr \"");lb.write(mFile);fprintf_s(mFile,"\" \"%s.lb\";\n",mName.c_str());}
	/*Initial dropoff Value in direction of lower joint*/
	void setLowerValue(float lv){if(lv == 1.0) return; fprintf_s(mFile, "setAttr \".lv\" %f;\n", lv);}
	/*Initial dropoff Value in direction of lower joint*/
	void setLowerValue(const FloatID& lv){fprintf_s(mFile,"connectAttr \"");lv.write(mFile);fprintf_s(mFile,"\" \"%s.lv\";\n",mName.c_str());}
	/*
	Type of dropoff above joint.
	Valid values are: 0 = "linear", 1 = "sine", 2 = "exponential",
	3 = "none".
	*/
	void setUpperDropoffType(unsigned int udt){if(udt == 0) return; fprintf_s(mFile, "setAttr \".udt\" %i;\n", udt);}
	/*
	Type of dropoff below joint: sinusoidal, linear, exponential
	Valid values are: 0 = "linear", 1 = "sine", 2 = "exponential",
	3 = "none".
	*/
	void setLowerDropoffType(unsigned int ldt){if(ldt == 0) return; fprintf_s(mFile, "setAttr \".ldt\" %i;\n", ldt);}
	/*Whether or not the upper part is enabled.*/
	void setUpperEnabled(bool upe){if(upe == 0) return; fprintf_s(mFile, "setAttr \".upe\" %i;\n", upe);}
	/*
	attribute is connected to the flexor set if this is a cluster
	flexor
	*/
	void setClusterFlexorSet(const MessageID& cfs){fprintf_s(mFile,"connectAttr \"");cfs.write(mFile);fprintf_s(mFile,"\" \"%s.cfs\";\n",mName.c_str());}
	/*whether the percents have been converted to 2.0 style. This value should not be modified by the user. Doing so will cause your percents to be modified the next time the file is read.*/
	void setConvertedTo2(bool ct2){if(ct2 == 0) return; fprintf_s(mFile, "setAttr \".ct2\" %i;\n", ct2);}
	/*
	Message attribute used internally to indicate that
	lower bone weights are dirty.
	*/
	MessageID getRedoLowerWeights(){char buffer[4096];sprintf_s (buffer, "%s.rlw",mName.c_str());return (const char*)buffer;}
	/*
	Message attribute used internally to indicate that
	the upper bone weights are dirty.
	*/
	MessageID getRedoUpperWeights(){char buffer[4096];sprintf_s (buffer, "%s.ruw",mName.c_str());return (const char*)buffer;}
	/*The bundled cluster transforms for the child joint.*/
	const ChildJointClusterXformsID& getChildJointClusterXforms(size_t cjx_i){char buffer[4096];sprintf_s (buffer, "%s.cjx[%i]",mName.c_str(),cjx_i);return (const char*)buffer;}
	/*WorldSpace matrix above cluster weighted matrix for child joint.*/
	const MatrixID& getChildJointPreMatrix(size_t cjx_i){char buffer[4096];sprintf_s (buffer, "%s.cjx[%i].cpr",mName.c_str(),cjx_i);return (const char*)buffer;}
	/*Cluster weighted matrix for child joint.*/
	const MatrixID& getChildJointWeightedMatrix(size_t cjx_i){char buffer[4096];sprintf_s (buffer, "%s.cjx[%i].cjw",mName.c_str(),cjx_i);return (const char*)buffer;}
	/*WorldSpace matrix below cluster weighted matrix for child joint.*/
	const MatrixID& getChildJointPostMatrix(size_t cjx_i){char buffer[4096];sprintf_s (buffer, "%s.cjx[%i].cpo",mName.c_str(),cjx_i);return (const char*)buffer;}
	/*WorldSpace matrix above next joints weighted matrix comp (-bs)*/
	const MatrixID& getChildJointPreCompensationMatrix(size_t cjpr_i){char buffer[4096];sprintf_s (buffer, "%s.cjpr[%i]",mName.c_str(),cjpr_i);return (const char*)buffer;}
	/*Cluster weighted matrix compensation*/
	const MatrixID& getChildJointWeightedCompensationMatrix(size_t cjwc_i){char buffer[4096];sprintf_s (buffer, "%s.cjwc[%i]",mName.c_str(),cjwc_i);return (const char*)buffer;}
	/*WorldSpace matrix below child joint's handle.*/
	const MatrixID& getChildJointPostCompensationMatrix(size_t cjps_i){char buffer[4096];sprintf_s (buffer, "%s.cjps[%i]",mName.c_str(),cjps_i);return (const char*)buffer;}
	/*
	The matrix of the clustered joint,
	at the time it was bound.
	*/
	MatrixID getBindPose(){char buffer[4096];sprintf_s (buffer, "%s.bp",mName.c_str());return (const char*)buffer;}
	/*
	The matrix of the joint after the clustered joint,
	at the time it was bound.
	*/
	MatrixID getNextJointBindPose(){char buffer[4096];sprintf_s (buffer, "%s.njb",mName.c_str());return (const char*)buffer;}
	/*
	The matrix of the child of the clustered joint
	at the time it was bound.
	*/
	const MatrixID& getChildJointBindPose(size_t cjb_i){char buffer[4096];sprintf_s (buffer, "%s.cjb[%i]",mName.c_str(),cjb_i);return (const char*)buffer;}
	/*
	Axis that averages the bindPose axes above and below this joint.
	Used when a joint has more than one child joint.
	*/
	Double3ID getJointMidplaneAxis(){char buffer[4096];sprintf_s (buffer, "%s.jma",mName.c_str());return (const char*)buffer;}
	/*
	X value of the axis that averages the bindPose axes above
	and below this joint.
	*/
	DoubleID getJointMidplaneAxisX(){char buffer[4096];sprintf_s (buffer, "%s.jma.jmx",mName.c_str());return (const char*)buffer;}
	/*
	Y value of the axis that averages the bindPose axes above
	and below this joint.
	*/
	DoubleID getJointMidplaneAxisY(){char buffer[4096];sprintf_s (buffer, "%s.jma.jmy",mName.c_str());return (const char*)buffer;}
	/*
	Z value of the axis that averages the bindPose axes above
	and below this joint.
	*/
	DoubleID getJointMidplaneAxisZ(){char buffer[4096];sprintf_s (buffer, "%s.jma.jmz",mName.c_str());return (const char*)buffer;}
	/*The bundled cluster transforms for the next joint.*/
	NextJointClusterXformsID getNextJointClusterXforms(){char buffer[4096];sprintf_s (buffer, "%s.njx",mName.c_str());return (const char*)buffer;}
	/*WorldSpace matrix above cluster weighted matrix for next joint.*/
	MatrixID getNextJointPreMatrix(){char buffer[4096];sprintf_s (buffer, "%s.njx.npr",mName.c_str());return (const char*)buffer;}
	/*Cluster weighted matrix for next joint.*/
	MatrixID getNextJointWeightedMatrix(){char buffer[4096];sprintf_s (buffer, "%s.njx.njw",mName.c_str());return (const char*)buffer;}
	/*WorldSpace matrix below cluster weighted matrix for next joint.*/
	MatrixID getNextJointPostMatrix(){char buffer[4096];sprintf_s (buffer, "%s.njx.npo",mName.c_str());return (const char*)buffer;}
	/*WorldSpace matrix above next joint's weighted matrix compensation.*/
	MatrixID getNextJointPreCompensationMatrix(){char buffer[4096];sprintf_s (buffer, "%s.njpr",mName.c_str());return (const char*)buffer;}
	/*Cluster weighted matrix compensation.*/
	MatrixID getNextJointWeightedCompensationMatrix(){char buffer[4096];sprintf_s (buffer, "%s.njwc",mName.c_str());return (const char*)buffer;}
	/*WorldSpace matrix below next joint's handle.*/
	MatrixID getNextJointPostCompensationMatrix(){char buffer[4096];sprintf_s (buffer, "%s.njps",mName.c_str());return (const char*)buffer;}
	/*Axis that averages the bindPose axes above and below the next joint.*/
	Double3ID getNextJointMidplaneAxis(){char buffer[4096];sprintf_s (buffer, "%s.njm",mName.c_str());return (const char*)buffer;}
	/*X value of the axis that averages the bindPose axes above and below the next joint.*/
	DoubleID getNextjointMidplaneAxisX(){char buffer[4096];sprintf_s (buffer, "%s.njm.nmx",mName.c_str());return (const char*)buffer;}
	/*Y value of the axis that averages the bindPose axes above and below the next joint.*/
	DoubleID getNextjointMidplaneAxisY(){char buffer[4096];sprintf_s (buffer, "%s.njm.nmy",mName.c_str());return (const char*)buffer;}
	/*Z value of the axis that averages the bindPose axes above and below the next joint.*/
	DoubleID getNextjointMidplaneAxisZ(){char buffer[4096];sprintf_s (buffer, "%s.njm.nmz",mName.c_str());return (const char*)buffer;}
	/*Axis that averages the bindPose axes above and below the child joint.*/
	const Double3ID& getChildJointMidplaneAxis(size_t cjm_i){char buffer[4096];sprintf_s (buffer, "%s.cjm[%i]",mName.c_str(),cjm_i);return (const char*)buffer;}
	/*
	X value of the axis that averages the bindPose axes above
	and below the child joint.
	*/
	const DoubleID& getChildjointMidplaneAxisX(size_t cjm_i){char buffer[4096];sprintf_s (buffer, "%s.cjm[%i].cmx",mName.c_str(),cjm_i);return (const char*)buffer;}
	/*
	Y value of the axis that averages the bindPose axes above
	and below the child joint.
	*/
	const DoubleID& getChildjointMidplaneAxisY(size_t cjm_i){char buffer[4096];sprintf_s (buffer, "%s.cjm[%i].cmy",mName.c_str(),cjm_i);return (const char*)buffer;}
	/*
	Z value of the axis that averages the bindPose axes above
	and below the child joint.
	*/
	const DoubleID& getChildjointMidplaneAxisZ(size_t cjm_i){char buffer[4096];sprintf_s (buffer, "%s.cjm[%i].cmz",mName.c_str(),cjm_i);return (const char*)buffer;}
	/*List of cached distances to nearest bone, one per input geometry.*/
	const DistanceListID& getDistanceList(size_t dl_i){char buffer[4096];sprintf_s (buffer, "%s.dl[%i]",mName.c_str(),dl_i);return (const char*)buffer;}
	/*Cached distances to nearest bone for one geometry.*/
	const FloatID& getDistances(size_t dl_i,size_t cd_i){char buffer[4096];sprintf_s (buffer, "%s.dl[%i].cd[%i]",mName.c_str(),dl_i,cd_i);return (const char*)buffer;}
	/*% of the length of the bone; used when joint has more than one child.*/
	FloatID getBoneLength(){char buffer[4096];sprintf_s (buffer, "%s.bl",mName.c_str());return (const char*)buffer;}
	/*% of the length of the bone along which the top joint dropoff occurs.*/
	FloatID getUpperBound(){char buffer[4096];sprintf_s (buffer, "%s.ub",mName.c_str());return (const char*)buffer;}
	/*Initial dropoff Value in direction of upper joint*/
	FloatID getUpperValue(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*% of the length of the bone along which the next joint dropoff occurs.*/
	FloatID getLowerBound(){char buffer[4096];sprintf_s (buffer, "%s.lb",mName.c_str());return (const char*)buffer;}
	/*Initial dropoff Value in direction of lower joint*/
	FloatID getLowerValue(){char buffer[4096];sprintf_s (buffer, "%s.lv",mName.c_str());return (const char*)buffer;}
	/*
	attribute is connected to the flexor set if this is a cluster
	flexor
	*/
	MessageID getClusterFlexorSet(){char buffer[4096];sprintf_s (buffer, "%s.cfs",mName.c_str());return (const char*)buffer;}
protected:
	JointCluster(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Cluster(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_JOINTCLUSTER_H__
