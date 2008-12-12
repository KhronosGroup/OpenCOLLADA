/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REVERSECURVE_H__
#define __MayaDM_REVERSECURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Reverses the direction of the input curve.  The parameter range of the
  curve remains the same.  This is useful if the curve is the input to
  an operation where curve direction is important, eg. if the curve
  is used as a motion path.
  <p/> If a curve is reversed twice, the result is exactly the same
  as the original curve.
*/
class ReverseCurve : public AbstractBaseCreate
{
public:
public:
	ReverseCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "reverseCurve"){}
	virtual ~ReverseCurve(){}
	/*The input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*The output curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*The output curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	ReverseCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REVERSECURVE_H__
