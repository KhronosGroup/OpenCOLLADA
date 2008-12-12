/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRIPLESHADINGSWITCH_H__
#define __MayaDM_TRIPLESHADINGSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseShadingSwitch.h"
namespace MayaDM
{
/*
<b>Triple Shading Switch</b> is a utility node that enables
  you to switch between different values based on which surface
  is being shaded.
  <p/>
        For example, say you have a complex shading network that is being
  used by many objects.  However, two of these objects need to use
  different colors in one of the textures.
  <p/>
        You could accomplish this by copying the entire shading network for
  each of these objects.  But if you do that, any changes made to
  the shading network later will have to be repeated for each of the
  copies.
 <p/>
  Instead of copying the network, just use one network with a
  Triple Shading Switch node.  Connect the Output attribute of the Triple
  Shading Switch to the Color attribute of the texture.  Set the
  Default attribute of the Triple Shading Switch to the color value
  used by most shapes.  Then, for each object that needs a different
  color, specify the object and its particular value.
  <p/>
  Now, you can assign the same shader to all the objects, and the
  objects that need the different color values will get them
  automatically.
  <p/>
  <b>Note:</b> The Triple Shading Switch only works on triple-valued
  attributes, such as colors or xyz coordinates.  If you need to switch
  single attributes (such as Intensity
  of Translucence), use a Single Shading Switch.  If you need to switch
  double attributes, such as UV coordinates, use a Double
  Shading switch.
  <p/>
  In the table below, important attributes have their names listed
  in <b>bold</b> in the description column.
*/
class TripleShadingSwitch : public BaseShadingSwitch
{
public:
	/*
	<b>Input</b> is a combination of two attributes, a triple value
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
		float3 inTriple;
		void write(FILE* file) const
		{
			inTriple.write(file);
			fprintf_s(file, " ");
		}
	};
public:
	TripleShadingSwitch(FILE* file,const std::string& name,const std::string& parent=""):BaseShadingSwitch(file, name, parent, "tripleShadingSwitch"){}
	virtual ~TripleShadingSwitch(){}
	/*
	<b>Input</b> is a combination of two attributes, a triple value
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
	<b>Input</b> is a combination of two attributes, a triple value
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
	/*<b>InTriple</b> is the "Value" component of Input (see above).*/
	void setInTriple(size_t i_i,const float3& it){fprintf_s(mFile, "setAttr \".i[%i].it\" -type \"float3\" ",i_i);it.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>InTriple</b> is the "Value" component of Input (see above).*/
	void setInTriple(size_t i_i,const Float3ID& it){fprintf_s(mFile,"connectAttr \"");it.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].it\";\n",mName.c_str(),i_i);}
	/*The first component of InTriple*/
	void setInComp1(size_t i_i,float ic1){if(ic1 == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].it.ic1\" %f;\n", i_i,ic1);}
	/*The first component of InTriple*/
	void setInComp1(size_t i_i,const FloatID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].it.ic1\";\n",mName.c_str(),i_i);}
	/*The second component of InTriple*/
	void setInComp2(size_t i_i,float ic2){if(ic2 == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].it.ic2\" %f;\n", i_i,ic2);}
	/*The second component of InTriple*/
	void setInComp2(size_t i_i,const FloatID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].it.ic2\";\n",mName.c_str(),i_i);}
	/*The third component of InTriple*/
	void setInComp3(size_t i_i,float ic3){if(ic3 == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].it.ic3\" %f;\n", i_i,ic3);}
	/*The third component of InTriple*/
	void setInComp3(size_t i_i,const FloatID& ic3){fprintf_s(mFile,"connectAttr \"");ic3.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].it.ic3\";\n",mName.c_str(),i_i);}
	/*<b>inShape</b> in the "Shape" component of Input (see above).*/
	void setInShape(size_t i_i,const MessageID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].is\";\n",mName.c_str(),i_i);}
	/*
	<b>Default</b> is the value used by this node when it is
	not rendering one of the nodes on the Input list..
	*/
	void setDefault(const float3& def){if(def == float3(0.8, 0.8, 0.8)) return; fprintf_s(mFile, "setAttr \".def\" -type \"float3\" ");def.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Default</b> is the value used by this node when it is
	not rendering one of the nodes on the Input list..
	*/
	void setDefault(const Float3ID& def){fprintf_s(mFile,"connectAttr \"");def.write(mFile);fprintf_s(mFile,"\" \"%s.def\";\n",mName.c_str());}
	/*The first component of Default*/
	void setDefComp1(float dc1){if(dc1 == 0.0) return; fprintf_s(mFile, "setAttr \".def.dc1\" %f;\n", dc1);}
	/*The first component of Default*/
	void setDefComp1(const FloatID& dc1){fprintf_s(mFile,"connectAttr \"");dc1.write(mFile);fprintf_s(mFile,"\" \"%s.def.dc1\";\n",mName.c_str());}
	/*The second component of Default*/
	void setDefComp2(float dc2){if(dc2 == 0.0) return; fprintf_s(mFile, "setAttr \".def.dc2\" %f;\n", dc2);}
	/*The second component of Default*/
	void setDefComp2(const FloatID& dc2){fprintf_s(mFile,"connectAttr \"");dc2.write(mFile);fprintf_s(mFile,"\" \"%s.def.dc2\";\n",mName.c_str());}
	/*The third component of Default*/
	void setDefComp3(float dc3){if(dc3 == 0.0) return; fprintf_s(mFile, "setAttr \".def.dc3\" %f;\n", dc3);}
	/*The third component of Default*/
	void setDefComp3(const FloatID& dc3){fprintf_s(mFile,"connectAttr \"");dc3.write(mFile);fprintf_s(mFile,"\" \"%s.def.dc3\";\n",mName.c_str());}
	/*
	<b>Output</b> is the Output value of the switch.  This
	value depends on what shape is being rendered.  When one of
	the objects in the Input
	list is being rendered, then Output is set to its
	corresponding value.  When none of the objects in the list
	is being rendered, Output is set to equal Default.
	*/
	void setOutput(const Float3ID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out\";\n",mName.c_str());}
	/*The first component of Output*/
	void setOutComp1(const FloatID& oc1){fprintf_s(mFile,"connectAttr \"");oc1.write(mFile);fprintf_s(mFile,"\" \"%s.out.oc1\";\n",mName.c_str());}
	/*The second component of Output*/
	void setOutComp2(const FloatID& oc2){fprintf_s(mFile,"connectAttr \"");oc2.write(mFile);fprintf_s(mFile,"\" \"%s.out.oc2\";\n",mName.c_str());}
	/*The third component of Output*/
	void setOutComp3(const FloatID& oc3){fprintf_s(mFile,"connectAttr \"");oc3.write(mFile);fprintf_s(mFile,"\" \"%s.out.oc3\";\n",mName.c_str());}
	/*
	<b>Input</b> is a combination of two attributes, a triple value
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
	/*<b>InTriple</b> is the "Value" component of Input (see above).*/
	const Float3ID& getInTriple(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].it",mName.c_str(),i_i);return (const char*)buffer;}
	/*The first component of InTriple*/
	const FloatID& getInComp1(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].it.ic1",mName.c_str(),i_i);return (const char*)buffer;}
	/*The second component of InTriple*/
	const FloatID& getInComp2(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].it.ic2",mName.c_str(),i_i);return (const char*)buffer;}
	/*The third component of InTriple*/
	const FloatID& getInComp3(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].it.ic3",mName.c_str(),i_i);return (const char*)buffer;}
	/*<b>inShape</b> in the "Shape" component of Input (see above).*/
	const MessageID& getInShape(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].is",mName.c_str(),i_i);return (const char*)buffer;}
	/*
	<b>Default</b> is the value used by this node when it is
	not rendering one of the nodes on the Input list..
	*/
	Float3ID getDefault(){char buffer[4096];sprintf_s (buffer, "%s.def",mName.c_str());return (const char*)buffer;}
	/*The first component of Default*/
	FloatID getDefComp1(){char buffer[4096];sprintf_s (buffer, "%s.def.dc1",mName.c_str());return (const char*)buffer;}
	/*The second component of Default*/
	FloatID getDefComp2(){char buffer[4096];sprintf_s (buffer, "%s.def.dc2",mName.c_str());return (const char*)buffer;}
	/*The third component of Default*/
	FloatID getDefComp3(){char buffer[4096];sprintf_s (buffer, "%s.def.dc3",mName.c_str());return (const char*)buffer;}
	/*
	<b>Output</b> is the Output value of the switch.  This
	value depends on what shape is being rendered.  When one of
	the objects in the Input
	list is being rendered, then Output is set to its
	corresponding value.  When none of the objects in the list
	is being rendered, Output is set to equal Default.
	*/
	Float3ID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.out",mName.c_str());return (const char*)buffer;}
	/*The first component of Output*/
	FloatID getOutComp1(){char buffer[4096];sprintf_s (buffer, "%s.out.oc1",mName.c_str());return (const char*)buffer;}
	/*The second component of Output*/
	FloatID getOutComp2(){char buffer[4096];sprintf_s (buffer, "%s.out.oc2",mName.c_str());return (const char*)buffer;}
	/*The third component of Output*/
	FloatID getOutComp3(){char buffer[4096];sprintf_s (buffer, "%s.out.oc3",mName.c_str());return (const char*)buffer;}
protected:
	TripleShadingSwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseShadingSwitch(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TRIPLESHADINGSWITCH_H__
