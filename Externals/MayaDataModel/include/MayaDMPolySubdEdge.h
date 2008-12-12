/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSUBDEDGE_H__
#define __MayaDM_POLYSUBDEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*Subdivides an edge into one or more subedges.<p/>*/
class PolySubdEdge : public PolyModifierWorld
{
public:
public:
	PolySubdEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polySubdEdge"){}
	virtual ~PolySubdEdge(){}
	/*
	The number of vertices to be inserted in each edge
	(resulting in (divisions+1) subedges). If the subdivide would create
	edges that are smaller than the size attribute, fewer vertices
	will be inserted to ensure new edge lengths are at least as Tint32
	as the size attribute.
	*/
	void setDivisions(int dv){if(dv == 1) return; fprintf_s(mFile, "setAttr \".dv\" %i;\n", dv);}
	/*
	The number of vertices to be inserted in each edge
	(resulting in (divisions+1) subedges). If the subdivide would create
	edges that are smaller than the size attribute, fewer vertices
	will be inserted to ensure new edge lengths are at least as Tint32
	as the size attribute.
	*/
	void setDivisions(const IntID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*
	The minimum length of each subedge created. This value may
	force fewer subdivisions than specified by the divisions attribute.
	*/
	void setSize(double s){if(s == 0) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*
	The minimum length of each subedge created. This value may
	force fewer subdivisions than specified by the divisions attribute.
	*/
	void setSize(const DoubleID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	The number of vertices to be inserted in each edge
	(resulting in (divisions+1) subedges). If the subdivide would create
	edges that are smaller than the size attribute, fewer vertices
	will be inserted to ensure new edge lengths are at least as Tint32
	as the size attribute.
	*/
	IntID getDivisions(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*
	The minimum length of each subedge created. This value may
	force fewer subdivisions than specified by the divisions attribute.
	*/
	DoubleID getSize(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
protected:
	PolySubdEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSUBDEDGE_H__
