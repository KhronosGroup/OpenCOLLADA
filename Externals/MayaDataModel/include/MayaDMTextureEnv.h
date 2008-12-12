/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TEXTUREENV_H__
#define __MayaDM_TEXTUREENV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>TextureEnv</b> is the base node from which all the 3d environment
 texture nodes derive.  Here you will find all the attributes that
 are common to all 3d environment textures.
 <p/>
 Environment textures are used as a cheap way to simulate the reflections
 you can get using RayTracing.  Connect the Out Color attribute of the
 Environment texture to the Reflected Color attribute of any specular
 shader, such as Phong or Blinn.  The shader will then appear to
 reflect the environment texture.
 <p/>
 In the table below, important attributes have their names shown in
 <b>bold</b> in the description column.
*/
class TextureEnv : public DependNode
{
public:
public:
	TextureEnv(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "textureEnv"){}
	virtual ~TextureEnv(){}
	/*The type of object this samples belongs to.*/
	void setObjectType(char ot){if(ot == 1) return; fprintf_s(mFile, "setAttr \".ot\" %;\n", ot);}
	/*The type of object this samples belongs to.*/
	void setObjectType(const CharID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*The placement  matrix, to transform from world to the texture space*/
	void setPlacementMatrix(const FltMatrixID& pm){fprintf_s(mFile,"connectAttr \"");pm.write(mFile);fprintf_s(mFile,"\" \"%s.pm\";\n",mName.c_str());}
	/*The transform to go from eye to world space*/
	void setMatrixEyeToWorld(const FltMatrixID& e2w){fprintf_s(mFile,"connectAttr \"");e2w.write(mFile);fprintf_s(mFile,"\" \"%s.e2w\";\n",mName.c_str());}
	/*The pixel angle*/
	void setXPixelAngle(float xpa){if(xpa == 0.002053) return; fprintf_s(mFile, "setAttr \".xpa\" %f;\n", xpa);}
	/*The current sample normal*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The x component of the normal*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The y component of the normal*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The z component of the normal*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*The current incident ray*/
	void setRayDirection(const Float3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The x component of the ray*/
	void setRayDirectionX(const FloatID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*The y component of the ray*/
	void setRayDirectionY(const FloatID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*The z component of the ray*/
	void setRayDirectionZ(const FloatID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*The UV coords of the current sample point*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setUCoord(const FloatID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.uv.u\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setVCoord(const FloatID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.uv.v\";\n",mName.c_str());}
	/*The sample (filter) size*/
	void setUvFilterSize(const Float2ID& uf){fprintf_s(mFile,"connectAttr \"");uf.write(mFile);fprintf_s(mFile,"\" \"%s.uf\";\n",mName.c_str());}
	/*The X size of the filter (sample)*/
	void setUvFilterSizeX(const FloatID& ufx){fprintf_s(mFile,"connectAttr \"");ufx.write(mFile);fprintf_s(mFile,"\" \"%s.uf.ufx\";\n",mName.c_str());}
	/*The Y size of the filter (sample)*/
	void setUvFilterSizeY(const FloatID& ufy){fprintf_s(mFile,"connectAttr \"");ufy.write(mFile);fprintf_s(mFile,"\" \"%s.uf.ufy\";\n",mName.c_str());}
	/*The sample (filter) size*/
	void setFilterSize(const Float3ID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs\";\n",mName.c_str());}
	/*The X size of the filter (sample)*/
	void setFilterSizeX(const FloatID& fsx){fprintf_s(mFile,"connectAttr \"");fsx.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsx\";\n",mName.c_str());}
	/*The Y size of the filter (sample)*/
	void setFilterSizeY(const FloatID& fsy){fprintf_s(mFile,"connectAttr \"");fsy.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsy\";\n",mName.c_str());}
	/*The Z size of the filter (sample)*/
	void setFilterSizeZ(const FloatID& fsz){fprintf_s(mFile,"connectAttr \"");fsz.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsz\";\n",mName.c_str());}
	/*
	<b>Out Color</b>.  To use this node as an environment
	map, connect Out Color to the Reflected
	Color attribute of a specular shader, such as Blinn or
	PhongE.
	*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The R component of the output value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*The G component of the output value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*The B component of the output value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*The standard output value for bump and displacement mapping*/
	void setOutAlpha(const FloatID& oa){fprintf_s(mFile,"connectAttr \"");oa.write(mFile);fprintf_s(mFile,"\" \"%s.oa\";\n",mName.c_str());}
	/*The type of object this samples belongs to.*/
	CharID getObjectType(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*The placement  matrix, to transform from world to the texture space*/
	FltMatrixID getPlacementMatrix(){char buffer[4096];sprintf_s (buffer, "%s.pm",mName.c_str());return (const char*)buffer;}
	/*The transform to go from eye to world space*/
	FltMatrixID getMatrixEyeToWorld(){char buffer[4096];sprintf_s (buffer, "%s.e2w",mName.c_str());return (const char*)buffer;}
	/*The current sample normal*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The x component of the normal*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The y component of the normal*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The z component of the normal*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*The current incident ray*/
	Float3ID getRayDirection(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The x component of the ray*/
	FloatID getRayDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*The y component of the ray*/
	FloatID getRayDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*The z component of the ray*/
	FloatID getRayDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*The UV coords of the current sample point*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.u",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.v",mName.c_str());return (const char*)buffer;}
	/*The sample (filter) size*/
	Float2ID getUvFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.uf",mName.c_str());return (const char*)buffer;}
	/*The X size of the filter (sample)*/
	FloatID getUvFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.uf.ufx",mName.c_str());return (const char*)buffer;}
	/*The Y size of the filter (sample)*/
	FloatID getUvFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.uf.ufy",mName.c_str());return (const char*)buffer;}
	/*The sample (filter) size*/
	Float3ID getFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.fs",mName.c_str());return (const char*)buffer;}
	/*The X size of the filter (sample)*/
	FloatID getFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsx",mName.c_str());return (const char*)buffer;}
	/*The Y size of the filter (sample)*/
	FloatID getFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsy",mName.c_str());return (const char*)buffer;}
	/*The Z size of the filter (sample)*/
	FloatID getFilterSizeZ(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Color</b>.  To use this node as an environment
	map, connect Out Color to the Reflected
	Color attribute of a specular shader, such as Blinn or
	PhongE.
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*The R component of the output value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*The G component of the output value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*The B component of the output value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*The standard output value for bump and displacement mapping*/
	FloatID getOutAlpha(){char buffer[4096];sprintf_s (buffer, "%s.oa",mName.c_str());return (const char*)buffer;}
protected:
	TextureEnv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TEXTUREENV_H__
