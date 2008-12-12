/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HWREFLECTIONMAP_H__
#define __MayaDM_HWREFLECTIONMAP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>

 This is the dependency node for doing the hardware environment mapping.
 Currently, there are 2 different mapping available: the openGL
 sphereMap and cubeMap. When the attribute cubeMap is true, the environment
 mapping will be cubeMap, otherwise sphereMap.
 The textureFileName attribute provide the name of the file texture(s).
 Cube mapping needs 6 textures, therefore the filename will be expanded
 internally to 6 different names. E.g. when the filename is fname.ext,
 internally will be expanded to: fname.top.ext, fname.bottom.ext,
 fname.front.ext, fname back,ext, fname.left.ext, and fname.right.ext

</pre></p>
*/
class HwReflectionMap : public DependNode
{
public:
public:
	HwReflectionMap(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hwReflectionMap"){}
	virtual ~HwReflectionMap(){}
	/*Replace the surface color by the reflection color*/
	void setDecalMode(bool dm){if(dm == true) return; fprintf_s(mFile, "setAttr \".dm\" %i;\n", dm);}
	/*Replace the surface color by the reflection color*/
	void setDecalMode(const BoolID& dm){fprintf_s(mFile,"connectAttr \"");dm.write(mFile);fprintf_s(mFile,"\" \"%s.dm\";\n",mName.c_str());}
	/*Activate the cube mapping instead of the default sphereMapping*/
	void setCubeMap(bool cm){if(cm == false) return; fprintf_s(mFile, "setAttr \".cm\" %i;\n", cm);}
	/*Activate the cube mapping instead of the default sphereMapping*/
	void setCubeMap(const BoolID& cm){fprintf_s(mFile,"connectAttr \"");cm.write(mFile);fprintf_s(mFile,"\" \"%s.cm\";\n",mName.c_str());}
	/*Indicates the file texture name has changed*/
	void setTextureHasChanged(bool thc){if(thc == false) return; fprintf_s(mFile, "setAttr \".thc\" %i;\n", thc);}
	/*Indicates the file texture name has changed*/
	void setTextureHasChanged(const BoolID& thc){fprintf_s(mFile,"connectAttr \"");thc.write(mFile);fprintf_s(mFile,"\" \"%s.thc\";\n",mName.c_str());}
	/*The name of the file texture to use in the sphereMap mode.*/
	void setSphereMapTextureName(const string& smtn){if(smtn == "NULL") return; fprintf_s(mFile, "setAttr \".smtn\" -type \"string\" ");smtn.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the file texture to use in the sphereMap mode.*/
	void setSphereMapTextureName(const StringID& smtn){fprintf_s(mFile,"connectAttr \"");smtn.write(mFile);fprintf_s(mFile,"\" \"%s.smtn\";\n",mName.c_str());}
	/*The name of the file texture to apply on the front side of the cube.*/
	void setCubeFrontTextureName(const string& cftn){if(cftn == "NULL") return; fprintf_s(mFile, "setAttr \".cftn\" -type \"string\" ");cftn.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the file texture to apply on the front side of the cube.*/
	void setCubeFrontTextureName(const StringID& cftn){fprintf_s(mFile,"connectAttr \"");cftn.write(mFile);fprintf_s(mFile,"\" \"%s.cftn\";\n",mName.c_str());}
	/*The name of the file texture to apply on the back side of the cube.*/
	void setCubeBackTextureName(const string& cbkn){if(cbkn == "NULL") return; fprintf_s(mFile, "setAttr \".cbkn\" -type \"string\" ");cbkn.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the file texture to apply on the back side of the cube.*/
	void setCubeBackTextureName(const StringID& cbkn){fprintf_s(mFile,"connectAttr \"");cbkn.write(mFile);fprintf_s(mFile,"\" \"%s.cbkn\";\n",mName.c_str());}
	/*The name of the file texture to apply on the top side of the cube.*/
	void setCubeTopTextureName(const string& ctpn){if(ctpn == "NULL") return; fprintf_s(mFile, "setAttr \".ctpn\" -type \"string\" ");ctpn.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the file texture to apply on the top side of the cube.*/
	void setCubeTopTextureName(const StringID& ctpn){fprintf_s(mFile,"connectAttr \"");ctpn.write(mFile);fprintf_s(mFile,"\" \"%s.ctpn\";\n",mName.c_str());}
	/*The name of the file texture to apply on the bottom side of the cube.*/
	void setCubeBottomTextureName(const string& cbmn){if(cbmn == "NULL") return; fprintf_s(mFile, "setAttr \".cbmn\" -type \"string\" ");cbmn.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the file texture to apply on the bottom side of the cube.*/
	void setCubeBottomTextureName(const StringID& cbmn){fprintf_s(mFile,"connectAttr \"");cbmn.write(mFile);fprintf_s(mFile,"\" \"%s.cbmn\";\n",mName.c_str());}
	/*The name of the file texture to apply on the left side of the cube.*/
	void setCubeLeftTextureName(const string& cltn){if(cltn == "NULL") return; fprintf_s(mFile, "setAttr \".cltn\" -type \"string\" ");cltn.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the file texture to apply on the left side of the cube.*/
	void setCubeLeftTextureName(const StringID& cltn){fprintf_s(mFile,"connectAttr \"");cltn.write(mFile);fprintf_s(mFile,"\" \"%s.cltn\";\n",mName.c_str());}
	/*The name of the file texture to apply on the right side of the cube.*/
	void setCubeRightTextureName(const string& crtn){if(crtn == "NULL") return; fprintf_s(mFile, "setAttr \".crtn\" -type \"string\" ");crtn.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the file texture to apply on the right side of the cube.*/
	void setCubeRightTextureName(const StringID& crtn){fprintf_s(mFile,"connectAttr \"");crtn.write(mFile);fprintf_s(mFile,"\" \"%s.crtn\";\n",mName.c_str());}
	/*Replace the surface color by the reflection color*/
	BoolID getDecalMode(){char buffer[4096];sprintf_s (buffer, "%s.dm",mName.c_str());return (const char*)buffer;}
	/*Activate the cube mapping instead of the default sphereMapping*/
	BoolID getCubeMap(){char buffer[4096];sprintf_s (buffer, "%s.cm",mName.c_str());return (const char*)buffer;}
	/*Indicates the file texture name has changed*/
	BoolID getTextureHasChanged(){char buffer[4096];sprintf_s (buffer, "%s.thc",mName.c_str());return (const char*)buffer;}
	/*The name of the file texture to use in the sphereMap mode.*/
	StringID getSphereMapTextureName(){char buffer[4096];sprintf_s (buffer, "%s.smtn",mName.c_str());return (const char*)buffer;}
	/*The name of the file texture to apply on the front side of the cube.*/
	StringID getCubeFrontTextureName(){char buffer[4096];sprintf_s (buffer, "%s.cftn",mName.c_str());return (const char*)buffer;}
	/*The name of the file texture to apply on the back side of the cube.*/
	StringID getCubeBackTextureName(){char buffer[4096];sprintf_s (buffer, "%s.cbkn",mName.c_str());return (const char*)buffer;}
	/*The name of the file texture to apply on the top side of the cube.*/
	StringID getCubeTopTextureName(){char buffer[4096];sprintf_s (buffer, "%s.ctpn",mName.c_str());return (const char*)buffer;}
	/*The name of the file texture to apply on the bottom side of the cube.*/
	StringID getCubeBottomTextureName(){char buffer[4096];sprintf_s (buffer, "%s.cbmn",mName.c_str());return (const char*)buffer;}
	/*The name of the file texture to apply on the left side of the cube.*/
	StringID getCubeLeftTextureName(){char buffer[4096];sprintf_s (buffer, "%s.cltn",mName.c_str());return (const char*)buffer;}
	/*The name of the file texture to apply on the right side of the cube.*/
	StringID getCubeRightTextureName(){char buffer[4096];sprintf_s (buffer, "%s.crtn",mName.c_str());return (const char*)buffer;}
protected:
	HwReflectionMap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HWREFLECTIONMAP_H__
