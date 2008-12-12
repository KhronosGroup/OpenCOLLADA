/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VERTEXBAKESET_H__
#define __MayaDM_VERTEXBAKESET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBakeSet.h"
namespace MayaDM
{
/*
A vertexBakeSet allows the user to collect together objects which are
  to be baked in the same way, for instance with the same color blending,
  or clamping.  When Polygon Prelight is used, for each mesh being baked
  the vertexBakeSet to which that object belongs specifies the parameters
  for the baking process.
  <p/>
*/
class VertexBakeSet : public BakeSet
{
public:
public:
	VertexBakeSet(FILE* file,const std::string& name,const std::string& parent=""):BakeSet(file, name, parent, "vertexBakeSet"){}
	virtual ~VertexBakeSet(){}
	/*
	Obsolete.
	Use <b>Optimize Vertex Sharing</b> in the mental ray globals instead
	(mentalrayGlobals.exportSharedVertices).
	Use this option in order to bake just one result for each
	vertex in the mesh, rather than a one result for each vertex in
	each face in the mesh (each vertex is typically in a number of
	different faces).  Chosing shared vertices will tend to soften
	the shading of a mesh, sometimes dramatically.
	*/
	void setSharedVertices(const BoolID& shared){fprintf_s(mFile,"connectAttr \"");shared.write(mFile);fprintf_s(mFile,"\" \"%s.shared\";\n",mName.c_str());}
	/*
	Activate this option to bake rgb.
	If <b>Bake Color</b>is off, no color data will be written
	onto the mesh.  If the mesh has color data already, those values will
	remain untouched.  If the mesh hasn't any color, it will continue to
	be colorless.
	*/
	void setBakeColor(bool color){if(color == 1) return; fprintf_s(mFile, "setAttr \".color\" %i;\n", color);}
	/*
	Activate this option to bake rgb.
	If <b>Bake Color</b>is off, no color data will be written
	onto the mesh.  If the mesh has color data already, those values will
	remain untouched.  If the mesh hasn't any color, it will continue to
	be colorless.
	*/
	void setBakeColor(const BoolID& color){fprintf_s(mFile,"connectAttr \"");color.write(mFile);fprintf_s(mFile,"\" \"%s.color\";\n",mName.c_str());}
	/*
	How to merge existing vertex colors with the ones just baked, if any.
	For example, the color blend mode subtract will set
	(existing_color) - (baked_color) as the final vertex color.
	*/
	void setColorBlending(unsigned int cblend){if(cblend == 0) return; fprintf_s(mFile, "setAttr \".cblend\" %i;\n", cblend);}
	/*
	How to merge existing vertex colors with the ones just baked, if any.
	For example, the color blend mode subtract will set
	(existing_color) - (baked_color) as the final vertex color.
	*/
	void setColorBlending(const UnsignedintID& cblend){fprintf_s(mFile,"connectAttr \"");cblend.write(mFile);fprintf_s(mFile,"\" \"%s.cblend\";\n",mName.c_str());}
	/*How to merge existing vertex alphas with the ones just baked, if any.*/
	void setAlphaBlending(unsigned int ablend){if(ablend == 0) return; fprintf_s(mFile, "setAttr \".ablend\" %i;\n", ablend);}
	/*How to merge existing vertex alphas with the ones just baked, if any.*/
	void setAlphaBlending(const UnsignedintID& ablend){fprintf_s(mFile,"connectAttr \"");ablend.write(mFile);fprintf_s(mFile,"\" \"%s.ablend\";\n",mName.c_str());}
	/*Scale vertex colors by the specified value.*/
	void setScaleRgba(float scale){if(scale == 1.0) return; fprintf_s(mFile, "setAttr \".scale\" %f;\n", scale);}
	/*Scale vertex colors by the specified value.*/
	void setScaleRgba(const FloatID& scale){fprintf_s(mFile,"connectAttr \"");scale.write(mFile);fprintf_s(mFile,"\" \"%s.scale\";\n",mName.c_str());}
	/*Clamp vertex colors to this lower limit.*/
	void setClampMin(bool min){if(min == 0) return; fprintf_s(mFile, "setAttr \".min\" %i;\n", min);}
	/*Clamp vertex colors to this lower limit.*/
	void setClampMin(const BoolID& min){fprintf_s(mFile,"connectAttr \"");min.write(mFile);fprintf_s(mFile,"\" \"%s.min\";\n",mName.c_str());}
	/*The lower limit to clamp vertex colors to.*/
	void setMinColor(const float3& lc){fprintf_s(mFile, "setAttr \".lc\" -type \"float3\" ");lc.write(mFile);fprintf_s(mFile,";\n");}
	/*Minimum red.*/
	void setMinColorR(float lr){if(lr == 0.0) return; fprintf_s(mFile, "setAttr \".lc.lr\" %f;\n", lr);}
	/*Minimum red.*/
	void setMinColorR(const FloatID& lr){fprintf_s(mFile,"connectAttr \"");lr.write(mFile);fprintf_s(mFile,"\" \"%s.lc.lr\";\n",mName.c_str());}
	/*Minimum green.*/
	void setMinColorG(float lg){if(lg == 0.0) return; fprintf_s(mFile, "setAttr \".lc.lg\" %f;\n", lg);}
	/*Minimum green.*/
	void setMinColorG(const FloatID& lg){fprintf_s(mFile,"connectAttr \"");lg.write(mFile);fprintf_s(mFile,"\" \"%s.lc.lg\";\n",mName.c_str());}
	/*Minimum blue.*/
	void setMinColorB(float lb){if(lb == 0.0) return; fprintf_s(mFile, "setAttr \".lc.lb\" %f;\n", lb);}
	/*Minimum blue.*/
	void setMinColorB(const FloatID& lb){fprintf_s(mFile,"connectAttr \"");lb.write(mFile);fprintf_s(mFile,"\" \"%s.lc.lb\";\n",mName.c_str());}
	/*Minimum alpha*/
	void setMinAlpha(float mina){if(mina == 0) return; fprintf_s(mFile, "setAttr \".mina\" %f;\n", mina);}
	/*Minimum alpha*/
	void setMinAlpha(const FloatID& mina){fprintf_s(mFile,"connectAttr \"");mina.write(mFile);fprintf_s(mFile,"\" \"%s.mina\";\n",mName.c_str());}
	/*The lower limit to clamp vertex colors to.*/
	void setClampMax(bool max){if(max == 0) return; fprintf_s(mFile, "setAttr \".max\" %i;\n", max);}
	/*The lower limit to clamp vertex colors to.*/
	void setClampMax(const BoolID& max){fprintf_s(mFile,"connectAttr \"");max.write(mFile);fprintf_s(mFile,"\" \"%s.max\";\n",mName.c_str());}
	/*The upper limit to clamp vertex colors to.*/
	void setMaxColor(const float3& hc){fprintf_s(mFile, "setAttr \".hc\" -type \"float3\" ");hc.write(mFile);fprintf_s(mFile,";\n");}
	/*Maximum red.*/
	void setMaxColorR(float hr){if(hr == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hr\" %f;\n", hr);}
	/*Maximum red.*/
	void setMaxColorR(const FloatID& hr){fprintf_s(mFile,"connectAttr \"");hr.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hr\";\n",mName.c_str());}
	/*Maximum green.*/
	void setMaxColorG(float hg){if(hg == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hg\" %f;\n", hg);}
	/*Maximum green.*/
	void setMaxColorG(const FloatID& hg){fprintf_s(mFile,"connectAttr \"");hg.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hg\";\n",mName.c_str());}
	/*Maximum blue.*/
	void setMaxColorB(float hb){if(hb == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hb\" %f;\n", hb);}
	/*Maximum blue.*/
	void setMaxColorB(const FloatID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hb\";\n",mName.c_str());}
	/*Maximum alpha*/
	void setMaxAlpha(float maxa){if(maxa == 1) return; fprintf_s(mFile, "setAttr \".maxa\" %f;\n", maxa);}
	/*Maximum alpha*/
	void setMaxAlpha(const FloatID& maxa){fprintf_s(mFile,"connectAttr \"");maxa.write(mFile);fprintf_s(mFile,"\" \"%s.maxa\";\n",mName.c_str());}
	/*
	Use face normal or vertex normal.
	This does not affect the lighting computation,
	but is used when storing color per vertex.
	*/
	void setUseFaceNormals(bool ufn){if(ufn == 0) return; fprintf_s(mFile, "setAttr \".ufn\" %i;\n", ufn);}
	/*
	Use face normal or vertex normal.
	This does not affect the lighting computation,
	but is used when storing color per vertex.
	*/
	void setUseFaceNormals(const BoolID& ufn){fprintf_s(mFile,"connectAttr \"");ufn.write(mFile);fprintf_s(mFile,"\" \"%s.ufn\";\n",mName.c_str());}
	/*
	Name of the color set to store the baked vertex colors.
	If empty, current color set it used.
	If the given colorSetName does not exist on the mesh,
	a new color set will be created.
	*/
	void setColorSetName(const string& csn){if(csn == "NULL") return; fprintf_s(mFile, "setAttr \".csn\" -type \"string\" ");csn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Name of the color set to store the baked vertex colors.
	If empty, current color set it used.
	If the given colorSetName does not exist on the mesh,
	a new color set will be created.
	*/
	void setColorSetName(const StringID& csn){fprintf_s(mFile,"connectAttr \"");csn.write(mFile);fprintf_s(mFile,"\" \"%s.csn\";\n",mName.c_str());}
	/*
	Obsolete.
	Use <b>Optimize Vertex Sharing</b> in the mental ray globals instead
	(mentalrayGlobals.exportSharedVertices).
	Use this option in order to bake just one result for each
	vertex in the mesh, rather than a one result for each vertex in
	each face in the mesh (each vertex is typically in a number of
	different faces).  Chosing shared vertices will tend to soften
	the shading of a mesh, sometimes dramatically.
	*/
	BoolID getSharedVertices(){char buffer[4096];sprintf_s (buffer, "%s.shared",mName.c_str());return (const char*)buffer;}
	/*
	Activate this option to bake rgb.
	If <b>Bake Color</b>is off, no color data will be written
	onto the mesh.  If the mesh has color data already, those values will
	remain untouched.  If the mesh hasn't any color, it will continue to
	be colorless.
	*/
	BoolID getBakeColor(){char buffer[4096];sprintf_s (buffer, "%s.color",mName.c_str());return (const char*)buffer;}
	/*
	How to merge existing vertex colors with the ones just baked, if any.
	For example, the color blend mode subtract will set
	(existing_color) - (baked_color) as the final vertex color.
	*/
	UnsignedintID getColorBlending(){char buffer[4096];sprintf_s (buffer, "%s.cblend",mName.c_str());return (const char*)buffer;}
	/*How to merge existing vertex alphas with the ones just baked, if any.*/
	UnsignedintID getAlphaBlending(){char buffer[4096];sprintf_s (buffer, "%s.ablend",mName.c_str());return (const char*)buffer;}
	/*Scale vertex colors by the specified value.*/
	FloatID getScaleRgba(){char buffer[4096];sprintf_s (buffer, "%s.scale",mName.c_str());return (const char*)buffer;}
	/*Clamp vertex colors to this lower limit.*/
	BoolID getClampMin(){char buffer[4096];sprintf_s (buffer, "%s.min",mName.c_str());return (const char*)buffer;}
	/*Minimum red.*/
	FloatID getMinColorR(){char buffer[4096];sprintf_s (buffer, "%s.lc.lr",mName.c_str());return (const char*)buffer;}
	/*Minimum green.*/
	FloatID getMinColorG(){char buffer[4096];sprintf_s (buffer, "%s.lc.lg",mName.c_str());return (const char*)buffer;}
	/*Minimum blue.*/
	FloatID getMinColorB(){char buffer[4096];sprintf_s (buffer, "%s.lc.lb",mName.c_str());return (const char*)buffer;}
	/*Minimum alpha*/
	FloatID getMinAlpha(){char buffer[4096];sprintf_s (buffer, "%s.mina",mName.c_str());return (const char*)buffer;}
	/*The lower limit to clamp vertex colors to.*/
	BoolID getClampMax(){char buffer[4096];sprintf_s (buffer, "%s.max",mName.c_str());return (const char*)buffer;}
	/*Maximum red.*/
	FloatID getMaxColorR(){char buffer[4096];sprintf_s (buffer, "%s.hc.hr",mName.c_str());return (const char*)buffer;}
	/*Maximum green.*/
	FloatID getMaxColorG(){char buffer[4096];sprintf_s (buffer, "%s.hc.hg",mName.c_str());return (const char*)buffer;}
	/*Maximum blue.*/
	FloatID getMaxColorB(){char buffer[4096];sprintf_s (buffer, "%s.hc.hb",mName.c_str());return (const char*)buffer;}
	/*Maximum alpha*/
	FloatID getMaxAlpha(){char buffer[4096];sprintf_s (buffer, "%s.maxa",mName.c_str());return (const char*)buffer;}
	/*
	Use face normal or vertex normal.
	This does not affect the lighting computation,
	but is used when storing color per vertex.
	*/
	BoolID getUseFaceNormals(){char buffer[4096];sprintf_s (buffer, "%s.ufn",mName.c_str());return (const char*)buffer;}
	/*
	Name of the color set to store the baked vertex colors.
	If empty, current color set it used.
	If the given colorSetName does not exist on the mesh,
	a new color set will be created.
	*/
	StringID getColorSetName(){char buffer[4096];sprintf_s (buffer, "%s.csn",mName.c_str());return (const char*)buffer;}
protected:
	VertexBakeSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BakeSet(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_VERTEXBAKESET_H__
