/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DOUBLESHADINGSWITCH_H__
#define __MayaDM_DOUBLESHADINGSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseShadingSwitch.h"
namespace MayaDM
{
/*
<b>Double Shading Switch</b> is a utility node that enables
  you to switch between different values based on which surface
  is being shaded.
  <p/>
        For example, say you have a complex shading network that is being
  used by many objects.  However, two of these objects need to have
  different UV coordintate values set in one of the texture placements.
  <p/>
        You could accomplish this by copying the entire shading network for
  each of these objects.  But if you do that, any changes made to
  the shading network later will have to be repeated for each of the
  copies.
 <p/>
  Instead of copying the network, just use one network with a
  Double Shading Switch node.  Connect the Output attribute of the Double
  Shading Switch to the uvCoord attribute of the texture.  Set the
  Default attribute of the Double Shading Switch to the value
  used by most shapes.  Then, for each object that needs a different
  value, specify the object and its particular value.
  <p/>
  Now, you can assign the same shader to all the objects, and the
  objects that need the different UV Coord values will get them
  automatically.
  <p/>
  <b>Note:</b> The Double Shading Switch only works on double-valued
  attributes.  If you need to switch single attributes (such as Intensity
  of Translucence), use a Single Shading Switch.  If you need to switch
  triple attributes, such as 3d coordinates, or colors, use a Triple
  Shading switch.
  <p/>
  In the table below, important attributes have their names listed
  in <b>bold</b> in the description column.
*/
class DoubleShadingSwitch : public BaseShadingSwitch
{
public:
	/*
	<b>Input</b> is a combination of two attributes, a double value
	and the name of a shape.  This is also a multiple attribute,
	so you can specify any number of these value/shape pairs.
	<p/>
	During rendering, the Output attribute is set depending on
	which object is being rendered.  When one of the objects in
	in this list are being rendered, then Output is set to its
	corresponding value.  When none of the objects in this list
	is being rendered, Output is set to equal Default.
	*/
	struct Input{
		float2 inDouble;
		void write(FILE* file) const
		{
			inDouble.write(file);
			fprintf_s(file, " ");
		}
	};
public:
	DoubleShadingSwitch(FILE* file,const std::string& name,const std::string& parent=""):BaseShadingSwitch(file, name, parent, "doubleShadingSwitch"){}
	virtual ~DoubleShadingSwitch(){}
	/*
	<b>Input</b> is a combination of two attributes, a double value
	and the name of a shape.  This is also a multiple attribute,
	so you can specify any number of these value/shape pairs.
	<p/>
	During rendering, the Output attribute is set depending on
	which object is being rendered.  When one of the objects in
	in this list are being rendered, then Output is set to its
	corresponding value.  When none of the objects in this list
	is being rendered, Output is set to equal Default.
	*/
	void setInput(size_t i_i,const Input& i){fprintf_s(mFile, "setAttr \".i[%i]\" ",i_i);i.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Input</b> is a combination of two attributes, a double value
	and the name of a shape.  This is also a multiple attribute,
	so you can specify any number of these value/shape pairs.
	<p/>
	During rendering, the Output attribute is set depending on
	which object is being rendered.  When one of the objects in
	in this list are being rendered, then Output is set to its
	corresponding value.  When none of the objects in this list
	is being rendered, Output is set to equal Default.
	*/
	void setInput(size_t i_i,const InputID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i]\";\n",mName.c_str(),i_i);}
	/*<b>InDouble</b> is the "Value" component of Input (see above).*/
	void setInDouble(size_t i_i,const float2& idl){fprintf_s(mFile, "setAttr \".i[%i].idl\" -type \"float2\" ",i_i);idl.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>InDouble</b> is the "Value" component of Input (see above).*/
	void setInDouble(size_t i_i,const Float2ID& idl){fprintf_s(mFile,"connectAttr \"");idl.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].idl\";\n",mName.c_str(),i_i);}
	/*The first component of.InDouble*/
	void setInComp1(size_t i_i,float ic1){if(ic1 == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].idl.ic1\" %f;\n", i_i,ic1);}
	/*The first component of.InDouble*/
	void setInComp1(size_t i_i,const FloatID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].idl.ic1\";\n",mName.c_str(),i_i);}
	/*The second component of InDouble*/
	void setInComp2(size_t i_i,float ic2){if(ic2 == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].idl.ic2\" %f;\n", i_i,ic2);}
	/*The second component of InDouble*/
	void setInComp2(size_t i_i,const FloatID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].idl.ic2\";\n",mName.c_str(),i_i);}
	/*<b>inShape</b> in the "Shape" component of Input (see above).*/
	void setInShape(size_t i_i,const MessageID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].is\";\n",mName.c_str(),i_i);}
	/*
	<b>Default</b> is the value used by this node when it is
	not rendering one of the nodes on the Input list..
	*/
	void setDefault(const float2& def){if(def == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".def\" -type \"float2\" ");def.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Default</b> is the value used by this node when it is
	not rendering one of the nodes on the Input list..
	*/
	void setDefault(const Float2ID& def){fprintf_s(mFile,"connectAttr \"");def.write(mFile);fprintf_s(mFile,"\" \"%s.def\";\n",mName.c_str());}
	/*The first component of Default*/
	void setDefComp1(float dc1){if(dc1 == 0.0) return; fprintf_s(mFile, "setAttr \".def.dc1\" %f;\n", dc1);}
	/*The first component of Default*/
	void setDefComp1(const FloatID& dc1){fprintf_s(mFile,"connectAttr \"");dc1.write(mFile);fprintf_s(mFile,"\" \"%s.def.dc1\";\n",mName.c_str());}
	/*The second component of Default*/
	void setDefComp2(float dc2){if(dc2 == 0.0) return; fprintf_s(mFile, "setAttr \".def.dc2\" %f;\n", dc2);}
	/*The second component of Default*/
	void setDefComp2(const FloatID& dc2){fprintf_s(mFile,"connectAttr \"");dc2.write(mFile);fprintf_s(mFile,"\" \"%s.def.dc2\";\n",mName.c_str());}
	/*
	<b>Output</b> is the Output value of the switch.  This
	value depends on what shape is being rendered.  When one of
	the objects in the Input
	list is being rendered, then Output is set to its
	corresponding value.  When none of the objects in the list
	is being rendered, Output is set to equal Default.
	*/
	void setOutput(const Float2ID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out\";\n",mName.c_str());}
	/*The first component of Output*/
	void setOutComp1(const FloatID& oc1){fprintf_s(mFile,"connectAttr \"");oc1.write(mFile);fprintf_s(mFile,"\" \"%s.out.oc1\";\n",mName.c_str());}
	/*The second component of Output*/
	void setOutComp2(const FloatID& oc2){fprintf_s(mFile,"connectAttr \"");oc2.write(mFile);fprintf_s(mFile,"\" \"%s.out.oc2\";\n",mName.c_str());}
	/*
	<b>Input</b> is a combination of two attributes, a double value
	and the name of a shape.  This is also a multiple attribute,
	so you can specify any number of these value/shape pairs.
	<p/>
	During rendering, the Output attribute is set depending on
	which object is being rendered.  When one of the objects in
	in this list are being rendered, then Output is set to its
	corresponding value.  When none of the objects in this list
	is being rendered, Output is set to equal Default.
	*/
	const InputID& getInput(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i]",mName.c_str(),i_i);return (const char*)buffer;}
	/*<b>InDouble</b> is the "Value" component of Input (see above).*/
	const Float2ID& getInDouble(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].idl",mName.c_str(),i_i);return (const char*)buffer;}
	/*The first component of.InDouble*/
	const FloatID& getInComp1(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].idl.ic1",mName.c_str(),i_i);return (const char*)buffer;}
	/*The second component of InDouble*/
	const FloatID& getInComp2(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].idl.ic2",mName.c_str(),i_i);return (const char*)buffer;}
	/*<b>inShape</b> in the "Shape" component of Input (see above).*/
	const MessageID& getInShape(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].is",mName.c_str(),i_i);return (const char*)buffer;}
	/*
	<b>Default</b> is the value used by this node when it is
	not rendering one of the nodes on the Input list..
	*/
	Float2ID getDefault(){char buffer[4096];sprintf_s (buffer, "%s.def",mName.c_str());return (const char*)buffer;}
	/*The first component of Default*/
	FloatID getDefComp1(){char buffer[4096];sprintf_s (buffer, "%s.def.dc1",mName.c_str());return (const char*)buffer;}
	/*The second component of Default*/
	FloatID getDefComp2(){char buffer[4096];sprintf_s (buffer, "%s.def.dc2",mName.c_str());return (const char*)buffer;}
	/*
	<b>Output</b> is the Output value of the switch.  This
	value depends on what shape is being rendered.  When one of
	the objects in the Input
	list is being rendered, then Output is set to its
	corresponding value.  When none of the objects in the list
	is being rendered, Output is set to equal Default.
	*/
	Float2ID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.out",mName.c_str());return (const char*)buffer;}
	/*The first component of Output*/
	FloatID getOutComp1(){char buffer[4096];sprintf_s (buffer, "%s.out.oc1",mName.c_str());return (const char*)buffer;}
	/*The second component of Output*/
	FloatID getOutComp2(){char buffer[4096];sprintf_s (buffer, "%s.out.oc2",mName.c_str());return (const char*)buffer;}
protected:
	DoubleShadingSwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseShadingSwitch(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DOUBLESHADINGSWITCH_H__
