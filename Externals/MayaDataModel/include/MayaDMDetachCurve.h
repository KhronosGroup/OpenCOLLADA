/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DETACHCURVE_H__
#define __MayaDM_DETACHCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Detaches a curve at the parameter specified in the "parameter" multiattribute.
 The output is a multiattribute containing the detached curve pieces.
 The "keep" multiattribute (which should be 1 element larger than
 the "parameter" attribute) specifies which curve pieces to keep or discard.
 <p/>
 For example, if a curve is detached at three places, there are four
 curve pieces to keep or discard.
 <p/>
 Generally, the parameters in the "parameter" multiattribute should be
 in ascending order, otherwise the curve pieces may overlap.
 <p/>
 Detaches a curve at the parameter specified in the "parameter" multiattribute.
 The output is a multiattribute containing the detached curve pieces.
 The "keep" multiattribute (which should be 1 element larger than
 the "parameter" attribute) specifies which curve pieces to keep or discard.
 <p/>
 For example, if a curve is detached at three places, there are four
 curve pieces to keep or discard.
 <p/>
 Generally, the parameters in the "parameter" multiattribute should be
 in ascending order, otherwise the curve pieces may overlap.
*/
class DetachCurve : public AbstractBaseCreate
{
public:
public:
	DetachCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "detachCurve"){}
	virtual ~DetachCurve(){}
	/*The input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*The output detached curve(s)*/
	void setOutputCurve(size_t oc_i,const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc[%i]\";\n",mName.c_str(),oc_i);}
	/*Parameter values to detach at*/
	void setParameter(size_t p_i,double p){if(p == 0.0) return; fprintf_s(mFile, "setAttr \".p[%i]\" %f;\n", p_i,p);}
	/*Parameter values to detach at*/
	void setParameter(size_t p_i,const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*Whether or not to keep a detached piece.  This multiattribute should be one element larger than the parameter multattribute.*/
	void setKeep(size_t k_i,bool k){if(k == true) return; fprintf_s(mFile, "setAttr \".k[%i]\" %i;\n", k_i,k);}
	/*Whether or not to keep a detached piece.  This multiattribute should be one element larger than the parameter multattribute.*/
	void setKeep(size_t k_i,const BoolID& k){fprintf_s(mFile,"connectAttr \"");k.write(mFile);fprintf_s(mFile,"\" \"%s.k[%i]\";\n",mName.c_str(),k_i);}
	/*The input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*The output detached curve(s)*/
	const NurbsCurveID& getOutputCurve(size_t oc_i){char buffer[4096];sprintf_s (buffer, "%s.oc[%i]",mName.c_str(),oc_i);return (const char*)buffer;}
	/*Parameter values to detach at*/
	const DoubleID& getParameter(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*Whether or not to keep a detached piece.  This multiattribute should be one element larger than the parameter multattribute.*/
	const BoolID& getKeep(size_t k_i){char buffer[4096];sprintf_s (buffer, "%s.k[%i]",mName.c_str(),k_i);return (const char*)buffer;}
protected:
	DetachCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DETACHCURVE_H__
