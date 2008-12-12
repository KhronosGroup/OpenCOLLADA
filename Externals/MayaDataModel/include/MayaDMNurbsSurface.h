/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSSURFACE_H__
#define __MayaDM_NURBSSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSurfaceShape.h"
namespace MayaDM
{
/*This node represents a NURBS surface.*/
class NurbsSurface : public SurfaceShape
{
public:
	/*This is a root of following mental ray attributes.*/
	struct MentalRayControls{
		bool miOverrideCaustics;
		short miCausticAccuracy;
		float miCausticRadius;
		bool miOverrideGlobalIllumination;
		short miGlobillumAccuracy;
		float miGlobillumRadius;
		bool miOverrideFinalGather;
		int miFinalGatherRays;
		float miFinalGatherMinRadius;
		float miFinalGatherMaxRadius;
		short miFinalGatherFilter;
		bool miFinalGatherView;
		bool miOverrideSamples;
		short miMinSamples;
		short miMaxSamples;
		bool miFinalGatherCast;
		bool miFinalGatherReceive;
		bool miTransparencyCast;
		bool miTransparencyReceive;
		bool miReflectionReceive;
		bool miRefractionReceive;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", miOverrideCaustics);
			fprintf_s(file,"%i ", miCausticAccuracy);
			fprintf_s(file,"%f ", miCausticRadius);
			fprintf_s(file,"%i ", miOverrideGlobalIllumination);
			fprintf_s(file,"%i ", miGlobillumAccuracy);
			fprintf_s(file,"%f ", miGlobillumRadius);
			fprintf_s(file,"%i ", miOverrideFinalGather);
			fprintf_s(file,"%i ", miFinalGatherRays);
			fprintf_s(file,"%f ", miFinalGatherMinRadius);
			fprintf_s(file,"%f ", miFinalGatherMaxRadius);
			fprintf_s(file,"%i ", miFinalGatherFilter);
			fprintf_s(file,"%i ", miFinalGatherView);
			fprintf_s(file,"%i ", miOverrideSamples);
			fprintf_s(file,"%i ", miMinSamples);
			fprintf_s(file,"%i ", miMaxSamples);
			fprintf_s(file,"%i ", miFinalGatherCast);
			fprintf_s(file,"%i ", miFinalGatherReceive);
			fprintf_s(file,"%i ", miTransparencyCast);
			fprintf_s(file,"%i ", miTransparencyReceive);
			fprintf_s(file,"%i ", miReflectionReceive);
			fprintf_s(file,"%i", miRefractionReceive);
		}
	};
public:
	NurbsSurface(FILE* file,const std::string& name,const std::string& parent=""):SurfaceShape(file, name, parent, "nurbsSurface"){}
	virtual ~NurbsSurface(){}
	/*
	Create in local space.  Construction history operations put the result
	in this attribute.
	*/
	void setCreate(const NurbsSurfaceID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*Surface in local space to be used in subsequent operations*/
	void setLocal(const NurbsSurfaceID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*
	Surface in world space (indexed by the instance number) to be used
	in subsequent operations
	*/
	void setWorldSpace(size_t ws_i,const NurbsSurfaceID& ws){fprintf_s(mFile,"connectAttr \"");ws.write(mFile);fprintf_s(mFile,"\" \"%s.ws[%i]\";\n",mName.c_str(),ws_i);}
	/*controls the num of divisions per span along U*/
	void setDivisionsU(unsigned char dvu){if(dvu == 0) return; fprintf_s(mFile, "setAttr \".dvu\" %i;\n", dvu);}
	/*controls the num of divisions per span along U*/
	void setDivisionsU(const UnsignedcharID& dvu){fprintf_s(mFile,"connectAttr \"");dvu.write(mFile);fprintf_s(mFile,"\" \"%s.dvu\";\n",mName.c_str());}
	/*controls the num of divisions per span along V*/
	void setDivisionsV(unsigned char dvv){if(dvv == 0) return; fprintf_s(mFile, "setAttr \".dvv\" %i;\n", dvv);}
	/*controls the num of divisions per span along V*/
	void setDivisionsV(const UnsignedcharID& dvv){fprintf_s(mFile,"connectAttr \"");dvv.write(mFile);fprintf_s(mFile,"\" \"%s.dvv\";\n",mName.c_str());}
	/*controls the wireframe display resolution: num of pts per span*/
	void setCurvePrecision(unsigned char cpr){if(cpr == 4) return; fprintf_s(mFile, "setAttr \".cpr\" %i;\n", cpr);}
	/*controls the wireframe display resolution: num of pts per span*/
	void setCurvePrecision(const UnsignedcharID& cpr){fprintf_s(mFile,"connectAttr \"");cpr.write(mFile);fprintf_s(mFile,"\" \"%s.cpr\";\n",mName.c_str());}
	/*controls the shaded mode display resolution*/
	void setCurvePrecisionShaded(unsigned char cps){if(cps == 1) return; fprintf_s(mFile, "setAttr \".cps\" %i;\n", cps);}
	/*controls the shaded mode display resolution*/
	void setCurvePrecisionShaded(const UnsignedcharID& cps){fprintf_s(mFile,"connectAttr \"");cps.write(mFile);fprintf_s(mFile,"\" \"%s.cps\";\n",mName.c_str());}
	/*Whether the geometry is displayed in full (actual) or hull mode*/
	void setSimplifyMode(unsigned char sm){if(sm == 0) return; fprintf_s(mFile, "setAttr \".sm\" %i;\n", sm);}
	/*Whether the geometry is displayed in full (actual) or hull mode*/
	void setSimplifyMode(const UnsignedcharID& sm){fprintf_s(mFile,"connectAttr \"");sm.write(mFile);fprintf_s(mFile,"\" \"%s.sm\";\n",mName.c_str());}
	/*Hull mode simplification value along U direction*/
	void setSimplifyU(unsigned char smu){if(smu == 1) return; fprintf_s(mFile, "setAttr \".smu\" %i;\n", smu);}
	/*Hull mode simplification value along U direction*/
	void setSimplifyU(const UnsignedcharID& smu){fprintf_s(mFile,"connectAttr \"");smu.write(mFile);fprintf_s(mFile,"\" \"%s.smu\";\n",mName.c_str());}
	/*Hull mode simplification value along V direction*/
	void setSimplifyV(unsigned char smv){if(smv == 1) return; fprintf_s(mFile, "setAttr \".smv\" %i;\n", smv);}
	/*Hull mode simplification value along V direction*/
	void setSimplifyV(const UnsignedcharID& smv){fprintf_s(mFile,"connectAttr \"");smv.write(mFile);fprintf_s(mFile,"\" \"%s.smv\";\n",mName.c_str());}
	/*
	Specifies if the decision to continue tessellation should be
	based on the nurbs edge smoothness
	*/
	void setSmoothEdge(bool ues){if(ues == false) return; fprintf_s(mFile, "setAttr \".ues\" %i;\n", ues);}
	/*
	Specifies if the decision to continue tessellation should be
	based on the nurbs edge smoothness
	*/
	void setSmoothEdge(const BoolID& ues){fprintf_s(mFile,"connectAttr \"");ues.write(mFile);fprintf_s(mFile,"\" \"%s.ues\";\n",mName.c_str());}
	/*
	Specifies the edge smooth ratio.  The higher the value, the
	smoother the edge will be.
	*/
	void setSmoothEdgeRatio(double esr){if(esr == 0.99) return; fprintf_s(mFile, "setAttr \".esr\" %f;\n", esr);}
	/*
	Specifies the edge smooth ratio.  The higher the value, the
	smoother the edge will be.
	*/
	void setSmoothEdgeRatio(const DoubleID& esr){fprintf_s(mFile,"connectAttr \"");esr.write(mFile);fprintf_s(mFile,"\" \"%s.esr\";\n",mName.c_str());}
	/*
	Specifies if the decision to continue tessellation should be
	based on the chord height tolerance value.
	*/
	void setUseChordHeight(bool uch){if(uch == false) return; fprintf_s(mFile, "setAttr \".uch\" %i;\n", uch);}
	/*
	Specifies if the decision to continue tessellation should be
	based on the chord height tolerance value.
	*/
	void setUseChordHeight(const BoolID& uch){fprintf_s(mFile,"connectAttr \"");uch.write(mFile);fprintf_s(mFile,"\" \"%s.uch\";\n",mName.c_str());}
	/*
	Specifies whether chord height should be measured in object space
	(as opposed to world space) when chord height is being used as a
	tessellation criterion.
	*/
	void setObjSpaceChordHeight(bool uco){if(uco == true) return; fprintf_s(mFile, "setAttr \".uco\" %i;\n", uco);}
	/*
	Specifies whether chord height should be measured in object space
	(as opposed to world space) when chord height is being used as a
	tessellation criterion.
	*/
	void setObjSpaceChordHeight(const BoolID& uco){fprintf_s(mFile,"connectAttr \"");uco.write(mFile);fprintf_s(mFile,"\" \"%s.uco\";\n",mName.c_str());}
	/*
	Specifies if the decision to continue tessellation should be based
	on the chord height ratio tolerance value.
	*/
	void setUseChordHeightRatio(bool ucr){if(ucr == true) return; fprintf_s(mFile, "setAttr \".ucr\" %i;\n", ucr);}
	/*
	Specifies if the decision to continue tessellation should be based
	on the chord height ratio tolerance value.
	*/
	void setUseChordHeightRatio(const BoolID& ucr){fprintf_s(mFile,"connectAttr \"");ucr.write(mFile);fprintf_s(mFile,"\" \"%s.ucr\";\n",mName.c_str());}
	/*
	Specifies if we want to examine the tessellation of quads to find
	the best triangles to represent them.
	*/
	void setEdgeSwap(bool es){if(es == false) return; fprintf_s(mFile, "setAttr \".es\" %i;\n", es);}
	/*
	Specifies if we want to examine the tessellation of quads to find
	the best triangles to represent them.
	*/
	void setEdgeSwap(const BoolID& es){fprintf_s(mFile,"connectAttr \"");es.write(mFile);fprintf_s(mFile,"\" \"%s.es\";\n",mName.c_str());}
	/*
	Specifies if the decision to continue tessellation should be
	based on the minimum triangle screen size.
	*/
	void setUseMinScreen(bool uns){if(uns == false) return; fprintf_s(mFile, "setAttr \".uns\" %i;\n", uns);}
	/*
	Specifies if the decision to continue tessellation should be
	based on the minimum triangle screen size.
	*/
	void setUseMinScreen(const BoolID& uns){fprintf_s(mFile,"connectAttr \"");uns.write(mFile);fprintf_s(mFile,"\" \"%s.uns\";\n",mName.c_str());}
	/*Controls selective CV display*/
	void setSelCVDisp(bool scvd){if(scvd == false) return; fprintf_s(mFile, "setAttr \".scvd\" %i;\n", scvd);}
	/*Controls selective CV display*/
	void setSelCVDisp(const BoolID& scvd){fprintf_s(mFile,"connectAttr \"");scvd.write(mFile);fprintf_s(mFile,"\" \"%s.scvd\";\n",mName.c_str());}
	/*Controls explicit CV display*/
	void setDispCV(bool dcv){if(dcv == false) return; fprintf_s(mFile, "setAttr \".dcv\" %i;\n", dcv);}
	/*Controls explicit CV display*/
	void setDispCV(const BoolID& dcv){fprintf_s(mFile,"connectAttr \"");dcv.write(mFile);fprintf_s(mFile,"\" \"%s.dcv\";\n",mName.c_str());}
	/*Controls explicit edit point display*/
	void setDispEP(bool dep){if(dep == false) return; fprintf_s(mFile, "setAttr \".dep\" %i;\n", dep);}
	/*Controls explicit edit point display*/
	void setDispEP(const BoolID& dep){fprintf_s(mFile,"connectAttr \"");dep.write(mFile);fprintf_s(mFile,"\" \"%s.dep\";\n",mName.c_str());}
	/*Controls explicit hull display*/
	void setDispHull(bool dh){if(dh == false) return; fprintf_s(mFile, "setAttr \".dh\" %i;\n", dh);}
	/*Controls explicit hull display*/
	void setDispHull(const BoolID& dh){fprintf_s(mFile,"connectAttr \"");dh.write(mFile);fprintf_s(mFile,"\" \"%s.dh\";\n",mName.c_str());}
	/*Controls explicit geometry display*/
	void setDispGeometry(bool dg){if(dg == true) return; fprintf_s(mFile, "setAttr \".dg\" %i;\n", dg);}
	/*Controls explicit geometry display*/
	void setDispGeometry(const BoolID& dg){fprintf_s(mFile,"connectAttr \"");dg.write(mFile);fprintf_s(mFile,"\" \"%s.dg\";\n",mName.c_str());}
	/*Controls explicit origin display*/
	void setDispOrigin(bool dor){if(dor == false) return; fprintf_s(mFile, "setAttr \".dor\" %i;\n", dor);}
	/*Controls explicit origin display*/
	void setDispOrigin(const BoolID& dor){fprintf_s(mFile,"connectAttr \"");dor.write(mFile);fprintf_s(mFile,"\" \"%s.dor\";\n",mName.c_str());}
	/*
	Specifies the number of initial isoparametric lines to create
	in U to start tessellation.
	*/
	void setNumberU(int nu){if(nu == 3) return; fprintf_s(mFile, "setAttr \".nu\" %i;\n", nu);}
	/*
	Specifies the number of initial isoparametric lines to create
	in U to start tessellation.
	*/
	void setNumberU(const IntID& nu){fprintf_s(mFile,"connectAttr \"");nu.write(mFile);fprintf_s(mFile,"\" \"%s.nu\";\n",mName.c_str());}
	/*
	Specifies the manner in which to distribute the initial
	isoparametric lines in U to start tessellation.
	*/
	void setModeU(unsigned int mu){if(mu == 3) return; fprintf_s(mFile, "setAttr \".mu\" %i;\n", mu);}
	/*
	Specifies the manner in which to distribute the initial
	isoparametric lines in U to start tessellation.
	*/
	void setModeU(const UnsignedintID& mu){fprintf_s(mFile,"connectAttr \"");mu.write(mFile);fprintf_s(mFile,"\" \"%s.mu\";\n",mName.c_str());}
	/*
	Specifies the number of initial isoparametric lines to create
	in V to start tessellation.
	*/
	void setNumberV(int nv){if(nv == 3) return; fprintf_s(mFile, "setAttr \".nv\" %i;\n", nv);}
	/*
	Specifies the number of initial isoparametric lines to create
	in V to start tessellation.
	*/
	void setNumberV(const IntID& nv){fprintf_s(mFile,"connectAttr \"");nv.write(mFile);fprintf_s(mFile,"\" \"%s.nv\";\n",mName.c_str());}
	/*
	Specifies the manner in which to distribute the initial
	isoparametric lines in V to start tessellation.
	*/
	void setModeV(unsigned int mv){if(mv == 3) return; fprintf_s(mFile, "setAttr \".mv\" %i;\n", mv);}
	/*
	Specifies the manner in which to distribute the initial
	isoparametric lines in V to start tessellation.
	*/
	void setModeV(const UnsignedintID& mv){fprintf_s(mFile,"connectAttr \"");mv.write(mFile);fprintf_s(mFile,"\" \"%s.mv\";\n",mName.c_str());}
	/*
	Specifies the maximum distance the center of a tessellated span
	can be from the actual NURBs surface (technically called chord height).
	*/
	void setChordHeight(double ch){if(ch == 0.1) return; fprintf_s(mFile, "setAttr \".ch\" %f;\n", ch);}
	/*
	Specifies the maximum distance the center of a tessellated span
	can be from the actual NURBs surface (technically called chord height).
	*/
	void setChordHeight(const DoubleID& ch){fprintf_s(mFile,"connectAttr \"");ch.write(mFile);fprintf_s(mFile,"\" \"%s.ch\";\n",mName.c_str());}
	/*
	Specifies the maximum ratio between the length of a span and the
	distance the center of that span is from the actual NURBS surface.
	*/
	void setChordHeightRatio(double chr){if(chr == 0.983) return; fprintf_s(mFile, "setAttr \".chr\" %f;\n", chr);}
	/*
	Specifies the maximum ratio between the length of a span and the
	distance the center of that span is from the actual NURBS surface.
	*/
	void setChordHeightRatio(const DoubleID& chr){fprintf_s(mFile,"connectAttr \"");chr.write(mFile);fprintf_s(mFile,"\" \"%s.chr\";\n",mName.c_str());}
	/*
	Specifies the maximum screen size (in pixels) a triangle can be
	for tessellation.
	*/
	void setMinScreen(double mns){if(mns == 14) return; fprintf_s(mFile, "setAttr \".mns\" %f;\n", mns);}
	/*
	Specifies the maximum screen size (in pixels) a triangle can be
	for tessellation.
	*/
	void setMinScreen(const DoubleID& mns){fprintf_s(mFile,"connectAttr \"");mns.write(mFile);fprintf_s(mFile,"\" \"%s.mns\";\n",mName.c_str());}
	/*Form in U (open = 0, closed = 1, periodic = 2)*/
	void setFormU(const UnsignedintID& fu){fprintf_s(mFile,"connectAttr \"");fu.write(mFile);fprintf_s(mFile,"\" \"%s.fu\";\n",mName.c_str());}
	/*Form in V(open = 0, closed = 1, periodic = 2)*/
	void setFormV(const UnsignedintID& fv){fprintf_s(mFile,"connectAttr \"");fv.write(mFile);fprintf_s(mFile,"\" \"%s.fv\";\n",mName.c_str());}
	/*
	Cached surface
	Defines geometry of the surface. The properties are defined in this order:
	First line: degree in U, degree in V, form in U, form in V, rational (yes/no)
	Second line: number of knots in U, list of knot values in U
	Third line: number of knots in V, list of knot values in V
	Fourth line: number of CVs
	Fifth and later lines: CV positions in x,y,z (and w if rational)
	*/
	void setCached(const nurbsSurface& cc){fprintf_s(mFile, "setAttr \".cc\" -type \"nurbsSurface\" ");cc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Cached surface
	Defines geometry of the surface. The properties are defined in this order:
	First line: degree in U, degree in V, form in U, form in V, rational (yes/no)
	Second line: number of knots in U, list of knot values in U
	Third line: number of knots in V, list of knot values in V
	Fourth line: number of CVs
	Fifth and later lines: CV positions in x,y,z (and w if rational)
	*/
	void setCached(const NurbsSurfaceID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.cc\";\n",mName.c_str());}
	/*
	Patch corner UV Ids. Explicit UVs on nurbs surfaces are stored on a
	per-patch per-patchCorner basis. This attribute is used to specify
	the UV ids on a per-patch per-patchCorner for each UV set that exists
	on the surface. The values on this attribute are to be used in
	conjunction with the UVSetPoints attribute defined in the parent
	controlPointShape class, since that attribute holds on to the uv values
	corresponding to these ids.
	*/
	void setPatchUVIds(size_t pu_i,const NurbsPatchUVIdsID& pu){fprintf_s(mFile,"connectAttr \"");pu.write(mFile);fprintf_s(mFile,"\" \"%s.pu[%i]\";\n",mName.c_str(),pu_i);}
	/*In place with history*/
	void setInPlace(bool ipo){if(ipo == false) return; fprintf_s(mFile, "setAttr \".ipo\" %i;\n", ipo);}
	/*In place with history*/
	void setInPlace(const BoolID& ipo){fprintf_s(mFile,"connectAttr \"");ipo.write(mFile);fprintf_s(mFile,"\" \"%s.ipo\";\n",mName.c_str());}
	/*What was the topology in U when we tweaked*/
	void setTweakSizeU(const IntID& tsu){fprintf_s(mFile,"connectAttr \"");tsu.write(mFile);fprintf_s(mFile,"\" \"%s.tsu\";\n",mName.c_str());}
	/*What was the topology in V when we tweaked*/
	void setTweakSizeV(const IntID& tsv){fprintf_s(mFile,"connectAttr \"");tsv.write(mFile);fprintf_s(mFile,"\" \"%s.tsv\";\n",mName.c_str());}
	/*
	Compound attribute holding the minValueU and maxValueU.  See the
	children attributes for explanation.
	*/
	void setMinMaxRangeU(const Double2ID& mmu){fprintf_s(mFile,"connectAttr \"");mmu.write(mFile);fprintf_s(mFile,"\" \"%s.mmu\";\n",mName.c_str());}
	/*U Parameter range min*/
	void setMinValueU(const DoubleID& mnu){fprintf_s(mFile,"connectAttr \"");mnu.write(mFile);fprintf_s(mFile,"\" \"%s.mmu.mnu\";\n",mName.c_str());}
	/*U Parameter range max*/
	void setMaxValueU(const DoubleID& mxu){fprintf_s(mFile,"connectAttr \"");mxu.write(mFile);fprintf_s(mFile,"\" \"%s.mmu.mxu\";\n",mName.c_str());}
	/*
	Compound attribute holding the minValueV and maxValueV.  See the
	children attributes for explanation.
	*/
	void setMinMaxRangeV(const Double2ID& mmv){fprintf_s(mFile,"connectAttr \"");mmv.write(mFile);fprintf_s(mFile,"\" \"%s.mmv\";\n",mName.c_str());}
	/*V Parameter range min*/
	void setMinValueV(const DoubleID& mnv){fprintf_s(mFile,"connectAttr \"");mnv.write(mFile);fprintf_s(mFile,"\" \"%s.mmv.mnv\";\n",mName.c_str());}
	/*V Parameter range max*/
	void setMaxValueV(const DoubleID& mxv){fprintf_s(mFile,"connectAttr \"");mxv.write(mFile);fprintf_s(mFile,"\" \"%s.mmv.mxv\";\n",mName.c_str());}
	/*
	Compound attribute holding the degreeU and degreeV.  See the
	children attributes for explanation.
	*/
	void setDegreeUV(const Short2ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Degree in U*/
	void setDegreeU(const ShortID& du){fprintf_s(mFile,"connectAttr \"");du.write(mFile);fprintf_s(mFile,"\" \"%s.d.du\";\n",mName.c_str());}
	/*Degree in V*/
	void setDegreeV(const ShortID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.d.dv\";\n",mName.c_str());}
	/*
	Compound attribute holding the spansU and spansV.  See the
	children attributes for explanation.
	*/
	void setSpansUV(const Long2ID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*Number of spans in U*/
	void setSpansU(const IntID& su){fprintf_s(mFile,"connectAttr \"");su.write(mFile);fprintf_s(mFile,"\" \"%s.sp.su\";\n",mName.c_str());}
	/*Number of spans in V*/
	void setSpansV(const IntID& sv){fprintf_s(mFile,"connectAttr \"");sv.write(mFile);fprintf_s(mFile,"\" \"%s.sp.sv\";\n",mName.c_str());}
	/*
	Specifies if the rendering tessellation is to be used for
	shaded mode display. This is a UI toggle only.
	*/
	void setDisplayRenderTessellation(bool drt){if(drt == false) return; fprintf_s(mFile, "setAttr \".drt\" %i;\n", drt);}
	/*
	Specifies if the rendering tessellation is to be used for
	shaded mode display. This is a UI toggle only.
	*/
	void setDisplayRenderTessellation(const BoolID& drt){fprintf_s(mFile,"connectAttr \"");drt.write(mFile);fprintf_s(mFile,"\" \"%s.drt\";\n",mName.c_str());}
	/*
	This will return the render tessellation
	triangle count (if known). This is for UI informational purposes only
	*/
	void setRenderTriangleCount(const IntID& tcn){fprintf_s(mFile,"connectAttr \"");tcn.write(mFile);fprintf_s(mFile,"\" \"%s.tcn\";\n",mName.c_str());}
	/*
	Specifies if the rendering needs to use the Chord Length
	Texture Mapping method instead of the default surface
	parameter based.
	*/
	void setFixTextureWarp(bool ftwp){if(ftwp == false) return; fprintf_s(mFile, "setAttr \".ftwp\" %i;\n", ftwp);}
	/*
	Specifies if the rendering needs to use the Chord Length
	Texture Mapping method instead of the default surface
	parameter based.
	*/
	void setFixTextureWarp(const BoolID& ftwp){fprintf_s(mFile,"connectAttr \"");ftwp.write(mFile);fprintf_s(mFile,"\" \"%s.ftwp\";\n",mName.c_str());}
	/*
	Specifies the number of divisions per span of the ChordLength grid
	along the u param
	*/
	void setGridDivisionPerSpanU(short gdsu){if(gdsu == 4) return; fprintf_s(mFile, "setAttr \".gdsu\" %i;\n", gdsu);}
	/*
	Specifies the number of divisions per span of the ChordLength grid
	along the u param
	*/
	void setGridDivisionPerSpanU(const ShortID& gdsu){fprintf_s(mFile,"connectAttr \"");gdsu.write(mFile);fprintf_s(mFile,"\" \"%s.gdsu\";\n",mName.c_str());}
	/*
	Specifies the number of divisions per span of the ChordLength grid
	along the v param
	*/
	void setGridDivisionPerSpanV(short gdsv){if(gdsv == 4) return; fprintf_s(mFile, "setAttr \".gdsv\" %i;\n", gdsv);}
	/*
	Specifies the number of divisions per span of the ChordLength grid
	along the v param
	*/
	void setGridDivisionPerSpanV(const ShortID& gdsv){fprintf_s(mFile,"connectAttr \"");gdsv.write(mFile);fprintf_s(mFile,"\" \"%s.gdsv\";\n",mName.c_str());}
	/*specify advanced or novice mode for tessellation parameters*/
	void setExplicitTessellationAttributes(bool eta){if(eta == false) return; fprintf_s(mFile, "setAttr \".eta\" %i;\n", eta);}
	/*specify advanced or novice mode for tessellation parameters*/
	void setExplicitTessellationAttributes(const BoolID& eta){fprintf_s(mFile,"connectAttr \"");eta.write(mFile);fprintf_s(mFile,"\" \"%s.eta\";\n",mName.c_str());}
	/*Specifies the tessellation increase factor in U for novice mode*/
	void setUDivisionsFactor(double nufa){if(nufa == 1.5) return; fprintf_s(mFile, "setAttr \".nufa\" %f;\n", nufa);}
	/*Specifies the tessellation increase factor in U for novice mode*/
	void setUDivisionsFactor(const DoubleID& nufa){fprintf_s(mFile,"connectAttr \"");nufa.write(mFile);fprintf_s(mFile,"\" \"%s.nufa\";\n",mName.c_str());}
	/*Specifies the tessellation increase factor in V for novice mode*/
	void setVDivisionsFactor(double nvfa){if(nvfa == 1.5) return; fprintf_s(mFile, "setAttr \".nvfa\" %f;\n", nvfa);}
	/*Specifies the tessellation increase factor in V for novice mode*/
	void setVDivisionsFactor(const DoubleID& nvfa){fprintf_s(mFile,"connectAttr \"");nvfa.write(mFile);fprintf_s(mFile,"\" \"%s.nvfa\";\n",mName.c_str());}
	/*
	Presets for level of secondary criteria curvature tolerance:
	0 = highest tolerance, 1 = high tolerance, 2 = medium tolerance,
	3 = no tolerance
	*/
	void setCurvatureTolerance(unsigned int cvto){if(cvto == 2) return; fprintf_s(mFile, "setAttr \".cvto\" %i;\n", cvto);}
	/*
	Presets for level of secondary criteria curvature tolerance:
	0 = highest tolerance, 1 = high tolerance, 2 = medium tolerance,
	3 = no tolerance
	*/
	void setCurvatureTolerance(const UnsignedintID& cvto){fprintf_s(mFile,"connectAttr \"");cvto.write(mFile);fprintf_s(mFile,"\" \"%s.cvto\";\n",mName.c_str());}
	/*
	Specify the space to use for novice tessellation. Object space
	will give constant tessellation between frames, whereas screen
	space tessellation will vary as the distance between the geometry
	and the camera changes. Surfaces which are far from the camera
	will be tesselated more coarsely than surfaces close to the
	camera. The screen based tessellation can be better render times
	or tessellation quality; but shading artifacts may be exhibited
	between frames when the tessellation changes. A highly reflective
	surface is one case where problems may be observed.
	*/
	void setBasicTessellationType(unsigned int btt){if(btt == 0) return; fprintf_s(mFile, "setAttr \".btt\" %i;\n", btt);}
	/*
	Specify the space to use for novice tessellation. Object space
	will give constant tessellation between frames, whereas screen
	space tessellation will vary as the distance between the geometry
	and the camera changes. Surfaces which are far from the camera
	will be tesselated more coarsely than surfaces close to the
	camera. The screen based tessellation can be better render times
	or tessellation quality; but shading artifacts may be exhibited
	between frames when the tessellation changes. A highly reflective
	surface is one case where problems may be observed.
	*/
	void setBasicTessellationType(const UnsignedintID& btt){fprintf_s(mFile,"connectAttr \"");btt.write(mFile);fprintf_s(mFile,"\" \"%s.btt\";\n",mName.c_str());}
	/*Controls explicit surface face display*/
	void setDispSF(bool dsf){if(dsf == false) return; fprintf_s(mFile, "setAttr \".dsf\" %i;\n", dsf);}
	/*Controls explicit surface face display*/
	void setDispSF(const BoolID& dsf){fprintf_s(mFile,"connectAttr \"");dsf.write(mFile);fprintf_s(mFile,"\" \"%s.dsf\";\n",mName.c_str());}
	/*Specifies the scaling factor for the surface normal display.*/
	void setNormalsDisplayScale(double ndf){if(ndf == 1.0) return; fprintf_s(mFile, "setAttr \".ndf\" %f;\n", ndf);}
	/*Specifies the scaling factor for the surface normal display.*/
	void setNormalsDisplayScale(const DoubleID& ndf){fprintf_s(mFile,"connectAttr \"");ndf.write(mFile);fprintf_s(mFile,"\" \"%s.ndf\";\n",mName.c_str());}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(bool oca){if(oca == false) return; fprintf_s(mFile, "setAttr \".mrc.oca\" %i;\n", oca);}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(const BoolID& oca){fprintf_s(mFile,"connectAttr \"");oca.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oca\";\n",mName.c_str());}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(short caa){if(caa == 64) return; fprintf_s(mFile, "setAttr \".mrc.caa\" %i;\n", caa);}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(const ShortID& caa){fprintf_s(mFile,"connectAttr \"");caa.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.caa\";\n",mName.c_str());}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(float car){if(car == 0) return; fprintf_s(mFile, "setAttr \".mrc.car\" %f;\n", car);}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(const FloatID& car){fprintf_s(mFile,"connectAttr \"");car.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.car\";\n",mName.c_str());}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(bool ogi){if(ogi == false) return; fprintf_s(mFile, "setAttr \".mrc.ogi\" %i;\n", ogi);}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(const BoolID& ogi){fprintf_s(mFile,"connectAttr \"");ogi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ogi\";\n",mName.c_str());}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(short gia){if(gia == 64) return; fprintf_s(mFile, "setAttr \".mrc.gia\" %i;\n", gia);}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(const ShortID& gia){fprintf_s(mFile,"connectAttr \"");gia.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gia\";\n",mName.c_str());}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(float gir){if(gir == 0) return; fprintf_s(mFile, "setAttr \".mrc.gir\" %f;\n", gir);}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(const FloatID& gir){fprintf_s(mFile,"connectAttr \"");gir.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gir\";\n",mName.c_str());}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(bool ofg){if(ofg == false) return; fprintf_s(mFile, "setAttr \".mrc.ofg\" %i;\n", ofg);}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(const BoolID& ofg){fprintf_s(mFile,"connectAttr \"");ofg.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ofg\";\n",mName.c_str());}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(int fry){if(fry == 1000) return; fprintf_s(mFile, "setAttr \".mrc.fry\" %i;\n", fry);}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(const IntID& fry){fprintf_s(mFile,"connectAttr \"");fry.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fry\";\n",mName.c_str());}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(float fmn){if(fmn == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmn\" %f;\n", fmn);}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(const FloatID& fmn){fprintf_s(mFile,"connectAttr \"");fmn.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmn\";\n",mName.c_str());}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(float fmx){if(fmx == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmx\" %f;\n", fmx);}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(const FloatID& fmx){fprintf_s(mFile,"connectAttr \"");fmx.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmx\";\n",mName.c_str());}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(short ffi){if(ffi == 1) return; fprintf_s(mFile, "setAttr \".mrc.ffi\" %i;\n", ffi);}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(const ShortID& ffi){fprintf_s(mFile,"connectAttr \"");ffi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ffi\";\n",mName.c_str());}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(bool fgv){if(fgv == false) return; fprintf_s(mFile, "setAttr \".mrc.fgv\" %i;\n", fgv);}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(const BoolID& fgv){fprintf_s(mFile,"connectAttr \"");fgv.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgv\";\n",mName.c_str());}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	void setMiOverrideSamples(bool oos){if(oos == false) return; fprintf_s(mFile, "setAttr \".mrc.oos\" %i;\n", oos);}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	void setMiOverrideSamples(const BoolID& oos){fprintf_s(mFile,"connectAttr \"");oos.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oos\";\n",mName.c_str());}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(short mins){if(mins == 0) return; fprintf_s(mFile, "setAttr \".mrc.mins\" %i;\n", mins);}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(const ShortID& mins){fprintf_s(mFile,"connectAttr \"");mins.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mins\";\n",mName.c_str());}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(short maxs){if(maxs == 2) return; fprintf_s(mFile, "setAttr \".mrc.maxs\" %i;\n", maxs);}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(const ShortID& maxs){fprintf_s(mFile,"connectAttr \"");maxs.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.maxs\";\n",mName.c_str());}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	void setMiFinalGatherCast(bool fgc){if(fgc == true) return; fprintf_s(mFile, "setAttr \".mrc.fgc\" %i;\n", fgc);}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	void setMiFinalGatherCast(const BoolID& fgc){fprintf_s(mFile,"connectAttr \"");fgc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgc\";\n",mName.c_str());}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	void setMiFinalGatherReceive(bool fge){if(fge == true) return; fprintf_s(mFile, "setAttr \".mrc.fge\" %i;\n", fge);}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	void setMiFinalGatherReceive(const BoolID& fge){fprintf_s(mFile,"connectAttr \"");fge.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fge\";\n",mName.c_str());}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	void setMiTransparencyCast(bool tpc){if(tpc == true) return; fprintf_s(mFile, "setAttr \".mrc.tpc\" %i;\n", tpc);}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	void setMiTransparencyCast(const BoolID& tpc){fprintf_s(mFile,"connectAttr \"");tpc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.tpc\";\n",mName.c_str());}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	void setMiTransparencyReceive(bool tpr){if(tpr == true) return; fprintf_s(mFile, "setAttr \".mrc.tpr\" %i;\n", tpr);}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	void setMiTransparencyReceive(const BoolID& tpr){fprintf_s(mFile,"connectAttr \"");tpr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.tpr\";\n",mName.c_str());}
	/*
	The object receives reflection rays if <b>miReflectionReceive</b> is on.
	This flag controls reflection of other objects on this object.
	If disabled, this object will not show any reflection,
	as if the surface is not reflective.
	The casting behaviour is ruled by visibleInReflections flag,
	which controls reflection of this object on other objects.
	Disabling <b>visibleInReflections</b> will make this object
	disappera from reflection.
	*/
	void setMiReflectionReceive(bool rflr){if(rflr == true) return; fprintf_s(mFile, "setAttr \".mrc.rflr\" %i;\n", rflr);}
	/*
	The object receives reflection rays if <b>miReflectionReceive</b> is on.
	This flag controls reflection of other objects on this object.
	If disabled, this object will not show any reflection,
	as if the surface is not reflective.
	The casting behaviour is ruled by visibleInReflections flag,
	which controls reflection of this object on other objects.
	Disabling <b>visibleInReflections</b> will make this object
	disappera from reflection.
	*/
	void setMiReflectionReceive(const BoolID& rflr){fprintf_s(mFile,"connectAttr \"");rflr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.rflr\";\n",mName.c_str());}
	/*
	The object receives refraction rays if <b>miRefractionReceive</b> is on.
	This flag contols refraction of other objects through this object.
	Disabling this value will make this object non-refractive.
	The casting behaviour is ruled by visibleInRefractions flag,
	which controls refraction of this object showing through other objects.
	Disabling <b>visibleInRefractions</b> will make this object disappear
	from refraction.
	*/
	void setMiRefractionReceive(bool rfrr){if(rfrr == true) return; fprintf_s(mFile, "setAttr \".mrc.rfrr\" %i;\n", rfrr);}
	/*
	The object receives refraction rays if <b>miRefractionReceive</b> is on.
	This flag contols refraction of other objects through this object.
	Disabling this value will make this object non-refractive.
	The casting behaviour is ruled by visibleInRefractions flag,
	which controls refraction of this object showing through other objects.
	Disabling <b>visibleInRefractions</b> will make this object disappear
	from refraction.
	*/
	void setMiRefractionReceive(const BoolID& rfrr){fprintf_s(mFile,"connectAttr \"");rfrr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.rfrr\";\n",mName.c_str());}
	/*
	Create in local space.  Construction history operations put the result
	in this attribute.
	*/
	NurbsSurfaceID getCreate(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*Surface in local space to be used in subsequent operations*/
	NurbsSurfaceID getLocal(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*
	Surface in world space (indexed by the instance number) to be used
	in subsequent operations
	*/
	const NurbsSurfaceID& getWorldSpace(size_t ws_i){char buffer[4096];sprintf_s (buffer, "%s.ws[%i]",mName.c_str(),ws_i);return (const char*)buffer;}
	/*controls the num of divisions per span along U*/
	UnsignedcharID getDivisionsU(){char buffer[4096];sprintf_s (buffer, "%s.dvu",mName.c_str());return (const char*)buffer;}
	/*controls the num of divisions per span along V*/
	UnsignedcharID getDivisionsV(){char buffer[4096];sprintf_s (buffer, "%s.dvv",mName.c_str());return (const char*)buffer;}
	/*controls the wireframe display resolution: num of pts per span*/
	UnsignedcharID getCurvePrecision(){char buffer[4096];sprintf_s (buffer, "%s.cpr",mName.c_str());return (const char*)buffer;}
	/*controls the shaded mode display resolution*/
	UnsignedcharID getCurvePrecisionShaded(){char buffer[4096];sprintf_s (buffer, "%s.cps",mName.c_str());return (const char*)buffer;}
	/*Whether the geometry is displayed in full (actual) or hull mode*/
	UnsignedcharID getSimplifyMode(){char buffer[4096];sprintf_s (buffer, "%s.sm",mName.c_str());return (const char*)buffer;}
	/*Hull mode simplification value along U direction*/
	UnsignedcharID getSimplifyU(){char buffer[4096];sprintf_s (buffer, "%s.smu",mName.c_str());return (const char*)buffer;}
	/*Hull mode simplification value along V direction*/
	UnsignedcharID getSimplifyV(){char buffer[4096];sprintf_s (buffer, "%s.smv",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if the decision to continue tessellation should be
	based on the nurbs edge smoothness
	*/
	BoolID getSmoothEdge(){char buffer[4096];sprintf_s (buffer, "%s.ues",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the edge smooth ratio.  The higher the value, the
	smoother the edge will be.
	*/
	DoubleID getSmoothEdgeRatio(){char buffer[4096];sprintf_s (buffer, "%s.esr",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if the decision to continue tessellation should be
	based on the chord height tolerance value.
	*/
	BoolID getUseChordHeight(){char buffer[4096];sprintf_s (buffer, "%s.uch",mName.c_str());return (const char*)buffer;}
	/*
	Specifies whether chord height should be measured in object space
	(as opposed to world space) when chord height is being used as a
	tessellation criterion.
	*/
	BoolID getObjSpaceChordHeight(){char buffer[4096];sprintf_s (buffer, "%s.uco",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if the decision to continue tessellation should be based
	on the chord height ratio tolerance value.
	*/
	BoolID getUseChordHeightRatio(){char buffer[4096];sprintf_s (buffer, "%s.ucr",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if we want to examine the tessellation of quads to find
	the best triangles to represent them.
	*/
	BoolID getEdgeSwap(){char buffer[4096];sprintf_s (buffer, "%s.es",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if the decision to continue tessellation should be
	based on the minimum triangle screen size.
	*/
	BoolID getUseMinScreen(){char buffer[4096];sprintf_s (buffer, "%s.uns",mName.c_str());return (const char*)buffer;}
	/*Controls selective CV display*/
	BoolID getSelCVDisp(){char buffer[4096];sprintf_s (buffer, "%s.scvd",mName.c_str());return (const char*)buffer;}
	/*Controls explicit CV display*/
	BoolID getDispCV(){char buffer[4096];sprintf_s (buffer, "%s.dcv",mName.c_str());return (const char*)buffer;}
	/*Controls explicit edit point display*/
	BoolID getDispEP(){char buffer[4096];sprintf_s (buffer, "%s.dep",mName.c_str());return (const char*)buffer;}
	/*Controls explicit hull display*/
	BoolID getDispHull(){char buffer[4096];sprintf_s (buffer, "%s.dh",mName.c_str());return (const char*)buffer;}
	/*Controls explicit geometry display*/
	BoolID getDispGeometry(){char buffer[4096];sprintf_s (buffer, "%s.dg",mName.c_str());return (const char*)buffer;}
	/*Controls explicit origin display*/
	BoolID getDispOrigin(){char buffer[4096];sprintf_s (buffer, "%s.dor",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the number of initial isoparametric lines to create
	in U to start tessellation.
	*/
	IntID getNumberU(){char buffer[4096];sprintf_s (buffer, "%s.nu",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the manner in which to distribute the initial
	isoparametric lines in U to start tessellation.
	*/
	UnsignedintID getModeU(){char buffer[4096];sprintf_s (buffer, "%s.mu",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the number of initial isoparametric lines to create
	in V to start tessellation.
	*/
	IntID getNumberV(){char buffer[4096];sprintf_s (buffer, "%s.nv",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the manner in which to distribute the initial
	isoparametric lines in V to start tessellation.
	*/
	UnsignedintID getModeV(){char buffer[4096];sprintf_s (buffer, "%s.mv",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the maximum distance the center of a tessellated span
	can be from the actual NURBs surface (technically called chord height).
	*/
	DoubleID getChordHeight(){char buffer[4096];sprintf_s (buffer, "%s.ch",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the maximum ratio between the length of a span and the
	distance the center of that span is from the actual NURBS surface.
	*/
	DoubleID getChordHeightRatio(){char buffer[4096];sprintf_s (buffer, "%s.chr",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the maximum screen size (in pixels) a triangle can be
	for tessellation.
	*/
	DoubleID getMinScreen(){char buffer[4096];sprintf_s (buffer, "%s.mns",mName.c_str());return (const char*)buffer;}
	/*Form in U (open = 0, closed = 1, periodic = 2)*/
	UnsignedintID getFormU(){char buffer[4096];sprintf_s (buffer, "%s.fu",mName.c_str());return (const char*)buffer;}
	/*Form in V(open = 0, closed = 1, periodic = 2)*/
	UnsignedintID getFormV(){char buffer[4096];sprintf_s (buffer, "%s.fv",mName.c_str());return (const char*)buffer;}
	/*
	Cached surface
	Defines geometry of the surface. The properties are defined in this order:
	First line: degree in U, degree in V, form in U, form in V, rational (yes/no)
	Second line: number of knots in U, list of knot values in U
	Third line: number of knots in V, list of knot values in V
	Fourth line: number of CVs
	Fifth and later lines: CV positions in x,y,z (and w if rational)
	*/
	NurbsSurfaceID getCached(){char buffer[4096];sprintf_s (buffer, "%s.cc",mName.c_str());return (const char*)buffer;}
	/*
	Patch corner UV Ids. Explicit UVs on nurbs surfaces are stored on a
	per-patch per-patchCorner basis. This attribute is used to specify
	the UV ids on a per-patch per-patchCorner for each UV set that exists
	on the surface. The values on this attribute are to be used in
	conjunction with the UVSetPoints attribute defined in the parent
	controlPointShape class, since that attribute holds on to the uv values
	corresponding to these ids.
	*/
	const NurbsPatchUVIdsID& getPatchUVIds(size_t pu_i){char buffer[4096];sprintf_s (buffer, "%s.pu[%i]",mName.c_str(),pu_i);return (const char*)buffer;}
	/*In place with history*/
	BoolID getInPlace(){char buffer[4096];sprintf_s (buffer, "%s.ipo",mName.c_str());return (const char*)buffer;}
	/*What was the topology in U when we tweaked*/
	IntID getTweakSizeU(){char buffer[4096];sprintf_s (buffer, "%s.tsu",mName.c_str());return (const char*)buffer;}
	/*What was the topology in V when we tweaked*/
	IntID getTweakSizeV(){char buffer[4096];sprintf_s (buffer, "%s.tsv",mName.c_str());return (const char*)buffer;}
	/*
	Compound attribute holding the minValueU and maxValueU.  See the
	children attributes for explanation.
	*/
	Double2ID getMinMaxRangeU(){char buffer[4096];sprintf_s (buffer, "%s.mmu",mName.c_str());return (const char*)buffer;}
	/*U Parameter range min*/
	DoubleID getMinValueU(){char buffer[4096];sprintf_s (buffer, "%s.mmu.mnu",mName.c_str());return (const char*)buffer;}
	/*U Parameter range max*/
	DoubleID getMaxValueU(){char buffer[4096];sprintf_s (buffer, "%s.mmu.mxu",mName.c_str());return (const char*)buffer;}
	/*
	Compound attribute holding the minValueV and maxValueV.  See the
	children attributes for explanation.
	*/
	Double2ID getMinMaxRangeV(){char buffer[4096];sprintf_s (buffer, "%s.mmv",mName.c_str());return (const char*)buffer;}
	/*V Parameter range min*/
	DoubleID getMinValueV(){char buffer[4096];sprintf_s (buffer, "%s.mmv.mnv",mName.c_str());return (const char*)buffer;}
	/*V Parameter range max*/
	DoubleID getMaxValueV(){char buffer[4096];sprintf_s (buffer, "%s.mmv.mxv",mName.c_str());return (const char*)buffer;}
	/*
	Compound attribute holding the degreeU and degreeV.  See the
	children attributes for explanation.
	*/
	Short2ID getDegreeUV(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Degree in U*/
	ShortID getDegreeU(){char buffer[4096];sprintf_s (buffer, "%s.d.du",mName.c_str());return (const char*)buffer;}
	/*Degree in V*/
	ShortID getDegreeV(){char buffer[4096];sprintf_s (buffer, "%s.d.dv",mName.c_str());return (const char*)buffer;}
	/*
	Compound attribute holding the spansU and spansV.  See the
	children attributes for explanation.
	*/
	Long2ID getSpansUV(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*Number of spans in U*/
	IntID getSpansU(){char buffer[4096];sprintf_s (buffer, "%s.sp.su",mName.c_str());return (const char*)buffer;}
	/*Number of spans in V*/
	IntID getSpansV(){char buffer[4096];sprintf_s (buffer, "%s.sp.sv",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if the rendering tessellation is to be used for
	shaded mode display. This is a UI toggle only.
	*/
	BoolID getDisplayRenderTessellation(){char buffer[4096];sprintf_s (buffer, "%s.drt",mName.c_str());return (const char*)buffer;}
	/*
	This will return the render tessellation
	triangle count (if known). This is for UI informational purposes only
	*/
	IntID getRenderTriangleCount(){char buffer[4096];sprintf_s (buffer, "%s.tcn",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if the rendering needs to use the Chord Length
	Texture Mapping method instead of the default surface
	parameter based.
	*/
	BoolID getFixTextureWarp(){char buffer[4096];sprintf_s (buffer, "%s.ftwp",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the number of divisions per span of the ChordLength grid
	along the u param
	*/
	ShortID getGridDivisionPerSpanU(){char buffer[4096];sprintf_s (buffer, "%s.gdsu",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the number of divisions per span of the ChordLength grid
	along the v param
	*/
	ShortID getGridDivisionPerSpanV(){char buffer[4096];sprintf_s (buffer, "%s.gdsv",mName.c_str());return (const char*)buffer;}
	/*specify advanced or novice mode for tessellation parameters*/
	BoolID getExplicitTessellationAttributes(){char buffer[4096];sprintf_s (buffer, "%s.eta",mName.c_str());return (const char*)buffer;}
	/*Specifies the tessellation increase factor in U for novice mode*/
	DoubleID getUDivisionsFactor(){char buffer[4096];sprintf_s (buffer, "%s.nufa",mName.c_str());return (const char*)buffer;}
	/*Specifies the tessellation increase factor in V for novice mode*/
	DoubleID getVDivisionsFactor(){char buffer[4096];sprintf_s (buffer, "%s.nvfa",mName.c_str());return (const char*)buffer;}
	/*
	Presets for level of secondary criteria curvature tolerance:
	0 = highest tolerance, 1 = high tolerance, 2 = medium tolerance,
	3 = no tolerance
	*/
	UnsignedintID getCurvatureTolerance(){char buffer[4096];sprintf_s (buffer, "%s.cvto",mName.c_str());return (const char*)buffer;}
	/*
	Specify the space to use for novice tessellation. Object space
	will give constant tessellation between frames, whereas screen
	space tessellation will vary as the distance between the geometry
	and the camera changes. Surfaces which are far from the camera
	will be tesselated more coarsely than surfaces close to the
	camera. The screen based tessellation can be better render times
	or tessellation quality; but shading artifacts may be exhibited
	between frames when the tessellation changes. A highly reflective
	surface is one case where problems may be observed.
	*/
	UnsignedintID getBasicTessellationType(){char buffer[4096];sprintf_s (buffer, "%s.btt",mName.c_str());return (const char*)buffer;}
	/*Controls explicit surface face display*/
	BoolID getDispSF(){char buffer[4096];sprintf_s (buffer, "%s.dsf",mName.c_str());return (const char*)buffer;}
	/*Specifies the scaling factor for the surface normal display.*/
	DoubleID getNormalsDisplayScale(){char buffer[4096];sprintf_s (buffer, "%s.ndf",mName.c_str());return (const char*)buffer;}
	/*This is a root of following mental ray attributes.*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideCaustics(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oca",mName.c_str());return (const char*)buffer;}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	ShortID getMiCausticAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.caa",mName.c_str());return (const char*)buffer;}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	FloatID getMiCausticRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.car",mName.c_str());return (const char*)buffer;}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideGlobalIllumination(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ogi",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	ShortID getMiGlobillumAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gia",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	FloatID getMiGlobillumRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gir",mName.c_str());return (const char*)buffer;}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideFinalGather(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ofg",mName.c_str());return (const char*)buffer;}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	IntID getMiFinalGatherRays(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fry",mName.c_str());return (const char*)buffer;}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMinRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmn",mName.c_str());return (const char*)buffer;}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMaxRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmx",mName.c_str());return (const char*)buffer;}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	ShortID getMiFinalGatherFilter(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ffi",mName.c_str());return (const char*)buffer;}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	BoolID getMiFinalGatherView(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgv",mName.c_str());return (const char*)buffer;}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	BoolID getMiOverrideSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oos",mName.c_str());return (const char*)buffer;}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	ShortID getMiMinSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mins",mName.c_str());return (const char*)buffer;}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	ShortID getMiMaxSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.maxs",mName.c_str());return (const char*)buffer;}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	BoolID getMiFinalGatherCast(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgc",mName.c_str());return (const char*)buffer;}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	BoolID getMiFinalGatherReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fge",mName.c_str());return (const char*)buffer;}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	BoolID getMiTransparencyCast(){char buffer[4096];sprintf_s (buffer, "%s.mrc.tpc",mName.c_str());return (const char*)buffer;}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	BoolID getMiTransparencyReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.tpr",mName.c_str());return (const char*)buffer;}
	/*
	The object receives reflection rays if <b>miReflectionReceive</b> is on.
	This flag controls reflection of other objects on this object.
	If disabled, this object will not show any reflection,
	as if the surface is not reflective.
	The casting behaviour is ruled by visibleInReflections flag,
	which controls reflection of this object on other objects.
	Disabling <b>visibleInReflections</b> will make this object
	disappera from reflection.
	*/
	BoolID getMiReflectionReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.rflr",mName.c_str());return (const char*)buffer;}
	/*
	The object receives refraction rays if <b>miRefractionReceive</b> is on.
	This flag contols refraction of other objects through this object.
	Disabling this value will make this object non-refractive.
	The casting behaviour is ruled by visibleInRefractions flag,
	which controls refraction of this object showing through other objects.
	Disabling <b>visibleInRefractions</b> will make this object disappear
	from refraction.
	*/
	BoolID getMiRefractionReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.rfrr",mName.c_str());return (const char*)buffer;}
protected:
	NurbsSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SurfaceShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NURBSSURFACE_H__
