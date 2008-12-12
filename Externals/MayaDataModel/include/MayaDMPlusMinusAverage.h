/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PLUSMINUSAVERAGE_H__
#define __MayaDM_PLUSMINUSAVERAGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The <b>Plus Minus Average</b> utility node allows you find the sum,
 difference or average of a set of input attributes.
 It has three parts --- two or more input
 attributes, an operator that you apply to the attributes, and
 an output attribute that holds the result of the operation.
<p/>
 This node actually has different input attributes for use
 for different kinds of data.  For simple numbers, you use
 the Input1D attribute and get the result from Output1D.  For
 2d attributes, such as UV coordinates, you use the Input2D
 attribute and get the result from Output2D.  For 3d attributes,
 like vectors or colors or 3d coordinates, you use the Input3D
 attribute and get the result from the Output3D attribute.
<p/>
 Each of these input attributes (Input1D, Input2D, and Input3D) are
 special, in that they each hold a list of values, rather than
 just one value.  Each of the elements of the list is assigned
 its own number.  The first connection is assigned
 a 0, then next 1, and so on.
 <p/>
 There are four settings for the operator;  No operation, Sum,
 Subtract, and Average.  They are explained below.
 <p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class PlusMinusAverage : public DependNode
{
public:
public:
	PlusMinusAverage(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "plusMinusAverage"){}
	virtual ~PlusMinusAverage(){}
	/*
	<b>Operation</b> controls the mathematical operation done
	by this node.  It has four possible values:
	<ul><p/>
	<b>No operation:</b> The first input is copied to the
	output.  All other inputs are ignored.
	<p/>
	<b>Sum</b>: All of the inputs are added together, and
	the output is set to their sum.
	<p/>
	<b>Subtract:</b> The output is set to the first input, minus
	all the other inputs.
	<p/>
	<b>Average:</b> The output is set to the sum of all the
	inputs, divided by the number of inputs.
	</ul>
	*/
	void setOperation(unsigned int op){if(op == 1) return; fprintf_s(mFile, "setAttr \".op\" %i;\n", op);}
	/*
	<b>Operation</b> controls the mathematical operation done
	by this node.  It has four possible values:
	<ul><p/>
	<b>No operation:</b> The first input is copied to the
	output.  All other inputs are ignored.
	<p/>
	<b>Sum</b>: All of the inputs are added together, and
	the output is set to their sum.
	<p/>
	<b>Subtract:</b> The output is set to the first input, minus
	all the other inputs.
	<p/>
	<b>Average:</b> The output is set to the sum of all the
	inputs, divided by the number of inputs.
	</ul>
	*/
	void setOperation(const UnsignedintID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*
	<b>Input1D</b> is the list of input values.  Use this
	particular list to add, subtract, or average simple
	numerical values.  The results of operations on this
	list will be placed in Output1D.
	*/
	void setInput1D(size_t i1_i,float i1){if(i1 == 0.0) return; fprintf_s(mFile, "setAttr \".i1[%i]\" %f;\n", i1_i,i1);}
	/*
	<b>Input2D</b> is the list of 2d input values.  Use this
	particular list to add, subtract, or average 2d values,
	such as UV coordinates.  The results of operations on this
	list will be placed in Output2D.
	*/
	void setInput2D(size_t i2_i,const float2& i2){if(i2 == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".i2[%i]\" -type \"float2\" ",i2_i);i2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Input2D</b> is the list of 2d input values.  Use this
	particular list to add, subtract, or average 2d values,
	such as UV coordinates.  The results of operations on this
	list will be placed in Output2D.
	*/
	void setInput2D(size_t i2_start,size_t i2_end,float* i2){fprintf_s(mFile,"setAttr \".i2[%i:%i]\" ", i2_start,i2_end);size_t size = (i2_end-i2_start)*2+2;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",i2[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*The x component of input2d*/
	void setInput2Dx(size_t i2_i,float i2x){if(i2x == 0.0) return; fprintf_s(mFile, "setAttr \".i2[%i].i2x\" %f;\n", i2_i,i2x);}
	/*The y component of input2d*/
	void setInput2Dy(size_t i2_i,float i2y){if(i2y == 0.0) return; fprintf_s(mFile, "setAttr \".i2[%i].i2y\" %f;\n", i2_i,i2y);}
	/*
	<b>Input3D</b> is the list of 3d input values.  Use this
	particular list to add, subtract, or average 3d values,
	such as XYZ coordinates or colors.  The results of operations on this
	list will be placed in Output3D.
	*/
	void setInput3D(size_t i3_i,const float3& i3){if(i3 == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".i3[%i]\" -type \"float3\" ",i3_i);i3.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Input3D</b> is the list of 3d input values.  Use this
	particular list to add, subtract, or average 3d values,
	such as XYZ coordinates or colors.  The results of operations on this
	list will be placed in Output3D.
	*/
	void setInput3D(size_t i3_start,size_t i3_end,float* i3){fprintf_s(mFile,"setAttr \".i3[%i:%i]\" ", i3_start,i3_end);size_t size = (i3_end-i3_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",i3[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*The x component of input3d*/
	void setInput3Dx(size_t i3_i,float i3x){if(i3x == 0.0) return; fprintf_s(mFile, "setAttr \".i3[%i].i3x\" %f;\n", i3_i,i3x);}
	/*The y component of input3d*/
	void setInput3Dy(size_t i3_i,float i3y){if(i3y == 0.0) return; fprintf_s(mFile, "setAttr \".i3[%i].i3y\" %f;\n", i3_i,i3y);}
	/*The z component of input3d*/
	void setInput3Dz(size_t i3_i,float i3z){if(i3z == 0.0) return; fprintf_s(mFile, "setAttr \".i3[%i].i3z\" %f;\n", i3_i,i3z);}
	/*
	<b>Output1D</b> holds the result of calculations performed
	on the Input1D list.
	*/
	void setOutput1D(const FloatID& o1){fprintf_s(mFile,"connectAttr \"");o1.write(mFile);fprintf_s(mFile,"\" \"%s.o1\";\n",mName.c_str());}
	/*
	<b>Output2D</b> holds the result of calculations performed
	on the Input2D list.
	*/
	void setOutput2D(const Float2ID& o2){fprintf_s(mFile,"connectAttr \"");o2.write(mFile);fprintf_s(mFile,"\" \"%s.o2\";\n",mName.c_str());}
	/*The X component of the output 2D value*/
	void setOutput2Dx(const FloatID& o2x){fprintf_s(mFile,"connectAttr \"");o2x.write(mFile);fprintf_s(mFile,"\" \"%s.o2.o2x\";\n",mName.c_str());}
	/*The Y component of the output 2D value*/
	void setOutput2Dy(const FloatID& o2y){fprintf_s(mFile,"connectAttr \"");o2y.write(mFile);fprintf_s(mFile,"\" \"%s.o2.o2y\";\n",mName.c_str());}
	/*
	<b>Output3D</b> holds the result of calculations performed
	on the Input3D list.
	*/
	void setOutput3D(const Float3ID& o3){fprintf_s(mFile,"connectAttr \"");o3.write(mFile);fprintf_s(mFile,"\" \"%s.o3\";\n",mName.c_str());}
	/*The X component of the output 3D value*/
	void setOutput3Dx(const FloatID& o3x){fprintf_s(mFile,"connectAttr \"");o3x.write(mFile);fprintf_s(mFile,"\" \"%s.o3.o3x\";\n",mName.c_str());}
	/*The Y component of the output 3D value*/
	void setOutput3Dy(const FloatID& o3y){fprintf_s(mFile,"connectAttr \"");o3y.write(mFile);fprintf_s(mFile,"\" \"%s.o3.o3y\";\n",mName.c_str());}
	/*The Z component of the output 3D value*/
	void setOutput3Dz(const FloatID& o3z){fprintf_s(mFile,"connectAttr \"");o3z.write(mFile);fprintf_s(mFile,"\" \"%s.o3.o3z\";\n",mName.c_str());}
	/*
	<b>Operation</b> controls the mathematical operation done
	by this node.  It has four possible values:
	<ul><p/>
	<b>No operation:</b> The first input is copied to the
	output.  All other inputs are ignored.
	<p/>
	<b>Sum</b>: All of the inputs are added together, and
	the output is set to their sum.
	<p/>
	<b>Subtract:</b> The output is set to the first input, minus
	all the other inputs.
	<p/>
	<b>Average:</b> The output is set to the sum of all the
	inputs, divided by the number of inputs.
	</ul>
	*/
	UnsignedintID getOperation(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*
	<b>Output1D</b> holds the result of calculations performed
	on the Input1D list.
	*/
	FloatID getOutput1D(){char buffer[4096];sprintf_s (buffer, "%s.o1",mName.c_str());return (const char*)buffer;}
	/*
	<b>Output2D</b> holds the result of calculations performed
	on the Input2D list.
	*/
	Float2ID getOutput2D(){char buffer[4096];sprintf_s (buffer, "%s.o2",mName.c_str());return (const char*)buffer;}
	/*The X component of the output 2D value*/
	FloatID getOutput2Dx(){char buffer[4096];sprintf_s (buffer, "%s.o2.o2x",mName.c_str());return (const char*)buffer;}
	/*The Y component of the output 2D value*/
	FloatID getOutput2Dy(){char buffer[4096];sprintf_s (buffer, "%s.o2.o2y",mName.c_str());return (const char*)buffer;}
	/*
	<b>Output3D</b> holds the result of calculations performed
	on the Input3D list.
	*/
	Float3ID getOutput3D(){char buffer[4096];sprintf_s (buffer, "%s.o3",mName.c_str());return (const char*)buffer;}
	/*The X component of the output 3D value*/
	FloatID getOutput3Dx(){char buffer[4096];sprintf_s (buffer, "%s.o3.o3x",mName.c_str());return (const char*)buffer;}
	/*The Y component of the output 3D value*/
	FloatID getOutput3Dy(){char buffer[4096];sprintf_s (buffer, "%s.o3.o3y",mName.c_str());return (const char*)buffer;}
	/*The Z component of the output 3D value*/
	FloatID getOutput3Dz(){char buffer[4096];sprintf_s (buffer, "%s.o3.o3z",mName.c_str());return (const char*)buffer;}
protected:
	PlusMinusAverage(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PLUSMINUSAVERAGE_H__
