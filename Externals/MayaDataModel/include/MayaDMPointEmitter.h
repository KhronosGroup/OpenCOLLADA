/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POINTEMITTER_H__
#define __MayaDM_POINTEMITTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDynBase.h"
namespace MayaDM
{
/*
<p><pre>    The emitter node is a dependency graph node used to generate particles
  which then live in a a particle shape node. The emitter type determines
  the general characteristic of the emission. Some attributes do not
  apply to all types emitters.
</pre></p>
*/
class PointEmitter : public DynBase
{
public:
public:
	PointEmitter(FILE* file,const std::string& name,const std::string& parent=""):DynBase(file, name, parent, "pointEmitter"){}
	virtual ~PointEmitter(){}
	/*
	Specifies the emitter type: omni, directional, surface,
	curve, or some type of volume.
	*/
	void setEmitterType(unsigned int emt){if(emt == 1) return; fprintf_s(mFile, "setAttr \".emt\" %i;\n", emt);}
	/*
	Specifies the emitter type: omni, directional, surface,
	curve, or some type of volume.
	*/
	void setEmitterType(const UnsignedintID& emt){fprintf_s(mFile,"connectAttr \"");emt.write(mFile);fprintf_s(mFile,"\" \"%s.emt\";\n",mName.c_str());}
	/*Rate of emission per second.*/
	void setRate(double rat){if(rat == 100) return; fprintf_s(mFile, "setAttr \".rat\" %f;\n", rat);}
	/*Rate of emission per second.*/
	void setRate(const DoubleID& rat){fprintf_s(mFile,"connectAttr \"");rat.write(mFile);fprintf_s(mFile,"\" \"%s.rat\";\n",mName.c_str());}
	/*
	Applies to curve and surface emitters, only.
	If true, number of particles is determined by object size
	(area or length) times rate value.  If false, object size
	is ignored and the rate value is used without modification.
	The former is the way Maya behaved prior to version 3.0.
	*/
	void setScaleRateByObjectSize(bool sro){if(sro == true) return; fprintf_s(mFile, "setAttr \".sro\" %i;\n", sro);}
	/*
	It determines if the node uses RatePP or Rate.
	By default, this node uses Rate.
	*/
	void setUseRatePP(bool urpp){if(urpp == false) return; fprintf_s(mFile, "setAttr \".urpp\" %i;\n", urpp);}
	/*
	If aNeedParentUV is true, send (u,v) coordinates for point of
	emission to the particle object. Particle object must have
	parentU/parentV attributes.  Applies only to nurbs surfaces.
	*/
	void setNeedParentUV(bool npuv){if(npuv == false) return; fprintf_s(mFile, "setAttr \".npuv\" %i;\n", npuv);}
	/*
	Cycling emission restarts the random number stream after
	an interval in frames, specified by the cycleInterval attribute.
	Setting cycleEmission to "Frame" and cycleInterval to 1 is
	will cause the random stream to re-start every frame.
	cycleInterval values greater than 1 can be used
	to generate cycles for games work.  Note that this resets ONLY
	the random stream used by the emitter. It does not reset the random
	number stream used by Mel, shaders, etc.
	Note also that the "frame" option resets at most once per frame.
	Use caution when animating the particle's currentTime.
	However, oversampling does not affect the results.
	*/
	void setCycleEmission(unsigned int cye){if(cye == 0) return; fprintf_s(mFile, "setAttr \".cye\" %i;\n", cye);}
	/*
	Cycling emission restarts the random number stream after
	an interval in frames, specified by the cycleInterval attribute.
	Setting cycleEmission to "Frame" and cycleInterval to 1 is
	will cause the random stream to re-start every frame.
	cycleInterval values greater than 1 can be used
	to generate cycles for games work.  Note that this resets ONLY
	the random stream used by the emitter. It does not reset the random
	number stream used by Mel, shaders, etc.
	Note also that the "frame" option resets at most once per frame.
	Use caution when animating the particle's currentTime.
	However, oversampling does not affect the results.
	*/
	void setCycleEmission(const UnsignedintID& cye){fprintf_s(mFile,"connectAttr \"");cye.write(mFile);fprintf_s(mFile,"\" \"%s.cye\";\n",mName.c_str());}
	/*
	Specifies the number of frames between restarts of
	the random number stream.  See cycleEmission.  Has no effect if
	cycleEmission is set to None.
	*/
	void setCycleInterval(int cyi){if(cyi == 1) return; fprintf_s(mFile, "setAttr \".cyi\" %i;\n", cyi);}
	/*
	Specifies the number of frames between restarts of
	the random number stream.  See cycleEmission.  Has no effect if
	cycleEmission is set to None.
	*/
	void setCycleInterval(const IntID& cyi){fprintf_s(mFile,"connectAttr \"");cyi.write(mFile);fprintf_s(mFile,"\" \"%s.cyi\";\n",mName.c_str());}
	/*
	Maximum distance at which new particles or density is created
	from emitter. Not used for volume emitters.
	*/
	void setMaxDistance(double max){if(max == 0) return; fprintf_s(mFile, "setAttr \".max\" %f;\n", max);}
	/*
	Maximum distance at which new particles or density is created
	from emitter. Not used for volume emitters.
	*/
	void setMaxDistance(const DoubleID& max){fprintf_s(mFile,"connectAttr \"");max.write(mFile);fprintf_s(mFile,"\" \"%s.max\";\n",mName.c_str());}
	/*
	Minimum distance at which new particles are created
	from emitter.
	Not used for volume emitters.
	*/
	void setMinDistance(double min){if(min == 0) return; fprintf_s(mFile, "setAttr \".min\" %f;\n", min);}
	/*
	Minimum distance at which new particles are created
	from emitter.
	Not used for volume emitters.
	*/
	void setMinDistance(const DoubleID& min){fprintf_s(mFile,"connectAttr \"");min.write(mFile);fprintf_s(mFile,"\" \"%s.min\";\n",mName.c_str());}
	/*Direction of emitter. Not used for omni emitters.*/
	void setDirection(const double3& d){fprintf_s(mFile, "setAttr \".d\" -type \"double3\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*Direction of emitter. Not used for omni emitters.*/
	void setDirection(const Double3ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*X-component of direction of emission (if directional).*/
	void setDirectionX(double dx){if(dx == 1.0) return; fprintf_s(mFile, "setAttr \".d.dx\" %f;\n", dx);}
	/*X-component of direction of emission (if directional).*/
	void setDirectionX(const DoubleID& dx){fprintf_s(mFile,"connectAttr \"");dx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dx\";\n",mName.c_str());}
	/*Y-component of direction of emission (if directional).*/
	void setDirectionY(double dy){if(dy == 0.0) return; fprintf_s(mFile, "setAttr \".d.dy\" %f;\n", dy);}
	/*Y-component of direction of emission (if directional).*/
	void setDirectionY(const DoubleID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.d.dy\";\n",mName.c_str());}
	/*Z-component of direction of emission (if directional).*/
	void setDirectionZ(double dz){if(dz == 0.0) return; fprintf_s(mFile, "setAttr \".d.dz\" %f;\n", dz);}
	/*Z-component of direction of emission (if directional).*/
	void setDirectionZ(const DoubleID& dz){fprintf_s(mFile,"connectAttr \"");dz.write(mFile);fprintf_s(mFile,"\" \"%s.d.dz\";\n",mName.c_str());}
	/*Degree of spread off direction axis as fraction of 90 degrees.*/
	void setSpread(double spr){if(spr == 0.0) return; fprintf_s(mFile, "setAttr \".spr\" %f;\n", spr);}
	/*Degree of spread off direction axis as fraction of 90 degrees.*/
	void setSpread(const DoubleID& spr){fprintf_s(mFile,"connectAttr \"");spr.write(mFile);fprintf_s(mFile,"\" \"%s.spr\";\n",mName.c_str());}
	/*Initial velocity multiplier.*/
	void setSpeed(double spd){if(spd == 1.0) return; fprintf_s(mFile, "setAttr \".spd\" %f;\n", spd);}
	/*Initial velocity multiplier.*/
	void setSpeed(const DoubleID& spd){fprintf_s(mFile,"connectAttr \"");spd.write(mFile);fprintf_s(mFile,"\" \"%s.spd\";\n",mName.c_str());}
	/*
	Identifies a range of random variation for the speed of
	each generated particle.  If set to a non-zero value, speed
	becomes the mean value of the generated particles, whose speeds
	vary by a random amount up to plus or minus speedRandom/2.
	For example, speed 5 and speedRandom 2 will make the speeds
	vary between 4 and 6.
	*/
	void setSpeedRandom(double srnd){if(srnd == 0.0) return; fprintf_s(mFile, "setAttr \".srnd\" %f;\n", srnd);}
	/*
	Identifies a range of random variation for the speed of
	each generated particle.  If set to a non-zero value, speed
	becomes the mean value of the generated particles, whose speeds
	vary by a random amount up to plus or minus speedRandom/2.
	For example, speed 5 and speedRandom 2 will make the speeds
	vary between 4 and 6.
	*/
	void setSpeedRandom(const DoubleID& srnd){fprintf_s(mFile,"connectAttr \"");srnd.write(mFile);fprintf_s(mFile,"\" \"%s.srnd\";\n",mName.c_str());}
	/*Surface emission only. Speed multipler tangent to emitting plane.*/
	void setTangentSpeed(double tspd){if(tspd == 0.0) return; fprintf_s(mFile, "setAttr \".tspd\" %f;\n", tspd);}
	/*Surface emission only. Speed multipler tangent to emitting plane.*/
	void setTangentSpeed(const DoubleID& tspd){fprintf_s(mFile,"connectAttr \"");tspd.write(mFile);fprintf_s(mFile,"\" \"%s.tspd\";\n",mName.c_str());}
	/*Speed multipler normal to emitting plane or emitting curve.*/
	void setNormalSpeed(double nspd){if(nspd == 1.0) return; fprintf_s(mFile, "setAttr \".nspd\" %f;\n", nspd);}
	/*Speed multipler normal to emitting plane or emitting curve.*/
	void setNormalSpeed(const DoubleID& nspd){fprintf_s(mFile,"connectAttr \"");nspd.write(mFile);fprintf_s(mFile,"\" \"%s.nspd\";\n",mName.c_str());}
	/*The current scene time. It is connected with time1.*/
	void setCurrentTime(const TimeID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*
	It is connected with the particle object(target particle).
	The final velocities of new particles has a portion of emitter's
	velocity multiplying inheritFactor.
	*/
	void setInheritFactor(size_t inh_i,double inh){if(inh == 0.0) return; fprintf_s(mFile, "setAttr \".inh[%i]\" %f;\n", inh_i,inh);}
	/*
	It is connected with the particle object(target particle).
	The final velocities of new particles has a portion of emitter's
	velocity multiplying inheritFactor.
	*/
	void setInheritFactor(size_t inh_i,const DoubleID& inh){fprintf_s(mFile,"connectAttr \"");inh.write(mFile);fprintf_s(mFile,"\" \"%s.inh[%i]\";\n",mName.c_str(),inh_i);}
	/*
	It determines if the target particle object has enough particles.
	If it is true, no more emission.
	*/
	void setIsFull(size_t full_i,bool full){if(full == false) return; fprintf_s(mFile, "setAttr \".full[%i]\" %i;\n", full_i,full);}
	/*
	It determines if the target particle object has enough particles.
	If it is true, no more emission.
	*/
	void setIsFull(size_t full_i,const BoolID& full){fprintf_s(mFile,"connectAttr \"");full.write(mFile);fprintf_s(mFile,"\" \"%s.full[%i]\";\n",mName.c_str(),full_i);}
	/*
	It is used to determine if emitting particles.
	If currentTime <= startTime, reset emitter states, such as
	remainder, fLastWorldPoint. It is connected with target particle.
	*/
	void setStartTime(size_t stt_i,const TimeID& stt){fprintf_s(mFile,"connectAttr \"");stt.write(mFile);fprintf_s(mFile,"\" \"%s.stt[%i]\";\n",mName.c_str(),stt_i);}
	/*
	An elapsed time since particles were emitted.
	It is connected with particle object.
	*/
	void setDeltaTime(size_t dt_i,const TimeID& dt){fprintf_s(mFile,"connectAttr \"");dt.write(mFile);fprintf_s(mFile,"\" \"%s.dt[%i]\";\n",mName.c_str(),dt_i);}
	/*
	This is a storage to save emit count remainder. It is for positional
	emitter only(curve/surface emitter handles remainder differently).
	*/
	void setEmitCountRemainder(size_t ecr_i,const DoubleArrayID& ecr){fprintf_s(mFile,"connectAttr \"");ecr.write(mFile);fprintf_s(mFile,"\" \"%s.ecr[%i]\";\n",mName.c_str(),ecr_i);}
	/*
	Rate per-particle array. It is connected with its owner object.
	If aUseRatePP is true, this node will use ratePP.
	*/
	void setRatePP(const doubleArray& rpp){if(rpp.size == 0) return; fprintf_s(mFile, "setAttr \".rpp\" -type \"doubleArray\" ");rpp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	If the emitter's owner is a particle object, it will be connected with
	the owner. The new particles know where they from.
	*/
	void setParentId(const doubleArray& paid){if(paid.size == 0) return; fprintf_s(mFile, "setAttr \".paid\" -type \"doubleArray\" ");paid.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is for surface/curve emitter. The owner is a geoConnector.
	The geoConnector creates triangle/line list from a surface/curve.
	*/
	void setSweptGeometry(const SweptGeometryID& swge){fprintf_s(mFile,"connectAttr \"");swge.write(mFile);fprintf_s(mFile,"\" \"%s.swge\";\n",mName.c_str());}
	/*It outputs new particles to the particle object.*/
	void setOutput(size_t ot_i,const GenericArrayID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot[%i]\";\n",mName.c_str(),ot_i);}
	/*
	Random number stream seed for emitter's own random number stream.
	Separate seed for each particle object into which we are emitting.
	*/
	void setSeed(size_t sd_i,const IntID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd[%i]\";\n",mName.c_str(),sd_i);}
	/*Random state attribute to hold emitter's own random number stream.*/
	void setRandStateX(size_t rst_i,int rstx){if(rstx == 0) return; fprintf_s(mFile, "setAttr \".rst[%i].rstx\" %i;\n", rst_i,rstx);}
	/*Random state attribute to hold emitter's own random number stream.*/
	void setRandStateY(size_t rst_i,int rsty){if(rsty == 0) return; fprintf_s(mFile, "setAttr \".rst[%i].rsty\" %i;\n", rst_i,rsty);}
	/*Random state attribute to hold emitter's own random number stream.*/
	void setRandStateZ(size_t rst_i,int rstz){if(rstz == 0) return; fprintf_s(mFile, "setAttr \".rst[%i].rstz\" %i;\n", rst_i,rstz);}
	/*
	If it is on, the surface emitter generates particles based on
	texture information of the geometric owner. Note that a texture
	can have a continous range of values while a particle either
	exists or does not exist. As a consequence of this the texture is
	used to filter the particles. The emission of particles more closely
	matches the texture as the rate of particle emission increases.
	Since low emission rates do not clearly match the texture a
	high emission rate is recommended when textured emission is being used.
	*/
	void setEnableTextureRate(bool etr){if(etr == false) return; fprintf_s(mFile, "setAttr \".etr\" %i;\n", etr);}
	/*
	If it is on, the surface emitter generates particles based on
	texture information of the geometric owner. Note that a texture
	can have a continous range of values while a particle either
	exists or does not exist. As a consequence of this the texture is
	used to filter the particles. The emission of particles more closely
	matches the texture as the rate of particle emission increases.
	Since low emission rates do not clearly match the texture a
	high emission rate is recommended when textured emission is being used.
	*/
	void setEnableTextureRate(const BoolID& etr){fprintf_s(mFile,"connectAttr \"");etr.write(mFile);fprintf_s(mFile,"\" \"%s.etr\";\n",mName.c_str());}
	/*It is connected with the texture node which control the rate.*/
	void setTextureRate(const float3& txr){if(txr == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".txr\" -type \"float3\" ");txr.write(mFile);fprintf_s(mFile,";\n");}
	/*It is connected with the texture node which control the rate.*/
	void setTextureRate(const Float3ID& txr){fprintf_s(mFile,"connectAttr \"");txr.write(mFile);fprintf_s(mFile,"\" \"%s.txr\";\n",mName.c_str());}
	/*See comments for aTextureRate.*/
	void setTextureRateR(float txrr){if(txrr == 0.0) return; fprintf_s(mFile, "setAttr \".txr.txrr\" %f;\n", txrr);}
	/*See comments for aTextureRate.*/
	void setTextureRateR(const FloatID& txrr){fprintf_s(mFile,"connectAttr \"");txrr.write(mFile);fprintf_s(mFile,"\" \"%s.txr.txrr\";\n",mName.c_str());}
	/*See comments for aTextureRate.*/
	void setTextureRateG(float txrg){if(txrg == 0.0) return; fprintf_s(mFile, "setAttr \".txr.txrg\" %f;\n", txrg);}
	/*See comments for aTextureRate.*/
	void setTextureRateG(const FloatID& txrg){fprintf_s(mFile,"connectAttr \"");txrg.write(mFile);fprintf_s(mFile,"\" \"%s.txr.txrg\";\n",mName.c_str());}
	/*See comments for aTextureRate.*/
	void setTextureRateB(float txrb){if(txrb == 0.0) return; fprintf_s(mFile, "setAttr \".txr.txrb\" %f;\n", txrb);}
	/*See comments for aTextureRate.*/
	void setTextureRateB(const FloatID& txrb){fprintf_s(mFile,"connectAttr \"");txrb.write(mFile);fprintf_s(mFile,"\" \"%s.txr.txrb\";\n",mName.c_str());}
	/*If it is on, particles will be emitted from dark area.*/
	void setEmitFromDark(bool efd){if(efd == false) return; fprintf_s(mFile, "setAttr \".efd\" %i;\n", efd);}
	/*If it is on, particles will be emitted from dark area.*/
	void setEmitFromDark(const BoolID& efd){fprintf_s(mFile,"connectAttr \"");efd.write(mFile);fprintf_s(mFile,"\" \"%s.efd\";\n",mName.c_str());}
	/*
	If it is true, emitter passes the color to new particles.
	The color may be from a texture or color selector.
	*/
	void setInheritColor(bool inhc){if(inhc == false) return; fprintf_s(mFile, "setAttr \".inhc\" %i;\n", inhc);}
	/*
	If it is true, emitter passes the color to new particles.
	The color may be from a texture or color selector.
	*/
	void setInheritColor(const BoolID& inhc){fprintf_s(mFile,"connectAttr \"");inhc.write(mFile);fprintf_s(mFile,"\" \"%s.inhc\";\n",mName.c_str());}
	/*
	If it is true, emitter passes the opacity to new particles if
	there is a texture node is connected to the particle color attribute.
	*/
	void setInheritOpacity(bool inho){if(inho == false) return; fprintf_s(mFile, "setAttr \".inho\" %i;\n", inho);}
	/*
	If it is true, emitter passes the opacity to new particles if
	there is a texture node is connected to the particle color attribute.
	*/
	void setInheritOpacity(const BoolID& inho){fprintf_s(mFile,"connectAttr \"");inho.write(mFile);fprintf_s(mFile,"\" \"%s.inho\";\n",mName.c_str());}
	/*If it is true, use invert-alpha as opacity for new particles.*/
	void setInvertOpacity(bool invo){if(invo == false) return; fprintf_s(mFile, "setAttr \".invo\" %i;\n", invo);}
	/*If it is true, use invert-alpha as opacity for new particles.*/
	void setInvertOpacity(const BoolID& invo){fprintf_s(mFile,"connectAttr \"");invo.write(mFile);fprintf_s(mFile,"\" \"%s.invo\";\n",mName.c_str());}
	/*If it is true, use luminance as opacity for new particles.*/
	void setUseLuminance(bool usel){if(usel == false) return; fprintf_s(mFile, "setAttr \".usel\" %i;\n", usel);}
	/*If it is true, use luminance as opacity for new particles.*/
	void setUseLuminance(const BoolID& usel){fprintf_s(mFile,"connectAttr \"");usel.write(mFile);fprintf_s(mFile,"\" \"%s.usel\";\n",mName.c_str());}
	/*The color for new particles.*/
	void setParticleColor(const float3& pc){if(pc == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".pc\" -type \"float3\" ");pc.write(mFile);fprintf_s(mFile,";\n");}
	/*The color for new particles.*/
	void setParticleColor(const Float3ID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*The color for new particles.*/
	void setParticleColorR(float pcr){if(pcr == 0.5) return; fprintf_s(mFile, "setAttr \".pc.pcr\" %f;\n", pcr);}
	/*The color for new particles.*/
	void setParticleColorR(const FloatID& pcr){fprintf_s(mFile,"connectAttr \"");pcr.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcr\";\n",mName.c_str());}
	/*The color for new particles.*/
	void setParticleColorG(float pcg){if(pcg == 0.5) return; fprintf_s(mFile, "setAttr \".pc.pcg\" %f;\n", pcg);}
	/*The color for new particles.*/
	void setParticleColorG(const FloatID& pcg){fprintf_s(mFile,"connectAttr \"");pcg.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcg\";\n",mName.c_str());}
	/*The color for new particles.*/
	void setParticleColorB(float pcb){if(pcb == 0.5) return; fprintf_s(mFile, "setAttr \".pc.pcb\" %f;\n", pcb);}
	/*The color for new particles.*/
	void setParticleColorB(const FloatID& pcb){fprintf_s(mFile,"connectAttr \"");pcb.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcb\";\n",mName.c_str());}
	/*
	Indicates the shape of volume the emitter will use,
	if the emitter is of volume type.  Has an effect only
	if emitter type is Volume. Otherwise volume controls
	are disabled.
	*/
	void setVolumeShape(unsigned int vol){if(vol == 0) return; fprintf_s(mFile, "setAttr \".vol\" %i;\n", vol);}
	/*
	Indicates the shape of volume the emitter will use,
	if the emitter is of volume type.  Has an effect only
	if emitter type is Volume. Otherwise volume controls
	are disabled.
	*/
	void setVolumeShape(const UnsignedintID& vol){fprintf_s(mFile,"connectAttr \"");vol.write(mFile);fprintf_s(mFile,"\" \"%s.vol\";\n",mName.c_str());}
	/*
	This is the parent attribute for the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	void setVolumeOffset(const double3& vof){fprintf_s(mFile, "setAttr \".vof\" -type \"double3\" ");vof.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is the parent attribute for the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	void setVolumeOffset(const Double3ID& vof){fprintf_s(mFile,"connectAttr \"");vof.write(mFile);fprintf_s(mFile,"\" \"%s.vof\";\n",mName.c_str());}
	/*
	This is the X component of the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	void setVolumeOffsetX(double vfx){if(vfx == 0) return; fprintf_s(mFile, "setAttr \".vof.vfx\" %f;\n", vfx);}
	/*
	This is the X component of the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	void setVolumeOffsetX(const DoubleID& vfx){fprintf_s(mFile,"connectAttr \"");vfx.write(mFile);fprintf_s(mFile,"\" \"%s.vof.vfx\";\n",mName.c_str());}
	/*
	This is the Y component of the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	void setVolumeOffsetY(double vfy){if(vfy == 0) return; fprintf_s(mFile, "setAttr \".vof.vfy\" %f;\n", vfy);}
	/*
	This is the Y component of the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	void setVolumeOffsetY(const DoubleID& vfy){fprintf_s(mFile,"connectAttr \"");vfy.write(mFile);fprintf_s(mFile,"\" \"%s.vof.vfy\";\n",mName.c_str());}
	/*
	This is the Z component of the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	void setVolumeOffsetZ(double vfz){if(vfz == 0) return; fprintf_s(mFile, "setAttr \".vof.vfz\" %f;\n", vfz);}
	/*
	This is the Z component of the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	void setVolumeOffsetZ(const DoubleID& vfz){fprintf_s(mFile,"connectAttr \"");vfz.write(mFile);fprintf_s(mFile,"\" \"%s.vof.vfz\";\n",mName.c_str());}
	/*
	This attribute computes how efficient the volume will be at
	generating uniformly-distributed random point within the
	volume.
	*/
	void setVolumeEfficiency(const DoubleID& vef){fprintf_s(mFile,"connectAttr \"");vef.write(mFile);fprintf_s(mFile,"\" \"%s.vef\";\n",mName.c_str());}
	/*The arc of the volume emission.  Used for sphere, cone, cynlinder and torus.*/
	void setVolumeSweep(double vsw){if(vsw == 3) return; fprintf_s(mFile, "setAttr \".vsw\" %f;\n", vsw);}
	/*The arc of the volume emission.  Used for sphere, cone, cynlinder and torus.*/
	void setVolumeSweep(const DoubleID& vsw){fprintf_s(mFile,"connectAttr \"");vsw.write(mFile);fprintf_s(mFile,"\" \"%s.vsw\";\n",mName.c_str());}
	/*
	Applies to torus volumes only.
	The radius of a section of the torus.
	*/
	void setSectionRadius(double vsr){if(vsr == 0) return; fprintf_s(mFile, "setAttr \".vsr\" %f;\n", vsr);}
	/*
	Applies to torus volumes only.
	The radius of a section of the torus.
	*/
	void setSectionRadius(const DoubleID& vsr){fprintf_s(mFile,"connectAttr \"");vsr.write(mFile);fprintf_s(mFile,"\" \"%s.vsr\";\n",mName.c_str());}
	/*
	Initial velocity in the direction away from the center
	point of a cube or sphere volume emitter. Used only with
	the cube and sphere volume emitters.
	*/
	void setAwayFromCenter(double afc){if(afc == 1.0) return; fprintf_s(mFile, "setAttr \".afc\" %f;\n", afc);}
	/*
	Initial velocity in the direction away from the center
	point of a cube or sphere volume emitter. Used only with
	the cube and sphere volume emitters.
	*/
	void setAwayFromCenter(const DoubleID& afc){fprintf_s(mFile,"connectAttr \"");afc.write(mFile);fprintf_s(mFile,"\" \"%s.afc\";\n",mName.c_str());}
	/*
	Initial velocity multiplier in the direction away
	from the central axis of the volume.  See the diagrams
	in the documentation.  Used only with the cylinder, cone,
	and sphere volume emitters.
	*/
	void setAwayFromAxis(double afa){if(afa == 1.0) return; fprintf_s(mFile, "setAttr \".afa\" %f;\n", afa);}
	/*
	Initial velocity multiplier in the direction away
	from the central axis of the volume.  See the diagrams
	in the documentation.  Used only with the cylinder, cone,
	and sphere volume emitters.
	*/
	void setAwayFromAxis(const DoubleID& afa){fprintf_s(mFile,"connectAttr \"");afa.write(mFile);fprintf_s(mFile,"\" \"%s.afa\";\n",mName.c_str());}
	/*
	Initial velocity multiplier in the direction along
	the central axis of the volume.  See the diagrams in
	the documentation.  Applies only to volume emitters.
	*/
	void setAlongAxis(double alx){if(alx == 0.0) return; fprintf_s(mFile, "setAttr \".alx\" %f;\n", alx);}
	/*
	Initial velocity multiplier in the direction along
	the central axis of the volume.  See the diagrams in
	the documentation.  Applies only to volume emitters.
	*/
	void setAlongAxis(const DoubleID& alx){fprintf_s(mFile,"connectAttr \"");alx.write(mFile);fprintf_s(mFile,"\" \"%s.alx\";\n",mName.c_str());}
	/*
	Initial velocity multiplier in the direction around
	the central axis of the volume.  See the diagrams
	in the documentation.  Applies only to volume emitters.
	*/
	void setAroundAxis(double arx){if(arx == 0.0) return; fprintf_s(mFile, "setAttr \".arx\" %f;\n", arx);}
	/*
	Initial velocity multiplier in the direction around
	the central axis of the volume.  See the diagrams
	in the documentation.  Applies only to volume emitters.
	*/
	void setAroundAxis(const DoubleID& arx){fprintf_s(mFile,"connectAttr \"");arx.write(mFile);fprintf_s(mFile,"\" \"%s.arx\";\n",mName.c_str());}
	/*Magnitude of a random component of the speed from volume emission.*/
	void setRandomDirection(double rnd){if(rnd == 0.0) return; fprintf_s(mFile, "setAttr \".rnd\" %f;\n", rnd);}
	/*Magnitude of a random component of the speed from volume emission.*/
	void setRandomDirection(const DoubleID& rnd){fprintf_s(mFile,"connectAttr \"");rnd.write(mFile);fprintf_s(mFile,"\" \"%s.rnd\";\n",mName.c_str());}
	/*
	For volume emitters only, adds a component of speed in the
	direction specified by the directionX, Y, and Z attributes.
	Applies only to volume emitters. Does not apply to other types
	of emitters.
	*/
	void setDirectionalSpeed(double drs){if(drs == 0.0) return; fprintf_s(mFile, "setAttr \".drs\" %f;\n", drs);}
	/*
	For volume emitters only, adds a component of speed in the
	direction specified by the directionX, Y, and Z attributes.
	Applies only to volume emitters. Does not apply to other types
	of emitters.
	*/
	void setDirectionalSpeed(const DoubleID& drs){fprintf_s(mFile,"connectAttr \"");drs.write(mFile);fprintf_s(mFile,"\" \"%s.drs\";\n",mName.c_str());}
	/*
	Indicates whether the scale of a volume emitter affects
	the velocity of the emitted particles.
	*/
	void setScaleSpeedBySize(bool ssz){if(ssz == false) return; fprintf_s(mFile, "setAttr \".ssz\" %i;\n", ssz);}
	/*
	Indicates whether the scale of a volume emitter affects
	the velocity of the emitted particles.
	*/
	void setScaleSpeedBySize(const BoolID& ssz){fprintf_s(mFile,"connectAttr \"");ssz.write(mFile);fprintf_s(mFile,"\" \"%s.ssz\";\n",mName.c_str());}
	/*
	This boolean tells the emitter whether or not to draw the
	volume speed arrows.
	*/
	void setDisplaySpeed(bool dss){if(dss == true) return; fprintf_s(mFile, "setAttr \".dss\" %i;\n", dss);}
	/*
	This boolean tells the emitter whether or not to draw the
	volume speed arrows.
	*/
	void setDisplaySpeed(const BoolID& dss){fprintf_s(mFile,"connectAttr \"");dss.write(mFile);fprintf_s(mFile,"\" \"%s.dss\";\n",mName.c_str());}
	/*
	Specifies the emitter type: omni, directional, surface,
	curve, or some type of volume.
	*/
	UnsignedintID getEmitterType(){char buffer[4096];sprintf_s (buffer, "%s.emt",mName.c_str());return (const char*)buffer;}
	/*Rate of emission per second.*/
	DoubleID getRate(){char buffer[4096];sprintf_s (buffer, "%s.rat",mName.c_str());return (const char*)buffer;}
	/*
	Cycling emission restarts the random number stream after
	an interval in frames, specified by the cycleInterval attribute.
	Setting cycleEmission to "Frame" and cycleInterval to 1 is
	will cause the random stream to re-start every frame.
	cycleInterval values greater than 1 can be used
	to generate cycles for games work.  Note that this resets ONLY
	the random stream used by the emitter. It does not reset the random
	number stream used by Mel, shaders, etc.
	Note also that the "frame" option resets at most once per frame.
	Use caution when animating the particle's currentTime.
	However, oversampling does not affect the results.
	*/
	UnsignedintID getCycleEmission(){char buffer[4096];sprintf_s (buffer, "%s.cye",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the number of frames between restarts of
	the random number stream.  See cycleEmission.  Has no effect if
	cycleEmission is set to None.
	*/
	IntID getCycleInterval(){char buffer[4096];sprintf_s (buffer, "%s.cyi",mName.c_str());return (const char*)buffer;}
	/*
	Maximum distance at which new particles or density is created
	from emitter. Not used for volume emitters.
	*/
	DoubleID getMaxDistance(){char buffer[4096];sprintf_s (buffer, "%s.max",mName.c_str());return (const char*)buffer;}
	/*
	Minimum distance at which new particles are created
	from emitter.
	Not used for volume emitters.
	*/
	DoubleID getMinDistance(){char buffer[4096];sprintf_s (buffer, "%s.min",mName.c_str());return (const char*)buffer;}
	/*Direction of emitter. Not used for omni emitters.*/
	Double3ID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*X-component of direction of emission (if directional).*/
	DoubleID getDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.d.dx",mName.c_str());return (const char*)buffer;}
	/*Y-component of direction of emission (if directional).*/
	DoubleID getDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.d.dy",mName.c_str());return (const char*)buffer;}
	/*Z-component of direction of emission (if directional).*/
	DoubleID getDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.d.dz",mName.c_str());return (const char*)buffer;}
	/*Degree of spread off direction axis as fraction of 90 degrees.*/
	DoubleID getSpread(){char buffer[4096];sprintf_s (buffer, "%s.spr",mName.c_str());return (const char*)buffer;}
	/*Initial velocity multiplier.*/
	DoubleID getSpeed(){char buffer[4096];sprintf_s (buffer, "%s.spd",mName.c_str());return (const char*)buffer;}
	/*
	Identifies a range of random variation for the speed of
	each generated particle.  If set to a non-zero value, speed
	becomes the mean value of the generated particles, whose speeds
	vary by a random amount up to plus or minus speedRandom/2.
	For example, speed 5 and speedRandom 2 will make the speeds
	vary between 4 and 6.
	*/
	DoubleID getSpeedRandom(){char buffer[4096];sprintf_s (buffer, "%s.srnd",mName.c_str());return (const char*)buffer;}
	/*Surface emission only. Speed multipler tangent to emitting plane.*/
	DoubleID getTangentSpeed(){char buffer[4096];sprintf_s (buffer, "%s.tspd",mName.c_str());return (const char*)buffer;}
	/*Speed multipler normal to emitting plane or emitting curve.*/
	DoubleID getNormalSpeed(){char buffer[4096];sprintf_s (buffer, "%s.nspd",mName.c_str());return (const char*)buffer;}
	/*The current scene time. It is connected with time1.*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*
	It is connected with the particle object(target particle).
	The final velocities of new particles has a portion of emitter's
	velocity multiplying inheritFactor.
	*/
	const DoubleID& getInheritFactor(size_t inh_i){char buffer[4096];sprintf_s (buffer, "%s.inh[%i]",mName.c_str(),inh_i);return (const char*)buffer;}
	/*
	It determines if the target particle object has enough particles.
	If it is true, no more emission.
	*/
	const BoolID& getIsFull(size_t full_i){char buffer[4096];sprintf_s (buffer, "%s.full[%i]",mName.c_str(),full_i);return (const char*)buffer;}
	/*
	It is used to determine if emitting particles.
	If currentTime <= startTime, reset emitter states, such as
	remainder, fLastWorldPoint. It is connected with target particle.
	*/
	const TimeID& getStartTime(size_t stt_i){char buffer[4096];sprintf_s (buffer, "%s.stt[%i]",mName.c_str(),stt_i);return (const char*)buffer;}
	/*
	An elapsed time since particles were emitted.
	It is connected with particle object.
	*/
	const TimeID& getDeltaTime(size_t dt_i){char buffer[4096];sprintf_s (buffer, "%s.dt[%i]",mName.c_str(),dt_i);return (const char*)buffer;}
	/*
	This is a storage to save emit count remainder. It is for positional
	emitter only(curve/surface emitter handles remainder differently).
	*/
	const DoubleArrayID& getEmitCountRemainder(size_t ecr_i){char buffer[4096];sprintf_s (buffer, "%s.ecr[%i]",mName.c_str(),ecr_i);return (const char*)buffer;}
	/*
	This is for surface/curve emitter. The owner is a geoConnector.
	The geoConnector creates triangle/line list from a surface/curve.
	*/
	SweptGeometryID getSweptGeometry(){char buffer[4096];sprintf_s (buffer, "%s.swge",mName.c_str());return (const char*)buffer;}
	/*It outputs new particles to the particle object.*/
	const GenericArrayID& getOutput(size_t ot_i){char buffer[4096];sprintf_s (buffer, "%s.ot[%i]",mName.c_str(),ot_i);return (const char*)buffer;}
	/*
	Random number stream seed for emitter's own random number stream.
	Separate seed for each particle object into which we are emitting.
	*/
	const IntID& getSeed(size_t sd_i){char buffer[4096];sprintf_s (buffer, "%s.sd[%i]",mName.c_str(),sd_i);return (const char*)buffer;}
	/*
	If it is on, the surface emitter generates particles based on
	texture information of the geometric owner. Note that a texture
	can have a continous range of values while a particle either
	exists or does not exist. As a consequence of this the texture is
	used to filter the particles. The emission of particles more closely
	matches the texture as the rate of particle emission increases.
	Since low emission rates do not clearly match the texture a
	high emission rate is recommended when textured emission is being used.
	*/
	BoolID getEnableTextureRate(){char buffer[4096];sprintf_s (buffer, "%s.etr",mName.c_str());return (const char*)buffer;}
	/*It is connected with the texture node which control the rate.*/
	Float3ID getTextureRate(){char buffer[4096];sprintf_s (buffer, "%s.txr",mName.c_str());return (const char*)buffer;}
	/*See comments for aTextureRate.*/
	FloatID getTextureRateR(){char buffer[4096];sprintf_s (buffer, "%s.txr.txrr",mName.c_str());return (const char*)buffer;}
	/*See comments for aTextureRate.*/
	FloatID getTextureRateG(){char buffer[4096];sprintf_s (buffer, "%s.txr.txrg",mName.c_str());return (const char*)buffer;}
	/*See comments for aTextureRate.*/
	FloatID getTextureRateB(){char buffer[4096];sprintf_s (buffer, "%s.txr.txrb",mName.c_str());return (const char*)buffer;}
	/*If it is on, particles will be emitted from dark area.*/
	BoolID getEmitFromDark(){char buffer[4096];sprintf_s (buffer, "%s.efd",mName.c_str());return (const char*)buffer;}
	/*
	If it is true, emitter passes the color to new particles.
	The color may be from a texture or color selector.
	*/
	BoolID getInheritColor(){char buffer[4096];sprintf_s (buffer, "%s.inhc",mName.c_str());return (const char*)buffer;}
	/*
	If it is true, emitter passes the opacity to new particles if
	there is a texture node is connected to the particle color attribute.
	*/
	BoolID getInheritOpacity(){char buffer[4096];sprintf_s (buffer, "%s.inho",mName.c_str());return (const char*)buffer;}
	/*If it is true, use invert-alpha as opacity for new particles.*/
	BoolID getInvertOpacity(){char buffer[4096];sprintf_s (buffer, "%s.invo",mName.c_str());return (const char*)buffer;}
	/*If it is true, use luminance as opacity for new particles.*/
	BoolID getUseLuminance(){char buffer[4096];sprintf_s (buffer, "%s.usel",mName.c_str());return (const char*)buffer;}
	/*The color for new particles.*/
	Float3ID getParticleColor(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*The color for new particles.*/
	FloatID getParticleColorR(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcr",mName.c_str());return (const char*)buffer;}
	/*The color for new particles.*/
	FloatID getParticleColorG(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcg",mName.c_str());return (const char*)buffer;}
	/*The color for new particles.*/
	FloatID getParticleColorB(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcb",mName.c_str());return (const char*)buffer;}
	/*
	Indicates the shape of volume the emitter will use,
	if the emitter is of volume type.  Has an effect only
	if emitter type is Volume. Otherwise volume controls
	are disabled.
	*/
	UnsignedintID getVolumeShape(){char buffer[4096];sprintf_s (buffer, "%s.vol",mName.c_str());return (const char*)buffer;}
	/*
	This is the parent attribute for the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	Double3ID getVolumeOffset(){char buffer[4096];sprintf_s (buffer, "%s.vof",mName.c_str());return (const char*)buffer;}
	/*
	This is the X component of the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	DoubleID getVolumeOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.vof.vfx",mName.c_str());return (const char*)buffer;}
	/*
	This is the Y component of the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	DoubleID getVolumeOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.vof.vfy",mName.c_str());return (const char*)buffer;}
	/*
	This is the Z component of the translational offset of
	the emission volume's center from the emitter's origin.
	*/
	DoubleID getVolumeOffsetZ(){char buffer[4096];sprintf_s (buffer, "%s.vof.vfz",mName.c_str());return (const char*)buffer;}
	/*
	This attribute computes how efficient the volume will be at
	generating uniformly-distributed random point within the
	volume.
	*/
	DoubleID getVolumeEfficiency(){char buffer[4096];sprintf_s (buffer, "%s.vef",mName.c_str());return (const char*)buffer;}
	/*The arc of the volume emission.  Used for sphere, cone, cynlinder and torus.*/
	DoubleID getVolumeSweep(){char buffer[4096];sprintf_s (buffer, "%s.vsw",mName.c_str());return (const char*)buffer;}
	/*
	Applies to torus volumes only.
	The radius of a section of the torus.
	*/
	DoubleID getSectionRadius(){char buffer[4096];sprintf_s (buffer, "%s.vsr",mName.c_str());return (const char*)buffer;}
	/*
	Initial velocity in the direction away from the center
	point of a cube or sphere volume emitter. Used only with
	the cube and sphere volume emitters.
	*/
	DoubleID getAwayFromCenter(){char buffer[4096];sprintf_s (buffer, "%s.afc",mName.c_str());return (const char*)buffer;}
	/*
	Initial velocity multiplier in the direction away
	from the central axis of the volume.  See the diagrams
	in the documentation.  Used only with the cylinder, cone,
	and sphere volume emitters.
	*/
	DoubleID getAwayFromAxis(){char buffer[4096];sprintf_s (buffer, "%s.afa",mName.c_str());return (const char*)buffer;}
	/*
	Initial velocity multiplier in the direction along
	the central axis of the volume.  See the diagrams in
	the documentation.  Applies only to volume emitters.
	*/
	DoubleID getAlongAxis(){char buffer[4096];sprintf_s (buffer, "%s.alx",mName.c_str());return (const char*)buffer;}
	/*
	Initial velocity multiplier in the direction around
	the central axis of the volume.  See the diagrams
	in the documentation.  Applies only to volume emitters.
	*/
	DoubleID getAroundAxis(){char buffer[4096];sprintf_s (buffer, "%s.arx",mName.c_str());return (const char*)buffer;}
	/*Magnitude of a random component of the speed from volume emission.*/
	DoubleID getRandomDirection(){char buffer[4096];sprintf_s (buffer, "%s.rnd",mName.c_str());return (const char*)buffer;}
	/*
	For volume emitters only, adds a component of speed in the
	direction specified by the directionX, Y, and Z attributes.
	Applies only to volume emitters. Does not apply to other types
	of emitters.
	*/
	DoubleID getDirectionalSpeed(){char buffer[4096];sprintf_s (buffer, "%s.drs",mName.c_str());return (const char*)buffer;}
	/*
	Indicates whether the scale of a volume emitter affects
	the velocity of the emitted particles.
	*/
	BoolID getScaleSpeedBySize(){char buffer[4096];sprintf_s (buffer, "%s.ssz",mName.c_str());return (const char*)buffer;}
	/*
	This boolean tells the emitter whether or not to draw the
	volume speed arrows.
	*/
	BoolID getDisplaySpeed(){char buffer[4096];sprintf_s (buffer, "%s.dss",mName.c_str());return (const char*)buffer;}
protected:
	PointEmitter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DynBase(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POINTEMITTER_H__
