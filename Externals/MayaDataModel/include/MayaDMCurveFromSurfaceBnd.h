/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSURFACEBND_H__
#define __MayaDM_CURVEFROMSURFACEBND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSurface.h"
namespace MayaDM
{
/*
This node defines a NURBS curve that is derived from
 a trimmed NURBS surface.  (Only trimmed NURBS surfaces
 have boundaries.)   A trimmed NURBS surface can have
 several faces, boundaries and edges.  A face is a disjoint region
 that may contain holes.  A face has one or more boundaries.
 A boundary is a continous curve in a face.  A boundary has one
 or more edges.  An edge is a curvature continous curve segment.
 <p/>
 <p/>  For example, if a trimmed surface is a solid letter "A", then:
 <p/>
 - There is only one face, which is the entire letter.
 <p/>
 - There are two boundaries, one which is the outside of the "A"
 and one which is the triangular hole.
 <p/>
 - The outside boundary has several edges, depending on how many corners
 the letter has.  The triangular boundary probably has three edges.
 <p/>
 This node extracts a face, boundary and/or edge from a trimmed
 NURBS surface based on the face, boundary and/or edge index attributes.
 This index is zero-based.  In the case of edges, if the index
 is -1, then it is assumed that all edges are to be extracted.
*/
class CurveFromSurfaceBnd : public CurveFromSurface
{
public:
public:
	CurveFromSurfaceBnd(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSurface(file, name, parent, "curveFromSurfaceBnd"){}
	virtual ~CurveFromSurfaceBnd(){}
	/*Face index if the trim surface has multiple regions*/
	void setFace(int f){if(f == 0) return; fprintf_s(mFile, "setAttr \".f\" %i;\n", f);}
	/*Face index if the trim surface has multiple regions*/
	void setFace(const IntID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Boundary index within a face*/
	void setBoundary(int b){if(b == 0) return; fprintf_s(mFile, "setAttr \".b\" %i;\n", b);}
	/*Boundary index within a face*/
	void setBoundary(const IntID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*Edge index within a boundary; if negative, the whole boundary will be converted*/
	void setEdge(int e){if(e == -1) return; fprintf_s(mFile, "setAttr \".e\" %i;\n", e);}
	/*Edge index within a boundary; if negative, the whole boundary will be converted*/
	void setEdge(const IntID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e\";\n",mName.c_str());}
	/*Face index if the trim surface has multiple regions*/
	IntID getFace(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*Boundary index within a face*/
	IntID getBoundary(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*Edge index within a boundary; if negative, the whole boundary will be converted*/
	IntID getEdge(){char buffer[4096];sprintf_s (buffer, "%s.e",mName.c_str());return (const char*)buffer;}
protected:
	CurveFromSurfaceBnd(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromSurface(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSURFACEBND_H__
