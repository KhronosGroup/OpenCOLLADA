/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BUMP2D_H__
#define __MayaDM_BUMP2D_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Bump2d</b> is a utility node that is useful for doing Bump
 Mapping.  Its job is to take the output of any 2d texture
 (usually the Out Alpha attribute) and convert it to
 "perturbed normals" that are used to calculate bump maps.
<p/>
 Usually, the system will create the bump2d node for you when
 you specify a bump map texture.  The Out Alpha attribute
 of the texture is connected to the Bump Value attribute of the
 Bump2d node, and the Out Normal attribute of the Bump2d node
 is connected to the Normal Camera attribute of a shader node, such
 as Lambert or Blinn or Phong.
<p/>
<pre>
 Checker           Bump2d           Blinn
 ---------         ------           -----
 Out Alpha  ---->  Bump Value
                   Out Normal ----> Normal Camera
</pre>
<p/>
 You can also "stack" different bump maps on top of one another.
 To do this, connect the Out Normal attribute of one bump
 map to the Normal Camera attribute of another.
<p/>
<pre>
 Checker       Bump3d        Cloth         Bump3d           Blinn
 -------       ------        -----         ------           -----
 Out Alpha --> Bump Value    Out Alpha --> Bump Value
               Out Normal ---------------> Normal Camera
                                           Out Normal ----->Normal Camera
</pre>
<p/>
 <b>Note:</b> If you are bump-mapping a shader that is using environment
 maps, then you must connect the Out Normal attribute of the bump
 node to the Normal Camera attribute of the Environment Texture, as
 well as to the Normal Camera attribute of the shader.  Otherwise, the
 environment will not be correctly reflected in the bumpy areas.  There
 is a MEL script to do this for you;  after you have connected the
 Out Color of the environtment map to the Reflected Color of the shader,
 type "cnctBumpProjNormal <i>shader-name</i>" in the command line, replacing
 <i>shader-name</i> with the name of your shader.
<p/>
<pre>
 Checker       Bump2d         EnvSphere         Blinn
 -------       ------         ---------         -----
 Out Alpha --> Bump Value     Out Color ------> Reflected Color
               Out Normal --> Normal Camera
                      and --------------------> Normal Camera
</pre><p/>
 You can use the other attributes of the Bump2d node to control
 the depth and filtering of the bump map.
