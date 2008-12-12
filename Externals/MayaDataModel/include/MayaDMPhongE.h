/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PHONGE_H__
#define __MayaDM_PHONGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMReflect.h"
namespace MayaDM
{
/*
Use a <b>PhongE</b> shader to produce
  glossy surfaces.  PhongE is perfect for creating plastics,
  or the kinds of polymers used to create bathroom and car
  mouldings.
  <p/>
  Aside from the attributes described here, the PhongE shader
  inherits many attributes from its parents <a href="reflect.html">
  Reflect</a> and <a href="lambert.html">Lambert</a>.
  <p/>
  Maya also has a Phong shader, which is very similar, and can
  be used to make the same kinds of materials.  The difference
  is mostly a matter of personal preference.
  <p/>
        Other kinds of shaders you can use:
  <ul>
        For unpolished surfaces, like chalk or matte paint, use a <b>Lambert</b> shader.
  <p/>
  For metallic surfaces, such as brass or aluminum,
  use a <b>Blinn</b> shader.
  <p/>
  For microgrooved surfaces like CDs, brushed metal, or hair, use an
  <b>Anisotropic</b> shader.
  </ul>
  <p/>
  In the table below, important attribute have their names indicated
  in <b>bold</b> in the description column.
*/
class PhongE : public Reflect
{
public:
public:
	PhongE(FILE* file,const std::string& name,const std::string& parent=""):Reflect(file, name, parent, "phongE"){}
	virtual ~PhongE(){}
	/*
	<b>Roughness</b> controls how fast the brightness
	of a highlight
	decreases from the center of the highlight area to its edge
	This value ranges from 0 to 1.  Low values
	make the highlight die away quickly, giving the material
	a more polished look.  Higher values make the whole
	highlight region brighter, making the material appear
	rougher.
	*/
	void setRoughness(float rn){if(rn == 0.5) return; fprintf_s(mFile, "setAttr \".rn\" %f;\n", rn);}
	/*
	<b>Roughness</b> controls how fast the brightness
	of a highlight
	decreases from the center of the highlight area to its edge
	This value ranges from 0 to 1.  Low values
	make the highlight die away quickly, giving the material
	a more polished look.  Higher values make the whole
	highlight region brighter, making the material appear
	rougher.
	*/
	void setRoughness(const FloatID& rn){fprintf_s(mFile,"connectAttr \"");rn.write(mFile);fprintf_s(mFile,"\" \"%s.rn\";\n",mName.c_str());}
	/*
	<b>Highlight Size</b> controls how big the total highlight
	area is.
	*/
	void setHighlightSize(float hls){if(hls == 0.5) return; fprintf_s(mFile, "setAttr \".hls\" %f;\n", hls);}
	/*
	<b>Highlight Size</b> controls how big the total highlight
	area is.
	*/
	void setHighlightSize(const FloatID& hls){fprintf_s(mFile,"connectAttr \"");hls.write(mFile);fprintf_s(mFile,"\" \"%s.hls\";\n",mName.c_str());}
	/*
	Use <b>Whiteness</b> to blend the color of the highlight
	between the base color of the material and white.  As this
	color becomes brighter, the highlight becomes more white.
	As this gets darker, the highlight color gets closer to
	the base color of the material.
	<p/>
	<i>Tip:</i> To make your material look more plastic, make
	this brighter.  To make it look more metallic, make this
	darker.
	*/
	void setWhiteness(const float3& wn){if(wn == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".wn\" -type \"float3\" ");wn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Use <b>Whiteness</b> to blend the color of the highlight
	between the base color of the material and white.  As this
	color becomes brighter, the highlight becomes more white.
	As this gets darker, the highlight color gets closer to
	the base color of the material.
	<p/>
	<i>Tip:</i> To make your material look more plastic, make
	this brighter.  To make it look more metallic, make this
	darker.
	*/
	void setWhiteness(const Float3ID& wn){fprintf_s(mFile,"connectAttr \"");wn.write(mFile);fprintf_s(mFile,"\" \"%s.wn\";\n",mName.c_str());}
	/*whiteness red value*/
	void setWhitenessR(float wnr){if(wnr == 0.0) return; fprintf_s(mFile, "setAttr \".wn.wnr\" %f;\n", wnr);}
	/*whiteness red value*/
	void setWhitenessR(const FloatID& wnr){fprintf_s(mFile,"connectAttr \"");wnr.write(mFile);fprintf_s(mFile,"\" \"%s.wn.wnr\";\n",mName.c_str());}
	/*whiteness green value*/
	void setWhitenessG(float wng){if(wng == 0.0) return; fprintf_s(mFile, "setAttr \".wn.wng\" %f;\n", wng);}
	/*whiteness green value*/
	void setWhitenessG(const FloatID& wng){fprintf_s(mFile,"connectAttr \"");wng.write(mFile);fprintf_s(mFile,"\" \"%s.wn.wng\";\n",mName.c_str());}
	/*whiteness blue value*/
	void setWhitenessB(float wnb){if(wnb == 0.0) return; fprintf_s(mFile, "setAttr \".wn.wnb\" %f;\n", wnb);}
	/*whiteness blue value*/
	void setWhitenessB(const FloatID& wnb){fprintf_s(mFile,"connectAttr \"");wnb.write(mFile);fprintf_s(mFile,"\" \"%s.wn.wnb\";\n",mName.c_str());}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a ray direction is not exactly determined anymore.
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
	because a ray direction is not exactly determined anymore.
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
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	void setMiShinyness(float mis){if(mis == 10) return; fprintf_s(mFile, "setAttr \".mis\" %f;\n", mis);}
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	void setMiShinyness(const FloatID& mis){fprintf_s(mFile,"connectAttr \"");mis.write(mFile);fprintf_s(mFile,"\" \"%s.mis\";\n",mName.c_str());}
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
	/*
	<b>Roughness</b> controls how fast the brightness
	of a highlight
	decreases from the center of the highlight area to its edge
	This value ranges from 0 to 1.  Low values
	make the highlight die away quickly, giving the material
	a more polished look.  Higher values make the whole
	highlight region brighter, making the material appear
	rougher.
	*/
	FloatID getRoughness(){char buffer[4096];sprintf_s (buffer, "%s.rn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Highlight Size</b> controls how big the total highlight
	area is.
	*/
	FloatID getHighlightSize(){char buffer[4096];sprintf_s (buffer, "%s.hls",mName.c_str());return (const char*)buffer;}
	/*
	Use <b>Whiteness</b> to blend the color of the highlight
	between the base color of the material and white.  As this
	color becomes brighter, the highlight becomes more white.
	As this gets darker, the highlight color gets closer to
	the base color of the material.
	<p/>
	<i>Tip:</i> To make your material look more plastic, make
	this brighter.  To make it look more metallic, make this
	darker.
	*/
	Float3ID getWhiteness(){char buffer[4096];sprintf_s (buffer, "%s.wn",mName.c_str());return (const char*)buffer;}
	/*whiteness red value*/
	FloatID getWhitenessR(){char buffer[4096];sprintf_s (buffer, "%s.wn.wnr",mName.c_str());return (const char*)buffer;}
	/*whiteness green value*/
	FloatID getWhitenessG(){char buffer[4096];sprintf_s (buffer, "%s.wn.wng",mName.c_str());return (const char*)buffer;}
	/*whiteness blue value*/
	FloatID getWhitenessB(){char buffer[4096];sprintf_s (buffer, "%s.wn.wnb",mName.c_str());return (const char*)buffer;}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a ray direction is not exactly determined anymore.
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
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	FloatID getMiShinyness(){char buffer[4096];sprintf_s (buffer, "%s.mis",mName.c_str());return (const char*)buffer;}
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
protected:
	PhongE(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Reflect(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PHONGE_H__
