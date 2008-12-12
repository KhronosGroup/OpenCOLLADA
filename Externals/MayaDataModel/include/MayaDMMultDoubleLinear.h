/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MULTDOUBLELINEAR_H__
#define __MayaDM_MULTDOUBLELINEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
  This node multiplies the values from both its inputs and outputs the
    product.

</pre></p>
*/
class MultDoubleLinear : public DependNode
{
public:
public:
	MultDoubleLinear(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "multDoubleLinear"){}
	virtual ~MultDoubleLinear(){}
	/*the first input value*/
	void setInput1(double i1){if(i1 == 0) return; fprintf_s(mFile, "setAttr \".i1\" %f;\n", i1);}
	/*the first input value*/
	void setInput1(const DoubleID& i1){fprintf_s(mFile,"connectAttr \"");i1.write(mFile);fprintf_s(mFile,"\" \"%s.i1\";\n",mName.c_str());}
	/*the second input value*/
	void setInput2(double i2){if(i2 == 0) return; fprintf_s(mFile, "setAttr \".i2\" %f;\n", i2);}
	/*the second input value*/
	void setInput2(const DoubleID& i2){fprintf_s(mFile,"connectAttr \"");i2.write(mFile);fprintf_s(mFile,"\" \"%s.i2\";\n",mName.c_str());}
	/*the prodcut of its input values (= input1 * input2 )*/
	void setOutput(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*the first input value*/
	DoubleID getInput1(){char buffer[4096];sprintf_s (buffer, "%s.i1",mName.c_str());return (const char*)buffer;}
	/*the second input value*/
	DoubleID getInput2(){char buffer[4096];sprintf_s (buffer, "%s.i2",mName.c_str());return (const char*)buffer;}
	/*the prodcut of its input values (= input1 * input2 )*/
	DoubleID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	MultDoubleLinear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MULTDOUBLELINEAR_H__
