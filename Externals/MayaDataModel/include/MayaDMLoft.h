/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LOFT_H__
#define __MayaDM_LOFT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The 'loft' node constructs a NURBS surface to pass through (interpolate)
 two or more input NURBS curves.
 <p/>
 The attribute ".ic[i]" is used to specify the i-th NURBS curve
 to be used for the surface creation.
 <p/>
 The attribute ".degree" is used to specify the degree of the
 constructed surface. The following are legal values : 1 - Linear,
 3- Cubic.
 <p/>
 The attribute ".uniform" can be used to choose between uniform
 or chord length parameterization in the direction across the
 input curves on the resulting surface.
 <p/>
 The attribute ".close" can be used to close the surface in the
 direction across the input NURBS curves.
 <p/>
 The attribute ".ar" is used to automate the reversal of input
 curves. The input curves are internally reversed as required in
 order to avoid a bow-tie like surface. A 'true' value overrides
 any explicit reversal specified on the individual input curves.
 <p/>
 The attribute ".r[i]" can be used to explicitly reverse the i-th
 input NURBS curve. It must be noted that the attribute ".ar"  must
 be set to 'false' for the attribute ".r[i]" to have any effect.
 <p/>
 The attribute ".cc[i]" can be used to create a (potential) cusp
 at the i-th profile curve.
*/
class Loft : public AbstractBaseCreate
{
public:
public:
	Loft(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "loft"){}
	virtual ~Loft(){}
	/*The input curves*/
	void setInputCurve(size_t ic_i,const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i]\";\n",mName.c_str(),ic_i);}
	/*If set to true, the resulting surface will have uniform parameterization in the loft direction.  If set to false, the parameterization will be chord length.*/
	void setUniform(bool u){if(u == false) return; fprintf_s(mFile, "setAttr \".u\" %i;\n", u);}
	/*If set to true, the resulting surface will have uniform parameterization in the loft direction.  If set to false, the parameterization will be chord length.*/
	void setUniform(const BoolID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*If set to true, the resulting surface will be closed (periodic) with the start (end) at the first curve.  If set to false, the surface will remain open.*/
	void setClose(bool c){if(c == false) return; fprintf_s(mFile, "setAttr \".c\" %i;\n", c);}
	/*If set to true, the resulting surface will be closed (periodic) with the start (end) at the first curve.  If set to false, the surface will remain open.*/
	void setClose(const BoolID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*The degree of the resulting surface*/
	void setDegree(unsigned int d){if(d == 3) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*The degree of the resulting surface*/
	void setDegree(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Output NURBS surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*If set to true, the direction of the curves for the loft is computed automatically.  If set to false, the values of the multi-use reverse flag are used instead.*/
	void setAutoReverse(bool ar){if(ar == true) return; fprintf_s(mFile, "setAttr \".ar\" %i;\n", ar);}
	/*If set to true, the direction of the curves for the loft is computed automatically.  If set to false, the values of the multi-use reverse flag are used instead.*/
	void setAutoReverse(const BoolID& ar){fprintf_s(mFile,"connectAttr \"");ar.write(mFile);fprintf_s(mFile,"\" \"%s.ar\";\n",mName.c_str());}
	/*Multi-use flag; each occurence of the flag refers to the matching curve in the loft operation; if the flag is set the particular curve will be reversed before being used in the loft operation.*/
	void setReverse(size_t r_i,bool r){if(r == false) return; fprintf_s(mFile, "setAttr \".r[%i]\" %i;\n", r_i,r);}
	/*Multi-use flag; each occurence of the flag refers to the matching curve in the loft operation; if the flag is set the particular curve will be reversed before being used in the loft operation.*/
	void setReverse(size_t r_i,const BoolID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i]\";\n",mName.c_str(),r_i);}
	/*If set, the surface normals on the output NURBS surface will be reversed.  This is accomplished by swapping the U and V parametric directions.*/
	void setReverseSurfaceNormals(bool rsn){if(rsn == false) return; fprintf_s(mFile, "setAttr \".rsn\" %i;\n", rsn);}
	/*If set, the surface normals on the output NURBS surface will be reversed.  This is accomplished by swapping the U and V parametric directions.*/
	void setReverseSurfaceNormals(const BoolID& rsn){fprintf_s(mFile,"connectAttr \"");rsn.write(mFile);fprintf_s(mFile,"\" \"%s.rsn\";\n",mName.c_str());}
	/*The number of surface spans between consecutive curves in the loft.*/
	void setSectionSpans(int ss){if(ss == 1) return; fprintf_s(mFile, "setAttr \".ss\" %i;\n", ss);}
	/*The number of surface spans between consecutive curves in the loft.*/
	void setSectionSpans(const IntID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*Multi-use flag; each occurence of the flag refers to the matching curve in the loft operation; if the flag is set the particular profile will have a cusp (tangent break) in the resulting surface.*/
	void setCreateCusp(size_t cc_i,bool cc){if(cc == false) return; fprintf_s(mFile, "setAttr \".cc[%i]\" %i;\n", cc_i,cc);}
	/*Multi-use flag; each occurence of the flag refers to the matching curve in the loft operation; if the flag is set the particular profile will have a cusp (tangent break) in the resulting surface.*/
	void setCreateCusp(size_t cc_i,const BoolID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.cc[%i]\";\n",mName.c_str(),cc_i);}
	/*The input curves*/
	const NurbsCurveID& getInputCurve(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i]",mName.c_str(),ic_i);return (const char*)buffer;}
	/*If set to true, the resulting surface will have uniform parameterization in the loft direction.  If set to false, the parameterization will be chord length.*/
	BoolID getUniform(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*If set to true, the resulting surface will be closed (periodic) with the start (end) at the first curve.  If set to false, the surface will remain open.*/
	BoolID getClose(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*The degree of the resulting surface*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Output NURBS surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*If set to true, the direction of the curves for the loft is computed automatically.  If set to false, the values of the multi-use reverse flag are used instead.*/
	BoolID getAutoReverse(){char buffer[4096];sprintf_s (buffer, "%s.ar",mName.c_str());return (const char*)buffer;}
	/*Multi-use flag; each occurence of the flag refers to the matching curve in the loft operation; if the flag is set the particular curve will be reversed before being used in the loft operation.*/
	const BoolID& getReverse(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i]",mName.c_str(),r_i);return (const char*)buffer;}
	/*If set, the surface normals on the output NURBS surface will be reversed.  This is accomplished by swapping the U and V parametric directions.*/
	BoolID getReverseSurfaceNormals(){char buffer[4096];sprintf_s (buffer, "%s.rsn",mName.c_str());return (const char*)buffer;}
	/*The number of surface spans between consecutive curves in the loft.*/
	IntID getSectionSpans(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*Multi-use flag; each occurence of the flag refers to the matching curve in the loft operation; if the flag is set the particular profile will have a cusp (tangent break) in the resulting surface.*/
	const BoolID& getCreateCusp(size_t cc_i){char buffer[4096];sprintf_s (buffer, "%s.cc[%i]",mName.c_str(),cc_i);return (const char*)buffer;}
protected:
	Loft(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LOFT_H__
