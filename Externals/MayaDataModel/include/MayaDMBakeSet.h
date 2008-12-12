/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BAKESET_H__
#define __MayaDM_BAKESET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectSet.h"
namespace MayaDM
{
/*
Bake sets are an abstraction derived from objectSet, which allows objects
  to be collected together and associated with various parameters which
  drive the baking process.  For more detailed descriptions, see the
  concrete subclasses, textureBakeSet and vertexBakeSet.
  <p/>
*/
class BakeSet : public ObjectSet
{
public:
public:
	BakeSet(FILE* file,const std::string& name,const std::string& parent=""):ObjectSet(file, name, parent, "bakeSet"){}
	virtual ~BakeSet(){}
	/*Activate this option to bake an alpha channel in addition to RGB.*/
	void setBakeAlpha(bool alpha){if(alpha == 0) return; fprintf_s(mFile, "setAttr \".alpha\" %i;\n", alpha);}
	/*Activate this option to bake an alpha channel in addition to RGB.*/
	void setBakeAlpha(const BoolID& alpha){fprintf_s(mFile,"connectAttr \"");alpha.write(mFile);fprintf_s(mFile,"\" \"%s.alpha\";\n",mName.c_str());}
	/*
	When baking an alpha channel, this attribute determines what
	the data in the alpha channel represents.  The "Pass Through"
	options is probably only of interest for custom shader usage
	within Maya.  The returned baked 'color' alpha component is
	retained, and especially not further affected by Maya's matte
	channel. Custom shaders usually set the fourth component of a
	mental ray 'color' to provide the alpha channel.
	*/
	void setAlphaMode(unsigned int mode){if(mode == 1) return; fprintf_s(mFile, "setAttr \".mode\" %i;\n", mode);}
	/*
	When baking an alpha channel, this attribute determines what
	the data in the alpha channel represents.  The "Pass Through"
	options is probably only of interest for custom shader usage
	within Maya.  The returned baked 'color' alpha component is
	retained, and especially not further affected by Maya's matte
	channel. Custom shaders usually set the fourth component of a
	mental ray 'color' to provide the alpha channel.
	*/
	void setAlphaMode(const UnsignedintID& mode){fprintf_s(mFile,"connectAttr \"");mode.write(mFile);fprintf_s(mFile,"\" \"%s.mode\";\n",mName.c_str());}
	/*
	<b>occlusionRays</b> and <b>occlusionFalloff</b>
	controls "Occlusion" color mode.
	<b>occlusionRays</b> specifies number of occlusion rays to trace per sample point.
	*/
	void setOcclusionRays(int mor){if(mor == 64) return; fprintf_s(mFile, "setAttr \".mor\" %i;\n", mor);}
	/*
	<b>occlusionRays</b> and <b>occlusionFalloff</b>
	controls "Occlusion" color mode.
	<b>occlusionRays</b> specifies number of occlusion rays to trace per sample point.
	*/
	void setOcclusionRays(const IntID& mor){fprintf_s(mFile,"connectAttr \"");mor.write(mFile);fprintf_s(mFile,"\" \"%s.mor\";\n",mName.c_str());}
	/*
	<b>occlusionRays</b> and <b>occlusionFalloff</b>
	controls "Occlusion" color mode.
	<b>occlusionFalloff</b> specifies the maximum length of an occlusion ray.
	Rays longer than the falloff are considered "un-occluded".
	*/
	void setOcclusionFalloff(float mof){if(mof == 0) return; fprintf_s(mFile, "setAttr \".mof\" %f;\n", mof);}
	/*
	<b>occlusionRays</b> and <b>occlusionFalloff</b>
	controls "Occlusion" color mode.
	<b>occlusionFalloff</b> specifies the maximum length of an occlusion ray.
	Rays longer than the falloff are considered "un-occluded".
	*/
	void setOcclusionFalloff(const FloatID& mof){fprintf_s(mFile,"connectAttr \"");mof.write(mFile);fprintf_s(mFile,"\" \"%s.mof\";\n",mName.c_str());}
	/*
	The lighting information to be computed.
	<b>Light and Color</b> computes both the incoming light and surface color
	to produce the final color.
	<b>Only Light</b> computes incoming light (both direct and indirect lighting).
	<b>Only Global Illumination</b> gives global illumination(indirect light) only.
	<b>Occlusion</b> computes grey scale value of how much of light reaches the point.
	<b>Custom Shader</b> relies on <b>customShader</b> to compute data.
	*/
	void setColorMode(unsigned int clm){if(clm == 0) return; fprintf_s(mFile, "setAttr \".clm\" %i;\n", clm);}
	/*
	The lighting information to be computed.
	<b>Light and Color</b> computes both the incoming light and surface color
	to produce the final color.
	<b>Only Light</b> computes incoming light (both direct and indirect lighting).
	<b>Only Global Illumination</b> gives global illumination(indirect light) only.
	<b>Occlusion</b> computes grey scale value of how much of light reaches the point.
	<b>Custom Shader</b> relies on <b>customShader</b> to compute data.
	*/
	void setColorMode(const UnsignedintID& clm){fprintf_s(mFile,"connectAttr \"");clm.write(mFile);fprintf_s(mFile,"\" \"%s.clm\";\n",mName.c_str());}
	/*
	Reflection is view dependent because reflection changes depending on viewing angle.
	Baking the reflection from a particular viewing angle could be undesirable,
	especially if the lightmap information is used in camera-fly environment.
	If <b>OrthogonalReflection</b> is on,
	a surface normal is used to compute reflection instead of eye ray.
	The reflection becomes more like an environment map.
	*/
	void setOrthogonalReflection(bool orf){if(orf == 0) return; fprintf_s(mFile, "setAttr \".orf\" %i;\n", orf);}
	/*
	Reflection is view dependent because reflection changes depending on viewing angle.
	Baking the reflection from a particular viewing angle could be undesirable,
	especially if the lightmap information is used in camera-fly environment.
	If <b>OrthogonalReflection</b> is on,
	a surface normal is used to compute reflection instead of eye ray.
	The reflection becomes more like an environment map.
	*/
	void setOrthogonalReflection(const BoolID& orf){fprintf_s(mFile,"connectAttr \"");orf.write(mFile);fprintf_s(mFile,"\" \"%s.orf\";\n",mName.c_str());}
	/*Specify the normal vector direction to be used during lighting calculation.*/
	void setNormalDirection(unsigned int ndr){if(ndr == 1) return; fprintf_s(mFile, "setAttr \".ndr\" %i;\n", ndr);}
	/*Specify the normal vector direction to be used during lighting calculation.*/
	void setNormalDirection(const UnsignedintID& ndr){fprintf_s(mFile,"connectAttr \"");ndr.write(mFile);fprintf_s(mFile,"\" \"%s.ndr\";\n",mName.c_str());}
	/*
	Connect a cusom material shader to <b>customShader</b>
	to customize the lighting calculation.
	The shader is called during baking process,
	and is responsible for computing lighting.
	For texture baking, the shader should return
	a single color value per vertex,
	which will then be interpolated within a triangle
	and be written to a lightmap texture.
	For vertex baking, the shader can return
	more than a single color value,
	provided that the output structure of the shader is fixed.
	The data computed during vertex baking is accessible after baking is complete.
	*/
	void setCustomShader(const MessageID& csh){fprintf_s(mFile,"connectAttr \"");csh.write(mFile);fprintf_s(mFile,"\" \"%s.csh\";\n",mName.c_str());}
	/*Activate this option to bake an alpha channel in addition to RGB.*/
	BoolID getBakeAlpha(){char buffer[4096];sprintf_s (buffer, "%s.alpha",mName.c_str());return (const char*)buffer;}
	/*
	When baking an alpha channel, this attribute determines what
	the data in the alpha channel represents.  The "Pass Through"
	options is probably only of interest for custom shader usage
	within Maya.  The returned baked 'color' alpha component is
	retained, and especially not further affected by Maya's matte
	channel. Custom shaders usually set the fourth component of a
	mental ray 'color' to provide the alpha channel.
	*/
	UnsignedintID getAlphaMode(){char buffer[4096];sprintf_s (buffer, "%s.mode",mName.c_str());return (const char*)buffer;}
	/*
	<b>occlusionRays</b> and <b>occlusionFalloff</b>
	controls "Occlusion" color mode.
	<b>occlusionRays</b> specifies number of occlusion rays to trace per sample point.
	*/
	IntID getOcclusionRays(){char buffer[4096];sprintf_s (buffer, "%s.mor",mName.c_str());return (const char*)buffer;}
	/*
	<b>occlusionRays</b> and <b>occlusionFalloff</b>
	controls "Occlusion" color mode.
	<b>occlusionFalloff</b> specifies the maximum length of an occlusion ray.
	Rays longer than the falloff are considered "un-occluded".
	*/
	FloatID getOcclusionFalloff(){char buffer[4096];sprintf_s (buffer, "%s.mof",mName.c_str());return (const char*)buffer;}
	/*
	The lighting information to be computed.
	<b>Light and Color</b> computes both the incoming light and surface color
	to produce the final color.
	<b>Only Light</b> computes incoming light (both direct and indirect lighting).
	<b>Only Global Illumination</b> gives global illumination(indirect light) only.
	<b>Occlusion</b> computes grey scale value of how much of light reaches the point.
	<b>Custom Shader</b> relies on <b>customShader</b> to compute data.
	*/
	UnsignedintID getColorMode(){char buffer[4096];sprintf_s (buffer, "%s.clm",mName.c_str());return (const char*)buffer;}
	/*
	Reflection is view dependent because reflection changes depending on viewing angle.
	Baking the reflection from a particular viewing angle could be undesirable,
	especially if the lightmap information is used in camera-fly environment.
	If <b>OrthogonalReflection</b> is on,
	a surface normal is used to compute reflection instead of eye ray.
	The reflection becomes more like an environment map.
	*/
	BoolID getOrthogonalReflection(){char buffer[4096];sprintf_s (buffer, "%s.orf",mName.c_str());return (const char*)buffer;}
	/*Specify the normal vector direction to be used during lighting calculation.*/
	UnsignedintID getNormalDirection(){char buffer[4096];sprintf_s (buffer, "%s.ndr",mName.c_str());return (const char*)buffer;}
	/*
	Connect a cusom material shader to <b>customShader</b>
	to customize the lighting calculation.
	The shader is called during baking process,
	and is responsible for computing lighting.
	For texture baking, the shader should return
	a single color value per vertex,
	which will then be interpolated within a triangle
	and be written to a lightmap texture.
	For vertex baking, the shader can return
	more than a single color value,
	provided that the output structure of the shader is fixed.
	The data computed during vertex baking is accessible after baking is complete.
	*/
	MessageID getCustomShader(){char buffer[4096];sprintf_s (buffer, "%s.csh",mName.c_str());return (const char*)buffer;}
protected:
	BakeSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectSet(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BAKESET_H__
