/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVENORMALIZER_H__
#define __MayaDM_CURVENORMALIZER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
  This node multiplies the values from animInput and scalar and outputs the
    product. It is intended to be used to scale animCurves.

</pre></p>
*/
class CurveNormalizer : public DependNode
{
public:
public:
	CurveNormalizer(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "curveNormalizer"){}
	virtual ~CurveNormalizer(){}
	/*The value by which to scale the input animCurve.*/
	void setScalar(double sc){if(sc == 1.0) return; fprintf_s(mFile, "setAttr \".sc\" %f;\n", sc);}
	/*The value by which to scale the input animCurve.*/
	void setScalar(const DoubleID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*The value by which to scale the input animCurve.*/
	DoubleID getScalar(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
protected:
	CurveNormalizer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVENORMALIZER_H__
