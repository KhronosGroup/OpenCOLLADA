/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NUCLEUS_H__
#define __MayaDM_NUCLEUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> This is the generic solver node for different nThings
 For now nCloth, but later nParticles, nRigidBodies....
</pre></p>
*/
class Nucleus : public DependNode
{
public:
public:
	Nucleus(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "nucleus"){}
	virtual ~Nucleus(){}
	/*
	Input start eval connection from active nObjects. This should be connected
	from the eval start output of all the active nObjects simulated by this solver.
	Valid inputs are nCloth, dynamicConstraints, nParticle, etc.
	*/
	void setInputStart(size_t is_i,const NIdID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is[%i]\";\n",mName.c_str(),is_i);}
	/*
	Input current position eval from active nObjects. This should be connected
	from the eval current output of all the active nObjects simulated by this solver.
	Valid inputs are nCloth, dynamicConstraints, nParticle, etc.
	*/
	void setInputCurrent(size_t ic_i,const NIdID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i]\";\n",mName.c_str(),ic_i);}
	/*
	Input nData from active  nThings. This should be connected
	from the output of all the active nThings simulated by this solver
	Valid inputs are nCloth (nParticle, etc)
	*/
	void setInputActive(size_t niao_i,const GenericID& niao){fprintf_s(mFile,"connectAttr \"");niao.write(mFile);fprintf_s(mFile,"\" \"%s.niao[%i]\";\n",mName.c_str(),niao_i);}
	/*
	Input nData from passive  nThings. This should be connected
	from the output of all the passive nThings connected to this solver
	Valid inputs are polygons, nurbs surfaces, nurbs curves, and lattices.
	*/
	void setInputPassive(size_t nipo_i,const GenericID& nipo){fprintf_s(mFile,"connectAttr \"");nipo.write(mFile);fprintf_s(mFile,"\" \"%s.nipo[%i]\";\n",mName.c_str(),nipo_i);}
	/*
	Input nData from active  nThings. This should be connected
	from the output of all the active nThings simulated by this solver
	Valid inputs are nCloth (nParticle, etc)
	*/
	void setInputActiveStart(size_t nias_i,const GenericID& nias){fprintf_s(mFile,"connectAttr \"");nias.write(mFile);fprintf_s(mFile,"\" \"%s.nias[%i]\";\n",mName.c_str(),nias_i);}
	/*
	Input nData from passive  nThings. This should be connected
	from the output of all the passive nThings connected to this solver
	Valid inputs are polygons, nurbs surfaces, nurbs curves, and lattices.
	*/
	void setInputPassiveStart(size_t nips_i,const GenericID& nips){fprintf_s(mFile,"connectAttr \"");nips.write(mFile);fprintf_s(mFile,"\" \"%s.nips[%i]\";\n",mName.c_str(),nips_i);}
	/*Output Geometry for soft body.*/
	void setOutputObjects(size_t noao_i,const GenericID& noao){fprintf_s(mFile,"connectAttr \"");noao.write(mFile);fprintf_s(mFile,"\" \"%s.noao[%i]\";\n",mName.c_str(),noao_i);}
	/*
	This is the current time used for the nucleus solve.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.  There must be some incoming connection in order
	for the solve to take place and connected objects to play back.
	*/
	void setCurrentTime(const TimeID& cti){fprintf_s(mFile,"connectAttr \"");cti.write(mFile);fprintf_s(mFile,"\" \"%s.cti\";\n",mName.c_str());}
	/*The actual time of the start frame at the current frame rate.*/
	void setStartTime(const TimeID& sti){fprintf_s(mFile,"connectAttr \"");sti.write(mFile);fprintf_s(mFile,"\" \"%s.sti\";\n",mName.c_str());}
	/*
	The frame at which the solver will initialize and start solving.
	This attribute gets connected to all the objects controlled by
	this solver so that the start of the solve is synchronized.
	*/
	void setStartFrame(double stf){if(stf == 1.0) return; fprintf_s(mFile, "setAttr \".stf\" %f;\n", stf);}
	/*
	The frame at which the solver will initialize and start solving.
	This attribute gets connected to all the objects controlled by
	this solver so that the start of the solve is synchronized.
	*/
	void setStartFrame(const DoubleID& stf){fprintf_s(mFile,"connectAttr \"");stf.write(mFile);fprintf_s(mFile,"\" \"%s.stf\";\n",mName.c_str());}
	/*Toggle dynamics on/off for all the dynamic nThings using this solver*/
	void setEnable(bool ena){if(ena == true) return; fprintf_s(mFile, "setAttr \".ena\" %i;\n", ena);}
	/*Toggle dynamics on/off for all the dynamic nThings using this solver*/
	void setEnable(const BoolID& ena){fprintf_s(mFile,"connectAttr \"");ena.write(mFile);fprintf_s(mFile,"\" \"%s.ena\";\n",mName.c_str());}
	/*Defines the gravity affecting this nucleus*/
	void setGravity(float grty){if(grty == 9.8) return; fprintf_s(mFile, "setAttr \".grty\" %f;\n", grty);}
	/*Defines the gravity affecting this nucleus*/
	void setGravity(const FloatID& grty){fprintf_s(mFile,"connectAttr \"");grty.write(mFile);fprintf_s(mFile,"\" \"%s.grty\";\n",mName.c_str());}
	/*Defines the gravity direction affecting this nParticle system*/
	void setGravityDirection(const float3& grdi){fprintf_s(mFile, "setAttr \".grdi\" -type \"float3\" ");grdi.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the gravity direction affecting this nParticle system*/
	void setGravityDirection(const Float3ID& grdi){fprintf_s(mFile,"connectAttr \"");grdi.write(mFile);fprintf_s(mFile,"\" \"%s.grdi\";\n",mName.c_str());}
	/*Defines the x component of the gravity direction.*/
	void setGravityDirectionX(float grdx){if(grdx == 0.0) return; fprintf_s(mFile, "setAttr \".grdi.grdx\" %f;\n", grdx);}
	/*Defines the x component of the gravity direction.*/
	void setGravityDirectionX(const FloatID& grdx){fprintf_s(mFile,"connectAttr \"");grdx.write(mFile);fprintf_s(mFile,"\" \"%s.grdi.grdx\";\n",mName.c_str());}
	/*Defines the y component of the gravity direction.*/
	void setGravityDirectionY(float grdy){if(grdy == -1.0) return; fprintf_s(mFile, "setAttr \".grdi.grdy\" %f;\n", grdy);}
	/*Defines the y component of the gravity direction.*/
	void setGravityDirectionY(const FloatID& grdy){fprintf_s(mFile,"connectAttr \"");grdy.write(mFile);fprintf_s(mFile,"\" \"%s.grdi.grdy\";\n",mName.c_str());}
	/*Defines the z component of the gravity direction.*/
	void setGravityDirectionZ(float grdz){if(grdz == 0.0) return; fprintf_s(mFile, "setAttr \".grdi.grdz\" %f;\n", grdz);}
	/*Defines the z component of the gravity direction.*/
	void setGravityDirectionZ(const FloatID& grdz){fprintf_s(mFile,"connectAttr \"");grdz.write(mFile);fprintf_s(mFile,"\" \"%s.grdi.grdz\";\n",mName.c_str());}
	/*Defines the air density affecting this dynamic system*/
	void setAirDensity(float ady){if(ady == 1.0) return; fprintf_s(mFile, "setAttr \".ady\" %f;\n", ady);}
	/*Defines the air density affecting this dynamic system*/
	void setAirDensity(const FloatID& ady){fprintf_s(mFile,"connectAttr \"");ady.write(mFile);fprintf_s(mFile,"\" \"%s.ady\";\n",mName.c_str());}
	/*Defines the wind speed affecting this nParticle system*/
	void setWindSpeed(float wisp){if(wisp == 0.0) return; fprintf_s(mFile, "setAttr \".wisp\" %f;\n", wisp);}
	/*Defines the wind speed affecting this nParticle system*/
	void setWindSpeed(const FloatID& wisp){fprintf_s(mFile,"connectAttr \"");wisp.write(mFile);fprintf_s(mFile,"\" \"%s.wisp\";\n",mName.c_str());}
	/*Defines the wind direction affecting this nParticle system*/
	void setWindDirection(const float3& widi){fprintf_s(mFile, "setAttr \".widi\" -type \"float3\" ");widi.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the wind direction affecting this nParticle system*/
	void setWindDirection(const Float3ID& widi){fprintf_s(mFile,"connectAttr \"");widi.write(mFile);fprintf_s(mFile,"\" \"%s.widi\";\n",mName.c_str());}
	/*Defines the x component of the wind direction.*/
	void setWindDirectionX(float widx){if(widx == 1.0) return; fprintf_s(mFile, "setAttr \".widi.widx\" %f;\n", widx);}
	/*Defines the x component of the wind direction.*/
	void setWindDirectionX(const FloatID& widx){fprintf_s(mFile,"connectAttr \"");widx.write(mFile);fprintf_s(mFile,"\" \"%s.widi.widx\";\n",mName.c_str());}
	/*Defines the y component of the wind direction.*/
	void setWindDirectionY(float widy){if(widy == 0.0) return; fprintf_s(mFile, "setAttr \".widi.widy\" %f;\n", widy);}
	/*Defines the y component of the wind direction.*/
	void setWindDirectionY(const FloatID& widy){fprintf_s(mFile,"connectAttr \"");widy.write(mFile);fprintf_s(mFile,"\" \"%s.widi.widy\";\n",mName.c_str());}
	/*Defines the z component of the wind direction.*/
	void setWindDirectionZ(float widz){if(widz == 0.0) return; fprintf_s(mFile, "setAttr \".widi.widz\" %f;\n", widz);}
	/*Defines the z component of the wind direction.*/
	void setWindDirectionZ(const FloatID& widz){fprintf_s(mFile,"connectAttr \"");widz.write(mFile);fprintf_s(mFile,"\" \"%s.widi.widz\";\n",mName.c_str());}
	/*Defines the wind randomization affecting this nParticle system*/
	void setWindNoise(float wnoi){if(wnoi == 0.0) return; fprintf_s(mFile, "setAttr \".wnoi\" %f;\n", wnoi);}
	/*Defines the wind randomization affecting this nParticle system*/
	void setWindNoise(const FloatID& wnoi){fprintf_s(mFile,"connectAttr \"");wnoi.write(mFile);fprintf_s(mFile,"\" \"%s.wnoi\";\n",mName.c_str());}
	/*
	This defines how close the collisionLayer value for two objects
	needs to be in order for them to intercollide. For example if
	one object has a collisionLayer value of 2 and the other 5, then
	they will collide as long the collisionLayerRange is greater than 3.
	*/
	void setCollisionLayerRange(float clra){if(clra == 4.0) return; fprintf_s(mFile, "setAttr \".clra\" %f;\n", clra);}
	/*
	This defines how close the collisionLayer value for two objects
	needs to be in order for them to intercollide. For example if
	one object has a collisionLayer value of 2 and the other 5, then
	they will collide as long the collisionLayerRange is greater than 3.
	*/
	void setCollisionLayerRange(const FloatID& clra){fprintf_s(mFile,"connectAttr \"");clra.write(mFile);fprintf_s(mFile,"\" \"%s.clra\";\n",mName.c_str());}
	/*This defines how much collisions can interpenetrate the thickness*/
	void setCollisionSoftness(float clso){if(clso == 0.0) return; fprintf_s(mFile, "setAttr \".clso\" %f;\n", clso);}
	/*This defines how much collisions can interpenetrate the thickness*/
	void setCollisionSoftness(const FloatID& clso){fprintf_s(mFile,"connectAttr \"");clso.write(mFile);fprintf_s(mFile,"\" \"%s.clso\";\n",mName.c_str());}
	/*Defines whether or not we use a plane in the collision system*/
	void setUsePlane(bool nupl){if(nupl == false) return; fprintf_s(mFile, "setAttr \".nupl\" %i;\n", nupl);}
	/*Defines whether or not we use a plane in the collision system*/
	void setUsePlane(const BoolID& nupl){fprintf_s(mFile,"connectAttr \"");nupl.write(mFile);fprintf_s(mFile,"\" \"%s.nupl\";\n",mName.c_str());}
	/*Defines the origin of the plane in the collision system*/
	void setPlaneOrigin(const float3& npor){fprintf_s(mFile, "setAttr \".npor\" -type \"float3\" ");npor.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the origin of the plane in the collision system*/
	void setPlaneOrigin(const Float3ID& npor){fprintf_s(mFile,"connectAttr \"");npor.write(mFile);fprintf_s(mFile,"\" \"%s.npor\";\n",mName.c_str());}
	/*Defines the x component of the plane origin.*/
	void setPlaneOriginX(float npox){if(npox == 0.0) return; fprintf_s(mFile, "setAttr \".npor.npox\" %f;\n", npox);}
	/*Defines the x component of the plane origin.*/
	void setPlaneOriginX(const FloatID& npox){fprintf_s(mFile,"connectAttr \"");npox.write(mFile);fprintf_s(mFile,"\" \"%s.npor.npox\";\n",mName.c_str());}
	/*Defines the y component of the plane origin.*/
	void setPlaneOriginY(float npoy){if(npoy == 0.0) return; fprintf_s(mFile, "setAttr \".npor.npoy\" %f;\n", npoy);}
	/*Defines the y component of the plane origin.*/
	void setPlaneOriginY(const FloatID& npoy){fprintf_s(mFile,"connectAttr \"");npoy.write(mFile);fprintf_s(mFile,"\" \"%s.npor.npoy\";\n",mName.c_str());}
	/*Defines the z component of the plane origin.*/
	void setPlaneOriginZ(float npoz){if(npoz == 0.0) return; fprintf_s(mFile, "setAttr \".npor.npoz\" %f;\n", npoz);}
	/*Defines the z component of the plane origin.*/
	void setPlaneOriginZ(const FloatID& npoz){fprintf_s(mFile,"connectAttr \"");npoz.write(mFile);fprintf_s(mFile,"\" \"%s.npor.npoz\";\n",mName.c_str());}
	/*Defines the (unit) normal of the plane in the collision system*/
	void setPlaneNormal(const float3& npun){fprintf_s(mFile, "setAttr \".npun\" -type \"float3\" ");npun.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the (unit) normal of the plane in the collision system*/
	void setPlaneNormal(const Float3ID& npun){fprintf_s(mFile,"connectAttr \"");npun.write(mFile);fprintf_s(mFile,"\" \"%s.npun\";\n",mName.c_str());}
	/*Defines the x component of the plane normal.*/
	void setPlaneNormalX(float npnx){if(npnx == 0.0) return; fprintf_s(mFile, "setAttr \".npun.npnx\" %f;\n", npnx);}
	/*Defines the x component of the plane normal.*/
	void setPlaneNormalX(const FloatID& npnx){fprintf_s(mFile,"connectAttr \"");npnx.write(mFile);fprintf_s(mFile,"\" \"%s.npun.npnx\";\n",mName.c_str());}
	/*Defines the y component of the plane normal.*/
	void setPlaneNormalY(float npny){if(npny == 1.0) return; fprintf_s(mFile, "setAttr \".npun.npny\" %f;\n", npny);}
	/*Defines the y component of the plane normal.*/
	void setPlaneNormalY(const FloatID& npny){fprintf_s(mFile,"connectAttr \"");npny.write(mFile);fprintf_s(mFile,"\" \"%s.npun.npny\";\n",mName.c_str());}
	/*Defines the z component of the plane normal.*/
	void setPlaneNormalZ(float npnz){if(npnz == 0.0) return; fprintf_s(mFile, "setAttr \".npun.npnz\" %f;\n", npnz);}
	/*Defines the z component of the plane normal.*/
	void setPlaneNormalZ(const FloatID& npnz){fprintf_s(mFile,"connectAttr \"");npnz.write(mFile);fprintf_s(mFile,"\" \"%s.npun.npnz\";\n",mName.c_str());}
	/*Defines the plane bounce*/
	void setPlaneBounce(float npbc){if(npbc == 0.0) return; fprintf_s(mFile, "setAttr \".npbc\" %f;\n", npbc);}
	/*Defines the plane bounce*/
	void setPlaneBounce(const FloatID& npbc){fprintf_s(mFile,"connectAttr \"");npbc.write(mFile);fprintf_s(mFile,"\" \"%s.npbc\";\n",mName.c_str());}
	/*Defines the plane friction*/
	void setPlaneFriction(float npfr){if(npfr == 0.1) return; fprintf_s(mFile, "setAttr \".npfr\" %f;\n", npfr);}
	/*Defines the plane friction*/
	void setPlaneFriction(const FloatID& npfr){fprintf_s(mFile,"connectAttr \"");npfr.write(mFile);fprintf_s(mFile,"\" \"%s.npfr\";\n",mName.c_str());}
	/*Number of subSteps for each solve step.*/
	void setSubSteps(int sstp){if(sstp == 3) return; fprintf_s(mFile, "setAttr \".sstp\" %i;\n", sstp);}
	/*Number of subSteps for each solve step.*/
	void setSubSteps(const IntID& sstp){fprintf_s(mFile,"connectAttr \"");sstp.write(mFile);fprintf_s(mFile,"\" \"%s.sstp\";\n",mName.c_str());}
	/*Maximum number of collision iterations per subStep.*/
	void setMaxCollisionIterations(int mcit){if(mcit == 4) return; fprintf_s(mFile, "setAttr \".mcit\" %i;\n", mcit);}
	/*Maximum number of collision iterations per subStep.*/
	void setMaxCollisionIterations(const IntID& mcit){fprintf_s(mFile,"connectAttr \"");mcit.write(mFile);fprintf_s(mFile,"\" \"%s.mcit\";\n",mName.c_str());}
	/*Controls the type(s) of collisions that are processed.*/
	void setCollisionFlag(unsigned int cofl){if(cofl == 4) return; fprintf_s(mFile, "setAttr \".cofl\" %i;\n", cofl);}
	/*Controls the type(s) of collisions that are processed.*/
	void setCollisionFlag(const UnsignedintID& cofl){fprintf_s(mFile,"connectAttr \"");cofl.write(mFile);fprintf_s(mFile,"\" \"%s.cofl\";\n",mName.c_str());}
	/*Controls the type(s) of self-collisions that are processed*/
	void setSelfCollisionFlag(unsigned int scfl){if(scfl == 1) return; fprintf_s(mFile, "setAttr \".scfl\" %i;\n", scfl);}
	/*Controls the type(s) of self-collisions that are processed*/
	void setSelfCollisionFlag(const UnsignedintID& scfl){fprintf_s(mFile,"connectAttr \"");scfl.write(mFile);fprintf_s(mFile,"\" \"%s.scfl\";\n",mName.c_str());}
	/*Scale the timestep that the solver uses.*/
	void setTimeScale(float tisc){if(tisc == 1.0) return; fprintf_s(mFile, "setAttr \".tisc\" %f;\n", tisc);}
	/*Scale the timestep that the solver uses.*/
	void setTimeScale(const FloatID& tisc){fprintf_s(mFile,"connectAttr \"");tisc.write(mFile);fprintf_s(mFile,"\" \"%s.tisc\";\n",mName.c_str());}
	/*
	Pretend that the the object is a scale model, and apply forces
	internally so that you get the expected behavior for the actual sized model
	*/
	void setSpaceScale(float spsc){if(spsc == 1.0) return; fprintf_s(mFile, "setAttr \".spsc\" %f;\n", spsc);}
	/*
	Pretend that the the object is a scale model, and apply forces
	internally so that you get the expected behavior for the actual sized model
	*/
	void setSpaceScale(const FloatID& spsc){fprintf_s(mFile,"connectAttr \"");spsc.write(mFile);fprintf_s(mFile,"\" \"%s.spsc\";\n",mName.c_str());}
	/*
	Input start eval connection from active nObjects. This should be connected
	from the eval start output of all the active nObjects simulated by this solver.
	Valid inputs are nCloth, dynamicConstraints, nParticle, etc.
	*/
	const NIdID& getInputStart(size_t is_i){char buffer[4096];sprintf_s (buffer, "%s.is[%i]",mName.c_str(),is_i);return (const char*)buffer;}
	/*
	Input current position eval from active nObjects. This should be connected
	from the eval current output of all the active nObjects simulated by this solver.
	Valid inputs are nCloth, dynamicConstraints, nParticle, etc.
	*/
	const NIdID& getInputCurrent(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i]",mName.c_str(),ic_i);return (const char*)buffer;}
	/*
	Input nData from active  nThings. This should be connected
	from the output of all the active nThings simulated by this solver
	Valid inputs are nCloth (nParticle, etc)
	*/
	const GenericID& getInputActive(size_t niao_i){char buffer[4096];sprintf_s (buffer, "%s.niao[%i]",mName.c_str(),niao_i);return (const char*)buffer;}
	/*
	Input nData from passive  nThings. This should be connected
	from the output of all the passive nThings connected to this solver
	Valid inputs are polygons, nurbs surfaces, nurbs curves, and lattices.
	*/
	const GenericID& getInputPassive(size_t nipo_i){char buffer[4096];sprintf_s (buffer, "%s.nipo[%i]",mName.c_str(),nipo_i);return (const char*)buffer;}
	/*
	Input nData from active  nThings. This should be connected
	from the output of all the active nThings simulated by this solver
	Valid inputs are nCloth (nParticle, etc)
	*/
	const GenericID& getInputActiveStart(size_t nias_i){char buffer[4096];sprintf_s (buffer, "%s.nias[%i]",mName.c_str(),nias_i);return (const char*)buffer;}
	/*
	Input nData from passive  nThings. This should be connected
	from the output of all the passive nThings connected to this solver
	Valid inputs are polygons, nurbs surfaces, nurbs curves, and lattices.
	*/
	const GenericID& getInputPassiveStart(size_t nips_i){char buffer[4096];sprintf_s (buffer, "%s.nips[%i]",mName.c_str(),nips_i);return (const char*)buffer;}
	/*Output Geometry for soft body.*/
	const GenericID& getOutputObjects(size_t noao_i){char buffer[4096];sprintf_s (buffer, "%s.noao[%i]",mName.c_str(),noao_i);return (const char*)buffer;}
	/*
	This is the current time used for the nucleus solve.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.  There must be some incoming connection in order
	for the solve to take place and connected objects to play back.
	*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.cti",mName.c_str());return (const char*)buffer;}
	/*The actual time of the start frame at the current frame rate.*/
	TimeID getStartTime(){char buffer[4096];sprintf_s (buffer, "%s.sti",mName.c_str());return (const char*)buffer;}
	/*
	The frame at which the solver will initialize and start solving.
	This attribute gets connected to all the objects controlled by
	this solver so that the start of the solve is synchronized.
	*/
	DoubleID getStartFrame(){char buffer[4096];sprintf_s (buffer, "%s.stf",mName.c_str());return (const char*)buffer;}
	/*Toggle dynamics on/off for all the dynamic nThings using this solver*/
	BoolID getEnable(){char buffer[4096];sprintf_s (buffer, "%s.ena",mName.c_str());return (const char*)buffer;}
	/*Defines the gravity affecting this nucleus*/
	FloatID getGravity(){char buffer[4096];sprintf_s (buffer, "%s.grty",mName.c_str());return (const char*)buffer;}
	/*Defines the gravity direction affecting this nParticle system*/
	Float3ID getGravityDirection(){char buffer[4096];sprintf_s (buffer, "%s.grdi",mName.c_str());return (const char*)buffer;}
	/*Defines the x component of the gravity direction.*/
	FloatID getGravityDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.grdi.grdx",mName.c_str());return (const char*)buffer;}
	/*Defines the y component of the gravity direction.*/
	FloatID getGravityDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.grdi.grdy",mName.c_str());return (const char*)buffer;}
	/*Defines the z component of the gravity direction.*/
	FloatID getGravityDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.grdi.grdz",mName.c_str());return (const char*)buffer;}
	/*Defines the air density affecting this dynamic system*/
	FloatID getAirDensity(){char buffer[4096];sprintf_s (buffer, "%s.ady",mName.c_str());return (const char*)buffer;}
	/*Defines the wind speed affecting this nParticle system*/
	FloatID getWindSpeed(){char buffer[4096];sprintf_s (buffer, "%s.wisp",mName.c_str());return (const char*)buffer;}
	/*Defines the wind direction affecting this nParticle system*/
	Float3ID getWindDirection(){char buffer[4096];sprintf_s (buffer, "%s.widi",mName.c_str());return (const char*)buffer;}
	/*Defines the x component of the wind direction.*/
	FloatID getWindDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.widi.widx",mName.c_str());return (const char*)buffer;}
	/*Defines the y component of the wind direction.*/
	FloatID getWindDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.widi.widy",mName.c_str());return (const char*)buffer;}
	/*Defines the z component of the wind direction.*/
	FloatID getWindDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.widi.widz",mName.c_str());return (const char*)buffer;}
	/*Defines the wind randomization affecting this nParticle system*/
	FloatID getWindNoise(){char buffer[4096];sprintf_s (buffer, "%s.wnoi",mName.c_str());return (const char*)buffer;}
	/*
	This defines how close the collisionLayer value for two objects
	needs to be in order for them to intercollide. For example if
	one object has a collisionLayer value of 2 and the other 5, then
	they will collide as long the collisionLayerRange is greater than 3.
	*/
	FloatID getCollisionLayerRange(){char buffer[4096];sprintf_s (buffer, "%s.clra",mName.c_str());return (const char*)buffer;}
	/*This defines how much collisions can interpenetrate the thickness*/
	FloatID getCollisionSoftness(){char buffer[4096];sprintf_s (buffer, "%s.clso",mName.c_str());return (const char*)buffer;}
	/*Defines whether or not we use a plane in the collision system*/
	BoolID getUsePlane(){char buffer[4096];sprintf_s (buffer, "%s.nupl",mName.c_str());return (const char*)buffer;}
	/*Defines the origin of the plane in the collision system*/
	Float3ID getPlaneOrigin(){char buffer[4096];sprintf_s (buffer, "%s.npor",mName.c_str());return (const char*)buffer;}
	/*Defines the x component of the plane origin.*/
	FloatID getPlaneOriginX(){char buffer[4096];sprintf_s (buffer, "%s.npor.npox",mName.c_str());return (const char*)buffer;}
	/*Defines the y component of the plane origin.*/
	FloatID getPlaneOriginY(){char buffer[4096];sprintf_s (buffer, "%s.npor.npoy",mName.c_str());return (const char*)buffer;}
	/*Defines the z component of the plane origin.*/
	FloatID getPlaneOriginZ(){char buffer[4096];sprintf_s (buffer, "%s.npor.npoz",mName.c_str());return (const char*)buffer;}
	/*Defines the (unit) normal of the plane in the collision system*/
	Float3ID getPlaneNormal(){char buffer[4096];sprintf_s (buffer, "%s.npun",mName.c_str());return (const char*)buffer;}
	/*Defines the x component of the plane normal.*/
	FloatID getPlaneNormalX(){char buffer[4096];sprintf_s (buffer, "%s.npun.npnx",mName.c_str());return (const char*)buffer;}
	/*Defines the y component of the plane normal.*/
	FloatID getPlaneNormalY(){char buffer[4096];sprintf_s (buffer, "%s.npun.npny",mName.c_str());return (const char*)buffer;}
	/*Defines the z component of the plane normal.*/
	FloatID getPlaneNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.npun.npnz",mName.c_str());return (const char*)buffer;}
	/*Defines the plane bounce*/
	FloatID getPlaneBounce(){char buffer[4096];sprintf_s (buffer, "%s.npbc",mName.c_str());return (const char*)buffer;}
	/*Defines the plane friction*/
	FloatID getPlaneFriction(){char buffer[4096];sprintf_s (buffer, "%s.npfr",mName.c_str());return (const char*)buffer;}
	/*Number of subSteps for each solve step.*/
	IntID getSubSteps(){char buffer[4096];sprintf_s (buffer, "%s.sstp",mName.c_str());return (const char*)buffer;}
	/*Maximum number of collision iterations per subStep.*/
	IntID getMaxCollisionIterations(){char buffer[4096];sprintf_s (buffer, "%s.mcit",mName.c_str());return (const char*)buffer;}
	/*Controls the type(s) of collisions that are processed.*/
	UnsignedintID getCollisionFlag(){char buffer[4096];sprintf_s (buffer, "%s.cofl",mName.c_str());return (const char*)buffer;}
	/*Controls the type(s) of self-collisions that are processed*/
	UnsignedintID getSelfCollisionFlag(){char buffer[4096];sprintf_s (buffer, "%s.scfl",mName.c_str());return (const char*)buffer;}
	/*Scale the timestep that the solver uses.*/
	FloatID getTimeScale(){char buffer[4096];sprintf_s (buffer, "%s.tisc",mName.c_str());return (const char*)buffer;}
	/*
	Pretend that the the object is a scale model, and apply forces
	internally so that you get the expected behavior for the actual sized model
	*/
	FloatID getSpaceScale(){char buffer[4096];sprintf_s (buffer, "%s.spsc",mName.c_str());return (const char*)buffer;}
protected:
	Nucleus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NUCLEUS_H__
