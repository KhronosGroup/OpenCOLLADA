/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLE_H__
#define __MayaDM_PARTICLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformableShape.h"
namespace MayaDM
{
/*
<p><pre>The particle node implements a particle object (a collection of particles).
It uses the position, velocity, acceleration (and mass, if the user adds it)
attributes to compute dynamics for the particles.   It also has attributes
to define goal forces for the particles and to write per-particle expressions
for the particles.  To save memory, many attributes are added dynamically
as the user needs them: these include lifespan, color, goals, and most
rendering attributes.  The particle node also maintains the collection of
collision events which has been defined for this object, and resolves the
effect of those events as collisions occur.
</pre></p>
*/
class Particle : public DeformableShape
{
public:
	/*
	This compound holds the mapping information for the particle
	ID values.
	*/
	struct IdMapping{
		void write(FILE* file) const
		{
		}
	};
	/*
	This is the compound that holds all of the default attribute for the
	fields to connect to.  The contents are just sharing the data from
	the real attributes.
	*/
	struct FieldData{
		void write(FILE* file) const
		{
		}
	};
	/*
	This is the compound that holds all of the default attribute for the
	emitters to connect to.  The contents are just sharing the data from
	the real attributes.
	*/
	struct EmitterData{
		void write(FILE* file) const
		{
		}
	};
	/*Parent attribute for all collision input data.*/
	struct CollisionData{
		void write(FILE* file) const
		{
		}
	};
	/*
	This compound attribute groups together the attributes that provide data about
	instanced particles to the instancer node, or other node that can make use of
	this info.
	*/
	struct InstanceData{
		stringArray instanceAttributeMapping;
		void write(FILE* file) const
		{
			instanceAttributeMapping.write(file);
			fprintf_s(file, " ");
		}
	};
	/*This is a root of following mental ray attributes.*/
	struct MentalRayControls{
		bool miOverrideCaustics;
		short miCausticAccuracy;
		float miCausticRadius;
		bool miOverrideGlobalIllumination;
		short miGlobillumAccuracy;
		float miGlobillumRadius;
		bool miOverrideFinalGather;
		int miFinalGatherRays;
		float miFinalGatherMinRadius;
		float miFinalGatherMaxRadius;
		short miFinalGatherFilter;
		bool miFinalGatherView;
		bool miOverrideSamples;
		short miMinSamples;
		short miMaxSamples;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", miOverrideCaustics);
			fprintf_s(file,"%i ", miCausticAccuracy);
			fprintf_s(file,"%f ", miCausticRadius);
			fprintf_s(file,"%i ", miOverrideGlobalIllumination);
			fprintf_s(file,"%i ", miGlobillumAccuracy);
			fprintf_s(file,"%f ", miGlobillumRadius);
			fprintf_s(file,"%i ", miOverrideFinalGather);
			fprintf_s(file,"%i ", miFinalGatherRays);
			fprintf_s(file,"%f ", miFinalGatherMinRadius);
			fprintf_s(file,"%f ", miFinalGatherMaxRadius);
			fprintf_s(file,"%i ", miFinalGatherFilter);
			fprintf_s(file,"%i ", miFinalGatherView);
			fprintf_s(file,"%i ", miOverrideSamples);
			fprintf_s(file,"%i ", miMinSamples);
			fprintf_s(file,"%i", miMaxSamples);
		}
	};
public:
	Particle(FILE* file,const std::string& name,const std::string& parent=""):DeformableShape(file, name, parent, "particle"){}
	virtual ~Particle(){}
	/*
	Runtime state, positions in object-space at the end of the time-step, per-particle.
	Requesting this attribute will force the dynamics to be solved.
	*/
	void setPosition(const VectorArrayID& pos){fprintf_s(mFile,"connectAttr \"");pos.write(mFile);fprintf_s(mFile,"\" \"%s.pos\";\n",mName.c_str());}
	/*
	Use this attribute to control position by a ramp.
	The values from this attribute will be copied into "position"
	before each step in the dynamics simulation.
	*/
	void setRampPosition(const VectorArrayID& rps){fprintf_s(mFile,"connectAttr \"");rps.write(mFile);fprintf_s(mFile,"\" \"%s.rps\";\n",mName.c_str());}
	/*
	Centroid (average position) of the particles.
	This is in local coordinates. See also worldCentroid.
	*/
	void setCentroid(const Double3ID& ctd){fprintf_s(mFile,"connectAttr \"");ctd.write(mFile);fprintf_s(mFile,"\" \"%s.ctd\";\n",mName.c_str());}
	/*
	X-component of centroid (average position) of the particles.
	This is in local coordinates. See also worldCentroid.
	*/
	void setCentroidX(const DoubleID& ctdx){fprintf_s(mFile,"connectAttr \"");ctdx.write(mFile);fprintf_s(mFile,"\" \"%s.ctd.ctdx\";\n",mName.c_str());}
	/*
	Y-component of centroid (average position) of the particles.
	This is in local coordinates. See also worldCentroid.
	*/
	void setCentroidY(const DoubleID& ctdy){fprintf_s(mFile,"connectAttr \"");ctdy.write(mFile);fprintf_s(mFile,"\" \"%s.ctd.ctdy\";\n",mName.c_str());}
	/*
	Z-component of centroid (average position) of the particles.
	This is in local coordinates. See also worldCentroid.
	*/
	void setCentroidZ(const DoubleID& ctdz){fprintf_s(mFile,"connectAttr \"");ctdz.write(mFile);fprintf_s(mFile,"\" \"%s.ctd.ctdz\";\n",mName.c_str());}
	/*
	The position of the particles at the end of the previous
	timestep.  This attribute does force the evaluation of
	dynamics.
	*/
	void setLastPosition(const VectorArrayID& lpos){fprintf_s(mFile,"connectAttr \"");lpos.write(mFile);fprintf_s(mFile,"\" \"%s.lpos\";\n",mName.c_str());}
	/*Runtime state, velocities at the end of the time-step, per-particle.*/
	void setVelocity(const VectorArrayID& vel){fprintf_s(mFile,"connectAttr \"");vel.write(mFile);fprintf_s(mFile,"\" \"%s.vel\";\n",mName.c_str());}
	/*
	Use this attribute to control velocity with a ramp.
	The values from this attribute will be copied into "velocity"
	before each step in the dynamics simulation.
	*/
	void setRampVelocity(const VectorArrayID& rvl){fprintf_s(mFile,"connectAttr \"");rvl.write(mFile);fprintf_s(mFile,"\" \"%s.rvl\";\n",mName.c_str());}
	/*
	The velocity at the end of the previous solving step.
	This will have its value set at the END of the previous solving step.
	*/
	void setLastVelocity(const VectorArrayID& lvel){fprintf_s(mFile,"connectAttr \"");lvel.write(mFile);fprintf_s(mFile,"\" \"%s.lvel\";\n",mName.c_str());}
	/*Runtime state, accelerations, per-particle.*/
	void setAcceleration(const VectorArrayID& acc){fprintf_s(mFile,"connectAttr \"");acc.write(mFile);fprintf_s(mFile,"\" \"%s.acc\";\n",mName.c_str());}
	/*
	This is where all ramps input "acceleration" will actually connect.
	The values from this attribute will be copied into "acceleration"
	before each step in the dynamics simulation.
	*/
	void setRampAcceleration(const VectorArrayID& rac){fprintf_s(mFile,"connectAttr \"");rac.write(mFile);fprintf_s(mFile,"\" \"%s.rac\";\n",mName.c_str());}
	/*
	The effects of fields, goals, etc. on the particles are
	accumulated in this attribute.
	*/
	void setForce(const VectorArrayID& frc){fprintf_s(mFile,"connectAttr \"");frc.write(mFile);fprintf_s(mFile,"\" \"%s.frc\";\n",mName.c_str());}
	/*
	This is the input multi-attribute where any fields acting on
	this particle object are connected.  These are accumulated
	in the computePlug() section for aForce, along with other
	forces like goals.
	*/
	void setInputForce(size_t ifc_i,const VectorArrayID& ifc){fprintf_s(mFile,"connectAttr \"");ifc.write(mFile);fprintf_s(mFile,"\" \"%s.ifc[%i]\";\n",mName.c_str(),ifc_i);}
	/*
	This is the world-space position of the particles at the end of the time-step.
	Requesting this attribute will force the dynamics to be solved.
	*/
	void setWorldPosition(const VectorArrayID& wps){fprintf_s(mFile,"connectAttr \"");wps.write(mFile);fprintf_s(mFile,"\" \"%s.wps\";\n",mName.c_str());}
	/*
	World-space centroid (average position) of the particles.
	This is in world coordinates. See also "centroid."
	*/
	void setWorldCentroid(const Double3ID& wctn){fprintf_s(mFile,"connectAttr \"");wctn.write(mFile);fprintf_s(mFile,"\" \"%s.wctn\";\n",mName.c_str());}
	/*
	X-component of world centroid (average position) of the particles.
	This is in world coordinates. See also "centroid."
	*/
	void setWorldCentroidX(const DoubleID& wctx){fprintf_s(mFile,"connectAttr \"");wctx.write(mFile);fprintf_s(mFile,"\" \"%s.wctn.wctx\";\n",mName.c_str());}
	/*
	Y-component of world centroid (average position)of the particles.
	This is in world coordinates. See also "centroid."
	*/
	void setWorldCentroidY(const DoubleID& wcty){fprintf_s(mFile,"connectAttr \"");wcty.write(mFile);fprintf_s(mFile,"\" \"%s.wctn.wcty\";\n",mName.c_str());}
	/*
	Z-component of world centroid (average position) of the particles.
	This is in world coordinates. See also "centroid."
	*/
	void setWorldCentroidZ(const DoubleID& wctz){fprintf_s(mFile,"connectAttr \"");wctz.write(mFile);fprintf_s(mFile,"\" \"%s.wctn.wctz\";\n",mName.c_str());}
	/*
	The world-space position of the particles at the end of the
	previous timestep.  This attribute does force the evaluation of
	dynamics.
	*/
	void setLastWorldPosition(const VectorArrayID& lwps){fprintf_s(mFile,"connectAttr \"");lwps.write(mFile);fprintf_s(mFile,"\" \"%s.lwps\";\n",mName.c_str());}
	/*
	This is the world-space velocity of the particles at the end of the time-step.
	This includes motion from the parent matrix.
	*/
	void setWorldVelocity(const VectorArrayID& wvl){fprintf_s(mFile,"connectAttr \"");wvl.write(mFile);fprintf_s(mFile,"\" \"%s.wvl\";\n",mName.c_str());}
	/*
	This is the world-space velocity of the particles as derived from dynamics
	and from motion of the world matrix.  THis value is then tranformed into
	object-space for drawing.
	*/
	void setWorldVelocityInObjectSpace(const VectorArrayID& wvo){fprintf_s(mFile,"connectAttr \"");wvo.write(mFile);fprintf_s(mFile,"\" \"%s.wvo\";\n",mName.c_str());}
	/*This is the world-space velocity from the end of the LAST time-step.*/
	void setLastWorldVelocity(const VectorArrayID& lwvl){fprintf_s(mFile,"connectAttr \"");lwvl.write(mFile);fprintf_s(mFile,"\" \"%s.lwvl\";\n",mName.c_str());}
	/*This is the world matrix from the last time evaluated (currentSceneTime - sceneTimeStepSize).*/
	void setLastWorldMatrix(const MatrixID& lwm){fprintf_s(mFile,"connectAttr \"");lwm.write(mFile);fprintf_s(mFile,"\" \"%s.lwm\";\n",mName.c_str());}
	/*Initial state, positions, per-particle.*/
	void setPosition0(const vectorArray& pos0){if(pos0.size == 0) return; fprintf_s(mFile, "setAttr \".pos0\" -type \"vectorArray\" ");pos0.write(mFile);fprintf_s(mFile,";\n");}
	/*Initial state, positions, per-particle.*/
	void setPosition0(const VectorArrayID& pos0){fprintf_s(mFile,"connectAttr \"");pos0.write(mFile);fprintf_s(mFile,"\" \"%s.pos0\";\n",mName.c_str());}
	/*Initial state, velocities, per-particle.*/
	void setVelocity0(const vectorArray& vel0){if(vel0.size == 0) return; fprintf_s(mFile, "setAttr \".vel0\" -type \"vectorArray\" ");vel0.write(mFile);fprintf_s(mFile,";\n");}
	/*Initial state, velocities, per-particle.*/
	void setVelocity0(const VectorArrayID& vel0){fprintf_s(mFile,"connectAttr \"");vel0.write(mFile);fprintf_s(mFile,"\" \"%s.vel0\";\n",mName.c_str());}
	/*Initial state, accelerations, per-particle.*/
	void setAcceleration0(const vectorArray& acc0){if(acc0.size == 0) return; fprintf_s(mFile, "setAttr \".acc0\" -type \"vectorArray\" ");acc0.write(mFile);fprintf_s(mFile,";\n");}
	/*Initial state, accelerations, per-particle.*/
	void setAcceleration0(const VectorArrayID& acc0){fprintf_s(mFile,"connectAttr \"");acc0.write(mFile);fprintf_s(mFile,"\" \"%s.acc0\";\n",mName.c_str());}
	/*
	This boolean attribute is used at file save and load.
	It records whether a runtime state has been stored in a
	startup cache file. If this attribute is true,
	Maya will use the values stored in that file instead of restoring
	the initial state and running up the scene.  If Maya cannot find
	the startup cache file or it does not contain valid data, Maya
	will run up the scene. Users normally do not set this attribute.
	Instead, use the dynamics preferences window to tell Maya to do
	all the necessary operations.  Just setting this attribute does
	not create the cache.
	*/
	void setUseStartupCache(bool usc){if(usc == false) return; fprintf_s(mFile, "setAttr \".usc\" %i;\n", usc);}
	/*
	This attribute holds the name of the file path on which to
	find the startup cache file (see useStartupCache). Users normally
	do not set this attribute.  Maya sets it when creating the cache.
	The path is always relative to the workspace particle data area.
	*/
	void setStartupCachePath(const string& scp){if(scp == "NULL") return; fprintf_s(mFile, "setAttr \".scp\" -type \"string\" ");scp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute holds the name of the file path on which to
	find the startup cache file (see useStartupCache). Users normally
	do not set this attribute.  Maya sets it when creating the cache.
	The path is always relative to the workspace particle data area.
	*/
	void setStartupCachePath(const StringID& scp){fprintf_s(mFile,"connectAttr \"");scp.write(mFile);fprintf_s(mFile,"\" \"%s.scp\";\n",mName.c_str());}
	/*
	Ifentifies the frame for which the current startup cache
	is valid. generally this will be the frame for which this
	object was most recently saved. Users notmally should not
	set this attribute.  Use the Dynamics option window to enable
	or disable startup cache.
	*/
	void setStartupCacheFrame(int scf){if(scf == 0) return; fprintf_s(mFile, "setAttr \".scf\" %i;\n", scf);}
	/*
	Ifentifies the frame for which the current startup cache
	is valid. generally this will be the frame for which this
	object was most recently saved. Users notmally should not
	set this attribute.  Use the Dynamics option window to enable
	or disable startup cache.
	*/
	void setStartupCacheFrame(const IntID& scf){fprintf_s(mFile,"connectAttr \"");scf.write(mFile);fprintf_s(mFile,"\" \"%s.scf\";\n",mName.c_str());}
	/*
	This will have its value set at the END of the solving step.
	This attribute shares the memory with aPosition and is the most
	current value of aPosition WITHOUT forcing evaluation of the
	dynamics.
	*/
	void setCachedPosition(const VectorArrayID& cpos){fprintf_s(mFile,"connectAttr \"");cpos.write(mFile);fprintf_s(mFile,"\" \"%s.cpos\";\n",mName.c_str());}
	/*
	This is the most current value for aLastPosition WITHOUT
	forcing evaluation of the dynamics.
	*/
	void setLastCachedPosition(const VectorArrayID& lcps){fprintf_s(mFile,"connectAttr \"");lcps.write(mFile);fprintf_s(mFile,"\" \"%s.lcps\";\n",mName.c_str());}
	/*
	This is the most current value for the aWorldPosition
	attribute WITHOUT forcing evaluation of the dynamics.
	*/
	void setCachedWorldPosition(const VectorArrayID& cwps){fprintf_s(mFile,"connectAttr \"");cwps.write(mFile);fprintf_s(mFile,"\" \"%s.cwps\";\n",mName.c_str());}
	/*
	Cached World-space centroid (average position) of the particles.
	This is the most current value of the worldCentroid
	WITHOUT forcing the evaluation of dynamics.
	*/
	void setCachedWorldCentroid(const Double3ID& cwcn){fprintf_s(mFile,"connectAttr \"");cwcn.write(mFile);fprintf_s(mFile,"\" \"%s.cwcn\";\n",mName.c_str());}
	/*
	Cached World x-component of centroid (average position) of the particles.
	This is the most current value of the worldCentroid
	WITHOUT forcing the evaluation of dynamics.
	*/
	void setCachedWorldCentroidX(const DoubleID& cwcx){fprintf_s(mFile,"connectAttr \"");cwcx.write(mFile);fprintf_s(mFile,"\" \"%s.cwcn.cwcx\";\n",mName.c_str());}
	/*
	Cached World y-component of centroid (average position) of the particles.
	This is the most current value of the worldCentroid
	WITHOUT forcing the evaluation of dynamics.
	*/
	void setCachedWorldCentroidY(const DoubleID& cwcy){fprintf_s(mFile,"connectAttr \"");cwcy.write(mFile);fprintf_s(mFile,"\" \"%s.cwcn.cwcy\";\n",mName.c_str());}
	/*
	Cached World z-component of centroid (average position) of the particles.
	This is the most current value of the worldCentroid
	WITHOUT forcing the evaluation of dynamics.
	*/
	void setCachedWorldCentroidZ(const DoubleID& cwcz){fprintf_s(mFile,"connectAttr \"");cwcz.write(mFile);fprintf_s(mFile,"\" \"%s.cwcn.cwcz\";\n",mName.c_str());}
	/*
	This will have its value set at the END of the solving step.
	Its value will be that of the resulting aVelocity attribute.
	*/
	void setCachedVelocity(const VectorArrayID& cvel){fprintf_s(mFile,"connectAttr \"");cvel.write(mFile);fprintf_s(mFile,"\" \"%s.cvel\";\n",mName.c_str());}
	/*
	This will have its value set at the END of the solving step.
	Its value will be that of the resulting aVelocity attribute.
	*/
	void setCachedWorldVelocity(const VectorArrayID& cwvl){fprintf_s(mFile,"connectAttr \"");cwvl.write(mFile);fprintf_s(mFile,"\" \"%s.cwvl\";\n",mName.c_str());}
	/*The number of particles in the object.*/
	void setCount(const IntID& cnt){fprintf_s(mFile,"connectAttr \"");cnt.write(mFile);fprintf_s(mFile,"\" \"%s.cnt\";\n",mName.c_str());}
	/*Runtime state, mass, per-particle.*/
	void setMass(const DoubleArrayID& mas){fprintf_s(mFile,"connectAttr \"");mas.write(mFile);fprintf_s(mFile,"\" \"%s.mas\";\n",mName.c_str());}
	/*Initial state, mass, per-particle.*/
	void setMass0(const doubleArray& mas0){if(mas0.size == 0) return; fprintf_s(mFile, "setAttr \".mas0\" -type \"doubleArray\" ");mas0.write(mFile);fprintf_s(mFile,";\n");}
	/*Initial state, mass, per-particle.*/
	void setMass0(const DoubleArrayID& mas0){fprintf_s(mFile,"connectAttr \"");mas0.write(mFile);fprintf_s(mFile,"\" \"%s.mas0\";\n",mName.c_str());}
	/*Cached state, mass.*/
	void setMassCache(const DoubleArrayID& masc){fprintf_s(mFile,"connectAttr \"");masc.write(mFile);fprintf_s(mFile,"\" \"%s.masc\";\n",mName.c_str());}
	/*Unique id number for each particle.*/
	void setParticleId(const DoubleArrayID& id){fprintf_s(mFile,"connectAttr \"");id.write(mFile);fprintf_s(mFile,"\" \"%s.id\";\n",mName.c_str());}
	/*Initial state, id values, per-particle.*/
	void setParticleId0(const doubleArray& id0){if(id0.size == 0) return; fprintf_s(mFile, "setAttr \".id0\" -type \"doubleArray\" ");id0.write(mFile);fprintf_s(mFile,";\n");}
	/*Initial state, id values, per-particle.*/
	void setParticleId0(const DoubleArrayID& id0){fprintf_s(mFile,"connectAttr \"");id0.write(mFile);fprintf_s(mFile,"\" \"%s.id0\";\n",mName.c_str());}
	/*Cached state, id values.*/
	void setIdCache(const DoubleArrayID& idc){fprintf_s(mFile,"connectAttr \"");idc.write(mFile);fprintf_s(mFile,"\" \"%s.idc\";\n",mName.c_str());}
	/*
	This compound holds the mapping information for the particle
	ID values.
	*/
	void setIdMapping(const IdMappingID& idm){fprintf_s(mFile,"connectAttr \"");idm.write(mFile);fprintf_s(mFile,"\" \"%s.idm\";\n",mName.c_str());}
	/*
	This array holds the particleId values sorted in ascending order.
	Together with idIndex, it can be used to locate a given id
	quickly in the arrays of particle data.
	*/
	void setSortedId(const IntArrayID& sid){fprintf_s(mFile,"connectAttr \"");sid.write(mFile);fprintf_s(mFile,"\" \"%s.idm.sid\";\n",mName.c_str());}
	/*
	This array holds the index positions into the per-particle attribute
	arrays for the corresponding ids stored in aSortedId.
	Together with sortedId, it can be used to locate a given id
	quickly in the arrays of particle data.
	*/
	void setIdIndex(const IntArrayID& idix){fprintf_s(mFile,"connectAttr \"");idix.write(mFile);fprintf_s(mFile,"\" \"%s.idm.idix\";\n",mName.c_str());}
	/*Next available value for aId*/
	void setNextId(int nid){if(nid == 0) return; fprintf_s(mFile, "setAttr \".nid\" %i;\n", nid);}
	/*Initial value of aNextId*/
	void setNextId0(int nid0){if(nid0 == 0) return; fprintf_s(mFile, "setAttr \".nid0\" %i;\n", nid0);}
	/*
	This stores the time, in seconds, at which each particle was born.  This
	makes the age computation more accurate and easily calculated.
	*/
	void setBirthTime(const DoubleArrayID& bt){fprintf_s(mFile,"connectAttr \"");bt.write(mFile);fprintf_s(mFile,"\" \"%s.bt\";\n",mName.c_str());}
	/*Initial state, birth times, per-particle.*/
	void setBirthTime0(const doubleArray& bt0){if(bt0.size == 0) return; fprintf_s(mFile, "setAttr \".bt0\" -type \"doubleArray\" ");bt0.write(mFile);fprintf_s(mFile,";\n");}
	/*Initial state, birth times, per-particle.*/
	void setBirthTime0(const DoubleArrayID& bt0){fprintf_s(mFile,"connectAttr \"");bt0.write(mFile);fprintf_s(mFile,"\" \"%s.bt0\";\n",mName.c_str());}
	/*Cached state, birth times, per-particle.*/
	void setBirthTimeCache(const DoubleArrayID& btc){fprintf_s(mFile,"connectAttr \"");btc.write(mFile);fprintf_s(mFile,"\" \"%s.btc\";\n",mName.c_str());}
	/*Age per-particle in seconds.*/
	void setAge(const DoubleArrayID& ag){fprintf_s(mFile,"connectAttr \"");ag.write(mFile);fprintf_s(mFile,"\" \"%s.ag\";\n",mName.c_str());}
	/*Initial state, ages, per-particle.*/
	void setAge0(const doubleArray& ag0){if(ag0.size == 0) return; fprintf_s(mFile, "setAttr \".ag0\" -type \"doubleArray\" ");ag0.write(mFile);fprintf_s(mFile,";\n");}
	/*Initial state, ages, per-particle.*/
	void setAge0(const DoubleArrayID& ag0){fprintf_s(mFile,"connectAttr \"");ag0.write(mFile);fprintf_s(mFile,"\" \"%s.ag0\";\n",mName.c_str());}
	/*Cached state, age values.*/
	void setAgeCache(const DoubleArrayID& agc){fprintf_s(mFile,"connectAttr \"");agc.write(mFile);fprintf_s(mFile,"\" \"%s.agc\";\n",mName.c_str());}
	/*
	This attribute holds all of the particles added to this
	object from emitters and the emit action, but NOT from
	collision events.
	*/
	void setEmission(const GenericArrayID& emt){fprintf_s(mFile,"connectAttr \"");emt.write(mFile);fprintf_s(mFile,"\" \"%s.emt\";\n",mName.c_str());}
	/*
	If the particles were emitted from a volume, die when
	they exit that volume.
	*/
	void setDieOnEmissionVolumeExit(bool dve){if(dve == false) return; fprintf_s(mFile, "setAttr \".dve\" %i;\n", dve);}
	/*
	If the particles were emitted from a volume, die when
	they exit that volume.
	*/
	void setDieOnEmissionVolumeExit(const BoolID& dve){fprintf_s(mFile,"connectAttr \"");dve.write(mFile);fprintf_s(mFile,"\" \"%s.dve\";\n",mName.c_str());}
	/*
	Tells any object whether this particle object has room for any new
	particles or not, based on the maxCount and count attributes.
	*/
	void setIsFull(const BoolID& ifl){fprintf_s(mFile,"connectAttr \"");ifl.write(mFile);fprintf_s(mFile,"\" \"%s.ifl\";\n",mName.c_str());}
	/*
	Determines which attributes to use for particle lifespan.
	"Range" means use lifespan + lifespanRandom together to give
	each particle an individual lifespan. This lifespan is stored
	in the attribute "finalLifespanPP."
	"PP" means that you want to drive lifespans using the lifespanPP
	attribute.  You must then either write an expression or set
	values for this attribute in the component editor.
	"Live forever" disables lifespan altogether.  In this mode, all
	particles live forever, unless killed by collision events or emission
	volume exit (see the dieOnEmissionVolume exit attribute).
	Lifespan mode has nothing to do with events or
	emission volume exit and does not override them.
	*/
	void setLifespanMode(unsigned int lfm){if(lfm == 0) return; fprintf_s(mFile, "setAttr \".lfm\" %i;\n", lfm);}
	/*
	Determines which attributes to use for particle lifespan.
	"Range" means use lifespan + lifespanRandom together to give
	each particle an individual lifespan. This lifespan is stored
	in the attribute "finalLifespanPP."
	"PP" means that you want to drive lifespans using the lifespanPP
	attribute.  You must then either write an expression or set
	values for this attribute in the component editor.
	"Live forever" disables lifespan altogether.  In this mode, all
	particles live forever, unless killed by collision events or emission
	volume exit (see the dieOnEmissionVolume exit attribute).
	Lifespan mode has nothing to do with events or
	emission volume exit and does not override them.
	*/
	void setLifespanMode(const UnsignedintID& lfm){fprintf_s(mFile,"connectAttr \"");lfm.write(mFile);fprintf_s(mFile,"\" \"%s.lfm\";\n",mName.c_str());}
	/*
	Used only if lifespanMode is set to "Random Range."
	Identifies a range of random variation for the lifespan of
	each particle.  If set to a non-zero value, each particle's lifespan
	varies randomly up to plus or minus lifespanRandom/2, with the
	"lifespan" attribute value as the mean (the average lifespan).
	For example, lifespan 5 and lifespanRandom 2 will make the lifespans
	vary between 4 and 6.
	In Constant or Random Range mode, the finalLifespanPP attribute
	stores the values generated from lifespan and lifespanRandom.
	Note: Changes in the values of lifespan and lifespanRandom affect
	only new particles, not particles that already exist.  For example,
	if you key the value of lifespan to be 2 up until frame 50 and 5
	thereafter, then particles generated from frame 1 to 50 will have
	finalLifespanPP 2 and particles generated after frame 50 will have
	finalLifespanPP 5.  The finalLifespanPP values of particles born
	prior to frame 50 will not change.
	*/
	void setLifespanRandom(double lfr){if(lfr == 0.0) return; fprintf_s(mFile, "setAttr \".lfr\" %f;\n", lfr);}
	/*
	Used only if lifespanMode is set to "Random Range."
	Identifies a range of random variation for the lifespan of
	each particle.  If set to a non-zero value, each particle's lifespan
	varies randomly up to plus or minus lifespanRandom/2, with the
	"lifespan" attribute value as the mean (the average lifespan).
	For example, lifespan 5 and lifespanRandom 2 will make the lifespans
	vary between 4 and 6.
	In Constant or Random Range mode, the finalLifespanPP attribute
	stores the values generated from lifespan and lifespanRandom.
	Note: Changes in the values of lifespan and lifespanRandom affect
	only new particles, not particles that already exist.  For example,
	if you key the value of lifespan to be 2 up until frame 50 and 5
	thereafter, then particles generated from frame 1 to 50 will have
	finalLifespanPP 2 and particles generated after frame 50 will have
	finalLifespanPP 5.  The finalLifespanPP values of particles born
	prior to frame 50 will not change.
	*/
	void setLifespanRandom(const DoubleID& lfr){fprintf_s(mFile,"connectAttr \"");lfr.write(mFile);fprintf_s(mFile,"\" \"%s.lfr\";\n",mName.c_str());}
	/*
	finalLifespanPP stores the final result of the particle object's
	lifespan computations, from whatever lifespan mode is currently
	in force.  if the lifespan mode is "use lifespanPP" then this
	attribute will be a copy of lifespanPP.  If the mode is "constant"
	or "random range" then it will be generated from lifespan and
	lifespan random.  If the mode is "None" then it will be an array
	of maximum float values.  You cannot write to finalLifespanPP,
	the particle object generates it for you.  You can always access
	finalLifespanPP for expressions and it will always be the effective
	lifespan value regardless of mode.
	Note that there is no finalLifespanPP0 initial state attribute.
	Instead, finalLifespanPP values are re-generated when needed
	from the random stream.
	*/
	void setFinalLifespanPP(const DoubleArrayID& flp){fprintf_s(mFile,"connectAttr \"");flp.write(mFile);fprintf_s(mFile,"\" \"%s.flp\";\n",mName.c_str());}
	/*
	This boolean attribute lets the user decide whether they
	want the expressions to happen before or after the dynamics
	is computed.
	*/
	void setExpressionsAfterDynamics(bool ead){if(ead == false) return; fprintf_s(mFile, "setAttr \".ead\" %i;\n", ead);}
	/*
	This boolean attribute lets the user decide whether they
	want the expressions to happen before or after the dynamics
	is computed.
	*/
	void setExpressionsAfterDynamics(const BoolID& ead){fprintf_s(mFile,"connectAttr \"");ead.write(mFile);fprintf_s(mFile,"\" \"%s.ead\";\n",mName.c_str());}
	/*
	This attribute is where any input attribute for the expressions,
	both runtime and creation, is connected.
	*/
	void setInput(size_t xi_i,const GenericID& xi){fprintf_s(mFile,"connectAttr \"");xi.write(mFile);fprintf_s(mFile,"\" \"%s.xi[%i]\";\n",mName.c_str(),xi_i);}
	/*
	This attribute is where any output attribute for the expressions,
	both runtime and creation, is connected.
	*/
	void setOutput(size_t xo_i,const GenericID& xo){fprintf_s(mFile,"connectAttr \"");xo.write(mFile);fprintf_s(mFile,"\" \"%s.xo[%i]\";\n",mName.c_str(),xo_i);}
	/*
	This is the internal representation of the runtime expression.
	All of the places where attributes were are replaced with
	tokens representing the multi-index of the input/output
	attribute to which they are connected.
	*/
	void setInternalRuntimeBeforeDynamicsExpression(const string& irbx){if(irbx == "NULL") return; fprintf_s(mFile, "setAttr \".irbx\" -type \"string\" ");irbx.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is the internal representation of the runtime expression.
	All of the places where attributes were are replaced with
	tokens representing the multi-index of the input/output
	attribute to which they are connected.
	*/
	void setInternalRuntimeAfterDynamicsExpression(const string& irax){if(irax == "NULL") return; fprintf_s(mFile, "setAttr \".irax\" -type \"string\" ");irax.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is the internal representation of the creation expression.
	All of the places where attributes were are replaced with
	tokens representing the multi-index of the input/output
	attribute to which they are connected.
	*/
	void setInternalCreationExpression(const string& icx){if(icx == "NULL") return; fprintf_s(mFile, "setAttr \".icx\" -type \"string\" ");icx.write(mFile);fprintf_s(mFile,";\n");}
	/*OBSOLETE ATTRIBUTE.  No effect.*/
	void setDiedLastTime(const IntID& dlt){fprintf_s(mFile,"connectAttr \"");dlt.write(mFile);fprintf_s(mFile,"\" \"%s.dlt\";\n",mName.c_str());}
	/*OBSOLETE ATTRIBUTE.  No effect.*/
	void setNetEmittedLastTime(const IntID& nlt){fprintf_s(mFile,"connectAttr \"");nlt.write(mFile);fprintf_s(mFile,"\" \"%s.nlt\";\n",mName.c_str());}
	/*OBSOLETE ATTRIBUTE.  No effect.*/
	void setStartEmittedIndex(const IntID& sei){fprintf_s(mFile,"connectAttr \"");sei.write(mFile);fprintf_s(mFile,"\" \"%s.sei\";\n",mName.c_str());}
	/*Toggle dynamics on/off for this object.*/
	void setIsDynamic(bool isd){if(isd == true) return; fprintf_s(mFile, "setAttr \".isd\" %i;\n", isd);}
	/*Toggle dynamics on/off for this object.*/
	void setIsDynamic(const BoolID& isd){fprintf_s(mFile,"connectAttr \"");isd.write(mFile);fprintf_s(mFile,"\" \"%s.isd\";\n",mName.c_str());}
	/*Fraction of dynamics forces which get applied each time step.*/
	void setDynamicsWeight(double dw){if(dw == 1.0) return; fprintf_s(mFile, "setAttr \".dw\" %f;\n", dw);}
	/*Fraction of dynamics forces which get applied each time step.*/
	void setDynamicsWeight(const DoubleID& dw){fprintf_s(mFile,"connectAttr \"");dw.write(mFile);fprintf_s(mFile,"\" \"%s.dw\";\n",mName.c_str());}
	/*
	This boolean tells the solver to transform all field forces into object space
	before doing the dynamics.  This makes the particles respond as if they
	were in the same space as the forces when they are in some non-identity
	hierarchy.
	*/
	void setForcesInWorld(bool fiw){if(fiw == true) return; fprintf_s(mFile, "setAttr \".fiw\" %i;\n", fiw);}
	/*
	This boolean tells the solver to transform all field forces into object space
	before doing the dynamics.  This makes the particles respond as if they
	were in the same space as the forces when they are in some non-identity
	hierarchy.
	*/
	void setForcesInWorld(const BoolID& fiw){fprintf_s(mFile,"connectAttr \"");fiw.write(mFile);fprintf_s(mFile,"\" \"%s.fiw\";\n",mName.c_str());}
	/*
	If set to a value less than one, only the corresponding portion of
	existing velocity will be retained when computing the next step.
	For example, if conserve is 0, all existing velocity will be erased
	before each new step. The name "conserve" refers to conservation
	momentum.  Real (Newtonian) physics corresponds to conserve = 1.
	*/
	void setConserve(double con){if(con == 1.0) return; fprintf_s(mFile, "setAttr \".con\" %f;\n", con);}
	/*
	If set to a value less than one, only the corresponding portion of
	existing velocity will be retained when computing the next step.
	For example, if conserve is 0, all existing velocity will be erased
	before each new step. The name "conserve" refers to conservation
	momentum.  Real (Newtonian) physics corresponds to conserve = 1.
	*/
	void setConserve(const DoubleID& con){fprintf_s(mFile,"connectAttr \"");con.write(mFile);fprintf_s(mFile,"\" \"%s.con\";\n",mName.c_str());}
	/*
	This boolean tells the particle object to assume that particles created
	from emission are in world space, and to transform them into object space
	before adding them to the particle array.  This makes the particles respond as if
	they were in the same space as the emitter when they are in some non-identity
	hierarchy.
	*/
	void setEmissionInWorld(bool eiw){if(eiw == true) return; fprintf_s(mFile, "setAttr \".eiw\" %i;\n", eiw);}
	/*
	This boolean tells the particle object to assume that particles created
	from emission are in world space, and to transform them into object space
	before adding them to the particle array.  This makes the particles respond as if
	they were in the same space as the emitter when they are in some non-identity
	hierarchy.
	*/
	void setEmissionInWorld(const BoolID& eiw){fprintf_s(mFile,"connectAttr \"");eiw.write(mFile);fprintf_s(mFile,"\" \"%s.eiw\";\n",mName.c_str());}
	/*
	Maximum count of particles this shape will allow.
	If some particles die off, new particles will again be accepted
	up to the max count, and so on.
	*/
	void setMaxCount(int mxc){if(mxc == -1) return; fprintf_s(mFile, "setAttr \".mxc\" %i;\n", mxc);}
	/*
	Maximum count of particles this shape will allow.
	If some particles die off, new particles will again be accepted
	up to the max count, and so on.
	*/
	void setMaxCount(const IntID& mxc){fprintf_s(mFile,"connectAttr \"");mxc.write(mFile);fprintf_s(mFile,"\" \"%s.mxc\";\n",mName.c_str());}
	/*
	Currently only used to scale the amount of emission
	to be used for quick motion tests without having to
	change emitter values. Affects only emitted particles.
	*/
	void setLevelOfDetail(double lod){if(lod == 1) return; fprintf_s(mFile, "setAttr \".lod\" %f;\n", lod);}
	/*
	Currently only used to scale the amount of emission
	to be used for quick motion tests without having to
	change emitter values. Affects only emitted particles.
	*/
	void setLevelOfDetail(const DoubleID& lod){fprintf_s(mFile,"connectAttr \"");lod.write(mFile);fprintf_s(mFile,"\" \"%s.lod\";\n",mName.c_str());}
	/*
	Fraction of emitter velocity that particles emitted into this
	object inherit.
	*/
	void setInheritFactor(double inh){if(inh == 0.0) return; fprintf_s(mFile, "setAttr \".inh\" %f;\n", inh);}
	/*
	Fraction of emitter velocity that particles emitted into this
	object inherit.
	*/
	void setInheritFactor(const DoubleID& inh){fprintf_s(mFile,"connectAttr \"");inh.write(mFile);fprintf_s(mFile,"\" \"%s.inh\";\n",mName.c_str());}
	/*
	Random number stream seed for emitter's random number stream.
	Separate seed for each emitter. Set seeds equal to get identical
	stream.  Resetting the seed at a particular frame will restart
	the stream.
	*/
	void setSeed(size_t sd_i,int sd){if(sd == 1) return; fprintf_s(mFile, "setAttr \".sd[%i]\" %i;\n", sd_i,sd);}
	/*
	Random number stream seed for emitter's random number stream.
	Separate seed for each emitter. Set seeds equal to get identical
	stream.  Resetting the seed at a particular frame will restart
	the stream.
	*/
	void setSeed(size_t sd_i,const IntID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd[%i]\";\n",mName.c_str(),sd_i);}
	/*
	This is the compound that holds all of the default attribute for the
	fields to connect to.  The contents are just sharing the data from
	the real attributes.
	*/
	void setFieldData(const FieldDataID& fd){fprintf_s(mFile,"connectAttr \"");fd.write(mFile);fprintf_s(mFile,"\" \"%s.fd\";\n",mName.c_str());}
	/*
	This is the default place that the fields will get this particle object's
	position data from.  It will share the data from aPosition.
	*/
	void setFieldDataPosition(const VectorArrayID& fdp){fprintf_s(mFile,"connectAttr \"");fdp.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdp\";\n",mName.c_str());}
	/*
	This is the default place that the fields will get this particle object's
	velcoity data from.  It will share the data from aVelocity.
	*/
	void setFieldDataVelocity(const VectorArrayID& fdv){fprintf_s(mFile,"connectAttr \"");fdv.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdv\";\n",mName.c_str());}
	/*
	This is the default place that the fields will get this particle object's
	mass data from.  It will share the data from aMass.
	*/
	void setFieldDataMass(const DoubleArrayID& fdm){fprintf_s(mFile,"connectAttr \"");fdm.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdm\";\n",mName.c_str());}
	/*
	This is the default place that the fields will get this particle object's
	timeStep size from.  It will share the data from aTimeStepSize.
	*/
	void setFieldDataDeltaTime(const TimeID& fdt){fprintf_s(mFile,"connectAttr \"");fdt.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdt\";\n",mName.c_str());}
	/*
	This is the compound that holds all of the default attribute for the
	emitters to connect to.  The contents are just sharing the data from
	the real attributes.
	*/
	void setEmitterData(const EmitterDataID& ed){fprintf_s(mFile,"connectAttr \"");ed.write(mFile);fprintf_s(mFile,"\" \"%s.ed\";\n",mName.c_str());}
	/*
	This is the default place that the emitters will get this particle object's
	position data from.  It will share the data from aPosition.
	*/
	void setEmitterDataPosition(const VectorArrayID& edp){fprintf_s(mFile,"connectAttr \"");edp.write(mFile);fprintf_s(mFile,"\" \"%s.ed.edp\";\n",mName.c_str());}
	/*
	This is the default place that the emitters will get this particle object's
	velcoity data from.  It will share the data from aVelocity.
	*/
	void setEmitterDataVelocity(const VectorArrayID& edv){fprintf_s(mFile,"connectAttr \"");edv.write(mFile);fprintf_s(mFile,"\" \"%s.ed.edv\";\n",mName.c_str());}
	/*
	This is the default place that the emitters will get this particle object's
	timeStep size from.  It will share the data from aTimeStepSize.
	*/
	void setEmitterDataDeltaTime(const TimeID& edt){fprintf_s(mFile,"connectAttr \"");edt.write(mFile);fprintf_s(mFile,"\" \"%s.ed.edt\";\n",mName.c_str());}
	/*
	This is the current time used for the particle solution.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.  There must be some incoming connection in order
	for the particle object to play back.
	*/
	void setCurrentTime(const TimeID& cti){fprintf_s(mFile,"connectAttr \"");cti.write(mFile);fprintf_s(mFile,"\" \"%s.cti\";\n",mName.c_str());}
	/*
	This would get the value from aCurrentTime "copied" into it
	at the end of the solving process.  There are no AFFECTS
	relationships here so that requesting this attribute does
	not trigger any other evaluation.  Because of the timing of
	when this attribute gets set, it should not be used by users
	as reliable data.  It is for internal computation only.
	*/
	void setLastTimeEvaluated(const TimeID& lti){fprintf_s(mFile,"connectAttr \"");lti.write(mFile);fprintf_s(mFile,"\" \"%s.lti\";\n",mName.c_str());}
	/*
	Users should not set or use this attribute. Results will be
	unpredictable.
	*/
	void setCachedTime(const TimeID& chti){fprintf_s(mFile,"connectAttr \"");chti.write(mFile);fprintf_s(mFile,"\" \"%s.chti\";\n",mName.c_str());}
	/*
	For internal use only.  Users should not set this.
	It is defined as (currentTime - lastTimeEvaluated)/overSamples.
	*/
	void setTimeStepSize(const TimeID& tss){fprintf_s(mFile,"connectAttr \"");tss.write(mFile);fprintf_s(mFile,"\" \"%s.tss\";\n",mName.c_str());}
	/*
	This is the step size in scene time.  This should be used for world-space
	computations. Users should not set this attribute.
	*/
	void setSceneTimeStepSize(const TimeID& sts){fprintf_s(mFile,"connectAttr \"");sts.write(mFile);fprintf_s(mFile,"\" \"%s.sts\";\n",mName.c_str());}
	/*
	This is the frame after which dynamics will be solved. No dynamics
	will play back for this object prior to startFrame.
	*/
	void setStartFrame(double stf){if(stf == 1.0) return; fprintf_s(mFile, "setAttr \".stf\" %f;\n", stf);}
	/*
	This is the frame after which dynamics will be solved. No dynamics
	will play back for this object prior to startFrame.
	*/
	void setStartFrame(const DoubleID& stf){fprintf_s(mFile,"connectAttr \"");stf.write(mFile);fprintf_s(mFile,"\" \"%s.stf\";\n",mName.c_str());}
	/*
	The time after which dynamics will be solved for this particle object.
	This is set from the startFrame attribute.
	Users should set startFrame instead of this attribute.
	*/
	void setStartTime(const TimeID& stt){fprintf_s(mFile,"connectAttr \"");stt.write(mFile);fprintf_s(mFile,"\" \"%s.stt\";\n",mName.c_str());}
	/*
	Input Geometr(y/ies) for soft body. This should be connected
	from the local/object-space version of the geometry.
	Valid inputs are polygons, nurbs surfaces, nurbs curves, and lattices.
	*/
	void setInputGeometry(const GenericID& igeo){fprintf_s(mFile,"connectAttr \"");igeo.write(mFile);fprintf_s(mFile,"\" \"%s.igeo\";\n",mName.c_str());}
	/*
	This attribute stores the point data from the inputGeometry
	attribute as a vectorArray.  This allows the expressions to have
	access and knowledge about the geometry.
	*/
	void setInputGeometryPoints(const VectorArrayID& igpt){fprintf_s(mFile,"connectAttr \"");igpt.write(mFile);fprintf_s(mFile,"\" \"%s.igpt\";\n",mName.c_str());}
	/*
	This attribute tells the particle object which coordinate
	space to make the inputGeometryPoints attribute in.
	The inputGeometry is received with the points in the
	geometry's local space.  If the attribute is set to
	0(kGeomLocal), then those same point values are
	put into the inputGeometryPoints.  If the value is
	1(kGeomWorld), then the point values are transformed
	input world-space with the geometry's world matrix.  Finally,
	if the value is 2(kGeomParticle), then the points are
	transformed into world-space with the geometry's world
	matrix, and then into the particle object's loca space with
	the particle objecty's inverse world matrix.
	*/
	void setInputGeometrySpace(unsigned int igs){if(igs == 0) return; fprintf_s(mFile, "setAttr \".igs\" %i;\n", igs);}
	/*
	This attribute tells the particle object which coordinate
	space to make the inputGeometryPoints attribute in.
	The inputGeometry is received with the points in the
	geometry's local space.  If the attribute is set to
	0(kGeomLocal), then those same point values are
	put into the inputGeometryPoints.  If the value is
	1(kGeomWorld), then the point values are transformed
	input world-space with the geometry's world matrix.  Finally,
	if the value is 2(kGeomParticle), then the points are
	transformed into world-space with the geometry's world
	matrix, and then into the particle object's loca space with
	the particle objecty's inverse world matrix.
	*/
	void setInputGeometrySpace(const UnsignedintID& igs){fprintf_s(mFile,"connectAttr \"");igs.write(mFile);fprintf_s(mFile,"\" \"%s.igs\";\n",mName.c_str());}
	/*
	Tells the particle object to keep its count consistent with
	the pointCount of any incoming history in inputGeometry, if one exists.
	*/
	void setEnforceCountFromHistory(bool ecfh){if(ecfh == true) return; fprintf_s(mFile, "setAttr \".ecfh\" %i;\n", ecfh);}
	/*
	Tells the particle object to keep its count consistent with
	the pointCount of any incoming history in inputGeometry, if one exists.
	*/
	void setEnforceCountFromHistory(const BoolID& ecfh){fprintf_s(mFile,"connectAttr \"");ecfh.write(mFile);fprintf_s(mFile,"\" \"%s.ecfh\";\n",mName.c_str());}
	/*Geometry for soft body.*/
	void setTargetGeometry(const GenericID& tgeo){fprintf_s(mFile,"connectAttr \"");tgeo.write(mFile);fprintf_s(mFile,"\" \"%s.tgeo\";\n",mName.c_str());}
	/*
	This attribute is optionally connected to from the world matrix
	of the target geometry.  It allows the targetGeometrySpace attribute
	to correctly use the kTargetGeomLocal setting.
	*/
	void setTargetGeometryWorldMatrix(const MatrixID& tgm){fprintf_s(mFile,"connectAttr \"");tgm.write(mFile);fprintf_s(mFile,"\" \"%s.tgm\";\n",mName.c_str());}
	/*
	This attribute tells the particle object which coordinate
	space to build the targetGeometry data in.
	If targetGeometrySpace is 2(kTargetGeomParticle), then
	the values from the particle object's position attribute
	are used as the points for the target geometry.  If the
	value is 1(kTargetGeomWorld), then the position points
	are transformed into world-space with the particle object's
	world matrix.  If the value is 0(kTargetGeomLocal), then
	the position points are transformed into world-space, and
	then they are transformed into the target geometry's local
	space with the inverse of targetGeometryMatrix if it has an
	incoming connection.  If targetGeometryMatrix does not have
	a connection, then a warning is displayed telling the user
	why it can not get the target geometry's world matrix, and
	the identity matrix is used.
	*/
	void setTargetGeometrySpace(unsigned int tgs){if(tgs == 2) return; fprintf_s(mFile, "setAttr \".tgs\" %i;\n", tgs);}
	/*
	This attribute tells the particle object which coordinate
	space to build the targetGeometry data in.
	If targetGeometrySpace is 2(kTargetGeomParticle), then
	the values from the particle object's position attribute
	are used as the points for the target geometry.  If the
	value is 1(kTargetGeomWorld), then the position points
	are transformed into world-space with the particle object's
	world matrix.  If the value is 0(kTargetGeomLocal), then
	the position points are transformed into world-space, and
	then they are transformed into the target geometry's local
	space with the inverse of targetGeometryMatrix if it has an
	incoming connection.  If targetGeometryMatrix does not have
	a connection, then a warning is displayed telling the user
	why it can not get the target geometry's world matrix, and
	the identity matrix is used.
	*/
	void setTargetGeometrySpace(const UnsignedintID& tgs){fprintf_s(mFile,"connectAttr \"");tgs.write(mFile);fprintf_s(mFile,"\" \"%s.tgs\";\n",mName.c_str());}
	/*
	This value is used to control the "smoothness" of the change in the
	goal forces as the weight changes from 0.0 to 1.0.  This is purely
	an asthetic effect, with no scientific basis.  The higher the number,
	the smoother the change.
	*/
	void setGoalSmoothness(double gsm){if(gsm == 3) return; fprintf_s(mFile, "setAttr \".gsm\" %f;\n", gsm);}
	/*
	This value is used to control the "smoothness" of the change in the
	goal forces as the weight changes from 0.0 to 1.0.  This is purely
	an asthetic effect, with no scientific basis.  The higher the number,
	the smoother the change.
	*/
	void setGoalSmoothness(const DoubleID& gsm){fprintf_s(mFile,"connectAttr \"");gsm.write(mFile);fprintf_s(mFile,"\" \"%s.gsm\";\n",mName.c_str());}
	/*The input geometry attributes for the goal objects.*/
	void setGoalGeometry(size_t ggeo_i,const GenericID& ggeo){fprintf_s(mFile,"connectAttr \"");ggeo.write(mFile);fprintf_s(mFile,"\" \"%s.ggeo[%i]\";\n",mName.c_str(),ggeo_i);}
	/*The goal weights for the various goal objects.*/
	void setGoalWeight(size_t gw_i,double gw){if(gw == 0.0) return; fprintf_s(mFile, "setAttr \".gw[%i]\" %f;\n", gw_i,gw);}
	/*The goal weights for the various goal objects.*/
	void setGoalWeight(size_t gw_i,const DoubleID& gw){fprintf_s(mFile,"connectAttr \"");gw.write(mFile);fprintf_s(mFile,"\" \"%s.gw[%i]\";\n",mName.c_str(),gw_i);}
	/*
	The active status for the goal objects.  This is a switch that
	turns each goal ON or OFF.  This has the same visual
	as setting the corresponding goalWeight to 0.  The
	difference is that with a goalActive of OFF, the goal
	positions are not even taken into account in the
	computation, and therefore make the computation run faster.
	*/
	void setGoalActive(size_t ga_i,bool ga){if(ga == true) return; fprintf_s(mFile, "setAttr \".ga[%i]\" %i;\n", ga_i,ga);}
	/*
	The active status for the goal objects.  This is a switch that
	turns each goal ON or OFF.  This has the same visual
	as setting the corresponding goalWeight to 0.  The
	difference is that with a goalActive of OFF, the goal
	positions are not even taken into account in the
	computation, and therefore make the computation run faster.
	*/
	void setGoalActive(size_t ga_i,const BoolID& ga){fprintf_s(mFile,"connectAttr \"");ga.write(mFile);fprintf_s(mFile,"\" \"%s.ga[%i]\";\n",mName.c_str(),ga_i);}
	/*
	For goal objects that have multiple uv sets, this attribute
	specifies which uv set to use when goalU/goalV values are
	present for particles.
	*/
	void setGoalUvSetName(size_t guv_i,const string& guv){if(guv == "NULL") return; fprintf_s(mFile, "setAttr \".guv[%i]\" -type \"string\" ",guv_i);guv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	For goal objects that have multiple uv sets, this attribute
	specifies which uv set to use when goalU/goalV values are
	present for particles.
	*/
	void setGoalUvSetName(size_t guv_i,const StringID& guv){fprintf_s(mFile,"connectAttr \"");guv.write(mFile);fprintf_s(mFile,"\" \"%s.guv[%i]\";\n",mName.c_str(),guv_i);}
	/*Indicates that caching is on/off.*/
	void setCacheData(bool chd){if(chd == 0) return; fprintf_s(mFile, "setAttr \".chd\" %i;\n", chd);}
	/*Indicates that caching is on/off.*/
	void setCacheData(const BoolID& chd){fprintf_s(mFile,"connectAttr \"");chd.write(mFile);fprintf_s(mFile,"\" \"%s.chd\";\n",mName.c_str());}
	/*
	The width of the cache is the number of different time points
	for which the state can be cached.
	*/
	void setCacheWidth(int chw){if(chw == 1) return; fprintf_s(mFile, "setAttr \".chw\" %i;\n", chw);}
	/*
	The width of the cache is the number of different time points
	for which the state can be cached.
	*/
	void setCacheWidth(const IntID& chw){fprintf_s(mFile,"connectAttr \"");chw.write(mFile);fprintf_s(mFile,"\" \"%s.chw\";\n",mName.c_str());}
	/*
	This is the maximum number of consecutive collisions that are
	detected within a frame for each particle.  Particles may
	collide fewer times, of course.
	*/
	void setTraceDepth(int trd){if(trd == 10) return; fprintf_s(mFile, "setAttr \".trd\" %i;\n", trd);}
	/*
	This is the maximum number of consecutive collisions that are
	detected within a frame for each particle.  Particles may
	collide fewer times, of course.
	*/
	void setTraceDepth(const IntID& trd){fprintf_s(mFile,"connectAttr \"");trd.write(mFile);fprintf_s(mFile,"\" \"%s.trd\";\n",mName.c_str());}
	/*Parent attribute for all collision input data.*/
	void setCollisionData(const CollisionDataID& cda){fprintf_s(mFile,"connectAttr \"");cda.write(mFile);fprintf_s(mFile,"\" \"%s.cda\";\n",mName.c_str());}
	/*The swept geometry for the connected shape.*/
	void setCollisionGeometry(size_t cge_i,const SweptGeometryID& cge){fprintf_s(mFile,"connectAttr \"");cge.write(mFile);fprintf_s(mFile,"\" \"%s.cda.cge[%i]\";\n",mName.c_str(),cge_i);}
	/*How much of the particle's velocity perpendicular to the surface is reflected*/
	void setCollisionResilience(size_t crs_i,const DoubleID& crs){fprintf_s(mFile,"connectAttr \"");crs.write(mFile);fprintf_s(mFile,"\" \"%s.cda.crs[%i]\";\n",mName.c_str(),crs_i);}
	/*The amount of a particle's velocity parallel to a surface that is lost in the collision*/
	void setCollisionFriction(size_t cfr_i,const DoubleID& cfr){fprintf_s(mFile,"connectAttr \"");cfr.write(mFile);fprintf_s(mFile,"\" \"%s.cda.cfr[%i]\";\n",mName.c_str(),cfr_i);}
	/*The distance the particle is offset from point of intersection on surface during reflection.*/
	void setCollisionOffset(size_t cof_i,const DoubleID& cof){fprintf_s(mFile,"connectAttr \"");cof.write(mFile);fprintf_s(mFile,"\" \"%s.cda.cof[%i]\";\n",mName.c_str(),cof_i);}
	/*
	This is the READ-ONLY attribute where all of the information
	about the particle object's collisions for each frame is
	stored.
	*/
	void setCollisionRecords(const GenericArrayID& crc){fprintf_s(mFile,"connectAttr \"");crc.write(mFile);fprintf_s(mFile,"\" \"%s.crc\";\n",mName.c_str());}
	/*
	Total number of collisions which have occurred for this object.
	All collisions are counted regardless of whether any collision
	events were actually executed.  In other words, totalEventCount
	is the sum of the per-particle "event" attribute.
	*/
	void setTotalEventCount(const IntID& tec){fprintf_s(mFile,"connectAttr \"");tec.write(mFile);fprintf_s(mFile,"\" \"%s.tec\";\n",mName.c_str());}
	/*
	True if any particle collision has occured since the last time
	the attribute was read. However, if you read the attribute twice
	in succession in the same frame you will get the same result both
	times. Note that it does not matter whether collision events were
	executed at the collisions in question.
	*/
	void setEventTest(const BoolID& evt){fprintf_s(mFile,"connectAttr \"");evt.write(mFile);fprintf_s(mFile,"\" \"%s.evt\";\n",mName.c_str());}
	/*Used to compute eventTest attribute.*/
	void setLastTotalEventCount(const IntID& ltec){fprintf_s(mFile,"connectAttr \"");ltec.write(mFile);fprintf_s(mFile,"\" \"%s.ltec\";\n",mName.c_str());}
	/*
	Target parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventTarget(size_t etg_i,const MessageID& etg){fprintf_s(mFile,"connectAttr \"");etg.write(mFile);fprintf_s(mFile,"\" \"%s.etg[%i]\";\n",mName.c_str(),etg_i);}
	/*
	Names of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventName(size_t evn_i,const string& evn){if(evn == "NULL") return; fprintf_s(mFile, "setAttr \".evn[%i]\" -type \"string\" ",evn_i);evn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Names of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventName(size_t evn_i,const StringID& evn){fprintf_s(mFile,"connectAttr \"");evn.write(mFile);fprintf_s(mFile,"\" \"%s.evn[%i]\";\n",mName.c_str(),evn_i);}
	/*
	Marks valid particle collision events.
	Setting this to false turns an event off, in effect.
	Edit this through the particle event editor.
	*/
	void setEventValid(size_t evv_i,int evv){if(evv == -1) return; fprintf_s(mFile, "setAttr \".evv[%i]\" %i;\n", evv_i,evv);}
	/*
	Marks valid particle collision events.
	Setting this to false turns an event off, in effect.
	Edit this through the particle event editor.
	*/
	void setEventValid(size_t evv_i,const IntID& evv){fprintf_s(mFile,"connectAttr \"");evv.write(mFile);fprintf_s(mFile,"\" \"%s.evv[%i]\";\n",mName.c_str(),evv_i);}
	/*
	Event count parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventCount(size_t ecp_i,short ecp){if(ecp == -1) return; fprintf_s(mFile, "setAttr \".ecp[%i]\" %i;\n", ecp_i,ecp);}
	/*
	Event count parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventCount(size_t ecp_i,const ShortID& ecp){fprintf_s(mFile,"connectAttr \"");ecp.write(mFile);fprintf_s(mFile,"\" \"%s.ecp[%i]\";\n",mName.c_str(),ecp_i);}
	/*
	Emit parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventEmit(size_t eve_i,short eve){if(eve == -1) return; fprintf_s(mFile, "setAttr \".eve[%i]\" %i;\n", eve_i,eve);}
	/*
	Emit parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventEmit(size_t eve_i,const ShortID& eve){fprintf_s(mFile,"connectAttr \"");eve.write(mFile);fprintf_s(mFile,"\" \"%s.eve[%i]\";\n",mName.c_str(),eve_i);}
	/*
	Split parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventSplit(size_t evs_i,short evs){if(evs == -1) return; fprintf_s(mFile, "setAttr \".evs[%i]\" %i;\n", evs_i,evs);}
	/*
	Split parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventSplit(size_t evs_i,const ShortID& evs){fprintf_s(mFile,"connectAttr \"");evs.write(mFile);fprintf_s(mFile,"\" \"%s.evs[%i]\";\n",mName.c_str(),evs_i);}
	/*
	Die parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventDie(size_t evd_i,short evd){if(evd == -1) return; fprintf_s(mFile, "setAttr \".evd[%i]\" %i;\n", evd_i,evd);}
	/*
	Die parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventDie(size_t evd_i,const ShortID& evd){fprintf_s(mFile,"connectAttr \"");evd.write(mFile);fprintf_s(mFile,"\" \"%s.evd[%i]\";\n",mName.c_str(),evd_i);}
	/*
	Random parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventRandom(size_t evr_i,short evr){if(evr == -1) return; fprintf_s(mFile, "setAttr \".evr[%i]\" %i;\n", evr_i,evr);}
	/*
	Random parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventRandom(size_t evr_i,const ShortID& evr){fprintf_s(mFile,"connectAttr \"");evr.write(mFile);fprintf_s(mFile,"\" \"%s.evr[%i]\";\n",mName.c_str(),evr_i);}
	/*
	Controls random distribution of multiple particles created at single collision.
	Edit this through the particle event editor.
	*/
	void setEventSpread(size_t esp_i,double esp){if(esp == -1.0) return; fprintf_s(mFile, "setAttr \".esp[%i]\" %f;\n", esp_i,esp);}
	/*
	Controls random distribution of multiple particles created at single collision.
	Edit this through the particle event editor.
	*/
	void setEventSpread(size_t esp_i,const DoubleID& esp){fprintf_s(mFile,"connectAttr \"");esp.write(mFile);fprintf_s(mFile,"\" \"%s.esp[%i]\";\n",mName.c_str(),esp_i);}
	/*
	Proc names for particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventProc(size_t epr_i,const string& epr){if(epr == "NULL") return; fprintf_s(mFile, "setAttr \".epr[%i]\" -type \"string\" ",epr_i);epr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Proc names for particle collision events.
	Edit this through the particle event editor.
	*/
	void setEventProc(size_t epr_i,const StringID& epr){fprintf_s(mFile,"connectAttr \"");epr.write(mFile);fprintf_s(mFile,"\" \"%s.epr[%i]\";\n",mName.c_str(),epr_i);}
	/*
	This compound attribute groups together the attributes that provide data about
	instanced particles to the instancer node, or other node that can make use of
	this info.
	*/
	void setInstanceData(size_t idt_i,const InstanceData& idt){fprintf_s(mFile, "setAttr \".idt[%i]\" ",idt_i);idt.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This compound attribute groups together the attributes that provide data about
	instanced particles to the instancer node, or other node that can make use of
	this info.
	*/
	void setInstanceData(size_t idt_i,const InstanceDataID& idt){fprintf_s(mFile,"connectAttr \"");idt.write(mFile);fprintf_s(mFile,"\" \"%s.idt[%i]\";\n",mName.c_str(),idt_i);}
	/*
	This attribute defines the names of the attributes for which the instancePointData
	attribute will output per-particle data.
	*/
	void setInstanceAttributeMapping(size_t idt_i,const stringArray& iam){fprintf_s(mFile, "setAttr \".idt[%i].iam\" -type \"stringArray\" ",idt_i);iam.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute contains per-particle data that is created according to the
	string data (attribute names) in the instanceAttributeMapping attribute.
	For each attribute listed by the instanceAttributeMapping, an array of per-particle
	data is output for use by the instancer node.
	*/
	void setInstancePointData(size_t idt_i,const GenericArrayID& ipd){fprintf_s(mFile,"connectAttr \"");ipd.write(mFile);fprintf_s(mFile,"\" \"%s.idt[%i].ipd\";\n",mName.c_str(),idt_i);}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setNumberOfEvents(const ShortID& nev){fprintf_s(mFile,"connectAttr \"");nev.write(mFile);fprintf_s(mFile,"\" \"%s.nev\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setEventNameCount(const ShortID& enc){fprintf_s(mFile,"connectAttr \"");enc.write(mFile);fprintf_s(mFile,"\" \"%s.enc\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setFieldConnections(size_t fc_i,const MessageID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i]\";\n",mName.c_str(),fc_i);}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setCollisionConnections(size_t cc_i,const MessageID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.cc[%i]\";\n",mName.c_str(),cc_i);}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setConnectionsToMe(size_t ct_i,const MessageID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct[%i]\";\n",mName.c_str(),ct_i);}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setAuxiliariesOwned(const MessageID& ao){fprintf_s(mFile,"connectAttr \"");ao.write(mFile);fprintf_s(mFile,"\" \"%s.ao\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setEmitterConnections(size_t ec_i,const MessageID& ec){fprintf_s(mFile,"connectAttr \"");ec.write(mFile);fprintf_s(mFile,"\" \"%s.ec[%i]\";\n",mName.c_str(),ec_i);}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setInheritColor(const BoolID& inc){fprintf_s(mFile,"connectAttr \"");inc.write(mFile);fprintf_s(mFile,"\" \"%s.inc\";\n",mName.c_str());}
	/*Identifies a shape to be used for geometry instancing. (Incomplete in Maya 1.0.)*/
	void setShapeNameMsg(const MessageID& snmg){fprintf_s(mFile,"connectAttr \"");snmg.write(mFile);fprintf_s(mFile,"\" \"%s.snmg\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setDoDynamics(const BoolID& ddy){fprintf_s(mFile,"connectAttr \"");ddy.write(mFile);fprintf_s(mFile,"\" \"%s.ddy\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setDoEmission(const BoolID& dem){fprintf_s(mFile,"connectAttr \"");dem.write(mFile);fprintf_s(mFile,"\" \"%s.dem\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setForceEmission(const BoolID& fem){fprintf_s(mFile,"connectAttr \"");fem.write(mFile);fprintf_s(mFile,"\" \"%s.fem\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setDoAge(const BoolID& dag){fprintf_s(mFile,"connectAttr \"");dag.write(mFile);fprintf_s(mFile,"\" \"%s.dag\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setAgesLastDone(const DoubleID& agld){fprintf_s(mFile,"connectAttr \"");agld.write(mFile);fprintf_s(mFile,"\" \"%s.agld\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setTimeLastComputed(const DoubleID& tlc){fprintf_s(mFile,"connectAttr \"");tlc.write(mFile);fprintf_s(mFile,"\" \"%s.tlc\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setParentMatrixDirty(const BoolID& pmd){fprintf_s(mFile,"connectAttr \"");pmd.write(mFile);fprintf_s(mFile,"\" \"%s.pmd\";\n",mName.c_str());}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setNewFileFormat(short nff){if(nff == 0) return; fprintf_s(mFile, "setAttr \".nff\" %i;\n", nff);}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	void setNewFileFormat(const ShortID& nff){fprintf_s(mFile,"connectAttr \"");nff.write(mFile);fprintf_s(mFile,"\" \"%s.nff\";\n",mName.c_str());}
	/*Turn on depth sorting of particles for rendering.*/
	void setDepthSort(bool ds){if(ds == false) return; fprintf_s(mFile, "setAttr \".ds\" %i;\n", ds);}
	/*Turn on depth sorting of particles for rendering.*/
	void setDepthSort(const BoolID& ds){fprintf_s(mFile,"connectAttr \"");ds.write(mFile);fprintf_s(mFile,"\" \"%s.ds\";\n",mName.c_str());}
	/*Hardware rendering method.*/
	void setParticleRenderType(unsigned int prt){if(prt == 3) return; fprintf_s(mFile, "setAttr \".prt\" %i;\n", prt);}
	/*Hardware rendering method.*/
	void setParticleRenderType(const UnsignedintID& prt){fprintf_s(mFile,"connectAttr \"");prt.write(mFile);fprintf_s(mFile,"\" \"%s.prt\";\n",mName.c_str());}
	/*Disable the dominant axis for cloud better illumination.*/
	void setDisableCloudAxis(bool dca){if(dca == false) return; fprintf_s(mFile, "setAttr \".dca\" %i;\n", dca);}
	/*Disable the dominant axis for cloud better illumination.*/
	void setDisableCloudAxis(const BoolID& dca){fprintf_s(mFile,"connectAttr \"");dca.write(mFile);fprintf_s(mFile,"\" \"%s.dca\";\n",mName.c_str());}
	/*Not yet enabled*/
	void setNormalizeVelocity(bool nvl){if(nvl == false) return; fprintf_s(mFile, "setAttr \".nvl\" %i;\n", nvl);}
	/*Not yet enabled*/
	void setNormalizeVelocity(const BoolID& nvl){fprintf_s(mFile,"connectAttr \"");nvl.write(mFile);fprintf_s(mFile,"\" \"%s.nvl\";\n",mName.c_str());}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(bool oca){if(oca == false) return; fprintf_s(mFile, "setAttr \".mrc.oca\" %i;\n", oca);}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(const BoolID& oca){fprintf_s(mFile,"connectAttr \"");oca.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oca\";\n",mName.c_str());}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(short caa){if(caa == 64) return; fprintf_s(mFile, "setAttr \".mrc.caa\" %i;\n", caa);}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(const ShortID& caa){fprintf_s(mFile,"connectAttr \"");caa.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.caa\";\n",mName.c_str());}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(float car){if(car == 0) return; fprintf_s(mFile, "setAttr \".mrc.car\" %f;\n", car);}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(const FloatID& car){fprintf_s(mFile,"connectAttr \"");car.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.car\";\n",mName.c_str());}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(bool ogi){if(ogi == false) return; fprintf_s(mFile, "setAttr \".mrc.ogi\" %i;\n", ogi);}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(const BoolID& ogi){fprintf_s(mFile,"connectAttr \"");ogi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ogi\";\n",mName.c_str());}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(short gia){if(gia == 64) return; fprintf_s(mFile, "setAttr \".mrc.gia\" %i;\n", gia);}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(const ShortID& gia){fprintf_s(mFile,"connectAttr \"");gia.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gia\";\n",mName.c_str());}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(float gir){if(gir == 0) return; fprintf_s(mFile, "setAttr \".mrc.gir\" %f;\n", gir);}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(const FloatID& gir){fprintf_s(mFile,"connectAttr \"");gir.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gir\";\n",mName.c_str());}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(bool ofg){if(ofg == false) return; fprintf_s(mFile, "setAttr \".mrc.ofg\" %i;\n", ofg);}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(const BoolID& ofg){fprintf_s(mFile,"connectAttr \"");ofg.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ofg\";\n",mName.c_str());}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(int fry){if(fry == 1000) return; fprintf_s(mFile, "setAttr \".mrc.fry\" %i;\n", fry);}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(const IntID& fry){fprintf_s(mFile,"connectAttr \"");fry.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fry\";\n",mName.c_str());}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(float fmn){if(fmn == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmn\" %f;\n", fmn);}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(const FloatID& fmn){fprintf_s(mFile,"connectAttr \"");fmn.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmn\";\n",mName.c_str());}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(float fmx){if(fmx == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmx\" %f;\n", fmx);}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(const FloatID& fmx){fprintf_s(mFile,"connectAttr \"");fmx.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmx\";\n",mName.c_str());}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(short ffi){if(ffi == 1) return; fprintf_s(mFile, "setAttr \".mrc.ffi\" %i;\n", ffi);}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(const ShortID& ffi){fprintf_s(mFile,"connectAttr \"");ffi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ffi\";\n",mName.c_str());}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(bool fgv){if(fgv == false) return; fprintf_s(mFile, "setAttr \".mrc.fgv\" %i;\n", fgv);}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(const BoolID& fgv){fprintf_s(mFile,"connectAttr \"");fgv.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgv\";\n",mName.c_str());}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default.
	*/
	void setMiOverrideSamples(bool oos){if(oos == false) return; fprintf_s(mFile, "setAttr \".mrc.oos\" %i;\n", oos);}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default.
	*/
	void setMiOverrideSamples(const BoolID& oos){fprintf_s(mFile,"connectAttr \"");oos.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oos\";\n",mName.c_str());}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(short mins){if(mins == 1) return; fprintf_s(mFile, "setAttr \".mrc.mins\" %i;\n", mins);}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(const ShortID& mins){fprintf_s(mFile,"connectAttr \"");mins.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mins\";\n",mName.c_str());}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(short maxs){if(maxs == 2) return; fprintf_s(mFile, "setAttr \".mrc.maxs\" %i;\n", maxs);}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(const ShortID& maxs){fprintf_s(mFile,"connectAttr \"");maxs.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.maxs\";\n",mName.c_str());}
	/*
	This contains a list of arrays and each array stores the per particle
	inforamtion of a particular attribute
	*/
	void setPpFieldData(size_t ppfd_i,const GenericArrayID& ppfd){fprintf_s(mFile,"connectAttr \"");ppfd.write(mFile);fprintf_s(mFile,"\" \"%s.ppfd[%i]\";\n",mName.c_str(),ppfd_i);}
	/*
	This contains a list of arrays and each array stores the per particle
	inforamtion of a particular attribute
	*/
	void setOwnerPPFieldData(size_t opfd_i,const GenericArrayID& opfd){fprintf_s(mFile,"connectAttr \"");opfd.write(mFile);fprintf_s(mFile,"\" \"%s.opfd[%i]\";\n",mName.c_str(),opfd_i);}
	/*
	When using a deformer, the output positions from the deformer are connected here
	on the downstream particle object.
	A connection on this attribute indicates that this particle object is not dynamic.
	*/
	void setDeformedPosition(const GenericID& dpos){fprintf_s(mFile,"connectAttr \"");dpos.write(mFile);fprintf_s(mFile,"\" \"%s.dpos\";\n",mName.c_str());}
	/*
	Runtime state, positions in object-space at the end of the time-step, per-particle.
	Requesting this attribute will force the dynamics to be solved.
	*/
	VectorArrayID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.pos",mName.c_str());return (const char*)buffer;}
	/*
	Use this attribute to control position by a ramp.
	The values from this attribute will be copied into "position"
	before each step in the dynamics simulation.
	*/
	VectorArrayID getRampPosition(){char buffer[4096];sprintf_s (buffer, "%s.rps",mName.c_str());return (const char*)buffer;}
	/*
	Centroid (average position) of the particles.
	This is in local coordinates. See also worldCentroid.
	*/
	Double3ID getCentroid(){char buffer[4096];sprintf_s (buffer, "%s.ctd",mName.c_str());return (const char*)buffer;}
	/*
	X-component of centroid (average position) of the particles.
	This is in local coordinates. See also worldCentroid.
	*/
	DoubleID getCentroidX(){char buffer[4096];sprintf_s (buffer, "%s.ctd.ctdx",mName.c_str());return (const char*)buffer;}
	/*
	Y-component of centroid (average position) of the particles.
	This is in local coordinates. See also worldCentroid.
	*/
	DoubleID getCentroidY(){char buffer[4096];sprintf_s (buffer, "%s.ctd.ctdy",mName.c_str());return (const char*)buffer;}
	/*
	Z-component of centroid (average position) of the particles.
	This is in local coordinates. See also worldCentroid.
	*/
	DoubleID getCentroidZ(){char buffer[4096];sprintf_s (buffer, "%s.ctd.ctdz",mName.c_str());return (const char*)buffer;}
	/*
	The position of the particles at the end of the previous
	timestep.  This attribute does force the evaluation of
	dynamics.
	*/
	VectorArrayID getLastPosition(){char buffer[4096];sprintf_s (buffer, "%s.lpos",mName.c_str());return (const char*)buffer;}
	/*Runtime state, velocities at the end of the time-step, per-particle.*/
	VectorArrayID getVelocity(){char buffer[4096];sprintf_s (buffer, "%s.vel",mName.c_str());return (const char*)buffer;}
	/*
	Use this attribute to control velocity with a ramp.
	The values from this attribute will be copied into "velocity"
	before each step in the dynamics simulation.
	*/
	VectorArrayID getRampVelocity(){char buffer[4096];sprintf_s (buffer, "%s.rvl",mName.c_str());return (const char*)buffer;}
	/*
	The velocity at the end of the previous solving step.
	This will have its value set at the END of the previous solving step.
	*/
	VectorArrayID getLastVelocity(){char buffer[4096];sprintf_s (buffer, "%s.lvel",mName.c_str());return (const char*)buffer;}
	/*Runtime state, accelerations, per-particle.*/
	VectorArrayID getAcceleration(){char buffer[4096];sprintf_s (buffer, "%s.acc",mName.c_str());return (const char*)buffer;}
	/*
	This is where all ramps input "acceleration" will actually connect.
	The values from this attribute will be copied into "acceleration"
	before each step in the dynamics simulation.
	*/
	VectorArrayID getRampAcceleration(){char buffer[4096];sprintf_s (buffer, "%s.rac",mName.c_str());return (const char*)buffer;}
	/*
	The effects of fields, goals, etc. on the particles are
	accumulated in this attribute.
	*/
	VectorArrayID getForce(){char buffer[4096];sprintf_s (buffer, "%s.frc",mName.c_str());return (const char*)buffer;}
	/*
	This is the input multi-attribute where any fields acting on
	this particle object are connected.  These are accumulated
	in the computePlug() section for aForce, along with other
	forces like goals.
	*/
	const VectorArrayID& getInputForce(size_t ifc_i){char buffer[4096];sprintf_s (buffer, "%s.ifc[%i]",mName.c_str(),ifc_i);return (const char*)buffer;}
	/*
	This is the world-space position of the particles at the end of the time-step.
	Requesting this attribute will force the dynamics to be solved.
	*/
	VectorArrayID getWorldPosition(){char buffer[4096];sprintf_s (buffer, "%s.wps",mName.c_str());return (const char*)buffer;}
	/*
	World-space centroid (average position) of the particles.
	This is in world coordinates. See also "centroid."
	*/
	Double3ID getWorldCentroid(){char buffer[4096];sprintf_s (buffer, "%s.wctn",mName.c_str());return (const char*)buffer;}
	/*
	X-component of world centroid (average position) of the particles.
	This is in world coordinates. See also "centroid."
	*/
	DoubleID getWorldCentroidX(){char buffer[4096];sprintf_s (buffer, "%s.wctn.wctx",mName.c_str());return (const char*)buffer;}
	/*
	Y-component of world centroid (average position)of the particles.
	This is in world coordinates. See also "centroid."
	*/
	DoubleID getWorldCentroidY(){char buffer[4096];sprintf_s (buffer, "%s.wctn.wcty",mName.c_str());return (const char*)buffer;}
	/*
	Z-component of world centroid (average position) of the particles.
	This is in world coordinates. See also "centroid."
	*/
	DoubleID getWorldCentroidZ(){char buffer[4096];sprintf_s (buffer, "%s.wctn.wctz",mName.c_str());return (const char*)buffer;}
	/*
	The world-space position of the particles at the end of the
	previous timestep.  This attribute does force the evaluation of
	dynamics.
	*/
	VectorArrayID getLastWorldPosition(){char buffer[4096];sprintf_s (buffer, "%s.lwps",mName.c_str());return (const char*)buffer;}
	/*
	This is the world-space velocity of the particles at the end of the time-step.
	This includes motion from the parent matrix.
	*/
	VectorArrayID getWorldVelocity(){char buffer[4096];sprintf_s (buffer, "%s.wvl",mName.c_str());return (const char*)buffer;}
	/*
	This is the world-space velocity of the particles as derived from dynamics
	and from motion of the world matrix.  THis value is then tranformed into
	object-space for drawing.
	*/
	VectorArrayID getWorldVelocityInObjectSpace(){char buffer[4096];sprintf_s (buffer, "%s.wvo",mName.c_str());return (const char*)buffer;}
	/*This is the world-space velocity from the end of the LAST time-step.*/
	VectorArrayID getLastWorldVelocity(){char buffer[4096];sprintf_s (buffer, "%s.lwvl",mName.c_str());return (const char*)buffer;}
	/*This is the world matrix from the last time evaluated (currentSceneTime - sceneTimeStepSize).*/
	MatrixID getLastWorldMatrix(){char buffer[4096];sprintf_s (buffer, "%s.lwm",mName.c_str());return (const char*)buffer;}
	/*Initial state, positions, per-particle.*/
	VectorArrayID getPosition0(){char buffer[4096];sprintf_s (buffer, "%s.pos0",mName.c_str());return (const char*)buffer;}
	/*Initial state, velocities, per-particle.*/
	VectorArrayID getVelocity0(){char buffer[4096];sprintf_s (buffer, "%s.vel0",mName.c_str());return (const char*)buffer;}
	/*Initial state, accelerations, per-particle.*/
	VectorArrayID getAcceleration0(){char buffer[4096];sprintf_s (buffer, "%s.acc0",mName.c_str());return (const char*)buffer;}
	/*
	This attribute holds the name of the file path on which to
	find the startup cache file (see useStartupCache). Users normally
	do not set this attribute.  Maya sets it when creating the cache.
	The path is always relative to the workspace particle data area.
	*/
	StringID getStartupCachePath(){char buffer[4096];sprintf_s (buffer, "%s.scp",mName.c_str());return (const char*)buffer;}
	/*
	Ifentifies the frame for which the current startup cache
	is valid. generally this will be the frame for which this
	object was most recently saved. Users notmally should not
	set this attribute.  Use the Dynamics option window to enable
	or disable startup cache.
	*/
	IntID getStartupCacheFrame(){char buffer[4096];sprintf_s (buffer, "%s.scf",mName.c_str());return (const char*)buffer;}
	/*
	This will have its value set at the END of the solving step.
	This attribute shares the memory with aPosition and is the most
	current value of aPosition WITHOUT forcing evaluation of the
	dynamics.
	*/
	VectorArrayID getCachedPosition(){char buffer[4096];sprintf_s (buffer, "%s.cpos",mName.c_str());return (const char*)buffer;}
	/*
	This is the most current value for aLastPosition WITHOUT
	forcing evaluation of the dynamics.
	*/
	VectorArrayID getLastCachedPosition(){char buffer[4096];sprintf_s (buffer, "%s.lcps",mName.c_str());return (const char*)buffer;}
	/*
	This is the most current value for the aWorldPosition
	attribute WITHOUT forcing evaluation of the dynamics.
	*/
	VectorArrayID getCachedWorldPosition(){char buffer[4096];sprintf_s (buffer, "%s.cwps",mName.c_str());return (const char*)buffer;}
	/*
	Cached World-space centroid (average position) of the particles.
	This is the most current value of the worldCentroid
	WITHOUT forcing the evaluation of dynamics.
	*/
	Double3ID getCachedWorldCentroid(){char buffer[4096];sprintf_s (buffer, "%s.cwcn",mName.c_str());return (const char*)buffer;}
	/*
	Cached World x-component of centroid (average position) of the particles.
	This is the most current value of the worldCentroid
	WITHOUT forcing the evaluation of dynamics.
	*/
	DoubleID getCachedWorldCentroidX(){char buffer[4096];sprintf_s (buffer, "%s.cwcn.cwcx",mName.c_str());return (const char*)buffer;}
	/*
	Cached World y-component of centroid (average position) of the particles.
	This is the most current value of the worldCentroid
	WITHOUT forcing the evaluation of dynamics.
	*/
	DoubleID getCachedWorldCentroidY(){char buffer[4096];sprintf_s (buffer, "%s.cwcn.cwcy",mName.c_str());return (const char*)buffer;}
	/*
	Cached World z-component of centroid (average position) of the particles.
	This is the most current value of the worldCentroid
	WITHOUT forcing the evaluation of dynamics.
	*/
	DoubleID getCachedWorldCentroidZ(){char buffer[4096];sprintf_s (buffer, "%s.cwcn.cwcz",mName.c_str());return (const char*)buffer;}
	/*
	This will have its value set at the END of the solving step.
	Its value will be that of the resulting aVelocity attribute.
	*/
	VectorArrayID getCachedVelocity(){char buffer[4096];sprintf_s (buffer, "%s.cvel",mName.c_str());return (const char*)buffer;}
	/*
	This will have its value set at the END of the solving step.
	Its value will be that of the resulting aVelocity attribute.
	*/
	VectorArrayID getCachedWorldVelocity(){char buffer[4096];sprintf_s (buffer, "%s.cwvl",mName.c_str());return (const char*)buffer;}
	/*The number of particles in the object.*/
	IntID getCount(){char buffer[4096];sprintf_s (buffer, "%s.cnt",mName.c_str());return (const char*)buffer;}
	/*Runtime state, mass, per-particle.*/
	DoubleArrayID getMass(){char buffer[4096];sprintf_s (buffer, "%s.mas",mName.c_str());return (const char*)buffer;}
	/*Initial state, mass, per-particle.*/
	DoubleArrayID getMass0(){char buffer[4096];sprintf_s (buffer, "%s.mas0",mName.c_str());return (const char*)buffer;}
	/*Cached state, mass.*/
	DoubleArrayID getMassCache(){char buffer[4096];sprintf_s (buffer, "%s.masc",mName.c_str());return (const char*)buffer;}
	/*Unique id number for each particle.*/
	DoubleArrayID getParticleId(){char buffer[4096];sprintf_s (buffer, "%s.id",mName.c_str());return (const char*)buffer;}
	/*Initial state, id values, per-particle.*/
	DoubleArrayID getParticleId0(){char buffer[4096];sprintf_s (buffer, "%s.id0",mName.c_str());return (const char*)buffer;}
	/*Cached state, id values.*/
	DoubleArrayID getIdCache(){char buffer[4096];sprintf_s (buffer, "%s.idc",mName.c_str());return (const char*)buffer;}
	/*
	This compound holds the mapping information for the particle
	ID values.
	*/
	IdMappingID getIdMapping(){char buffer[4096];sprintf_s (buffer, "%s.idm",mName.c_str());return (const char*)buffer;}
	/*
	This array holds the particleId values sorted in ascending order.
	Together with idIndex, it can be used to locate a given id
	quickly in the arrays of particle data.
	*/
	IntArrayID getSortedId(){char buffer[4096];sprintf_s (buffer, "%s.idm.sid",mName.c_str());return (const char*)buffer;}
	/*
	This array holds the index positions into the per-particle attribute
	arrays for the corresponding ids stored in aSortedId.
	Together with sortedId, it can be used to locate a given id
	quickly in the arrays of particle data.
	*/
	IntArrayID getIdIndex(){char buffer[4096];sprintf_s (buffer, "%s.idm.idix",mName.c_str());return (const char*)buffer;}
	/*
	This stores the time, in seconds, at which each particle was born.  This
	makes the age computation more accurate and easily calculated.
	*/
	DoubleArrayID getBirthTime(){char buffer[4096];sprintf_s (buffer, "%s.bt",mName.c_str());return (const char*)buffer;}
	/*Initial state, birth times, per-particle.*/
	DoubleArrayID getBirthTime0(){char buffer[4096];sprintf_s (buffer, "%s.bt0",mName.c_str());return (const char*)buffer;}
	/*Cached state, birth times, per-particle.*/
	DoubleArrayID getBirthTimeCache(){char buffer[4096];sprintf_s (buffer, "%s.btc",mName.c_str());return (const char*)buffer;}
	/*Age per-particle in seconds.*/
	DoubleArrayID getAge(){char buffer[4096];sprintf_s (buffer, "%s.ag",mName.c_str());return (const char*)buffer;}
	/*Initial state, ages, per-particle.*/
	DoubleArrayID getAge0(){char buffer[4096];sprintf_s (buffer, "%s.ag0",mName.c_str());return (const char*)buffer;}
	/*Cached state, age values.*/
	DoubleArrayID getAgeCache(){char buffer[4096];sprintf_s (buffer, "%s.agc",mName.c_str());return (const char*)buffer;}
	/*
	This attribute holds all of the particles added to this
	object from emitters and the emit action, but NOT from
	collision events.
	*/
	GenericArrayID getEmission(){char buffer[4096];sprintf_s (buffer, "%s.emt",mName.c_str());return (const char*)buffer;}
	/*
	If the particles were emitted from a volume, die when
	they exit that volume.
	*/
	BoolID getDieOnEmissionVolumeExit(){char buffer[4096];sprintf_s (buffer, "%s.dve",mName.c_str());return (const char*)buffer;}
	/*
	Tells any object whether this particle object has room for any new
	particles or not, based on the maxCount and count attributes.
	*/
	BoolID getIsFull(){char buffer[4096];sprintf_s (buffer, "%s.ifl",mName.c_str());return (const char*)buffer;}
	/*
	Determines which attributes to use for particle lifespan.
	"Range" means use lifespan + lifespanRandom together to give
	each particle an individual lifespan. This lifespan is stored
	in the attribute "finalLifespanPP."
	"PP" means that you want to drive lifespans using the lifespanPP
	attribute.  You must then either write an expression or set
	values for this attribute in the component editor.
	"Live forever" disables lifespan altogether.  In this mode, all
	particles live forever, unless killed by collision events or emission
	volume exit (see the dieOnEmissionVolume exit attribute).
	Lifespan mode has nothing to do with events or
	emission volume exit and does not override them.
	*/
	UnsignedintID getLifespanMode(){char buffer[4096];sprintf_s (buffer, "%s.lfm",mName.c_str());return (const char*)buffer;}
	/*
	Used only if lifespanMode is set to "Random Range."
	Identifies a range of random variation for the lifespan of
	each particle.  If set to a non-zero value, each particle's lifespan
	varies randomly up to plus or minus lifespanRandom/2, with the
	"lifespan" attribute value as the mean (the average lifespan).
	For example, lifespan 5 and lifespanRandom 2 will make the lifespans
	vary between 4 and 6.
	In Constant or Random Range mode, the finalLifespanPP attribute
	stores the values generated from lifespan and lifespanRandom.
	Note: Changes in the values of lifespan and lifespanRandom affect
	only new particles, not particles that already exist.  For example,
	if you key the value of lifespan to be 2 up until frame 50 and 5
	thereafter, then particles generated from frame 1 to 50 will have
	finalLifespanPP 2 and particles generated after frame 50 will have
	finalLifespanPP 5.  The finalLifespanPP values of particles born
	prior to frame 50 will not change.
	*/
	DoubleID getLifespanRandom(){char buffer[4096];sprintf_s (buffer, "%s.lfr",mName.c_str());return (const char*)buffer;}
	/*
	finalLifespanPP stores the final result of the particle object's
	lifespan computations, from whatever lifespan mode is currently
	in force.  if the lifespan mode is "use lifespanPP" then this
	attribute will be a copy of lifespanPP.  If the mode is "constant"
	or "random range" then it will be generated from lifespan and
	lifespan random.  If the mode is "None" then it will be an array
	of maximum float values.  You cannot write to finalLifespanPP,
	the particle object generates it for you.  You can always access
	finalLifespanPP for expressions and it will always be the effective
	lifespan value regardless of mode.
	Note that there is no finalLifespanPP0 initial state attribute.
	Instead, finalLifespanPP values are re-generated when needed
	from the random stream.
	*/
	DoubleArrayID getFinalLifespanPP(){char buffer[4096];sprintf_s (buffer, "%s.flp",mName.c_str());return (const char*)buffer;}
	/*
	This boolean attribute lets the user decide whether they
	want the expressions to happen before or after the dynamics
	is computed.
	*/
	BoolID getExpressionsAfterDynamics(){char buffer[4096];sprintf_s (buffer, "%s.ead",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is where any input attribute for the expressions,
	both runtime and creation, is connected.
	*/
	const GenericID& getInput(size_t xi_i){char buffer[4096];sprintf_s (buffer, "%s.xi[%i]",mName.c_str(),xi_i);return (const char*)buffer;}
	/*
	This attribute is where any output attribute for the expressions,
	both runtime and creation, is connected.
	*/
	const GenericID& getOutput(size_t xo_i){char buffer[4096];sprintf_s (buffer, "%s.xo[%i]",mName.c_str(),xo_i);return (const char*)buffer;}
	/*OBSOLETE ATTRIBUTE.  No effect.*/
	IntID getDiedLastTime(){char buffer[4096];sprintf_s (buffer, "%s.dlt",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE ATTRIBUTE.  No effect.*/
	IntID getNetEmittedLastTime(){char buffer[4096];sprintf_s (buffer, "%s.nlt",mName.c_str());return (const char*)buffer;}
	/*OBSOLETE ATTRIBUTE.  No effect.*/
	IntID getStartEmittedIndex(){char buffer[4096];sprintf_s (buffer, "%s.sei",mName.c_str());return (const char*)buffer;}
	/*Toggle dynamics on/off for this object.*/
	BoolID getIsDynamic(){char buffer[4096];sprintf_s (buffer, "%s.isd",mName.c_str());return (const char*)buffer;}
	/*Fraction of dynamics forces which get applied each time step.*/
	DoubleID getDynamicsWeight(){char buffer[4096];sprintf_s (buffer, "%s.dw",mName.c_str());return (const char*)buffer;}
	/*
	This boolean tells the solver to transform all field forces into object space
	before doing the dynamics.  This makes the particles respond as if they
	were in the same space as the forces when they are in some non-identity
	hierarchy.
	*/
	BoolID getForcesInWorld(){char buffer[4096];sprintf_s (buffer, "%s.fiw",mName.c_str());return (const char*)buffer;}
	/*
	If set to a value less than one, only the corresponding portion of
	existing velocity will be retained when computing the next step.
	For example, if conserve is 0, all existing velocity will be erased
	before each new step. The name "conserve" refers to conservation
	momentum.  Real (Newtonian) physics corresponds to conserve = 1.
	*/
	DoubleID getConserve(){char buffer[4096];sprintf_s (buffer, "%s.con",mName.c_str());return (const char*)buffer;}
	/*
	This boolean tells the particle object to assume that particles created
	from emission are in world space, and to transform them into object space
	before adding them to the particle array.  This makes the particles respond as if
	they were in the same space as the emitter when they are in some non-identity
	hierarchy.
	*/
	BoolID getEmissionInWorld(){char buffer[4096];sprintf_s (buffer, "%s.eiw",mName.c_str());return (const char*)buffer;}
	/*
	Maximum count of particles this shape will allow.
	If some particles die off, new particles will again be accepted
	up to the max count, and so on.
	*/
	IntID getMaxCount(){char buffer[4096];sprintf_s (buffer, "%s.mxc",mName.c_str());return (const char*)buffer;}
	/*
	Currently only used to scale the amount of emission
	to be used for quick motion tests without having to
	change emitter values. Affects only emitted particles.
	*/
	DoubleID getLevelOfDetail(){char buffer[4096];sprintf_s (buffer, "%s.lod",mName.c_str());return (const char*)buffer;}
	/*
	Fraction of emitter velocity that particles emitted into this
	object inherit.
	*/
	DoubleID getInheritFactor(){char buffer[4096];sprintf_s (buffer, "%s.inh",mName.c_str());return (const char*)buffer;}
	/*
	Random number stream seed for emitter's random number stream.
	Separate seed for each emitter. Set seeds equal to get identical
	stream.  Resetting the seed at a particular frame will restart
	the stream.
	*/
	const IntID& getSeed(size_t sd_i){char buffer[4096];sprintf_s (buffer, "%s.sd[%i]",mName.c_str(),sd_i);return (const char*)buffer;}
	/*
	This is the compound that holds all of the default attribute for the
	fields to connect to.  The contents are just sharing the data from
	the real attributes.
	*/
	FieldDataID getFieldData(){char buffer[4096];sprintf_s (buffer, "%s.fd",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the fields will get this particle object's
	position data from.  It will share the data from aPosition.
	*/
	VectorArrayID getFieldDataPosition(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdp",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the fields will get this particle object's
	velcoity data from.  It will share the data from aVelocity.
	*/
	VectorArrayID getFieldDataVelocity(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdv",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the fields will get this particle object's
	mass data from.  It will share the data from aMass.
	*/
	DoubleArrayID getFieldDataMass(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdm",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the fields will get this particle object's
	timeStep size from.  It will share the data from aTimeStepSize.
	*/
	TimeID getFieldDataDeltaTime(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdt",mName.c_str());return (const char*)buffer;}
	/*
	This is the compound that holds all of the default attribute for the
	emitters to connect to.  The contents are just sharing the data from
	the real attributes.
	*/
	EmitterDataID getEmitterData(){char buffer[4096];sprintf_s (buffer, "%s.ed",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the emitters will get this particle object's
	position data from.  It will share the data from aPosition.
	*/
	VectorArrayID getEmitterDataPosition(){char buffer[4096];sprintf_s (buffer, "%s.ed.edp",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the emitters will get this particle object's
	velcoity data from.  It will share the data from aVelocity.
	*/
	VectorArrayID getEmitterDataVelocity(){char buffer[4096];sprintf_s (buffer, "%s.ed.edv",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the emitters will get this particle object's
	timeStep size from.  It will share the data from aTimeStepSize.
	*/
	TimeID getEmitterDataDeltaTime(){char buffer[4096];sprintf_s (buffer, "%s.ed.edt",mName.c_str());return (const char*)buffer;}
	/*
	This is the current time used for the particle solution.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.  There must be some incoming connection in order
	for the particle object to play back.
	*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.cti",mName.c_str());return (const char*)buffer;}
	/*
	This would get the value from aCurrentTime "copied" into it
	at the end of the solving process.  There are no AFFECTS
	relationships here so that requesting this attribute does
	not trigger any other evaluation.  Because of the timing of
	when this attribute gets set, it should not be used by users
	as reliable data.  It is for internal computation only.
	*/
	TimeID getLastTimeEvaluated(){char buffer[4096];sprintf_s (buffer, "%s.lti",mName.c_str());return (const char*)buffer;}
	/*
	Users should not set or use this attribute. Results will be
	unpredictable.
	*/
	TimeID getCachedTime(){char buffer[4096];sprintf_s (buffer, "%s.chti",mName.c_str());return (const char*)buffer;}
	/*
	For internal use only.  Users should not set this.
	It is defined as (currentTime - lastTimeEvaluated)/overSamples.
	*/
	TimeID getTimeStepSize(){char buffer[4096];sprintf_s (buffer, "%s.tss",mName.c_str());return (const char*)buffer;}
	/*
	This is the step size in scene time.  This should be used for world-space
	computations. Users should not set this attribute.
	*/
	TimeID getSceneTimeStepSize(){char buffer[4096];sprintf_s (buffer, "%s.sts",mName.c_str());return (const char*)buffer;}
	/*
	This is the frame after which dynamics will be solved. No dynamics
	will play back for this object prior to startFrame.
	*/
	DoubleID getStartFrame(){char buffer[4096];sprintf_s (buffer, "%s.stf",mName.c_str());return (const char*)buffer;}
	/*
	The time after which dynamics will be solved for this particle object.
	This is set from the startFrame attribute.
	Users should set startFrame instead of this attribute.
	*/
	TimeID getStartTime(){char buffer[4096];sprintf_s (buffer, "%s.stt",mName.c_str());return (const char*)buffer;}
	/*
	Input Geometr(y/ies) for soft body. This should be connected
	from the local/object-space version of the geometry.
	Valid inputs are polygons, nurbs surfaces, nurbs curves, and lattices.
	*/
	GenericID getInputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.igeo",mName.c_str());return (const char*)buffer;}
	/*
	This attribute stores the point data from the inputGeometry
	attribute as a vectorArray.  This allows the expressions to have
	access and knowledge about the geometry.
	*/
	VectorArrayID getInputGeometryPoints(){char buffer[4096];sprintf_s (buffer, "%s.igpt",mName.c_str());return (const char*)buffer;}
	/*
	This attribute tells the particle object which coordinate
	space to make the inputGeometryPoints attribute in.
	The inputGeometry is received with the points in the
	geometry's local space.  If the attribute is set to
	0(kGeomLocal), then those same point values are
	put into the inputGeometryPoints.  If the value is
	1(kGeomWorld), then the point values are transformed
	input world-space with the geometry's world matrix.  Finally,
	if the value is 2(kGeomParticle), then the points are
	transformed into world-space with the geometry's world
	matrix, and then into the particle object's loca space with
	the particle objecty's inverse world matrix.
	*/
	UnsignedintID getInputGeometrySpace(){char buffer[4096];sprintf_s (buffer, "%s.igs",mName.c_str());return (const char*)buffer;}
	/*
	Tells the particle object to keep its count consistent with
	the pointCount of any incoming history in inputGeometry, if one exists.
	*/
	BoolID getEnforceCountFromHistory(){char buffer[4096];sprintf_s (buffer, "%s.ecfh",mName.c_str());return (const char*)buffer;}
	/*Geometry for soft body.*/
	GenericID getTargetGeometry(){char buffer[4096];sprintf_s (buffer, "%s.tgeo",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is optionally connected to from the world matrix
	of the target geometry.  It allows the targetGeometrySpace attribute
	to correctly use the kTargetGeomLocal setting.
	*/
	MatrixID getTargetGeometryWorldMatrix(){char buffer[4096];sprintf_s (buffer, "%s.tgm",mName.c_str());return (const char*)buffer;}
	/*
	This attribute tells the particle object which coordinate
	space to build the targetGeometry data in.
	If targetGeometrySpace is 2(kTargetGeomParticle), then
	the values from the particle object's position attribute
	are used as the points for the target geometry.  If the
	value is 1(kTargetGeomWorld), then the position points
	are transformed into world-space with the particle object's
	world matrix.  If the value is 0(kTargetGeomLocal), then
	the position points are transformed into world-space, and
	then they are transformed into the target geometry's local
	space with the inverse of targetGeometryMatrix if it has an
	incoming connection.  If targetGeometryMatrix does not have
	a connection, then a warning is displayed telling the user
	why it can not get the target geometry's world matrix, and
	the identity matrix is used.
	*/
	UnsignedintID getTargetGeometrySpace(){char buffer[4096];sprintf_s (buffer, "%s.tgs",mName.c_str());return (const char*)buffer;}
	/*
	This value is used to control the "smoothness" of the change in the
	goal forces as the weight changes from 0.0 to 1.0.  This is purely
	an asthetic effect, with no scientific basis.  The higher the number,
	the smoother the change.
	*/
	DoubleID getGoalSmoothness(){char buffer[4096];sprintf_s (buffer, "%s.gsm",mName.c_str());return (const char*)buffer;}
	/*The input geometry attributes for the goal objects.*/
	const GenericID& getGoalGeometry(size_t ggeo_i){char buffer[4096];sprintf_s (buffer, "%s.ggeo[%i]",mName.c_str(),ggeo_i);return (const char*)buffer;}
	/*The goal weights for the various goal objects.*/
	const DoubleID& getGoalWeight(size_t gw_i){char buffer[4096];sprintf_s (buffer, "%s.gw[%i]",mName.c_str(),gw_i);return (const char*)buffer;}
	/*
	The active status for the goal objects.  This is a switch that
	turns each goal ON or OFF.  This has the same visual
	as setting the corresponding goalWeight to 0.  The
	difference is that with a goalActive of OFF, the goal
	positions are not even taken into account in the
	computation, and therefore make the computation run faster.
	*/
	const BoolID& getGoalActive(size_t ga_i){char buffer[4096];sprintf_s (buffer, "%s.ga[%i]",mName.c_str(),ga_i);return (const char*)buffer;}
	/*
	For goal objects that have multiple uv sets, this attribute
	specifies which uv set to use when goalU/goalV values are
	present for particles.
	*/
	const StringID& getGoalUvSetName(size_t guv_i){char buffer[4096];sprintf_s (buffer, "%s.guv[%i]",mName.c_str(),guv_i);return (const char*)buffer;}
	/*Indicates that caching is on/off.*/
	BoolID getCacheData(){char buffer[4096];sprintf_s (buffer, "%s.chd",mName.c_str());return (const char*)buffer;}
	/*
	The width of the cache is the number of different time points
	for which the state can be cached.
	*/
	IntID getCacheWidth(){char buffer[4096];sprintf_s (buffer, "%s.chw",mName.c_str());return (const char*)buffer;}
	/*
	This is the maximum number of consecutive collisions that are
	detected within a frame for each particle.  Particles may
	collide fewer times, of course.
	*/
	IntID getTraceDepth(){char buffer[4096];sprintf_s (buffer, "%s.trd",mName.c_str());return (const char*)buffer;}
	/*Parent attribute for all collision input data.*/
	CollisionDataID getCollisionData(){char buffer[4096];sprintf_s (buffer, "%s.cda",mName.c_str());return (const char*)buffer;}
	/*The swept geometry for the connected shape.*/
	const SweptGeometryID& getCollisionGeometry(size_t cge_i){char buffer[4096];sprintf_s (buffer, "%s.cda.cge[%i]",mName.c_str(),cge_i);return (const char*)buffer;}
	/*How much of the particle's velocity perpendicular to the surface is reflected*/
	const DoubleID& getCollisionResilience(size_t crs_i){char buffer[4096];sprintf_s (buffer, "%s.cda.crs[%i]",mName.c_str(),crs_i);return (const char*)buffer;}
	/*The amount of a particle's velocity parallel to a surface that is lost in the collision*/
	const DoubleID& getCollisionFriction(size_t cfr_i){char buffer[4096];sprintf_s (buffer, "%s.cda.cfr[%i]",mName.c_str(),cfr_i);return (const char*)buffer;}
	/*The distance the particle is offset from point of intersection on surface during reflection.*/
	const DoubleID& getCollisionOffset(size_t cof_i){char buffer[4096];sprintf_s (buffer, "%s.cda.cof[%i]",mName.c_str(),cof_i);return (const char*)buffer;}
	/*
	This is the READ-ONLY attribute where all of the information
	about the particle object's collisions for each frame is
	stored.
	*/
	GenericArrayID getCollisionRecords(){char buffer[4096];sprintf_s (buffer, "%s.crc",mName.c_str());return (const char*)buffer;}
	/*
	Total number of collisions which have occurred for this object.
	All collisions are counted regardless of whether any collision
	events were actually executed.  In other words, totalEventCount
	is the sum of the per-particle "event" attribute.
	*/
	IntID getTotalEventCount(){char buffer[4096];sprintf_s (buffer, "%s.tec",mName.c_str());return (const char*)buffer;}
	/*
	True if any particle collision has occured since the last time
	the attribute was read. However, if you read the attribute twice
	in succession in the same frame you will get the same result both
	times. Note that it does not matter whether collision events were
	executed at the collisions in question.
	*/
	BoolID getEventTest(){char buffer[4096];sprintf_s (buffer, "%s.evt",mName.c_str());return (const char*)buffer;}
	/*Used to compute eventTest attribute.*/
	IntID getLastTotalEventCount(){char buffer[4096];sprintf_s (buffer, "%s.ltec",mName.c_str());return (const char*)buffer;}
	/*
	Target parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	const MessageID& getEventTarget(size_t etg_i){char buffer[4096];sprintf_s (buffer, "%s.etg[%i]",mName.c_str(),etg_i);return (const char*)buffer;}
	/*
	Names of particle collision events.
	Edit this through the particle event editor.
	*/
	const StringID& getEventName(size_t evn_i){char buffer[4096];sprintf_s (buffer, "%s.evn[%i]",mName.c_str(),evn_i);return (const char*)buffer;}
	/*
	Marks valid particle collision events.
	Setting this to false turns an event off, in effect.
	Edit this through the particle event editor.
	*/
	const IntID& getEventValid(size_t evv_i){char buffer[4096];sprintf_s (buffer, "%s.evv[%i]",mName.c_str(),evv_i);return (const char*)buffer;}
	/*
	Event count parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	const ShortID& getEventCount(size_t ecp_i){char buffer[4096];sprintf_s (buffer, "%s.ecp[%i]",mName.c_str(),ecp_i);return (const char*)buffer;}
	/*
	Emit parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	const ShortID& getEventEmit(size_t eve_i){char buffer[4096];sprintf_s (buffer, "%s.eve[%i]",mName.c_str(),eve_i);return (const char*)buffer;}
	/*
	Split parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	const ShortID& getEventSplit(size_t evs_i){char buffer[4096];sprintf_s (buffer, "%s.evs[%i]",mName.c_str(),evs_i);return (const char*)buffer;}
	/*
	Die parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	const ShortID& getEventDie(size_t evd_i){char buffer[4096];sprintf_s (buffer, "%s.evd[%i]",mName.c_str(),evd_i);return (const char*)buffer;}
	/*
	Random parameters of particle collision events.
	Edit this through the particle event editor.
	*/
	const ShortID& getEventRandom(size_t evr_i){char buffer[4096];sprintf_s (buffer, "%s.evr[%i]",mName.c_str(),evr_i);return (const char*)buffer;}
	/*
	Controls random distribution of multiple particles created at single collision.
	Edit this through the particle event editor.
	*/
	const DoubleID& getEventSpread(size_t esp_i){char buffer[4096];sprintf_s (buffer, "%s.esp[%i]",mName.c_str(),esp_i);return (const char*)buffer;}
	/*
	Proc names for particle collision events.
	Edit this through the particle event editor.
	*/
	const StringID& getEventProc(size_t epr_i){char buffer[4096];sprintf_s (buffer, "%s.epr[%i]",mName.c_str(),epr_i);return (const char*)buffer;}
	/*
	This compound attribute groups together the attributes that provide data about
	instanced particles to the instancer node, or other node that can make use of
	this info.
	*/
	const InstanceDataID& getInstanceData(size_t idt_i){char buffer[4096];sprintf_s (buffer, "%s.idt[%i]",mName.c_str(),idt_i);return (const char*)buffer;}
	/*
	This attribute contains per-particle data that is created according to the
	string data (attribute names) in the instanceAttributeMapping attribute.
	For each attribute listed by the instanceAttributeMapping, an array of per-particle
	data is output for use by the instancer node.
	*/
	const GenericArrayID& getInstancePointData(size_t idt_i){char buffer[4096];sprintf_s (buffer, "%s.idt[%i].ipd",mName.c_str(),idt_i);return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	ShortID getNumberOfEvents(){char buffer[4096];sprintf_s (buffer, "%s.nev",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	ShortID getEventNameCount(){char buffer[4096];sprintf_s (buffer, "%s.enc",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	const MessageID& getFieldConnections(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i]",mName.c_str(),fc_i);return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	const MessageID& getCollisionConnections(size_t cc_i){char buffer[4096];sprintf_s (buffer, "%s.cc[%i]",mName.c_str(),cc_i);return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	const MessageID& getConnectionsToMe(size_t ct_i){char buffer[4096];sprintf_s (buffer, "%s.ct[%i]",mName.c_str(),ct_i);return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	MessageID getAuxiliariesOwned(){char buffer[4096];sprintf_s (buffer, "%s.ao",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	const MessageID& getEmitterConnections(size_t ec_i){char buffer[4096];sprintf_s (buffer, "%s.ec[%i]",mName.c_str(),ec_i);return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	BoolID getInheritColor(){char buffer[4096];sprintf_s (buffer, "%s.inc",mName.c_str());return (const char*)buffer;}
	/*Identifies a shape to be used for geometry instancing. (Incomplete in Maya 1.0.)*/
	MessageID getShapeNameMsg(){char buffer[4096];sprintf_s (buffer, "%s.snmg",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	BoolID getDoDynamics(){char buffer[4096];sprintf_s (buffer, "%s.ddy",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	BoolID getDoEmission(){char buffer[4096];sprintf_s (buffer, "%s.dem",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	BoolID getForceEmission(){char buffer[4096];sprintf_s (buffer, "%s.fem",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	BoolID getDoAge(){char buffer[4096];sprintf_s (buffer, "%s.dag",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	DoubleID getAgesLastDone(){char buffer[4096];sprintf_s (buffer, "%s.agld",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	DoubleID getTimeLastComputed(){char buffer[4096];sprintf_s (buffer, "%s.tlc",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	BoolID getParentMatrixDirty(){char buffer[4096];sprintf_s (buffer, "%s.pmd",mName.c_str());return (const char*)buffer;}
	/*Obsolete.  No function.  Will be removed in next major release.*/
	ShortID getNewFileFormat(){char buffer[4096];sprintf_s (buffer, "%s.nff",mName.c_str());return (const char*)buffer;}
	/*Turn on depth sorting of particles for rendering.*/
	BoolID getDepthSort(){char buffer[4096];sprintf_s (buffer, "%s.ds",mName.c_str());return (const char*)buffer;}
	/*Hardware rendering method.*/
	UnsignedintID getParticleRenderType(){char buffer[4096];sprintf_s (buffer, "%s.prt",mName.c_str());return (const char*)buffer;}
	/*Disable the dominant axis for cloud better illumination.*/
	BoolID getDisableCloudAxis(){char buffer[4096];sprintf_s (buffer, "%s.dca",mName.c_str());return (const char*)buffer;}
	/*Not yet enabled*/
	BoolID getNormalizeVelocity(){char buffer[4096];sprintf_s (buffer, "%s.nvl",mName.c_str());return (const char*)buffer;}
	/*This is a root of following mental ray attributes.*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideCaustics(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oca",mName.c_str());return (const char*)buffer;}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	ShortID getMiCausticAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.caa",mName.c_str());return (const char*)buffer;}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	FloatID getMiCausticRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.car",mName.c_str());return (const char*)buffer;}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideGlobalIllumination(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ogi",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	ShortID getMiGlobillumAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gia",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	FloatID getMiGlobillumRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gir",mName.c_str());return (const char*)buffer;}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideFinalGather(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ofg",mName.c_str());return (const char*)buffer;}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	IntID getMiFinalGatherRays(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fry",mName.c_str());return (const char*)buffer;}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMinRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmn",mName.c_str());return (const char*)buffer;}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMaxRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmx",mName.c_str());return (const char*)buffer;}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	ShortID getMiFinalGatherFilter(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ffi",mName.c_str());return (const char*)buffer;}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	BoolID getMiFinalGatherView(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgv",mName.c_str());return (const char*)buffer;}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default.
	*/
	BoolID getMiOverrideSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oos",mName.c_str());return (const char*)buffer;}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	ShortID getMiMinSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mins",mName.c_str());return (const char*)buffer;}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	ShortID getMiMaxSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.maxs",mName.c_str());return (const char*)buffer;}
	/*
	This contains a list of arrays and each array stores the per particle
	inforamtion of a particular attribute
	*/
	const GenericArrayID& getPpFieldData(size_t ppfd_i){char buffer[4096];sprintf_s (buffer, "%s.ppfd[%i]",mName.c_str(),ppfd_i);return (const char*)buffer;}
	/*
	This contains a list of arrays and each array stores the per particle
	inforamtion of a particular attribute
	*/
	const GenericArrayID& getOwnerPPFieldData(size_t opfd_i){char buffer[4096];sprintf_s (buffer, "%s.opfd[%i]",mName.c_str(),opfd_i);return (const char*)buffer;}
	/*
	When using a deformer, the output positions from the deformer are connected here
	on the downstream particle object.
	A connection on this attribute indicates that this particle object is not dynamic.
	*/
	GenericID getDeformedPosition(){char buffer[4096];sprintf_s (buffer, "%s.dpos",mName.c_str());return (const char*)buffer;}
protected:
	Particle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DeformableShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLE_H__
