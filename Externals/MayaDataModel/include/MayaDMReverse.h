/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REVERSE_H__
#define __MayaDM_REVERSE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The <b>Reverse</b> node is a simple utility node, used to reverse
 node effects or colors. The output is simply 1 minus the input.
*/
class Reverse : public DependNode
{
public:
public:
	Reverse(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "reverse"){}
	virtual ~Reverse(){}
	/*<b>Input</b> is the input value, that will be reversed.*/
	void setInput(const float3& i){if(i == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".i\" -type \"float3\" ");i.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Input</b> is the input value, that will be reversed.*/
	void setInput(const Float3ID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*The x component of input*/
	void setInputX(float ix){if(ix == 0.0) return; fprintf_s(mFile, "setAttr \".i.ix\" %f;\n", ix);}
	/*The x component of input*/
	void setInputX(const FloatID& ix){fprintf_s(mFile,"connectAttr \"");ix.write(mFile);fprintf_s(mFile,"\" \"%s.i.ix\";\n",mName.c_str());}
	/*The y component of input*/
	void setInputY(float iy){if(iy == 0.0) return; fprintf_s(mFile, "setAttr \".i.iy\" %f;\n", iy);}
	/*The y component of input*/
	void setInputY(const FloatID& iy){fprintf_s(mFile,"connectAttr \"");iy.write(mFile);fprintf_s(mFile,"\" \"%s.i.iy\";\n",mName.c_str());}
	/*The z component of input*/
	void setInputZ(float iz){if(iz == 0.0) return; fprintf_s(mFile, "setAttr \".i.iz\" %f;\n", iz);}
	/*The z component of input*/
	void setInputZ(const FloatID& iz){fprintf_s(mFile,"connectAttr \"");iz.write(mFile);fprintf_s(mFile,"\" \"%s.i.iz\";\n",mName.c_str());}
	/*<b>Output</b> is set to be 1.0 - input.*/
	void setOutput(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The X component of the output value*/
	void setOutputX(const FloatID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*The Y component of the output value*/
	void setOutputY(const FloatID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*The Z component of the output value*/
	void setOutputZ(const FloatID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*<b>Input</b> is the input value, that will be reversed.*/
	Float3ID getInput(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*The x component of input*/
	FloatID getInputX(){char buffer[4096];sprintf_s (buffer, "%s.i.ix",mName.c_str());return (const char*)buffer;}
	/*The y component of input*/
	FloatID getInputY(){char buffer[4096];sprintf_s (buffer, "%s.i.iy",mName.c_str());return (const char*)buffer;}
	/*The z component of input*/
	FloatID getInputZ(){char buffer[4096];sprintf_s (buffer, "%s.i.iz",mName.c_str());return (const char*)buffer;}
	/*<b>Output</b> is set to be 1.0 - input.*/
	Float3ID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The X component of the output value*/
	FloatID getOutputX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*The Y component of the output value*/
	FloatID getOutputY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the output value*/
	FloatID getOutputZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
protected:
	Reverse(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REVERSE_H__
