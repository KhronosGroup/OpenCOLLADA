/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HEIGHTFIELD_H__
#define __MayaDM_HEIGHTFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSurfaceShape.h"
namespace MayaDM
{
/*
<p><pre>
        This node draws a plane that shows the displacement
        of a surface texture or an ocean shader.
        It is currently only for
        preview purposes, and does not
        appear in a render.

</pre></p>
*/
class HeightField : public SurfaceShape
{
public:
public:
	HeightField(FILE* file,const std::string& name,const std::string& parent=""):SurfaceShape(file, name, parent, "heightField"){}
	virtual ~HeightField(){}
	/*
	The number of samples relative to the largest side of the
	plane. For a square plane the ocean will be sampled at
	resolution * resolution points. Higher values result in a
	more detailed surface, but slower draw time.
	*/
	void setResolution(int res){if(res == 10) return; fprintf_s(mFile, "setAttr \".res\" %i;\n", res);}
	/*
	The number of samples relative to the largest side of the
	plane. For a square plane the ocean will be sampled at
	resolution * resolution points. Higher values result in a
	more detailed surface, but slower draw time.
	*/
	void setResolution(const IntID& res){fprintf_s(mFile,"connectAttr \"");res.write(mFile);fprintf_s(mFile,"\" \"%s.res\";\n",mName.c_str());}
	/*
	<b>Color</b> is the basic color of the preview surface.
	This may be mapped with a surface texture or an ocean
	shader. The mapping will always use the outColor from
	the connected node, regardless of the actual attribute connected.
	*/
	void setColor(const float3& cl){fprintf_s(mFile, "setAttr \".cl\" -type \"float3\" ");cl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color</b> is the basic color of the preview surface.
	This may be mapped with a surface texture or an ocean
	shader. The mapping will always use the outColor from
	the connected node, regardless of the actual attribute connected.
	*/
	void setColor(const Float3ID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl\";\n",mName.c_str());}
	/*color red value*/
	void setColorR(float cr){if(cr == 0.5) return; fprintf_s(mFile, "setAttr \".cl.cr\" %f;\n", cr);}
	/*color red value*/
	void setColorR(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cr\";\n",mName.c_str());}
	/*color green value*/
	void setColorG(float cg){if(cg == 0.5) return; fprintf_s(mFile, "setAttr \".cl.cg\" %f;\n", cg);}
	/*color green value*/
	void setColorG(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cg\";\n",mName.c_str());}
	/*color blue value*/
	void setColorB(float cb){if(cb == 0.5) return; fprintf_s(mFile, "setAttr \".cl.cb\" %f;\n", cb);}
	/*color blue value*/
	void setColorB(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cb\";\n",mName.c_str());}
	/*
	The height of the plane.
	This may be mapped with a surface texture or an ocean
	shader. The mapping will always use the outAlpha from
	the connected node, regardless of the actual attribute connected.
	This does a special fast evaluation of the texture that will
	ignores added shading engine inputs.
	*/
	void setDisplacement(float dis){if(dis == 0.0) return; fprintf_s(mFile, "setAttr \".dis\" %f;\n", dis);}
	/*
	The height of the plane.
	This may be mapped with a surface texture or an ocean
	shader. The mapping will always use the outAlpha from
	the connected node, regardless of the actual attribute connected.
	This does a special fast evaluation of the texture that will
	ignores added shading engine inputs.
	*/
	void setDisplacement(const FloatID& dis){fprintf_s(mFile,"connectAttr \"");dis.write(mFile);fprintf_s(mFile,"\" \"%s.dis\";\n",mName.c_str());}
	/*Scale factor for input displacement.*/
	void setHeightScale(float hc){if(hc == 1.0) return; fprintf_s(mFile, "setAttr \".hc\" %f;\n", hc);}
	/*Scale factor for input displacement.*/
	void setHeightScale(const FloatID& hc){fprintf_s(mFile,"connectAttr \"");hc.write(mFile);fprintf_s(mFile,"\" \"%s.hc\";\n",mName.c_str());}
	/*A convenience attribute that forces all the inputs to be updated*/
	void setCacheNeedsRebuilding(const BoolID& cnr){fprintf_s(mFile,"connectAttr \"");cnr.write(mFile);fprintf_s(mFile,"\" \"%s.cnr\";\n",mName.c_str());}
	/*
	The number of samples relative to the largest side of the
	plane. For a square plane the ocean will be sampled at
	resolution * resolution points. Higher values result in a
	more detailed surface, but slower draw time.
	*/
	IntID getResolution(){char buffer[4096];sprintf_s (buffer, "%s.res",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color</b> is the basic color of the preview surface.
	This may be mapped with a surface texture or an ocean
	shader. The mapping will always use the outColor from
	the connected node, regardless of the actual attribute connected.
	*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.cl",mName.c_str());return (const char*)buffer;}
	/*color red value*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.cl.cr",mName.c_str());return (const char*)buffer;}
	/*color green value*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.cl.cg",mName.c_str());return (const char*)buffer;}
	/*color blue value*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.cl.cb",mName.c_str());return (const char*)buffer;}
	/*
	The height of the plane.
	This may be mapped with a surface texture or an ocean
	shader. The mapping will always use the outAlpha from
	the connected node, regardless of the actual attribute connected.
	This does a special fast evaluation of the texture that will
	ignores added shading engine inputs.
	*/
	FloatID getDisplacement(){char buffer[4096];sprintf_s (buffer, "%s.dis",mName.c_str());return (const char*)buffer;}
	/*Scale factor for input displacement.*/
	FloatID getHeightScale(){char buffer[4096];sprintf_s (buffer, "%s.hc",mName.c_str());return (const char*)buffer;}
	/*A convenience attribute that forces all the inputs to be updated*/
	BoolID getCacheNeedsRebuilding(){char buffer[4096];sprintf_s (buffer, "%s.cnr",mName.c_str());return (const char*)buffer;}
protected:
	HeightField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SurfaceShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HEIGHTFIELD_H__
