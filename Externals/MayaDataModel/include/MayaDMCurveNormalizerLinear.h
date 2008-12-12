/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVENORMALIZERLINEAR_H__
#define __MayaDM_CURVENORMALIZERLINEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveNormalizer.h"
namespace MayaDM
{
/*
<p><pre>
  This node multiplies the values from both its inputs and outputs the
    product.

</pre></p>
*/
class CurveNormalizerLinear : public CurveNormalizer
{
public:
public:
	CurveNormalizerLinear(FILE* file,const std::string& name,const std::string& parent=""):CurveNormalizer(file, name, parent, "curveNormalizerLinear"){}
	virtual ~CurveNormalizerLinear(){}
	/*the first input value*/
	void setAnimInput(double ai){if(ai == 0) return; fprintf_s(mFile, "setAttr \".ai\" %f;\n", ai);}
	/*the first input value*/
	void setAnimInput(const DoubleID& ai){fprintf_s(mFile,"connectAttr \"");ai.write(mFile);fprintf_s(mFile,"\" \"%s.ai\";\n",mName.c_str());}
	/*the prodcut of its input values (= input1 * input2 )*/
	void setOutput(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*the first input value*/
	DoubleID getAnimInput(){char buffer[4096];sprintf_s (buffer, "%s.ai",mName.c_str());return (const char*)buffer;}
	/*the prodcut of its input values (= input1 * input2 )*/
	DoubleID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	CurveNormalizerLinear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveNormalizer(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVENORMALIZERLINEAR_H__
