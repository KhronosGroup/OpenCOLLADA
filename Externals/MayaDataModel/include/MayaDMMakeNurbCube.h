/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBCUBE_H__
#define __MayaDM_MAKENURBCUBE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPrimitive.h"
namespace MayaDM
{
/*
Compute a cube given its center (pivot), normal (axis), and
 dimensions (width, lengthRatio, and heightRatio). The number
 of spans in the resulting surface can be controlled by patchesU
 and patchesV.
 The resulting planes can have a degree of linear or cubic.
 <p/>
*/
class MakeNurbCube : public Primitive
{
public:
public:
	MakeNurbCube(FILE* file,const std::string& name,const std::string& parent=""):Primitive(file, name, parent, "makeNurbCube"){}
	virtual ~MakeNurbCube(){}
	/*Width of the object*/
	void setWidth(double w){if(w == 1) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*Width of the object*/
	void setWidth(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*Ratio of "length" to "width"*/
	void setLengthRatio(double lr){if(lr == 1.0) return; fprintf_s(mFile, "setAttr \".lr\" %f;\n", lr);}
	/*Ratio of "length" to "width"*/
	void setLengthRatio(const DoubleID& lr){fprintf_s(mFile,"connectAttr \"");lr.write(mFile);fprintf_s(mFile,"\" \"%s.lr\";\n",mName.c_str());}
	/*Ratio of "height" to "width"*/
	void setHeightRatio(double hr){if(hr == 1.0) return; fprintf_s(mFile, "setAttr \".hr\" %f;\n", hr);}
	/*Ratio of "height" to "width"*/
	void setHeightRatio(const DoubleID& hr){fprintf_s(mFile,"connectAttr \"");hr.write(mFile);fprintf_s(mFile,"\" \"%s.hr\";\n",mName.c_str());}
	/*Number of sections in U*/
	void setPatchesU(int u){if(u == 1) return; fprintf_s(mFile, "setAttr \".u\" %i;\n", u);}
	/*Number of sections in U*/
	void setPatchesU(const IntID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*Number of sections in V*/
	void setPatchesV(int v){if(v == 1) return; fprintf_s(mFile, "setAttr \".v\" %i;\n", v);}
	/*Number of sections in V*/
	void setPatchesV(const IntID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*
	The degree of the resulting surface.
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegree(unsigned int d){if(d == 3) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	The degree of the resulting surface.
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegree(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Output surface 1 - the bottom of the cube*/
	void setOutputSurface1(const NurbsSurfaceID& os1){fprintf_s(mFile,"connectAttr \"");os1.write(mFile);fprintf_s(mFile,"\" \"%s.os1\";\n",mName.c_str());}
	/*Output surface 2 - the left side of the cube*/
	void setOutputSurface2(const NurbsSurfaceID& os2){fprintf_s(mFile,"connectAttr \"");os2.write(mFile);fprintf_s(mFile,"\" \"%s.os2\";\n",mName.c_str());}
	/*Output surface 3 - the right of the cube*/
	void setOutputSurface3(const NurbsSurfaceID& os3){fprintf_s(mFile,"connectAttr \"");os3.write(mFile);fprintf_s(mFile,"\" \"%s.os3\";\n",mName.c_str());}
	/*Output surface 4 - the front side of the cube*/
	void setOutputSurface4(const NurbsSurfaceID& os4){fprintf_s(mFile,"connectAttr \"");os4.write(mFile);fprintf_s(mFile,"\" \"%s.os4\";\n",mName.c_str());}
	/*Output surface 5 - the back of the cube*/
	void setOutputSurface5(const NurbsSurfaceID& os5){fprintf_s(mFile,"connectAttr \"");os5.write(mFile);fprintf_s(mFile,"\" \"%s.os5\";\n",mName.c_str());}
	/*Width of the object*/
	DoubleID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*Ratio of "length" to "width"*/
	DoubleID getLengthRatio(){char buffer[4096];sprintf_s (buffer, "%s.lr",mName.c_str());return (const char*)buffer;}
	/*Ratio of "height" to "width"*/
	DoubleID getHeightRatio(){char buffer[4096];sprintf_s (buffer, "%s.hr",mName.c_str());return (const char*)buffer;}
	/*Number of sections in U*/
	IntID getPatchesU(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*Number of sections in V*/
	IntID getPatchesV(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*
	The degree of the resulting surface.
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Output surface 1 - the bottom of the cube*/
	NurbsSurfaceID getOutputSurface1(){char buffer[4096];sprintf_s (buffer, "%s.os1",mName.c_str());return (const char*)buffer;}
	/*Output surface 2 - the left side of the cube*/
	NurbsSurfaceID getOutputSurface2(){char buffer[4096];sprintf_s (buffer, "%s.os2",mName.c_str());return (const char*)buffer;}
	/*Output surface 3 - the right of the cube*/
	NurbsSurfaceID getOutputSurface3(){char buffer[4096];sprintf_s (buffer, "%s.os3",mName.c_str());return (const char*)buffer;}
	/*Output surface 4 - the front side of the cube*/
	NurbsSurfaceID getOutputSurface4(){char buffer[4096];sprintf_s (buffer, "%s.os4",mName.c_str());return (const char*)buffer;}
	/*Output surface 5 - the back of the cube*/
	NurbsSurfaceID getOutputSurface5(){char buffer[4096];sprintf_s (buffer, "%s.os5",mName.c_str());return (const char*)buffer;}
protected:
	MakeNurbCube(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Primitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBCUBE_H__
