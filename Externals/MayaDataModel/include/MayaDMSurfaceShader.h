/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACESHADER_H__
#define __MayaDM_SURFACESHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Use a <b>Surface Shader</b> when you want to completely control
 the color, transparency and matte opacity of a material.  This kind
 of shader does no shading calculation of any kind.  Rather, it allows you
 connect other attributes directly to its color, glow color,
 and transparency.  It completely ignores everything
 else that would normally affect a shader.
 <p/>
 For example, if you connect the Translate attribute of an object to the
 Out Color attribute of a Surface Shader, then the color of the shader
 will depend on the position of the object in space.  As the object
 moves, it will change color.
 <p/>
 In the table below, important attributes have their names indicated
 in <b>bold</b> in the description column.
*/
class SurfaceShader : public DependNode
{
public:
public:
	SurfaceShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "surfaceShader"){}
	virtual ~SurfaceShader(){}
	/*
	<b>Out Color</b>. Connect another attribute to this to
	control the color of the material with that attribute.
	*/
	void setOutColor(const float3& oc){if(oc == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".oc\" -type \"float3\" ");oc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Out Color</b>. Connect another attribute to this to
	control the color of the material with that attribute.
	*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Out Color red value*/
	void setOutColorR(float ocr){if(ocr == 0.0) return; fprintf_s(mFile, "setAttr \".oc.ocr\" %f;\n", ocr);}
	/*Out Color red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*Out Color green value*/
	void setOutColorG(float ocg){if(ocg == 0.0) return; fprintf_s(mFile, "setAttr \".oc.ocg\" %f;\n", ocg);}
	/*Out Color green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*Out Color blue value*/
	void setOutColorB(float ocb){if(ocb == 0.0) return; fprintf_s(mFile, "setAttr \".oc.ocb\" %f;\n", ocb);}
	/*Out Color blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*
	<b>Out Transparency</b>. Connect another attribute to this to
	control the transparency of the material.
	*/
	void setOutTransparency(const float3& ot){if(ot == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ot\" -type \"float3\" ");ot.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Out Transparency</b>. Connect another attribute to this to
	control the transparency of the material.
	*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*Out Transparency red value*/
	void setOutTransparencyR(float otr){if(otr == 0.0) return; fprintf_s(mFile, "setAttr \".ot.otr\" %f;\n", otr);}
	/*Out Transparency red value*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*Out Transparency green value*/
	void setOutTransparencyG(float otg){if(otg == 0.0) return; fprintf_s(mFile, "setAttr \".ot.otg\" %f;\n", otg);}
	/*Out Transparency green value*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*Out Transparency blue value*/
	void setOutTransparencyB(float otb){if(otb == 0.0) return; fprintf_s(mFile, "setAttr \".ot.otb\" %f;\n", otb);}
	/*Out Transparency blue value*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*
	<b>Out Matte Opacity</b>. Connect another attribute to this to
	control the opacity of the material's matte (alpha) channel.
	*/
	void setOutMatteOpacity(const float3& omo){if(omo == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".omo\" -type \"float3\" ");omo.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Out Matte Opacity</b>. Connect another attribute to this to
	control the opacity of the material's matte (alpha) channel.
	*/
	void setOutMatteOpacity(const Float3ID& omo){fprintf_s(mFile,"connectAttr \"");omo.write(mFile);fprintf_s(mFile,"\" \"%s.omo\";\n",mName.c_str());}
	/*Out Matte Opacity red value*/
	void setOutMatteOpacityR(float omor){if(omor == 0.0) return; fprintf_s(mFile, "setAttr \".omo.omor\" %f;\n", omor);}
	/*Out Matte Opacity red value*/
	void setOutMatteOpacityR(const FloatID& omor){fprintf_s(mFile,"connectAttr \"");omor.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omor\";\n",mName.c_str());}
	/*Out Matte Opacity green value*/
	void setOutMatteOpacityG(float omog){if(omog == 0.0) return; fprintf_s(mFile, "setAttr \".omo.omog\" %f;\n", omog);}
	/*Out Matte Opacity green value*/
	void setOutMatteOpacityG(const FloatID& omog){fprintf_s(mFile,"connectAttr \"");omog.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omog\";\n",mName.c_str());}
	/*Out Matte Opacity blue value*/
	void setOutMatteOpacityB(float omob){if(omob == 0.0) return; fprintf_s(mFile, "setAttr \".omo.omob\" %f;\n", omob);}
	/*Out Matte Opacity blue value*/
	void setOutMatteOpacityB(const FloatID& omob){fprintf_s(mFile,"connectAttr \"");omob.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omob\";\n",mName.c_str());}
	/*
	<b>Out Glow Color</b>. Connect another attribute to this to
	control the glow color of the material.
	*/
	void setOutGlowColor(const float3& og){if(og == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".og\" -type \"float3\" ");og.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Out Glow Color</b>. Connect another attribute to this to
	control the glow color of the material.
	*/
	void setOutGlowColor(const Float3ID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og\";\n",mName.c_str());}
	/*Out Glow Color red value*/
	void setOutGlowColorR(float ogr){if(ogr == 0.0) return; fprintf_s(mFile, "setAttr \".og.ogr\" %f;\n", ogr);}
	/*Out Glow Color red value*/
	void setOutGlowColorR(const FloatID& ogr){fprintf_s(mFile,"connectAttr \"");ogr.write(mFile);fprintf_s(mFile,"\" \"%s.og.ogr\";\n",mName.c_str());}
	/*Out Glow Color green value*/
	void setOutGlowColorG(float ogg){if(ogg == 0.0) return; fprintf_s(mFile, "setAttr \".og.ogg\" %f;\n", ogg);}
	/*Out Glow Color green value*/
	void setOutGlowColorG(const FloatID& ogg){fprintf_s(mFile,"connectAttr \"");ogg.write(mFile);fprintf_s(mFile,"\" \"%s.og.ogg\";\n",mName.c_str());}
	/*Out Glow Color blue value*/
	void setOutGlowColorB(float ogb){if(ogb == 0.0) return; fprintf_s(mFile, "setAttr \".og.ogb\" %f;\n", ogb);}
	/*Out Glow Color blue value*/
	void setOutGlowColorB(const FloatID& ogb){fprintf_s(mFile,"connectAttr \"");ogb.write(mFile);fprintf_s(mFile,"\" \"%s.og.ogb\";\n",mName.c_str());}
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
	/*Red component*/
	void setMiWhitenessR(float miwnr){if(miwnr == 0.5) return; fprintf_s(mFile, "setAttr \".miwn.miwnr\" %f;\n", miwnr);}
	/*Red component*/
	void setMiWhitenessR(const FloatID& miwnr){fprintf_s(mFile,"connectAttr \"");miwnr.write(mFile);fprintf_s(mFile,"\" \"%s.miwn.miwnr\";\n",mName.c_str());}
	/*Green component*/
	void setMiWhitenessG(float miwng){if(miwng == 0.5) return; fprintf_s(mFile, "setAttr \".miwn.miwng\" %f;\n", miwng);}
	/*Green component*/
	void setMiWhitenessG(const FloatID& miwng){fprintf_s(mFile,"connectAttr \"");miwng.write(mFile);fprintf_s(mFile,"\" \"%s.miwn.miwng\";\n",mName.c_str());}
	/*Blue component*/
	void setMiWhitenessB(float miwnb){if(miwnb == 0.5) return; fprintf_s(mFile, "setAttr \".miwn.miwnb\" %f;\n", miwnb);}
	/*Blue component*/
	void setMiWhitenessB(const FloatID& miwnb){fprintf_s(mFile,"connectAttr \"");miwnb.write(mFile);fprintf_s(mFile,"\" \"%s.miwn.miwnb\";\n",mName.c_str());}
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const float3& misc){fprintf_s(mFile, "setAttr \".misc\" -type \"float3\" ");misc.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const Float3ID& misc){fprintf_s(mFile,"connectAttr \"");misc.write(mFile);fprintf_s(mFile,"\" \"%s.misc\";\n",mName.c_str());}
	/*Red component*/
	void setMiSpecularColorR(float miscr){if(miscr == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscr\" %f;\n", miscr);}
	/*Red component*/
	void setMiSpecularColorR(const FloatID& miscr){fprintf_s(mFile,"connectAttr \"");miscr.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscr\";\n",mName.c_str());}
	/*Green component*/
	void setMiSpecularColorG(float miscg){if(miscg == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscg\" %f;\n", miscg);}
	/*Green component*/
	void setMiSpecularColorG(const FloatID& miscg){fprintf_s(mFile,"connectAttr \"");miscg.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscg\";\n",mName.c_str());}
	/*Blue component*/
	void setMiSpecularColorB(float miscb){if(miscb == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscb\" %f;\n", miscb);}
	/*Blue component*/
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
	/*Red component*/
	void setMiColorR(float micr){if(micr == 0.5) return; fprintf_s(mFile, "setAttr \".mic.micr\" %f;\n", micr);}
	/*Red component*/
	void setMiColorR(const FloatID& micr){fprintf_s(mFile,"connectAttr \"");micr.write(mFile);fprintf_s(mFile,"\" \"%s.mic.micr\";\n",mName.c_str());}
	/*Green component*/
	void setMiColorG(float micg){if(micg == 0.5) return; fprintf_s(mFile, "setAttr \".mic.micg\" %f;\n", micg);}
	/*Green component*/
	void setMiColorG(const FloatID& micg){fprintf_s(mFile,"connectAttr \"");micg.write(mFile);fprintf_s(mFile,"\" \"%s.mic.micg\";\n",mName.c_str());}
	/*Blue component*/
	void setMiColorB(float micb){if(micb == 0.5) return; fprintf_s(mFile, "setAttr \".mic.micb\" %f;\n", micb);}
	/*Blue component*/
	void setMiColorB(const FloatID& micb){fprintf_s(mFile,"connectAttr \"");micb.write(mFile);fprintf_s(mFile,"\" \"%s.mic.micb\";\n",mName.c_str());}
	/*Photon shader transparency parameter.*/
	void setMiTransparency(const float3& mit){fprintf_s(mFile, "setAttr \".mit\" -type \"float3\" ");mit.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader transparency parameter.*/
	void setMiTransparency(const Float3ID& mit){fprintf_s(mFile,"connectAttr \"");mit.write(mFile);fprintf_s(mFile,"\" \"%s.mit\";\n",mName.c_str());}
	/*Red component*/
	void setMiTransparencyR(float mitr){if(mitr == 0) return; fprintf_s(mFile, "setAttr \".mit.mitr\" %f;\n", mitr);}
	/*Red component*/
	void setMiTransparencyR(const FloatID& mitr){fprintf_s(mFile,"connectAttr \"");mitr.write(mFile);fprintf_s(mFile,"\" \"%s.mit.mitr\";\n",mName.c_str());}
	/*Green component*/
	void setMiTransparencyG(float mitg){if(mitg == 0) return; fprintf_s(mFile, "setAttr \".mit.mitg\" %f;\n", mitg);}
	/*Green component*/
	void setMiTransparencyG(const FloatID& mitg){fprintf_s(mFile,"connectAttr \"");mitg.write(mFile);fprintf_s(mFile,"\" \"%s.mit.mitg\";\n",mName.c_str());}
	/*Blue component*/
	void setMiTransparencyB(float mitb){if(mitb == 0) return; fprintf_s(mFile, "setAttr \".mit.mitb\" %f;\n", mitb);}
	/*Blue component*/
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
	/*X component*/
	void setMiNormalCameraX(float mincx){if(mincx == 0) return; fprintf_s(mFile, "setAttr \".minc.mincx\" %f;\n", mincx);}
	/*X component*/
	void setMiNormalCameraX(const FloatID& mincx){fprintf_s(mFile,"connectAttr \"");mincx.write(mFile);fprintf_s(mFile,"\" \"%s.minc.mincx\";\n",mName.c_str());}
	/*Y component*/
	void setMiNormalCameraY(float mincy){if(mincy == 0) return; fprintf_s(mFile, "setAttr \".minc.mincy\" %f;\n", mincy);}
	/*Y component*/
	void setMiNormalCameraY(const FloatID& mincy){fprintf_s(mFile,"connectAttr \"");mincy.write(mFile);fprintf_s(mFile,"\" \"%s.minc.mincy\";\n",mName.c_str());}
	/*Z component*/
	void setMiNormalCameraZ(float mincz){if(mincz == 0) return; fprintf_s(mFile, "setAttr \".minc.mincz\" %f;\n", mincz);}
	/*Z component*/
	void setMiNormalCameraZ(const FloatID& mincz){fprintf_s(mFile,"connectAttr \"");mincz.write(mFile);fprintf_s(mFile,"\" \"%s.minc.mincz\";\n",mName.c_str());}
	/*Material Alpha Gain*/
	void setMaterialAlphaGain(float maga){if(maga == 1.0) return; fprintf_s(mFile, "setAttr \".maga\" %f;\n", maga);}
	/*Material Alpha Gain*/
	void setMaterialAlphaGain(const FloatID& maga){fprintf_s(mFile,"connectAttr \"");maga.write(mFile);fprintf_s(mFile,"\" \"%s.maga\";\n",mName.c_str());}
	/*
	<b>Out Color</b>. Connect another attribute to this to
	control the color of the material with that attribute.
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*Out Color red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*Out Color green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*Out Color blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Transparency</b>. Connect another attribute to this to
	control the transparency of the material.
	*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*Out Transparency red value*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*Out Transparency green value*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*Out Transparency blue value*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Matte Opacity</b>. Connect another attribute to this to
	control the opacity of the material's matte (alpha) channel.
	*/
	Float3ID getOutMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.omo",mName.c_str());return (const char*)buffer;}
	/*Out Matte Opacity red value*/
	FloatID getOutMatteOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.omo.omor",mName.c_str());return (const char*)buffer;}
	/*Out Matte Opacity green value*/
	FloatID getOutMatteOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.omo.omog",mName.c_str());return (const char*)buffer;}
	/*Out Matte Opacity blue value*/
	FloatID getOutMatteOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.omo.omob",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Glow Color</b>. Connect another attribute to this to
	control the glow color of the material.
	*/
	Float3ID getOutGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.og",mName.c_str());return (const char*)buffer;}
	/*Out Glow Color red value*/
	FloatID getOutGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.og.ogr",mName.c_str());return (const char*)buffer;}
	/*Out Glow Color green value*/
	FloatID getOutGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.og.ogg",mName.c_str());return (const char*)buffer;}
	/*Out Glow Color blue value*/
	FloatID getOutGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.og.ogb",mName.c_str());return (const char*)buffer;}
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
	/*Red component*/
	FloatID getMiWhitenessR(){char buffer[4096];sprintf_s (buffer, "%s.miwn.miwnr",mName.c_str());return (const char*)buffer;}
	/*Green component*/
	FloatID getMiWhitenessG(){char buffer[4096];sprintf_s (buffer, "%s.miwn.miwng",mName.c_str());return (const char*)buffer;}
	/*Blue component*/
	FloatID getMiWhitenessB(){char buffer[4096];sprintf_s (buffer, "%s.miwn.miwnb",mName.c_str());return (const char*)buffer;}
	/*Photon shader specular color parameter.*/
	Float3ID getMiSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.misc",mName.c_str());return (const char*)buffer;}
	/*Red component*/
	FloatID getMiSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscr",mName.c_str());return (const char*)buffer;}
	/*Green component*/
	FloatID getMiSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscg",mName.c_str());return (const char*)buffer;}
	/*Blue component*/
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
	/*Red component*/
	FloatID getMiColorR(){char buffer[4096];sprintf_s (buffer, "%s.mic.micr",mName.c_str());return (const char*)buffer;}
	/*Green component*/
	FloatID getMiColorG(){char buffer[4096];sprintf_s (buffer, "%s.mic.micg",mName.c_str());return (const char*)buffer;}
	/*Blue component*/
	FloatID getMiColorB(){char buffer[4096];sprintf_s (buffer, "%s.mic.micb",mName.c_str());return (const char*)buffer;}
	/*Photon shader transparency parameter.*/
	Float3ID getMiTransparency(){char buffer[4096];sprintf_s (buffer, "%s.mit",mName.c_str());return (const char*)buffer;}
	/*Red component*/
	FloatID getMiTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.mit.mitr",mName.c_str());return (const char*)buffer;}
	/*Green component*/
	FloatID getMiTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.mit.mitg",mName.c_str());return (const char*)buffer;}
	/*Blue component*/
	FloatID getMiTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.mit.mitb",mName.c_str());return (const char*)buffer;}
	/*Photon shader translucency parameter.*/
	FloatID getMiTranslucence(){char buffer[4096];sprintf_s (buffer, "%s.mitc",mName.c_str());return (const char*)buffer;}
	/*Photon shader translucence focus parameter.*/
	FloatID getMiTranslucenceFocus(){char buffer[4096];sprintf_s (buffer, "%s.mitf",mName.c_str());return (const char*)buffer;}
	/*Port to connect bump node for photon shader.*/
	Float3ID getMiNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.minc",mName.c_str());return (const char*)buffer;}
	/*X component*/
	FloatID getMiNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.minc.mincx",mName.c_str());return (const char*)buffer;}
	/*Y component*/
	FloatID getMiNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.minc.mincy",mName.c_str());return (const char*)buffer;}
	/*Z component*/
	FloatID getMiNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.minc.mincz",mName.c_str());return (const char*)buffer;}
	/*Material Alpha Gain*/
	FloatID getMaterialAlphaGain(){char buffer[4096];sprintf_s (buffer, "%s.maga",mName.c_str());return (const char*)buffer;}
protected:
	SurfaceShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SURFACESHADER_H__
