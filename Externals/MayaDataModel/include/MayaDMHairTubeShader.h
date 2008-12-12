/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HAIRTUBESHADER_H__
#define __MayaDM_HAIRTUBESHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMReflect.h"
namespace MayaDM
{
/*
<b>HairTubeShader</b> simulates a thin tube, where the
 width of the tube is small enough that local shading effects
 can be ignored. The surface normal of the tube is ignored and
 all shading derives from the view and the tube direction. The
 direction of the tube is assumed to be either the u or the v tangent.
 Because the highlights are spread across the entire tube width, the
 render of objects like fine hairs do not require as high antialiasing
 levels as one would need using shaders like Blinn or Phong.
  <p/>
  Aside from the attributes described here, the Anisotropic shader
  inherits many attributes from its parents <a href="reflect.html">
  Reflect</a> and <a href="lambert.html">Lambert</a>.
        The lambert portion of this shading is defined with translucence and
  no diffuse to better handle hair shading.
  <p/>
  In the table below, important attribute have their names indicated
  in <b>bold</b> in the description column.
*/
class HairTubeShader : public Reflect
{
public:
	/*
	This scales, or multiplies, the base color of the surface.
	This allows one to vary the color from root to tip of hair tubes.
	The ramp is mapped along U or V of the surface depending on
	the tube direction attribute.
	*/
	struct ColorScale{
		float colorScale_Position;
		float3 colorScale_Color;
		unsigned int colorScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", colorScale_Position);
			colorScale_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", colorScale_Interp);
		}
	};
public:
	HairTubeShader(FILE* file,const std::string& name,const std::string& parent=""):Reflect(file, name, parent, "hairTubeShader"){}
	virtual ~HairTubeShader(){}
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
	/*The UV coords of the current sample point*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setUCoord(const FloatID& uvu){fprintf_s(mFile,"connectAttr \"");uvu.write(mFile);fprintf_s(mFile,"\" \"%s.uv.uvu\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setVCoord(const FloatID& uvv){fprintf_s(mFile,"connectAttr \"");uvv.write(mFile);fprintf_s(mFile,"\" \"%s.uv.uvv\";\n",mName.c_str());}
	/*
	The shading assumes that the primary direction of the tube
	lines up with either the U or V parameterization. This
	parameter should be set to match the tube for correct shading.
	0 - The U tangent defines the primary tube axis
	1 - The V tangent defines the primary tube axis
	*/
	void setTubeDirection(unsigned int tdr){if(tdr == 0) return; fprintf_s(mFile, "setAttr \".tdr\" %i;\n", tdr);}
	/*
	The shading assumes that the primary direction of the tube
	lines up with either the U or V parameterization. This
	parameter should be set to match the tube for correct shading.
	0 - The U tangent defines the primary tube axis
	1 - The V tangent defines the primary tube axis
	*/
	void setTubeDirection(const UnsignedintID& tdr){fprintf_s(mFile,"connectAttr \"");tdr.write(mFile);fprintf_s(mFile,"\" \"%s.tdr\";\n",mName.c_str());}
	/*
	This scales, or multiplies, the base color of the surface.
	This allows one to vary the color from root to tip of hair tubes.
	The ramp is mapped along U or V of the surface depending on
	the tube direction attribute.
	*/
	void setColorScale(size_t cls_i,const ColorScale& cls){fprintf_s(mFile, "setAttr \".cls[%i]\" ",cls_i);cls.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This scales, or multiplies, the base color of the surface.
	This allows one to vary the color from root to tip of hair tubes.
	The ramp is mapped along U or V of the surface depending on
	the tube direction attribute.
	*/
	void setColorScale(size_t cls_i,const ColorScaleID& cls){fprintf_s(mFile,"connectAttr \"");cls.write(mFile);fprintf_s(mFile,"\" \"%s.cls[%i]\";\n",mName.c_str(),cls_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColorScale_Position(size_t cls_i,float clsp){if(clsp == 0.0) return; fprintf_s(mFile, "setAttr \".cls[%i].clsp\" %f;\n", cls_i,clsp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColorScale_Position(size_t cls_i,const FloatID& clsp){fprintf_s(mFile,"connectAttr \"");clsp.write(mFile);fprintf_s(mFile,"\" \"%s.cls[%i].clsp\";\n",mName.c_str(),cls_i);}
	/*Ramp color at the sibling position*/
	void setColorScale_Color(size_t cls_i,const float3& clsc){fprintf_s(mFile, "setAttr \".cls[%i].clsc\" -type \"float3\" ",cls_i);clsc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setColorScale_Color(size_t cls_i,const Float3ID& clsc){fprintf_s(mFile,"connectAttr \"");clsc.write(mFile);fprintf_s(mFile,"\" \"%s.cls[%i].clsc\";\n",mName.c_str(),cls_i);}
	/*Ramp red channel value at the sibling position*/
	void setColorScale_ColorR(size_t cls_i,float clscr){if(clscr == 0.0) return; fprintf_s(mFile, "setAttr \".cls[%i].clsc.clscr\" %f;\n", cls_i,clscr);}
	/*Ramp red channel value at the sibling position*/
	void setColorScale_ColorR(size_t cls_i,const FloatID& clscr){fprintf_s(mFile,"connectAttr \"");clscr.write(mFile);fprintf_s(mFile,"\" \"%s.cls[%i].clsc.clscr\";\n",mName.c_str(),cls_i);}
	/*Ramp green channel value at the sibling position*/
	void setColorScale_ColorG(size_t cls_i,float clscg){if(clscg == 0.0) return; fprintf_s(mFile, "setAttr \".cls[%i].clsc.clscg\" %f;\n", cls_i,clscg);}
	/*Ramp green channel value at the sibling position*/
	void setColorScale_ColorG(size_t cls_i,const FloatID& clscg){fprintf_s(mFile,"connectAttr \"");clscg.write(mFile);fprintf_s(mFile,"\" \"%s.cls[%i].clsc.clscg\";\n",mName.c_str(),cls_i);}
	/*Ramp blue channel value at the sibling position*/
	void setColorScale_ColorB(size_t cls_i,float clscb){if(clscb == 0.0) return; fprintf_s(mFile, "setAttr \".cls[%i].clsc.clscb\" %f;\n", cls_i,clscb);}
	/*Ramp blue channel value at the sibling position*/
	void setColorScale_ColorB(size_t cls_i,const FloatID& clscb){fprintf_s(mFile,"connectAttr \"");clscb.write(mFile);fprintf_s(mFile,"\" \"%s.cls[%i].clsc.clscb\";\n",mName.c_str(),cls_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setColorScale_Interp(size_t cls_i,unsigned int clsi){if(clsi == 0) return; fprintf_s(mFile, "setAttr \".cls[%i].clsi\" %i;\n", cls_i,clsi);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setColorScale_Interp(size_t cls_i,const UnsignedintID& clsi){fprintf_s(mFile,"connectAttr \"");clsi.write(mFile);fprintf_s(mFile,"\" \"%s.cls[%i].clsi\";\n",mName.c_str(),cls_i);}
	/*
	<b>Specular Power</b> is used to control the "tightness" of
	the specular highlights (also called 'hot spots') on the surface.
	The minimum value is 2.
	The higher the value, the more tighly focussed (smaller) is
	the highlight, simulating smoother hair.
	*/
	void setSpecularPower(float sp){if(sp == 20.0) return; fprintf_s(mFile, "setAttr \".sp\" %f;\n", sp);}
	/*
	<b>Specular Power</b> is used to control the "tightness" of
	the specular highlights (also called 'hot spots') on the surface.
	The minimum value is 2.
	The higher the value, the more tighly focussed (smaller) is
	the highlight, simulating smoother hair.
	*/
	void setSpecularPower(const FloatID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*
	<b>Specular Shift</b> is used to control the offset of the
	specular highlight along the tube. This models the way hairs
	are composed of conical segments, somewhat like a Chinese pagoda.
	As a result the surface is not exactly parallel to the tube direction,
	which results in a slight shift of the highlight. The units represent
	degrees of incline relative to the primary tube direction.
	*/
	void setSpecularShift(float ssh){if(ssh == 5.0) return; fprintf_s(mFile, "setAttr \".ssh\" %f;\n", ssh);}
	/*
	<b>Specular Shift</b> is used to control the offset of the
	specular highlight along the tube. This models the way hairs
	are composed of conical segments, somewhat like a Chinese pagoda.
	As a result the surface is not exactly parallel to the tube direction,
	which results in a slight shift of the highlight. The units represent
	degrees of incline relative to the primary tube direction.
	*/
	void setSpecularShift(const FloatID& ssh){fprintf_s(mFile,"connectAttr \"");ssh.write(mFile);fprintf_s(mFile,"\" \"%s.ssh\";\n",mName.c_str());}
	/*
	<b>Scatter Power</b> is used to control the "tightness" of
	the highlights caused by light bouncing around inside hair tubes.
	These highlights pick up the color of the hair.
	The higher the value, the more tighly focussed (smaller) is
	the highlight, simulating smoother hair. For best results this
	value should be lower than the specular power.
	*/
	void setScatterPower(float scp){if(scp == 5.0) return; fprintf_s(mFile, "setAttr \".scp\" %f;\n", scp);}
	/*
	<b>Scatter Power</b> is used to control the "tightness" of
	the highlights caused by light bouncing around inside hair tubes.
	These highlights pick up the color of the hair.
	The higher the value, the more tighly focussed (smaller) is
	the highlight, simulating smoother hair. For best results this
	value should be lower than the specular power.
	*/
	void setScatterPower(const FloatID& scp){fprintf_s(mFile,"connectAttr \"");scp.write(mFile);fprintf_s(mFile,"\" \"%s.scp\";\n",mName.c_str());}
	/*
	<b>Scatter</b> controls how much specular interscattering
	occurs within the hair, where the light bounces inside the
	simulated hair and emerges like a spread out colored highlight.
	This is like a broad specular highlight
	that picks up the surface color, and the effect is particularily
	noticable in brown hair, where one sees large brown highlight regions.
	The general diffuse contribution is near black outside these regions.
	*/
	void setScatter(float sct){if(sct == 0.2) return; fprintf_s(mFile, "setAttr \".sct\" %f;\n", sct);}
	/*
	<b>Scatter</b> controls how much specular interscattering
	occurs within the hair, where the light bounces inside the
	simulated hair and emerges like a spread out colored highlight.
	This is like a broad specular highlight
	that picks up the surface color, and the effect is particularily
	noticable in brown hair, where one sees large brown highlight regions.
	The general diffuse contribution is near black outside these regions.
	*/
	void setScatter(const FloatID& sct){fprintf_s(mFile,"connectAttr \"");sct.write(mFile);fprintf_s(mFile,"\" \"%s.sct\";\n",mName.c_str());}
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
	per-object samples and the Render Globals sample setting supersample in image space.
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
	per-object samples and the Render Globals sample setting supersample in image space.
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
	/*The UV coords of the current sample point*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.uvu",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.uvv",mName.c_str());return (const char*)buffer;}
	/*
	The shading assumes that the primary direction of the tube
	lines up with either the U or V parameterization. This
	parameter should be set to match the tube for correct shading.
	0 - The U tangent defines the primary tube axis
	1 - The V tangent defines the primary tube axis
	*/
	UnsignedintID getTubeDirection(){char buffer[4096];sprintf_s (buffer, "%s.tdr",mName.c_str());return (const char*)buffer;}
	/*
	This scales, or multiplies, the base color of the surface.
	This allows one to vary the color from root to tip of hair tubes.
	The ramp is mapped along U or V of the surface depending on
	the tube direction attribute.
	*/
	const ColorScaleID& getColorScale(size_t cls_i){char buffer[4096];sprintf_s (buffer, "%s.cls[%i]",mName.c_str(),cls_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getColorScale_Position(size_t cls_i){char buffer[4096];sprintf_s (buffer, "%s.cls[%i].clsp",mName.c_str(),cls_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getColorScale_Color(size_t cls_i){char buffer[4096];sprintf_s (buffer, "%s.cls[%i].clsc",mName.c_str(),cls_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getColorScale_ColorR(size_t cls_i){char buffer[4096];sprintf_s (buffer, "%s.cls[%i].clsc.clscr",mName.c_str(),cls_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getColorScale_ColorG(size_t cls_i){char buffer[4096];sprintf_s (buffer, "%s.cls[%i].clsc.clscg",mName.c_str(),cls_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getColorScale_ColorB(size_t cls_i){char buffer[4096];sprintf_s (buffer, "%s.cls[%i].clsc.clscb",mName.c_str(),cls_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getColorScale_Interp(size_t cls_i){char buffer[4096];sprintf_s (buffer, "%s.cls[%i].clsi",mName.c_str(),cls_i);return (const char*)buffer;}
	/*
	<b>Specular Power</b> is used to control the "tightness" of
	the specular highlights (also called 'hot spots') on the surface.
	The minimum value is 2.
	The higher the value, the more tighly focussed (smaller) is
	the highlight, simulating smoother hair.
	*/
	FloatID getSpecularPower(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Specular Shift</b> is used to control the offset of the
	specular highlight along the tube. This models the way hairs
	are composed of conical segments, somewhat like a Chinese pagoda.
	As a result the surface is not exactly parallel to the tube direction,
	which results in a slight shift of the highlight. The units represent
	degrees of incline relative to the primary tube direction.
	*/
	FloatID getSpecularShift(){char buffer[4096];sprintf_s (buffer, "%s.ssh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Scatter Power</b> is used to control the "tightness" of
	the highlights caused by light bouncing around inside hair tubes.
	These highlights pick up the color of the hair.
	The higher the value, the more tighly focussed (smaller) is
	the highlight, simulating smoother hair. For best results this
	value should be lower than the specular power.
	*/
	FloatID getScatterPower(){char buffer[4096];sprintf_s (buffer, "%s.scp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Scatter</b> controls how much specular interscattering
	occurs within the hair, where the light bounces inside the
	simulated hair and emerges like a spread out colored highlight.
	This is like a broad specular highlight
	that picks up the surface color, and the effect is particularily
	noticable in brown hair, where one sees large brown highlight regions.
	The general diffuse contribution is near black outside these regions.
	*/
	FloatID getScatter(){char buffer[4096];sprintf_s (buffer, "%s.sct",mName.c_str());return (const char*)buffer;}
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
	per-object samples and the Render Globals sample setting supersample in image space.
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
	/*Red component.*/
	FloatID getMiSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscb",mName.c_str());return (const char*)buffer;}
	/*Photon shader reflectivity parameter.*/
	FloatID getMiReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.mirf",mName.c_str());return (const char*)buffer;}
protected:
	HairTubeShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Reflect(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HAIRTUBESHADER_H__
