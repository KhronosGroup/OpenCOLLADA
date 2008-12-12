/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STROKE_H__
#define __MayaDM_STROKE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPfxGeometry.h"
namespace MayaDM
{
/*
<p><pre>
        This node contains stroke attributes
        that are used to display painted strokes
      for Maya Paint Effects.

</pre></p>
*/
class Stroke : public PfxGeometry
{
public:
	/*
	This contains an array of curves to use as stroke path,
	along with number of points to sample along each curve.
	The curves are sampled in the order they appear in this
	list to produce a single set of output points and normals
	which define a poly line path for the paint effects stroke.
	By default the resulting points will correspond to the list
	of points sampled while the user painted the stroke. If the
	stroke crossed multiple surfaces there will be a separate curve
	created each time the user paints across a surface boundary.
	*/
	struct PathCurve{
		int samples;
		bool opposite;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", samples);
			fprintf_s(file,"%i", opposite);
		}
	};
	/*
	Scale factor applied to the input pressure array.
	This can be used to shape stroke widths, or other elements like tube length
	along the stroke without needing to edit using pressure curves.
	*/
	struct PressureScale{
		float pressureScale_Position;
		float pressureScale_FloatValue;
		unsigned int pressureScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", pressureScale_Position);
			fprintf_s(file,"%f ", pressureScale_FloatValue);
			fprintf_s(file,"%i", pressureScale_Interp);
		}
	};
