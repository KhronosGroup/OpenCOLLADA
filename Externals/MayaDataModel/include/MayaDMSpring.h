/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SPRING_H__
#define __MayaDM_SPRING_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
<p><pre>    The spring node represents a group of springs between points in one or more
    particle or geometry objects.  The stiffness, damping, restLength, and
    end1weight/end2Weight attributes control the motion of the springs.
</pre></p>
*/
class Spring : public Shape
{
public:
	/*
	This attribute holds the mapping information for the particle
	IDs<<==>>Index into per-particle attribute arrays.
	It will connected with aIdMapping of particle nodes.
	*/
	struct IdMapping{
		void write(FILE* file) const
		{
		}
	};
public:
	Spring(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "spring"){}
	virtual ~Spring(){}
	/*
	The amount [0,1] that the first or the 'from' end will be affected
	by the spring.
	*/
	void setEnd1Weight(double f){if(f == 1) return; fprintf_s(mFile, "setAttr \".f\" %f;\n", f);}
	/*
	The amount [0,1] that the first or the 'from' end will be affected
	by the spring.
	*/
	void setEnd1Weight(const DoubleID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*
	The amount [0,1] that the second or the 'to' end will be affected
	by the spring.
	*/
	void setEnd2Weight(double t){if(t == 1) return; fprintf_s(mFile, "setAttr \".t\" %f;\n", t);}
	/*
	The amount [0,1] that the second or the 'to' end will be affected
	by the spring.
	*/
	void setEnd2Weight(const DoubleID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*
	This attribute determines if the node uses per object or per spring
	stiffness. If true, each spring will use the corresponding value in the
	stiffnessPS array. If false, every spring will use the stiffness
	attribute value.
	*/
	void setUseStiffnessPS(bool usps){if(usps == true) return; fprintf_s(mFile, "setAttr \".usps\" %i;\n", usps);}
	/*
	This attribute determines if the node uses per object or per spring
	damping. If true, each spring will use the corresponding value in the
	dampingPS array. Otherwise, every spring will use the damping
	attribute value.
	*/
	void setUseDampingPS(bool udps){if(udps == true) return; fprintf_s(mFile, "setAttr \".udps\" %i;\n", udps);}
	/*
	This attribute determines if the node uses per object or per spring
	rest length. If true, each spring will use the corresponding value in
	the restLengthPS array. Otherwise, every spring will use the
	restLength attribute value.
	*/
	void setUseRestLengthPS(bool urps){if(urps == true) return; fprintf_s(mFile, "setAttr \".urps\" %i;\n", urps);}
	/*
	This attribute is per object.
	The strength with which springs are trying to maintain their length.
	*/
	void setStiffness(double s){if(s == 1) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*
	This attribute is per object.
	The strength with which springs are trying to maintain their length.
	*/
	void setStiffness(const DoubleID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	This attribute is per object.
	How strongly the motion of springs are damped by the 'physical'
	properties of the springs. A larger value makes the springs converge
	faster to their rest length.
	*/
	void setDamping(double d){if(d == .2) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	This attribute is per object.
	How strongly the motion of springs are damped by the 'physical'
	properties of the springs. A larger value makes the springs converge
	faster to their rest length.
	*/
	void setDamping(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*This attribute is per object. The length at which springs try to stay.*/
	void setRestLength(double r){if(r == 0) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*This attribute is per object. The length at which springs try to stay.*/
	void setRestLength(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*
	This attribute is per spring.
	The strength with which springs are trying to maintain their length.
	PS stands for per-spring. This attribute stores an array of data, one
	for each spring. The value can be edited with the spring command or
	component editor.
	*/
	void setStiffnessPS(const doubleArray& sps){if(sps.size == 0) return; fprintf_s(mFile, "setAttr \".sps\" -type \"doubleArray\" ");sps.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute is per spring.
	The strength with which springs are trying to maintain their length.
	PS stands for per-spring. This attribute stores an array of data, one
	for each spring. The value can be edited with the spring command or
	component editor.
	*/
	void setStiffnessPS(const DoubleArrayID& sps){fprintf_s(mFile,"connectAttr \"");sps.write(mFile);fprintf_s(mFile,"\" \"%s.sps\";\n",mName.c_str());}
	/*
	This attribute is per spring.
	How strongly the motion of springs are damped by the 'physical'
	properties of the springs. PS stands for per-spring. This attribute
	stores an array of data, one for each spring. The value can be edited
	with the spring command or component editor.
	*/
	void setDampingPS(const doubleArray& dps){if(dps.size == 0) return; fprintf_s(mFile, "setAttr \".dps\" -type \"doubleArray\" ");dps.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute is per spring.
	How strongly the motion of springs are damped by the 'physical'
	properties of the springs. PS stands for per-spring. This attribute
	stores an array of data, one for each spring. The value can be edited
	with the spring command or component editor.
	*/
	void setDampingPS(const DoubleArrayID& dps){fprintf_s(mFile,"connectAttr \"");dps.write(mFile);fprintf_s(mFile,"\" \"%s.dps\";\n",mName.c_str());}
	/*
	It is per spring attribute which represents the length at which springs
	try to stay. PS stands for per-spring. The values can be edited with
	the spring command or component editor.
	*/
	void setRestLengthPS(const doubleArray& rps){if(rps.size == 0) return; fprintf_s(mFile, "setAttr \".rps\" -type \"doubleArray\" ");rps.write(mFile);fprintf_s(mFile,";\n");}
	/*
	It is per spring attribute which represents the length at which springs
	try to stay. PS stands for per-spring. The values can be edited with
	the spring command or component editor.
	*/
	void setRestLengthPS(const DoubleArrayID& rps){fprintf_s(mFile,"connectAttr \"");rps.write(mFile);fprintf_s(mFile,"\" \"%s.rps\";\n",mName.c_str());}
	/*position array for the objects incident to the springs.*/
	void setObjectPositions(size_t opos_i,const vectorArray& opos){if(opos.size == 0) return; fprintf_s(mFile, "setAttr \".opos[%i]\" -type \"vectorArray\" ",opos_i);opos.write(mFile);fprintf_s(mFile,";\n");}
	/*position array for the objects incident to the springs.*/
	void setObjectPositions(size_t opos_i,const VectorArrayID& opos){fprintf_s(mFile,"connectAttr \"");opos.write(mFile);fprintf_s(mFile,"\" \"%s.opos[%i]\";\n",mName.c_str(),opos_i);}
	/*velocity array for the objects incident to the springs.*/
	void setObjectVelocities(size_t ovel_i,const vectorArray& ovel){if(ovel.size == 0) return; fprintf_s(mFile, "setAttr \".ovel[%i]\" -type \"vectorArray\" ",ovel_i);ovel.write(mFile);fprintf_s(mFile,";\n");}
	/*velocity array for the objects incident to the springs.*/
	void setObjectVelocities(size_t ovel_i,const VectorArrayID& ovel){fprintf_s(mFile,"connectAttr \"");ovel.write(mFile);fprintf_s(mFile,"\" \"%s.ovel[%i]\";\n",mName.c_str(),ovel_i);}
	/*mass array for particle objects incident to the springs.*/
	void setObjectMass(size_t omas_i,const doubleArray& omas){if(omas.size == 0) return; fprintf_s(mFile, "setAttr \".omas[%i]\" -type \"doubleArray\" ",omas_i);omas.write(mFile);fprintf_s(mFile,";\n");}
	/*mass array for particle objects incident to the springs.*/
	void setObjectMass(size_t omas_i,const DoubleArrayID& omas){fprintf_s(mFile,"connectAttr \"");omas.write(mFile);fprintf_s(mFile,"\" \"%s.omas[%i]\";\n",mName.c_str(),omas_i);}
	/*
	spring node may need deltaTime to compute force.
	It is connected with particle objects.
	*/
	void setDeltaTime(size_t dt_i,const TimeID& dt){fprintf_s(mFile,"connectAttr \"");dt.write(mFile);fprintf_s(mFile,"\" \"%s.dt[%i]\";\n",mName.c_str(),dt_i);}
	/*
	output force to particle objects.
	It is "CACHED" so that the computePlug is called once for all nodes
	which are waiting for the output force from this spring node.
	*/
	void setOutputForce(size_t of_i,const VectorArrayID& of){fprintf_s(mFile,"connectAttr \"");of.write(mFile);fprintf_s(mFile,"\" \"%s.of[%i]\";\n",mName.c_str(),of_i);}
	/*Indices to indicate which springs are valid.*/
	void setValidIndex(const intArray& vali){if(vali.size == 0) return; fprintf_s(mFile, "setAttr \".vali\" -type \"intArray\" ");vali.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Indices of attached object(should be plug multi-index in the
	aObjectPositions attribute).
	*/
	void setObject0(const intArray& obz){if(obz.size == 0) return; fprintf_s(mFile, "setAttr \".obz\" -type \"intArray\" ");obz.write(mFile);fprintf_s(mFile,";\n");}
	/*Indices of spring endpoints in their respective objects.*/
	void setPoint0(const intArray& ptz){if(ptz.size == 0) return; fprintf_s(mFile, "setAttr \".ptz\" -type \"intArray\" ");ptz.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Indices of attached object(should be plug multi-index in the
	aObjectPositions attribute).
	*/
	void setObject1(const intArray& obo){if(obo.size == 0) return; fprintf_s(mFile, "setAttr \".obo\" -type \"intArray\" ");obo.write(mFile);fprintf_s(mFile,";\n");}
	/*Indices of spring endpoints in their respective objects.*/
	void setPoint1(const intArray& pto){if(pto.size == 0) return; fprintf_s(mFile, "setAttr \".pto\" -type \"intArray\" ");pto.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute hold the shortest length of index arrays so that
	computeForce method will use it to get each spring without over range
	of the five index arrays. This will save time (don't do too many
	checkings) and method won't fail if some springs are missing.
	This attribute is affected when edit end object index arrays or
	end point index arrays.
	*/
	void setMinSprings(int ms){if(ms == 0) return; fprintf_s(mFile, "setAttr \".ms\" %i;\n", ms);}
	/*
	This attribute determines if the spring node need to do ID/Index
	mapping. The default value is true for this attribute. If users know
	that there is not any particle died, it can be set to false. With
	the false value, the spring node will not do particle Id/index mapping
	and speed up the evaluation.
	*/
	void setManageParticleDeath(bool mpd){if(mpd == true) return; fprintf_s(mFile, "setAttr \".mpd\" %i;\n", mpd);}
	/*
	This attribute holds the mapping information for the particle
	IDs<<==>>Index into per-particle attribute arrays.
	It will connected with aIdMapping of particle nodes.
	*/
	void setIdMapping(size_t idm_i,const IdMappingID& idm){fprintf_s(mFile,"connectAttr \"");idm.write(mFile);fprintf_s(mFile,"\" \"%s.idm[%i]\";\n",mName.c_str(),idm_i);}
	/*
	With this attribute, we get the particleIds from particle node.
	The particleId values are sorted in ascending order.
	*/
	void setSortedId(size_t idm_i,const IntArrayID& sid){fprintf_s(mFile,"connectAttr \"");sid.write(mFile);fprintf_s(mFile,"\" \"%s.idm[%i].sid\";\n",mName.c_str(),idm_i);}
	/*
	With this attribute, we get the particle index positions into
	per-particle attribute arrays for the corresponding ids stored
	in aSortedId.
	*/
	void setIdIndex(size_t idm_i,const IntArrayID& idix){fprintf_s(mFile,"connectAttr \"");idix.write(mFile);fprintf_s(mFile,"\" \"%s.idm[%i].idix\";\n",mName.c_str(),idm_i);}
	/*The number of springs in the object.*/
	void setCount(const IntID& cnt){fprintf_s(mFile,"connectAttr \"");cnt.write(mFile);fprintf_s(mFile,"\" \"%s.cnt\";\n",mName.c_str());}
	/*
	Obsolete.
	Used only to read version 1 files.  Will be removed after version 2.
	*/
	void setObjects(size_t obj_i,const MessageID& obj){fprintf_s(mFile,"connectAttr \"");obj.write(mFile);fprintf_s(mFile,"\" \"%s.obj[%i]\";\n",mName.c_str(),obj_i);}
	/*
	Obsolete.
	Used only to read version 1 files.  Will be removed after version 2.
	*/
	void setObjCount(const IntID& obc){fprintf_s(mFile,"connectAttr \"");obc.write(mFile);fprintf_s(mFile,"\" \"%s.obc\";\n",mName.c_str());}
	/*
	Obsolete.
	Used only to read version 1 files.  Will be removed after version 2.
	*/
	void setLengths(const doubleArray& lns){if(lns.size == 0) return; fprintf_s(mFile, "setAttr \".lns\" -type \"doubleArray\" ");lns.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Obsolete.
	Used only to read version 1 files.  Will be removed after version 2.
	*/
	void setLengths(const DoubleArrayID& lns){fprintf_s(mFile,"connectAttr \"");lns.write(mFile);fprintf_s(mFile,"\" \"%s.lns\";\n",mName.c_str());}
	/*Obsolete. Not used.  Will be removed after version 2.*/
	void setMinUsed(const DoubleID& mnu){fprintf_s(mFile,"connectAttr \"");mnu.write(mFile);fprintf_s(mFile,"\" \"%s.mnu\";\n",mName.c_str());}
	/*
	Min value used when springs were made
	Obsolete. Not used.  Will be removed after version 2.
	*/
	void setMaxUsed(const DoubleID& mxu){fprintf_s(mFile,"connectAttr \"");mxu.write(mFile);fprintf_s(mFile,"\" \"%s.mxu\";\n",mName.c_str());}
	/*Used only to read version 1 files.  Will be removed after version 2.*/
	void setPt0Index(const DoubleArrayID& pzi){fprintf_s(mFile,"connectAttr \"");pzi.write(mFile);fprintf_s(mFile,"\" \"%s.pzi\";\n",mName.c_str());}
	/*Used only to read version 1 files.  Will be removed after version 2.*/
	void setPt1Index(const DoubleArrayID& poi){fprintf_s(mFile,"connectAttr \"");poi.write(mFile);fprintf_s(mFile,"\" \"%s.poi\";\n",mName.c_str());}
	/*Used only to read version 1 files.  Will be removed after version 2.*/
	void setObj0Index(const DoubleArrayID& ozi){fprintf_s(mFile,"connectAttr \"");ozi.write(mFile);fprintf_s(mFile,"\" \"%s.ozi\";\n",mName.c_str());}
	/*Used only to read version 1 files.  Will be removed after version 2.*/
	void setObj1Index(const DoubleArrayID& ooi){fprintf_s(mFile,"connectAttr \"");ooi.write(mFile);fprintf_s(mFile,"\" \"%s.ooi\";\n",mName.c_str());}
	/*
	The amount [0,1] that the first or the 'from' end will be affected
	by the spring.
	*/
	DoubleID getEnd1Weight(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*
	The amount [0,1] that the second or the 'to' end will be affected
	by the spring.
	*/
	DoubleID getEnd2Weight(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is per object.
	The strength with which springs are trying to maintain their length.
	*/
	DoubleID getStiffness(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is per object.
	How strongly the motion of springs are damped by the 'physical'
	properties of the springs. A larger value makes the springs converge
	faster to their rest length.
	*/
	DoubleID getDamping(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*This attribute is per object. The length at which springs try to stay.*/
	DoubleID getRestLength(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is per spring.
	The strength with which springs are trying to maintain their length.
	PS stands for per-spring. This attribute stores an array of data, one
	for each spring. The value can be edited with the spring command or
	component editor.
	*/
	DoubleArrayID getStiffnessPS(){char buffer[4096];sprintf_s (buffer, "%s.sps",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is per spring.
	How strongly the motion of springs are damped by the 'physical'
	properties of the springs. PS stands for per-spring. This attribute
	stores an array of data, one for each spring. The value can be edited
	with the spring command or component editor.
	*/
	DoubleArrayID getDampingPS(){char buffer[4096];sprintf_s (buffer, "%s.dps",mName.c_str());return (const char*)buffer;}
	/*
	It is per spring attribute which represents the length at which springs
	try to stay. PS stands for per-spring. The values can be edited with
	the spring command or component editor.
	*/
	DoubleArrayID getRestLengthPS(){char buffer[4096];sprintf_s (buffer, "%s.rps",mName.c_str());return (const char*)buffer;}
	/*position array for the objects incident to the springs.*/
	const VectorArrayID& getObjectPositions(size_t opos_i){char buffer[4096];sprintf_s (buffer, "%s.opos[%i]",mName.c_str(),opos_i);return (const char*)buffer;}
	/*velocity array for the objects incident to the springs.*/
	const VectorArrayID& getObjectVelocities(size_t ovel_i){char buffer[4096];sprintf_s (buffer, "%s.ovel[%i]",mName.c_str(),ovel_i);return (const char*)buffer;}
	/*mass array for particle objects incident to the springs.*/
	const DoubleArrayID& getObjectMass(size_t omas_i){char buffer[4096];sprintf_s (buffer, "%s.omas[%i]",mName.c_str(),omas_i);return (const char*)buffer;}
	/*
	spring node may need deltaTime to compute force.
	It is connected with particle objects.
	*/
	const TimeID& getDeltaTime(size_t dt_i){char buffer[4096];sprintf_s (buffer, "%s.dt[%i]",mName.c_str(),dt_i);return (const char*)buffer;}
	/*
	output force to particle objects.
	It is "CACHED" so that the computePlug is called once for all nodes
	which are waiting for the output force from this spring node.
	*/
	const VectorArrayID& getOutputForce(size_t of_i){char buffer[4096];sprintf_s (buffer, "%s.of[%i]",mName.c_str(),of_i);return (const char*)buffer;}
	/*
	This attribute holds the mapping information for the particle
	IDs<<==>>Index into per-particle attribute arrays.
	It will connected with aIdMapping of particle nodes.
	*/
	const IdMappingID& getIdMapping(size_t idm_i){char buffer[4096];sprintf_s (buffer, "%s.idm[%i]",mName.c_str(),idm_i);return (const char*)buffer;}
	/*
	With this attribute, we get the particleIds from particle node.
	The particleId values are sorted in ascending order.
	*/
	const IntArrayID& getSortedId(size_t idm_i){char buffer[4096];sprintf_s (buffer, "%s.idm[%i].sid",mName.c_str(),idm_i);return (const char*)buffer;}
	/*
	With this attribute, we get the particle index positions into
	per-particle attribute arrays for the corresponding ids stored
	in aSortedId.
	*/
	const IntArrayID& getIdIndex(size_t idm_i){char buffer[4096];sprintf_s (buffer, "%s.idm[%i].idix",mName.c_str(),idm_i);return (const char*)buffer;}
	/*The number of springs in the object.*/
	IntID getCount(){char buffer[4096];sprintf_s (buffer, "%s.cnt",mName.c_str());return (const char*)buffer;}
	/*
	Obsolete.
	Used only to read version 1 files.  Will be removed after version 2.
	*/
	const MessageID& getObjects(size_t obj_i){char buffer[4096];sprintf_s (buffer, "%s.obj[%i]",mName.c_str(),obj_i);return (const char*)buffer;}
	/*
	Obsolete.
	Used only to read version 1 files.  Will be removed after version 2.
	*/
	IntID getObjCount(){char buffer[4096];sprintf_s (buffer, "%s.obc",mName.c_str());return (const char*)buffer;}
	/*
	Obsolete.
	Used only to read version 1 files.  Will be removed after version 2.
	*/
	DoubleArrayID getLengths(){char buffer[4096];sprintf_s (buffer, "%s.lns",mName.c_str());return (const char*)buffer;}
	/*Obsolete. Not used.  Will be removed after version 2.*/
	DoubleID getMinUsed(){char buffer[4096];sprintf_s (buffer, "%s.mnu",mName.c_str());return (const char*)buffer;}
	/*
	Min value used when springs were made
	Obsolete. Not used.  Will be removed after version 2.
	*/
	DoubleID getMaxUsed(){char buffer[4096];sprintf_s (buffer, "%s.mxu",mName.c_str());return (const char*)buffer;}
	/*Used only to read version 1 files.  Will be removed after version 2.*/
	DoubleArrayID getPt0Index(){char buffer[4096];sprintf_s (buffer, "%s.pzi",mName.c_str());return (const char*)buffer;}
	/*Used only to read version 1 files.  Will be removed after version 2.*/
	DoubleArrayID getPt1Index(){char buffer[4096];sprintf_s (buffer, "%s.poi",mName.c_str());return (const char*)buffer;}
	/*Used only to read version 1 files.  Will be removed after version 2.*/
	DoubleArrayID getObj0Index(){char buffer[4096];sprintf_s (buffer, "%s.ozi",mName.c_str());return (const char*)buffer;}
	/*Used only to read version 1 files.  Will be removed after version 2.*/
	DoubleArrayID getObj1Index(){char buffer[4096];sprintf_s (buffer, "%s.ooi",mName.c_str());return (const char*)buffer;}
protected:
	Spring(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SPRING_H__
