/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNITTOTIMECONVERSION_H__
#define __MayaDM_UNITTOTIMECONVERSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    This is the unit to time conversion node. It gets inserted between two
    nodes when a connection is made between a numeric attribute and a
    time attribute.

    For more information about the purpose of conversion nodes,
    see the documentation for the unitConversion node.
</pre></p>
*/
class UnitToTimeConversion : public DependNode
{
public:
public:
	UnitToTimeConversion(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "unitToTimeConversion"){}
	virtual ~UnitToTimeConversion(){}
	/*Value to be converted*/
	void setInput(double i){if(i == 0.0) return; fprintf_s(mFile, "setAttr \".i\" %f;\n", i);}
	/*Value to be converted*/
	void setInput(const DoubleID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Evaluated time value of the numeric input*/
	void setOutput(const TimeID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*
	The multiplier that will convert the input double attribute
	to the output time attribute preserving the 1=1 relationship
	between the two unit types from the time of connection.
	*/
	void setConversionFactor(double cf){if(cf == 1.0) return; fprintf_s(mFile, "setAttr \".cf\" %f;\n", cf);}
	/*Value to be converted*/
	DoubleID getInput(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Evaluated time value of the numeric input*/
	TimeID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	UnitToTimeConversion(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_UNITTOTIMECONVERSION_H__
