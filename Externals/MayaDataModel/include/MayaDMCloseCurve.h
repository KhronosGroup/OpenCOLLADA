/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOSECURVE_H__
#define __MayaDM_CLOSECURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
If the input curve is open, then this node makes the curve
 periodic.  If the input curve is periodic, then this node makes the curve
 open.
 <p/> This node behaves as a toggle, ie. if a curve is closed twice,
 then the result is exactly the same as the original curve.
 <p/> Use this node if want to close a curve such that it becomes
 curvature continuous along its entire length.
*/
class CloseCurve : public AbstractBaseCreate
{
public:
public:
	CloseCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "closeCurve"){}
	virtual ~CloseCurve(){}
	/*The input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*
	0 - without preserving the shape
	1 - preserve shape
	2 - blend
	*/
	void setPreserveShape(unsigned int ps){if(ps == 1) return; fprintf_s(mFile, "setAttr \".ps\" %i;\n", ps);}
	/*
	0 - without preserving the shape
	1 - preserve shape
	2 - blend
	*/
	void setPreserveShape(const UnsignedintID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*
	Skew the result toward the first or the second curve depending
	on the blend value being smaller or larger than 0.5.
	*/
	void setBlendBias(double bb){if(bb == 0.5) return; fprintf_s(mFile, "setAttr \".bb\" %f;\n", bb);}
	/*
	Skew the result toward the first or the second curve depending
	on the blend value being smaller or larger than 0.5.
	*/
	void setBlendBias(const DoubleID& bb){fprintf_s(mFile,"connectAttr \"");bb.write(mFile);fprintf_s(mFile,"\" \"%s.bb\";\n",mName.c_str());}
	/*
	If set to true, insert a knot in one of the original curves
	(relative position given by the parameter attribute below)
	in order to produce a slightly different effect.
	*/
	void setBlendKnotInsertion(bool bki){if(bki == false) return; fprintf_s(mFile, "setAttr \".bki\" %i;\n", bki);}
	/*
	If set to true, insert a knot in one of the original curves
	(relative position given by the parameter attribute below)
	in order to produce a slightly different effect.
	*/
	void setBlendKnotInsertion(const BoolID& bki){fprintf_s(mFile,"connectAttr \"");bki.write(mFile);fprintf_s(mFile,"\" \"%s.bki\";\n",mName.c_str());}
	/*The parameter value for the positioning of the newly inserted knot.*/
	void setParameter(double p){if(p == 0.1) return; fprintf_s(mFile, "setAttr \".p\" %f;\n", p);}
	/*The parameter value for the positioning of the newly inserted knot.*/
	void setParameter(const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The output curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*
	0 - without preserving the shape
	1 - preserve shape
	2 - blend
	*/
	UnsignedintID getPreserveShape(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*
	Skew the result toward the first or the second curve depending
	on the blend value being smaller or larger than 0.5.
	*/
	DoubleID getBlendBias(){char buffer[4096];sprintf_s (buffer, "%s.bb",mName.c_str());return (const char*)buffer;}
	/*
	If set to true, insert a knot in one of the original curves
	(relative position given by the parameter attribute below)
	in order to produce a slightly different effect.
	*/
	BoolID getBlendKnotInsertion(){char buffer[4096];sprintf_s (buffer, "%s.bki",mName.c_str());return (const char*)buffer;}
	/*The parameter value for the positioning of the newly inserted knot.*/
	DoubleID getParameter(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The output curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	CloseCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLOSECURVE_H__
