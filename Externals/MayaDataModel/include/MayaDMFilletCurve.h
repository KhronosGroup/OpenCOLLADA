/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILLETCURVE_H__
#define __MayaDM_FILLETCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute the fillet curve given two input curves. The two input curves can
 be the same curve. The type of fillet created (circular) can be circular or
 freeform. For a circular fillet a radius value (radius) is required. There
 are two types of freeform fillets (freeformBlend): blend and tangent. The
 blendControl option must be true in order to control depth and bias values.
 Note that a true circular fillet is not created if blendControl is on.
 <br/>
 The two input curves can be trimmed (if trim is true) at the point where the
 fillet curve contacts them. The trimmed curves are output in detachedCurve1
 and detachedCurve2. If join is on as well, then the trimmed curves can be
 attached to the fillet curve. The attached curves will be output in
 outputCurve only and no trimmed curves are available through detachedCurve1
 and detachedCurve2.
 <p/>
*/
class FilletCurve : public AbstractBaseCreate
{
public:
public:
	FilletCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "filletCurve"){}
	virtual ~FilletCurve(){}
	/*The primary curve.*/
	void setPrimaryCurve(const NurbsCurveID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*The secondary curve.*/
	void setSecondaryCurve(const NurbsCurveID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*Output fillet/joined curve.*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Output trimmed primary curve. Available when trim is true and join is false.*/
	void setDetachedCurve1(const NurbsCurveID& dc1){fprintf_s(mFile,"connectAttr \"");dc1.write(mFile);fprintf_s(mFile,"\" \"%s.dc1\";\n",mName.c_str());}
	/*Output trimmed secondary curve. Available when trim is true and join is false.*/
	void setDetachedCurve2(const NurbsCurveID& dc2){fprintf_s(mFile,"connectAttr \"");dc2.write(mFile);fprintf_s(mFile,"\" \"%s.dc2\";\n",mName.c_str());}
	/*The radius if creating a circular fillet.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*The radius if creating a circular fillet.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Adjusts the depth of the fillet curve. Available only if blendControl is true.*/
	void setDepth(double d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*Adjusts the depth of the fillet curve. Available only if blendControl is true.*/
	void setDepth(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Adjusting the bias value causes the fillet curve to be skewed to one of the input curves. Available only if blendControl is true.*/
	void setBias(double b){if(b == 0) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*Adjusting the bias value causes the fillet curve to be skewed to one of the input curves. Available only if blendControl is true.*/
	void setBias(const DoubleID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*Parameter where fillet curve will contact the primary input curve.*/
	void setCurveParameter1(double cp1){if(cp1 == 0.0) return; fprintf_s(mFile, "setAttr \".cp1\" %f;\n", cp1);}
	/*Parameter where fillet curve will contact the primary input curve.*/
	void setCurveParameter1(const DoubleID& cp1){fprintf_s(mFile,"connectAttr \"");cp1.write(mFile);fprintf_s(mFile,"\" \"%s.cp1\";\n",mName.c_str());}
	/*Parameter where fillet curve will contact the secondary input curve.*/
	void setCurveParameter2(double cp2){if(cp2 == 0.0) return; fprintf_s(mFile, "setAttr \".cp2\" %f;\n", cp2);}
	/*Parameter where fillet curve will contact the secondary input curve.*/
	void setCurveParameter2(const DoubleID& cp2){fprintf_s(mFile,"connectAttr \"");cp2.write(mFile);fprintf_s(mFile,"\" \"%s.cp2\";\n",mName.c_str());}
	/*If true, trim the input curves at the parameter values. Otherwise, leave the input curves as they are. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setTrim(bool t){if(t == false) return; fprintf_s(mFile, "setAttr \".t\" %i;\n", t);}
	/*If true, trim the input curves at the parameter values. Otherwise, leave the input curves as they are. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setTrim(const BoolID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*If true, join the trimmed curves to the fillet curve. Available only if trim option is true. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setJoin(bool jn){if(jn == false) return; fprintf_s(mFile, "setAttr \".jn\" %i;\n", jn);}
	/*If true, join the trimmed curves to the fillet curve. Available only if trim option is true. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setJoin(const BoolID& jn){fprintf_s(mFile,"connectAttr \"");jn.write(mFile);fprintf_s(mFile,"\" \"%s.jn\";\n",mName.c_str());}
	/*Curve fillet will be created as circular if true or freeform if false.*/
	void setCircular(bool cir){if(cir == true) return; fprintf_s(mFile, "setAttr \".cir\" %i;\n", cir);}
	/*Curve fillet will be created as circular if true or freeform if false.*/
	void setCircular(const BoolID& cir){fprintf_s(mFile,"connectAttr \"");cir.write(mFile);fprintf_s(mFile,"\" \"%s.cir\";\n",mName.c_str());}
	/*The freeform type is blend if true or tangent if false. Available if the fillet type is freeform.*/
	void setFreeformBlend(bool fb){if(fb == false) return; fprintf_s(mFile, "setAttr \".fb\" %i;\n", fb);}
	/*The freeform type is blend if true or tangent if false. Available if the fillet type is freeform.*/
	void setFreeformBlend(const BoolID& fb){fprintf_s(mFile,"connectAttr \"");fb.write(mFile);fprintf_s(mFile,"\" \"%s.fb\";\n",mName.c_str());}
	/*If true then depth and bias can be controlled. Otherwise, depth and bias are not available options.*/
	void setBlendControl(bool bc){if(bc == false) return; fprintf_s(mFile, "setAttr \".bc\" %i;\n", bc);}
	/*If true then depth and bias can be controlled. Otherwise, depth and bias are not available options.*/
	void setBlendControl(const BoolID& bc){fprintf_s(mFile,"connectAttr \"");bc.write(mFile);fprintf_s(mFile,"\" \"%s.bc\";\n",mName.c_str());}
	/*The primary curve.*/
	NurbsCurveID getPrimaryCurve(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*The secondary curve.*/
	NurbsCurveID getSecondaryCurve(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*Output fillet/joined curve.*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*Output trimmed primary curve. Available when trim is true and join is false.*/
	NurbsCurveID getDetachedCurve1(){char buffer[4096];sprintf_s (buffer, "%s.dc1",mName.c_str());return (const char*)buffer;}
	/*Output trimmed secondary curve. Available when trim is true and join is false.*/
	NurbsCurveID getDetachedCurve2(){char buffer[4096];sprintf_s (buffer, "%s.dc2",mName.c_str());return (const char*)buffer;}
	/*The radius if creating a circular fillet.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Adjusts the depth of the fillet curve. Available only if blendControl is true.*/
	DoubleID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Adjusting the bias value causes the fillet curve to be skewed to one of the input curves. Available only if blendControl is true.*/
	DoubleID getBias(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*Parameter where fillet curve will contact the primary input curve.*/
	DoubleID getCurveParameter1(){char buffer[4096];sprintf_s (buffer, "%s.cp1",mName.c_str());return (const char*)buffer;}
	/*Parameter where fillet curve will contact the secondary input curve.*/
	DoubleID getCurveParameter2(){char buffer[4096];sprintf_s (buffer, "%s.cp2",mName.c_str());return (const char*)buffer;}
	/*If true, trim the input curves at the parameter values. Otherwise, leave the input curves as they are. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getTrim(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*If true, join the trimmed curves to the fillet curve. Available only if trim option is true. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getJoin(){char buffer[4096];sprintf_s (buffer, "%s.jn",mName.c_str());return (const char*)buffer;}
	/*Curve fillet will be created as circular if true or freeform if false.*/
	BoolID getCircular(){char buffer[4096];sprintf_s (buffer, "%s.cir",mName.c_str());return (const char*)buffer;}
	/*The freeform type is blend if true or tangent if false. Available if the fillet type is freeform.*/
	BoolID getFreeformBlend(){char buffer[4096];sprintf_s (buffer, "%s.fb",mName.c_str());return (const char*)buffer;}
	/*If true then depth and bias can be controlled. Otherwise, depth and bias are not available options.*/
	BoolID getBlendControl(){char buffer[4096];sprintf_s (buffer, "%s.bc",mName.c_str());return (const char*)buffer;}
protected:
	FilletCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FILLETCURVE_H__
