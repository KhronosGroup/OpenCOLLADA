/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBPLANE_H__
#define __MayaDM_MAKENURBPLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPrimitive.h"
namespace MayaDM
{
/*
<p><pre>
 Compute a plane given a center (pivot), normal (axis), and
 dimensions (width & lengthRatio). The number of spans in the
 resulting surface can be controlled by patchesU and patchesV.
 The resulting plane can have a degree of linear or cubic.

</pre></p>
*/
class MakeNurbPlane : public Primitive
{
public:
public:
	MakeNurbPlane(FILE* file,const std::string& name,const std::string& parent=""):Primitive(file, name, parent, "makeNurbPlane"){}
	virtual ~MakeNurbPlane(){}
	/*The width of the plane*/
	void setWidth(double w){if(w == 1) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*The width of the plane*/
	void setWidth(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*The ratio of "length" to "width" of the plane.*/
	void setLengthRatio(double lr){if(lr == 1.0) return; fprintf_s(mFile, "setAttr \".lr\" %f;\n", lr);}
	/*The ratio of "length" to "width" of the plane.*/
	void setLengthRatio(const DoubleID& lr){fprintf_s(mFile,"connectAttr \"");lr.write(mFile);fprintf_s(mFile,"\" \"%s.lr\";\n",mName.c_str());}
	/*The number of spans in the U direction.*/
	void setPatchesU(int u){if(u == 1) return; fprintf_s(mFile, "setAttr \".u\" %i;\n", u);}
	/*The number of spans in the U direction.*/
	void setPatchesU(const IntID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*The number of spans in the V direction.*/
	void setPatchesV(int v){if(v == 1) return; fprintf_s(mFile, "setAttr \".v\" %i;\n", v);}
	/*The number of spans in the V direction.*/
	void setPatchesV(const IntID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*
	The degree of the resulting surface
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegree(unsigned int d){if(d == 3) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	The degree of the resulting surface
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegree(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The width of the plane*/
	DoubleID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*The ratio of "length" to "width" of the plane.*/
	DoubleID getLengthRatio(){char buffer[4096];sprintf_s (buffer, "%s.lr",mName.c_str());return (const char*)buffer;}
	/*The number of spans in the U direction.*/
	IntID getPatchesU(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*The number of spans in the V direction.*/
	IntID getPatchesV(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*
	The degree of the resulting surface
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
protected:
	MakeNurbPlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Primitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBPLANE_H__
