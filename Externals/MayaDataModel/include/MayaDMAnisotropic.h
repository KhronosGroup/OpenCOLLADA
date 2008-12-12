/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANISOTROPIC_H__
#define __MayaDM_ANISOTROPIC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMReflect.h"
namespace MayaDM
{
/*
The <b>Anisotropic</b> shader simulates a surface that has
 microscopic grooves, such as compact discs, some Christmas
 tree ornaments, brushed metal, or satiny cloth.
 <p/>
 An <i>isotropic</i> material (such as Phong or Blinn) has the same
 specular properties in all directions. An anisotropic material has a
 distinguishable direction along which the surface is particularly shiny.
  <p/>
  Aside from the attributes described here, the Anisotropic shader
  inherits many attributes from its parents <a href="reflect.html">
  Reflect</a> and <a href="lambert.html">Lambert</a>.
  <p/>
        Other kinds of shaders you can use:
  <ul>
           <li>For unpolished surfaces, like chalk or matte paint, use a
           <b>Lambert</b> shader.</li>
     <li>For metallic surfaces, such as brass or aluminum, use a
     <b>Blinn</b> shader.</li>
     <li>For glossy plastic surfaces, bathroom mouldings, or
     polymers, use a <b>PhongE</b> shader.</li>
  </ul>
  <p/>
  In the table below, important attribute have their names indicated
  in <b>bold</b> in the description column.
*/
class Anisotropic : public Reflect
{
public:
public:
	Anisotropic(FILE* file,const std::string& name,const std::string& parent=""):Reflect(file, name, parent, "anisotropic"){}
	virtual ~Anisotropic(){}
	/*u-tangent at sample point*/
	void setTangentUCamera(const Float3ID& utan){fprintf_s(mFile,"connectAttr \"");utan.write(mFile);fprintf_s(mFile,"\" \"%s.utan\";\n",mName.c_str());}
	/*u-tangent x value*/
	void setTangentUCameraX(const FloatID& utnx){fprintf_s(mFile,"connectAttr \"");utnx.write(mFile);fprintf_s(mFile,"\" \"%s.utan.utnx\";\n",mName.c_str());}
	/*u-tangent y value*/
	void setTangentUCameraY(const FloatID& utny){fprintf_s(mFile,"connectAttr \"");utny.write(mFile);fprintf_s(mFile,"\" \"%s.utan.utny\";\n",mName.c_str());}
	/*u-tangent z value*/
	void setTangentUCameraZ(const FloatID& utnz){fprintf_s(mFile,"connectAttr \"");utnz.write(mFile);fprintf_s(mFile,"\" \"%s.utan.utnz\";\n",mName.c_str());}
	/*v-tangent at sample point*/
	void setTangentVCamera(const Float3ID& vtan){fprintf_s(mFile,"connectAttr \"");vtan.write(mFile);fprintf_s(mFile,"\" \"%s.vtan\";\n",mName.c_str());}
	/*v-tangent x value*/
	void setTangentVCameraX(const FloatID& vtnx){fprintf_s(mFile,"connectAttr \"");vtnx.write(mFile);fprintf_s(mFile,"\" \"%s.vtan.vtnx\";\n",mName.c_str());}
	/*v-tangent y value*/
	void setTangentVCameraY(const FloatID& vtny){fprintf_s(mFile,"connectAttr \"");vtny.write(mFile);fprintf_s(mFile,"\" \"%s.vtan.vtny\";\n",mName.c_str());}
	/*v-tangent z value*/
	void setTangentVCameraZ(const FloatID& vtnz){fprintf_s(mFile,"connectAttr \"");vtnz.write(mFile);fprintf_s(mFile,"\" \"%s.vtan.vtnz\";\n",mName.c_str());}
	/*
	<b>Spread X</b> controls how much the grooves spread out
	in the "X" direction.  It ranges from 0.1 to 100.  (The "X"
	direction is the surface U-direction, rotated counterclockwise
	by the Angle attribute)
	<p/>
	When this value is increased, the surface appears smoother
	in that direction (that is, the specular highlight in that
	direction shrink).  When the value is decreased, the
	highlight spreads out more in that direction, making the
	surface appear less smooth.
	*/
	void setSpreadX(float sprx){if(sprx == 13.0) return; fprintf_s(mFile, "setAttr \".sprx\" %f;\n", sprx);}
	/*
	<b>Spread X</b> controls how much the grooves spread out
	in the "X" direction.  It ranges from 0.1 to 100.  (The "X"
	direction is the surface U-direction, rotated counterclockwise
	by the Angle attribute)
	<p/>
	When this value is increased, the surface appears smoother
	in that direction (that is, the specular highlight in that
	direction shrink).  When the value is decreased, the
	highlight spreads out more in that direction, making the
	surface appear less smooth.
	*/
	void setSpreadX(const FloatID& sprx){fprintf_s(mFile,"connectAttr \"");sprx.write(mFile);fprintf_s(mFile,"\" \"%s.sprx\";\n",mName.c_str());}
	/*
	<b>Spread Y</b> controls how much the grooves spread out
	in the "Y" direction.  It ranges from 0.1 to 100.  (The Y
	direction is perpendicular to the "X" direction --- see
	the Spread X attribute above.)
	<p/>
	When this value is increased, the surface appears smoother
	in that direction (that is, the specular highlight in that
	direction shrink).  When the value is decreased, the
	highlight spreads out more in that direction, making the
	surface appear less smooth.
	*/
	void setSpreadY(float spry){if(spry == 3.0) return; fprintf_s(mFile, "setAttr \".spry\" %f;\n", spry);}
	/*
	<b>Spread Y</b> controls how much the grooves spread out
	in the "Y" direction.  It ranges from 0.1 to 100.  (The Y
	direction is perpendicular to the "X" direction --- see
	the Spread X attribute above.)
	<p/>
	When this value is increased, the surface appears smoother
	in that direction (that is, the specular highlight in that
	direction shrink).  When the value is decreased, the
	highlight spreads out more in that direction, making the
	surface appear less smooth.
	*/
	void setSpreadY(const FloatID& spry){fprintf_s(mFile,"connectAttr \"");spry.write(mFile);fprintf_s(mFile,"\" \"%s.spry\";\n",mName.c_str());}
	/*
	<b>Roughness</b> controls the overall roughness of the
	surface.  It ranges from 0.01 to 1.0, with larger values
	giving a rougher appearance.
	<p/>
	As this value is increased, the specular highlights are
	more spread out.  This value will also affect the reflectivity
	of the material, if Anisotropic Reflectivity is turned on.
	*/
	void setRoughness(float roug){if(roug == 0.7) return; fprintf_s(mFile, "setAttr \".roug\" %f;\n", roug);}
	/*
	<b>Roughness</b> controls the overall roughness of the
	surface.  It ranges from 0.01 to 1.0, with larger values
	giving a rougher appearance.
	<p/>
	As this value is increased, the specular highlights are
	more spread out.  This value will also affect the reflectivity
	of the material, if Anisotropic Reflectivity is turned on.
	*/
	void setRoughness(const FloatID& roug){fprintf_s(mFile,"connectAttr \"");roug.write(mFile);fprintf_s(mFile,"\" \"%s.roug\";\n",mName.c_str());}
	/*
	<b>Angle</b> defines the "X" and "Y" directions on the
	surface relative to the surface intrinsic "U" and "V"
	directions.  "X" is the "U" direction, rotated counter-clockwise
	by the Angle attribute.  These "X" and "Y" directions are
	used by the shader to place the microgrooves that control
	the anisotropic properties of the shader.<p/>
	This value ranges
	from 0 to 360 degrees.
	*/
	void setAngle(float angl){if(angl == 0.0) return; fprintf_s(mFile, "setAttr \".angl\" %f;\n", angl);}
	/*
	<b>Angle</b> defines the "X" and "Y" directions on the
	surface relative to the surface intrinsic "U" and "V"
	directions.  "X" is the "U" direction, rotated counter-clockwise
	by the Angle attribute.  These "X" and "Y" directions are
	used by the shader to place the microgrooves that control
	the anisotropic properties of the shader.<p/>
	This value ranges
	from 0 to 360 degrees.
	*/
	void setAngle(const FloatID& angl){fprintf_s(mFile,"connectAttr \"");angl.write(mFile);fprintf_s(mFile,"\" \"%s.angl\";\n",mName.c_str());}
	/*
	<b>Fresnel Refractive Index</b> affects the look of
	the anisotropic highlight. It does <i>not</i> affect the way
	light from other objects bends when
	when passing through the material, if the material is
	transparent and you are raytracing. As you increase the Fresnel
	Refractive Index, the highlight becomes brighter.
	<p/>
	For transparent objects, you may want to set the Fresnel index
	to match the object's Refractive Index.  This will give the
	most physically accurate result for the highlight.
	*/
	void setFresnelRefractiveIndex(float frfi){if(frfi == 6.0) return; fprintf_s(mFile, "setAttr \".frfi\" %f;\n", frfi);}
	/*
	<b>Fresnel Refractive Index</b> affects the look of
	the anisotropic highlight. It does <i>not</i> affect the way
	light from other objects bends when
	when passing through the material, if the material is
	transparent and you are raytracing. As you increase the Fresnel
	Refractive Index, the highlight becomes brighter.
	<p/>
	For transparent objects, you may want to set the Fresnel index
	to match the object's Refractive Index.  This will give the
	most physically accurate result for the highlight.
	*/
	void setFresnelRefractiveIndex(const FloatID& frfi){fprintf_s(mFile,"connectAttr \"");frfi.write(mFile);fprintf_s(mFile,"\" \"%s.frfi\";\n",mName.c_str());}
	/*
	If <b>Anisotropic Reflectivity</b> is turned on, then the
	reflectivity of the material is calculated directly from its
	roughness.
	<p/>
	If this attribute is turned off, the value in Reflectivity
	is used instead.
	*/
	void setAnisotropicReflectivity(bool arfl){if(arfl == true) return; fprintf_s(mFile, "setAttr \".arfl\" %i;\n", arfl);}
	/*
	If <b>Anisotropic Reflectivity</b> is turned on, then the
	reflectivity of the material is calculated directly from its
	roughness.
	<p/>
	If this attribute is turned off, the value in Reflectivity
	is used instead.
	*/
	void setAnisotropicReflectivity(const BoolID& arfl){fprintf_s(mFile,"connectAttr \"");arfl.write(mFile);fprintf_s(mFile,"\" \"%s.arfl\";\n",mName.c_str());}
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
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const float3& misc){fprintf_s(mFile, "setAttr \".misc\" -type \"float3\" ");misc.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const Float3ID& misc){fprintf_s(mFile,"connectAttr \"");misc.write(mFile);fprintf_s(mFile,"\" \"%s.misc\";\n",mName.c_str());}
	/*Red component of photon shader specular color.*/
	void setMiSpecularColorR(float miscr){if(miscr == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscr\" %f;\n", miscr);}
	/*Red component of photon shader specular color.*/
	void setMiSpecularColorR(const FloatID& miscr){fprintf_s(mFile,"connectAttr \"");miscr.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscr\";\n",mName.c_str());}
	/*Green component of photon shader specular color.*/
	void setMiSpecularColorG(float miscg){if(miscg == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscg\" %f;\n", miscg);}
	/*Green component of photon shader specular color.*/
	void setMiSpecularColorG(const FloatID& miscg){fprintf_s(mFile,"connectAttr \"");miscg.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscg\";\n",mName.c_str());}
	/*Blue component of photon shader specular color.*/
	void setMiSpecularColorB(float miscb){if(miscb == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscb\" %f;\n", miscb);}
	/*Blue component of photon shader specular color.*/
	void setMiSpecularColorB(const FloatID& miscb){fprintf_s(mFile,"connectAttr \"");miscb.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscb\";\n",mName.c_str());}
	/*Photon shader reflectivity parameter.*/
	void setMiReflectivity(float mirf){if(mirf == 0.5) return; fprintf_s(mFile, "setAttr \".mirf\" %f;\n", mirf);}
	/*Photon shader reflectivity parameter.*/
	void setMiReflectivity(const FloatID& mirf){fprintf_s(mFile,"connectAttr \"");mirf.write(mFile);fprintf_s(mFile,"\" \"%s.mirf\";\n",mName.c_str());}
	/*u-tangent at sample point*/
	Float3ID getTangentUCamera(){char buffer[4096];sprintf_s (buffer, "%s.utan",mName.c_str());return (const char*)buffer;}
	/*u-tangent x value*/
	FloatID getTangentUCameraX(){char buffer[4096];sprintf_s (buffer, "%s.utan.utnx",mName.c_str());return (const char*)buffer;}
	/*u-tangent y value*/
	FloatID getTangentUCameraY(){char buffer[4096];sprintf_s (buffer, "%s.utan.utny",mName.c_str());return (const char*)buffer;}
	/*u-tangent z value*/
	FloatID getTangentUCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.utan.utnz",mName.c_str());return (const char*)buffer;}
	/*v-tangent at sample point*/
	Float3ID getTangentVCamera(){char buffer[4096];sprintf_s (buffer, "%s.vtan",mName.c_str());return (const char*)buffer;}
	/*v-tangent x value*/
	FloatID getTangentVCameraX(){char buffer[4096];sprintf_s (buffer, "%s.vtan.vtnx",mName.c_str());return (const char*)buffer;}
	/*v-tangent y value*/
	FloatID getTangentVCameraY(){char buffer[4096];sprintf_s (buffer, "%s.vtan.vtny",mName.c_str());return (const char*)buffer;}
	/*v-tangent z value*/
	FloatID getTangentVCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.vtan.vtnz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Spread X</b> controls how much the grooves spread out
	in the "X" direction.  It ranges from 0.1 to 100.  (The "X"
	direction is the surface U-direction, rotated counterclockwise
	by the Angle attribute)
	<p/>
	When this value is increased, the surface appears smoother
	in that direction (that is, the specular highlight in that
	direction shrink).  When the value is decreased, the
	highlight spreads out more in that direction, making the
	surface appear less smooth.
	*/
	FloatID getSpreadX(){char buffer[4096];sprintf_s (buffer, "%s.sprx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Spread Y</b> controls how much the grooves spread out
	in the "Y" direction.  It ranges from 0.1 to 100.  (The Y
	direction is perpendicular to the "X" direction --- see
	the Spread X attribute above.)
	<p/>
	When this value is increased, the surface appears smoother
	in that direction (that is, the specular highlight in that
	direction shrink).  When the value is decreased, the
	highlight spreads out more in that direction, making the
	surface appear less smooth.
	*/
	FloatID getSpreadY(){char buffer[4096];sprintf_s (buffer, "%s.spry",mName.c_str());return (const char*)buffer;}
	/*
	<b>Roughness</b> controls the overall roughness of the
	surface.  It ranges from 0.01 to 1.0, with larger values
	giving a rougher appearance.
	<p/>
	As this value is increased, the specular highlights are
	more spread out.  This value will also affect the reflectivity
	of the material, if Anisotropic Reflectivity is turned on.
	*/
	FloatID getRoughness(){char buffer[4096];sprintf_s (buffer, "%s.roug",mName.c_str());return (const char*)buffer;}
	/*
	<b>Angle</b> defines the "X" and "Y" directions on the
	surface relative to the surface intrinsic "U" and "V"
	directions.  "X" is the "U" direction, rotated counter-clockwise
	by the Angle attribute.  These "X" and "Y" directions are
	used by the shader to place the microgrooves that control
	the anisotropic properties of the shader.<p/>
	This value ranges
	from 0 to 360 degrees.
	*/
	FloatID getAngle(){char buffer[4096];sprintf_s (buffer, "%s.angl",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fresnel Refractive Index</b> affects the look of
	the anisotropic highlight. It does <i>not</i> affect the way
	light from other objects bends when
	when passing through the material, if the material is
	transparent and you are raytracing. As you increase the Fresnel
	Refractive Index, the highlight becomes brighter.
	<p/>
	For transparent objects, you may want to set the Fresnel index
	to match the object's Refractive Index.  This will give the
	most physically accurate result for the highlight.
	*/
	FloatID getFresnelRefractiveIndex(){char buffer[4096];sprintf_s (buffer, "%s.frfi",mName.c_str());return (const char*)buffer;}
	/*
	If <b>Anisotropic Reflectivity</b> is turned on, then the
	reflectivity of the material is calculated directly from its
	roughness.
	<p/>
	If this attribute is turned off, the value in Reflectivity
	is used instead.
	*/
	BoolID getAnisotropicReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.arfl",mName.c_str());return (const char*)buffer;}
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
	/*Photon shader angle parameter to control direction of anisotropic feature.*/
	FloatID getMiAngle(){char buffer[4096];sprintf_s (buffer, "%s.mia",mName.c_str());return (const char*)buffer;}
	/*Photon shader x spread parameter to control size of anisotropic feature in x direction.*/
	FloatID getMiSpreadX(){char buffer[4096];sprintf_s (buffer, "%s.misx",mName.c_str());return (const char*)buffer;}
	/*Photon shader spread parameter to control size of anisotropic feature in y direction.*/
	FloatID getMiSpreadY(){char buffer[4096];sprintf_s (buffer, "%s.misy",mName.c_str());return (const char*)buffer;}
	/*Photon shader specular color parameter.*/
	Float3ID getMiSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.misc",mName.c_str());return (const char*)buffer;}
	/*Red component of photon shader specular color.*/
	FloatID getMiSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscr",mName.c_str());return (const char*)buffer;}
	/*Green component of photon shader specular color.*/
	FloatID getMiSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscg",mName.c_str());return (const char*)buffer;}
	/*Blue component of photon shader specular color.*/
	FloatID getMiSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscb",mName.c_str());return (const char*)buffer;}
	/*Photon shader reflectivity parameter.*/
	FloatID getMiReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.mirf",mName.c_str());return (const char*)buffer;}
protected:
	Anisotropic(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Reflect(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ANISOTROPIC_H__
