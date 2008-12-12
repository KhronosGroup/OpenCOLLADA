/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MENTALRAYIBLSHAPE_H__
#define __MayaDM_MENTALRAYIBLSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
namespace MayaDM
{
/*
"mentalrayIblShape" is a mental ray for Maya plugin node that
 simulate light emitted from an infinitely distant (environment) sphere.
 mental ray for Maya plugin needs to be loaded to use this node.
 <br/>
 Image Based Lighting is a popular technique for realistic image synthesis.
 It involves taking one or more pictures of a real environment
 (usually by means of a chrome ball),
 processing that picture into a texture and using it to illuminate the scene.
 The texture is typically mapped to the incandescence channel of a sphere that surrounds the scene.
 Final Gathering is used to illuminated the scene;
 it can pick up incandescence samples from the environment texture.
 Illumination models deal with these samples similar to direct light arriving from, say, a spot light.
 <br/>
 Users could enclose their scenes by a real sphere (mesh, NURBS) which the texture is mapped to.
 While this workflow is appropriate if a finite distance to the environment is required,
 it has several drawbacks when the environment can be considered infinitely distant.
 Because the sphere is actual geometry, mental ray processes it as such.
 It gets tesselated.
 The sphere becomes part of acceleration structures (BSP tree)
 where it (due to its "encompassing" nature) can slow rendering down significantly.
 The interactive Maya workflow can be hindered if such a large sphere present in the scene
 <br/>
 Users may activate the Image Based Lighting (IBL) feature
 in mental ray's Render Settings window by creating an IBL node.
 The attribute editor (AE) may be used to tune attributes.
 IBL environments can be previewed in OpenGL (if they are file texture based).
 In mental ray, IBL is represented by a set of shaders and no geometry is created or exported.
 <br/>
 Image Based Lighting is represented in the Model View by means of a shape node.
 You may scale or move the shape, but this has no effect
 because the environment is considered infinitely distant.
 For best feedback, you should not move the shape, but scale it as large as your clipping planes permit.
  Rotations of the shape are relevant and recognized
 as placement attribute on the corresponding mental ray shaders.
 <p/>
 To sum up, Image Based Lighting consists of three mental ray shaders:
 <p/>
 <b>Environment Shader</b>
 <br/>
 Together with Final Gathering this implements classical image based lighting.
 The color of the environment is picked up by final gather rays and incorporated into surface illumination.
 An environment shader is passive, it just "sits around" and occasionally gets hit by a ray.
 This approach works best if the IBL texture is diffuse.
 An extreme would be if the texture consisted only of a single color;
 this results in ambient occlusion computation.
 <p/>
 <b>Photon Emission Shader</b>
 <br/>
 Photons are emitted from the IBL environment sphere.
 These photons pick up their energies (or colors) from the IBL texture.
 A photon emission shader emits all its photons once per frame.
 It is more "active" than an environment shader in this sense.
 Photons work best with mostly diffuse IBL textures.
 <p/>
 <b>Light Shader</b>
 <br/>
 A low-resolution control texture is computed (from the file or procedural IBL texture)
 and mapped to the IBL environment sphere.
 Whenever direct lights are sampled, the light shader is invoked.
 In this sense, the light shader approach is the most "active" one, and the most expensive.
 The IBL environment can be seen as one big area light.
 This approach works best (also due to importance sampling) if the IBL texture contains sharp features;
 preferably contains much more black than non-black pixels.
 <p/>
 These three approaches may be combined, at the expense of computation time.
*/
class MentalrayIblShape
{
public:
protected:
	FILE* mFile;
	std::string mName;
	std::string mParent;
	std::string mNodeType;
public:
	const std::string& getName(){return mName;}
	const std::string& getParent(){return mParent;}
	const std::string& getType(){return mNodeType;}
public:
		virtual ~MentalrayIblShape(){}
	/*
	Select a UV space for the environment sphere.
	0 = Spherical (latitude-longitude), 1 = Angular (HDR Shop).
	*/
	void setMapping(unsigned int map){if(map == 0) return; fprintf_s(mFile, "setAttr \".map\" %i;\n", map);}
	/*
	Whether to map a file or a procedural texture as IBL texture.
	File textures can be previewed in OpenGL.
	0 = Image File, 1 = Texture.
	If a file is used as IBL texture, it is recommended to use Image File
	instead of using maya fileTexture and set the <b>type</b> to Texture.
	There is no difference between the two for the Environment and Photon Emission part.
	However, the Light Emission will downfilter the Image File,
	whereas the Texture is just point sampled.
	*/
	void setType(unsigned int typ){if(typ == 0) return; fprintf_s(mFile, "setAttr \".typ\" %i;\n", typ);}
	/*Name of file on disk if <b>Type</b> is <b>File Texture</b>.*/
	void setTexture(const string& tx){if(tx == "NULL") return; fprintf_s(mFile, "setAttr \".tx\" -type \"string\" ");tx.write(mFile);fprintf_s(mFile,";\n");}
	/*If enabled, the texture's file name may change on a per-frame basis.*/
	void setUseFrameExtension(bool ufe){if(ufe == false) return; fprintf_s(mFile, "setAttr \".ufe\" %i;\n", ufe);}
	/*The frame extension.*/
	void setFrameExtension(int fe){if(fe == 1) return; fprintf_s(mFile, "setAttr \".fe\" %i;\n", fe);}
	/*The frame extension.*/
	void setFrameExtension(const IntID& fe){fprintf_s(mFile,"connectAttr \"");fe.write(mFile);fprintf_s(mFile,"\" \"%s.fe\";\n",mName.c_str());}
	/*If <b>Type</b> is Procedural, hook up a 2D texture shader here.*/
	void setColor(const float3& col){if(col == float3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".col\" -type \"float3\" ");col.write(mFile);fprintf_s(mFile,";\n");}
	/*If <b>Type</b> is Procedural, hook up a 2D texture shader here.*/
	void setColor(const Float3ID& col){fprintf_s(mFile,"connectAttr \"");col.write(mFile);fprintf_s(mFile,"\" \"%s.col\";\n",mName.c_str());}
	/*Alpha component of 2d texture.*/
	void setColorR(float colr){if(colr == 0) return; fprintf_s(mFile, "setAttr \".col.colr\" %f;\n", colr);}
	/*Alpha component of 2d texture.*/
	void setColorR(const FloatID& colr){fprintf_s(mFile,"connectAttr \"");colr.write(mFile);fprintf_s(mFile,"\" \"%s.col.colr\";\n",mName.c_str());}
	/*Green component of 2d texture.*/
	void setColorG(float colg){if(colg == 0) return; fprintf_s(mFile, "setAttr \".col.colg\" %f;\n", colg);}
	/*Green component of 2d texture.*/
	void setColorG(const FloatID& colg){fprintf_s(mFile,"connectAttr \"");colg.write(mFile);fprintf_s(mFile,"\" \"%s.col.colg\";\n",mName.c_str());}
	/*Blue component of 2d texture.*/
	void setColorB(float colb){if(colb == 0) return; fprintf_s(mFile, "setAttr \".col.colb\" %f;\n", colb);}
	/*Blue component of 2d texture.*/
	void setColorB(const FloatID& colb){fprintf_s(mFile,"connectAttr \"");colb.write(mFile);fprintf_s(mFile,"\" \"%s.col.colb\";\n",mName.c_str());}
	/*
	Set texture filter quality for model view.
	0 = Nearest, 1 = Linear
	*/
	void setHardwareFilter(unsigned int hwf){if(hwf == 0) return; fprintf_s(mFile, "setAttr \".hwf\" %i;\n", hwf);}
	/*
	Set transparency of IBL shape locator in model view.
	0 is transparent, 1 is fully opaque.
	*/
	void setHardwareAlpha(float hwt){if(hwt == 0.5) return; fprintf_s(mFile, "setAttr \".hwt\" %f;\n", hwt);}
	/*
	Use <b>Color Gain</b> to fine-tune the balance of a texture's Out Color.
	Color Gain is applied as a multiplier to the texture's color.
	If Color Gain is white, it has no effect.
	Reducing the amount of red (for example) in Color Gain will scale down the amount of red in the final output color.
	*/
	void setColorGain(const float3& cg){if(cg == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".cg\" -type \"float3\" ");cg.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Use <b>Color Gain</b> to fine-tune the balance of a texture's Out Color.
	Color Gain is applied as a multiplier to the texture's color.
	If Color Gain is white, it has no effect.
	Reducing the amount of red (for example) in Color Gain will scale down the amount of red in the final output color.
	*/
	void setColorGain(const Float3ID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.cg\";\n",mName.c_str());}
	/*Color Gain Red Value*/
	void setColorGainR(float cgr){if(cgr == 1.0) return; fprintf_s(mFile, "setAttr \".cg.cgr\" %f;\n", cgr);}
	/*Color Gain Red Value*/
	void setColorGainR(const FloatID& cgr){fprintf_s(mFile,"connectAttr \"");cgr.write(mFile);fprintf_s(mFile,"\" \"%s.cg.cgr\";\n",mName.c_str());}
	/*Color Gain Green Value*/
	void setColorGainG(float cgg){if(cgg == 1.0) return; fprintf_s(mFile, "setAttr \".cg.cgg\" %f;\n", cgg);}
	/*Color Gain Green Value*/
	void setColorGainG(const FloatID& cgg){fprintf_s(mFile,"connectAttr \"");cgg.write(mFile);fprintf_s(mFile,"\" \"%s.cg.cgg\";\n",mName.c_str());}
	/*Color Gain Blue Value*/
	void setColorGainB(float cgb){if(cgb == 1.0) return; fprintf_s(mFile, "setAttr \".cg.cgb\" %f;\n", cgb);}
	/*Color Gain Blue Value*/
	void setColorGainB(const FloatID& cgb){fprintf_s(mFile,"connectAttr \"");cgb.write(mFile);fprintf_s(mFile,"\" \"%s.cg.cgb\";\n",mName.c_str());}
	/*
	Use <b>Color Offset</b> to brighten and adjust a texture's Out Color.
	Unlike Color Gain (which is a multiplier), Color Offset is simply added to the texture's Out Color.
	Therefore if Color Offset is black, it has no effect.
	Increasing the amount of red (for example) in Color Offset
	will uniformly increase the amount of red in the final output color.
	*/
	void setColorOffset(const float3& cof){if(cof == float3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".cof\" -type \"float3\" ");cof.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Use <b>Color Offset</b> to brighten and adjust a texture's Out Color.
	Unlike Color Gain (which is a multiplier), Color Offset is simply added to the texture's Out Color.
	Therefore if Color Offset is black, it has no effect.
	Increasing the amount of red (for example) in Color Offset
	will uniformly increase the amount of red in the final output color.
	*/
	void setColorOffset(const Float3ID& cof){fprintf_s(mFile,"connectAttr \"");cof.write(mFile);fprintf_s(mFile,"\" \"%s.cof\";\n",mName.c_str());}
	/*Color Offset Red Value*/
	void setColorOffsetR(float cofr){if(cofr == 0) return; fprintf_s(mFile, "setAttr \".cof.cofr\" %f;\n", cofr);}
	/*Color Offset Red Value*/
	void setColorOffsetR(const FloatID& cofr){fprintf_s(mFile,"connectAttr \"");cofr.write(mFile);fprintf_s(mFile,"\" \"%s.cof.cofr\";\n",mName.c_str());}
	/*Color Offset Green Value*/
	void setColorOffsetG(float cofg){if(cofg == 0) return; fprintf_s(mFile, "setAttr \".cof.cofg\" %f;\n", cofg);}
	/*Color Offset Green Value*/
	void setColorOffsetG(const FloatID& cofg){fprintf_s(mFile,"connectAttr \"");cofg.write(mFile);fprintf_s(mFile,"\" \"%s.cof.cofg\";\n",mName.c_str());}
	/*Color Offset Blue Value*/
	void setColorOffsetB(float cofb){if(cofb == 0) return; fprintf_s(mFile, "setAttr \".cof.cofb\" %f;\n", cofb);}
	/*Color Offset Blue Value*/
	void setColorOffsetB(const FloatID& cofb){fprintf_s(mFile,"connectAttr \"");cofb.write(mFile);fprintf_s(mFile,"\" \"%s.cof.cofb\";\n",mName.c_str());}
	/*
	<b>Invert</b> is used to reverse the color values of the texture.
	When Invert is turned on, white becomes black, black becomes white,
	red becomes cyan, yellow becomes blue, etc.
	*/
	void setInvert(bool inv){if(inv == false) return; fprintf_s(mFile, "setAttr \".inv\" %i;\n", inv);}
	/*
	<b>Alpha Is Luminance</b> can be turned on to
	make the alpha (mask) output of this node depend on the luminance of the texture.
	This means that bright areas of the texture will be more opaque when compositing,
	and dark areas will be more transparent.
	*/
	void setAlphaIsLuminance(bool ail){if(ail == false) return; fprintf_s(mFile, "setAttr \".ail\" %i;\n", ail);}
	/*
	The visiblity attributes under Render Stats maps to a camera environment shader in mental ray.
	If all visiblity attributes are turned off, no environment shader is exported.
	<b>primaryVisibility</b> decides IBL texture's visiblity to primary rays.
	*/
	void setPrimaryVisibility(bool vis){if(vis == true) return; fprintf_s(mFile, "setAttr \".vis\" %i;\n", vis);}
	/*
	The visiblity attributes under Render Stats maps to a camera environment shader in mental ray.
	If all visiblity attributes are turned off, no environment shader is exported.
	<b>visibleInEnvironment</b> decides IBL texture's visiblity to Environment rays.
	The default is false, but if created through mental ray render settings,
	this value will be set to true on creation.
	Environment ray contributes to the reflection from the environment.
	*/
	void setVisibleInEnvironment(bool vien){if(vien == false) return; fprintf_s(mFile, "setAttr \".vien\" %i;\n", vien);}
	/*
	The visiblity attributes under Render Stats maps to a camera environment shader in mental ray.
	If all visiblity attributes are turned off, no environment shader is exported.
	<b>visibleInReflections</b> decides IBL texture's visiblity to reflection rays.
	The default is false, but if created through mental ray render settings,
	this value will be set to true on creation.
	This attribute controls the secondary reflections.
	The direct reflection of the enviroment is controlled by visibleInEnvironment.
	*/
	void setVisibleInReflections(bool vir){if(vir == false) return; fprintf_s(mFile, "setAttr \".vir\" %i;\n", vir);}
	/*
	The visiblity attributes under Render Stats maps to a camera environment shader in mental ray.
	If all visiblity attributes are turned off, no environment shader is exported.
	<b>visibleInRefractions</b> decides IBL texture's visiblity to refraction rays.
	The default is false, but if created through mental ray render settings,
	this value will be set to true on creation.
	This attribute controls if IBL texture is visible in refractions.
	*/
	void setVisibleInRefractions(bool vif){if(vif == false) return; fprintf_s(mFile, "setAttr \".vif\" %i;\n", vif);}
	/*
	The visiblity attributes under Render Stats maps to a camera environment shader in mental ray.
	If all visiblity attributes are turned off, no environment shader is exported.
	<b>visibleInFinalGather</b> decides IBL texture's visiblity to Final Gather rays.
	The default is false, but if created through mental ray render settings,
	this value will be set to true on creation.
	If visible to Final Gather rays, the IBL texture will be used to illuminate the scene.
	Otherwise, IBL does not affect final gather.
	*/
	void setVisibleInFinalGather(bool vifg){if(vifg == false) return; fprintf_s(mFile, "setAttr \".vifg\" %i;\n", vifg);}
	/*
	You can adjust IBL contribution per component.
	To adjust the environment color, enable <b>overrideEnvColorFx</b>,
	and use envInvert, envColorGain, envColorOffset to fine tune the contribution.
	*/
	void setOverrideEnvColorFx(bool oefx){if(oefx == false) return; fprintf_s(mFile, "setAttr \".oefx\" %i;\n", oefx);}
	/*Invert the IBL texture color for the environment component only.*/
	void setEnvInvert(bool einv){if(einv == false) return; fprintf_s(mFile, "setAttr \".einv\" %i;\n", einv);}
	/*Color Gain for the environment component.*/
	void setEnvColorGain(const float3& ecg){if(ecg == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".ecg\" -type \"float3\" ");ecg.write(mFile);fprintf_s(mFile,";\n");}
	/*Color Gain for the environment component.*/
	void setEnvColorGain(const Float3ID& ecg){fprintf_s(mFile,"connectAttr \"");ecg.write(mFile);fprintf_s(mFile,"\" \"%s.ecg\";\n",mName.c_str());}
	/*Environment color gain red value*/
	void setEnvColorGainR(float ecgr){if(ecgr == 1.0) return; fprintf_s(mFile, "setAttr \".ecg.ecgr\" %f;\n", ecgr);}
	/*Environment color gain red value*/
	void setEnvColorGainR(const FloatID& ecgr){fprintf_s(mFile,"connectAttr \"");ecgr.write(mFile);fprintf_s(mFile,"\" \"%s.ecg.ecgr\";\n",mName.c_str());}
	/*Environment color gain green value*/
	void setEnvColorGainG(float ecgg){if(ecgg == 1.0) return; fprintf_s(mFile, "setAttr \".ecg.ecgg\" %f;\n", ecgg);}
	/*Environment color gain green value*/
	void setEnvColorGainG(const FloatID& ecgg){fprintf_s(mFile,"connectAttr \"");ecgg.write(mFile);fprintf_s(mFile,"\" \"%s.ecg.ecgg\";\n",mName.c_str());}
	/*Environment color gain blue value*/
	void setEnvColorGainB(float ecgb){if(ecgb == 1.0) return; fprintf_s(mFile, "setAttr \".ecg.ecgb\" %f;\n", ecgb);}
	/*Environment color gain blue value*/
	void setEnvColorGainB(const FloatID& ecgb){fprintf_s(mFile,"connectAttr \"");ecgb.write(mFile);fprintf_s(mFile,"\" \"%s.ecg.ecgb\";\n",mName.c_str());}
	/*Color offset for the environment component.*/
	void setEnvColorOffset(const float3& eco){if(eco == float3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".eco\" -type \"float3\" ");eco.write(mFile);fprintf_s(mFile,";\n");}
	/*Color offset for the environment component.*/
	void setEnvColorOffset(const Float3ID& eco){fprintf_s(mFile,"connectAttr \"");eco.write(mFile);fprintf_s(mFile,"\" \"%s.eco\";\n",mName.c_str());}
	/*Environment color offset red value*/
	void setEnvColorOffsetR(float ecor){if(ecor == 0) return; fprintf_s(mFile, "setAttr \".eco.ecor\" %f;\n", ecor);}
	/*Environment color offset red value*/
	void setEnvColorOffsetR(const FloatID& ecor){fprintf_s(mFile,"connectAttr \"");ecor.write(mFile);fprintf_s(mFile,"\" \"%s.eco.ecor\";\n",mName.c_str());}
	/*Environment color offset green value*/
	void setEnvColorOffsetG(float ecog){if(ecog == 0) return; fprintf_s(mFile, "setAttr \".eco.ecog\" %f;\n", ecog);}
	/*Environment color offset green value*/
	void setEnvColorOffsetG(const FloatID& ecog){fprintf_s(mFile,"connectAttr \"");ecog.write(mFile);fprintf_s(mFile,"\" \"%s.eco.ecog\";\n",mName.c_str());}
	/*Environment color offset blue value*/
	void setEnvColorOffsetB(float ecorb){if(ecorb == 0) return; fprintf_s(mFile, "setAttr \".eco.ecorb\" %f;\n", ecorb);}
	/*Environment color offset blue value*/
	void setEnvColorOffsetB(const FloatID& ecorb){fprintf_s(mFile,"connectAttr \"");ecorb.write(mFile);fprintf_s(mFile,"\" \"%s.eco.ecorb\";\n",mName.c_str());}
	/*
	You can adjust IBL contribution per component.
	To adjust the final gather contribution, enable <b>overrideFgColorFx</b>,
	and use fgInvert, fgColorGain, fgColorOffset
	to fine tune the final gather contribution from the IBL texture.
	*/
	void setOverrideFgColorFx(bool offx){if(offx == false) return; fprintf_s(mFile, "setAttr \".offx\" %i;\n", offx);}
	/*Invert the color of IBL texture final gather contribution.*/
	void setFgInvert(bool finv){if(finv == false) return; fprintf_s(mFile, "setAttr \".finv\" %i;\n", finv);}
	/*Color Gain for the final gather contribution.*/
	void setFgColorGain(const float3& fcg){if(fcg == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".fcg\" -type \"float3\" ");fcg.write(mFile);fprintf_s(mFile,";\n");}
	/*Color Gain for the final gather contribution.*/
	void setFgColorGain(const Float3ID& fcg){fprintf_s(mFile,"connectAttr \"");fcg.write(mFile);fprintf_s(mFile,"\" \"%s.fcg\";\n",mName.c_str());}
	/*Final gather color gain red value*/
	void setFgColorGainR(float fcgr){if(fcgr == 1.0) return; fprintf_s(mFile, "setAttr \".fcg.fcgr\" %f;\n", fcgr);}
	/*Final gather color gain red value*/
	void setFgColorGainR(const FloatID& fcgr){fprintf_s(mFile,"connectAttr \"");fcgr.write(mFile);fprintf_s(mFile,"\" \"%s.fcg.fcgr\";\n",mName.c_str());}
	/*Environment color gain green value*/
	void setFgColorGainG(float fcgg){if(fcgg == 1.0) return; fprintf_s(mFile, "setAttr \".fcg.fcgg\" %f;\n", fcgg);}
	/*Environment color gain green value*/
	void setFgColorGainG(const FloatID& fcgg){fprintf_s(mFile,"connectAttr \"");fcgg.write(mFile);fprintf_s(mFile,"\" \"%s.fcg.fcgg\";\n",mName.c_str());}
	/*Environment color gain blue value*/
	void setFgColorGainB(float fcgb){if(fcgb == 1.0) return; fprintf_s(mFile, "setAttr \".fcg.fcgb\" %f;\n", fcgb);}
	/*Environment color gain blue value*/
	void setFgColorGainB(const FloatID& fcgb){fprintf_s(mFile,"connectAttr \"");fcgb.write(mFile);fprintf_s(mFile,"\" \"%s.fcg.fcgb\";\n",mName.c_str());}
	/*Color Offset for the final gather contribution.*/
	void setFgColorOffset(const float3& fco){if(fco == float3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".fco\" -type \"float3\" ");fco.write(mFile);fprintf_s(mFile,";\n");}
	/*Color Offset for the final gather contribution.*/
	void setFgColorOffset(const Float3ID& fco){fprintf_s(mFile,"connectAttr \"");fco.write(mFile);fprintf_s(mFile,"\" \"%s.fco\";\n",mName.c_str());}
	/*Environment color offset red value*/
	void setFgColorOffsetR(float fcor){if(fcor == 0) return; fprintf_s(mFile, "setAttr \".fco.fcor\" %f;\n", fcor);}
	/*Environment color offset red value*/
	void setFgColorOffsetR(const FloatID& fcor){fprintf_s(mFile,"connectAttr \"");fcor.write(mFile);fprintf_s(mFile,"\" \"%s.fco.fcor\";\n",mName.c_str());}
	/*Environment color offset green value*/
	void setFgColorOffsetG(float fcog){if(fcog == 0) return; fprintf_s(mFile, "setAttr \".fco.fcog\" %f;\n", fcog);}
	/*Environment color offset green value*/
	void setFgColorOffsetG(const FloatID& fcog){fprintf_s(mFile,"connectAttr \"");fcog.write(mFile);fprintf_s(mFile,"\" \"%s.fco.fcog\";\n",mName.c_str());}
	/*Environment color offset blue value*/
	void setFgColorOffsetB(float fcob){if(fcob == 0) return; fprintf_s(mFile, "setAttr \".fco.fcob\" %f;\n", fcob);}
	/*Environment color offset blue value*/
	void setFgColorOffsetB(const FloatID& fcob){fprintf_s(mFile,"connectAttr \"");fcob.write(mFile);fprintf_s(mFile,"\" \"%s.fco.fcob\";\n",mName.c_str());}
	/*
	It is possible to emit light from the IBL environment radially towards the origin of world space.
	If light <b>emitLight</b> is turned on,
	the IBL node acts like any of the other true light sources in the scene,
	and emits light from the infinitely distant IBL environment.
	This maps to a mental ray light shader.
	*/
	void setEmitLight(bool el){if(el == false) return; fprintf_s(mFile, "setAttr \".el\" %i;\n", el);}
	/*
	The light shader sets up a "control texture" for light emission.
	Every pixel in that texture corresponds to a directional light.
	<b>filter</b> specifies the texture's resolution.
	Bigger filter creates more directional lights to better match the IBL texture,
	and more render time.
	File textures may be downsampled to the filter resolution,
	procedural textures are sampled at this resolution.
	*/
	void setFilter(const long2& flt){if(flt == long2(256, 256)) return; fprintf_s(mFile, "setAttr \".flt\" -type \"long2\" ");flt.write(mFile);fprintf_s(mFile,";\n");}
	/*The UI name is QualityU*/
	void setFilterU(int fiu){if(fiu == 256) return; fprintf_s(mFile, "setAttr \".flt.fiu\" %i;\n", fiu);}
	/*The UI name is QualityU*/
	void setFilterU(const IntID& fiu){fprintf_s(mFile,"connectAttr \"");fiu.write(mFile);fprintf_s(mFile,"\" \"%s.flt.fiu\";\n",mName.c_str());}
	/*The UI name is QualityV*/
	void setFilterV(int fiv){if(fiv == 256) return; fprintf_s(mFile, "setAttr \".flt.fiv\" %i;\n", fiv);}
	/*The UI name is QualityV*/
	void setFilterV(const IntID& fiv){fprintf_s(mFile,"connectAttr \"");fiv.write(mFile);fprintf_s(mFile,"\" \"%s.flt.fiv\";\n",mName.c_str());}
	/*
	Sampling all directional lights represented by the control texture is often prohibitively expensive.
	Therefore the shader has a built-in importance mechanism
	that attempts to select the "most important" lights.
	The first Samples parameter specifies the number of important lights that must be sampled.
	The second parameter quasi-randomly selects a certain number of remaining lights.
	The product of filterU and filterV should always be
	larger than or equal to the sum of the two Samples parameters.
	<b>samples</b> parameters larger than the product are clamped.
	*/
	void setSamples(const long2& smp){if(smp == long2(40, 16)) return; fprintf_s(mFile, "setAttr \".smp\" -type \"long2\" ");smp.write(mFile);fprintf_s(mFile,";\n");}
	/*U component of samples.*/
	void setSamplesU(int smpu){if(smpu == 40) return; fprintf_s(mFile, "setAttr \".smp.smpu\" %i;\n", smpu);}
	/*U component of samples.*/
	void setSamplesU(const IntID& smpu){fprintf_s(mFile,"connectAttr \"");smpu.write(mFile);fprintf_s(mFile,"\" \"%s.smp.smpu\";\n",mName.c_str());}
	/*V component of samples.*/
	void setSamplesV(int smpv){if(smpv == 16) return; fprintf_s(mFile, "setAttr \".smp.smpv\" %i;\n", smpv);}
	/*V component of samples.*/
	void setSamplesV(const IntID& smpv){fprintf_s(mFile,"connectAttr \"");smpv.write(mFile);fprintf_s(mFile,"\" \"%s.smp.smpv\";\n",mName.c_str());}
	/*
	<b>lowSamples</b> specifies the number of light samples
	taken from IBL during final gathering.
	1/8th of the regular samples is a good starting point.
	*/
	void setLowSamples(const long2& low){if(low == long2(5, 2)) return; fprintf_s(mFile, "setAttr \".low\" -type \"long2\" ");low.write(mFile);fprintf_s(mFile,";\n");}
	/*U component of lowSamples.*/
	void setLowSamplesU(int lowu){if(lowu == 5) return; fprintf_s(mFile, "setAttr \".low.lowu\" %i;\n", lowu);}
	/*U component of lowSamples.*/
	void setLowSamplesU(const IntID& lowu){fprintf_s(mFile,"connectAttr \"");lowu.write(mFile);fprintf_s(mFile,"\" \"%s.low.lowu\";\n",mName.c_str());}
	/*V component of lowSamples.*/
	void setLowSamplesV(int lowv){if(lowv == 2) return; fprintf_s(mFile, "setAttr \".low.lowv\" %i;\n", lowv);}
	/*V component of lowSamples.*/
	void setLowSamplesV(const IntID& lowv){fprintf_s(mFile,"connectAttr \"");lowv.write(mFile);fprintf_s(mFile,"\" \"%s.low.lowv\";\n",mName.c_str());}
	/*
	Each pixel in the control texture maps to a location on the environment sphere
	to determine the direction of its associated virtual directional light.
	Turning on <b>jitter</b> quasi-randomly jitters that direction and thus improves quality.
	*/
	void setJitter(float jit){if(jit == 0.8) return; fprintf_s(mFile, "setAttr \".jit\" %f;\n", jit);}
	/*
	If lights on the backside of surfaces do not contribute to the surfaces' illumination
	(i.e. there is no translucency in the scene), you turn <b>skipBack</b> on.
	It aids the importance sampling a lot.
	*/
	void setSkipBack(bool skb){if(skb == true) return; fprintf_s(mFile, "setAttr \".skb\" %i;\n", skb);}
	/*Determine if this light contributes to the diffuse shading.*/
	void setEmitDiffuse(bool emdf){if(emdf == true) return; fprintf_s(mFile, "setAttr \".emdf\" %i;\n", emdf);}
	/*Determine if this light contributes to the specular shading.*/
	void setEmitSpecular(bool emsp){if(emsp == true) return; fprintf_s(mFile, "setAttr \".emsp\" %i;\n", emsp);}
	/*Do I ray trace my shadows?*/
	void setUseRayTraceShadows(bool rts){if(rts == true) return; fprintf_s(mFile, "setAttr \".rts\" %i;\n", rts);}
	/*The input shadow color.*/
	void setShadowColor(const float3& shc){if(shc == float3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".shc\" -type \"float3\" ");shc.write(mFile);fprintf_s(mFile,";\n");}
	/*The input shadow color.*/
	void setShadowColor(const Float3ID& shc){fprintf_s(mFile,"connectAttr \"");shc.write(mFile);fprintf_s(mFile,"\" \"%s.shc\";\n",mName.c_str());}
	/*Shadow color red value*/
	void setShadowColorR(float shcr){if(shcr == 0) return; fprintf_s(mFile, "setAttr \".shc.shcr\" %f;\n", shcr);}
	/*Shadow color red value*/
	void setShadowColorR(const FloatID& shcr){fprintf_s(mFile,"connectAttr \"");shcr.write(mFile);fprintf_s(mFile,"\" \"%s.shc.shcr\";\n",mName.c_str());}
	/*Shadow color green value*/
	void setShadowColorG(float shcg){if(shcg == 0) return; fprintf_s(mFile, "setAttr \".shc.shcg\" %f;\n", shcg);}
	/*Shadow color green value*/
	void setShadowColorG(const FloatID& shcg){fprintf_s(mFile,"connectAttr \"");shcg.write(mFile);fprintf_s(mFile,"\" \"%s.shc.shcg\";\n",mName.c_str());}
	/*Shadow color blue value*/
	void setShadowColorB(float shcb){if(shcb == 0) return; fprintf_s(mFile, "setAttr \".shc.shcb\" %f;\n", shcb);}
	/*Shadow color blue value*/
	void setShadowColorB(const FloatID& shcb){fprintf_s(mFile,"connectAttr \"");shcb.write(mFile);fprintf_s(mFile,"\" \"%s.shc.shcb\";\n",mName.c_str());}
	/*max ray depth allowed*/
	void setRayDepthLimit(int rdl){if(rdl == 2) return; fprintf_s(mFile, "setAttr \".rdl\" %i;\n", rdl);}
	/*
	You can adjust IBL contribution per component.
	To adjust the light color, enable <b>overrideLightColorFx</b>,
	and use lightInvert, lightColorGain, lightColorOffset to fine tune the contribution.
	*/
	void setOverrideLightColorFx(bool olfx){if(olfx == false) return; fprintf_s(mFile, "setAttr \".olfx\" %i;\n", olfx);}
	/*Invert the IBL light color.*/
	void setLightInvert(bool linv){if(linv == false) return; fprintf_s(mFile, "setAttr \".linv\" %i;\n", linv);}
	/*Color Gain for the IBL light color.*/
	void setLightColorGain(const float3& lcg){if(lcg == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".lcg\" -type \"float3\" ");lcg.write(mFile);fprintf_s(mFile,";\n");}
	/*Color Gain for the IBL light color.*/
	void setLightColorGain(const Float3ID& lcg){fprintf_s(mFile,"connectAttr \"");lcg.write(mFile);fprintf_s(mFile,"\" \"%s.lcg\";\n",mName.c_str());}
	/*Light color gain red component.*/
	void setLightColorGainR(float lcgr){if(lcgr == 1.0) return; fprintf_s(mFile, "setAttr \".lcg.lcgr\" %f;\n", lcgr);}
	/*Light color gain red component.*/
	void setLightColorGainR(const FloatID& lcgr){fprintf_s(mFile,"connectAttr \"");lcgr.write(mFile);fprintf_s(mFile,"\" \"%s.lcg.lcgr\";\n",mName.c_str());}
	/*Light color gain green component.*/
	void setLightColorGainG(float lcgg){if(lcgg == 1.0) return; fprintf_s(mFile, "setAttr \".lcg.lcgg\" %f;\n", lcgg);}
	/*Light color gain green component.*/
	void setLightColorGainG(const FloatID& lcgg){fprintf_s(mFile,"connectAttr \"");lcgg.write(mFile);fprintf_s(mFile,"\" \"%s.lcg.lcgg\";\n",mName.c_str());}
	/*Light color gain blue component.*/
	void setLightColorGainB(float lcgb){if(lcgb == 1.0) return; fprintf_s(mFile, "setAttr \".lcg.lcgb\" %f;\n", lcgb);}
	/*Light color gain blue component.*/
	void setLightColorGainB(const FloatID& lcgb){fprintf_s(mFile,"connectAttr \"");lcgb.write(mFile);fprintf_s(mFile,"\" \"%s.lcg.lcgb\";\n",mName.c_str());}
	/*Color Offset for the IBL light color.*/
	void setLightColorOffset(const float3& lco){if(lco == float3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".lco\" -type \"float3\" ");lco.write(mFile);fprintf_s(mFile,";\n");}
	/*Color Offset for the IBL light color.*/
	void setLightColorOffset(const Float3ID& lco){fprintf_s(mFile,"connectAttr \"");lco.write(mFile);fprintf_s(mFile,"\" \"%s.lco\";\n",mName.c_str());}
	/*Light color offset red component.*/
	void setLightColorOffsetR(float lcor){if(lcor == 0) return; fprintf_s(mFile, "setAttr \".lco.lcor\" %f;\n", lcor);}
	/*Light color offset red component.*/
	void setLightColorOffsetR(const FloatID& lcor){fprintf_s(mFile,"connectAttr \"");lcor.write(mFile);fprintf_s(mFile,"\" \"%s.lco.lcor\";\n",mName.c_str());}
	/*Light color offset green component.*/
	void setLightColorOffsetG(float lcog){if(lcog == 0) return; fprintf_s(mFile, "setAttr \".lco.lcog\" %f;\n", lcog);}
	/*Light color offset green component.*/
	void setLightColorOffsetG(const FloatID& lcog){fprintf_s(mFile,"connectAttr \"");lcog.write(mFile);fprintf_s(mFile,"\" \"%s.lco.lcog\";\n",mName.c_str());}
	/*Light color offset blue component.*/
	void setLightColorOffsetB(float lcob){if(lcob == 0) return; fprintf_s(mFile, "setAttr \".lco.lcob\" %f;\n", lcob);}
	/*Light color offset blue component.*/
	void setLightColorOffsetB(const FloatID& lcob){fprintf_s(mFile,"connectAttr \"");lcob.write(mFile);fprintf_s(mFile,"\" \"%s.lco.lcob\";\n",mName.c_str());}
	/*
	photons may be emitted from the IBL environment sphere.
	This requires Global Illumination and/or Caustic photons to be turned on the Render Settings.
	The emission direction is chosen quasi-randomly for individual photons.
	Similar to light emission, a photon picks up the color corresponding
	to its emission direction from the IBL texture (file or procedural),
	possibly adjusted by color gain and offset.
	This maps to a mental ray photon emission shader.
	Turn <b>emitPhotons</b> on, if you want to emit photons from the infinitely distant IBL environment.
	*/
	void setEmitPhotons(bool ep){if(ep == false) return; fprintf_s(mFile, "setAttr \".ep\" %i;\n", ep);}
	/*Determines how many global illumination photons are emitted.*/
	void setGlobillumPhotons(int giph){if(giph == 25000) return; fprintf_s(mFile, "setAttr \".giph\" %i;\n", giph);}
	/*Determines how many caustic photons are emitted.*/
	void setCausticPhotons(int caph){if(caph == 15000) return; fprintf_s(mFile, "setAttr \".caph\" %i;\n", caph);}
	/*Determines the exponent used for photon emission.*/
	void setExponent(float exp){if(exp == 2.0) return; fprintf_s(mFile, "setAttr \".exp\" %f;\n", exp);}
	/*
	If off, photons will be stored on first hit.
	This is useful if IBL is to be achieved using global illumination photons alone.
	In terms of a real environment you can think of this switch
	as photons from the Sun being scattered in the atmosphere before reaching any surface.
	Turn this option on, if you are emitting caustic photons,
	or if you are emitting light in combination with photons.
	*/
	void setStandardEmission(bool se){if(se == false) return; fprintf_s(mFile, "setAttr \".se\" %i;\n", se);}
	/*
	You can adjust IBL contribution per component.
	To adjust the photon color, enable <b>overridePhotonColorFx</b>,
	and use photonInvert, photonColorGain, photonColorOffset to fine tune the contribution.
	*/
	void setOverridePhotonColorFx(bool opfx){if(opfx == false) return; fprintf_s(mFile, "setAttr \".opfx\" %i;\n", opfx);}
	/*Invert the IBL photon color.*/
	void setPhotonInvert(bool pinv){if(pinv == false) return; fprintf_s(mFile, "setAttr \".pinv\" %i;\n", pinv);}
	/*Color Gain for the IBL photon color.*/
	void setPhotonColorGain(const float3& pcg){if(pcg == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".pcg\" -type \"float3\" ");pcg.write(mFile);fprintf_s(mFile,";\n");}
	/*Color Gain for the IBL photon color.*/
	void setPhotonColorGain(const Float3ID& pcg){fprintf_s(mFile,"connectAttr \"");pcg.write(mFile);fprintf_s(mFile,"\" \"%s.pcg\";\n",mName.c_str());}
	/*Photon color gain red component.*/
	void setPhotonColorGainR(float pcgr){if(pcgr == 1.0) return; fprintf_s(mFile, "setAttr \".pcg.pcgr\" %f;\n", pcgr);}
	/*Photon color gain red component.*/
	void setPhotonColorGainR(const FloatID& pcgr){fprintf_s(mFile,"connectAttr \"");pcgr.write(mFile);fprintf_s(mFile,"\" \"%s.pcg.pcgr\";\n",mName.c_str());}
	/*Photon color gain green component.*/
	void setPhotonColorGainG(float pcgg){if(pcgg == 1.0) return; fprintf_s(mFile, "setAttr \".pcg.pcgg\" %f;\n", pcgg);}
	/*Photon color gain green component.*/
	void setPhotonColorGainG(const FloatID& pcgg){fprintf_s(mFile,"connectAttr \"");pcgg.write(mFile);fprintf_s(mFile,"\" \"%s.pcg.pcgg\";\n",mName.c_str());}
	/*Photon color gain blue component.*/
	void setPhotonColorGainB(float pcgb){if(pcgb == 1.0) return; fprintf_s(mFile, "setAttr \".pcg.pcgb\" %f;\n", pcgb);}
	/*Photon color gain blue component.*/
	void setPhotonColorGainB(const FloatID& pcgb){fprintf_s(mFile,"connectAttr \"");pcgb.write(mFile);fprintf_s(mFile,"\" \"%s.pcg.pcgb\";\n",mName.c_str());}
	/*Color Offset for the IBL photon color.*/
	void setPhotonColorOffset(const float3& pco){if(pco == float3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".pco\" -type \"float3\" ");pco.write(mFile);fprintf_s(mFile,";\n");}
	/*Color Offset for the IBL photon color.*/
	void setPhotonColorOffset(const Float3ID& pco){fprintf_s(mFile,"connectAttr \"");pco.write(mFile);fprintf_s(mFile,"\" \"%s.pco\";\n",mName.c_str());}
	/*Photon color offset red component.*/
	void setPhotonColorOffsetR(float pcor){if(pcor == 0) return; fprintf_s(mFile, "setAttr \".pco.pcor\" %f;\n", pcor);}
	/*Photon color offset red component.*/
	void setPhotonColorOffsetR(const FloatID& pcor){fprintf_s(mFile,"connectAttr \"");pcor.write(mFile);fprintf_s(mFile,"\" \"%s.pco.pcor\";\n",mName.c_str());}
	/*Photon color offset green component.*/
	void setPhotonColorOffsetG(float pcog){if(pcog == 0) return; fprintf_s(mFile, "setAttr \".pco.pcog\" %f;\n", pcog);}
	/*Photon color offset green component.*/
	void setPhotonColorOffsetG(const FloatID& pcog){fprintf_s(mFile,"connectAttr \"");pcog.write(mFile);fprintf_s(mFile,"\" \"%s.pco.pcog\";\n",mName.c_str());}
	/*Photon color offset blue component.*/
	void setPhotonColorOffsetB(float pcob){if(pcob == 0) return; fprintf_s(mFile, "setAttr \".pco.pcob\" %f;\n", pcob);}
	/*Photon color offset blue component.*/
	void setPhotonColorOffsetB(const FloatID& pcob){fprintf_s(mFile,"connectAttr \"");pcob.write(mFile);fprintf_s(mFile,"\" \"%s.pco.pcob\";\n",mName.c_str());}
	/*The frame extension.*/
	IntID getFrameExtension(){char buffer[4096];sprintf_s (buffer, "%s.fe",mName.c_str());return (const char*)buffer;}
	/*If <b>Type</b> is Procedural, hook up a 2D texture shader here.*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.col",mName.c_str());return (const char*)buffer;}
	/*Alpha component of 2d texture.*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.col.colr",mName.c_str());return (const char*)buffer;}
	/*Green component of 2d texture.*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.col.colg",mName.c_str());return (const char*)buffer;}
	/*Blue component of 2d texture.*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.col.colb",mName.c_str());return (const char*)buffer;}
	/*
	Use <b>Color Gain</b> to fine-tune the balance of a texture's Out Color.
	Color Gain is applied as a multiplier to the texture's color.
	If Color Gain is white, it has no effect.
	Reducing the amount of red (for example) in Color Gain will scale down the amount of red in the final output color.
	*/
	Float3ID getColorGain(){char buffer[4096];sprintf_s (buffer, "%s.cg",mName.c_str());return (const char*)buffer;}
	/*Color Gain Red Value*/
	FloatID getColorGainR(){char buffer[4096];sprintf_s (buffer, "%s.cg.cgr",mName.c_str());return (const char*)buffer;}
	/*Color Gain Green Value*/
	FloatID getColorGainG(){char buffer[4096];sprintf_s (buffer, "%s.cg.cgg",mName.c_str());return (const char*)buffer;}
	/*Color Gain Blue Value*/
	FloatID getColorGainB(){char buffer[4096];sprintf_s (buffer, "%s.cg.cgb",mName.c_str());return (const char*)buffer;}
	/*
	Use <b>Color Offset</b> to brighten and adjust a texture's Out Color.
	Unlike Color Gain (which is a multiplier), Color Offset is simply added to the texture's Out Color.
	Therefore if Color Offset is black, it has no effect.
	Increasing the amount of red (for example) in Color Offset
	will uniformly increase the amount of red in the final output color.
	*/
	Float3ID getColorOffset(){char buffer[4096];sprintf_s (buffer, "%s.cof",mName.c_str());return (const char*)buffer;}
	/*Color Offset Red Value*/
	FloatID getColorOffsetR(){char buffer[4096];sprintf_s (buffer, "%s.cof.cofr",mName.c_str());return (const char*)buffer;}
	/*Color Offset Green Value*/
	FloatID getColorOffsetG(){char buffer[4096];sprintf_s (buffer, "%s.cof.cofg",mName.c_str());return (const char*)buffer;}
	/*Color Offset Blue Value*/
	FloatID getColorOffsetB(){char buffer[4096];sprintf_s (buffer, "%s.cof.cofb",mName.c_str());return (const char*)buffer;}
	/*Color Gain for the environment component.*/
	Float3ID getEnvColorGain(){char buffer[4096];sprintf_s (buffer, "%s.ecg",mName.c_str());return (const char*)buffer;}
	/*Environment color gain red value*/
	FloatID getEnvColorGainR(){char buffer[4096];sprintf_s (buffer, "%s.ecg.ecgr",mName.c_str());return (const char*)buffer;}
	/*Environment color gain green value*/
	FloatID getEnvColorGainG(){char buffer[4096];sprintf_s (buffer, "%s.ecg.ecgg",mName.c_str());return (const char*)buffer;}
	/*Environment color gain blue value*/
	FloatID getEnvColorGainB(){char buffer[4096];sprintf_s (buffer, "%s.ecg.ecgb",mName.c_str());return (const char*)buffer;}
	/*Color offset for the environment component.*/
	Float3ID getEnvColorOffset(){char buffer[4096];sprintf_s (buffer, "%s.eco",mName.c_str());return (const char*)buffer;}
	/*Environment color offset red value*/
	FloatID getEnvColorOffsetR(){char buffer[4096];sprintf_s (buffer, "%s.eco.ecor",mName.c_str());return (const char*)buffer;}
	/*Environment color offset green value*/
	FloatID getEnvColorOffsetG(){char buffer[4096];sprintf_s (buffer, "%s.eco.ecog",mName.c_str());return (const char*)buffer;}
	/*Environment color offset blue value*/
	FloatID getEnvColorOffsetB(){char buffer[4096];sprintf_s (buffer, "%s.eco.ecorb",mName.c_str());return (const char*)buffer;}
	/*Color Gain for the final gather contribution.*/
	Float3ID getFgColorGain(){char buffer[4096];sprintf_s (buffer, "%s.fcg",mName.c_str());return (const char*)buffer;}
	/*Final gather color gain red value*/
	FloatID getFgColorGainR(){char buffer[4096];sprintf_s (buffer, "%s.fcg.fcgr",mName.c_str());return (const char*)buffer;}
	/*Environment color gain green value*/
	FloatID getFgColorGainG(){char buffer[4096];sprintf_s (buffer, "%s.fcg.fcgg",mName.c_str());return (const char*)buffer;}
	/*Environment color gain blue value*/
	FloatID getFgColorGainB(){char buffer[4096];sprintf_s (buffer, "%s.fcg.fcgb",mName.c_str());return (const char*)buffer;}
	/*Color Offset for the final gather contribution.*/
	Float3ID getFgColorOffset(){char buffer[4096];sprintf_s (buffer, "%s.fco",mName.c_str());return (const char*)buffer;}
	/*Environment color offset red value*/
	FloatID getFgColorOffsetR(){char buffer[4096];sprintf_s (buffer, "%s.fco.fcor",mName.c_str());return (const char*)buffer;}
	/*Environment color offset green value*/
	FloatID getFgColorOffsetG(){char buffer[4096];sprintf_s (buffer, "%s.fco.fcog",mName.c_str());return (const char*)buffer;}
	/*Environment color offset blue value*/
	FloatID getFgColorOffsetB(){char buffer[4096];sprintf_s (buffer, "%s.fco.fcob",mName.c_str());return (const char*)buffer;}
	/*The UI name is QualityU*/
	IntID getFilterU(){char buffer[4096];sprintf_s (buffer, "%s.flt.fiu",mName.c_str());return (const char*)buffer;}
	/*The UI name is QualityV*/
	IntID getFilterV(){char buffer[4096];sprintf_s (buffer, "%s.flt.fiv",mName.c_str());return (const char*)buffer;}
	/*U component of samples.*/
	IntID getSamplesU(){char buffer[4096];sprintf_s (buffer, "%s.smp.smpu",mName.c_str());return (const char*)buffer;}
	/*V component of samples.*/
	IntID getSamplesV(){char buffer[4096];sprintf_s (buffer, "%s.smp.smpv",mName.c_str());return (const char*)buffer;}
	/*U component of lowSamples.*/
	IntID getLowSamplesU(){char buffer[4096];sprintf_s (buffer, "%s.low.lowu",mName.c_str());return (const char*)buffer;}
	/*V component of lowSamples.*/
	IntID getLowSamplesV(){char buffer[4096];sprintf_s (buffer, "%s.low.lowv",mName.c_str());return (const char*)buffer;}
	/*The input shadow color.*/
	Float3ID getShadowColor(){char buffer[4096];sprintf_s (buffer, "%s.shc",mName.c_str());return (const char*)buffer;}
	/*Shadow color red value*/
	FloatID getShadowColorR(){char buffer[4096];sprintf_s (buffer, "%s.shc.shcr",mName.c_str());return (const char*)buffer;}
	/*Shadow color green value*/
	FloatID getShadowColorG(){char buffer[4096];sprintf_s (buffer, "%s.shc.shcg",mName.c_str());return (const char*)buffer;}
	/*Shadow color blue value*/
	FloatID getShadowColorB(){char buffer[4096];sprintf_s (buffer, "%s.shc.shcb",mName.c_str());return (const char*)buffer;}
	/*Color Gain for the IBL light color.*/
	Float3ID getLightColorGain(){char buffer[4096];sprintf_s (buffer, "%s.lcg",mName.c_str());return (const char*)buffer;}
	/*Light color gain red component.*/
	FloatID getLightColorGainR(){char buffer[4096];sprintf_s (buffer, "%s.lcg.lcgr",mName.c_str());return (const char*)buffer;}
	/*Light color gain green component.*/
	FloatID getLightColorGainG(){char buffer[4096];sprintf_s (buffer, "%s.lcg.lcgg",mName.c_str());return (const char*)buffer;}
	/*Light color gain blue component.*/
	FloatID getLightColorGainB(){char buffer[4096];sprintf_s (buffer, "%s.lcg.lcgb",mName.c_str());return (const char*)buffer;}
	/*Color Offset for the IBL light color.*/
	Float3ID getLightColorOffset(){char buffer[4096];sprintf_s (buffer, "%s.lco",mName.c_str());return (const char*)buffer;}
	/*Light color offset red component.*/
	FloatID getLightColorOffsetR(){char buffer[4096];sprintf_s (buffer, "%s.lco.lcor",mName.c_str());return (const char*)buffer;}
	/*Light color offset green component.*/
	FloatID getLightColorOffsetG(){char buffer[4096];sprintf_s (buffer, "%s.lco.lcog",mName.c_str());return (const char*)buffer;}
	/*Light color offset blue component.*/
	FloatID getLightColorOffsetB(){char buffer[4096];sprintf_s (buffer, "%s.lco.lcob",mName.c_str());return (const char*)buffer;}
	/*Color Gain for the IBL photon color.*/
	Float3ID getPhotonColorGain(){char buffer[4096];sprintf_s (buffer, "%s.pcg",mName.c_str());return (const char*)buffer;}
	/*Photon color gain red component.*/
	FloatID getPhotonColorGainR(){char buffer[4096];sprintf_s (buffer, "%s.pcg.pcgr",mName.c_str());return (const char*)buffer;}
	/*Photon color gain green component.*/
	FloatID getPhotonColorGainG(){char buffer[4096];sprintf_s (buffer, "%s.pcg.pcgg",mName.c_str());return (const char*)buffer;}
	/*Photon color gain blue component.*/
	FloatID getPhotonColorGainB(){char buffer[4096];sprintf_s (buffer, "%s.pcg.pcgb",mName.c_str());return (const char*)buffer;}
	/*Color Offset for the IBL photon color.*/
	Float3ID getPhotonColorOffset(){char buffer[4096];sprintf_s (buffer, "%s.pco",mName.c_str());return (const char*)buffer;}
	/*Photon color offset red component.*/
	FloatID getPhotonColorOffsetR(){char buffer[4096];sprintf_s (buffer, "%s.pco.pcor",mName.c_str());return (const char*)buffer;}
	/*Photon color offset green component.*/
	FloatID getPhotonColorOffsetG(){char buffer[4096];sprintf_s (buffer, "%s.pco.pcog",mName.c_str());return (const char*)buffer;}
	/*Photon color offset blue component.*/
	FloatID getPhotonColorOffsetB(){char buffer[4096];sprintf_s (buffer, "%s.pco.pcob",mName.c_str());return (const char*)buffer;}
protected:
	MentalrayIblShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):mFile(file), mName(name), mParent(parent), mNodeType(nodeType){createNode();}
private:
	void createNode(){fprintf_s(mFile, "createNode %s -n \"%s\"", mNodeType.c_str(),mName.c_str());if(mParent != "") fprintf_s(mFile, " -p \"%s\"", mParent.c_str());fprintf_s(mFile, ";\n");}

};
}//namespace MayaDM
#endif//__MayaDM_MENTALRAYIBLSHAPE_H__
