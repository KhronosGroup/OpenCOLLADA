/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ADDDOUBLELINEAR_H__
#define __MayaDM_ADDDOUBLELINEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*This node adds the values from both its inputs.<p/>*/
class AddDoubleLinear : public DependNode
{
public:
public:
	AddDoubleLinear(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "addDoubleLinear"){}
	virtual ~AddDoubleLinear(){}
	/*the first input value*/
	void setInput1(double i1){if(i1 == 0) return; fprintf_s(mFile, "setAttr \".i1\" %f;\n", i1);}
	/*the first input value*/
	void setInput1(const DoubleID& i1){fprintf_s(mFile,"connectAttr \"");i1.write(mFile);fprintf_s(mFile,"\" \"%s.i1\";\n",mName.c_str());}
	/*the second input value*/
	void setInput2(double i2){if(i2 == 0) return; fprintf_s(mFile, "setAttr \".i2\" %f;\n", i2);}
	/*the second input value*/
	void setInput2(const DoubleID& i2){fprintf_s(mFile,"connectAttr \"");i2.write(mFile);fprintf_s(mFile,"\" \"%s.i2\";\n",mName.c_str());}
	/*the sum of its input value (= i1 + i2 )*/
	void setOutput(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*the first input value*/
	DoubleID getInput1(){char buffer[4096];sprintf_s (buffer, "%s.i1",mName.c_str());return (const char*)buffer;}
	/*the second input value*/
	DoubleID getInput2(){char buffer[4096];sprintf_s (buffer, "%s.i2",mName.c_str());return (const char*)buffer;}
	/*the sum of its input value (= i1 + i2 )*/
	DoubleID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	AddDoubleLinear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ADDDOUBLELINEAR_H__
