/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HAIRCONSTRAINT_H__
#define __MayaDM_HAIRCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
This node can be used to constrain points in a hair simulation.
 <p/>
*/
class HairConstraint : public Shape
{
public:
public:
	HairConstraint(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "hairConstraint"){}
	virtual ~HairConstraint(){}
	/*HairSystem node index values used to determine curves affected by this constraint.*/
	void setCurveIndices(size_t cin_i,int cin){if(cin == 0) return; fprintf_s(mFile, "setAttr \".cin[%i]\" %i;\n", cin_i,cin);}
	/*HairSystem node index values used to determine curves affected by this constraint.*/
	void setCurveIndices(size_t cin_i,const IntID& cin){fprintf_s(mFile,"connectAttr \"");cin.write(mFile);fprintf_s(mFile,"\" \"%s.cin[%i]\";\n",mName.c_str(),cin_i);}
	/*
	This specifies how the hairpin constrains the hair. If off then no constraint is computed.
	HairToPin locks attaches the hair to the pin, such that moving the pin will drag along the hair.
	HairToHair will constrain the hair vertices at the pin location to other hair vertices. The attachments
	are created at the startframe and are based on the start position of the hairs. The closest points
	along each hair to the pin are the ones that get the constraint.
	*/
	void setConstraintMethod(unsigned int cm){if(cm == 1) return; fprintf_s(mFile, "setAttr \".cm\" %i;\n", cm);}
	/*
	This specifies how the hairpin constrains the hair. If off then no constraint is computed.
	HairToPin locks attaches the hair to the pin, such that moving the pin will drag along the hair.
	HairToHair will constrain the hair vertices at the pin location to other hair vertices. The attachments
	are created at the startframe and are based on the start position of the hairs. The closest points
	along each hair to the pin are the ones that get the constraint.
	*/
	void setConstraintMethod(const UnsignedintID& cm){fprintf_s(mFile,"connectAttr \"");cm.write(mFile);fprintf_s(mFile,"\" \"%s.cm\";\n",mName.c_str());}
	/*
	This specifies how the point to constrain along each hair is determined.
	Nearest constrains the closest point on each curve to the constraint at the start frame.
	U Parameter constrains the point at that U value along the curve. The end of the curve is 1.0 .
	U Distance constrains the points at that distance in worldspace from the start of the curve.
	*/
	void setPointMethod(unsigned int pmt){if(pmt == 0) return; fprintf_s(mFile, "setAttr \".pmt\" %i;\n", pmt);}
	/*
	This specifies how the point to constrain along each hair is determined.
	Nearest constrains the closest point on each curve to the constraint at the start frame.
	U Parameter constrains the point at that U value along the curve. The end of the curve is 1.0 .
	U Distance constrains the points at that distance in worldspace from the start of the curve.
	*/
	void setPointMethod(const UnsignedintID& pmt){fprintf_s(mFile,"connectAttr \"");pmt.write(mFile);fprintf_s(mFile,"\" \"%s.pmt\";\n",mName.c_str());}
	/*The stiffness of the spring attachments created by the hair pin.*/
	void setStiffness(double stf){if(stf == 0.5) return; fprintf_s(mFile, "setAttr \".stf\" %f;\n", stf);}
	/*The stiffness of the spring attachments created by the hair pin.*/
	void setStiffness(const DoubleID& stf){fprintf_s(mFile,"connectAttr \"");stf.write(mFile);fprintf_s(mFile,"\" \"%s.stf\";\n",mName.c_str());}
	/*
	Strength of glue holding the pin. A value less than one can allow the
	constraint to break during the simulation if the tension exceeds the strength.
	*/
	void setGlueStrength(double gst){if(gst == 1.0) return; fprintf_s(mFile, "setAttr \".gst\" %f;\n", gst);}
	/*
	Strength of glue holding the pin. A value less than one can allow the
	constraint to break during the simulation if the tension exceeds the strength.
	*/
	void setGlueStrength(const DoubleID& gst){fprintf_s(mFile,"connectAttr \"");gst.write(mFile);fprintf_s(mFile,"\" \"%s.gst\";\n",mName.c_str());}
	/*
	If the point method is uParameter this determines the u value used in determining
	the point along curves to constrain.
	*/
	void setUParameter(double upr){if(upr == 1.0) return; fprintf_s(mFile, "setAttr \".upr\" %f;\n", upr);}
	/*
	If the point method is uParameter this determines the u value used in determining
	the point along curves to constrain.
	*/
	void setUParameter(const DoubleID& upr){fprintf_s(mFile,"connectAttr \"");upr.write(mFile);fprintf_s(mFile,"\" \"%s.upr\";\n",mName.c_str());}
	/*
	If the point method is uDistance this determines the distance from the curve start
	that determines the point along curves to constrain.
	*/
	void setUDistance(double udi){if(udi == 1.0) return; fprintf_s(mFile, "setAttr \".udi\" %f;\n", udi);}
	/*
	If the point method is uDistance this determines the distance from the curve start
	that determines the point along curves to constrain.
	*/
	void setUDistance(const DoubleID& udi){fprintf_s(mFile,"connectAttr \"");udi.write(mFile);fprintf_s(mFile,"\" \"%s.udi\";\n",mName.c_str());}
	/*output hairpin data for use by hairSystemShape node*/
	void setOutPin(size_t opn_i,const HairPinID& opn){fprintf_s(mFile,"connectAttr \"");opn.write(mFile);fprintf_s(mFile,"\" \"%s.opn[%i]\";\n",mName.c_str(),opn_i);}
	/*HairSystem node index values used to determine curves affected by this constraint.*/
	const IntID& getCurveIndices(size_t cin_i){char buffer[4096];sprintf_s (buffer, "%s.cin[%i]",mName.c_str(),cin_i);return (const char*)buffer;}
	/*
	This specifies how the hairpin constrains the hair. If off then no constraint is computed.
	HairToPin locks attaches the hair to the pin, such that moving the pin will drag along the hair.
	HairToHair will constrain the hair vertices at the pin location to other hair vertices. The attachments
	are created at the startframe and are based on the start position of the hairs. The closest points
	along each hair to the pin are the ones that get the constraint.
	*/
	UnsignedintID getConstraintMethod(){char buffer[4096];sprintf_s (buffer, "%s.cm",mName.c_str());return (const char*)buffer;}
	/*
	This specifies how the point to constrain along each hair is determined.
	Nearest constrains the closest point on each curve to the constraint at the start frame.
	U Parameter constrains the point at that U value along the curve. The end of the curve is 1.0 .
	U Distance constrains the points at that distance in worldspace from the start of the curve.
	*/
	UnsignedintID getPointMethod(){char buffer[4096];sprintf_s (buffer, "%s.pmt",mName.c_str());return (const char*)buffer;}
	/*The stiffness of the spring attachments created by the hair pin.*/
	DoubleID getStiffness(){char buffer[4096];sprintf_s (buffer, "%s.stf",mName.c_str());return (const char*)buffer;}
	/*
	Strength of glue holding the pin. A value less than one can allow the
	constraint to break during the simulation if the tension exceeds the strength.
	*/
	DoubleID getGlueStrength(){char buffer[4096];sprintf_s (buffer, "%s.gst",mName.c_str());return (const char*)buffer;}
	/*
	If the point method is uParameter this determines the u value used in determining
	the point along curves to constrain.
	*/
	DoubleID getUParameter(){char buffer[4096];sprintf_s (buffer, "%s.upr",mName.c_str());return (const char*)buffer;}
	/*
	If the point method is uDistance this determines the distance from the curve start
	that determines the point along curves to constrain.
	*/
	DoubleID getUDistance(){char buffer[4096];sprintf_s (buffer, "%s.udi",mName.c_str());return (const char*)buffer;}
	/*output hairpin data for use by hairSystemShape node*/
	const HairPinID& getOutPin(size_t opn_i){char buffer[4096];sprintf_s (buffer, "%s.opn[%i]",mName.c_str(),opn_i);return (const char*)buffer;}
protected:
	HairConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HAIRCONSTRAINT_H__
