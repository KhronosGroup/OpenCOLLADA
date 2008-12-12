/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVENORMALIZERANGLE_H__
#define __MayaDM_CURVENORMALIZERANGLE_H__
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
class CurveNormalizerAngle : public CurveNormalizer
{
public:
public:
	CurveNormalizerAngle(FILE* file,const std::string& name,const std::string& parent=""):CurveNormalizer(file, name, parent, "curveNormalizerAngle"){}
	virtual ~CurveNormalizerAngle(){}
	/*the first input value*/
	void setAnimInput(double ai){if(ai == 0) return; fprintf_s(mFile, "setAttr \".ai\" %f;\n", ai);}
	/*the first input value*/
	void setAnimInput(const DoubleID& ai){fprintf_s(mFile,"connectAttr \"");ai.write(mFile);fprintf_s(mFile,"\" \"%s.ai\";\n",mName.c_str());}
	/*the prodcut of the node's input values (= animInput * scalar )*/
	void setOutput(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*the first input value*/
	DoubleID getAnimInput(){char buffer[4096];sprintf_s (buffer, "%s.ai",mName.c_str());return (const char*)buffer;}
	/*the prodcut of the node's input values (= animInput * scalar )*/
	DoubleID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	CurveNormalizerAngle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveNormalizer(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVENORMALIZERANGLE_H__
