/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYBEVEL_H__
#define __MayaDM_POLYBEVEL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
<p><pre> Computes the edges bevelling for polygonal objects, using the bevel offset (offset),
 the number of segments (segments),
 the smooth roundness (autoFit) : new facets round off a smooth angle,
 when it (autoFit) is unset then the roundness (roundness) is used : a roundness
 of 0 means that all new facets are coplanar.
</pre></p>
*/
class PolyBevel : public PolyModifierWorld
{
public:
public:
	PolyBevel(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyBevel"){}
	virtual ~PolyBevel(){}
	/*If on, the offset value is treated as a fraction between zero and one.*/
	void setOffsetAsFraction(bool oaf){if(oaf == false) return; fprintf_s(mFile, "setAttr \".oaf\" %i;\n", oaf);}
	/*If on, the offset value is treated as a fraction between zero and one.*/
	void setOffsetAsFraction(const BoolID& oaf){fprintf_s(mFile,"connectAttr \"");oaf.write(mFile);fprintf_s(mFile,"\" \"%s.oaf\";\n",mName.c_str());}
	/*The offset for bevel.*/
	void setOffset(double o){if(o == 0) return; fprintf_s(mFile, "setAttr \".o\" %f;\n", o);}
	/*The offset for bevel.*/
	void setOffset(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The roundness of bevel, it is taken into account when autoFit is off.*/
	void setRoundness(double r){if(r == 0.5) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*The roundness of bevel, it is taken into account when autoFit is off.*/
	void setRoundness(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The number of segments used for bevelling.*/
	void setSegments(int sg){if(sg == 1) return; fprintf_s(mFile, "setAttr \".sg\" %i;\n", sg);}
	/*The number of segments used for bevelling.*/
	void setSegments(const IntID& sg){fprintf_s(mFile,"connectAttr \"");sg.write(mFile);fprintf_s(mFile,"\" \"%s.sg\";\n",mName.c_str());}
	/*If autoFit is on, it computes a smooth roundness :  new facets round off a smooth angle.*/
	void setAutoFit(bool af){if(af == true) return; fprintf_s(mFile, "setAttr \".af\" %i;\n", af);}
	/*If autoFit is on, it computes a smooth roundness :  new facets round off a smooth angle.*/
	void setAutoFit(const BoolID& af){fprintf_s(mFile,"connectAttr \"");af.write(mFile);fprintf_s(mFile,"\" \"%s.af\";\n",mName.c_str());}
	/*
	Angular tolerance for creation of extra triangles
	Note this attribute is for compatability only and should not be modified in Maya 7.0 files
	*/
	void setAngleTolerance(double at){if(at == 20.0) return; fprintf_s(mFile, "setAttr \".at\" %f;\n", at);}
	/*
	Angular tolerance for creation of extra triangles
	Note this attribute is for compatability only and should not be modified in Maya 7.0 files
	*/
	void setAngleTolerance(const DoubleID& at){fprintf_s(mFile,"connectAttr \"");at.write(mFile);fprintf_s(mFile,"\" \"%s.at\";\n",mName.c_str());}
	/*Subdivide new faces with more than 4 edges*/
	void setFillNgons(bool fn){if(fn == false) return; fprintf_s(mFile, "setAttr \".fn\" %i;\n", fn);}
	/*Subdivide new faces with more than 4 edges*/
	void setFillNgons(const BoolID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn\";\n",mName.c_str());}
	/*
	Technique used to compute UVs on new faces
	0 computes new UVs by projecting along surface normal of original mesh onto new mesh
	1 computes new UVs by projecting along surface normal of new mesh onto original mesh
	*/
	void setUvAssignment(unsigned int ua){if(ua == 0) return; fprintf_s(mFile, "setAttr \".ua\" %i;\n", ua);}
	/*
	Technique used to compute UVs on new faces
	0 computes new UVs by projecting along surface normal of original mesh onto new mesh
	1 computes new UVs by projecting along surface normal of new mesh onto original mesh
	*/
	void setUvAssignment(const UnsignedintID& ua){fprintf_s(mFile,"connectAttr \"");ua.write(mFile);fprintf_s(mFile,"\" \"%s.ua\";\n",mName.c_str());}
	/*Merge vertices within a tolerance*/
	void setMergeVertices(bool mv){if(mv == false) return; fprintf_s(mFile, "setAttr \".mv\" %i;\n", mv);}
	/*Merge vertices within a tolerance*/
	void setMergeVertices(const BoolID& mv){fprintf_s(mFile,"connectAttr \"");mv.write(mFile);fprintf_s(mFile,"\" \"%s.mv\";\n",mName.c_str());}
	/*Tolerance within which to merge vertices*/
	void setMergeVertexTolerance(double mvt){if(mvt == 0) return; fprintf_s(mFile, "setAttr \".mvt\" %f;\n", mvt);}
	/*Tolerance within which to merge vertices*/
	void setMergeVertexTolerance(const DoubleID& mvt){fprintf_s(mFile,"connectAttr \"");mvt.write(mFile);fprintf_s(mFile,"\" \"%s.mvt\";\n",mName.c_str());}
	/*Create new edges as hard edges if the angle between adjacent faces exceeds this value*/
	void setSmoothingAngle(double sa){if(sa == 0.0) return; fprintf_s(mFile, "setAttr \".sa\" %f;\n", sa);}
	/*Create new edges as hard edges if the angle between adjacent faces exceeds this value*/
	void setSmoothingAngle(const DoubleID& sa){fprintf_s(mFile,"connectAttr \"");sa.write(mFile);fprintf_s(mFile,"\" \"%s.sa\";\n",mName.c_str());}
	/*Miter faces that have angles less than this value*/
	void setMiteringAngle(double ma){if(ma == 0.0) return; fprintf_s(mFile, "setAttr \".ma\" %f;\n", ma);}
	/*Miter faces that have angles less than this value*/
	void setMiteringAngle(const DoubleID& ma){fprintf_s(mFile,"connectAttr \"");ma.write(mFile);fprintf_s(mFile,"\" \"%s.ma\";\n",mName.c_str());}
	/*If on, the offset value is treated as a fraction between zero and one.*/
	BoolID getOffsetAsFraction(){char buffer[4096];sprintf_s (buffer, "%s.oaf",mName.c_str());return (const char*)buffer;}
	/*The offset for bevel.*/
	DoubleID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The roundness of bevel, it is taken into account when autoFit is off.*/
	DoubleID getRoundness(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The number of segments used for bevelling.*/
	IntID getSegments(){char buffer[4096];sprintf_s (buffer, "%s.sg",mName.c_str());return (const char*)buffer;}
	/*If autoFit is on, it computes a smooth roundness :  new facets round off a smooth angle.*/
	BoolID getAutoFit(){char buffer[4096];sprintf_s (buffer, "%s.af",mName.c_str());return (const char*)buffer;}
	/*
	Angular tolerance for creation of extra triangles
	Note this attribute is for compatability only and should not be modified in Maya 7.0 files
	*/
	DoubleID getAngleTolerance(){char buffer[4096];sprintf_s (buffer, "%s.at",mName.c_str());return (const char*)buffer;}
	/*Subdivide new faces with more than 4 edges*/
	BoolID getFillNgons(){char buffer[4096];sprintf_s (buffer, "%s.fn",mName.c_str());return (const char*)buffer;}
	/*
	Technique used to compute UVs on new faces
	0 computes new UVs by projecting along surface normal of original mesh onto new mesh
	1 computes new UVs by projecting along surface normal of new mesh onto original mesh
	*/
	UnsignedintID getUvAssignment(){char buffer[4096];sprintf_s (buffer, "%s.ua",mName.c_str());return (const char*)buffer;}
	/*Merge vertices within a tolerance*/
	BoolID getMergeVertices(){char buffer[4096];sprintf_s (buffer, "%s.mv",mName.c_str());return (const char*)buffer;}
	/*Tolerance within which to merge vertices*/
	DoubleID getMergeVertexTolerance(){char buffer[4096];sprintf_s (buffer, "%s.mvt",mName.c_str());return (const char*)buffer;}
	/*Create new edges as hard edges if the angle between adjacent faces exceeds this value*/
	DoubleID getSmoothingAngle(){char buffer[4096];sprintf_s (buffer, "%s.sa",mName.c_str());return (const char*)buffer;}
	/*Miter faces that have angles less than this value*/
	DoubleID getMiteringAngle(){char buffer[4096];sprintf_s (buffer, "%s.ma",mName.c_str());return (const char*)buffer;}
protected:
	PolyBevel(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYBEVEL_H__
