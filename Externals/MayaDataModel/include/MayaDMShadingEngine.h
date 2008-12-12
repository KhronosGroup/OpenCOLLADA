/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SHADINGENGINE_H__
#define __MayaDM_SHADINGENGINE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectSet.h"
namespace MayaDM
{
/*
The shading engine node (also known as the shading group node) is the
  node that associates shaders with geometry.  The shading group is a
  special type of object set that, in addition to containing geometry,
  defines a number of "shading ports" that control how the geometry in
  the set will be shaded.  Each port is the starting point of a
  shading network.

  The shading group has 3 shading ports:

  1) surface shading port - The shader that is connected to this port will
     control the appearance of the "surface geometry" contained in the
           shading group.  Maya currently has 4 surface geometry types:

                - NURBS surfaces
      - polygonal meshes
      - subdivision surfaces
      - particle systems using the "blobby" software render mode

     For each of these object types, the renderer will evaluate the
     "outColor" and "outTransparency" attributes of the shader attached
     to the surface shader port to determine the color and transparency
     of the objects, respectively.

  2) volume shading port - The shader that is connected to this port
     will control the appearance of the "volume geometry" contained
     in the shading group.  Maya currently has 3 volume geometry types:

                - light fogs
      - environment fog
      - particle systems using the "cloud" or "tube" software render modes

           The renderer will evaluate the "outColor" and "outTransparency"
     attributes of the shader attached to the volume shader port to
           compute the color and transparency of these volume objects.

  3) displacement shading port - The shader that is connected to this
     port will be invoked for the purpose of displacement-mapping all
     of the surface geometry in the shading group.  The renderer will
     evaluate the "displacement" attribute of the shader attached
     to the displacement shader port for this purpose.  The surface
     shader port will then be used to shade the displaced geometry.


  Following shading port is for mental ray for maya exclusively.


  1) material shading port

  2) shadow shading port

  3) volume shading port

  4) photon shading port

  5) photon volume shading port

  6) displacement shading port

  7) environment shading port

  8) light map shading port

  9) contour shading port


  It should be noted that the type of the actual shading port attributes
  is irrelevant, as they exist only to establish a connection between the
  shading group and the root node of a shading network.  Connecting *any*
  attribute of a shader to the shading port is sufficient to establish
  this connection.  For this reason, the port attributes are declared as
  type Tdata, meaning that any type of attribute can be connected to them.
*/
class ShadingEngine : public ObjectSet
{
public:
public:
	ShadingEngine(FILE* file,const std::string& name,const std::string& parent=""):ObjectSet(file, name, parent, "shadingEngine"){}
	virtual ~ShadingEngine(){}
	/*
	The surface shader port.  The node connected to this, the
	most commonly used port, will have its "outColor" and
	"outTransparency" attributes evaluated to sample the color
	and transparency of surface geometry in the shading group.
	Surface geometry types include NURBS surfaces, polygonal
	meshes, subdivision surfaces, and particles using the
	blobbly surface rendering mode.
	*/
	void setSurfaceShader(const GenerictypeddataID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*
	The displacement shader port.  The node that is connected
	to this port will have its "displacement" attribute evaluated
	to sample the displacement values for surface geometry in the
	shading group.
	*/
	void setDisplacementShader(const GenerictypeddataID& ds){fprintf_s(mFile,"connectAttr \"");ds.write(mFile);fprintf_s(mFile,"\" \"%s.ds\";\n",mName.c_str());}
	/*
	The volume shader port.  The node that is connected to
	this port will have its "outColor" and "outTransparency"
	attributes evaluated to sample the color and transparency
	of volume objects in the shading group.  Volume geometry
	types include light fogs, environment fog, and particles
	using the cloud or tube rendering modes.
	*/
	void setVolumeShader(const GenerictypeddataID& vs){fprintf_s(mFile,"connectAttr \"");vs.write(mFile);fprintf_s(mFile,"\" \"%s.vs\";\n",mName.c_str());}
	/*Currently unused port.*/
	void setImageShader(const GenerictypeddataID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*
	Controls usage of default mayabase material shaders, which are
	used by default. If enabled, the mayabase material shaders won't
	be applied at all but any custom mental ray node will.
	*/
	void setMiExportMrMaterial(bool mimt){if(mimt == false) return; fprintf_s(mFile, "setAttr \".mimt\" %i;\n", mimt);}
	/*
	Set the opaque material flag in mental ray for known non-transparent materials.
	If <b>miOpaque</b> is set, the material will not cast
	reflraction or transparency rays and its alpha will be always 1.
	This allows certain optimizations that improve rendering speed.
	*/
	void setMiOpaque(bool miop){if(miop == false) return; fprintf_s(mFile, "setAttr \".miop\" %i;\n", miop);}
	/*
	This is is an opacity threshold: all surface points that are less opaque than
	specified by this attribute will be considered non-existant. E.g. a value of 0.05
	removes all surface points with a transparency of 95% or more.
	*/
	void setMiCutAwayOpacity(float mico){if(mico == 0.0) return; fprintf_s(mFile, "setAttr \".mico\" %f;\n", mico);}
	/*
	Apply the mayabase shadingengine shader required for mayabase
	surface shaders also to custom mental ray surface nodes.
	*/
	void setMiExportShadingEngine(bool mise){if(mise == false) return; fprintf_s(mFile, "setAttr \".mise\" %i;\n", mise);}
	/*Port to connect custom mental ray node of type material shader.*/
	void setMiMaterialShader(const GenerictypeddataID& mims){fprintf_s(mFile,"connectAttr \"");mims.write(mFile);fprintf_s(mFile,"\" \"%s.mims\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type shadow shader.*/
	void setMiShadowShader(const GenerictypeddataID& miss){fprintf_s(mFile,"connectAttr \"");miss.write(mFile);fprintf_s(mFile,"\" \"%s.miss\";\n",mName.c_str());}
	/*
	Apply the mayabase volumesampler shader required for mayabase
	volume shaders also to custom mental ray volume nodes.
	*/
	void setMiExportVolumeSampler(bool mism){if(mism == false) return; fprintf_s(mFile, "setAttr \".mism\" %i;\n", mism);}
	/*Port to connect custom mental ray node of type volume shader.*/
	void setMiVolumeShader(const GenerictypeddataID& mivs){fprintf_s(mFile,"connectAttr \"");mivs.write(mFile);fprintf_s(mFile,"\" \"%s.mivs\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type photon shader.*/
	void setMiPhotonShader(const GenerictypeddataID& mips){fprintf_s(mFile,"connectAttr \"");mips.write(mFile);fprintf_s(mFile,"\" \"%s.mips\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type photon volume shader.*/
	void setMiPhotonVolumeShader(const GenerictypeddataID& mipv){fprintf_s(mFile,"connectAttr \"");mipv.write(mFile);fprintf_s(mFile,"\" \"%s.mipv\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type displacement shader.*/
	void setMiDisplacementShader(const GenerictypeddataID& mids){fprintf_s(mFile,"connectAttr \"");mids.write(mFile);fprintf_s(mFile,"\" \"%s.mids\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type environment shader.*/
	void setMiEnvironmentShader(const GenerictypeddataID& mies){fprintf_s(mFile,"connectAttr \"");mies.write(mFile);fprintf_s(mFile,"\" \"%s.mies\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type lightmap shader.*/
	void setMiLightMapShader(const GenerictypeddataID& milm){fprintf_s(mFile,"connectAttr \"");milm.write(mFile);fprintf_s(mFile,"\" \"%s.milm\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type contour shader.*/
	void setMiContourShader(const GenerictypeddataID& mics){fprintf_s(mFile,"connectAttr \"");mics.write(mFile);fprintf_s(mFile,"\" \"%s.mics\";\n",mName.c_str());}
	/*
	Enable contour detection and storage for contour output rendering.
	If <b>miContourEnable</b> is on, following contour settings will be used instead of <b>miContourShader</b>.
	<b>miContourEnable</b> enables contour shading for all objects associated with this shading engine.
	*/
	void setMiContourEnable(bool mice){if(mice == false) return; fprintf_s(mFile, "setAttr \".mice\" %i;\n", mice);}
	/*<b>miContourColor</b> specifies the color of the contour lines.*/
	void setMiContourColor(const float3& micc){fprintf_s(mFile, "setAttr \".micc\" -type \"float3\" ");micc.write(mFile);fprintf_s(mFile,";\n");}
	/*Red component of contour color.*/
	void setMiContourColorR(float micr){if(micr == 1.0) return; fprintf_s(mFile, "setAttr \".micc.micr\" %f;\n", micr);}
	/*Green component of contour color.*/
	void setMiContourColorG(float micg){if(micg == 1.0) return; fprintf_s(mFile, "setAttr \".micc.micg\" %f;\n", micg);}
	/*Blue component of contour color.*/
	void setMiContourColorB(float micb){if(micb == 1.0) return; fprintf_s(mFile, "setAttr \".micc.micb\" %f;\n", micb);}
	/*Alpha value of contour lines.*/
	void setMiContourAlpha(float mica){if(mica == 1.0) return; fprintf_s(mFile, "setAttr \".mica\" %f;\n", mica);}
	/*Width of the contour lines in pixel.*/
	void setMiContourWidth(float micw){if(micw == 1.25) return; fprintf_s(mFile, "setAttr \".micw\" %f;\n", micw);}
	/*
	If <b>miContourRelativeWidth</b>off,
	<b>miContourWidth</b> is specified as (fractional) number of pixels.
	If on, <b>miContourWidth</b> is specified in percents of
	the horiztonal image resolution
	thus maintaining the relative contour size if the resolution changes.
	*/
	void setMiContourRelativeWidth(bool mirw){if(mirw == false) return; fprintf_s(mFile, "setAttr \".mirw\" %i;\n", mirw);}
	/*
	The surface shader port.  The node connected to this, the
	most commonly used port, will have its "outColor" and
	"outTransparency" attributes evaluated to sample the color
	and transparency of surface geometry in the shading group.
	Surface geometry types include NURBS surfaces, polygonal
	meshes, subdivision surfaces, and particles using the
	blobbly surface rendering mode.
	*/
	GenerictypeddataID getSurfaceShader(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*
	The displacement shader port.  The node that is connected
	to this port will have its "displacement" attribute evaluated
	to sample the displacement values for surface geometry in the
	shading group.
	*/
	GenerictypeddataID getDisplacementShader(){char buffer[4096];sprintf_s (buffer, "%s.ds",mName.c_str());return (const char*)buffer;}
	/*
	The volume shader port.  The node that is connected to
	this port will have its "outColor" and "outTransparency"
	attributes evaluated to sample the color and transparency
	of volume objects in the shading group.  Volume geometry
	types include light fogs, environment fog, and particles
	using the cloud or tube rendering modes.
	*/
	GenerictypeddataID getVolumeShader(){char buffer[4096];sprintf_s (buffer, "%s.vs",mName.c_str());return (const char*)buffer;}
	/*Currently unused port.*/
	GenerictypeddataID getImageShader(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type material shader.*/
	GenerictypeddataID getMiMaterialShader(){char buffer[4096];sprintf_s (buffer, "%s.mims",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type shadow shader.*/
	GenerictypeddataID getMiShadowShader(){char buffer[4096];sprintf_s (buffer, "%s.miss",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type volume shader.*/
	GenerictypeddataID getMiVolumeShader(){char buffer[4096];sprintf_s (buffer, "%s.mivs",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type photon shader.*/
	GenerictypeddataID getMiPhotonShader(){char buffer[4096];sprintf_s (buffer, "%s.mips",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type photon volume shader.*/
	GenerictypeddataID getMiPhotonVolumeShader(){char buffer[4096];sprintf_s (buffer, "%s.mipv",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type displacement shader.*/
	GenerictypeddataID getMiDisplacementShader(){char buffer[4096];sprintf_s (buffer, "%s.mids",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type environment shader.*/
	GenerictypeddataID getMiEnvironmentShader(){char buffer[4096];sprintf_s (buffer, "%s.mies",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type lightmap shader.*/
	GenerictypeddataID getMiLightMapShader(){char buffer[4096];sprintf_s (buffer, "%s.milm",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type contour shader.*/
	GenerictypeddataID getMiContourShader(){char buffer[4096];sprintf_s (buffer, "%s.mics",mName.c_str());return (const char*)buffer;}
protected:
	ShadingEngine(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectSet(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SHADINGENGINE_H__
