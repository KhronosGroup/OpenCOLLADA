/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVCUBE_H__
#define __MayaDM_ENVCUBE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTextureEnv.h"
namespace MayaDM
{
/*
The <b>EnvCube</b> texture creates a cubic texture map for use as
 an environment map.  The effect is like placing a reflective object
 inside a cube with an image on each face.  The object will reflect
 those images.  You can select what images or textures are mapped
 onto each face of the Env Cube.
 <p/>
 To use this texture as an environment map, connect its Out Color
 attribute to the Reflected Color attribute of any specular shader,
 such as Blinn or Phong..
 <p/>
 Aside from the attributes listed here, EnvCube inherits additional
 attributes from <a href="textureEnv.html">TextureEnv</a>.
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class EnvCube : public TextureEnv
{
public:
public:
	EnvCube(FILE* file,const std::string& name,const std::string& parent=""):TextureEnv(file, name, parent, "envCube"){}
	virtual ~EnvCube(){}
	/*The input point*/
	void setPointWorld(const float3& pw){fprintf_s(mFile, "setAttr \".pw\" -type \"float3\" ");pw.write(mFile);fprintf_s(mFile,";\n");}
	/*The input point*/
	void setPointWorld(const Float3ID& pw){fprintf_s(mFile,"connectAttr \"");pw.write(mFile);fprintf_s(mFile,"\" \"%s.pw\";\n",mName.c_str());}
	/*The X component of the input point*/
	void setPointWorldX(float pwx){if(pwx == 0.0) return; fprintf_s(mFile, "setAttr \".pw.pwx\" %f;\n", pwx);}
	/*The X component of the input point*/
	void setPointWorldX(const FloatID& pwx){fprintf_s(mFile,"connectAttr \"");pwx.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwx\";\n",mName.c_str());}
	/*The Y component of the input point*/
	void setPointWorldY(float pwy){if(pwy == 0.0) return; fprintf_s(mFile, "setAttr \".pw.pwy\" %f;\n", pwy);}
	/*The Y component of the input point*/
	void setPointWorldY(const FloatID& pwy){fprintf_s(mFile,"connectAttr \"");pwy.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwy\";\n",mName.c_str());}
	/*The Z component of the input point*/
	void setPointWorldZ(float pwz){if(pwz == 0.0) return; fprintf_s(mFile, "setAttr \".pw.pwz\" %f;\n", pwz);}
	/*The Z component of the input point*/
	void setPointWorldZ(const FloatID& pwz){fprintf_s(mFile,"connectAttr \"");pwz.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwz\";\n",mName.c_str());}
	/*
	<b>Infinite Size</b>.  If this is turned on, then the images in the cube will be
	reflected as though the sides of the cube were infinitely far away. If you
	are using images of distant things, such as the horizon or a starfield, turn
	on Infinite Size.  If the images are of the interior of a room, or nearby
	objects, leave Infinite Size off.
	*/
	void setInfiniteSize(bool ie){if(ie == 0) return; fprintf_s(mFile, "setAttr \".ie\" %i;\n", ie);}
	/*
	Determines how the texture should be looked up in the cube map and is currently only
	support by the hardware renderer. The default is the reflection vector look up.
	Normal uses the normal vector versus the reflection vector.
	*/
	void setLookupType(unsigned int lt){if(lt == 0) return; fprintf_s(mFile, "setAttr \".lt\" %i;\n", lt);}
	/*
	<b>Left</b> is the image that is mapped onto the
	left side of the EnvCube.
	*/
	void setLeft(const float3& le){if(le == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".le\" -type \"float3\" ");le.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Left</b> is the image that is mapped onto the
	left side of the EnvCube.
	*/
	void setLeft(const Float3ID& le){fprintf_s(mFile,"connectAttr \"");le.write(mFile);fprintf_s(mFile,"\" \"%s.le\";\n",mName.c_str());}
	/*The red component of Left*/
	void setLeftR(float ler){if(ler == 0.0) return; fprintf_s(mFile, "setAttr \".le.ler\" %f;\n", ler);}
	/*The red component of Left*/
	void setLeftR(const FloatID& ler){fprintf_s(mFile,"connectAttr \"");ler.write(mFile);fprintf_s(mFile,"\" \"%s.le.ler\";\n",mName.c_str());}
	/*The green component of Left*/
	void setLeftG(float leg){if(leg == 0.0) return; fprintf_s(mFile, "setAttr \".le.leg\" %f;\n", leg);}
	/*The green component of Left*/
	void setLeftG(const FloatID& leg){fprintf_s(mFile,"connectAttr \"");leg.write(mFile);fprintf_s(mFile,"\" \"%s.le.leg\";\n",mName.c_str());}
	/*The blue component of Left*/
	void setLeftB(float leb){if(leb == 0.0) return; fprintf_s(mFile, "setAttr \".le.leb\" %f;\n", leb);}
	/*The blue component of Left*/
	void setLeftB(const FloatID& leb){fprintf_s(mFile,"connectAttr \"");leb.write(mFile);fprintf_s(mFile,"\" \"%s.le.leb\";\n",mName.c_str());}
	/*
	<b>Right</b> is the image that is mapped onto the
	right side of the EnvCube.
	*/
	void setRight(const float3& ri){if(ri == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ri\" -type \"float3\" ");ri.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Right</b> is the image that is mapped onto the
	right side of the EnvCube.
	*/
	void setRight(const Float3ID& ri){fprintf_s(mFile,"connectAttr \"");ri.write(mFile);fprintf_s(mFile,"\" \"%s.ri\";\n",mName.c_str());}
	/*The red component of Right*/
	void setRightR(float rir){if(rir == 0.0) return; fprintf_s(mFile, "setAttr \".ri.rir\" %f;\n", rir);}
	/*The red component of Right*/
	void setRightR(const FloatID& rir){fprintf_s(mFile,"connectAttr \"");rir.write(mFile);fprintf_s(mFile,"\" \"%s.ri.rir\";\n",mName.c_str());}
	/*The green component of Right*/
	void setRightG(float rig){if(rig == 0.0) return; fprintf_s(mFile, "setAttr \".ri.rig\" %f;\n", rig);}
	/*The green component of Right*/
	void setRightG(const FloatID& rig){fprintf_s(mFile,"connectAttr \"");rig.write(mFile);fprintf_s(mFile,"\" \"%s.ri.rig\";\n",mName.c_str());}
	/*The blue component of Right*/
	void setRightB(float rib){if(rib == 0.0) return; fprintf_s(mFile, "setAttr \".ri.rib\" %f;\n", rib);}
	/*The blue component of Right*/
	void setRightB(const FloatID& rib){fprintf_s(mFile,"connectAttr \"");rib.write(mFile);fprintf_s(mFile,"\" \"%s.ri.rib\";\n",mName.c_str());}
	/*
	<b>Top</b> is the image that is mapped onto the
	top side of the EnvCube.
	*/
	void setTop(const float3& to){if(to == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".to\" -type \"float3\" ");to.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Top</b> is the image that is mapped onto the
	top side of the EnvCube.
	*/
	void setTop(const Float3ID& to){fprintf_s(mFile,"connectAttr \"");to.write(mFile);fprintf_s(mFile,"\" \"%s.to\";\n",mName.c_str());}
	/*The red component of Top*/
	void setTopR(float tor){if(tor == 0.0) return; fprintf_s(mFile, "setAttr \".to.tor\" %f;\n", tor);}
	/*The red component of Top*/
	void setTopR(const FloatID& tor){fprintf_s(mFile,"connectAttr \"");tor.write(mFile);fprintf_s(mFile,"\" \"%s.to.tor\";\n",mName.c_str());}
	/*The green component of Top*/
	void setTopG(float tog){if(tog == 0.0) return; fprintf_s(mFile, "setAttr \".to.tog\" %f;\n", tog);}
	/*The green component of Top*/
	void setTopG(const FloatID& tog){fprintf_s(mFile,"connectAttr \"");tog.write(mFile);fprintf_s(mFile,"\" \"%s.to.tog\";\n",mName.c_str());}
	/*The blue component of Top*/
	void setTopB(float tob){if(tob == 0.0) return; fprintf_s(mFile, "setAttr \".to.tob\" %f;\n", tob);}
	/*The blue component of Top*/
	void setTopB(const FloatID& tob){fprintf_s(mFile,"connectAttr \"");tob.write(mFile);fprintf_s(mFile,"\" \"%s.to.tob\";\n",mName.c_str());}
	/*
	<b>Bottom</b> is the image that is mapped onto the
	bottom side of the EnvCube.
	*/
	void setBottom(const float3& bo){if(bo == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".bo\" -type \"float3\" ");bo.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Bottom</b> is the image that is mapped onto the
	bottom side of the EnvCube.
	*/
	void setBottom(const Float3ID& bo){fprintf_s(mFile,"connectAttr \"");bo.write(mFile);fprintf_s(mFile,"\" \"%s.bo\";\n",mName.c_str());}
	/*The red component of Bottom*/
	void setBottomR(float bor){if(bor == 0.0) return; fprintf_s(mFile, "setAttr \".bo.bor\" %f;\n", bor);}
	/*The red component of Bottom*/
	void setBottomR(const FloatID& bor){fprintf_s(mFile,"connectAttr \"");bor.write(mFile);fprintf_s(mFile,"\" \"%s.bo.bor\";\n",mName.c_str());}
	/*The green component of Bottom*/
	void setBottomG(float bog){if(bog == 0.0) return; fprintf_s(mFile, "setAttr \".bo.bog\" %f;\n", bog);}
	/*The green component of Bottom*/
	void setBottomG(const FloatID& bog){fprintf_s(mFile,"connectAttr \"");bog.write(mFile);fprintf_s(mFile,"\" \"%s.bo.bog\";\n",mName.c_str());}
	/*The blue component of Bottom*/
	void setBottomB(float bob){if(bob == 0.0) return; fprintf_s(mFile, "setAttr \".bo.bob\" %f;\n", bob);}
	/*The blue component of Bottom*/
	void setBottomB(const FloatID& bob){fprintf_s(mFile,"connectAttr \"");bob.write(mFile);fprintf_s(mFile,"\" \"%s.bo.bob\";\n",mName.c_str());}
	/*
	<b>Front</b> is the image that is mapped onto the
	front side of the EnvCube.
	*/
	void setFront(const float3& fr){if(fr == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".fr\" -type \"float3\" ");fr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Front</b> is the image that is mapped onto the
	front side of the EnvCube.
	*/
	void setFront(const Float3ID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*The red component of Front*/
	void setFrontR(float frr){if(frr == 0.0) return; fprintf_s(mFile, "setAttr \".fr.frr\" %f;\n", frr);}
	/*The red component of Front*/
	void setFrontR(const FloatID& frr){fprintf_s(mFile,"connectAttr \"");frr.write(mFile);fprintf_s(mFile,"\" \"%s.fr.frr\";\n",mName.c_str());}
	/*The green component of Front*/
	void setFrontG(float frg){if(frg == 0.0) return; fprintf_s(mFile, "setAttr \".fr.frg\" %f;\n", frg);}
	/*The green component of Front*/
	void setFrontG(const FloatID& frg){fprintf_s(mFile,"connectAttr \"");frg.write(mFile);fprintf_s(mFile,"\" \"%s.fr.frg\";\n",mName.c_str());}
	/*The blue component of Front*/
	void setFrontB(float frb){if(frb == 0.0) return; fprintf_s(mFile, "setAttr \".fr.frb\" %f;\n", frb);}
	/*The blue component of Front*/
	void setFrontB(const FloatID& frb){fprintf_s(mFile,"connectAttr \"");frb.write(mFile);fprintf_s(mFile,"\" \"%s.fr.frb\";\n",mName.c_str());}
	/*
	<b>Back</b> is the image that is mapped onto the
	back side of the EnvCube.
	*/
	void setBack(const float3& ba){if(ba == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ba\" -type \"float3\" ");ba.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Back</b> is the image that is mapped onto the
	back side of the EnvCube.
	*/
	void setBack(const Float3ID& ba){fprintf_s(mFile,"connectAttr \"");ba.write(mFile);fprintf_s(mFile,"\" \"%s.ba\";\n",mName.c_str());}
	/*The red component of Back*/
	void setBackR(float bar){if(bar == 0.0) return; fprintf_s(mFile, "setAttr \".ba.bar\" %f;\n", bar);}
	/*The red component of Back*/
	void setBackR(const FloatID& bar){fprintf_s(mFile,"connectAttr \"");bar.write(mFile);fprintf_s(mFile,"\" \"%s.ba.bar\";\n",mName.c_str());}
	/*The green component of Back*/
	void setBackG(float bag){if(bag == 0.0) return; fprintf_s(mFile, "setAttr \".ba.bag\" %f;\n", bag);}
	/*The green component of Back*/
	void setBackG(const FloatID& bag){fprintf_s(mFile,"connectAttr \"");bag.write(mFile);fprintf_s(mFile,"\" \"%s.ba.bag\";\n",mName.c_str());}
	/*The blue component of Back*/
	void setBackB(float bab){if(bab == 0.0) return; fprintf_s(mFile, "setAttr \".ba.bab\" %f;\n", bab);}
	/*The blue component of Back*/
	void setBackB(const FloatID& bab){fprintf_s(mFile,"connectAttr \"");bab.write(mFile);fprintf_s(mFile,"\" \"%s.ba.bab\";\n",mName.c_str());}
	/*Information bits passing along information about type of shading*/
	void setInfoBits(const IntID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
	/*The input point*/
	Float3ID getPointWorld(){char buffer[4096];sprintf_s (buffer, "%s.pw",mName.c_str());return (const char*)buffer;}
	/*The X component of the input point*/
	FloatID getPointWorldX(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the input point*/
	FloatID getPointWorldY(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the input point*/
	FloatID getPointWorldZ(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Left</b> is the image that is mapped onto the
	left side of the EnvCube.
	*/
	Float3ID getLeft(){char buffer[4096];sprintf_s (buffer, "%s.le",mName.c_str());return (const char*)buffer;}
	/*The red component of Left*/
	FloatID getLeftR(){char buffer[4096];sprintf_s (buffer, "%s.le.ler",mName.c_str());return (const char*)buffer;}
	/*The green component of Left*/
	FloatID getLeftG(){char buffer[4096];sprintf_s (buffer, "%s.le.leg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Left*/
	FloatID getLeftB(){char buffer[4096];sprintf_s (buffer, "%s.le.leb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Right</b> is the image that is mapped onto the
	right side of the EnvCube.
	*/
	Float3ID getRight(){char buffer[4096];sprintf_s (buffer, "%s.ri",mName.c_str());return (const char*)buffer;}
	/*The red component of Right*/
	FloatID getRightR(){char buffer[4096];sprintf_s (buffer, "%s.ri.rir",mName.c_str());return (const char*)buffer;}
	/*The green component of Right*/
	FloatID getRightG(){char buffer[4096];sprintf_s (buffer, "%s.ri.rig",mName.c_str());return (const char*)buffer;}
	/*The blue component of Right*/
	FloatID getRightB(){char buffer[4096];sprintf_s (buffer, "%s.ri.rib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Top</b> is the image that is mapped onto the
	top side of the EnvCube.
	*/
	Float3ID getTop(){char buffer[4096];sprintf_s (buffer, "%s.to",mName.c_str());return (const char*)buffer;}
	/*The red component of Top*/
	FloatID getTopR(){char buffer[4096];sprintf_s (buffer, "%s.to.tor",mName.c_str());return (const char*)buffer;}
	/*The green component of Top*/
	FloatID getTopG(){char buffer[4096];sprintf_s (buffer, "%s.to.tog",mName.c_str());return (const char*)buffer;}
	/*The blue component of Top*/
	FloatID getTopB(){char buffer[4096];sprintf_s (buffer, "%s.to.tob",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bottom</b> is the image that is mapped onto the
	bottom side of the EnvCube.
	*/
	Float3ID getBottom(){char buffer[4096];sprintf_s (buffer, "%s.bo",mName.c_str());return (const char*)buffer;}
	/*The red component of Bottom*/
	FloatID getBottomR(){char buffer[4096];sprintf_s (buffer, "%s.bo.bor",mName.c_str());return (const char*)buffer;}
	/*The green component of Bottom*/
	FloatID getBottomG(){char buffer[4096];sprintf_s (buffer, "%s.bo.bog",mName.c_str());return (const char*)buffer;}
	/*The blue component of Bottom*/
	FloatID getBottomB(){char buffer[4096];sprintf_s (buffer, "%s.bo.bob",mName.c_str());return (const char*)buffer;}
	/*
	<b>Front</b> is the image that is mapped onto the
	front side of the EnvCube.
	*/
	Float3ID getFront(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*The red component of Front*/
	FloatID getFrontR(){char buffer[4096];sprintf_s (buffer, "%s.fr.frr",mName.c_str());return (const char*)buffer;}
	/*The green component of Front*/
	FloatID getFrontG(){char buffer[4096];sprintf_s (buffer, "%s.fr.frg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Front*/
	FloatID getFrontB(){char buffer[4096];sprintf_s (buffer, "%s.fr.frb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Back</b> is the image that is mapped onto the
	back side of the EnvCube.
	*/
	Float3ID getBack(){char buffer[4096];sprintf_s (buffer, "%s.ba",mName.c_str());return (const char*)buffer;}
	/*The red component of Back*/
	FloatID getBackR(){char buffer[4096];sprintf_s (buffer, "%s.ba.bar",mName.c_str());return (const char*)buffer;}
	/*The green component of Back*/
	FloatID getBackG(){char buffer[4096];sprintf_s (buffer, "%s.ba.bag",mName.c_str());return (const char*)buffer;}
	/*The blue component of Back*/
	FloatID getBackB(){char buffer[4096];sprintf_s (buffer, "%s.ba.bab",mName.c_str());return (const char*)buffer;}
	/*Information bits passing along information about type of shading*/
	IntID getInfoBits(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
protected:
	EnvCube(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):TextureEnv(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ENVCUBE_H__
