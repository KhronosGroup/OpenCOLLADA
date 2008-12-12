/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NONEXTENDEDLIGHTSHAPENODE_H__
#define __MayaDM_NONEXTENDEDLIGHTSHAPENODE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNonAmbientLightShapeNode.h"
namespace MayaDM
{
/*
<p><pre>
        This class is the abstract class that describes nonExtended
        lights (e.g., spot, point lights).  Non-extended lights are
        lights which are not correctly represented physically, and
        are lights which disseminate from a single point source or
        direction (which there are no such things in the real world),
        and requires no numerical integration evaluations during
        shading of a point.  Extended lights tends to be more physically
        accurate, which includes lights such as linear + area lights.

</pre></p>
*/
class NonExtendedLightShapeNode : public NonAmbientLightShapeNode
{
public:
public:
	NonExtendedLightShapeNode(FILE* file,const std::string& name,const std::string& parent=""):NonAmbientLightShapeNode(file, name, parent, "nonExtendedLightShapeNode"){}
	virtual ~NonExtendedLightShapeNode(){}
	/*
	The light radius used to determine how soft the shadows
	(or the penumbra region) should be.  The radius provides
	a spherical region in which we can jitter the shadow
	rays to fake soft shadows.  The larger the light radius,
	the softer the shadows (or larger the penumbra region).
	Non-extended lights do not cast soft shadows mathematically
	(represented by the default radius of 0), which is why
	this light radius is needed to fake soft shadows.
	*/
	void setLightRadius(float lr){if(lr == 0.0) return; fprintf_s(mFile, "setAttr \".lr\" %f;\n", lr);}
	/*
	The light radius used to determine how soft the shadows
	(or the penumbra region) should be.  The radius provides
	a spherical region in which we can jitter the shadow
	rays to fake soft shadows.  The larger the light radius,
	the softer the shadows (or larger the penumbra region).
	Non-extended lights do not cast soft shadows mathematically
	(represented by the default radius of 0), which is why
	this light radius is needed to fake soft shadows.
	*/
	void setLightRadius(const FloatID& lr){fprintf_s(mFile,"connectAttr \"");lr.write(mFile);fprintf_s(mFile,"\" \"%s.lr\";\n",mName.c_str());}
	/*
	Turn on soft shadows.  This is only useful when
	ray tracing shadows are turned on, and the light
	radius is larger than 0.
	*/
	void setCastSoftShadows(bool cw){if(cw == false) return; fprintf_s(mFile, "setAttr \".cw\" %i;\n", cw);}
	/*
	Turn on soft shadows.  This is only useful when
	ray tracing shadows are turned on, and the light
	radius is larger than 0.
	*/
	void setCastSoftShadows(const BoolID& cw){fprintf_s(mFile,"connectAttr \"");cw.write(mFile);fprintf_s(mFile,"\" \"%s.cw\";\n",mName.c_str());}
	/*Turn on depth map shadows.*/
	void setUseDepthMapShadows(bool dms){if(dms == false) return; fprintf_s(mFile, "setAttr \".dms\" %i;\n", dms);}
	/*Turn on depth map shadows.*/
	void setUseDepthMapShadows(const BoolID& dms){fprintf_s(mFile,"connectAttr \"");dms.write(mFile);fprintf_s(mFile,"\" \"%s.dms\";\n",mName.c_str());}
	/*Reuse last written depth map.*/
	void setReuseDmap(bool du){if(du == false) return; fprintf_s(mFile, "setAttr \".du\" %i;\n", du);}
	/*Reuse last written depth map.*/
	void setReuseDmap(const BoolID& du){fprintf_s(mFile,"connectAttr \"");du.write(mFile);fprintf_s(mFile,"\" \"%s.du\";\n",mName.c_str());}
	/*Turn on mid distance depth map.*/
	void setUseMidDistDmap(bool md){if(md == true) return; fprintf_s(mFile, "setAttr \".md\" %i;\n", md);}
	/*Turn on mid distance depth map.*/
	void setUseMidDistDmap(const BoolID& md){fprintf_s(mFile,"connectAttr \"");md.write(mFile);fprintf_s(mFile,"\" \"%s.md\";\n",mName.c_str());}
	/*
	The depth map filter size.  The larger the size, the
	softer the shadows (larger penumbra region).
	*/
	void setDmapFilterSize(short fs){if(fs == 1) return; fprintf_s(mFile, "setAttr \".fs\" %i;\n", fs);}
	/*
	The depth map filter size.  The larger the size, the
	softer the shadows (larger penumbra region).
	*/
	void setDmapFilterSize(const ShortID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs\";\n",mName.c_str());}
	/*The depth map resolution.*/
	void setDmapResolution(short dr){if(dr == 512) return; fprintf_s(mFile, "setAttr \".dr\" %i;\n", dr);}
	/*The depth map resolution.*/
	void setDmapResolution(const ShortID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr\";\n",mName.c_str());}
	/*
	The depth map bias, used to escape bad self-shadowing
	artifacts.
	*/
	void setDmapBias(float db){if(db == 0.001) return; fprintf_s(mFile, "setAttr \".db\" %f;\n", db);}
	/*
	The depth map bias, used to escape bad self-shadowing
	artifacts.
	*/
	void setDmapBias(const FloatID& db){fprintf_s(mFile,"connectAttr \"");db.write(mFile);fprintf_s(mFile,"\" \"%s.db\";\n",mName.c_str());}
	/*
	The depth map focus.  If the auto focus is off, we need
	to rely on some region which we need to compute depth map
	shadows for, which is what this angle is meant for.
	This is only useful for spot + point lights, and the
	equivalent for directional lights ais the dmapWidthFocus.
	*/
	void setDmapFocus(float df){if(df == 90.0) return; fprintf_s(mFile, "setAttr \".df\" %f;\n", df);}
	/*
	The depth map focus.  If the auto focus is off, we need
	to rely on some region which we need to compute depth map
	shadows for, which is what this angle is meant for.
	This is only useful for spot + point lights, and the
	equivalent for directional lights ais the dmapWidthFocus.
	*/
	void setDmapFocus(const FloatID& df){fprintf_s(mFile,"connectAttr \"");df.write(mFile);fprintf_s(mFile,"\" \"%s.df\";\n",mName.c_str());}
	/*The depth map width focus for directional lights.*/
	void setDmapWidthFocus(float dw){if(dw == 100.0) return; fprintf_s(mFile, "setAttr \".dw\" %f;\n", dw);}
	/*The depth map width focus for directional lights.*/
	void setDmapWidthFocus(const FloatID& dw){fprintf_s(mFile,"connectAttr \"");dw.write(mFile);fprintf_s(mFile,"\" \"%s.dw\";\n",mName.c_str());}
	/*Automatic computation of the depth map bounding box focus.*/
	void setUseDmapAutoFocus(bool af){if(af == true) return; fprintf_s(mFile, "setAttr \".af\" %i;\n", af);}
	/*Automatic computation of the depth map bounding box focus.*/
	void setUseDmapAutoFocus(const BoolID& af){fprintf_s(mFile,"connectAttr \"");af.write(mFile);fprintf_s(mFile,"\" \"%s.af\";\n",mName.c_str());}
	/*The number of volume shadow samples.*/
	void setVolumeShadowSamples(short nv){if(nv == 20) return; fprintf_s(mFile, "setAttr \".nv\" %i;\n", nv);}
	/*The number of volume shadow samples.*/
	void setVolumeShadowSamples(const ShortID& nv){fprintf_s(mFile,"connectAttr \"");nv.write(mFile);fprintf_s(mFile,"\" \"%s.nv\";\n",mName.c_str());}
	/*The amount of fog shadow exaggeration.*/
	void setFogShadowIntensity(short fsi){if(fsi == 1) return; fprintf_s(mFile, "setAttr \".fsi\" %i;\n", fsi);}
	/*The amount of fog shadow exaggeration.*/
	void setFogShadowIntensity(const ShortID& fsi){fprintf_s(mFile,"connectAttr \"");fsi.write(mFile);fprintf_s(mFile,"\" \"%s.fsi\";\n",mName.c_str());}
	/*Automatic computation of the depth map near/far clipping planes.*/
	void setUseDmapAutoClipping(bool uc){if(uc == true) return; fprintf_s(mFile, "setAttr \".uc\" %i;\n", uc);}
	/*Automatic computation of the depth map near/far clipping planes.*/
	void setUseDmapAutoClipping(const BoolID& uc){fprintf_s(mFile,"connectAttr \"");uc.write(mFile);fprintf_s(mFile,"\" \"%s.uc\";\n",mName.c_str());}
	/*The depth map near clipping plane distance.*/
	void setDmapNearClipPlane(float nc){if(nc == 0.001) return; fprintf_s(mFile, "setAttr \".nc\" %f;\n", nc);}
	/*The depth map near clipping plane distance.*/
	void setDmapNearClipPlane(const FloatID& nc){fprintf_s(mFile,"connectAttr \"");nc.write(mFile);fprintf_s(mFile,"\" \"%s.nc\";\n",mName.c_str());}
	/*The depth map farclipping plane distance.*/
	void setDmapFarClipPlane(float fcp){if(fcp == 10000.0) return; fprintf_s(mFile, "setAttr \".fcp\" %f;\n", fcp);}
	/*The depth map farclipping plane distance.*/
	void setDmapFarClipPlane(const FloatID& fcp){fprintf_s(mFile,"connectAttr \"");fcp.write(mFile);fprintf_s(mFile,"\" \"%s.fcp\";\n",mName.c_str());}
	/*use a single map.*/
	void setUseOnlySingleDmap(bool us){if(us == true) return; fprintf_s(mFile, "setAttr \".us\" %i;\n", us);}
	/*use a single map.*/
	void setUseOnlySingleDmap(const BoolID& us){fprintf_s(mFile,"connectAttr \"");us.write(mFile);fprintf_s(mFile,"\" \"%s.us\";\n",mName.c_str());}
	/*compute the X Positive Depthmap.*/
	void setUseXPositiveDmap(bool xp){if(xp == true) return; fprintf_s(mFile, "setAttr \".xp\" %i;\n", xp);}
	/*compute the X Positive Depthmap.*/
	void setUseXPositiveDmap(const BoolID& xp){fprintf_s(mFile,"connectAttr \"");xp.write(mFile);fprintf_s(mFile,"\" \"%s.xp\";\n",mName.c_str());}
	/*compute the X Negative Depthmap.*/
	void setUseXNegativeDmap(bool xn){if(xn == true) return; fprintf_s(mFile, "setAttr \".xn\" %i;\n", xn);}
	/*compute the X Negative Depthmap.*/
	void setUseXNegativeDmap(const BoolID& xn){fprintf_s(mFile,"connectAttr \"");xn.write(mFile);fprintf_s(mFile,"\" \"%s.xn\";\n",mName.c_str());}
	/*compute the Y Positive Depthmap.*/
	void setUseYPositiveDmap(bool yp){if(yp == true) return; fprintf_s(mFile, "setAttr \".yp\" %i;\n", yp);}
	/*compute the Y Positive Depthmap.*/
	void setUseYPositiveDmap(const BoolID& yp){fprintf_s(mFile,"connectAttr \"");yp.write(mFile);fprintf_s(mFile,"\" \"%s.yp\";\n",mName.c_str());}
	/*compute the Y Negative Depthmap.*/
	void setUseYNegativeDmap(bool yn){if(yn == true) return; fprintf_s(mFile, "setAttr \".yn\" %i;\n", yn);}
	/*compute the Y Negative Depthmap.*/
	void setUseYNegativeDmap(const BoolID& yn){fprintf_s(mFile,"connectAttr \"");yn.write(mFile);fprintf_s(mFile,"\" \"%s.yn\";\n",mName.c_str());}
	/*compute the Z Positive Depthmap.*/
	void setUseZPositiveDmap(bool zp){if(zp == true) return; fprintf_s(mFile, "setAttr \".zp\" %i;\n", zp);}
	/*compute the Z Positive Depthmap.*/
	void setUseZPositiveDmap(const BoolID& zp){fprintf_s(mFile,"connectAttr \"");zp.write(mFile);fprintf_s(mFile,"\" \"%s.zp\";\n",mName.c_str());}
	/*compute the Z Negative Depthmap.*/
	void setUseZNegativeDmap(bool zn){if(zn == true) return; fprintf_s(mFile, "setAttr \".zn\" %i;\n", zn);}
	/*compute the Z Negative Depthmap.*/
	void setUseZNegativeDmap(const BoolID& zn){fprintf_s(mFile,"connectAttr \"");zn.write(mFile);fprintf_s(mFile,"\" \"%s.zn\";\n",mName.c_str());}
	/*The Shadow Map Pre Callback Name*/
	void setDmapUseMacro(const string& dc){if(dc == "NULL") return; fprintf_s(mFile, "setAttr \".dc\" -type \"string\" ");dc.write(mFile);fprintf_s(mFile,";\n");}
	/*The Shadow Map Pre Callback Name*/
	void setDmapUseMacro(const StringID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*The Shadow Depth Map Name*/
	void setDmapName(const string& smn){if(smn == "NULL") return; fprintf_s(mFile, "setAttr \".smn\" -type \"string\" ");smn.write(mFile);fprintf_s(mFile,";\n");}
	/*The Shadow Depth Map Name*/
	void setDmapName(const StringID& smn){fprintf_s(mFile,"connectAttr \"");smn.write(mFile);fprintf_s(mFile,"\" \"%s.smn\";\n",mName.c_str());}
	/*Use the light name in the depth map I/O file name.*/
	void setDmapLightName(bool ul){if(ul == true) return; fprintf_s(mFile, "setAttr \".ul\" %i;\n", ul);}
	/*Use the light name in the depth map I/O file name.*/
	void setDmapLightName(const BoolID& ul){fprintf_s(mFile,"connectAttr \"");ul.write(mFile);fprintf_s(mFile,"\" \"%s.ul\";\n",mName.c_str());}
	/*Use the scene name in the depth map I/O file name.*/
	void setDmapSceneName(bool um){if(um == false) return; fprintf_s(mFile, "setAttr \".um\" %i;\n", um);}
	/*Use the scene name in the depth map I/O file name.*/
	void setDmapSceneName(const BoolID& um){fprintf_s(mFile,"connectAttr \"");um.write(mFile);fprintf_s(mFile,"\" \"%s.um\";\n",mName.c_str());}
	/*Use the frame extension in the depth map I/O file name.*/
	void setDmapFrameExt(bool uf){if(uf == false) return; fprintf_s(mFile, "setAttr \".uf\" %i;\n", uf);}
	/*Use the frame extension in the depth map I/O file name.*/
	void setDmapFrameExt(const BoolID& uf){fprintf_s(mFile,"connectAttr \"");uf.write(mFile);fprintf_s(mFile,"\" \"%s.uf\";\n",mName.c_str());}
	/*write shadow depth maps to disk.*/
	void setWriteDmap(bool ws){if(ws == false) return; fprintf_s(mFile, "setAttr \".ws\" %i;\n", ws);}
	/*write shadow depth maps to disk.*/
	void setWriteDmap(const BoolID& ws){fprintf_s(mFile,"connectAttr \"");ws.write(mFile);fprintf_s(mFile,"\" \"%s.ws\";\n",mName.c_str());}
	/*Last written depth map Anim Extension Name*/
	void setLastWrittenDmapAnimExtName(const string& lw){if(lw == "NULL") return; fprintf_s(mFile, "setAttr \".lw\" -type \"string\" ");lw.write(mFile);fprintf_s(mFile,";\n");}
	/*Last written depth map Anim Extension Name*/
	void setLastWrittenDmapAnimExtName(const StringID& lw){fprintf_s(mFile,"connectAttr \"");lw.write(mFile);fprintf_s(mFile,"\" \"%s.lw\";\n",mName.c_str());}
	/*sampleData = geometry receives shadows*/
	void setReceiveShadows(bool gs){if(gs == true) return; fprintf_s(mFile, "setAttr \".gs\" %i;\n", gs);}
	/*sampleData = geometry receives shadows*/
	void setReceiveShadows(const BoolID& gs){fprintf_s(mFile,"connectAttr \"");gs.write(mFile);fprintf_s(mFile,"\" \"%s.gs\";\n",mName.c_str());}
	/*
	The light radius used to determine how soft the shadows
	(or the penumbra region) should be.  The radius provides
	a spherical region in which we can jitter the shadow
	rays to fake soft shadows.  The larger the light radius,
	the softer the shadows (or larger the penumbra region).
	Non-extended lights do not cast soft shadows mathematically
	(represented by the default radius of 0), which is why
	this light radius is needed to fake soft shadows.
	*/
	FloatID getLightRadius(){char buffer[4096];sprintf_s (buffer, "%s.lr",mName.c_str());return (const char*)buffer;}
	/*
	Turn on soft shadows.  This is only useful when
	ray tracing shadows are turned on, and the light
	radius is larger than 0.
	*/
	BoolID getCastSoftShadows(){char buffer[4096];sprintf_s (buffer, "%s.cw",mName.c_str());return (const char*)buffer;}
	/*Turn on depth map shadows.*/
	BoolID getUseDepthMapShadows(){char buffer[4096];sprintf_s (buffer, "%s.dms",mName.c_str());return (const char*)buffer;}
	/*Reuse last written depth map.*/
	BoolID getReuseDmap(){char buffer[4096];sprintf_s (buffer, "%s.du",mName.c_str());return (const char*)buffer;}
	/*Turn on mid distance depth map.*/
	BoolID getUseMidDistDmap(){char buffer[4096];sprintf_s (buffer, "%s.md",mName.c_str());return (const char*)buffer;}
	/*
	The depth map filter size.  The larger the size, the
	softer the shadows (larger penumbra region).
	*/
	ShortID getDmapFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.fs",mName.c_str());return (const char*)buffer;}
	/*The depth map resolution.*/
	ShortID getDmapResolution(){char buffer[4096];sprintf_s (buffer, "%s.dr",mName.c_str());return (const char*)buffer;}
	/*
	The depth map bias, used to escape bad self-shadowing
	artifacts.
	*/
	FloatID getDmapBias(){char buffer[4096];sprintf_s (buffer, "%s.db",mName.c_str());return (const char*)buffer;}
	/*
	The depth map focus.  If the auto focus is off, we need
	to rely on some region which we need to compute depth map
	shadows for, which is what this angle is meant for.
	This is only useful for spot + point lights, and the
	equivalent for directional lights ais the dmapWidthFocus.
	*/
	FloatID getDmapFocus(){char buffer[4096];sprintf_s (buffer, "%s.df",mName.c_str());return (const char*)buffer;}
	/*The depth map width focus for directional lights.*/
	FloatID getDmapWidthFocus(){char buffer[4096];sprintf_s (buffer, "%s.dw",mName.c_str());return (const char*)buffer;}
	/*Automatic computation of the depth map bounding box focus.*/
	BoolID getUseDmapAutoFocus(){char buffer[4096];sprintf_s (buffer, "%s.af",mName.c_str());return (const char*)buffer;}
	/*The number of volume shadow samples.*/
	ShortID getVolumeShadowSamples(){char buffer[4096];sprintf_s (buffer, "%s.nv",mName.c_str());return (const char*)buffer;}
	/*The amount of fog shadow exaggeration.*/
	ShortID getFogShadowIntensity(){char buffer[4096];sprintf_s (buffer, "%s.fsi",mName.c_str());return (const char*)buffer;}
	/*Automatic computation of the depth map near/far clipping planes.*/
	BoolID getUseDmapAutoClipping(){char buffer[4096];sprintf_s (buffer, "%s.uc",mName.c_str());return (const char*)buffer;}
	/*The depth map near clipping plane distance.*/
	FloatID getDmapNearClipPlane(){char buffer[4096];sprintf_s (buffer, "%s.nc",mName.c_str());return (const char*)buffer;}
	/*The depth map farclipping plane distance.*/
	FloatID getDmapFarClipPlane(){char buffer[4096];sprintf_s (buffer, "%s.fcp",mName.c_str());return (const char*)buffer;}
	/*use a single map.*/
	BoolID getUseOnlySingleDmap(){char buffer[4096];sprintf_s (buffer, "%s.us",mName.c_str());return (const char*)buffer;}
	/*compute the X Positive Depthmap.*/
	BoolID getUseXPositiveDmap(){char buffer[4096];sprintf_s (buffer, "%s.xp",mName.c_str());return (const char*)buffer;}
	/*compute the X Negative Depthmap.*/
	BoolID getUseXNegativeDmap(){char buffer[4096];sprintf_s (buffer, "%s.xn",mName.c_str());return (const char*)buffer;}
	/*compute the Y Positive Depthmap.*/
	BoolID getUseYPositiveDmap(){char buffer[4096];sprintf_s (buffer, "%s.yp",mName.c_str());return (const char*)buffer;}
	/*compute the Y Negative Depthmap.*/
	BoolID getUseYNegativeDmap(){char buffer[4096];sprintf_s (buffer, "%s.yn",mName.c_str());return (const char*)buffer;}
	/*compute the Z Positive Depthmap.*/
	BoolID getUseZPositiveDmap(){char buffer[4096];sprintf_s (buffer, "%s.zp",mName.c_str());return (const char*)buffer;}
	/*compute the Z Negative Depthmap.*/
	BoolID getUseZNegativeDmap(){char buffer[4096];sprintf_s (buffer, "%s.zn",mName.c_str());return (const char*)buffer;}
	/*The Shadow Map Pre Callback Name*/
	StringID getDmapUseMacro(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*The Shadow Depth Map Name*/
	StringID getDmapName(){char buffer[4096];sprintf_s (buffer, "%s.smn",mName.c_str());return (const char*)buffer;}
	/*Use the light name in the depth map I/O file name.*/
	BoolID getDmapLightName(){char buffer[4096];sprintf_s (buffer, "%s.ul",mName.c_str());return (const char*)buffer;}
	/*Use the scene name in the depth map I/O file name.*/
	BoolID getDmapSceneName(){char buffer[4096];sprintf_s (buffer, "%s.um",mName.c_str());return (const char*)buffer;}
	/*Use the frame extension in the depth map I/O file name.*/
	BoolID getDmapFrameExt(){char buffer[4096];sprintf_s (buffer, "%s.uf",mName.c_str());return (const char*)buffer;}
	/*write shadow depth maps to disk.*/
	BoolID getWriteDmap(){char buffer[4096];sprintf_s (buffer, "%s.ws",mName.c_str());return (const char*)buffer;}
	/*Last written depth map Anim Extension Name*/
	StringID getLastWrittenDmapAnimExtName(){char buffer[4096];sprintf_s (buffer, "%s.lw",mName.c_str());return (const char*)buffer;}
	/*sampleData = geometry receives shadows*/
	BoolID getReceiveShadows(){char buffer[4096];sprintf_s (buffer, "%s.gs",mName.c_str());return (const char*)buffer;}
protected:
	NonExtendedLightShapeNode(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):NonAmbientLightShapeNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NONEXTENDEDLIGHTSHAPENODE_H__
