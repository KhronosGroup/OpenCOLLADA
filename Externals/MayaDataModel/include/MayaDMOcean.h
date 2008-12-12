/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OCEAN_H__
#define __MayaDM_OCEAN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
The <b>Ocean</b> texture can be used to simulate a range
 of water wave patterns, from small scale waves in a bathtub
 to large stormy sea swells. It is designed to be used as a displacement
 map. It is recommended to turn off feature based displacement on objects
 (assigned the shader) before applying as a displacment. This sets up a bump node
 in addition to the displacement, allowing one to keep the number of
 triangles low. The time parameter must be animated to see wave motion.
 This texture is procedurally defined internally using Perlin noise and
 sin waves that are driven by the time parameter.
 <p/>
  Aside from the attributes listed here, Ocean inherits many other
  attributes from its parent node, <a href="texture2d.html">Texture2d</a>.
  <p/>
 In the table below, important attributes are shown in <b>bold</b>
 in the description column.
*/
class Ocean : public Texture2d
{
public:
	/*
	<b>WaveHeight</b> controls the size of waves relative
	to their wave length. If the value is 1.0, then the waves are half as
	tall as they are long. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	If the graph is a horizontal line, then all waves will
	exactly the same height proportional to their length.
	*/
	struct WaveHeight{
		float waveHeight_Position;
		float waveHeight_FloatValue;
		unsigned int waveHeight_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", waveHeight_Position);
			fprintf_s(file,"%f ", waveHeight_FloatValue);
			fprintf_s(file,"%i", waveHeight_Interp);
		}
	};
	/*
	<b>WaveTurbulence</b> controls the amount of turbulence at different
	wave frequencies. For values of 1.0 the wave motion will be
	completely turbulent at the defined frequency. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	This is the most computationaly expensive attribute. Making it zero
	will speed up renders significantly, although it is important for
	simulations of stormy or windy water. The peaking parameter only
	affects the turbulent wave layer, so there will be no affect from
	the peaking parameter wherever this value is zero.
	*/
	struct WaveTurbulence{
		float waveTurbulence_Position;
		float waveTurbulence_FloatValue;
		unsigned int waveTurbulence_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", waveTurbulence_Position);
			fprintf_s(file,"%f ", waveTurbulence_FloatValue);
			fprintf_s(file,"%i", waveTurbulence_Interp);
		}
	};
	/*
	<b>WavePeaking</b> controls the amount of crest formation for waves
	across the range of wave frequencies.
	This simulates a side to side sloshing of waves, as opposed to
	up-down motion. When this parameter is non-zero many more
	evaluations of the noise function are performed, and thus the
	computation speed will be affected. Also the waveTurbulence
	function must be non-zero for this parameter to have an effects,
	as it is only applied to the turbulent waves.
	*/
	struct WavePeaking{
		float wavePeaking_Position;
		float wavePeaking_FloatValue;
		unsigned int wavePeaking_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", wavePeaking_Position);
			fprintf_s(file,"%f ", wavePeaking_FloatValue);
			fprintf_s(file,"%i", wavePeaking_Interp);
		}
	};
