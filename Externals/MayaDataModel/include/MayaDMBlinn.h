/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLINN_H__
#define __MayaDM_BLINN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMReflect.h"
namespace MayaDM
{
/*
<b>Blinn</b> shaders (also known as Torrance-Sparrow shaders)
  produce metallic-looking surfaces.  Use them to create materials
  like brass or aluminum.
  <p/>
  Aside from the attributes described here, the Blinn shader
  inherits many attributes from its parents <a href="reflect.html">
  Reflect</a> and <a href="lambert.html">Lambert</a>.
  <p/>
        Other kinds of shaders you can use:
  <ul>
        For unpolished surfaces, like chalk or matte paint, use a <b>Lambert</b> shader.
  <p/>
  For glass and glossy plastic surfaces, or car and bathroom mouldings,
  use a <b>PhongE</b> shader.
  <p/>
  For microgrooved surfaces like CDs, brushed metal, or hair, use an
  <b>Anisotropic</b> shader.
  </ul>
  <p/>
  In the table below, important attribute have their names indicated
  in <b>bold</b> in the description column.
*/
class Blinn : public Reflect
{
public:
public:
	Blinn(FILE* file,const std::string& name,const std::string& parent=""):Reflect(file, name, parent, "blinn"){}
	virtual ~Blinn(){}
	/*
	<b>Eccentricity</b> controls how big your specular highlights
	(also called 'hot spots') will be.  The range is 0 to 0.9999, with
	larger values making larger highlights.  Smaller values make
	objects appear more finely polished.
	*/
	void setEccentricity(float ec){if(ec == 0.3) return; fprintf_s(mFile, "setAttr \".ec\" %f;\n", ec);}
	/*
	<b>Eccentricity</b> controls how big your specular highlights
	(also called 'hot spots') will be.  The range is 0 to 0.9999, with
	larger values making larger highlights.  Smaller values make
	objects appear more finely polished.
	*/
	void setEccentricity(const FloatID& ec){fprintf_s(mFile,"connectAttr \"");ec.write(mFile);fprintf_s(mFile,"\" \"%s.ec\";\n",mName.c_str());}
	/*
	<b>Specular Rolloff</b> controls the ability of a surface to
	reflect its surroundings (the environment, other objects, or
	the Reflection Map, if any), when viewed at oblique angles.  This
	value ranges from 0 to 1, with a default of 0.7.
	<p/>
	Specular Rolloff does not affect the reflections produced
	when you render using Ray Tracing.
	<p/>
	<i>Tip:</i> to get a "wet" look (such as wet paint), use a value of around 0.7.
	*/
	void setSpecularRollOff(float sro){if(sro == 0.7) return; fprintf_s(mFile, "setAttr \".sro\" %f;\n", sro);}
	/*
	<b>Specular Rolloff</b> controls the ability of a surface to
	reflect its surroundings (the environment, other objects, or
	the Reflection Map, if any), when viewed at oblique angles.  This
	value ranges from 0 to 1, with a default of 0.7.
	<p/>
	Specular Rolloff does not affect the reflections produced
	when you render using Ray Tracing.
	<p/>
	<i>Tip:</i> to get a "wet" look (such as wet paint), use a value of around 0.7.
	*/
	void setSpecularRollOff(const FloatID& sro){fprintf_s(mFile,"connectAttr \"");sro.write(mFile);fprintf_s(mFile,"\" \"%s.sro\";\n",mName.c_str());}
	/*
	By default, Blinn Specular Rolloff effects both specular highlights
	resulting from illumination, and specular reflections of reflection
	maps.  You may wish to have this rolloff apply only to illumination
	if you are using a ClearCoat node or a home-made shading network to
	create a roll-off effect by attenuating a reflection map directly.
	To do this, change <b>reflectionRolloff</b> to false, which will
	cause the Blinn rolloff to apply only to illumination.
	*/
	void setReflectionRolloff(bool rro){if(rro == true) return; fprintf_s(mFile, "setAttr \".rro\" %i;\n", rro);}
	/*
	By default, Blinn Specular Rolloff effects both specular highlights
	resulting from illumination, and specular reflections of reflection
	maps.  You may wish to have this rolloff apply only to illumination
	if you are using a ClearCoat node or a home-made shading network to
	create a roll-off effect by attenuating a reflection map directly.
	To do this, change <b>reflectionRolloff</b> to false, which will
	cause the Blinn rolloff to apply only to illumination.
	*/
	void setReflectionRolloff(const BoolID& rro){fprintf_s(mFile,"connectAttr \"");rro.write(mFile);fprintf_s(mFile,"\" \"%s.rro\";\n",mName.c_str());}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a rays direction is not exactly determined anymore.
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
	because a rays direction is not exactly determined anymore.
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
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const float3& misc){fprintf_s(mFile, "setAttr \".misc\" -type \"float3\" ");misc.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const Float3ID& misc){fprintf_s(mFile,"connectAttr \"");misc.write(mFile);fprintf_s(mFile,"\" \"%s.misc\";\n",mName.c_str());}
	/*Photon shader specular red color parameter.*/
	void setMiSpecularColorR(float miscr){if(miscr == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscr\" %f;\n", miscr);}
	/*Photon shader specular red color parameter.*/
	void setMiSpecularColorR(const FloatID& miscr){fprintf_s(mFile,"connectAttr \"");miscr.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscr\";\n",mName.c_str());}
	/*Photon shader specular green color parameter.*/
	void setMiSpecularColorG(float miscg){if(miscg == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscg\" %f;\n", miscg);}
	/*Photon shader specular green color parameter.*/
	void setMiSpecularColorG(const FloatID& miscg){fprintf_s(mFile,"connectAttr \"");miscg.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscg\";\n",mName.c_str());}
	/*Photon shader specular blue color parameter.*/
	void setMiSpecularColorB(float miscb){if(miscb == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscb\" %f;\n", miscb);}
	/*Photon shader specular blue color parameter.*/
	void setMiSpecularColorB(const FloatID& miscb){fprintf_s(mFile,"connectAttr \"");miscb.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscb\";\n",mName.c_str());}
	/*Photon shader reflectivity parameter.*/
	void setMiReflectivity(float mirf){if(mirf == 0.5) return; fprintf_s(mFile, "setAttr \".mirf\" %f;\n", mirf);}
	/*Photon shader reflectivity parameter.*/
	void setMiReflectivity(const FloatID& mirf){fprintf_s(mFile,"connectAttr \"");mirf.write(mFile);fprintf_s(mFile,"\" \"%s.mirf\";\n",mName.c_str());}
	/*
	<b>Eccentricity</b> controls how big your specular highlights
	(also called 'hot spots') will be.  The range is 0 to 0.9999, with
	larger values making larger highlights.  Smaller values make
	objects appear more finely polished.
	*/
	FloatID getEccentricity(){char buffer[4096];sprintf_s (buffer, "%s.ec",mName.c_str());return (const char*)buffer;}
	/*
	<b>Specular Rolloff</b> controls the ability of a surface to
	reflect its surroundings (the environment, other objects, or
	the Reflection Map, if any), when viewed at oblique angles.  This
	value ranges from 0 to 1, with a default of 0.7.
	<p/>
	Specular Rolloff does not affect the reflections produced
	when you render using Ray Tracing.
	<p/>
	<i>Tip:</i> to get a "wet" look (such as wet paint), use a value of around 0.7.
	*/
	FloatID getSpecularRollOff(){char buffer[4096];sprintf_s (buffer, "%s.sro",mName.c_str());return (const char*)buffer;}
	/*
	By default, Blinn Specular Rolloff effects both specular highlights
	resulting from illumination, and specular reflections of reflection
	maps.  You may wish to have this rolloff apply only to illumination
	if you are using a ClearCoat node or a home-made shading network to
	create a roll-off effect by attenuating a reflection map directly.
	To do this, change <b>reflectionRolloff</b> to false, which will
	cause the Blinn rolloff to apply only to illumination.
	*/
	BoolID getReflectionRolloff(){char buffer[4096];sprintf_s (buffer, "%s.rro",mName.c_str());return (const char*)buffer;}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a rays direction is not exactly determined anymore.
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
	/*Photon shader specular color parameter.*/
	Float3ID getMiSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.misc",mName.c_str());return (const char*)buffer;}
	/*Photon shader specular red color parameter.*/
	FloatID getMiSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscr",mName.c_str());return (const char*)buffer;}
	/*Photon shader specular green color parameter.*/
	FloatID getMiSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscg",mName.c_str());return (const char*)buffer;}
	/*Photon shader specular blue color parameter.*/
	FloatID getMiSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscb",mName.c_str());return (const char*)buffer;}
	/*Photon shader reflectivity parameter.*/
	FloatID getMiReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.mirf",mName.c_str());return (const char*)buffer;}
protected:
	Blinn(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Reflect(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BLINN_H__
