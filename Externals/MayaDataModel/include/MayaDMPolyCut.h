/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCUT_H__
#define __MayaDM_POLYCUT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*Cuts(slices) the face(s) a polygonal object.<p/>*/
class PolyCut : public PolyModifierWorld
{
public:
public:
	PolyCut(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyCut"){}
	virtual ~PolyCut(){}
	/*The position of the cutting plane.*/
	void setCutPlaneCenter(const double3& pc){if(pc == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".pc\" -type \"double3\" ");pc.write(mFile);fprintf_s(mFile,";\n");}
	/*The position of the cutting plane.*/
	void setCutPlaneCenter(const Double3ID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*Cutting plane center X coord.*/
	void setCutPlaneCenterX(double pcx){if(pcx == 0) return; fprintf_s(mFile, "setAttr \".pc.pcx\" %f;\n", pcx);}
	/*Cutting plane center X coord.*/
	void setCutPlaneCenterX(const DoubleID& pcx){fprintf_s(mFile,"connectAttr \"");pcx.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcx\";\n",mName.c_str());}
	/*Cutting plane center Y coord.*/
	void setCutPlaneCenterY(double pcy){if(pcy == 0) return; fprintf_s(mFile, "setAttr \".pc.pcy\" %f;\n", pcy);}
	/*Cutting plane center Y coord.*/
	void setCutPlaneCenterY(const DoubleID& pcy){fprintf_s(mFile,"connectAttr \"");pcy.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcy\";\n",mName.c_str());}
	/*Cutting plane center Z coord.*/
	void setCutPlaneCenterZ(double pcz){if(pcz == 0) return; fprintf_s(mFile, "setAttr \".pc.pcz\" %f;\n", pcz);}
	/*Cutting plane center Z coord.*/
	void setCutPlaneCenterZ(const DoubleID& pcz){fprintf_s(mFile,"connectAttr \"");pcz.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcz\";\n",mName.c_str());}
	/*The orientation of the cutting plane.*/
	void setCutPlaneRotate(const double3& ro){if(ro == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ro\" -type \"double3\" ");ro.write(mFile);fprintf_s(mFile,";\n");}
	/*The orientation of the cutting plane.*/
	void setCutPlaneRotate(const Double3ID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*cutting plane X rotate angle.*/
	void setCutPlaneRotateX(double rx){if(rx == 0) return; fprintf_s(mFile, "setAttr \".ro.rx\" %f;\n", rx);}
	/*cutting plane X rotate angle.*/
	void setCutPlaneRotateX(const DoubleID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.ro.rx\";\n",mName.c_str());}
	/*cutting plane Y rotate angle.*/
	void setCutPlaneRotateY(double ry){if(ry == 0) return; fprintf_s(mFile, "setAttr \".ro.ry\" %f;\n", ry);}
	/*cutting plane Y rotate angle.*/
	void setCutPlaneRotateY(const DoubleID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.ro.ry\";\n",mName.c_str());}
	/*cutting plane Z rotate angle.*/
	void setCutPlaneRotateZ(double rz){if(rz == 0) return; fprintf_s(mFile, "setAttr \".ro.rz\" %f;\n", rz);}
	/*cutting plane Z rotate angle.*/
	void setCutPlaneRotateZ(const DoubleID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.ro.rz\";\n",mName.c_str());}
	/*The width and the height of the cutting plane*/
	void setCutPlaneSize(const double2& ps){if(ps == double2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".ps\" -type \"double2\" ");ps.write(mFile);fprintf_s(mFile,";\n");}
	/*The width and the height of the cutting plane*/
	void setCutPlaneSize(const Double2ID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*The width of the cutting plane*/
	void setCutPlaneWidth(double pw){if(pw == 0) return; fprintf_s(mFile, "setAttr \".ps.pw\" %f;\n", pw);}
	/*The width of the cutting plane*/
	void setCutPlaneWidth(const DoubleID& pw){fprintf_s(mFile,"connectAttr \"");pw.write(mFile);fprintf_s(mFile,"\" \"%s.ps.pw\";\n",mName.c_str());}
	/*The height of the cutting plane*/
	void setCutPlaneHeight(double ph){if(ph == 0) return; fprintf_s(mFile, "setAttr \".ps.ph\" %f;\n", ph);}
	/*The height of the cutting plane*/
	void setCutPlaneHeight(const DoubleID& ph){fprintf_s(mFile,"connectAttr \"");ph.write(mFile);fprintf_s(mFile,"\" \"%s.ps.ph\";\n",mName.c_str());}
	/*
	whether to extract the cut-faces of the poly
	into a separate shell.  If true, they are extracted.
	*/
	void setExtractFaces(bool ef){if(ef == false) return; fprintf_s(mFile, "setAttr \".ef\" %i;\n", ef);}
	/*
	whether to extract the cut-faces of the poly
	into a separate shell.  If true, they are extracted.
	*/
	void setExtractFaces(const BoolID& ef){fprintf_s(mFile,"connectAttr \"");ef.write(mFile);fprintf_s(mFile,"\" \"%s.ef\";\n",mName.c_str());}
	/*The displacement offset of the cut faces.*/
	void setExtractOffset(const double3& eo){if(eo == double3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".eo\" -type \"double3\" ");eo.write(mFile);fprintf_s(mFile,";\n");}
	/*The displacement offset of the cut faces.*/
	void setExtractOffset(const Double3ID& eo){fprintf_s(mFile,"connectAttr \"");eo.write(mFile);fprintf_s(mFile,"\" \"%s.eo\";\n",mName.c_str());}
	/*The X-displacement offset of the cut faces.*/
	void setExtractOffsetX(double eox){if(eox == 0) return; fprintf_s(mFile, "setAttr \".eo.eox\" %f;\n", eox);}
	/*The X-displacement offset of the cut faces.*/
	void setExtractOffsetX(const DoubleID& eox){fprintf_s(mFile,"connectAttr \"");eox.write(mFile);fprintf_s(mFile,"\" \"%s.eo.eox\";\n",mName.c_str());}
	/*The Y-displacement offset of the cut faces.*/
	void setExtractOffsetY(double eoy){if(eoy == 0) return; fprintf_s(mFile, "setAttr \".eo.eoy\" %f;\n", eoy);}
	/*The Y-displacement offset of the cut faces.*/
	void setExtractOffsetY(const DoubleID& eoy){fprintf_s(mFile,"connectAttr \"");eoy.write(mFile);fprintf_s(mFile,"\" \"%s.eo.eoy\";\n",mName.c_str());}
	/*The Z-displacement offset of the cut faces.*/
	void setExtractOffsetZ(double eoz){if(eoz == 0) return; fprintf_s(mFile, "setAttr \".eo.eoz\" %f;\n", eoz);}
	/*The Z-displacement offset of the cut faces.*/
	void setExtractOffsetZ(const DoubleID& eoz){fprintf_s(mFile,"connectAttr \"");eoz.write(mFile);fprintf_s(mFile,"\" \"%s.eo.eoz\";\n",mName.c_str());}
	/*
	whether to delete the one-half of the cut-faces
	of the poly.  If true, they are deleted.
	*/
	void setDeleteFaces(bool df){if(df == false) return; fprintf_s(mFile, "setAttr \".df\" %i;\n", df);}
	/*
	whether to delete the one-half of the cut-faces
	of the poly.  If true, they are deleted.
	*/
	void setDeleteFaces(const BoolID& df){fprintf_s(mFile,"connectAttr \"");df.write(mFile);fprintf_s(mFile,"\" \"%s.df\";\n",mName.c_str());}
	/*
	whether to act on the entire polyObject
	or its selected face components
	*/
	void setOnObject(bool oo){if(oo == true) return; fprintf_s(mFile, "setAttr \".oo\" %i;\n", oo);}
	/*
	whether to act on the entire polyObject
	or its selected face components
	*/
	void setOnObject(const BoolID& oo){fprintf_s(mFile,"connectAttr \"");oo.write(mFile);fprintf_s(mFile,"\" \"%s.oo\";\n",mName.c_str());}
	/*Which element to place the manip on (for interaction purposes only).*/
	void setCompId(const IntID& cid){fprintf_s(mFile,"connectAttr \"");cid.write(mFile);fprintf_s(mFile,"\" \"%s.cid\";\n",mName.c_str());}
	/*The position of the cutting plane.*/
	Double3ID getCutPlaneCenter(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*Cutting plane center X coord.*/
	DoubleID getCutPlaneCenterX(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcx",mName.c_str());return (const char*)buffer;}
	/*Cutting plane center Y coord.*/
	DoubleID getCutPlaneCenterY(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcy",mName.c_str());return (const char*)buffer;}
	/*Cutting plane center Z coord.*/
	DoubleID getCutPlaneCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcz",mName.c_str());return (const char*)buffer;}
	/*The orientation of the cutting plane.*/
	Double3ID getCutPlaneRotate(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*cutting plane X rotate angle.*/
	DoubleID getCutPlaneRotateX(){char buffer[4096];sprintf_s (buffer, "%s.ro.rx",mName.c_str());return (const char*)buffer;}
	/*cutting plane Y rotate angle.*/
	DoubleID getCutPlaneRotateY(){char buffer[4096];sprintf_s (buffer, "%s.ro.ry",mName.c_str());return (const char*)buffer;}
	/*cutting plane Z rotate angle.*/
	DoubleID getCutPlaneRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.ro.rz",mName.c_str());return (const char*)buffer;}
	/*The width and the height of the cutting plane*/
	Double2ID getCutPlaneSize(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*The width of the cutting plane*/
	DoubleID getCutPlaneWidth(){char buffer[4096];sprintf_s (buffer, "%s.ps.pw",mName.c_str());return (const char*)buffer;}
	/*The height of the cutting plane*/
	DoubleID getCutPlaneHeight(){char buffer[4096];sprintf_s (buffer, "%s.ps.ph",mName.c_str());return (const char*)buffer;}
	/*
	whether to extract the cut-faces of the poly
	into a separate shell.  If true, they are extracted.
	*/
	BoolID getExtractFaces(){char buffer[4096];sprintf_s (buffer, "%s.ef",mName.c_str());return (const char*)buffer;}
	/*The displacement offset of the cut faces.*/
	Double3ID getExtractOffset(){char buffer[4096];sprintf_s (buffer, "%s.eo",mName.c_str());return (const char*)buffer;}
	/*The X-displacement offset of the cut faces.*/
	DoubleID getExtractOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.eo.eox",mName.c_str());return (const char*)buffer;}
	/*The Y-displacement offset of the cut faces.*/
	DoubleID getExtractOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.eo.eoy",mName.c_str());return (const char*)buffer;}
	/*The Z-displacement offset of the cut faces.*/
	DoubleID getExtractOffsetZ(){char buffer[4096];sprintf_s (buffer, "%s.eo.eoz",mName.c_str());return (const char*)buffer;}
	/*
	whether to delete the one-half of the cut-faces
	of the poly.  If true, they are deleted.
	*/
	BoolID getDeleteFaces(){char buffer[4096];sprintf_s (buffer, "%s.df",mName.c_str());return (const char*)buffer;}
	/*
	whether to act on the entire polyObject
	or its selected face components
	*/
	BoolID getOnObject(){char buffer[4096];sprintf_s (buffer, "%s.oo",mName.c_str());return (const char*)buffer;}
	/*Which element to place the manip on (for interaction purposes only).*/
	IntID getCompId(){char buffer[4096];sprintf_s (buffer, "%s.cid",mName.c_str());return (const char*)buffer;}
protected:
	PolyCut(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCUT_H__
