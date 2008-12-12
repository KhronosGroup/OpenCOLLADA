/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HWRENDERGLOBALS_H__
#define __MayaDM_HWRENDERGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    Node used to store global hardware render attributes. By using
    a node, these attributes will be read/written to file. There
    should only be one of these nodes.
</pre></p>
*/
class HwRenderGlobals : public DependNode
{
public:
public:
	HwRenderGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hwRenderGlobals"){}
	virtual ~HwRenderGlobals(){}
	/*The number of accum buffer render passes.*/
	void setRenderPasses(unsigned int rp){if(rp == 0) return; fprintf_s(mFile, "setAttr \".rp\" %i;\n", rp);}
	/*The number of accum buffer render passes.*/
	void setRenderPasses(const UnsignedintID& rp){fprintf_s(mFile,"connectAttr \"");rp.write(mFile);fprintf_s(mFile,"\" \"%s.rp\";\n",mName.c_str());}
	/*Display status of camera icons*/
	void setCameraIcons(bool cai){if(cai == false) return; fprintf_s(mFile, "setAttr \".cai\" %i;\n", cai);}
	/*Display status of camera icons*/
	void setCameraIcons(const BoolID& cai){fprintf_s(mFile,"connectAttr \"");cai.write(mFile);fprintf_s(mFile,"\" \"%s.cai\";\n",mName.c_str());}
	/*Display status of collison model icons*/
	void setCollisionIcons(bool coi){if(coi == false) return; fprintf_s(mFile, "setAttr \".coi\" %i;\n", coi);}
	/*Display status of collison model icons*/
	void setCollisionIcons(const BoolID& coi){fprintf_s(mFile,"connectAttr \"");coi.write(mFile);fprintf_s(mFile,"\" \"%s.coi\";\n",mName.c_str());}
	/*The viewport clear color.*/
	void setBackgroundColor(const float3& bc){if(bc == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".bc\" -type \"float3\" ");bc.write(mFile);fprintf_s(mFile,";\n");}
	/*The viewport clear color.*/
	void setBackgroundColor(const Float3ID& bc){fprintf_s(mFile,"connectAttr \"");bc.write(mFile);fprintf_s(mFile,"\" \"%s.bc\";\n",mName.c_str());}
	/*The viewport clear color red component (see backgroundColor).*/
	void setBackgroundColorR(float bcr){if(bcr == 0.0) return; fprintf_s(mFile, "setAttr \".bc.bcr\" %f;\n", bcr);}
	/*The viewport clear color red component (see backgroundColor).*/
	void setBackgroundColorR(const FloatID& bcr){fprintf_s(mFile,"connectAttr \"");bcr.write(mFile);fprintf_s(mFile,"\" \"%s.bc.bcr\";\n",mName.c_str());}
	/*The viewport clear color green component (see backgroundColor).*/
	void setBackgroundColorG(float bcg){if(bcg == 0.0) return; fprintf_s(mFile, "setAttr \".bc.bcg\" %f;\n", bcg);}
	/*The viewport clear color green component (see backgroundColor).*/
	void setBackgroundColorG(const FloatID& bcg){fprintf_s(mFile,"connectAttr \"");bcg.write(mFile);fprintf_s(mFile,"\" \"%s.bc.bcg\";\n",mName.c_str());}
	/*The viewport clear color blue component (see backgroundColor).*/
	void setBackgroundColorB(float bcb){if(bcb == 0.0) return; fprintf_s(mFile, "setAttr \".bc.bcb\" %f;\n", bcb);}
	/*The viewport clear color blue component (see backgroundColor).*/
	void setBackgroundColorB(const FloatID& bcb){fprintf_s(mFile,"connectAttr \"");bcb.write(mFile);fprintf_s(mFile,"\" \"%s.bc.bcb\";\n",mName.c_str());}
	/*Display status of emitter icons*/
	void setEmitterIcons(bool ei){if(ei == false) return; fprintf_s(mFile, "setAttr \".ei\" %i;\n", ei);}
	/*Display status of emitter icons*/
	void setEmitterIcons(const BoolID& ei){fprintf_s(mFile,"connectAttr \"");ei.write(mFile);fprintf_s(mFile,"\" \"%s.ei\";\n",mName.c_str());}
	/*Specify number padding and extension.*/
	void setExtension(unsigned int ex){if(ex == 3) return; fprintf_s(mFile, "setAttr \".ex\" %i;\n", ex);}
	/*Specify number padding and extension.*/
	void setExtension(const UnsignedintID& ex){fprintf_s(mFile,"connectAttr \"");ex.write(mFile);fprintf_s(mFile,"\" \"%s.ex\";\n",mName.c_str());}
	/*Controls the amount of edge smoothing.*/
	void setEdgeSmoothing(float es){if(es == 1.0) return; fprintf_s(mFile, "setAttr \".es\" %f;\n", es);}
	/*Controls the amount of edge smoothing.*/
	void setEdgeSmoothing(const FloatID& es){fprintf_s(mFile,"connectAttr \"");es.write(mFile);fprintf_s(mFile,"\" \"%s.es\";\n",mName.c_str());}
	/*The last frame to be rendered*/
	void setEndFrame(int ef){if(ef == 10) return; fprintf_s(mFile, "setAttr \".ef\" %i;\n", ef);}
	/*The last frame to be rendered*/
	void setEndFrame(const IntID& ef){fprintf_s(mFile,"connectAttr \"");ef.write(mFile);fprintf_s(mFile,"\" \"%s.ef\";\n",mName.c_str());}
	/*The frame increment during rendering*/
	void setByFrame(int bf){if(bf == 1) return; fprintf_s(mFile, "setAttr \".bf\" %i;\n", bf);}
	/*The frame increment during rendering*/
	void setByFrame(const IntID& bf){fprintf_s(mFile,"connectAttr \"");bf.write(mFile);fprintf_s(mFile,"\" \"%s.bf\";\n",mName.c_str());}
	/*Display status of field icons*/
	void setFieldIcons(bool fii){if(fii == false) return; fprintf_s(mFile, "setAttr \".fii\" %i;\n", fii);}
	/*Display status of field icons*/
	void setFieldIcons(const BoolID& fii){fprintf_s(mFile,"connectAttr \"");fii.write(mFile);fprintf_s(mFile,"\" \"%s.fii\";\n",mName.c_str());}
	/*The first frame to be rendered*/
	void setStartFrame(int sf){if(sf == 1) return; fprintf_s(mFile, "setAttr \".sf\" %i;\n", sf);}
	/*The first frame to be rendered*/
	void setStartFrame(const IntID& sf){fprintf_s(mFile,"connectAttr \"");sf.write(mFile);fprintf_s(mFile,"\" \"%s.sf\";\n",mName.c_str());}
	/*Display status of the grid*/
	void setGrid(bool gr){if(gr == false) return; fprintf_s(mFile, "setAttr \".gr\" %i;\n", gr);}
	/*Display status of the grid*/
	void setGrid(const BoolID& gr){fprintf_s(mFile,"connectAttr \"");gr.write(mFile);fprintf_s(mFile,"\" \"%s.gr\";\n",mName.c_str());}
	/*Display status of light icons*/
	void setLightIcons(bool li){if(li == false) return; fprintf_s(mFile, "setAttr \".li\" %i;\n", li);}
	/*Display status of light icons*/
	void setLightIcons(const BoolID& li){fprintf_s(mFile,"connectAttr \"");li.write(mFile);fprintf_s(mFile,"\" \"%s.li\";\n",mName.c_str());}
	/*Enable/disable anti-aliased lines*/
	void setLineSmoothing(bool ls){if(ls == false) return; fprintf_s(mFile, "setAttr \".ls\" %i;\n", ls);}
	/*Enable/disable anti-aliased lines*/
	void setLineSmoothing(const BoolID& ls){fprintf_s(mFile,"connectAttr \"");ls.write(mFile);fprintf_s(mFile,"\" \"%s.ls\";\n",mName.c_str());}
	/*Set the shutter angle used for motion blur.*/
	void setMotionBlur(float mb){if(mb == 0.0) return; fprintf_s(mFile, "setAttr \".mb\" %f;\n", mb);}
	/*Set the shutter angle used for motion blur.*/
	void setMotionBlur(const FloatID& mb){fprintf_s(mFile,"connectAttr \"");mb.write(mFile);fprintf_s(mFile,"\" \"%s.mb\";\n",mName.c_str());}
	/*Display status of transform icons*/
	void setTransformIcons(bool ti){if(ti == false) return; fprintf_s(mFile, "setAttr \".ti\" %i;\n", ti);}
	/*Display status of transform icons*/
	void setTransformIcons(const BoolID& ti){fprintf_s(mFile,"connectAttr \"");ti.write(mFile);fprintf_s(mFile,"\" \"%s.ti\";\n",mName.c_str());}
	/*Enable/disable texture map display*/
	void setTexturing(bool txt){if(txt == true) return; fprintf_s(mFile, "setAttr \".txt\" %i;\n", txt);}
	/*Enable/disable texture map display*/
	void setTexturing(const BoolID& txt){fprintf_s(mFile,"connectAttr \"");txt.write(mFile);fprintf_s(mFile,"\" \"%s.txt\";\n",mName.c_str());}
	/*Control the multipass rendering.*/
	void setMultiPassRendering(bool mpr){if(mpr == false) return; fprintf_s(mFile, "setAttr \".mpr\" %i;\n", mpr);}
	/*Control the multipass rendering.*/
	void setMultiPassRendering(const BoolID& mpr){fprintf_s(mFile,"connectAttr \"");mpr.write(mFile);fprintf_s(mFile,"\" \"%s.mpr\";\n",mName.c_str());}
	/*Enable/disable writing of zdepth to image files*/
	void setWriteZDepth(bool wzd){if(wzd == false) return; fprintf_s(mFile, "setAttr \".wzd\" %i;\n", wzd);}
	/*Enable/disable writing of zdepth to image files*/
	void setWriteZDepth(const BoolID& wzd){fprintf_s(mFile,"connectAttr \"");wzd.write(mFile);fprintf_s(mFile,"\" \"%s.wzd\";\n",mName.c_str());}
	/*Image output filename.*/
	void setFilename(const string& fn){if(fn == "NULL") return; fprintf_s(mFile, "setAttr \".fn\" -type \"string\" ");fn.write(mFile);fprintf_s(mFile,";\n");}
	/*Image output filename.*/
	void setFilename(const StringID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn\";\n",mName.c_str());}
	/*Specifies image file format.*/
	void setImageFormat(unsigned int if_){if(if_ == 0) return; fprintf_s(mFile, "setAttr \".if\" %i;\n", if_);}
	/*Specifies image file format.*/
	void setImageFormat(const UnsignedintID& if_){fprintf_s(mFile,"connectAttr \"");if_.write(mFile);fprintf_s(mFile,"\" \"%s.if\";\n",mName.c_str());}
	/*Image output resolution (and aspect ratio).*/
	void setResolution(const string& res){if(res == "NULL") return; fprintf_s(mFile, "setAttr \".res\" -type \"string\" ");res.write(mFile);fprintf_s(mFile,";\n");}
	/*Image output resolution (and aspect ratio).*/
	void setResolution(const StringID& res){fprintf_s(mFile,"connectAttr \"");res.write(mFile);fprintf_s(mFile,"\" \"%s.res\";\n",mName.c_str());}
	/*Specifies how to compute the alpha channel.*/
	void setAlphaSource(unsigned int as){if(as == 0) return; fprintf_s(mFile, "setAttr \".as\" %i;\n", as);}
	/*Specifies how to compute the alpha channel.*/
	void setAlphaSource(const UnsignedintID& as){fprintf_s(mFile,"connectAttr \"");as.write(mFile);fprintf_s(mFile,"\" \"%s.as\";\n",mName.c_str());}
	/*Specifies how to draw the geometry.*/
	void setDrawStyle(unsigned int ds){if(ds == 3) return; fprintf_s(mFile, "setAttr \".ds\" %i;\n", ds);}
	/*Specifies how to draw the geometry.*/
	void setDrawStyle(const UnsignedintID& ds){fprintf_s(mFile,"connectAttr \"");ds.write(mFile);fprintf_s(mFile,"\" \"%s.ds\";\n",mName.c_str());}
	/*Specifies the lighting mode used for rendering.*/
	void setLightingMode(unsigned int lm){if(lm == 0) return; fprintf_s(mFile, "setAttr \".lm\" %i;\n", lm);}
	/*Specifies the lighting mode used for rendering.*/
	void setLightingMode(const UnsignedintID& lm){fprintf_s(mFile,"connectAttr \"");lm.write(mFile);fprintf_s(mFile,"\" \"%s.lm\";\n",mName.c_str());}
	/*Output full image resolution (turns on tiling if needed).*/
	void setFullImageResolution(bool fir){if(fir == false) return; fprintf_s(mFile, "setAttr \".fir\" %i;\n", fir);}
	/*Output full image resolution (turns on tiling if needed).*/
	void setFullImageResolution(const BoolID& fir){fprintf_s(mFile,"connectAttr \"");fir.write(mFile);fprintf_s(mFile,"\" \"%s.fir\";\n",mName.c_str());}
	/*Turns on/off camera jitter to anti-alias polygons.*/
	void setAntiAliasPolygons(bool aap){if(aap == false) return; fprintf_s(mFile, "setAttr \".aap\" %i;\n", aap);}
	/*Turns on/off camera jitter to anti-alias polygons.*/
	void setAntiAliasPolygons(const BoolID& aap){fprintf_s(mFile,"connectAttr \"");aap.write(mFile);fprintf_s(mFile,"\" \"%s.aap\";\n",mName.c_str());}
	/*Use geometry as a mask for particles.*/
	void setGeometryMask(bool gh){if(gh == false) return; fprintf_s(mFile, "setAttr \".gh\" %i;\n", gh);}
	/*Use geometry as a mask for particles.*/
	void setGeometryMask(const BoolID& gh){fprintf_s(mFile,"connectAttr \"");gh.write(mFile);fprintf_s(mFile,"\" \"%s.gh\";\n",mName.c_str());}
	/*Display shadows when in all or selected lights mode*/
	void setDisplayShadows(bool sd){if(sd == false) return; fprintf_s(mFile, "setAttr \".sd\" %i;\n", sd);}
	/*Display shadows when in all or selected lights mode*/
	void setDisplayShadows(const BoolID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd\";\n",mName.c_str());}
	/*The number of accum buffer render passes.*/
	UnsignedintID getRenderPasses(){char buffer[4096];sprintf_s (buffer, "%s.rp",mName.c_str());return (const char*)buffer;}
	/*Display status of camera icons*/
	BoolID getCameraIcons(){char buffer[4096];sprintf_s (buffer, "%s.cai",mName.c_str());return (const char*)buffer;}
	/*Display status of collison model icons*/
	BoolID getCollisionIcons(){char buffer[4096];sprintf_s (buffer, "%s.coi",mName.c_str());return (const char*)buffer;}
	/*The viewport clear color.*/
	Float3ID getBackgroundColor(){char buffer[4096];sprintf_s (buffer, "%s.bc",mName.c_str());return (const char*)buffer;}
	/*The viewport clear color red component (see backgroundColor).*/
	FloatID getBackgroundColorR(){char buffer[4096];sprintf_s (buffer, "%s.bc.bcr",mName.c_str());return (const char*)buffer;}
	/*The viewport clear color green component (see backgroundColor).*/
	FloatID getBackgroundColorG(){char buffer[4096];sprintf_s (buffer, "%s.bc.bcg",mName.c_str());return (const char*)buffer;}
	/*The viewport clear color blue component (see backgroundColor).*/
	FloatID getBackgroundColorB(){char buffer[4096];sprintf_s (buffer, "%s.bc.bcb",mName.c_str());return (const char*)buffer;}
	/*Display status of emitter icons*/
	BoolID getEmitterIcons(){char buffer[4096];sprintf_s (buffer, "%s.ei",mName.c_str());return (const char*)buffer;}
	/*Specify number padding and extension.*/
	UnsignedintID getExtension(){char buffer[4096];sprintf_s (buffer, "%s.ex",mName.c_str());return (const char*)buffer;}
	/*Controls the amount of edge smoothing.*/
	FloatID getEdgeSmoothing(){char buffer[4096];sprintf_s (buffer, "%s.es",mName.c_str());return (const char*)buffer;}
	/*The last frame to be rendered*/
	IntID getEndFrame(){char buffer[4096];sprintf_s (buffer, "%s.ef",mName.c_str());return (const char*)buffer;}
	/*The frame increment during rendering*/
	IntID getByFrame(){char buffer[4096];sprintf_s (buffer, "%s.bf",mName.c_str());return (const char*)buffer;}
	/*Display status of field icons*/
	BoolID getFieldIcons(){char buffer[4096];sprintf_s (buffer, "%s.fii",mName.c_str());return (const char*)buffer;}
	/*The first frame to be rendered*/
	IntID getStartFrame(){char buffer[4096];sprintf_s (buffer, "%s.sf",mName.c_str());return (const char*)buffer;}
	/*Display status of the grid*/
	BoolID getGrid(){char buffer[4096];sprintf_s (buffer, "%s.gr",mName.c_str());return (const char*)buffer;}
	/*Display status of light icons*/
	BoolID getLightIcons(){char buffer[4096];sprintf_s (buffer, "%s.li",mName.c_str());return (const char*)buffer;}
	/*Enable/disable anti-aliased lines*/
	BoolID getLineSmoothing(){char buffer[4096];sprintf_s (buffer, "%s.ls",mName.c_str());return (const char*)buffer;}
	/*Set the shutter angle used for motion blur.*/
	FloatID getMotionBlur(){char buffer[4096];sprintf_s (buffer, "%s.mb",mName.c_str());return (const char*)buffer;}
	/*Display status of transform icons*/
	BoolID getTransformIcons(){char buffer[4096];sprintf_s (buffer, "%s.ti",mName.c_str());return (const char*)buffer;}
	/*Enable/disable texture map display*/
	BoolID getTexturing(){char buffer[4096];sprintf_s (buffer, "%s.txt",mName.c_str());return (const char*)buffer;}
	/*Control the multipass rendering.*/
	BoolID getMultiPassRendering(){char buffer[4096];sprintf_s (buffer, "%s.mpr",mName.c_str());return (const char*)buffer;}
	/*Enable/disable writing of zdepth to image files*/
	BoolID getWriteZDepth(){char buffer[4096];sprintf_s (buffer, "%s.wzd",mName.c_str());return (const char*)buffer;}
	/*Image output filename.*/
	StringID getFilename(){char buffer[4096];sprintf_s (buffer, "%s.fn",mName.c_str());return (const char*)buffer;}
	/*Specifies image file format.*/
	UnsignedintID getImageFormat(){char buffer[4096];sprintf_s (buffer, "%s.if",mName.c_str());return (const char*)buffer;}
	/*Image output resolution (and aspect ratio).*/
	StringID getResolution(){char buffer[4096];sprintf_s (buffer, "%s.res",mName.c_str());return (const char*)buffer;}
	/*Specifies how to compute the alpha channel.*/
	UnsignedintID getAlphaSource(){char buffer[4096];sprintf_s (buffer, "%s.as",mName.c_str());return (const char*)buffer;}
	/*Specifies how to draw the geometry.*/
	UnsignedintID getDrawStyle(){char buffer[4096];sprintf_s (buffer, "%s.ds",mName.c_str());return (const char*)buffer;}
	/*Specifies the lighting mode used for rendering.*/
	UnsignedintID getLightingMode(){char buffer[4096];sprintf_s (buffer, "%s.lm",mName.c_str());return (const char*)buffer;}
	/*Output full image resolution (turns on tiling if needed).*/
	BoolID getFullImageResolution(){char buffer[4096];sprintf_s (buffer, "%s.fir",mName.c_str());return (const char*)buffer;}
	/*Turns on/off camera jitter to anti-alias polygons.*/
	BoolID getAntiAliasPolygons(){char buffer[4096];sprintf_s (buffer, "%s.aap",mName.c_str());return (const char*)buffer;}
	/*Use geometry as a mask for particles.*/
	BoolID getGeometryMask(){char buffer[4096];sprintf_s (buffer, "%s.gh",mName.c_str());return (const char*)buffer;}
	/*Display shadows when in all or selected lights mode*/
	BoolID getDisplayShadows(){char buffer[4096];sprintf_s (buffer, "%s.sd",mName.c_str());return (const char*)buffer;}
protected:
	HwRenderGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HWRENDERGLOBALS_H__
