/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PLACE2DTEXTURE_H__
#define __MayaDM_PLACE2DTEXTURE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Place2dTexture</b> is a utility node that controls how a
 2d texture is placed onto an object.  Normally a Place2dTexture
 node is created automatically by the system when you texture-map
 an attribute using a 2d texture.  (The Out UV attribute of this
 node is connected to the uvCoord attribute of the texture node,
 and the outUVFilterSize attribute of this node is connected to
 the uvFilterSize attribute of the texture node.)
 <p/>
 2d textures are placed on a surface using the surface's UV coordinates.
 (These coordinates are implicit in NURBS surfaces, but they must
 be assigned explicitly to polygonal objects.)
<p/>
 The Place2dTexture node defines a <i>texture frame</i>, which is
 a rectangular area on a surface (in the UV coordinate space)
 in which the texture will appear.  You can control the position, size,
 and rotation of this
 frame on the surface using the Coverage, Translate Frame
 and Rotate Frame attributes.  You can controls how the
 texture is tiled within the frame using the Repeat UV, Rotate UV,
 Offset, Mirror, Stagger, and Wrap atttributes. These are all explained below.
<p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class Place2dTexture : public DependNode
{
public:
public:
	Place2dTexture(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "place2dTexture"){}
	virtual ~Place2dTexture(){}
	/*The UV coords of the current sample point*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setUCoord(const FloatID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.uv.u\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setVCoord(const FloatID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.uv.v\";\n",mName.c_str());}
	/*Triangle s first vertex, in texture space*/
	void setVertexUvOne(const float2& vt1){fprintf_s(mFile, "setAttr \".vt1\" -type \"float2\" ");vt1.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s first vertex, in texture space*/
	void setVertexUvOne(const Float2ID& vt1){fprintf_s(mFile,"connectAttr \"");vt1.write(mFile);fprintf_s(mFile,"\" \"%s.vt1\";\n",mName.c_str());}
	/*X component of aVertexUvOne*/
	void setVertexUvOneU(float t1u){if(t1u == 0.0) return; fprintf_s(mFile, "setAttr \".vt1.t1u\" %f;\n", t1u);}
	/*X component of aVertexUvOne*/
	void setVertexUvOneU(const FloatID& t1u){fprintf_s(mFile,"connectAttr \"");t1u.write(mFile);fprintf_s(mFile,"\" \"%s.vt1.t1u\";\n",mName.c_str());}
	/*Y component of aVertexUvOne*/
	void setVertexUvOneV(float t1v){if(t1v == 0.0) return; fprintf_s(mFile, "setAttr \".vt1.t1v\" %f;\n", t1v);}
	/*Y component of aVertexUvOne*/
	void setVertexUvOneV(const FloatID& t1v){fprintf_s(mFile,"connectAttr \"");t1v.write(mFile);fprintf_s(mFile,"\" \"%s.vt1.t1v\";\n",mName.c_str());}
	/*Triangle s second vertex, in texture space*/
	void setVertexUvTwo(const float2& vt2){fprintf_s(mFile, "setAttr \".vt2\" -type \"float2\" ");vt2.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s second vertex, in texture space*/
	void setVertexUvTwo(const Float2ID& vt2){fprintf_s(mFile,"connectAttr \"");vt2.write(mFile);fprintf_s(mFile,"\" \"%s.vt2\";\n",mName.c_str());}
	/*X component of aVertexUvTwo*/
	void setVertexUvTwoU(float t2u){if(t2u == 0.0) return; fprintf_s(mFile, "setAttr \".vt2.t2u\" %f;\n", t2u);}
	/*X component of aVertexUvTwo*/
	void setVertexUvTwoU(const FloatID& t2u){fprintf_s(mFile,"connectAttr \"");t2u.write(mFile);fprintf_s(mFile,"\" \"%s.vt2.t2u\";\n",mName.c_str());}
	/*Y component of aVertexUvTwo*/
	void setVertexUvTwoV(float t2v){if(t2v == 0.0) return; fprintf_s(mFile, "setAttr \".vt2.t2v\" %f;\n", t2v);}
	/*Y component of aVertexUvTwo*/
	void setVertexUvTwoV(const FloatID& t2v){fprintf_s(mFile,"connectAttr \"");t2v.write(mFile);fprintf_s(mFile,"\" \"%s.vt2.t2v\";\n",mName.c_str());}
	/*Triangle s third vertex, in texture space*/
	void setVertexUvThree(const float2& vt3){fprintf_s(mFile, "setAttr \".vt3\" -type \"float2\" ");vt3.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s third vertex, in texture space*/
	void setVertexUvThree(const Float2ID& vt3){fprintf_s(mFile,"connectAttr \"");vt3.write(mFile);fprintf_s(mFile,"\" \"%s.vt3\";\n",mName.c_str());}
	/*X component of aVertexUvThree*/
	void setVertexUvThreeU(float t3u){if(t3u == 0.0) return; fprintf_s(mFile, "setAttr \".vt3.t3u\" %f;\n", t3u);}
	/*X component of aVertexUvThree*/
	void setVertexUvThreeU(const FloatID& t3u){fprintf_s(mFile,"connectAttr \"");t3u.write(mFile);fprintf_s(mFile,"\" \"%s.vt3.t3u\";\n",mName.c_str());}
	/*Y component of aVertexUvThree*/
	void setVertexUvThreeV(float t3v){if(t3v == 0.0) return; fprintf_s(mFile, "setAttr \".vt3.t3v\" %f;\n", t3v);}
	/*Y component of aVertexUvThree*/
	void setVertexUvThreeV(const FloatID& t3v){fprintf_s(mFile,"connectAttr \"");t3v.write(mFile);fprintf_s(mFile,"\" \"%s.vt3.t3v\";\n",mName.c_str());}
	/*Triangle s first vertex, in camera space*/
	void setVertexCameraOne(const float3& vc1){fprintf_s(mFile, "setAttr \".vc1\" -type \"float3\" ");vc1.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s first vertex, in camera space*/
	void setVertexCameraOne(const Float3ID& vc1){fprintf_s(mFile,"connectAttr \"");vc1.write(mFile);fprintf_s(mFile,"\" \"%s.vc1\";\n",mName.c_str());}
	/*X component of aVertexCameraOne*/
	void setVertexCameraOneX(float c1x){if(c1x == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1x\" %f;\n", c1x);}
	/*X component of aVertexCameraOne*/
	void setVertexCameraOneX(const FloatID& c1x){fprintf_s(mFile,"connectAttr \"");c1x.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1x\";\n",mName.c_str());}
	/*Y component of aVertexCameraOne*/
	void setVertexCameraOneY(float c1y){if(c1y == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1y\" %f;\n", c1y);}
	/*Y component of aVertexCameraOne*/
	void setVertexCameraOneY(const FloatID& c1y){fprintf_s(mFile,"connectAttr \"");c1y.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1y\";\n",mName.c_str());}
	/*Z component of aVertexCameraOne*/
	void setVertexCameraOneZ(float c1z){if(c1z == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1z\" %f;\n", c1z);}
	/*Z component of aVertexCameraOne*/
	void setVertexCameraOneZ(const FloatID& c1z){fprintf_s(mFile,"connectAttr \"");c1z.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1z\";\n",mName.c_str());}
	/*The current sample size that has to be shaded*/
	void setUvFilterSize(const Float2ID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setUvFilterSizeX(const FloatID& fsx){fprintf_s(mFile,"connectAttr \"");fsx.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setUvFilterSizeY(const FloatID& fsy){fprintf_s(mFile,"connectAttr \"");fsy.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsy\";\n",mName.c_str());}
	/*
	<b>UV Coverage</b> controls how much of the surface will
	be covered by the texture frame.  Its default values,
	(1 and 1) will cover the entire surface.  Reduce these
	values to shrink the texture frame.  For example, if
	you set Coverage U to 0.5, then the texture frame
	will only cover half the surface in the U direction.
	*/
	void setCoverage(const float2& c){if(c == float2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".c\" -type \"float2\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>UV Coverage</b> controls how much of the surface will
	be covered by the texture frame.  Its default values,
	(1 and 1) will cover the entire surface.  Reduce these
	values to shrink the texture frame.  For example, if
	you set Coverage U to 0.5, then the texture frame
	will only cover half the surface in the U direction.
	*/
	void setCoverage(const Float2ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*
	<b>Coverage U</b> controls how much of the surface's
	U-direction will be covered by the texture.
	*/
	void setCoverageU(float cu){if(cu == 0.0) return; fprintf_s(mFile, "setAttr \".c.cu\" %f;\n", cu);}
	/*
	<b>Coverage U</b> controls how much of the surface's
	U-direction will be covered by the texture.
	*/
	void setCoverageU(const FloatID& cu){fprintf_s(mFile,"connectAttr \"");cu.write(mFile);fprintf_s(mFile,"\" \"%s.c.cu\";\n",mName.c_str());}
	/*
	<b>Coverage V</b> controls how much of the surface's
	V-direction will be covered by the texture.
	*/
	void setCoverageV(float cv){if(cv == 0.0) return; fprintf_s(mFile, "setAttr \".c.cv\" %f;\n", cv);}
	/*
	<b>Coverage V</b> controls how much of the surface's
	V-direction will be covered by the texture.
	*/
	void setCoverageV(const FloatID& cv){fprintf_s(mFile,"connectAttr \"");cv.write(mFile);fprintf_s(mFile,"\" \"%s.c.cv\";\n",mName.c_str());}
	/*
	<b>Translate Frame</b> controls the position of the
	texture frame, relative to the UV origin of the surface.
	(That is, the corner of the surface where U and V are zero).
	Increase these values to move the texture frame away from
	the corner.  If you set Translate Frame U to 0.5, the
	texture frame will be shifted half-way along the surface.
	*/
	void setTranslateFrame(const float2& tf){if(tf == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".tf\" -type \"float2\" ");tf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Translate Frame</b> controls the position of the
	texture frame, relative to the UV origin of the surface.
	(That is, the corner of the surface where U and V are zero).
	Increase these values to move the texture frame away from
	the corner.  If you set Translate Frame U to 0.5, the
	texture frame will be shifted half-way along the surface.
	*/
	void setTranslateFrame(const Float2ID& tf){fprintf_s(mFile,"connectAttr \"");tf.write(mFile);fprintf_s(mFile,"\" \"%s.tf\";\n",mName.c_str());}
	/*
	<b>Translate Frame U</b> controls the U-position of the
	texture frame.  (see above)
	*/
	void setTranslateFrameU(float tfu){if(tfu == 0.0) return; fprintf_s(mFile, "setAttr \".tf.tfu\" %f;\n", tfu);}
	/*
	<b>Translate Frame U</b> controls the U-position of the
	texture frame.  (see above)
	*/
	void setTranslateFrameU(const FloatID& tfu){fprintf_s(mFile,"connectAttr \"");tfu.write(mFile);fprintf_s(mFile,"\" \"%s.tf.tfu\";\n",mName.c_str());}
	/*
	<b>Translate Frame V</b> controls the V-position of the
	texture frame.  (see above)
	*/
	void setTranslateFrameV(float tfv){if(tfv == 0.0) return; fprintf_s(mFile, "setAttr \".tf.tfv\" %f;\n", tfv);}
	/*
	<b>Translate Frame V</b> controls the V-position of the
	texture frame.  (see above)
	*/
	void setTranslateFrameV(const FloatID& tfv){fprintf_s(mFile,"connectAttr \"");tfv.write(mFile);fprintf_s(mFile,"\" \"%s.tf.tfv\";\n",mName.c_str());}
	/*
	<b>Rotate Frame</b> controls how much the texture frame
	is rotated relative to the surface.
	*/
	void setRotateFrame(double rf){if(rf == 0) return; fprintf_s(mFile, "setAttr \".rf\" %f;\n", rf);}
	/*
	<b>Rotate Frame</b> controls how much the texture frame
	is rotated relative to the surface.
	*/
	void setRotateFrame(const DoubleID& rf){fprintf_s(mFile,"connectAttr \"");rf.write(mFile);fprintf_s(mFile,"\" \"%s.rf\";\n",mName.c_str());}
	/*
	<b>MirrorU</b> controls how texture tiles are placed
	beside each other.  When MirrorU is turned on, then
	each copy of the texture will be the mirror image of
	the ones on the U sides of it, with their shared
	edge being the (V) axis of reflection.
	<ul>
	MirrorU OFF:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|       **  **  **
	|       *   *   *
	</pre><p/>
	MirrorU ON:
	<p/><pre>
	|      *    *  *
	|      **  **  **
	|
	|      *    *  *
	|      **  **  **
	</pre>
	</ul>
	<p/>
	Textures are tiled when Repeat U or Repeat V is greater than 1.
	*/
	void setMirrorU(bool mu){if(mu == false) return; fprintf_s(mFile, "setAttr \".mu\" %i;\n", mu);}
	/*
	<b>MirrorU</b> controls how texture tiles are placed
	beside each other.  When MirrorU is turned on, then
	each copy of the texture will be the mirror image of
	the ones on the U sides of it, with their shared
	edge being the (V) axis of reflection.
	<ul>
	MirrorU OFF:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|       **  **  **
	|       *   *   *
	</pre><p/>
	MirrorU ON:
	<p/><pre>
	|      *    *  *
	|      **  **  **
	|
	|      *    *  *
	|      **  **  **
	</pre>
	</ul>
	<p/>
	Textures are tiled when Repeat U or Repeat V is greater than 1.
	*/
	void setMirrorU(const BoolID& mu){fprintf_s(mFile,"connectAttr \"");mu.write(mFile);fprintf_s(mFile,"\" \"%s.mu\";\n",mName.c_str());}
	/*
	<b>MirrorV</b> controls how texture tiles are placed
	beside each other.  When MirrorV is turned on, then
	each copy of the texture will be the mirror image of
	the ones on all V sides of it, with their shared
	edge being the (U) axis of reflection.
	<ul>
	MirrorV OFF:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|       **  **  **
	|       *   *   *
	</pre><p/>
	MirrorV ON:
	<p/><pre>
	|      **  **  **
	|      *   *   *
	|
	|      *   *   *
	|      **  **  **
	</pre>
	</ul>
	<p/>
	Textures are tiled when Repeat U or Repeat V is greater than 1.
	*/
	void setMirrorV(bool mv){if(mv == false) return; fprintf_s(mFile, "setAttr \".mv\" %i;\n", mv);}
	/*
	<b>MirrorV</b> controls how texture tiles are placed
	beside each other.  When MirrorV is turned on, then
	each copy of the texture will be the mirror image of
	the ones on all V sides of it, with their shared
	edge being the (U) axis of reflection.
	<ul>
	MirrorV OFF:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|       **  **  **
	|       *   *   *
	</pre><p/>
	MirrorV ON:
	<p/><pre>
	|      **  **  **
	|      *   *   *
	|
	|      *   *   *
	|      **  **  **
	</pre>
	</ul>
	<p/>
	Textures are tiled when Repeat U or Repeat V is greater than 1.
	*/
	void setMirrorV(const BoolID& mv){fprintf_s(mFile,"connectAttr \"");mv.write(mFile);fprintf_s(mFile,"\" \"%s.mv\";\n",mName.c_str());}
	/*
	<b>Stagger</b> controls how rows of texture tiles are placed
	beside each other.  When Stagger is turned on, then
	every other row of texture tiles is offset by one-half
	its width, like rows of bricks in a brick wall.
	<ul>
	Stagger OFF:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|       **  **  **
	|       *   *   *
	</pre><p/>
	Stagger ON:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|         **  **  **
	|         *   *   *
	</pre>
	</ul>
	<p/>
	Textures are tiled when Repeat U or Repeat V is greater than 1.
	*/
	void setStagger(bool s){if(s == false) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*
	<b>Stagger</b> controls how rows of texture tiles are placed
	beside each other.  When Stagger is turned on, then
	every other row of texture tiles is offset by one-half
	its width, like rows of bricks in a brick wall.
	<ul>
	Stagger OFF:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|       **  **  **
	|       *   *   *
	</pre><p/>
	Stagger ON:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|         **  **  **
	|         *   *   *
	</pre>
	</ul>
	<p/>
	Textures are tiled when Repeat U or Repeat V is greater than 1.
	*/
	void setStagger(const BoolID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	<b>Wrap U</b> controls whether or not the texture will
	"wrap around" in the U direction.  For example, say you
	increase the value of Translate Frame U enough to push part
	of the texture frame right off the surface.  If Wrap U is
	turned off, then
	that part of the texture will be cut off and lost.  If
	Wrap U is turned on, then that part of the texture will
	be wrapped around to the other end of the surface.
	<p/>
	When you are bump mapping with the default full coverage,
	it is best to turn off Wrap U and Wrap V to avoid wrap-around
	effects on the bump.  You should also turn on Adjust Edges
	in the Bump2d node.
	*/
	void setWrapU(bool wu){if(wu == true) return; fprintf_s(mFile, "setAttr \".wu\" %i;\n", wu);}
	/*
	<b>Wrap U</b> controls whether or not the texture will
	"wrap around" in the U direction.  For example, say you
	increase the value of Translate Frame U enough to push part
	of the texture frame right off the surface.  If Wrap U is
	turned off, then
	that part of the texture will be cut off and lost.  If
	Wrap U is turned on, then that part of the texture will
	be wrapped around to the other end of the surface.
	<p/>
	When you are bump mapping with the default full coverage,
	it is best to turn off Wrap U and Wrap V to avoid wrap-around
	effects on the bump.  You should also turn on Adjust Edges
	in the Bump2d node.
	*/
	void setWrapU(const BoolID& wu){fprintf_s(mFile,"connectAttr \"");wu.write(mFile);fprintf_s(mFile,"\" \"%s.wu\";\n",mName.c_str());}
	/*
	<b>Wrap V</b> controls whether or not the texture will
	"wrap around" in the V direction.  For example, say you
	increase the value of Translate Frame V enough to push part
	of the texture frame right off the surface.  If Wrap V is
	turned off, then
	that part of the texture will be cut off and lost.  If
	Wrap V is turned on, then that part of the texture will
	be wrapped around to the other end of the surface.
	<p/>When you are bump mapping with the default full coverage,
	it is best to turn off Wrap U and Wrap V to avoid wrap-around
	effects on the bump.  You should also turn on Adjust Edges
	in the Bump2d node.
	*/
	void setWrapV(bool wv){if(wv == true) return; fprintf_s(mFile, "setAttr \".wv\" %i;\n", wv);}
	/*
	<b>Wrap V</b> controls whether or not the texture will
	"wrap around" in the V direction.  For example, say you
	increase the value of Translate Frame V enough to push part
	of the texture frame right off the surface.  If Wrap V is
	turned off, then
	that part of the texture will be cut off and lost.  If
	Wrap V is turned on, then that part of the texture will
	be wrapped around to the other end of the surface.
	<p/>When you are bump mapping with the default full coverage,
	it is best to turn off Wrap U and Wrap V to avoid wrap-around
	effects on the bump.  You should also turn on Adjust Edges
	in the Bump2d node.
	*/
	void setWrapV(const BoolID& wv){fprintf_s(mFile,"connectAttr \"");wv.write(mFile);fprintf_s(mFile,"\" \"%s.wv\";\n",mName.c_str());}
	/*
	<b>RepeatUV</b> controls how many times the basic
	texture is repeated (tiled) within the texture frame.
	*/
	void setRepeatUV(const float2& re){if(re == float2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".re\" -type \"float2\" ");re.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>RepeatUV</b> controls how many times the basic
	texture is repeated (tiled) within the texture frame.
	*/
	void setRepeatUV(const Float2ID& re){fprintf_s(mFile,"connectAttr \"");re.write(mFile);fprintf_s(mFile,"\" \"%s.re\";\n",mName.c_str());}
	/*
	<b>Repeat U</b> controls how many times the besic
	texture is repeated in the U direction.
	*/
	void setRepeatU(float reu){if(reu == 0.0) return; fprintf_s(mFile, "setAttr \".re.reu\" %f;\n", reu);}
	/*
	<b>Repeat U</b> controls how many times the besic
	texture is repeated in the U direction.
	*/
	void setRepeatU(const FloatID& reu){fprintf_s(mFile,"connectAttr \"");reu.write(mFile);fprintf_s(mFile,"\" \"%s.re.reu\";\n",mName.c_str());}
	/*
	<b>Repeat V</b> controls how many times the besic
	texture is repeated in the V direction.
	*/
	void setRepeatV(float rev){if(rev == 0.0) return; fprintf_s(mFile, "setAttr \".re.rev\" %f;\n", rev);}
	/*
	<b>Repeat V</b> controls how many times the besic
	texture is repeated in the V direction.
	*/
	void setRepeatV(const FloatID& rev){fprintf_s(mFile,"connectAttr \"");rev.write(mFile);fprintf_s(mFile,"\" \"%s.re.rev\";\n",mName.c_str());}
	/*
	<b>Offset</b> controls the position of the texture
	tiles within the texture frame.  If it is set to
	0, 0, then the starting edge of the first texture tile will line up
	exactly with the starting edge of the frame.  if it
	is set to 0.5, then the half-way point of the first texture tile
	will be positioned at start edge of the texture frame.
	*/
	void setOffset(const float2& of){if(of == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".of\" -type \"float2\" ");of.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Offset</b> controls the position of the texture
	tiles within the texture frame.  If it is set to
	0, 0, then the starting edge of the first texture tile will line up
	exactly with the starting edge of the frame.  if it
	is set to 0.5, then the half-way point of the first texture tile
	will be positioned at start edge of the texture frame.
	*/
	void setOffset(const Float2ID& of){fprintf_s(mFile,"connectAttr \"");of.write(mFile);fprintf_s(mFile,"\" \"%s.of\";\n",mName.c_str());}
	/*<b>Offset U</b> is the U component of Offset.*/
	void setOffsetU(float ofu){if(ofu == 0.0) return; fprintf_s(mFile, "setAttr \".of.ofu\" %f;\n", ofu);}
	/*<b>Offset U</b> is the U component of Offset.*/
	void setOffsetU(const FloatID& ofu){fprintf_s(mFile,"connectAttr \"");ofu.write(mFile);fprintf_s(mFile,"\" \"%s.of.ofu\";\n",mName.c_str());}
	/*<b>Offset V</b> is the V component of Offset.*/
	void setOffsetV(float ofv){if(ofv == 0.0) return; fprintf_s(mFile, "setAttr \".of.ofv\" %f;\n", ofv);}
	/*<b>Offset V</b> is the V component of Offset.*/
	void setOffsetV(const FloatID& ofv){fprintf_s(mFile,"connectAttr \"");ofv.write(mFile);fprintf_s(mFile,"\" \"%s.of.ofv\";\n",mName.c_str());}
	/*
	<b>Rotate UV</b> controls how much the texture is
	rotated within the texture frame.  (The frame itself is
	not rotated.  To rotate the frame, use the Rotate Frame
	attribute instead).
	*/
	void setRotateUV(double r){if(r == 0) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*
	<b>Rotate UV</b> controls how much the texture is
	rotated within the texture frame.  (The frame itself is
	not rotated.  To rotate the frame, use the Rotate Frame
	attribute instead).
	*/
	void setRotateUV(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The 2D noise for U and V*/
	void setNoiseUV(const float2& n){if(n == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".n\" -type \"float2\" ");n.write(mFile);fprintf_s(mFile,";\n");}
	/*The 2D noise for U and V*/
	void setNoiseUV(const Float2ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The U noise*/
	void setNoiseU(float nu){if(nu == 0.0) return; fprintf_s(mFile, "setAttr \".n.nu\" %f;\n", nu);}
	/*The U noise*/
	void setNoiseU(const FloatID& nu){fprintf_s(mFile,"connectAttr \"");nu.write(mFile);fprintf_s(mFile,"\" \"%s.n.nu\";\n",mName.c_str());}
	/*The V noise*/
	void setNoiseV(float nv){if(nv == 0.0) return; fprintf_s(mFile, "setAttr \".n.nv\" %f;\n", nv);}
	/*The V noise*/
	void setNoiseV(const FloatID& nv){fprintf_s(mFile,"connectAttr \"");nv.write(mFile);fprintf_s(mFile,"\" \"%s.n.nv\";\n",mName.c_str());}
	/*
	<b>Fast</b> is an optimation you can use under
	certain rare circumstances to speed up calculation
	in this node.  It will only work if Coverage and Repeat is 1,
	all the translates, rotates, and offsets are 0 and
	Mirror, Stagger, and Wrap are all turned off.
	<p/>If you are unsure about using this, it is best to
	just leave it turned off.
	*/
	void setFast(bool fa){if(fa == false) return; fprintf_s(mFile, "setAttr \".fa\" %i;\n", fa);}
	/*
	<b>Fast</b> is an optimation you can use under
	certain rare circumstances to speed up calculation
	in this node.  It will only work if Coverage and Repeat is 1,
	all the translates, rotates, and offsets are 0 and
	Mirror, Stagger, and Wrap are all turned off.
	<p/>If you are unsure about using this, it is best to
	just leave it turned off.
	*/
	void setFast(const BoolID& fa){fprintf_s(mFile,"connectAttr \"");fa.write(mFile);fprintf_s(mFile,"\" \"%s.fa\";\n",mName.c_str());}
	/*
	<b>Out UV</b>:  This attribute should be connected
	to the UV Coord attribute of the 2d texture being placed.
	*/
	void setOutUV(const Float2ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The U component of OutUV*/
	void setOutU(const FloatID& ou){fprintf_s(mFile,"connectAttr \"");ou.write(mFile);fprintf_s(mFile,"\" \"%s.o.ou\";\n",mName.c_str());}
	/*The V component of OutUV*/
	void setOutV(const FloatID& ov){fprintf_s(mFile,"connectAttr \"");ov.write(mFile);fprintf_s(mFile,"\" \"%s.o.ov\";\n",mName.c_str());}
	/*
	<b>Out UV Filter Size</b>: This attribute should be
	connected to the UV Filter Size attribute of the 2d
	texture being placed.
	*/
	void setOutUvFilterSize(const Float2ID& ofs){fprintf_s(mFile,"connectAttr \"");ofs.write(mFile);fprintf_s(mFile,"\" \"%s.ofs\";\n",mName.c_str());}
	/*The x component of Out UV Filter Size*/
	void setOutUvFilterSizeX(const FloatID& ofsx){fprintf_s(mFile,"connectAttr \"");ofsx.write(mFile);fprintf_s(mFile,"\" \"%s.ofs.ofsx\";\n",mName.c_str());}
	/*The y component of Out UV Filter Size*/
	void setOutUvFilterSizeY(const FloatID& ofsy){fprintf_s(mFile,"connectAttr \"");ofsy.write(mFile);fprintf_s(mFile,"\" \"%s.ofs.ofsy\";\n",mName.c_str());}
	/*This output tells if the transformations must be applied*/
	void setDoTransform(const BoolID& do_){fprintf_s(mFile,"connectAttr \"");do_.write(mFile);fprintf_s(mFile,"\" \"%s.do\";\n",mName.c_str());}
	/*The UV coords of the current sample point*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.u",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.v",mName.c_str());return (const char*)buffer;}
	/*Triangle s first vertex, in texture space*/
	Float2ID getVertexUvOne(){char buffer[4096];sprintf_s (buffer, "%s.vt1",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexUvOne*/
	FloatID getVertexUvOneU(){char buffer[4096];sprintf_s (buffer, "%s.vt1.t1u",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexUvOne*/
	FloatID getVertexUvOneV(){char buffer[4096];sprintf_s (buffer, "%s.vt1.t1v",mName.c_str());return (const char*)buffer;}
	/*Triangle s second vertex, in texture space*/
	Float2ID getVertexUvTwo(){char buffer[4096];sprintf_s (buffer, "%s.vt2",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexUvTwo*/
	FloatID getVertexUvTwoU(){char buffer[4096];sprintf_s (buffer, "%s.vt2.t2u",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexUvTwo*/
	FloatID getVertexUvTwoV(){char buffer[4096];sprintf_s (buffer, "%s.vt2.t2v",mName.c_str());return (const char*)buffer;}
	/*Triangle s third vertex, in texture space*/
	Float2ID getVertexUvThree(){char buffer[4096];sprintf_s (buffer, "%s.vt3",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexUvThree*/
	FloatID getVertexUvThreeU(){char buffer[4096];sprintf_s (buffer, "%s.vt3.t3u",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexUvThree*/
	FloatID getVertexUvThreeV(){char buffer[4096];sprintf_s (buffer, "%s.vt3.t3v",mName.c_str());return (const char*)buffer;}
	/*Triangle s first vertex, in camera space*/
	Float3ID getVertexCameraOne(){char buffer[4096];sprintf_s (buffer, "%s.vc1",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexCameraOne*/
	FloatID getVertexCameraOneX(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1x",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexCameraOne*/
	FloatID getVertexCameraOneY(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1y",mName.c_str());return (const char*)buffer;}
	/*Z component of aVertexCameraOne*/
	FloatID getVertexCameraOneZ(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1z",mName.c_str());return (const char*)buffer;}
	/*The current sample size that has to be shaded*/
	Float2ID getUvFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.fs",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getUvFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getUvFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsy",mName.c_str());return (const char*)buffer;}
	/*
	<b>UV Coverage</b> controls how much of the surface will
	be covered by the texture frame.  Its default values,
	(1 and 1) will cover the entire surface.  Reduce these
	values to shrink the texture frame.  For example, if
	you set Coverage U to 0.5, then the texture frame
	will only cover half the surface in the U direction.
	*/
	Float2ID getCoverage(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*
	<b>Coverage U</b> controls how much of the surface's
	U-direction will be covered by the texture.
	*/
	FloatID getCoverageU(){char buffer[4096];sprintf_s (buffer, "%s.c.cu",mName.c_str());return (const char*)buffer;}
	/*
	<b>Coverage V</b> controls how much of the surface's
	V-direction will be covered by the texture.
	*/
	FloatID getCoverageV(){char buffer[4096];sprintf_s (buffer, "%s.c.cv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Translate Frame</b> controls the position of the
	texture frame, relative to the UV origin of the surface.
	(That is, the corner of the surface where U and V are zero).
	Increase these values to move the texture frame away from
	the corner.  If you set Translate Frame U to 0.5, the
	texture frame will be shifted half-way along the surface.
	*/
	Float2ID getTranslateFrame(){char buffer[4096];sprintf_s (buffer, "%s.tf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Translate Frame U</b> controls the U-position of the
	texture frame.  (see above)
	*/
	FloatID getTranslateFrameU(){char buffer[4096];sprintf_s (buffer, "%s.tf.tfu",mName.c_str());return (const char*)buffer;}
	/*
	<b>Translate Frame V</b> controls the V-position of the
	texture frame.  (see above)
	*/
	FloatID getTranslateFrameV(){char buffer[4096];sprintf_s (buffer, "%s.tf.tfv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Rotate Frame</b> controls how much the texture frame
	is rotated relative to the surface.
	*/
	DoubleID getRotateFrame(){char buffer[4096];sprintf_s (buffer, "%s.rf",mName.c_str());return (const char*)buffer;}
	/*
	<b>MirrorU</b> controls how texture tiles are placed
	beside each other.  When MirrorU is turned on, then
	each copy of the texture will be the mirror image of
	the ones on the U sides of it, with their shared
	edge being the (V) axis of reflection.
	<ul>
	MirrorU OFF:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|       **  **  **
	|       *   *   *
	</pre><p/>
	MirrorU ON:
	<p/><pre>
	|      *    *  *
	|      **  **  **
	|
	|      *    *  *
	|      **  **  **
	</pre>
	</ul>
	<p/>
	Textures are tiled when Repeat U or Repeat V is greater than 1.
	*/
	BoolID getMirrorU(){char buffer[4096];sprintf_s (buffer, "%s.mu",mName.c_str());return (const char*)buffer;}
	/*
	<b>MirrorV</b> controls how texture tiles are placed
	beside each other.  When MirrorV is turned on, then
	each copy of the texture will be the mirror image of
	the ones on all V sides of it, with their shared
	edge being the (U) axis of reflection.
	<ul>
	MirrorV OFF:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|       **  **  **
	|       *   *   *
	</pre><p/>
	MirrorV ON:
	<p/><pre>
	|      **  **  **
	|      *   *   *
	|
	|      *   *   *
	|      **  **  **
	</pre>
	</ul>
	<p/>
	Textures are tiled when Repeat U or Repeat V is greater than 1.
	*/
	BoolID getMirrorV(){char buffer[4096];sprintf_s (buffer, "%s.mv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Stagger</b> controls how rows of texture tiles are placed
	beside each other.  When Stagger is turned on, then
	every other row of texture tiles is offset by one-half
	its width, like rows of bricks in a brick wall.
	<ul>
	Stagger OFF:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|       **  **  **
	|       *   *   *
	</pre><p/>
	Stagger ON:
	<p/><pre>
	|       **  **  **
	|       *   *   *
	|
	|         **  **  **
	|         *   *   *
	</pre>
	</ul>
	<p/>
	Textures are tiled when Repeat U or Repeat V is greater than 1.
	*/
	BoolID getStagger(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wrap U</b> controls whether or not the texture will
	"wrap around" in the U direction.  For example, say you
	increase the value of Translate Frame U enough to push part
	of the texture frame right off the surface.  If Wrap U is
	turned off, then
	that part of the texture will be cut off and lost.  If
	Wrap U is turned on, then that part of the texture will
	be wrapped around to the other end of the surface.
	<p/>
	When you are bump mapping with the default full coverage,
	it is best to turn off Wrap U and Wrap V to avoid wrap-around
	effects on the bump.  You should also turn on Adjust Edges
	in the Bump2d node.
	*/
	BoolID getWrapU(){char buffer[4096];sprintf_s (buffer, "%s.wu",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wrap V</b> controls whether or not the texture will
	"wrap around" in the V direction.  For example, say you
	increase the value of Translate Frame V enough to push part
	of the texture frame right off the surface.  If Wrap V is
	turned off, then
	that part of the texture will be cut off and lost.  If
	Wrap V is turned on, then that part of the texture will
	be wrapped around to the other end of the surface.
	<p/>When you are bump mapping with the default full coverage,
	it is best to turn off Wrap U and Wrap V to avoid wrap-around
	effects on the bump.  You should also turn on Adjust Edges
	in the Bump2d node.
	*/
	BoolID getWrapV(){char buffer[4096];sprintf_s (buffer, "%s.wv",mName.c_str());return (const char*)buffer;}
	/*
	<b>RepeatUV</b> controls how many times the basic
	texture is repeated (tiled) within the texture frame.
	*/
	Float2ID getRepeatUV(){char buffer[4096];sprintf_s (buffer, "%s.re",mName.c_str());return (const char*)buffer;}
	/*
	<b>Repeat U</b> controls how many times the besic
	texture is repeated in the U direction.
	*/
	FloatID getRepeatU(){char buffer[4096];sprintf_s (buffer, "%s.re.reu",mName.c_str());return (const char*)buffer;}
	/*
	<b>Repeat V</b> controls how many times the besic
	texture is repeated in the V direction.
	*/
	FloatID getRepeatV(){char buffer[4096];sprintf_s (buffer, "%s.re.rev",mName.c_str());return (const char*)buffer;}
	/*
	<b>Offset</b> controls the position of the texture
	tiles within the texture frame.  If it is set to
	0, 0, then the starting edge of the first texture tile will line up
	exactly with the starting edge of the frame.  if it
	is set to 0.5, then the half-way point of the first texture tile
	will be positioned at start edge of the texture frame.
	*/
	Float2ID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.of",mName.c_str());return (const char*)buffer;}
	/*<b>Offset U</b> is the U component of Offset.*/
	FloatID getOffsetU(){char buffer[4096];sprintf_s (buffer, "%s.of.ofu",mName.c_str());return (const char*)buffer;}
	/*<b>Offset V</b> is the V component of Offset.*/
	FloatID getOffsetV(){char buffer[4096];sprintf_s (buffer, "%s.of.ofv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Rotate UV</b> controls how much the texture is
	rotated within the texture frame.  (The frame itself is
	not rotated.  To rotate the frame, use the Rotate Frame
	attribute instead).
	*/
	DoubleID getRotateUV(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The 2D noise for U and V*/
	Float2ID getNoiseUV(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The U noise*/
	FloatID getNoiseU(){char buffer[4096];sprintf_s (buffer, "%s.n.nu",mName.c_str());return (const char*)buffer;}
	/*The V noise*/
	FloatID getNoiseV(){char buffer[4096];sprintf_s (buffer, "%s.n.nv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fast</b> is an optimation you can use under
	certain rare circumstances to speed up calculation
	in this node.  It will only work if Coverage and Repeat is 1,
	all the translates, rotates, and offsets are 0 and
	Mirror, Stagger, and Wrap are all turned off.
	<p/>If you are unsure about using this, it is best to
	just leave it turned off.
	*/
	BoolID getFast(){char buffer[4096];sprintf_s (buffer, "%s.fa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out UV</b>:  This attribute should be connected
	to the UV Coord attribute of the 2d texture being placed.
	*/
	Float2ID getOutUV(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The U component of OutUV*/
	FloatID getOutU(){char buffer[4096];sprintf_s (buffer, "%s.o.ou",mName.c_str());return (const char*)buffer;}
	/*The V component of OutUV*/
	FloatID getOutV(){char buffer[4096];sprintf_s (buffer, "%s.o.ov",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out UV Filter Size</b>: This attribute should be
	connected to the UV Filter Size attribute of the 2d
	texture being placed.
	*/
	Float2ID getOutUvFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.ofs",mName.c_str());return (const char*)buffer;}
	/*The x component of Out UV Filter Size*/
	FloatID getOutUvFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.ofs.ofsx",mName.c_str());return (const char*)buffer;}
	/*The y component of Out UV Filter Size*/
	FloatID getOutUvFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.ofs.ofsy",mName.c_str());return (const char*)buffer;}
	/*This output tells if the transformations must be applied*/
	BoolID getDoTransform(){char buffer[4096];sprintf_s (buffer, "%s.do",mName.c_str());return (const char*)buffer;}
protected:
	Place2dTexture(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PLACE2DTEXTURE_H__
