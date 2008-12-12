/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_USEBACKGROUND_H__
#define __MayaDM_USEBACKGROUND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The <b>Use Background</b> shader allows you to mix computer-generated
 objects with scanned images in a seamless way.  An object with a
 Use Background shader does not show up in the scene;  wherever that
 material is, you just see the background image of the scene.  However,
 shadows can fall on the material, and if it is made shiny, it can
 reflect other computer-generated objects.
 <p/>
 For example, let's say you scan in a picture of a tree, and put
 that on an image plane.  You can then create a tube to "stand in"
 for this tree in the scene.  Position it so that it lines up with
 the tree, and assign a Use Background shader to it.  When you render,
 you will not see the tube.  Rather, you will see the tree in the
 background image.  But if a computer-generated object should cast
 a shadow on the tube, it will appear to be cast on the tree.  And
 if a computer-generated object should pass behind the tube, it
 will sppear to be passing behind the tree in the background image.
 <p/>
 In the table below, important attributes have their names indicated
 in <b>bold</b> in the description column.
*/
class UseBackground : public DependNode
{
public:
public:
	UseBackground(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "useBackground"){}
	virtual ~UseBackground(){}
	/*output color*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*outColor red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*outColor green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*outColor blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*output Transparency*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*outTransparency R value*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*outTransparency G value*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*outTransparency B value*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*surface intersection point in camera space*/
	void setPointCamera(const Float3ID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*point camera X value*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.pc.px\";\n",mName.c_str());}
	/*point camera Y value*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.pc.py\";\n",mName.c_str());}
	/*point camera Z value*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pz\";\n",mName.c_str());}
	/*
	<b>Normal Camera</b> represents the surface normals in the
	camera's space. (These are
	used to calculate shading.)<p/>To do Bump Mapping, connect the output of a bump
	node to this attribute.
	*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*normal camera x value*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*normal camera Y value*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*normal camera Z value*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*
	shadow attenuation. If less than 1.0, it makes the shadows appear
	dimmer.  At a value of 0, the shadows are not visible.
	*/
	void setShadowMask(float sm){if(sm == 1.0) return; fprintf_s(mFile, "setAttr \".sm\" %f;\n", sm);}
	/*
	shadow attenuation. If less than 1.0, it makes the shadows appear
	dimmer.  At a value of 0, the shadows are not visible.
	*/
	void setShadowMask(const FloatID& sm){fprintf_s(mFile,"connectAttr \"");sm.write(mFile);fprintf_s(mFile,"\" \"%s.sm\";\n",mName.c_str());}
	/*reflected ray depth limit*/
	void setReflectionLimit(short fll){if(fll == 2) return; fprintf_s(mFile, "setAttr \".fll\" %i;\n", fll);}
	/*reflected ray depth limit*/
	void setReflectionLimit(const ShortID& fll){fprintf_s(mFile,"connectAttr \"");fll.write(mFile);fprintf_s(mFile,"\" \"%s.fll\";\n",mName.c_str());}
	/*
	<b>Specular Color</b> is the color of the specular reflections
	(also called 'hot spots') on the material.  The final color
	of a specular reflection is a combination of the Specular Color
	and the color of the light.
	<p/>By making the Specular Color brighter or dimmer, you can control
	the brightness of the specular reflections on an object.
	<p/>
	<i>Tip:</i> To make a material look more plastic, use white for the specular
	color.  To make a material look more metallic, make the specular
	color similar to the surface color.
	*/
	void setSpecularColor(const float3& sc){fprintf_s(mFile, "setAttr \".sc\" -type \"float3\" ");sc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Specular Color</b> is the color of the specular reflections
	(also called 'hot spots') on the material.  The final color
	of a specular reflection is a combination of the Specular Color
	and the color of the light.
	<p/>By making the Specular Color brighter or dimmer, you can control
	the brightness of the specular reflections on an object.
	<p/>
	<i>Tip:</i> To make a material look more plastic, use white for the specular
	color.  To make a material look more metallic, make the specular
	color similar to the surface color.
	*/
	void setSpecularColor(const Float3ID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*specular color red value*/
	void setSpecularColorR(float sr){if(sr == 0.5) return; fprintf_s(mFile, "setAttr \".sc.sr\" %f;\n", sr);}
	/*specular color red value*/
	void setSpecularColorR(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sc.sr\";\n",mName.c_str());}
	/*specular color green value*/
	void setSpecularColorG(float sg){if(sg == 0.5) return; fprintf_s(mFile, "setAttr \".sc.sg\" %f;\n", sg);}
	/*specular color green value*/
	void setSpecularColorG(const FloatID& sg){fprintf_s(mFile,"connectAttr \"");sg.write(mFile);fprintf_s(mFile,"\" \"%s.sc.sg\";\n",mName.c_str());}
	/*specular color blue value*/
	void setSpecularColorB(float sb){if(sb == 0.5) return; fprintf_s(mFile, "setAttr \".sc.sb\" %f;\n", sb);}
	/*specular color blue value*/
	void setSpecularColorB(const FloatID& sb){fprintf_s(mFile,"connectAttr \"");sb.write(mFile);fprintf_s(mFile,"\" \"%s.sc.sb\";\n",mName.c_str());}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
	<p/>
	This attribute is only meaningful if there is a reflection map, or
	if you are doing Ray Tracing.
	<p/>
	Here are some useful values for Reflectivity:
	<ul>
	Car Paint: 0.4<br/>
	Glass: 0.7<br/>
	Mirror: 1.0<br/>
	Chrome: 1.0
	</ul>
	<p/>
	<i>Note:</i> If you are doing Ray Tracing, and you want
	other objects in the scene to be seen in reflections, then
	you must turn on the Visible In Reflections attribute of
	those objects.
	*/
	void setReflectivity(float rfl){if(rfl == 0.5) return; fprintf_s(mFile, "setAttr \".rfl\" %f;\n", rfl);}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
	<p/>
	This attribute is only meaningful if there is a reflection map, or
	if you are doing Ray Tracing.
	<p/>
	Here are some useful values for Reflectivity:
	<ul>
	Car Paint: 0.4<br/>
	Glass: 0.7<br/>
	Mirror: 1.0<br/>
	Chrome: 1.0
	</ul>
	<p/>
	<i>Note:</i> If you are doing Ray Tracing, and you want
	other objects in the scene to be seen in reflections, then
	you must turn on the Visible In Reflections attribute of
	those objects.
	*/
	void setReflectivity(const FloatID& rfl){fprintf_s(mFile,"connectAttr \"");rfl.write(mFile);fprintf_s(mFile,"\" \"%s.rfl\";\n",mName.c_str());}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	</ul>
	*/
	void setMatteOpacityMode(unsigned int mom){if(mom == 2) return; fprintf_s(mFile, "setAttr \".mom\" %i;\n", mom);}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	</ul>
	*/
	void setMatteOpacityMode(const UnsignedintID& mom){fprintf_s(mFile,"connectAttr \"");mom.write(mFile);fprintf_s(mFile,"\" \"%s.mom\";\n",mName.c_str());}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(float mog){if(mog == 1.0) return; fprintf_s(mFile, "setAttr \".mog\" %f;\n", mog);}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(const FloatID& mog){fprintf_s(mFile,"connectAttr \"");mog.write(mFile);fprintf_s(mFile,"\" \"%s.mog\";\n",mName.c_str());}
	/*output Matte Opacity*/
	void setOutMatteOpacity(const Float3ID& omo){fprintf_s(mFile,"connectAttr \"");omo.write(mFile);fprintf_s(mFile,"\" \"%s.omo\";\n",mName.c_str());}
	/*output Matte Opacity red value*/
	void setOutMatteOpacityR(const FloatID& omor){fprintf_s(mFile,"connectAttr \"");omor.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omor\";\n",mName.c_str());}
	/*output Matte Opacity green value*/
	void setOutMatteOpacityG(const FloatID& omog){fprintf_s(mFile,"connectAttr \"");omog.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omog\";\n",mName.c_str());}
	/*output Matte Opacity blue value*/
	void setOutMatteOpacityB(const FloatID& omob){fprintf_s(mFile,"connectAttr \"");omob.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omob\";\n",mName.c_str());}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a ray's direction is not exactly determined anymore.
	It may deviate (randomly) from the perfect specular direction,
	within the bounds specified by <b>miReflectionBlur</b> (in angle).
	A value of zero implies a perfectly specular interaction,
	a value of 90 a perfectly diffuse reflection or refraction.
	Values of 10 to 30 are a good starting point
	*/
	void setMiReflectionBlur(float mircb){if(mircb == 0) return; fprintf_s(mFile, "setAttr \".mircb\" %f;\n", mircb);}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a ray's direction is not exactly determined anymore.
	It may deviate (randomly) from the perfect specular direction,
	within the bounds specified by <b>miReflectionBlur</b> (in angle).
	A value of zero implies a perfectly specular interaction,
	a value of 90 a perfectly diffuse reflection or refraction.
	Values of 10 to 30 are a good starting point
	*/
	void setMiReflectionBlur(const FloatID& mircb){fprintf_s(mFile,"connectAttr \"");mircb.write(mFile);fprintf_s(mFile,"\" \"%s.mircb\";\n",mName.c_str());}
	/*
	Number of reflection rays to use for blurring.
	<b>miReflectionRays</b> specifies number of rays to use
	to sample the random deviation. In general more rays are required
	for more blurry reflections or refractions.
	Other sampling parameters also affect this setting:
	per-object samples and the Render Settings sample setting supersample in image space.
	If you increase any of these two settings,
	you may be able to reduce the number of rays without loss of quality,
	but significant performance gain.
	*/
	void setMiReflectionRays(short mircr){if(mircr == 1) return; fprintf_s(mFile, "setAttr \".mircr\" %i;\n", mircr);}
	/*
	Number of reflection rays to use for blurring.
	<b>miReflectionRays</b> specifies number of rays to use
	to sample the random deviation. In general more rays are required
	for more blurry reflections or refractions.
	Other sampling parameters also affect this setting:
	per-object samples and the Render Settings sample setting supersample in image space.
	If you increase any of these two settings,
	you may be able to reduce the number of rays without loss of quality,
	but significant performance gain.
	*/
	void setMiReflectionRays(const ShortID& mircr){fprintf_s(mFile,"connectAttr \"");mircr.write(mFile);fprintf_s(mFile,"\" \"%s.mircr\";\n",mName.c_str());}
	/*
	Derive photon shader parameters from the shading node if enabled,
	otherwise use explicit mental ray attributes.
	*/
	void setMiDeriveFromMaya(bool mifm){if(mifm == true) return; fprintf_s(mFile, "setAttr \".mifm\" %i;\n", mifm);}
	/*
	Derive photon shader parameters from the shading node if enabled,
	otherwise use explicit mental ray attributes.
	*/
	void setMiDeriveFromMaya(const BoolID& mifm){fprintf_s(mFile,"connectAttr \"");mifm.write(mFile);fprintf_s(mFile,"\" \"%s.mifm\";\n",mName.c_str());}
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	void setMiShinyness(float mis){if(mis == 10) return; fprintf_s(mFile, "setAttr \".mis\" %f;\n", mis);}
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	void setMiShinyness(const FloatID& mis){fprintf_s(mFile,"connectAttr \"");mis.write(mFile);fprintf_s(mFile,"\" \"%s.mis\";\n",mName.c_str());}
	/*Photon shader angle parameter to control direction of anisotropic feature.*/
	void setMiAngle(float mia){if(mia == 0) return; fprintf_s(mFile, "setAttr \".mia\" %f;\n", mia);}
	/*Photon shader angle parameter to control direction of anisotropic feature.*/
	void setMiAngle(const FloatID& mia){fprintf_s(mFile,"connectAttr \"");mia.write(mFile);fprintf_s(mFile,"\" \"%s.mia\";\n",mName.c_str());}
	/*Photon shader x spread parameter to control size of anisotropic feature in x direction.*/
	void setMiSpreadX(float misx){if(misx == 10) return; fprintf_s(mFile, "setAttr \".misx\" %f;\n", misx);}
	/*Photon shader x spread parameter to control size of anisotropic feature in x direction.*/
	void setMiSpreadX(const FloatID& misx){fprintf_s(mFile,"connectAttr \"");misx.write(mFile);fprintf_s(mFile,"\" \"%s.misx\";\n",mName.c_str());}
	/*Photon shader spread parameter to control size of anisotropic feature in y direction.*/
	void setMiSpreadY(float misy){if(misy == 5) return; fprintf_s(mFile, "setAttr \".misy\" %f;\n", misy);}
	/*Photon shader spread parameter to control size of anisotropic feature in y direction.*/
	void setMiSpreadY(const FloatID& misy){fprintf_s(mFile,"connectAttr \"");misy.write(mFile);fprintf_s(mFile,"\" \"%s.misy\";\n",mName.c_str());}
	/*Photon shader whiteness parameter.*/
	void setMiWhiteness(const float3& miwn){fprintf_s(mFile, "setAttr \".miwn\" -type \"float3\" ");miwn.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader whiteness parameter.*/
	void setMiWhiteness(const Float3ID& miwn){fprintf_s(mFile,"connectAttr \"");miwn.write(mFile);fprintf_s(mFile,"\" \"%s.miwn\";\n",mName.c_str());}
	/*Red component.*/
	void setMiWhitenessR(float miwnr){if(miwnr == 0.5) return; fprintf_s(mFile, "setAttr \".miwn.miwnr\" %f;\n", miwnr);}
	/*Red component.*/
	void setMiWhitenessR(const FloatID& miwnr){fprintf_s(mFile,"connectAttr \"");miwnr.write(mFile);fprintf_s(mFile,"\" \"%s.miwn.miwnr\";\n",mName.c_str());}
	/*Green component.*/
	void setMiWhitenessG(float miwng){if(miwng == 0.5) return; fprintf_s(mFile, "setAttr \".miwn.miwng\" %f;\n", miwng);}
	/*Green component.*/
	void setMiWhitenessG(const FloatID& miwng){fprintf_s(mFile,"connectAttr \"");miwng.write(mFile);fprintf_s(mFile,"\" \"%s.miwn.miwng\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiWhitenessB(float miwnb){if(miwnb == 0.5) return; fprintf_s(mFile, "setAttr \".miwn.miwnb\" %f;\n", miwnb);}
	/*Blue component.*/
	void setMiWhitenessB(const FloatID& miwnb){fprintf_s(mFile,"connectAttr \"");miwnb.write(mFile);fprintf_s(mFile,"\" \"%s.miwn.miwnb\";\n",mName.c_str());}
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const float3& misc){fprintf_s(mFile, "setAttr \".misc\" -type \"float3\" ");misc.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const Float3ID& misc){fprintf_s(mFile,"connectAttr \"");misc.write(mFile);fprintf_s(mFile,"\" \"%s.misc\";\n",mName.c_str());}
	/*Red component.*/
	void setMiSpecularColorR(float miscr){if(miscr == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscr\" %f;\n", miscr);}
	/*Red component.*/
	void setMiSpecularColorR(const FloatID& miscr){fprintf_s(mFile,"connectAttr \"");miscr.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscr\";\n",mName.c_str());}
	/*Green component.*/
	void setMiSpecularColorG(float miscg){if(miscg == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscg\" %f;\n", miscg);}
	/*Green component.*/
	void setMiSpecularColorG(const FloatID& miscg){fprintf_s(mFile,"connectAttr \"");miscg.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscg\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiSpecularColorB(float miscb){if(miscb == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscb\" %f;\n", miscb);}
	/*Blue component.*/
	void setMiSpecularColorB(const FloatID& miscb){fprintf_s(mFile,"connectAttr \"");miscb.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscb\";\n",mName.c_str());}
	/*Photon shader reflectivity parameter.*/
	void setMiReflectivity(float mirf){if(mirf == 0.5) return; fprintf_s(mFile, "setAttr \".mirf\" %f;\n", mirf);}
	/*Photon shader reflectivity parameter.*/
	void setMiReflectivity(const FloatID& mirf){fprintf_s(mFile,"connectAttr \"");mirf.write(mFile);fprintf_s(mFile,"\" \"%s.mirf\";\n",mName.c_str());}
	/*Photon shader index-of-refraction parameter.*/
	void setMiRefractiveIndex(float miri){if(miri == 1) return; fprintf_s(mFile, "setAttr \".miri\" %f;\n", miri);}
	/*Photon shader index-of-refraction parameter.*/
	void setMiRefractiveIndex(const FloatID& miri){fprintf_s(mFile,"connectAttr \"");miri.write(mFile);fprintf_s(mFile,"\" \"%s.miri\";\n",mName.c_str());}
	/*Photon shader refractions parameter.*/
	void setMiRefractions(bool mirc){if(mirc == true) return; fprintf_s(mFile, "setAttr \".mirc\" %i;\n", mirc);}
	/*Photon shader refractions parameter.*/
	void setMiRefractions(const BoolID& mirc){fprintf_s(mFile,"connectAttr \"");mirc.write(mFile);fprintf_s(mFile,"\" \"%s.mirc\";\n",mName.c_str());}
	/*Photon shader absorption parameter.*/
	void setMiAbsorbs(bool miab){if(miab == true) return; fprintf_s(mFile, "setAttr \".miab\" %i;\n", miab);}
	/*Photon shader absorption parameter.*/
	void setMiAbsorbs(const BoolID& miab){fprintf_s(mFile,"connectAttr \"");miab.write(mFile);fprintf_s(mFile,"\" \"%s.miab\";\n",mName.c_str());}
	/*Photon shader diffuse parameter.*/
	void setMiDiffuse(float midc){if(midc == 0.8) return; fprintf_s(mFile, "setAttr \".midc\" %f;\n", midc);}
	/*Photon shader diffuse parameter.*/
	void setMiDiffuse(const FloatID& midc){fprintf_s(mFile,"connectAttr \"");midc.write(mFile);fprintf_s(mFile,"\" \"%s.midc\";\n",mName.c_str());}
	/*Photon shader base color parameter.*/
	void setMiColor(const float3& mic){fprintf_s(mFile, "setAttr \".mic\" -type \"float3\" ");mic.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader base color parameter.*/
	void setMiColor(const Float3ID& mic){fprintf_s(mFile,"connectAttr \"");mic.write(mFile);fprintf_s(mFile,"\" \"%s.mic\";\n",mName.c_str());}
	/*Red component.*/
	void setMiColorR(float micr){if(micr == 0.5) return; fprintf_s(mFile, "setAttr \".mic.micr\" %f;\n", micr);}
	/*Red component.*/
	void setMiColorR(const FloatID& micr){fprintf_s(mFile,"connectAttr \"");micr.write(mFile);fprintf_s(mFile,"\" \"%s.mic.micr\";\n",mName.c_str());}
	/*Green component.*/
	void setMiColorG(float micg){if(micg == 0.5) return; fprintf_s(mFile, "setAttr \".mic.micg\" %f;\n", micg);}
	/*Green component.*/
	void setMiColorG(const FloatID& micg){fprintf_s(mFile,"connectAttr \"");micg.write(mFile);fprintf_s(mFile,"\" \"%s.mic.micg\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiColorB(float micb){if(micb == 0.5) return; fprintf_s(mFile, "setAttr \".mic.micb\" %f;\n", micb);}
	/*Blue component.*/
	void setMiColorB(const FloatID& micb){fprintf_s(mFile,"connectAttr \"");micb.write(mFile);fprintf_s(mFile,"\" \"%s.mic.micb\";\n",mName.c_str());}
	/*Photon shader transparency parameter.*/
	void setMiTransparency(const float3& mit){fprintf_s(mFile, "setAttr \".mit\" -type \"float3\" ");mit.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader transparency parameter.*/
	void setMiTransparency(const Float3ID& mit){fprintf_s(mFile,"connectAttr \"");mit.write(mFile);fprintf_s(mFile,"\" \"%s.mit\";\n",mName.c_str());}
	/*Red component.*/
	void setMiTransparencyR(float mitr){if(mitr == 0) return; fprintf_s(mFile, "setAttr \".mit.mitr\" %f;\n", mitr);}
	/*Red component.*/
	void setMiTransparencyR(const FloatID& mitr){fprintf_s(mFile,"connectAttr \"");mitr.write(mFile);fprintf_s(mFile,"\" \"%s.mit.mitr\";\n",mName.c_str());}
	/*Green component.*/
	void setMiTransparencyG(float mitg){if(mitg == 0) return; fprintf_s(mFile, "setAttr \".mit.mitg\" %f;\n", mitg);}
	/*Green component.*/
	void setMiTransparencyG(const FloatID& mitg){fprintf_s(mFile,"connectAttr \"");mitg.write(mFile);fprintf_s(mFile,"\" \"%s.mit.mitg\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiTransparencyB(float mitb){if(mitb == 0) return; fprintf_s(mFile, "setAttr \".mit.mitb\" %f;\n", mitb);}
	/*Blue component.*/
	void setMiTransparencyB(const FloatID& mitb){fprintf_s(mFile,"connectAttr \"");mitb.write(mFile);fprintf_s(mFile,"\" \"%s.mit.mitb\";\n",mName.c_str());}
	/*Photon shader translucency parameter.*/
	void setMiTranslucence(float mitc){if(mitc == 0) return; fprintf_s(mFile, "setAttr \".mitc\" %f;\n", mitc);}
	/*Photon shader translucency parameter.*/
	void setMiTranslucence(const FloatID& mitc){fprintf_s(mFile,"connectAttr \"");mitc.write(mFile);fprintf_s(mFile,"\" \"%s.mitc\";\n",mName.c_str());}
	/*Photon shader translucence focus parameter.*/
	void setMiTranslucenceFocus(float mitf){if(mitf == 0.5) return; fprintf_s(mFile, "setAttr \".mitf\" %f;\n", mitf);}
	/*Photon shader translucence focus parameter.*/
	void setMiTranslucenceFocus(const FloatID& mitf){fprintf_s(mFile,"connectAttr \"");mitf.write(mFile);fprintf_s(mFile,"\" \"%s.mitf\";\n",mName.c_str());}
	/*Port to connect bump node for photon shader.*/
	void setMiNormalCamera(const float3& minc){fprintf_s(mFile, "setAttr \".minc\" -type \"float3\" ");minc.write(mFile);fprintf_s(mFile,";\n");}
	/*Port to connect bump node for photon shader.*/
	void setMiNormalCamera(const Float3ID& minc){fprintf_s(mFile,"connectAttr \"");minc.write(mFile);fprintf_s(mFile,"\" \"%s.minc\";\n",mName.c_str());}
	/*X coordinate*/
	void setMiNormalCameraX(float mincx){if(mincx == 0) return; fprintf_s(mFile, "setAttr \".minc.mincx\" %f;\n", mincx);}
	/*X coordinate*/
	void setMiNormalCameraX(const FloatID& mincx){fprintf_s(mFile,"connectAttr \"");mincx.write(mFile);fprintf_s(mFile,"\" \"%s.minc.mincx\";\n",mName.c_str());}
	/*Y coordinate*/
	void setMiNormalCameraY(float mincy){if(mincy == 0) return; fprintf_s(mFile, "setAttr \".minc.mincy\" %f;\n", mincy);}
	/*Y coordinate*/
	void setMiNormalCameraY(const FloatID& mincy){fprintf_s(mFile,"connectAttr \"");mincy.write(mFile);fprintf_s(mFile,"\" \"%s.minc.mincy\";\n",mName.c_str());}
	/*Z coordinate*/
	void setMiNormalCameraZ(float mincz){if(mincz == 0) return; fprintf_s(mFile, "setAttr \".minc.mincz\" %f;\n", mincz);}
	/*Z coordinate*/
	void setMiNormalCameraZ(const FloatID& mincz){fprintf_s(mFile,"connectAttr \"");mincz.write(mFile);fprintf_s(mFile,"\" \"%s.minc.mincz\";\n",mName.c_str());}
	/*
	This attribute controls contribution from
	indirect diffuse illumination to the useBackground shader.
	The alpha value of the indirect illumination on a surface point
	is scaled by this attribute, and contributes to the final color and alpha.
	0 means no indirect illumination on the surface,
	which is same as the old behaviour.
	If set to 1, useBackground will be affected by final gather
	like other material shaders, but only in grey scale.
	*/
	void setMiOcclusionMask(float mio){if(mio == 1) return; fprintf_s(mFile, "setAttr \".mio\" %f;\n", mio);}
	/*
	This attribute controls contribution from
	indirect diffuse illumination to the useBackground shader.
	The alpha value of the indirect illumination on a surface point
	is scaled by this attribute, and contributes to the final color and alpha.
	0 means no indirect illumination on the surface,
	which is same as the old behaviour.
	If set to 1, useBackground will be affected by final gather
	like other material shaders, but only in grey scale.
	*/
	void setMiOcclusionMask(const FloatID& mio){fprintf_s(mFile,"connectAttr \"");mio.write(mFile);fprintf_s(mFile,"\" \"%s.mio\";\n",mName.c_str());}
	/*output color*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*outColor red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*outColor green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*outColor blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*output Transparency*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*outTransparency R value*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*outTransparency G value*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*outTransparency B value*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*surface intersection point in camera space*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*point camera X value*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.pc.px",mName.c_str());return (const char*)buffer;}
	/*point camera Y value*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.pc.py",mName.c_str());return (const char*)buffer;}
	/*point camera Z value*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.pc.pz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Normal Camera</b> represents the surface normals in the
	camera's space. (These are
	used to calculate shading.)<p/>To do Bump Mapping, connect the output of a bump
	node to this attribute.
	*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*normal camera x value*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*normal camera Y value*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*normal camera Z value*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*
	shadow attenuation. If less than 1.0, it makes the shadows appear
	dimmer.  At a value of 0, the shadows are not visible.
	*/
	FloatID getShadowMask(){char buffer[4096];sprintf_s (buffer, "%s.sm",mName.c_str());return (const char*)buffer;}
	/*reflected ray depth limit*/
	ShortID getReflectionLimit(){char buffer[4096];sprintf_s (buffer, "%s.fll",mName.c_str());return (const char*)buffer;}
	/*
	<b>Specular Color</b> is the color of the specular reflections
	(also called 'hot spots') on the material.  The final color
	of a specular reflection is a combination of the Specular Color
	and the color of the light.
	<p/>By making the Specular Color brighter or dimmer, you can control
	the brightness of the specular reflections on an object.
	<p/>
	<i>Tip:</i> To make a material look more plastic, use white for the specular
	color.  To make a material look more metallic, make the specular
	color similar to the surface color.
	*/
	Float3ID getSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*specular color red value*/
	FloatID getSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.sc.sr",mName.c_str());return (const char*)buffer;}
	/*specular color green value*/
	FloatID getSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.sc.sg",mName.c_str());return (const char*)buffer;}
	/*specular color blue value*/
	FloatID getSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.sc.sb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
	<p/>
	This attribute is only meaningful if there is a reflection map, or
	if you are doing Ray Tracing.
	<p/>
	Here are some useful values for Reflectivity:
	<ul>
	Car Paint: 0.4<br/>
	Glass: 0.7<br/>
	Mirror: 1.0<br/>
	Chrome: 1.0
	</ul>
	<p/>
	<i>Note:</i> If you are doing Ray Tracing, and you want
	other objects in the scene to be seen in reflections, then
	you must turn on the Visible In Reflections attribute of
	those objects.
	*/
	FloatID getReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.rfl",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	</ul>
	*/
	UnsignedintID getMatteOpacityMode(){char buffer[4096];sprintf_s (buffer, "%s.mom",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	FloatID getMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.mog",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity*/
	Float3ID getOutMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.omo",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity red value*/
	FloatID getOutMatteOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.omo.omor",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity green value*/
	FloatID getOutMatteOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.omo.omog",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity blue value*/
	FloatID getOutMatteOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.omo.omob",mName.c_str());return (const char*)buffer;}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a ray's direction is not exactly determined anymore.
	It may deviate (randomly) from the perfect specular direction,
	within the bounds specified by <b>miReflectionBlur</b> (in angle).
	A value of zero implies a perfectly specular interaction,
	a value of 90 a perfectly diffuse reflection or refraction.
	Values of 10 to 30 are a good starting point
	*/
	FloatID getMiReflectionBlur(){char buffer[4096];sprintf_s (buffer, "%s.mircb",mName.c_str());return (const char*)buffer;}
	/*
	Number of reflection rays to use for blurring.
	<b>miReflectionRays</b> specifies number of rays to use
	to sample the random deviation. In general more rays are required
	for more blurry reflections or refractions.
	Other sampling parameters also affect this setting:
	per-object samples and the Render Settings sample setting supersample in image space.
	If you increase any of these two settings,
	you may be able to reduce the number of rays without loss of quality,
	but significant performance gain.
	*/
	ShortID getMiReflectionRays(){char buffer[4096];sprintf_s (buffer, "%s.mircr",mName.c_str());return (const char*)buffer;}
	/*
	Derive photon shader parameters from the shading node if enabled,
	otherwise use explicit mental ray attributes.
	*/
	BoolID getMiDeriveFromMaya(){char buffer[4096];sprintf_s (buffer, "%s.mifm",mName.c_str());return (const char*)buffer;}
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	FloatID getMiShinyness(){char buffer[4096];sprintf_s (buffer, "%s.mis",mName.c_str());return (const char*)buffer;}
	/*Photon shader angle parameter to control direction of anisotropic feature.*/
	FloatID getMiAngle(){char buffer[4096];sprintf_s (buffer, "%s.mia",mName.c_str());return (const char*)buffer;}
	/*Photon shader x spread parameter to control size of anisotropic feature in x direction.*/
	FloatID getMiSpreadX(){char buffer[4096];sprintf_s (buffer, "%s.misx",mName.c_str());return (const char*)buffer;}
	/*Photon shader spread parameter to control size of anisotropic feature in y direction.*/
	FloatID getMiSpreadY(){char buffer[4096];sprintf_s (buffer, "%s.misy",mName.c_str());return (const char*)buffer;}
	/*Photon shader whiteness parameter.*/
	Float3ID getMiWhiteness(){char buffer[4096];sprintf_s (buffer, "%s.miwn",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiWhitenessR(){char buffer[4096];sprintf_s (buffer, "%s.miwn.miwnr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiWhitenessG(){char buffer[4096];sprintf_s (buffer, "%s.miwn.miwng",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiWhitenessB(){char buffer[4096];sprintf_s (buffer, "%s.miwn.miwnb",mName.c_str());return (const char*)buffer;}
	/*Photon shader specular color parameter.*/
	Float3ID getMiSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.misc",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscb",mName.c_str());return (const char*)buffer;}
	/*Photon shader reflectivity parameter.*/
	FloatID getMiReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.mirf",mName.c_str());return (const char*)buffer;}
	/*Photon shader index-of-refraction parameter.*/
	FloatID getMiRefractiveIndex(){char buffer[4096];sprintf_s (buffer, "%s.miri",mName.c_str());return (const char*)buffer;}
	/*Photon shader refractions parameter.*/
	BoolID getMiRefractions(){char buffer[4096];sprintf_s (buffer, "%s.mirc",mName.c_str());return (const char*)buffer;}
	/*Photon shader absorption parameter.*/
	BoolID getMiAbsorbs(){char buffer[4096];sprintf_s (buffer, "%s.miab",mName.c_str());return (const char*)buffer;}
	/*Photon shader diffuse parameter.*/
	FloatID getMiDiffuse(){char buffer[4096];sprintf_s (buffer, "%s.midc",mName.c_str());return (const char*)buffer;}
	/*Photon shader base color parameter.*/
	Float3ID getMiColor(){char buffer[4096];sprintf_s (buffer, "%s.mic",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiColorR(){char buffer[4096];sprintf_s (buffer, "%s.mic.micr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiColorG(){char buffer[4096];sprintf_s (buffer, "%s.mic.micg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiColorB(){char buffer[4096];sprintf_s (buffer, "%s.mic.micb",mName.c_str());return (const char*)buffer;}
	/*Photon shader transparency parameter.*/
	Float3ID getMiTransparency(){char buffer[4096];sprintf_s (buffer, "%s.mit",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.mit.mitr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.mit.mitg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.mit.mitb",mName.c_str());return (const char*)buffer;}
	/*Photon shader translucency parameter.*/
	FloatID getMiTranslucence(){char buffer[4096];sprintf_s (buffer, "%s.mitc",mName.c_str());return (const char*)buffer;}
	/*Photon shader translucence focus parameter.*/
	FloatID getMiTranslucenceFocus(){char buffer[4096];sprintf_s (buffer, "%s.mitf",mName.c_str());return (const char*)buffer;}
	/*Port to connect bump node for photon shader.*/
	Float3ID getMiNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.minc",mName.c_str());return (const char*)buffer;}
	/*X coordinate*/
	FloatID getMiNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.minc.mincx",mName.c_str());return (const char*)buffer;}
	/*Y coordinate*/
	FloatID getMiNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.minc.mincy",mName.c_str());return (const char*)buffer;}
	/*Z coordinate*/
	FloatID getMiNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.minc.mincz",mName.c_str());return (const char*)buffer;}
	/*
	This attribute controls contribution from
	indirect diffuse illumination to the useBackground shader.
	The alpha value of the indirect illumination on a surface point
	is scaled by this attribute, and contributes to the final color and alpha.
	0 means no indirect illumination on the surface,
	which is same as the old behaviour.
	If set to 1, useBackground will be affected by final gather
	like other material shaders, but only in grey scale.
	*/
	FloatID getMiOcclusionMask(){char buffer[4096];sprintf_s (buffer, "%s.mio",mName.c_str());return (const char*)buffer;}
protected:
	UseBackground(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_USEBACKGROUND_H__
