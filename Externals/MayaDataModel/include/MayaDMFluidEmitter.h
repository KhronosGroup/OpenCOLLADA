/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLUIDEMITTER_H__
#define __MayaDM_FLUIDEMITTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPointEmitter.h"
namespace MayaDM
{
/*
<p><pre>    The emitter node is a dependency graph node to generate particles. The
    emitter type determines that the emitter is a pointEmitter, surfaceEmitter
    or curveEmitter.
 This is a "stub" version of the emitter for use in manips work.
</pre></p>
*/
class FluidEmitter : public PointEmitter
{
public:
public:
	FluidEmitter(FILE* file,const std::string& name,const std::string& parent=""):PointEmitter(file, name, parent, "fluidEmitter"){}
	virtual ~FluidEmitter(){}
	/*
	Drop-off value for fluid emission. For volume emitters the dropoff
	specifies how much the emission drops off as you move away from the
	volume axis (dependent on the volume shape). For point, curve, and
	surface emitters the drop off is based on the emission point and
	radiates out from minDistance to maxDistance.
	*/
	void setFluidDropoff(double fdo){if(fdo == 2) return; fprintf_s(mFile, "setAttr \".fdo\" %f;\n", fdo);}
	/*
	Drop-off value for fluid emission. For volume emitters the dropoff
	specifies how much the emission drops off as you move away from the
	volume axis (dependent on the volume shape). For point, curve, and
	surface emitters the drop off is based on the emission point and
	radiates out from minDistance to maxDistance.
	*/
	void setFluidDropoff(const DoubleID& fdo){fprintf_s(mFile,"connectAttr \"");fdo.write(mFile);fprintf_s(mFile,"\" \"%s.fdo\";\n",mName.c_str());}
	/*
	Determines what type of turbulence to apply to fluid emission.
	The default, "Gradient", applies turbulence that ranges smoothly
	through space. "Random" applies random turbulence.
	*/
	void setTurbulenceType(unsigned int trt){if(trt == 0) return; fprintf_s(mFile, "setAttr \".trt\" %i;\n", trt);}
	/*
	Determines what type of turbulence to apply to fluid emission.
	The default, "Gradient", applies turbulence that ranges smoothly
	through space. "Random" applies random turbulence.
	*/
	void setTurbulenceType(const UnsignedintID& trt){fprintf_s(mFile,"connectAttr \"");trt.write(mFile);fprintf_s(mFile,"\" \"%s.trt\";\n",mName.c_str());}
	/*
	Determines whether emission is based on random (jitter)
	or fixed (no jitter) sampling.
	The default, Jitter on, provides better anti-aliasting around
	the edges of the emitting volume. Jitter off works better with
	the Spring-Mesh solver (Ocean and Pond wakes), and reduces
	"sizzling" effects in the region of the emitter.
	*/
	void setFluidJitter(bool fjt){if(fjt == true) return; fprintf_s(mFile, "setAttr \".fjt\" %i;\n", fjt);}
	/*
	Determines whether emission is based on random (jitter)
	or fixed (no jitter) sampling.
	The default, Jitter on, provides better anti-aliasting around
	the edges of the emitting volume. Jitter off works better with
	the Spring-Mesh solver (Ocean and Pond wakes), and reduces
	"sizzling" effects in the region of the emitter.
	*/
	void setFluidJitter(const BoolID& fjt){fprintf_s(mFile,"connectAttr \"");fjt.write(mFile);fprintf_s(mFile,"\" \"%s.fjt\";\n",mName.c_str());}
	/*
	The intensity of a force simulating
	a turbulent wind that evolves over time.
	*/
	void setTurbulence(double trb){if(trb == 0.0) return; fprintf_s(mFile, "setAttr \".trb\" %f;\n", trb);}
	/*
	The intensity of a force simulating
	a turbulent wind that evolves over time.
	*/
	void setTurbulence(const DoubleID& trb){fprintf_s(mFile,"connectAttr \"");trb.write(mFile);fprintf_s(mFile,"\" \"%s.trb\";\n",mName.c_str());}
	/*
	The rate of change of the turbulence
	over time. The turbulence loops seamlessly
	every 1.0/turbulenceSpeed seconds. To animate
	this rate attach a new time node to the time input
	and animate the time value on the time node.
	*/
	void setTurbulenceSpeed(double trs){if(trs == 0.2) return; fprintf_s(mFile, "setAttr \".trs\" %f;\n", trs);}
	/*
	The rate of change of the turbulence
	over time. The turbulence loops seamlessly
	every 1.0/turbulenceSpeed seconds. To animate
	this rate attach a new time node to the time input
	and animate the time value on the time node.
	*/
	void setTurbulenceSpeed(const DoubleID& trs){fprintf_s(mFile,"connectAttr \"");trs.write(mFile);fprintf_s(mFile,"\" \"%s.trs\";\n",mName.c_str());}
	/*
	This controls how many repeats of the turbulence function fit
	inside the bounding volume of the emitter. Low values create
	a very smooth turbulence.
	*/
	void setTurbulenceFrequency(const double3& tf){fprintf_s(mFile, "setAttr \".tf\" -type \"double3\" ");tf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This controls how many repeats of the turbulence function fit
	inside the bounding volume of the emitter. Low values create
	a very smooth turbulence.
	*/
	void setTurbulenceFrequency(const Double3ID& tf){fprintf_s(mFile,"connectAttr \"");tf.write(mFile);fprintf_s(mFile,"\" \"%s.tf\";\n",mName.c_str());}
	/*repeats in X of turbulence function.*/
	void setTurbulenceFrequencyX(double tfx){if(tfx == 1.0) return; fprintf_s(mFile, "setAttr \".tf.tfx\" %f;\n", tfx);}
	/*repeats in X of turbulence function.*/
	void setTurbulenceFrequencyX(const DoubleID& tfx){fprintf_s(mFile,"connectAttr \"");tfx.write(mFile);fprintf_s(mFile,"\" \"%s.tf.tfx\";\n",mName.c_str());}
	/*repeats in Y of turbulence function.*/
	void setTurbulenceFrequencyY(double tfy){if(tfy == 1.0) return; fprintf_s(mFile, "setAttr \".tf.tfy\" %f;\n", tfy);}
	/*repeats in Y of turbulence function.*/
	void setTurbulenceFrequencyY(const DoubleID& tfy){fprintf_s(mFile,"connectAttr \"");tfy.write(mFile);fprintf_s(mFile,"\" \"%s.tf.tfy\";\n",mName.c_str());}
	/*repeats in Z of turbulence function.*/
	void setTurbulenceFrequencyZ(double tfz){if(tfz == 1.0) return; fprintf_s(mFile, "setAttr \".tf.tfz\" %f;\n", tfz);}
	/*repeats in Z of turbulence function.*/
	void setTurbulenceFrequencyZ(const DoubleID& tfz){fprintf_s(mFile,"connectAttr \"");tfz.write(mFile);fprintf_s(mFile,"\" \"%s.tf.tfz\";\n",mName.c_str());}
	/*
	This can be used to translate the turbulence within the volume.
	Animating it can simulate blowing turbulent wind.
	*/
	void setTurbulenceOffset(const double3& to){fprintf_s(mFile, "setAttr \".to\" -type \"double3\" ");to.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This can be used to translate the turbulence within the volume.
	Animating it can simulate blowing turbulent wind.
	*/
	void setTurbulenceOffset(const Double3ID& to){fprintf_s(mFile,"connectAttr \"");to.write(mFile);fprintf_s(mFile,"\" \"%s.to\";\n",mName.c_str());}
	/*translation in X of turbulence function.*/
	void setTurbulenceOffsetX(double tox){if(tox == 0.0) return; fprintf_s(mFile, "setAttr \".to.tox\" %f;\n", tox);}
	/*translation in X of turbulence function.*/
	void setTurbulenceOffsetX(const DoubleID& tox){fprintf_s(mFile,"connectAttr \"");tox.write(mFile);fprintf_s(mFile,"\" \"%s.to.tox\";\n",mName.c_str());}
	/*translation in Y of turbulence function.*/
	void setTurbulenceOffsetY(double toy){if(toy == 0.0) return; fprintf_s(mFile, "setAttr \".to.toy\" %f;\n", toy);}
	/*translation in Y of turbulence function.*/
	void setTurbulenceOffsetY(const DoubleID& toy){fprintf_s(mFile,"connectAttr \"");toy.write(mFile);fprintf_s(mFile,"\" \"%s.to.toy\";\n",mName.c_str());}
	/*translation in Z of turbulence function.*/
	void setTurbulenceOffsetZ(double toz){if(toz == 0.0) return; fprintf_s(mFile, "setAttr \".to.toz\" %f;\n", toz);}
	/*translation in Z of turbulence function.*/
	void setTurbulenceOffsetZ(const DoubleID& toz){fprintf_s(mFile,"connectAttr \"");toz.write(mFile);fprintf_s(mFile,"\" \"%s.to.toz\";\n",mName.c_str());}
	/*
	The relative intensity of a second higher frequency turbulence.
	This can be used to create fine features in large scale flows.
	Both the speed and the frequency on this second turbulence are
	higher than the primary turbulence. When the detailTurbulence
	is non-zero the simulation may run a bit slower, due to the
	computation of a second turbulence.
	*/
	void setDetailTurbulence(double dtr){if(dtr == 0.0) return; fprintf_s(mFile, "setAttr \".dtr\" %f;\n", dtr);}
	/*
	The relative intensity of a second higher frequency turbulence.
	This can be used to create fine features in large scale flows.
	Both the speed and the frequency on this second turbulence are
	higher than the primary turbulence. When the detailTurbulence
	is non-zero the simulation may run a bit slower, due to the
	computation of a second turbulence.
	*/
	void setDetailTurbulence(const DoubleID& dtr){fprintf_s(mFile,"connectAttr \"");dtr.write(mFile);fprintf_s(mFile,"\" \"%s.dtr\";\n",mName.c_str());}
	/*rate of emission into the fluid density grid*/
	void setFluidDensityEmission(double fde){if(fde == 1.0) return; fprintf_s(mFile, "setAttr \".fde\" %f;\n", fde);}
	/*rate of emission into the fluid density grid*/
	void setFluidDensityEmission(const DoubleID& fde){fprintf_s(mFile,"connectAttr \"");fde.write(mFile);fprintf_s(mFile,"\" \"%s.fde\";\n",mName.c_str());}
	/*rate of emission into the fluid temperature grid*/
	void setFluidHeatEmission(double fhe){if(fhe == 0.0) return; fprintf_s(mFile, "setAttr \".fhe\" %f;\n", fhe);}
	/*rate of emission into the fluid temperature grid*/
	void setFluidHeatEmission(const DoubleID& fhe){fprintf_s(mFile,"connectAttr \"");fhe.write(mFile);fprintf_s(mFile,"\" \"%s.fhe\";\n",mName.c_str());}
	/*
	rate of emission into the fluid reaction grid. This is similar to emitting
	a fuel.
	*/
	void setFluidFuelEmission(double ffe){if(ffe == 0.0) return; fprintf_s(mFile, "setAttr \".ffe\" %f;\n", ffe);}
	/*
	rate of emission into the fluid reaction grid. This is similar to emitting
	a fuel.
	*/
	void setFluidFuelEmission(const DoubleID& ffe){fprintf_s(mFile,"connectAttr \"");ffe.write(mFile);fprintf_s(mFile,"\" \"%s.ffe\";\n",mName.c_str());}
	/*Use particle color to emit color into the fluid color grid*/
	void setEmitFluidColor(bool efc){if(efc == false) return; fprintf_s(mFile, "setAttr \".efc\" %i;\n", efc);}
	/*Use particle color to emit color into the fluid color grid*/
	void setEmitFluidColor(const BoolID& efc){fprintf_s(mFile,"connectAttr \"");efc.write(mFile);fprintf_s(mFile,"\" \"%s.efc\";\n",mName.c_str());}
	/*
	Function attribute the connected fluidShape uses to get emission from
	this node.
	*/
	void setEmissionFunction(const FunctionID& ef){fprintf_s(mFile,"connectAttr \"");ef.write(mFile);fprintf_s(mFile,"\" \"%s.ef\";\n",mName.c_str());}
	/*
	Drop-off value for fluid emission. For volume emitters the dropoff
	specifies how much the emission drops off as you move away from the
	volume axis (dependent on the volume shape). For point, curve, and
	surface emitters the drop off is based on the emission point and
	radiates out from minDistance to maxDistance.
	*/
	DoubleID getFluidDropoff(){char buffer[4096];sprintf_s (buffer, "%s.fdo",mName.c_str());return (const char*)buffer;}
	/*
	Determines what type of turbulence to apply to fluid emission.
	The default, "Gradient", applies turbulence that ranges smoothly
	through space. "Random" applies random turbulence.
	*/
	UnsignedintID getTurbulenceType(){char buffer[4096];sprintf_s (buffer, "%s.trt",mName.c_str());return (const char*)buffer;}
	/*
	Determines whether emission is based on random (jitter)
	or fixed (no jitter) sampling.
	The default, Jitter on, provides better anti-aliasting around
	the edges of the emitting volume. Jitter off works better with
	the Spring-Mesh solver (Ocean and Pond wakes), and reduces
	"sizzling" effects in the region of the emitter.
	*/
	BoolID getFluidJitter(){char buffer[4096];sprintf_s (buffer, "%s.fjt",mName.c_str());return (const char*)buffer;}
	/*
	The intensity of a force simulating
	a turbulent wind that evolves over time.
	*/
	DoubleID getTurbulence(){char buffer[4096];sprintf_s (buffer, "%s.trb",mName.c_str());return (const char*)buffer;}
	/*
	The rate of change of the turbulence
	over time. The turbulence loops seamlessly
	every 1.0/turbulenceSpeed seconds. To animate
	this rate attach a new time node to the time input
	and animate the time value on the time node.
	*/
	DoubleID getTurbulenceSpeed(){char buffer[4096];sprintf_s (buffer, "%s.trs",mName.c_str());return (const char*)buffer;}
	/*
	This controls how many repeats of the turbulence function fit
	inside the bounding volume of the emitter. Low values create
	a very smooth turbulence.
	*/
	Double3ID getTurbulenceFrequency(){char buffer[4096];sprintf_s (buffer, "%s.tf",mName.c_str());return (const char*)buffer;}
	/*repeats in X of turbulence function.*/
	DoubleID getTurbulenceFrequencyX(){char buffer[4096];sprintf_s (buffer, "%s.tf.tfx",mName.c_str());return (const char*)buffer;}
	/*repeats in Y of turbulence function.*/
	DoubleID getTurbulenceFrequencyY(){char buffer[4096];sprintf_s (buffer, "%s.tf.tfy",mName.c_str());return (const char*)buffer;}
	/*repeats in Z of turbulence function.*/
	DoubleID getTurbulenceFrequencyZ(){char buffer[4096];sprintf_s (buffer, "%s.tf.tfz",mName.c_str());return (const char*)buffer;}
	/*
	This can be used to translate the turbulence within the volume.
	Animating it can simulate blowing turbulent wind.
	*/
	Double3ID getTurbulenceOffset(){char buffer[4096];sprintf_s (buffer, "%s.to",mName.c_str());return (const char*)buffer;}
	/*translation in X of turbulence function.*/
	DoubleID getTurbulenceOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.to.tox",mName.c_str());return (const char*)buffer;}
	/*translation in Y of turbulence function.*/
	DoubleID getTurbulenceOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.to.toy",mName.c_str());return (const char*)buffer;}
	/*translation in Z of turbulence function.*/
	DoubleID getTurbulenceOffsetZ(){char buffer[4096];sprintf_s (buffer, "%s.to.toz",mName.c_str());return (const char*)buffer;}
	/*
	The relative intensity of a second higher frequency turbulence.
	This can be used to create fine features in large scale flows.
	Both the speed and the frequency on this second turbulence are
	higher than the primary turbulence. When the detailTurbulence
	is non-zero the simulation may run a bit slower, due to the
	computation of a second turbulence.
	*/
	DoubleID getDetailTurbulence(){char buffer[4096];sprintf_s (buffer, "%s.dtr",mName.c_str());return (const char*)buffer;}
	/*rate of emission into the fluid density grid*/
	DoubleID getFluidDensityEmission(){char buffer[4096];sprintf_s (buffer, "%s.fde",mName.c_str());return (const char*)buffer;}
	/*rate of emission into the fluid temperature grid*/
	DoubleID getFluidHeatEmission(){char buffer[4096];sprintf_s (buffer, "%s.fhe",mName.c_str());return (const char*)buffer;}
	/*
	rate of emission into the fluid reaction grid. This is similar to emitting
	a fuel.
	*/
	DoubleID getFluidFuelEmission(){char buffer[4096];sprintf_s (buffer, "%s.ffe",mName.c_str());return (const char*)buffer;}
	/*Use particle color to emit color into the fluid color grid*/
	BoolID getEmitFluidColor(){char buffer[4096];sprintf_s (buffer, "%s.efc",mName.c_str());return (const char*)buffer;}
	/*
	Function attribute the connected fluidShape uses to get emission from
	this node.
	*/
	FunctionID getEmissionFunction(){char buffer[4096];sprintf_s (buffer, "%s.ef",mName.c_str());return (const char*)buffer;}
protected:
	FluidEmitter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PointEmitter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FLUIDEMITTER_H__
