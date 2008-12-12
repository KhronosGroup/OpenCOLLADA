/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSMOOTHPROXY_H__
#define __MayaDM_POLYSMOOTHPROXY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Subdivide and smooth faces of the entire polygonal object.<p/>

 See the documentation for the parent node polyModifier for more
 details.<p/>
*/
class PolySmoothProxy : public PolyModifier
{
public:
public:
	PolySmoothProxy(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polySmoothProxy"){}
	virtual ~PolySmoothProxy(){}
	/*Cached smooth mesh (for faster updates).*/
	void setCachedSmoothMesh(const MeshID& csm){fprintf_s(mFile,"connectAttr \"");csm.write(mFile);fprintf_s(mFile,"\" \"%s.csm\";\n",mName.c_str());}
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
	/*The number of recursive quad subdivisions to perform on each face.*/
	void setExponentialLevel(short el){if(el == 1) return; fprintf_s(mFile, "setAttr \".el\" %i;\n", el);}
	/*The number of recursive quad subdivisions to perform on each face.*/
	void setExponentialLevel(const ShortID& el){fprintf_s(mFile,"connectAttr \"");el.write(mFile);fprintf_s(mFile,"\" \"%s.el\";\n",mName.c_str());}
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
	/*If true: UVs as well as geometry will be smoothed*/
	void setSmoothUVs(bool suv){if(suv == false) return; fprintf_s(mFile, "setAttr \".suv\" %i;\n", suv);}
	/*If true: UVs as well as geometry will be smoothed*/
	void setSmoothUVs(const BoolID& suv){fprintf_s(mFile,"connectAttr \"");suv.write(mFile);fprintf_s(mFile,"\" \"%s.suv\";\n",mName.c_str());}
	/*If true: border edges will not be smoothed.*/
	void setKeepBorder(bool kb){if(kb == true) return; fprintf_s(mFile, "setAttr \".kb\" %i;\n", kb);}
	/*If true: border edges will not be smoothed.*/
	void setKeepBorder(const BoolID& kb){fprintf_s(mFile,"connectAttr \"");kb.write(mFile);fprintf_s(mFile,"\" \"%s.kb\";\n",mName.c_str());}
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
	/*The number of recursive quad subdivisions to perform on each face.*/
	void setLinearLevel(short ll){if(ll == 1) return; fprintf_s(mFile, "setAttr \".ll\" %i;\n", ll);}
	/*The number of recursive quad subdivisions to perform on each face.*/
	void setLinearLevel(const ShortID& ll){fprintf_s(mFile,"connectAttr \"");ll.write(mFile);fprintf_s(mFile,"\" \"%s.ll\";\n",mName.c_str());}
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
	/*Treat adjacent edges as part of a single crease or treat each edge independently*/
	void setMultiEdgeCrease(bool mec){if(mec == true) return; fprintf_s(mFile, "setAttr \".mec\" %i;\n", mec);}
	/*Treat adjacent edges as part of a single crease or treat each edge independently*/
	void setMultiEdgeCrease(const BoolID& mec){fprintf_s(mFile,"connectAttr \"");mec.write(mFile);fprintf_s(mFile,"\" \"%s.mec\";\n",mName.c_str());}
	/*Internal attribute to handle file compatibilty*/
	void setMaya65Above(bool ma){if(ma == false) return; fprintf_s(mFile, "setAttr \".ma\" %i;\n", ma);}
	/*Internal attribute to handle file compatibilty*/
	void setMaya65Above(const BoolID& ma){fprintf_s(mFile,"connectAttr \"");ma.write(mFile);fprintf_s(mFile,"\" \"%s.ma\";\n",mName.c_str());}
	/*Internal attribute to handle file compatibilty*/
	void setMaya2008Above(bool mn){if(mn == false) return; fprintf_s(mFile, "setAttr \".mn\" %i;\n", mn);}
	/*Internal attribute to handle file compatibilty*/
	void setMaya2008Above(const BoolID& mn){fprintf_s(mFile,"connectAttr \"");mn.write(mFile);fprintf_s(mFile,"\" \"%s.mn\";\n",mName.c_str());}
	/*Cached smooth mesh (for faster updates).*/
	MeshID getCachedSmoothMesh(){char buffer[4096];sprintf_s (buffer, "%s.csm",mName.c_str());return (const char*)buffer;}
	/*
	Type of smoothing algorithm to use
	0 - exponential - traditional smoothing
	1 - linear - number of faces per edge grows linearly
	*/
	UnsignedintID getMethod(){char buffer[4096];sprintf_s (buffer, "%s.mth",mName.c_str());return (const char*)buffer;}
	/*The number of recursive quad subdivisions to perform on each face.*/
	ShortID getExponentialLevel(){char buffer[4096];sprintf_s (buffer, "%s.el",mName.c_str());return (const char*)buffer;}
	/*
	The smoothness parameter. Range is [0,1]. Default value of 1
	smooths the faces as much as possible. Value of 0 subdivides faces only.
	*/
	FloatID getContinuity(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*If true: UVs as well as geometry will be smoothed*/
	BoolID getSmoothUVs(){char buffer[4096];sprintf_s (buffer, "%s.suv",mName.c_str());return (const char*)buffer;}
	/*If true: border edges will not be smoothed.*/
	BoolID getKeepBorder(){char buffer[4096];sprintf_s (buffer, "%s.kb",mName.c_str());return (const char*)buffer;}
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
	/*The number of recursive quad subdivisions to perform on each face.*/
	ShortID getLinearLevel(){char buffer[4096];sprintf_s (buffer, "%s.ll",mName.c_str());return (const char*)buffer;}
	/*Number of subdivisions along one edge for each step.*/
	IntID getDivisionsPerEdge(){char buffer[4096];sprintf_s (buffer, "%s.dpe",mName.c_str());return (const char*)buffer;}
	/*Degree of the resulting limit surface*/
	IntID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.deg",mName.c_str());return (const char*)buffer;}
	/*0 is approximation, 1 is interpolation scheme*/
	FloatID getPushStrength(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*When 1, push vectors are renormalized to keep length constant*/
	FloatID getRoundness(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*Treat adjacent edges as part of a single crease or treat each edge independently*/
	BoolID getMultiEdgeCrease(){char buffer[4096];sprintf_s (buffer, "%s.mec",mName.c_str());return (const char*)buffer;}
	/*Internal attribute to handle file compatibilty*/
	BoolID getMaya65Above(){char buffer[4096];sprintf_s (buffer, "%s.ma",mName.c_str());return (const char*)buffer;}
	/*Internal attribute to handle file compatibilty*/
	BoolID getMaya2008Above(){char buffer[4096];sprintf_s (buffer, "%s.mn",mName.c_str());return (const char*)buffer;}
protected:
	PolySmoothProxy(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSMOOTHPROXY_H__
