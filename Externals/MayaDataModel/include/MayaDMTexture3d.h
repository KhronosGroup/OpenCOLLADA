/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TEXTURE3D_H__
#define __MayaDM_TEXTURE3D_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Texture3d</b> is the base node from which all the 3d texture nodes
 derive.  Here you will find all the attributes that are common to
 all 3d textures.
 <p/>
 In the table below, important attributes have their names shown in
 <b>bold</b> in the description column.
*/
class Texture3d : public DependNode
{
public:
public:
	Texture3d(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "texture3d"){}
	virtual ~Texture3d(){}
	/*The current sample point that has to be shaded*/
	void setPointObj(const Float3ID& po){fprintf_s(mFile,"connectAttr \"");po.write(mFile);fprintf_s(mFile,"\" \"%s.po\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointObjX(const FloatID& pox){fprintf_s(mFile,"connectAttr \"");pox.write(mFile);fprintf_s(mFile,"\" \"%s.po.pox\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointObjY(const FloatID& poy){fprintf_s(mFile,"connectAttr \"");poy.write(mFile);fprintf_s(mFile,"\" \"%s.po.poy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointObjZ(const FloatID& poz){fprintf_s(mFile,"connectAttr \"");poz.write(mFile);fprintf_s(mFile,"\" \"%s.po.poz\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	void setPointCamera(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*The sample (filter) size*/
	void setFilterSize(const Float3ID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs\";\n",mName.c_str());}
	/*The X size of the filter (sample)*/
	void setFilterSizeX(const FloatID& fsx){fprintf_s(mFile,"connectAttr \"");fsx.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsx\";\n",mName.c_str());}
	/*The Y size of the filter (sample)*/
	void setFilterSizeY(const FloatID& fsy){fprintf_s(mFile,"connectAttr \"");fsy.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsy\";\n",mName.c_str());}
	/*The Z size of the filter (sample)*/
	void setFilterSizeZ(const FloatID& fsz){fprintf_s(mFile,"connectAttr \"");fsz.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsz\";\n",mName.c_str());}
	/*The placement  matrix, to transform from world to the texture space*/
	void setPlacementMatrix(const FltMatrixID& pm){fprintf_s(mFile,"connectAttr \"");pm.write(mFile);fprintf_s(mFile,"\" \"%s.pm\";\n",mName.c_str());}
	/*The transform to go from eye to world space*/
	void setMatrixEyeToWorld(const FltMatrixID& e2w){fprintf_s(mFile,"connectAttr \"");e2w.write(mFile);fprintf_s(mFile,"\" \"%s.e2w\";\n",mName.c_str());}
	/*
	<b>Filter</b> affects the amount of filtering performed on
	a texture.
	<p/>
	The amount of filtering the system does is calculated based
	on how much screen space the texture occupies in the final
	image.  The Filter attribute is a multiplier on that value.
	<p/>
	Values greater than 1.0 will cause the renderer to do more filtering.
	This will make the texture blurier.  Increase the
	amount of filtering
	if there is aliasing (<i>i.e.</i> jagged staircase effects)
	in your final renderings, or if the
	texture appears to "pop" or "sizzle" over the course of several
	frames.
	<p/>
	Values less than 1.0 will cause the renderer to do less filtering.
	This will make the texture appear sharper.  Decrease
	the amount of filtering.
	if your textures are appearing too blurry in the final rendered
	images.
	<p/>
	This attribute does not do anything if this is a Granite, Leather,
	or Snow texture.
	<p/>
	See also the Filter Offset attribute (below).
	*/
	void setFilter(float f){if(f == 1.0) return; fprintf_s(mFile, "setAttr \".f\" %f;\n", f);}
	/*
	<b>Filter</b> affects the amount of filtering performed on
	a texture.
	<p/>
	The amount of filtering the system does is calculated based
	on how much screen space the texture occupies in the final
	image.  The Filter attribute is a multiplier on that value.
	<p/>
	Values greater than 1.0 will cause the renderer to do more filtering.
	This will make the texture blurier.  Increase the
	amount of filtering
	if there is aliasing (<i>i.e.</i> jagged staircase effects)
	in your final renderings, or if the
	texture appears to "pop" or "sizzle" over the course of several
	frames.
	<p/>
	Values less than 1.0 will cause the renderer to do less filtering.
	This will make the texture appear sharper.  Decrease
	the amount of filtering.
	if your textures are appearing too blurry in the final rendered
	images.
	<p/>
	This attribute does not do anything if this is a Granite, Leather,
	or Snow texture.
	<p/>
	See also the Filter Offset attribute (below).
	*/
	void setFilter(const FloatID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*
	<b>Filter Offset</b> affects the amount of filtering
	performed on a texture.
	<p/>
	Unlike the Filter attribute (which is a multiplier),
	Filter Offset is added to the system's calculated filtering
	values.  This increases the amount of filtering uniformly.
	<p/>
	This attribute can be used to "lock" the system's
	filtering values.  To do this, set the Filter attribute to
	0.  Then the Filter Offset value will completely determine
	the amount of filtering.
	<p/>
	This attribute does not do anything if this is a Granite, Leather,
	or Snow texture.
	*/
	void setFilterOffset(float fo){if(fo == 0.0) return; fprintf_s(mFile, "setAttr \".fo\" %f;\n", fo);}
	/*
	<b>Filter Offset</b> affects the amount of filtering
	performed on a texture.
	<p/>
	Unlike the Filter attribute (which is a multiplier),
	Filter Offset is added to the system's calculated filtering
	values.  This increases the amount of filtering uniformly.
	<p/>
	This attribute can be used to "lock" the system's
	filtering values.  To do this, set the Filter attribute to
	0.  Then the Filter Offset value will completely determine
	the amount of filtering.
	<p/>
	This attribute does not do anything if this is a Granite, Leather,
	or Snow texture.
	*/
	void setFilterOffset(const FloatID& fo){fprintf_s(mFile,"connectAttr \"");fo.write(mFile);fprintf_s(mFile,"\" \"%s.fo\";\n",mName.c_str());}
	/*
	<b>Blend</b> controls how much of the texture's Default
	Color is 'mixed in' to the texture color.
	A value of 0 means that the default color does not
	affect the texture color.  As you increase Blend,
	more and more of the Default Color is mixed in.
	<p/>This attribute
	does not do anything unless Wrap is turned OFF.
	*/
	void setBlend(float b){if(b == 0.0) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*
	<b>Blend</b> controls how much of the texture's Default
	Color is 'mixed in' to the texture color.
	A value of 0 means that the default color does not
	affect the texture color.  As you increase Blend,
	more and more of the Default Color is mixed in.
	<p/>This attribute
	does not do anything unless Wrap is turned OFF.
	*/
	void setBlend(const FloatID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*
	<b>Local</b> controls if the texture is calculated in
	world space, or in the space of the object it is attached
	to.  Turn Local on to put the texture into the object's
	local space.
	*/
	void setLocal(bool lo){if(lo == false) return; fprintf_s(mFile, "setAttr \".lo\" %i;\n", lo);}
	/*
	<b>Wrap</b> controls how objects are textured outside
	of the defined texture placement cube.  If Wrap is
	turned off, then everything outside of the cube will
	just be shown using the default color.  If Wrap is turned
	on, then the texture will extend to cover the whole object.
	<p/>Some textures, such as Projection, will repeat themselves
	to achieve this.  Others, such as Marble, will simply
	extend outwards without repeating.
	*/
	void setWrap(bool w){if(w == true) return; fprintf_s(mFile, "setAttr \".w\" %i;\n", w);}
	/*
	<b>Wrap</b> controls how objects are textured outside
	of the defined texture placement cube.  If Wrap is
	turned off, then everything outside of the cube will
	just be shown using the default color.  If Wrap is turned
	on, then the texture will extend to cover the whole object.
	<p/>Some textures, such as Projection, will repeat themselves
	to achieve this.  Others, such as Marble, will simply
	extend outwards without repeating.
	*/
	void setWrap(const BoolID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*
	<b>Invert</b> is used to reverse the color values of the
	texture.  When Invert is turned on, white becomes black, black
	becomes white, red becomes cyan, yellow becomes blue, etc.
	*/
	void setInvert(bool i){if(i == false) return; fprintf_s(mFile, "setAttr \".i\" %i;\n", i);}
	/*
	<b>Invert</b> is used to reverse the color values of the
	texture.  When Invert is turned on, white becomes black, black
	becomes white, red becomes cyan, yellow becomes blue, etc.
	*/
	void setInvert(const BoolID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*
	<b>Alpha Is Luminance</b> can be turned on to make the
	alpha (mask) output of this node depend on the luminance
	of the texture.  This means that bright areas of the texture
	will be more opaque when compositing, and dark areas will
	be more transparent.
	<p/>
	This attribute is not used in textures of type Marble, Projection,
	or Wood.
	*/
	void setAlphaIsLuminance(bool ail){if(ail == false) return; fprintf_s(mFile, "setAttr \".ail\" %i;\n", ail);}
	/*
	<b>Alpha Is Luminance</b> can be turned on to make the
	alpha (mask) output of this node depend on the luminance
	of the texture.  This means that bright areas of the texture
	will be more opaque when compositing, and dark areas will
	be more transparent.
	<p/>
	This attribute is not used in textures of type Marble, Projection,
	or Wood.
	*/
	void setAlphaIsLuminance(const BoolID& ail){fprintf_s(mFile,"connectAttr \"");ail.write(mFile);fprintf_s(mFile,"\" \"%s.ail\";\n",mName.c_str());}
	/*
	Use <b>Color Gain</b> to fine-tune the balance of a texture's
	Out Color.
	<p/>
	Color Gain is applied as a multiplier to the texture's
	color.  If Color Gain is white, it has no effect.  Reducing
	the amount of red (for example) in Color Gain will scale down
	the amount of red in the final output color.
	*/
	void setColorGain(const float3& cg){if(cg == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".cg\" -type \"float3\" ");cg.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Use <b>Color Gain</b> to fine-tune the balance of a texture's
	Out Color.
	<p/>
	Color Gain is applied as a multiplier to the texture's
	color.  If Color Gain is white, it has no effect.  Reducing
	the amount of red (for example) in Color Gain will scale down
	the amount of red in the final output color.
	*/
	void setColorGain(const Float3ID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.cg\";\n",mName.c_str());}
	/*Color Gain Red Value*/
	void setColorGainR(float cgr){if(cgr == 0.0) return; fprintf_s(mFile, "setAttr \".cg.cgr\" %f;\n", cgr);}
	/*Color Gain Red Value*/
	void setColorGainR(const FloatID& cgr){fprintf_s(mFile,"connectAttr \"");cgr.write(mFile);fprintf_s(mFile,"\" \"%s.cg.cgr\";\n",mName.c_str());}
	/*Color Gain Green Value*/
	void setColorGainG(float cgg){if(cgg == 0.0) return; fprintf_s(mFile, "setAttr \".cg.cgg\" %f;\n", cgg);}
	/*Color Gain Green Value*/
	void setColorGainG(const FloatID& cgg){fprintf_s(mFile,"connectAttr \"");cgg.write(mFile);fprintf_s(mFile,"\" \"%s.cg.cgg\";\n",mName.c_str());}
	/*Color Gain Blue Value*/
	void setColorGainB(float cgb){if(cgb == 0.0) return; fprintf_s(mFile, "setAttr \".cg.cgb\" %f;\n", cgb);}
	/*Color Gain Blue Value*/
	void setColorGainB(const FloatID& cgb){fprintf_s(mFile,"connectAttr \"");cgb.write(mFile);fprintf_s(mFile,"\" \"%s.cg.cgb\";\n",mName.c_str());}
	/*
	Use <b>Color Offset</b> to brighten and adjust a texture's
	Out Color.
	<p/>
	Unlike Color Gain (which is a multiplier), Color Offset
	is simply added to the texture's Out
	Color.  Therefore if Color Offset is white, it has no effect.
	Increasing
	the amount of red (for example) in Color Gain will uniformly increase
	the amount of red in the final output color.
	*/
	void setColorOffset(const float3& co){if(co == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".co\" -type \"float3\" ");co.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Use <b>Color Offset</b> to brighten and adjust a texture's
	Out Color.
	<p/>
	Unlike Color Gain (which is a multiplier), Color Offset
	is simply added to the texture's Out
	Color.  Therefore if Color Offset is white, it has no effect.
	Increasing
	the amount of red (for example) in Color Gain will uniformly increase
	the amount of red in the final output color.
	*/
	void setColorOffset(const Float3ID& co){fprintf_s(mFile,"connectAttr \"");co.write(mFile);fprintf_s(mFile,"\" \"%s.co\";\n",mName.c_str());}
	/*Color Offset Red Value*/
	void setColorOffsetR(float cor){if(cor == 0.0) return; fprintf_s(mFile, "setAttr \".co.cor\" %f;\n", cor);}
	/*Color Offset Red Value*/
	void setColorOffsetR(const FloatID& cor){fprintf_s(mFile,"connectAttr \"");cor.write(mFile);fprintf_s(mFile,"\" \"%s.co.cor\";\n",mName.c_str());}
	/*Color Offset Green Value*/
	void setColorOffsetG(float cog){if(cog == 0.0) return; fprintf_s(mFile, "setAttr \".co.cog\" %f;\n", cog);}
	/*Color Offset Green Value*/
	void setColorOffsetG(const FloatID& cog){fprintf_s(mFile,"connectAttr \"");cog.write(mFile);fprintf_s(mFile,"\" \"%s.co.cog\";\n",mName.c_str());}
	/*Color Offset Blue Value*/
	void setColorOffsetB(float cob){if(cob == 0.0) return; fprintf_s(mFile, "setAttr \".co.cob\" %f;\n", cob);}
	/*Color Offset Blue Value*/
	void setColorOffsetB(const FloatID& cob){fprintf_s(mFile,"connectAttr \"");cob.write(mFile);fprintf_s(mFile,"\" \"%s.co.cob\";\n",mName.c_str());}
	/*
	<b>Alpha Gain</b> is a multiplier that affects the
	alpha (mask) channel.
	*/
	void setAlphaGain(float ag){if(ag == 1.0) return; fprintf_s(mFile, "setAttr \".ag\" %f;\n", ag);}
	/*
	<b>Alpha Gain</b> is a multiplier that affects the
	alpha (mask) channel.
	*/
	void setAlphaGain(const FloatID& ag){fprintf_s(mFile,"connectAttr \"");ag.write(mFile);fprintf_s(mFile,"\" \"%s.ag\";\n",mName.c_str());}
	/*
	<b>Alpha Offset</b> is a value that is added to the
	alpha (mask) channel.
	*/
	void setAlphaOffset(float ao){if(ao == 0.0) return; fprintf_s(mFile, "setAttr \".ao\" %f;\n", ao);}
	/*
	<b>Alpha Offset</b> is a value that is added to the
	alpha (mask) channel.
	*/
	void setAlphaOffset(const FloatID& ao){fprintf_s(mFile,"connectAttr \"");ao.write(mFile);fprintf_s(mFile,"\" \"%s.ao\";\n",mName.c_str());}
	/*
	<b>Default Color</b> is the color of the texture in the
	areas that are not mapped.  If the placement of this
	texture is not covering an entire surface, then Default
	Color will be used in the areas not covered.
	<p/>See also the Wrap attribute.
	*/
	void setDefaultColor(const float3& dc){if(dc == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".dc\" -type \"float3\" ");dc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Default Color</b> is the color of the texture in the
	areas that are not mapped.  If the placement of this
	texture is not covering an entire surface, then Default
	Color will be used in the areas not covered.
	<p/>See also the Wrap attribute.
	*/
	void setDefaultColor(const Float3ID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*Default Color red value.*/
	void setDefaultColorR(float dcr){if(dcr == 0.0) return; fprintf_s(mFile, "setAttr \".dc.dcr\" %f;\n", dcr);}
	/*Default Color red value.*/
	void setDefaultColorR(const FloatID& dcr){fprintf_s(mFile,"connectAttr \"");dcr.write(mFile);fprintf_s(mFile,"\" \"%s.dc.dcr\";\n",mName.c_str());}
	/*Default Color Green value.*/
	void setDefaultColorG(float dcg){if(dcg == 0.0) return; fprintf_s(mFile, "setAttr \".dc.dcg\" %f;\n", dcg);}
	/*Default Color Green value.*/
	void setDefaultColorG(const FloatID& dcg){fprintf_s(mFile,"connectAttr \"");dcg.write(mFile);fprintf_s(mFile,"\" \"%s.dc.dcg\";\n",mName.c_str());}
	/*Default Color blue value.*/
	void setDefaultColorB(float dcb){if(dcb == 0.0) return; fprintf_s(mFile, "setAttr \".dc.dcb\" %f;\n", dcb);}
	/*Default Color blue value.*/
	void setDefaultColorB(const FloatID& dcb){fprintf_s(mFile,"connectAttr \"");dcb.write(mFile);fprintf_s(mFile,"\" \"%s.dc.dcb\";\n",mName.c_str());}
	/*
	<b>Out Color</b> is the color computed by this texture.
	Connect this value to a Color
	attribute of a shader or another texture to texture map that color.
	*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Out Color red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*Out Color green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*Out Color blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*
	<b>Out Alpha</b> is the alpha (mask) value computed by
	texture.  Connect this value to a bump node or a displacement
	node of a shader to use this texture as a bump or
	displacement map.
	*/
	void setOutAlpha(const FloatID& oa){fprintf_s(mFile,"connectAttr \"");oa.write(mFile);fprintf_s(mFile,"\" \"%s.oa\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	Float3ID getPointObj(){char buffer[4096];sprintf_s (buffer, "%s.po",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.po.pox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.po.poy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.po.poz",mName.c_str());return (const char*)buffer;}
	/*The current sample point that has to be shaded*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*The sample (filter) size*/
	Float3ID getFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.fs",mName.c_str());return (const char*)buffer;}
	/*The X size of the filter (sample)*/
	FloatID getFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsx",mName.c_str());return (const char*)buffer;}
	/*The Y size of the filter (sample)*/
	FloatID getFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsy",mName.c_str());return (const char*)buffer;}
	/*The Z size of the filter (sample)*/
	FloatID getFilterSizeZ(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsz",mName.c_str());return (const char*)buffer;}
	/*The placement  matrix, to transform from world to the texture space*/
	FltMatrixID getPlacementMatrix(){char buffer[4096];sprintf_s (buffer, "%s.pm",mName.c_str());return (const char*)buffer;}
	/*The transform to go from eye to world space*/
	FltMatrixID getMatrixEyeToWorld(){char buffer[4096];sprintf_s (buffer, "%s.e2w",mName.c_str());return (const char*)buffer;}
	/*
	<b>Filter</b> affects the amount of filtering performed on
	a texture.
	<p/>
	The amount of filtering the system does is calculated based
	on how much screen space the texture occupies in the final
	image.  The Filter attribute is a multiplier on that value.
	<p/>
	Values greater than 1.0 will cause the renderer to do more filtering.
	This will make the texture blurier.  Increase the
	amount of filtering
	if there is aliasing (<i>i.e.</i> jagged staircase effects)
	in your final renderings, or if the
	texture appears to "pop" or "sizzle" over the course of several
	frames.
	<p/>
	Values less than 1.0 will cause the renderer to do less filtering.
	This will make the texture appear sharper.  Decrease
	the amount of filtering.
	if your textures are appearing too blurry in the final rendered
	images.
	<p/>
	This attribute does not do anything if this is a Granite, Leather,
	or Snow texture.
	<p/>
	See also the Filter Offset attribute (below).
	*/
	FloatID getFilter(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*
	<b>Filter Offset</b> affects the amount of filtering
	performed on a texture.
	<p/>
	Unlike the Filter attribute (which is a multiplier),
	Filter Offset is added to the system's calculated filtering
	values.  This increases the amount of filtering uniformly.
	<p/>
	This attribute can be used to "lock" the system's
	filtering values.  To do this, set the Filter attribute to
	0.  Then the Filter Offset value will completely determine
	the amount of filtering.
	<p/>
	This attribute does not do anything if this is a Granite, Leather,
	or Snow texture.
	*/
	FloatID getFilterOffset(){char buffer[4096];sprintf_s (buffer, "%s.fo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Blend</b> controls how much of the texture's Default
	Color is 'mixed in' to the texture color.
	A value of 0 means that the default color does not
	affect the texture color.  As you increase Blend,
	more and more of the Default Color is mixed in.
	<p/>This attribute
	does not do anything unless Wrap is turned OFF.
	*/
	FloatID getBlend(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wrap</b> controls how objects are textured outside
	of the defined texture placement cube.  If Wrap is
	turned off, then everything outside of the cube will
	just be shown using the default color.  If Wrap is turned
	on, then the texture will extend to cover the whole object.
	<p/>Some textures, such as Projection, will repeat themselves
	to achieve this.  Others, such as Marble, will simply
	extend outwards without repeating.
	*/
	BoolID getWrap(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*
	<b>Invert</b> is used to reverse the color values of the
	texture.  When Invert is turned on, white becomes black, black
	becomes white, red becomes cyan, yellow becomes blue, etc.
	*/
	BoolID getInvert(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*
	<b>Alpha Is Luminance</b> can be turned on to make the
	alpha (mask) output of this node depend on the luminance
	of the texture.  This means that bright areas of the texture
	will be more opaque when compositing, and dark areas will
	be more transparent.
	<p/>
	This attribute is not used in textures of type Marble, Projection,
	or Wood.
	*/
	BoolID getAlphaIsLuminance(){char buffer[4096];sprintf_s (buffer, "%s.ail",mName.c_str());return (const char*)buffer;}
	/*
	Use <b>Color Gain</b> to fine-tune the balance of a texture's
	Out Color.
	<p/>
	Color Gain is applied as a multiplier to the texture's
	color.  If Color Gain is white, it has no effect.  Reducing
	the amount of red (for example) in Color Gain will scale down
	the amount of red in the final output color.
	*/
	Float3ID getColorGain(){char buffer[4096];sprintf_s (buffer, "%s.cg",mName.c_str());return (const char*)buffer;}
	/*Color Gain Red Value*/
	FloatID getColorGainR(){char buffer[4096];sprintf_s (buffer, "%s.cg.cgr",mName.c_str());return (const char*)buffer;}
	/*Color Gain Green Value*/
	FloatID getColorGainG(){char buffer[4096];sprintf_s (buffer, "%s.cg.cgg",mName.c_str());return (const char*)buffer;}
	/*Color Gain Blue Value*/
	FloatID getColorGainB(){char buffer[4096];sprintf_s (buffer, "%s.cg.cgb",mName.c_str());return (const char*)buffer;}
	/*
	Use <b>Color Offset</b> to brighten and adjust a texture's
	Out Color.
	<p/>
	Unlike Color Gain (which is a multiplier), Color Offset
	is simply added to the texture's Out
	Color.  Therefore if Color Offset is white, it has no effect.
	Increasing
	the amount of red (for example) in Color Gain will uniformly increase
	the amount of red in the final output color.
	*/
	Float3ID getColorOffset(){char buffer[4096];sprintf_s (buffer, "%s.co",mName.c_str());return (const char*)buffer;}
	/*Color Offset Red Value*/
	FloatID getColorOffsetR(){char buffer[4096];sprintf_s (buffer, "%s.co.cor",mName.c_str());return (const char*)buffer;}
	/*Color Offset Green Value*/
	FloatID getColorOffsetG(){char buffer[4096];sprintf_s (buffer, "%s.co.cog",mName.c_str());return (const char*)buffer;}
	/*Color Offset Blue Value*/
	FloatID getColorOffsetB(){char buffer[4096];sprintf_s (buffer, "%s.co.cob",mName.c_str());return (const char*)buffer;}
	/*
	<b>Alpha Gain</b> is a multiplier that affects the
	alpha (mask) channel.
	*/
	FloatID getAlphaGain(){char buffer[4096];sprintf_s (buffer, "%s.ag",mName.c_str());return (const char*)buffer;}
	/*
	<b>Alpha Offset</b> is a value that is added to the
	alpha (mask) channel.
	*/
	FloatID getAlphaOffset(){char buffer[4096];sprintf_s (buffer, "%s.ao",mName.c_str());return (const char*)buffer;}
	/*
	<b>Default Color</b> is the color of the texture in the
	areas that are not mapped.  If the placement of this
	texture is not covering an entire surface, then Default
	Color will be used in the areas not covered.
	<p/>See also the Wrap attribute.
	*/
	Float3ID getDefaultColor(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*Default Color red value.*/
	FloatID getDefaultColorR(){char buffer[4096];sprintf_s (buffer, "%s.dc.dcr",mName.c_str());return (const char*)buffer;}
	/*Default Color Green value.*/
	FloatID getDefaultColorG(){char buffer[4096];sprintf_s (buffer, "%s.dc.dcg",mName.c_str());return (const char*)buffer;}
	/*Default Color blue value.*/
	FloatID getDefaultColorB(){char buffer[4096];sprintf_s (buffer, "%s.dc.dcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Color</b> is the color computed by this texture.
	Connect this value to a Color
	attribute of a shader or another texture to texture map that color.
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*Out Color red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*Out Color green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*Out Color blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Alpha</b> is the alpha (mask) value computed by
	texture.  Connect this value to a bump node or a displacement
	node of a shader to use this texture as a bump or
	displacement map.
	*/
	FloatID getOutAlpha(){char buffer[4096];sprintf_s (buffer, "%s.oa",mName.c_str());return (const char*)buffer;}
protected:
	Texture3d(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TEXTURE3D_H__
