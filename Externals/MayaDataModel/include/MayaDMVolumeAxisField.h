/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VOLUMEAXISFIELD_H__
#define __MayaDM_VOLUMEAXISFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
/*
A volume axis field imparts motion to particles similar to
 that generated for new particles by the volume type emitters.<p/>
 The volume attribute determines which volume to use.
 Setting that attribute to None disables the field.<p/>
 Unlike other fields, the volume axis field does not use the
 apply per vertex attribute. It always originates from its local
 origin or that of its owner.  It does use the max distance attribute
 (if useMaxDistance is set to true). <p/>
 The volume exclusion attribute does not apply to this type of field
 (the field ignores it entirely).
*/
class VolumeAxisField : public Field
{
public:
public:
	VolumeAxisField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "volumeAxisField"){}
	virtual ~VolumeAxisField(){}
	/*
	This attribute tells the volumeAxis field to invert the
	of the attenuation value.  If this is TRUE, then the
	field will be stronger the closer to the edge of the
	volume a point is.
	*/
	void setInvertAttenuation(bool ia){if(ia == false) return; fprintf_s(mFile, "setAttr \".ia\" %i;\n", ia);}
	/*
	This attribute tells the volumeAxis field to invert the
	of the attenuation value.  If this is TRUE, then the
	field will be stronger the closer to the edge of the
	volume a point is.
	*/
	void setInvertAttenuation(const BoolID& ia){fprintf_s(mFile,"connectAttr \"");ia.write(mFile);fprintf_s(mFile,"\" \"%s.ia\";\n",mName.c_str());}
	/*
	Field force in the direction away from the center
	point of a cube or sphere volume.
	*/
	void setAwayFromCenter(double afc){if(afc == 1.0) return; fprintf_s(mFile, "setAttr \".afc\" %f;\n", afc);}
	/*
	Field force in the direction away from the center
	point of a cube or sphere volume.
	*/
	void setAwayFromCenter(const DoubleID& afc){fprintf_s(mFile,"connectAttr \"");afc.write(mFile);fprintf_s(mFile,"\" \"%s.afc\";\n",mName.c_str());}
	/*
	Field force multiplier in the direction away
	from the central axis of the volume.  See the diagrams
	in the documentation.
	*/
	void setAwayFromAxis(double afa){if(afa == 1.0) return; fprintf_s(mFile, "setAttr \".afa\" %f;\n", afa);}
	/*
	Field force multiplier in the direction away
	from the central axis of the volume.  See the diagrams
	in the documentation.
	*/
	void setAwayFromAxis(const DoubleID& afa){fprintf_s(mFile,"connectAttr \"");afa.write(mFile);fprintf_s(mFile,"\" \"%s.afa\";\n",mName.c_str());}
	/*
	Field force multiplier in the direction along
	the central axis of the volume.  See the diagrams in
	the documentation.
	*/
	void setAlongAxis(double alx){if(alx == 0.0) return; fprintf_s(mFile, "setAttr \".alx\" %f;\n", alx);}
	/*
	Field force multiplier in the direction along
	the central axis of the volume.  See the diagrams in
	the documentation.
	*/
	void setAlongAxis(const DoubleID& alx){fprintf_s(mFile,"connectAttr \"");alx.write(mFile);fprintf_s(mFile,"\" \"%s.alx\";\n",mName.c_str());}
	/*
	Field force multiplier in the direction around
	the central axis of the volume.  See the diagrams
	in the documentation.
	*/
	void setAroundAxis(double arx){if(arx == 0.0) return; fprintf_s(mFile, "setAttr \".arx\" %f;\n", arx);}
	/*
	Field force multiplier in the direction around
	the central axis of the volume.  See the diagrams
	in the documentation.
	*/
	void setAroundAxis(const DoubleID& arx){fprintf_s(mFile,"connectAttr \"");arx.write(mFile);fprintf_s(mFile,"\" \"%s.arx\";\n",mName.c_str());}
	/*
	Adds a component of force in the
	direction specified by the directionX, Y, and Z attributes.
	*/
	void setDirectionalSpeed(double drs){if(drs == 0.0) return; fprintf_s(mFile, "setAttr \".drs\" %f;\n", drs);}
	/*
	Adds a component of force in the
	direction specified by the directionX, Y, and Z attributes.
	*/
	void setDirectionalSpeed(const DoubleID& drs){fprintf_s(mFile,"connectAttr \"");drs.write(mFile);fprintf_s(mFile,"\" \"%s.drs\";\n",mName.c_str());}
	/*direction control for field. Used with directionalSpeed.*/
	void setDirection(const double3& d){fprintf_s(mFile, "setAttr \".d\" -type \"double3\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*direction control for field. Used with directionalSpeed.*/
	void setDirection(const Double3ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*X-component of direction.*/
	void setDirectionX(double dx){if(dx == 1.0) return; fprintf_s(mFile, "setAttr \".d.dx\" %f;\n", dx);}
	/*X-component of direction.*/
	void setDirectionX(const DoubleID& dx){fprintf_s(mFile,"connectAttr \"");dx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dx\";\n",mName.c_str());}
	/*Y-component of direction.*/
	void setDirectionY(double dy){if(dy == 0.0) return; fprintf_s(mFile, "setAttr \".d.dy\" %f;\n", dy);}
	/*Y-component of direction.*/
	void setDirectionY(const DoubleID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.d.dy\";\n",mName.c_str());}
	/*Z-component of direction.*/
	void setDirectionZ(double dz){if(dz == 0.0) return; fprintf_s(mFile, "setAttr \".d.dz\" %f;\n", dz);}
	/*Z-component of direction.*/
	void setDirectionZ(const DoubleID& dz){fprintf_s(mFile,"connectAttr \"");dz.write(mFile);fprintf_s(mFile,"\" \"%s.d.dz\";\n",mName.c_str());}
	/*
	This boolean tells the field whether or not to draw the
	volume speed arrows.
	*/
	void setDisplaySpeed(bool dss){if(dss == true) return; fprintf_s(mFile, "setAttr \".dss\" %i;\n", dss);}
	/*
	This boolean tells the field whether or not to draw the
	volume speed arrows.
	*/
	void setDisplaySpeed(const BoolID& dss){fprintf_s(mFile,"connectAttr \"");dss.write(mFile);fprintf_s(mFile,"\" \"%s.dss\";\n",mName.c_str());}
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
	inside the bounding volume of the volumeAxis force. Low values create
	a very smooth turbulence.
	*/
	void setTurbulenceFrequency(const double3& tf){fprintf_s(mFile, "setAttr \".tf\" -type \"double3\" ");tf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This controls how many repeats of the turbulence function fit
	inside the bounding volume of the volumeAxis force. Low values create
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
	/*time value for animated effects*/
	void setTime(const TimeID& tim){fprintf_s(mFile,"connectAttr \"");tim.write(mFile);fprintf_s(mFile,"\" \"%s.tim\";\n",mName.c_str());}
	/*
	This attribute tells the volumeAxis field to invert the
	of the attenuation value.  If this is TRUE, then the
	field will be stronger the closer to the edge of the
	volume a point is.
	*/
	BoolID getInvertAttenuation(){char buffer[4096];sprintf_s (buffer, "%s.ia",mName.c_str());return (const char*)buffer;}
	/*
	Field force in the direction away from the center
	point of a cube or sphere volume.
	*/
	DoubleID getAwayFromCenter(){char buffer[4096];sprintf_s (buffer, "%s.afc",mName.c_str());return (const char*)buffer;}
	/*
	Field force multiplier in the direction away
	from the central axis of the volume.  See the diagrams
	in the documentation.
	*/
	DoubleID getAwayFromAxis(){char buffer[4096];sprintf_s (buffer, "%s.afa",mName.c_str());return (const char*)buffer;}
	/*
	Field force multiplier in the direction along
	the central axis of the volume.  See the diagrams in
	the documentation.
	*/
	DoubleID getAlongAxis(){char buffer[4096];sprintf_s (buffer, "%s.alx",mName.c_str());return (const char*)buffer;}
	/*
	Field force multiplier in the direction around
	the central axis of the volume.  See the diagrams
	in the documentation.
	*/
	DoubleID getAroundAxis(){char buffer[4096];sprintf_s (buffer, "%s.arx",mName.c_str());return (const char*)buffer;}
	/*
	Adds a component of force in the
	direction specified by the directionX, Y, and Z attributes.
	*/
	DoubleID getDirectionalSpeed(){char buffer[4096];sprintf_s (buffer, "%s.drs",mName.c_str());return (const char*)buffer;}
	/*direction control for field. Used with directionalSpeed.*/
	Double3ID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*X-component of direction.*/
	DoubleID getDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.d.dx",mName.c_str());return (const char*)buffer;}
	/*Y-component of direction.*/
	DoubleID getDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.d.dy",mName.c_str());return (const char*)buffer;}
	/*Z-component of direction.*/
	DoubleID getDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.d.dz",mName.c_str());return (const char*)buffer;}
	/*
	This boolean tells the field whether or not to draw the
	volume speed arrows.
	*/
	BoolID getDisplaySpeed(){char buffer[4096];sprintf_s (buffer, "%s.dss",mName.c_str());return (const char*)buffer;}
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
	inside the bounding volume of the volumeAxis force. Low values create
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
	/*time value for animated effects*/
	TimeID getTime(){char buffer[4096];sprintf_s (buffer, "%s.tim",mName.c_str());return (const char*)buffer;}
protected:
	VolumeAxisField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMEAXISFIELD_H__