public:
	Ocean(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "ocean"){}
	virtual ~Ocean(){}
	/*
	<b>Time</b> is used to animate the Ocean texture.
	You can keyframe the Time attribute to control
	the rate and amount of change of the ocean texture
	in your scene. This value represents seconds for
	a water surface at the given scale value. Thus typing
	the expression "= time" into the edit cell will create
	approximately correct animation speed relative to the scale.
	*/
	void setTime(float ti){if(ti == 0.0) return; fprintf_s(mFile, "setAttr \".ti\" %f;\n", ti);}
	/*
	<b>Time</b> is used to animate the Ocean texture.
	You can keyframe the Time attribute to control
	the rate and amount of change of the ocean texture
	in your scene. This value represents seconds for
	a water surface at the given scale value. Thus typing
	the expression "= time" into the edit cell will create
	approximately correct animation speed relative to the scale.
	*/
	void setTime(const FloatID& ti){fprintf_s(mFile,"connectAttr \"");ti.write(mFile);fprintf_s(mFile,"\" \"%s.ti\";\n",mName.c_str());}
	/*
	<b>Scale</b> controls the defined size in meters that corresponds
	to the texture space 0-1 in UV( for default texture placement settings ).
	*/
	void setScale(float sc){if(sc == 10.0) return; fprintf_s(mFile, "setAttr \".sc\" %f;\n", sc);}
	/*
	<b>Scale</b> controls the defined size in meters that corresponds
	to the texture space 0-1 in UV( for default texture placement settings ).
	*/
	void setScale(const FloatID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*
	<b>Wind UV</b> controls the (average) direction that
	the waves will travel, simulating the effect
	of wind.  This is expressed as U and V values, in the
	UV texture space. Note: animating this parameter will
	cause unnatural motion, and should be avoided.
	*/
	void setWindUV(const float2& wi){if(wi == float2(1.0, 0.0)) return; fprintf_s(mFile, "setAttr \".wi\" -type \"float2\" ");wi.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Wind UV</b> controls the (average) direction that
	the waves will travel, simulating the effect
	of wind.  This is expressed as U and V values, in the
	UV texture space. Note: animating this parameter will
	cause unnatural motion, and should be avoided.
	*/
	void setWindUV(const Float2ID& wi){fprintf_s(mFile,"connectAttr \"");wi.write(mFile);fprintf_s(mFile,"\" \"%s.wi\";\n",mName.c_str());}
	/*The U component of the wind direction*/
	void setWindU(float wiu){if(wiu == 0.0) return; fprintf_s(mFile, "setAttr \".wi.wiu\" %f;\n", wiu);}
	/*The U component of the wind direction*/
	void setWindU(const FloatID& wiu){fprintf_s(mFile,"connectAttr \"");wiu.write(mFile);fprintf_s(mFile,"\" \"%s.wi.wiu\";\n",mName.c_str());}
	/*The V component of the wind direction*/
	void setWindV(float wiv){if(wiv == 0.0) return; fprintf_s(mFile, "setAttr \".wi.wiv\" %f;\n", wiv);}
	/*The V component of the wind direction*/
	void setWindV(const FloatID& wiv){fprintf_s(mFile,"connectAttr \"");wiv.write(mFile);fprintf_s(mFile,"\" \"%s.wi.wiv\";\n",mName.c_str());}
	/*
	<b>Observer Speed</b> is useful when you don't want the waves
	to move transversely. It cancels out transverse wave motion by
	moving a simulated observer. This is similar to animating the
	uvOffset of the texture relative to the wind direction.
	When <b>Observer Speed</b> is 1.0 the primary waves will not
	appear to travel because the viewer is moving at the same speed as
	the waves. The secondary waves will still move relative to the
	primary ones.
	*/
	void setObserverSpeed(float os){if(os == 0.0) return; fprintf_s(mFile, "setAttr \".os\" %f;\n", os);}
	/*
	<b>Observer Speed</b> is useful when you don't want the waves
	to move transversely. It cancels out transverse wave motion by
	moving a simulated observer. This is similar to animating the
	uvOffset of the texture relative to the wind direction.
	When <b>Observer Speed</b> is 1.0 the primary waves will not
	appear to travel because the viewer is moving at the same speed as
	the waves. The secondary waves will still move relative to the
	primary ones.
	*/
	void setObserverSpeed(const FloatID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*
	<b>WaveDirSpread</b> determines the variance in wave direction with
	respect to the wind direction. If it is zero, then all waves
	travel in the same direction. If it is one, then waves will travel
	in random directions. Inconsistency of the wind
	direction along with other effects like wave refraction tend
	to cause a natural variation in wave direction.
	*/
	void setWaveDirSpread(float wd){if(wd == 0.2) return; fprintf_s(mFile, "setAttr \".wd\" %f;\n", wd);}
	/*
	<b>WaveDirSpread</b> determines the variance in wave direction with
	respect to the wind direction. If it is zero, then all waves
	travel in the same direction. If it is one, then waves will travel
	in random directions. Inconsistency of the wind
	direction along with other effects like wave refraction tend
	to cause a natural variation in wave direction.
	*/
	void setWaveDirSpread(const FloatID& wd){fprintf_s(mFile,"connectAttr \"");wd.write(mFile);fprintf_s(mFile,"\" \"%s.wd\";\n",mName.c_str());}
	/*
	<b>NumFrequencies</b> controls the number of interpolated frequencies
	between <b>waveLengthMin</b> and <b>WaveLengthMax</b>
	Note: the higher this value, the longer this texture takes to compute.
	If this value is not an integer, then the number of created frequencies
	will be the rounded up value, but the amplitude for the extra
	frequency will be proportional to the remainder( ie .25 for 8.25 )
	This allows this parameter to be smoothly animated.
	*/
	void setNumFrequencies(float nf){if(nf == 3.0) return; fprintf_s(mFile, "setAttr \".nf\" %f;\n", nf);}
	/*
	<b>NumFrequencies</b> controls the number of interpolated frequencies
	between <b>waveLengthMin</b> and <b>WaveLengthMax</b>
	Note: the higher this value, the longer this texture takes to compute.
	If this value is not an integer, then the number of created frequencies
	will be the rounded up value, but the amplitude for the extra
	frequency will be proportional to the remainder( ie .25 for 8.25 )
	This allows this parameter to be smoothly animated.
	*/
	void setNumFrequencies(const FloatID& nf){fprintf_s(mFile,"connectAttr \"");nf.write(mFile);fprintf_s(mFile,"\" \"%s.nf\";\n",mName.c_str());}
	/*
	<b>WaveLengthMin</b> controls the minimum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	void setWaveLengthMin(float wlm){if(wlm == 0.3) return; fprintf_s(mFile, "setAttr \".wlm\" %f;\n", wlm);}
	/*
	<b>WaveLengthMin</b> controls the minimum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	void setWaveLengthMin(const FloatID& wlm){fprintf_s(mFile,"connectAttr \"");wlm.write(mFile);fprintf_s(mFile,"\" \"%s.wlm\";\n",mName.c_str());}
	/*
	<b>WaveLengthMax</b> controls the maximum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	void setWaveLengthMax(float wlx){if(wlx == 4.0) return; fprintf_s(mFile, "setAttr \".wlx\" %f;\n", wlx);}
	/*
	<b>WaveLengthMax</b> controls the maximum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	void setWaveLengthMax(const FloatID& wlx){fprintf_s(mFile,"connectAttr \"");wlx.write(mFile);fprintf_s(mFile,"\" \"%s.wlx\";\n",mName.c_str());}
	/*
	<b>WaveHeight</b> controls the size of waves relative
	to their wave length. If the value is 1.0, then the waves are half as
	tall as they are long. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	If the graph is a horizontal line, then all waves will
	exactly the same height proportional to their length.
	*/
	void setWaveHeight(size_t wh_i,const WaveHeight& wh){fprintf_s(mFile, "setAttr \".wh[%i]\" ",wh_i);wh.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>WaveHeight</b> controls the size of waves relative
	to their wave length. If the value is 1.0, then the waves are half as
	tall as they are long. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	If the graph is a horizontal line, then all waves will
	exactly the same height proportional to their length.
	*/
	void setWaveHeight(size_t wh_i,const WaveHeightID& wh){fprintf_s(mFile,"connectAttr \"");wh.write(mFile);fprintf_s(mFile,"\" \"%s.wh[%i]\";\n",mName.c_str(),wh_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWaveHeight_Position(size_t wh_i,float whp){if(whp == 0.0) return; fprintf_s(mFile, "setAttr \".wh[%i].whp\" %f;\n", wh_i,whp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWaveHeight_Position(size_t wh_i,const FloatID& whp){fprintf_s(mFile,"connectAttr \"");whp.write(mFile);fprintf_s(mFile,"\" \"%s.wh[%i].whp\";\n",mName.c_str(),wh_i);}
	/*Ramp value at the sibling position*/
	void setWaveHeight_FloatValue(size_t wh_i,float whfv){if(whfv == 0.0) return; fprintf_s(mFile, "setAttr \".wh[%i].whfv\" %f;\n", wh_i,whfv);}
	/*Ramp value at the sibling position*/
	void setWaveHeight_FloatValue(size_t wh_i,const FloatID& whfv){fprintf_s(mFile,"connectAttr \"");whfv.write(mFile);fprintf_s(mFile,"\" \"%s.wh[%i].whfv\";\n",mName.c_str(),wh_i);}
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
	void setWaveHeight_Interp(size_t wh_i,unsigned int whi){if(whi == 0) return; fprintf_s(mFile, "setAttr \".wh[%i].whi\" %i;\n", wh_i,whi);}
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
	void setWaveHeight_Interp(size_t wh_i,const UnsignedintID& whi){fprintf_s(mFile,"connectAttr \"");whi.write(mFile);fprintf_s(mFile,"\" \"%s.wh[%i].whi\";\n",mName.c_str(),wh_i);}
	/*
	<b>WaveTurbulence</b> controls the amount of turbulence at different
	wave frequencies. For values of 1.0 the wave motion will be
	completely turbulent at the defined frequency. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	This is the most computationaly expensive attribute. Making it zero
	will speed up renders significantly, although it is important for
	simulations of stormy or windy water. The peaking parameter only
	affects the turbulent wave layer, so there will be no affect from
	the peaking parameter wherever this value is zero.
	*/
	void setWaveTurbulence(size_t wtb_i,const WaveTurbulence& wtb){fprintf_s(mFile, "setAttr \".wtb[%i]\" ",wtb_i);wtb.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>WaveTurbulence</b> controls the amount of turbulence at different
	wave frequencies. For values of 1.0 the wave motion will be
	completely turbulent at the defined frequency. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	This is the most computationaly expensive attribute. Making it zero
	will speed up renders significantly, although it is important for
	simulations of stormy or windy water. The peaking parameter only
	affects the turbulent wave layer, so there will be no affect from
	the peaking parameter wherever this value is zero.
	*/
	void setWaveTurbulence(size_t wtb_i,const WaveTurbulenceID& wtb){fprintf_s(mFile,"connectAttr \"");wtb.write(mFile);fprintf_s(mFile,"\" \"%s.wtb[%i]\";\n",mName.c_str(),wtb_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWaveTurbulence_Position(size_t wtb_i,float wtbp){if(wtbp == 0.0) return; fprintf_s(mFile, "setAttr \".wtb[%i].wtbp\" %f;\n", wtb_i,wtbp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWaveTurbulence_Position(size_t wtb_i,const FloatID& wtbp){fprintf_s(mFile,"connectAttr \"");wtbp.write(mFile);fprintf_s(mFile,"\" \"%s.wtb[%i].wtbp\";\n",mName.c_str(),wtb_i);}
	/*Ramp value at the sibling position*/
	void setWaveTurbulence_FloatValue(size_t wtb_i,float wtbfv){if(wtbfv == 0.0) return; fprintf_s(mFile, "setAttr \".wtb[%i].wtbfv\" %f;\n", wtb_i,wtbfv);}
	/*Ramp value at the sibling position*/
	void setWaveTurbulence_FloatValue(size_t wtb_i,const FloatID& wtbfv){fprintf_s(mFile,"connectAttr \"");wtbfv.write(mFile);fprintf_s(mFile,"\" \"%s.wtb[%i].wtbfv\";\n",mName.c_str(),wtb_i);}
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
	void setWaveTurbulence_Interp(size_t wtb_i,unsigned int wtbi){if(wtbi == 0) return; fprintf_s(mFile, "setAttr \".wtb[%i].wtbi\" %i;\n", wtb_i,wtbi);}
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
	void setWaveTurbulence_Interp(size_t wtb_i,const UnsignedintID& wtbi){fprintf_s(mFile,"connectAttr \"");wtbi.write(mFile);fprintf_s(mFile,"\" \"%s.wtb[%i].wtbi\";\n",mName.c_str(),wtb_i);}
	/*
	<b>WavePeaking</b> controls the amount of crest formation for waves
	across the range of wave frequencies.
	This simulates a side to side sloshing of waves, as opposed to
	up-down motion. When this parameter is non-zero many more
	evaluations of the noise function are performed, and thus the
	computation speed will be affected. Also the waveTurbulence
	function must be non-zero for this parameter to have an effects,
	as it is only applied to the turbulent waves.
	*/
	void setWavePeaking(size_t wp_i,const WavePeaking& wp){fprintf_s(mFile, "setAttr \".wp[%i]\" ",wp_i);wp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>WavePeaking</b> controls the amount of crest formation for waves
	across the range of wave frequencies.
	This simulates a side to side sloshing of waves, as opposed to
	up-down motion. When this parameter is non-zero many more
	evaluations of the noise function are performed, and thus the
	computation speed will be affected. Also the waveTurbulence
	function must be non-zero for this parameter to have an effects,
	as it is only applied to the turbulent waves.
	*/
	void setWavePeaking(size_t wp_i,const WavePeakingID& wp){fprintf_s(mFile,"connectAttr \"");wp.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i]\";\n",mName.c_str(),wp_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWavePeaking_Position(size_t wp_i,float wpp){if(wpp == 0.0) return; fprintf_s(mFile, "setAttr \".wp[%i].wpp\" %f;\n", wp_i,wpp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWavePeaking_Position(size_t wp_i,const FloatID& wpp){fprintf_s(mFile,"connectAttr \"");wpp.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i].wpp\";\n",mName.c_str(),wp_i);}
	/*Ramp value at the sibling position*/
	void setWavePeaking_FloatValue(size_t wp_i,float wpfv){if(wpfv == 0.0) return; fprintf_s(mFile, "setAttr \".wp[%i].wpfv\" %f;\n", wp_i,wpfv);}
	/*Ramp value at the sibling position*/
	void setWavePeaking_FloatValue(size_t wp_i,const FloatID& wpfv){fprintf_s(mFile,"connectAttr \"");wpfv.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i].wpfv\";\n",mName.c_str(),wp_i);}
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
	void setWavePeaking_Interp(size_t wp_i,unsigned int wpi){if(wpi == 0) return; fprintf_s(mFile, "setAttr \".wp[%i].wpi\" %i;\n", wp_i,wpi);}
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
	void setWavePeaking_Interp(size_t wp_i,const UnsignedintID& wpi){fprintf_s(mFile,"connectAttr \"");wpi.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i].wpi\";\n",mName.c_str(),wp_i);}
	/*
	<b>FoamEmission</b> Controls density of foam generated above
	the foam threshold. The foam value is output to the outFoam
	attribute, which can be used to define opacity of a layered
	foam shader.
	*/
	void setFoamEmission(float fme){if(fme == 0.0) return; fprintf_s(mFile, "setAttr \".fme\" %f;\n", fme);}
	/*
	<b>FoamEmission</b> Controls density of foam generated above
	the foam threshold. The foam value is output to the outFoam
	attribute, which can be used to define opacity of a layered
	foam shader.
	*/
	void setFoamEmission(const FloatID& fme){fprintf_s(mFile,"connectAttr \"");fme.write(mFile);fprintf_s(mFile,"\" \"%s.fme\";\n",mName.c_str());}
	/*
	<b>FoamThreshold</b> Controls the wave amplitude required
	to generate foam as well as how long the foam lasts.
	*/
	void setFoamThreshold(float fmt){if(fmt == 0.51) return; fprintf_s(mFile, "setAttr \".fmt\" %f;\n", fmt);}
	/*
	<b>FoamThreshold</b> Controls the wave amplitude required
	to generate foam as well as how long the foam lasts.
	*/
	void setFoamThreshold(const FloatID& fmt){fprintf_s(mFile,"connectAttr \"");fmt.write(mFile);fprintf_s(mFile,"\" \"%s.fmt\";\n",mName.c_str());}
	/*
	Decide what to output to the color channel, the normalized waveheight,
	foam, or waveHeight in blue green with white foam.
	*/
	void setColorMode(unsigned int cmd){if(cmd == 0) return; fprintf_s(mFile, "setAttr \".cmd\" %i;\n", cmd);}
	/*
	Decide what to output to the color channel, the normalized waveheight,
	foam, or waveHeight in blue green with white foam.
	*/
	void setColorMode(const UnsignedintID& cmd){fprintf_s(mFile,"connectAttr \"");cmd.write(mFile);fprintf_s(mFile,"\" \"%s.cmd\";\n",mName.c_str());}
	/*
	<b>Out Foam</b> is the output foam density value
	computed by the texture.  Use this value to control
	the density of a layered foam shader. If applied
	to transparency, the value should be first inverted.
	*/
	void setOutFoam(const FloatID& ofm){fprintf_s(mFile,"connectAttr \"");ofm.write(mFile);fprintf_s(mFile,"\" \"%s.ofm\";\n",mName.c_str());}
	/*
	<b>Time</b> is used to animate the Ocean texture.
	You can keyframe the Time attribute to control
	the rate and amount of change of the ocean texture
	in your scene. This value represents seconds for
	a water surface at the given scale value. Thus typing
	the expression "= time" into the edit cell will create
	approximately correct animation speed relative to the scale.
	*/
	FloatID getTime(){char buffer[4096];sprintf_s (buffer, "%s.ti",mName.c_str());return (const char*)buffer;}
	/*
	<b>Scale</b> controls the defined size in meters that corresponds
	to the texture space 0-1 in UV( for default texture placement settings ).
	*/
	FloatID getScale(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wind UV</b> controls the (average) direction that
	the waves will travel, simulating the effect
	of wind.  This is expressed as U and V values, in the
	UV texture space. Note: animating this parameter will
	cause unnatural motion, and should be avoided.
	*/
	Float2ID getWindUV(){char buffer[4096];sprintf_s (buffer, "%s.wi",mName.c_str());return (const char*)buffer;}
	/*The U component of the wind direction*/
	FloatID getWindU(){char buffer[4096];sprintf_s (buffer, "%s.wi.wiu",mName.c_str());return (const char*)buffer;}
	/*The V component of the wind direction*/
	FloatID getWindV(){char buffer[4096];sprintf_s (buffer, "%s.wi.wiv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Observer Speed</b> is useful when you don't want the waves
	to move transversely. It cancels out transverse wave motion by
	moving a simulated observer. This is similar to animating the
	uvOffset of the texture relative to the wind direction.
	When <b>Observer Speed</b> is 1.0 the primary waves will not
	appear to travel because the viewer is moving at the same speed as
	the waves. The secondary waves will still move relative to the
	primary ones.
	*/
	FloatID getObserverSpeed(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*
	<b>WaveDirSpread</b> determines the variance in wave direction with
	respect to the wind direction. If it is zero, then all waves
	travel in the same direction. If it is one, then waves will travel
	in random directions. Inconsistency of the wind
	direction along with other effects like wave refraction tend
	to cause a natural variation in wave direction.
	*/
	FloatID getWaveDirSpread(){char buffer[4096];sprintf_s (buffer, "%s.wd",mName.c_str());return (const char*)buffer;}
	/*
	<b>NumFrequencies</b> controls the number of interpolated frequencies
	between <b>waveLengthMin</b> and <b>WaveLengthMax</b>
	Note: the higher this value, the longer this texture takes to compute.
	If this value is not an integer, then the number of created frequencies
	will be the rounded up value, but the amplitude for the extra
	frequency will be proportional to the remainder( ie .25 for 8.25 )
	This allows this parameter to be smoothly animated.
	*/
	FloatID getNumFrequencies(){char buffer[4096];sprintf_s (buffer, "%s.nf",mName.c_str());return (const char*)buffer;}
	/*
	<b>WaveLengthMin</b> controls the minimum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	FloatID getWaveLengthMin(){char buffer[4096];sprintf_s (buffer, "%s.wlm",mName.c_str());return (const char*)buffer;}
	/*
	<b>WaveLengthMax</b> controls the maximum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	FloatID getWaveLengthMax(){char buffer[4096];sprintf_s (buffer, "%s.wlx",mName.c_str());return (const char*)buffer;}
	/*
	<b>WaveHeight</b> controls the size of waves relative
	to their wave length. If the value is 1.0, then the waves are half as
	tall as they are long. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	If the graph is a horizontal line, then all waves will
	exactly the same height proportional to their length.
	*/
	const WaveHeightID& getWaveHeight(size_t wh_i){char buffer[4096];sprintf_s (buffer, "%s.wh[%i]",mName.c_str(),wh_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getWaveHeight_Position(size_t wh_i){char buffer[4096];sprintf_s (buffer, "%s.wh[%i].whp",mName.c_str(),wh_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getWaveHeight_FloatValue(size_t wh_i){char buffer[4096];sprintf_s (buffer, "%s.wh[%i].whfv",mName.c_str(),wh_i);return (const char*)buffer;}
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
	const UnsignedintID& getWaveHeight_Interp(size_t wh_i){char buffer[4096];sprintf_s (buffer, "%s.wh[%i].whi",mName.c_str(),wh_i);return (const char*)buffer;}
	/*
	<b>WaveTurbulence</b> controls the amount of turbulence at different
	wave frequencies. For values of 1.0 the wave motion will be
	completely turbulent at the defined frequency. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	This is the most computationaly expensive attribute. Making it zero
	will speed up renders significantly, although it is important for
	simulations of stormy or windy water. The peaking parameter only
	affects the turbulent wave layer, so there will be no affect from
	the peaking parameter wherever this value is zero.
	*/
	const WaveTurbulenceID& getWaveTurbulence(size_t wtb_i){char buffer[4096];sprintf_s (buffer, "%s.wtb[%i]",mName.c_str(),wtb_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getWaveTurbulence_Position(size_t wtb_i){char buffer[4096];sprintf_s (buffer, "%s.wtb[%i].wtbp",mName.c_str(),wtb_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getWaveTurbulence_FloatValue(size_t wtb_i){char buffer[4096];sprintf_s (buffer, "%s.wtb[%i].wtbfv",mName.c_str(),wtb_i);return (const char*)buffer;}
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
	const UnsignedintID& getWaveTurbulence_Interp(size_t wtb_i){char buffer[4096];sprintf_s (buffer, "%s.wtb[%i].wtbi",mName.c_str(),wtb_i);return (const char*)buffer;}
	/*
	<b>WavePeaking</b> controls the amount of crest formation for waves
	across the range of wave frequencies.
	This simulates a side to side sloshing of waves, as opposed to
	up-down motion. When this parameter is non-zero many more
	evaluations of the noise function are performed, and thus the
	computation speed will be affected. Also the waveTurbulence
	function must be non-zero for this parameter to have an effects,
	as it is only applied to the turbulent waves.
	*/
	const WavePeakingID& getWavePeaking(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i]",mName.c_str(),wp_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getWavePeaking_Position(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i].wpp",mName.c_str(),wp_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getWavePeaking_FloatValue(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i].wpfv",mName.c_str(),wp_i);return (const char*)buffer;}
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
	const UnsignedintID& getWavePeaking_Interp(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i].wpi",mName.c_str(),wp_i);return (const char*)buffer;}
	/*
	<b>FoamEmission</b> Controls density of foam generated above
	the foam threshold. The foam value is output to the outFoam
	attribute, which can be used to define opacity of a layered
	foam shader.
	*/
	FloatID getFoamEmission(){char buffer[4096];sprintf_s (buffer, "%s.fme",mName.c_str());return (const char*)buffer;}
	/*
	<b>FoamThreshold</b> Controls the wave amplitude required
	to generate foam as well as how long the foam lasts.
	*/
	FloatID getFoamThreshold(){char buffer[4096];sprintf_s (buffer, "%s.fmt",mName.c_str());return (const char*)buffer;}
	/*
	Decide what to output to the color channel, the normalized waveheight,
	foam, or waveHeight in blue green with white foam.
	*/
	UnsignedintID getColorMode(){char buffer[4096];sprintf_s (buffer, "%s.cmd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Foam</b> is the output foam density value
	computed by the texture.  Use this value to control
	the density of a layered foam shader. If applied
	to transparency, the value should be first inverted.
	*/
	FloatID getOutFoam(){char buffer[4096];sprintf_s (buffer, "%s.ofm",mName.c_str());return (const char*)buffer;}
protected:
	Ocean(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OCEAN_H__
