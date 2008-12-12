/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BEVELPLUS_H__
#define __MayaDM_BEVELPLUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
*/
class BevelPlus : public AbstractBaseCreate
{
public:
public:
	BevelPlus(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "bevelPlus"){}
	virtual ~BevelPlus(){}
	/*The input curves.  The first one is the outer curve and should contain all the other curves within it.*/
	void setInputCurves(size_t ics_i,const NurbsCurveID& ics){fprintf_s(mFile,"connectAttr \"");ics.write(mFile);fprintf_s(mFile,"\" \"%s.ics[%i]\";\n",mName.c_str(),ics_i);}
	/*The bevel outer style curve, used for the first (outer) curve.*/
	void setOuterStyleCurve(const NurbsCurveID& osc){fprintf_s(mFile,"connectAttr \"");osc.write(mFile);fprintf_s(mFile,"\" \"%s.osc\";\n",mName.c_str());}
	/*The bevel inner style curve, used for all but the first (outer) curve.*/
	void setInnerStyleCurve(const NurbsCurveID& isc){fprintf_s(mFile,"connectAttr \"");isc.write(mFile);fprintf_s(mFile,"\" \"%s.isc\";\n",mName.c_str());}
	/*Output as a single polygon of all the bevel surfaces and caps.*/
	void setOutputPoly(const MeshID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*Start cap surface.  This will always be a trimmed NURBS surface.*/
	void setStartCapSurface(const NurbsSurfaceID& scs){fprintf_s(mFile,"connectAttr \"");scs.write(mFile);fprintf_s(mFile,"\" \"%s.scs\";\n",mName.c_str());}
	/*End cap surface.  This will always be a trimmed NURBS surface.*/
	void setEndCapSurface(const NurbsSurfaceID& ecs){fprintf_s(mFile,"connectAttr \"");ecs.write(mFile);fprintf_s(mFile,"\" \"%s.ecs\";\n",mName.c_str());}
	/*Output NURBS surfaces - the bevel surfaces (one per each input curve).*/
	void setOutputSurfaces(size_t os1_i,const NurbsSurfaceID& os1){fprintf_s(mFile,"connectAttr \"");os1.write(mFile);fprintf_s(mFile,"\" \"%s.os1[%i]\";\n",mName.c_str(),os1_i);}
	/*
	The number of curves for each created text character.
	There is an entry for each character in the string, and the value
	should be the number of curves in that character.
	NOTE: This attribute is intended for use only by the makeTextCurves node
	*/
	void setCount(size_t c_i,const IntID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c[%i]\";\n",mName.c_str(),c_i);}
	/*
	Offsets for each character of the created text string.
	The value is specified in the current distance units.
	NOTE: This attribute is intended for use only by the makeTextCurves node
	*/
	void setPosition(size_t p_i,const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*Offsets for each character in X.*/
	void setPositionX(size_t p_i,const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].px\";\n",mName.c_str(),p_i);}
	/*Offsets for each character in Y.*/
	void setPositionY(size_t p_i,const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].py\";\n",mName.c_str(),p_i);}
	/*Offsets for each character in Z.*/
	void setPositionZ(size_t p_i,const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].pz\";\n",mName.c_str(),p_i);}
	/*The tolerance for creating NURBS caps.*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*The tolerance for creating NURBS caps.*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*The width for the bevel.*/
	void setWidth(double w){if(w == 0) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*The width for the bevel.*/
	void setWidth(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*The depth for the bevel.*/
	void setDepth(double d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*The depth for the bevel.*/
	void setDepth(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The extrude distance (depth) for bevel.*/
	void setExtrudeDepth(double ed){if(ed == 0) return; fprintf_s(mFile, "setAttr \".ed\" %f;\n", ed);}
	/*The extrude distance (depth) for bevel.*/
	void setExtrudeDepth(const DoubleID& ed){fprintf_s(mFile,"connectAttr \"");ed.write(mFile);fprintf_s(mFile,"\" \"%s.ed\";\n",mName.c_str());}
	/*Number of sides to bevel: 1 - no bevel just extrude, 2 - bevel start and extrude, 3 - bevel end and extrude, 4 - bevel start and end and extrude*/
	void setNumberOfSides(int ns){if(ns == 4) return; fprintf_s(mFile, "setAttr \".ns\" %i;\n", ns);}
	/*Number of sides to bevel: 1 - no bevel just extrude, 2 - bevel start and extrude, 3 - bevel end and extrude, 4 - bevel start and end and extrude*/
	void setNumberOfSides(const IntID& ns){fprintf_s(mFile,"connectAttr \"");ns.write(mFile);fprintf_s(mFile,"\" \"%s.ns\";\n",mName.c_str());}
	/*Number of sides to cap: 1 - none, 2 - At start, 3 - At end, 4 - At start and end*/
	void setCapSides(int cap){if(cap == 1) return; fprintf_s(mFile, "setAttr \".cap\" %i;\n", cap);}
	/*Number of sides to cap: 1 - none, 2 - At start, 3 - At end, 4 - At start and end*/
	void setCapSides(const IntID& cap){fprintf_s(mFile,"connectAttr \"");cap.write(mFile);fprintf_s(mFile,"\" \"%s.cap\";\n",mName.c_str());}
	/*
	If true, join all the bevel surfaces into one, if false leave separate
	Only applies to NURBS surfaces. Does not join the caps to the sides.
	*/
	void setJoinSurfaces(bool js){if(js == true) return; fprintf_s(mFile, "setAttr \".js\" %i;\n", js);}
	/*
	If true, join all the bevel surfaces into one, if false leave separate
	Only applies to NURBS surfaces. Does not join the caps to the sides.
	*/
	void setJoinSurfaces(const BoolID& js){fprintf_s(mFile,"connectAttr \"");js.write(mFile);fprintf_s(mFile,"\" \"%s.js\";\n",mName.c_str());}
	/*
	If true, the orientation of the curves defines their nesting, and the first curve on
	each letter is the outer curve. If false the ordering of curves in a letter is undetermined.
	In the latter case the node will try to determine the nesting of the curves itself.
	*/
	void setOrderedCurves(bool oc){if(oc == false) return; fprintf_s(mFile, "setAttr \".oc\" %i;\n", oc);}
	/*
	If true, the orientation of the curves defines their nesting, and the first curve on
	each letter is the outer curve. If false the ordering of curves in a letter is undetermined.
	In the latter case the node will try to determine the nesting of the curves itself.
	*/
	void setOrderedCurves(const BoolID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*
	If true, surface normals point outwards
	Default is false for compatability with pre-7.0 files that had inward-facing normals
	*/
	void setNormalsOutwards(bool no){if(no == false) return; fprintf_s(mFile, "setAttr \".no\" %i;\n", no);}
	/*
	If true, surface normals point outwards
	Default is false for compatability with pre-7.0 files that had inward-facing normals
	*/
	void setNormalsOutwards(const BoolID& no){fprintf_s(mFile,"connectAttr \"");no.write(mFile);fprintf_s(mFile,"\" \"%s.no\";\n",mName.c_str());}
	/*Method for the polygonal output: 0 - Face Count, 2 - Sampling*/
	void setPolyOutMethod(unsigned int pom){if(pom == 0) return; fprintf_s(mFile, "setAttr \".pom\" %i;\n", pom);}
	/*Method for the polygonal output: 0 - Face Count, 2 - Sampling*/
	void setPolyOutMethod(const UnsignedintID& pom){fprintf_s(mFile,"connectAttr \"");pom.write(mFile);fprintf_s(mFile,"\" \"%s.pom\";\n",mName.c_str());}
	/*
	The number of polygons to produce when the polygon is requested.
	Only used if method is face count.
	*/
	void setPolyOutCount(int poc){if(poc == 200) return; fprintf_s(mFile, "setAttr \".poc\" %i;\n", poc);}
	/*
	The number of polygons to produce when the polygon is requested.
	Only used if method is face count.
	*/
	void setPolyOutCount(const IntID& poc){fprintf_s(mFile,"connectAttr \"");poc.write(mFile);fprintf_s(mFile,"\" \"%s.poc\";\n",mName.c_str());}
	/*
	Initial type tessellation criteria along the extrude direction.
	Type 2 - Complete Extrusion.  This type
	places a specific number of lines
	across the surface, equally spaced in parameter space.
	Type 3 - Extrusion Section.  This type
	places a specific number of lines
	across each surface span, equally spaced in parameter space.
	This attribute is only used if Method is Sampling.
	*/
	void setPolyOutExtrusionType(unsigned int pet){if(pet == 1) return; fprintf_s(mFile, "setAttr \".pet\" %i;\n", pet);}
	/*
	Initial type tessellation criteria along the extrude direction.
	Type 2 - Complete Extrusion.  This type
	places a specific number of lines
	across the surface, equally spaced in parameter space.
	Type 3 - Extrusion Section.  This type
	places a specific number of lines
	across each surface span, equally spaced in parameter space.
	This attribute is only used if Method is Sampling.
	*/
	void setPolyOutExtrusionType(const UnsignedintID& pet){fprintf_s(mFile,"connectAttr \"");pet.write(mFile);fprintf_s(mFile,"\" \"%s.pet\";\n",mName.c_str());}
	/*Initial number of samples along the extrusion. Only used if Method is Sampling.*/
	void setPolyOutExtrusionSamples(int pes){if(pes == 2) return; fprintf_s(mFile, "setAttr \".pes\" %i;\n", pes);}
	/*Initial number of samples along the extrusion. Only used if Method is Sampling.*/
	void setPolyOutExtrusionSamples(const IntID& pes){fprintf_s(mFile,"connectAttr \"");pes.write(mFile);fprintf_s(mFile,"\" \"%s.pes\";\n",mName.c_str());}
	/*
	Initial V type tessellation criteria along the curve.
	Type 2 - Complete Curve.  This type
	places a specific number of sample points
	along the curve, equally spaced in parameter space.
	Type 3 - Curve Span.  This type
	places a specific number of sample points
	across each curve span, equally spaced in parameter space.
	Only used if Method is Sampling.
	*/
	void setPolyOutCurveType(unsigned int pct){if(pct == 1) return; fprintf_s(mFile, "setAttr \".pct\" %i;\n", pct);}
	/*
	Initial V type tessellation criteria along the curve.
	Type 2 - Complete Curve.  This type
	places a specific number of sample points
	along the curve, equally spaced in parameter space.
	Type 3 - Curve Span.  This type
	places a specific number of sample points
	across each curve span, equally spaced in parameter space.
	Only used if Method is Sampling.
	*/
	void setPolyOutCurveType(const UnsignedintID& pct){fprintf_s(mFile,"connectAttr \"");pct.write(mFile);fprintf_s(mFile,"\" \"%s.pct\";\n",mName.c_str());}
	/*Initial number of samples in the curve direction. Only used if Method is Sampling.*/
	void setPolyOutCurveSamples(int pcs){if(pcs == 6) return; fprintf_s(mFile, "setAttr \".pcs\" %i;\n", pcs);}
	/*Initial number of samples in the curve direction. Only used if Method is Sampling.*/
	void setPolyOutCurveSamples(const IntID& pcs){fprintf_s(mFile,"connectAttr \"");pcs.write(mFile);fprintf_s(mFile,"\" \"%s.pcs\";\n",mName.c_str());}
	/*True means use chord height.  This is a secondary criteria that refines the tessellation produced using the sampling value.  Only used if Method is Sampling.*/
	void setPolyOutUseChordHeight(bool uch){if(uch == false) return; fprintf_s(mFile, "setAttr \".uch\" %i;\n", uch);}
	/*True means use chord height.  This is a secondary criteria that refines the tessellation produced using the sampling value.  Only used if Method is Sampling.*/
	void setPolyOutUseChordHeight(const BoolID& uch){fprintf_s(mFile,"connectAttr \"");uch.write(mFile);fprintf_s(mFile,"\" \"%s.uch\";\n",mName.c_str());}
	/*Chord height is the absolute distance in object space which the center of a polygon edge can deviate from the actual center of the surface span. Only used if Method is Sampling and if polyOutseChordHeight is true.*/
	void setPolyOutChordHeight(double cht){if(cht == 0) return; fprintf_s(mFile, "setAttr \".cht\" %f;\n", cht);}
	/*Chord height is the absolute distance in object space which the center of a polygon edge can deviate from the actual center of the surface span. Only used if Method is Sampling and if polyOutseChordHeight is true.*/
	void setPolyOutChordHeight(const DoubleID& cht){fprintf_s(mFile,"connectAttr \"");cht.write(mFile);fprintf_s(mFile,"\" \"%s.cht\";\n",mName.c_str());}
	/*True means use chord height ratio.  This is a secondary criteria that refines the tessellation produced using the sampling value.  Only used if Method is Sampling.*/
	void setPolyOutUseChordHeightRatio(bool ucr){if(ucr == true) return; fprintf_s(mFile, "setAttr \".ucr\" %i;\n", ucr);}
	/*True means use chord height ratio.  This is a secondary criteria that refines the tessellation produced using the sampling value.  Only used if Method is Sampling.*/
	void setPolyOutUseChordHeightRatio(const BoolID& ucr){fprintf_s(mFile,"connectAttr \"");ucr.write(mFile);fprintf_s(mFile,"\" \"%s.ucr\";\n",mName.c_str());}
	/*Chord height ratio is the ratio of the chord length of a surface span to the chord height.  (This is a length to height ratio). 0 is a very loose fit. 1 is a very tight fit.  This applies to the polygonal output type only. (See also description of chord height.) Used if Method is Sampling and polyOutUseChordHeightRatio is true.*/
	void setPolyOutChordHeightRatio(double chr){if(chr == 0.1) return; fprintf_s(mFile, "setAttr \".chr\" %f;\n", chr);}
	/*Chord height ratio is the ratio of the chord length of a surface span to the chord height.  (This is a length to height ratio). 0 is a very loose fit. 1 is a very tight fit.  This applies to the polygonal output type only. (See also description of chord height.) Used if Method is Sampling and polyOutUseChordHeightRatio is true.*/
	void setPolyOutChordHeightRatio(const DoubleID& chr){fprintf_s(mFile,"connectAttr \"");chr.write(mFile);fprintf_s(mFile,"\" \"%s.chr\";\n",mName.c_str());}
	/*The input curves.  The first one is the outer curve and should contain all the other curves within it.*/
	const NurbsCurveID& getInputCurves(size_t ics_i){char buffer[4096];sprintf_s (buffer, "%s.ics[%i]",mName.c_str(),ics_i);return (const char*)buffer;}
	/*The bevel outer style curve, used for the first (outer) curve.*/
	NurbsCurveID getOuterStyleCurve(){char buffer[4096];sprintf_s (buffer, "%s.osc",mName.c_str());return (const char*)buffer;}
	/*The bevel inner style curve, used for all but the first (outer) curve.*/
	NurbsCurveID getInnerStyleCurve(){char buffer[4096];sprintf_s (buffer, "%s.isc",mName.c_str());return (const char*)buffer;}
	/*Output as a single polygon of all the bevel surfaces and caps.*/
	MeshID getOutputPoly(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*Start cap surface.  This will always be a trimmed NURBS surface.*/
	NurbsSurfaceID getStartCapSurface(){char buffer[4096];sprintf_s (buffer, "%s.scs",mName.c_str());return (const char*)buffer;}
	/*End cap surface.  This will always be a trimmed NURBS surface.*/
	NurbsSurfaceID getEndCapSurface(){char buffer[4096];sprintf_s (buffer, "%s.ecs",mName.c_str());return (const char*)buffer;}
	/*Output NURBS surfaces - the bevel surfaces (one per each input curve).*/
	const NurbsSurfaceID& getOutputSurfaces(size_t os1_i){char buffer[4096];sprintf_s (buffer, "%s.os1[%i]",mName.c_str(),os1_i);return (const char*)buffer;}
	/*
	The number of curves for each created text character.
	There is an entry for each character in the string, and the value
	should be the number of curves in that character.
	NOTE: This attribute is intended for use only by the makeTextCurves node
	*/
	const IntID& getCount(size_t c_i){char buffer[4096];sprintf_s (buffer, "%s.c[%i]",mName.c_str(),c_i);return (const char*)buffer;}
	/*
	Offsets for each character of the created text string.
	The value is specified in the current distance units.
	NOTE: This attribute is intended for use only by the makeTextCurves node
	*/
	const Double3ID& getPosition(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*Offsets for each character in X.*/
	const DoubleID& getPositionX(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].px",mName.c_str(),p_i);return (const char*)buffer;}
	/*Offsets for each character in Y.*/
	const DoubleID& getPositionY(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].py",mName.c_str(),p_i);return (const char*)buffer;}
	/*Offsets for each character in Z.*/
	const DoubleID& getPositionZ(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].pz",mName.c_str(),p_i);return (const char*)buffer;}
	/*The tolerance for creating NURBS caps.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*The width for the bevel.*/
	DoubleID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*The depth for the bevel.*/
	DoubleID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The extrude distance (depth) for bevel.*/
	DoubleID getExtrudeDepth(){char buffer[4096];sprintf_s (buffer, "%s.ed",mName.c_str());return (const char*)buffer;}
	/*Number of sides to bevel: 1 - no bevel just extrude, 2 - bevel start and extrude, 3 - bevel end and extrude, 4 - bevel start and end and extrude*/
	IntID getNumberOfSides(){char buffer[4096];sprintf_s (buffer, "%s.ns",mName.c_str());return (const char*)buffer;}
	/*Number of sides to cap: 1 - none, 2 - At start, 3 - At end, 4 - At start and end*/
	IntID getCapSides(){char buffer[4096];sprintf_s (buffer, "%s.cap",mName.c_str());return (const char*)buffer;}
	/*
	If true, join all the bevel surfaces into one, if false leave separate
	Only applies to NURBS surfaces. Does not join the caps to the sides.
	*/
	BoolID getJoinSurfaces(){char buffer[4096];sprintf_s (buffer, "%s.js",mName.c_str());return (const char*)buffer;}
	/*
	If true, the orientation of the curves defines their nesting, and the first curve on
	each letter is the outer curve. If false the ordering of curves in a letter is undetermined.
	In the latter case the node will try to determine the nesting of the curves itself.
	*/
	BoolID getOrderedCurves(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*
	If true, surface normals point outwards
	Default is false for compatability with pre-7.0 files that had inward-facing normals
	*/
	BoolID getNormalsOutwards(){char buffer[4096];sprintf_s (buffer, "%s.no",mName.c_str());return (const char*)buffer;}
	/*Method for the polygonal output: 0 - Face Count, 2 - Sampling*/
	UnsignedintID getPolyOutMethod(){char buffer[4096];sprintf_s (buffer, "%s.pom",mName.c_str());return (const char*)buffer;}
	/*
	The number of polygons to produce when the polygon is requested.
	Only used if method is face count.
	*/
	IntID getPolyOutCount(){char buffer[4096];sprintf_s (buffer, "%s.poc",mName.c_str());return (const char*)buffer;}
	/*
	Initial type tessellation criteria along the extrude direction.
	Type 2 - Complete Extrusion.  This type
	places a specific number of lines
	across the surface, equally spaced in parameter space.
	Type 3 - Extrusion Section.  This type
	places a specific number of lines
	across each surface span, equally spaced in parameter space.
	This attribute is only used if Method is Sampling.
	*/
	UnsignedintID getPolyOutExtrusionType(){char buffer[4096];sprintf_s (buffer, "%s.pet",mName.c_str());return (const char*)buffer;}
	/*Initial number of samples along the extrusion. Only used if Method is Sampling.*/
	IntID getPolyOutExtrusionSamples(){char buffer[4096];sprintf_s (buffer, "%s.pes",mName.c_str());return (const char*)buffer;}
	/*
	Initial V type tessellation criteria along the curve.
	Type 2 - Complete Curve.  This type
	places a specific number of sample points
	along the curve, equally spaced in parameter space.
	Type 3 - Curve Span.  This type
	places a specific number of sample points
	across each curve span, equally spaced in parameter space.
	Only used if Method is Sampling.
	*/
	UnsignedintID getPolyOutCurveType(){char buffer[4096];sprintf_s (buffer, "%s.pct",mName.c_str());return (const char*)buffer;}
	/*Initial number of samples in the curve direction. Only used if Method is Sampling.*/
	IntID getPolyOutCurveSamples(){char buffer[4096];sprintf_s (buffer, "%s.pcs",mName.c_str());return (const char*)buffer;}
	/*True means use chord height.  This is a secondary criteria that refines the tessellation produced using the sampling value.  Only used if Method is Sampling.*/
	BoolID getPolyOutUseChordHeight(){char buffer[4096];sprintf_s (buffer, "%s.uch",mName.c_str());return (const char*)buffer;}
	/*Chord height is the absolute distance in object space which the center of a polygon edge can deviate from the actual center of the surface span. Only used if Method is Sampling and if polyOutseChordHeight is true.*/
	DoubleID getPolyOutChordHeight(){char buffer[4096];sprintf_s (buffer, "%s.cht",mName.c_str());return (const char*)buffer;}
	/*True means use chord height ratio.  This is a secondary criteria that refines the tessellation produced using the sampling value.  Only used if Method is Sampling.*/
	BoolID getPolyOutUseChordHeightRatio(){char buffer[4096];sprintf_s (buffer, "%s.ucr",mName.c_str());return (const char*)buffer;}
	/*Chord height ratio is the ratio of the chord length of a surface span to the chord height.  (This is a length to height ratio). 0 is a very loose fit. 1 is a very tight fit.  This applies to the polygonal output type only. (See also description of chord height.) Used if Method is Sampling and polyOutUseChordHeightRatio is true.*/
	DoubleID getPolyOutChordHeightRatio(){char buffer[4096];sprintf_s (buffer, "%s.chr",mName.c_str());return (const char*)buffer;}
protected:
	BevelPlus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BEVELPLUS_H__
