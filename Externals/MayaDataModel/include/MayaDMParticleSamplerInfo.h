/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLESAMPLERINFO_H__
#define __MayaDM_PARTICLESAMPLERINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Particle Sampler Info</b> is a utility node to allow accessing
 attributes defined on the TdynParticleShape.  This gives useful
 result only in software rendering.

 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class ParticleSamplerInfo : public DependNode
{
public:
public:
	ParticleSamplerInfo(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleSamplerInfo"){}
	virtual ~ParticleSamplerInfo(){}
	/*
	<b>Out UV Coord</b> is the output coordinates calculated
	by this node.  The return values for outUvCoord depend on
	the outUvType.  In the case of normalized age or absolute
	age, U and V will have the same value.  This attribute is
	equivalent to what particleAgeMapper used to supply.
	<p/>This attribute should be connected to the UV Coord
	attribute of a 2d texture placement node.
	*/
	void setOutUvCoord(const Float2ID& ouv){fprintf_s(mFile,"connectAttr \"");ouv.write(mFile);fprintf_s(mFile,"\" \"%s.ouv\";\n",mName.c_str());}
	/*Output U Coord*/
	void setOutUCoord(const FloatID& ouc){fprintf_s(mFile,"connectAttr \"");ouc.write(mFile);fprintf_s(mFile,"\" \"%s.ouv.ouc\";\n",mName.c_str());}
	/*Output V Coord*/
	void setOutVCoord(const FloatID& ovc){fprintf_s(mFile,"connectAttr \"");ovc.write(mFile);fprintf_s(mFile,"\" \"%s.ouv.ovc\";\n",mName.c_str());}
	/*
	<b>OutUv Type:</b>  If it's relative age, then the output
	of this node (both U and V Coord) will be a fraction of the particle's
	total lifespan.  That is, age/lifespan, which is a number between 0 and 1,
	where 1 is the total lifespan of the particular particle.  So
	particles with a shorter lifespans will go through the whole
	texture quicker than particles with longer lifespans.
	<p/>
	If it's absolute age, then the output of this node
	(both U and V Coord) will be the particle's current age,
	divided by the value of the Normalization Value attribute.  For example,
	if Normalization Value is set to 5 seconds, and the particle is 1 second
	old, then the output of this node will be 0.2.  So all particles
	will take the same amount of time to go through the texture,
	regardless of their lifespans.
	<p/>
	If the particle age is greater than user defined lifespan, this node
	will map it back to a number between 0 and 1, based on the
	Normalization Method attribute (see below)
	<p/>
	If it's parent uv, then the output will be (parentU, parentV) from
	particleShape.
	<p/>
	If it's collision uv, then the output will be (collisionU, collisionV)
	from particleShape.
	*/
	void setOutUvType(unsigned int ouvt){if(ouvt == 0) return; fprintf_s(mFile, "setAttr \".ouvt\" %i;\n", ouvt);}
	/*
	<b>OutUv Type:</b>  If it's relative age, then the output
	of this node (both U and V Coord) will be a fraction of the particle's
	total lifespan.  That is, age/lifespan, which is a number between 0 and 1,
	where 1 is the total lifespan of the particular particle.  So
	particles with a shorter lifespans will go through the whole
	texture quicker than particles with longer lifespans.
	<p/>
	If it's absolute age, then the output of this node
	(both U and V Coord) will be the particle's current age,
	divided by the value of the Normalization Value attribute.  For example,
	if Normalization Value is set to 5 seconds, and the particle is 1 second
	old, then the output of this node will be 0.2.  So all particles
	will take the same amount of time to go through the texture,
	regardless of their lifespans.
	<p/>
	If the particle age is greater than user defined lifespan, this node
	will map it back to a number between 0 and 1, based on the
	Normalization Method attribute (see below)
	<p/>
	If it's parent uv, then the output will be (parentU, parentV) from
	particleShape.
	<p/>
	If it's collision uv, then the output will be (collisionU, collisionV)
	from particleShape.
	*/
	void setOutUvType(const UnsignedintID& ouvt){fprintf_s(mFile,"connectAttr \"");ouvt.write(mFile);fprintf_s(mFile,"\" \"%s.ouvt\";\n",mName.c_str());}
	/*
	<b>Normalization Value</b> is the value used to normalize
	outUvCoord to [0,1] range when absolute age is selected. It acts
	like particle lifespan does for the relative age option.
	<p/>
	<b>Note:</b> The unit is in seconds, not frames or anything else.
	*/
	void setNormalizationValue(float nlv){if(nlv == 1.0) return; fprintf_s(mFile, "setAttr \".nlv\" %f;\n", nlv);}
	/*
	<b>Normalization Value</b> is the value used to normalize
	outUvCoord to [0,1] range when absolute age is selected. It acts
	like particle lifespan does for the relative age option.
	<p/>
	<b>Note:</b> The unit is in seconds, not frames or anything else.
	*/
	void setNormalizationValue(const FloatID& nlv){fprintf_s(mFile,"connectAttr \"");nlv.write(mFile);fprintf_s(mFile,"\" \"%s.nlv\";\n",mName.c_str());}
	/*
	<b>normalization Method</b> controls how this node deals with output
	values that go outside the 0 to 1 range.  It is only meaningful
	with absolute age type, and some particles get older
	than the normalization value.
	<p/>
	If Oscillate is used, then values above 1.0 are folding
	back, that is, turned around.  If Clamp is used,
	then the values above 1.0 are clampped to 1.0.
	<p/>For example, lets say you set normalization value to 10 seconds,
	and your particles live longer than that.  Here is the
	output of this node:
	<pre>
	Oscillate :
	Particle Age:  7    8    9    10   11   12   13
	Output U or V:.7   .8   .9   1.0   .9   .8   .7
	----
	Clamp:
	Particle Age:  7    8    9    10   11   12   13
	Output U or V:.7   .8   .9   1.0   1.0  1.0  1.0
	</pre>
	*/
	void setNormalizationMethod(unsigned int nlm){if(nlm == 0) return; fprintf_s(mFile, "setAttr \".nlm\" %i;\n", nlm);}
	/*
	<b>normalization Method</b> controls how this node deals with output
	values that go outside the 0 to 1 range.  It is only meaningful
	with absolute age type, and some particles get older
	than the normalization value.
	<p/>
	If Oscillate is used, then values above 1.0 are folding
	back, that is, turned around.  If Clamp is used,
	then the values above 1.0 are clampped to 1.0.
	<p/>For example, lets say you set normalization value to 10 seconds,
	and your particles live longer than that.  Here is the
	output of this node:
	<pre>
	Oscillate :
	Particle Age:  7    8    9    10   11   12   13
	Output U or V:.7   .8   .9   1.0   .9   .8   .7
	----
	Clamp:
	Particle Age:  7    8    9    10   11   12   13
	Output U or V:.7   .8   .9   1.0   1.0  1.0  1.0
	</pre>
	*/
	void setNormalizationMethod(const UnsignedintID& nlm){fprintf_s(mFile,"connectAttr \"");nlm.write(mFile);fprintf_s(mFile,"\" \"%s.nlm\";\n",mName.c_str());}
	/*
	<b>inverse out uv</b> affects outUvCoord. If it's false,
	the final uv is the computed uv. Otherwise, the final uv is
	one minus the computed uv.
	*/
	void setInverseOutUv(bool iouv){if(iouv == false) return; fprintf_s(mFile, "setAttr \".iouv\" %i;\n", iouv);}
	/*
	<b>inverse out uv</b> affects outUvCoord. If it's false,
	the final uv is the computed uv. Otherwise, the final uv is
	one minus the computed uv.
	*/
	void setInverseOutUv(const BoolID& iouv){fprintf_s(mFile,"connectAttr \"");iouv.write(mFile);fprintf_s(mFile,"\" \"%s.iouv\";\n",mName.c_str());}
	/*
	<b>outColor</b>.  This attribute returns rgbPP if it exists on the
	particleShape, or it will return (colorRed, colorGreen, colorBlue).
	The most common usage would be to connect this attribute to the Color
	attribute of a shader.  This attribute is equivalent
	to what particleColorMapper can supply.
	*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*out color red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*out color green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*out color blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*
	<b>OutTransparency</b>.  This attribute returns 1 - opacityPP if opscityPP
	exists on the particleShape, or it will return 1 - opacity.  The opacityPP and
	opacity have only one channel, the particleTransparency will always be grey scale, i.e.
	same values in red, green, and blue channels.  The most common usage is to connect
	this attribute to the Transparency attribute of a shader. This
	is equivallent to what particleTranspMapper can supply.
	*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*out transparency red value*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*out transparency green value*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*out transparency blue value*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*
	<b>outIncandescencePP</b>.  This attribute returns incandescencePP if incandescencePP
	exists on the particleShape, or it will return incandescence.
	The most common usage is to connect this attribute to the Incandescence
	attribute of a shader.  This is equivallent to what
	particleIncandMapper can supply.
	*/
	void setOutIncandescence(const Float3ID& oi){fprintf_s(mFile,"connectAttr \"");oi.write(mFile);fprintf_s(mFile,"\" \"%s.oi\";\n",mName.c_str());}
	/*incandescence red value*/
	void setOutIncandescenceR(const FloatID& oicr){fprintf_s(mFile,"connectAttr \"");oicr.write(mFile);fprintf_s(mFile,"\" \"%s.oi.oicr\";\n",mName.c_str());}
	/*incandescence green value*/
	void setOutIncandescenceG(const FloatID& oicg){fprintf_s(mFile,"connectAttr \"");oicg.write(mFile);fprintf_s(mFile,"\" \"%s.oi.oicg\";\n",mName.c_str());}
	/*incandescence blue value*/
	void setOutIncandescenceB(const FloatID& oicb){fprintf_s(mFile,"connectAttr \"");oicb.write(mFile);fprintf_s(mFile,"\" \"%s.oi.oicb\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setFinalLifespanPP(const FloatID& flp){fprintf_s(mFile,"connectAttr \"");flp.write(mFile);fprintf_s(mFile,"\" \"%s.flp\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setAgeNormalized(const FloatID& anl){fprintf_s(mFile,"connectAttr \"");anl.write(mFile);fprintf_s(mFile,"\" \"%s.anl\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setParticleId(const IntID& pid){fprintf_s(mFile,"connectAttr \"");pid.write(mFile);fprintf_s(mFile,"\" \"%s.pid\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setAge(const FloatID& ag){fprintf_s(mFile,"connectAttr \"");ag.write(mFile);fprintf_s(mFile,"\" \"%s.ag\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setLifespan(const FloatID& lsp){fprintf_s(mFile,"connectAttr \"");lsp.write(mFile);fprintf_s(mFile,"\" \"%s.lsp\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setLifespanPP(const FloatID& lpp){fprintf_s(mFile,"connectAttr \"");lpp.write(mFile);fprintf_s(mFile,"\" \"%s.lpp\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setAcceleration(const Float3ID& acc){fprintf_s(mFile,"connectAttr \"");acc.write(mFile);fprintf_s(mFile,"\" \"%s.acc\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setAccelerationX(const FloatID& accx){fprintf_s(mFile,"connectAttr \"");accx.write(mFile);fprintf_s(mFile,"\" \"%s.acc.accx\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setAccelerationY(const FloatID& accy){fprintf_s(mFile,"connectAttr \"");accy.write(mFile);fprintf_s(mFile,"\" \"%s.acc.accy\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setAccelerationZ(const FloatID& accz){fprintf_s(mFile,"connectAttr \"");accz.write(mFile);fprintf_s(mFile,"\" \"%s.acc.accz\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBirthTime(const FloatID& bt){fprintf_s(mFile,"connectAttr \"");bt.write(mFile);fprintf_s(mFile,"\" \"%s.bt\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setForce(const Float3ID& frc){fprintf_s(mFile,"connectAttr \"");frc.write(mFile);fprintf_s(mFile,"\" \"%s.frc\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setForceX(const FloatID& frx){fprintf_s(mFile,"connectAttr \"");frx.write(mFile);fprintf_s(mFile,"\" \"%s.frc.frx\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setForceY(const FloatID& fry){fprintf_s(mFile,"connectAttr \"");fry.write(mFile);fprintf_s(mFile,"\" \"%s.frc.fry\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setForceZ(const FloatID& frz){fprintf_s(mFile,"connectAttr \"");frz.write(mFile);fprintf_s(mFile,"\" \"%s.frc.frz\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setPosition(const Float3ID& pos){fprintf_s(mFile,"connectAttr \"");pos.write(mFile);fprintf_s(mFile,"\" \"%s.pos\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setPositionX(const FloatID& posx){fprintf_s(mFile,"connectAttr \"");posx.write(mFile);fprintf_s(mFile,"\" \"%s.pos.posx\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setPositionY(const FloatID& posy){fprintf_s(mFile,"connectAttr \"");posy.write(mFile);fprintf_s(mFile,"\" \"%s.pos.posy\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setPositionZ(const FloatID& posz){fprintf_s(mFile,"connectAttr \"");posz.write(mFile);fprintf_s(mFile,"\" \"%s.pos.posz\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBirthPosition(const Float3ID& bpos){fprintf_s(mFile,"connectAttr \"");bpos.write(mFile);fprintf_s(mFile,"\" \"%s.bpos\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBirthPositionX(const FloatID& bpox){fprintf_s(mFile,"connectAttr \"");bpox.write(mFile);fprintf_s(mFile,"\" \"%s.bpos.bpox\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBirthPositionY(const FloatID& bpoy){fprintf_s(mFile,"connectAttr \"");bpoy.write(mFile);fprintf_s(mFile,"\" \"%s.bpos.bpoy\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBirthPositionZ(const FloatID& bpoz){fprintf_s(mFile,"connectAttr \"");bpoz.write(mFile);fprintf_s(mFile,"\" \"%s.bpos.bpoz\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBirthWorldPosition(const Float3ID& bwpo){fprintf_s(mFile,"connectAttr \"");bwpo.write(mFile);fprintf_s(mFile,"\" \"%s.bwpo\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBirthWorldPositionX(const FloatID& bwpx){fprintf_s(mFile,"connectAttr \"");bwpx.write(mFile);fprintf_s(mFile,"\" \"%s.bwpo.bwpx\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBirthWorldPositionY(const FloatID& bwpy){fprintf_s(mFile,"connectAttr \"");bwpy.write(mFile);fprintf_s(mFile,"\" \"%s.bwpo.bwpy\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBirthWorldPositionZ(const FloatID& bwpz){fprintf_s(mFile,"connectAttr \"");bwpz.write(mFile);fprintf_s(mFile,"\" \"%s.bwpo.bwpz\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setVelocity(const Float3ID& vel){fprintf_s(mFile,"connectAttr \"");vel.write(mFile);fprintf_s(mFile,"\" \"%s.vel\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setVelocityX(const FloatID& velx){fprintf_s(mFile,"connectAttr \"");velx.write(mFile);fprintf_s(mFile,"\" \"%s.vel.velx\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setVelocityY(const FloatID& vely){fprintf_s(mFile,"connectAttr \"");vely.write(mFile);fprintf_s(mFile,"\" \"%s.vel.vely\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setVelocityZ(const FloatID& velz){fprintf_s(mFile,"connectAttr \"");velz.write(mFile);fprintf_s(mFile,"\" \"%s.vel.velz\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setWorldPosition(const Float3ID& wps){fprintf_s(mFile,"connectAttr \"");wps.write(mFile);fprintf_s(mFile,"\" \"%s.wps\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setWorldPositionX(const FloatID& wpsx){fprintf_s(mFile,"connectAttr \"");wpsx.write(mFile);fprintf_s(mFile,"\" \"%s.wps.wpsx\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setWorldPositionY(const FloatID& wpsy){fprintf_s(mFile,"connectAttr \"");wpsy.write(mFile);fprintf_s(mFile,"\" \"%s.wps.wpsy\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setWorldPositionZ(const FloatID& wpsz){fprintf_s(mFile,"connectAttr \"");wpsz.write(mFile);fprintf_s(mFile,"\" \"%s.wps.wpsz\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setWorldVelocity(const Float3ID& wvl){fprintf_s(mFile,"connectAttr \"");wvl.write(mFile);fprintf_s(mFile,"\" \"%s.wvl\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setWorldVelocityX(const FloatID& wvlx){fprintf_s(mFile,"connectAttr \"");wvlx.write(mFile);fprintf_s(mFile,"\" \"%s.wvl.wvlx\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setWorldVelocityY(const FloatID& wvly){fprintf_s(mFile,"connectAttr \"");wvly.write(mFile);fprintf_s(mFile,"\" \"%s.wvl.wvly\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setWorldVelocityZ(const FloatID& wvlz){fprintf_s(mFile,"connectAttr \"");wvlz.write(mFile);fprintf_s(mFile,"\" \"%s.wvl.wvlz\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setParentU(const FloatID& pau){fprintf_s(mFile,"connectAttr \"");pau.write(mFile);fprintf_s(mFile,"\" \"%s.pau\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setParentV(const FloatID& pav){fprintf_s(mFile,"connectAttr \"");pav.write(mFile);fprintf_s(mFile,"\" \"%s.pav\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setCollisionU(const FloatID& clu){fprintf_s(mFile,"connectAttr \"");clu.write(mFile);fprintf_s(mFile,"\" \"%s.clu\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setCollisionV(const FloatID& clv){fprintf_s(mFile,"connectAttr \"");clv.write(mFile);fprintf_s(mFile,"\" \"%s.clv\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setColorRed(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setColorGreen(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.cg\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setColorBlue(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cb\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setRgbPP(const Float3ID& rgb){fprintf_s(mFile,"connectAttr \"");rgb.write(mFile);fprintf_s(mFile,"\" \"%s.rgb\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setRPP(const FloatID& rpp){fprintf_s(mFile,"connectAttr \"");rpp.write(mFile);fprintf_s(mFile,"\" \"%s.rgb.rpp\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setGPP(const FloatID& gpp){fprintf_s(mFile,"connectAttr \"");gpp.write(mFile);fprintf_s(mFile,"\" \"%s.rgb.gpp\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setBPP(const FloatID& bpp){fprintf_s(mFile,"connectAttr \"");bpp.write(mFile);fprintf_s(mFile,"\" \"%s.rgb.bpp\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setIncandescencePP(const Float3ID& oipp){fprintf_s(mFile,"connectAttr \"");oipp.write(mFile);fprintf_s(mFile,"\" \"%s.oipp\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setIncandescencePPR(const FloatID& ippr){fprintf_s(mFile,"connectAttr \"");ippr.write(mFile);fprintf_s(mFile,"\" \"%s.oipp.ippr\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setIncandescencePPG(const FloatID& ippg){fprintf_s(mFile,"connectAttr \"");ippg.write(mFile);fprintf_s(mFile,"\" \"%s.oipp.ippg\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setIncandescencePPB(const FloatID& ippb){fprintf_s(mFile,"connectAttr \"");ippb.write(mFile);fprintf_s(mFile,"\" \"%s.oipp.ippb\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setIncandescence(const Float3ID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setIncandescenceR(const FloatID& inr){fprintf_s(mFile,"connectAttr \"");inr.write(mFile);fprintf_s(mFile,"\" \"%s.in.inr\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setIncandescenceG(const FloatID& ing){fprintf_s(mFile,"connectAttr \"");ing.write(mFile);fprintf_s(mFile,"\" \"%s.in.ing\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setIncandescenceB(const FloatID& inb){fprintf_s(mFile,"connectAttr \"");inb.write(mFile);fprintf_s(mFile,"\" \"%s.in.inb\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setOpacity(const FloatID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setOpacityPP(const FloatID& opp){fprintf_s(mFile,"connectAttr \"");opp.write(mFile);fprintf_s(mFile,"\" \"%s.opp\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setRadius(const FloatID& rds){fprintf_s(mFile,"connectAttr \"");rds.write(mFile);fprintf_s(mFile,"\" \"%s.rds\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setRadiusPP(const FloatID& rdp){fprintf_s(mFile,"connectAttr \"");rdp.write(mFile);fprintf_s(mFile,"\" \"%s.rdp\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserScalar1PP(const FloatID& uds1){fprintf_s(mFile,"connectAttr \"");uds1.write(mFile);fprintf_s(mFile,"\" \"%s.uds1\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserScalar2PP(const FloatID& uds2){fprintf_s(mFile,"connectAttr \"");uds2.write(mFile);fprintf_s(mFile,"\" \"%s.uds2\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserScalar3PP(const FloatID& uds3){fprintf_s(mFile,"connectAttr \"");uds3.write(mFile);fprintf_s(mFile,"\" \"%s.uds3\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserScalar4PP(const FloatID& uds4){fprintf_s(mFile,"connectAttr \"");uds4.write(mFile);fprintf_s(mFile,"\" \"%s.uds4\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserScalar5PP(const FloatID& uds5){fprintf_s(mFile,"connectAttr \"");uds5.write(mFile);fprintf_s(mFile,"\" \"%s.uds5\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector1PP(const Float3ID& udv1){fprintf_s(mFile,"connectAttr \"");udv1.write(mFile);fprintf_s(mFile,"\" \"%s.udv1\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector1PPX(const FloatID& uv1x){fprintf_s(mFile,"connectAttr \"");uv1x.write(mFile);fprintf_s(mFile,"\" \"%s.udv1.uv1x\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector1PPY(const FloatID& uv1y){fprintf_s(mFile,"connectAttr \"");uv1y.write(mFile);fprintf_s(mFile,"\" \"%s.udv1.uv1y\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector1PPZ(const FloatID& uv1z){fprintf_s(mFile,"connectAttr \"");uv1z.write(mFile);fprintf_s(mFile,"\" \"%s.udv1.uv1z\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector2PP(const Float3ID& udv2){fprintf_s(mFile,"connectAttr \"");udv2.write(mFile);fprintf_s(mFile,"\" \"%s.udv2\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector2PPX(const FloatID& uv2x){fprintf_s(mFile,"connectAttr \"");uv2x.write(mFile);fprintf_s(mFile,"\" \"%s.udv2.uv2x\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector2PPY(const FloatID& uv2y){fprintf_s(mFile,"connectAttr \"");uv2y.write(mFile);fprintf_s(mFile,"\" \"%s.udv2.uv2y\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector2PPZ(const FloatID& uv2z){fprintf_s(mFile,"connectAttr \"");uv2z.write(mFile);fprintf_s(mFile,"\" \"%s.udv2.uv2z\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector3PP(const Float3ID& udv3){fprintf_s(mFile,"connectAttr \"");udv3.write(mFile);fprintf_s(mFile,"\" \"%s.udv3\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector3PPX(const FloatID& uv3x){fprintf_s(mFile,"connectAttr \"");uv3x.write(mFile);fprintf_s(mFile,"\" \"%s.udv3.uv3x\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector3PPY(const FloatID& uv3y){fprintf_s(mFile,"connectAttr \"");uv3y.write(mFile);fprintf_s(mFile,"\" \"%s.udv3.uv3y\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector3PPZ(const FloatID& uv3z){fprintf_s(mFile,"connectAttr \"");uv3z.write(mFile);fprintf_s(mFile,"\" \"%s.udv3.uv3z\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector4PP(const Float3ID& udv4){fprintf_s(mFile,"connectAttr \"");udv4.write(mFile);fprintf_s(mFile,"\" \"%s.udv4\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector4PPX(const FloatID& uv4x){fprintf_s(mFile,"connectAttr \"");uv4x.write(mFile);fprintf_s(mFile,"\" \"%s.udv4.uv4x\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector4PPY(const FloatID& uv4y){fprintf_s(mFile,"connectAttr \"");uv4y.write(mFile);fprintf_s(mFile,"\" \"%s.udv4.uv4y\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector4PPZ(const FloatID& uv4z){fprintf_s(mFile,"connectAttr \"");uv4z.write(mFile);fprintf_s(mFile,"\" \"%s.udv4.uv4z\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector5PP(const Float3ID& udv5){fprintf_s(mFile,"connectAttr \"");udv5.write(mFile);fprintf_s(mFile,"\" \"%s.udv5\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector5PPX(const FloatID& uv5x){fprintf_s(mFile,"connectAttr \"");uv5x.write(mFile);fprintf_s(mFile,"\" \"%s.udv5.uv5x\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector5PPY(const FloatID& uv5y){fprintf_s(mFile,"connectAttr \"");uv5y.write(mFile);fprintf_s(mFile,"\" \"%s.udv5.uv5y\";\n",mName.c_str());}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	void setUserVector5PPZ(const FloatID& uv5z){fprintf_s(mFile,"connectAttr \"");uv5z.write(mFile);fprintf_s(mFile,"\" \"%s.udv5.uv5z\";\n",mName.c_str());}
	/*
	<b>Out UV Coord</b> is the output coordinates calculated
	by this node.  The return values for outUvCoord depend on
	the outUvType.  In the case of normalized age or absolute
	age, U and V will have the same value.  This attribute is
	equivalent to what particleAgeMapper used to supply.
	<p/>This attribute should be connected to the UV Coord
	attribute of a 2d texture placement node.
	*/
	Float2ID getOutUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.ouv",mName.c_str());return (const char*)buffer;}
	/*Output U Coord*/
	FloatID getOutUCoord(){char buffer[4096];sprintf_s (buffer, "%s.ouv.ouc",mName.c_str());return (const char*)buffer;}
	/*Output V Coord*/
	FloatID getOutVCoord(){char buffer[4096];sprintf_s (buffer, "%s.ouv.ovc",mName.c_str());return (const char*)buffer;}
	/*
	<b>OutUv Type:</b>  If it's relative age, then the output
	of this node (both U and V Coord) will be a fraction of the particle's
	total lifespan.  That is, age/lifespan, which is a number between 0 and 1,
	where 1 is the total lifespan of the particular particle.  So
	particles with a shorter lifespans will go through the whole
	texture quicker than particles with longer lifespans.
	<p/>
	If it's absolute age, then the output of this node
	(both U and V Coord) will be the particle's current age,
	divided by the value of the Normalization Value attribute.  For example,
	if Normalization Value is set to 5 seconds, and the particle is 1 second
	old, then the output of this node will be 0.2.  So all particles
	will take the same amount of time to go through the texture,
	regardless of their lifespans.
	<p/>
	If the particle age is greater than user defined lifespan, this node
	will map it back to a number between 0 and 1, based on the
	Normalization Method attribute (see below)
	<p/>
	If it's parent uv, then the output will be (parentU, parentV) from
	particleShape.
	<p/>
	If it's collision uv, then the output will be (collisionU, collisionV)
	from particleShape.
	*/
	UnsignedintID getOutUvType(){char buffer[4096];sprintf_s (buffer, "%s.ouvt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Normalization Value</b> is the value used to normalize
	outUvCoord to [0,1] range when absolute age is selected. It acts
	like particle lifespan does for the relative age option.
	<p/>
	<b>Note:</b> The unit is in seconds, not frames or anything else.
	*/
	FloatID getNormalizationValue(){char buffer[4096];sprintf_s (buffer, "%s.nlv",mName.c_str());return (const char*)buffer;}
	/*
	<b>normalization Method</b> controls how this node deals with output
	values that go outside the 0 to 1 range.  It is only meaningful
	with absolute age type, and some particles get older
	than the normalization value.
	<p/>
	If Oscillate is used, then values above 1.0 are folding
	back, that is, turned around.  If Clamp is used,
	then the values above 1.0 are clampped to 1.0.
	<p/>For example, lets say you set normalization value to 10 seconds,
	and your particles live longer than that.  Here is the
	output of this node:
	<pre>
	Oscillate :
	Particle Age:  7    8    9    10   11   12   13
	Output U or V:.7   .8   .9   1.0   .9   .8   .7
	----
	Clamp:
	Particle Age:  7    8    9    10   11   12   13
	Output U or V:.7   .8   .9   1.0   1.0  1.0  1.0
	</pre>
	*/
	UnsignedintID getNormalizationMethod(){char buffer[4096];sprintf_s (buffer, "%s.nlm",mName.c_str());return (const char*)buffer;}
	/*
	<b>inverse out uv</b> affects outUvCoord. If it's false,
	the final uv is the computed uv. Otherwise, the final uv is
	one minus the computed uv.
	*/
	BoolID getInverseOutUv(){char buffer[4096];sprintf_s (buffer, "%s.iouv",mName.c_str());return (const char*)buffer;}
	/*
	<b>outColor</b>.  This attribute returns rgbPP if it exists on the
	particleShape, or it will return (colorRed, colorGreen, colorBlue).
	The most common usage would be to connect this attribute to the Color
	attribute of a shader.  This attribute is equivalent
	to what particleColorMapper can supply.
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*out color red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*out color green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*out color blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*
	<b>OutTransparency</b>.  This attribute returns 1 - opacityPP if opscityPP
	exists on the particleShape, or it will return 1 - opacity.  The opacityPP and
	opacity have only one channel, the particleTransparency will always be grey scale, i.e.
	same values in red, green, and blue channels.  The most common usage is to connect
	this attribute to the Transparency attribute of a shader. This
	is equivallent to what particleTranspMapper can supply.
	*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*out transparency red value*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*out transparency green value*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*out transparency blue value*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*
	<b>outIncandescencePP</b>.  This attribute returns incandescencePP if incandescencePP
	exists on the particleShape, or it will return incandescence.
	The most common usage is to connect this attribute to the Incandescence
	attribute of a shader.  This is equivallent to what
	particleIncandMapper can supply.
	*/
	Float3ID getOutIncandescence(){char buffer[4096];sprintf_s (buffer, "%s.oi",mName.c_str());return (const char*)buffer;}
	/*incandescence red value*/
	FloatID getOutIncandescenceR(){char buffer[4096];sprintf_s (buffer, "%s.oi.oicr",mName.c_str());return (const char*)buffer;}
	/*incandescence green value*/
	FloatID getOutIncandescenceG(){char buffer[4096];sprintf_s (buffer, "%s.oi.oicg",mName.c_str());return (const char*)buffer;}
	/*incandescence blue value*/
	FloatID getOutIncandescenceB(){char buffer[4096];sprintf_s (buffer, "%s.oi.oicb",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getFinalLifespanPP(){char buffer[4096];sprintf_s (buffer, "%s.flp",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getAgeNormalized(){char buffer[4096];sprintf_s (buffer, "%s.anl",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	IntID getParticleId(){char buffer[4096];sprintf_s (buffer, "%s.pid",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getAge(){char buffer[4096];sprintf_s (buffer, "%s.ag",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getLifespan(){char buffer[4096];sprintf_s (buffer, "%s.lsp",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getLifespanPP(){char buffer[4096];sprintf_s (buffer, "%s.lpp",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getAcceleration(){char buffer[4096];sprintf_s (buffer, "%s.acc",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getAccelerationX(){char buffer[4096];sprintf_s (buffer, "%s.acc.accx",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getAccelerationY(){char buffer[4096];sprintf_s (buffer, "%s.acc.accy",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getAccelerationZ(){char buffer[4096];sprintf_s (buffer, "%s.acc.accz",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getBirthTime(){char buffer[4096];sprintf_s (buffer, "%s.bt",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getForce(){char buffer[4096];sprintf_s (buffer, "%s.frc",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getForceX(){char buffer[4096];sprintf_s (buffer, "%s.frc.frx",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getForceY(){char buffer[4096];sprintf_s (buffer, "%s.frc.fry",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getForceZ(){char buffer[4096];sprintf_s (buffer, "%s.frc.frz",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.pos",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.pos.posx",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.pos.posy",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.pos.posz",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getBirthPosition(){char buffer[4096];sprintf_s (buffer, "%s.bpos",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getBirthPositionX(){char buffer[4096];sprintf_s (buffer, "%s.bpos.bpox",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getBirthPositionY(){char buffer[4096];sprintf_s (buffer, "%s.bpos.bpoy",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getBirthPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.bpos.bpoz",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getBirthWorldPosition(){char buffer[4096];sprintf_s (buffer, "%s.bwpo",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getBirthWorldPositionX(){char buffer[4096];sprintf_s (buffer, "%s.bwpo.bwpx",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getBirthWorldPositionY(){char buffer[4096];sprintf_s (buffer, "%s.bwpo.bwpy",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getBirthWorldPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.bwpo.bwpz",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getVelocity(){char buffer[4096];sprintf_s (buffer, "%s.vel",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getVelocityX(){char buffer[4096];sprintf_s (buffer, "%s.vel.velx",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getVelocityY(){char buffer[4096];sprintf_s (buffer, "%s.vel.vely",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getVelocityZ(){char buffer[4096];sprintf_s (buffer, "%s.vel.velz",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getWorldPosition(){char buffer[4096];sprintf_s (buffer, "%s.wps",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getWorldPositionX(){char buffer[4096];sprintf_s (buffer, "%s.wps.wpsx",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getWorldPositionY(){char buffer[4096];sprintf_s (buffer, "%s.wps.wpsy",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getWorldPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.wps.wpsz",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getWorldVelocity(){char buffer[4096];sprintf_s (buffer, "%s.wvl",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getWorldVelocityX(){char buffer[4096];sprintf_s (buffer, "%s.wvl.wvlx",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getWorldVelocityY(){char buffer[4096];sprintf_s (buffer, "%s.wvl.wvly",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getWorldVelocityZ(){char buffer[4096];sprintf_s (buffer, "%s.wvl.wvlz",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getParentU(){char buffer[4096];sprintf_s (buffer, "%s.pau",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getParentV(){char buffer[4096];sprintf_s (buffer, "%s.pav",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getCollisionU(){char buffer[4096];sprintf_s (buffer, "%s.clu",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getCollisionV(){char buffer[4096];sprintf_s (buffer, "%s.clv",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getColorRed(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getColorGreen(){char buffer[4096];sprintf_s (buffer, "%s.cg",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getColorBlue(){char buffer[4096];sprintf_s (buffer, "%s.cb",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getRgbPP(){char buffer[4096];sprintf_s (buffer, "%s.rgb",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getRPP(){char buffer[4096];sprintf_s (buffer, "%s.rgb.rpp",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getGPP(){char buffer[4096];sprintf_s (buffer, "%s.rgb.gpp",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getBPP(){char buffer[4096];sprintf_s (buffer, "%s.rgb.bpp",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getIncandescencePP(){char buffer[4096];sprintf_s (buffer, "%s.oipp",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getIncandescencePPR(){char buffer[4096];sprintf_s (buffer, "%s.oipp.ippr",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getIncandescencePPG(){char buffer[4096];sprintf_s (buffer, "%s.oipp.ippg",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getIncandescencePPB(){char buffer[4096];sprintf_s (buffer, "%s.oipp.ippb",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getIncandescence(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getIncandescenceR(){char buffer[4096];sprintf_s (buffer, "%s.in.inr",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getIncandescenceG(){char buffer[4096];sprintf_s (buffer, "%s.in.ing",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getIncandescenceB(){char buffer[4096];sprintf_s (buffer, "%s.in.inb",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getOpacity(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getOpacityPP(){char buffer[4096];sprintf_s (buffer, "%s.opp",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.rds",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getRadiusPP(){char buffer[4096];sprintf_s (buffer, "%s.rdp",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserScalar1PP(){char buffer[4096];sprintf_s (buffer, "%s.uds1",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserScalar2PP(){char buffer[4096];sprintf_s (buffer, "%s.uds2",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserScalar3PP(){char buffer[4096];sprintf_s (buffer, "%s.uds3",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserScalar4PP(){char buffer[4096];sprintf_s (buffer, "%s.uds4",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserScalar5PP(){char buffer[4096];sprintf_s (buffer, "%s.uds5",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getUserVector1PP(){char buffer[4096];sprintf_s (buffer, "%s.udv1",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector1PPX(){char buffer[4096];sprintf_s (buffer, "%s.udv1.uv1x",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector1PPY(){char buffer[4096];sprintf_s (buffer, "%s.udv1.uv1y",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector1PPZ(){char buffer[4096];sprintf_s (buffer, "%s.udv1.uv1z",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getUserVector2PP(){char buffer[4096];sprintf_s (buffer, "%s.udv2",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector2PPX(){char buffer[4096];sprintf_s (buffer, "%s.udv2.uv2x",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector2PPY(){char buffer[4096];sprintf_s (buffer, "%s.udv2.uv2y",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector2PPZ(){char buffer[4096];sprintf_s (buffer, "%s.udv2.uv2z",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getUserVector3PP(){char buffer[4096];sprintf_s (buffer, "%s.udv3",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector3PPX(){char buffer[4096];sprintf_s (buffer, "%s.udv3.uv3x",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector3PPY(){char buffer[4096];sprintf_s (buffer, "%s.udv3.uv3y",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector3PPZ(){char buffer[4096];sprintf_s (buffer, "%s.udv3.uv3z",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getUserVector4PP(){char buffer[4096];sprintf_s (buffer, "%s.udv4",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector4PPX(){char buffer[4096];sprintf_s (buffer, "%s.udv4.uv4x",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector4PPY(){char buffer[4096];sprintf_s (buffer, "%s.udv4.uv4y",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector4PPZ(){char buffer[4096];sprintf_s (buffer, "%s.udv4.uv4z",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	Float3ID getUserVector5PP(){char buffer[4096];sprintf_s (buffer, "%s.udv5",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector5PPX(){char buffer[4096];sprintf_s (buffer, "%s.udv5.uv5x",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector5PPY(){char buffer[4096];sprintf_s (buffer, "%s.udv5.uv5y",mName.c_str());return (const char*)buffer;}
	/*Provides this attribute from the particle shape, see particle shape for definition.*/
	FloatID getUserVector5PPZ(){char buffer[4096];sprintf_s (buffer, "%s.udv5.uv5z",mName.c_str());return (const char*)buffer;}
protected:
	ParticleSamplerInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLESAMPLERINFO_H__
