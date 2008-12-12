/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNITCONVERSION_H__
#define __MayaDM_UNITCONVERSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>        This is the unit conversion node. It gets inserted between two
        nodes when a connection is made between numeric attributes that
        are of different unit types. The purpose of the unit conversion
        node is to ensure that "1" in the unit of the attribute at the
        source end of the connection is equivalent to "1" in the unit of
        the attribute at the destination end of the connection, in the
        current user units at the time of connection.

        For example, if a connection is made between transform1.translateX
        and transform2.rotateX, and the current user units are centimeters
        for linear, and degrees for angle, then when transform1.translateX
        is 1 cm, transform2.rotateX is 1 degree. If the linear units are then
        changed to meters, then when transform1.translateX is set to
        1 (i.e. 100 cm), transform2.rotateX will have the value 100 degrees.
</pre></p>
*/
class UnitConversion : public DependNode
{
public:
public:
	UnitConversion(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "unitConversion"){}
	virtual ~UnitConversion(){}
	/*Number or list of numbers to be converted*/
	void setInput(const GenericID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Number or list of numbers after unit conversion*/
	void setOutput(const GenericID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*
	The multiplier that will convert the input attribute(s) to the
	output attribute(s) preserving the 1=1 relationship between the two
	unit types from the time of connection.
	*/
	void setConversionFactor(double cf){if(cf == 1.0) return; fprintf_s(mFile, "setAttr \".cf\" %f;\n", cf);}
	/*Number or list of numbers to be converted*/
	GenericID getInput(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Number or list of numbers after unit conversion*/
	GenericID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	UnitConversion(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_UNITCONVERSION_H__
