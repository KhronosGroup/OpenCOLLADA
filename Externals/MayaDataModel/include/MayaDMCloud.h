/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOUD_H__
#define __MayaDM_CLOUD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
<b>Cloud</b> textures are used to create effects such as clouds,
 smoke, and steam.  It can be applied as a transparency map to another
 shader to make it cloud-like, or can be used as a color map to make
 a cloudy surface on an object.
<p/>
 Tips for creating a good cloud effect:
 <ul>
   <li>Create an ellipsoidal object (say, a sphere).</li>
   <li>Create a lambert shader.  Make it the color you want your
 cloud to be.  Make sure its Refractive Index is 1.0, and assign it
 to your object.</li>
   <li>Apply a Cloud texture as a Transparency map to the shader.</li>
   <li>In the Cloud attribute editor, set both colors to white, and
 turn on Invert under the Effects tab.</li>
   <li>The object will look like a wispy cloud.</li>
   <li>If you turn off Invert, the sphere will look like a
 round glass with a cloudy center.</li>
</ul>
<p/>
 Aside from the attributes listed here, Cloud textures inherit many
 other attributes from the parent class <a href="texture3d.html">Texture3d</a>.
<p/>
 In the table below, important attributes have their names shown in
 <b>bold</b> in the Description column.
*/
class Cloud : public Texture3d
{
public:
public:
	Cloud(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "cloud"){}
	virtual ~Cloud(){}
	/*The input normal to perturbate*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The X component of the input normal*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The Y component of the input normal*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The Z component of the input normal*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointObj(const Float3ID& rpo){fprintf_s(mFile,"connectAttr \"");rpo.write(mFile);fprintf_s(mFile,"\" \"%s.rpo\";\n",mName.c_str());}
	/*The x component of the current reference sample position*/
	void setRefPointObjX(const FloatID& rox){fprintf_s(mFile,"connectAttr \"");rox.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.rox\";\n",mName.c_str());}
	/*The y component of the current reference sample position*/
	void setRefPointObjY(const FloatID& roy){fprintf_s(mFile,"connectAttr \"");roy.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.roy\";\n",mName.c_str());}
	/*The z component of the current reference sample position*/
	void setRefPointObjZ(const FloatID& roz){fprintf_s(mFile,"connectAttr \"");roz.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.roz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointCamera(const Float3ID& rpc){fprintf_s(mFile,"connectAttr \"");rpc.write(mFile);fprintf_s(mFile,"\" \"%s.rpc\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setRefPointCameraX(const FloatID& rcx){fprintf_s(mFile,"connectAttr \"");rcx.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setRefPointCameraY(const FloatID& rcy){fprintf_s(mFile,"connectAttr \"");rcy.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setRefPointCameraZ(const FloatID& rcz){fprintf_s(mFile,"connectAttr \"");rcz.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcz\";\n",mName.c_str());}
	/*The pixel angle*/
	void setXPixelAngle(float xpa){if(xpa == 0.002053) return; fprintf_s(mFile, "setAttr \".xpa\" %f;\n", xpa);}
	/*The transform to go from eye to texture space (pTx = pEye * matrix). It must come from the 3D placement node.*/
	void setEyeToTextureMatrix(const FltMatrixID& e2t){fprintf_s(mFile,"connectAttr \"");e2t.write(mFile);fprintf_s(mFile,"\" \"%s.e2t\";\n",mName.c_str());}
	/*
	<b>Color 1</b> is one of the two colors that comprise
	the cloud.
	*/
	void setColor1(const float3& c1){if(c1 == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".c1\" -type \"float3\" ");c1.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color 1</b> is one of the two colors that comprise
	the cloud.
	*/
	void setColor1(const Float3ID& c1){fprintf_s(mFile,"connectAttr \"");c1.write(mFile);fprintf_s(mFile,"\" \"%s.c1\";\n",mName.c_str());}
	/*The red value of Color 1*/
	void setColor1R(float c1r){if(c1r == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1r\" %f;\n", c1r);}
	/*The red value of Color 1*/
	void setColor1R(const FloatID& c1r){fprintf_s(mFile,"connectAttr \"");c1r.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1r\";\n",mName.c_str());}
	/*The green value of Color 1*/
	void setColor1G(float c1g){if(c1g == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1g\" %f;\n", c1g);}
	/*The green value of Color 1*/
	void setColor1G(const FloatID& c1g){fprintf_s(mFile,"connectAttr \"");c1g.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1g\";\n",mName.c_str());}
	/*The blue value of Color 1*/
	void setColor1B(float c1b){if(c1b == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1b\" %f;\n", c1b);}
	/*The blue value of Color 1*/
	void setColor1B(const FloatID& c1b){fprintf_s(mFile,"connectAttr \"");c1b.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1b\";\n",mName.c_str());}
	/*
	<b>Color 2</b> is one of the two colors that comprise
	the cloud.
	*/
	void setColor2(const float3& c2){if(c2 == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".c2\" -type \"float3\" ");c2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color 2</b> is one of the two colors that comprise
	the cloud.
	*/
	void setColor2(const Float3ID& c2){fprintf_s(mFile,"connectAttr \"");c2.write(mFile);fprintf_s(mFile,"\" \"%s.c2\";\n",mName.c_str());}
	/*The red value of Color 2*/
	void setColor2R(float c2r){if(c2r == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2r\" %f;\n", c2r);}
	/*The red value of Color 2*/
	void setColor2R(const FloatID& c2r){fprintf_s(mFile,"connectAttr \"");c2r.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2r\";\n",mName.c_str());}
	/*The green  of the Color 2*/
	void setColor2G(float c2g){if(c2g == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2g\" %f;\n", c2g);}
	/*The green  of the Color 2*/
	void setColor2G(const FloatID& c2g){fprintf_s(mFile,"connectAttr \"");c2g.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2g\";\n",mName.c_str());}
	/*The blue  of the Color 2*/
	void setColor2B(float c2b){if(c2b == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2b\" %f;\n", c2b);}
	/*The blue  of the Color 2*/
	void setColor2B(const FloatID& c2b){fprintf_s(mFile,"connectAttr \"");c2b.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2b\";\n",mName.c_str());}
	/*
	<b>Contrast</b> controls how much the two colors that
	comprise the cloud mix together.  If Contrast is set to
	0, the two colors are averaged across the entire texture.
	If contrast is set to 1.0, the colors do not affect each
	other at all.
	<p/>
	If the Cloud texture is being used as a transparency
	map, this attribute will not have an appreciable effect.
	*/
	void setContrast(float c){if(c == 0.5) return; fprintf_s(mFile, "setAttr \".c\" %f;\n", c);}
	/*
	<b>Contrast</b> controls how much the two colors that
	comprise the cloud mix together.  If Contrast is set to
	0, the two colors are averaged across the entire texture.
	If contrast is set to 1.0, the colors do not affect each
	other at all.
	<p/>
	If the Cloud texture is being used as a transparency
	map, this attribute will not have an appreciable effect.
	*/
	void setContrast(const FloatID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*
	<b>Soft Edges</b> creates a roll-off effect so that the
	clouds look more transparent at the edges than in the
	center.  When Soft Edges is turned off, there is no such
	effect.  See also Center Thresh and Edge Thresh.
	*/
	void setSoftEdges(bool se){if(se == true) return; fprintf_s(mFile, "setAttr \".se\" %i;\n", se);}
	/*
	<b>Soft Edges</b> creates a roll-off effect so that the
	clouds look more transparent at the edges than in the
	center.  When Soft Edges is turned off, there is no such
	effect.  See also Center Thresh and Edge Thresh.
	*/
	void setSoftEdges(const BoolID& se){fprintf_s(mFile,"connectAttr \"");se.write(mFile);fprintf_s(mFile,"\" \"%s.se\";\n",mName.c_str());}
	/*
	<b>Transparency Range</b> controls the range over which
	the cloud texture goes from being opaque to being
	transparent.  If you increase this value, the transition
	between opaque and transparent areas becomes more gentle
	and diffuse.
	*/
	void setTranspRange(float tr){if(tr == 0.5) return; fprintf_s(mFile, "setAttr \".tr\" %f;\n", tr);}
	/*
	<b>Transparency Range</b> controls the range over which
	the cloud texture goes from being opaque to being
	transparent.  If you increase this value, the transition
	between opaque and transparent areas becomes more gentle
	and diffuse.
	*/
	void setTranspRange(const FloatID& tr){fprintf_s(mFile,"connectAttr \"");tr.write(mFile);fprintf_s(mFile,"\" \"%s.tr\";\n",mName.c_str());}
	/*
	<b>Center Thresh</b>, along with <b>Edge Thresh</b>, determines
	how diffuse or concentrated the Edge Rolloff is.  For a dense
	cotton-ball effect, use a low Center Thresh with a high
	Edge Thresh.  For a wispy, broken-up cloud effect use a
	high Center Thresh and a low Edge Thresh.
	*/
	void setCenterThresh(float ct){if(ct == 0.0) return; fprintf_s(mFile, "setAttr \".ct\" %f;\n", ct);}
	/*
	<b>Center Thresh</b>, along with <b>Edge Thresh</b>, determines
	how diffuse or concentrated the Edge Rolloff is.  For a dense
	cotton-ball effect, use a low Center Thresh with a high
	Edge Thresh.  For a wispy, broken-up cloud effect use a
	high Center Thresh and a low Edge Thresh.
	*/
	void setCenterThresh(const FloatID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*<b>Edge Thresh</b>.  See the description for Center Thresh, above.*/
	void setEdgeThresh(float et){if(et == 1.0) return; fprintf_s(mFile, "setAttr \".et\" %f;\n", et);}
	/*<b>Edge Thresh</b>.  See the description for Center Thresh, above.*/
	void setEdgeThresh(const FloatID& et){fprintf_s(mFile,"connectAttr \"");et.write(mFile);fprintf_s(mFile,"\" \"%s.et\";\n",mName.c_str());}
	/*
	<b>Ripples</b> determines how wavy the texture will be
	by controlling the scale of the fundamental frequence
	of the fractals.
	*/
	void setRipples(const float3& r){if(r == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".r\" -type \"float3\" ");r.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Ripples</b> determines how wavy the texture will be
	by controlling the scale of the fundamental frequence
	of the fractals.
	*/
	void setRipples(const Float3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Ripple X value*/
	void setRipplesX(float rx){if(rx == 0.0) return; fprintf_s(mFile, "setAttr \".r.rx\" %f;\n", rx);}
	/*Ripple X value*/
	void setRipplesX(const FloatID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*Ripple Y value*/
	void setRipplesY(float ry){if(ry == 0.0) return; fprintf_s(mFile, "setAttr \".r.ry\" %f;\n", ry);}
	/*Ripple Y value*/
	void setRipplesY(const FloatID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*Ripple Z value*/
	void setRipplesZ(float rz){if(rz == 0.0) return; fprintf_s(mFile, "setAttr \".r.rz\" %f;\n", rz);}
	/*Ripple Z value*/
	void setRipplesZ(const FloatID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*
	<b>Depth</b> controls
	how much calculation is done by the
	Cloud texture.  Fractal textures (such as Cloud)
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	void setDepth(const float2& d){if(d == float2(0.0, 8.0)) return; fprintf_s(mFile, "setAttr \".d\" -type \"float2\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Depth</b> controls
	how much calculation is done by the
	Cloud texture.  Fractal textures (such as Cloud)
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	void setDepth(const Float2ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The minimum value for recursion depth*/
	void setDepthMin(float dmn){if(dmn == 0.0) return; fprintf_s(mFile, "setAttr \".d.dmn\" %f;\n", dmn);}
	/*The minimum value for recursion depth*/
	void setDepthMin(const FloatID& dmn){fprintf_s(mFile,"connectAttr \"");dmn.write(mFile);fprintf_s(mFile,"\" \"%s.d.dmn\";\n",mName.c_str());}
	/*The maximum value for recursion depth*/
	void setDepthMax(float dmx){if(dmx == 0.0) return; fprintf_s(mFile, "setAttr \".d.dmx\" %f;\n", dmx);}
	/*The maximum value for recursion depth*/
	void setDepthMax(const FloatID& dmx){fprintf_s(mFile,"connectAttr \"");dmx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dmx\";\n",mName.c_str());}
	/*
	<b>Amplitude</b> scales the effect of the fractal
	noise.  Increase Amplitude to make the texture more
	contrasty, with the light areas lighter and the dark
	areas darker.
	*/
	void setAmplitude(float a){if(a == 1.0) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*
	<b>Amplitude</b> scales the effect of the fractal
	noise.  Increase Amplitude to make the texture more
	contrasty, with the light areas lighter and the dark
	areas darker.
	*/
	void setAmplitude(const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	<b>Ratio</b> controls the ratio for the fractal noise.
	Increase Ratio to make the detail in the texture smaller
	and more fine-grained.  Decrease Ratio to make the detail
	larger, giving the cloud a more homogeneous appearance.
	*/
	void setRatio(float ra){if(ra == 0.707) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	<b>Ratio</b> controls the ratio for the fractal noise.
	Increase Ratio to make the detail in the texture smaller
	and more fine-grained.  Decrease Ratio to make the detail
	larger, giving the cloud a more homogeneous appearance.
	*/
	void setRatio(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*The input normal to perturbate*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The X component of the input normal*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the input normal*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The Z component of the input normal*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointObj(){char buffer[4096];sprintf_s (buffer, "%s.rpo",mName.c_str());return (const char*)buffer;}
	/*The x component of the current reference sample position*/
	FloatID getRefPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.rpo.rox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current reference sample position*/
	FloatID getRefPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.rpo.roy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current reference sample position*/
	FloatID getRefPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.rpo.roz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.rpc",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getRefPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getRefPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getRefPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcz",mName.c_str());return (const char*)buffer;}
	/*The transform to go from eye to texture space (pTx = pEye * matrix). It must come from the 3D placement node.*/
	FltMatrixID getEyeToTextureMatrix(){char buffer[4096];sprintf_s (buffer, "%s.e2t",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color 1</b> is one of the two colors that comprise
	the cloud.
	*/
	Float3ID getColor1(){char buffer[4096];sprintf_s (buffer, "%s.c1",mName.c_str());return (const char*)buffer;}
	/*The red value of Color 1*/
	FloatID getColor1R(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1r",mName.c_str());return (const char*)buffer;}
	/*The green value of Color 1*/
	FloatID getColor1G(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1g",mName.c_str());return (const char*)buffer;}
	/*The blue value of Color 1*/
	FloatID getColor1B(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color 2</b> is one of the two colors that comprise
	the cloud.
	*/
	Float3ID getColor2(){char buffer[4096];sprintf_s (buffer, "%s.c2",mName.c_str());return (const char*)buffer;}
	/*The red value of Color 2*/
	FloatID getColor2R(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2r",mName.c_str());return (const char*)buffer;}
	/*The green  of the Color 2*/
	FloatID getColor2G(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2g",mName.c_str());return (const char*)buffer;}
	/*The blue  of the Color 2*/
	FloatID getColor2B(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Contrast</b> controls how much the two colors that
	comprise the cloud mix together.  If Contrast is set to
	0, the two colors are averaged across the entire texture.
	If contrast is set to 1.0, the colors do not affect each
	other at all.
	<p/>
	If the Cloud texture is being used as a transparency
	map, this attribute will not have an appreciable effect.
	*/
	FloatID getContrast(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*
	<b>Soft Edges</b> creates a roll-off effect so that the
	clouds look more transparent at the edges than in the
	center.  When Soft Edges is turned off, there is no such
	effect.  See also Center Thresh and Edge Thresh.
	*/
	BoolID getSoftEdges(){char buffer[4096];sprintf_s (buffer, "%s.se",mName.c_str());return (const char*)buffer;}
	/*
	<b>Transparency Range</b> controls the range over which
	the cloud texture goes from being opaque to being
	transparent.  If you increase this value, the transition
	between opaque and transparent areas becomes more gentle
	and diffuse.
	*/
	FloatID getTranspRange(){char buffer[4096];sprintf_s (buffer, "%s.tr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Center Thresh</b>, along with <b>Edge Thresh</b>, determines
	how diffuse or concentrated the Edge Rolloff is.  For a dense
	cotton-ball effect, use a low Center Thresh with a high
	Edge Thresh.  For a wispy, broken-up cloud effect use a
	high Center Thresh and a low Edge Thresh.
	*/
	FloatID getCenterThresh(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*<b>Edge Thresh</b>.  See the description for Center Thresh, above.*/
	FloatID getEdgeThresh(){char buffer[4096];sprintf_s (buffer, "%s.et",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ripples</b> determines how wavy the texture will be
	by controlling the scale of the fundamental frequence
	of the fractals.
	*/
	Float3ID getRipples(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Ripple X value*/
	FloatID getRipplesX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*Ripple Y value*/
	FloatID getRipplesY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*Ripple Z value*/
	FloatID getRipplesZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Depth</b> controls
	how much calculation is done by the
	Cloud texture.  Fractal textures (such as Cloud)
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	Float2ID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The minimum value for recursion depth*/
	FloatID getDepthMin(){char buffer[4096];sprintf_s (buffer, "%s.d.dmn",mName.c_str());return (const char*)buffer;}
	/*The maximum value for recursion depth*/
	FloatID getDepthMax(){char buffer[4096];sprintf_s (buffer, "%s.d.dmx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Amplitude</b> scales the effect of the fractal
	noise.  Increase Amplitude to make the texture more
	contrasty, with the light areas lighter and the dark
	areas darker.
	*/
	FloatID getAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ratio</b> controls the ratio for the fractal noise.
	Increase Ratio to make the detail in the texture smaller
	and more fine-grained.  Decrease Ratio to make the detail
	larger, giving the cloud a more homogeneous appearance.
	*/
	FloatID getRatio(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
protected:
	Cloud(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLOUD_H__
