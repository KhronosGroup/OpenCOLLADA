/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PHONG_H__
#define __MayaDM_PHONG_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMReflect.h"
namespace MayaDM
{
/*
Use a <b>Phong</b> shader to produce
  glossy plastic-looking sufaces.  Phong shaders are good for
  modeling things like car and bathroom mouldings, and many
  high-tech polymers and plastics.
  <p/>
  Aside from the attributes described here, the Phong shader
  inherits many attributes from its parents <a href="reflect.html">
  Reflect</a> and <a href="lambert.html">Lambert</a>.
  <p/>
  Maya also has a PhongE shader, which is very similar, and can
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
class Phong : public Reflect
{
public:
public:
	Phong(FILE* file,const std::string& name,const std::string& parent=""):Reflect(file, name, parent, "phong"){}
	virtual ~Phong(){}
	/*
	<b>Cosine Power</b> is used to control the "tightness" of
	the specular highlights (also called 'hot spots') on the surface.
	The minimum value is 2.
	The higher the value, the more tighly focussed (smaller) is
	the highlight.
	*/
	void setCosinePower(float cp){if(cp == 20.0) return; fprintf_s(mFile, "setAttr \".cp\" %f;\n", cp);}
	/*
	<b>Cosine Power</b> is used to control the "tightness" of
	the specular highlights (also called 'hot spots') on the surface.
	The minimum value is 2.
	The higher the value, the more tighly focussed (smaller) is
	the highlight.
	*/
	void setCosinePower(const FloatID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp\";\n",mName.c_str());}
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
	<b>Cosine Power</b> is used to control the "tightness" of
	the specular highlights (also called 'hot spots') on the surface.
	The minimum value is 2.
	The higher the value, the more tighly focussed (smaller) is
	the highlight.
	*/
	FloatID getCosinePower(){char buffer[4096];sprintf_s (buffer, "%s.cp",mName.c_str());return (const char*)buffer;}
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
	Phong(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Reflect(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PHONG_H__
