/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OFFSETCURVE_H__
#define __MayaDM_OFFSETCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Create a new curve which is an offset of an existing curve.
 The 'distance' attribute defines how far the offset curve should be
 from the original curve, and the 'tolerance' attribute sets the
 accuracy required. 'subdivisionDensity' defines how many times the
 offset curve spans can be subdivided in order to match the required
 tolerance. If there are sharp corners on the original curve, the
 offset curve may break into separate sections at these points. The
 attribute 'connectBreaks' can be set to ensure such breaks are
 filled, either with a linear or a circular curve section. In some
 cases the offset curve may contain a loop. The attribute 'cutLoop'
 can be set to cut off such loops, and, if this attribute is set, an
 additional attribute 'cutRadius' can be set to round off the
 resulting corner. 'useGivenNormal' defines whether a user-defined
 normal is or the normal to the curve is used.
*/
class OffsetCurve : public AbstractBaseCreate
{
public:
public:
	OffsetCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "offsetCurve"){}
	virtual ~OffsetCurve(){}
	/*The input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*
	Connect breaks method (between gaps):
	0 - off,
	1 - circular,
	2 - linear
	*/
	void setConnectBreaks(unsigned int cb){if(cb == 2) return; fprintf_s(mFile, "setAttr \".cb\" %i;\n", cb);}
	/*
	Connect breaks method (between gaps):
	0 - off,
	1 - circular,
	2 - linear
	*/
	void setConnectBreaks(const UnsignedintID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cb\";\n",mName.c_str());}
	/*Do reparameterization? Not advisable to change this value.*/
	void setReparameterize(bool rp){if(rp == false) return; fprintf_s(mFile, "setAttr \".rp\" %i;\n", rp);}
	/*Do reparameterization? Not advisable to change this value.*/
	void setReparameterize(const BoolID& rp){fprintf_s(mFile,"connectAttr \"");rp.write(mFile);fprintf_s(mFile,"\" \"%s.rp\";\n",mName.c_str());}
	/*Stitch curve segments together. Not advisable to change this value.*/
	void setStitch(bool st){if(st == true) return; fprintf_s(mFile, "setAttr \".st\" %i;\n", st);}
	/*Stitch curve segments together. Not advisable to change this value.*/
	void setStitch(const BoolID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*Do loop cutting?*/
	void setCutLoop(bool cl){if(cl == false) return; fprintf_s(mFile, "setAttr \".cl\" %i;\n", cl);}
	/*Do loop cutting?*/
	void setCutLoop(const BoolID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl\";\n",mName.c_str());}
	/*Loop cut radius. Only used if cutLoop attribute is set true.*/
	void setCutRadius(double cr){if(cr == 0) return; fprintf_s(mFile, "setAttr \".cr\" %f;\n", cr);}
	/*Loop cut radius. Only used if cutLoop attribute is set true.*/
	void setCutRadius(const DoubleID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*Offset distance*/
	void setDistance(double d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*Offset distance*/
	void setDistance(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Tolerance*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*Tolerance*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*Maximum subdivision density per span*/
	void setSubdivisionDensity(int sd){if(sd == 5) return; fprintf_s(mFile, "setAttr \".sd\" %i;\n", sd);}
	/*Maximum subdivision density per span*/
	void setSubdivisionDensity(const IntID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd\";\n",mName.c_str());}
	/*Use the given normal (or, alternativelly, geometry normal)*/
	void setUseGivenNormal(bool ugn){if(ugn == 1) return; fprintf_s(mFile, "setAttr \".ugn\" %i;\n", ugn);}
	/*Use the given normal (or, alternativelly, geometry normal)*/
	void setUseGivenNormal(const BoolID& ugn){fprintf_s(mFile,"connectAttr \"");ugn.write(mFile);fprintf_s(mFile,"\" \"%s.ugn\";\n",mName.c_str());}
	/*Offset plane normal*/
	void setNormal(const double3& nr){fprintf_s(mFile, "setAttr \".nr\" -type \"double3\" ");nr.write(mFile);fprintf_s(mFile,";\n");}
	/*Offset plane normal*/
	void setNormal(const Double3ID& nr){fprintf_s(mFile,"connectAttr \"");nr.write(mFile);fprintf_s(mFile,"\" \"%s.nr\";\n",mName.c_str());}
	/*X of the normal*/
	void setNormalX(double nrx){if(nrx == 0) return; fprintf_s(mFile, "setAttr \".nr.nrx\" %f;\n", nrx);}
	/*X of the normal*/
	void setNormalX(const DoubleID& nrx){fprintf_s(mFile,"connectAttr \"");nrx.write(mFile);fprintf_s(mFile,"\" \"%s.nr.nrx\";\n",mName.c_str());}
	/*Y of the normal*/
	void setNormalY(double nry){if(nry == 1) return; fprintf_s(mFile, "setAttr \".nr.nry\" %f;\n", nry);}
	/*Y of the normal*/
	void setNormalY(const DoubleID& nry){fprintf_s(mFile,"connectAttr \"");nry.write(mFile);fprintf_s(mFile,"\" \"%s.nr.nry\";\n",mName.c_str());}
	/*Z of the normal*/
	void setNormalZ(double nrz){if(nrz == 0) return; fprintf_s(mFile, "setAttr \".nr.nrz\" %f;\n", nrz);}
	/*Z of the normal*/
	void setNormalZ(const DoubleID& nrz){fprintf_s(mFile,"connectAttr \"");nrz.write(mFile);fprintf_s(mFile,"\" \"%s.nr.nrz\";\n",mName.c_str());}
	/*parameter value on the curve to use while drawing manipulator on offset history*/
	void setParameter(double p){if(p == 0.0) return; fprintf_s(mFile, "setAttr \".p\" %f;\n", p);}
	/*parameter value on the curve to use while drawing manipulator on offset history*/
	void setParameter(const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*use parameter value on the curve while drawing manipulator on offset history*/
	void setUseParameter(bool up){if(up == false) return; fprintf_s(mFile, "setAttr \".up\" %i;\n", up);}
	/*use parameter value on the curve while drawing manipulator on offset history*/
	void setUseParameter(const BoolID& up){fprintf_s(mFile,"connectAttr \"");up.write(mFile);fprintf_s(mFile,"\" \"%s.up\";\n",mName.c_str());}
	/*Output curves*/
	void setOutputCurve(size_t oc_i,const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc[%i]\";\n",mName.c_str(),oc_i);}
	/*The input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*
	Connect breaks method (between gaps):
	0 - off,
	1 - circular,
	2 - linear
	*/
	UnsignedintID getConnectBreaks(){char buffer[4096];sprintf_s (buffer, "%s.cb",mName.c_str());return (const char*)buffer;}
	/*Do reparameterization? Not advisable to change this value.*/
	BoolID getReparameterize(){char buffer[4096];sprintf_s (buffer, "%s.rp",mName.c_str());return (const char*)buffer;}
	/*Stitch curve segments together. Not advisable to change this value.*/
	BoolID getStitch(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*Do loop cutting?*/
	BoolID getCutLoop(){char buffer[4096];sprintf_s (buffer, "%s.cl",mName.c_str());return (const char*)buffer;}
	/*Loop cut radius. Only used if cutLoop attribute is set true.*/
	DoubleID getCutRadius(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*Offset distance*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Tolerance*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*Maximum subdivision density per span*/
	IntID getSubdivisionDensity(){char buffer[4096];sprintf_s (buffer, "%s.sd",mName.c_str());return (const char*)buffer;}
	/*Use the given normal (or, alternativelly, geometry normal)*/
	BoolID getUseGivenNormal(){char buffer[4096];sprintf_s (buffer, "%s.ugn",mName.c_str());return (const char*)buffer;}
	/*Offset plane normal*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.nr",mName.c_str());return (const char*)buffer;}
	/*X of the normal*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.nr.nrx",mName.c_str());return (const char*)buffer;}
	/*Y of the normal*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.nr.nry",mName.c_str());return (const char*)buffer;}
	/*Z of the normal*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.nr.nrz",mName.c_str());return (const char*)buffer;}
	/*parameter value on the curve to use while drawing manipulator on offset history*/
	DoubleID getParameter(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*use parameter value on the curve while drawing manipulator on offset history*/
	BoolID getUseParameter(){char buffer[4096];sprintf_s (buffer, "%s.up",mName.c_str());return (const char*)buffer;}
	/*Output curves*/
	const NurbsCurveID& getOutputCurve(size_t oc_i){char buffer[4096];sprintf_s (buffer, "%s.oc[%i]",mName.c_str(),oc_i);return (const char*)buffer;}
protected:
	OffsetCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OFFSETCURVE_H__
