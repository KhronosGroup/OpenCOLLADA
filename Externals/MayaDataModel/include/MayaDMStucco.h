/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STUCCO_H__
#define __MayaDM_STUCCO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
The <b>Stucco</b> texture can be used as a bump map to create
 a stucco-like finish on a surface.  It has a special Out Normal
 attribute, which you can
 connect directly to the Normal Camera of a shading node to produce
 bump mapping.  (For most 3d textures, you connect the Out Alpha to a
 Bump 3d node, and the output of the Bump3d node to Normal Camera).
<p/>
 You can also use the Stucco texture as a color map.  It randomly
 mixes its two input colors to create the final appearance of
 stains or clouds.
<p/>
 Aside from the attributes listed here, Crater inherits many attributes
 from <a href="texture3d.html">Texture3d</a>.
<p/>
 In the table below, important attributes have their names shown
 in <b>bold</b> in the Description column.
*/
class Stucco : public Texture3d
{
public:
public:
	Stucco(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "stucco"){}
	virtual ~Stucco(){}
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
	<b>Shaker</b> controls the mix of the two contributing
	colors.  If Shaker is set to a low value, then the texture
	will be mostly Channel2, with little bits of Channel1 peeking
	through.  As Shaker is increased, the areas with the Channel1
	color become more solid and spread out.
	*/
	void setShaker(float sh){if(sh == 20.0) return; fprintf_s(mFile, "setAttr \".sh\" %f;\n", sh);}
	/*
	<b>Shaker</b> controls the mix of the two contributing
	colors.  If Shaker is set to a low value, then the texture
	will be mostly Channel2, with little bits of Channel1 peeking
	through.  As Shaker is increased, the areas with the Channel1
	color become more solid and spread out.
	*/
	void setShaker(const FloatID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*
	<b>Channel1</b> is one of the two colors that comprise
	the texture.
	*/
	void setChannel1(const float3& c1){if(c1 == float3(1.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".c1\" -type \"float3\" ");c1.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Channel1</b> is one of the two colors that comprise
	the texture.
	*/
	void setChannel1(const Float3ID& c1){fprintf_s(mFile,"connectAttr \"");c1.write(mFile);fprintf_s(mFile,"\" \"%s.c1\";\n",mName.c_str());}
	/*The red component of Channel1.*/
	void setChannel1R(float c1r){if(c1r == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1r\" %f;\n", c1r);}
	/*The red component of Channel1.*/
	void setChannel1R(const FloatID& c1r){fprintf_s(mFile,"connectAttr \"");c1r.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1r\";\n",mName.c_str());}
	/*The green component of Channel1.*/
	void setChannel1G(float c1g){if(c1g == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1g\" %f;\n", c1g);}
	/*The green component of Channel1.*/
	void setChannel1G(const FloatID& c1g){fprintf_s(mFile,"connectAttr \"");c1g.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1g\";\n",mName.c_str());}
	/*The blue component of Channel1.*/
	void setChannel1B(float c1b){if(c1b == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1b\" %f;\n", c1b);}
	/*The blue component of Channel1.*/
	void setChannel1B(const FloatID& c1b){fprintf_s(mFile,"connectAttr \"");c1b.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1b\";\n",mName.c_str());}
	/*
	<b>Channel2</b> is one of the two colors that comprise
	the texture.
	*/
	void setChannel2(const float3& c2){if(c2 == float3(0.0, 0.0, 1.0)) return; fprintf_s(mFile, "setAttr \".c2\" -type \"float3\" ");c2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Channel2</b> is one of the two colors that comprise
	the texture.
	*/
	void setChannel2(const Float3ID& c2){fprintf_s(mFile,"connectAttr \"");c2.write(mFile);fprintf_s(mFile,"\" \"%s.c2\";\n",mName.c_str());}
	/*The red component of Channel2.*/
	void setChannel2R(float c2r){if(c2r == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2r\" %f;\n", c2r);}
	/*The red component of Channel2.*/
	void setChannel2R(const FloatID& c2r){fprintf_s(mFile,"connectAttr \"");c2r.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2r\";\n",mName.c_str());}
	/*The green component of Channel2.*/
	void setChannel2G(float c2g){if(c2g == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2g\" %f;\n", c2g);}
	/*The green component of Channel2.*/
	void setChannel2G(const FloatID& c2g){fprintf_s(mFile,"connectAttr \"");c2g.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2g\";\n",mName.c_str());}
	/*The blue component of Channel2.*/
	void setChannel2B(float c2b){if(c2b == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2b\" %f;\n", c2b);}
	/*The blue component of Channel2.*/
	void setChannel2B(const FloatID& c2b){fprintf_s(mFile,"connectAttr \"");c2b.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2b\";\n",mName.c_str());}
	/*The input normal to perturbate*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The X component of the input normal*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The Y component of the input normal*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The Z component of the input normal*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*
	<b>Normal Melt</b> controls the softness of the crater edges
	when this texture is used as a bump map.  Increase Normal Melt
	to make the edges softer.  Animate this texture to make the
	cratered surface look like it is melting.
	<p/>Normal Melt only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormalMelt(float nm){if(nm == 0.1) return; fprintf_s(mFile, "setAttr \".nm\" %f;\n", nm);}
	/*
	<b>Normal Melt</b> controls the softness of the crater edges
	when this texture is used as a bump map.  Increase Normal Melt
	to make the edges softer.  Animate this texture to make the
	cratered surface look like it is melting.
	<p/>Normal Melt only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormalMelt(const FloatID& nm){fprintf_s(mFile,"connectAttr \"");nm.write(mFile);fprintf_s(mFile,"\" \"%s.nm\";\n",mName.c_str());}
	/*
	<b>Normal Depth</b> controls how deep the craters will be when
	this texture is used as a bump map.  Increase Normal Depth to
	make the craters deeper.
	<p/>Normal Depth only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormalDepth(float nd){if(nd == 1.0) return; fprintf_s(mFile, "setAttr \".nd\" %f;\n", nd);}
	/*
	<b>Normal Depth</b> controls how deep the craters will be when
	this texture is used as a bump map.  Increase Normal Depth to
	make the craters deeper.
	<p/>Normal Depth only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	void setNormalDepth(const FloatID& nd){fprintf_s(mFile,"connectAttr \"");nd.write(mFile);fprintf_s(mFile,"\" \"%s.nd\";\n",mName.c_str());}
	/*
	<b>Out Normal</b>.  To use the Stucco texture as a bump
	map, connect this attribute to the Normal Camera attribute
	of a shader, such as Phong or Blinn.
	*/
	void setOutNormal(const Float3ID& on){fprintf_s(mFile,"connectAttr \"");on.write(mFile);fprintf_s(mFile,"\" \"%s.on\";\n",mName.c_str());}
	/*The X component of Out Normal*/
	void setOutNormalX(const FloatID& onx){fprintf_s(mFile,"connectAttr \"");onx.write(mFile);fprintf_s(mFile,"\" \"%s.on.onx\";\n",mName.c_str());}
	/*The Y component of Out Normal*/
	void setOutNormalY(const FloatID& ony){fprintf_s(mFile,"connectAttr \"");ony.write(mFile);fprintf_s(mFile,"\" \"%s.on.ony\";\n",mName.c_str());}
	/*The Z component of Out Normal*/
	void setOutNormalZ(const FloatID& onz){fprintf_s(mFile,"connectAttr \"");onz.write(mFile);fprintf_s(mFile,"\" \"%s.on.onz\";\n",mName.c_str());}
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
	<b>Shaker</b> controls the mix of the two contributing
	colors.  If Shaker is set to a low value, then the texture
	will be mostly Channel2, with little bits of Channel1 peeking
	through.  As Shaker is increased, the areas with the Channel1
	color become more solid and spread out.
	*/
	FloatID getShaker(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Channel1</b> is one of the two colors that comprise
	the texture.
	*/
	Float3ID getChannel1(){char buffer[4096];sprintf_s (buffer, "%s.c1",mName.c_str());return (const char*)buffer;}
	/*The red component of Channel1.*/
	FloatID getChannel1R(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1r",mName.c_str());return (const char*)buffer;}
	/*The green component of Channel1.*/
	FloatID getChannel1G(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1g",mName.c_str());return (const char*)buffer;}
	/*The blue component of Channel1.*/
	FloatID getChannel1B(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Channel2</b> is one of the two colors that comprise
	the texture.
	*/
	Float3ID getChannel2(){char buffer[4096];sprintf_s (buffer, "%s.c2",mName.c_str());return (const char*)buffer;}
	/*The red component of Channel2.*/
	FloatID getChannel2R(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2r",mName.c_str());return (const char*)buffer;}
	/*The green component of Channel2.*/
	FloatID getChannel2G(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2g",mName.c_str());return (const char*)buffer;}
	/*The blue component of Channel2.*/
	FloatID getChannel2B(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2b",mName.c_str());return (const char*)buffer;}
	/*The input normal to perturbate*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The X component of the input normal*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the input normal*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The Z component of the input normal*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Normal Melt</b> controls the softness of the crater edges
	when this texture is used as a bump map.  Increase Normal Melt
	to make the edges softer.  Animate this texture to make the
	cratered surface look like it is melting.
	<p/>Normal Melt only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	FloatID getNormalMelt(){char buffer[4096];sprintf_s (buffer, "%s.nm",mName.c_str());return (const char*)buffer;}
	/*
	<b>Normal Depth</b> controls how deep the craters will be when
	this texture is used as a bump map.  Increase Normal Depth to
	make the craters deeper.
	<p/>Normal Depth only has an effect if the Out Normal attribute of
	this node is connected to the Normal Camera attribute of a shader.
	*/
	FloatID getNormalDepth(){char buffer[4096];sprintf_s (buffer, "%s.nd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Normal</b>.  To use the Stucco texture as a bump
	map, connect this attribute to the Normal Camera attribute
	of a shader, such as Phong or Blinn.
	*/
	Float3ID getOutNormal(){char buffer[4096];sprintf_s (buffer, "%s.on",mName.c_str());return (const char*)buffer;}
	/*The X component of Out Normal*/
	FloatID getOutNormalX(){char buffer[4096];sprintf_s (buffer, "%s.on.onx",mName.c_str());return (const char*)buffer;}
	/*The Y component of Out Normal*/
	FloatID getOutNormalY(){char buffer[4096];sprintf_s (buffer, "%s.on.ony",mName.c_str());return (const char*)buffer;}
	/*The Z component of Out Normal*/
	FloatID getOutNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.on.onz",mName.c_str());return (const char*)buffer;}
protected:
	Stucco(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_STUCCO_H__
