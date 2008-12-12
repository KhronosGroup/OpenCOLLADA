/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TIMETOUNITCONVERSION_H__
#define __MayaDM_TIMETOUNITCONVERSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This is the time to unit conversion node. It gets inserted between two
        nodes when a connection is made between a time attribute and another
        numeric attribute.<p/>

        For more information about the purpose of conversion nodes,
        see the documentation for the unitConversion node.
*/
class TimeToUnitConversion : public DependNode
{
public:
public:
	TimeToUnitConversion(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "timeToUnitConversion"){}
	virtual ~TimeToUnitConversion(){}
	/*Time to be converted*/
	void setInput(const TimeID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Evaluated numeric value of the time input*/
	void setOutput(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*
	The multiplier that will convert the time attribute to the
	output attribute preserving the 1=1 relationship between the two unit
	types from the time of connection.
	*/
	void setConversionFactor(double cf){if(cf == 1.0) return; fprintf_s(mFile, "setAttr \".cf\" %f;\n", cf);}
	/*Time to be converted*/
	TimeID getInput(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Evaluated numeric value of the time input*/
	DoubleID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	TimeToUnitConversion(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TIMETOUNITCONVERSION_H__
