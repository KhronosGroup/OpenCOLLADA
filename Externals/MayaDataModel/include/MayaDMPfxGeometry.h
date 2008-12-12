/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PFXGEOMETRY_H__
#define __MayaDM_PFXGEOMETRY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
<p><pre>
        This node contains attributes
        that are common to all pfx shape nodes.
        It cannot be used directly, but rather should be derived from.

</pre></p>
*/
class PfxGeometry : public Shape
{
public:
public:
	PfxGeometry(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "pfxGeometry"){}
	virtual ~PfxGeometry(){}
	/*percentage of particles to display for interactive draw*/
	void setDisplayPercent(double dpc){if(dpc == 0.0) return; fprintf_s(mFile, "setAttr \".dpc\" %f;\n", dpc);}
	/*percentage of particles to display for interactive draw*/
	void setDisplayPercent(const DoubleID& dpc){fprintf_s(mFile,"connectAttr \"");dpc.write(mFile);fprintf_s(mFile,"\" \"%s.dpc\";\n",mName.c_str());}
	/*
	if ON, then the stroke is displayed in the modeling views
	as a quad mesh and the tube shape and thickness can be seen.
	Otherwise it is displayed by lines running down the
	center spine of each tube. Note that the quad mesh is only an
	accurate preview if the brushType is Mesh, otherwise it may
	differ somewhat from the final rendered look.
	*/
	void setDrawAsMesh(bool dam){if(dam == 1) return; fprintf_s(mFile, "setAttr \".dam\" %i;\n", dam);}
	/*
	if ON, then the stroke is displayed in the modeling views
	as a quad mesh and the tube shape and thickness can be seen.
	Otherwise it is displayed by lines running down the
	center spine of each tube. Note that the quad mesh is only an
	accurate preview if the brushType is Mesh, otherwise it may
	differ somewhat from the final rendered look.
	*/
	void setDrawAsMesh(const BoolID& dam){fprintf_s(mFile,"connectAttr \"");dam.write(mFile);fprintf_s(mFile,"\" \"%s.dam\";\n",mName.c_str());}
	/*seed for randomization of stroke*/
	void setSeed(int sed){if(sed == 0) return; fprintf_s(mFile, "setAttr \".sed\" %i;\n", sed);}
	/*seed for randomization of stroke*/
	void setSeed(const IntID& sed){fprintf_s(mFile,"connectAttr \"");sed.write(mFile);fprintf_s(mFile,"\" \"%s.sed\";\n",mName.c_str());}
	/*determines order of draw, lower numbers are drawn first*/
	void setDrawOrder(int dro){if(dro == 0) return; fprintf_s(mFile, "setAttr \".dro\" %i;\n", dro);}
	/*determines order of draw, lower numbers are drawn first*/
	void setDrawOrder(const IntID& dro){fprintf_s(mFile,"connectAttr \"");dro.write(mFile);fprintf_s(mFile,"\" \"%s.dro\";\n",mName.c_str());}
	/*offset of stroke from construction surface along normal*/
	void setSurfaceOffset(double sof){if(sof == 0.0) return; fprintf_s(mFile, "setAttr \".sof\" %f;\n", sof);}
	/*offset of stroke from construction surface along normal*/
	void setSurfaceOffset(const DoubleID& sof){fprintf_s(mFile,"connectAttr \"");sof.write(mFile);fprintf_s(mFile,"\" \"%s.sof\";\n",mName.c_str());}
	/*Input from brush node*/
	void setBrush(const DynBrushID& brs){fprintf_s(mFile,"connectAttr \"");brs.write(mFile);fprintf_s(mFile,"\" \"%s.brs\";\n",mName.c_str());}
	/*if ON, then the stroke is motion blurred*/
	void setMotionBlurred(bool mblr){if(mblr == 1) return; fprintf_s(mFile, "setAttr \".mblr\" %i;\n", mblr);}
	/*if ON, then the stroke is motion blurred*/
	void setMotionBlurred(const BoolID& mblr){fprintf_s(mFile,"connectAttr \"");mblr.write(mFile);fprintf_s(mFile,"\" \"%s.mblr\";\n",mName.c_str());}
	/*Does this stroke appear in shadow casts and rendering (TRUE) or only in shadow casts (FALSE).*/
	void setPrimaryVisibility(bool pvs){if(pvs == 1) return; fprintf_s(mFile, "setAttr \".pvs\" %i;\n", pvs);}
	/*Does this stroke appear in shadow casts and rendering (TRUE) or only in shadow casts (FALSE).*/
	void setPrimaryVisibility(const BoolID& pvs){fprintf_s(mFile,"connectAttr \"");pvs.write(mFile);fprintf_s(mFile,"\" \"%s.pvs\";\n",mName.c_str());}
	/*curve to use as follow path and/or force*/
	void setControlCurve(size_t clc_i,const GenericID& clc){fprintf_s(mFile,"connectAttr \"");clc.write(mFile);fprintf_s(mFile,"\" \"%s.clc[%i]\";\n",mName.c_str(),clc_i);}
	/*Output branch and twig surface.*/
	void setOutMainMesh(const MeshID& omm){fprintf_s(mFile,"connectAttr \"");omm.write(mFile);fprintf_s(mFile,"\" \"%s.omm\";\n",mName.c_str());}
	/*Output flower surface.*/
	void setOutFlowerMesh(const MeshID& ofm){fprintf_s(mFile,"connectAttr \"");ofm.write(mFile);fprintf_s(mFile,"\" \"%s.ofm\";\n",mName.c_str());}
	/*Output leaf surface.*/
	void setOutLeafMesh(const MeshID& olm){fprintf_s(mFile,"connectAttr \"");olm.write(mFile);fprintf_s(mFile,"\" \"%s.olm\";\n",mName.c_str());}
	/*Output world space branch and twig surfaces*/
	void setWorldMainMesh(size_t wmm_i,const MeshID& wmm){fprintf_s(mFile,"connectAttr \"");wmm.write(mFile);fprintf_s(mFile,"\" \"%s.wmm[%i]\";\n",mName.c_str(),wmm_i);}
	/*Output world space leaf surfaces*/
	void setWorldLeafMesh(size_t wlm_i,const MeshID& wlm){fprintf_s(mFile,"connectAttr \"");wlm.write(mFile);fprintf_s(mFile,"\" \"%s.wlm[%i]\";\n",mName.c_str(),wlm_i);}
	/*Output world space flower surfaces*/
	void setWorldFlowerMesh(size_t wfm_i,const MeshID& wfm){fprintf_s(mFile,"connectAttr \"");wfm.write(mFile);fprintf_s(mFile,"\" \"%s.wfm[%i]\";\n",mName.c_str(),wfm_i);}
	/*
	Number of verts created the last time the main body
	of this stroke was converted to poly. Used to predict
	amount of memory to prealloc the next time
	*/
	void setMainVertBufSize(int mvbs){if(mvbs == 0) return; fprintf_s(mFile, "setAttr \".mvbs\" %i;\n", mvbs);}
	/*
	Number of verts created the last time the main body
	of this stroke was converted to poly. Used to predict
	amount of memory to prealloc the next time
	*/
	void setMainVertBufSize(const IntID& mvbs){fprintf_s(mFile,"connectAttr \"");mvbs.write(mFile);fprintf_s(mFile,"\" \"%s.mvbs\";\n",mName.c_str());}
	/*
	Number of verts created the last time these flowers
	were converted to poly. Used to predict amount of
	memory to prealloc the next time
	*/
	void setFlowerVertBufSize(int fvbs){if(fvbs == 0) return; fprintf_s(mFile, "setAttr \".fvbs\" %i;\n", fvbs);}
	/*
	Number of verts created the last time these flowers
	were converted to poly. Used to predict amount of
	memory to prealloc the next time
	*/
	void setFlowerVertBufSize(const IntID& fvbs){fprintf_s(mFile,"connectAttr \"");fvbs.write(mFile);fprintf_s(mFile,"\" \"%s.fvbs\";\n",mName.c_str());}
	/*
	Number of verts created the last time these leaves
	were converted to poly. Used to predict amount of
	memory to prealloc the next time
	*/
	void setLeafVertBufSize(int lvbs){if(lvbs == 0) return; fprintf_s(mFile, "setAttr \".lvbs\" %i;\n", lvbs);}
	/*
	Number of verts created the last time these leaves
	were converted to poly. Used to predict amount of
	memory to prealloc the next time
	*/
	void setLeafVertBufSize(const IntID& lvbs){fprintf_s(mFile,"connectAttr \"");lvbs.write(mFile);fprintf_s(mFile,"\" \"%s.lvbs\";\n",mName.c_str());}
	/*
	Limit number of faces created for each of the meshes
	to be within a segment of this limit.
	A value of 0 means no limit.
	*/
	void setMeshPolyLimit(int mpl){if(mpl == 0) return; fprintf_s(mFile, "setAttr \".mpl\" %i;\n", mpl);}
	/*
	Limit number of faces created for each of the meshes
	to be within a segment of this limit.
	A value of 0 means no limit.
	*/
	void setMeshPolyLimit(const IntID& mpl){fprintf_s(mFile,"connectAttr \"");mpl.write(mFile);fprintf_s(mFile,"\" \"%s.mpl\";\n",mName.c_str());}
	/*
	This attribute determines what to output for vertex colors
	on polys. Illuminated will bake the lighting for you.
	*/
	void setMeshVertexColorMode(unsigned int mvc){if(mvc == 0) return; fprintf_s(mFile, "setAttr \".mvc\" %i;\n", mvc);}
	/*
	This attribute determines what to output for vertex colors
	on polys. Illuminated will bake the lighting for you.
	*/
	void setMeshVertexColorMode(const UnsignedintID& mvc){fprintf_s(mFile,"connectAttr \"");mvc.write(mFile);fprintf_s(mFile,"\" \"%s.mvc\";\n",mName.c_str());}
	/*
	If true, then for poly output, those edges aligned with
	the tube direction will be hard. This could be useful
	for some of those inorganic shapes, e.g. a cityscape
	*/
	void setMeshHardEdges(bool mhe){if(mhe == false) return; fprintf_s(mFile, "setAttr \".mhe\" %i;\n", mhe);}
	/*
	If true, then for poly output, those edges aligned with
	the tube direction will be hard. This could be useful
	for some of those inorganic shapes, e.g. a cityscape
	*/
	void setMeshHardEdges(const BoolID& mhe){fprintf_s(mFile,"connectAttr \"");mhe.write(mFile);fprintf_s(mFile,"\" \"%s.mhe\";\n",mName.c_str());}
	/*
	If true, then for poly output, quads will be output
	The default is triangles
	*/
	void setMeshQuadOutput(bool mqo){if(mqo == false) return; fprintf_s(mFile, "setAttr \".mqo\" %i;\n", mqo);}
	/*
	If true, then for poly output, quads will be output
	The default is triangles
	*/
	void setMeshQuadOutput(const BoolID& mqo){fprintf_s(mFile,"connectAttr \"");mqo.write(mFile);fprintf_s(mFile,"\" \"%s.mqo\";\n",mName.c_str());}
	/*
	camera location to use for forward twist computation
	for poly mesh output. This allows poly output billboards
	to face a particular camera( outside of the paint effects
	render pass context ).
	*/
	void setCameraPoint(const double3& cpt){fprintf_s(mFile, "setAttr \".cpt\" -type \"double3\" ");cpt.write(mFile);fprintf_s(mFile,";\n");}
	/*
	camera location to use for forward twist computation
	for poly mesh output. This allows poly output billboards
	to face a particular camera( outside of the paint effects
	render pass context ).
	*/
	void setCameraPoint(const Double3ID& cpt){fprintf_s(mFile,"connectAttr \"");cpt.write(mFile);fprintf_s(mFile,"\" \"%s.cpt\";\n",mName.c_str());}
	/*worldspace camera X position value*/
	void setCameraPointX(double cpx){if(cpx == 0.0) return; fprintf_s(mFile, "setAttr \".cpt.cpx\" %f;\n", cpx);}
	/*worldspace camera X position value*/
	void setCameraPointX(const DoubleID& cpx){fprintf_s(mFile,"connectAttr \"");cpx.write(mFile);fprintf_s(mFile,"\" \"%s.cpt.cpx\";\n",mName.c_str());}
	/*worldspace camera Y position value*/
	void setCameraPointY(double cpy){if(cpy == 0.0) return; fprintf_s(mFile, "setAttr \".cpt.cpy\" %f;\n", cpy);}
	/*worldspace camera Y position value*/
	void setCameraPointY(const DoubleID& cpy){fprintf_s(mFile,"connectAttr \"");cpy.write(mFile);fprintf_s(mFile,"\" \"%s.cpt.cpy\";\n",mName.c_str());}
	/*worldspace camera Z position value*/
	void setCameraPointZ(double cpz){if(cpz == 0.0) return; fprintf_s(mFile, "setAttr \".cpt.cpz\" %f;\n", cpz);}
	/*worldspace camera Z position value*/
	void setCameraPointZ(const DoubleID& cpz){fprintf_s(mFile,"connectAttr \"");cpz.write(mFile);fprintf_s(mFile,"\" \"%s.cpt.cpz\";\n",mName.c_str());}
	/*Input Array of line modifier data*/
	void setLineModifier(size_t lmd_i,const LineModifierID& lmd){fprintf_s(mFile,"connectAttr \"");lmd.write(mFile);fprintf_s(mFile,"\" \"%s.lmd[%i]\";\n",mName.c_str(),lmd_i);}
	/*
	Maximum number of segments or poly faces to draw in viewports.
	This prevents very heavy brushes from locking up the interactive display.
	*/
	void setMaxDrawSegments(int mdsg){if(mdsg == 1000000) return; fprintf_s(mFile, "setAttr \".mdsg\" %i;\n", mdsg);}
	/*
	Maximum number of segments or poly faces to draw in viewports.
	This prevents very heavy brushes from locking up the interactive display.
	*/
	void setMaxDrawSegments(const IntID& mdsg){fprintf_s(mFile,"connectAttr \"");mdsg.write(mFile);fprintf_s(mFile,"\" \"%s.mdsg\";\n",mName.c_str());}
	/*Controls if profile curves are output.*/
	void setCurveMode(int cmd){if(cmd == 0) return; fprintf_s(mFile, "setAttr \".cmd\" %i;\n", cmd);}
	/*Controls if profile curves are output.*/
	void setCurveMode(const IntID& cmd){fprintf_s(mFile,"connectAttr \"");cmd.write(mFile);fprintf_s(mFile,"\" \"%s.cmd\";\n",mName.c_str());}
	/*Controls if profile curves are output.*/
	void setLeafCurveMode(int lcm){if(lcm == 0) return; fprintf_s(mFile, "setAttr \".lcm\" %i;\n", lcm);}
	/*Controls if profile curves are output.*/
	void setLeafCurveMode(const IntID& lcm){fprintf_s(mFile,"connectAttr \"");lcm.write(mFile);fprintf_s(mFile,"\" \"%s.lcm\";\n",mName.c_str());}
	/*Controls if profile curves are output.*/
	void setFlowerCurveMode(int fcm){if(fcm == 0) return; fprintf_s(mFile, "setAttr \".fcm\" %i;\n", fcm);}
	/*Controls if profile curves are output.*/
	void setFlowerCurveMode(const IntID& fcm){fprintf_s(mFile,"connectAttr \"");fcm.write(mFile);fprintf_s(mFile,"\" \"%s.fcm\";\n",mName.c_str());}
	/*The degree of the final generated output curve.*/
	void setDegree(int dgr){if(dgr == 2) return; fprintf_s(mFile, "setAttr \".dgr\" %i;\n", dgr);}
	/*The degree of the final generated output curve.*/
	void setDegree(const IntID& dgr){fprintf_s(mFile,"connectAttr \"");dgr.write(mFile);fprintf_s(mFile,"\" \"%s.dgr\";\n",mName.c_str());}
	/*This enables tangent continuity across output curves were branches meet.*/
	void setCurveAlign(bool cva){if(cva == false) return; fprintf_s(mFile, "setAttr \".cva\" %i;\n", cva);}
	/*This enables tangent continuity across output curves were branches meet.*/
	void setCurveAlign(const BoolID& cva){fprintf_s(mFile,"connectAttr \"");cva.write(mFile);fprintf_s(mFile,"\" \"%s.cva\";\n",mName.c_str());}
	/*the current number of main curves generated for the outMainCurves array*/
	void setOutMainCurveCount(const IntID& omcc){fprintf_s(mFile,"connectAttr \"");omcc.write(mFile);fprintf_s(mFile,"\" \"%s.omcc\";\n",mName.c_str());}
	/*the current number of leaf curves generated for the outLeafCurves array*/
	void setOutLeafCurveCount(const IntID& olcc){fprintf_s(mFile,"connectAttr \"");olcc.write(mFile);fprintf_s(mFile,"\" \"%s.olcc\";\n",mName.c_str());}
	/*the current number of flower curves generated for the outFlowerCurves array*/
	void setOutFlowerCurveCount(const IntID& ofcc){fprintf_s(mFile,"connectAttr \"");ofcc.write(mFile);fprintf_s(mFile,"\" \"%s.ofcc\";\n",mName.c_str());}
	/*output array of nurbs curve data representing the primary paint effects tubes*/
	void setOutMainCurves(size_t omc_i,const NurbsCurveID& omc){fprintf_s(mFile,"connectAttr \"");omc.write(mFile);fprintf_s(mFile,"\" \"%s.omc[%i]\";\n",mName.c_str(),omc_i);}
	/*output array of nurbs curve data representing the leaf paint effects tubes*/
	void setOutLeafCurves(size_t olc_i,const NurbsCurveID& olc){fprintf_s(mFile,"connectAttr \"");olc.write(mFile);fprintf_s(mFile,"\" \"%s.olc[%i]\";\n",mName.c_str(),olc_i);}
	/*output array of nurbs curve data representing the flower paint effects tubes*/
	void setOutFlowerCurves(size_t ofc_i,const NurbsCurveID& ofc){fprintf_s(mFile,"connectAttr \"");ofc.write(mFile);fprintf_s(mFile,"\" \"%s.ofc[%i]\";\n",mName.c_str(),ofc_i);}
	/*percentage of particles to display for interactive draw*/
	DoubleID getDisplayPercent(){char buffer[4096];sprintf_s (buffer, "%s.dpc",mName.c_str());return (const char*)buffer;}
	/*
	if ON, then the stroke is displayed in the modeling views
	as a quad mesh and the tube shape and thickness can be seen.
	Otherwise it is displayed by lines running down the
	center spine of each tube. Note that the quad mesh is only an
	accurate preview if the brushType is Mesh, otherwise it may
	differ somewhat from the final rendered look.
	*/
	BoolID getDrawAsMesh(){char buffer[4096];sprintf_s (buffer, "%s.dam",mName.c_str());return (const char*)buffer;}
	/*seed for randomization of stroke*/
	IntID getSeed(){char buffer[4096];sprintf_s (buffer, "%s.sed",mName.c_str());return (const char*)buffer;}
	/*determines order of draw, lower numbers are drawn first*/
	IntID getDrawOrder(){char buffer[4096];sprintf_s (buffer, "%s.dro",mName.c_str());return (const char*)buffer;}
	/*offset of stroke from construction surface along normal*/
	DoubleID getSurfaceOffset(){char buffer[4096];sprintf_s (buffer, "%s.sof",mName.c_str());return (const char*)buffer;}
	/*Input from brush node*/
	DynBrushID getBrush(){char buffer[4096];sprintf_s (buffer, "%s.brs",mName.c_str());return (const char*)buffer;}
	/*if ON, then the stroke is motion blurred*/
	BoolID getMotionBlurred(){char buffer[4096];sprintf_s (buffer, "%s.mblr",mName.c_str());return (const char*)buffer;}
	/*Does this stroke appear in shadow casts and rendering (TRUE) or only in shadow casts (FALSE).*/
	BoolID getPrimaryVisibility(){char buffer[4096];sprintf_s (buffer, "%s.pvs",mName.c_str());return (const char*)buffer;}
	/*curve to use as follow path and/or force*/
	const GenericID& getControlCurve(size_t clc_i){char buffer[4096];sprintf_s (buffer, "%s.clc[%i]",mName.c_str(),clc_i);return (const char*)buffer;}
	/*Output branch and twig surface.*/
	MeshID getOutMainMesh(){char buffer[4096];sprintf_s (buffer, "%s.omm",mName.c_str());return (const char*)buffer;}
	/*Output flower surface.*/
	MeshID getOutFlowerMesh(){char buffer[4096];sprintf_s (buffer, "%s.ofm",mName.c_str());return (const char*)buffer;}
	/*Output leaf surface.*/
	MeshID getOutLeafMesh(){char buffer[4096];sprintf_s (buffer, "%s.olm",mName.c_str());return (const char*)buffer;}
	/*Output world space branch and twig surfaces*/
	const MeshID& getWorldMainMesh(size_t wmm_i){char buffer[4096];sprintf_s (buffer, "%s.wmm[%i]",mName.c_str(),wmm_i);return (const char*)buffer;}
	/*Output world space leaf surfaces*/
	const MeshID& getWorldLeafMesh(size_t wlm_i){char buffer[4096];sprintf_s (buffer, "%s.wlm[%i]",mName.c_str(),wlm_i);return (const char*)buffer;}
	/*Output world space flower surfaces*/
	const MeshID& getWorldFlowerMesh(size_t wfm_i){char buffer[4096];sprintf_s (buffer, "%s.wfm[%i]",mName.c_str(),wfm_i);return (const char*)buffer;}
	/*
	Number of verts created the last time the main body
	of this stroke was converted to poly. Used to predict
	amount of memory to prealloc the next time
	*/
	IntID getMainVertBufSize(){char buffer[4096];sprintf_s (buffer, "%s.mvbs",mName.c_str());return (const char*)buffer;}
	/*
	Number of verts created the last time these flowers
	were converted to poly. Used to predict amount of
	memory to prealloc the next time
	*/
	IntID getFlowerVertBufSize(){char buffer[4096];sprintf_s (buffer, "%s.fvbs",mName.c_str());return (const char*)buffer;}
	/*
	Number of verts created the last time these leaves
	were converted to poly. Used to predict amount of
	memory to prealloc the next time
	*/
	IntID getLeafVertBufSize(){char buffer[4096];sprintf_s (buffer, "%s.lvbs",mName.c_str());return (const char*)buffer;}
	/*
	Limit number of faces created for each of the meshes
	to be within a segment of this limit.
	A value of 0 means no limit.
	*/
	IntID getMeshPolyLimit(){char buffer[4096];sprintf_s (buffer, "%s.mpl",mName.c_str());return (const char*)buffer;}
	/*
	This attribute determines what to output for vertex colors
	on polys. Illuminated will bake the lighting for you.
	*/
	UnsignedintID getMeshVertexColorMode(){char buffer[4096];sprintf_s (buffer, "%s.mvc",mName.c_str());return (const char*)buffer;}
	/*
	If true, then for poly output, those edges aligned with
	the tube direction will be hard. This could be useful
	for some of those inorganic shapes, e.g. a cityscape
	*/
	BoolID getMeshHardEdges(){char buffer[4096];sprintf_s (buffer, "%s.mhe",mName.c_str());return (const char*)buffer;}
	/*
	If true, then for poly output, quads will be output
	The default is triangles
	*/
	BoolID getMeshQuadOutput(){char buffer[4096];sprintf_s (buffer, "%s.mqo",mName.c_str());return (const char*)buffer;}
	/*
	camera location to use for forward twist computation
	for poly mesh output. This allows poly output billboards
	to face a particular camera( outside of the paint effects
	render pass context ).
	*/
	Double3ID getCameraPoint(){char buffer[4096];sprintf_s (buffer, "%s.cpt",mName.c_str());return (const char*)buffer;}
	/*worldspace camera X position value*/
	DoubleID getCameraPointX(){char buffer[4096];sprintf_s (buffer, "%s.cpt.cpx",mName.c_str());return (const char*)buffer;}
	/*worldspace camera Y position value*/
	DoubleID getCameraPointY(){char buffer[4096];sprintf_s (buffer, "%s.cpt.cpy",mName.c_str());return (const char*)buffer;}
	/*worldspace camera Z position value*/
	DoubleID getCameraPointZ(){char buffer[4096];sprintf_s (buffer, "%s.cpt.cpz",mName.c_str());return (const char*)buffer;}
	/*Input Array of line modifier data*/
	const LineModifierID& getLineModifier(size_t lmd_i){char buffer[4096];sprintf_s (buffer, "%s.lmd[%i]",mName.c_str(),lmd_i);return (const char*)buffer;}
	/*
	Maximum number of segments or poly faces to draw in viewports.
	This prevents very heavy brushes from locking up the interactive display.
	*/
	IntID getMaxDrawSegments(){char buffer[4096];sprintf_s (buffer, "%s.mdsg",mName.c_str());return (const char*)buffer;}
	/*Controls if profile curves are output.*/
	IntID getCurveMode(){char buffer[4096];sprintf_s (buffer, "%s.cmd",mName.c_str());return (const char*)buffer;}
	/*Controls if profile curves are output.*/
	IntID getLeafCurveMode(){char buffer[4096];sprintf_s (buffer, "%s.lcm",mName.c_str());return (const char*)buffer;}
	/*Controls if profile curves are output.*/
	IntID getFlowerCurveMode(){char buffer[4096];sprintf_s (buffer, "%s.fcm",mName.c_str());return (const char*)buffer;}
	/*The degree of the final generated output curve.*/
	IntID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.dgr",mName.c_str());return (const char*)buffer;}
	/*This enables tangent continuity across output curves were branches meet.*/
	BoolID getCurveAlign(){char buffer[4096];sprintf_s (buffer, "%s.cva",mName.c_str());return (const char*)buffer;}
	/*the current number of main curves generated for the outMainCurves array*/
	IntID getOutMainCurveCount(){char buffer[4096];sprintf_s (buffer, "%s.omcc",mName.c_str());return (const char*)buffer;}
	/*the current number of leaf curves generated for the outLeafCurves array*/
	IntID getOutLeafCurveCount(){char buffer[4096];sprintf_s (buffer, "%s.olcc",mName.c_str());return (const char*)buffer;}
	/*the current number of flower curves generated for the outFlowerCurves array*/
	IntID getOutFlowerCurveCount(){char buffer[4096];sprintf_s (buffer, "%s.ofcc",mName.c_str());return (const char*)buffer;}
	/*output array of nurbs curve data representing the primary paint effects tubes*/
	const NurbsCurveID& getOutMainCurves(size_t omc_i){char buffer[4096];sprintf_s (buffer, "%s.omc[%i]",mName.c_str(),omc_i);return (const char*)buffer;}
	/*output array of nurbs curve data representing the leaf paint effects tubes*/
	const NurbsCurveID& getOutLeafCurves(size_t olc_i){char buffer[4096];sprintf_s (buffer, "%s.olc[%i]",mName.c_str(),olc_i);return (const char*)buffer;}
	/*output array of nurbs curve data representing the flower paint effects tubes*/
	const NurbsCurveID& getOutFlowerCurves(size_t ofc_i){char buffer[4096];sprintf_s (buffer, "%s.ofc[%i]",mName.c_str(),ofc_i);return (const char*)buffer;}
protected:
	PfxGeometry(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PFXGEOMETRY_H__
