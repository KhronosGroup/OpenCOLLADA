/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VOLUMELIGHT_H__
#define __MayaDM_VOLUMELIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPointLight.h"
namespace MayaDM
{
/*
<p><pre>
        This class contains the "shape" information for volume lights.

</pre></p>
*/
class VolumeLight : public PointLight
{
public:
	/*
	The color of the light from the center to the edge of the volume.
	By changing the ramp values one can decay or change color along
	the defined light direction.
	*/
	struct ColorRange{
		float colorRange_Position;
		float3 colorRange_Color;
		unsigned int colorRange_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", colorRange_Position);
			colorRange_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", colorRange_Interp);
		}
	};
	/*
	The range of light intensity with distance from the primary axis
	of a Cylinder or Cone volume light. This has no effect if Sphere
	or Cube shape is used.
	*/
	struct Penumbra{
		float penumbra_Position;
		float penumbra_FloatValue;
		unsigned int penumbra_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", penumbra_Position);
			fprintf_s(file,"%f ", penumbra_FloatValue);
			fprintf_s(file,"%i", penumbra_Interp);
		}
	};
public:
	VolumeLight(FILE* file,const std::string& name,const std::string& parent=""):PointLight(file, name, parent, "volumeLight"){}
	virtual ~VolumeLight(){}
	/*This determines the volumetric shape of the light.*/
	void setLightShape(unsigned int lis){if(lis == 1) return; fprintf_s(mFile, "setAttr \".lis\" %i;\n", lis);}
	/*This determines the volumetric shape of the light.*/
	void setLightShape(const UnsignedintID& lis){fprintf_s(mFile,"connectAttr \"");lis.write(mFile);fprintf_s(mFile,"\" \"%s.lis\";\n",mName.c_str());}
	/*
	This determines the direction of the light
	within the volume. Outward has light moving
	away from the center of a Box or Sphere and
	away from the central axis of a Cylinder or Cone.
	Inward is the reverse of the direction. One can light
	from the outside of a sphere going in. Up Axis is like
	a directional light pointing in the positive y direction.
	Down axis points in the negative y direction.
	Note that Inward  will not always shadow in a desirable fashion.
	*/
	void setVolumeLightDir(unsigned int vld){if(vld == 0) return; fprintf_s(mFile, "setAttr \".vld\" %i;\n", vld);}
	/*
	This determines the direction of the light
	within the volume. Outward has light moving
	away from the center of a Box or Sphere and
	away from the central axis of a Cylinder or Cone.
	Inward is the reverse of the direction. One can light
	from the outside of a sphere going in. Up Axis is like
	a directional light pointing in the positive y direction.
	Down axis points in the negative y direction.
	Note that Inward  will not always shadow in a desirable fashion.
	*/
	void setVolumeLightDir(const UnsignedintID& vld){fprintf_s(mFile,"connectAttr \"");vld.write(mFile);fprintf_s(mFile,"\" \"%s.vld\";\n",mName.c_str());}
	/*
	An angular slice about the y axis. 180 and 360 degrees
	are probably the most useful settings. 180 is like slicing
	the light in half, while 360 is the full light.
	*/
	void setArc(float ac){if(ac == 360.0) return; fprintf_s(mFile, "setAttr \".ac\" %f;\n", ac);}
	/*
	An angular slice about the y axis. 180 and 360 degrees
	are probably the most useful settings. 180 is like slicing
	the light in half, while 360 is the full light.
	*/
	void setArc(const FloatID& ac){fprintf_s(mFile,"connectAttr \"");ac.write(mFile);fprintf_s(mFile,"\" \"%s.ac\";\n",mName.c_str());}
	/*
	The relative size of the one end of the cone. At a value
	of 1.0 it is a cylinder, while at 0 it is a cone.
	*/
	void setConeEndRadius(float cer){if(cer == 0.0) return; fprintf_s(mFile, "setAttr \".cer\" %f;\n", cer);}
	/*
	The relative size of the one end of the cone. At a value
	of 1.0 it is a cylinder, while at 0 it is a cone.
	*/
	void setConeEndRadius(const FloatID& cer){fprintf_s(mFile,"connectAttr \"");cer.write(mFile);fprintf_s(mFile,"\" \"%s.cer\";\n",mName.c_str());}
	/*
	The color of the light from the center to the edge of the volume.
	By changing the ramp values one can decay or change color along
	the defined light direction.
	*/
	void setColorRange(size_t crg_i,const ColorRange& crg){fprintf_s(mFile, "setAttr \".crg[%i]\" ",crg_i);crg.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The color of the light from the center to the edge of the volume.
	By changing the ramp values one can decay or change color along
	the defined light direction.
	*/
	void setColorRange(size_t crg_i,const ColorRangeID& crg){fprintf_s(mFile,"connectAttr \"");crg.write(mFile);fprintf_s(mFile,"\" \"%s.crg[%i]\";\n",mName.c_str(),crg_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColorRange_Position(size_t crg_i,float crgp){if(crgp == 0.0) return; fprintf_s(mFile, "setAttr \".crg[%i].crgp\" %f;\n", crg_i,crgp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColorRange_Position(size_t crg_i,const FloatID& crgp){fprintf_s(mFile,"connectAttr \"");crgp.write(mFile);fprintf_s(mFile,"\" \"%s.crg[%i].crgp\";\n",mName.c_str(),crg_i);}
	/*Ramp color at the sibling position*/
	void setColorRange_Color(size_t crg_i,const float3& crgc){fprintf_s(mFile, "setAttr \".crg[%i].crgc\" -type \"float3\" ",crg_i);crgc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setColorRange_Color(size_t crg_i,const Float3ID& crgc){fprintf_s(mFile,"connectAttr \"");crgc.write(mFile);fprintf_s(mFile,"\" \"%s.crg[%i].crgc\";\n",mName.c_str(),crg_i);}
	/*Ramp red channel value at the sibling position*/
	void setColorRange_ColorR(size_t crg_i,float crgcr){if(crgcr == 0.0) return; fprintf_s(mFile, "setAttr \".crg[%i].crgc.crgcr\" %f;\n", crg_i,crgcr);}
	/*Ramp red channel value at the sibling position*/
	void setColorRange_ColorR(size_t crg_i,const FloatID& crgcr){fprintf_s(mFile,"connectAttr \"");crgcr.write(mFile);fprintf_s(mFile,"\" \"%s.crg[%i].crgc.crgcr\";\n",mName.c_str(),crg_i);}
	/*Ramp green channel value at the sibling position*/
	void setColorRange_ColorG(size_t crg_i,float crgcg){if(crgcg == 0.0) return; fprintf_s(mFile, "setAttr \".crg[%i].crgc.crgcg\" %f;\n", crg_i,crgcg);}
	/*Ramp green channel value at the sibling position*/
	void setColorRange_ColorG(size_t crg_i,const FloatID& crgcg){fprintf_s(mFile,"connectAttr \"");crgcg.write(mFile);fprintf_s(mFile,"\" \"%s.crg[%i].crgc.crgcg\";\n",mName.c_str(),crg_i);}
	/*Ramp blue channel value at the sibling position*/
	void setColorRange_ColorB(size_t crg_i,float crgcb){if(crgcb == 0.0) return; fprintf_s(mFile, "setAttr \".crg[%i].crgc.crgcb\" %f;\n", crg_i,crgcb);}
	/*Ramp blue channel value at the sibling position*/
	void setColorRange_ColorB(size_t crg_i,const FloatID& crgcb){fprintf_s(mFile,"connectAttr \"");crgcb.write(mFile);fprintf_s(mFile,"\" \"%s.crg[%i].crgc.crgcb\";\n",mName.c_str(),crg_i);}
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
	void setColorRange_Interp(size_t crg_i,unsigned int crgi){if(crgi == 0) return; fprintf_s(mFile, "setAttr \".crg[%i].crgi\" %i;\n", crg_i,crgi);}
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
	void setColorRange_Interp(size_t crg_i,const UnsignedintID& crgi){fprintf_s(mFile,"connectAttr \"");crgi.write(mFile);fprintf_s(mFile,"\" \"%s.crg[%i].crgi\";\n",mName.c_str(),crg_i);}
	/*
	The range of light intensity with distance from the primary axis
	of a Cylinder or Cone volume light. This has no effect if Sphere
	or Cube shape is used.
	*/
	void setPenumbra(size_t pen_i,const Penumbra& pen){fprintf_s(mFile, "setAttr \".pen[%i]\" ",pen_i);pen.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The range of light intensity with distance from the primary axis
	of a Cylinder or Cone volume light. This has no effect if Sphere
	or Cube shape is used.
	*/
	void setPenumbra(size_t pen_i,const PenumbraID& pen){fprintf_s(mFile,"connectAttr \"");pen.write(mFile);fprintf_s(mFile,"\" \"%s.pen[%i]\";\n",mName.c_str(),pen_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setPenumbra_Position(size_t pen_i,float penp){if(penp == 0.0) return; fprintf_s(mFile, "setAttr \".pen[%i].penp\" %f;\n", pen_i,penp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setPenumbra_Position(size_t pen_i,const FloatID& penp){fprintf_s(mFile,"connectAttr \"");penp.write(mFile);fprintf_s(mFile,"\" \"%s.pen[%i].penp\";\n",mName.c_str(),pen_i);}
	/*Ramp value at the sibling position*/
	void setPenumbra_FloatValue(size_t pen_i,float penfv){if(penfv == 0.0) return; fprintf_s(mFile, "setAttr \".pen[%i].penfv\" %f;\n", pen_i,penfv);}
	/*Ramp value at the sibling position*/
	void setPenumbra_FloatValue(size_t pen_i,const FloatID& penfv){fprintf_s(mFile,"connectAttr \"");penfv.write(mFile);fprintf_s(mFile,"\" \"%s.pen[%i].penfv\";\n",mName.c_str(),pen_i);}
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
	void setPenumbra_Interp(size_t pen_i,unsigned int peni){if(peni == 0) return; fprintf_s(mFile, "setAttr \".pen[%i].peni\" %i;\n", pen_i,peni);}
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
	void setPenumbra_Interp(size_t pen_i,const UnsignedintID& peni){fprintf_s(mFile,"connectAttr \"");peni.write(mFile);fprintf_s(mFile,"\" \"%s.pen[%i].peni\";\n",mName.c_str(),pen_i);}
	/*
	If true then light affects surfaces in a non directional
	fashion. When combined with Emit Diffuse the lighting at a
	surface will be half applied using the surface/light angle,
	and half in a nondirectional fashion. If Emit Diffuse is
	off then the light will be totally omnidirectional.
	*/
	void setEmitAmbient(bool ema){if(ema == false) return; fprintf_s(mFile, "setAttr \".ema\" %i;\n", ema);}
	/*
	If true then light affects surfaces in a non directional
	fashion. When combined with Emit Diffuse the lighting at a
	surface will be half applied using the surface/light angle,
	and half in a nondirectional fashion. If Emit Diffuse is
	off then the light will be totally omnidirectional.
	*/
	void setEmitAmbient(const BoolID& ema){fprintf_s(mFile,"connectAttr \"");ema.write(mFile);fprintf_s(mFile,"\" \"%s.ema\";\n",mName.c_str());}
	/*This determines the volumetric shape of the light.*/
	UnsignedintID getLightShape(){char buffer[4096];sprintf_s (buffer, "%s.lis",mName.c_str());return (const char*)buffer;}
	/*
	This determines the direction of the light
	within the volume. Outward has light moving
	away from the center of a Box or Sphere and
	away from the central axis of a Cylinder or Cone.
	Inward is the reverse of the direction. One can light
	from the outside of a sphere going in. Up Axis is like
	a directional light pointing in the positive y direction.
	Down axis points in the negative y direction.
	Note that Inward  will not always shadow in a desirable fashion.
	*/
	UnsignedintID getVolumeLightDir(){char buffer[4096];sprintf_s (buffer, "%s.vld",mName.c_str());return (const char*)buffer;}
	/*
	An angular slice about the y axis. 180 and 360 degrees
	are probably the most useful settings. 180 is like slicing
	the light in half, while 360 is the full light.
	*/
	FloatID getArc(){char buffer[4096];sprintf_s (buffer, "%s.ac",mName.c_str());return (const char*)buffer;}
	/*
	The relative size of the one end of the cone. At a value
	of 1.0 it is a cylinder, while at 0 it is a cone.
	*/
	FloatID getConeEndRadius(){char buffer[4096];sprintf_s (buffer, "%s.cer",mName.c_str());return (const char*)buffer;}
	/*
	The color of the light from the center to the edge of the volume.
	By changing the ramp values one can decay or change color along
	the defined light direction.
	*/
	const ColorRangeID& getColorRange(size_t crg_i){char buffer[4096];sprintf_s (buffer, "%s.crg[%i]",mName.c_str(),crg_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getColorRange_Position(size_t crg_i){char buffer[4096];sprintf_s (buffer, "%s.crg[%i].crgp",mName.c_str(),crg_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getColorRange_Color(size_t crg_i){char buffer[4096];sprintf_s (buffer, "%s.crg[%i].crgc",mName.c_str(),crg_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getColorRange_ColorR(size_t crg_i){char buffer[4096];sprintf_s (buffer, "%s.crg[%i].crgc.crgcr",mName.c_str(),crg_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getColorRange_ColorG(size_t crg_i){char buffer[4096];sprintf_s (buffer, "%s.crg[%i].crgc.crgcg",mName.c_str(),crg_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getColorRange_ColorB(size_t crg_i){char buffer[4096];sprintf_s (buffer, "%s.crg[%i].crgc.crgcb",mName.c_str(),crg_i);return (const char*)buffer;}
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
	const UnsignedintID& getColorRange_Interp(size_t crg_i){char buffer[4096];sprintf_s (buffer, "%s.crg[%i].crgi",mName.c_str(),crg_i);return (const char*)buffer;}
	/*
	The range of light intensity with distance from the primary axis
	of a Cylinder or Cone volume light. This has no effect if Sphere
	or Cube shape is used.
	*/
	const PenumbraID& getPenumbra(size_t pen_i){char buffer[4096];sprintf_s (buffer, "%s.pen[%i]",mName.c_str(),pen_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getPenumbra_Position(size_t pen_i){char buffer[4096];sprintf_s (buffer, "%s.pen[%i].penp",mName.c_str(),pen_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getPenumbra_FloatValue(size_t pen_i){char buffer[4096];sprintf_s (buffer, "%s.pen[%i].penfv",mName.c_str(),pen_i);return (const char*)buffer;}
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
	const UnsignedintID& getPenumbra_Interp(size_t pen_i){char buffer[4096];sprintf_s (buffer, "%s.pen[%i].peni",mName.c_str(),pen_i);return (const char*)buffer;}
	/*
	If true then light affects surfaces in a non directional
	fashion. When combined with Emit Diffuse the lighting at a
	surface will be half applied using the surface/light angle,
	and half in a nondirectional fashion. If Emit Diffuse is
	off then the light will be totally omnidirectional.
	*/
	BoolID getEmitAmbient(){char buffer[4096];sprintf_s (buffer, "%s.ema",mName.c_str());return (const char*)buffer;}
protected:
	VolumeLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PointLight(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMELIGHT_H__
