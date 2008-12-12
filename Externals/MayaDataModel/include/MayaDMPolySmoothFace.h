/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSMOOTHFACE_H__
#define __MayaDM_POLYSMOOTHFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Subdivide and smooth faces of a polygonal object.<p/>

 See the documentation for the parent node polyModifier for more
 details.<p/>
*/
class PolySmoothFace : public PolyModifier
{
public:
public:
	PolySmoothFace(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polySmoothFace"){}
	virtual ~PolySmoothFace(){}
	/*
	Type of smoothing algorithm to use
	0 - exponential - traditional smoothing
	1 - linear - number of faces per edge grows linearly
	*/
	void setMethod(unsigned int mth){if(mth == 0) return; fprintf_s(mFile, "setAttr \".mth\" %i;\n", mth);}
	/*
	Type of smoothing algorithm to use
	0 - exponential - traditional smoothing
	1 - linear - number of faces per edge grows linearly
	*/
	void setMethod(const UnsignedintID& mth){fprintf_s(mFile,"connectAttr \"");mth.write(mFile);fprintf_s(mFile,"\" \"%s.mth\";\n",mName.c_str());}
	/*
	The smoothness parameter. Range is [0,1]. Default value of 1
	smooths the faces as much as possible. Value of 0 subdivides faces only.
	*/
	void setContinuity(float c){if(c == 1) return; fprintf_s(mFile, "setAttr \".c\" %f;\n", c);}
	/*
	The smoothness parameter. Range is [0,1]. Default value of 1
	smooths the faces as much as possible. Value of 0 subdivides faces only.
	*/
	void setContinuity(const FloatID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*The number of recursive quad subdivisions to perform on each face.*/
	void setDivisions(short dv){if(dv == 1) return; fprintf_s(mFile, "setAttr \".dv\" %i;\n", dv);}
	/*The number of recursive quad subdivisions to perform on each face.*/
	void setDivisions(const ShortID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*If true: UVs as well as geometry will be smoothed*/
	void setSmoothUVs(bool suv){if(suv == false) return; fprintf_s(mFile, "setAttr \".suv\" %i;\n", suv);}
	/*If true: UVs as well as geometry will be smoothed*/
	void setSmoothUVs(const BoolID& suv){fprintf_s(mFile,"connectAttr \"");suv.write(mFile);fprintf_s(mFile,"\" \"%s.suv\";\n",mName.c_str());}
	/*If true: border edges will not be smoothed.*/
	void setKeepBorder(bool kb){if(kb == true) return; fprintf_s(mFile, "setAttr \".kb\" %i;\n", kb);}
	/*If true: border edges will not be smoothed.*/
	void setKeepBorder(const BoolID& kb){fprintf_s(mFile,"connectAttr \"");kb.write(mFile);fprintf_s(mFile,"\" \"%s.kb\";\n",mName.c_str());}
	/*If true: edges at selection borders will not be smoothed.*/
	void setKeepSelectionBorder(bool ksb){if(ksb == true) return; fprintf_s(mFile, "setAttr \".ksb\" %i;\n", ksb);}
	/*If true: edges at selection borders will not be smoothed.*/
	void setKeepSelectionBorder(const BoolID& ksb){fprintf_s(mFile,"connectAttr \"");ksb.write(mFile);fprintf_s(mFile,"\" \"%s.ksb\";\n",mName.c_str());}
	/*If true: hard edges will not be smoothed.*/
	void setKeepHardEdge(bool khe){if(khe == false) return; fprintf_s(mFile, "setAttr \".khe\" %i;\n", khe);}
	/*If true: hard edges will not be smoothed.*/
	void setKeepHardEdge(const BoolID& khe){fprintf_s(mFile,"connectAttr \"");khe.write(mFile);fprintf_s(mFile,"\" \"%s.khe\";\n",mName.c_str());}
	/*
	If true: edges which are a result of smoothed edges will be given
	the same value for their edge hardness.  New subdivided edges will
	always be smooth.
	*/
	void setPropagateEdgeHardness(bool peh){if(peh == false) return; fprintf_s(mFile, "setAttr \".peh\" %i;\n", peh);}
	/*
	If true: edges which are a result of smoothed edges will be given
	the same value for their edge hardness.  New subdivided edges will
	always be smooth.
	*/
	void setPropagateEdgeHardness(const BoolID& peh){fprintf_s(mFile,"connectAttr \"");peh.write(mFile);fprintf_s(mFile,"\" \"%s.peh\";\n",mName.c_str());}
	/*
	Treatment of UV map borders
	0 - all map border edges will be smoothed
	1 - map borders that are also geometry borders will be smoothed
	2 - no map borders will be smoothed
	*/
	void setKeepMapBorders(unsigned int kmb){if(kmb == 1) return; fprintf_s(mFile, "setAttr \".kmb\" %i;\n", kmb);}
	/*
	Treatment of UV map borders
	0 - all map border edges will be smoothed
	1 - map borders that are also geometry borders will be smoothed
	2 - no map borders will be smoothed
	*/
	void setKeepMapBorders(const UnsignedintID& kmb){fprintf_s(mFile,"connectAttr \"");kmb.write(mFile);fprintf_s(mFile,"\" \"%s.kmb\";\n",mName.c_str());}
	/*
	If true: the object will be smoothed consistently from frame to frame.
	This is best when the object is being deformed or animated .
	If false: non-starlike faces will be triangulated before being
	smoothed.  This avoids self-overlapping faces, but could lead to a
	change in topology (number of vertices/faces) from frame to frame,
	during an animated deformation.
	*/
	void setKeepTessellation(bool kt){if(kt == true) return; fprintf_s(mFile, "setAttr \".kt\" %i;\n", kt);}
	/*
	If true: the object will be smoothed consistently from frame to frame.
	This is best when the object is being deformed or animated .
	If false: non-starlike faces will be triangulated before being
	smoothed.  This avoids self-overlapping faces, but could lead to a
	change in topology (number of vertices/faces) from frame to frame,
	during an animated deformation.
	*/
	void setKeepTessellation(const BoolID& kt){fprintf_s(mFile,"connectAttr \"");kt.write(mFile);fprintf_s(mFile,"\" \"%s.kt\";\n",mName.c_str());}
	/*Number of times the subdivide and smooth operation is run.*/
	void setSubdivisionLevels(int sl){if(sl == 1) return; fprintf_s(mFile, "setAttr \".sl\" %i;\n", sl);}
	/*Number of times the subdivide and smooth operation is run.*/
	void setSubdivisionLevels(const IntID& sl){fprintf_s(mFile,"connectAttr \"");sl.write(mFile);fprintf_s(mFile,"\" \"%s.sl\";\n",mName.c_str());}
	/*Number of subdivisions along one edge for each step.*/
	void setDivisionsPerEdge(int dpe){if(dpe == 1) return; fprintf_s(mFile, "setAttr \".dpe\" %i;\n", dpe);}
	/*Number of subdivisions along one edge for each step.*/
	void setDivisionsPerEdge(const IntID& dpe){fprintf_s(mFile,"connectAttr \"");dpe.write(mFile);fprintf_s(mFile,"\" \"%s.dpe\";\n",mName.c_str());}
	/*Degree of the resulting limit surface*/
	void setDegree(int deg){if(deg == 3) return; fprintf_s(mFile, "setAttr \".deg\" %i;\n", deg);}
	/*Degree of the resulting limit surface*/
	void setDegree(const IntID& deg){fprintf_s(mFile,"connectAttr \"");deg.write(mFile);fprintf_s(mFile,"\" \"%s.deg\";\n",mName.c_str());}
	/*0 is approximation, 1 is interpolation scheme*/
	void setPushStrength(float ps){if(ps == 0.0) return; fprintf_s(mFile, "setAttr \".ps\" %f;\n", ps);}
	/*0 is approximation, 1 is interpolation scheme*/
	void setPushStrength(const FloatID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*When 1, push vectors are renormalized to keep length constant*/
	void setRoundness(float ro){if(ro == 0) return; fprintf_s(mFile, "setAttr \".ro\" %f;\n", ro);}
	/*When 1, push vectors are renormalized to keep length constant*/
	void setRoundness(const FloatID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*Internal attribute to handle file compatibilty*/
	void setMaya65Above(bool ma){if(ma == false) return; fprintf_s(mFile, "setAttr \".ma\" %i;\n", ma);}
	/*Internal attribute to handle file compatibilty*/
	void setMaya65Above(const BoolID& ma){fprintf_s(mFile,"connectAttr \"");ma.write(mFile);fprintf_s(mFile,"\" \"%s.ma\";\n",mName.c_str());}
	/*Internal attribute to handle file compatibilty*/
	void setMaya2008Above(bool m08){if(m08 == false) return; fprintf_s(mFile, "setAttr \".m08\" %i;\n", m08);}
	/*Internal attribute to handle file compatibilty*/
	void setMaya2008Above(const BoolID& m08){fprintf_s(mFile,"connectAttr \"");m08.write(mFile);fprintf_s(mFile,"\" \"%s.m08\";\n",mName.c_str());}
	/*
	Type of smoothing algorithm to use
	0 - exponential - traditional smoothing
	1 - linear - number of faces per edge grows linearly
	*/
	UnsignedintID getMethod(){char buffer[4096];sprintf_s (buffer, "%s.mth",mName.c_str());return (const char*)buffer;}
	/*
	The smoothness parameter. Range is [0,1]. Default value of 1
	smooths the faces as much as possible. Value of 0 subdivides faces only.
	*/
	FloatID getContinuity(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*The number of recursive quad subdivisions to perform on each face.*/
	ShortID getDivisions(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*If true: UVs as well as geometry will be smoothed*/
	BoolID getSmoothUVs(){char buffer[4096];sprintf_s (buffer, "%s.suv",mName.c_str());return (const char*)buffer;}
	/*If true: border edges will not be smoothed.*/
	BoolID getKeepBorder(){char buffer[4096];sprintf_s (buffer, "%s.kb",mName.c_str());return (const char*)buffer;}
	/*If true: edges at selection borders will not be smoothed.*/
	BoolID getKeepSelectionBorder(){char buffer[4096];sprintf_s (buffer, "%s.ksb",mName.c_str());return (const char*)buffer;}
	/*If true: hard edges will not be smoothed.*/
	BoolID getKeepHardEdge(){char buffer[4096];sprintf_s (buffer, "%s.khe",mName.c_str());return (const char*)buffer;}
	/*
	If true: edges which are a result of smoothed edges will be given
	the same value for their edge hardness.  New subdivided edges will
	always be smooth.
	*/
	BoolID getPropagateEdgeHardness(){char buffer[4096];sprintf_s (buffer, "%s.peh",mName.c_str());return (const char*)buffer;}
	/*
	Treatment of UV map borders
	0 - all map border edges will be smoothed
	1 - map borders that are also geometry borders will be smoothed
	2 - no map borders will be smoothed
	*/
	UnsignedintID getKeepMapBorders(){char buffer[4096];sprintf_s (buffer, "%s.kmb",mName.c_str());return (const char*)buffer;}
	/*
	If true: the object will be smoothed consistently from frame to frame.
	This is best when the object is being deformed or animated .
	If false: non-starlike faces will be triangulated before being
	smoothed.  This avoids self-overlapping faces, but could lead to a
	change in topology (number of vertices/faces) from frame to frame,
	during an animated deformation.
	*/
	BoolID getKeepTessellation(){char buffer[4096];sprintf_s (buffer, "%s.kt",mName.c_str());return (const char*)buffer;}
	/*Number of times the subdivide and smooth operation is run.*/
	IntID getSubdivisionLevels(){char buffer[4096];sprintf_s (buffer, "%s.sl",mName.c_str());return (const char*)buffer;}
	/*Number of subdivisions along one edge for each step.*/
	IntID getDivisionsPerEdge(){char buffer[4096];sprintf_s (buffer, "%s.dpe",mName.c_str());return (const char*)buffer;}
	/*Degree of the resulting limit surface*/
	IntID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.deg",mName.c_str());return (const char*)buffer;}
	/*0 is approximation, 1 is interpolation scheme*/
	FloatID getPushStrength(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*When 1, push vectors are renormalized to keep length constant*/
	FloatID getRoundness(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*Internal attribute to handle file compatibilty*/
	BoolID getMaya65Above(){char buffer[4096];sprintf_s (buffer, "%s.ma",mName.c_str());return (const char*)buffer;}
	/*Internal attribute to handle file compatibilty*/
	BoolID getMaya2008Above(){char buffer[4096];sprintf_s (buffer, "%s.m08",mName.c_str());return (const char*)buffer;}
protected:
	PolySmoothFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSMOOTHFACE_H__
