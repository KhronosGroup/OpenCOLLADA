/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STROKEGLOBALS_H__
#define __MayaDM_STROKEGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
*/
class StrokeGlobals : public DependNode
{
public:
public:
	StrokeGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "strokeGlobals"){}
	virtual ~StrokeGlobals(){}
	/*global scale on template brush is adjusted by this factor for 3D strokes*/
	void setSceneScale(double pss){if(pss == 5.0) return; fprintf_s(mFile, "setAttr \".pss\" %f;\n", pss);}
	/*global scale on template brush is adjusted by this factor for 3D strokes*/
	void setSceneScale(const DoubleID& pss){fprintf_s(mFile,"connectAttr \"");pss.write(mFile);fprintf_s(mFile,"\" \"%s.pss\";\n",mName.c_str());}
	/*global scale on template brush is adjusted by this factor for 2D strokes*/
	void setCanvasScale(double pcs){if(pcs == 1.0) return; fprintf_s(mFile, "setAttr \".pcs\" %f;\n", pcs);}
	/*global scale on template brush is adjusted by this factor for 2D strokes*/
	void setCanvasScale(const DoubleID& pcs){fprintf_s(mFile,"connectAttr \"");pcs.write(mFile);fprintf_s(mFile,"\" \"%s.pcs\";\n",mName.c_str());}
	/*wrap brushstrokes outside left and right image boundaries to opposite edge*/
	void setWrapH(bool wrh){if(wrh == false) return; fprintf_s(mFile, "setAttr \".wrh\" %i;\n", wrh);}
	/*wrap brushstrokes outside left and right image boundaries to opposite edge*/
	void setWrapH(const BoolID& wrh){fprintf_s(mFile,"connectAttr \"");wrh.write(mFile);fprintf_s(mFile,"\" \"%s.wrh\";\n",mName.c_str());}
	/*wrap brushstrokes outside top and bottom image boundaries to opposite edge*/
	void setWrapV(bool wrv){if(wrv == false) return; fprintf_s(mFile, "setAttr \".wrv\" %i;\n", wrv);}
	/*wrap brushstrokes outside top and bottom image boundaries to opposite edge*/
	void setWrapV(const BoolID& wrv){fprintf_s(mFile,"connectAttr \"");wrv.write(mFile);fprintf_s(mFile,"\" \"%s.wrv\";\n",mName.c_str());}
	/*in scene render wrap brushstrokes outside left and right image boundaries to opposite edge*/
	void setSceneWrapH(bool swh){if(swh == false) return; fprintf_s(mFile, "setAttr \".swh\" %i;\n", swh);}
	/*in scene render wrap brushstrokes outside left and right image boundaries to opposite edge*/
	void setSceneWrapH(const BoolID& swh){fprintf_s(mFile,"connectAttr \"");swh.write(mFile);fprintf_s(mFile,"\" \"%s.swh\";\n",mName.c_str());}
	/*in scene render wrap brushstrokes outside top and bottom image boundaries to opposite edge*/
	void setSceneWrapV(bool swv){if(swv == false) return; fprintf_s(mFile, "setAttr \".swv\" %i;\n", swv);}
	/*in scene render wrap brushstrokes outside top and bottom image boundaries to opposite edge*/
	void setSceneWrapV(const BoolID& swv){fprintf_s(mFile,"connectAttr \"");swv.write(mFile);fprintf_s(mFile,"\" \"%s.swv\";\n",mName.c_str());}
	/*force brushes created in scene mode to use real lights*/
	void setForceRealLights(bool frl){if(frl == true) return; fprintf_s(mFile, "setAttr \".frl\" %i;\n", frl);}
	/*force brushes created in scene mode to use real lights*/
	void setForceRealLights(const BoolID& frl){fprintf_s(mFile,"connectAttr \"");frl.write(mFile);fprintf_s(mFile,"\" \"%s.frl\";\n",mName.c_str());}
	/*force brushes created in scene mode to use depth*/
	void setForceDepth(bool fdp){if(fdp == true) return; fprintf_s(mFile, "setAttr \".fdp\" %i;\n", fdp);}
	/*force brushes created in scene mode to use depth*/
	void setForceDepth(const BoolID& fdp){fprintf_s(mFile,"connectAttr \"");fdp.write(mFile);fprintf_s(mFile,"\" \"%s.fdp\";\n",mName.c_str());}
	/*use a global canvas light for brushes instead of scene lights*/
	void setUseCanvasLight(bool ucl){if(ucl == true) return; fprintf_s(mFile, "setAttr \".ucl\" %i;\n", ucl);}
	/*use a global canvas light for brushes instead of scene lights*/
	void setUseCanvasLight(const BoolID& ucl){fprintf_s(mFile,"connectAttr \"");ucl.write(mFile);fprintf_s(mFile,"\" \"%s.ucl\";\n",mName.c_str());}
	/*Force stroke direction to be along path in Canvas mode*/
	void setForceTubeDirAlongPath(bool ftd){if(ftd == true) return; fprintf_s(mFile, "setAttr \".ftd\" %i;\n", ftd);}
	/*Force stroke direction to be along path in Canvas mode*/
	void setForceTubeDirAlongPath(const BoolID& ftd){fprintf_s(mFile,"connectAttr \"");ftd.write(mFile);fprintf_s(mFile,"\" \"%s.ftd\";\n",mName.c_str());}
	/*direction of simple directional lightsource for the canvas*/
	void setLightDirection(const double3& ldr){fprintf_s(mFile, "setAttr \".ldr\" -type \"double3\" ");ldr.write(mFile);fprintf_s(mFile,";\n");}
	/*direction of simple directional lightsource for the canvas*/
	void setLightDirection(const Double3ID& ldr){fprintf_s(mFile,"connectAttr \"");ldr.write(mFile);fprintf_s(mFile,"\" \"%s.ldr\";\n",mName.c_str());}
	/*X value for light direction*/
	void setLightDirectionX(double ldx){if(ldx == 0.2) return; fprintf_s(mFile, "setAttr \".ldr.ldx\" %f;\n", ldx);}
	/*X value for light direction*/
	void setLightDirectionX(const DoubleID& ldx){fprintf_s(mFile,"connectAttr \"");ldx.write(mFile);fprintf_s(mFile,"\" \"%s.ldr.ldx\";\n",mName.c_str());}
	/*Y value for light direction*/
	void setLightDirectionY(double ldy){if(ldy == -.9) return; fprintf_s(mFile, "setAttr \".ldr.ldy\" %f;\n", ldy);}
	/*Y value for light direction*/
	void setLightDirectionY(const DoubleID& ldy){fprintf_s(mFile,"connectAttr \"");ldy.write(mFile);fprintf_s(mFile,"\" \"%s.ldr.ldy\";\n",mName.c_str());}
	/*Z value for light direction*/
	void setLightDirectionZ(double ldz){if(ldz == -0.5) return; fprintf_s(mFile, "setAttr \".ldr.ldz\" %f;\n", ldz);}
	/*Z value for light direction*/
	void setLightDirectionZ(const DoubleID& ldz){fprintf_s(mFile,"connectAttr \"");ldz.write(mFile);fprintf_s(mFile,"\" \"%s.ldr.ldz\";\n",mName.c_str());}
	/*global scale on template brush is adjusted by this factor for 3D strokes*/
	DoubleID getSceneScale(){char buffer[4096];sprintf_s (buffer, "%s.pss",mName.c_str());return (const char*)buffer;}
	/*global scale on template brush is adjusted by this factor for 2D strokes*/
	DoubleID getCanvasScale(){char buffer[4096];sprintf_s (buffer, "%s.pcs",mName.c_str());return (const char*)buffer;}
	/*wrap brushstrokes outside left and right image boundaries to opposite edge*/
	BoolID getWrapH(){char buffer[4096];sprintf_s (buffer, "%s.wrh",mName.c_str());return (const char*)buffer;}
	/*wrap brushstrokes outside top and bottom image boundaries to opposite edge*/
	BoolID getWrapV(){char buffer[4096];sprintf_s (buffer, "%s.wrv",mName.c_str());return (const char*)buffer;}
	/*in scene render wrap brushstrokes outside left and right image boundaries to opposite edge*/
	BoolID getSceneWrapH(){char buffer[4096];sprintf_s (buffer, "%s.swh",mName.c_str());return (const char*)buffer;}
	/*in scene render wrap brushstrokes outside top and bottom image boundaries to opposite edge*/
	BoolID getSceneWrapV(){char buffer[4096];sprintf_s (buffer, "%s.swv",mName.c_str());return (const char*)buffer;}
	/*force brushes created in scene mode to use real lights*/
	BoolID getForceRealLights(){char buffer[4096];sprintf_s (buffer, "%s.frl",mName.c_str());return (const char*)buffer;}
	/*force brushes created in scene mode to use depth*/
	BoolID getForceDepth(){char buffer[4096];sprintf_s (buffer, "%s.fdp",mName.c_str());return (const char*)buffer;}
	/*use a global canvas light for brushes instead of scene lights*/
	BoolID getUseCanvasLight(){char buffer[4096];sprintf_s (buffer, "%s.ucl",mName.c_str());return (const char*)buffer;}
	/*Force stroke direction to be along path in Canvas mode*/
	BoolID getForceTubeDirAlongPath(){char buffer[4096];sprintf_s (buffer, "%s.ftd",mName.c_str());return (const char*)buffer;}
	/*direction of simple directional lightsource for the canvas*/
	Double3ID getLightDirection(){char buffer[4096];sprintf_s (buffer, "%s.ldr",mName.c_str());return (const char*)buffer;}
	/*X value for light direction*/
	DoubleID getLightDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.ldr.ldx",mName.c_str());return (const char*)buffer;}
	/*Y value for light direction*/
	DoubleID getLightDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.ldr.ldy",mName.c_str());return (const char*)buffer;}
	/*Z value for light direction*/
	DoubleID getLightDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.ldr.ldz",mName.c_str());return (const char*)buffer;}
protected:
	StrokeGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_STROKEGLOBALS_H__
