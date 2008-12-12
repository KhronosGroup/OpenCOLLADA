/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FIELD_H__
#define __MayaDM_FIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDynBase.h"
namespace MayaDM
{
/*
The field node is a base class node for all fields.
        It includes the attributes which are common to all the fields,
        such as magnitude.  Each derived class provides the machinery
        to compute its particular field force from these attributes.<p/>
*/
class Field : public DynBase
{
public:
	/*
	Data from dynamic nodes for computing new output force.
	The field gets data from a set of "points" (particles, locations
	on a rigid body, etc.) and returns a force computed for each
	point.  Arbitrary user-defined nodes can make use of the field
	as Tint32 as they can give data for a set of points and can interpret
	the outputs.  Nodes using the field should take care to set
	up their attributes so as not to cause a DG loop.
	*/
	struct InputData{
		vectorArray inputPositions;
		vectorArray inputVelocities;
		doubleArray inputMass;
		void write(FILE* file) const
		{
			inputPositions.write(file);
			fprintf_s(file, " ");
			inputVelocities.write(file);
			fprintf_s(file, " ");
			inputMass.write(file);
			fprintf_s(file, " ");
		}
	};
	/*Define the falloff curve to use with maxDistance*/
	struct FalloffCurve{
		float falloffCurve_Position;
		float falloffCurve_FloatValue;
		unsigned int falloffCurve_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", falloffCurve_Position);
			fprintf_s(file,"%f ", falloffCurve_FloatValue);
			fprintf_s(file,"%i", falloffCurve_Interp);
		}
	};
public:
	Field(FILE* file,const std::string& name,const std::string& parent=""):DynBase(file, name, parent, "field"){}
	virtual ~Field(){}
	/*field magnitude*/
	void setMagnitude(double mag){if(mag == 1.0) return; fprintf_s(mFile, "setAttr \".mag\" %f;\n", mag);}
	/*field magnitude*/
	void setMagnitude(const DoubleID& mag){fprintf_s(mFile,"connectAttr \"");mag.write(mFile);fprintf_s(mFile,"\" \"%s.mag\";\n",mName.c_str());}
	/*field attenuation*/
	void setAttenuation(double att){if(att == 0.0) return; fprintf_s(mFile, "setAttr \".att\" %f;\n", att);}
	/*field attenuation*/
	void setAttenuation(const DoubleID& att){fprintf_s(mFile,"connectAttr \"");att.write(mFile);fprintf_s(mFile,"\" \"%s.att\";\n",mName.c_str());}
	/*field max distance*/
	void setMaxDistance(double max){if(max == 1) return; fprintf_s(mFile, "setAttr \".max\" %f;\n", max);}
	/*field max distance*/
	void setMaxDistance(const DoubleID& max){fprintf_s(mFile,"connectAttr \"");max.write(mFile);fprintf_s(mFile,"\" \"%s.max\";\n",mName.c_str());}
	/*apply per vertex (true) or from centroid (false)*/
	void setApplyPerVertex(bool apv){if(apv == false) return; fprintf_s(mFile, "setAttr \".apv\" %i;\n", apv);}
	/*apply per vertex (true) or from centroid (false)*/
	void setApplyPerVertex(const BoolID& apv){fprintf_s(mFile,"connectAttr \"");apv.write(mFile);fprintf_s(mFile,"\" \"%s.apv\";\n",mName.c_str());}
	/*use max distance value (if true) or infinite distance (if false)*/
	void setUseMaxDistance(bool umd){if(umd == false) return; fprintf_s(mFile, "setAttr \".umd\" %i;\n", umd);}
	/*use max distance value (if true) or infinite distance (if false)*/
	void setUseMaxDistance(const BoolID& umd){fprintf_s(mFile,"connectAttr \"");umd.write(mFile);fprintf_s(mFile,"\" \"%s.umd\";\n",mName.c_str());}
	/*
	Data from dynamic nodes for computing new output force.
	The field gets data from a set of "points" (particles, locations
	on a rigid body, etc.) and returns a force computed for each
	point.  Arbitrary user-defined nodes can make use of the field
	as Tint32 as they can give data for a set of points and can interpret
	the outputs.  Nodes using the field should take care to set
	up their attributes so as not to cause a DG loop.
	*/
	void setInputData(size_t ind_i,const InputData& ind){fprintf_s(mFile, "setAttr \".ind[%i]\" ",ind_i);ind.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Data from dynamic nodes for computing new output force.
	The field gets data from a set of "points" (particles, locations
	on a rigid body, etc.) and returns a force computed for each
	point.  Arbitrary user-defined nodes can make use of the field
	as Tint32 as they can give data for a set of points and can interpret
	the outputs.  Nodes using the field should take care to set
	up their attributes so as not to cause a DG loop.
	*/
	void setInputData(size_t ind_i,const InputDataID& ind){fprintf_s(mFile,"connectAttr \"");ind.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i]\";\n",mName.c_str(),ind_i);}
	/*Input position array*/
	void setInputPositions(size_t ind_i,const vectorArray& inp){if(inp.size == 0) return; fprintf_s(mFile, "setAttr \".ind[%i].inp\" -type \"vectorArray\" ",ind_i);inp.write(mFile);fprintf_s(mFile,";\n");}
	/*Input position array*/
	void setInputPositions(size_t ind_i,const VectorArrayID& inp){fprintf_s(mFile,"connectAttr \"");inp.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i].inp\";\n",mName.c_str(),ind_i);}
	/*Input velocity array*/
	void setInputVelocities(size_t ind_i,const vectorArray& inv){if(inv.size == 0) return; fprintf_s(mFile, "setAttr \".ind[%i].inv\" -type \"vectorArray\" ",ind_i);inv.write(mFile);fprintf_s(mFile,";\n");}
	/*Input velocity array*/
	void setInputVelocities(size_t ind_i,const VectorArrayID& inv){fprintf_s(mFile,"connectAttr \"");inv.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i].inv\";\n",mName.c_str(),ind_i);}
	/*Input mass array*/
	void setInputMass(size_t ind_i,const doubleArray& inm){if(inm.size == 0) return; fprintf_s(mFile, "setAttr \".ind[%i].inm\" -type \"doubleArray\" ",ind_i);inm.write(mFile);fprintf_s(mFile,";\n");}
	/*Input mass array*/
	void setInputMass(size_t ind_i,const DoubleArrayID& inm){fprintf_s(mFile,"connectAttr \"");inm.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i].inm\";\n",mName.c_str(),ind_i);}
	/*
	Some fields may need deltaTime to compute force.  Of the standard
	nodes, vortex is the only one.  User-defined nodes can use this
	attribute if they wish.
	*/
	void setDeltaTime(size_t ind_i,const TimeID& dt){fprintf_s(mFile,"connectAttr \"");dt.write(mFile);fprintf_s(mFile,"\" \"%s.ind[%i].dt\";\n",mName.c_str(),ind_i);}
	/*
	Force data from dynamic nodes for computing new output force.
	If an array of forces is supplied here, the field will ADD its
	force to that array instead of writing it to outputForce.
	The particle shape uses this to gain some important efficiencies.
	*/
	void setInputForce(size_t inf_i,const VectorArrayID& inf){fprintf_s(mFile,"connectAttr \"");inf.write(mFile);fprintf_s(mFile,"\" \"%s.inf[%i]\";\n",mName.c_str(),inf_i);}
	/*
	Force data output to dynamic nodes.
	The entries in this output array match the input entries
	in inputPositions et al.
	*/
	void setOutputForce(size_t of_i,const VectorArrayID& of){fprintf_s(mFile,"connectAttr \"");of.write(mFile);fprintf_s(mFile,"\" \"%s.of[%i]\";\n",mName.c_str(),of_i);}
	/*
	Indicates the shape of volume the field will use.
	If set to None, volume controls are disabled.
	*/
	void setVolumeShape(unsigned int vol){if(vol == 0) return; fprintf_s(mFile, "setAttr \".vol\" %i;\n", vol);}
	/*
	Indicates the shape of volume the field will use.
	If set to None, volume controls are disabled.
	*/
	void setVolumeShape(const UnsignedintID& vol){fprintf_s(mFile,"connectAttr \"");vol.write(mFile);fprintf_s(mFile,"\" \"%s.vol\";\n",mName.c_str());}
	/*Indicates that the field should be apply outside the volume.*/
	void setVolumeExclusion(bool vex){if(vex == false) return; fprintf_s(mFile, "setAttr \".vex\" %i;\n", vex);}
	/*Indicates that the field should be apply outside the volume.*/
	void setVolumeExclusion(const BoolID& vex){fprintf_s(mFile,"connectAttr \"");vex.write(mFile);fprintf_s(mFile,"\" \"%s.vex\";\n",mName.c_str());}
	/*offset of the field from the volume.*/
	void setVolumeOffset(const double3& vfo){fprintf_s(mFile, "setAttr \".vfo\" -type \"double3\" ");vfo.write(mFile);fprintf_s(mFile,";\n");}
	/*offset of the field from the volume.*/
	void setVolumeOffset(const Double3ID& vfo){fprintf_s(mFile,"connectAttr \"");vfo.write(mFile);fprintf_s(mFile,"\" \"%s.vfo\";\n",mName.c_str());}
	/*X-component of volume field offset.*/
	void setVolumeOffsetX(double vox){if(vox == 0) return; fprintf_s(mFile, "setAttr \".vfo.vox\" %f;\n", vox);}
	/*X-component of volume field offset.*/
	void setVolumeOffsetX(const DoubleID& vox){fprintf_s(mFile,"connectAttr \"");vox.write(mFile);fprintf_s(mFile,"\" \"%s.vfo.vox\";\n",mName.c_str());}
	/*Y-component of volume field offset.*/
	void setVolumeOffsetY(double voy){if(voy == 0) return; fprintf_s(mFile, "setAttr \".vfo.voy\" %f;\n", voy);}
	/*Y-component of volume field offset.*/
	void setVolumeOffsetY(const DoubleID& voy){fprintf_s(mFile,"connectAttr \"");voy.write(mFile);fprintf_s(mFile,"\" \"%s.vfo.voy\";\n",mName.c_str());}
	/*Z-component of volume field offset.*/
	void setVolumeOffsetZ(double voz){if(voz == 0) return; fprintf_s(mFile, "setAttr \".vfo.voz\" %f;\n", voz);}
	/*Z-component of volume field offset.*/
	void setVolumeOffsetZ(const DoubleID& voz){fprintf_s(mFile,"connectAttr \"");voz.write(mFile);fprintf_s(mFile,"\" \"%s.vfo.voz\";\n",mName.c_str());}
	/*
	Applies to torus volumes only.
	The radius of a section of the torus.
	*/
	void setSectionRadius(double tsr){if(tsr == 0) return; fprintf_s(mFile, "setAttr \".tsr\" %f;\n", tsr);}
	/*
	Applies to torus volumes only.
	The radius of a section of the torus.
	*/
	void setSectionRadius(const DoubleID& tsr){fprintf_s(mFile,"connectAttr \"");tsr.write(mFile);fprintf_s(mFile,"\" \"%s.tsr\";\n",mName.c_str());}
	/*Sweep of the volume sphere, cone, cylinder and torus.*/
	void setVolumeSweep(double vsw){if(vsw == 3) return; fprintf_s(mFile, "setAttr \".vsw\" %f;\n", vsw);}
	/*Sweep of the volume sphere, cone, cylinder and torus.*/
	void setVolumeSweep(const DoubleID& vsw){fprintf_s(mFile,"connectAttr \"");vsw.write(mFile);fprintf_s(mFile,"\" \"%s.vsw\";\n",mName.c_str());}
	/*
	This contains a list of arrays and each array stores the per particle
	inforamtion of a particular attribute that is used to drive this field
	*/
	void setInputPPData(size_t ppda_i,const GenericArrayID& ppda){fprintf_s(mFile,"connectAttr \"");ppda.write(mFile);fprintf_s(mFile,"\" \"%s.ppda[%i]\";\n",mName.c_str(),ppda_i);}
	/*
	This contains a list of arrays and each array stores the per particle
	inforamtion of a particular attribute that is used to drive this field
	*/
	void setOwnerPPData(const GenericArrayID& oppd){fprintf_s(mFile,"connectAttr \"");oppd.write(mFile);fprintf_s(mFile,"\" \"%s.oppd\";\n",mName.c_str());}
	/*Define the falloff curve to use with maxDistance*/
	void setFalloffCurve(size_t fc_i,const FalloffCurve& fc){fprintf_s(mFile, "setAttr \".fc[%i]\" ",fc_i);fc.write(mFile);fprintf_s(mFile,";\n");}
	/*Define the falloff curve to use with maxDistance*/
	void setFalloffCurve(size_t fc_i,const FalloffCurveID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i]\";\n",mName.c_str(),fc_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setFalloffCurve_Position(size_t fc_i,float fcp){if(fcp == 0.0) return; fprintf_s(mFile, "setAttr \".fc[%i].fcp\" %f;\n", fc_i,fcp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setFalloffCurve_Position(size_t fc_i,const FloatID& fcp){fprintf_s(mFile,"connectAttr \"");fcp.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i].fcp\";\n",mName.c_str(),fc_i);}
	/*Ramp value at the sibling position*/
	void setFalloffCurve_FloatValue(size_t fc_i,float fcfv){if(fcfv == 0.0) return; fprintf_s(mFile, "setAttr \".fc[%i].fcfv\" %f;\n", fc_i,fcfv);}
	/*Ramp value at the sibling position*/
	void setFalloffCurve_FloatValue(size_t fc_i,const FloatID& fcfv){fprintf_s(mFile,"connectAttr \"");fcfv.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i].fcfv\";\n",mName.c_str(),fc_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setFalloffCurve_Interp(size_t fc_i,unsigned int fci){if(fci == 0) return; fprintf_s(mFile, "setAttr \".fc[%i].fci\" %i;\n", fc_i,fci);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setFalloffCurve_Interp(size_t fc_i,const UnsignedintID& fci){fprintf_s(mFile,"connectAttr \"");fci.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i].fci\";\n",mName.c_str(),fc_i);}
	/*field magnitude*/
	DoubleID getMagnitude(){char buffer[4096];sprintf_s (buffer, "%s.mag",mName.c_str());return (const char*)buffer;}
	/*field attenuation*/
	DoubleID getAttenuation(){char buffer[4096];sprintf_s (buffer, "%s.att",mName.c_str());return (const char*)buffer;}
	/*field max distance*/
	DoubleID getMaxDistance(){char buffer[4096];sprintf_s (buffer, "%s.max",mName.c_str());return (const char*)buffer;}
	/*apply per vertex (true) or from centroid (false)*/
	BoolID getApplyPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.apv",mName.c_str());return (const char*)buffer;}
	/*use max distance value (if true) or infinite distance (if false)*/
	BoolID getUseMaxDistance(){char buffer[4096];sprintf_s (buffer, "%s.umd",mName.c_str());return (const char*)buffer;}
	/*
	Data from dynamic nodes for computing new output force.
	The field gets data from a set of "points" (particles, locations
	on a rigid body, etc.) and returns a force computed for each
	point.  Arbitrary user-defined nodes can make use of the field
	as Tint32 as they can give data for a set of points and can interpret
	the outputs.  Nodes using the field should take care to set
	up their attributes so as not to cause a DG loop.
	*/
	const InputDataID& getInputData(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i]",mName.c_str(),ind_i);return (const char*)buffer;}
	/*Input position array*/
	const VectorArrayID& getInputPositions(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i].inp",mName.c_str(),ind_i);return (const char*)buffer;}
	/*Input velocity array*/
	const VectorArrayID& getInputVelocities(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i].inv",mName.c_str(),ind_i);return (const char*)buffer;}
	/*Input mass array*/
	const DoubleArrayID& getInputMass(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i].inm",mName.c_str(),ind_i);return (const char*)buffer;}
	/*
	Some fields may need deltaTime to compute force.  Of the standard
	nodes, vortex is the only one.  User-defined nodes can use this
	attribute if they wish.
	*/
	const TimeID& getDeltaTime(size_t ind_i){char buffer[4096];sprintf_s (buffer, "%s.ind[%i].dt",mName.c_str(),ind_i);return (const char*)buffer;}
	/*
	Force data from dynamic nodes for computing new output force.
	If an array of forces is supplied here, the field will ADD its
	force to that array instead of writing it to outputForce.
	The particle shape uses this to gain some important efficiencies.
	*/
	const VectorArrayID& getInputForce(size_t inf_i){char buffer[4096];sprintf_s (buffer, "%s.inf[%i]",mName.c_str(),inf_i);return (const char*)buffer;}
	/*
	Force data output to dynamic nodes.
	The entries in this output array match the input entries
	in inputPositions et al.
	*/
	const VectorArrayID& getOutputForce(size_t of_i){char buffer[4096];sprintf_s (buffer, "%s.of[%i]",mName.c_str(),of_i);return (const char*)buffer;}
	/*
	Indicates the shape of volume the field will use.
	If set to None, volume controls are disabled.
	*/
	UnsignedintID getVolumeShape(){char buffer[4096];sprintf_s (buffer, "%s.vol",mName.c_str());return (const char*)buffer;}
	/*Indicates that the field should be apply outside the volume.*/
	BoolID getVolumeExclusion(){char buffer[4096];sprintf_s (buffer, "%s.vex",mName.c_str());return (const char*)buffer;}
	/*offset of the field from the volume.*/
	Double3ID getVolumeOffset(){char buffer[4096];sprintf_s (buffer, "%s.vfo",mName.c_str());return (const char*)buffer;}
	/*X-component of volume field offset.*/
	DoubleID getVolumeOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.vfo.vox",mName.c_str());return (const char*)buffer;}
	/*Y-component of volume field offset.*/
	DoubleID getVolumeOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.vfo.voy",mName.c_str());return (const char*)buffer;}
	/*Z-component of volume field offset.*/
	DoubleID getVolumeOffsetZ(){char buffer[4096];sprintf_s (buffer, "%s.vfo.voz",mName.c_str());return (const char*)buffer;}
	/*
	Applies to torus volumes only.
	The radius of a section of the torus.
	*/
	DoubleID getSectionRadius(){char buffer[4096];sprintf_s (buffer, "%s.tsr",mName.c_str());return (const char*)buffer;}
	/*Sweep of the volume sphere, cone, cylinder and torus.*/
	DoubleID getVolumeSweep(){char buffer[4096];sprintf_s (buffer, "%s.vsw",mName.c_str());return (const char*)buffer;}
	/*
	This contains a list of arrays and each array stores the per particle
	inforamtion of a particular attribute that is used to drive this field
	*/
	const GenericArrayID& getInputPPData(size_t ppda_i){char buffer[4096];sprintf_s (buffer, "%s.ppda[%i]",mName.c_str(),ppda_i);return (const char*)buffer;}
	/*
	This contains a list of arrays and each array stores the per particle
	inforamtion of a particular attribute that is used to drive this field
	*/
	GenericArrayID getOwnerPPData(){char buffer[4096];sprintf_s (buffer, "%s.oppd",mName.c_str());return (const char*)buffer;}
	/*Define the falloff curve to use with maxDistance*/
	const FalloffCurveID& getFalloffCurve(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i]",mName.c_str(),fc_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getFalloffCurve_Position(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i].fcp",mName.c_str(),fc_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getFalloffCurve_FloatValue(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i].fcfv",mName.c_str(),fc_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getFalloffCurve_Interp(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i].fci",mName.c_str(),fc_i);return (const char*)buffer;}
protected:
	Field(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DynBase(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FIELD_H__
