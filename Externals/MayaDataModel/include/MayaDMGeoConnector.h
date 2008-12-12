/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
The geoConnector node provides an interface between ordinary geometry
        objects (such as NURBS surfaces) and the dynamics system.  A geoConnector
        node is associated with any such geometry which is emitting particles,
        exerting a force field, or colliding with particles.  The geoConnector
        node is not used when making an object a rigid or soft body.  The
        node stores positions (and if necessary, pseodo-velocities) for the
        geometry, and provides a tesselated polygonal representation if needed for
        emission or collisions.<p/>
*/
class GeoConnector : public DependNode
{
public:
	/*
	Currently this attribute is not used by the geoConnector.
	It is provided for possible future expansion.
	When springs are placed on geometry, an input connection
	to this attribute is made.  But the geoConnector currently
	never requests the input.
	*/
	struct IdMapping{
		void write(FILE* file) const
		{
		}
	};
public:
	GeoConnector(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "geoConnector"){}
	virtual ~GeoConnector(){}
	/*The current time at which position/velocity data was computed.*/
	void setCurrentTime(const TimeID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*
	Message connection to owning geometry shape.  Necessary
	to support curve on surface.  Users should not modify.
	*/
	void setOwner(const MessageID& own){fprintf_s(mFile,"connectAttr \"");own.write(mFile);fprintf_s(mFile,"\" \"%s.own\";\n",mName.c_str());}
	/*
	Obsolete.  Retained for file load compatibility in 2.0.
	Will be removed for 3.0.
	*/
	void setInputGeometryMsg(const MessageID& igm){fprintf_s(mFile,"connectAttr \"");igm.write(mFile);fprintf_s(mFile,"\" \"%s.igm\";\n",mName.c_str());}
	/*Used to obtain local surface/curve data from associated geometry.*/
	void setLocalGeometry(const GenericID& lge){fprintf_s(mFile,"connectAttr \"");lge.write(mFile);fprintf_s(mFile,"\" \"%s.lge\";\n",mName.c_str());}
	/*
	It is the global transformation matrix which is used to transform
	CVs to the world space.
	*/
	void setWorldMatrix(const matrix& wm){if(wm == identity) return; fprintf_s(mFile, "setAttr \".wm\" -type \"matrix\" ");wm.write(mFile);fprintf_s(mFile,";\n");}
	/*
	It is the global transformation matrix which is used to transform
	CVs to the world space.
	*/
	void setWorldMatrix(const MatrixID& wm){fprintf_s(mFile,"connectAttr \"");wm.write(mFile);fprintf_s(mFile,"\" \"%s.wm\";\n",mName.c_str());}
	/*All edit point positions of the owner shape.*/
	void setOwnerPositions(const VectorArrayID& pos){fprintf_s(mFile,"connectAttr \"");pos.write(mFile);fprintf_s(mFile,"\" \"%s.pos\";\n",mName.c_str());}
	/*All edit point velocities of the owner shape.*/
	void setOwnerVelocities(const VectorArrayID& vel){fprintf_s(mFile,"connectAttr \"");vel.write(mFile);fprintf_s(mFile,"\" \"%s.vel\";\n",mName.c_str());}
	/*
	Currently this always returns null.  It is provided for possible
	future expansion to return an array of owner masses.
	*/
	void setOwnerMasses(const DoubleArrayID& mas){fprintf_s(mFile,"connectAttr \"");mas.write(mFile);fprintf_s(mFile,"\" \"%s.mas\";\n",mName.c_str());}
	/*
	Currently this attribute is not used by the geoConnector.
	It is provided for possible future expansion.
	When springs are placed on geometry, an input connection
	to this attribute is made.  But the geoConnector currently
	never requests the input.
	*/
	void setIdMapping(const IdMappingID& idm){fprintf_s(mFile,"connectAttr \"");idm.write(mFile);fprintf_s(mFile,"\" \"%s.idm\";\n",mName.c_str());}
	/*
	Currently this attribute is not used by the geoConnector.
	It is provided for possible future expansion.
	When springs are placed on geometry, an input connection
	to this attribute is made.  But the geoConnector currently
	never requests the input.
	*/
	void setSortedId(const IntArrayID& sid){fprintf_s(mFile,"connectAttr \"");sid.write(mFile);fprintf_s(mFile,"\" \"%s.idm.sid\";\n",mName.c_str());}
	/*
	Currently this attribute is not used by the geoConnector.
	It is provided for possible future expansion.
	When springs are placed on geometry, an input connection
	to this attribute is made.  But the geoConnector currently
	never requests the input.
	*/
	void setIdIndex(const IntArrayID& idix){fprintf_s(mFile,"connectAttr \"");idix.write(mFile);fprintf_s(mFile,"\" \"%s.idm.idix\";\n",mName.c_str());}
	/*
	Currently this attribute is not used by the geoConnector.
	It is provided for possible future expansion.
	When springs are placed on geometry, an input connection
	to this attribute is made.  But the geoConnector currently
	never requests the input.
	*/
	void setInputForce(size_t ifc_i,const VectorArrayID& ifc){fprintf_s(mFile,"connectAttr \"");ifc.write(mFile);fprintf_s(mFile,"\" \"%s.ifc[%i]\";\n",mName.c_str(),ifc_i);}
	/*Centroid of the owner's CV's or particles positions in world space.*/
	void setOwnerCentroid(const Double3ID& ocd){fprintf_s(mFile,"connectAttr \"");ocd.write(mFile);fprintf_s(mFile,"\" \"%s.ocd\";\n",mName.c_str());}
	/*x-component of centroid of the owner position in world space.*/
	void setOwnerCentroidX(const DoubleID& ocx){fprintf_s(mFile,"connectAttr \"");ocx.write(mFile);fprintf_s(mFile,"\" \"%s.ocd.ocx\";\n",mName.c_str());}
	/*y-component of centroid of the owner position in world space.*/
	void setOwnerCentroidY(const DoubleID& ocy){fprintf_s(mFile,"connectAttr \"");ocy.write(mFile);fprintf_s(mFile,"\" \"%s.ocd.ocy\";\n",mName.c_str());}
	/*z-component of centroid of the owner position in world space.*/
	void setOwnerCentroidZ(const DoubleID& ocz){fprintf_s(mFile,"connectAttr \"");ocz.write(mFile);fprintf_s(mFile,"\" \"%s.ocd.ocz\";\n",mName.c_str());}
	/*Centroid of the owner's CV's or particles positions in local space.*/
	void setOwnerCentroidLocal(const Double3ID& ocl){fprintf_s(mFile,"connectAttr \"");ocl.write(mFile);fprintf_s(mFile,"\" \"%s.ocl\";\n",mName.c_str());}
	/*x-component of centroid of the owner position in local space.*/
	void setOwnerCentroidLocalX(const DoubleID& olcx){fprintf_s(mFile,"connectAttr \"");olcx.write(mFile);fprintf_s(mFile,"\" \"%s.ocl.olcx\";\n",mName.c_str());}
	/*y-component of centroid of the owner position in local space.*/
	void setOwnerCentroidLocalY(const DoubleID& ocly){fprintf_s(mFile,"connectAttr \"");ocly.write(mFile);fprintf_s(mFile,"\" \"%s.ocl.ocly\";\n",mName.c_str());}
	/*z-component of centroid of the owner position in local space.*/
	void setOwnerCentroidLocalZ(const DoubleID& oclz){fprintf_s(mFile,"connectAttr \"");oclz.write(mFile);fprintf_s(mFile,"\" \"%s.ocl.oclz\";\n",mName.c_str());}
	/*
	Records group identification for selected components of vertices/cvs
	which are emitting or exerting fields.
	*/
	void setGroupId(size_t gri_i,int gri){if(gri == -1) return; fprintf_s(mFile, "setAttr \".gri[%i]\" %i;\n", gri_i,gri);}
	/*
	Records group identification for selected components of vertices/cvs
	which are emitting or exerting fields.
	*/
	void setGroupId(size_t gri_i,const IntID& gri){fprintf_s(mFile,"connectAttr \"");gri.write(mFile);fprintf_s(mFile,"\" \"%s.gri[%i]\";\n",mName.c_str(),gri_i);}
	/*A set of CVs' positions of the owner shape.*/
	void setComponentPositions(size_t cpp_i,const VectorArrayID& cpp){fprintf_s(mFile,"connectAttr \"");cpp.write(mFile);fprintf_s(mFile,"\" \"%s.cpp[%i]\";\n",mName.c_str(),cpp_i);}
	/*A set of CVs' velocities of the owner shape.*/
	void setComponentVelocities(size_t cpv_i,const VectorArrayID& cpv){fprintf_s(mFile,"connectAttr \"");cpv.write(mFile);fprintf_s(mFile,"\" \"%s.cpv[%i]\";\n",mName.c_str(),cpv_i);}
	/*Computed based a set of CV's positions of the owner shape.*/
	void setComponentCentroid(size_t cpc_i,const Double3ID& cpc){fprintf_s(mFile,"connectAttr \"");cpc.write(mFile);fprintf_s(mFile,"\" \"%s.cpc[%i]\";\n",mName.c_str(),cpc_i);}
	/*x-component of centroid of the owner component positions.*/
	void setComponentCentroidX(size_t cpc_i,const DoubleID& ccx){fprintf_s(mFile,"connectAttr \"");ccx.write(mFile);fprintf_s(mFile,"\" \"%s.cpc[%i].ccx\";\n",mName.c_str(),cpc_i);}
	/*y-component of centroid of the owner component positions.*/
	void setComponentCentroidY(size_t cpc_i,const DoubleID& ccy){fprintf_s(mFile,"connectAttr \"");ccy.write(mFile);fprintf_s(mFile,"\" \"%s.cpc[%i].ccy\";\n",mName.c_str(),cpc_i);}
	/*z-component of centroid of the owner component positions.*/
	void setComponentCentroidZ(size_t cpc_i,const DoubleID& ccz){fprintf_s(mFile,"connectAttr \"");ccz.write(mFile);fprintf_s(mFile,"\" \"%s.cpc[%i].ccz\";\n",mName.c_str(),cpc_i);}
	/*Based on a set of CV's positions of the owner shape in local space.*/
	void setComponentCentroidLocal(size_t ccl_i,const Double3ID& ccl){fprintf_s(mFile,"connectAttr \"");ccl.write(mFile);fprintf_s(mFile,"\" \"%s.ccl[%i]\";\n",mName.c_str(),ccl_i);}
	/*x-component of owner's component centroid positions in local space.*/
	void setComponentCentroidLocalX(size_t ccl_i,const DoubleID& cclx){fprintf_s(mFile,"connectAttr \"");cclx.write(mFile);fprintf_s(mFile,"\" \"%s.ccl[%i].cclx\";\n",mName.c_str(),ccl_i);}
	/*y-component of owner's component centroid positions in local space.*/
	void setComponentCentroidLocalY(size_t ccl_i,const DoubleID& clcy){fprintf_s(mFile,"connectAttr \"");clcy.write(mFile);fprintf_s(mFile,"\" \"%s.ccl[%i].clcy\";\n",mName.c_str(),ccl_i);}
	/*z-component of owner's component centroid positions in local space.*/
	void setComponentCentroidLocalZ(size_t ccl_i,const DoubleID& clcz){fprintf_s(mFile,"connectAttr \"");clcz.write(mFile);fprintf_s(mFile,"\" \"%s.ccl[%i].clcz\";\n",mName.c_str(),ccl_i);}
	/*The swept geometry for the connected shape.*/
	void setSweptGeometry(const SweptGeometryID& swg){fprintf_s(mFile,"connectAttr \"");swg.write(mFile);fprintf_s(mFile,"\" \"%s.swg\";\n",mName.c_str());}
	/*A local copy of the swept geometry used for nurbs surfaces.*/
	void setLocalSweptGeometry(const SweptGeometryID& lsg){fprintf_s(mFile,"connectAttr \"");lsg.write(mFile);fprintf_s(mFile,"\" \"%s.lsg\";\n",mName.c_str());}
	/*input for per particle emission rates.*/
	void setRatePPIn(size_t rpi_i,const DoubleID& rpi){fprintf_s(mFile,"connectAttr \"");rpi.write(mFile);fprintf_s(mFile,"\" \"%s.rpi[%i]\";\n",mName.c_str(),rpi_i);}
	/*output for per particle emission rates.*/
	void setRatePPOut(const DoubleArrayID& rpo){fprintf_s(mFile,"connectAttr \"");rpo.write(mFile);fprintf_s(mFile,"\" \"%s.rpo\";\n",mName.c_str());}
	/*Indicates that the matrix has been modified in a non-playback mode.*/
	void setMatrixModified(const BoolID& mtm){fprintf_s(mFile,"connectAttr \"");mtm.write(mFile);fprintf_s(mFile,"\" \"%s.mtm\";\n",mName.c_str());}
	/*Indicates that the surface has been modified (surface change or matrix change).*/
	void setGeometryModified(const IntID& gmd){fprintf_s(mFile,"connectAttr \"");gmd.write(mFile);fprintf_s(mFile,"\" \"%s.gmd\";\n",mName.c_str());}
	/*The approximate number of polygons in the tesselated surface.*/
	void setTessellationFactor(int tf){if(tf == 200) return; fprintf_s(mFile, "setAttr \".tf\" %i;\n", tf);}
	/*
	For poly surface emitters that have multiple uv sets, this attr
	specifies which uv set to use when emission rates or
	colors/opacities have been textured.
	*/
	void setUvSetName(const string& guv){if(guv == "NULL") return; fprintf_s(mFile, "setAttr \".guv\" -type \"string\" ");guv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	For poly surface emitters that have multiple uv sets, this attr
	specifies which uv set to use when emission rates or
	colors/opacities have been textured.
	*/
	void setUvSetName(const StringID& guv){fprintf_s(mFile,"connectAttr \"");guv.write(mFile);fprintf_s(mFile,"\" \"%s.guv\";\n",mName.c_str());}
	/*How much of the particle's velocity perpendicular to the surface is reflected*/
	void setResilience(double res){if(res == 1) return; fprintf_s(mFile, "setAttr \".res\" %f;\n", res);}
	/*How much of the particle's velocity perpendicular to the surface is reflected*/
	void setResilience(const DoubleID& res){fprintf_s(mFile,"connectAttr \"");res.write(mFile);fprintf_s(mFile,"\" \"%s.res\";\n",mName.c_str());}
	/*The amount of a particle's velocity parallel to a surface that is lost in the collision*/
	void setFriction(double fri){if(fri == 0) return; fprintf_s(mFile, "setAttr \".fri\" %f;\n", fri);}
	/*The amount of a particle's velocity parallel to a surface that is lost in the collision*/
	void setFriction(const DoubleID& fri){fprintf_s(mFile,"connectAttr \"");fri.write(mFile);fprintf_s(mFile,"\" \"%s.fri\";\n",mName.c_str());}
	/*The distance from the surface particle will be offset on reflection*/
	void setOffset(double off){if(off == 0.01) return; fprintf_s(mFile, "setAttr \".off\" %f;\n", off);}
	/*The distance from the surface particle will be offset on reflection*/
	void setOffset(const DoubleID& off){fprintf_s(mFile,"connectAttr \"");off.write(mFile);fprintf_s(mFile,"\" \"%s.off\";\n",mName.c_str());}
	/*The current time at which position/velocity data was computed.*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*
	Message connection to owning geometry shape.  Necessary
	to support curve on surface.  Users should not modify.
	*/
	MessageID getOwner(){char buffer[4096];sprintf_s (buffer, "%s.own",mName.c_str());return (const char*)buffer;}
	/*
	Obsolete.  Retained for file load compatibility in 2.0.
	Will be removed for 3.0.
	*/
	MessageID getInputGeometryMsg(){char buffer[4096];sprintf_s (buffer, "%s.igm",mName.c_str());return (const char*)buffer;}
	/*Used to obtain local surface/curve data from associated geometry.*/
	GenericID getLocalGeometry(){char buffer[4096];sprintf_s (buffer, "%s.lge",mName.c_str());return (const char*)buffer;}
	/*
	It is the global transformation matrix which is used to transform
	CVs to the world space.
	*/
	MatrixID getWorldMatrix(){char buffer[4096];sprintf_s (buffer, "%s.wm",mName.c_str());return (const char*)buffer;}
	/*All edit point positions of the owner shape.*/
	VectorArrayID getOwnerPositions(){char buffer[4096];sprintf_s (buffer, "%s.pos",mName.c_str());return (const char*)buffer;}
	/*All edit point velocities of the owner shape.*/
	VectorArrayID getOwnerVelocities(){char buffer[4096];sprintf_s (buffer, "%s.vel",mName.c_str());return (const char*)buffer;}
	/*
	Currently this always returns null.  It is provided for possible
	future expansion to return an array of owner masses.
	*/
	DoubleArrayID getOwnerMasses(){char buffer[4096];sprintf_s (buffer, "%s.mas",mName.c_str());return (const char*)buffer;}
	/*
	Currently this attribute is not used by the geoConnector.
	It is provided for possible future expansion.
	When springs are placed on geometry, an input connection
	to this attribute is made.  But the geoConnector currently
	never requests the input.
	*/
	IdMappingID getIdMapping(){char buffer[4096];sprintf_s (buffer, "%s.idm",mName.c_str());return (const char*)buffer;}
	/*
	Currently this attribute is not used by the geoConnector.
	It is provided for possible future expansion.
	When springs are placed on geometry, an input connection
	to this attribute is made.  But the geoConnector currently
	never requests the input.
	*/
	IntArrayID getSortedId(){char buffer[4096];sprintf_s (buffer, "%s.idm.sid",mName.c_str());return (const char*)buffer;}
	/*
	Currently this attribute is not used by the geoConnector.
	It is provided for possible future expansion.
	When springs are placed on geometry, an input connection
	to this attribute is made.  But the geoConnector currently
	never requests the input.
	*/
	IntArrayID getIdIndex(){char buffer[4096];sprintf_s (buffer, "%s.idm.idix",mName.c_str());return (const char*)buffer;}
	/*
	Currently this attribute is not used by the geoConnector.
	It is provided for possible future expansion.
	When springs are placed on geometry, an input connection
	to this attribute is made.  But the geoConnector currently
	never requests the input.
	*/
	const VectorArrayID& getInputForce(size_t ifc_i){char buffer[4096];sprintf_s (buffer, "%s.ifc[%i]",mName.c_str(),ifc_i);return (const char*)buffer;}
	/*Centroid of the owner's CV's or particles positions in world space.*/
	Double3ID getOwnerCentroid(){char buffer[4096];sprintf_s (buffer, "%s.ocd",mName.c_str());return (const char*)buffer;}
	/*x-component of centroid of the owner position in world space.*/
	DoubleID getOwnerCentroidX(){char buffer[4096];sprintf_s (buffer, "%s.ocd.ocx",mName.c_str());return (const char*)buffer;}
	/*y-component of centroid of the owner position in world space.*/
	DoubleID getOwnerCentroidY(){char buffer[4096];sprintf_s (buffer, "%s.ocd.ocy",mName.c_str());return (const char*)buffer;}
	/*z-component of centroid of the owner position in world space.*/
	DoubleID getOwnerCentroidZ(){char buffer[4096];sprintf_s (buffer, "%s.ocd.ocz",mName.c_str());return (const char*)buffer;}
	/*Centroid of the owner's CV's or particles positions in local space.*/
	Double3ID getOwnerCentroidLocal(){char buffer[4096];sprintf_s (buffer, "%s.ocl",mName.c_str());return (const char*)buffer;}
	/*x-component of centroid of the owner position in local space.*/
	DoubleID getOwnerCentroidLocalX(){char buffer[4096];sprintf_s (buffer, "%s.ocl.olcx",mName.c_str());return (const char*)buffer;}
	/*y-component of centroid of the owner position in local space.*/
	DoubleID getOwnerCentroidLocalY(){char buffer[4096];sprintf_s (buffer, "%s.ocl.ocly",mName.c_str());return (const char*)buffer;}
	/*z-component of centroid of the owner position in local space.*/
	DoubleID getOwnerCentroidLocalZ(){char buffer[4096];sprintf_s (buffer, "%s.ocl.oclz",mName.c_str());return (const char*)buffer;}
	/*
	Records group identification for selected components of vertices/cvs
	which are emitting or exerting fields.
	*/
	const IntID& getGroupId(size_t gri_i){char buffer[4096];sprintf_s (buffer, "%s.gri[%i]",mName.c_str(),gri_i);return (const char*)buffer;}
	/*A set of CVs' positions of the owner shape.*/
	const VectorArrayID& getComponentPositions(size_t cpp_i){char buffer[4096];sprintf_s (buffer, "%s.cpp[%i]",mName.c_str(),cpp_i);return (const char*)buffer;}
	/*A set of CVs' velocities of the owner shape.*/
	const VectorArrayID& getComponentVelocities(size_t cpv_i){char buffer[4096];sprintf_s (buffer, "%s.cpv[%i]",mName.c_str(),cpv_i);return (const char*)buffer;}
	/*Computed based a set of CV's positions of the owner shape.*/
	const Double3ID& getComponentCentroid(size_t cpc_i){char buffer[4096];sprintf_s (buffer, "%s.cpc[%i]",mName.c_str(),cpc_i);return (const char*)buffer;}
	/*x-component of centroid of the owner component positions.*/
	const DoubleID& getComponentCentroidX(size_t cpc_i){char buffer[4096];sprintf_s (buffer, "%s.cpc[%i].ccx",mName.c_str(),cpc_i);return (const char*)buffer;}
	/*y-component of centroid of the owner component positions.*/
	const DoubleID& getComponentCentroidY(size_t cpc_i){char buffer[4096];sprintf_s (buffer, "%s.cpc[%i].ccy",mName.c_str(),cpc_i);return (const char*)buffer;}
	/*z-component of centroid of the owner component positions.*/
	const DoubleID& getComponentCentroidZ(size_t cpc_i){char buffer[4096];sprintf_s (buffer, "%s.cpc[%i].ccz",mName.c_str(),cpc_i);return (const char*)buffer;}
	/*Based on a set of CV's positions of the owner shape in local space.*/
	const Double3ID& getComponentCentroidLocal(size_t ccl_i){char buffer[4096];sprintf_s (buffer, "%s.ccl[%i]",mName.c_str(),ccl_i);return (const char*)buffer;}
	/*x-component of owner's component centroid positions in local space.*/
	const DoubleID& getComponentCentroidLocalX(size_t ccl_i){char buffer[4096];sprintf_s (buffer, "%s.ccl[%i].cclx",mName.c_str(),ccl_i);return (const char*)buffer;}
	/*y-component of owner's component centroid positions in local space.*/
	const DoubleID& getComponentCentroidLocalY(size_t ccl_i){char buffer[4096];sprintf_s (buffer, "%s.ccl[%i].clcy",mName.c_str(),ccl_i);return (const char*)buffer;}
	/*z-component of owner's component centroid positions in local space.*/
	const DoubleID& getComponentCentroidLocalZ(size_t ccl_i){char buffer[4096];sprintf_s (buffer, "%s.ccl[%i].clcz",mName.c_str(),ccl_i);return (const char*)buffer;}
	/*The swept geometry for the connected shape.*/
	SweptGeometryID getSweptGeometry(){char buffer[4096];sprintf_s (buffer, "%s.swg",mName.c_str());return (const char*)buffer;}
	/*A local copy of the swept geometry used for nurbs surfaces.*/
	SweptGeometryID getLocalSweptGeometry(){char buffer[4096];sprintf_s (buffer, "%s.lsg",mName.c_str());return (const char*)buffer;}
	/*input for per particle emission rates.*/
	const DoubleID& getRatePPIn(size_t rpi_i){char buffer[4096];sprintf_s (buffer, "%s.rpi[%i]",mName.c_str(),rpi_i);return (const char*)buffer;}
	/*output for per particle emission rates.*/
	DoubleArrayID getRatePPOut(){char buffer[4096];sprintf_s (buffer, "%s.rpo",mName.c_str());return (const char*)buffer;}
	/*Indicates that the matrix has been modified in a non-playback mode.*/
	BoolID getMatrixModified(){char buffer[4096];sprintf_s (buffer, "%s.mtm",mName.c_str());return (const char*)buffer;}
	/*Indicates that the surface has been modified (surface change or matrix change).*/
	IntID getGeometryModified(){char buffer[4096];sprintf_s (buffer, "%s.gmd",mName.c_str());return (const char*)buffer;}
	/*
	For poly surface emitters that have multiple uv sets, this attr
	specifies which uv set to use when emission rates or
	colors/opacities have been textured.
	*/
	StringID getUvSetName(){char buffer[4096];sprintf_s (buffer, "%s.guv",mName.c_str());return (const char*)buffer;}
	/*How much of the particle's velocity perpendicular to the surface is reflected*/
	DoubleID getResilience(){char buffer[4096];sprintf_s (buffer, "%s.res",mName.c_str());return (const char*)buffer;}
	/*The amount of a particle's velocity parallel to a surface that is lost in the collision*/
	DoubleID getFriction(){char buffer[4096];sprintf_s (buffer, "%s.fri",mName.c_str());return (const char*)buffer;}
	/*The distance from the surface particle will be offset on reflection*/
	DoubleID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.off",mName.c_str());return (const char*)buffer;}
protected:
	GeoConnector(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GEOCONNECTOR_H__
