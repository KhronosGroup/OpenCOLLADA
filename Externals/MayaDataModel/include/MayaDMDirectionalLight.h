/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DIRECTIONALLIGHT_H__
#define __MayaDM_DIRECTIONALLIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNonExtendedLightShapeNode.h"
namespace MayaDM
{
/*
<p><pre>
        This class contains the "shape" information for directional lights.

</pre></p>
*/
class DirectionalLight : public NonExtendedLightShapeNode
{
public:
	/*This is a root of following mental ray attributes.*/
	struct MentalRayControls{
		bool miExportMrLight;
		bool emitPhotons;
		float3 energy;
		float photonIntensity;
		float exponent;
		int causticPhotons;
		int globIllPhotons;
		bool shadowMap;
		int smapResolution;
		short smapSamples;
		float smapSoftness;
		float smapBias;
		string smapFilename;
		bool smapLightName;
		bool smapSceneName;
		bool smapFrameExt;
		bool smapDetail;
		short smapDetailSamples;
		float smapDetailAccuracy;
		bool smapDetailAlpha;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", miExportMrLight);
			fprintf_s(file,"%i ", emitPhotons);
			energy.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f ", photonIntensity);
			fprintf_s(file,"%f ", exponent);
			fprintf_s(file,"%i ", causticPhotons);
			fprintf_s(file,"%i ", globIllPhotons);
			fprintf_s(file,"%i ", shadowMap);
			fprintf_s(file,"%i ", smapResolution);
			fprintf_s(file,"%i ", smapSamples);
			fprintf_s(file,"%f ", smapSoftness);
			fprintf_s(file,"%f ", smapBias);
			smapFilename.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i ", smapLightName);
			fprintf_s(file,"%i ", smapSceneName);
			fprintf_s(file,"%i ", smapFrameExt);
			fprintf_s(file,"%i ", smapDetail);
			fprintf_s(file,"%i ", smapDetailSamples);
			fprintf_s(file,"%f ", smapDetailAccuracy);
			fprintf_s(file,"%i", smapDetailAlpha);
		}
	};
public:
	DirectionalLight(FILE* file,const std::string& name,const std::string& parent=""):NonExtendedLightShapeNode(file, name, parent, "directionalLight"){}
	virtual ~DirectionalLight(){}
	/*Infinite or local using the light position.*/
	void setUseLightPosition(bool up){if(up == false) return; fprintf_s(mFile, "setAttr \".up\" %i;\n", up);}
	/*Infinite or local using the light position.*/
	void setUseLightPosition(const BoolID& up){fprintf_s(mFile,"connectAttr \"");up.write(mFile);fprintf_s(mFile,"\" \"%s.up\";\n",mName.c_str());}
	/*The type of object being lit (volume or surface).*/
	void setObjectType(char ot){if(ot == 1) return; fprintf_s(mFile, "setAttr \".ot\" %;\n", ot);}
	/*The soft shadow light sampling angle.*/
	void setLightAngle(float lang){if(lang == 0.0) return; fprintf_s(mFile, "setAttr \".lang\" %f;\n", lang);}
	/*The soft shadow light sampling angle.*/
	void setLightAngle(const FloatID& lang){fprintf_s(mFile,"connectAttr \"");lang.write(mFile);fprintf_s(mFile,"\" \"%s.lang\";\n",mName.c_str());}
	/*The point to light in world space (for shadow maps).*/
	void setPointWorld(const float3& pw){if(pw == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".pw\" -type \"float3\" ");pw.write(mFile);fprintf_s(mFile,";\n");}
	/*The x-component of the world position.*/
	void setPointWorldX(float tx){if(tx == 0.0) return; fprintf_s(mFile, "setAttr \".pw.tx\" %f;\n", tx);}
	/*The y-component of the world position.*/
	void setPointWorldY(float ty){if(ty == 0.0) return; fprintf_s(mFile, "setAttr \".pw.ty\" %f;\n", ty);}
	/*The z-component of the world position.*/
	void setPointWorldZ(float tz){if(tz == 0.0) return; fprintf_s(mFile, "setAttr \".pw.tz\" %f;\n", tz);}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*
	Controls usage of default mayabase light shader, which is used
	by default. If enabled, the mayabase light shader will not be applied
	at all but any connected custom mental ray node will.
	*/
	void setMiExportMrLight(bool milt){if(milt == false) return; fprintf_s(mFile, "setAttr \".mrc.milt\" %i;\n", milt);}
	/*
	Controls usage of default mayabase light shader, which is used
	by default. If enabled, the mayabase light shader will not be applied
	at all but any connected custom mental ray node will.
	*/
	void setMiExportMrLight(const BoolID& milt){fprintf_s(mFile,"connectAttr \"");milt.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.milt\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type light shader.*/
	void setMiLightShader(const GenerictypeddataID& mils){fprintf_s(mFile,"connectAttr \"");mils.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mils\";\n",mName.c_str());}
	/*Port to connect custom mental ray node of type photon emitter shader.*/
	void setMiPhotonEmitter(const GenerictypeddataID& mipe){fprintf_s(mFile,"connectAttr \"");mipe.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mipe\";\n",mName.c_str());}
	/*Enable photon emission for the light.*/
	void setEmitPhotons(bool phot){if(phot == false) return; fprintf_s(mFile, "setAttr \".mrc.phot\" %i;\n", phot);}
	/*Enable photon emission for the light.*/
	void setEmitPhotons(const BoolID& phot){fprintf_s(mFile,"connectAttr \"");phot.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.phot\";\n",mName.c_str());}
	/*
	Determines photon energy for the light.
	<b>energy</b> is a produc of <b>Photon color</b> and <b>Photon intensity</b>
	<b>Photon Color</b> is available in UI only, and is not a real attribute.
	*/
	void setEnergy(const float3& eng){fprintf_s(mFile, "setAttr \".mrc.eng\" -type \"float3\" ");eng.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Determines photon energy for the light.
	<b>energy</b> is a produc of <b>Photon color</b> and <b>Photon intensity</b>
	<b>Photon Color</b> is available in UI only, and is not a real attribute.
	*/
	void setEnergy(const Float3ID& eng){fprintf_s(mFile,"connectAttr \"");eng.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.eng\";\n",mName.c_str());}
	/*The red component of the photon energy*/
	void setEnergyR(float engr){if(engr == 8000) return; fprintf_s(mFile, "setAttr \".mrc.eng.engr\" %f;\n", engr);}
	/*The red component of the photon energy*/
	void setEnergyR(const FloatID& engr){fprintf_s(mFile,"connectAttr \"");engr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.eng.engr\";\n",mName.c_str());}
	/*The green component of the photon energy*/
	void setEnergyG(float engg){if(engg == 8000) return; fprintf_s(mFile, "setAttr \".mrc.eng.engg\" %f;\n", engg);}
	/*The green component of the photon energy*/
	void setEnergyG(const FloatID& engg){fprintf_s(mFile,"connectAttr \"");engg.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.eng.engg\";\n",mName.c_str());}
	/*The blue component of the photon energy*/
	void setEnergyB(float engb){if(engb == 8000) return; fprintf_s(mFile, "setAttr \".mrc.eng.engb\" %f;\n", engb);}
	/*The blue component of the photon energy*/
	void setEnergyB(const FloatID& engb){fprintf_s(mFile,"connectAttr \"");engb.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.eng.engb\";\n",mName.c_str());}
	/*
	Photon intensity factor for the photon energy color
	to determine photon energy for the light.
	Should be changed through the UI only.
	*/
	void setPhotonIntensity(float phi){if(phi == 1) return; fprintf_s(mFile, "setAttr \".mrc.phi\" %f;\n", phi);}
	/*
	Photon intensity factor for the photon energy color
	to determine photon energy for the light.
	Should be changed through the UI only.
	*/
	void setPhotonIntensity(const FloatID& phi){fprintf_s(mFile,"connectAttr \"");phi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.phi\";\n",mName.c_str());}
	/*
	Photon energy falloff.
	Values other than 2 produce non-physically correct indirect illumination.
	*/
	void setExponent(float exp){if(exp == 2) return; fprintf_s(mFile, "setAttr \".mrc.exp\" %f;\n", exp);}
	/*
	Photon energy falloff.
	Values other than 2 produce non-physically correct indirect illumination.
	*/
	void setExponent(const FloatID& exp){fprintf_s(mFile,"connectAttr \"");exp.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.exp\";\n",mName.c_str());}
	/*Caustic photons to emit (actually store) from the light.*/
	void setCausticPhotons(int cph){if(cph == 10000) return; fprintf_s(mFile, "setAttr \".mrc.cph\" %i;\n", cph);}
	/*Caustic photons to emit (actually store) from the light.*/
	void setCausticPhotons(const IntID& cph){fprintf_s(mFile,"connectAttr \"");cph.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.cph\";\n",mName.c_str());}
	/*Global illumination photons to emit (actually store) from the light.*/
	void setGlobIllPhotons(int gph){if(gph == 10000) return; fprintf_s(mFile, "setAttr \".mrc.gph\" %i;\n", gph);}
	/*Global illumination photons to emit (actually store) from the light.*/
	void setGlobIllPhotons(const IntID& gph){fprintf_s(mFile,"connectAttr \"");gph.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gph\";\n",mName.c_str());}
	/*Turn on mental ray shadowmap creation for the light.*/
	void setShadowMap(bool usm){if(usm == false) return; fprintf_s(mFile, "setAttr \".mrc.usm\" %i;\n", usm);}
	/*Turn on mental ray shadowmap creation for the light.*/
	void setShadowMap(const BoolID& usm){fprintf_s(mFile,"connectAttr \"");usm.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.usm\";\n",mName.c_str());}
	/*Resolution (both width and height) of the shadowmap for mental ray.*/
	void setSmapResolution(int smr){if(smr == 256) return; fprintf_s(mFile, "setAttr \".mrc.smr\" %i;\n", smr);}
	/*Resolution (both width and height) of the shadowmap for mental ray.*/
	void setSmapResolution(const IntID& smr){fprintf_s(mFile,"connectAttr \"");smr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smr\";\n",mName.c_str());}
	/*
	Number of shadowmap samples to be taken if <b>smapSoftness</b> is greater zero.
	mental ray only.
	*/
	void setSmapSamples(short smsa){if(smsa == 1) return; fprintf_s(mFile, "setAttr \".mrc.smsa\" %i;\n", smsa);}
	/*
	Number of shadowmap samples to be taken if <b>smapSoftness</b> is greater zero.
	mental ray only.
	*/
	void setSmapSamples(const ShortID& smsa){fprintf_s(mFile,"connectAttr \"");smsa.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smsa\";\n",mName.c_str());}
	/*
	The mental ray shadowmap softness for the light.
	If greater zero, oversampling will be used to produce blurry shadows.
	*/
	void setSmapSoftness(float smso){if(smso == 0) return; fprintf_s(mFile, "setAttr \".mrc.smso\" %f;\n", smso);}
	/*
	The mental ray shadowmap softness for the light.
	If greater zero, oversampling will be used to produce blurry shadows.
	*/
	void setSmapSoftness(const FloatID& smso){fprintf_s(mFile,"connectAttr \"");smso.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smso\";\n",mName.c_str());}
	/*
	Controls mental ray shadow map bias. It is a factor on the internal bias value.
	If <b>smapBias</b> is 0, the Woo algorithm (mid dist shadowmap) is enabled,
	and the bias is not used.
	*/
	void setSmapBias(float smb){if(smb == 0) return; fprintf_s(mFile, "setAttr \".mrc.smb\" %f;\n", smb);}
	/*
	Controls mental ray shadow map bias. It is a factor on the internal bias value.
	If <b>smapBias</b> is 0, the Woo algorithm (mid dist shadowmap) is enabled,
	and the bias is not used.
	*/
	void setSmapBias(const FloatID& smb){fprintf_s(mFile,"connectAttr \"");smb.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smb\";\n",mName.c_str());}
	/*For internal use only.*/
	void setSmapCamera(const MessageID& smc){fprintf_s(mFile,"connectAttr \"");smc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smc\";\n",mName.c_str());}
	/*If not empty, enable shadowmap file creation with that name for mental ray.*/
	void setSmapFilename(const string& smf){if(smf == "NULL") return; fprintf_s(mFile, "setAttr \".mrc.smf\" -type \"string\" ");smf.write(mFile);fprintf_s(mFile,";\n");}
	/*If not empty, enable shadowmap file creation with that name for mental ray.*/
	void setSmapFilename(const StringID& smf){fprintf_s(mFile,"connectAttr \"");smf.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smf\";\n",mName.c_str());}
	/*Include the light name in the shadow map name.*/
	void setSmapLightName(bool smln){if(smln == 0) return; fprintf_s(mFile, "setAttr \".mrc.smln\" %i;\n", smln);}
	/*Include the light name in the shadow map name.*/
	void setSmapLightName(const BoolID& smln){fprintf_s(mFile,"connectAttr \"");smln.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smln\";\n",mName.c_str());}
	/*Include the scene name in the shadow map name.*/
	void setSmapSceneName(bool smsn){if(smsn == 0) return; fprintf_s(mFile, "setAttr \".mrc.smsn\" %i;\n", smsn);}
	/*Include the scene name in the shadow map name.*/
	void setSmapSceneName(const BoolID& smsn){fprintf_s(mFile,"connectAttr \"");smsn.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smsn\";\n",mName.c_str());}
	/*Include the frame extention in the shadow map name.*/
	void setSmapFrameExt(bool smfe){if(smfe == 0) return; fprintf_s(mFile, "setAttr \".mrc.smfe\" %i;\n", smfe);}
	/*Include the frame extention in the shadow map name.*/
	void setSmapFrameExt(const BoolID& smfe){fprintf_s(mFile,"connectAttr \"");smfe.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smfe\";\n",mName.c_str());}
	/*
	Use mental ray detail shadow map for this light.
	<b>shadowMap</b> must be enabled.
	This algorithm is a combination of standard shadowmaps and ray traced shadows.
	Unlike standard shadowmaps, the detail shadowmap algorithm invokes shadow shaders
	at intersection points with shadow-casting geometry
	In general, detail shadowmaps need less resolution than standard shadowmaps,
	since they may take more samples per pixel.
	Still, detail shadowmaps tend to be more expensive to compute than standard shadowmaps
	because of the shadow shader calls.
	They may even be more expensive than raytraced shadows.
	However, their cost may be offset by repeated reuse over several frames.
	They may also be more efficient with time and memory resources than raytraced shadows for motion blurred shadows.
	The file format used to store detail shadowmaps is incompatible with the file format used to store regular shadowmaps.
	The entire file format is tile-based and only those tiles computed or used during a rendering will be stored in the file.
	New tiles may be dynamically added during rendering of new frames.
	Detail shadowmap files tend to be larger than regular shadowmap files since more information per pixel is stored.
	*/
	void setSmapDetail(bool smd){if(smd == 0) return; fprintf_s(mFile, "setAttr \".mrc.smd\" %i;\n", smd);}
	/*
	Use mental ray detail shadow map for this light.
	<b>shadowMap</b> must be enabled.
	This algorithm is a combination of standard shadowmaps and ray traced shadows.
	Unlike standard shadowmaps, the detail shadowmap algorithm invokes shadow shaders
	at intersection points with shadow-casting geometry
	In general, detail shadowmaps need less resolution than standard shadowmaps,
	since they may take more samples per pixel.
	Still, detail shadowmaps tend to be more expensive to compute than standard shadowmaps
	because of the shadow shader calls.
	They may even be more expensive than raytraced shadows.
	However, their cost may be offset by repeated reuse over several frames.
	They may also be more efficient with time and memory resources than raytraced shadows for motion blurred shadows.
	The file format used to store detail shadowmaps is incompatible with the file format used to store regular shadowmaps.
	The entire file format is tile-based and only those tiles computed or used during a rendering will be stored in the file.
	New tiles may be dynamically added during rendering of new frames.
	Detail shadowmap files tend to be larger than regular shadowmap files since more information per pixel is stored.
	*/
	void setSmapDetail(const BoolID& smd){fprintf_s(mFile,"connectAttr \"");smd.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.smd\";\n",mName.c_str());}
	/*
	Specify the number of samples per pixel taken when computing a mental ray detail shadowmap pixel.
	A value of  <b>n</b> means that nxn samples are taken per pixel,
	each involving a shadow intersection
	including a shadow shader call at some varying subpixel coordinate inside the shadowmap pixel.
	If <b>smapDetailSamples</b> is set to 0, mental ray default value is used.
	*/
	void setSmapDetailSamples(short sds){if(sds == 0) return; fprintf_s(mFile, "setAttr \".mrc.sds\" %i;\n", sds);}
	/*
	Specify the number of samples per pixel taken when computing a mental ray detail shadowmap pixel.
	A value of  <b>n</b> means that nxn samples are taken per pixel,
	each involving a shadow intersection
	including a shadow shader call at some varying subpixel coordinate inside the shadowmap pixel.
	If <b>smapDetailSamples</b> is set to 0, mental ray default value is used.
	*/
	void setSmapDetailSamples(const ShortID& sds){fprintf_s(mFile,"connectAttr \"");sds.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.sds\";\n",mName.c_str());}
	/*
	This parameter determines how far two depth values of a sample
	have to be separated in order to be considered two distinct values.
	Selecting this value too small will result in larger memory
	and compute resource requirements for detail shadowmaps.
	Selecting it too large will lead to visible artifacts.
	mental ray tries to use a reasonable default value for the accuracy.
	If <b>smapDetailAccuracy</b> is set to 0, mental ray default value is used.
	*/
	void setSmapDetailAccuracy(float sdac){if(sdac == 0) return; fprintf_s(mFile, "setAttr \".mrc.sdac\" %f;\n", sdac);}
	/*
	This parameter determines how far two depth values of a sample
	have to be separated in order to be considered two distinct values.
	Selecting this value too small will result in larger memory
	and compute resource requirements for detail shadowmaps.
	Selecting it too large will lead to visible artifacts.
	mental ray tries to use a reasonable default value for the accuracy.
	If <b>smapDetailAccuracy</b> is set to 0, mental ray default value is used.
	*/
	void setSmapDetailAccuracy(const FloatID& sdac){fprintf_s(mFile,"connectAttr \"");sdac.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.sdac\";\n",mName.c_str());}
	/*
	If <b>smapDetailAlpha</b> is set,
	then only the intensity values of the color transmission coeffiencents are used.
	*/
	void setSmapDetailAlpha(bool sdal){if(sdal == 0) return; fprintf_s(mFile, "setAttr \".mrc.sdal\" %i;\n", sdal);}
	/*
	If <b>smapDetailAlpha</b> is set,
	then only the intensity values of the color transmission coeffiencents are used.
	*/
	void setSmapDetailAlpha(const BoolID& sdal){fprintf_s(mFile,"connectAttr \"");sdal.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.sdal\";\n",mName.c_str());}
	/*Infinite or local using the light position.*/
	BoolID getUseLightPosition(){char buffer[4096];sprintf_s (buffer, "%s.up",mName.c_str());return (const char*)buffer;}
	/*The soft shadow light sampling angle.*/
	FloatID getLightAngle(){char buffer[4096];sprintf_s (buffer, "%s.lang",mName.c_str());return (const char*)buffer;}
	/*This is a root of following mental ray attributes.*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*
	Controls usage of default mayabase light shader, which is used
	by default. If enabled, the mayabase light shader will not be applied
	at all but any connected custom mental ray node will.
	*/
	BoolID getMiExportMrLight(){char buffer[4096];sprintf_s (buffer, "%s.mrc.milt",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type light shader.*/
	GenerictypeddataID getMiLightShader(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mils",mName.c_str());return (const char*)buffer;}
	/*Port to connect custom mental ray node of type photon emitter shader.*/
	GenerictypeddataID getMiPhotonEmitter(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mipe",mName.c_str());return (const char*)buffer;}
	/*Enable photon emission for the light.*/
	BoolID getEmitPhotons(){char buffer[4096];sprintf_s (buffer, "%s.mrc.phot",mName.c_str());return (const char*)buffer;}
	/*
	Determines photon energy for the light.
	<b>energy</b> is a produc of <b>Photon color</b> and <b>Photon intensity</b>
	<b>Photon Color</b> is available in UI only, and is not a real attribute.
	*/
	Float3ID getEnergy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.eng",mName.c_str());return (const char*)buffer;}
	/*The red component of the photon energy*/
	FloatID getEnergyR(){char buffer[4096];sprintf_s (buffer, "%s.mrc.eng.engr",mName.c_str());return (const char*)buffer;}
	/*The green component of the photon energy*/
	FloatID getEnergyG(){char buffer[4096];sprintf_s (buffer, "%s.mrc.eng.engg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the photon energy*/
	FloatID getEnergyB(){char buffer[4096];sprintf_s (buffer, "%s.mrc.eng.engb",mName.c_str());return (const char*)buffer;}
	/*
	Photon intensity factor for the photon energy color
	to determine photon energy for the light.
	Should be changed through the UI only.
	*/
	FloatID getPhotonIntensity(){char buffer[4096];sprintf_s (buffer, "%s.mrc.phi",mName.c_str());return (const char*)buffer;}
	/*
	Photon energy falloff.
	Values other than 2 produce non-physically correct indirect illumination.
	*/
	FloatID getExponent(){char buffer[4096];sprintf_s (buffer, "%s.mrc.exp",mName.c_str());return (const char*)buffer;}
	/*Caustic photons to emit (actually store) from the light.*/
	IntID getCausticPhotons(){char buffer[4096];sprintf_s (buffer, "%s.mrc.cph",mName.c_str());return (const char*)buffer;}
	/*Global illumination photons to emit (actually store) from the light.*/
	IntID getGlobIllPhotons(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gph",mName.c_str());return (const char*)buffer;}
	/*Turn on mental ray shadowmap creation for the light.*/
	BoolID getShadowMap(){char buffer[4096];sprintf_s (buffer, "%s.mrc.usm",mName.c_str());return (const char*)buffer;}
	/*Resolution (both width and height) of the shadowmap for mental ray.*/
	IntID getSmapResolution(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smr",mName.c_str());return (const char*)buffer;}
	/*
	Number of shadowmap samples to be taken if <b>smapSoftness</b> is greater zero.
	mental ray only.
	*/
	ShortID getSmapSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smsa",mName.c_str());return (const char*)buffer;}
	/*
	The mental ray shadowmap softness for the light.
	If greater zero, oversampling will be used to produce blurry shadows.
	*/
	FloatID getSmapSoftness(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smso",mName.c_str());return (const char*)buffer;}
	/*
	Controls mental ray shadow map bias. It is a factor on the internal bias value.
	If <b>smapBias</b> is 0, the Woo algorithm (mid dist shadowmap) is enabled,
	and the bias is not used.
	*/
	FloatID getSmapBias(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smb",mName.c_str());return (const char*)buffer;}
	/*For internal use only.*/
	MessageID getSmapCamera(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smc",mName.c_str());return (const char*)buffer;}
	/*If not empty, enable shadowmap file creation with that name for mental ray.*/
	StringID getSmapFilename(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smf",mName.c_str());return (const char*)buffer;}
	/*Include the light name in the shadow map name.*/
	BoolID getSmapLightName(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smln",mName.c_str());return (const char*)buffer;}
	/*Include the scene name in the shadow map name.*/
	BoolID getSmapSceneName(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smsn",mName.c_str());return (const char*)buffer;}
	/*Include the frame extention in the shadow map name.*/
	BoolID getSmapFrameExt(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smfe",mName.c_str());return (const char*)buffer;}
	/*
	Use mental ray detail shadow map for this light.
	<b>shadowMap</b> must be enabled.
	This algorithm is a combination of standard shadowmaps and ray traced shadows.
	Unlike standard shadowmaps, the detail shadowmap algorithm invokes shadow shaders
	at intersection points with shadow-casting geometry
	In general, detail shadowmaps need less resolution than standard shadowmaps,
	since they may take more samples per pixel.
	Still, detail shadowmaps tend to be more expensive to compute than standard shadowmaps
	because of the shadow shader calls.
	They may even be more expensive than raytraced shadows.
	However, their cost may be offset by repeated reuse over several frames.
	They may also be more efficient with time and memory resources than raytraced shadows for motion blurred shadows.
	The file format used to store detail shadowmaps is incompatible with the file format used to store regular shadowmaps.
	The entire file format is tile-based and only those tiles computed or used during a rendering will be stored in the file.
	New tiles may be dynamically added during rendering of new frames.
	Detail shadowmap files tend to be larger than regular shadowmap files since more information per pixel is stored.
	*/
	BoolID getSmapDetail(){char buffer[4096];sprintf_s (buffer, "%s.mrc.smd",mName.c_str());return (const char*)buffer;}
	/*
	Specify the number of samples per pixel taken when computing a mental ray detail shadowmap pixel.
	A value of  <b>n</b> means that nxn samples are taken per pixel,
	each involving a shadow intersection
	including a shadow shader call at some varying subpixel coordinate inside the shadowmap pixel.
	If <b>smapDetailSamples</b> is set to 0, mental ray default value is used.
	*/
	ShortID getSmapDetailSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.sds",mName.c_str());return (const char*)buffer;}
	/*
	This parameter determines how far two depth values of a sample
	have to be separated in order to be considered two distinct values.
	Selecting this value too small will result in larger memory
	and compute resource requirements for detail shadowmaps.
	Selecting it too large will lead to visible artifacts.
	mental ray tries to use a reasonable default value for the accuracy.
	If <b>smapDetailAccuracy</b> is set to 0, mental ray default value is used.
	*/
	FloatID getSmapDetailAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.sdac",mName.c_str());return (const char*)buffer;}
	/*
	If <b>smapDetailAlpha</b> is set,
	then only the intensity values of the color transmission coeffiencents are used.
	*/
	BoolID getSmapDetailAlpha(){char buffer[4096];sprintf_s (buffer, "%s.mrc.sdal",mName.c_str());return (const char*)buffer;}
protected:
	DirectionalLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):NonExtendedLightShapeNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DIRECTIONALLIGHT_H__
