/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RAMP_H__
#define __MayaDM_RAMP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
The <b>Ramp</b> texture creates a texture map that graduates from
 one color to another through a series of colors.
<p/>
 You can easily create effects ranging from simple stripes to
 geometric patterns and mottled surfaces are easily created
 by the choice of Ramp and Interpolation types.  By default,
 the Ramp texture graduates from red to green to blue in a linear,
 horizontal (V ramp) fashion.
<p/>
 When applied as a bump map, the colors in a ramp appear as a gray
 scale based on the luminance of each color.
<p/>
 Aside from the attributes listed here, Ramp inherits many other
 attributes from its parent node, <a href="texture2d.html">Texture2d</a>.
<p/>
 In the table below, important attributes are shown in <b>bold</b>
 in the description column.
*/
class Ramp : public Texture2d
{
public:
	/*
	<b>Color Entry List</b> is the list of colors that
	comprise the ramp.
	*/
	struct ColorEntryList{
		float position;
		float3 color;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", position);
			color.write(file);
		}
	};
public:
	Ramp(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "ramp"){}
	virtual ~Ramp(){}
	/*
	<b>Type</b> controls what kind of ramp you are creating.
	The available types are:
	<ul>
	<b>V Ramp</b>: colors change along the "V" direction of the texture.
	<p/><b>U Ramp</b>: colors change along the "U" direction of the texture.
	<p/><b>Diagonal Ramp</b>: colors change diagonally across the "U" and
	"V" directions.
	<p/><b>Radial Ramp</b>: colors change along a circular path, centered
	in the middle of the texture.
	<p/><b>Circular Ramp</b>: colors change along a straight line
	starting from s single point, forming a series of concentric
	circles.
	<p/><b>Box Ramp</b>: colors change along a straight line starting
	from a single point, forming a series of concentric squares or
	rectangles.
	<p/><b>UV Ramp</b>: colors change along both the "U" and the "V" directions..
	<p/><b>Four Corner Ramp</b>: the colors from the ramp are placed
	sequentially around the four corners of the texture, and the
	middle of the texture is interpolated between those colors.
	(if there are less than four colors in the ramp, black is used
	in the remaining corners.)
	<p/><b>Tartan Ramp</b>: the colors are interpolated in bands along both
	the "U" and the "V" directions, and blended where they cross
	each other, forming a plaid-like pattern.
	</ul>
	*/
	void setType(unsigned int t){if(t == 0) return; fprintf_s(mFile, "setAttr \".t\" %i;\n", t);}
	/*
	<b>Type</b> controls what kind of ramp you are creating.
	The available types are:
	<ul>
	<b>V Ramp</b>: colors change along the "V" direction of the texture.
	<p/><b>U Ramp</b>: colors change along the "U" direction of the texture.
	<p/><b>Diagonal Ramp</b>: colors change diagonally across the "U" and
	"V" directions.
	<p/><b>Radial Ramp</b>: colors change along a circular path, centered
	in the middle of the texture.
	<p/><b>Circular Ramp</b>: colors change along a straight line
	starting from s single point, forming a series of concentric
	circles.
	<p/><b>Box Ramp</b>: colors change along a straight line starting
	from a single point, forming a series of concentric squares or
	rectangles.
	<p/><b>UV Ramp</b>: colors change along both the "U" and the "V" directions..
	<p/><b>Four Corner Ramp</b>: the colors from the ramp are placed
	sequentially around the four corners of the texture, and the
	middle of the texture is interpolated between those colors.
	(if there are less than four colors in the ramp, black is used
	in the remaining corners.)
	<p/><b>Tartan Ramp</b>: the colors are interpolated in bands along both
	the "U" and the "V" directions, and blended where they cross
	each other, forming a plaid-like pattern.
	</ul>
	*/
	void setType(const UnsignedintID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*
	<b>Interpolation</b> controls the way the intermediate
	colors are calculated.  The values are:
	<ul><b>None</b>: No interpolation is done; the different
	colors just show up as different bands in the final texture.
	<p/><b>Linear</b>: The values are interpolated linearly in RGB
	color space.
	<p/><b>Exponential Up</b>: The values are interpolated exponentially
	from the bottom to the top of the ramp.  This means that each
	color dominates the space between it and the next color.
	<p/><b>Exponential Down</b>: The values are interpolated exponentially
	from the top to the bottom of the ramp.  This means that each
	color dominates the space between it and the next color.
	<p/><b>Smooth</b>: The values are interpolated along a bell curve,
	so that each color on the ramp dominates the region around it,
	then blends quickly to the next color.
	<p/><b>Bump</b>: The values are interpolated along a sin curve,
	based on the luminosity values.
	<p/><b>Spike</b>: Each color in the ramp dominates only its
	very immediate neighborhood, falling off very quickly.
	</ul>
	*/
	void setInterpolation(unsigned int in){if(in == 1) return; fprintf_s(mFile, "setAttr \".in\" %i;\n", in);}
	/*
	<b>Interpolation</b> controls the way the intermediate
	colors are calculated.  The values are:
	<ul><b>None</b>: No interpolation is done; the different
	colors just show up as different bands in the final texture.
	<p/><b>Linear</b>: The values are interpolated linearly in RGB
	color space.
	<p/><b>Exponential Up</b>: The values are interpolated exponentially
	from the bottom to the top of the ramp.  This means that each
	color dominates the space between it and the next color.
	<p/><b>Exponential Down</b>: The values are interpolated exponentially
	from the top to the bottom of the ramp.  This means that each
	color dominates the space between it and the next color.
	<p/><b>Smooth</b>: The values are interpolated along a bell curve,
	so that each color on the ramp dominates the region around it,
	then blends quickly to the next color.
	<p/><b>Bump</b>: The values are interpolated along a sin curve,
	based on the luminosity values.
	<p/><b>Spike</b>: Each color in the ramp dominates only its
	very immediate neighborhood, falling off very quickly.
	</ul>
	*/
	void setInterpolation(const UnsignedintID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in\";\n",mName.c_str());}
	/*
	<b>Color Entry List</b> is the list of colors that
	comprise the ramp.
	*/
	void setColorEntryList(size_t cel_i,const ColorEntryList& cel){fprintf_s(mFile, "setAttr \".cel[%i]\" ",cel_i);cel.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color Entry List</b> is the list of colors that
	comprise the ramp.
	*/
	void setColorEntryList(size_t cel_i,const ColorEntryListID& cel){fprintf_s(mFile,"connectAttr \"");cel.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i]\";\n",mName.c_str(),cel_i);}
	/*
	<b>Position</b> is a list of locations, one for each color
	in the ramp, giving its position.
	*/
	void setPosition(size_t cel_i,float ep){if(ep == 0.0) return; fprintf_s(mFile, "setAttr \".cel[%i].ep\" %f;\n", cel_i,ep);}
	/*
	<b>Position</b> is a list of locations, one for each color
	in the ramp, giving its position.
	*/
	void setPosition(size_t cel_i,const FloatID& ep){fprintf_s(mFile,"connectAttr \"");ep.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].ep\";\n",mName.c_str(),cel_i);}
	/*The current entry*/
	void setColor(size_t cel_i,const float3& ec){if(ec == float3(1.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".cel[%i].ec\" -type \"float3\" ",cel_i);ec.write(mFile);fprintf_s(mFile,";\n");}
	/*The current entry*/
	void setColor(size_t cel_i,const Float3ID& ec){fprintf_s(mFile,"connectAttr \"");ec.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].ec\";\n",mName.c_str(),cel_i);}
	/*The red component of the color entry*/
	void setColorR(size_t cel_i,float ecr){if(ecr == 0.0) return; fprintf_s(mFile, "setAttr \".cel[%i].ec.ecr\" %f;\n", cel_i,ecr);}
	/*The red component of the color entry*/
	void setColorR(size_t cel_i,const FloatID& ecr){fprintf_s(mFile,"connectAttr \"");ecr.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].ec.ecr\";\n",mName.c_str(),cel_i);}
	/*The green component of the color entry*/
	void setColorG(size_t cel_i,float ecg){if(ecg == 0.0) return; fprintf_s(mFile, "setAttr \".cel[%i].ec.ecg\" %f;\n", cel_i,ecg);}
	/*The green component of the color entry*/
	void setColorG(size_t cel_i,const FloatID& ecg){fprintf_s(mFile,"connectAttr \"");ecg.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].ec.ecg\";\n",mName.c_str(),cel_i);}
	/*The blue component of the color entry*/
	void setColorB(size_t cel_i,float ecb){if(ecb == 0.0) return; fprintf_s(mFile, "setAttr \".cel[%i].ec.ecb\" %f;\n", cel_i,ecb);}
	/*The blue component of the color entry*/
	void setColorB(size_t cel_i,const FloatID& ecb){fprintf_s(mFile,"connectAttr \"");ecb.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].ec.ecb\";\n",mName.c_str(),cel_i);}
	/*
	<b>U Wave</b> controls the amplitude of sine wave
	offset in the texture in the "U" direction.  For
	example, if you increase the value of U Wave,  a
	linear interpolation pattern takes on a wavy appearance.
	If you want more waves, increase the texture's Repeat
	value in the Surface Placement window.
	*/
	void setUWave(float uw){if(uw == 0.0) return; fprintf_s(mFile, "setAttr \".uw\" %f;\n", uw);}
	/*
	<b>U Wave</b> controls the amplitude of sine wave
	offset in the texture in the "U" direction.  For
	example, if you increase the value of U Wave,  a
	linear interpolation pattern takes on a wavy appearance.
	If you want more waves, increase the texture's Repeat
	value in the Surface Placement window.
	*/
	void setUWave(const FloatID& uw){fprintf_s(mFile,"connectAttr \"");uw.write(mFile);fprintf_s(mFile,"\" \"%s.uw\";\n",mName.c_str());}
	/*
	<b>V Wave</b> controls the amplitude of sine wave
	offset in the texture in the "V" direction.  For
	example, if you increase the value of V Wave,  a
	linear interpolation pattern takes on a wavy appearance.
	If you want more waves, increase the texture's Repeat
	value in the Surface Placement window.
	*/
	void setVWave(float vw){if(vw == 0.0) return; fprintf_s(mFile, "setAttr \".vw\" %f;\n", vw);}
	/*
	<b>V Wave</b> controls the amplitude of sine wave
	offset in the texture in the "V" direction.  For
	example, if you increase the value of V Wave,  a
	linear interpolation pattern takes on a wavy appearance.
	If you want more waves, increase the texture's Repeat
	value in the Surface Placement window.
	*/
	void setVWave(const FloatID& vw){fprintf_s(mFile,"connectAttr \"");vw.write(mFile);fprintf_s(mFile,"\" \"%s.vw\";\n",mName.c_str());}
	/*
	<b>Noise</b> affects the amount that the texture
	is offset in the "U" and "V" directions by
	two-dimensional noise.
	*/
	void setNoise(float n){if(n == 0.0) return; fprintf_s(mFile, "setAttr \".n\" %f;\n", n);}
	/*
	<b>Noise</b> affects the amount that the texture
	is offset in the "U" and "V" directions by
	two-dimensional noise.
	*/
	void setNoise(const FloatID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*
	<b>Noise Frequency</b> controls how fine-grained
	the noise is.  Increase this to make the noise detail
	finer.
	*/
	void setNoiseFreq(float nf){if(nf == 0.5) return; fprintf_s(mFile, "setAttr \".nf\" %f;\n", nf);}
	/*
	<b>Noise Frequency</b> controls how fine-grained
	the noise is.  Increase this to make the noise detail
	finer.
	*/
	void setNoiseFreq(const FloatID& nf){fprintf_s(mFile,"connectAttr \"");nf.write(mFile);fprintf_s(mFile,"\" \"%s.nf\";\n",mName.c_str());}
	/*
	<b>Hue Noise</b> adds randomness to the hue of the
	colors in the ramp, resulting in mottled colors.
	Use higher values to produce psychedelic effects.
	*/
	void setHueNoise(float hn){if(hn == 0.0) return; fprintf_s(mFile, "setAttr \".hn\" %f;\n", hn);}
	/*
	<b>Hue Noise</b> adds randomness to the hue of the
	colors in the ramp, resulting in mottled colors.
	Use higher values to produce psychedelic effects.
	*/
	void setHueNoise(const FloatID& hn){fprintf_s(mFile,"connectAttr \"");hn.write(mFile);fprintf_s(mFile,"\" \"%s.hn\";\n",mName.c_str());}
	/*
	<b>Sat Noise</b> adds randomness to the saturation
	of the colors.  Increase this to add random areas of
	fading to the texture, simulating wear.
	*/
	void setSatNoise(float sn){if(sn == 0.0) return; fprintf_s(mFile, "setAttr \".sn\" %f;\n", sn);}
	/*
	<b>Sat Noise</b> adds randomness to the saturation
	of the colors.  Increase this to add random areas of
	fading to the texture, simulating wear.
	*/
	void setSatNoise(const FloatID& sn){fprintf_s(mFile,"connectAttr \"");sn.write(mFile);fprintf_s(mFile,"\" \"%s.sn\";\n",mName.c_str());}
	/*
	<b>Val Noise</b> adds randomness to the brightness
	of the colors.  Increase this to add randome areas
	of darkness to bright textures, perhaps simulating dirt.
	*/
	void setValNoise(float vn){if(vn == 0.0) return; fprintf_s(mFile, "setAttr \".vn\" %f;\n", vn);}
	/*
	<b>Val Noise</b> adds randomness to the brightness
	of the colors.  Increase this to add randome areas
	of darkness to bright textures, perhaps simulating dirt.
	*/
	void setValNoise(const FloatID& vn){fprintf_s(mFile,"connectAttr \"");vn.write(mFile);fprintf_s(mFile,"\" \"%s.vn\";\n",mName.c_str());}
	/*
	<b>Hue Noise Freq</b> controls the coarseness of the
	mottling caused by Hue Noise.  Increase this value to
	make the mottling finer and more detailed.
	*/
	void setHueNoiseFreq(float hnf){if(hnf == 0.5) return; fprintf_s(mFile, "setAttr \".hnf\" %f;\n", hnf);}
	/*
	<b>Hue Noise Freq</b> controls the coarseness of the
	mottling caused by Hue Noise.  Increase this value to
	make the mottling finer and more detailed.
	*/
	void setHueNoiseFreq(const FloatID& hnf){fprintf_s(mFile,"connectAttr \"");hnf.write(mFile);fprintf_s(mFile,"\" \"%s.hnf\";\n",mName.c_str());}
	/*
	<b>Sat Noise Freq</b> controls the coarseness of the
	mottling caused by Sat Noise.  Increase this value to
	make the mottling finer and more detailed.
	*/
	void setSatNoiseFreq(float snf){if(snf == 0.5) return; fprintf_s(mFile, "setAttr \".snf\" %f;\n", snf);}
	/*
	<b>Sat Noise Freq</b> controls the coarseness of the
	mottling caused by Sat Noise.  Increase this value to
	make the mottling finer and more detailed.
	*/
	void setSatNoiseFreq(const FloatID& snf){fprintf_s(mFile,"connectAttr \"");snf.write(mFile);fprintf_s(mFile,"\" \"%s.snf\";\n",mName.c_str());}
	/*
	<b>Val Noise Freq</b> controls the coarseness of the
	mottling caused by Val Noise.  Increase this value to
	make the mottling finer and more detailed.
	*/
	void setValNoiseFreq(float vnf){if(vnf == 0.5) return; fprintf_s(mFile, "setAttr \".vnf\" %f;\n", vnf);}
	/*
	<b>Val Noise Freq</b> controls the coarseness of the
	mottling caused by Val Noise.  Increase this value to
	make the mottling finer and more detailed.
	*/
	void setValNoiseFreq(const FloatID& vnf){fprintf_s(mFile,"connectAttr \"");vnf.write(mFile);fprintf_s(mFile,"\" \"%s.vnf\";\n",mName.c_str());}
	/*
	<b>Type</b> controls what kind of ramp you are creating.
	The available types are:
	<ul>
	<b>V Ramp</b>: colors change along the "V" direction of the texture.
	<p/><b>U Ramp</b>: colors change along the "U" direction of the texture.
	<p/><b>Diagonal Ramp</b>: colors change diagonally across the "U" and
	"V" directions.
	<p/><b>Radial Ramp</b>: colors change along a circular path, centered
	in the middle of the texture.
	<p/><b>Circular Ramp</b>: colors change along a straight line
	starting from s single point, forming a series of concentric
	circles.
	<p/><b>Box Ramp</b>: colors change along a straight line starting
	from a single point, forming a series of concentric squares or
	rectangles.
	<p/><b>UV Ramp</b>: colors change along both the "U" and the "V" directions..
	<p/><b>Four Corner Ramp</b>: the colors from the ramp are placed
	sequentially around the four corners of the texture, and the
	middle of the texture is interpolated between those colors.
	(if there are less than four colors in the ramp, black is used
	in the remaining corners.)
	<p/><b>Tartan Ramp</b>: the colors are interpolated in bands along both
	the "U" and the "V" directions, and blended where they cross
	each other, forming a plaid-like pattern.
	</ul>
	*/
	UnsignedintID getType(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*
	<b>Interpolation</b> controls the way the intermediate
	colors are calculated.  The values are:
	<ul><b>None</b>: No interpolation is done; the different
	colors just show up as different bands in the final texture.
	<p/><b>Linear</b>: The values are interpolated linearly in RGB
	color space.
	<p/><b>Exponential Up</b>: The values are interpolated exponentially
	from the bottom to the top of the ramp.  This means that each
	color dominates the space between it and the next color.
	<p/><b>Exponential Down</b>: The values are interpolated exponentially
	from the top to the bottom of the ramp.  This means that each
	color dominates the space between it and the next color.
	<p/><b>Smooth</b>: The values are interpolated along a bell curve,
	so that each color on the ramp dominates the region around it,
	then blends quickly to the next color.
	<p/><b>Bump</b>: The values are interpolated along a sin curve,
	based on the luminosity values.
	<p/><b>Spike</b>: Each color in the ramp dominates only its
	very immediate neighborhood, falling off very quickly.
	</ul>
	*/
	UnsignedintID getInterpolation(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color Entry List</b> is the list of colors that
	comprise the ramp.
	*/
	const ColorEntryListID& getColorEntryList(size_t cel_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i]",mName.c_str(),cel_i);return (const char*)buffer;}
	/*
	<b>Position</b> is a list of locations, one for each color
	in the ramp, giving its position.
	*/
	const FloatID& getPosition(size_t cel_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].ep",mName.c_str(),cel_i);return (const char*)buffer;}
	/*The current entry*/
	const Float3ID& getColor(size_t cel_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].ec",mName.c_str(),cel_i);return (const char*)buffer;}
	/*The red component of the color entry*/
	const FloatID& getColorR(size_t cel_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].ec.ecr",mName.c_str(),cel_i);return (const char*)buffer;}
	/*The green component of the color entry*/
	const FloatID& getColorG(size_t cel_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].ec.ecg",mName.c_str(),cel_i);return (const char*)buffer;}
	/*The blue component of the color entry*/
	const FloatID& getColorB(size_t cel_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].ec.ecb",mName.c_str(),cel_i);return (const char*)buffer;}
	/*
	<b>U Wave</b> controls the amplitude of sine wave
	offset in the texture in the "U" direction.  For
	example, if you increase the value of U Wave,  a
	linear interpolation pattern takes on a wavy appearance.
	If you want more waves, increase the texture's Repeat
	value in the Surface Placement window.
	*/
	FloatID getUWave(){char buffer[4096];sprintf_s (buffer, "%s.uw",mName.c_str());return (const char*)buffer;}
	/*
	<b>V Wave</b> controls the amplitude of sine wave
	offset in the texture in the "V" direction.  For
	example, if you increase the value of V Wave,  a
	linear interpolation pattern takes on a wavy appearance.
	If you want more waves, increase the texture's Repeat
	value in the Surface Placement window.
	*/
	FloatID getVWave(){char buffer[4096];sprintf_s (buffer, "%s.vw",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise</b> affects the amount that the texture
	is offset in the "U" and "V" directions by
	two-dimensional noise.
	*/
	FloatID getNoise(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise Frequency</b> controls how fine-grained
	the noise is.  Increase this to make the noise detail
	finer.
	*/
	FloatID getNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.nf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Hue Noise</b> adds randomness to the hue of the
	colors in the ramp, resulting in mottled colors.
	Use higher values to produce psychedelic effects.
	*/
	FloatID getHueNoise(){char buffer[4096];sprintf_s (buffer, "%s.hn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sat Noise</b> adds randomness to the saturation
	of the colors.  Increase this to add random areas of
	fading to the texture, simulating wear.
	*/
	FloatID getSatNoise(){char buffer[4096];sprintf_s (buffer, "%s.sn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Val Noise</b> adds randomness to the brightness
	of the colors.  Increase this to add randome areas
	of darkness to bright textures, perhaps simulating dirt.
	*/
	FloatID getValNoise(){char buffer[4096];sprintf_s (buffer, "%s.vn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Hue Noise Freq</b> controls the coarseness of the
	mottling caused by Hue Noise.  Increase this value to
	make the mottling finer and more detailed.
	*/
	FloatID getHueNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.hnf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sat Noise Freq</b> controls the coarseness of the
	mottling caused by Sat Noise.  Increase this value to
	make the mottling finer and more detailed.
	*/
	FloatID getSatNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.snf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Val Noise Freq</b> controls the coarseness of the
	mottling caused by Val Noise.  Increase this value to
	make the mottling finer and more detailed.
	*/
	FloatID getValNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.vnf",mName.c_str());return (const char*)buffer;}
protected:
	Ramp(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RAMP_H__
