/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYQUAD_H__
#define __MayaDM_POLYQUAD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*Merges triangles of a polygonal object into four-sided faces.<p/>*/
class PolyQuad : public PolyModifierWorld
{
public:
public:
	PolyQuad(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyQuad"){}
	virtual ~PolyQuad(){}
	/*
	Angle threshold used to determine if
	triangles are merged or not. Range is [0,180].
	A value of 0 means only co-planar triangles will be merged.
	*/
	void setAngle(double a){if(a == 3) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*
	Angle threshold used to determine if
	triangles are merged or not. Range is [0,180].
	A value of 0 means only co-planar triangles will be merged.
	*/
	void setAngle(const DoubleID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	Keep facet group border.
	If "on", the borders of input faces are maintained,
	otherwise the borders of input faces may be modified.
	*/
	void setKeepGroupBorder(bool kgb){if(kgb == true) return; fprintf_s(mFile, "setAttr \".kgb\" %i;\n", kgb);}
	/*
	Keep facet group border.
	If "on", the borders of input faces are maintained,
	otherwise the borders of input faces may be modified.
	*/
	void setKeepGroupBorder(const BoolID& kgb){fprintf_s(mFile,"connectAttr \"");kgb.write(mFile);fprintf_s(mFile,"\" \"%s.kgb\";\n",mName.c_str());}
	/*
	Keep texture border.
	If "on", the borders of texture maps are maintained,
	otherwise the borders of texture maps may be modified.
	*/
	void setKeepTextureBorders(bool ktb){if(ktb == true) return; fprintf_s(mFile, "setAttr \".ktb\" %i;\n", ktb);}
	/*
	Keep texture border.
	If "on", the borders of texture maps are maintained,
	otherwise the borders of texture maps may be modified.
	*/
	void setKeepTextureBorders(const BoolID& ktb){fprintf_s(mFile,"connectAttr \"");ktb.write(mFile);fprintf_s(mFile,"\" \"%s.ktb\";\n",mName.c_str());}
	/*
	Keep hard edges.
	If "on", the hard edges of input faces are maintained,
	otherwise they may be deleted between two triangles.
	*/
	void setKeepHardEdges(bool khe){if(khe == true) return; fprintf_s(mFile, "setAttr \".khe\" %i;\n", khe);}
	/*
	Keep hard edges.
	If "on", the hard edges of input faces are maintained,
	otherwise they may be deleted between two triangles.
	*/
	void setKeepHardEdges(const BoolID& khe){fprintf_s(mFile,"connectAttr \"");khe.write(mFile);fprintf_s(mFile,"\" \"%s.khe\";\n",mName.c_str());}
	/*
	Enable Maya 8.0 behaviour.
	This attribute is not meant to be modified through command line.
	*/
	void setMaya80(bool m80){if(m80 == true) return; fprintf_s(mFile, "setAttr \".m80\" %i;\n", m80);}
	/*
	Angle threshold used to determine if
	triangles are merged or not. Range is [0,180].
	A value of 0 means only co-planar triangles will be merged.
	*/
	DoubleID getAngle(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	Keep facet group border.
	If "on", the borders of input faces are maintained,
	otherwise the borders of input faces may be modified.
	*/
	BoolID getKeepGroupBorder(){char buffer[4096];sprintf_s (buffer, "%s.kgb",mName.c_str());return (const char*)buffer;}
	/*
	Keep texture border.
	If "on", the borders of texture maps are maintained,
	otherwise the borders of texture maps may be modified.
	*/
	BoolID getKeepTextureBorders(){char buffer[4096];sprintf_s (buffer, "%s.ktb",mName.c_str());return (const char*)buffer;}
	/*
	Keep hard edges.
	If "on", the hard edges of input faces are maintained,
	otherwise they may be deleted between two triangles.
	*/
	BoolID getKeepHardEdges(){char buffer[4096];sprintf_s (buffer, "%s.khe",mName.c_str());return (const char*)buffer;}
protected:
	PolyQuad(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYQUAD_H__