public:
	Stroke(FILE* file,const std::string& name,const std::string& parent=""):PfxGeometry(file, name, parent, "stroke"){}
	virtual ~Stroke(){}
	/*increases or decreases the total number of samples along path*/
	void setSampleDensity(double sdn){if(sdn == 1.0) return; fprintf_s(mFile, "setAttr \".sdn\" %f;\n", sdn);}
	/*increases or decreases the total number of samples along path*/
	void setSampleDensity(const DoubleID& sdn){fprintf_s(mFile,"connectAttr \"");sdn.write(mFile);fprintf_s(mFile,"\" \"%s.sdn\";\n",mName.c_str());}
	/*smoothness of output stroke points and normals*/
	void setSmoothing(double smo){if(smo == 0.0) return; fprintf_s(mFile, "setAttr \".smo\" %f;\n", smo);}
	/*smoothness of output stroke points and normals*/
	void setSmoothing(const DoubleID& smo){fprintf_s(mFile,"connectAttr \"");smo.write(mFile);fprintf_s(mFile,"\" \"%s.smo\";\n",mName.c_str());}
	/*draw in perspective using the current camera( otherwise draw in the image plane )*/
	void setPerspective(bool per){if(per == 1) return; fprintf_s(mFile, "setAttr \".per\" %i;\n", per);}
	/*draw in perspective using the current camera( otherwise draw in the image plane )*/
	void setPerspective(const BoolID& per){fprintf_s(mFile,"connectAttr \"");per.write(mFile);fprintf_s(mFile,"\" \"%s.per\";\n",mName.c_str());}
	/*use the fixed stroke normal instead of the per-vertex curve normal*/
	void setUseNormal(bool usn){if(usn == 0) return; fprintf_s(mFile, "setAttr \".usn\" %i;\n", usn);}
	/*use the fixed stroke normal instead of the per-vertex curve normal*/
	void setUseNormal(const BoolID& usn){fprintf_s(mFile,"connectAttr \"");usn.write(mFile);fprintf_s(mFile,"\" \"%s.usn\";\n",mName.c_str());}
	/*worldspace override normal for entire stroke*/
	void setNormal(const double3& nml){fprintf_s(mFile, "setAttr \".nml\" -type \"double3\" ");nml.write(mFile);fprintf_s(mFile,";\n");}
	/*worldspace override normal for entire stroke*/
	void setNormal(const Double3ID& nml){fprintf_s(mFile,"connectAttr \"");nml.write(mFile);fprintf_s(mFile,"\" \"%s.nml\";\n",mName.c_str());}
	/*worldspace directional force X value*/
	void setNormalX(double nmx){if(nmx == 0.0) return; fprintf_s(mFile, "setAttr \".nml.nmx\" %f;\n", nmx);}
	/*worldspace directional force X value*/
	void setNormalX(const DoubleID& nmx){fprintf_s(mFile,"connectAttr \"");nmx.write(mFile);fprintf_s(mFile,"\" \"%s.nml.nmx\";\n",mName.c_str());}
	/*worldspace directional force Y value*/
	void setNormalY(double nmy){if(nmy == 0.0) return; fprintf_s(mFile, "setAttr \".nml.nmy\" %f;\n", nmy);}
	/*worldspace directional force Y value*/
	void setNormalY(const DoubleID& nmy){fprintf_s(mFile,"connectAttr \"");nmy.write(mFile);fprintf_s(mFile,"\" \"%s.nml.nmy\";\n",mName.c_str());}
	/*worldspace directional force Z value*/
	void setNormalZ(double nmz){if(nmz == 1.0) return; fprintf_s(mFile, "setAttr \".nml.nmz\" %f;\n", nmz);}
	/*worldspace directional force Z value*/
	void setNormalZ(const DoubleID& nmz){fprintf_s(mFile,"connectAttr \"");nmz.write(mFile);fprintf_s(mFile,"\" \"%s.nml.nmz\";\n",mName.c_str());}
	/*start of visible segment of stroke*/
	void setMinClip(double mnc){if(mnc == 0.0) return; fprintf_s(mFile, "setAttr \".mnc\" %f;\n", mnc);}
	/*start of visible segment of stroke*/
	void setMinClip(const DoubleID& mnc){fprintf_s(mFile,"connectAttr \"");mnc.write(mFile);fprintf_s(mFile,"\" \"%s.mnc\";\n",mName.c_str());}
	/*end of visible segment of stroke*/
	void setMaxClip(double mxc){if(mxc == 1.0) return; fprintf_s(mFile, "setAttr \".mxc\" %f;\n", mxc);}
	/*end of visible segment of stroke*/
	void setMaxClip(const DoubleID& mxc){fprintf_s(mFile,"connectAttr \"");mxc.write(mFile);fprintf_s(mFile,"\" \"%s.mxc\";\n",mName.c_str());}
	/*
	This contains an array of curves to use as stroke path,
	along with number of points to sample along each curve.
	The curves are sampled in the order they appear in this
	list to produce a single set of output points and normals
	which define a poly line path for the paint effects stroke.
	By default the resulting points will correspond to the list
	of points sampled while the user painted the stroke. If the
	stroke crossed multiple surfaces there will be a separate curve
	created each time the user paints across a surface boundary.
	*/
	void setPathCurve(size_t pcv_i,const PathCurve& pcv){fprintf_s(mFile, "setAttr \".pcv[%i]\" ",pcv_i);pcv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This contains an array of curves to use as stroke path,
	along with number of points to sample along each curve.
	The curves are sampled in the order they appear in this
	list to produce a single set of output points and normals
	which define a poly line path for the paint effects stroke.
	By default the resulting points will correspond to the list
	of points sampled while the user painted the stroke. If the
	stroke crossed multiple surfaces there will be a separate curve
	created each time the user paints across a surface boundary.
	*/
	void setPathCurve(size_t pcv_i,const PathCurveID& pcv){fprintf_s(mFile,"connectAttr \"");pcv.write(mFile);fprintf_s(mFile,"\" \"%s.pcv[%i]\";\n",mName.c_str(),pcv_i);}
	/*curve to use as stroke path*/
	void setCurve(size_t pcv_i,const GenericID& crv){fprintf_s(mFile,"connectAttr \"");crv.write(mFile);fprintf_s(mFile,"\" \"%s.pcv[%i].crv\";\n",mName.c_str(),pcv_i);}
	/*number of points to sample across curve*/
	void setSamples(size_t pcv_i,int smp){if(smp == 0) return; fprintf_s(mFile, "setAttr \".pcv[%i].smp\" %i;\n", pcv_i,smp);}
	/*number of points to sample across curve*/
	void setSamples(size_t pcv_i,const IntID& smp){fprintf_s(mFile,"connectAttr \"");smp.write(mFile);fprintf_s(mFile,"\" \"%s.pcv[%i].smp\";\n",mName.c_str(),pcv_i);}
	/*Determines wether the normal calculated for this section of the stroke should be flipped or not (default).*/
	void setOpposite(size_t pcv_i,bool opp){if(opp == false) return; fprintf_s(mFile, "setAttr \".pcv[%i].opp\" %i;\n", pcv_i,opp);}
	/*Determines wether the normal calculated for this section of the stroke should be flipped or not (default).*/
	void setOpposite(size_t pcv_i,const BoolID& opp){fprintf_s(mFile,"connectAttr \"");opp.write(mFile);fprintf_s(mFile,"\" \"%s.pcv[%i].opp\";\n",mName.c_str(),pcv_i);}
	/*Output worldspace points for brush stroke. Although it is writable, do not write to this attribute.*/
	void setOutPoint(size_t opt_i,const double3& opt){fprintf_s(mFile, "setAttr \".opt[%i]\" -type \"double3\" ",opt_i);opt.write(mFile);fprintf_s(mFile,";\n");}
	/*Output worldspace points for brush stroke. Although it is writable, do not write to this attribute.*/
	void setOutPoint(size_t opt_start,size_t opt_end,double* opt){fprintf_s(mFile,"setAttr \".opt[%i:%i]\" ", opt_start,opt_end);size_t size = (opt_end-opt_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",opt[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Output worldspace points for brush stroke. Although it is writable, do not write to this attribute.*/
	void setOutPoint(size_t opt_i,const Double3ID& opt){fprintf_s(mFile,"connectAttr \"");opt.write(mFile);fprintf_s(mFile,"\" \"%s.opt[%i]\";\n",mName.c_str(),opt_i);}
	/*X value of a stroke point. Although it is writable, do not write to this attribute.*/
	void setOutPointX(size_t opt_i,double ox){if(ox == 0.0) return; fprintf_s(mFile, "setAttr \".opt[%i].ox\" %f;\n", opt_i,ox);}
	/*X value of a stroke point. Although it is writable, do not write to this attribute.*/
	void setOutPointX(size_t opt_i,const DoubleID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.opt[%i].ox\";\n",mName.c_str(),opt_i);}
	/*Y value of a stroke point. Although it is writable, do not write to this attribute.*/
	void setOutPointY(size_t opt_i,double oy){if(oy == 0.0) return; fprintf_s(mFile, "setAttr \".opt[%i].oy\" %f;\n", opt_i,oy);}
	/*Y value of a stroke point. Although it is writable, do not write to this attribute.*/
	void setOutPointY(size_t opt_i,const DoubleID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.opt[%i].oy\";\n",mName.c_str(),opt_i);}
	/*Z value of a stroke point. Although it is writable, do not write to this attribute.*/
	void setOutPointZ(size_t opt_i,double oz){if(oz == 0.0) return; fprintf_s(mFile, "setAttr \".opt[%i].oz\" %f;\n", opt_i,oz);}
	/*Z value of a stroke point. Although it is writable, do not write to this attribute.*/
	void setOutPointZ(size_t opt_i,const DoubleID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.opt[%i].oz\";\n",mName.c_str(),opt_i);}
	/*output worldspace normals for brush stroke*/
	void setOutNormal(size_t onm_i,const Double3ID& onm){fprintf_s(mFile,"connectAttr \"");onm.write(mFile);fprintf_s(mFile,"\" \"%s.onm[%i]\";\n",mName.c_str(),onm_i);}
	/*X value of a stroke normal*/
	void setOutNormalX(size_t onm_i,const DoubleID& onx){fprintf_s(mFile,"connectAttr \"");onx.write(mFile);fprintf_s(mFile,"\" \"%s.onm[%i].onx\";\n",mName.c_str(),onm_i);}
	/*Y value of a stroke normal*/
	void setOutNormalY(size_t onm_i,const DoubleID& ony){fprintf_s(mFile,"connectAttr \"");ony.write(mFile);fprintf_s(mFile,"\" \"%s.onm[%i].ony\";\n",mName.c_str(),onm_i);}
	/*Z value of a stroke normal*/
	void setOutNormalZ(size_t onm_i,const DoubleID& onz){fprintf_s(mFile,"connectAttr \"");onz.write(mFile);fprintf_s(mFile,"\" \"%s.onm[%i].onz\";\n",mName.c_str(),onm_i);}
	/*Parameter to modulate using cached pen pressure values*/
	void setPressureMap1(unsigned int spm1){if(spm1 == 0) return; fprintf_s(mFile, "setAttr \".spm1\" %i;\n", spm1);}
	/*Parameter to modulate using cached pen pressure values*/
	void setPressureMap1(const UnsignedintID& spm1){fprintf_s(mFile,"connectAttr \"");spm1.write(mFile);fprintf_s(mFile,"\" \"%s.spm1\";\n",mName.c_str());}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMin1(double ps1){if(ps1 == 0.0) return; fprintf_s(mFile, "setAttr \".ps1\" %f;\n", ps1);}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMin1(const DoubleID& ps1){fprintf_s(mFile,"connectAttr \"");ps1.write(mFile);fprintf_s(mFile,"\" \"%s.ps1\";\n",mName.c_str());}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMax1(double px1){if(px1 == 1.0) return; fprintf_s(mFile, "setAttr \".px1\" %f;\n", px1);}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMax1(const DoubleID& px1){fprintf_s(mFile,"connectAttr \"");px1.write(mFile);fprintf_s(mFile,"\" \"%s.px1\";\n",mName.c_str());}
	/*Parameter to modulate using cached pen pressure values*/
	void setPressureMap2(unsigned int spm2){if(spm2 == 0) return; fprintf_s(mFile, "setAttr \".spm2\" %i;\n", spm2);}
	/*Parameter to modulate using cached pen pressure values*/
	void setPressureMap2(const UnsignedintID& spm2){fprintf_s(mFile,"connectAttr \"");spm2.write(mFile);fprintf_s(mFile,"\" \"%s.spm2\";\n",mName.c_str());}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMin2(double ps2){if(ps2 == 0.0) return; fprintf_s(mFile, "setAttr \".ps2\" %f;\n", ps2);}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMin2(const DoubleID& ps2){fprintf_s(mFile,"connectAttr \"");ps2.write(mFile);fprintf_s(mFile,"\" \"%s.ps2\";\n",mName.c_str());}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMax2(double px2){if(px2 == 1.0) return; fprintf_s(mFile, "setAttr \".px2\" %f;\n", px2);}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMax2(const DoubleID& px2){fprintf_s(mFile,"connectAttr \"");px2.write(mFile);fprintf_s(mFile,"\" \"%s.px2\";\n",mName.c_str());}
	/*Parameter to modulate using cached pen pressure values*/
	void setPressureMap3(unsigned int spm3){if(spm3 == 0) return; fprintf_s(mFile, "setAttr \".spm3\" %i;\n", spm3);}
	/*Parameter to modulate using cached pen pressure values*/
	void setPressureMap3(const UnsignedintID& spm3){fprintf_s(mFile,"connectAttr \"");spm3.write(mFile);fprintf_s(mFile,"\" \"%s.spm3\";\n",mName.c_str());}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMin3(double ps3){if(ps3 == 0.0) return; fprintf_s(mFile, "setAttr \".ps3\" %f;\n", ps3);}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMin3(const DoubleID& ps3){fprintf_s(mFile,"connectAttr \"");ps3.write(mFile);fprintf_s(mFile,"\" \"%s.ps3\";\n",mName.c_str());}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMax3(double px3){if(px3 == 1.0) return; fprintf_s(mFile, "setAttr \".px3\" %f;\n", px3);}
	/*0-1 pressure inputs are remapped into the min-max range*/
	void setPressureMax3(const DoubleID& px3){fprintf_s(mFile,"connectAttr \"");px3.write(mFile);fprintf_s(mFile,"\" \"%s.px3\";\n",mName.c_str());}
	/*
	Scale factor applied to the input pressure array.
	This can be used to shape stroke widths, or other elements like tube length
	along the stroke without needing to edit using pressure curves.
	*/
	void setPressureScale(size_t psc_i,const PressureScale& psc){fprintf_s(mFile, "setAttr \".psc[%i]\" ",psc_i);psc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Scale factor applied to the input pressure array.
	This can be used to shape stroke widths, or other elements like tube length
	along the stroke without needing to edit using pressure curves.
	*/
	void setPressureScale(size_t psc_i,const PressureScaleID& psc){fprintf_s(mFile,"connectAttr \"");psc.write(mFile);fprintf_s(mFile,"\" \"%s.psc[%i]\";\n",mName.c_str(),psc_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setPressureScale_Position(size_t psc_i,float pscp){if(pscp == 0.0) return; fprintf_s(mFile, "setAttr \".psc[%i].pscp\" %f;\n", psc_i,pscp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setPressureScale_Position(size_t psc_i,const FloatID& pscp){fprintf_s(mFile,"connectAttr \"");pscp.write(mFile);fprintf_s(mFile,"\" \"%s.psc[%i].pscp\";\n",mName.c_str(),psc_i);}
	/*Ramp value at the sibling position*/
	void setPressureScale_FloatValue(size_t psc_i,float pscfv){if(pscfv == 0.0) return; fprintf_s(mFile, "setAttr \".psc[%i].pscfv\" %f;\n", psc_i,pscfv);}
	/*Ramp value at the sibling position*/
	void setPressureScale_FloatValue(size_t psc_i,const FloatID& pscfv){fprintf_s(mFile,"connectAttr \"");pscfv.write(mFile);fprintf_s(mFile,"\" \"%s.psc[%i].pscfv\";\n",mName.c_str(),psc_i);}
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
	void setPressureScale_Interp(size_t psc_i,unsigned int psci){if(psci == 0) return; fprintf_s(mFile, "setAttr \".psc[%i].psci\" %i;\n", psc_i,psci);}
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
	void setPressureScale_Interp(size_t psc_i,const UnsignedintID& psci){fprintf_s(mFile,"connectAttr \"");psci.write(mFile);fprintf_s(mFile,"\" \"%s.psc[%i].psci\";\n",mName.c_str(),psc_i);}
	/*the array of pressure values generated by pen device*/
	void setPressure(size_t psr_i,double psr){if(psr == 0.0) return; fprintf_s(mFile, "setAttr \".psr[%i]\" %f;\n", psr_i,psr);}
	/*the array of pressure values generated by pen device*/
	void setPressure(size_t psr_i,const DoubleID& psr){fprintf_s(mFile,"connectAttr \"");psr.write(mFile);fprintf_s(mFile,"\" \"%s.psr[%i]\";\n",mName.c_str(),psr_i);}
	/*
	This is the name of the UVset, to which the curve is connected.
	This exists only when we have created PFX on Poly.
	*/
	void setUvSetName(size_t uvsetn_i,const MessageID& uvsetn){fprintf_s(mFile,"connectAttr \"");uvsetn.write(mFile);fprintf_s(mFile,"\" \"%s.uvsetn[%i]\";\n",mName.c_str(),uvsetn_i);}
	/*increases or decreases the total number of samples along path*/
	DoubleID getSampleDensity(){char buffer[4096];sprintf_s (buffer, "%s.sdn",mName.c_str());return (const char*)buffer;}
	/*smoothness of output stroke points and normals*/
	DoubleID getSmoothing(){char buffer[4096];sprintf_s (buffer, "%s.smo",mName.c_str());return (const char*)buffer;}
	/*draw in perspective using the current camera( otherwise draw in the image plane )*/
	BoolID getPerspective(){char buffer[4096];sprintf_s (buffer, "%s.per",mName.c_str());return (const char*)buffer;}
	/*use the fixed stroke normal instead of the per-vertex curve normal*/
	BoolID getUseNormal(){char buffer[4096];sprintf_s (buffer, "%s.usn",mName.c_str());return (const char*)buffer;}
	/*worldspace override normal for entire stroke*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.nml",mName.c_str());return (const char*)buffer;}
	/*worldspace directional force X value*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.nml.nmx",mName.c_str());return (const char*)buffer;}
	/*worldspace directional force Y value*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.nml.nmy",mName.c_str());return (const char*)buffer;}
	/*worldspace directional force Z value*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.nml.nmz",mName.c_str());return (const char*)buffer;}
	/*start of visible segment of stroke*/
	DoubleID getMinClip(){char buffer[4096];sprintf_s (buffer, "%s.mnc",mName.c_str());return (const char*)buffer;}
	/*end of visible segment of stroke*/
	DoubleID getMaxClip(){char buffer[4096];sprintf_s (buffer, "%s.mxc",mName.c_str());return (const char*)buffer;}
	/*
	This contains an array of curves to use as stroke path,
	along with number of points to sample along each curve.
	The curves are sampled in the order they appear in this
	list to produce a single set of output points and normals
	which define a poly line path for the paint effects stroke.
	By default the resulting points will correspond to the list
	of points sampled while the user painted the stroke. If the
	stroke crossed multiple surfaces there will be a separate curve
	created each time the user paints across a surface boundary.
	*/
	const PathCurveID& getPathCurve(size_t pcv_i){char buffer[4096];sprintf_s (buffer, "%s.pcv[%i]",mName.c_str(),pcv_i);return (const char*)buffer;}
	/*curve to use as stroke path*/
	const GenericID& getCurve(size_t pcv_i){char buffer[4096];sprintf_s (buffer, "%s.pcv[%i].crv",mName.c_str(),pcv_i);return (const char*)buffer;}
	/*number of points to sample across curve*/
	const IntID& getSamples(size_t pcv_i){char buffer[4096];sprintf_s (buffer, "%s.pcv[%i].smp",mName.c_str(),pcv_i);return (const char*)buffer;}
	/*Determines wether the normal calculated for this section of the stroke should be flipped or not (default).*/
	const BoolID& getOpposite(size_t pcv_i){char buffer[4096];sprintf_s (buffer, "%s.pcv[%i].opp",mName.c_str(),pcv_i);return (const char*)buffer;}
	/*Output worldspace points for brush stroke. Although it is writable, do not write to this attribute.*/
	const Double3ID& getOutPoint(size_t opt_i){char buffer[4096];sprintf_s (buffer, "%s.opt[%i]",mName.c_str(),opt_i);return (const char*)buffer;}
	/*X value of a stroke point. Although it is writable, do not write to this attribute.*/
	const DoubleID& getOutPointX(size_t opt_i){char buffer[4096];sprintf_s (buffer, "%s.opt[%i].ox",mName.c_str(),opt_i);return (const char*)buffer;}
	/*Y value of a stroke point. Although it is writable, do not write to this attribute.*/
	const DoubleID& getOutPointY(size_t opt_i){char buffer[4096];sprintf_s (buffer, "%s.opt[%i].oy",mName.c_str(),opt_i);return (const char*)buffer;}
	/*Z value of a stroke point. Although it is writable, do not write to this attribute.*/
	const DoubleID& getOutPointZ(size_t opt_i){char buffer[4096];sprintf_s (buffer, "%s.opt[%i].oz",mName.c_str(),opt_i);return (const char*)buffer;}
	/*output worldspace normals for brush stroke*/
	const Double3ID& getOutNormal(size_t onm_i){char buffer[4096];sprintf_s (buffer, "%s.onm[%i]",mName.c_str(),onm_i);return (const char*)buffer;}
	/*X value of a stroke normal*/
	const DoubleID& getOutNormalX(size_t onm_i){char buffer[4096];sprintf_s (buffer, "%s.onm[%i].onx",mName.c_str(),onm_i);return (const char*)buffer;}
	/*Y value of a stroke normal*/
	const DoubleID& getOutNormalY(size_t onm_i){char buffer[4096];sprintf_s (buffer, "%s.onm[%i].ony",mName.c_str(),onm_i);return (const char*)buffer;}
	/*Z value of a stroke normal*/
	const DoubleID& getOutNormalZ(size_t onm_i){char buffer[4096];sprintf_s (buffer, "%s.onm[%i].onz",mName.c_str(),onm_i);return (const char*)buffer;}
	/*Parameter to modulate using cached pen pressure values*/
	UnsignedintID getPressureMap1(){char buffer[4096];sprintf_s (buffer, "%s.spm1",mName.c_str());return (const char*)buffer;}
	/*0-1 pressure inputs are remapped into the min-max range*/
	DoubleID getPressureMin1(){char buffer[4096];sprintf_s (buffer, "%s.ps1",mName.c_str());return (const char*)buffer;}
	/*0-1 pressure inputs are remapped into the min-max range*/
	DoubleID getPressureMax1(){char buffer[4096];sprintf_s (buffer, "%s.px1",mName.c_str());return (const char*)buffer;}
	/*Parameter to modulate using cached pen pressure values*/
	UnsignedintID getPressureMap2(){char buffer[4096];sprintf_s (buffer, "%s.spm2",mName.c_str());return (const char*)buffer;}
	/*0-1 pressure inputs are remapped into the min-max range*/
	DoubleID getPressureMin2(){char buffer[4096];sprintf_s (buffer, "%s.ps2",mName.c_str());return (const char*)buffer;}
	/*0-1 pressure inputs are remapped into the min-max range*/
	DoubleID getPressureMax2(){char buffer[4096];sprintf_s (buffer, "%s.px2",mName.c_str());return (const char*)buffer;}
	/*Parameter to modulate using cached pen pressure values*/
	UnsignedintID getPressureMap3(){char buffer[4096];sprintf_s (buffer, "%s.spm3",mName.c_str());return (const char*)buffer;}
	/*0-1 pressure inputs are remapped into the min-max range*/
	DoubleID getPressureMin3(){char buffer[4096];sprintf_s (buffer, "%s.ps3",mName.c_str());return (const char*)buffer;}
	/*0-1 pressure inputs are remapped into the min-max range*/
	DoubleID getPressureMax3(){char buffer[4096];sprintf_s (buffer, "%s.px3",mName.c_str());return (const char*)buffer;}
	/*
	Scale factor applied to the input pressure array.
	This can be used to shape stroke widths, or other elements like tube length
	along the stroke without needing to edit using pressure curves.
	*/
	const PressureScaleID& getPressureScale(size_t psc_i){char buffer[4096];sprintf_s (buffer, "%s.psc[%i]",mName.c_str(),psc_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getPressureScale_Position(size_t psc_i){char buffer[4096];sprintf_s (buffer, "%s.psc[%i].pscp",mName.c_str(),psc_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getPressureScale_FloatValue(size_t psc_i){char buffer[4096];sprintf_s (buffer, "%s.psc[%i].pscfv",mName.c_str(),psc_i);return (const char*)buffer;}
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
	const UnsignedintID& getPressureScale_Interp(size_t psc_i){char buffer[4096];sprintf_s (buffer, "%s.psc[%i].psci",mName.c_str(),psc_i);return (const char*)buffer;}
	/*the array of pressure values generated by pen device*/
	const DoubleID& getPressure(size_t psr_i){char buffer[4096];sprintf_s (buffer, "%s.psr[%i]",mName.c_str(),psr_i);return (const char*)buffer;}
	/*
	This is the name of the UVset, to which the curve is connected.
	This exists only when we have created PFX on Poly.
	*/
	const MessageID& getUvSetName(size_t uvsetn_i){char buffer[4096];sprintf_s (buffer, "%s.uvsetn[%i]",mName.c_str(),uvsetn_i);return (const char*)buffer;}
protected:
	Stroke(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PfxGeometry(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_STROKE_H__
