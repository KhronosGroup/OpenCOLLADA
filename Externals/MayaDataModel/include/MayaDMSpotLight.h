/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SPOTLIGHT_H__
#define __MayaDM_SPOTLIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNonExtendedLightShapeNode.h"
namespace MayaDM
{
/*
<p><pre>
        This class contains the "shape" information for spot lights.

</pre></p>
*/
class SpotLight : public NonExtendedLightShapeNode
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
		bool areaLight;
		unsigned int areaType;
		float3 areaNormal;
		float3 areaEdge;
		float areaRadius;
		short2 areaSampling;
		short areaLowLevel;
		short2 areaLowSampling;
		bool areaVisible;
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
			fprintf_s(file,"%i ", smapDetailAlpha);
			fprintf_s(file,"%i ", areaLight);
			fprintf_s(file,"%i ", areaType);
			areaNormal.write(file);
			fprintf_s(file, " ");
			areaEdge.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f ", areaRadius);
			areaSampling.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i ", areaLowLevel);
			areaLowSampling.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", areaVisible);
		}
	};
public:
	SpotLight(FILE* file,const std::string& name,const std::string& parent=""):NonExtendedLightShapeNode(file, name, parent, "spotLight"){}
	virtual ~SpotLight(){}
	/*The cone angle.*/
	void setConeAngle(double ca){if(ca == 4) return; fprintf_s(mFile, "setAttr \".ca\" %f;\n", ca);}
	/*The cone angle.*/
	void setConeAngle(const DoubleID& ca){fprintf_s(mFile,"connectAttr \"");ca.write(mFile);fprintf_s(mFile,"\" \"%s.ca\";\n",mName.c_str());}
	/*The penumbra angle.*/
	void setPenumbraAngle(double pa){if(pa == 0) return; fprintf_s(mFile, "setAttr \".pa\" %f;\n", pa);}
	/*The penumbra angle.*/
	void setPenumbraAngle(const DoubleID& pa){fprintf_s(mFile,"connectAttr \"");pa.write(mFile);fprintf_s(mFile,"\" \"%s.pa\";\n",mName.c_str());}
	/*The dropoff.*/
	void setDropoff(double dro){if(dro == 0.0) return; fprintf_s(mFile, "setAttr \".dro\" %f;\n", dro);}
	/*The dropoff.*/
	void setDropoff(const DoubleID& dro){fprintf_s(mFile,"connectAttr \"");dro.write(mFile);fprintf_s(mFile,"\" \"%s.dro\";\n",mName.c_str());}
	/*Are barndoors on?*/
	void setBarnDoors(bool bd){if(bd == false) return; fprintf_s(mFile, "setAttr \".bd\" %i;\n", bd);}
	/*Are barndoors on?*/
	void setBarnDoors(const BoolID& bd){fprintf_s(mFile,"connectAttr \"");bd.write(mFile);fprintf_s(mFile,"\" \"%s.bd\";\n",mName.c_str());}
	/*The left barn door angle.*/
	void setLeftBarnDoor(double lbd){if(lbd == 2) return; fprintf_s(mFile, "setAttr \".lbd\" %f;\n", lbd);}
	/*The left barn door angle.*/
	void setLeftBarnDoor(const DoubleID& lbd){fprintf_s(mFile,"connectAttr \"");lbd.write(mFile);fprintf_s(mFile,"\" \"%s.lbd\";\n",mName.c_str());}
	/*The right barn door angle.*/
	void setRightBarnDoor(double rbd){if(rbd == 2) return; fprintf_s(mFile, "setAttr \".rbd\" %f;\n", rbd);}
	/*The right barn door angle.*/
	void setRightBarnDoor(const DoubleID& rbd){fprintf_s(mFile,"connectAttr \"");rbd.write(mFile);fprintf_s(mFile,"\" \"%s.rbd\";\n",mName.c_str());}
	/*The top barn door angle.*/
	void setTopBarnDoor(double tbd){if(tbd == 2) return; fprintf_s(mFile, "setAttr \".tbd\" %f;\n", tbd);}
	/*The top barn door angle.*/
	void setTopBarnDoor(const DoubleID& tbd){fprintf_s(mFile,"connectAttr \"");tbd.write(mFile);fprintf_s(mFile,"\" \"%s.tbd\";\n",mName.c_str());}
	/*The bottom barn door angle.*/
	void setBottomBarnDoor(double bbd){if(bbd == 2) return; fprintf_s(mFile, "setAttr \".bbd\" %f;\n", bbd);}
	/*The bottom barn door angle.*/
	void setBottomBarnDoor(const DoubleID& bbd){fprintf_s(mFile,"connectAttr \"");bbd.write(mFile);fprintf_s(mFile,"\" \"%s.bbd\";\n",mName.c_str());}
	/*Are decayregions on?*/
	void setUseDecayRegions(bool udr){if(udr == false) return; fprintf_s(mFile, "setAttr \".udr\" %i;\n", udr);}
	/*Are decayregions on?*/
	void setUseDecayRegions(const BoolID& udr){fprintf_s(mFile,"connectAttr \"");udr.write(mFile);fprintf_s(mFile,"\" \"%s.udr\";\n",mName.c_str());}
	/*The start distance of decay region 1.*/
	void setStartDistance1(float sd1){if(sd1 == 1) return; fprintf_s(mFile, "setAttr \".sd1\" %f;\n", sd1);}
	/*The start distance of decay region 1.*/
	void setStartDistance1(const FloatID& sd1){fprintf_s(mFile,"connectAttr \"");sd1.write(mFile);fprintf_s(mFile,"\" \"%s.sd1\";\n",mName.c_str());}
	/*The end distance of decay region 1.*/
	void setEndDistance1(float ed1){if(ed1 == 2) return; fprintf_s(mFile, "setAttr \".ed1\" %f;\n", ed1);}
	/*The end distance of decay region 1.*/
	void setEndDistance1(const FloatID& ed1){fprintf_s(mFile,"connectAttr \"");ed1.write(mFile);fprintf_s(mFile,"\" \"%s.ed1\";\n",mName.c_str());}
	/*The start distance of decay region 2.*/
	void setStartDistance2(float sd2){if(sd2 == 3) return; fprintf_s(mFile, "setAttr \".sd2\" %f;\n", sd2);}
	/*The start distance of decay region 2.*/
	void setStartDistance2(const FloatID& sd2){fprintf_s(mFile,"connectAttr \"");sd2.write(mFile);fprintf_s(mFile,"\" \"%s.sd2\";\n",mName.c_str());}
	/*The end distance of decay region 2.*/
	void setEndDistance2(float ed2){if(ed2 == 6) return; fprintf_s(mFile, "setAttr \".ed2\" %f;\n", ed2);}
	/*The end distance of decay region 2.*/
	void setEndDistance2(const FloatID& ed2){fprintf_s(mFile,"connectAttr \"");ed2.write(mFile);fprintf_s(mFile,"\" \"%s.ed2\";\n",mName.c_str());}
	/*The start distance of decay region 3.*/
	void setStartDistance3(float sd3){if(sd3 == 8) return; fprintf_s(mFile, "setAttr \".sd3\" %f;\n", sd3);}
	/*The start distance of decay region 3.*/
	void setStartDistance3(const FloatID& sd3){fprintf_s(mFile,"connectAttr \"");sd3.write(mFile);fprintf_s(mFile,"\" \"%s.sd3\";\n",mName.c_str());}
	/*The end distance of decay region 3.*/
	void setEndDistance3(float ed3){if(ed3 == 1) return; fprintf_s(mFile, "setAttr \".ed3\" %f;\n", ed3);}
	/*The end distance of decay region 3.*/
	void setEndDistance3(const FloatID& ed3){fprintf_s(mFile,"connectAttr \"");ed3.write(mFile);fprintf_s(mFile,"\" \"%s.ed3\";\n",mName.c_str());}
	/*The fog spread.*/
	void setFogSpread(float fsp){if(fsp == 1.0) return; fprintf_s(mFile, "setAttr \".fsp\" %f;\n", fsp);}
	/*The fog spread.*/
	void setFogSpread(const FloatID& fsp){fprintf_s(mFile,"connectAttr \"");fsp.write(mFile);fprintf_s(mFile,"\" \"%s.fsp\";\n",mName.c_str());}
	/*The fog intensity.*/
	void setFogIntensity(float fin){if(fin == 1.0) return; fprintf_s(mFile, "setAttr \".fin\" %f;\n", fin);}
	/*The fog intensity.*/
	void setFogIntensity(const FloatID& fin){fprintf_s(mFile,"connectAttr \"");fin.write(mFile);fprintf_s(mFile,"\" \"%s.fin\";\n",mName.c_str());}
	/*The type of object being lit (volume or surface).*/
	void setObjectType(char ot){if(ot == 1) return; fprintf_s(mFile, "setAttr \".ot\" %;\n", ot);}
	/*
	The start point of the interval produced by the viewing ray
	and the shadow map, in world space.
	*/
	void setPointWorld(const float3& pw){if(pw == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".pw\" -type \"float3\" ");pw.write(mFile);fprintf_s(mFile,";\n");}
	/*The x-component of the world position.*/
	void setPointWorldX(float tx){if(tx == 0.0) return; fprintf_s(mFile, "setAttr \".pw.tx\" %f;\n", tx);}
	/*The y-component of the world position.*/
	void setPointWorldY(float ty){if(ty == 0.0) return; fprintf_s(mFile, "setAttr \".pw.ty\" %f;\n", ty);}
	/*The z-component of the world position.*/
	void setPointWorldZ(float tz){if(tz == 0.0) return; fprintf_s(mFile, "setAttr \".pw.tz\" %f;\n", tz);}
	/*
	The end point of the interval produced by the viewing ray
	and the shadow map, in world space.
	*/
	void setFarPointWorld(const float3& fw){if(fw == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".fw\" -type \"float3\" ");fw.write(mFile);fprintf_s(mFile,";\n");}
	/*The x-component of the world far-position.*/
	void setFarPointWorldX(float fx){if(fx == 0.0) return; fprintf_s(mFile, "setAttr \".fw.fx\" %f;\n", fx);}
	/*The y-component of the world far-position.*/
	void setFarPointWorldY(float fy){if(fy == 0.0) return; fprintf_s(mFile, "setAttr \".fw.fy\" %f;\n", fy);}
	/*The z-component of the world far-position.*/
	void setFarPointWorldZ(float fz){if(fz == 0.0) return; fprintf_s(mFile, "setAttr \".fw.fz\" %f;\n", fz);}
	/*Connect this to the fog geometry.*/
	void setFogGeometry(const MessageID& fg){fprintf_s(mFile,"connectAttr \"");fg.write(mFile);fprintf_s(mFile,"\" \"%s.fg\";\n",mName.c_str());}
	/*Connect this to the light glow.*/
	void setLightGlow(const MessageID& lg){fprintf_s(mFile,"connectAttr \"");lg.write(mFile);fprintf_s(mFile,"\" \"%s.lg\";\n",mName.c_str());}
	/*The number of particle illumination samples*/
	void setPsIllumSamples(short pis){if(pis == 1) return; fprintf_s(mFile, "setAttr \".pis\" %i;\n", pis);}
	/*The number of particle illumination samples*/
	void setPsIllumSamples(const ShortID& pis){fprintf_s(mFile,"connectAttr \"");pis.write(mFile);fprintf_s(mFile,"\" \"%s.pis\";\n",mName.c_str());}
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
	<b>energy</b> is a product of <b>Photon color</b> and <b>Photon intensity</b>
	<b>Photon Color</b> is available in UI only, and is not a real attribute.
	*/
	void setEnergy(const float3& eng){fprintf_s(mFile, "setAttr \".mrc.eng\" -type \"float3\" ");eng.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Determines photon energy for the light.
	<b>energy</b> is a product of <b>Photon color</b> and <b>Photon intensity</b>
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
	/*Enable mental ray area light attributes for the light.*/
	void setAreaLight(bool algt){if(algt == false) return; fprintf_s(mFile, "setAttr \".mrc.algt\" %i;\n", algt);}
	/*Enable mental ray area light attributes for the light.*/
	void setAreaLight(const BoolID& algt){fprintf_s(mFile,"connectAttr \"");algt.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.algt\";\n",mName.c_str());}
	/*Type to determine the shape of the area light.*/
	void setAreaType(unsigned int atyp){if(atyp == 0) return; fprintf_s(mFile, "setAttr \".mrc.atyp\" %i;\n", atyp);}
	/*Type to determine the shape of the area light.*/
	void setAreaType(const UnsignedintID& atyp){fprintf_s(mFile,"connectAttr \"");atyp.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.atyp\";\n",mName.c_str());}
	/*Normal vector to control direction of rectangle and disk area lights.*/
	void setAreaNormal(const float3& ano){fprintf_s(mFile, "setAttr \".mrc.ano\" -type \"float3\" ");ano.write(mFile);fprintf_s(mFile,";\n");}
	/*Normal vector to control direction of rectangle and disk area lights.*/
	void setAreaNormal(const Float3ID& ano){fprintf_s(mFile,"connectAttr \"");ano.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ano\";\n",mName.c_str());}
	/*X component of areaNormal*/
	void setAreaNormalX(float anox){if(anox == 0) return; fprintf_s(mFile, "setAttr \".mrc.ano.anox\" %f;\n", anox);}
	/*X component of areaNormal*/
	void setAreaNormalX(const FloatID& anox){fprintf_s(mFile,"connectAttr \"");anox.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ano.anox\";\n",mName.c_str());}
	/*Y component of areaNormal*/
	void setAreaNormalY(float anoy){if(anoy == 2) return; fprintf_s(mFile, "setAttr \".mrc.ano.anoy\" %f;\n", anoy);}
	/*Y component of areaNormal*/
	void setAreaNormalY(const FloatID& anoy){fprintf_s(mFile,"connectAttr \"");anoy.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ano.anoy\";\n",mName.c_str());}
	/*Z component of areaNormal*/
	void setAreaNormalZ(float anoz){if(anoz == 0) return; fprintf_s(mFile, "setAttr \".mrc.ano.anoz\" %f;\n", anoz);}
	/*Z component of areaNormal*/
	void setAreaNormalZ(const FloatID& anoz){fprintf_s(mFile,"connectAttr \"");anoz.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ano.anoz\";\n",mName.c_str());}
	/*Edge vector to control direction of rectangle and cylinder area lights.*/
	void setAreaEdge(const float3& aed){fprintf_s(mFile, "setAttr \".mrc.aed\" -type \"float3\" ");aed.write(mFile);fprintf_s(mFile,";\n");}
	/*Edge vector to control direction of rectangle and cylinder area lights.*/
	void setAreaEdge(const Float3ID& aed){fprintf_s(mFile,"connectAttr \"");aed.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.aed\";\n",mName.c_str());}
	/*X component of areaEdge*/
	void setAreaEdgeX(float aedx){if(aedx == 2) return; fprintf_s(mFile, "setAttr \".mrc.aed.aedx\" %f;\n", aedx);}
	/*X component of areaEdge*/
	void setAreaEdgeX(const FloatID& aedx){fprintf_s(mFile,"connectAttr \"");aedx.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.aed.aedx\";\n",mName.c_str());}
	/*Y component of areaEdge*/
	void setAreaEdgeY(float aedy){if(aedy == 0) return; fprintf_s(mFile, "setAttr \".mrc.aed.aedy\" %f;\n", aedy);}
	/*Y component of areaEdge*/
	void setAreaEdgeY(const FloatID& aedy){fprintf_s(mFile,"connectAttr \"");aedy.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.aed.aedy\";\n",mName.c_str());}
	/*Z component of areaEdge*/
	void setAreaEdgeZ(float aedz){if(aedz == 0) return; fprintf_s(mFile, "setAttr \".mrc.aed.aedz\" %f;\n", aedz);}
	/*Z component of areaEdge*/
	void setAreaEdgeZ(const FloatID& aedz){fprintf_s(mFile,"connectAttr \"");aedz.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.aed.aedz\";\n",mName.c_str());}
	/*Radius to control size of disk, sphere, and cylinder area lights.*/
	void setAreaRadius(float arad){if(arad == 2) return; fprintf_s(mFile, "setAttr \".mrc.arad\" %f;\n", arad);}
	/*Radius to control size of disk, sphere, and cylinder area lights.*/
	void setAreaRadius(const FloatID& arad){fprintf_s(mFile,"connectAttr \"");arad.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.arad\";\n",mName.c_str());}
	/*Area light sample values for primary light sampling.*/
	void setAreaSampling(const short2& asa){fprintf_s(mFile, "setAttr \".mrc.asa\" -type \"short2\" ");asa.write(mFile);fprintf_s(mFile,";\n");}
	/*Area light sample values for primary light sampling.*/
	void setAreaSampling(const Short2ID& asa){fprintf_s(mFile,"connectAttr \"");asa.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.asa\";\n",mName.c_str());}
	/*U component of areaSampling*/
	void setAreaSamplingU(short asau){if(asau == 3) return; fprintf_s(mFile, "setAttr \".mrc.asa.asau\" %i;\n", asau);}
	/*U component of areaSampling*/
	void setAreaSamplingU(const ShortID& asau){fprintf_s(mFile,"connectAttr \"");asau.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.asa.asau\";\n",mName.c_str());}
	/*V component of areaSampling*/
	void setAreaSamplingV(short asav){if(asav == 3) return; fprintf_s(mFile, "setAttr \".mrc.asa.asav\" %i;\n", asav);}
	/*V component of areaSampling*/
	void setAreaSamplingV(const ShortID& asav){fprintf_s(mFile,"connectAttr \"");asav.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.asa.asav\";\n",mName.c_str());}
	/*Area light tracing level to switch to lower sampling.*/
	void setAreaLowLevel(short alev){if(alev == 0) return; fprintf_s(mFile, "setAttr \".mrc.alev\" %i;\n", alev);}
	/*Area light tracing level to switch to lower sampling.*/
	void setAreaLowLevel(const ShortID& alev){fprintf_s(mFile,"connectAttr \"");alev.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.alev\";\n",mName.c_str());}
	/*Area light sample values for lower light sampling.*/
	void setAreaLowSampling(const short2& alo){fprintf_s(mFile, "setAttr \".mrc.alo\" -type \"short2\" ");alo.write(mFile);fprintf_s(mFile,";\n");}
	/*Area light sample values for lower light sampling.*/
	void setAreaLowSampling(const Short2ID& alo){fprintf_s(mFile,"connectAttr \"");alo.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.alo\";\n",mName.c_str());}
	/*U component of areaLowSampling*/
	void setAreaLowSamplingU(short alou){if(alou == 2) return; fprintf_s(mFile, "setAttr \".mrc.alo.alou\" %i;\n", alou);}
	/*U component of areaLowSampling*/
	void setAreaLowSamplingU(const ShortID& alou){fprintf_s(mFile,"connectAttr \"");alou.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.alo.alou\";\n",mName.c_str());}
	/*V component of areaLowSampling*/
	void setAreaLowSamplingV(short alov){if(alov == 2) return; fprintf_s(mFile, "setAttr \".mrc.alo.alov\" %i;\n", alov);}
	/*V component of areaLowSampling*/
	void setAreaLowSamplingV(const ShortID& alov){fprintf_s(mFile,"connectAttr \"");alov.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.alo.alov\";\n",mName.c_str());}
	/*Control primary visibility of the area light shape.*/
	void setAreaVisible(bool avis){if(avis == false) return; fprintf_s(mFile, "setAttr \".mrc.avis\" %i;\n", avis);}
	/*Control primary visibility of the area light shape.*/
	void setAreaVisible(const BoolID& avis){fprintf_s(mFile,"connectAttr \"");avis.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.avis\";\n",mName.c_str());}
	/*The cone angle.*/
	DoubleID getConeAngle(){char buffer[4096];sprintf_s (buffer, "%s.ca",mName.c_str());return (const char*)buffer;}
	/*The penumbra angle.*/
	DoubleID getPenumbraAngle(){char buffer[4096];sprintf_s (buffer, "%s.pa",mName.c_str());return (const char*)buffer;}
	/*The dropoff.*/
	DoubleID getDropoff(){char buffer[4096];sprintf_s (buffer, "%s.dro",mName.c_str());return (const char*)buffer;}
	/*Are barndoors on?*/
	BoolID getBarnDoors(){char buffer[4096];sprintf_s (buffer, "%s.bd",mName.c_str());return (const char*)buffer;}
	/*The left barn door angle.*/
	DoubleID getLeftBarnDoor(){char buffer[4096];sprintf_s (buffer, "%s.lbd",mName.c_str());return (const char*)buffer;}
	/*The right barn door angle.*/
	DoubleID getRightBarnDoor(){char buffer[4096];sprintf_s (buffer, "%s.rbd",mName.c_str());return (const char*)buffer;}
	/*The top barn door angle.*/
	DoubleID getTopBarnDoor(){char buffer[4096];sprintf_s (buffer, "%s.tbd",mName.c_str());return (const char*)buffer;}
	/*The bottom barn door angle.*/
	DoubleID getBottomBarnDoor(){char buffer[4096];sprintf_s (buffer, "%s.bbd",mName.c_str());return (const char*)buffer;}
	/*Are decayregions on?*/
	BoolID getUseDecayRegions(){char buffer[4096];sprintf_s (buffer, "%s.udr",mName.c_str());return (const char*)buffer;}
	/*The start distance of decay region 1.*/
	FloatID getStartDistance1(){char buffer[4096];sprintf_s (buffer, "%s.sd1",mName.c_str());return (const char*)buffer;}
	/*The end distance of decay region 1.*/
	FloatID getEndDistance1(){char buffer[4096];sprintf_s (buffer, "%s.ed1",mName.c_str());return (const char*)buffer;}
	/*The start distance of decay region 2.*/
	FloatID getStartDistance2(){char buffer[4096];sprintf_s (buffer, "%s.sd2",mName.c_str());return (const char*)buffer;}
	/*The end distance of decay region 2.*/
	FloatID getEndDistance2(){char buffer[4096];sprintf_s (buffer, "%s.ed2",mName.c_str());return (const char*)buffer;}
	/*The start distance of decay region 3.*/
	FloatID getStartDistance3(){char buffer[4096];sprintf_s (buffer, "%s.sd3",mName.c_str());return (const char*)buffer;}
	/*The end distance of decay region 3.*/
	FloatID getEndDistance3(){char buffer[4096];sprintf_s (buffer, "%s.ed3",mName.c_str());return (const char*)buffer;}
	/*The fog spread.*/
	FloatID getFogSpread(){char buffer[4096];sprintf_s (buffer, "%s.fsp",mName.c_str());return (const char*)buffer;}
	/*The fog intensity.*/
	FloatID getFogIntensity(){char buffer[4096];sprintf_s (buffer, "%s.fin",mName.c_str());return (const char*)buffer;}
	/*Connect this to the fog geometry.*/
	MessageID getFogGeometry(){char buffer[4096];sprintf_s (buffer, "%s.fg",mName.c_str());return (const char*)buffer;}
	/*Connect this to the light glow.*/
	MessageID getLightGlow(){char buffer[4096];sprintf_s (buffer, "%s.lg",mName.c_str());return (const char*)buffer;}
	/*The number of particle illumination samples*/
	ShortID getPsIllumSamples(){char buffer[4096];sprintf_s (buffer, "%s.pis",mName.c_str());return (const char*)buffer;}
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
	<b>energy</b> is a product of <b>Photon color</b> and <b>Photon intensity</b>
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
	/*Enable mental ray area light attributes for the light.*/
	BoolID getAreaLight(){char buffer[4096];sprintf_s (buffer, "%s.mrc.algt",mName.c_str());return (const char*)buffer;}
	/*Type to determine the shape of the area light.*/
	UnsignedintID getAreaType(){char buffer[4096];sprintf_s (buffer, "%s.mrc.atyp",mName.c_str());return (const char*)buffer;}
	/*Normal vector to control direction of rectangle and disk area lights.*/
	Float3ID getAreaNormal(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ano",mName.c_str());return (const char*)buffer;}
	/*X component of areaNormal*/
	FloatID getAreaNormalX(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ano.anox",mName.c_str());return (const char*)buffer;}
	/*Y component of areaNormal*/
	FloatID getAreaNormalY(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ano.anoy",mName.c_str());return (const char*)buffer;}
	/*Z component of areaNormal*/
	FloatID getAreaNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ano.anoz",mName.c_str());return (const char*)buffer;}
	/*Edge vector to control direction of rectangle and cylinder area lights.*/
	Float3ID getAreaEdge(){char buffer[4096];sprintf_s (buffer, "%s.mrc.aed",mName.c_str());return (const char*)buffer;}
	/*X component of areaEdge*/
	FloatID getAreaEdgeX(){char buffer[4096];sprintf_s (buffer, "%s.mrc.aed.aedx",mName.c_str());return (const char*)buffer;}
	/*Y component of areaEdge*/
	FloatID getAreaEdgeY(){char buffer[4096];sprintf_s (buffer, "%s.mrc.aed.aedy",mName.c_str());return (const char*)buffer;}
	/*Z component of areaEdge*/
	FloatID getAreaEdgeZ(){char buffer[4096];sprintf_s (buffer, "%s.mrc.aed.aedz",mName.c_str());return (const char*)buffer;}
	/*Radius to control size of disk, sphere, and cylinder area lights.*/
	FloatID getAreaRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.arad",mName.c_str());return (const char*)buffer;}
	/*Area light sample values for primary light sampling.*/
	Short2ID getAreaSampling(){char buffer[4096];sprintf_s (buffer, "%s.mrc.asa",mName.c_str());return (const char*)buffer;}
	/*U component of areaSampling*/
	ShortID getAreaSamplingU(){char buffer[4096];sprintf_s (buffer, "%s.mrc.asa.asau",mName.c_str());return (const char*)buffer;}
	/*V component of areaSampling*/
	ShortID getAreaSamplingV(){char buffer[4096];sprintf_s (buffer, "%s.mrc.asa.asav",mName.c_str());return (const char*)buffer;}
	/*Area light tracing level to switch to lower sampling.*/
	ShortID getAreaLowLevel(){char buffer[4096];sprintf_s (buffer, "%s.mrc.alev",mName.c_str());return (const char*)buffer;}
	/*Area light sample values for lower light sampling.*/
	Short2ID getAreaLowSampling(){char buffer[4096];sprintf_s (buffer, "%s.mrc.alo",mName.c_str());return (const char*)buffer;}
	/*U component of areaLowSampling*/
	ShortID getAreaLowSamplingU(){char buffer[4096];sprintf_s (buffer, "%s.mrc.alo.alou",mName.c_str());return (const char*)buffer;}
	/*V component of areaLowSampling*/
	ShortID getAreaLowSamplingV(){char buffer[4096];sprintf_s (buffer, "%s.mrc.alo.alov",mName.c_str());return (const char*)buffer;}
	/*Control primary visibility of the area light shape.*/
	BoolID getAreaVisible(){char buffer[4096];sprintf_s (buffer, "%s.mrc.avis",mName.c_str());return (const char*)buffer;}
protected:
	SpotLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):NonExtendedLightShapeNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SPOTLIGHT_H__
