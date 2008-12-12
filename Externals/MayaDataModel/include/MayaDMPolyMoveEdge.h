/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMOVEEDGE_H__
#define __MayaDM_POLYMOVEEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyMoveVertex.h"
namespace MayaDM
{
/*
Translate, rotate or scale edges of a polygonal object.<p/>

 This node is derived from polyMoveVertex and reuses many
 of the attributes from that node. It is also a base for
 some nodes that perform geometric transformations (polyMoveFace,
 polyChipOff, polyExtrudeFace).<p/>
*/
class PolyMoveEdge : public PolyMoveVertex
{
public:
public:
	PolyMoveEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyMoveVertex(file, name, parent, "polyMoveEdge"){}
	virtual ~PolyMoveEdge(){}
	/*The local rotations.*/
	void setLocalRotate(const double3& lr){if(lr == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".lr\" -type \"double3\" ");lr.write(mFile);fprintf_s(mFile,";\n");}
	/*The local rotations.*/
	void setLocalRotate(const Double3ID& lr){fprintf_s(mFile,"connectAttr \"");lr.write(mFile);fprintf_s(mFile,"\" \"%s.lr\";\n",mName.c_str());}
	/*
	Local rotate X coord.
	The range is [0, 360].
	*/
	void setLocalRotateX(double lrx){if(lrx == 0) return; fprintf_s(mFile, "setAttr \".lr.lrx\" %f;\n", lrx);}
	/*
	Local rotate X coord.
	The range is [0, 360].
	*/
	void setLocalRotateX(const DoubleID& lrx){fprintf_s(mFile,"connectAttr \"");lrx.write(mFile);fprintf_s(mFile,"\" \"%s.lr.lrx\";\n",mName.c_str());}
	/*
	Local rotate Y coord.
	The range is [0, 360].
	*/
	void setLocalRotateY(double lry){if(lry == 0) return; fprintf_s(mFile, "setAttr \".lr.lry\" %f;\n", lry);}
	/*
	Local rotate Y coord.
	The range is [0, 360].
	*/
	void setLocalRotateY(const DoubleID& lry){fprintf_s(mFile,"connectAttr \"");lry.write(mFile);fprintf_s(mFile,"\" \"%s.lr.lry\";\n",mName.c_str());}
	/*
	Local rotate Z coord : Rotation along the normal.
	The range is [0, 360].
	*/
	void setLocalRotateZ(double lrz){if(lrz == 0) return; fprintf_s(mFile, "setAttr \".lr.lrz\" %f;\n", lrz);}
	/*
	Local rotate Z coord : Rotation along the normal.
	The range is [0, 360].
	*/
	void setLocalRotateZ(const DoubleID& lrz){fprintf_s(mFile,"connectAttr \"");lrz.write(mFile);fprintf_s(mFile,"\" \"%s.lr.lrz\";\n",mName.c_str());}
	/*Local Scale.*/
	void setLocalScale(const double3& ls){if(ls == double3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".ls\" -type \"double3\" ");ls.write(mFile);fprintf_s(mFile,";\n");}
	/*Local Scale.*/
	void setLocalScale(const Double3ID& ls){fprintf_s(mFile,"connectAttr \"");ls.write(mFile);fprintf_s(mFile,"\" \"%s.ls\";\n",mName.c_str());}
	/*Scale X coord.*/
	void setLocalScaleX(double lsx){if(lsx == 0.0) return; fprintf_s(mFile, "setAttr \".ls.lsx\" %f;\n", lsx);}
	/*Scale X coord.*/
	void setLocalScaleX(const DoubleID& lsx){fprintf_s(mFile,"connectAttr \"");lsx.write(mFile);fprintf_s(mFile,"\" \"%s.ls.lsx\";\n",mName.c_str());}
	/*Scale Y coord.*/
	void setLocalScaleY(double lsy){if(lsy == 0.0) return; fprintf_s(mFile, "setAttr \".ls.lsy\" %f;\n", lsy);}
	/*Scale Y coord.*/
	void setLocalScaleY(const DoubleID& lsy){fprintf_s(mFile,"connectAttr \"");lsy.write(mFile);fprintf_s(mFile,"\" \"%s.ls.lsy\";\n",mName.c_str());}
	/*Scale Z coord.*/
	void setLocalScaleZ(double lsz){if(lsz == 0.0) return; fprintf_s(mFile, "setAttr \".ls.lsz\" %f;\n", lsz);}
	/*Scale Z coord.*/
	void setLocalScaleZ(const DoubleID& lsz){fprintf_s(mFile,"connectAttr \"");lsz.write(mFile);fprintf_s(mFile,"\" \"%s.ls.lsz\";\n",mName.c_str());}
	/*Local center on the edge : 0=Middle point, 1=Start point, 2=End point.*/
	void setLocalCenter(unsigned int lc){if(lc == 0) return; fprintf_s(mFile, "setAttr \".lc\" %i;\n", lc);}
	/*Local center on the edge : 0=Middle point, 1=Start point, 2=End point.*/
	void setLocalCenter(const UnsignedintID& lc){fprintf_s(mFile,"connectAttr \"");lc.write(mFile);fprintf_s(mFile,"\" \"%s.lc\";\n",mName.c_str());}
	/*The local rotations.*/
	Double3ID getLocalRotate(){char buffer[4096];sprintf_s (buffer, "%s.lr",mName.c_str());return (const char*)buffer;}
	/*
	Local rotate X coord.
	The range is [0, 360].
	*/
	DoubleID getLocalRotateX(){char buffer[4096];sprintf_s (buffer, "%s.lr.lrx",mName.c_str());return (const char*)buffer;}
	/*
	Local rotate Y coord.
	The range is [0, 360].
	*/
	DoubleID getLocalRotateY(){char buffer[4096];sprintf_s (buffer, "%s.lr.lry",mName.c_str());return (const char*)buffer;}
	/*
	Local rotate Z coord : Rotation along the normal.
	The range is [0, 360].
	*/
	DoubleID getLocalRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.lr.lrz",mName.c_str());return (const char*)buffer;}
	/*Local Scale.*/
	Double3ID getLocalScale(){char buffer[4096];sprintf_s (buffer, "%s.ls",mName.c_str());return (const char*)buffer;}
	/*Scale X coord.*/
	DoubleID getLocalScaleX(){char buffer[4096];sprintf_s (buffer, "%s.ls.lsx",mName.c_str());return (const char*)buffer;}
	/*Scale Y coord.*/
	DoubleID getLocalScaleY(){char buffer[4096];sprintf_s (buffer, "%s.ls.lsy",mName.c_str());return (const char*)buffer;}
	/*Scale Z coord.*/
	DoubleID getLocalScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.ls.lsz",mName.c_str());return (const char*)buffer;}
	/*Local center on the edge : 0=Middle point, 1=Start point, 2=End point.*/
	UnsignedintID getLocalCenter(){char buffer[4096];sprintf_s (buffer, "%s.lc",mName.c_str());return (const char*)buffer;}
protected:
	PolyMoveEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyMoveVertex(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMOVEEDGE_H__
