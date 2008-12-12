/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ROCK_H__
#define __MayaDM_ROCK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
<b>Rock</b> is a solid texture created by blending two distinct
 colors using 3d granular noise.  The result resembles rock.
 <p/>
 Used as a bump map, the Rock texture can produce a rough,
 sandpaper-like texture.
 <p/>
 Aside from the attributes listed here, Rock inherits many
 other attributes from its parent, <a href="texture3d.html">
 Texture3d</a>
<p/>
 In the table below, important attributes are listed with their
 names shown in <b>bold</b> in the description column.
*/
class Rock : public Texture3d
{
public:
public:
	Rock(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "rock"){}
	virtual ~Rock(){}
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
	<b>Color1</b> is one of the two colors blended together
	to make the Rock texture.
	*/
	void setColor1(const float3& c1){if(c1 == float3(0.235, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".c1\" -type \"float3\" ");c1.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color1</b> is one of the two colors blended together
	to make the Rock texture.
	*/
	void setColor1(const Float3ID& c1){fprintf_s(mFile,"connectAttr \"");c1.write(mFile);fprintf_s(mFile,"\" \"%s.c1\";\n",mName.c_str());}
	/*Color1 red value*/
	void setColor1R(float c1r){if(c1r == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1r\" %f;\n", c1r);}
	/*Color1 red value*/
	void setColor1R(const FloatID& c1r){fprintf_s(mFile,"connectAttr \"");c1r.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1r\";\n",mName.c_str());}
	/*Color1 green value*/
	void setColor1G(float c1g){if(c1g == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1g\" %f;\n", c1g);}
	/*Color1 green value*/
	void setColor1G(const FloatID& c1g){fprintf_s(mFile,"connectAttr \"");c1g.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1g\";\n",mName.c_str());}
	/*Color1 blue value*/
	void setColor1B(float c1b){if(c1b == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1b\" %f;\n", c1b);}
	/*Color1 blue value*/
	void setColor1B(const FloatID& c1b){fprintf_s(mFile,"connectAttr \"");c1b.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1b\";\n",mName.c_str());}
	/*
	<b>Color2</b> is one of the two colors blended together
	to make the Rock texture.
	*/
	void setColor2(const float3& c2){if(c2 == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".c2\" -type \"float3\" ");c2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color2</b> is one of the two colors blended together
	to make the Rock texture.
	*/
	void setColor2(const Float3ID& c2){fprintf_s(mFile,"connectAttr \"");c2.write(mFile);fprintf_s(mFile,"\" \"%s.c2\";\n",mName.c_str());}
	/*Color2 red value*/
	void setColor2R(float c2r){if(c2r == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2r\" %f;\n", c2r);}
	/*Color2 red value*/
	void setColor2R(const FloatID& c2r){fprintf_s(mFile,"connectAttr \"");c2r.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2r\";\n",mName.c_str());}
	/*Color2 green value*/
	void setColor2G(float c2g){if(c2g == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2g\" %f;\n", c2g);}
	/*Color2 green value*/
	void setColor2G(const FloatID& c2g){fprintf_s(mFile,"connectAttr \"");c2g.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2g\";\n",mName.c_str());}
	/*Color2 blue value*/
	void setColor2B(float c2b){if(c2b == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2b\" %f;\n", c2b);}
	/*Color2 blue value*/
	void setColor2B(const FloatID& c2b){fprintf_s(mFile,"connectAttr \"");c2b.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2b\";\n",mName.c_str());}
	/*
	<b>Grain</b> controls the size of the color speckles
	that are blended together to make the texture.  Small
	values make the texture look finely speckled, more
	granite-like.  Larger
	values make the texture look chunkier.
	*/
	void setGrainSize(float gs){if(gs == 0.01) return; fprintf_s(mFile, "setAttr \".gs\" %f;\n", gs);}
	/*
	<b>Grain</b> controls the size of the color speckles
	that are blended together to make the texture.  Small
	values make the texture look finely speckled, more
	granite-like.  Larger
	values make the texture look chunkier.
	*/
	void setGrainSize(const FloatID& gs){fprintf_s(mFile,"connectAttr \"");gs.write(mFile);fprintf_s(mFile,"\" \"%s.gs\";\n",mName.c_str());}
	/*
	<b>Diffusion</b> controls how much the two colors
	blend into each other at their boundaries.  Decrease
	Diffusion to make the two colors more separated from
	each other. Increase Diffusion to make the colors blend
	more.
	*/
	void setDiffusion(float di){if(di == 1.0) return; fprintf_s(mFile, "setAttr \".di\" %f;\n", di);}
	/*
	<b>Diffusion</b> controls how much the two colors
	blend into each other at their boundaries.  Decrease
	Diffusion to make the two colors more separated from
	each other. Increase Diffusion to make the colors blend
	more.
	*/
	void setDiffusion(const FloatID& di){fprintf_s(mFile,"connectAttr \"");di.write(mFile);fprintf_s(mFile,"\" \"%s.di\";\n",mName.c_str());}
	/*
	<b>Mix Ratio</b> controls the relative amounts of
	each color that are seen in the final texture.  Reduce
	Mix Ratio to see more of Color1, increase Mix Ratio
	to see more of Color2.
	*/
	void setMixRatio(float mr){if(mr == 0.5) return; fprintf_s(mFile, "setAttr \".mr\" %f;\n", mr);}
	/*
	<b>Mix Ratio</b> controls the relative amounts of
	each color that are seen in the final texture.  Reduce
	Mix Ratio to see more of Color1, increase Mix Ratio
	to see more of Color2.
	*/
	void setMixRatio(const FloatID& mr){fprintf_s(mFile,"connectAttr \"");mr.write(mFile);fprintf_s(mFile,"\" \"%s.mr\";\n",mName.c_str());}
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
	<b>Color1</b> is one of the two colors blended together
	to make the Rock texture.
	*/
	Float3ID getColor1(){char buffer[4096];sprintf_s (buffer, "%s.c1",mName.c_str());return (const char*)buffer;}
	/*Color1 red value*/
	FloatID getColor1R(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1r",mName.c_str());return (const char*)buffer;}
	/*Color1 green value*/
	FloatID getColor1G(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1g",mName.c_str());return (const char*)buffer;}
	/*Color1 blue value*/
	FloatID getColor1B(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color2</b> is one of the two colors blended together
	to make the Rock texture.
	*/
	Float3ID getColor2(){char buffer[4096];sprintf_s (buffer, "%s.c2",mName.c_str());return (const char*)buffer;}
	/*Color2 red value*/
	FloatID getColor2R(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2r",mName.c_str());return (const char*)buffer;}
	/*Color2 green value*/
	FloatID getColor2G(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2g",mName.c_str());return (const char*)buffer;}
	/*Color2 blue value*/
	FloatID getColor2B(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grain</b> controls the size of the color speckles
	that are blended together to make the texture.  Small
	values make the texture look finely speckled, more
	granite-like.  Larger
	values make the texture look chunkier.
	*/
	FloatID getGrainSize(){char buffer[4096];sprintf_s (buffer, "%s.gs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Diffusion</b> controls how much the two colors
	blend into each other at their boundaries.  Decrease
	Diffusion to make the two colors more separated from
	each other. Increase Diffusion to make the colors blend
	more.
	*/
	FloatID getDiffusion(){char buffer[4096];sprintf_s (buffer, "%s.di",mName.c_str());return (const char*)buffer;}
	/*
	<b>Mix Ratio</b> controls the relative amounts of
	each color that are seen in the final texture.  Reduce
	Mix Ratio to see more of Color1, increase Mix Ratio
	to see more of Color2.
	*/
	FloatID getMixRatio(){char buffer[4096];sprintf_s (buffer, "%s.mr",mName.c_str());return (const char*)buffer;}
protected:
	Rock(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ROCK_H__
