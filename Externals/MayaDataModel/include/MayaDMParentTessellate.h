/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARENTTESSELLATE_H__
#define __MayaDM_PARENTTESSELLATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseNurbsConversion.h"
namespace MayaDM
{
/*The node serves as the parent class of TdnNurbsTesselate and TdnShellTesselate*/
class ParentTessellate : public AbstractBaseNurbsConversion
{
public:
public:
	ParentTessellate(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseNurbsConversion(file, name, parent, "parentTessellate"){}
	virtual ~ParentTessellate(){}
	/*Format: 0 - Triangle Count, 1 - Standard Fit, 2 - General, 3 - CVs*/
	void setFormat(unsigned int f){if(f == 1) return; fprintf_s(mFile, "setAttr \".f\" %i;\n", f);}
	/*Format: 0 - Triangle Count, 1 - Standard Fit, 2 - General, 3 - CVs*/
	void setFormat(const UnsignedintID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Polygon type: 0 - Triangles, 1 - Quads*/
	void setPolygonType(unsigned int pt){if(pt == 0) return; fprintf_s(mFile, "setAttr \".pt\" %i;\n", pt);}
	/*Polygon type: 0 - Triangles, 1 - Quads*/
	void setPolygonType(const UnsignedintID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
	/*
	The number of polygons to produce.
	Only used if Format is Triangle Count.
	*/
	void setPolygonCount(int pc){if(pc == 200) return; fprintf_s(mFile, "setAttr \".pc\" %i;\n", pc);}
	/*
	The number of polygons to produce.
	Only used if Format is Triangle Count.
	*/
	void setPolygonCount(const IntID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*
	Chord height ratio is the ratio of the chord length of a surface
	span to the chord height.  (This is a length to height ratio).
	0 is a very loose fit.
	1 is a very tight fit.
	(See also description of chord height.)
	Always used if Format is Standard Fit.  Otherwise,
	only used if Format is General and useChordHeightRatio is true.
	*/
	void setChordHeightRatio(double chr){if(chr == 0.983) return; fprintf_s(mFile, "setAttr \".chr\" %f;\n", chr);}
	/*
	Chord height ratio is the ratio of the chord length of a surface
	span to the chord height.  (This is a length to height ratio).
	0 is a very loose fit.
	1 is a very tight fit.
	(See also description of chord height.)
	Always used if Format is Standard Fit.  Otherwise,
	only used if Format is General and useChordHeightRatio is true.
	*/
	void setChordHeightRatio(const DoubleID& chr){fprintf_s(mFile,"connectAttr \"");chr.write(mFile);fprintf_s(mFile,"\" \"%s.chr\";\n",mName.c_str());}
	/*
	ChordHeightRatio evaluation changed in maya7.0 to match the behavior of this
	attribute on the nurbs surface shape node. Enabling
	this attribute will revert to the older behavior. The new behavior
	corresponds to roughly 1.0 minus the old value, although this simple
	math does not yield an exact match.
	*/
	void setPre70ChordHeightRatio(bool pchr){if(pchr == false) return; fprintf_s(mFile, "setAttr \".pchr\" %i;\n", pchr);}
	/*
	ChordHeightRatio evaluation changed in maya7.0 to match the behavior of this
	attribute on the nurbs surface shape node. Enabling
	this attribute will revert to the older behavior. The new behavior
	corresponds to roughly 1.0 minus the old value, although this simple
	math does not yield an exact match.
	*/
	void setPre70ChordHeightRatio(const BoolID& pchr){fprintf_s(mFile,"connectAttr \"");pchr.write(mFile);fprintf_s(mFile,"\" \"%s.pchr\";\n",mName.c_str());}
	/*
	Fractional tolerance.
	Only used if Format is Standard Fit.
	*/
	void setFractionalTolerance(double ft){if(ft == 0.01) return; fprintf_s(mFile, "setAttr \".ft\" %f;\n", ft);}
	/*
	Fractional tolerance.
	Only used if Format is Standard Fit.
	*/
	void setFractionalTolerance(const DoubleID& ft){fprintf_s(mFile,"connectAttr \"");ft.write(mFile);fprintf_s(mFile,"\" \"%s.ft\";\n",mName.c_str());}
	/*
	Minimal edge length.
	Only used if Format is Standard Fit.
	*/
	void setMinEdgeLength(double mel){if(mel == 0) return; fprintf_s(mFile, "setAttr \".mel\" %f;\n", mel);}
	/*
	Minimal edge length.
	Only used if Format is Standard Fit.
	*/
	void setMinEdgeLength(const DoubleID& mel){fprintf_s(mFile,"connectAttr \"");mel.write(mFile);fprintf_s(mFile,"\" \"%s.mel\";\n",mName.c_str());}
	/*
	3D delta.
	Only used if Format is Standard Fit.
	*/
	void setDelta(double d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	3D delta.
	Only used if Format is Standard Fit.
	*/
	void setDelta(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	Initial U type tessellation criteria (3 types).
	Type 0 - Per surface # of isoparms in 3D.  This type
	places a specific number of iso-parametric subdivision lines
	across the surface, equally spaced in 3D space.
	Type 1 - Per surface # of isoparms.  This type
	places a specific number of iso-parametric subdivision lines
	across the surface, equally spaced in parameter space.
	Type 2 - Per span # of isoparms.  This type
	places a specific number of iso-parametric subdivision lines
	across each surface span, equally spaced in parameter space.
	(This is the closest option to the Alias Studio
	tessellation parameters.)
	This attribute is only used if Format is General.
	*/
	void setUType(unsigned int ut){if(ut == 3) return; fprintf_s(mFile, "setAttr \".ut\" %i;\n", ut);}
	/*
	Initial U type tessellation criteria (3 types).
	Type 0 - Per surface # of isoparms in 3D.  This type
	places a specific number of iso-parametric subdivision lines
	across the surface, equally spaced in 3D space.
	Type 1 - Per surface # of isoparms.  This type
	places a specific number of iso-parametric subdivision lines
	across the surface, equally spaced in parameter space.
	Type 2 - Per span # of isoparms.  This type
	places a specific number of iso-parametric subdivision lines
	across each surface span, equally spaced in parameter space.
	(This is the closest option to the Alias Studio
	tessellation parameters.)
	This attribute is only used if Format is General.
	*/
	void setUType(const UnsignedintID& ut){fprintf_s(mFile,"connectAttr \"");ut.write(mFile);fprintf_s(mFile,"\" \"%s.ut\";\n",mName.c_str());}
	/*
	Initial number of isoparms in U.  Used in conjunction with
	the uType attribute.
	Only used if Format is General.
	*/
	void setUNumber(int un){if(un == 3) return; fprintf_s(mFile, "setAttr \".un\" %i;\n", un);}
	/*
	Initial number of isoparms in U.  Used in conjunction with
	the uType attribute.
	Only used if Format is General.
	*/
	void setUNumber(const IntID& un){fprintf_s(mFile,"connectAttr \"");un.write(mFile);fprintf_s(mFile,"\" \"%s.un\";\n",mName.c_str());}
	/*
	Initial V type tessellation criteria (3 types).
	See description for the uType attribute.
	Only used if Format is General.
	*/
	void setVType(unsigned int vt){if(vt == 3) return; fprintf_s(mFile, "setAttr \".vt\" %i;\n", vt);}
	/*
	Initial V type tessellation criteria (3 types).
	See description for the uType attribute.
	Only used if Format is General.
	*/
	void setVType(const UnsignedintID& vt){fprintf_s(mFile,"connectAttr \"");vt.write(mFile);fprintf_s(mFile,"\" \"%s.vt\";\n",mName.c_str());}
	/*
	Initial number of isoparms in V.  Used in conjunction with
	the vType attribute.
	Only used if Format is General.
	*/
	void setVNumber(int vn){if(vn == 3) return; fprintf_s(mFile, "setAttr \".vn\" %i;\n", vn);}
	/*
	Initial number of isoparms in V.  Used in conjunction with
	the vType attribute.
	Only used if Format is General.
	*/
	void setVNumber(const IntID& vn){fprintf_s(mFile,"connectAttr \"");vn.write(mFile);fprintf_s(mFile,"\" \"%s.vn\";\n",mName.c_str());}
	/*
	True means use chord height.
	Only used if Format is General.
	*/
	void setUseChordHeight(bool uch){if(uch == false) return; fprintf_s(mFile, "setAttr \".uch\" %i;\n", uch);}
	/*
	True means use chord height.
	Only used if Format is General.
	*/
	void setUseChordHeight(const BoolID& uch){fprintf_s(mFile,"connectAttr \"");uch.write(mFile);fprintf_s(mFile,"\" \"%s.uch\";\n",mName.c_str());}
	/*True means use chord height ratio.*/
	void setUseChordHeightRatio(bool ucr){if(ucr == true) return; fprintf_s(mFile, "setAttr \".ucr\" %i;\n", ucr);}
	/*True means use chord height ratio.*/
	void setUseChordHeightRatio(const BoolID& ucr){fprintf_s(mFile,"connectAttr \"");ucr.write(mFile);fprintf_s(mFile,"\" \"%s.ucr\";\n",mName.c_str());}
	/*
	Chord height is the absolute distance in OBJECT space
	which the center of a polygon edge can deviate from
	the actual center of the surface span.
	Only used if Format is General and if useChordHeight is true.
	*/
	void setChordHeight(double cht){if(cht == 0) return; fprintf_s(mFile, "setAttr \".cht\" %f;\n", cht);}
	/*
	Chord height is the absolute distance in OBJECT space
	which the center of a polygon edge can deviate from
	the actual center of the surface span.
	Only used if Format is General and if useChordHeight is true.
	*/
	void setChordHeight(const DoubleID& cht){fprintf_s(mFile,"connectAttr \"");cht.write(mFile);fprintf_s(mFile,"\" \"%s.cht\";\n",mName.c_str());}
	/*
	Edge swap.  This attribute enables an algorithm which determines
	the optimal method with which to tessellate a quadrilateral
	into triangles.
	Only used if Format is General.
	*/
	void setEdgeSwap(bool es){if(es == false) return; fprintf_s(mFile, "setAttr \".es\" %i;\n", es);}
	/*
	Edge swap.  This attribute enables an algorithm which determines
	the optimal method with which to tessellate a quadrilateral
	into triangles.
	Only used if Format is General.
	*/
	void setEdgeSwap(const BoolID& es){fprintf_s(mFile,"connectAttr \"");es.write(mFile);fprintf_s(mFile,"\" \"%s.es\";\n",mName.c_str());}
	/*
	Only used when the format is CVs.  Order the cvs so that
	the normal matches the direction of the original surface
	if set to true.
	*/
	void setMatchNormalDir(bool mnd){if(mnd == false) return; fprintf_s(mFile, "setAttr \".mnd\" %i;\n", mnd);}
	/*
	Only used when the format is CVs.  Order the cvs so that
	the normal matches the direction of the original surface
	if set to true.
	*/
	void setMatchNormalDir(const BoolID& mnd){fprintf_s(mFile,"connectAttr \"");mnd.write(mFile);fprintf_s(mFile,"\" \"%s.mnd\";\n",mName.c_str());}
	/*
	This attribute is only applicable when a trimmed NURBS surface
	is used as the input surface.
	When true, the UV texture coordinates on the trimmed input surface
	are normalized and applied to the output surface as they are
	for the untrimmed version of the input surface.
	(The texture coordinates on the entire untrimmed surface
	are mapped to the entire output surface.)
	When false, the UV texture coordinates on the trimmed input surface
	are applied to the output surface as they are for the trimmed
	input surface.  (Only the texture coordinates visible on the trimmed
	input surface are mapped to the output surface.)
	*/
	void setNormalizeTrimmedUVRange(bool ntr){if(ntr == true) return; fprintf_s(mFile, "setAttr \".ntr\" %i;\n", ntr);}
	/*
	This attribute is only applicable when a trimmed NURBS surface
	is used as the input surface.
	When true, the UV texture coordinates on the trimmed input surface
	are normalized and applied to the output surface as they are
	for the untrimmed version of the input surface.
	(The texture coordinates on the entire untrimmed surface
	are mapped to the entire output surface.)
	When false, the UV texture coordinates on the trimmed input surface
	are applied to the output surface as they are for the trimmed
	input surface.  (Only the texture coordinates visible on the trimmed
	input surface are mapped to the output surface.)
	*/
	void setNormalizeTrimmedUVRange(const BoolID& ntr){fprintf_s(mFile,"connectAttr \"");ntr.write(mFile);fprintf_s(mFile,"\" \"%s.ntr\";\n",mName.c_str());}
	/*Output polygon*/
	void setOutputPolygon(const MeshID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*Format: 0 - Triangle Count, 1 - Standard Fit, 2 - General, 3 - CVs*/
	UnsignedintID getFormat(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*Polygon type: 0 - Triangles, 1 - Quads*/
	UnsignedintID getPolygonType(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*
	The number of polygons to produce.
	Only used if Format is Triangle Count.
	*/
	IntID getPolygonCount(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*
	Chord height ratio is the ratio of the chord length of a surface
	span to the chord height.  (This is a length to height ratio).
	0 is a very loose fit.
	1 is a very tight fit.
	(See also description of chord height.)
	Always used if Format is Standard Fit.  Otherwise,
	only used if Format is General and useChordHeightRatio is true.
	*/
	DoubleID getChordHeightRatio(){char buffer[4096];sprintf_s (buffer, "%s.chr",mName.c_str());return (const char*)buffer;}
	/*
	ChordHeightRatio evaluation changed in maya7.0 to match the behavior of this
	attribute on the nurbs surface shape node. Enabling
	this attribute will revert to the older behavior. The new behavior
	corresponds to roughly 1.0 minus the old value, although this simple
	math does not yield an exact match.
	*/
	BoolID getPre70ChordHeightRatio(){char buffer[4096];sprintf_s (buffer, "%s.pchr",mName.c_str());return (const char*)buffer;}
	/*
	Fractional tolerance.
	Only used if Format is Standard Fit.
	*/
	DoubleID getFractionalTolerance(){char buffer[4096];sprintf_s (buffer, "%s.ft",mName.c_str());return (const char*)buffer;}
	/*
	Minimal edge length.
	Only used if Format is Standard Fit.
	*/
	DoubleID getMinEdgeLength(){char buffer[4096];sprintf_s (buffer, "%s.mel",mName.c_str());return (const char*)buffer;}
	/*
	3D delta.
	Only used if Format is Standard Fit.
	*/
	DoubleID getDelta(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	Initial U type tessellation criteria (3 types).
	Type 0 - Per surface # of isoparms in 3D.  This type
	places a specific number of iso-parametric subdivision lines
	across the surface, equally spaced in 3D space.
	Type 1 - Per surface # of isoparms.  This type
	places a specific number of iso-parametric subdivision lines
	across the surface, equally spaced in parameter space.
	Type 2 - Per span # of isoparms.  This type
	places a specific number of iso-parametric subdivision lines
	across each surface span, equally spaced in parameter space.
	(This is the closest option to the Alias Studio
	tessellation parameters.)
	This attribute is only used if Format is General.
	*/
	UnsignedintID getUType(){char buffer[4096];sprintf_s (buffer, "%s.ut",mName.c_str());return (const char*)buffer;}
	/*
	Initial number of isoparms in U.  Used in conjunction with
	the uType attribute.
	Only used if Format is General.
	*/
	IntID getUNumber(){char buffer[4096];sprintf_s (buffer, "%s.un",mName.c_str());return (const char*)buffer;}
	/*
	Initial V type tessellation criteria (3 types).
	See description for the uType attribute.
	Only used if Format is General.
	*/
	UnsignedintID getVType(){char buffer[4096];sprintf_s (buffer, "%s.vt",mName.c_str());return (const char*)buffer;}
	/*
	Initial number of isoparms in V.  Used in conjunction with
	the vType attribute.
	Only used if Format is General.
	*/
	IntID getVNumber(){char buffer[4096];sprintf_s (buffer, "%s.vn",mName.c_str());return (const char*)buffer;}
	/*
	True means use chord height.
	Only used if Format is General.
	*/
	BoolID getUseChordHeight(){char buffer[4096];sprintf_s (buffer, "%s.uch",mName.c_str());return (const char*)buffer;}
	/*True means use chord height ratio.*/
	BoolID getUseChordHeightRatio(){char buffer[4096];sprintf_s (buffer, "%s.ucr",mName.c_str());return (const char*)buffer;}
	/*
	Chord height is the absolute distance in OBJECT space
	which the center of a polygon edge can deviate from
	the actual center of the surface span.
	Only used if Format is General and if useChordHeight is true.
	*/
	DoubleID getChordHeight(){char buffer[4096];sprintf_s (buffer, "%s.cht",mName.c_str());return (const char*)buffer;}
	/*
	Edge swap.  This attribute enables an algorithm which determines
	the optimal method with which to tessellate a quadrilateral
	into triangles.
	Only used if Format is General.
	*/
	BoolID getEdgeSwap(){char buffer[4096];sprintf_s (buffer, "%s.es",mName.c_str());return (const char*)buffer;}
	/*
	Only used when the format is CVs.  Order the cvs so that
	the normal matches the direction of the original surface
	if set to true.
	*/
	BoolID getMatchNormalDir(){char buffer[4096];sprintf_s (buffer, "%s.mnd",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is only applicable when a trimmed NURBS surface
	is used as the input surface.
	When true, the UV texture coordinates on the trimmed input surface
	are normalized and applied to the output surface as they are
	for the untrimmed version of the input surface.
	(The texture coordinates on the entire untrimmed surface
	are mapped to the entire output surface.)
	When false, the UV texture coordinates on the trimmed input surface
	are applied to the output surface as they are for the trimmed
	input surface.  (Only the texture coordinates visible on the trimmed
	input surface are mapped to the output surface.)
	*/
	BoolID getNormalizeTrimmedUVRange(){char buffer[4096];sprintf_s (buffer, "%s.ntr",mName.c_str());return (const char*)buffer;}
	/*Output polygon*/
	MeshID getOutputPolygon(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
protected:
	ParentTessellate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseNurbsConversion(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARENTTESSELLATE_H__
