/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TIMEFUNCTION_H__
#define __MayaDM_TIMEFUNCTION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The timeFunction node was designed with the goal of allowing constraints and expressions
 to be blended using Trax. It converts a numeric input to a function data type.
 <p/>
*/
class TimeFunction : public DependNode
{
public:
public:
	TimeFunction(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "timeFunction"){}
	virtual ~TimeFunction(){}
	/*Input data*/
	void setInput(double i){if(i == 0.0) return; fprintf_s(mFile, "setAttr \".i\" %f;\n", i);}
	/*Input data*/
	void setInput(const DoubleID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Function attribute to get the value of the input at a time*/
	void setOutput(const FunctionID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Input data*/
	DoubleID getInput(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Function attribute to get the value of the input at a time*/
	FunctionID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	TimeFunction(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TIMEFUNCTION_H__