<p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class Bump2d : public DependNode
{
public:
public:
	Bump2d(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "bump2d"){}
	virtual ~Bump2d(){}
	/*The current sample point that has to be shaded*/
	void setPointCamera(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	void setPointObj(const Float3ID& po){fprintf_s(mFile,"connectAttr \"");po.write(mFile);fprintf_s(mFile,"\" \"%s.po\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointObjX(const FloatID& pox){fprintf_s(mFile,"connectAttr \"");pox.write(mFile);fprintf_s(mFile,"\" \"%s.po.pox\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointObjY(const FloatID& poy){fprintf_s(mFile,"connectAttr \"");poy.write(mFile);fprintf_s(mFile,"\" \"%s.po.poy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointObjZ(const FloatID& poz){fprintf_s(mFile,"connectAttr \"");poz.write(mFile);fprintf_s(mFile,"\" \"%s.po.poz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointObj(const Float3ID& rpo){fprintf_s(mFile,"connectAttr \"");rpo.write(mFile);fprintf_s(mFile,"\" \"%s.rpo\";\n",mName.c_str());}
	/*The x component of the current reference sample position*/
	void setRefPointObjX(const FloatID& rpox){fprintf_s(mFile,"connectAttr \"");rpox.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.rpox\";\n",mName.c_str());}
	/*The y component of the current reference sample position*/
	void setRefPointObjY(const FloatID& rpoy){fprintf_s(mFile,"connectAttr \"");rpoy.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.rpoy\";\n",mName.c_str());}
	/*The z component of the current reference sample position*/
	void setRefPointObjZ(const FloatID& rpoz){fprintf_s(mFile,"connectAttr \"");rpoz.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.rpoz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointCamera(const Float3ID& rpc){fprintf_s(mFile,"connectAttr \"");rpc.write(mFile);fprintf_s(mFile,"\" \"%s.rpc\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setRefPointCameraX(const FloatID& rcx){fprintf_s(mFile,"connectAttr \"");rcx.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setRefPointCameraY(const FloatID& rcy){fprintf_s(mFile,"connectAttr \"");rcy.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setRefPointCameraZ(const FloatID& rcz){fprintf_s(mFile,"connectAttr \"");rcz.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcz\";\n",mName.c_str());}
	/*The current ray origin*/
	void setRayOrigin(const Float3ID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*The x component of the current  ray origin*/
	void setRayOriginX(const FloatID& rox){fprintf_s(mFile,"connectAttr \"");rox.write(mFile);fprintf_s(mFile,"\" \"%s.ro.rox\";\n",mName.c_str());}
	/*The y component of the current  ray origin*/
	void setRayOriginY(const FloatID& roy){fprintf_s(mFile,"connectAttr \"");roy.write(mFile);fprintf_s(mFile,"\" \"%s.ro.roy\";\n",mName.c_str());}
	/*The z component of the current  ray origin*/
	void setRayOriginZ(const FloatID& roz){fprintf_s(mFile,"connectAttr \"");roz.write(mFile);fprintf_s(mFile,"\" \"%s.ro.roz\";\n",mName.c_str());}
	/*The pixel angle*/
	void setXPixelAngle(float xpa){if(xpa == 0.002053) return; fprintf_s(mFile, "setAttr \".xpa\" %f;\n", xpa);}
	/*The UV coords of the current sample point*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setUCoord(const FloatID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.uv.u\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setVCoord(const FloatID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.uv.v\";\n",mName.c_str());}
	/*The sample (filter) size*/
	void setUvFilterSize(const Float2ID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs\";\n",mName.c_str());}
	/*The X size of the filter (sample)*/
	void setUvFilterSizeX(const FloatID& fsx){fprintf_s(mFile,"connectAttr \"");fsx.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsx\";\n",mName.c_str());}
	/*The Y size of the filter (sample)*/
	void setUvFilterSizeY(const FloatID& fsy){fprintf_s(mFile,"connectAttr \"");fsy.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsy\";\n",mName.c_str());}
	/*Information bits passing along information about type of shading*/
	void setInfoBits(const IntID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
	/*
	<b>Normal Camera</b>.  If you are combining more than
	one bump map, chain them together by connecting the
	Out Normal attribute of one to the Normal Camera attribute
	of the next.  The last bump map in the chain should be
	connected to the Normal Camera attribute of the shader.
	*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The X component of Normal Camera*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The Y component of Normal Camera*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The Z component of Normal Camera*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*The surface tangent along U (dPdU)*/
	void setTangentUCamera(const Float3ID& tu){fprintf_s(mFile,"connectAttr \"");tu.write(mFile);fprintf_s(mFile,"\" \"%s.tu\";\n",mName.c_str());}
	/*The X component of the U tangent*/
	void setTangentUx(const FloatID& tux){fprintf_s(mFile,"connectAttr \"");tux.write(mFile);fprintf_s(mFile,"\" \"%s.tu.tux\";\n",mName.c_str());}
	/*The Y component of the U tangent*/
	void setTangentUy(const FloatID& tuy){fprintf_s(mFile,"connectAttr \"");tuy.write(mFile);fprintf_s(mFile,"\" \"%s.tu.tuy\";\n",mName.c_str());}
	/*The Z component of the U tangent*/
	void setTangentUz(const FloatID& tuz){fprintf_s(mFile,"connectAttr \"");tuz.write(mFile);fprintf_s(mFile,"\" \"%s.tu.tuz\";\n",mName.c_str());}
	/*The surface tangent along V (dPdV)*/
	void setTangentVCamera(const Float3ID& tv){fprintf_s(mFile,"connectAttr \"");tv.write(mFile);fprintf_s(mFile,"\" \"%s.tv\";\n",mName.c_str());}
	/*The X component of the V tangent*/
	void setTangentVx(const FloatID& tvx){fprintf_s(mFile,"connectAttr \"");tvx.write(mFile);fprintf_s(mFile,"\" \"%s.tv.tvx\";\n",mName.c_str());}
	/*The Y component of the V tangent*/
	void setTangentVy(const FloatID& tvy){fprintf_s(mFile,"connectAttr \"");tvy.write(mFile);fprintf_s(mFile,"\" \"%s.tv.tvy\";\n",mName.c_str());}
	/*The Z component of the V tangent*/
	void setTangentVz(const FloatID& tvz){fprintf_s(mFile,"connectAttr \"");tvz.write(mFile);fprintf_s(mFile,"\" \"%s.tv.tvz\";\n",mName.c_str());}
	/*
	<b>Adjust Edges</b>.  Turn on Adjust Edges to remove any
	artifacts on texture boundaries.  These artifacts may
	appear when you are mapping textures with the Wrap U and
	and Wrap V turned off.
	*/
	void setAdjustEdges(bool ae){if(ae == false) return; fprintf_s(mFile, "setAttr \".ae\" %i;\n", ae);}
	/*
	<b>Adjust Edges</b>.  Turn on Adjust Edges to remove any
	artifacts on texture boundaries.  These artifacts may
	appear when you are mapping textures with the Wrap U and
	and Wrap V turned off.
	*/
	void setAdjustEdges(const BoolID& ae){fprintf_s(mFile,"connectAttr \"");ae.write(mFile);fprintf_s(mFile,"\" \"%s.ae\";\n",mName.c_str());}
	/*
	<b>Bump Depth</b> controls how high the bumps will
	appear to be on the surface.  Increase Bump Depth
	to make the bumps higher.  Decrease Bump Depth to
	make the surface smoother.
	*/
	void setBumpDepth(float bd){if(bd == 1.0) return; fprintf_s(mFile, "setAttr \".bd\" %f;\n", bd);}
	/*
	<b>Bump Depth</b> controls how high the bumps will
	appear to be on the surface.  Increase Bump Depth
	to make the bumps higher.  Decrease Bump Depth to
	make the surface smoother.
	*/
	void setBumpDepth(const FloatID& bd){fprintf_s(mFile,"connectAttr \"");bd.write(mFile);fprintf_s(mFile,"\" \"%s.bd\";\n",mName.c_str());}
	/*
	<b>Bump Interpretation</b> controls how to interpret
	the incoming bump value. By defualt it is taken as
	a height field value.
	*/
	void setBumpInterp(unsigned int bi){if(bi == 0) return; fprintf_s(mFile, "setAttr \".bi\" %i;\n", bi);}
	/*
	<b>Bump Interpretation</b> controls how to interpret
	the incoming bump value. By defualt it is taken as
	a height field value.
	*/
	void setBumpInterp(const UnsignedintID& bi){fprintf_s(mFile,"connectAttr \"");bi.write(mFile);fprintf_s(mFile,"\" \"%s.bi\";\n",mName.c_str());}
	/*
	<b>Bump Filter</b> affects the amount of filtering performed on
	a texture used as a bump map.
	<p/>
	The amount of filtering the system does is calculated based
	on how much screen space the texture occupies in the final
	image.  The Bump Filter attribute is a multiplier on that value.
	<p/>
	Values greater than 1.0 will cause the renderer to do more filtering.
	This will make the bumps smoother.  Increase the
	amount of filtering
	if there is aliasing (<i>i.e.</i> jagged staircase effects)
	in your final renderings, or if the
	bump map appears to "pop" or "sizzle" over the course of several
	frames.
	<p/>
	Values less than 1.0 will cause the renderer to do less filtering.
	This will make the bumps appear sharper.  Decrease
	the amount of filtering.
	if your bumps are appearing too smoothed-out in the final rendered
	images.
	<p/>
	See also the Bump Filter Offset attribute (below).
	*/
	void setBumpFilter(float bf){if(bf == 1.0) return; fprintf_s(mFile, "setAttr \".bf\" %f;\n", bf);}
	/*
	<b>Bump Filter</b> affects the amount of filtering performed on
	a texture used as a bump map.
	<p/>
	The amount of filtering the system does is calculated based
	on how much screen space the texture occupies in the final
	image.  The Bump Filter attribute is a multiplier on that value.
	<p/>
	Values greater than 1.0 will cause the renderer to do more filtering.
	This will make the bumps smoother.  Increase the
	amount of filtering
	if there is aliasing (<i>i.e.</i> jagged staircase effects)
	in your final renderings, or if the
	bump map appears to "pop" or "sizzle" over the course of several
	frames.
	<p/>
	Values less than 1.0 will cause the renderer to do less filtering.
	This will make the bumps appear sharper.  Decrease
	the amount of filtering.
	if your bumps are appearing too smoothed-out in the final rendered
	images.
	<p/>
	See also the Bump Filter Offset attribute (below).
	*/
	void setBumpFilter(const FloatID& bf){fprintf_s(mFile,"connectAttr \"");bf.write(mFile);fprintf_s(mFile,"\" \"%s.bf\";\n",mName.c_str());}
	/*
	<b>Bump Filter Offset</b> affects the amount of filtering
	performed on a texture.
	<p/>
	Unlike the Bump Filter attribute (which is a multiplier),
	Bump Filter Offset is added to the system's calculated filtering
	values.  This increases the amount of filtering uniformly.
	<p/>
	This attribute can be used to "lock" the system's
	filtering values.  To do this, set the Bump Filter attribute to
	0.  Then the Bump Filter Offset value will completely determine
	the amount of filtering.
	*/
	void setBumpFilterOffset(float bfo){if(bfo == 0.0) return; fprintf_s(mFile, "setAttr \".bfo\" %f;\n", bfo);}
	/*
	<b>Bump Filter Offset</b> affects the amount of filtering
	performed on a texture.
	<p/>
	Unlike the Bump Filter attribute (which is a multiplier),
	Bump Filter Offset is added to the system's calculated filtering
	values.  This increases the amount of filtering uniformly.
	<p/>
	This attribute can be used to "lock" the system's
	filtering values.  To do this, set the Bump Filter attribute to
	0.  Then the Bump Filter Offset value will completely determine
	the amount of filtering.
	*/
	void setBumpFilterOffset(const FloatID& bfo){fprintf_s(mFile,"connectAttr \"");bfo.write(mFile);fprintf_s(mFile,"\" \"%s.bfo\";\n",mName.c_str());}
	/*
	<b>Bump Value</b> is the source texture that is being
	used for the bump map.  The Out Alpha attribute of a 2d
	texture should be connected to this attribute.
	<p/>
	Of course, you can connect the output of any shading
	network to Bump Value, and it will be used as the source
	of the bumps.  See also the Provide 3d Info attribute below.
	*/
	void setBumpValue(float bv){if(bv == 0.0) return; fprintf_s(mFile, "setAttr \".bv\" %f;\n", bv);}
	/*
	<b>Bump Value</b> is the source texture that is being
	used for the bump map.  The Out Alpha attribute of a 2d
	texture should be connected to this attribute.
	<p/>
	Of course, you can connect the output of any shading
	network to Bump Value, and it will be used as the source
	of the bumps.  See also the Provide 3d Info attribute below.
	*/
	void setBumpValue(const FloatID& bv){fprintf_s(mFile,"connectAttr \"");bv.write(mFile);fprintf_s(mFile,"\" \"%s.bv\";\n",mName.c_str());}
	/*
	<b>Provide 3d Info</b> is useful when the input to this node is
	something more complex than a simple 2d texture.
	If you are using a shading network as input,
	or if you are stacking bump maps together, and there is
	one or more 3d texture nodes in that network,
	then you must turn on Provide 3d Info. Otherwise the
	3d nodes 'upstream' will not get all the information they need.
	<p/>Turning on Provide 3d Info slows down the bump node
	a little, so it is left off by default.
	*/
	void setProvide3dInfo(bool p3d){if(p3d == false) return; fprintf_s(mFile, "setAttr \".p3d\" %i;\n", p3d);}
	/*
	<b>Provide 3d Info</b> is useful when the input to this node is
	something more complex than a simple 2d texture.
	If you are using a shading network as input,
	or if you are stacking bump maps together, and there is
	one or more 3d texture nodes in that network,
	then you must turn on Provide 3d Info. Otherwise the
	3d nodes 'upstream' will not get all the information they need.
	<p/>Turning on Provide 3d Info slows down the bump node
	a little, so it is left off by default.
	*/
	void setProvide3dInfo(const BoolID& p3d){fprintf_s(mFile,"connectAttr \"");p3d.write(mFile);fprintf_s(mFile,"\" \"%s.p3d\";\n",mName.c_str());}
	/*
	<b>Out Normal</b> is the 'perturbed normal', that
	is calculated from the input texture.  Connect this
	to the Normal Camera attribute of a shader to put a
	bump map on that shader.  Or, connect this to the
	Normal Camera attribute of another bump map to stack
	them together.
	*/
	void setOutNormal(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The X component of Out Normal*/
	void setOutNormalX(const FloatID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*The Y component of Out Normal*/
	void setOutNormalY(const FloatID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*The Z component of Out Normal*/
	void setOutNormalZ(const FloatID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvOne(const float2& vt1){fprintf_s(mFile, "setAttr \".vt1\" -type \"float2\" ");vt1.write(mFile);fprintf_s(mFile,";\n");}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvOne(const Float2ID& vt1){fprintf_s(mFile,"connectAttr \"");vt1.write(mFile);fprintf_s(mFile,"\" \"%s.vt1\";\n",mName.c_str());}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvOneU(float t1u){if(t1u == 0.0) return; fprintf_s(mFile, "setAttr \".vt1.t1u\" %f;\n", t1u);}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvOneU(const FloatID& t1u){fprintf_s(mFile,"connectAttr \"");t1u.write(mFile);fprintf_s(mFile,"\" \"%s.vt1.t1u\";\n",mName.c_str());}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvOneV(float t1v){if(t1v == 0.0) return; fprintf_s(mFile, "setAttr \".vt1.t1v\" %f;\n", t1v);}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvOneV(const FloatID& t1v){fprintf_s(mFile,"connectAttr \"");t1v.write(mFile);fprintf_s(mFile,"\" \"%s.vt1.t1v\";\n",mName.c_str());}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvTwo(const float2& vt2){fprintf_s(mFile, "setAttr \".vt2\" -type \"float2\" ");vt2.write(mFile);fprintf_s(mFile,";\n");}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvTwo(const Float2ID& vt2){fprintf_s(mFile,"connectAttr \"");vt2.write(mFile);fprintf_s(mFile,"\" \"%s.vt2\";\n",mName.c_str());}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvTwoU(float t2u){if(t2u == 0.0) return; fprintf_s(mFile, "setAttr \".vt2.t2u\" %f;\n", t2u);}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvTwoU(const FloatID& t2u){fprintf_s(mFile,"connectAttr \"");t2u.write(mFile);fprintf_s(mFile,"\" \"%s.vt2.t2u\";\n",mName.c_str());}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvTwoV(float t2v){if(t2v == 0.0) return; fprintf_s(mFile, "setAttr \".vt2.t2v\" %f;\n", t2v);}
	/*Unused, but left in for backward compatibility*/
	void setVertexUvTwoV(const FloatID& t2v){fprintf_s(mFile,"connectAttr \"");t2v.write(mFile);fprintf_s(mFile,"\" \"%s.vt2.t2v\";\n",mName.c_str());}
	/*
	Usually, this is the triangle's first vertex, in camera space.
	But if bump mapping is being used, this field is used to pass the
	original uv to the file texture node, should the file texture node
	be feeding the bump map.  We'll check the info bits, and if
	INFO_BUMP is set, we'll transform vertexCameraOne exactly like we
	transform uv.  This is safe to do since advanced filtering can't
	be used with bump mapping, hence the fields are not being used
	otherwise.
	*/
	void setVertexCameraOne(const float3& vc1){fprintf_s(mFile, "setAttr \".vc1\" -type \"float3\" ");vc1.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Usually, this is the triangle's first vertex, in camera space.
	But if bump mapping is being used, this field is used to pass the
	original uv to the file texture node, should the file texture node
	be feeding the bump map.  We'll check the info bits, and if
	INFO_BUMP is set, we'll transform vertexCameraOne exactly like we
	transform uv.  This is safe to do since advanced filtering can't
	be used with bump mapping, hence the fields are not being used
	otherwise.
	*/
	void setVertexCameraOne(const Float3ID& vc1){fprintf_s(mFile,"connectAttr \"");vc1.write(mFile);fprintf_s(mFile,"\" \"%s.vc1\";\n",mName.c_str());}
	/*X coordinate of Vertex Camera One*/
	void setVertexCameraOneX(float c1x){if(c1x == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1x\" %f;\n", c1x);}
	/*X coordinate of Vertex Camera One*/
	void setVertexCameraOneX(const FloatID& c1x){fprintf_s(mFile,"connectAttr \"");c1x.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1x\";\n",mName.c_str());}
	/*Y coordinate of Vertex Camera One*/
	void setVertexCameraOneY(float c1y){if(c1y == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1y\" %f;\n", c1y);}
	/*Y coordinate of Vertex Camera One*/
	void setVertexCameraOneY(const FloatID& c1y){fprintf_s(mFile,"connectAttr \"");c1y.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1y\";\n",mName.c_str());}
	/*Z coordinate of Vertex Camera One*/
	void setVertexCameraOneZ(float c1z){if(c1z == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1z\" %f;\n", c1z);}
	/*Z coordinate of Vertex Camera One*/
	void setVertexCameraOneZ(const FloatID& c1z){fprintf_s(mFile,"connectAttr \"");c1z.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1z\";\n",mName.c_str());}
	/*
	Usually, this is the triangle's second vertex, in camera space.
	But if bump mapping is being used, this field is used to pass the
	resulting filter size (i.e., sizeValsUV) to the file texture node,
	should the file texture nodebe feeding the bump map.  We'll check
	the info bits, and if INFO_BUMP is set, we'll transform
	vertexCameraTwo exactly like we transform uv.  This is safe to do
	since advanced filtering can't be used with bump mapping, hence
	the fields are not being used otherwise.
	*/
	void setVertexCameraTwo(const float3& vc2){fprintf_s(mFile, "setAttr \".vc2\" -type \"float3\" ");vc2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Usually, this is the triangle's second vertex, in camera space.
	But if bump mapping is being used, this field is used to pass the
	resulting filter size (i.e., sizeValsUV) to the file texture node,
	should the file texture nodebe feeding the bump map.  We'll check
	the info bits, and if INFO_BUMP is set, we'll transform
	vertexCameraTwo exactly like we transform uv.  This is safe to do
	since advanced filtering can't be used with bump mapping, hence
	the fields are not being used otherwise.
	*/
	void setVertexCameraTwo(const Float3ID& vc2){fprintf_s(mFile,"connectAttr \"");vc2.write(mFile);fprintf_s(mFile,"\" \"%s.vc2\";\n",mName.c_str());}
	/*X coordinate of Vertex Camera Two*/
	void setVertexCameraTwoX(float c2x){if(c2x == 0.0) return; fprintf_s(mFile, "setAttr \".vc2.c2x\" %f;\n", c2x);}
	/*X coordinate of Vertex Camera Two*/
	void setVertexCameraTwoX(const FloatID& c2x){fprintf_s(mFile,"connectAttr \"");c2x.write(mFile);fprintf_s(mFile,"\" \"%s.vc2.c2x\";\n",mName.c_str());}
	/*Y coordinate of Vertex Camera Two*/
	void setVertexCameraTwoY(float c2y){if(c2y == 0.0) return; fprintf_s(mFile, "setAttr \".vc2.c2y\" %f;\n", c2y);}
	/*Y coordinate of Vertex Camera Two*/
	void setVertexCameraTwoY(const FloatID& c2y){fprintf_s(mFile,"connectAttr \"");c2y.write(mFile);fprintf_s(mFile,"\" \"%s.vc2.c2y\";\n",mName.c_str());}
	/*Z coordinate of Vertex Camera Two*/
	void setVertexCameraTwoZ(float c2z){if(c2z == 0.0) return; fprintf_s(mFile, "setAttr \".vc2.c2z\" %f;\n", c2z);}
	/*Z coordinate of Vertex Camera Two*/
	void setVertexCameraTwoZ(const FloatID& c2z){fprintf_s(mFile,"connectAttr \"");c2z.write(mFile);fprintf_s(mFile,"\" \"%s.vc2.c2z\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*The current sample point that has to be shaded*/
	Float3ID getPointObj(){char buffer[4096];sprintf_s (buffer, "%s.po",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.po.pox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.po.poy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.po.poz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointObj(){char buffer[4096];sprintf_s (buffer, "%s.rpo",mName.c_str());return (const char*)buffer;}
	/*The x component of the current reference sample position*/
	FloatID getRefPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.rpo.rpox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current reference sample position*/
	FloatID getRefPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.rpo.rpoy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current reference sample position*/
	FloatID getRefPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.rpo.rpoz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.rpc",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getRefPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getRefPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getRefPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcz",mName.c_str());return (const char*)buffer;}
	/*The current ray origin*/
	Float3ID getRayOrigin(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*The x component of the current  ray origin*/
	FloatID getRayOriginX(){char buffer[4096];sprintf_s (buffer, "%s.ro.rox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current  ray origin*/
	FloatID getRayOriginY(){char buffer[4096];sprintf_s (buffer, "%s.ro.roy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current  ray origin*/
	FloatID getRayOriginZ(){char buffer[4096];sprintf_s (buffer, "%s.ro.roz",mName.c_str());return (const char*)buffer;}
	/*The UV coords of the current sample point*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.u",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.v",mName.c_str());return (const char*)buffer;}
	/*The sample (filter) size*/
	Float2ID getUvFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.fs",mName.c_str());return (const char*)buffer;}
	/*The X size of the filter (sample)*/
	FloatID getUvFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsx",mName.c_str());return (const char*)buffer;}
	/*The Y size of the filter (sample)*/
	FloatID getUvFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsy",mName.c_str());return (const char*)buffer;}
	/*Information bits passing along information about type of shading*/
	IntID getInfoBits(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Normal Camera</b>.  If you are combining more than
	one bump map, chain them together by connecting the
	Out Normal attribute of one to the Normal Camera attribute
	of the next.  The last bump map in the chain should be
	connected to the Normal Camera attribute of the shader.
	*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The X component of Normal Camera*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The Y component of Normal Camera*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The Z component of Normal Camera*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*The surface tangent along U (dPdU)*/
	Float3ID getTangentUCamera(){char buffer[4096];sprintf_s (buffer, "%s.tu",mName.c_str());return (const char*)buffer;}
	/*The X component of the U tangent*/
	FloatID getTangentUx(){char buffer[4096];sprintf_s (buffer, "%s.tu.tux",mName.c_str());return (const char*)buffer;}
	/*The Y component of the U tangent*/
	FloatID getTangentUy(){char buffer[4096];sprintf_s (buffer, "%s.tu.tuy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the U tangent*/
	FloatID getTangentUz(){char buffer[4096];sprintf_s (buffer, "%s.tu.tuz",mName.c_str());return (const char*)buffer;}
	/*The surface tangent along V (dPdV)*/
	Float3ID getTangentVCamera(){char buffer[4096];sprintf_s (buffer, "%s.tv",mName.c_str());return (const char*)buffer;}
	/*The X component of the V tangent*/
	FloatID getTangentVx(){char buffer[4096];sprintf_s (buffer, "%s.tv.tvx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the V tangent*/
	FloatID getTangentVy(){char buffer[4096];sprintf_s (buffer, "%s.tv.tvy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the V tangent*/
	FloatID getTangentVz(){char buffer[4096];sprintf_s (buffer, "%s.tv.tvz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Adjust Edges</b>.  Turn on Adjust Edges to remove any
	artifacts on texture boundaries.  These artifacts may
	appear when you are mapping textures with the Wrap U and
	and Wrap V turned off.
	*/
	BoolID getAdjustEdges(){char buffer[4096];sprintf_s (buffer, "%s.ae",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bump Depth</b> controls how high the bumps will
	appear to be on the surface.  Increase Bump Depth
	to make the bumps higher.  Decrease Bump Depth to
	make the surface smoother.
	*/
	FloatID getBumpDepth(){char buffer[4096];sprintf_s (buffer, "%s.bd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bump Interpretation</b> controls how to interpret
	the incoming bump value. By defualt it is taken as
	a height field value.
	*/
	UnsignedintID getBumpInterp(){char buffer[4096];sprintf_s (buffer, "%s.bi",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bump Filter</b> affects the amount of filtering performed on
	a texture used as a bump map.
	<p/>
	The amount of filtering the system does is calculated based
	on how much screen space the texture occupies in the final
	image.  The Bump Filter attribute is a multiplier on that value.
	<p/>
	Values greater than 1.0 will cause the renderer to do more filtering.
	This will make the bumps smoother.  Increase the
	amount of filtering
	if there is aliasing (<i>i.e.</i> jagged staircase effects)
	in your final renderings, or if the
	bump map appears to "pop" or "sizzle" over the course of several
	frames.
	<p/>
	Values less than 1.0 will cause the renderer to do less filtering.
	This will make the bumps appear sharper.  Decrease
	the amount of filtering.
	if your bumps are appearing too smoothed-out in the final rendered
	images.
	<p/>
	See also the Bump Filter Offset attribute (below).
	*/
	FloatID getBumpFilter(){char buffer[4096];sprintf_s (buffer, "%s.bf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bump Filter Offset</b> affects the amount of filtering
	performed on a texture.
	<p/>
	Unlike the Bump Filter attribute (which is a multiplier),
	Bump Filter Offset is added to the system's calculated filtering
	values.  This increases the amount of filtering uniformly.
	<p/>
	This attribute can be used to "lock" the system's
	filtering values.  To do this, set the Bump Filter attribute to
	0.  Then the Bump Filter Offset value will completely determine
	the amount of filtering.
	*/
	FloatID getBumpFilterOffset(){char buffer[4096];sprintf_s (buffer, "%s.bfo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bump Value</b> is the source texture that is being
	used for the bump map.  The Out Alpha attribute of a 2d
	texture should be connected to this attribute.
	<p/>
	Of course, you can connect the output of any shading
	network to Bump Value, and it will be used as the source
	of the bumps.  See also the Provide 3d Info attribute below.
	*/
	FloatID getBumpValue(){char buffer[4096];sprintf_s (buffer, "%s.bv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Provide 3d Info</b> is useful when the input to this node is
	something more complex than a simple 2d texture.
	If you are using a shading network as input,
	or if you are stacking bump maps together, and there is
	one or more 3d texture nodes in that network,
	then you must turn on Provide 3d Info. Otherwise the
	3d nodes 'upstream' will not get all the information they need.
	<p/>Turning on Provide 3d Info slows down the bump node
	a little, so it is left off by default.
	*/
	BoolID getProvide3dInfo(){char buffer[4096];sprintf_s (buffer, "%s.p3d",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Normal</b> is the 'perturbed normal', that
	is calculated from the input texture.  Connect this
	to the Normal Camera attribute of a shader to put a
	bump map on that shader.  Or, connect this to the
	Normal Camera attribute of another bump map to stack
	them together.
	*/
	Float3ID getOutNormal(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The X component of Out Normal*/
	FloatID getOutNormalX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*The Y component of Out Normal*/
	FloatID getOutNormalY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*The Z component of Out Normal*/
	FloatID getOutNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
	/*Unused, but left in for backward compatibility*/
	Float2ID getVertexUvOne(){char buffer[4096];sprintf_s (buffer, "%s.vt1",mName.c_str());return (const char*)buffer;}
	/*Unused, but left in for backward compatibility*/
	FloatID getVertexUvOneU(){char buffer[4096];sprintf_s (buffer, "%s.vt1.t1u",mName.c_str());return (const char*)buffer;}
	/*Unused, but left in for backward compatibility*/
	FloatID getVertexUvOneV(){char buffer[4096];sprintf_s (buffer, "%s.vt1.t1v",mName.c_str());return (const char*)buffer;}
	/*Unused, but left in for backward compatibility*/
	Float2ID getVertexUvTwo(){char buffer[4096];sprintf_s (buffer, "%s.vt2",mName.c_str());return (const char*)buffer;}
	/*Unused, but left in for backward compatibility*/
	FloatID getVertexUvTwoU(){char buffer[4096];sprintf_s (buffer, "%s.vt2.t2u",mName.c_str());return (const char*)buffer;}
	/*Unused, but left in for backward compatibility*/
	FloatID getVertexUvTwoV(){char buffer[4096];sprintf_s (buffer, "%s.vt2.t2v",mName.c_str());return (const char*)buffer;}
	/*
	Usually, this is the triangle's first vertex, in camera space.
	But if bump mapping is being used, this field is used to pass the
	original uv to the file texture node, should the file texture node
	be feeding the bump map.  We'll check the info bits, and if
	INFO_BUMP is set, we'll transform vertexCameraOne exactly like we
	transform uv.  This is safe to do since advanced filtering can't
	be used with bump mapping, hence the fields are not being used
	otherwise.
	*/
	Float3ID getVertexCameraOne(){char buffer[4096];sprintf_s (buffer, "%s.vc1",mName.c_str());return (const char*)buffer;}
	/*X coordinate of Vertex Camera One*/
	FloatID getVertexCameraOneX(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1x",mName.c_str());return (const char*)buffer;}
	/*Y coordinate of Vertex Camera One*/
	FloatID getVertexCameraOneY(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1y",mName.c_str());return (const char*)buffer;}
	/*Z coordinate of Vertex Camera One*/
	FloatID getVertexCameraOneZ(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1z",mName.c_str());return (const char*)buffer;}
	/*
	Usually, this is the triangle's second vertex, in camera space.
	But if bump mapping is being used, this field is used to pass the
	resulting filter size (i.e., sizeValsUV) to the file texture node,
	should the file texture nodebe feeding the bump map.  We'll check
	the info bits, and if INFO_BUMP is set, we'll transform
	vertexCameraTwo exactly like we transform uv.  This is safe to do
	since advanced filtering can't be used with bump mapping, hence
	the fields are not being used otherwise.
	*/
	Float3ID getVertexCameraTwo(){char buffer[4096];sprintf_s (buffer, "%s.vc2",mName.c_str());return (const char*)buffer;}
	/*X coordinate of Vertex Camera Two*/
	FloatID getVertexCameraTwoX(){char buffer[4096];sprintf_s (buffer, "%s.vc2.c2x",mName.c_str());return (const char*)buffer;}
	/*Y coordinate of Vertex Camera Two*/
	FloatID getVertexCameraTwoY(){char buffer[4096];sprintf_s (buffer, "%s.vc2.c2y",mName.c_str());return (const char*)buffer;}
	/*Z coordinate of Vertex Camera Two*/
	FloatID getVertexCameraTwoZ(){char buffer[4096];sprintf_s (buffer, "%s.vc2.c2z",mName.c_str());return (const char*)buffer;}
protected:
	Bump2d(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BUMP2D_H__
