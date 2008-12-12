/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SNOW_H__
#define __MayaDM_SNOW_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
The <b>Snow</b> texture simulates snow that has fallen on a
 surface.  Snow only sticks to parts of the object facing upward,
 and only if they are not too steeply sloped.
<p/>
 The rest of the object (the part not covered in snow) is rendered
 using the Surface Color.
<p/>
<b>Tips and ideas:</b>
<ul>
   <li>Try combining a Fractal bump map with a Snow color map.
 The snow will only appear on the peaks and valleys of the bump-mapped
 surface.</li>
   <li>To simulate windswept snow, rotate the Snow's 3d placement
 about a horizontal line.</li>
   <li>To make snow appear on all objects in your scene, apply the
 Snow texture as a transparency map on a white shader, and then layer
 this shader onto other shaders in the scene.</li>
</ul>
 Aside from the attributes listed here, Snow inherits many
 other attributes from its parent, <a href="texture3d.html">
 Texture3d</a>
<p/>
 In the table below, important attributes are listed with their
 names shown in <b>bold</b> in the description column.
*/
class Snow : public Texture3d
{
public:
public:
	Snow(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "snow"){}
	virtual ~Snow(){}
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
	/*The transform to go from eye to texture space (pTx = pEye * matrix). It must come from the 3D placement node.*/
	void setEyeToTextureMatrix(const FltMatrixID& e2t){fprintf_s(mFile,"connectAttr \"");e2t.write(mFile);fprintf_s(mFile,"\" \"%s.e2t\";\n",mName.c_str());}
	/*
	<b>Snow Color</b> controls the color of the snow.
	Normally this is left white. But by using different
	colors and bump values, you can simulate a range of
	effects, such as cocoa sprinkled on a cake,
	or crusts forming on top of cooling lava.
	*/
	void setSnowColor(const float3& sn){if(sn == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".sn\" -type \"float3\" ");sn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Snow Color</b> controls the color of the snow.
	Normally this is left white. But by using different
	colors and bump values, you can simulate a range of
	effects, such as cocoa sprinkled on a cake,
	or crusts forming on top of cooling lava.
	*/
	void setSnowColor(const Float3ID& sn){fprintf_s(mFile,"connectAttr \"");sn.write(mFile);fprintf_s(mFile,"\" \"%s.sn\";\n",mName.c_str());}
	/*Snow Color red value*/
	void setSnowColorR(float snr){if(snr == 0.0) return; fprintf_s(mFile, "setAttr \".sn.snr\" %f;\n", snr);}
	/*Snow Color red value*/
	void setSnowColorR(const FloatID& snr){fprintf_s(mFile,"connectAttr \"");snr.write(mFile);fprintf_s(mFile,"\" \"%s.sn.snr\";\n",mName.c_str());}
	/*Snow Color green value*/
	void setSnowColorG(float sng){if(sng == 0.0) return; fprintf_s(mFile, "setAttr \".sn.sng\" %f;\n", sng);}
	/*Snow Color green value*/
	void setSnowColorG(const FloatID& sng){fprintf_s(mFile,"connectAttr \"");sng.write(mFile);fprintf_s(mFile,"\" \"%s.sn.sng\";\n",mName.c_str());}
	/*Snow Color blue value*/
	void setSnowColorB(float snb){if(snb == 0.0) return; fprintf_s(mFile, "setAttr \".sn.snb\" %f;\n", snb);}
	/*Snow Color blue value*/
	void setSnowColorB(const FloatID& snb){fprintf_s(mFile,"connectAttr \"");snb.write(mFile);fprintf_s(mFile,"\" \"%s.sn.snb\";\n",mName.c_str());}
	/*
	<b>Surface Color</b> is the color of the surface
	underneath the snow.
	*/
	void setSurfaceColor(const float3& su){if(su == float3(0.5, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".su\" -type \"float3\" ");su.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Surface Color</b> is the color of the surface
	underneath the snow.
	*/
	void setSurfaceColor(const Float3ID& su){fprintf_s(mFile,"connectAttr \"");su.write(mFile);fprintf_s(mFile,"\" \"%s.su\";\n",mName.c_str());}
	/*Surface Color red value*/
	void setSurfaceColorR(float sur){if(sur == 0.0) return; fprintf_s(mFile, "setAttr \".su.sur\" %f;\n", sur);}
	/*Surface Color red value*/
	void setSurfaceColorR(const FloatID& sur){fprintf_s(mFile,"connectAttr \"");sur.write(mFile);fprintf_s(mFile,"\" \"%s.su.sur\";\n",mName.c_str());}
	/*Surface Color green value*/
	void setSurfaceColorG(float sug){if(sug == 0.0) return; fprintf_s(mFile, "setAttr \".su.sug\" %f;\n", sug);}
	/*Surface Color green value*/
	void setSurfaceColorG(const FloatID& sug){fprintf_s(mFile,"connectAttr \"");sug.write(mFile);fprintf_s(mFile,"\" \"%s.su.sug\";\n",mName.c_str());}
	/*Surface Color blue value*/
	void setSurfaceColorB(float sub){if(sub == 0.0) return; fprintf_s(mFile, "setAttr \".su.sub\" %f;\n", sub);}
	/*Surface Color blue value*/
	void setSurfaceColorB(const FloatID& sub){fprintf_s(mFile,"connectAttr \"");sub.write(mFile);fprintf_s(mFile,"\" \"%s.su.sub\";\n",mName.c_str());}
	/*
	<b>Threshold</b> controls how steep the surface has to be
	before snow will not stick to it.  You can think of it
	as the "slipperiness" of the snow.  Decrease Threshold to
	make the snow stick to steeper parts of the surface.
	*/
	void setThreshold(float th){if(th == 0.5) return; fprintf_s(mFile, "setAttr \".th\" %f;\n", th);}
	/*
	<b>Threshold</b> controls how steep the surface has to be
	before snow will not stick to it.  You can think of it
	as the "slipperiness" of the snow.  Decrease Threshold to
	make the snow stick to steeper parts of the surface.
	*/
	void setThreshold(const FloatID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th\";\n",mName.c_str());}
	/*
	<b>Depth Decay</b> controls how abruptly the snow
	ends and the rest of the surface begins.  Decrease
	Depth Decay to make the snow quickly fade to the
	surface color as you move down the slope.  Increase
	Depth Decay to make the surface stay snowy further
	down, with a more abrupt transition.
	*/
	void setDepthDecay(float dd){if(dd == 5.0) return; fprintf_s(mFile, "setAttr \".dd\" %f;\n", dd);}
	/*
	<b>Depth Decay</b> controls how abruptly the snow
	ends and the rest of the surface begins.  Decrease
	Depth Decay to make the snow quickly fade to the
	surface color as you move down the slope.  Increase
	Depth Decay to make the surface stay snowy further
	down, with a more abrupt transition.
	*/
	void setDepthDecay(const FloatID& dd){fprintf_s(mFile,"connectAttr \"");dd.write(mFile);fprintf_s(mFile,"\" \"%s.dd\";\n",mName.c_str());}
	/*
	<b>Thickness</b> controls how much the snow blocks out
	the color beneath it.  Set it to 1.0 to make the snow
	completely opaque.  As you decrease Thickness, the snow
	becomes more transparent so that you can see the
	Surface Color underneath it.
	*/
	void setThickness(float tn){if(tn == 1.0) return; fprintf_s(mFile, "setAttr \".tn\" %f;\n", tn);}
	/*
	<b>Thickness</b> controls how much the snow blocks out
	the color beneath it.  Set it to 1.0 to make the snow
	completely opaque.  As you decrease Thickness, the snow
	becomes more transparent so that you can see the
	Surface Color underneath it.
	*/
	void setThickness(const FloatID& tn){fprintf_s(mFile,"connectAttr \"");tn.write(mFile);fprintf_s(mFile,"\" \"%s.tn\";\n",mName.c_str());}
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
	<b>Snow Color</b> controls the color of the snow.
	Normally this is left white. But by using different
	colors and bump values, you can simulate a range of
	effects, such as cocoa sprinkled on a cake,
	or crusts forming on top of cooling lava.
	*/
	Float3ID getSnowColor(){char buffer[4096];sprintf_s (buffer, "%s.sn",mName.c_str());return (const char*)buffer;}
	/*Snow Color red value*/
	FloatID getSnowColorR(){char buffer[4096];sprintf_s (buffer, "%s.sn.snr",mName.c_str());return (const char*)buffer;}
	/*Snow Color green value*/
	FloatID getSnowColorG(){char buffer[4096];sprintf_s (buffer, "%s.sn.sng",mName.c_str());return (const char*)buffer;}
	/*Snow Color blue value*/
	FloatID getSnowColorB(){char buffer[4096];sprintf_s (buffer, "%s.sn.snb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Surface Color</b> is the color of the surface
	underneath the snow.
	*/
	Float3ID getSurfaceColor(){char buffer[4096];sprintf_s (buffer, "%s.su",mName.c_str());return (const char*)buffer;}
	/*Surface Color red value*/
	FloatID getSurfaceColorR(){char buffer[4096];sprintf_s (buffer, "%s.su.sur",mName.c_str());return (const char*)buffer;}
	/*Surface Color green value*/
	FloatID getSurfaceColorG(){char buffer[4096];sprintf_s (buffer, "%s.su.sug",mName.c_str());return (const char*)buffer;}
	/*Surface Color blue value*/
	FloatID getSurfaceColorB(){char buffer[4096];sprintf_s (buffer, "%s.su.sub",mName.c_str());return (const char*)buffer;}
	/*
	<b>Threshold</b> controls how steep the surface has to be
	before snow will not stick to it.  You can think of it
	as the "slipperiness" of the snow.  Decrease Threshold to
	make the snow stick to steeper parts of the surface.
	*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.th",mName.c_str());return (const char*)buffer;}
	/*
	<b>Depth Decay</b> controls how abruptly the snow
	ends and the rest of the surface begins.  Decrease
	Depth Decay to make the snow quickly fade to the
	surface color as you move down the slope.  Increase
	Depth Decay to make the surface stay snowy further
	down, with a more abrupt transition.
	*/
	FloatID getDepthDecay(){char buffer[4096];sprintf_s (buffer, "%s.dd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Thickness</b> controls how much the snow blocks out
	the color beneath it.  Set it to 1.0 to make the snow
	completely opaque.  As you decrease Thickness, the snow
	becomes more transparent so that you can see the
	Surface Color underneath it.
	*/
	FloatID getThickness(){char buffer[4096];sprintf_s (buffer, "%s.tn",mName.c_str());return (const char*)buffer;}
protected:
	Snow(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SNOW_H__
