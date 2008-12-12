/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYEXTRUDEFACE_H__
#define __MayaDM_POLYEXTRUDEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyMoveFace.h"
namespace MayaDM
{
/*
Extrudes faces separately or together.<p/>

 This node uses many attributes of its parent nodes
 to calculate the face extrusion.<p/>
*/
class PolyExtrudeFace : public PolyMoveFace
{
public:
	/*
	Curve control for taper along extrusion
	Using this curve, the taper along extrusion
	can be changed from a simple linear scaling to
	custom scaling along the extrusion path.
	*/
	struct TaperCurve{
		float taperCurve_Position;
		float taperCurve_FloatValue;
		unsigned int taperCurve_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", taperCurve_Position);
			fprintf_s(file,"%f ", taperCurve_FloatValue);
			fprintf_s(file,"%i", taperCurve_Interp);
		}
	};
public:
	PolyExtrudeFace(FILE* file,const std::string& name,const std::string& parent=""):PolyMoveFace(file, name, parent, "polyExtrudeFace"){}
	virtual ~PolyExtrudeFace(){}
	/*
	How to extrude faces.
	If "on", faces are pulled together (connected ones stay connected),
	otherwise they are pulled independently.
	*/
	void setKeepFacesTogether(bool kft){if(kft == true) return; fprintf_s(mFile, "setAttr \".kft\" %i;\n", kft);}
	/*
	How to extrude faces.
	If "on", faces are pulled together (connected ones stay connected),
	otherwise they are pulled independently.
	*/
	void setKeepFacesTogether(const BoolID& kft){fprintf_s(mFile,"connectAttr \"");kft.write(mFile);fprintf_s(mFile,"\" \"%s.kft\";\n",mName.c_str());}
	/*How many divisions should the extrusion be broken-up into.*/
	void setDivisions(int d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*How many divisions should the extrusion be broken-up into.*/
	void setDivisions(const IntID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*input profile curve*/
	void setInputProfile(const NurbsCurveID& ipc){fprintf_s(mFile,"connectAttr \"");ipc.write(mFile);fprintf_s(mFile,"\" \"%s.ipc\";\n",mName.c_str());}
	/*Twist or Rotation along the extrusion path*/
	void setTwist(double twt){if(twt == 0) return; fprintf_s(mFile, "setAttr \".twt\" %f;\n", twt);}
	/*Twist or Rotation along the extrusion path*/
	void setTwist(const DoubleID& twt){fprintf_s(mFile,"connectAttr \"");twt.write(mFile);fprintf_s(mFile,"\" \"%s.twt\";\n",mName.c_str());}
	/*Taper or Scale along the extrusion path*/
	void setTaper(double tp){if(tp == 1.0) return; fprintf_s(mFile, "setAttr \".tp\" %f;\n", tp);}
	/*Taper or Scale along the extrusion path*/
	void setTaper(const DoubleID& tp){fprintf_s(mFile,"connectAttr \"");tp.write(mFile);fprintf_s(mFile,"\" \"%s.tp\";\n",mName.c_str());}
	/*
	Curve control for taper along extrusion
	Using this curve, the taper along extrusion
	can be changed from a simple linear scaling to
	custom scaling along the extrusion path.
	*/
	void setTaperCurve(size_t c_i,const TaperCurve& c){fprintf_s(mFile, "setAttr \".c[%i]\" ",c_i);c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Curve control for taper along extrusion
	Using this curve, the taper along extrusion
	can be changed from a simple linear scaling to
	custom scaling along the extrusion path.
	*/
	void setTaperCurve(size_t c_i,const TaperCurveID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c[%i]\";\n",mName.c_str(),c_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setTaperCurve_Position(size_t c_i,float cp){if(cp == 0.0) return; fprintf_s(mFile, "setAttr \".c[%i].cp\" %f;\n", c_i,cp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setTaperCurve_Position(size_t c_i,const FloatID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.c[%i].cp\";\n",mName.c_str(),c_i);}
	/*Ramp value at the sibling position*/
	void setTaperCurve_FloatValue(size_t c_i,float cfv){if(cfv == 0.0) return; fprintf_s(mFile, "setAttr \".c[%i].cfv\" %f;\n", c_i,cfv);}
	/*Ramp value at the sibling position*/
	void setTaperCurve_FloatValue(size_t c_i,const FloatID& cfv){fprintf_s(mFile,"connectAttr \"");cfv.write(mFile);fprintf_s(mFile,"\" \"%s.c[%i].cfv\";\n",mName.c_str(),c_i);}
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
	void setTaperCurve_Interp(size_t c_i,unsigned int ci){if(ci == 0) return; fprintf_s(mFile, "setAttr \".c[%i].ci\" %i;\n", c_i,ci);}
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
	void setTaperCurve_Interp(size_t c_i,const UnsignedintID& ci){fprintf_s(mFile,"connectAttr \"");ci.write(mFile);fprintf_s(mFile,"\" \"%s.c[%i].ci\";\n",mName.c_str(),c_i);}
	/*Angle below which new edges will be smoothed*/
	void setSmoothingAngle(double sma){if(sma == 3) return; fprintf_s(mFile, "setAttr \".sma\" %f;\n", sma);}
	/*Angle below which new edges will be smoothed*/
	void setSmoothingAngle(const DoubleID& sma){fprintf_s(mFile,"connectAttr \"");sma.write(mFile);fprintf_s(mFile,"\" \"%s.sma\";\n",mName.c_str());}
	/*
	How to extrude faces.
	If "on", faces are pulled together (connected ones stay connected),
	otherwise they are pulled independently.
	*/
	BoolID getKeepFacesTogether(){char buffer[4096];sprintf_s (buffer, "%s.kft",mName.c_str());return (const char*)buffer;}
	/*How many divisions should the extrusion be broken-up into.*/
	IntID getDivisions(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*input profile curve*/
	NurbsCurveID getInputProfile(){char buffer[4096];sprintf_s (buffer, "%s.ipc",mName.c_str());return (const char*)buffer;}
	/*Twist or Rotation along the extrusion path*/
	DoubleID getTwist(){char buffer[4096];sprintf_s (buffer, "%s.twt",mName.c_str());return (const char*)buffer;}
	/*Taper or Scale along the extrusion path*/
	DoubleID getTaper(){char buffer[4096];sprintf_s (buffer, "%s.tp",mName.c_str());return (const char*)buffer;}
	/*
	Curve control for taper along extrusion
	Using this curve, the taper along extrusion
	can be changed from a simple linear scaling to
	custom scaling along the extrusion path.
	*/
	const TaperCurveID& getTaperCurve(size_t c_i){char buffer[4096];sprintf_s (buffer, "%s.c[%i]",mName.c_str(),c_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getTaperCurve_Position(size_t c_i){char buffer[4096];sprintf_s (buffer, "%s.c[%i].cp",mName.c_str(),c_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getTaperCurve_FloatValue(size_t c_i){char buffer[4096];sprintf_s (buffer, "%s.c[%i].cfv",mName.c_str(),c_i);return (const char*)buffer;}
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
	const UnsignedintID& getTaperCurve_Interp(size_t c_i){char buffer[4096];sprintf_s (buffer, "%s.c[%i].ci",mName.c_str(),c_i);return (const char*)buffer;}
	/*Angle below which new edges will be smoothed*/
	DoubleID getSmoothingAngle(){char buffer[4096];sprintf_s (buffer, "%s.sma",mName.c_str());return (const char*)buffer;}
protected:
	PolyExtrudeFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyMoveFace(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYEXTRUDEFACE_H__
