/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMIRROR_H__
#define __MayaDM_POLYMIRROR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
Mirrors the object in the specified direction
 with/out merging with the original<p/>
*/
class PolyMirror : public PolyModifierWorld
{
public:
public:
	PolyMirror(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyMirror"){}
	virtual ~PolyMirror(){}
	/*Pivot point of the mirror plane.*/
	void setPivot(const double3& p){if(p == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".p\" -type \"double3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*Pivot point of the mirror plane.*/
	void setPivot(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*Translation X coord.*/
	void setPivotX(double px){if(px == 0) return; fprintf_s(mFile, "setAttr \".p.px\" %f;\n", px);}
	/*Translation X coord.*/
	void setPivotX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*Translation Y coord.*/
	void setPivotY(double py){if(py == 0) return; fprintf_s(mFile, "setAttr \".p.py\" %f;\n", py);}
	/*Translation Y coord.*/
	void setPivotY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*Translation Z coord.*/
	void setPivotZ(double pz){if(pz == 0) return; fprintf_s(mFile, "setAttr \".p.pz\" %f;\n", pz);}
	/*Translation Z coord.*/
	void setPivotZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*Direction to mirror the object along*/
	void setDirection(unsigned int d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*Direction to mirror the object along*/
	void setDirection(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Merge mode to apply*/
	void setMergeMode(unsigned int mm){if(mm == 0) return; fprintf_s(mFile, "setAttr \".mm\" %i;\n", mm);}
	/*Merge mode to apply*/
	void setMergeMode(const UnsignedintID& mm){fprintf_s(mFile,"connectAttr \"");mm.write(mFile);fprintf_s(mFile,"\" \"%s.mm\";\n",mName.c_str());}
	/*
	Tolerance to determine whether vertices should
	be merged.
	*/
	void setMergeThreshold(double mt){if(mt == 0) return; fprintf_s(mFile, "setAttr \".mt\" %f;\n", mt);}
	/*
	Tolerance to determine whether vertices should
	be merged.
	*/
	void setMergeThreshold(const DoubleID& mt){fprintf_s(mFile,"connectAttr \"");mt.write(mFile);fprintf_s(mFile,"\" \"%s.mt\";\n",mName.c_str());}
	/*Pivot point of the mirror plane.*/
	Double3ID getPivot(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*Translation X coord.*/
	DoubleID getPivotX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*Translation Y coord.*/
	DoubleID getPivotY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*Translation Z coord.*/
	DoubleID getPivotZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*Direction to mirror the object along*/
	UnsignedintID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Merge mode to apply*/
	UnsignedintID getMergeMode(){char buffer[4096];sprintf_s (buffer, "%s.mm",mName.c_str());return (const char*)buffer;}
	/*
	Tolerance to determine whether vertices should
	be merged.
	*/
	DoubleID getMergeThreshold(){char buffer[4096];sprintf_s (buffer, "%s.mt",mName.c_str());return (const char*)buffer;}
protected:
	PolyMirror(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMIRROR_H__
