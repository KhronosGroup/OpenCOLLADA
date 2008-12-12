/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VECTORPRODUCT_H__
#define __MayaDM_VECTORPRODUCT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The <b>Vector Product</b> utility node lets you multiply a vector
 by another vector in several different ways.  The Vector Product
 node has three parts; two input attributes, an operator that is
 applied to the two input attributes, and an output attribute for
 holding the result of the operation.
<p/>
 This node uses standard vector/matrix mathematics.  Say we have two
 input vectors, (a,b,c) and (d,e,f), and we are calculating the
 output vector (x, y, z).  The calculations are
 defined as follows:
 <ul>
 The <b>Dot Product</b>
 is useful for comparing the direction of two vectors.
 If you turn on "Normalize Output",  the Dot Product is actually
 the cosine of the angle between the two vectors.  A value of 1.0
 means the vectors point the same way.  A value of 0 means that
 they are at right angles to each other.  And a value of -1 means
 that the vectors point in opposite directions.
 <p/>Dot Product is defined as follows:
  <ul><pre>
  Dot Product = (a*d) + (b*e) + (c*f)
  </pre></ul>
  A dot product is a single value, so all three output values
  x, y and z will be set to the same thing.
 <p/>
 The <b>Cross Product</b> of two vectors gives you a new vector.  This
 new vector is guaranteed to be perpendicular (<i>i.e.</i> at
 right angles to) both of the input vectors.
 <p/>
 Cross Product is defined as follows:
 <ul><pre>
    x = (b*f)-(c*e)<br/>
    y = (c*d)-(a*f)<br/>
    z = (a*e)-(b*d)
 </pre></ul>
<p/>
 <b>Note:</b> If you just want to do simple component-by-component
 combinations of your vectors (<i>i.e.</i>, x = a*d, y=b*e, z=c*f)
 then you should use the Multiply Divide utility node instead
 of the Vector Product utility node.
<p/>
 The <b>Vector Matrix Product</b> is useful for taking a vector
 in one coordinate space and moving it to another.  For example,
 if you have a vector in camera coordinate space, you can multiply
 it by the Xform Matrix attribute of the camera.  That will give
 you a new vector in world coordinate space.
 <p/>
 Similarly, the <b>Point Matrix Product</b> is useful for taking
 a point in one coordinate space and moving it to another.  For
 example, if you have a point in camera coordinate space, you can multiply
 it by the Xform Matrix attribute of the camera.  That will give
 you a new point in world coordinate space.
 <p/>
 Given an input vector (a, b, c) and an input matrix:
 <ul>
 <pre>
 A B C D
 E F G H
 I J K L
 M N O P
 </pre></ul>
 <p/>
 Then Vector Matrix Product is defined as follows:
 <ul><pre>
 x = (a*A) + (b*B) + (c*C)
 y = (a*E) + (b*F) + (c*G)
 z = (a*I) + (b*J) + (c*K)
 </pre></ul>
 And the Point Matrix Product is defined as follows:
 <ul><pre>
 x = (a*A) + (b*B) + (c*C) + D
 y = (a*E) + (b*F) + (c*G) + H
 z = (a*I) + (b*J) + (c*K) + L
 </pre></ul>
