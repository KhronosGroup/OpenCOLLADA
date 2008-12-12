/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLECLOUD_H__
#define __MayaDM_PARTICLECLOUD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Particle Cloud</b> shaders are used by particles which have their
  render type set to "Cloud".  These can only be rendered using Software
  Rendering.  When you open a new file, a default Particle Cloud shader
  is created.  You can create new Particle Cloud shaders, and assign
  them to different particle objects.
  <p/>
  If you are connecting this node manually to a shading group, then
  you should connect the outColor attribute of the Particle Cloud to
  the Volume Shader (also called Volume Material) input of the the
  shading group.  (Most other shaders connect to the Surface Shader
  input.)
  <p/>
  In the table below, important attributes have their names shown
  in <b>bold</b>.
*/
class ParticleCloud : public DependNode
{
public:
public:
	ParticleCloud(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleCloud"){}
	virtual ~ParticleCloud(){}
	/*output; the light intensity received at each particle. Done before rendering started.*/
	void setOutParticleEmission(const Float3ID& oe){fprintf_s(mFile,"connectAttr \"");oe.write(mFile);fprintf_s(mFile,"\" \"%s.oe\";\n",mName.c_str());}
	/*output; red component of the emission*/
	void setOutParticleEmissionR(const FloatID& oer){fprintf_s(mFile,"connectAttr \"");oer.write(mFile);fprintf_s(mFile,"\" \"%s.oe.oer\";\n",mName.c_str());}
	/*output green component of the emission*/
	void setOutParticleEmissionG(const FloatID& oeg){fprintf_s(mFile,"connectAttr \"");oeg.write(mFile);fprintf_s(mFile,"\" \"%s.oe.oeg\";\n",mName.c_str());}
	/*output blue component of the emission*/
	void setOutParticleEmissionB(const FloatID& oeb){fprintf_s(mFile,"connectAttr \"");oeb.write(mFile);fprintf_s(mFile,"\" \"%s.oe.oeb\";\n",mName.c_str());}
	/*the final output color*/
	void setOutColor(const Float3ID& oi){fprintf_s(mFile,"connectAttr \"");oi.write(mFile);fprintf_s(mFile,"\" \"%s.oi\";\n",mName.c_str());}
	/*output red component of the source intensity*/
	void setOutColorR(const FloatID& oir){fprintf_s(mFile,"connectAttr \"");oir.write(mFile);fprintf_s(mFile,"\" \"%s.oi.oir\";\n",mName.c_str());}
	/*output green component of the source intensity*/
	void setOutColorG(const FloatID& oig){fprintf_s(mFile,"connectAttr \"");oig.write(mFile);fprintf_s(mFile,"\" \"%s.oi.oig\";\n",mName.c_str());}
	/*output blue component of the source intensity*/
	void setOutColorB(const FloatID& oib){fprintf_s(mFile,"connectAttr \"");oib.write(mFile);fprintf_s(mFile,"\" \"%s.oi.oib\";\n",mName.c_str());}
	/*the final output glow color*/
	void setOutGlowColor(const Float3ID& ogi){fprintf_s(mFile,"connectAttr \"");ogi.write(mFile);fprintf_s(mFile,"\" \"%s.ogi\";\n",mName.c_str());}
	/*output glow red component*/
	void setOutGlowColorR(const FloatID& ogr){fprintf_s(mFile,"connectAttr \"");ogr.write(mFile);fprintf_s(mFile,"\" \"%s.ogi.ogr\";\n",mName.c_str());}
	/*output glow green component*/
	void setOutGlowColorG(const FloatID& ogg){fprintf_s(mFile,"connectAttr \"");ogg.write(mFile);fprintf_s(mFile,"\" \"%s.ogi.ogg\";\n",mName.c_str());}
	/*output glow blue component*/
	void setOutGlowColorB(const FloatID& ogb){fprintf_s(mFile,"connectAttr \"");ogb.write(mFile);fprintf_s(mFile,"\" \"%s.ogi.ogb\";\n",mName.c_str());}
	/*output transparency*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*outTransparency red value*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*outTransparency green value*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*outTransparency blue value*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*
	<b>Color</b> is the basic color of the particle cloud. The
	default color is a green-blue.
	*/
	void setColor(const float3& c){fprintf_s(mFile, "setAttr \".c\" -type \"float3\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color</b> is the basic color of the particle cloud. The
	default color is a green-blue.
	*/
	void setColor(const Float3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*color red value*/
	void setColorR(float cr){if(cr == 0.0) return; fprintf_s(mFile, "setAttr \".c.cr\" %f;\n", cr);}
	/*color red value*/
	void setColorR(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.c.cr\";\n",mName.c_str());}
	/*color green value*/
	void setColorG(float cg){if(cg == 0.58824) return; fprintf_s(mFile, "setAttr \".c.cg\" %f;\n", cg);}
	/*color green value*/
	void setColorG(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.c.cg\";\n",mName.c_str());}
	/*color blue value*/
	void setColorB(float cb){if(cb == 0.644) return; fprintf_s(mFile, "setAttr \".c.cb\" %f;\n", cb);}
	/*color blue value*/
	void setColorB(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.c.cb\";\n",mName.c_str());}
	/*
	<b>Transparency</b> controls how much you can see through
	the particle cloud.  It is a color, so that you can control the
	the transparency of the red, green, and blue channels separately.
	To make the cloud more opaque, set transparency to be darker.
	To make the cloud more transparent, set transparency to be
	brighter.
	*/
	void setTransparency(const float3& t){fprintf_s(mFile, "setAttr \".t\" -type \"float3\" ");t.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Transparency</b> controls how much you can see through
	the particle cloud.  It is a color, so that you can control the
	the transparency of the red, green, and blue channels separately.
	To make the cloud more opaque, set transparency to be darker.
	To make the cloud more transparent, set transparency to be
	brighter.
	*/
	void setTransparency(const Float3ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*transparency red value*/
	void setTransparencyR(float tr){if(tr == 0.5) return; fprintf_s(mFile, "setAttr \".t.tr\" %f;\n", tr);}
	/*transparency red value*/
	void setTransparencyR(const FloatID& tr){fprintf_s(mFile,"connectAttr \"");tr.write(mFile);fprintf_s(mFile,"\" \"%s.t.tr\";\n",mName.c_str());}
	/*transparency green value*/
	void setTransparencyG(float tg){if(tg == 0.5) return; fprintf_s(mFile, "setAttr \".t.tg\" %f;\n", tg);}
	/*transparency green value*/
	void setTransparencyG(const FloatID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.t.tg\";\n",mName.c_str());}
	/*transparency blue value*/
	void setTransparencyB(float tb){if(tb == 0.5) return; fprintf_s(mFile, "setAttr \".t.tb\" %f;\n", tb);}
	/*transparency blue value*/
	void setTransparencyB(const FloatID& tb){fprintf_s(mFile,"connectAttr \"");tb.write(mFile);fprintf_s(mFile,"\" \"%s.t.tb\";\n",mName.c_str());}
	/*
	Use <b>Incandescence</b> to make the particle cloud brighter,
	as though it were a light source.  By default, Incandescence is black,
	meaning no glow will be added. <p/>
	Note that when Incandescence is turned on, although the particle
	cloud will glow,
	it will not cast light on other objects in the scene.
	*/
	void setIncandescence(const float3& i){fprintf_s(mFile, "setAttr \".i\" -type \"float3\" ");i.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Use <b>Incandescence</b> to make the particle cloud brighter,
	as though it were a light source.  By default, Incandescence is black,
	meaning no glow will be added. <p/>
	Note that when Incandescence is turned on, although the particle
	cloud will glow,
	it will not cast light on other objects in the scene.
	*/
	void setIncandescence(const Float3ID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*incandescence red value*/
	void setIncandescenceR(float ir){if(ir == 0.0) return; fprintf_s(mFile, "setAttr \".i.ir\" %f;\n", ir);}
	/*incandescence red value*/
	void setIncandescenceR(const FloatID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.i.ir\";\n",mName.c_str());}
	/*incandescence green value*/
	void setIncandescenceG(float ig){if(ig == 0.0) return; fprintf_s(mFile, "setAttr \".i.ig\" %f;\n", ig);}
	/*incandescence green value*/
	void setIncandescenceG(const FloatID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.i.ig\";\n",mName.c_str());}
	/*incandescence blue value*/
	void setIncandescenceB(float ib){if(ib == 0.0) return; fprintf_s(mFile, "setAttr \".i.ib\" %f;\n", ib);}
	/*incandescence blue value*/
	void setIncandescenceB(const FloatID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.i.ib\";\n",mName.c_str());}
	/*
	<b>Density</b> is very similar to transparency; it controls
	how dense the cloud of particles appears to be, and therefore
	how much of the background can be seen through it.  Increase
	this value to make the cloud more dense.
	*/
	void setDensity(float d){if(d == 1.0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	<b>Density</b> is very similar to transparency; it controls
	how dense the cloud of particles appears to be, and therefore
	how much of the background can be seen through it.  Increase
	this value to make the cloud more dense.
	*/
	void setDensity(const FloatID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	<b>Glow Intensity</b> controls how much of a halo-like glow
	effect will be added to the particle cloud.
	This glow effect is added as a post-process,
	after the rendering is completed.  Glow Intensity is zero
	by default, meaning that no glow is added.
	*/
	void setGlowIntensity(float gi){if(gi == 0.0) return; fprintf_s(mFile, "setAttr \".gi\" %f;\n", gi);}
	/*
	<b>Glow Intensity</b> controls how much of a halo-like glow
	effect will be added to the particle cloud.
	This glow effect is added as a post-process,
	after the rendering is completed.  Glow Intensity is zero
	by default, meaning that no glow is added.
	*/
	void setGlowIntensity(const FloatID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.gi\";\n",mName.c_str());}
	/*
	<b>Noise</b> controls the jitteryness within the
	particle cloud.  If it is set to zero, the cloud will look
	very smooth and uniform throughout.  As the amount of noise
	increases, the cloud will appear 'noisier', like static
	on a television screen.
	*/
	void setNoise(float n){if(n == 0.75) return; fprintf_s(mFile, "setAttr \".n\" %f;\n", n);}
	/*
	<b>Noise</b> controls the jitteryness within the
	particle cloud.  If it is set to zero, the cloud will look
	very smooth and uniform throughout.  As the amount of noise
	increases, the cloud will appear 'noisier', like static
	on a television screen.
	*/
	void setNoise(const FloatID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*
	<b>Noise Frequency</b> determines the size of the noise
	artifacts when Noise is turned on.  Higher values of Noise Frequency
	produce smaller, finer artifacts, and lower values produce
	larger, coarser artifacts.  If Noise Frequency is set to
	zero, that is the same as turning Noise off.
	*/
	void setNoiseFreq(float nf){if(nf == 0.15) return; fprintf_s(mFile, "setAttr \".nf\" %f;\n", nf);}
	/*
	<b>Noise Frequency</b> determines the size of the noise
	artifacts when Noise is turned on.  Higher values of Noise Frequency
	produce smaller, finer artifacts, and lower values produce
	larger, coarser artifacts.  If Noise Frequency is set to
	zero, that is the same as turning Noise off.
	*/
	void setNoiseFreq(const FloatID& nf){fprintf_s(mFile,"connectAttr \"");nf.write(mFile);fprintf_s(mFile,"\" \"%s.nf\";\n",mName.c_str());}
	/*
	<b>Noise Aspect</b> controls the distribution of the noise
	(when Noise is turned on).  It is zero by default, meaning
	that the noise is equally distributed in X and Y.  Positive
	values make the noise run perpendicular to the particle's path.
	Negative values make the noise run more parallel to the path.
	*/
	void setNoiseAspect(float na){if(na == 0.0) return; fprintf_s(mFile, "setAttr \".na\" %f;\n", na);}
	/*
	<b>Noise Aspect</b> controls the distribution of the noise
	(when Noise is turned on).  It is zero by default, meaning
	that the noise is equally distributed in X and Y.  Positive
	values make the noise run perpendicular to the particle's path.
	Negative values make the noise run more parallel to the path.
	*/
	void setNoiseAspect(const FloatID& na){fprintf_s(mFile,"connectAttr \"");na.write(mFile);fprintf_s(mFile,"\" \"%s.na\";\n",mName.c_str());}
	/*the weight in the intensity calculation*/
	void setParticleWeight(const FloatID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*particle emission*/
	void setParticleEmission(const Float3ID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e\";\n",mName.c_str());}
	/*emission red value*/
	void setParticleEmissionR(const FloatID& er){fprintf_s(mFile,"connectAttr \"");er.write(mFile);fprintf_s(mFile,"\" \"%s.e.er\";\n",mName.c_str());}
	/*emission green value*/
	void setParticleEmissionG(const FloatID& eg){fprintf_s(mFile,"connectAttr \"");eg.write(mFile);fprintf_s(mFile,"\" \"%s.e.eg\";\n",mName.c_str());}
	/*emission blue value*/
	void setParticleEmissionB(const FloatID& eb){fprintf_s(mFile,"connectAttr \"");eb.write(mFile);fprintf_s(mFile,"\" \"%s.e.eb\";\n",mName.c_str());}
	/*
	<b>Blob Map</b> is a scaling factor applied to the
	transparency of the particle cloud.  You can connect
	a 3d texture to it in order to give some internal texture
	or shape to the cloud beyond what it gets from the particles.
	*/
	void setBlobMap(const float3& m){fprintf_s(mFile, "setAttr \".m\" -type \"float3\" ");m.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Blob Map</b> is a scaling factor applied to the
	transparency of the particle cloud.  You can connect
	a 3d texture to it in order to give some internal texture
	or shape to the cloud beyond what it gets from the particles.
	*/
	void setBlobMap(const Float3ID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*blob map red value*/
	void setBlobMapR(float mr){if(mr == 1.0) return; fprintf_s(mFile, "setAttr \".m.mr\" %f;\n", mr);}
	/*blob map red value*/
	void setBlobMapR(const FloatID& mr){fprintf_s(mFile,"connectAttr \"");mr.write(mFile);fprintf_s(mFile,"\" \"%s.m.mr\";\n",mName.c_str());}
	/*blob map green value*/
	void setBlobMapG(float mg){if(mg == 1.0) return; fprintf_s(mFile, "setAttr \".m.mg\" %f;\n", mg);}
	/*blob map green value*/
	void setBlobMapG(const FloatID& mg){fprintf_s(mFile,"connectAttr \"");mg.write(mFile);fprintf_s(mFile,"\" \"%s.m.mg\";\n",mName.c_str());}
	/*blob map blue value*/
	void setBlobMapB(float mb){if(mb == 1.0) return; fprintf_s(mFile, "setAttr \".m.mb\" %f;\n", mb);}
	/*blob map blue value*/
	void setBlobMapB(const FloatID& mb){fprintf_s(mFile,"connectAttr \"");mb.write(mFile);fprintf_s(mFile,"\" \"%s.m.mb\";\n",mName.c_str());}
	/*The array of lighting infos.*/
	void setLightDataArray(size_t ltd_i,const LightDataID& ltd){fprintf_s(mFile,"connectAttr \"");ltd.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i]\";\n",mName.c_str(),ltd_i);}
	/*The light direction.*/
	void setLightDirection(size_t ltd_i,const Float3ID& ld){fprintf_s(mFile,"connectAttr \"");ld.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].ld\";\n",mName.c_str(),ltd_i);}
	/*The x component of the direction.*/
	void setLightDirectionX(size_t ltd_i,const FloatID& ldx){fprintf_s(mFile,"connectAttr \"");ldx.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].ld.ldx\";\n",mName.c_str(),ltd_i);}
	/*The y component of the direction.*/
	void setLightDirectionY(size_t ltd_i,const FloatID& ldy){fprintf_s(mFile,"connectAttr \"");ldy.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].ld.ldy\";\n",mName.c_str(),ltd_i);}
	/*The z component of the direction.*/
	void setLightDirectionZ(size_t ltd_i,const FloatID& ldz){fprintf_s(mFile,"connectAttr \"");ldz.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].ld.ldz\";\n",mName.c_str(),ltd_i);}
	/*The light intensity.*/
	void setLightIntensity(size_t ltd_i,const Float3ID& li){fprintf_s(mFile,"connectAttr \"");li.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].li\";\n",mName.c_str(),ltd_i);}
	/*The red component of the intensity.*/
	void setLightIntensityR(size_t ltd_i,const FloatID& lir){fprintf_s(mFile,"connectAttr \"");lir.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].li.lir\";\n",mName.c_str(),ltd_i);}
	/*The green component of the intensity.*/
	void setLightIntensityG(size_t ltd_i,const FloatID& lig){fprintf_s(mFile,"connectAttr \"");lig.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].li.lig\";\n",mName.c_str(),ltd_i);}
	/*The blue component of the intensity.*/
	void setLightIntensityB(size_t ltd_i,const FloatID& lib){fprintf_s(mFile,"connectAttr \"");lib.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].li.lib\";\n",mName.c_str(),ltd_i);}
	/*The boolean that indicates if the light has an ambient component.*/
	void setLightAmbient(size_t ltd_i,const BoolID& la){fprintf_s(mFile,"connectAttr \"");la.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].la\";\n",mName.c_str(),ltd_i);}
	/*The boolean that indicates if the light has a diffuse component.*/
	void setLightDiffuse(size_t ltd_i,const BoolID& ldf){fprintf_s(mFile,"connectAttr \"");ldf.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].ldf\";\n",mName.c_str(),ltd_i);}
	/*The boolean that indicates if the light has a specular component.*/
	void setLightSpecular(size_t ltd_i,const BoolID& ls){fprintf_s(mFile,"connectAttr \"");ls.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].ls\";\n",mName.c_str(),ltd_i);}
	/*The visibility fraction to the light.  value is in [0,1]*/
	void setLightShadowFraction(size_t ltd_i,const FloatID& lsf){fprintf_s(mFile,"connectAttr \"");lsf.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].lsf\";\n",mName.c_str(),ltd_i);}
	/*The light intensity without taking shadow into account.*/
	void setPreShadowIntensity(size_t ltd_i,const FloatID& psi){fprintf_s(mFile,"connectAttr \"");psi.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].psi\";\n",mName.c_str(),ltd_i);}
	/*The light's blind data.*/
	void setLightBlindData(size_t ltd_i,const AddrID& lbd){fprintf_s(mFile,"connectAttr \"");lbd.write(mFile);fprintf_s(mFile,"\" \"%s.ltd[%i].lbd\";\n",mName.c_str(),ltd_i);}
	/*The current sample point relative to the particle*/
	void setPointObj(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The x comp of the current sample position relative to the particle*/
	void setPointObjX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The y comp of the current sample position relative to the particle*/
	void setPointObjY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The z comp of the current sample position relative to the particle*/
	void setPointObjZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*
	<b>Normal Camera</b> represents the surface normals in the
	camera's space. (These are
	used to calculate shading.)<p/>To do Bump Mapping, connect the output of a bump
	node to this attribute.
	*/
	void setNormalCamera(const Float3ID& nc){fprintf_s(mFile,"connectAttr \"");nc.write(mFile);fprintf_s(mFile,"\" \"%s.nc\";\n",mName.c_str());}
	/*normal camera x value*/
	void setNormalCameraX(const FloatID& ncx){fprintf_s(mFile,"connectAttr \"");ncx.write(mFile);fprintf_s(mFile,"\" \"%s.nc.ncx\";\n",mName.c_str());}
	/*normal camera Y value*/
	void setNormalCameraY(const FloatID& ncy){fprintf_s(mFile,"connectAttr \"");ncy.write(mFile);fprintf_s(mFile,"\" \"%s.nc.ncy\";\n",mName.c_str());}
	/*normal camera Z value*/
	void setNormalCameraZ(const FloatID& ncz){fprintf_s(mFile,"connectAttr \"");ncz.write(mFile);fprintf_s(mFile,"\" \"%s.nc.ncz\";\n",mName.c_str());}
	/*
	<b>Translucence</b> simulates the way light diffusely penetrates
	through translucent objects.  This means that when light shines
	on one side of the object, the other side is partially illuminated.
	This can be used for effects such as clouds, fur, hair, marble,
	jade, wax, paper, leaves, etc.
	<p/>If this is set to 0 (the default) then no light shows through
	the object.  If this is set to 1, all the light shows through.
	*/
	void setTranslucenceCoeff(float tc){if(tc == 0.0) return; fprintf_s(mFile, "setAttr \".tc\" %f;\n", tc);}
	/*
	<b>Translucence</b> simulates the way light diffusely penetrates
	through translucent objects.  This means that when light shines
	on one side of the object, the other side is partially illuminated.
	This can be used for effects such as clouds, fur, hair, marble,
	jade, wax, paper, leaves, etc.
	<p/>If this is set to 0 (the default) then no light shows through
	the object.  If this is set to 1, all the light shows through.
	*/
	void setTranslucenceCoeff(const FloatID& tc){fprintf_s(mFile,"connectAttr \"");tc.write(mFile);fprintf_s(mFile,"\" \"%s.tc\";\n",mName.c_str());}
	/*
	<b>Diffuse</b> controls how much of the light in the scene
	is reflected from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.  The default
	value is 0.0;  a value of 1.0 would mean that all
	the light falling on the material is reflected;  a value of 0.0
	(the minimum) would mean that no light is reflected.  The surface
	color will be modulated by the transparency.  This value is allowed
	to be greater than one so that the surface property can still show
	up even when the material is transparent.
	*/
	void setDiffuseCoeff(float dc){if(dc == 0.0) return; fprintf_s(mFile, "setAttr \".dc\" %f;\n", dc);}
	/*
	<b>Diffuse</b> controls how much of the light in the scene
	is reflected from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.  The default
	value is 0.0;  a value of 1.0 would mean that all
	the light falling on the material is reflected;  a value of 0.0
	(the minimum) would mean that no light is reflected.  The surface
	color will be modulated by the transparency.  This value is allowed
	to be greater than one so that the surface property can still show
	up even when the material is transparent.
	*/
	void setDiffuseCoeff(const FloatID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*
	<b>Surface Shading Shadow</b> determines if we want to combine the surface
	shading with the pre-illumination, which contains shadow if enabled.
	*/
	void setSurfaceShadingShadow(bool sss){if(sss == false) return; fprintf_s(mFile, "setAttr \".sss\" %i;\n", sss);}
	/*
	<b>Surface Shading Shadow</b> determines if we want to combine the surface
	shading with the pre-illumination, which contains shadow if enabled.
	*/
	void setSurfaceShadingShadow(const BoolID& sss){fprintf_s(mFile,"connectAttr \"");sss.write(mFile);fprintf_s(mFile,"\" \"%s.sss\";\n",mName.c_str());}
	/*
	<b>SurfaceColor</b> is the basic color of the particle cloud for
	surface propoty, which is useful in a very dense volume.
	*/
	void setSurfaceColor(const float3& sc){fprintf_s(mFile, "setAttr \".sc\" -type \"float3\" ");sc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>SurfaceColor</b> is the basic color of the particle cloud for
	surface propoty, which is useful in a very dense volume.
	*/
	void setSurfaceColor(const Float3ID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*color red value*/
	void setSurfaceColorR(float scr){if(scr == 0.4) return; fprintf_s(mFile, "setAttr \".sc.scr\" %f;\n", scr);}
	/*color red value*/
	void setSurfaceColorR(const FloatID& scr){fprintf_s(mFile,"connectAttr \"");scr.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scr\";\n",mName.c_str());}
	/*color green value*/
	void setSurfaceColorG(float scg){if(scg == 0.4) return; fprintf_s(mFile, "setAttr \".sc.scg\" %f;\n", scg);}
	/*color green value*/
	void setSurfaceColorG(const FloatID& scg){fprintf_s(mFile,"connectAttr \"");scg.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scg\";\n",mName.c_str());}
	/*color blue value*/
	void setSurfaceColorB(float scb){if(scb == 0.4) return; fprintf_s(mFile, "setAttr \".sc.scb\" %f;\n", scb);}
	/*color blue value*/
	void setSurfaceColorB(const FloatID& scb){fprintf_s(mFile,"connectAttr \"");scb.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scb\";\n",mName.c_str());}
	/*
	<b>Solid Core Size</b> determines the size of the core, where it should be
	opaque.
	*/
	void setSolidCoreSize(float scs){if(scs == 0.0) return; fprintf_s(mFile, "setAttr \".scs\" %f;\n", scs);}
	/*
	<b>Solid Core Size</b> determines the size of the core, where it should be
	opaque.
	*/
	void setSolidCoreSize(const FloatID& scs){fprintf_s(mFile,"connectAttr \"");scs.write(mFile);fprintf_s(mFile,"\" \"%s.scs\";\n",mName.c_str());}
	/*
	<b>Translucence</b> is a scaling factor for density used only for
	shadow computation.  The way it's used is density * (1 - translucence).
	The larger translucence is, the more light will penetrate.
	*/
	void setTranslucence(float trsl){if(trsl == 0.5) return; fprintf_s(mFile, "setAttr \".trsl\" %f;\n", trsl);}
	/*
	<b>Translucence</b> is a scaling factor for density used only for
	shadow computation.  The way it's used is density * (1 - translucence).
	The larger translucence is, the more light will penetrate.
	*/
	void setTranslucence(const FloatID& trsl){fprintf_s(mFile,"connectAttr \"");trsl.write(mFile);fprintf_s(mFile,"\" \"%s.trsl\";\n",mName.c_str());}
	/*
	<b>Noise Anim Rate</b> is the scaling factor to control the rate of built-in
	noise changes during an animation.
	*/
	void setNoiseAnimRate(float nanr){if(nanr == 0.0) return; fprintf_s(mFile, "setAttr \".nanr\" %f;\n", nanr);}
	/*
	<b>Noise Anim Rate</b> is the scaling factor to control the rate of built-in
	noise changes during an animation.
	*/
	void setNoiseAnimRate(const FloatID& nanr){fprintf_s(mFile,"connectAttr \"");nanr.write(mFile);fprintf_s(mFile,"\" \"%s.nanr\";\n",mName.c_str());}
	/*
	<b>Roundness</b> gives the control of the noise's irregularity.  The smaller
	the value, the less rounded the shape is.
	*/
	void setRoundness(float rdns){if(rdns == 1.0) return; fprintf_s(mFile, "setAttr \".rdns\" %f;\n", rdns);}
	/*
	<b>Roundness</b> gives the control of the noise's irregularity.  The smaller
	the value, the less rounded the shape is.
	*/
	void setRoundness(const FloatID& rdns){fprintf_s(mFile,"connectAttr \"");rdns.write(mFile);fprintf_s(mFile,"\" \"%s.rdns\";\n",mName.c_str());}
	/*current ray depth*/
	void setRayDepth(const ShortID& rd){fprintf_s(mFile,"connectAttr \"");rd.write(mFile);fprintf_s(mFile,"\" \"%s.rd\";\n",mName.c_str());}
	/*particle order (it was called particleId before maya v3)*/
	void setParticleOrder(const IntID& podr){fprintf_s(mFile,"connectAttr \"");podr.write(mFile);fprintf_s(mFile,"\" \"%s.podr\";\n",mName.c_str());}
	/*filter radius for emission*/
	void setFilterRadius(float flrs){if(flrs == 0.0) return; fprintf_s(mFile, "setAttr \".flrs\" %f;\n", flrs);}
	/*filter radius for emission*/
	void setFilterRadius(const FloatID& flrs){fprintf_s(mFile,"connectAttr \"");flrs.write(mFile);fprintf_s(mFile,"\" \"%s.flrs\";\n",mName.c_str());}
	/*the flag to tell if the shading is for shadow computation.*/
	void setRenderState(int rdst){if(rdst == 0) return; fprintf_s(mFile, "setAttr \".rdst\" %i;\n", rdst);}
	/*output; the light intensity received at each particle. Done before rendering started.*/
	Float3ID getOutParticleEmission(){char buffer[4096];sprintf_s (buffer, "%s.oe",mName.c_str());return (const char*)buffer;}
	/*output; red component of the emission*/
	FloatID getOutParticleEmissionR(){char buffer[4096];sprintf_s (buffer, "%s.oe.oer",mName.c_str());return (const char*)buffer;}
	/*output green component of the emission*/
	FloatID getOutParticleEmissionG(){char buffer[4096];sprintf_s (buffer, "%s.oe.oeg",mName.c_str());return (const char*)buffer;}
	/*output blue component of the emission*/
	FloatID getOutParticleEmissionB(){char buffer[4096];sprintf_s (buffer, "%s.oe.oeb",mName.c_str());return (const char*)buffer;}
	/*the final output color*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oi",mName.c_str());return (const char*)buffer;}
	/*output red component of the source intensity*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oi.oir",mName.c_str());return (const char*)buffer;}
	/*output green component of the source intensity*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oi.oig",mName.c_str());return (const char*)buffer;}
	/*output blue component of the source intensity*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oi.oib",mName.c_str());return (const char*)buffer;}
	/*the final output glow color*/
	Float3ID getOutGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.ogi",mName.c_str());return (const char*)buffer;}
	/*output glow red component*/
	FloatID getOutGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.ogi.ogr",mName.c_str());return (const char*)buffer;}
	/*output glow green component*/
	FloatID getOutGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.ogi.ogg",mName.c_str());return (const char*)buffer;}
	/*output glow blue component*/
	FloatID getOutGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.ogi.ogb",mName.c_str());return (const char*)buffer;}
	/*output transparency*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*outTransparency red value*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*outTransparency green value*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*outTransparency blue value*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color</b> is the basic color of the particle cloud. The
	default color is a green-blue.
	*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*color red value*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.c.cr",mName.c_str());return (const char*)buffer;}
	/*color green value*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.c.cg",mName.c_str());return (const char*)buffer;}
	/*color blue value*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.c.cb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Transparency</b> controls how much you can see through
	the particle cloud.  It is a color, so that you can control the
	the transparency of the red, green, and blue channels separately.
	To make the cloud more opaque, set transparency to be darker.
	To make the cloud more transparent, set transparency to be
	brighter.
	*/
	Float3ID getTransparency(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*transparency red value*/
	FloatID getTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.t.tr",mName.c_str());return (const char*)buffer;}
	/*transparency green value*/
	FloatID getTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.t.tg",mName.c_str());return (const char*)buffer;}
	/*transparency blue value*/
	FloatID getTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.t.tb",mName.c_str());return (const char*)buffer;}
	/*
	Use <b>Incandescence</b> to make the particle cloud brighter,
	as though it were a light source.  By default, Incandescence is black,
	meaning no glow will be added. <p/>
	Note that when Incandescence is turned on, although the particle
	cloud will glow,
	it will not cast light on other objects in the scene.
	*/
	Float3ID getIncandescence(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*incandescence red value*/
	FloatID getIncandescenceR(){char buffer[4096];sprintf_s (buffer, "%s.i.ir",mName.c_str());return (const char*)buffer;}
	/*incandescence green value*/
	FloatID getIncandescenceG(){char buffer[4096];sprintf_s (buffer, "%s.i.ig",mName.c_str());return (const char*)buffer;}
	/*incandescence blue value*/
	FloatID getIncandescenceB(){char buffer[4096];sprintf_s (buffer, "%s.i.ib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Density</b> is very similar to transparency; it controls
	how dense the cloud of particles appears to be, and therefore
	how much of the background can be seen through it.  Increase
	this value to make the cloud more dense.
	*/
	FloatID getDensity(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Intensity</b> controls how much of a halo-like glow
	effect will be added to the particle cloud.
	This glow effect is added as a post-process,
	after the rendering is completed.  Glow Intensity is zero
	by default, meaning that no glow is added.
	*/
	FloatID getGlowIntensity(){char buffer[4096];sprintf_s (buffer, "%s.gi",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise</b> controls the jitteryness within the
	particle cloud.  If it is set to zero, the cloud will look
	very smooth and uniform throughout.  As the amount of noise
	increases, the cloud will appear 'noisier', like static
	on a television screen.
	*/
	FloatID getNoise(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise Frequency</b> determines the size of the noise
	artifacts when Noise is turned on.  Higher values of Noise Frequency
	produce smaller, finer artifacts, and lower values produce
	larger, coarser artifacts.  If Noise Frequency is set to
	zero, that is the same as turning Noise off.
	*/
	FloatID getNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.nf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise Aspect</b> controls the distribution of the noise
	(when Noise is turned on).  It is zero by default, meaning
	that the noise is equally distributed in X and Y.  Positive
	values make the noise run perpendicular to the particle's path.
	Negative values make the noise run more parallel to the path.
	*/
	FloatID getNoiseAspect(){char buffer[4096];sprintf_s (buffer, "%s.na",mName.c_str());return (const char*)buffer;}
	/*the weight in the intensity calculation*/
	FloatID getParticleWeight(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*particle emission*/
	Float3ID getParticleEmission(){char buffer[4096];sprintf_s (buffer, "%s.e",mName.c_str());return (const char*)buffer;}
	/*emission red value*/
	FloatID getParticleEmissionR(){char buffer[4096];sprintf_s (buffer, "%s.e.er",mName.c_str());return (const char*)buffer;}
	/*emission green value*/
	FloatID getParticleEmissionG(){char buffer[4096];sprintf_s (buffer, "%s.e.eg",mName.c_str());return (const char*)buffer;}
	/*emission blue value*/
	FloatID getParticleEmissionB(){char buffer[4096];sprintf_s (buffer, "%s.e.eb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Blob Map</b> is a scaling factor applied to the
	transparency of the particle cloud.  You can connect
	a 3d texture to it in order to give some internal texture
	or shape to the cloud beyond what it gets from the particles.
	*/
	Float3ID getBlobMap(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*blob map red value*/
	FloatID getBlobMapR(){char buffer[4096];sprintf_s (buffer, "%s.m.mr",mName.c_str());return (const char*)buffer;}
	/*blob map green value*/
	FloatID getBlobMapG(){char buffer[4096];sprintf_s (buffer, "%s.m.mg",mName.c_str());return (const char*)buffer;}
	/*blob map blue value*/
	FloatID getBlobMapB(){char buffer[4096];sprintf_s (buffer, "%s.m.mb",mName.c_str());return (const char*)buffer;}
	/*The array of lighting infos.*/
	const LightDataID& getLightDataArray(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i]",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The light direction.*/
	const Float3ID& getLightDirection(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].ld",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The x component of the direction.*/
	const FloatID& getLightDirectionX(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].ld.ldx",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The y component of the direction.*/
	const FloatID& getLightDirectionY(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].ld.ldy",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The z component of the direction.*/
	const FloatID& getLightDirectionZ(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].ld.ldz",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The light intensity.*/
	const Float3ID& getLightIntensity(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].li",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The red component of the intensity.*/
	const FloatID& getLightIntensityR(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].li.lir",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The green component of the intensity.*/
	const FloatID& getLightIntensityG(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].li.lig",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The blue component of the intensity.*/
	const FloatID& getLightIntensityB(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].li.lib",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The boolean that indicates if the light has an ambient component.*/
	const BoolID& getLightAmbient(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].la",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The boolean that indicates if the light has a diffuse component.*/
	const BoolID& getLightDiffuse(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].ldf",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The boolean that indicates if the light has a specular component.*/
	const BoolID& getLightSpecular(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].ls",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The visibility fraction to the light.  value is in [0,1]*/
	const FloatID& getLightShadowFraction(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].lsf",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The light intensity without taking shadow into account.*/
	const FloatID& getPreShadowIntensity(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].psi",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The light's blind data.*/
	const AddrID& getLightBlindData(size_t ltd_i){char buffer[4096];sprintf_s (buffer, "%s.ltd[%i].lbd",mName.c_str(),ltd_i);return (const char*)buffer;}
	/*The current sample point relative to the particle*/
	Float3ID getPointObj(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The x comp of the current sample position relative to the particle*/
	FloatID getPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The y comp of the current sample position relative to the particle*/
	FloatID getPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The z comp of the current sample position relative to the particle*/
	FloatID getPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Normal Camera</b> represents the surface normals in the
	camera's space. (These are
	used to calculate shading.)<p/>To do Bump Mapping, connect the output of a bump
	node to this attribute.
	*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.nc",mName.c_str());return (const char*)buffer;}
	/*normal camera x value*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.nc.ncx",mName.c_str());return (const char*)buffer;}
	/*normal camera Y value*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.nc.ncy",mName.c_str());return (const char*)buffer;}
	/*normal camera Z value*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.nc.ncz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Translucence</b> simulates the way light diffusely penetrates
	through translucent objects.  This means that when light shines
	on one side of the object, the other side is partially illuminated.
	This can be used for effects such as clouds, fur, hair, marble,
	jade, wax, paper, leaves, etc.
	<p/>If this is set to 0 (the default) then no light shows through
	the object.  If this is set to 1, all the light shows through.
	*/
	FloatID getTranslucenceCoeff(){char buffer[4096];sprintf_s (buffer, "%s.tc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Diffuse</b> controls how much of the light in the scene
	is reflected from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.  The default
	value is 0.0;  a value of 1.0 would mean that all
	the light falling on the material is reflected;  a value of 0.0
	(the minimum) would mean that no light is reflected.  The surface
	color will be modulated by the transparency.  This value is allowed
	to be greater than one so that the surface property can still show
	up even when the material is transparent.
	*/
	FloatID getDiffuseCoeff(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Surface Shading Shadow</b> determines if we want to combine the surface
	shading with the pre-illumination, which contains shadow if enabled.
	*/
	BoolID getSurfaceShadingShadow(){char buffer[4096];sprintf_s (buffer, "%s.sss",mName.c_str());return (const char*)buffer;}
	/*
	<b>SurfaceColor</b> is the basic color of the particle cloud for
	surface propoty, which is useful in a very dense volume.
	*/
	Float3ID getSurfaceColor(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*color red value*/
	FloatID getSurfaceColorR(){char buffer[4096];sprintf_s (buffer, "%s.sc.scr",mName.c_str());return (const char*)buffer;}
	/*color green value*/
	FloatID getSurfaceColorG(){char buffer[4096];sprintf_s (buffer, "%s.sc.scg",mName.c_str());return (const char*)buffer;}
	/*color blue value*/
	FloatID getSurfaceColorB(){char buffer[4096];sprintf_s (buffer, "%s.sc.scb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Solid Core Size</b> determines the size of the core, where it should be
	opaque.
	*/
	FloatID getSolidCoreSize(){char buffer[4096];sprintf_s (buffer, "%s.scs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Translucence</b> is a scaling factor for density used only for
	shadow computation.  The way it's used is density * (1 - translucence).
	The larger translucence is, the more light will penetrate.
	*/
	FloatID getTranslucence(){char buffer[4096];sprintf_s (buffer, "%s.trsl",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise Anim Rate</b> is the scaling factor to control the rate of built-in
	noise changes during an animation.
	*/
	FloatID getNoiseAnimRate(){char buffer[4096];sprintf_s (buffer, "%s.nanr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Roundness</b> gives the control of the noise's irregularity.  The smaller
	the value, the less rounded the shape is.
	*/
	FloatID getRoundness(){char buffer[4096];sprintf_s (buffer, "%s.rdns",mName.c_str());return (const char*)buffer;}
	/*current ray depth*/
	ShortID getRayDepth(){char buffer[4096];sprintf_s (buffer, "%s.rd",mName.c_str());return (const char*)buffer;}
	/*particle order (it was called particleId before maya v3)*/
	IntID getParticleOrder(){char buffer[4096];sprintf_s (buffer, "%s.podr",mName.c_str());return (const char*)buffer;}
	/*filter radius for emission*/
	FloatID getFilterRadius(){char buffer[4096];sprintf_s (buffer, "%s.flrs",mName.c_str());return (const char*)buffer;}
protected:
	ParticleCloud(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLECLOUD_H__
