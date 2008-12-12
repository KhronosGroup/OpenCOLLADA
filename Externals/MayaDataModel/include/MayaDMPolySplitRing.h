/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSPLITRING_H__
#define __MayaDM_POLYSPLITRING_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
<p><pre>    This node handles splitting the polygon object in multiple ways.

</pre></p>
*/
class PolySplitRing : public PolyModifierWorld
{
public:
	/*
	Curve which can control the profile of the new edges
	when doing a multisplit.
	*/
	struct ProfileCurve{
		float profileCurve_Position;
		float profileCurve_FloatValue;
		unsigned int profileCurve_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", profileCurve_Position);
			fprintf_s(file,"%f ", profileCurve_FloatValue);
			fprintf_s(file,"%i", profileCurve_Interp);
		}
	};
public:
	PolySplitRing(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polySplitRing"){}
	virtual ~PolySplitRing(){}
	/*
	Weight value controlling the relative positioning of the
	new points on existing edges. Range is [0.0, 1.0].
	Value of 0.1 indicates the new edges will be placed closer to
	the start vertex of the first edge of the sequence of edges.
	*/
	void setWeight(float wt){if(wt == 0.5) return; fprintf_s(mFile, "setAttr \".wt\" %f;\n", wt);}
	/*
	Weight value controlling the relative positioning of the
	new points on existing edges. Range is [0.0, 1.0].
	Value of 0.1 indicates the new edges will be placed closer to
	the start vertex of the first edge of the sequence of edges.
	*/
	void setWeight(const FloatID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.wt\";\n",mName.c_str());}
	/*
	The split can either be relative or absolute.
	If this attribute is false then the weight attribute will be used on all
	edges in the sequence as the percentage along the edge to do the split.
	If this attribute is true then the weight attribute is used with the length
	of the shortest edge in the sequence to determine the distance that the split
	should occur on all other edges in the sequence.
	*/
	void setAbsoluteWeight(const BoolID& ab){fprintf_s(mFile,"connectAttr \"");ab.write(mFile);fprintf_s(mFile,"\" \"%s.ab\";\n",mName.c_str());}
	/*
	This attribute is used when doing an absolute split.  If true then the
	distance is taken from the start vertex of the root edge.  If false the
	distance is taken from the end vertext of the root edge.
	*/
	void setDirection(bool dr){if(dr == true) return; fprintf_s(mFile, "setAttr \".dr\" %i;\n", dr);}
	/*
	This attribute is used when doing an absolute split.  If true then the
	distance is taken from the start vertex of the root edge.  If false the
	distance is taken from the end vertext of the root edge.
	*/
	void setDirection(const BoolID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr\";\n",mName.c_str());}
	/*
	The weight attribute uses the start vertex of this
	edge to determine where the new split occurs.
	*/
	void setRootEdge(int re){if(re == -1) return; fprintf_s(mFile, "setAttr \".re\" %i;\n", re);}
	/*
	The weight attribute uses the start vertex of this
	edge to determine where the new split occurs.
	*/
	void setRootEdge(const IntID& re){fprintf_s(mFile,"connectAttr \"");re.write(mFile);fprintf_s(mFile,"\" \"%s.re\";\n",mName.c_str());}
	/*Angle below which new edges will be smoothed*/
	void setSmoothingAngle(double sma){if(sma == 1) return; fprintf_s(mFile, "setAttr \".sma\" %f;\n", sma);}
	/*Angle below which new edges will be smoothed*/
	void setSmoothingAngle(const DoubleID& sma){fprintf_s(mFile,"connectAttr \"");sma.write(mFile);fprintf_s(mFile,"\" \"%s.sma\";\n",mName.c_str());}
	/*Format: 0 - Absolute, 1 - Relative, 2 - Multi*/
	void setSplitType(unsigned int stp){if(stp == 1) return; fprintf_s(mFile, "setAttr \".stp\" %i;\n", stp);}
	/*Format: 0 - Absolute, 1 - Relative, 2 - Multi*/
	void setSplitType(const UnsignedintID& stp){fprintf_s(mFile,"connectAttr \"");stp.write(mFile);fprintf_s(mFile,"\" \"%s.stp\";\n",mName.c_str());}
	/*Number of divisions.*/
	void setDivisions(int div){if(div == 2) return; fprintf_s(mFile, "setAttr \".div\" %i;\n", div);}
	/*Number of divisions.*/
	void setDivisions(const IntID& div){fprintf_s(mFile,"connectAttr \"");div.write(mFile);fprintf_s(mFile,"\" \"%s.div\";\n",mName.c_str());}
	/*Enables the use of the profile curve.*/
	void setEnableProfileCurve(bool epc){if(epc == true) return; fprintf_s(mFile, "setAttr \".epc\" %i;\n", epc);}
	/*Enables the use of the profile curve.*/
	void setEnableProfileCurve(const BoolID& epc){fprintf_s(mFile,"connectAttr \"");epc.write(mFile);fprintf_s(mFile,"\" \"%s.epc\";\n",mName.c_str());}
	/*
	Curve which can control the profile of the new edges
	when doing a multisplit.
	*/
	void setProfileCurve(size_t p_i,const ProfileCurve& p){fprintf_s(mFile, "setAttr \".p[%i]\" ",p_i);p.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Curve which can control the profile of the new edges
	when doing a multisplit.
	*/
	void setProfileCurve(size_t p_i,const ProfileCurveID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setProfileCurve_Position(size_t p_i,float pp){if(pp == 0.0) return; fprintf_s(mFile, "setAttr \".p[%i].pp\" %f;\n", p_i,pp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setProfileCurve_Position(size_t p_i,const FloatID& pp){fprintf_s(mFile,"connectAttr \"");pp.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].pp\";\n",mName.c_str(),p_i);}
	/*Ramp value at the sibling position*/
	void setProfileCurve_FloatValue(size_t p_i,float pfv){if(pfv == 0.0) return; fprintf_s(mFile, "setAttr \".p[%i].pfv\" %f;\n", p_i,pfv);}
	/*Ramp value at the sibling position*/
	void setProfileCurve_FloatValue(size_t p_i,const FloatID& pfv){fprintf_s(mFile,"connectAttr \"");pfv.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].pfv\";\n",mName.c_str(),p_i);}
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
	void setProfileCurve_Interp(size_t p_i,unsigned int pi){if(pi == 0) return; fprintf_s(mFile, "setAttr \".p[%i].pi\" %i;\n", p_i,pi);}
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
	void setProfileCurve_Interp(size_t p_i,const UnsignedintID& pi){fprintf_s(mFile,"connectAttr \"");pi.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].pi\";\n",mName.c_str(),p_i);}
	/*
	Changes the offset to the multisplit profile curve.
	eg. if the profile curve values go between 0 and 1 and this
	value is set to -1 then the profile curves values will be
	adjusted to go between -1 and 0.
	*/
	void setProfileCurveInputOffset(float pio){if(pio == 0.0f) return; fprintf_s(mFile, "setAttr \".pio\" %f;\n", pio);}
	/*
	Changes the offset to the multisplit profile curve.
	eg. if the profile curve values go between 0 and 1 and this
	value is set to -1 then the profile curves values will be
	adjusted to go between -1 and 0.
	*/
	void setProfileCurveInputOffset(const FloatID& pio){fprintf_s(mFile,"connectAttr \"");pio.write(mFile);fprintf_s(mFile,"\" \"%s.pio\";\n",mName.c_str());}
	/*
	Changes the range of values that the profile curve represents.
	eg. if the profile curve values go between 0 and 1 and this
	value is set to 2 then the profile curves values will be
	adjusted to go between 0 and 2.
	*/
	void setProfileCurveInputScale(float pis){if(pis == 1.0f) return; fprintf_s(mFile, "setAttr \".pis\" %f;\n", pis);}
	/*
	Changes the range of values that the profile curve represents.
	eg. if the profile curve values go between 0 and 1 and this
	value is set to 2 then the profile curves values will be
	adjusted to go between 0 and 2.
	*/
	void setProfileCurveInputScale(const FloatID& pis){fprintf_s(mFile,"connectAttr \"");pis.write(mFile);fprintf_s(mFile,"\" \"%s.pis\";\n",mName.c_str());}
	/*
	When doing a multisplit on a set of non-closed edge ring
	this will toggle the normals at the ends of the split to
	be calculated as the edge normal or the face normal.
	*/
	void setUseFaceNormalsAtEnds(bool fne){if(fne == true) return; fprintf_s(mFile, "setAttr \".fne\" %i;\n", fne);}
	/*
	When doing a multisplit on a set of non-closed edge ring
	this will toggle the normals at the ends of the split to
	be calculated as the edge normal or the face normal.
	*/
	void setUseFaceNormalsAtEnds(const BoolID& fne){fprintf_s(mFile,"connectAttr \"");fne.write(mFile);fprintf_s(mFile,"\" \"%s.fne\";\n",mName.c_str());}
	/*
	Changes how the profile curve effects the offset when doing
	a multisplit.  If true then the verts will be offset the same distance
	based on the shortest edge being split.  If false then each inserted
	edge loop will be offset a distance relative to the length of the edge
	that is being split.
	*/
	void setUseEqualMultiplier(bool uem){if(uem == true) return; fprintf_s(mFile, "setAttr \".uem\" %i;\n", uem);}
	/*
	Changes how the profile curve effects the offset when doing
	a multisplit.  If true then the verts will be offset the same distance
	based on the shortest edge being split.  If false then each inserted
	edge loop will be offset a distance relative to the length of the edge
	that is being split.
	*/
	void setUseEqualMultiplier(const BoolID& uem){fprintf_s(mFile,"connectAttr \"");uem.write(mFile);fprintf_s(mFile,"\" \"%s.uem\";\n",mName.c_str());}
	/*
	Fixes splits which go across a quad face leaving a 5 and 3
	sided faces by splitting from the middle of the new edge to
	the vertex accross from the edge on the 5 sided face.
	*/
	void setFixQuads(bool fq){if(fq == false) return; fprintf_s(mFile, "setAttr \".fq\" %i;\n", fq);}
	/*
	Fixes splits which go across a quad face leaving a 5 and 3
	sided faces by splitting from the middle of the new edge to
	the vertex accross from the edge on the 5 sided face.
	*/
	void setFixQuads(const BoolID& fq){fprintf_s(mFile,"connectAttr \"");fq.write(mFile);fprintf_s(mFile,"\" \"%s.fq\";\n",mName.c_str());}
	/*
	Weight value controlling the relative positioning of the
	new points on existing edges. Range is [0.0, 1.0].
	Value of 0.1 indicates the new edges will be placed closer to
	the start vertex of the first edge of the sequence of edges.
	*/
	FloatID getWeight(){char buffer[4096];sprintf_s (buffer, "%s.wt",mName.c_str());return (const char*)buffer;}
	/*
	The split can either be relative or absolute.
	If this attribute is false then the weight attribute will be used on all
	edges in the sequence as the percentage along the edge to do the split.
	If this attribute is true then the weight attribute is used with the length
	of the shortest edge in the sequence to determine the distance that the split
	should occur on all other edges in the sequence.
	*/
	BoolID getAbsoluteWeight(){char buffer[4096];sprintf_s (buffer, "%s.ab",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is used when doing an absolute split.  If true then the
	distance is taken from the start vertex of the root edge.  If false the
	distance is taken from the end vertext of the root edge.
	*/
	BoolID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.dr",mName.c_str());return (const char*)buffer;}
	/*
	The weight attribute uses the start vertex of this
	edge to determine where the new split occurs.
	*/
	IntID getRootEdge(){char buffer[4096];sprintf_s (buffer, "%s.re",mName.c_str());return (const char*)buffer;}
	/*Angle below which new edges will be smoothed*/
	DoubleID getSmoothingAngle(){char buffer[4096];sprintf_s (buffer, "%s.sma",mName.c_str());return (const char*)buffer;}
	/*Format: 0 - Absolute, 1 - Relative, 2 - Multi*/
	UnsignedintID getSplitType(){char buffer[4096];sprintf_s (buffer, "%s.stp",mName.c_str());return (const char*)buffer;}
	/*Number of divisions.*/
	IntID getDivisions(){char buffer[4096];sprintf_s (buffer, "%s.div",mName.c_str());return (const char*)buffer;}
	/*Enables the use of the profile curve.*/
	BoolID getEnableProfileCurve(){char buffer[4096];sprintf_s (buffer, "%s.epc",mName.c_str());return (const char*)buffer;}
	/*
	Curve which can control the profile of the new edges
	when doing a multisplit.
	*/
	const ProfileCurveID& getProfileCurve(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getProfileCurve_Position(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].pp",mName.c_str(),p_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getProfileCurve_FloatValue(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].pfv",mName.c_str(),p_i);return (const char*)buffer;}
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
	const UnsignedintID& getProfileCurve_Interp(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].pi",mName.c_str(),p_i);return (const char*)buffer;}
	/*
	Changes the offset to the multisplit profile curve.
	eg. if the profile curve values go between 0 and 1 and this
	value is set to -1 then the profile curves values will be
	adjusted to go between -1 and 0.
	*/
	FloatID getProfileCurveInputOffset(){char buffer[4096];sprintf_s (buffer, "%s.pio",mName.c_str());return (const char*)buffer;}
	/*
	Changes the range of values that the profile curve represents.
	eg. if the profile curve values go between 0 and 1 and this
	value is set to 2 then the profile curves values will be
	adjusted to go between 0 and 2.
	*/
	FloatID getProfileCurveInputScale(){char buffer[4096];sprintf_s (buffer, "%s.pis",mName.c_str());return (const char*)buffer;}
	/*
	When doing a multisplit on a set of non-closed edge ring
	this will toggle the normals at the ends of the split to
	be calculated as the edge normal or the face normal.
	*/
	BoolID getUseFaceNormalsAtEnds(){char buffer[4096];sprintf_s (buffer, "%s.fne",mName.c_str());return (const char*)buffer;}
	/*
	Changes how the profile curve effects the offset when doing
	a multisplit.  If true then the verts will be offset the same distance
	based on the shortest edge being split.  If false then each inserted
	edge loop will be offset a distance relative to the length of the edge
	that is being split.
	*/
	BoolID getUseEqualMultiplier(){char buffer[4096];sprintf_s (buffer, "%s.uem",mName.c_str());return (const char*)buffer;}
	/*
	Fixes splits which go across a quad face leaving a 5 and 3
	sided faces by splitting from the middle of the new edge to
	the vertex accross from the edge on the 5 sided face.
	*/
	BoolID getFixQuads(){char buffer[4096];sprintf_s (buffer, "%s.fq",mName.c_str());return (const char*)buffer;}
protected:
	PolySplitRing(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSPLITRING_H__
