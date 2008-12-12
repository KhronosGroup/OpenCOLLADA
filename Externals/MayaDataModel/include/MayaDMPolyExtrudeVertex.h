/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYEXTRUDEVERTEX_H__
#define __MayaDM_POLYEXTRUDEVERTEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
<p><pre> Extrude vertices

</pre></p>
*/
class PolyExtrudeVertex : public PolyModifierWorld
{
public:
public:
	PolyExtrudeVertex(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyExtrudeVertex"){}
	virtual ~PolyExtrudeVertex(){}
	/*Length of the vertex extrusion*/
	void setLength(float l){if(l == 0.0) return; fprintf_s(mFile, "setAttr \".l\" %f;\n", l);}
	/*Length of the vertex extrusion*/
	void setLength(const FloatID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*Width of the vertex extrusion*/
	void setWidth(float w){if(w == 0.0) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*Width of the vertex extrusion*/
	void setWidth(const FloatID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*The number of vertices to be inserted along the extrusion*/
	void setDivisions(int d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*The number of vertices to be inserted along the extrusion*/
	void setDivisions(const IntID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Length of the vertex extrusion*/
	FloatID getLength(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*Width of the vertex extrusion*/
	FloatID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*The number of vertices to be inserted along the extrusion*/
	IntID getDivisions(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
protected:
	PolyExtrudeVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYEXTRUDEVERTEX_H__
