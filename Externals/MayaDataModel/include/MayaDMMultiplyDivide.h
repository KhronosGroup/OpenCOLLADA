/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MULTIPLYDIVIDE_H__
#define __MayaDM_MULTIPLYDIVIDE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The <b>Multiply Divide</b> utility node allows you to multiply
 or divide input attributes.  It has three parts --- two input
 attributes, an operator that you apply to the attributes, and
 an output attribute that holds the result of the operation.
 <p/>
 All the input and output attributes have x, y, and z components;
 that way you can use this node to multiply colors or other
 triple-value things.  If you just want to work with single values,
 then just use one of the x, y, or z channels.
 <p/><ul>
 <b>Note:</b> This node does not do proper vector mathematics,
 such as dot products and cross products.  To do those kind
 of calculations, use the Vector Product utility node.</ul>
 <p/>
 There are four settings for the operator;  Do nothing, Multiply,
 Divide, and Power.  They are explained below.
 <p/>
 Let's say you have set the operator to Multiply.  Then this
 node does the following calculations:
 <ul>
 outputX = input1X * input2X<br/>
 outputY = input1Y * input2Y<br/>
 outputZ = input1Z * input2Z
 </ul>
<p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class MultiplyDivide : public DependNode
{
public:
public:
	MultiplyDivide(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "multiplyDivide"){}
	virtual ~MultiplyDivide(){}
	/*
	<b>Operation</b> controls the operation performed by
	this node.  The settings are:
	<ul>
	<b>No operation:</b>  Output is set to equal Input 1.
	Input 2 is completely ignored.
	<p/><b>Multiply:</b> Output is set to equal Input 1
	times Input 2.
	<p/><b>Divide:</b> Output is set to equal Input 1
	divided by Input 2.
	<p/><b>Power:</b> Output is set to equal Input 1
	raised to the power of Input 2.
	</ul>
	<b>Tip:</b> To calculate the square root of Input 1,
	set Operation to Power, and set Input 2 to 0.5
	*/
	void setOperation(unsigned int op){if(op == 1) return; fprintf_s(mFile, "setAttr \".op\" %i;\n", op);}
	/*
	<b>Operation</b> controls the operation performed by
	this node.  The settings are:
	<ul>
	<b>No operation:</b>  Output is set to equal Input 1.
	Input 2 is completely ignored.
	<p/><b>Multiply:</b> Output is set to equal Input 1
	times Input 2.
	<p/><b>Divide:</b> Output is set to equal Input 1
	divided by Input 2.
	<p/><b>Power:</b> Output is set to equal Input 1
	raised to the power of Input 2.
	</ul>
	<b>Tip:</b> To calculate the square root of Input 1,
	set Operation to Power, and set Input 2 to 0.5
	*/
	void setOperation(const UnsignedintID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*<b>Input 1:</b> The first input value*/
	void setInput1(const float3& i1){if(i1 == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".i1\" -type \"float3\" ");i1.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Input 1:</b> The first input value*/
	void setInput1(const Float3ID& i1){fprintf_s(mFile,"connectAttr \"");i1.write(mFile);fprintf_s(mFile,"\" \"%s.i1\";\n",mName.c_str());}
	/*The x component of Input 1*/
	void setInput1X(float i1x){if(i1x == 0.0) return; fprintf_s(mFile, "setAttr \".i1.i1x\" %f;\n", i1x);}
	/*The x component of Input 1*/
	void setInput1X(const FloatID& i1x){fprintf_s(mFile,"connectAttr \"");i1x.write(mFile);fprintf_s(mFile,"\" \"%s.i1.i1x\";\n",mName.c_str());}
	/*The y component of Input 1*/
	void setInput1Y(float i1y){if(i1y == 0.0) return; fprintf_s(mFile, "setAttr \".i1.i1y\" %f;\n", i1y);}
	/*The y component of Input 1*/
	void setInput1Y(const FloatID& i1y){fprintf_s(mFile,"connectAttr \"");i1y.write(mFile);fprintf_s(mFile,"\" \"%s.i1.i1y\";\n",mName.c_str());}
	/*The z component of Input 1*/
	void setInput1Z(float i1z){if(i1z == 0.0) return; fprintf_s(mFile, "setAttr \".i1.i1z\" %f;\n", i1z);}
	/*The z component of Input 1*/
	void setInput1Z(const FloatID& i1z){fprintf_s(mFile,"connectAttr \"");i1z.write(mFile);fprintf_s(mFile,"\" \"%s.i1.i1z\";\n",mName.c_str());}
	/*<b>Input 2:</b>The second input value*/
	void setInput2(const float3& i2){if(i2 == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".i2\" -type \"float3\" ");i2.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Input 2:</b>The second input value*/
	void setInput2(const Float3ID& i2){fprintf_s(mFile,"connectAttr \"");i2.write(mFile);fprintf_s(mFile,"\" \"%s.i2\";\n",mName.c_str());}
	/*The x component of Input 2*/
	void setInput2X(float i2x){if(i2x == 0.0) return; fprintf_s(mFile, "setAttr \".i2.i2x\" %f;\n", i2x);}
	/*The x component of Input 2*/
	void setInput2X(const FloatID& i2x){fprintf_s(mFile,"connectAttr \"");i2x.write(mFile);fprintf_s(mFile,"\" \"%s.i2.i2x\";\n",mName.c_str());}
	/*The y component of Input 2*/
	void setInput2Y(float i2y){if(i2y == 0.0) return; fprintf_s(mFile, "setAttr \".i2.i2y\" %f;\n", i2y);}
	/*The y component of Input 2*/
	void setInput2Y(const FloatID& i2y){fprintf_s(mFile,"connectAttr \"");i2y.write(mFile);fprintf_s(mFile,"\" \"%s.i2.i2y\";\n",mName.c_str());}
	/*The z component of Input 2*/
	void setInput2Z(float i2z){if(i2z == 0.0) return; fprintf_s(mFile, "setAttr \".i2.i2z\" %f;\n", i2z);}
	/*The z component of Input 2*/
	void setInput2Z(const FloatID& i2z){fprintf_s(mFile,"connectAttr \"");i2z.write(mFile);fprintf_s(mFile,"\" \"%s.i2.i2z\";\n",mName.c_str());}
	/*<b>Output</b> is the values calculated by this node.*/
	void setOutput(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The X component of Output*/
	void setOutputX(const FloatID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*The Y component of Output*/
	void setOutputY(const FloatID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*The Z component of Output*/
	void setOutputZ(const FloatID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*
	<b>Operation</b> controls the operation performed by
	this node.  The settings are:
	<ul>
	<b>No operation:</b>  Output is set to equal Input 1.
	Input 2 is completely ignored.
	<p/><b>Multiply:</b> Output is set to equal Input 1
	times Input 2.
	<p/><b>Divide:</b> Output is set to equal Input 1
	divided by Input 2.
	<p/><b>Power:</b> Output is set to equal Input 1
	raised to the power of Input 2.
	</ul>
	<b>Tip:</b> To calculate the square root of Input 1,
	set Operation to Power, and set Input 2 to 0.5
	*/
	UnsignedintID getOperation(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*<b>Input 1:</b> The first input value*/
	Float3ID getInput1(){char buffer[4096];sprintf_s (buffer, "%s.i1",mName.c_str());return (const char*)buffer;}
	/*The x component of Input 1*/
	FloatID getInput1X(){char buffer[4096];sprintf_s (buffer, "%s.i1.i1x",mName.c_str());return (const char*)buffer;}
	/*The y component of Input 1*/
	FloatID getInput1Y(){char buffer[4096];sprintf_s (buffer, "%s.i1.i1y",mName.c_str());return (const char*)buffer;}
	/*The z component of Input 1*/
	FloatID getInput1Z(){char buffer[4096];sprintf_s (buffer, "%s.i1.i1z",mName.c_str());return (const char*)buffer;}
	/*<b>Input 2:</b>The second input value*/
	Float3ID getInput2(){char buffer[4096];sprintf_s (buffer, "%s.i2",mName.c_str());return (const char*)buffer;}
	/*The x component of Input 2*/
	FloatID getInput2X(){char buffer[4096];sprintf_s (buffer, "%s.i2.i2x",mName.c_str());return (const char*)buffer;}
	/*The y component of Input 2*/
	FloatID getInput2Y(){char buffer[4096];sprintf_s (buffer, "%s.i2.i2y",mName.c_str());return (const char*)buffer;}
	/*The z component of Input 2*/
	FloatID getInput2Z(){char buffer[4096];sprintf_s (buffer, "%s.i2.i2z",mName.c_str());return (const char*)buffer;}
	/*<b>Output</b> is the values calculated by this node.*/
	Float3ID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The X component of Output*/
	FloatID getOutputX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*The Y component of Output*/
	FloatID getOutputY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*The Z component of Output*/
	FloatID getOutputZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
protected:
	MultiplyDivide(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MULTIPLYDIVIDE_H__
