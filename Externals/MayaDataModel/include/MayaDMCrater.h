/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CRATER_H__
#define __MayaDM_CRATER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
The <b>Crater</b> texture can be used to give the appearance of
 both plateaus and craters when it is used as a bump map on a shader.
 When it is used as a color map, it provides a psychedelic, colorful
 effect.
 <p/>
 The Crater texture has a special Out Normal attribute, which you can
 connect directly to the Normal Camera of a shading node to produce
 bump mapping.  (For most textures, you connect the Out Alpha to a
 Bump 3d node, and the output of the Bump3d node to Normal Camera).
<p/>
 Aside from the attributes listed here, Crater inherits many attributes
 from <a href="texture3d.html">Texture3d</a>.
<p/>
 In the table below, important attributes have their names shown
 in <b>bold</b> in the description column.
*/
class Crater : public Texture3d
{
public:
public:
	Crater(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "crater"){}
	virtual ~Crater(){}
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
	/*
	<b>Shaker</b> controls how 'perturbed' the texture is.
	Increase Shaker to make the texture more detailed, as
	though it has been "shaken up".  If the crater node is
	being used as a bump map, increase Shaker to increase
	the number of craters and valleys.
	*/
	void setShaker(float sh){if(sh == 1.5) return; fprintf_s(mFile, "setAttr \".sh\" %f;\n", sh);}
	/*
	<b>Shaker</b> controls how 'perturbed' the texture is.
	Increase Shaker to make the texture more detailed, as
	though it has been "shaken up".  If the crater node is
	being used as a bump map, increase Shaker to increase
	the number of craters and valleys.
	*/
	void setShaker(const FloatID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*
	<b>Channel1</b> is one of the three input colors
	that are mixed together in this texture.  Changing this
	has little effect if the Crater texture is used as a
	bump map.
	*/
	void setChannel1(const float3& c1){if(c1 == float3(1.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".c1\" -type \"float3\" ");c1.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Channel1</b> is one of the three input colors
	that are mixed together in this texture.  Changing this
	has little effect if the Crater texture is used as a
	bump map.
	*/
	void setChannel1(const Float3ID& c1){fprintf_s(mFile,"connectAttr \"");c1.write(mFile);fprintf_s(mFile,"\" \"%s.c1\";\n",mName.c_str());}
	/*The red component of channel 1.*/
	void setChannel1R(float c1r){if(c1r == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1r\" %f;\n", c1r);}
	/*The red component of channel 1.*/
	void setChannel1R(const FloatID& c1r){fprintf_s(mFile,"connectAttr \"");c1r.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1r\";\n",mName.c_str());}
	/*The green component of channel 1.*/
	void setChannel1G(float c1g){if(c1g == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1g\" %f;\n", c1g);}
	/*The green component of channel 1.*/
	void setChannel1G(const FloatID& c1g){fprintf_s(mFile,"connectAttr \"");c1g.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1g\";\n",mName.c_str());}
	/*The blue component of channel 1.*/
	void setChannel1B(float c1b){if(c1b == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1b\" %f;\n", c1b);}
	/*The blue component of channel 1.*/
	void setChannel1B(const FloatID& c1b){fprintf_s(mFile,"connectAttr \"");c1b.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1b\";\n",mName.c_str());}
	/*
	<b>Channel2</b> is one of the three input colors
	that are mixed together in this texture.  Changing this
	has little effect if the Crater texture is used as a
	bump map.
	*/
	void setChannel2(const float3& c2){if(c2 == float3(0.0, 1.0, 0.0)) return; fprintf_s(mFile, "setAttr \".c2\" -type \"float3\" ");c2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Channel2</b> is one of the three input colors
	that are mixed together in this texture.  Changing this
	has little effect if the Crater texture is used as a
	bump map.
	*/
	void setChannel2(const Float3ID& c2){fprintf_s(mFile,"connectAttr \"");c2.write(mFile);fprintf_s(mFile,"\" \"%s.c2\";\n",mName.c_str());}
	/*The red component of channel 2.*/
	void setChannel2R(float c2r){if(c2r == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2r\" %f;\n", c2r);}
	/*The red component of channel 2.*/
	void setChannel2R(const FloatID& c2r){fprintf_s(mFile,"connectAttr \"");c2r.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2r\";\n",mName.c_str());}
	/*The green component of channel 2.*/
	void setChannel2G(float c2g){if(c2g == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2g\" %f;\n", c2g);}
	/*The green component of channel 2.*/
	void setChannel2G(const FloatID& c2g){fprintf_s(mFile,"connectAttr \"");c2g.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2g\";\n",mName.c_str());}
	/*The blue component of channel 2.*/
	void setChannel2B(float c2b){if(c2b == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2b\" %f;\n", c2b);}
	/*The blue component of channel 2.*/
	void setChannel2B(const FloatID& c2b){fprintf_s(mFile,"connectAttr \"");c2b.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2b\";\n",mName.c_str());}
	/*
	<b>Channel3</b> is one of the three input colors
	that are mixed together in this texture.  Changing this
	has little effect if the Crater texture is used as a
	bump map.
	*/
	void setChannel3(const float3& c3){if(c3 == float3(0.0, 0.0, 1.0)) return; fprintf_s(mFile, "setAttr \".c3\" -type \"float3\" ");c3.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Channel3</b> is one of the three input colors
	that are mixed together in this texture.  Changing this
	has little effect if the Crater texture is used as a
	bump map.
	*/
	void setChannel3(const Float3ID& c3){fprintf_s(mFile,"connectAttr \"");c3.write(mFile);fprintf_s(mFile,"\" \"%s.c3\";\n",mName.c_str());}
	/*The red component of channel 3.*/
	void setChannel3R(float c3r){if(c3r == 0.0) return; fprintf_s(mFile, "setAttr \".c3.c3r\" %f;\n", c3r);}
	/*The red component of channel 3.*/
	void setChannel3R(const FloatID& c3r){fprintf_s(mFile,"connectAttr \"");c3r.write(mFile);fprintf_s(mFile,"\" \"%s.c3.c3r\";\n",mName.c_str());}
	/*The green component of channel 3.*/
	void setChannel3G(float c3g){if(c3g == 0.0) return; fprintf_s(mFile, "setAttr \".c3.c3g\" %f;\n", c3g);}
	/*The green component of channel 3.*/
	void setChannel3G(const FloatID& c3g){fprintf_s(mFile,"connectAttr \"");c3g.write(mFile);fprintf_s(mFile,"\" \"%s.c3.c3g\";\n",mName.c_str());}
	/*The blue component of channel 3.*/
	void setChannel3B(float c3b){if(c3b == 0.0) return; fprintf_s(mFile, "setAttr \".c3.c3b\" %f;\n", c3b);}
	/*The blue component of channel 3.*/
	void setChannel3B(const FloatID& c3b){fprintf_s(mFile,"connectAttr \"");c3b.write(mFile);fprintf_s(mFile,"\" \"%s.c3.c3b\";\n",mName.c_str());}
	/*
	<b>Melt</b> controls the softness of the edges between
	the colors in the texture.  Increase Melt to make the borders
	between the colors smoother and wider.
	*/
	void setMelt(float m){if(m == 0.0) return; fprintf_s(mFile, "setAttr \".m\" %f;\n", m);}
	/*
	<b>Melt</b> controls the softness of the edges between
	the colors in the texture.  Increase Melt to make the borders
	between the colors smoother and wider.
	*/
	void setMelt(const FloatID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*
	<b>Balance</b> controls the ratio in which the three
	colors show up in the final texture.
	*/
	void setBalance(float ba){if(ba == 0.0) return; fprintf_s(mFile, "setAttr \".ba\" %f;\n", ba);}
	/*
	<b>Balance</b> controls the ratio in which the three
	colors show up in the final texture.
	*/
	void setBalance(const FloatID& ba){fprintf_s(mFile,"connectAttr \"");ba.write(mFile);fprintf_s(mFile,"\" \"%s.ba\";\n",mName.c_str());}
	/*
	<b>Frequency</b> controls the frequency of the perturbation.
	Increase frequency to increase the detail in the texture,
	decreasing the size of the detail at the same time.
	*/
	void setFrequency(float fr){if(fr == 2.0) return; fprintf_s(mFile, "setAttr \".fr\" %f;\n", fr);}
	/*
	<b>Frequency</b> controls the frequency of the perturbation.
	Increase frequency to increase the detail in the texture,
	decreasing the size of the detail at the same time.
	*/
	void setFrequency(const FloatID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*
	<b>Norm Depth</b> controls how deep the craters will be when
	this texture is used as a bump map.  Increase Norm Depth to
	make the craters deeper.
	<p/>Norm Depth only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormDepth(float nd){if(nd == 5.0) return; fprintf_s(mFile, "setAttr \".nd\" %f;\n", nd);}
	/*
	<b>Norm Depth</b> controls how deep the craters will be when
	this texture is used as a bump map.  Increase Norm Depth to
	make the craters deeper.
	<p/>Norm Depth only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormDepth(const FloatID& nd){fprintf_s(mFile,"connectAttr \"");nd.write(mFile);fprintf_s(mFile,"\" \"%s.nd\";\n",mName.c_str());}
	/*
	<b>Norm Melt</b> controls the softness of the crater edges
	when this texture is used as a bump map.  Increase Norm Melt
	to make the edges softer.  Animate this texture to make the
	cratered surface look like it is melting.
	<p/>Norm Melt only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormMelt(float nm){if(nm == 0.0) return; fprintf_s(mFile, "setAttr \".nm\" %f;\n", nm);}
	/*
	<b>Norm Melt</b> controls the softness of the crater edges
	when this texture is used as a bump map.  Increase Norm Melt
	to make the edges softer.  Animate this texture to make the
	cratered surface look like it is melting.
	<p/>Norm Melt only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormMelt(const FloatID& nm){fprintf_s(mFile,"connectAttr \"");nm.write(mFile);fprintf_s(mFile,"\" \"%s.nm\";\n",mName.c_str());}
	/*
	<b>Norm Balance</b> controls the ratio between the low and
	high normals' perturbance, when this texture is used as a bump
	map.
	<p/>Norm Balance only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormBalance(float nb){if(nb == 1.0) return; fprintf_s(mFile, "setAttr \".nb\" %f;\n", nb);}
	/*
	<b>Norm Balance</b> controls the ratio between the low and
	high normals' perturbance, when this texture is used as a bump
	map.
	<p/>Norm Balance only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormBalance(const FloatID& nb){fprintf_s(mFile,"connectAttr \"");nb.write(mFile);fprintf_s(mFile,"\" \"%s.nb\";\n",mName.c_str());}
	/*
	<b>Norm Frequency</b> controls the amount of rough detail
	when this texture is used as a bump map.  Increase Norm Frequency
	to make the texture rougher, with finer detail.  Decrease it to
	make the roughness larger-grained.
	<p/>Norm Frequency only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormFrequency(float nf){if(nf == 1.0) return; fprintf_s(mFile, "setAttr \".nf\" %f;\n", nf);}
	/*
	<b>Norm Frequency</b> controls the amount of rough detail
	when this texture is used as a bump map.  Increase Norm Frequency
	to make the texture rougher, with finer detail.  Decrease it to
	make the roughness larger-grained.
	<p/>Norm Frequency only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormFrequency(const FloatID& nf){fprintf_s(mFile,"connectAttr \"");nf.write(mFile);fprintf_s(mFile,"\" \"%s.nf\";\n",mName.c_str());}
	/*
	<b>Out Normal</b>.  Connect this attribute directly
	to the Normal Camera attribute of a shader to use this
	texture as a bump map.  If you connect it directly in
	this way, then you can use the various Normal attributes
	(above) to control the qualities of the bumps.
	*/
	void setOutNormal(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The X component of Out Normal*/
	void setOutNormalX(const FloatID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*The Y component of Out Normal*/
	void setOutNormalY(const FloatID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*The Z component of Out Normal*/
	void setOutNormalZ(const FloatID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
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
	/*
	<b>Shaker</b> controls how 'perturbed' the texture is.
	Increase Shaker to make the texture more detailed, as
	though it has been "shaken up".  If the crater node is
	being used as a bump map, increase Shaker to increase
	the number of craters and valleys.
	*/
	FloatID getShaker(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Channel1</b> is one of the three input colors
	that are mixed together in this texture.  Changing this
	has little effect if the Crater texture is used as a
	bump map.
	*/
	Float3ID getChannel1(){char buffer[4096];sprintf_s (buffer, "%s.c1",mName.c_str());return (const char*)buffer;}
	/*The red component of channel 1.*/
	FloatID getChannel1R(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1r",mName.c_str());return (const char*)buffer;}
	/*The green component of channel 1.*/
	FloatID getChannel1G(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1g",mName.c_str());return (const char*)buffer;}
	/*The blue component of channel 1.*/
	FloatID getChannel1B(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Channel2</b> is one of the three input colors
	that are mixed together in this texture.  Changing this
	has little effect if the Crater texture is used as a
	bump map.
	*/
	Float3ID getChannel2(){char buffer[4096];sprintf_s (buffer, "%s.c2",mName.c_str());return (const char*)buffer;}
	/*The red component of channel 2.*/
	FloatID getChannel2R(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2r",mName.c_str());return (const char*)buffer;}
	/*The green component of channel 2.*/
	FloatID getChannel2G(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2g",mName.c_str());return (const char*)buffer;}
	/*The blue component of channel 2.*/
	FloatID getChannel2B(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Channel3</b> is one of the three input colors
	that are mixed together in this texture.  Changing this
	has little effect if the Crater texture is used as a
	bump map.
	*/
	Float3ID getChannel3(){char buffer[4096];sprintf_s (buffer, "%s.c3",mName.c_str());return (const char*)buffer;}
	/*The red component of channel 3.*/
	FloatID getChannel3R(){char buffer[4096];sprintf_s (buffer, "%s.c3.c3r",mName.c_str());return (const char*)buffer;}
	/*The green component of channel 3.*/
	FloatID getChannel3G(){char buffer[4096];sprintf_s (buffer, "%s.c3.c3g",mName.c_str());return (const char*)buffer;}
	/*The blue component of channel 3.*/
	FloatID getChannel3B(){char buffer[4096];sprintf_s (buffer, "%s.c3.c3b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Melt</b> controls the softness of the edges between
	the colors in the texture.  Increase Melt to make the borders
	between the colors smoother and wider.
	*/
	FloatID getMelt(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*
	<b>Balance</b> controls the ratio in which the three
	colors show up in the final texture.
	*/
	FloatID getBalance(){char buffer[4096];sprintf_s (buffer, "%s.ba",mName.c_str());return (const char*)buffer;}
	/*
	<b>Frequency</b> controls the frequency of the perturbation.
	Increase frequency to increase the detail in the texture,
	decreasing the size of the detail at the same time.
	*/
	FloatID getFrequency(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Norm Depth</b> controls how deep the craters will be when
	this texture is used as a bump map.  Increase Norm Depth to
	make the craters deeper.
	<p/>Norm Depth only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	FloatID getNormDepth(){char buffer[4096];sprintf_s (buffer, "%s.nd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Norm Melt</b> controls the softness of the crater edges
	when this texture is used as a bump map.  Increase Norm Melt
	to make the edges softer.  Animate this texture to make the
	cratered surface look like it is melting.
	<p/>Norm Melt only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	FloatID getNormMelt(){char buffer[4096];sprintf_s (buffer, "%s.nm",mName.c_str());return (const char*)buffer;}
	/*
	<b>Norm Balance</b> controls the ratio between the low and
	high normals' perturbance, when this texture is used as a bump
	map.
	<p/>Norm Balance only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	FloatID getNormBalance(){char buffer[4096];sprintf_s (buffer, "%s.nb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Norm Frequency</b> controls the amount of rough detail
	when this texture is used as a bump map.  Increase Norm Frequency
	to make the texture rougher, with finer detail.  Decrease it to
	make the roughness larger-grained.
	<p/>Norm Frequency only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	FloatID getNormFrequency(){char buffer[4096];sprintf_s (buffer, "%s.nf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Normal</b>.  Connect this attribute directly
	to the Normal Camera attribute of a shader to use this
	texture as a bump map.  If you connect it directly in
	this way, then you can use the various Normal attributes
	(above) to control the qualities of the bumps.
	*/
	Float3ID getOutNormal(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The X component of Out Normal*/
	FloatID getOutNormalX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*The Y component of Out Normal*/
	FloatID getOutNormalY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*The Z component of Out Normal*/
	FloatID getOutNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
protected:
	Crater(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CRATER_H__
