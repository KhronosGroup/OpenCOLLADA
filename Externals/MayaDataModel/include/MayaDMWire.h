/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WIRE_H__
#define __MayaDM_WIRE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
/*
This node deforms the components of an input object or
 objects based on how the associated wire curves are modified relative
 to both the base wires and the deformed objects.
<br/>
 Note that multi-attributes corresponding to wire curves (dropoffDistance and scale)
 and wire locators (wireLocatorPercentage,
wireLocatorParameter, wireLocatorEnvelope, wireLocatorTwist)
retain their values after the corresponding wire curve is deleted or removed
from the deformation (in order to support undo),
but such "orphaned" values are <em>not</em> saved out when a file is saved.
*/
class Wire : public WeightGeometryFilter
{
public:
public:
	Wire(FILE* file,const std::string& name,const std::string& parent=""):WeightGeometryFilter(file, name, parent, "wire"){}
	virtual ~Wire(){}
	/*
	Convolution filter value. 0.0 means full convolution; 1.0
	produces an additive effect.
	*/
	void setCrossingEffect(float ce){if(ce == 0) return; fprintf_s(mFile, "setAttr \".ce\" %f;\n", ce);}
	/*
	Convolution filter value. 0.0 means full convolution; 1.0
	produces an additive effect.
	*/
	void setCrossingEffect(const FloatID& ce){fprintf_s(mFile,"connectAttr \"");ce.write(mFile);fprintf_s(mFile,"\" \"%s.ce\";\n",mName.c_str());}
	/*Convolution filter tension*/
	void setTension(float te){if(te == 1) return; fprintf_s(mFile, "setAttr \".te\" %f;\n", te);}
	/*Convolution filter tension*/
	void setTension(const FloatID& te){fprintf_s(mFile,"connectAttr \"");te.write(mFile);fprintf_s(mFile,"\" \"%s.te\";\n",mName.c_str());}
	/*
	Local filter value. 0.0 means no local effect;
	1.0 produces a localized effect.
	*/
	void setLocalInfluence(float li){if(li == 0) return; fprintf_s(mFile, "setAttr \".li\" %f;\n", li);}
	/*
	Local filter value. 0.0 means no local effect;
	1.0 produces a localized effect.
	*/
	void setLocalInfluence(const FloatID& li){fprintf_s(mFile,"connectAttr \"");li.write(mFile);fprintf_s(mFile,"\" \"%s.li\";\n",mName.c_str());}
	/*
	Orientation effect. 0.0 produces no orientation effect;
	1.0 produces the full orientation effect.
	*/
	void setRotation(float ro){if(ro == 1) return; fprintf_s(mFile, "setAttr \".ro\" %f;\n", ro);}
	/*
	Orientation effect. 0.0 produces no orientation effect;
	1.0 produces the full orientation effect.
	*/
	void setRotation(const FloatID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*
	Wire mapping is frozen when the state of this variable is toggled on.
	This should be done only for performance improvement.
	Be careful not to move the geometry relative to the base wire if
	this is turned on!
	*/
	void setFreezeGeometry(bool fg){if(fg == 0) return; fprintf_s(mFile, "setAttr \".fg\" %i;\n", fg);}
	/*
	Wire mapping is frozen when the state of this variable is toggled on.
	This should be done only for performance improvement.
	Be careful not to move the geometry relative to the base wire if
	this is turned on!
	*/
	void setFreezeGeometry(const BoolID& fg){fprintf_s(mFile,"connectAttr \"");fg.write(mFile);fprintf_s(mFile,"\" \"%s.fg\";\n",mName.c_str());}
	/*Offset radius for dropoff around a wire.*/
	void setDropoffDistance(size_t dds_i,float dds){if(dds == 1) return; fprintf_s(mFile, "setAttr \".dds[%i]\" %f;\n", dds_i,dds);}
	/*Offset radius for dropoff around a wire.*/
	void setDropoffDistance(size_t dds_i,const FloatID& dds){fprintf_s(mFile,"connectAttr \"");dds.write(mFile);fprintf_s(mFile,"\" \"%s.dds[%i]\";\n",mName.c_str(),dds_i);}
	/*Scale for dropoff around a wire.*/
	void setScale(size_t sc_i,float sc){if(sc == 1) return; fprintf_s(mFile, "setAttr \".sc[%i]\" %f;\n", sc_i,sc);}
	/*Scale for dropoff around a wire.*/
	void setScale(size_t sc_i,const FloatID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i]\";\n",mName.c_str(),sc_i);}
	/*The percents of the wire locators for radius calculation.*/
	void setWireLocatorPercentage(size_t wlpc_i,float wlpc){if(wlpc == 1) return; fprintf_s(mFile, "setAttr \".wlpc[%i]\" %f;\n", wlpc_i,wlpc);}
	/*The percents of the wire locators for radius calculation.*/
	void setWireLocatorPercentage(size_t wlpc_i,const FloatID& wlpc){fprintf_s(mFile,"connectAttr \"");wlpc.write(mFile);fprintf_s(mFile,"\" \"%s.wlpc[%i]\";\n",mName.c_str(),wlpc_i);}
	/*The parameters of the wire locators for radius calculation.*/
	void setWireLocatorParameter(size_t wlp_i,float wlp){if(wlp == 0) return; fprintf_s(mFile, "setAttr \".wlp[%i]\" %f;\n", wlp_i,wlp);}
	/*The parameters of the wire locators for radius calculation.*/
	void setWireLocatorParameter(size_t wlp_i,const FloatID& wlp){fprintf_s(mFile,"connectAttr \"");wlp.write(mFile);fprintf_s(mFile,"\" \"%s.wlp[%i]\";\n",mName.c_str(),wlp_i);}
	/*The envelope of a wire locator.*/
	void setWireLocatorEnvelope(size_t wle_i,float wle){if(wle == 1) return; fprintf_s(mFile, "setAttr \".wle[%i]\" %f;\n", wle_i,wle);}
	/*The envelope of a wire locator.*/
	void setWireLocatorEnvelope(size_t wle_i,const FloatID& wle){fprintf_s(mFile,"connectAttr \"");wle.write(mFile);fprintf_s(mFile,"\" \"%s.wle[%i]\";\n",mName.c_str(),wle_i);}
	/*The twist of a wire locator.*/
	void setWireLocatorTwist(size_t wlt_i,float wlt){if(wlt == 0) return; fprintf_s(mFile, "setAttr \".wlt[%i]\" %f;\n", wlt_i,wlt);}
	/*The twist of a wire locator.*/
	void setWireLocatorTwist(size_t wlt_i,const FloatID& wlt){fprintf_s(mFile,"connectAttr \"");wlt.write(mFile);fprintf_s(mFile,"\" \"%s.wlt[%i]\";\n",mName.c_str(),wlt_i);}
	/*The points of the deformed wire.*/
	void setDeformedWire(size_t dw_i,const nurbsCurve& dw){fprintf_s(mFile, "setAttr \".dw[%i]\" -type \"nurbsCurve\" ",dw_i);dw.write(mFile);fprintf_s(mFile,";\n");}
	/*The points of the deformed wire.*/
	void setDeformedWire(size_t dw_i,const NurbsCurveID& dw){fprintf_s(mFile,"connectAttr \"");dw.write(mFile);fprintf_s(mFile,"\" \"%s.dw[%i]\";\n",mName.c_str(),dw_i);}
	/*The points of the base wire.*/
	void setBaseWire(size_t bw_i,const nurbsCurve& bw){fprintf_s(mFile, "setAttr \".bw[%i]\" -type \"nurbsCurve\" ",bw_i);bw.write(mFile);fprintf_s(mFile,";\n");}
	/*The points of the base wire.*/
	void setBaseWire(size_t bw_i,const NurbsCurveID& bw){fprintf_s(mFile,"connectAttr \"");bw.write(mFile);fprintf_s(mFile,"\" \"%s.bw[%i]\";\n",mName.c_str(),bw_i);}
	/*A list of (optional) holder curves.*/
	void setHolder(size_t ho_i,const GenericID& ho){fprintf_s(mFile,"connectAttr \"");ho.write(mFile);fprintf_s(mFile,"\" \"%s.ho[%i]\";\n",mName.c_str(),ho_i);}
	/*
	Convolution filter value. 0.0 means full convolution; 1.0
	produces an additive effect.
	*/
	FloatID getCrossingEffect(){char buffer[4096];sprintf_s (buffer, "%s.ce",mName.c_str());return (const char*)buffer;}
	/*Convolution filter tension*/
	FloatID getTension(){char buffer[4096];sprintf_s (buffer, "%s.te",mName.c_str());return (const char*)buffer;}
	/*
	Local filter value. 0.0 means no local effect;
	1.0 produces a localized effect.
	*/
	FloatID getLocalInfluence(){char buffer[4096];sprintf_s (buffer, "%s.li",mName.c_str());return (const char*)buffer;}
	/*
	Orientation effect. 0.0 produces no orientation effect;
	1.0 produces the full orientation effect.
	*/
	FloatID getRotation(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*
	Wire mapping is frozen when the state of this variable is toggled on.
	This should be done only for performance improvement.
	Be careful not to move the geometry relative to the base wire if
	this is turned on!
	*/
	BoolID getFreezeGeometry(){char buffer[4096];sprintf_s (buffer, "%s.fg",mName.c_str());return (const char*)buffer;}
	/*Offset radius for dropoff around a wire.*/
	const FloatID& getDropoffDistance(size_t dds_i){char buffer[4096];sprintf_s (buffer, "%s.dds[%i]",mName.c_str(),dds_i);return (const char*)buffer;}
	/*Scale for dropoff around a wire.*/
	const FloatID& getScale(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i]",mName.c_str(),sc_i);return (const char*)buffer;}
	/*The percents of the wire locators for radius calculation.*/
	const FloatID& getWireLocatorPercentage(size_t wlpc_i){char buffer[4096];sprintf_s (buffer, "%s.wlpc[%i]",mName.c_str(),wlpc_i);return (const char*)buffer;}
	/*The parameters of the wire locators for radius calculation.*/
	const FloatID& getWireLocatorParameter(size_t wlp_i){char buffer[4096];sprintf_s (buffer, "%s.wlp[%i]",mName.c_str(),wlp_i);return (const char*)buffer;}
	/*The envelope of a wire locator.*/
	const FloatID& getWireLocatorEnvelope(size_t wle_i){char buffer[4096];sprintf_s (buffer, "%s.wle[%i]",mName.c_str(),wle_i);return (const char*)buffer;}
	/*The twist of a wire locator.*/
	const FloatID& getWireLocatorTwist(size_t wlt_i){char buffer[4096];sprintf_s (buffer, "%s.wlt[%i]",mName.c_str(),wlt_i);return (const char*)buffer;}
	/*The points of the deformed wire.*/
	const NurbsCurveID& getDeformedWire(size_t dw_i){char buffer[4096];sprintf_s (buffer, "%s.dw[%i]",mName.c_str(),dw_i);return (const char*)buffer;}
	/*The points of the base wire.*/
	const NurbsCurveID& getBaseWire(size_t bw_i){char buffer[4096];sprintf_s (buffer, "%s.bw[%i]",mName.c_str(),bw_i);return (const char*)buffer;}
	/*A list of (optional) holder curves.*/
	const GenericID& getHolder(size_t ho_i){char buffer[4096];sprintf_s (buffer, "%s.ho[%i]",mName.c_str(),ho_i);return (const char*)buffer;}
protected:
	Wire(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):WeightGeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_WIRE_H__