</ul>
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class VectorProduct : public DependNode
{
public:
public:
	VectorProduct(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "vectorProduct"){}
	virtual ~VectorProduct(){}
	/*
	The operation to be performed on the inputs.  (See detailed
	descriptions at the top).  Values are:
	<p/><ul>
	<b>No operation:</b>  The value of Input1 is copied to
	the Output.  All other inputs are ignored.
	<p/>
	<b>Dot Product:</b>  Each of the components of Output is
	set to the dot product of Input 1 and Input 2.
	<p/>
	<b>Cross Product:</b>  Output is
	set to the cross product of Input 1 and Input 2.
	<p/>
	<b>Vector Matrix Product:</b>  Output is set to the
	vector-matrix product of Input 1 and Matrix.  Input 2
	is ignored.
	<p/>
	<b>Point Matrix Product:</b>  Output is set to the
	point-matrix product of Input 1 and Matrix.  Input 2
	is ignored.
	</ul>
	*/
	void setOperation(unsigned int op){if(op == 1) return; fprintf_s(mFile, "setAttr \".op\" %i;\n", op);}
	/*
	The operation to be performed on the inputs.  (See detailed
	descriptions at the top).  Values are:
	<p/><ul>
	<b>No operation:</b>  The value of Input1 is copied to
	the Output.  All other inputs are ignored.
	<p/>
	<b>Dot Product:</b>  Each of the components of Output is
	set to the dot product of Input 1 and Input 2.
	<p/>
	<b>Cross Product:</b>  Output is
	set to the cross product of Input 1 and Input 2.
	<p/>
	<b>Vector Matrix Product:</b>  Output is set to the
	vector-matrix product of Input 1 and Matrix.  Input 2
	is ignored.
	<p/>
	<b>Point Matrix Product:</b>  Output is set to the
	point-matrix product of Input 1 and Matrix.  Input 2
	is ignored.
	</ul>
	*/
	void setOperation(const UnsignedintID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*
	<b>Input 1</b> is the first vector input, used for
	all operations.
	*/
	void setInput1(const float3& i1){if(i1 == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".i1\" -type \"float3\" ");i1.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Input 1</b> is the first vector input, used for
	all operations.
	*/
	void setInput1(const Float3ID& i1){fprintf_s(mFile,"connectAttr \"");i1.write(mFile);fprintf_s(mFile,"\" \"%s.i1\";\n",mName.c_str());}
	/*The x component of Input 1*/
	void setInput1X(float i1x){if(i1x == 0.0) return; fprintf_s(mFile, "setAttr \".i1.i1x\" %f;\n", i1x);}
	/*The x component of Input 1*/
	void setInput1X(const FloatID& i1x){fprintf_s(mFile,"connectAttr \"");i1x.write(mFile);fprintf_s(mFile,"\" \"%s.i1.i1x\";\n",mName.c_str());}
	/*The y component of Input 1*/
	void setInput1Y(float i1y){if(i1y == 0.0) return; fprintf_s(mFile, "setAttr \".i1.i1y\" %f;\n", i1y);}
	/*The y component of Input 1*/
	void setInput1Y(const FloatID& i1y){fprintf_s(mFile,"connectAttr \"");i1y.write(mFile);fprintf_s(mFile,"\" \"%s.i1.i1y\";\n",mName.c_str());}
	/*The z component of input 1*/
	void setInput1Z(float i1z){if(i1z == 0.0) return; fprintf_s(mFile, "setAttr \".i1.i1z\" %f;\n", i1z);}
	/*The z component of input 1*/
	void setInput1Z(const FloatID& i1z){fprintf_s(mFile,"connectAttr \"");i1z.write(mFile);fprintf_s(mFile,"\" \"%s.i1.i1z\";\n",mName.c_str());}
	/*
	<b>Input 2</b> is the second vector input, used for
	the Dot Product and Cross Product operations only.
	*/
	void setInput2(const float3& i2){if(i2 == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".i2\" -type \"float3\" ");i2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Input 2</b> is the second vector input, used for
	the Dot Product and Cross Product operations only.
	*/
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
	/*
	<b>Matrix</b> is the matrix input, used for the
	Vector Matrix Product and Point Matrix Product
	operations only.
	<p/>
	This attribute is only connectable in the Connection
	Editor window.
	*/
	void setMatrix(const FltMatrixID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*
	<b>Normalize Output</b>.  If this is turned on, then
	this node will attempt to normalize the vector output.
	This means that the output vector will be re-sized to
	a length of 1, while maintaining the same direction.
	If the vector is of zero length, an error will be
	produced.
	<p/>
	For Dot Product (which does not produce a vector), turning
	on Normalize output will guarantee the output values lie
	between -1 and 1.  Effectively, the output will be the
	cosine of the angle between the input vectors.
	*/
	void setNormalizeOutput(bool no){if(no == false) return; fprintf_s(mFile, "setAttr \".no\" %i;\n", no);}
	/*
	<b>Normalize Output</b>.  If this is turned on, then
	this node will attempt to normalize the vector output.
	This means that the output vector will be re-sized to
	a length of 1, while maintaining the same direction.
	If the vector is of zero length, an error will be
	produced.
	<p/>
	For Dot Product (which does not produce a vector), turning
	on Normalize output will guarantee the output values lie
	between -1 and 1.  Effectively, the output will be the
	cosine of the angle between the input vectors.
	*/
	void setNormalizeOutput(const BoolID& no){fprintf_s(mFile,"connectAttr \"");no.write(mFile);fprintf_s(mFile,"\" \"%s.no\";\n",mName.c_str());}
	/*
	<b>Output</b> is the result of the calculation performed
	by this node.
	*/
	void setOutput(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The X component of Output*/
	void setOutputX(const FloatID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*The Y component of Output*/
	void setOutputY(const FloatID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*The Z component of Output*/
	void setOutputZ(const FloatID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*
	The operation to be performed on the inputs.  (See detailed
	descriptions at the top).  Values are:
	<p/><ul>
	<b>No operation:</b>  The value of Input1 is copied to
	the Output.  All other inputs are ignored.
	<p/>
	<b>Dot Product:</b>  Each of the components of Output is
	set to the dot product of Input 1 and Input 2.
	<p/>
	<b>Cross Product:</b>  Output is
	set to the cross product of Input 1 and Input 2.
	<p/>
	<b>Vector Matrix Product:</b>  Output is set to the
	vector-matrix product of Input 1 and Matrix.  Input 2
	is ignored.
	<p/>
	<b>Point Matrix Product:</b>  Output is set to the
	point-matrix product of Input 1 and Matrix.  Input 2
	is ignored.
	</ul>
	*/
	UnsignedintID getOperation(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*
	<b>Input 1</b> is the first vector input, used for
	all operations.
	*/
	Float3ID getInput1(){char buffer[4096];sprintf_s (buffer, "%s.i1",mName.c_str());return (const char*)buffer;}
	/*The x component of Input 1*/
	FloatID getInput1X(){char buffer[4096];sprintf_s (buffer, "%s.i1.i1x",mName.c_str());return (const char*)buffer;}
	/*The y component of Input 1*/
	FloatID getInput1Y(){char buffer[4096];sprintf_s (buffer, "%s.i1.i1y",mName.c_str());return (const char*)buffer;}
	/*The z component of input 1*/
	FloatID getInput1Z(){char buffer[4096];sprintf_s (buffer, "%s.i1.i1z",mName.c_str());return (const char*)buffer;}
	/*
	<b>Input 2</b> is the second vector input, used for
	the Dot Product and Cross Product operations only.
	*/
	Float3ID getInput2(){char buffer[4096];sprintf_s (buffer, "%s.i2",mName.c_str());return (const char*)buffer;}
	/*The x component of Input 2*/
	FloatID getInput2X(){char buffer[4096];sprintf_s (buffer, "%s.i2.i2x",mName.c_str());return (const char*)buffer;}
	/*The y component of Input 2*/
	FloatID getInput2Y(){char buffer[4096];sprintf_s (buffer, "%s.i2.i2y",mName.c_str());return (const char*)buffer;}
	/*The z component of Input 2*/
	FloatID getInput2Z(){char buffer[4096];sprintf_s (buffer, "%s.i2.i2z",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matrix</b> is the matrix input, used for the
	Vector Matrix Product and Point Matrix Product
	operations only.
	<p/>
	This attribute is only connectable in the Connection
	Editor window.
	*/
	FltMatrixID getMatrix(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*
	<b>Normalize Output</b>.  If this is turned on, then
	this node will attempt to normalize the vector output.
	This means that the output vector will be re-sized to
	a length of 1, while maintaining the same direction.
	If the vector is of zero length, an error will be
	produced.
	<p/>
	For Dot Product (which does not produce a vector), turning
	on Normalize output will guarantee the output values lie
	between -1 and 1.  Effectively, the output will be the
	cosine of the angle between the input vectors.
	*/
	BoolID getNormalizeOutput(){char buffer[4096];sprintf_s (buffer, "%s.no",mName.c_str());return (const char*)buffer;}
	/*
	<b>Output</b> is the result of the calculation performed
	by this node.
	*/
	Float3ID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The X component of Output*/
	FloatID getOutputX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*The Y component of Output*/
	FloatID getOutputY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*The Z component of Output*/
	FloatID getOutputZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
protected:
	VectorProduct(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_VECTORPRODUCT_H__
