/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURFEEDBACK_H__
#define __MayaDM_FURFEEDBACK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLocator.h"
namespace MayaDM
{
/*<i>FurFeedback</i> node provides a visual representation of the fur attributes for corresponding fur description.*/
class FurFeedback : public Locator
{
public:
	/*Defines to connect without data flow between individual attractor and attractor set.*/
	struct Attractors{
	};
	/*This is a root of following mental ray attributes.*/
	struct MentalRayControls{
		bool miOverrideCaustics;
		short miCausticAccuracy;
		float miCausticRadius;
		bool miOverrideGlobalIllumination;
		short miGlobillumAccuracy;
		float miGlobillumRadius;
		bool miOverrideFinalGather;
		int miFinalGatherRays;
		float miFinalGatherMinRadius;
		float miFinalGatherMaxRadius;
		short miFinalGatherFilter;
		bool miFinalGatherView;
		bool miOverrideSamples;
		short miMinSamples;
		short miMaxSamples;
		bool miFinalGatherCast;
		bool miFinalGatherReceive;
		bool miTransparencyCast;
		bool miTransparencyReceive;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", miOverrideCaustics);
			fprintf_s(file,"%i ", miCausticAccuracy);
			fprintf_s(file,"%f ", miCausticRadius);
			fprintf_s(file,"%i ", miOverrideGlobalIllumination);
			fprintf_s(file,"%i ", miGlobillumAccuracy);
			fprintf_s(file,"%f ", miGlobillumRadius);
			fprintf_s(file,"%i ", miOverrideFinalGather);
			fprintf_s(file,"%i ", miFinalGatherRays);
			fprintf_s(file,"%f ", miFinalGatherMinRadius);
			fprintf_s(file,"%f ", miFinalGatherMaxRadius);
			fprintf_s(file,"%i ", miFinalGatherFilter);
			fprintf_s(file,"%i ", miFinalGatherView);
			fprintf_s(file,"%i ", miOverrideSamples);
			fprintf_s(file,"%i ", miMinSamples);
			fprintf_s(file,"%i ", miMaxSamples);
			fprintf_s(file,"%i ", miFinalGatherCast);
			fprintf_s(file,"%i ", miFinalGatherReceive);
			fprintf_s(file,"%i ", miTransparencyCast);
			fprintf_s(file,"%i", miTransparencyReceive);
		}
	};
public:
	FurFeedback(FILE* file,const std::string& name,const std::string& parent=""):Locator(file, name, parent, "FurFeedback"){}
	virtual ~FurFeedback(){}
	/*Input surface.*/
	void setInputSurface(const nurbsSurface& is){fprintf_s(mFile, "setAttr \".is\" -type \"nurbsSurface\" ");is.write(mFile);fprintf_s(mFile,";\n");}
	/*Input surface.*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*The input mesh.*/
	void setInputMesh(const mesh& imsh){fprintf_s(mFile, "setAttr \".imsh\" -type \"mesh\" ");imsh.write(mFile);fprintf_s(mFile,";\n");}
	/*The input mesh.*/
	void setInputMesh(const MeshID& imsh){fprintf_s(mFile,"connectAttr \"");imsh.write(mFile);fprintf_s(mFile,"\" \"%s.imsh\";\n",mName.c_str());}
	/*Set the number of U Samples to define how many fur feedback hairs display on the surface.*/
	void setRealUSamples(int rus){if(rus == 32) return; fprintf_s(mFile, "setAttr \".rus\" %i;\n", rus);}
	/*Set the number of U Samples to define how many fur feedback hairs display on the surface.*/
	void setRealUSamples(const IntID& rus){fprintf_s(mFile,"connectAttr \"");rus.write(mFile);fprintf_s(mFile,"\" \"%s.rus\";\n",mName.c_str());}
	/*Set the number of V Samples to define how many fur feedback hairs display on the surface.*/
	void setRealVSamples(int rvs){if(rvs == 32) return; fprintf_s(mFile, "setAttr \".rvs\" %i;\n", rvs);}
	/*Set the number of V Samples to define how many fur feedback hairs display on the surface.*/
	void setRealVSamples(const IntID& rvs){fprintf_s(mFile,"connectAttr \"");rvs.write(mFile);fprintf_s(mFile,"\" \"%s.rvs\";\n",mName.c_str());}
	/*Set the number of U Samples to define how many fur feedback hairs display on the surface.*/
	void setUSamples(int us){if(us == 32) return; fprintf_s(mFile, "setAttr \".us\" %i;\n", us);}
	/*Set the number of U Samples to define how many fur feedback hairs display on the surface.*/
	void setUSamples(const IntID& us){fprintf_s(mFile,"connectAttr \"");us.write(mFile);fprintf_s(mFile,"\" \"%s.us\";\n",mName.c_str());}
	/*Set the number of V Samples to define how many fur feedback hairs display on the surface*/
	void setVSamples(int vs){if(vs == 32) return; fprintf_s(mFile, "setAttr \".vs\" %i;\n", vs);}
	/*Set the number of V Samples to define how many fur feedback hairs display on the surface*/
	void setVSamples(const IntID& vs){fprintf_s(mFile,"connectAttr \"");vs.write(mFile);fprintf_s(mFile,"\" \"%s.vs\";\n",mName.c_str());}
	/*Reverse the fur feedback normal.*/
	void setFlipNormals(bool fn){if(fn == false) return; fprintf_s(mFile, "setAttr \".fn\" %i;\n", fn);}
	/*Reverse the fur feedback normal.*/
	void setFlipNormals(const BoolID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn\";\n",mName.c_str());}
	/*This is used to store hair's vertex information.*/
	void setHairs(const pointArray& h){fprintf_s(mFile, "setAttr \".h\" -type \"pointArray\" ");h.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Set how closely the fur feedback resembles the appearance of the final rendered fur.
	A value of 0 represents the hairs as straight lines, regardless of any curl, scraggle, or attraction.
	A value of 1 uses the same number of segments for each hair in the fur feedback that will be used for the actual render, but significantly slows interaction
	*/
	void setFurAccuracy(float ha){if(ha == 0.0) return; fprintf_s(mFile, "setAttr \".ha\" %f;\n", ha);}
	/*
	Set how closely the fur feedback resembles the appearance of the final rendered fur.
	A value of 0 represents the hairs as straight lines, regardless of any curl, scraggle, or attraction.
	A value of 1 uses the same number of segments for each hair in the fur feedback that will be used for the actual render, but significantly slows interaction
	*/
	void setFurAccuracy(const FloatID& ha){fprintf_s(mFile,"connectAttr \"");ha.write(mFile);fprintf_s(mFile,"\" \"%s.ha\";\n",mName.c_str());}
	/*Define to scale the fur feedback uniformly. This is used to adjust the Base Width, Tip Width, Length, and Offset values by a common factor (including mapped values).*/
	void setFurGlobalScale(float fgs){if(fgs == 1.0) return; fprintf_s(mFile, "setAttr \".fgs\" %f;\n", fgs);}
	/*Define to scale the fur feedback uniformly. This is used to adjust the Base Width, Tip Width, Length, and Offset values by a common factor (including mapped values).*/
	void setFurGlobalScale(const FloatID& fgs){fprintf_s(mFile,"connectAttr \"");fgs.write(mFile);fprintf_s(mFile,"\" \"%s.fgs\";\n",mName.c_str());}
	/*Defines to adjust the Radius, Power, Influence, and Length values by a common factor (including mapped values).*/
	void setAttractorGlobalScale(float ags){if(ags == 1.0) return; fprintf_s(mFile, "setAttr \".ags\" %f;\n", ags);}
	/*Defines to adjust the Radius, Power, Influence, and Length values by a common factor (including mapped values).*/
	void setAttractorGlobalScale(const FloatID& ags){fprintf_s(mFile,"connectAttr \"");ags.write(mFile);fprintf_s(mFile,"\" \"%s.ags\";\n",mName.c_str());}
	/*attribute to export.*/
	void setExportAttr(const string& ea){if(ea == "n/a") return; fprintf_s(mFile, "setAttr \".ea\" -type \"string\" ");ea.write(mFile);fprintf_s(mFile,";\n");}
	/*file to export.*/
	void setExportFile(const string& ef){if(ef == "n/a") return; fprintf_s(mFile, "setAttr \".ef\" -type \"string\" ");ef.write(mFile);fprintf_s(mFile,";\n");}
	/*Set attribute map width.*/
	void setExportWidth(int ew){if(ew == 256) return; fprintf_s(mFile, "setAttr \".ew\" %i;\n", ew);}
	/*Set attribute map width.*/
	void setExportWidth(const IntID& ew){fprintf_s(mFile,"connectAttr \"");ew.write(mFile);fprintf_s(mFile,"\" \"%s.ew\";\n",mName.c_str());}
	/*Set attribute map height.*/
	void setExportHeight(int eh){if(eh == 256) return; fprintf_s(mFile, "setAttr \".eh\" %i;\n", eh);}
	/*Set attribute map height.*/
	void setExportHeight(const IntID& eh){fprintf_s(mFile,"connectAttr \"");eh.write(mFile);fprintf_s(mFile,"\" \"%s.eh\";\n",mName.c_str());}
	/*Sets the color of the fur feedback to be the same as the actual fur color for the fur description.*/
	void setColorFeedbackEnabled(bool cfe){if(cfe == false) return; fprintf_s(mFile, "setAttr \".cfe\" %i;\n", cfe);}
	/*Sets the color of the fur feedback to be the same as the actual fur color for the fur description.*/
	void setColorFeedbackEnabled(const BoolID& cfe){fprintf_s(mFile,"connectAttr \"");cfe.write(mFile);fprintf_s(mFile,"\" \"%s.cfe\";\n",mName.c_str());}
	/*Defines to connect without data flow between individual attractor and attractor set.*/
	void setAttractors(const AttractorsID& atr){fprintf_s(mFile,"connectAttr \"");atr.write(mFile);fprintf_s(mFile,"\" \"%s.atr\";\n",mName.c_str());}
	/*
	Defines the type of attractor.
	0-Local Each hair mimics the closest attractor(s) within the defined radius.
	1-Global Each hair grows towards the closest attractor(s) within the defined radius.
	*/
	void setAttractorModel(unsigned int amd){if(amd == 0) return; fprintf_s(mFile, "setAttr \".amd\" %i;\n", amd);}
	/*
	Defines the type of attractor.
	0-Local Each hair mimics the closest attractor(s) within the defined radius.
	1-Global Each hair grows towards the closest attractor(s) within the defined radius.
	*/
	void setAttractorModel(const UnsignedintID& amd){fprintf_s(mFile,"connectAttr \"");amd.write(mFile);fprintf_s(mFile,"\" \"%s.amd\";\n",mName.c_str());}
	/*
	Defines the number of attractors a hair should be influenced by.
	e.g. 1 Every hair is influenced by one attractor closest to it.
	2 Every hair is influenced by two attractors closest to it.
	3 Every hair is influenced by three attractors closest to it
	*/
	void setAttractorsPerHair(int aph){if(aph == 1) return; fprintf_s(mFile, "setAttr \".aph\" %i;\n", aph);}
	/*
	Defines the number of attractors a hair should be influenced by.
	e.g. 1 Every hair is influenced by one attractor closest to it.
	2 Every hair is influenced by two attractors closest to it.
	3 Every hair is influenced by three attractors closest to it
	*/
	void setAttractorsPerHair(const IntID& aph){fprintf_s(mFile,"connectAttr \"");aph.write(mFile);fprintf_s(mFile,"\" \"%s.aph\";\n",mName.c_str());}
	/*
	true: Display feedback indicating that attractors are attached to the surface.
	false: Don't Display feedback indicating that attractors are attached to the surface.
	*/
	void setDrawAttractors(bool drat){if(drat == false) return; fprintf_s(mFile, "setAttr \".drat\" %i;\n", drat);}
	/*
	true: Display feedback indicating that attractors are attached to the surface.
	false: Don't Display feedback indicating that attractors are attached to the surface.
	*/
	void setDrawAttractors(const BoolID& drat){fprintf_s(mFile,"connectAttr \"");drat.write(mFile);fprintf_s(mFile,"\" \"%s.drat\";\n",mName.c_str());}
	/*Defines the fur feedback length in world units.*/
	void setLength(double dl){if(dl == 1) return; fprintf_s(mFile, "setAttr \".dl\" %f;\n", dl);}
	/*Defines the fur feedback length in world units.*/
	void setLength(const DoubleID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*Used to store fur feedback length samples.*/
	void setLengthSamples(size_t ls_i,double ls){if(ls == 0.0) return; fprintf_s(mFile, "setAttr \".ls[%i]\" %f;\n", ls_i,ls);}
	/*Used to map values for fur feedback attribute "Length" by importing file textures.*/
	void setLengthMap(const string& lm){if(lm == "n/a") return; fprintf_s(mFile, "setAttr \".lm\" -type \"string\" ");lm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setLengthMapOffset(double lmo){if(lmo == 0) return; fprintf_s(mFile, "setAttr \".lmo\" %f;\n", lmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setLengthMapOffset(const DoubleID& lmo){fprintf_s(mFile,"connectAttr \"");lmo.write(mFile);fprintf_s(mFile,"\" \"%s.lmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setLengthMapMult(double lmm){if(lmm == 1) return; fprintf_s(mFile, "setAttr \".lmm\" %f;\n", lmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setLengthMapMult(const DoubleID& lmm){fprintf_s(mFile,"connectAttr \"");lmm.write(mFile);fprintf_s(mFile,"\" \"%s.lmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setLengthNoise(double ln){if(ln == 0) return; fprintf_s(mFile, "setAttr \".ln\" %f;\n", ln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setLengthNoise(const DoubleID& ln){fprintf_s(mFile,"connectAttr \"");ln.write(mFile);fprintf_s(mFile,"\" \"%s.ln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setLengthNoiseFreq(float lnf){if(lnf == 10.0) return; fprintf_s(mFile, "setAttr \".lnf\" %f;\n", lnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setLengthNoiseFreq(const FloatID& lnf){fprintf_s(mFile,"connectAttr \"");lnf.write(mFile);fprintf_s(mFile,"\" \"%s.lnf\";\n",mName.c_str());}
	/*Defines to set length samples dirty*/
	void setLengthSamplesDirty(int lsd){if(lsd == 0.0) return; fprintf_s(mFile, "setAttr \".lsd\" %i;\n", lsd);}
	/*Defines to set length samples dirty*/
	void setLengthSamplesDirty(const IntID& lsd){fprintf_s(mFile,"connectAttr \"");lsd.write(mFile);fprintf_s(mFile,"\" \"%s.lsd\";\n",mName.c_str());}
	/*Defines to set length map dirty*/
	void setLengthMapDirty(int lmd){if(lmd == 0.0) return; fprintf_s(mFile, "setAttr \".lmd\" %i;\n", lmd);}
	/*Defines to set length map dirty*/
	void setLengthMapDirty(const IntID& lmd){fprintf_s(mFile,"connectAttr \"");lmd.write(mFile);fprintf_s(mFile,"\" \"%s.lmd\";\n",mName.c_str());}
	/*
	Sets the amount of fur feedback inclination.
	0.0-No inclination. The fur is fully erect (normal to the surface). This is the default.
	0.5-Partial inclination. 1.0- Fully inclined. The fur lies flat (tangent to the surface at the root).
	*/
	void setInclination(float din){if(din == 0.0) return; fprintf_s(mFile, "setAttr \".din\" %f;\n", din);}
	/*
	Sets the amount of fur feedback inclination.
	0.0-No inclination. The fur is fully erect (normal to the surface). This is the default.
	0.5-Partial inclination. 1.0- Fully inclined. The fur lies flat (tangent to the surface at the root).
	*/
	void setInclination(const FloatID& din){fprintf_s(mFile,"connectAttr \"");din.write(mFile);fprintf_s(mFile,"\" \"%s.din\";\n",mName.c_str());}
	/*Used to store fur feedback inclination samples.*/
	void setInclinationSamples(size_t ins_i,double ins){if(ins == 0.0) return; fprintf_s(mFile, "setAttr \".ins[%i]\" %f;\n", ins_i,ins);}
	/*Used to map values for fur feedback attribute "Inclination" by importing file textures.*/
	void setInclinationMap(const string& inm){if(inm == "n/a") return; fprintf_s(mFile, "setAttr \".inm\" -type \"string\" ");inm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setInclinationMapOffset(float inmo){if(inmo == 0.0) return; fprintf_s(mFile, "setAttr \".inmo\" %f;\n", inmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setInclinationMapOffset(const FloatID& inmo){fprintf_s(mFile,"connectAttr \"");inmo.write(mFile);fprintf_s(mFile,"\" \"%s.inmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setInclinationMapMult(float inmm){if(inmm == 1.0) return; fprintf_s(mFile, "setAttr \".inmm\" %f;\n", inmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setInclinationMapMult(const FloatID& inmm){fprintf_s(mFile,"connectAttr \"");inmm.write(mFile);fprintf_s(mFile,"\" \"%s.inmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setInclinationNoise(float inn){if(inn == 0.0) return; fprintf_s(mFile, "setAttr \".inn\" %f;\n", inn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setInclinationNoise(const FloatID& inn){fprintf_s(mFile,"connectAttr \"");inn.write(mFile);fprintf_s(mFile,"\" \"%s.inn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setInclinationNoiseFreq(float innf){if(innf == 10.0) return; fprintf_s(mFile, "setAttr \".innf\" %f;\n", innf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setInclinationNoiseFreq(const FloatID& innf){fprintf_s(mFile,"connectAttr \"");innf.write(mFile);fprintf_s(mFile,"\" \"%s.innf\";\n",mName.c_str());}
	/*Defines to set inclination samples dirty*/
	void setInclinationSamplesDirty(int insd){if(insd == 0.0) return; fprintf_s(mFile, "setAttr \".insd\" %i;\n", insd);}
	/*Defines to set inclination samples dirty*/
	void setInclinationSamplesDirty(const IntID& insd){fprintf_s(mFile,"connectAttr \"");insd.write(mFile);fprintf_s(mFile,"\" \"%s.insd\";\n",mName.c_str());}
	/*Defines to set inclination map dirty*/
	void setInclinationMapDirty(int inmd){if(inmd == 0.0) return; fprintf_s(mFile, "setAttr \".inmd\" %i;\n", inmd);}
	/*Defines to set inclination map dirty*/
	void setInclinationMapDirty(const IntID& inmd){fprintf_s(mFile,"connectAttr \"");inmd.write(mFile);fprintf_s(mFile,"\" \"%s.inmd\";\n",mName.c_str());}
	/*
	Rotates the fur feedback about the surface V axis. You can achieve almost any fur feedback angle using Polar and Inclination, so use this option only when the fur feedback has curl and you want the curls to lie flat.
	0.0-90 degree rotation. 0.5-No rotation. This is the default.1.0-90 degree rotation.
	*/
	void setRoll(float drl){if(drl == 0.5) return; fprintf_s(mFile, "setAttr \".drl\" %f;\n", drl);}
	/*
	Rotates the fur feedback about the surface V axis. You can achieve almost any fur feedback angle using Polar and Inclination, so use this option only when the fur feedback has curl and you want the curls to lie flat.
	0.0-90 degree rotation. 0.5-No rotation. This is the default.1.0-90 degree rotation.
	*/
	void setRoll(const FloatID& drl){fprintf_s(mFile,"connectAttr \"");drl.write(mFile);fprintf_s(mFile,"\" \"%s.drl\";\n",mName.c_str());}
	/*Used to store fur feedback roll samples.*/
	void setRollSamples(size_t rls_i,double rls){if(rls == 0.0) return; fprintf_s(mFile, "setAttr \".rls[%i]\" %f;\n", rls_i,rls);}
	/*Used to map values for fur feedback attribute "Roll" by importing file textures.*/
	void setRollMap(const string& rlm){if(rlm == "n/a") return; fprintf_s(mFile, "setAttr \".rlm\" -type \"string\" ");rlm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setRollMapOffset(float rlmo){if(rlmo == 0.0) return; fprintf_s(mFile, "setAttr \".rlmo\" %f;\n", rlmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setRollMapOffset(const FloatID& rlmo){fprintf_s(mFile,"connectAttr \"");rlmo.write(mFile);fprintf_s(mFile,"\" \"%s.rlmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setRollMapMult(float rlmm){if(rlmm == 1.0) return; fprintf_s(mFile, "setAttr \".rlmm\" %f;\n", rlmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setRollMapMult(const FloatID& rlmm){fprintf_s(mFile,"connectAttr \"");rlmm.write(mFile);fprintf_s(mFile,"\" \"%s.rlmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setRollNoise(float rln){if(rln == 0.0) return; fprintf_s(mFile, "setAttr \".rln\" %f;\n", rln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setRollNoise(const FloatID& rln){fprintf_s(mFile,"connectAttr \"");rln.write(mFile);fprintf_s(mFile,"\" \"%s.rln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setRollNoiseFreq(float rlnf){if(rlnf == 10.0) return; fprintf_s(mFile, "setAttr \".rlnf\" %f;\n", rlnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setRollNoiseFreq(const FloatID& rlnf){fprintf_s(mFile,"connectAttr \"");rlnf.write(mFile);fprintf_s(mFile,"\" \"%s.rlnf\";\n",mName.c_str());}
	/*Defines to set roll samples dirty*/
	void setRollSamplesDirty(int rlsd){if(rlsd == 0.0) return; fprintf_s(mFile, "setAttr \".rlsd\" %i;\n", rlsd);}
	/*Defines to set roll samples dirty*/
	void setRollSamplesDirty(const IntID& rlsd){fprintf_s(mFile,"connectAttr \"");rlsd.write(mFile);fprintf_s(mFile,"\" \"%s.rlsd\";\n",mName.c_str());}
	/*Defines to set roll map dirty*/
	void setRollMapDirty(int rlmd){if(rlmd == 0.0) return; fprintf_s(mFile, "setAttr \".rlmd\" %i;\n", rlmd);}
	/*Defines to set roll map dirty*/
	void setRollMapDirty(const IntID& rlmd){fprintf_s(mFile,"connectAttr \"");rlmd.write(mFile);fprintf_s(mFile,"\" \"%s.rlmd\";\n",mName.c_str());}
	/*
	Rotates the fur feedback about the surface normal.
	0.0-180 degree rotation. 0.5-No rotation. This is the default. 1.0-180 degree rotation.
	*/
	void setPolar(float dpo){if(dpo == 0.5) return; fprintf_s(mFile, "setAttr \".dpo\" %f;\n", dpo);}
	/*
	Rotates the fur feedback about the surface normal.
	0.0-180 degree rotation. 0.5-No rotation. This is the default. 1.0-180 degree rotation.
	*/
	void setPolar(const FloatID& dpo){fprintf_s(mFile,"connectAttr \"");dpo.write(mFile);fprintf_s(mFile,"\" \"%s.dpo\";\n",mName.c_str());}
	/*Used to store fur feedback polar samples.*/
	void setPolarSamples(size_t pos_i,double pos){if(pos == 0.0) return; fprintf_s(mFile, "setAttr \".pos[%i]\" %f;\n", pos_i,pos);}
	/*Used to map values for fur feedback attribute "Polar" by importing file textures.*/
	void setPolarMap(const string& pom){if(pom == "n/a") return; fprintf_s(mFile, "setAttr \".pom\" -type \"string\" ");pom.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setPolarMapOffset(float pomo){if(pomo == 0.0) return; fprintf_s(mFile, "setAttr \".pomo\" %f;\n", pomo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setPolarMapOffset(const FloatID& pomo){fprintf_s(mFile,"connectAttr \"");pomo.write(mFile);fprintf_s(mFile,"\" \"%s.pomo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setPolarMapMult(float pomm){if(pomm == 1.0) return; fprintf_s(mFile, "setAttr \".pomm\" %f;\n", pomm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setPolarMapMult(const FloatID& pomm){fprintf_s(mFile,"connectAttr \"");pomm.write(mFile);fprintf_s(mFile,"\" \"%s.pomm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setPolarNoise(float pon){if(pon == 0.0) return; fprintf_s(mFile, "setAttr \".pon\" %f;\n", pon);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setPolarNoise(const FloatID& pon){fprintf_s(mFile,"connectAttr \"");pon.write(mFile);fprintf_s(mFile,"\" \"%s.pon\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setPolarNoiseFreq(float ponf){if(ponf == 10.0) return; fprintf_s(mFile, "setAttr \".ponf\" %f;\n", ponf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setPolarNoiseFreq(const FloatID& ponf){fprintf_s(mFile,"connectAttr \"");ponf.write(mFile);fprintf_s(mFile,"\" \"%s.ponf\";\n",mName.c_str());}
	/*Defines to set polar samples dirty*/
	void setPolarSamplesDirty(int posd){if(posd == 0.0) return; fprintf_s(mFile, "setAttr \".posd\" %i;\n", posd);}
	/*Defines to set polar samples dirty*/
	void setPolarSamplesDirty(const IntID& posd){fprintf_s(mFile,"connectAttr \"");posd.write(mFile);fprintf_s(mFile,"\" \"%s.posd\";\n",mName.c_str());}
	/*Defines to set polar map dirty*/
	void setPolarMapDirty(int pomd){if(pomd == 0.0) return; fprintf_s(mFile, "setAttr \".pomd\" %i;\n", pomd);}
	/*Defines to set polar map dirty*/
	void setPolarMapDirty(const IntID& pomd){fprintf_s(mFile,"connectAttr \"");pomd.write(mFile);fprintf_s(mFile,"\" \"%s.pomd\";\n",mName.c_str());}
	/*
	Defines how much fur feedback is on the surface.
	1.0-Full fur 0.0-Total baldness.
	*/
	void setBaldness(float db){if(db == 1.0) return; fprintf_s(mFile, "setAttr \".db\" %f;\n", db);}
	/*
	Defines how much fur feedback is on the surface.
	1.0-Full fur 0.0-Total baldness.
	*/
	void setBaldness(const FloatID& db){fprintf_s(mFile,"connectAttr \"");db.write(mFile);fprintf_s(mFile,"\" \"%s.db\";\n",mName.c_str());}
	/*Used to store fur feedback baldness samples.*/
	void setBaldnessSamples(size_t bs_i,double bs){if(bs == 0.0) return; fprintf_s(mFile, "setAttr \".bs[%i]\" %f;\n", bs_i,bs);}
	/*Used to map values for fur feedback attribute "Baldness" by importing file textures.*/
	void setBaldnessMap(const string& bm){if(bm == "n/a") return; fprintf_s(mFile, "setAttr \".bm\" -type \"string\" ");bm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setBaldnessMapOffset(float bmo){if(bmo == 0.0) return; fprintf_s(mFile, "setAttr \".bmo\" %f;\n", bmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setBaldnessMapOffset(const FloatID& bmo){fprintf_s(mFile,"connectAttr \"");bmo.write(mFile);fprintf_s(mFile,"\" \"%s.bmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaldnessMapMult(float bmm){if(bmm == 1.0) return; fprintf_s(mFile, "setAttr \".bmm\" %f;\n", bmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaldnessMapMult(const FloatID& bmm){fprintf_s(mFile,"connectAttr \"");bmm.write(mFile);fprintf_s(mFile,"\" \"%s.bmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaldnessNoise(float bn){if(bn == 0.0) return; fprintf_s(mFile, "setAttr \".bn\" %f;\n", bn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaldnessNoise(const FloatID& bn){fprintf_s(mFile,"connectAttr \"");bn.write(mFile);fprintf_s(mFile,"\" \"%s.bn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaldnessNoiseFreq(float bnf){if(bnf == 10.0) return; fprintf_s(mFile, "setAttr \".bnf\" %f;\n", bnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaldnessNoiseFreq(const FloatID& bnf){fprintf_s(mFile,"connectAttr \"");bnf.write(mFile);fprintf_s(mFile,"\" \"%s.bnf\";\n",mName.c_str());}
	/*Defines to set baldness samples dirty*/
	void setBaldnessSamplesDirty(int bsd){if(bsd == 0.0) return; fprintf_s(mFile, "setAttr \".bsd\" %i;\n", bsd);}
	/*Defines to set baldness samples dirty*/
	void setBaldnessSamplesDirty(const IntID& bsd){fprintf_s(mFile,"connectAttr \"");bsd.write(mFile);fprintf_s(mFile,"\" \"%s.bsd\";\n",mName.c_str());}
	/*Defines to set baldness map dirty*/
	void setBaldnessMapDirty(int bmd){if(bmd == 0.0) return; fprintf_s(mFile, "setAttr \".bmd\" %i;\n", bmd);}
	/*Defines to set baldness map dirty*/
	void setBaldnessMapDirty(const IntID& bmd){fprintf_s(mFile,"connectAttr \"");bmd.write(mFile);fprintf_s(mFile,"\" \"%s.bmd\";\n",mName.c_str());}
	/*
	Defines the opacity of the fur feedback base.
	0.0-Completely transparent base. 1.0-Completely opaque base.
	*/
	void setBaseOpacity(float dbo){if(dbo == 1.0) return; fprintf_s(mFile, "setAttr \".dbo\" %f;\n", dbo);}
	/*
	Defines the opacity of the fur feedback base.
	0.0-Completely transparent base. 1.0-Completely opaque base.
	*/
	void setBaseOpacity(const FloatID& dbo){fprintf_s(mFile,"connectAttr \"");dbo.write(mFile);fprintf_s(mFile,"\" \"%s.dbo\";\n",mName.c_str());}
	/*Used to store fur feedback base opacity samples.*/
	void setBaseOpacitySamples(size_t bos_i,double bos){if(bos == 0.0) return; fprintf_s(mFile, "setAttr \".bos[%i]\" %f;\n", bos_i,bos);}
	/*Used to map values for fur feedback attribute "BaseOpacity" by importing file textures.*/
	void setBaseOpacityMap(const string& bom){if(bom == "n/a") return; fprintf_s(mFile, "setAttr \".bom\" -type \"string\" ");bom.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setBaseOpacityMapOffset(float bomo){if(bomo == 0.0) return; fprintf_s(mFile, "setAttr \".bomo\" %f;\n", bomo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setBaseOpacityMapOffset(const FloatID& bomo){fprintf_s(mFile,"connectAttr \"");bomo.write(mFile);fprintf_s(mFile,"\" \"%s.bomo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseOpacityMapMult(float bomm){if(bomm == 1.0) return; fprintf_s(mFile, "setAttr \".bomm\" %f;\n", bomm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseOpacityMapMult(const FloatID& bomm){fprintf_s(mFile,"connectAttr \"");bomm.write(mFile);fprintf_s(mFile,"\" \"%s.bomm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseOpacityNoise(float bon){if(bon == 0.0) return; fprintf_s(mFile, "setAttr \".bon\" %f;\n", bon);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseOpacityNoise(const FloatID& bon){fprintf_s(mFile,"connectAttr \"");bon.write(mFile);fprintf_s(mFile,"\" \"%s.bon\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseOpacityNoiseFreq(float bonf){if(bonf == 10.0) return; fprintf_s(mFile, "setAttr \".bonf\" %f;\n", bonf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseOpacityNoiseFreq(const FloatID& bonf){fprintf_s(mFile,"connectAttr \"");bonf.write(mFile);fprintf_s(mFile,"\" \"%s.bonf\";\n",mName.c_str());}
	/*Defines to set base opacity samples dirty*/
	void setBaseOpacitySamplesDirty(int bosd){if(bosd == 0.0) return; fprintf_s(mFile, "setAttr \".bosd\" %i;\n", bosd);}
	/*Defines to set base opacity samples dirty*/
	void setBaseOpacitySamplesDirty(const IntID& bosd){fprintf_s(mFile,"connectAttr \"");bosd.write(mFile);fprintf_s(mFile,"\" \"%s.bosd\";\n",mName.c_str());}
	/*Defines to set base opacity map dirty*/
	void setBaseOpacityMapDirty(int bomd){if(bomd == 0.0) return; fprintf_s(mFile, "setAttr \".bomd\" %i;\n", bomd);}
	/*Defines to set base opacity map dirty*/
	void setBaseOpacityMapDirty(const IntID& bomd){fprintf_s(mFile,"connectAttr \"");bomd.write(mFile);fprintf_s(mFile,"\" \"%s.bomd\";\n",mName.c_str());}
	/*
	Defines the opacity of the fur feedback tip.
	0.0-Completely transparent tip. 1.0-Completely opaque tip.
	*/
	void setTipOpacity(float dto){if(dto == 1.0) return; fprintf_s(mFile, "setAttr \".dto\" %f;\n", dto);}
	/*
	Defines the opacity of the fur feedback tip.
	0.0-Completely transparent tip. 1.0-Completely opaque tip.
	*/
	void setTipOpacity(const FloatID& dto){fprintf_s(mFile,"connectAttr \"");dto.write(mFile);fprintf_s(mFile,"\" \"%s.dto\";\n",mName.c_str());}
	/*Used to store fur feedback tip opacity samples.*/
	void setTipOpacitySamples(size_t tos_i,double tos){if(tos == 0.0) return; fprintf_s(mFile, "setAttr \".tos[%i]\" %f;\n", tos_i,tos);}
	/*Used to map values for fur feedback attribute "TipOpacity" by importing file textures.*/
	void setTipOpacityMap(const string& tom){if(tom == "n/a") return; fprintf_s(mFile, "setAttr \".tom\" -type \"string\" ");tom.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setTipOpacityMapOffset(float tomo){if(tomo == 0.0) return; fprintf_s(mFile, "setAttr \".tomo\" %f;\n", tomo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setTipOpacityMapOffset(const FloatID& tomo){fprintf_s(mFile,"connectAttr \"");tomo.write(mFile);fprintf_s(mFile,"\" \"%s.tomo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipOpacityMapMult(float tomm){if(tomm == 1.0) return; fprintf_s(mFile, "setAttr \".tomm\" %f;\n", tomm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipOpacityMapMult(const FloatID& tomm){fprintf_s(mFile,"connectAttr \"");tomm.write(mFile);fprintf_s(mFile,"\" \"%s.tomm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipOpacityNoise(float ton){if(ton == 0.0) return; fprintf_s(mFile, "setAttr \".ton\" %f;\n", ton);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipOpacityNoise(const FloatID& ton){fprintf_s(mFile,"connectAttr \"");ton.write(mFile);fprintf_s(mFile,"\" \"%s.ton\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipOpacityNoiseFreq(float tonf){if(tonf == 10.0) return; fprintf_s(mFile, "setAttr \".tonf\" %f;\n", tonf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipOpacityNoiseFreq(const FloatID& tonf){fprintf_s(mFile,"connectAttr \"");tonf.write(mFile);fprintf_s(mFile,"\" \"%s.tonf\";\n",mName.c_str());}
	/*Defines to set tip opacity samples dirty*/
	void setTipOpacitySamplesDirty(int tosd){if(tosd == 0.0) return; fprintf_s(mFile, "setAttr \".tosd\" %i;\n", tosd);}
	/*Defines to set tip opacity samples dirty*/
	void setTipOpacitySamplesDirty(const IntID& tosd){fprintf_s(mFile,"connectAttr \"");tosd.write(mFile);fprintf_s(mFile,"\" \"%s.tosd\";\n",mName.c_str());}
	/*Defines to set tip opacity map dirty*/
	void setTipOpacityMapDirty(int tomd){if(tomd == 0.0) return; fprintf_s(mFile, "setAttr \".tomd\" %i;\n", tomd);}
	/*Defines to set tip opacity map dirty*/
	void setTipOpacityMapDirty(const IntID& tomd){fprintf_s(mFile,"connectAttr \"");tomd.write(mFile);fprintf_s(mFile,"\" \"%s.tomd\";\n",mName.c_str());}
	/*
	Defines the amount of curl at the base of the fur feedback. The fur feedback tip is not influenced by this value.
	0.0- Half-circle curl to one side. 0.5-No curl. 1.0-Half-circle curl to the other side.
	*/
	void setBaseCurl(float dbcl){if(dbcl == 0.50) return; fprintf_s(mFile, "setAttr \".dbcl\" %f;\n", dbcl);}
	/*
	Defines the amount of curl at the base of the fur feedback. The fur feedback tip is not influenced by this value.
	0.0- Half-circle curl to one side. 0.5-No curl. 1.0-Half-circle curl to the other side.
	*/
	void setBaseCurl(const FloatID& dbcl){fprintf_s(mFile,"connectAttr \"");dbcl.write(mFile);fprintf_s(mFile,"\" \"%s.dbcl\";\n",mName.c_str());}
	/*Used to store fur feedback base curl samples.*/
	void setBaseCurlSamples(size_t bcls_i,double bcls){if(bcls == 0.0) return; fprintf_s(mFile, "setAttr \".bcls[%i]\" %f;\n", bcls_i,bcls);}
	/*Used to map values for fur feedback attribute "BaseCurl" by importing file textures.*/
	void setBaseCurlMap(const string& bclm){if(bclm == "n/a") return; fprintf_s(mFile, "setAttr \".bclm\" -type \"string\" ");bclm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setBaseCurlMapOffset(float bclmo){if(bclmo == 0.0) return; fprintf_s(mFile, "setAttr \".bclmo\" %f;\n", bclmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setBaseCurlMapOffset(const FloatID& bclmo){fprintf_s(mFile,"connectAttr \"");bclmo.write(mFile);fprintf_s(mFile,"\" \"%s.bclmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseCurlMapMult(float bclmm){if(bclmm == 1.0) return; fprintf_s(mFile, "setAttr \".bclmm\" %f;\n", bclmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseCurlMapMult(const FloatID& bclmm){fprintf_s(mFile,"connectAttr \"");bclmm.write(mFile);fprintf_s(mFile,"\" \"%s.bclmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseCurlNoise(float bcln){if(bcln == 0.0) return; fprintf_s(mFile, "setAttr \".bcln\" %f;\n", bcln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseCurlNoise(const FloatID& bcln){fprintf_s(mFile,"connectAttr \"");bcln.write(mFile);fprintf_s(mFile,"\" \"%s.bcln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseCurlNoiseFreq(float bclnf){if(bclnf == 10.0) return; fprintf_s(mFile, "setAttr \".bclnf\" %f;\n", bclnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseCurlNoiseFreq(const FloatID& bclnf){fprintf_s(mFile,"connectAttr \"");bclnf.write(mFile);fprintf_s(mFile,"\" \"%s.bclnf\";\n",mName.c_str());}
	/*Defines to set base curl samples dirty*/
	void setBaseCurlSamplesDirty(int bclsd){if(bclsd == 0.0) return; fprintf_s(mFile, "setAttr \".bclsd\" %i;\n", bclsd);}
	/*Defines to set base curl samples dirty*/
	void setBaseCurlSamplesDirty(const IntID& bclsd){fprintf_s(mFile,"connectAttr \"");bclsd.write(mFile);fprintf_s(mFile,"\" \"%s.bclsd\";\n",mName.c_str());}
	/*Defines to set base curl map dirty*/
	void setBaseCurlMapDirty(int bclmd){if(bclmd == 0.0) return; fprintf_s(mFile, "setAttr \".bclmd\" %i;\n", bclmd);}
	/*Defines to set base curl map dirty*/
	void setBaseCurlMapDirty(const IntID& bclmd){fprintf_s(mFile,"connectAttr \"");bclmd.write(mFile);fprintf_s(mFile,"\" \"%s.bclmd\";\n",mName.c_str());}
	/*
	Defines the amount of curl at the tip of the fur feedback. The fur feedback base is not influenced by this value.
	0.0-Half-circle curl to one side. 0.5-No curl. 1.0- Half-circle curl to the other side
	*/
	void setTipCurl(float dtcl){if(dtcl == 0.5) return; fprintf_s(mFile, "setAttr \".dtcl\" %f;\n", dtcl);}
	/*
	Defines the amount of curl at the tip of the fur feedback. The fur feedback base is not influenced by this value.
	0.0-Half-circle curl to one side. 0.5-No curl. 1.0- Half-circle curl to the other side
	*/
	void setTipCurl(const FloatID& dtcl){fprintf_s(mFile,"connectAttr \"");dtcl.write(mFile);fprintf_s(mFile,"\" \"%s.dtcl\";\n",mName.c_str());}
	/*Used to store fur feedback tip curl samples.*/
	void setTipCurlSamples(size_t tcls_i,double tcls){if(tcls == 0.0) return; fprintf_s(mFile, "setAttr \".tcls[%i]\" %f;\n", tcls_i,tcls);}
	/*Used to map values for fur feedback attribute "TipCurl" by importing file textures.*/
	void setTipCurlMap(const string& tclm){if(tclm == "n/a") return; fprintf_s(mFile, "setAttr \".tclm\" -type \"string\" ");tclm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setTipCurlMapOffset(float tclmo){if(tclmo == 0.0) return; fprintf_s(mFile, "setAttr \".tclmo\" %f;\n", tclmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setTipCurlMapOffset(const FloatID& tclmo){fprintf_s(mFile,"connectAttr \"");tclmo.write(mFile);fprintf_s(mFile,"\" \"%s.tclmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipCurlMapMult(float tclmm){if(tclmm == 1.0) return; fprintf_s(mFile, "setAttr \".tclmm\" %f;\n", tclmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipCurlMapMult(const FloatID& tclmm){fprintf_s(mFile,"connectAttr \"");tclmm.write(mFile);fprintf_s(mFile,"\" \"%s.tclmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipCurlNoise(float tcln){if(tcln == 0.0) return; fprintf_s(mFile, "setAttr \".tcln\" %f;\n", tcln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipCurlNoise(const FloatID& tcln){fprintf_s(mFile,"connectAttr \"");tcln.write(mFile);fprintf_s(mFile,"\" \"%s.tcln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipCurlNoiseFreq(float tclnf){if(tclnf == 10.0) return; fprintf_s(mFile, "setAttr \".tclnf\" %f;\n", tclnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipCurlNoiseFreq(const FloatID& tclnf){fprintf_s(mFile,"connectAttr \"");tclnf.write(mFile);fprintf_s(mFile,"\" \"%s.tclnf\";\n",mName.c_str());}
	/*Defines to set tip curl samples dirty*/
	void setTipCurlSamplesDirty(int tclsd){if(tclsd == 0.0) return; fprintf_s(mFile, "setAttr \".tclsd\" %i;\n", tclsd);}
	/*Defines to set tip curl samples dirty*/
	void setTipCurlSamplesDirty(const IntID& tclsd){fprintf_s(mFile,"connectAttr \"");tclsd.write(mFile);fprintf_s(mFile,"\" \"%s.tclsd\";\n",mName.c_str());}
	/*Defines to set tip curl map dirty*/
	void setTipCurlMapDirty(int tclmd){if(tclmd == 0.0) return; fprintf_s(mFile, "setAttr \".tclmd\" %i;\n", tclmd);}
	/*Defines to set tip curl map dirty*/
	void setTipCurlMapDirty(const IntID& tclmd){fprintf_s(mFile,"connectAttr \"");tclmd.write(mFile);fprintf_s(mFile,"\" \"%s.tclmd\";\n",mName.c_str());}
	/*Defines the width of each hair feedback at the base, in world units.*/
	void setBaseWidth(double dbw){if(dbw == 0) return; fprintf_s(mFile, "setAttr \".dbw\" %f;\n", dbw);}
	/*Defines the width of each hair feedback at the base, in world units.*/
	void setBaseWidth(const DoubleID& dbw){fprintf_s(mFile,"connectAttr \"");dbw.write(mFile);fprintf_s(mFile,"\" \"%s.dbw\";\n",mName.c_str());}
	/*Used to store fur feedback base width samples.*/
	void setBaseWidthSamples(size_t bws_i,double bws){if(bws == 0.0) return; fprintf_s(mFile, "setAttr \".bws[%i]\" %f;\n", bws_i,bws);}
	/*Used to map values for fur feedback attribute "BaseWidth" by importing file textures.*/
	void setBaseWidthMap(const string& bwm){if(bwm == "n/a") return; fprintf_s(mFile, "setAttr \".bwm\" -type \"string\" ");bwm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setBaseWidthMapOffset(double bwmo){if(bwmo == 0) return; fprintf_s(mFile, "setAttr \".bwmo\" %f;\n", bwmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setBaseWidthMapOffset(const DoubleID& bwmo){fprintf_s(mFile,"connectAttr \"");bwmo.write(mFile);fprintf_s(mFile,"\" \"%s.bwmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseWidthMapMult(double bwmm){if(bwmm == 1) return; fprintf_s(mFile, "setAttr \".bwmm\" %f;\n", bwmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseWidthMapMult(const DoubleID& bwmm){fprintf_s(mFile,"connectAttr \"");bwmm.write(mFile);fprintf_s(mFile,"\" \"%s.bwmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseWidthNoise(double bwn){if(bwn == 0) return; fprintf_s(mFile, "setAttr \".bwn\" %f;\n", bwn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseWidthNoise(const DoubleID& bwn){fprintf_s(mFile,"connectAttr \"");bwn.write(mFile);fprintf_s(mFile,"\" \"%s.bwn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseWidthNoiseFreq(float bwnf){if(bwnf == 10.0) return; fprintf_s(mFile, "setAttr \".bwnf\" %f;\n", bwnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseWidthNoiseFreq(const FloatID& bwnf){fprintf_s(mFile,"connectAttr \"");bwnf.write(mFile);fprintf_s(mFile,"\" \"%s.bwnf\";\n",mName.c_str());}
	/*Defines to set base width samples dirty*/
	void setBaseWidthSamplesDirty(int bwsd){if(bwsd == 0.0) return; fprintf_s(mFile, "setAttr \".bwsd\" %i;\n", bwsd);}
	/*Defines to set base width samples dirty*/
	void setBaseWidthSamplesDirty(const IntID& bwsd){fprintf_s(mFile,"connectAttr \"");bwsd.write(mFile);fprintf_s(mFile,"\" \"%s.bwsd\";\n",mName.c_str());}
	/*Defines to set base width map dirty*/
	void setBaseWidthMapDirty(int bwmd){if(bwmd == 0.0) return; fprintf_s(mFile, "setAttr \".bwmd\" %i;\n", bwmd);}
	/*Defines to set base width map dirty*/
	void setBaseWidthMapDirty(const IntID& bwmd){fprintf_s(mFile,"connectAttr \"");bwmd.write(mFile);fprintf_s(mFile,"\" \"%s.bwmd\";\n",mName.c_str());}
	/*Defines the width of each hair feedback at the tip, in world units.*/
	void setTipWidth(double dtw){if(dtw == 0) return; fprintf_s(mFile, "setAttr \".dtw\" %f;\n", dtw);}
	/*Defines the width of each hair feedback at the tip, in world units.*/
	void setTipWidth(const DoubleID& dtw){fprintf_s(mFile,"connectAttr \"");dtw.write(mFile);fprintf_s(mFile,"\" \"%s.dtw\";\n",mName.c_str());}
	/*Used to store fur feedback tip width samples.*/
	void setTipWidthSamples(size_t tws_i,double tws){if(tws == 0.0) return; fprintf_s(mFile, "setAttr \".tws[%i]\" %f;\n", tws_i,tws);}
	/*Used to map values for fur feedback attribute "TipWidth" by importing file textures.*/
	void setTipWidthMap(const string& twm){if(twm == "n/a") return; fprintf_s(mFile, "setAttr \".twm\" -type \"string\" ");twm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setTipWidthMapOffset(double twmo){if(twmo == 0) return; fprintf_s(mFile, "setAttr \".twmo\" %f;\n", twmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setTipWidthMapOffset(const DoubleID& twmo){fprintf_s(mFile,"connectAttr \"");twmo.write(mFile);fprintf_s(mFile,"\" \"%s.twmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipWidthMapMult(double twmm){if(twmm == 1) return; fprintf_s(mFile, "setAttr \".twmm\" %f;\n", twmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipWidthMapMult(const DoubleID& twmm){fprintf_s(mFile,"connectAttr \"");twmm.write(mFile);fprintf_s(mFile,"\" \"%s.twmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipWidthNoise(double twn){if(twn == 0) return; fprintf_s(mFile, "setAttr \".twn\" %f;\n", twn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipWidthNoise(const DoubleID& twn){fprintf_s(mFile,"connectAttr \"");twn.write(mFile);fprintf_s(mFile,"\" \"%s.twn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipWidthNoiseFreq(float twnf){if(twnf == 10.0) return; fprintf_s(mFile, "setAttr \".twnf\" %f;\n", twnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipWidthNoiseFreq(const FloatID& twnf){fprintf_s(mFile,"connectAttr \"");twnf.write(mFile);fprintf_s(mFile,"\" \"%s.twnf\";\n",mName.c_str());}
	/*Defines to set tip width samples dirty*/
	void setTipWidthSamplesDirty(int twsd){if(twsd == 0.0) return; fprintf_s(mFile, "setAttr \".twsd\" %i;\n", twsd);}
	/*Defines to set tip width samples dirty*/
	void setTipWidthSamplesDirty(const IntID& twsd){fprintf_s(mFile,"connectAttr \"");twsd.write(mFile);fprintf_s(mFile,"\" \"%s.twsd\";\n",mName.c_str());}
	/*Defines to set tip width map dirty*/
	void setTipWidthMapDirty(int twmd){if(twmd == 0.0) return; fprintf_s(mFile, "setAttr \".twmd\" %i;\n", twmd);}
	/*Defines to set tip width map dirty*/
	void setTipWidthMapDirty(const IntID& twmd){fprintf_s(mFile,"connectAttr \"");twmd.write(mFile);fprintf_s(mFile,"\" \"%s.twmd\";\n",mName.c_str());}
	/*
	Defines how crooked the fur feedback is.
	0.0-No scraggle. 1.0-Full scraggle.
	*/
	void setScraggle(float ds){if(ds == 0.0) return; fprintf_s(mFile, "setAttr \".ds\" %f;\n", ds);}
	/*
	Defines how crooked the fur feedback is.
	0.0-No scraggle. 1.0-Full scraggle.
	*/
	void setScraggle(const FloatID& ds){fprintf_s(mFile,"connectAttr \"");ds.write(mFile);fprintf_s(mFile,"\" \"%s.ds\";\n",mName.c_str());}
	/*Used to store fur feedback scraggle samples.*/
	void setScraggleSamples(size_t ss_i,double ss){if(ss == 0.0) return; fprintf_s(mFile, "setAttr \".ss[%i]\" %f;\n", ss_i,ss);}
	/*Used to map values for fur feedback attribute "Scraggle" by importing file textures.*/
	void setScraggleMap(const string& sm){if(sm == "n/a") return; fprintf_s(mFile, "setAttr \".sm\" -type \"string\" ");sm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setScraggleMapOffset(float smo){if(smo == 0.0) return; fprintf_s(mFile, "setAttr \".smo\" %f;\n", smo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setScraggleMapOffset(const FloatID& smo){fprintf_s(mFile,"connectAttr \"");smo.write(mFile);fprintf_s(mFile,"\" \"%s.smo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleMapMult(float smm){if(smm == 1.0) return; fprintf_s(mFile, "setAttr \".smm\" %f;\n", smm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleMapMult(const FloatID& smm){fprintf_s(mFile,"connectAttr \"");smm.write(mFile);fprintf_s(mFile,"\" \"%s.smm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleNoise(float sn){if(sn == 0.0) return; fprintf_s(mFile, "setAttr \".sn\" %f;\n", sn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleNoise(const FloatID& sn){fprintf_s(mFile,"connectAttr \"");sn.write(mFile);fprintf_s(mFile,"\" \"%s.sn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setScraggleNoiseFreq(float snf){if(snf == 10.0) return; fprintf_s(mFile, "setAttr \".snf\" %f;\n", snf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setScraggleNoiseFreq(const FloatID& snf){fprintf_s(mFile,"connectAttr \"");snf.write(mFile);fprintf_s(mFile,"\" \"%s.snf\";\n",mName.c_str());}
	/*Defines to set scraggle samples dirty*/
	void setScraggleSamplesDirty(int ssd){if(ssd == 0.0) return; fprintf_s(mFile, "setAttr \".ssd\" %i;\n", ssd);}
	/*Defines to set scraggle samples dirty*/
	void setScraggleSamplesDirty(const IntID& ssd){fprintf_s(mFile,"connectAttr \"");ssd.write(mFile);fprintf_s(mFile,"\" \"%s.ssd\";\n",mName.c_str());}
	/*Defines to set scraggle map dirty*/
	void setScraggleMapDirty(int smd){if(smd == 0.0) return; fprintf_s(mFile, "setAttr \".smd\" %i;\n", smd);}
	/*Defines to set scraggle map dirty*/
	void setScraggleMapDirty(const IntID& smd){fprintf_s(mFile,"connectAttr \"");smd.write(mFile);fprintf_s(mFile,"\" \"%s.smd\";\n",mName.c_str());}
	/*
	Defines how the scraggle of each hair feedback relates to each other hair feedback.
	0.0-No correlation, so each hair has a unique scraggle. 1.0-Total correlation, so all hair "scraggle" in exactly the same way.
	*/
	void setScraggleCorrelation(float dsco){if(dsco == 0.0) return; fprintf_s(mFile, "setAttr \".dsco\" %f;\n", dsco);}
	/*
	Defines how the scraggle of each hair feedback relates to each other hair feedback.
	0.0-No correlation, so each hair has a unique scraggle. 1.0-Total correlation, so all hair "scraggle" in exactly the same way.
	*/
	void setScraggleCorrelation(const FloatID& dsco){fprintf_s(mFile,"connectAttr \"");dsco.write(mFile);fprintf_s(mFile,"\" \"%s.dsco\";\n",mName.c_str());}
	/*Used to store fur feedback scraggle correlation samples.*/
	void setScraggleCorrelationSamples(size_t scos_i,double scos){if(scos == 0.0) return; fprintf_s(mFile, "setAttr \".scos[%i]\" %f;\n", scos_i,scos);}
	/*Used to map values for fur feedback attribute "ScraggleCorrelation" by importing file textures.*/
	void setScraggleCorrelationMap(const string& scom){if(scom == "n/a") return; fprintf_s(mFile, "setAttr \".scom\" -type \"string\" ");scom.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setScraggleCorrelationMapOffset(float scomo){if(scomo == 0.0) return; fprintf_s(mFile, "setAttr \".scomo\" %f;\n", scomo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setScraggleCorrelationMapOffset(const FloatID& scomo){fprintf_s(mFile,"connectAttr \"");scomo.write(mFile);fprintf_s(mFile,"\" \"%s.scomo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleCorrelationMapMult(float scomm){if(scomm == 1.0) return; fprintf_s(mFile, "setAttr \".scomm\" %f;\n", scomm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleCorrelationMapMult(const FloatID& scomm){fprintf_s(mFile,"connectAttr \"");scomm.write(mFile);fprintf_s(mFile,"\" \"%s.scomm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleCorrelationNoise(float scon){if(scon == 0.0) return; fprintf_s(mFile, "setAttr \".scon\" %f;\n", scon);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleCorrelationNoise(const FloatID& scon){fprintf_s(mFile,"connectAttr \"");scon.write(mFile);fprintf_s(mFile,"\" \"%s.scon\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setScraggleCorrelationNoiseFreq(float sconf){if(sconf == 10.0) return; fprintf_s(mFile, "setAttr \".sconf\" %f;\n", sconf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setScraggleCorrelationNoiseFreq(const FloatID& sconf){fprintf_s(mFile,"connectAttr \"");sconf.write(mFile);fprintf_s(mFile,"\" \"%s.sconf\";\n",mName.c_str());}
	/*Defines to set scraggle correlation samples dirty*/
	void setScraggleCorrelationSamplesDirty(int scosd){if(scosd == 0.0) return; fprintf_s(mFile, "setAttr \".scosd\" %i;\n", scosd);}
	/*Defines to set scraggle correlation samples dirty*/
	void setScraggleCorrelationSamplesDirty(const IntID& scosd){fprintf_s(mFile,"connectAttr \"");scosd.write(mFile);fprintf_s(mFile,"\" \"%s.scosd\";\n",mName.c_str());}
	/*Defines to set scraggle correlation map dirty*/
	void setScraggleCorrelationMapDirty(int scomd){if(scomd == 0.0) return; fprintf_s(mFile, "setAttr \".scomd\" %i;\n", scomd);}
	/*Defines to set scraggle correlation map dirty*/
	void setScraggleCorrelationMapDirty(const IntID& scomd){fprintf_s(mFile,"connectAttr \"");scomd.write(mFile);fprintf_s(mFile,"\" \"%s.scomd\";\n",mName.c_str());}
	/*Defines the amount of change over each length of hair feedback. The higher the value, the more changes there will be along each length of hair feedback (the hair feedback becomes more deformed).*/
	void setScraggleFrequency(float dscf){if(dscf == 5.0) return; fprintf_s(mFile, "setAttr \".dscf\" %f;\n", dscf);}
	/*Defines the amount of change over each length of hair feedback. The higher the value, the more changes there will be along each length of hair feedback (the hair feedback becomes more deformed).*/
	void setScraggleFrequency(const FloatID& dscf){fprintf_s(mFile,"connectAttr \"");dscf.write(mFile);fprintf_s(mFile,"\" \"%s.dscf\";\n",mName.c_str());}
	/*Defines the amount of change over each length of hair feedback. The higher the value, the more changes there will be along each length of hair feedback (the hair feedback becomes more deformed).*/
	void setScraggleFrequencySamples(size_t scfs_i,double scfs){if(scfs == 0.0) return; fprintf_s(mFile, "setAttr \".scfs[%i]\" %f;\n", scfs_i,scfs);}
	/*Used to map values for fur feedback attribute "ScraggleFrequency" by importing file textures.*/
	void setScraggleFrequencyMap(const string& scfm){if(scfm == "n/a") return; fprintf_s(mFile, "setAttr \".scfm\" -type \"string\" ");scfm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setScraggleFrequencyMapOffset(float scfmo){if(scfmo == 0.0) return; fprintf_s(mFile, "setAttr \".scfmo\" %f;\n", scfmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setScraggleFrequencyMapOffset(const FloatID& scfmo){fprintf_s(mFile,"connectAttr \"");scfmo.write(mFile);fprintf_s(mFile,"\" \"%s.scfmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleFrequencyMapMult(float scfmm){if(scfmm == 1.0) return; fprintf_s(mFile, "setAttr \".scfmm\" %f;\n", scfmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleFrequencyMapMult(const FloatID& scfmm){fprintf_s(mFile,"connectAttr \"");scfmm.write(mFile);fprintf_s(mFile,"\" \"%s.scfmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleFrequencyNoise(float scfn){if(scfn == 0.0) return; fprintf_s(mFile, "setAttr \".scfn\" %f;\n", scfn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleFrequencyNoise(const FloatID& scfn){fprintf_s(mFile,"connectAttr \"");scfn.write(mFile);fprintf_s(mFile,"\" \"%s.scfn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setScraggleFrequencyNoiseFreq(float scfnf){if(scfnf == 10.0) return; fprintf_s(mFile, "setAttr \".scfnf\" %f;\n", scfnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setScraggleFrequencyNoiseFreq(const FloatID& scfnf){fprintf_s(mFile,"connectAttr \"");scfnf.write(mFile);fprintf_s(mFile,"\" \"%s.scfnf\";\n",mName.c_str());}
	/*Defines to set scraggle frequency samples dirty*/
	void setScraggleFrequencySamplesDirty(int scfsd){if(scfsd == 0.0) return; fprintf_s(mFile, "setAttr \".scfsd\" %i;\n", scfsd);}
	/*Defines to set scraggle frequency samples dirty*/
	void setScraggleFrequencySamplesDirty(const IntID& scfsd){fprintf_s(mFile,"connectAttr \"");scfsd.write(mFile);fprintf_s(mFile,"\" \"%s.scfsd\";\n",mName.c_str());}
	/*Defines to set scraggle frequency map dirty*/
	void setScraggleFrequencyMapDirty(int scfmd){if(scfmd == 0.0) return; fprintf_s(mFile, "setAttr \".scfmd\" %i;\n", scfmd);}
	/*Defines to set scraggle frequency map dirty*/
	void setScraggleFrequencyMapDirty(const IntID& scfmd){fprintf_s(mFile,"connectAttr \"");scfmd.write(mFile);fprintf_s(mFile,"\" \"%s.scfmd\";\n",mName.c_str());}
	/*Defines the number of segments each fur feedback is comprised of. For smoother curves, use more segments.*/
	void setSegments(float dseg){if(dseg == 10) return; fprintf_s(mFile, "setAttr \".dseg\" %f;\n", dseg);}
	/*Defines the number of segments each fur feedback is comprised of. For smoother curves, use more segments.*/
	void setSegments(const FloatID& dseg){fprintf_s(mFile,"connectAttr \"");dseg.write(mFile);fprintf_s(mFile,"\" \"%s.dseg\";\n",mName.c_str());}
	/*Used to store fur feedback segment samples.*/
	void setSegmentsSamples(size_t segs_i,double segs){if(segs == 0.0) return; fprintf_s(mFile, "setAttr \".segs[%i]\" %f;\n", segs_i,segs);}
	/*Used to map values for fur feedback attribute "Segments" by importing file textures.*/
	void setSegmentsMap(const string& segm){if(segm == "n/a") return; fprintf_s(mFile, "setAttr \".segm\" -type \"string\" ");segm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setSegmentsMapOffset(float segmo){if(segmo == 0.0) return; fprintf_s(mFile, "setAttr \".segmo\" %f;\n", segmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setSegmentsMapOffset(const FloatID& segmo){fprintf_s(mFile,"connectAttr \"");segmo.write(mFile);fprintf_s(mFile,"\" \"%s.segmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setSegmentsMapMult(float segmm){if(segmm == 1.0) return; fprintf_s(mFile, "setAttr \".segmm\" %f;\n", segmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setSegmentsMapMult(const FloatID& segmm){fprintf_s(mFile,"connectAttr \"");segmm.write(mFile);fprintf_s(mFile,"\" \"%s.segmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setSegmentsNoise(float segn){if(segn == 0.0) return; fprintf_s(mFile, "setAttr \".segn\" %f;\n", segn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setSegmentsNoise(const FloatID& segn){fprintf_s(mFile,"connectAttr \"");segn.write(mFile);fprintf_s(mFile,"\" \"%s.segn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setSegmentsNoiseFreq(float segnf){if(segnf == 10.0) return; fprintf_s(mFile, "setAttr \".segnf\" %f;\n", segnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setSegmentsNoiseFreq(const FloatID& segnf){fprintf_s(mFile,"connectAttr \"");segnf.write(mFile);fprintf_s(mFile,"\" \"%s.segnf\";\n",mName.c_str());}
	/*Defines to set segments samples dirty*/
	void setSegmentsSamplesDirty(int segsd){if(segsd == 0.0) return; fprintf_s(mFile, "setAttr \".segsd\" %i;\n", segsd);}
	/*Defines to set segments samples dirty*/
	void setSegmentsSamplesDirty(const IntID& segsd){fprintf_s(mFile,"connectAttr \"");segsd.write(mFile);fprintf_s(mFile,"\" \"%s.segsd\";\n",mName.c_str());}
	/*Defines to set segments map dirty*/
	void setSegmentsMapDirty(int segmd){if(segmd == 0.0) return; fprintf_s(mFile, "setAttr \".segmd\" %i;\n", segmd);}
	/*Defines to set segments map dirty*/
	void setSegmentsMapDirty(const IntID& segmd){fprintf_s(mFile,"connectAttr \"");segmd.write(mFile);fprintf_s(mFile,"\" \"%s.segmd\";\n",mName.c_str());}
	/*
	Defines the amount of attraction this fur feedback has towards attractors.
	0.0 No attraction. 1.0 Full attraction.
	*/
	void setAttraction(float dat){if(dat == 1.0) return; fprintf_s(mFile, "setAttr \".dat\" %f;\n", dat);}
	/*
	Defines the amount of attraction this fur feedback has towards attractors.
	0.0 No attraction. 1.0 Full attraction.
	*/
	void setAttraction(const FloatID& dat){fprintf_s(mFile,"connectAttr \"");dat.write(mFile);fprintf_s(mFile,"\" \"%s.dat\";\n",mName.c_str());}
	/*Used to store fur feedback attraction samples.*/
	void setAttractionSamples(size_t ats_i,double ats){if(ats == 0.0) return; fprintf_s(mFile, "setAttr \".ats[%i]\" %f;\n", ats_i,ats);}
	/*Used to map values for fur feedback attribute "Attraction" by importing file textures.*/
	void setAttractionMap(const string& atm){if(atm == "n/a") return; fprintf_s(mFile, "setAttr \".atm\" -type \"string\" ");atm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setAttractionMapOffset(float atmo){if(atmo == 0.0) return; fprintf_s(mFile, "setAttr \".atmo\" %f;\n", atmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setAttractionMapOffset(const FloatID& atmo){fprintf_s(mFile,"connectAttr \"");atmo.write(mFile);fprintf_s(mFile,"\" \"%s.atmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setAttractionMapMult(float atmm){if(atmm == 1.0) return; fprintf_s(mFile, "setAttr \".atmm\" %f;\n", atmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setAttractionMapMult(const FloatID& atmm){fprintf_s(mFile,"connectAttr \"");atmm.write(mFile);fprintf_s(mFile,"\" \"%s.atmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setAttractionNoise(float atn){if(atn == 0.0) return; fprintf_s(mFile, "setAttr \".atn\" %f;\n", atn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setAttractionNoise(const FloatID& atn){fprintf_s(mFile,"connectAttr \"");atn.write(mFile);fprintf_s(mFile,"\" \"%s.atn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setAttractionNoiseFreq(float atnf){if(atnf == 10.0) return; fprintf_s(mFile, "setAttr \".atnf\" %f;\n", atnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setAttractionNoiseFreq(const FloatID& atnf){fprintf_s(mFile,"connectAttr \"");atnf.write(mFile);fprintf_s(mFile,"\" \"%s.atnf\";\n",mName.c_str());}
	/*Defines to set attraction samples dirty*/
	void setAttractionSamplesDirty(int atsd){if(atsd == 0.0) return; fprintf_s(mFile, "setAttr \".atsd\" %i;\n", atsd);}
	/*Defines to set attraction samples dirty*/
	void setAttractionSamplesDirty(const IntID& atsd){fprintf_s(mFile,"connectAttr \"");atsd.write(mFile);fprintf_s(mFile,"\" \"%s.atsd\";\n",mName.c_str());}
	/*Defines to set attraction map dirty*/
	void setAttractionMapDirty(int atmd){if(atmd == 0.0) return; fprintf_s(mFile, "setAttr \".atmd\" %i;\n", atmd);}
	/*Defines to set attraction map dirty*/
	void setAttractionMapDirty(const IntID& atmd){fprintf_s(mFile,"connectAttr \"");atmd.write(mFile);fprintf_s(mFile,"\" \"%s.atmd\";\n",mName.c_str());}
	/*
	Defines how much to offset the fur feedback (in world units) from the surface it is attached to.
	When the Offset value is 0, the roots of the fur feedback start growing from the surface.
	When the value is less than zero, the roots start growing from inside the surface.
	When the value is greater than zero, the roots start growing from outside the surface
	*/
	void setOffset(double dofs){if(dofs == 0) return; fprintf_s(mFile, "setAttr \".dofs\" %f;\n", dofs);}
	/*
	Defines how much to offset the fur feedback (in world units) from the surface it is attached to.
	When the Offset value is 0, the roots of the fur feedback start growing from the surface.
	When the value is less than zero, the roots start growing from inside the surface.
	When the value is greater than zero, the roots start growing from outside the surface
	*/
	void setOffset(const DoubleID& dofs){fprintf_s(mFile,"connectAttr \"");dofs.write(mFile);fprintf_s(mFile,"\" \"%s.dofs\";\n",mName.c_str());}
	/*Used to store fur feedback offset samples.*/
	void setOffsetSamples(size_t ofss_i,double ofss){if(ofss == 0.0) return; fprintf_s(mFile, "setAttr \".ofss[%i]\" %f;\n", ofss_i,ofss);}
	/*Used to map values for fur feedback attribute "Offset" by importing file textures.*/
	void setOffsetMap(const string& ofsm){if(ofsm == "n/a") return; fprintf_s(mFile, "setAttr \".ofsm\" -type \"string\" ");ofsm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setOffsetMapOffset(double ofsmo){if(ofsmo == 0) return; fprintf_s(mFile, "setAttr \".ofsmo\" %f;\n", ofsmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setOffsetMapOffset(const DoubleID& ofsmo){fprintf_s(mFile,"connectAttr \"");ofsmo.write(mFile);fprintf_s(mFile,"\" \"%s.ofsmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setOffsetMapMult(double ofsmm){if(ofsmm == 1) return; fprintf_s(mFile, "setAttr \".ofsmm\" %f;\n", ofsmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setOffsetMapMult(const DoubleID& ofsmm){fprintf_s(mFile,"connectAttr \"");ofsmm.write(mFile);fprintf_s(mFile,"\" \"%s.ofsmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setOffsetNoise(double ofsn){if(ofsn == 0) return; fprintf_s(mFile, "setAttr \".ofsn\" %f;\n", ofsn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setOffsetNoise(const DoubleID& ofsn){fprintf_s(mFile,"connectAttr \"");ofsn.write(mFile);fprintf_s(mFile,"\" \"%s.ofsn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setOffsetNoiseFreq(float ofsnf){if(ofsnf == 10.0) return; fprintf_s(mFile, "setAttr \".ofsnf\" %f;\n", ofsnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setOffsetNoiseFreq(const FloatID& ofsnf){fprintf_s(mFile,"connectAttr \"");ofsnf.write(mFile);fprintf_s(mFile,"\" \"%s.ofsnf\";\n",mName.c_str());}
	/*Defines to set offset samples dirty*/
	void setOffsetSamplesDirty(int ofssd){if(ofssd == 0.0) return; fprintf_s(mFile, "setAttr \".ofssd\" %i;\n", ofssd);}
	/*Defines to set offset samples dirty*/
	void setOffsetSamplesDirty(const IntID& ofssd){fprintf_s(mFile,"connectAttr \"");ofssd.write(mFile);fprintf_s(mFile,"\" \"%s.ofssd\";\n",mName.c_str());}
	/*Defines to set offset map dirty*/
	void setOffsetMapDirty(int ofsmd){if(ofsmd == 0.0) return; fprintf_s(mFile, "setAttr \".ofsmd\" %i;\n", ofsmd);}
	/*Defines to set offset map dirty*/
	void setOffsetMapDirty(const IntID& ofsmd){fprintf_s(mFile,"connectAttr \"");ofsmd.write(mFile);fprintf_s(mFile,"\" \"%s.ofsmd\";\n",mName.c_str());}
	/*
	The degree to which the hairs are pulled in towards the centreof the clump.
	The higher the clumping value, the more the hairs are pulled in.
	The defaultis 0, which means no clumping.
	*/
	void setClumping(float dc){if(dc == 0.0) return; fprintf_s(mFile, "setAttr \".dc\" %f;\n", dc);}
	/*
	The degree to which the hairs are pulled in towards the centreof the clump.
	The higher the clumping value, the more the hairs are pulled in.
	The defaultis 0, which means no clumping.
	*/
	void setClumping(const FloatID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*Used to store fur feedback clumping samples.*/
	void setClumpingSamples(size_t cs_i,double cs){if(cs == 0.0) return; fprintf_s(mFile, "setAttr \".cs[%i]\" %f;\n", cs_i,cs);}
	/*Used to map values for fur feedback attribute "Clumping" by importing file textures.*/
	void setClumpingMap(const string& cm){if(cm == "n/a") return; fprintf_s(mFile, "setAttr \".cm\" -type \"string\" ");cm.write(mFile);fprintf_s(mFile,";\n");}
	/*Used to set the factor to offset the fur feedback attribute. The initial map is between 0 and 1.*/
	void setClumpingMapOffset(float cmo){if(cmo == 0.0) return; fprintf_s(mFile, "setAttr \".cmo\" %f;\n", cmo);}
	/*Used to set the factor to offset the fur feedback attribute. The initial map is between 0 and 1.*/
	void setClumpingMapOffset(const FloatID& cmo){fprintf_s(mFile,"connectAttr \"");cmo.write(mFile);fprintf_s(mFile,"\" \"%s.cmo\";\n",mName.c_str());}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingMapMult(float cmm){if(cmm == 0.0) return; fprintf_s(mFile, "setAttr \".cmm\" %f;\n", cmm);}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingMapMult(const FloatID& cmm){fprintf_s(mFile,"connectAttr \"");cmm.write(mFile);fprintf_s(mFile,"\" \"%s.cmm\";\n",mName.c_str());}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingNoise(float cn){if(cn == 0.0) return; fprintf_s(mFile, "setAttr \".cn\" %f;\n", cn);}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingNoise(const FloatID& cn){fprintf_s(mFile,"connectAttr \"");cn.write(mFile);fprintf_s(mFile,"\" \"%s.cn\";\n",mName.c_str());}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setClumpingNoiseFreq(float cnf){if(cnf == 0.0) return; fprintf_s(mFile, "setAttr \".cnf\" %f;\n", cnf);}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setClumpingNoiseFreq(const FloatID& cnf){fprintf_s(mFile,"connectAttr \"");cnf.write(mFile);fprintf_s(mFile,"\" \"%s.cnf\";\n",mName.c_str());}
	/*Used to set clumping samples dirty*/
	void setClumpingSamplesDirty(int csd){if(csd == 0.0) return; fprintf_s(mFile, "setAttr \".csd\" %i;\n", csd);}
	/*Used to set clumping samples dirty*/
	void setClumpingSamplesDirty(const IntID& csd){fprintf_s(mFile,"connectAttr \"");csd.write(mFile);fprintf_s(mFile,"\" \"%s.csd\";\n",mName.c_str());}
	/*Used to set clumping map dirty*/
	void setClumpingMapDirty(int cmd){if(cmd == 0.0) return; fprintf_s(mFile, "setAttr \".cmd\" %i;\n", cmd);}
	/*Used to set clumping map dirty*/
	void setClumpingMapDirty(const IntID& cmd){fprintf_s(mFile,"connectAttr \"");cmd.write(mFile);fprintf_s(mFile,"\" \"%s.cmd\";\n",mName.c_str());}
	/*
	Controls how many clumps occur across the surface.
	The higher the frequency, the greater the number, and therefore smaller-sized, clumps.
	The default is 0.0.As you increase the Clumping Frequency, the rendering time increases.
	*/
	void setClumpingFrequency(float dcf){if(dcf == 0.0) return; fprintf_s(mFile, "setAttr \".dcf\" %f;\n", dcf);}
	/*
	Controls how many clumps occur across the surface.
	The higher the frequency, the greater the number, and therefore smaller-sized, clumps.
	The default is 0.0.As you increase the Clumping Frequency, the rendering time increases.
	*/
	void setClumpingFrequency(const FloatID& dcf){fprintf_s(mFile,"connectAttr \"");dcf.write(mFile);fprintf_s(mFile,"\" \"%s.dcf\";\n",mName.c_str());}
	/*Used to store fur feedback clumpingFrequency samples.*/
	void setClumpingFrequencySamples(size_t cfs_i,double cfs){if(cfs == 0.0) return; fprintf_s(mFile, "setAttr \".cfs[%i]\" %f;\n", cfs_i,cfs);}
	/*Used to map values for fur feedback attribute "ClumpingFrequency" by importing file textures.*/
	void setClumpingFrequencyMap(const string& cfm){if(cfm == "n/a") return; fprintf_s(mFile, "setAttr \".cfm\" -type \"string\" ");cfm.write(mFile);fprintf_s(mFile,";\n");}
	/*Used to set the factor to offset the fur feedback attribute. The initial map is between 0 and 1.*/
	void setClumpingFrequencyMapOffset(float cfmo){if(cfmo == 0.0) return; fprintf_s(mFile, "setAttr \".cfmo\" %f;\n", cfmo);}
	/*Used to set the factor to offset the fur feedback attribute. The initial map is between 0 and 1.*/
	void setClumpingFrequencyMapOffset(const FloatID& cfmo){fprintf_s(mFile,"connectAttr \"");cfmo.write(mFile);fprintf_s(mFile,"\" \"%s.cfmo\";\n",mName.c_str());}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingFrequencyMapMult(float cfmm){if(cfmm == 0.0) return; fprintf_s(mFile, "setAttr \".cfmm\" %f;\n", cfmm);}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingFrequencyMapMult(const FloatID& cfmm){fprintf_s(mFile,"connectAttr \"");cfmm.write(mFile);fprintf_s(mFile,"\" \"%s.cfmm\";\n",mName.c_str());}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingFrequencyNoise(float cfn){if(cfn == 0.0) return; fprintf_s(mFile, "setAttr \".cfn\" %f;\n", cfn);}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingFrequencyNoise(const FloatID& cfn){fprintf_s(mFile,"connectAttr \"");cfn.write(mFile);fprintf_s(mFile,"\" \"%s.cfn\";\n",mName.c_str());}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setClumpingFrequencyNoiseFreq(float cfnf){if(cfnf == 0.0) return; fprintf_s(mFile, "setAttr \".cfnf\" %f;\n", cfnf);}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setClumpingFrequencyNoiseFreq(const FloatID& cfnf){fprintf_s(mFile,"connectAttr \"");cfnf.write(mFile);fprintf_s(mFile,"\" \"%s.cfnf\";\n",mName.c_str());}
	/*Used to set clumpingFrequency samples dirty*/
	void setClumpingFrequencySamplesDirty(int cfsd){if(cfsd == 0.0) return; fprintf_s(mFile, "setAttr \".cfsd\" %i;\n", cfsd);}
	/*Used to set clumpingFrequency samples dirty*/
	void setClumpingFrequencySamplesDirty(const IntID& cfsd){fprintf_s(mFile,"connectAttr \"");cfsd.write(mFile);fprintf_s(mFile,"\" \"%s.cfsd\";\n",mName.c_str());}
	/*Used to set clumpingFrequency map dirty*/
	void setClumpingFrequencyMapDirty(int cfmd){if(cfmd == 0.0) return; fprintf_s(mFile, "setAttr \".cfmd\" %i;\n", cfmd);}
	/*Used to set clumpingFrequency map dirty*/
	void setClumpingFrequencyMapDirty(const IntID& cfmd){fprintf_s(mFile,"connectAttr \"");cfmd.write(mFile);fprintf_s(mFile,"\" \"%s.cfmd\";\n",mName.c_str());}
	/*
	Controls the shape of the curve of the hair as it is attracted to the center of the clump.
	A value of -10 creates a concave shape and a value of 10 creates a convex shape.
	*/
	void setClumpingShape(float dcs){if(dcs == 0.0) return; fprintf_s(mFile, "setAttr \".dcs\" %f;\n", dcs);}
	/*
	Controls the shape of the curve of the hair as it is attracted to the center of the clump.
	A value of -10 creates a concave shape and a value of 10 creates a convex shape.
	*/
	void setClumpingShape(const FloatID& dcs){fprintf_s(mFile,"connectAttr \"");dcs.write(mFile);fprintf_s(mFile,"\" \"%s.dcs\";\n",mName.c_str());}
	/*Used to store fur feedback clumpingShape samples.*/
	void setClumpingShapeSamples(size_t css_i,double css){if(css == 0.0) return; fprintf_s(mFile, "setAttr \".css[%i]\" %f;\n", css_i,css);}
	/*Used to map values for fur feedback attribute "ClumpingShape" by importing file textures.*/
	void setClumpingShapeMap(const string& csm){if(csm == "n/a") return; fprintf_s(mFile, "setAttr \".csm\" -type \"string\" ");csm.write(mFile);fprintf_s(mFile,";\n");}
	/*Used to set the factor to offset the fur feedback attribute. The initial map is between 0 and 1.*/
	void setClumpingShapeMapOffset(float csmo){if(csmo == 0.0) return; fprintf_s(mFile, "setAttr \".csmo\" %f;\n", csmo);}
	/*Used to set the factor to offset the fur feedback attribute. The initial map is between 0 and 1.*/
	void setClumpingShapeMapOffset(const FloatID& csmo){fprintf_s(mFile,"connectAttr \"");csmo.write(mFile);fprintf_s(mFile,"\" \"%s.csmo\";\n",mName.c_str());}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingShapeMapMult(float csmm){if(csmm == 0.0) return; fprintf_s(mFile, "setAttr \".csmm\" %f;\n", csmm);}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingShapeMapMult(const FloatID& csmm){fprintf_s(mFile,"connectAttr \"");csmm.write(mFile);fprintf_s(mFile,"\" \"%s.csmm\";\n",mName.c_str());}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingShapeNoise(float csn){if(csn == 0.0) return; fprintf_s(mFile, "setAttr \".csn\" %f;\n", csn);}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingShapeNoise(const FloatID& csn){fprintf_s(mFile,"connectAttr \"");csn.write(mFile);fprintf_s(mFile,"\" \"%s.csn\";\n",mName.c_str());}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setClumpingShapeNoiseFreq(float csnf){if(csnf == 0.0) return; fprintf_s(mFile, "setAttr \".csnf\" %f;\n", csnf);}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setClumpingShapeNoiseFreq(const FloatID& csnf){fprintf_s(mFile,"connectAttr \"");csnf.write(mFile);fprintf_s(mFile,"\" \"%s.csnf\";\n",mName.c_str());}
	/*Used to set clumpingShape samples dirty*/
	void setClumpingShapeSamplesDirty(int cssd){if(cssd == 0.0) return; fprintf_s(mFile, "setAttr \".cssd\" %i;\n", cssd);}
	/*Used to set clumpingShape samples dirty*/
	void setClumpingShapeSamplesDirty(const IntID& cssd){fprintf_s(mFile,"connectAttr \"");cssd.write(mFile);fprintf_s(mFile,"\" \"%s.cssd\";\n",mName.c_str());}
	/*Used to set clumpingShape map dirty*/
	void setClumpingShapeMapDirty(int csmd){if(csmd == 0.0) return; fprintf_s(mFile, "setAttr \".csmd\" %i;\n", csmd);}
	/*Used to set clumpingShape map dirty*/
	void setClumpingShapeMapDirty(const IntID& csmd){fprintf_s(mFile,"connectAttr \"");csmd.write(mFile);fprintf_s(mFile,"\" \"%s.csmd\";\n",mName.c_str());}
	/*Defines the color of the fur feedback base.*/
	void setBaseColor(const float3& dbc){if(dbc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".dbc\" -type \"float3\" ");dbc.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the color of the fur feedback base.*/
	void setBaseColor(const Float3ID& dbc){fprintf_s(mFile,"connectAttr \"");dbc.write(mFile);fprintf_s(mFile,"\" \"%s.dbc\";\n",mName.c_str());}
	/*Defines the Red channel of the fur feedback base.*/
	void setBaseColorR(float dbcr){if(dbcr == 1.0) return; fprintf_s(mFile, "setAttr \".dbcr\" %f;\n", dbcr);}
	/*Defines the Red channel of the fur feedback base.*/
	void setBaseColorR(const FloatID& dbcr){fprintf_s(mFile,"connectAttr \"");dbcr.write(mFile);fprintf_s(mFile,"\" \"%s.dbcr\";\n",mName.c_str());}
	/*Defines the Green channel of the fur feedback base.*/
	void setBaseColorG(float dbcg){if(dbcg == 1.0) return; fprintf_s(mFile, "setAttr \".dbcg\" %f;\n", dbcg);}
	/*Defines the Green channel of the fur feedback base.*/
	void setBaseColorG(const FloatID& dbcg){fprintf_s(mFile,"connectAttr \"");dbcg.write(mFile);fprintf_s(mFile,"\" \"%s.dbcg\";\n",mName.c_str());}
	/*Defines the Blue channel of the fur feedback base.*/
	void setBaseColorB(float dbcb){if(dbcb == 1.0) return; fprintf_s(mFile, "setAttr \".dbcb\" %f;\n", dbcb);}
	/*Defines the Blue channel of the fur feedback base.*/
	void setBaseColorB(const FloatID& dbcb){fprintf_s(mFile,"connectAttr \"");dbcb.write(mFile);fprintf_s(mFile,"\" \"%s.dbcb\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseColorSamples(size_t bcs_i,double bcs){if(bcs == 0.0) return; fprintf_s(mFile, "setAttr \".bcs[%i]\" %f;\n", bcs_i,bcs);}
	/*Used to map values for Fur description attribute "BaseColor" by importing file textures.*/
	void setBaseColorMap(const string& bcm){if(bcm == "n/a") return; fprintf_s(mFile, "setAttr \".bcm\" -type \"string\" ");bcm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseColorNoise(float bcn){if(bcn == 0.0) return; fprintf_s(mFile, "setAttr \".bcn\" %f;\n", bcn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseColorNoise(const FloatID& bcn){fprintf_s(mFile,"connectAttr \"");bcn.write(mFile);fprintf_s(mFile,"\" \"%s.bcn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseColorNoiseFreq(float bcnf){if(bcnf == 10.0) return; fprintf_s(mFile, "setAttr \".bcnf\" %f;\n", bcnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseColorNoiseFreq(const FloatID& bcnf){fprintf_s(mFile,"connectAttr \"");bcnf.write(mFile);fprintf_s(mFile,"\" \"%s.bcnf\";\n",mName.c_str());}
	/*Defines to set base color samples dirty*/
	void setBaseColorSamplesDirty(int bcsd){if(bcsd == 0.0) return; fprintf_s(mFile, "setAttr \".bcsd\" %i;\n", bcsd);}
	/*Defines to set base color samples dirty*/
	void setBaseColorSamplesDirty(const IntID& bcsd){fprintf_s(mFile,"connectAttr \"");bcsd.write(mFile);fprintf_s(mFile,"\" \"%s.bcsd\";\n",mName.c_str());}
	/*Defines to set base color map dirty*/
	void setBaseColorMapDirty(int bcmd){if(bcmd == 0.0) return; fprintf_s(mFile, "setAttr \".bcmd\" %i;\n", bcmd);}
	/*Defines to set base color map dirty*/
	void setBaseColorMapDirty(const IntID& bcmd){fprintf_s(mFile,"connectAttr \"");bcmd.write(mFile);fprintf_s(mFile,"\" \"%s.bcmd\";\n",mName.c_str());}
	/*Defines the color of the fur feedback tip.*/
	void setTipColor(const float3& dtc){if(dtc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".dtc\" -type \"float3\" ");dtc.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the color of the fur feedback tip.*/
	void setTipColor(const Float3ID& dtc){fprintf_s(mFile,"connectAttr \"");dtc.write(mFile);fprintf_s(mFile,"\" \"%s.dtc\";\n",mName.c_str());}
	/*Defines the red channel of the fur feedback tip.*/
	void setTipColorR(float dtcr){if(dtcr == 1.0) return; fprintf_s(mFile, "setAttr \".dtcr\" %f;\n", dtcr);}
	/*Defines the red channel of the fur feedback tip.*/
	void setTipColorR(const FloatID& dtcr){fprintf_s(mFile,"connectAttr \"");dtcr.write(mFile);fprintf_s(mFile,"\" \"%s.dtcr\";\n",mName.c_str());}
	/*Defines the green channel of the fur feedback tip.*/
	void setTipColorG(float dtcg){if(dtcg == 1.0) return; fprintf_s(mFile, "setAttr \".dtcg\" %f;\n", dtcg);}
	/*Defines the green channel of the fur feedback tip.*/
	void setTipColorG(const FloatID& dtcg){fprintf_s(mFile,"connectAttr \"");dtcg.write(mFile);fprintf_s(mFile,"\" \"%s.dtcg\";\n",mName.c_str());}
	/*Defines the blue channel of the fur feedback tip.*/
	void setTipColorB(float dtcb){if(dtcb == 1.0) return; fprintf_s(mFile, "setAttr \".dtcb\" %f;\n", dtcb);}
	/*Defines the blue channel of the fur feedback tip.*/
	void setTipColorB(const FloatID& dtcb){fprintf_s(mFile,"connectAttr \"");dtcb.write(mFile);fprintf_s(mFile,"\" \"%s.dtcb\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipColorSamples(size_t tcs_i,double tcs){if(tcs == 0.0) return; fprintf_s(mFile, "setAttr \".tcs[%i]\" %f;\n", tcs_i,tcs);}
	/*Used to map values for Fur description attribute "TipColor" by importing file textures.*/
	void setTipColorMap(const string& tcm){if(tcm == "n/a") return; fprintf_s(mFile, "setAttr \".tcm\" -type \"string\" ");tcm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipColorNoise(float tcn){if(tcn == 0.0) return; fprintf_s(mFile, "setAttr \".tcn\" %f;\n", tcn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipColorNoise(const FloatID& tcn){fprintf_s(mFile,"connectAttr \"");tcn.write(mFile);fprintf_s(mFile,"\" \"%s.tcn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipColorNoiseFreq(float tcnf){if(tcnf == 10.0) return; fprintf_s(mFile, "setAttr \".tcnf\" %f;\n", tcnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipColorNoiseFreq(const FloatID& tcnf){fprintf_s(mFile,"connectAttr \"");tcnf.write(mFile);fprintf_s(mFile,"\" \"%s.tcnf\";\n",mName.c_str());}
	/*Defines to set tip color samples dirty*/
	void setTipColorSamplesDirty(int tcsd){if(tcsd == 0.0) return; fprintf_s(mFile, "setAttr \".tcsd\" %i;\n", tcsd);}
	/*Defines to set tip color samples dirty*/
	void setTipColorSamplesDirty(const IntID& tcsd){fprintf_s(mFile,"connectAttr \"");tcsd.write(mFile);fprintf_s(mFile,"\" \"%s.tcsd\";\n",mName.c_str());}
	/*Defines to set tip color map dirty*/
	void setTipColorMapDirty(int tcmd){if(tcmd == 0.0) return; fprintf_s(mFile, "setAttr \".tcmd\" %i;\n", tcmd);}
	/*Defines to set tip color map dirty*/
	void setTipColorMapDirty(const IntID& tcmd){fprintf_s(mFile,"connectAttr \"");tcmd.write(mFile);fprintf_s(mFile,"\" \"%s.tcmd\";\n",mName.c_str());}
	/*Used to set the radius in which to search for the closest attractors, in world units. This value can help prevent hairs from being influenced by attractors that are unreasonably far away.*/
	void setRadius(double dar){if(dar == 1) return; fprintf_s(mFile, "setAttr \".dar\" %f;\n", dar);}
	/*Used to set the radius in which to search for the closest attractors, in world units. This value can help prevent hairs from being influenced by attractors that are unreasonably far away.*/
	void setRadius(const DoubleID& dar){fprintf_s(mFile,"connectAttr \"");dar.write(mFile);fprintf_s(mFile,"\" \"%s.dar\";\n",mName.c_str());}
	/*Used to store feedback attractor radius samples.*/
	void setRadiusSamples(size_t ars_i,double ars){if(ars == 0.0) return; fprintf_s(mFile, "setAttr \".ars[%i]\" %f;\n", ars_i,ars);}
	/*Used to map values for feedback attractor set attribute "Radius" by importing file textures.*/
	void setRadiusMap(const string& arm){if(arm == "n/a") return; fprintf_s(mFile, "setAttr \".arm\" -type \"string\" ");arm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setRadiusMapOffset(double armo){if(armo == 0) return; fprintf_s(mFile, "setAttr \".armo\" %f;\n", armo);}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setRadiusMapOffset(const DoubleID& armo){fprintf_s(mFile,"connectAttr \"");armo.write(mFile);fprintf_s(mFile,"\" \"%s.armo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setRadiusMapMult(double armm){if(armm == 1) return; fprintf_s(mFile, "setAttr \".armm\" %f;\n", armm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setRadiusMapMult(const DoubleID& armm){fprintf_s(mFile,"connectAttr \"");armm.write(mFile);fprintf_s(mFile,"\" \"%s.armm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setRadiusNoise(double arn){if(arn == 0) return; fprintf_s(mFile, "setAttr \".arn\" %f;\n", arn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setRadiusNoise(const DoubleID& arn){fprintf_s(mFile,"connectAttr \"");arn.write(mFile);fprintf_s(mFile,"\" \"%s.arn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setRadiusNoiseFreq(float arnf){if(arnf == 10.0) return; fprintf_s(mFile, "setAttr \".arnf\" %f;\n", arnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setRadiusNoiseFreq(const FloatID& arnf){fprintf_s(mFile,"connectAttr \"");arnf.write(mFile);fprintf_s(mFile,"\" \"%s.arnf\";\n",mName.c_str());}
	/*Defines to set radius samples dirty*/
	void setRadiusSamplesDirty(int arsd){if(arsd == 0.0) return; fprintf_s(mFile, "setAttr \".arsd\" %i;\n", arsd);}
	/*Defines to set radius samples dirty*/
	void setRadiusSamplesDirty(const IntID& arsd){fprintf_s(mFile,"connectAttr \"");arsd.write(mFile);fprintf_s(mFile,"\" \"%s.arsd\";\n",mName.c_str());}
	/*Defines to set radius map dirty*/
	void setRadiusMapDirty(int armd){if(armd == 0.0) return; fprintf_s(mFile, "setAttr \".armd\" %i;\n", armd);}
	/*Defines to set radius map dirty*/
	void setRadiusMapDirty(const IntID& armd){fprintf_s(mFile,"connectAttr \"");armd.write(mFile);fprintf_s(mFile,"\" \"%s.armd\";\n",mName.c_str());}
	/*
	Set how feedback attractor will influence the hairs. The value you enter is the power to a falloff function that makes hairs become less influenced at the base of the hair than at the tip.
	0.0 The entire length of the hair feedback is influenced.
	1.0 Hair is much less influenced at the base.
	*/
	void setPower(float dap){if(dap == 1.0) return; fprintf_s(mFile, "setAttr \".dap\" %f;\n", dap);}
	/*
	Set how feedback attractor will influence the hairs. The value you enter is the power to a falloff function that makes hairs become less influenced at the base of the hair than at the tip.
	0.0 The entire length of the hair feedback is influenced.
	1.0 Hair is much less influenced at the base.
	*/
	void setPower(const FloatID& dap){fprintf_s(mFile,"connectAttr \"");dap.write(mFile);fprintf_s(mFile,"\" \"%s.dap\";\n",mName.c_str());}
	/*Used to store feedback attractor power samples.*/
	void setPowerSamples(size_t aps_i,double aps){if(aps == 0.0) return; fprintf_s(mFile, "setAttr \".aps[%i]\" %f;\n", aps_i,aps);}
	/*Used to map values for feedback attractor set attribute "Power" by importing file textures.*/
	void setPowerMap(const string& apm){if(apm == "n/a") return; fprintf_s(mFile, "setAttr \".apm\" -type \"string\" ");apm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setPowerMapOffset(float apmo){if(apmo == 0.0) return; fprintf_s(mFile, "setAttr \".apmo\" %f;\n", apmo);}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setPowerMapOffset(const FloatID& apmo){fprintf_s(mFile,"connectAttr \"");apmo.write(mFile);fprintf_s(mFile,"\" \"%s.apmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setPowerMapMult(float apmm){if(apmm == 1.0) return; fprintf_s(mFile, "setAttr \".apmm\" %f;\n", apmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setPowerMapMult(const FloatID& apmm){fprintf_s(mFile,"connectAttr \"");apmm.write(mFile);fprintf_s(mFile,"\" \"%s.apmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setPowerNoise(float apn){if(apn == 0.0) return; fprintf_s(mFile, "setAttr \".apn\" %f;\n", apn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setPowerNoise(const FloatID& apn){fprintf_s(mFile,"connectAttr \"");apn.write(mFile);fprintf_s(mFile,"\" \"%s.apn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setPowerNoiseFreq(float apnf){if(apnf == 10.0) return; fprintf_s(mFile, "setAttr \".apnf\" %f;\n", apnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setPowerNoiseFreq(const FloatID& apnf){fprintf_s(mFile,"connectAttr \"");apnf.write(mFile);fprintf_s(mFile,"\" \"%s.apnf\";\n",mName.c_str());}
	/*Defines to set power samples dirty*/
	void setPowerSamplesDirty(int apsd){if(apsd == 0.0) return; fprintf_s(mFile, "setAttr \".apsd\" %i;\n", apsd);}
	/*Defines to set power samples dirty*/
	void setPowerSamplesDirty(const IntID& apsd){fprintf_s(mFile,"connectAttr \"");apsd.write(mFile);fprintf_s(mFile,"\" \"%s.apsd\";\n",mName.c_str());}
	/*Defines to set power map dirty*/
	void setPowerMapDirty(int apmd){if(apmd == 0.0) return; fprintf_s(mFile, "setAttr \".apmd\" %i;\n", apmd);}
	/*Defines to set power map dirty*/
	void setPowerMapDirty(const IntID& apmd){fprintf_s(mFile,"connectAttr \"");apmd.write(mFile);fprintf_s(mFile,"\" \"%s.apmd\";\n",mName.c_str());}
	/*
	Set how much influence the feedback attractor will have on the hairs. The value you enter linearly increases or decreases the influence over the length of the hair feedback.
	0.0 No influence.
	1.0 Standard influence.
	*/
	void setInfluence(float dai){if(dai == 1.0) return; fprintf_s(mFile, "setAttr \".dai\" %f;\n", dai);}
	/*
	Set how much influence the feedback attractor will have on the hairs. The value you enter linearly increases or decreases the influence over the length of the hair feedback.
	0.0 No influence.
	1.0 Standard influence.
	*/
	void setInfluence(const FloatID& dai){fprintf_s(mFile,"connectAttr \"");dai.write(mFile);fprintf_s(mFile,"\" \"%s.dai\";\n",mName.c_str());}
	/*Used to store feedback attractor influence samples.*/
	void setInfluenceSamples(size_t ais_i,double ais){if(ais == 0.0) return; fprintf_s(mFile, "setAttr \".ais[%i]\" %f;\n", ais_i,ais);}
	/*Used to map values for feedback attractor set attribute "Influence" by importing file textures.*/
	void setInfluenceMap(const string& aim){if(aim == "n/a") return; fprintf_s(mFile, "setAttr \".aim\" -type \"string\" ");aim.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setInfluenceMapOffset(float aimo){if(aimo == 0.0) return; fprintf_s(mFile, "setAttr \".aimo\" %f;\n", aimo);}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setInfluenceMapOffset(const FloatID& aimo){fprintf_s(mFile,"connectAttr \"");aimo.write(mFile);fprintf_s(mFile,"\" \"%s.aimo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setInfluenceMapMult(float aimm){if(aimm == 1.0) return; fprintf_s(mFile, "setAttr \".aimm\" %f;\n", aimm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setInfluenceMapMult(const FloatID& aimm){fprintf_s(mFile,"connectAttr \"");aimm.write(mFile);fprintf_s(mFile,"\" \"%s.aimm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setInfluenceNoise(float ain){if(ain == 0.0) return; fprintf_s(mFile, "setAttr \".ain\" %f;\n", ain);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setInfluenceNoise(const FloatID& ain){fprintf_s(mFile,"connectAttr \"");ain.write(mFile);fprintf_s(mFile,"\" \"%s.ain\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setInfluenceNoiseFreq(float ainf){if(ainf == 10.0) return; fprintf_s(mFile, "setAttr \".ainf\" %f;\n", ainf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setInfluenceNoiseFreq(const FloatID& ainf){fprintf_s(mFile,"connectAttr \"");ainf.write(mFile);fprintf_s(mFile,"\" \"%s.ainf\";\n",mName.c_str());}
	/*Defines to set influence samples dirty*/
	void setInfluenceSamplesDirty(int aisd){if(aisd == 0.0) return; fprintf_s(mFile, "setAttr \".aisd\" %i;\n", aisd);}
	/*Defines to set influence samples dirty*/
	void setInfluenceSamplesDirty(const IntID& aisd){fprintf_s(mFile,"connectAttr \"");aisd.write(mFile);fprintf_s(mFile,"\" \"%s.aisd\";\n",mName.c_str());}
	/*Defines to set influence map dirty*/
	void setInfluenceMapDirty(int aimd){if(aimd == 0.0) return; fprintf_s(mFile, "setAttr \".aimd\" %i;\n", aimd);}
	/*Defines to set influence map dirty*/
	void setInfluenceMapDirty(const IntID& aimd){fprintf_s(mFile,"connectAttr \"");aimd.write(mFile);fprintf_s(mFile,"\" \"%s.aimd\";\n",mName.c_str());}
	/*Defines to set the point along the hair feedback, in world units, at which the hair feedback will start being influenced. In general, this value should be 0.0, unless you want the hair feedback to grow in its normal direction up to a point along the hair feedback.*/
	void setStartLength(double dasl){if(dasl == 0) return; fprintf_s(mFile, "setAttr \".dasl\" %f;\n", dasl);}
	/*Defines to set the point along the hair feedback, in world units, at which the hair feedback will start being influenced. In general, this value should be 0.0, unless you want the hair feedback to grow in its normal direction up to a point along the hair feedback.*/
	void setStartLength(const DoubleID& dasl){fprintf_s(mFile,"connectAttr \"");dasl.write(mFile);fprintf_s(mFile,"\" \"%s.dasl\";\n",mName.c_str());}
	/*Used to store feedback attractor start length  samples.*/
	void setStartLengthSamples(size_t asls_i,double asls){if(asls == 0.0) return; fprintf_s(mFile, "setAttr \".asls[%i]\" %f;\n", asls_i,asls);}
	/*Used to map values for feedback attractor set attribute "StartLength" by importing file textures.*/
	void setStartLengthMap(const string& aslm){if(aslm == "n/a") return; fprintf_s(mFile, "setAttr \".aslm\" -type \"string\" ");aslm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setStartLengthMapOffset(double aslmo){if(aslmo == 0) return; fprintf_s(mFile, "setAttr \".aslmo\" %f;\n", aslmo);}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setStartLengthMapOffset(const DoubleID& aslmo){fprintf_s(mFile,"connectAttr \"");aslmo.write(mFile);fprintf_s(mFile,"\" \"%s.aslmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setStartLengthMapMult(double aslmm){if(aslmm == 1) return; fprintf_s(mFile, "setAttr \".aslmm\" %f;\n", aslmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setStartLengthMapMult(const DoubleID& aslmm){fprintf_s(mFile,"connectAttr \"");aslmm.write(mFile);fprintf_s(mFile,"\" \"%s.aslmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setStartLengthNoise(double asln){if(asln == 0) return; fprintf_s(mFile, "setAttr \".asln\" %f;\n", asln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setStartLengthNoise(const DoubleID& asln){fprintf_s(mFile,"connectAttr \"");asln.write(mFile);fprintf_s(mFile,"\" \"%s.asln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setStartLengthNoiseFreq(float aslnf){if(aslnf == 10.0) return; fprintf_s(mFile, "setAttr \".aslnf\" %f;\n", aslnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setStartLengthNoiseFreq(const FloatID& aslnf){fprintf_s(mFile,"connectAttr \"");aslnf.write(mFile);fprintf_s(mFile,"\" \"%s.aslnf\";\n",mName.c_str());}
	/*Defines to set start length samples dirty*/
	void setStartLengthSamplesDirty(int aslsd){if(aslsd == 0.0) return; fprintf_s(mFile, "setAttr \".aslsd\" %i;\n", aslsd);}
	/*Defines to set start length samples dirty*/
	void setStartLengthSamplesDirty(const IntID& aslsd){fprintf_s(mFile,"connectAttr \"");aslsd.write(mFile);fprintf_s(mFile,"\" \"%s.aslsd\";\n",mName.c_str());}
	/*Defines to set start length map dirty*/
	void setStartLengthMapDirty(int aslmd){if(aslmd == 0.0) return; fprintf_s(mFile, "setAttr \".aslmd\" %i;\n", aslmd);}
	/*Defines to set start length map dirty*/
	void setStartLengthMapDirty(const IntID& aslmd){fprintf_s(mFile,"connectAttr \"");aslmd.write(mFile);fprintf_s(mFile,"\" \"%s.aslmd\";\n",mName.c_str());}
	/*Defines to set the point along the hair feedback, in world units, at which the hair will no longer be influenced. For the best effect, this should be at least as large as the longest hair length. With smaller values the tips of the hair feedback will not be influenced.*/
	void setEndLength(double dael){if(dael == 5) return; fprintf_s(mFile, "setAttr \".dael\" %f;\n", dael);}
	/*Defines to set the point along the hair feedback, in world units, at which the hair will no longer be influenced. For the best effect, this should be at least as large as the longest hair length. With smaller values the tips of the hair feedback will not be influenced.*/
	void setEndLength(const DoubleID& dael){fprintf_s(mFile,"connectAttr \"");dael.write(mFile);fprintf_s(mFile,"\" \"%s.dael\";\n",mName.c_str());}
	/*Used to store feedback attractor end length samples.*/
	void setEndLengthSamples(size_t aels_i,double aels){if(aels == 0.0) return; fprintf_s(mFile, "setAttr \".aels[%i]\" %f;\n", aels_i,aels);}
	/*Used to map values for feedback attractor set attribute "EndLength" by importing file textures.*/
	void setEndLengthMap(const string& aelm){if(aelm == "n/a") return; fprintf_s(mFile, "setAttr \".aelm\" -type \"string\" ");aelm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setEndLengthMapOffset(double aelmo){if(aelmo == 0) return; fprintf_s(mFile, "setAttr \".aelmo\" %f;\n", aelmo);}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setEndLengthMapOffset(const DoubleID& aelmo){fprintf_s(mFile,"connectAttr \"");aelmo.write(mFile);fprintf_s(mFile,"\" \"%s.aelmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setEndLengthMapMult(double aelmm){if(aelmm == 1) return; fprintf_s(mFile, "setAttr \".aelmm\" %f;\n", aelmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setEndLengthMapMult(const DoubleID& aelmm){fprintf_s(mFile,"connectAttr \"");aelmm.write(mFile);fprintf_s(mFile,"\" \"%s.aelmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setEndLengthNoise(double aeln){if(aeln == 0) return; fprintf_s(mFile, "setAttr \".aeln\" %f;\n", aeln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setEndLengthNoise(const DoubleID& aeln){fprintf_s(mFile,"connectAttr \"");aeln.write(mFile);fprintf_s(mFile,"\" \"%s.aeln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setEndLengthNoiseFreq(float aelnf){if(aelnf == 10.0) return; fprintf_s(mFile, "setAttr \".aelnf\" %f;\n", aelnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setEndLengthNoiseFreq(const FloatID& aelnf){fprintf_s(mFile,"connectAttr \"");aelnf.write(mFile);fprintf_s(mFile,"\" \"%s.aelnf\";\n",mName.c_str());}
	/*Defines to set end length samples dirty*/
	void setEndLengthSamplesDirty(int aelsd){if(aelsd == 0.0) return; fprintf_s(mFile, "setAttr \".aelsd\" %i;\n", aelsd);}
	/*Defines to set end length samples dirty*/
	void setEndLengthSamplesDirty(const IntID& aelsd){fprintf_s(mFile,"connectAttr \"");aelsd.write(mFile);fprintf_s(mFile,"\" \"%s.aelsd\";\n",mName.c_str());}
	/*Defines to set end length map dirty*/
	void setEndLengthMapDirty(int aelmd){if(aelmd == 0.0) return; fprintf_s(mFile, "setAttr \".aelmd\" %i;\n", aelmd);}
	/*Defines to set end length map dirty*/
	void setEndLengthMapDirty(const IntID& aelmd){fprintf_s(mFile,"connectAttr \"");aelmd.write(mFile);fprintf_s(mFile,"\" \"%s.aelmd\";\n",mName.c_str());}
	/*Hairs shorter than this value will not be influenced at all. Use this value to prevent short hairs from being influenced while long hairs are influenced.*/
	void setThresholdLength(double datl){if(datl == 0) return; fprintf_s(mFile, "setAttr \".datl\" %f;\n", datl);}
	/*Hairs shorter than this value will not be influenced at all. Use this value to prevent short hairs from being influenced while long hairs are influenced.*/
	void setThresholdLength(const DoubleID& datl){fprintf_s(mFile,"connectAttr \"");datl.write(mFile);fprintf_s(mFile,"\" \"%s.datl\";\n",mName.c_str());}
	/*Used to store feedback attractor threshold length samples.*/
	void setThresholdLengthSamples(size_t atls_i,double atls){if(atls == 0.0) return; fprintf_s(mFile, "setAttr \".atls[%i]\" %f;\n", atls_i,atls);}
	/*Used to map values for feedback attractor set attribute "ThresholdLength" by importing file textures.*/
	void setThresholdLengthMap(const string& atlm){if(atlm == "n/a") return; fprintf_s(mFile, "setAttr \".atlm\" -type \"string\" ");atlm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setThresholdLengthMapOffset(double atlmo){if(atlmo == 0) return; fprintf_s(mFile, "setAttr \".atlmo\" %f;\n", atlmo);}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	void setThresholdLengthMapOffset(const DoubleID& atlmo){fprintf_s(mFile,"connectAttr \"");atlmo.write(mFile);fprintf_s(mFile,"\" \"%s.atlmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setThresholdLengthMapMult(double atlmm){if(atlmm == 1) return; fprintf_s(mFile, "setAttr \".atlmm\" %f;\n", atlmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setThresholdLengthMapMult(const DoubleID& atlmm){fprintf_s(mFile,"connectAttr \"");atlmm.write(mFile);fprintf_s(mFile,"\" \"%s.atlmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setThresholdLengthNoise(double atln){if(atln == 0) return; fprintf_s(mFile, "setAttr \".atln\" %f;\n", atln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setThresholdLengthNoise(const DoubleID& atln){fprintf_s(mFile,"connectAttr \"");atln.write(mFile);fprintf_s(mFile,"\" \"%s.atln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setThresholdLengthNoiseFreq(float atlnf){if(atlnf == 10.0) return; fprintf_s(mFile, "setAttr \".atlnf\" %f;\n", atlnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setThresholdLengthNoiseFreq(const FloatID& atlnf){fprintf_s(mFile,"connectAttr \"");atlnf.write(mFile);fprintf_s(mFile,"\" \"%s.atlnf\";\n",mName.c_str());}
	/*Defines to set threshold length samples dirty*/
	void setThresholdLengthSamplesDirty(int atlsd){if(atlsd == 0.0) return; fprintf_s(mFile, "setAttr \".atlsd\" %i;\n", atlsd);}
	/*Defines to set threshold length samples dirty*/
	void setThresholdLengthSamplesDirty(const IntID& atlsd){fprintf_s(mFile,"connectAttr \"");atlsd.write(mFile);fprintf_s(mFile,"\" \"%s.atlsd\";\n",mName.c_str());}
	/*Defines to set threshold length map dirty*/
	void setThresholdLengthMapDirty(int atlmd){if(atlmd == 0.0) return; fprintf_s(mFile, "setAttr \".atlmd\" %i;\n", atlmd);}
	/*Defines to set threshold length map dirty*/
	void setThresholdLengthMapDirty(const IntID& atlmd){fprintf_s(mFile,"connectAttr \"");atlmd.write(mFile);fprintf_s(mFile,"\" \"%s.atlmd\";\n",mName.c_str());}
	/*
	This is an unused hair attribute that can be used as a dummy
	attribute or for painting some additional attribute not already covered
	*/
	void setUnused(float dun){if(dun == 1.0) return; fprintf_s(mFile, "setAttr \".dun\" %f;\n", dun);}
	/*
	This is an unused hair attribute that can be used as a dummy
	attribute or for painting some additional attribute not already covered
	*/
	void setUnused(const FloatID& dun){fprintf_s(mFile,"connectAttr \"");dun.write(mFile);fprintf_s(mFile,"\" \"%s.dun\";\n",mName.c_str());}
	/*Used to store fur feedback unused samples.*/
	void setUnusedSamples(size_t uns_i,double uns){if(uns == 0.0) return; fprintf_s(mFile, "setAttr \".uns[%i]\" %f;\n", uns_i,uns);}
	/*Used to map values for fur feedback attribute "Unused" by importing file textures.*/
	void setUnusedMap(const string& unm){if(unm == "n/a") return; fprintf_s(mFile, "setAttr \".unm\" -type \"string\" ");unm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setUnusedMapOffset(float unmo){if(unmo == 0.0) return; fprintf_s(mFile, "setAttr \".unmo\" %f;\n", unmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setUnusedMapOffset(const FloatID& unmo){fprintf_s(mFile,"connectAttr \"");unmo.write(mFile);fprintf_s(mFile,"\" \"%s.unmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setUnusedMapMult(float unmm){if(unmm == 1.0) return; fprintf_s(mFile, "setAttr \".unmm\" %f;\n", unmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setUnusedMapMult(const FloatID& unmm){fprintf_s(mFile,"connectAttr \"");unmm.write(mFile);fprintf_s(mFile,"\" \"%s.unmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setUnusedNoise(float unn){if(unn == 0.0) return; fprintf_s(mFile, "setAttr \".unn\" %f;\n", unn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setUnusedNoise(const FloatID& unn){fprintf_s(mFile,"connectAttr \"");unn.write(mFile);fprintf_s(mFile,"\" \"%s.unn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setUnusedNoiseFreq(float unnf){if(unnf == 10.0) return; fprintf_s(mFile, "setAttr \".unnf\" %f;\n", unnf);}
	/*Defines to set unused samples dirty*/
	void setUnusedSamplesDirty(int unsd){if(unsd == 0.0) return; fprintf_s(mFile, "setAttr \".unsd\" %i;\n", unsd);}
	/*Defines to set unused samples dirty*/
	void setUnusedSamplesDirty(const IntID& unsd){fprintf_s(mFile,"connectAttr \"");unsd.write(mFile);fprintf_s(mFile,"\" \"%s.unsd\";\n",mName.c_str());}
	/*Defines to set unused map dirty*/
	void setUnusedMapDirty(int unmd){if(unmd == 0.0) return; fprintf_s(mFile, "setAttr \".unmd\" %i;\n", unmd);}
	/*Defines to set unused map dirty*/
	void setUnusedMapDirty(const IntID& unmd){fprintf_s(mFile,"connectAttr \"");unmd.write(mFile);fprintf_s(mFile,"\" \"%s.unmd\";\n",mName.c_str());}
	/*An equalizer compensates for the uneven distribution of fur caused by uneven parameterization so that fur is evenly distributed across the surface.*/
	void setEqualizer(float dem){if(dem == 1.0) return; fprintf_s(mFile, "setAttr \".dem\" %f;\n", dem);}
	/*An equalizer compensates for the uneven distribution of fur caused by uneven parameterization so that fur is evenly distributed across the surface.*/
	void setEqualizer(const FloatID& dem){fprintf_s(mFile,"connectAttr \"");dem.write(mFile);fprintf_s(mFile,"\" \"%s.dem\";\n",mName.c_str());}
	/*Used to store fur feedback equalizer samples.*/
	void setEqualizerSamples(size_t ems_i,double ems){if(ems == 0.0) return; fprintf_s(mFile, "setAttr \".ems[%i]\" %f;\n", ems_i,ems);}
	/*Used to map values for fur feedback attribute "Equalizer" by importing file textures.*/
	void setEqualizerMap(const string& emm){if(emm == "n/a") return; fprintf_s(mFile, "setAttr \".emm\" -type \"string\" ");emm.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setEqualizerMapOffset(float emmo){if(emmo == 0.0) return; fprintf_s(mFile, "setAttr \".emmo\" %f;\n", emmo);}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	void setEqualizerMapOffset(const FloatID& emmo){fprintf_s(mFile,"connectAttr \"");emmo.write(mFile);fprintf_s(mFile,"\" \"%s.emmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setEqualizerMapMult(float emmm){if(emmm == 1.0) return; fprintf_s(mFile, "setAttr \".emmm\" %f;\n", emmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setEqualizerMapMult(const FloatID& emmm){fprintf_s(mFile,"connectAttr \"");emmm.write(mFile);fprintf_s(mFile,"\" \"%s.emmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setEqualizerNoise(float emn){if(emn == 0.0) return; fprintf_s(mFile, "setAttr \".emn\" %f;\n", emn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setEqualizerNoise(const FloatID& emn){fprintf_s(mFile,"connectAttr \"");emn.write(mFile);fprintf_s(mFile,"\" \"%s.emn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setEqualizerNoiseFreq(float emnf){if(emnf == 10.0) return; fprintf_s(mFile, "setAttr \".emnf\" %f;\n", emnf);}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setEqualizerNoiseFreq(const FloatID& emnf){fprintf_s(mFile,"connectAttr \"");emnf.write(mFile);fprintf_s(mFile,"\" \"%s.emnf\";\n",mName.c_str());}
	/*Defines to set equalizer samples dirty*/
	void setEqualizerSamplesDirty(int emsd){if(emsd == 0.0) return; fprintf_s(mFile, "setAttr \".emsd\" %i;\n", emsd);}
	/*Defines to set equalizer samples dirty*/
	void setEqualizerSamplesDirty(const IntID& emsd){fprintf_s(mFile,"connectAttr \"");emsd.write(mFile);fprintf_s(mFile,"\" \"%s.emsd\";\n",mName.c_str());}
	/*Defines to set equalizer map dirty*/
	void setEqualizerMapDirty(int emmd){if(emmd == 0.0) return; fprintf_s(mFile, "setAttr \".emmd\" %i;\n", emmd);}
	/*Defines to set equalizer map dirty*/
	void setEqualizerMapDirty(const IntID& emmd){fprintf_s(mFile,"connectAttr \"");emmd.write(mFile);fprintf_s(mFile,"\" \"%s.emmd\";\n",mName.c_str());}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the render settings for this shape node.
	*/
	void setMiOverrideCaustics(bool oca){if(oca == false) return; fprintf_s(mFile, "setAttr \".mrc.oca\" %i;\n", oca);}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the render settings for this shape node.
	*/
	void setMiOverrideCaustics(const BoolID& oca){fprintf_s(mFile,"connectAttr \"");oca.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oca\";\n",mName.c_str());}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(short caa){if(caa == 64) return; fprintf_s(mFile, "setAttr \".mrc.caa\" %i;\n", caa);}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(const ShortID& caa){fprintf_s(mFile,"connectAttr \"");caa.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.caa\";\n",mName.c_str());}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(float car){if(car == 0) return; fprintf_s(mFile, "setAttr \".mrc.car\" %f;\n", car);}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(const FloatID& car){fprintf_s(mFile,"connectAttr \"");car.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.car\";\n",mName.c_str());}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the render settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(bool ogi){if(ogi == false) return; fprintf_s(mFile, "setAttr \".mrc.ogi\" %i;\n", ogi);}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the render settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(const BoolID& ogi){fprintf_s(mFile,"connectAttr \"");ogi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ogi\";\n",mName.c_str());}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(short gia){if(gia == 64) return; fprintf_s(mFile, "setAttr \".mrc.gia\" %i;\n", gia);}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(const ShortID& gia){fprintf_s(mFile,"connectAttr \"");gia.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gia\";\n",mName.c_str());}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(float gir){if(gir == 0) return; fprintf_s(mFile, "setAttr \".mrc.gir\" %f;\n", gir);}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(const FloatID& gir){fprintf_s(mFile,"connectAttr \"");gir.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gir\";\n",mName.c_str());}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the render settings for this shape node.
	*/
	void setMiOverrideFinalGather(bool ofg){if(ofg == false) return; fprintf_s(mFile, "setAttr \".mrc.ofg\" %i;\n", ofg);}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the render settings for this shape node.
	*/
	void setMiOverrideFinalGather(const BoolID& ofg){fprintf_s(mFile,"connectAttr \"");ofg.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ofg\";\n",mName.c_str());}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(int fry){if(fry == 1000) return; fprintf_s(mFile, "setAttr \".mrc.fry\" %i;\n", fry);}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(const IntID& fry){fprintf_s(mFile,"connectAttr \"");fry.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fry\";\n",mName.c_str());}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(float fmn){if(fmn == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmn\" %f;\n", fmn);}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(const FloatID& fmn){fprintf_s(mFile,"connectAttr \"");fmn.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmn\";\n",mName.c_str());}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(float fmx){if(fmx == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmx\" %f;\n", fmx);}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(const FloatID& fmx){fprintf_s(mFile,"connectAttr \"");fmx.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmx\";\n",mName.c_str());}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(short ffi){if(ffi == 1) return; fprintf_s(mFile, "setAttr \".mrc.ffi\" %i;\n", ffi);}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(const ShortID& ffi){fprintf_s(mFile,"connectAttr \"");ffi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ffi\";\n",mName.c_str());}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(bool fgv){if(fgv == false) return; fprintf_s(mFile, "setAttr \".mrc.fgv\" %i;\n", fgv);}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(const BoolID& fgv){fprintf_s(mFile,"connectAttr \"");fgv.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgv\";\n",mName.c_str());}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	void setMiOverrideSamples(bool oos){if(oos == false) return; fprintf_s(mFile, "setAttr \".mrc.oos\" %i;\n", oos);}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	void setMiOverrideSamples(const BoolID& oos){fprintf_s(mFile,"connectAttr \"");oos.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oos\";\n",mName.c_str());}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(short mins){if(mins == -2) return; fprintf_s(mFile, "setAttr \".mrc.mins\" %i;\n", mins);}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(const ShortID& mins){fprintf_s(mFile,"connectAttr \"");mins.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mins\";\n",mName.c_str());}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(short maxs){if(maxs == 0) return; fprintf_s(mFile, "setAttr \".mrc.maxs\" %i;\n", maxs);}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(const ShortID& maxs){fprintf_s(mFile,"connectAttr \"");maxs.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.maxs\";\n",mName.c_str());}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	void setMiFinalGatherCast(bool fgc){if(fgc == true) return; fprintf_s(mFile, "setAttr \".mrc.fgc\" %i;\n", fgc);}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	void setMiFinalGatherCast(const BoolID& fgc){fprintf_s(mFile,"connectAttr \"");fgc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgc\";\n",mName.c_str());}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	void setMiFinalGatherReceive(bool fge){if(fge == true) return; fprintf_s(mFile, "setAttr \".mrc.fge\" %i;\n", fge);}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	void setMiFinalGatherReceive(const BoolID& fge){fprintf_s(mFile,"connectAttr \"");fge.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fge\";\n",mName.c_str());}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	void setMiTransparencyCast(bool tpc){if(tpc == true) return; fprintf_s(mFile, "setAttr \".mrc.tpc\" %i;\n", tpc);}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	void setMiTransparencyCast(const BoolID& tpc){fprintf_s(mFile,"connectAttr \"");tpc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.tpc\";\n",mName.c_str());}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	void setMiTransparencyReceive(bool tpr){if(tpr == true) return; fprintf_s(mFile, "setAttr \".mrc.tpr\" %i;\n", tpr);}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	void setMiTransparencyReceive(const BoolID& tpr){fprintf_s(mFile,"connectAttr \"");tpr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.tpr\";\n",mName.c_str());}
	/*Input surface.*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*The input mesh.*/
	MeshID getInputMesh(){char buffer[4096];sprintf_s (buffer, "%s.imsh",mName.c_str());return (const char*)buffer;}
	/*Set the number of U Samples to define how many fur feedback hairs display on the surface.*/
	IntID getRealUSamples(){char buffer[4096];sprintf_s (buffer, "%s.rus",mName.c_str());return (const char*)buffer;}
	/*Set the number of V Samples to define how many fur feedback hairs display on the surface.*/
	IntID getRealVSamples(){char buffer[4096];sprintf_s (buffer, "%s.rvs",mName.c_str());return (const char*)buffer;}
	/*Set the number of U Samples to define how many fur feedback hairs display on the surface.*/
	IntID getUSamples(){char buffer[4096];sprintf_s (buffer, "%s.us",mName.c_str());return (const char*)buffer;}
	/*Set the number of V Samples to define how many fur feedback hairs display on the surface*/
	IntID getVSamples(){char buffer[4096];sprintf_s (buffer, "%s.vs",mName.c_str());return (const char*)buffer;}
	/*Reverse the fur feedback normal.*/
	BoolID getFlipNormals(){char buffer[4096];sprintf_s (buffer, "%s.fn",mName.c_str());return (const char*)buffer;}
	/*
	Set how closely the fur feedback resembles the appearance of the final rendered fur.
	A value of 0 represents the hairs as straight lines, regardless of any curl, scraggle, or attraction.
	A value of 1 uses the same number of segments for each hair in the fur feedback that will be used for the actual render, but significantly slows interaction
	*/
	FloatID getFurAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.ha",mName.c_str());return (const char*)buffer;}
	/*Define to scale the fur feedback uniformly. This is used to adjust the Base Width, Tip Width, Length, and Offset values by a common factor (including mapped values).*/
	FloatID getFurGlobalScale(){char buffer[4096];sprintf_s (buffer, "%s.fgs",mName.c_str());return (const char*)buffer;}
	/*Defines to adjust the Radius, Power, Influence, and Length values by a common factor (including mapped values).*/
	FloatID getAttractorGlobalScale(){char buffer[4096];sprintf_s (buffer, "%s.ags",mName.c_str());return (const char*)buffer;}
	/*Set attribute map width.*/
	IntID getExportWidth(){char buffer[4096];sprintf_s (buffer, "%s.ew",mName.c_str());return (const char*)buffer;}
	/*Set attribute map height.*/
	IntID getExportHeight(){char buffer[4096];sprintf_s (buffer, "%s.eh",mName.c_str());return (const char*)buffer;}
	/*Sets the color of the fur feedback to be the same as the actual fur color for the fur description.*/
	BoolID getColorFeedbackEnabled(){char buffer[4096];sprintf_s (buffer, "%s.cfe",mName.c_str());return (const char*)buffer;}
	/*Defines to connect without data flow between individual attractor and attractor set.*/
	AttractorsID getAttractors(){char buffer[4096];sprintf_s (buffer, "%s.atr",mName.c_str());return (const char*)buffer;}
	/*
	Defines the type of attractor.
	0-Local Each hair mimics the closest attractor(s) within the defined radius.
	1-Global Each hair grows towards the closest attractor(s) within the defined radius.
	*/
	UnsignedintID getAttractorModel(){char buffer[4096];sprintf_s (buffer, "%s.amd",mName.c_str());return (const char*)buffer;}
	/*
	Defines the number of attractors a hair should be influenced by.
	e.g. 1 Every hair is influenced by one attractor closest to it.
	2 Every hair is influenced by two attractors closest to it.
	3 Every hair is influenced by three attractors closest to it
	*/
	IntID getAttractorsPerHair(){char buffer[4096];sprintf_s (buffer, "%s.aph",mName.c_str());return (const char*)buffer;}
	/*
	true: Display feedback indicating that attractors are attached to the surface.
	false: Don't Display feedback indicating that attractors are attached to the surface.
	*/
	BoolID getDrawAttractors(){char buffer[4096];sprintf_s (buffer, "%s.drat",mName.c_str());return (const char*)buffer;}
	/*Defines the fur feedback length in world units.*/
	DoubleID getLength(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	DoubleID getLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.lmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.lmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.ln",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getLengthNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.lnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set length samples dirty*/
	IntID getLengthSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.lsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set length map dirty*/
	IntID getLengthMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.lmd",mName.c_str());return (const char*)buffer;}
	/*
	Sets the amount of fur feedback inclination.
	0.0-No inclination. The fur is fully erect (normal to the surface). This is the default.
	0.5-Partial inclination. 1.0- Fully inclined. The fur lies flat (tangent to the surface at the root).
	*/
	FloatID getInclination(){char buffer[4096];sprintf_s (buffer, "%s.din",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getInclinationMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.inmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getInclinationMapMult(){char buffer[4096];sprintf_s (buffer, "%s.inmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getInclinationNoise(){char buffer[4096];sprintf_s (buffer, "%s.inn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getInclinationNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.innf",mName.c_str());return (const char*)buffer;}
	/*Defines to set inclination samples dirty*/
	IntID getInclinationSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.insd",mName.c_str());return (const char*)buffer;}
	/*Defines to set inclination map dirty*/
	IntID getInclinationMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.inmd",mName.c_str());return (const char*)buffer;}
	/*
	Rotates the fur feedback about the surface V axis. You can achieve almost any fur feedback angle using Polar and Inclination, so use this option only when the fur feedback has curl and you want the curls to lie flat.
	0.0-90 degree rotation. 0.5-No rotation. This is the default.1.0-90 degree rotation.
	*/
	FloatID getRoll(){char buffer[4096];sprintf_s (buffer, "%s.drl",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getRollMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.rlmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getRollMapMult(){char buffer[4096];sprintf_s (buffer, "%s.rlmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getRollNoise(){char buffer[4096];sprintf_s (buffer, "%s.rln",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getRollNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.rlnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set roll samples dirty*/
	IntID getRollSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.rlsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set roll map dirty*/
	IntID getRollMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.rlmd",mName.c_str());return (const char*)buffer;}
	/*
	Rotates the fur feedback about the surface normal.
	0.0-180 degree rotation. 0.5-No rotation. This is the default. 1.0-180 degree rotation.
	*/
	FloatID getPolar(){char buffer[4096];sprintf_s (buffer, "%s.dpo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getPolarMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.pomo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getPolarMapMult(){char buffer[4096];sprintf_s (buffer, "%s.pomm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getPolarNoise(){char buffer[4096];sprintf_s (buffer, "%s.pon",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getPolarNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.ponf",mName.c_str());return (const char*)buffer;}
	/*Defines to set polar samples dirty*/
	IntID getPolarSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.posd",mName.c_str());return (const char*)buffer;}
	/*Defines to set polar map dirty*/
	IntID getPolarMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.pomd",mName.c_str());return (const char*)buffer;}
	/*
	Defines how much fur feedback is on the surface.
	1.0-Full fur 0.0-Total baldness.
	*/
	FloatID getBaldness(){char buffer[4096];sprintf_s (buffer, "%s.db",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getBaldnessMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.bmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getBaldnessMapMult(){char buffer[4096];sprintf_s (buffer, "%s.bmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getBaldnessNoise(){char buffer[4096];sprintf_s (buffer, "%s.bn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getBaldnessNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.bnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set baldness samples dirty*/
	IntID getBaldnessSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.bsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set baldness map dirty*/
	IntID getBaldnessMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.bmd",mName.c_str());return (const char*)buffer;}
	/*
	Defines the opacity of the fur feedback base.
	0.0-Completely transparent base. 1.0-Completely opaque base.
	*/
	FloatID getBaseOpacity(){char buffer[4096];sprintf_s (buffer, "%s.dbo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getBaseOpacityMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.bomo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getBaseOpacityMapMult(){char buffer[4096];sprintf_s (buffer, "%s.bomm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getBaseOpacityNoise(){char buffer[4096];sprintf_s (buffer, "%s.bon",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getBaseOpacityNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.bonf",mName.c_str());return (const char*)buffer;}
	/*Defines to set base opacity samples dirty*/
	IntID getBaseOpacitySamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.bosd",mName.c_str());return (const char*)buffer;}
	/*Defines to set base opacity map dirty*/
	IntID getBaseOpacityMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.bomd",mName.c_str());return (const char*)buffer;}
	/*
	Defines the opacity of the fur feedback tip.
	0.0-Completely transparent tip. 1.0-Completely opaque tip.
	*/
	FloatID getTipOpacity(){char buffer[4096];sprintf_s (buffer, "%s.dto",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getTipOpacityMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.tomo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getTipOpacityMapMult(){char buffer[4096];sprintf_s (buffer, "%s.tomm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getTipOpacityNoise(){char buffer[4096];sprintf_s (buffer, "%s.ton",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getTipOpacityNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.tonf",mName.c_str());return (const char*)buffer;}
	/*Defines to set tip opacity samples dirty*/
	IntID getTipOpacitySamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.tosd",mName.c_str());return (const char*)buffer;}
	/*Defines to set tip opacity map dirty*/
	IntID getTipOpacityMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.tomd",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount of curl at the base of the fur feedback. The fur feedback tip is not influenced by this value.
	0.0- Half-circle curl to one side. 0.5-No curl. 1.0-Half-circle curl to the other side.
	*/
	FloatID getBaseCurl(){char buffer[4096];sprintf_s (buffer, "%s.dbcl",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getBaseCurlMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.bclmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getBaseCurlMapMult(){char buffer[4096];sprintf_s (buffer, "%s.bclmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getBaseCurlNoise(){char buffer[4096];sprintf_s (buffer, "%s.bcln",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getBaseCurlNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.bclnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set base curl samples dirty*/
	IntID getBaseCurlSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.bclsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set base curl map dirty*/
	IntID getBaseCurlMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.bclmd",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount of curl at the tip of the fur feedback. The fur feedback base is not influenced by this value.
	0.0-Half-circle curl to one side. 0.5-No curl. 1.0- Half-circle curl to the other side
	*/
	FloatID getTipCurl(){char buffer[4096];sprintf_s (buffer, "%s.dtcl",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getTipCurlMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.tclmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getTipCurlMapMult(){char buffer[4096];sprintf_s (buffer, "%s.tclmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getTipCurlNoise(){char buffer[4096];sprintf_s (buffer, "%s.tcln",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getTipCurlNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.tclnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set tip curl samples dirty*/
	IntID getTipCurlSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.tclsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set tip curl map dirty*/
	IntID getTipCurlMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.tclmd",mName.c_str());return (const char*)buffer;}
	/*Defines the width of each hair feedback at the base, in world units.*/
	DoubleID getBaseWidth(){char buffer[4096];sprintf_s (buffer, "%s.dbw",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	DoubleID getBaseWidthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.bwmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getBaseWidthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.bwmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getBaseWidthNoise(){char buffer[4096];sprintf_s (buffer, "%s.bwn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getBaseWidthNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.bwnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set base width samples dirty*/
	IntID getBaseWidthSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.bwsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set base width map dirty*/
	IntID getBaseWidthMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.bwmd",mName.c_str());return (const char*)buffer;}
	/*Defines the width of each hair feedback at the tip, in world units.*/
	DoubleID getTipWidth(){char buffer[4096];sprintf_s (buffer, "%s.dtw",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	DoubleID getTipWidthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.twmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getTipWidthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.twmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getTipWidthNoise(){char buffer[4096];sprintf_s (buffer, "%s.twn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getTipWidthNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.twnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set tip width samples dirty*/
	IntID getTipWidthSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.twsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set tip width map dirty*/
	IntID getTipWidthMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.twmd",mName.c_str());return (const char*)buffer;}
	/*
	Defines how crooked the fur feedback is.
	0.0-No scraggle. 1.0-Full scraggle.
	*/
	FloatID getScraggle(){char buffer[4096];sprintf_s (buffer, "%s.ds",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getScraggleMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.smo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getScraggleMapMult(){char buffer[4096];sprintf_s (buffer, "%s.smm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getScraggleNoise(){char buffer[4096];sprintf_s (buffer, "%s.sn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getScraggleNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.snf",mName.c_str());return (const char*)buffer;}
	/*Defines to set scraggle samples dirty*/
	IntID getScraggleSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.ssd",mName.c_str());return (const char*)buffer;}
	/*Defines to set scraggle map dirty*/
	IntID getScraggleMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.smd",mName.c_str());return (const char*)buffer;}
	/*
	Defines how the scraggle of each hair feedback relates to each other hair feedback.
	0.0-No correlation, so each hair has a unique scraggle. 1.0-Total correlation, so all hair "scraggle" in exactly the same way.
	*/
	FloatID getScraggleCorrelation(){char buffer[4096];sprintf_s (buffer, "%s.dsco",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getScraggleCorrelationMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.scomo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getScraggleCorrelationMapMult(){char buffer[4096];sprintf_s (buffer, "%s.scomm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getScraggleCorrelationNoise(){char buffer[4096];sprintf_s (buffer, "%s.scon",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getScraggleCorrelationNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.sconf",mName.c_str());return (const char*)buffer;}
	/*Defines to set scraggle correlation samples dirty*/
	IntID getScraggleCorrelationSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.scosd",mName.c_str());return (const char*)buffer;}
	/*Defines to set scraggle correlation map dirty*/
	IntID getScraggleCorrelationMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.scomd",mName.c_str());return (const char*)buffer;}
	/*Defines the amount of change over each length of hair feedback. The higher the value, the more changes there will be along each length of hair feedback (the hair feedback becomes more deformed).*/
	FloatID getScraggleFrequency(){char buffer[4096];sprintf_s (buffer, "%s.dscf",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getScraggleFrequencyMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.scfmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getScraggleFrequencyMapMult(){char buffer[4096];sprintf_s (buffer, "%s.scfmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getScraggleFrequencyNoise(){char buffer[4096];sprintf_s (buffer, "%s.scfn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getScraggleFrequencyNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.scfnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set scraggle frequency samples dirty*/
	IntID getScraggleFrequencySamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.scfsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set scraggle frequency map dirty*/
	IntID getScraggleFrequencyMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.scfmd",mName.c_str());return (const char*)buffer;}
	/*Defines the number of segments each fur feedback is comprised of. For smoother curves, use more segments.*/
	FloatID getSegments(){char buffer[4096];sprintf_s (buffer, "%s.dseg",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getSegmentsMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.segmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getSegmentsMapMult(){char buffer[4096];sprintf_s (buffer, "%s.segmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getSegmentsNoise(){char buffer[4096];sprintf_s (buffer, "%s.segn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getSegmentsNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.segnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set segments samples dirty*/
	IntID getSegmentsSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.segsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set segments map dirty*/
	IntID getSegmentsMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.segmd",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount of attraction this fur feedback has towards attractors.
	0.0 No attraction. 1.0 Full attraction.
	*/
	FloatID getAttraction(){char buffer[4096];sprintf_s (buffer, "%s.dat",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getAttractionMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.atmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getAttractionMapMult(){char buffer[4096];sprintf_s (buffer, "%s.atmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getAttractionNoise(){char buffer[4096];sprintf_s (buffer, "%s.atn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getAttractionNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.atnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set attraction samples dirty*/
	IntID getAttractionSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.atsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set attraction map dirty*/
	IntID getAttractionMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.atmd",mName.c_str());return (const char*)buffer;}
	/*
	Defines how much to offset the fur feedback (in world units) from the surface it is attached to.
	When the Offset value is 0, the roots of the fur feedback start growing from the surface.
	When the value is less than zero, the roots start growing from inside the surface.
	When the value is greater than zero, the roots start growing from outside the surface
	*/
	DoubleID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.dofs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	DoubleID getOffsetMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.ofsmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getOffsetMapMult(){char buffer[4096];sprintf_s (buffer, "%s.ofsmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getOffsetNoise(){char buffer[4096];sprintf_s (buffer, "%s.ofsn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getOffsetNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.ofsnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set offset samples dirty*/
	IntID getOffsetSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.ofssd",mName.c_str());return (const char*)buffer;}
	/*Defines to set offset map dirty*/
	IntID getOffsetMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.ofsmd",mName.c_str());return (const char*)buffer;}
	/*
	The degree to which the hairs are pulled in towards the centreof the clump.
	The higher the clumping value, the more the hairs are pulled in.
	The defaultis 0, which means no clumping.
	*/
	FloatID getClumping(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to offset the fur feedback attribute. The initial map is between 0 and 1.*/
	FloatID getClumpingMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.cmo",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getClumpingMapMult(){char buffer[4096];sprintf_s (buffer, "%s.cmm",mName.c_str());return (const char*)buffer;}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getClumpingNoise(){char buffer[4096];sprintf_s (buffer, "%s.cn",mName.c_str());return (const char*)buffer;}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getClumpingNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.cnf",mName.c_str());return (const char*)buffer;}
	/*Used to set clumping samples dirty*/
	IntID getClumpingSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.csd",mName.c_str());return (const char*)buffer;}
	/*Used to set clumping map dirty*/
	IntID getClumpingMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.cmd",mName.c_str());return (const char*)buffer;}
	/*
	Controls how many clumps occur across the surface.
	The higher the frequency, the greater the number, and therefore smaller-sized, clumps.
	The default is 0.0.As you increase the Clumping Frequency, the rendering time increases.
	*/
	FloatID getClumpingFrequency(){char buffer[4096];sprintf_s (buffer, "%s.dcf",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to offset the fur feedback attribute. The initial map is between 0 and 1.*/
	FloatID getClumpingFrequencyMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.cfmo",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getClumpingFrequencyMapMult(){char buffer[4096];sprintf_s (buffer, "%s.cfmm",mName.c_str());return (const char*)buffer;}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getClumpingFrequencyNoise(){char buffer[4096];sprintf_s (buffer, "%s.cfn",mName.c_str());return (const char*)buffer;}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getClumpingFrequencyNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.cfnf",mName.c_str());return (const char*)buffer;}
	/*Used to set clumpingFrequency samples dirty*/
	IntID getClumpingFrequencySamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.cfsd",mName.c_str());return (const char*)buffer;}
	/*Used to set clumpingFrequency map dirty*/
	IntID getClumpingFrequencyMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.cfmd",mName.c_str());return (const char*)buffer;}
	/*
	Controls the shape of the curve of the hair as it is attracted to the center of the clump.
	A value of -10 creates a concave shape and a value of 10 creates a convex shape.
	*/
	FloatID getClumpingShape(){char buffer[4096];sprintf_s (buffer, "%s.dcs",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to offset the fur feedback attribute. The initial map is between 0 and 1.*/
	FloatID getClumpingShapeMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.csmo",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getClumpingShapeMapMult(){char buffer[4096];sprintf_s (buffer, "%s.csmm",mName.c_str());return (const char*)buffer;}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getClumpingShapeNoise(){char buffer[4096];sprintf_s (buffer, "%s.csn",mName.c_str());return (const char*)buffer;}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getClumpingShapeNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.csnf",mName.c_str());return (const char*)buffer;}
	/*Used to set clumpingShape samples dirty*/
	IntID getClumpingShapeSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.cssd",mName.c_str());return (const char*)buffer;}
	/*Used to set clumpingShape map dirty*/
	IntID getClumpingShapeMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.csmd",mName.c_str());return (const char*)buffer;}
	/*Defines the color of the fur feedback base.*/
	Float3ID getBaseColor(){char buffer[4096];sprintf_s (buffer, "%s.dbc",mName.c_str());return (const char*)buffer;}
	/*Defines the Red channel of the fur feedback base.*/
	FloatID getBaseColorR(){char buffer[4096];sprintf_s (buffer, "%s.dbcr",mName.c_str());return (const char*)buffer;}
	/*Defines the Green channel of the fur feedback base.*/
	FloatID getBaseColorG(){char buffer[4096];sprintf_s (buffer, "%s.dbcg",mName.c_str());return (const char*)buffer;}
	/*Defines the Blue channel of the fur feedback base.*/
	FloatID getBaseColorB(){char buffer[4096];sprintf_s (buffer, "%s.dbcb",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getBaseColorNoise(){char buffer[4096];sprintf_s (buffer, "%s.bcn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getBaseColorNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.bcnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set base color samples dirty*/
	IntID getBaseColorSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.bcsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set base color map dirty*/
	IntID getBaseColorMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.bcmd",mName.c_str());return (const char*)buffer;}
	/*Defines the color of the fur feedback tip.*/
	Float3ID getTipColor(){char buffer[4096];sprintf_s (buffer, "%s.dtc",mName.c_str());return (const char*)buffer;}
	/*Defines the red channel of the fur feedback tip.*/
	FloatID getTipColorR(){char buffer[4096];sprintf_s (buffer, "%s.dtcr",mName.c_str());return (const char*)buffer;}
	/*Defines the green channel of the fur feedback tip.*/
	FloatID getTipColorG(){char buffer[4096];sprintf_s (buffer, "%s.dtcg",mName.c_str());return (const char*)buffer;}
	/*Defines the blue channel of the fur feedback tip.*/
	FloatID getTipColorB(){char buffer[4096];sprintf_s (buffer, "%s.dtcb",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getTipColorNoise(){char buffer[4096];sprintf_s (buffer, "%s.tcn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getTipColorNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.tcnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set tip color samples dirty*/
	IntID getTipColorSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.tcsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set tip color map dirty*/
	IntID getTipColorMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.tcmd",mName.c_str());return (const char*)buffer;}
	/*Used to set the radius in which to search for the closest attractors, in world units. This value can help prevent hairs from being influenced by attractors that are unreasonably far away.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.dar",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getRadiusMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.armo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getRadiusMapMult(){char buffer[4096];sprintf_s (buffer, "%s.armm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getRadiusNoise(){char buffer[4096];sprintf_s (buffer, "%s.arn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getRadiusNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.arnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set radius samples dirty*/
	IntID getRadiusSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.arsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set radius map dirty*/
	IntID getRadiusMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.armd",mName.c_str());return (const char*)buffer;}
	/*
	Set how feedback attractor will influence the hairs. The value you enter is the power to a falloff function that makes hairs become less influenced at the base of the hair than at the tip.
	0.0 The entire length of the hair feedback is influenced.
	1.0 Hair is much less influenced at the base.
	*/
	FloatID getPower(){char buffer[4096];sprintf_s (buffer, "%s.dap",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	FloatID getPowerMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.apmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getPowerMapMult(){char buffer[4096];sprintf_s (buffer, "%s.apmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getPowerNoise(){char buffer[4096];sprintf_s (buffer, "%s.apn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getPowerNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.apnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set power samples dirty*/
	IntID getPowerSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.apsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set power map dirty*/
	IntID getPowerMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.apmd",mName.c_str());return (const char*)buffer;}
	/*
	Set how much influence the feedback attractor will have on the hairs. The value you enter linearly increases or decreases the influence over the length of the hair feedback.
	0.0 No influence.
	1.0 Standard influence.
	*/
	FloatID getInfluence(){char buffer[4096];sprintf_s (buffer, "%s.dai",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	FloatID getInfluenceMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.aimo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getInfluenceMapMult(){char buffer[4096];sprintf_s (buffer, "%s.aimm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getInfluenceNoise(){char buffer[4096];sprintf_s (buffer, "%s.ain",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getInfluenceNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.ainf",mName.c_str());return (const char*)buffer;}
	/*Defines to set influence samples dirty*/
	IntID getInfluenceSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.aisd",mName.c_str());return (const char*)buffer;}
	/*Defines to set influence map dirty*/
	IntID getInfluenceMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.aimd",mName.c_str());return (const char*)buffer;}
	/*Defines to set the point along the hair feedback, in world units, at which the hair feedback will start being influenced. In general, this value should be 0.0, unless you want the hair feedback to grow in its normal direction up to a point along the hair feedback.*/
	DoubleID getStartLength(){char buffer[4096];sprintf_s (buffer, "%s.dasl",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getStartLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.aslmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getStartLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.aslmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getStartLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.asln",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getStartLengthNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.aslnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set start length samples dirty*/
	IntID getStartLengthSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.aslsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set start length map dirty*/
	IntID getStartLengthMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.aslmd",mName.c_str());return (const char*)buffer;}
	/*Defines to set the point along the hair feedback, in world units, at which the hair will no longer be influenced. For the best effect, this should be at least as large as the longest hair length. With smaller values the tips of the hair feedback will not be influenced.*/
	DoubleID getEndLength(){char buffer[4096];sprintf_s (buffer, "%s.dael",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getEndLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.aelmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getEndLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.aelmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getEndLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.aeln",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getEndLengthNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.aelnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set end length samples dirty*/
	IntID getEndLengthSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.aelsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set end length map dirty*/
	IntID getEndLengthMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.aelmd",mName.c_str());return (const char*)buffer;}
	/*Hairs shorter than this value will not be influenced at all. Use this value to prevent short hairs from being influenced while long hairs are influenced.*/
	DoubleID getThresholdLength(){char buffer[4096];sprintf_s (buffer, "%s.datl",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the feedback attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getThresholdLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.atlmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getThresholdLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.atlmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getThresholdLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.atln",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getThresholdLengthNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.atlnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set threshold length samples dirty*/
	IntID getThresholdLengthSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.atlsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set threshold length map dirty*/
	IntID getThresholdLengthMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.atlmd",mName.c_str());return (const char*)buffer;}
	/*
	This is an unused hair attribute that can be used as a dummy
	attribute or for painting some additional attribute not already covered
	*/
	FloatID getUnused(){char buffer[4096];sprintf_s (buffer, "%s.dun",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getUnusedMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.unmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getUnusedMapMult(){char buffer[4096];sprintf_s (buffer, "%s.unmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getUnusedNoise(){char buffer[4096];sprintf_s (buffer, "%s.unn",mName.c_str());return (const char*)buffer;}
	/*Defines to set unused samples dirty*/
	IntID getUnusedSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.unsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set unused map dirty*/
	IntID getUnusedMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.unmd",mName.c_str());return (const char*)buffer;}
	/*An equalizer compensates for the uneven distribution of fur caused by uneven parameterization so that fur is evenly distributed across the surface.*/
	FloatID getEqualizer(){char buffer[4096];sprintf_s (buffer, "%s.dem",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur feedback attribute value by. The initial map is between 0 and 1.*/
	FloatID getEqualizerMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.emmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getEqualizerMapMult(){char buffer[4096];sprintf_s (buffer, "%s.emmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getEqualizerNoise(){char buffer[4096];sprintf_s (buffer, "%s.emn",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	FloatID getEqualizerNoiseFreq(){char buffer[4096];sprintf_s (buffer, "%s.emnf",mName.c_str());return (const char*)buffer;}
	/*Defines to set equalizer samples dirty*/
	IntID getEqualizerSamplesDirty(){char buffer[4096];sprintf_s (buffer, "%s.emsd",mName.c_str());return (const char*)buffer;}
	/*Defines to set equalizer map dirty*/
	IntID getEqualizerMapDirty(){char buffer[4096];sprintf_s (buffer, "%s.emmd",mName.c_str());return (const char*)buffer;}
	/*This is a root of following mental ray attributes.*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the render settings for this shape node.
	*/
	BoolID getMiOverrideCaustics(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oca",mName.c_str());return (const char*)buffer;}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	ShortID getMiCausticAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.caa",mName.c_str());return (const char*)buffer;}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	FloatID getMiCausticRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.car",mName.c_str());return (const char*)buffer;}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the render settings for this shape node.
	*/
	BoolID getMiOverrideGlobalIllumination(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ogi",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	ShortID getMiGlobillumAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gia",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	FloatID getMiGlobillumRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gir",mName.c_str());return (const char*)buffer;}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the render settings for this shape node.
	*/
	BoolID getMiOverrideFinalGather(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ofg",mName.c_str());return (const char*)buffer;}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	IntID getMiFinalGatherRays(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fry",mName.c_str());return (const char*)buffer;}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMinRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmn",mName.c_str());return (const char*)buffer;}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMaxRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmx",mName.c_str());return (const char*)buffer;}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	ShortID getMiFinalGatherFilter(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ffi",mName.c_str());return (const char*)buffer;}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	BoolID getMiFinalGatherView(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgv",mName.c_str());return (const char*)buffer;}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	BoolID getMiOverrideSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oos",mName.c_str());return (const char*)buffer;}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	ShortID getMiMinSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mins",mName.c_str());return (const char*)buffer;}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	ShortID getMiMaxSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.maxs",mName.c_str());return (const char*)buffer;}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	BoolID getMiFinalGatherCast(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgc",mName.c_str());return (const char*)buffer;}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	BoolID getMiFinalGatherReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fge",mName.c_str());return (const char*)buffer;}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	BoolID getMiTransparencyCast(){char buffer[4096];sprintf_s (buffer, "%s.mrc.tpc",mName.c_str());return (const char*)buffer;}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	BoolID getMiTransparencyReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.tpr",mName.c_str());return (const char*)buffer;}
protected:
	FurFeedback(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Locator(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FURFEEDBACK_H__
