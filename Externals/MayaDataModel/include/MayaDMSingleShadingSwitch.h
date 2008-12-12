/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SINGLESHADINGSWITCH_H__
#define __MayaDM_SINGLESHADINGSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseShadingSwitch.h"
namespace MayaDM
{
/*
<b>Single Shading Switch</b> is a utility node that enables
  you to switch between different values based on which surface
  is being shaded.
  <p/>
        For example, say you have a complex shading network that is being
  used by many objects.  However, two of these objects need to have
  different Diffusion value.
  <p/>
        You could accomplish this by copying the entire shading network for
  each of these objects.  But if you do that, any changes made to
  the shading network later will have to be repeated for each of the
  copies.
 <p/>
  Instead of copying the network, just use one network with a
  Single Shading Switch node.  Connect the Output attribute of the Single
  Shading Switch to the Diffusion attribute of the shader.  Set the
  Default attribute of the Single Shading Switch to the value
  used by most shapes.  Then, for each object that needs a different
  value, specify the object and its particular value.
  <p/>
  Now, you can assign the same shader to all the objects, and the
  objects that need the different diffusion values will get them
  automatically.
  <p/>
  <b>Note:</b> The Single Shading Switch only works on single-valued
  attributes.  If you need to switch double attributes, such as UV
  coordinates, use a Double Shading Switch.  If you need to switch
  triple attributes, such as 3d coordinates, or colors, use a Triple
  Shading switch.
  <p/>
  In the table below, important attributes have their names listed
  in <b>bold</b> in the description column.
*/
class SingleShadingSwitch : public BaseShadingSwitch
{
public:
	/*
	<b>Input</b> is a combination of two attributes, a value
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
		float inSingle;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", inSingle);
		}
	};
public:
	SingleShadingSwitch(FILE* file,const std::string& name,const std::string& parent=""):BaseShadingSwitch(file, name, parent, "singleShadingSwitch"){}
	virtual ~SingleShadingSwitch(){}
	/*
	<b>Input</b> is a combination of two attributes, a value
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
	<b>Input</b> is a combination of two attributes, a value
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
	/*<b>InSingle</b> is the "Value" component of Input (see above).*/
	void setInSingle(size_t i_i,float it){if(it == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].it\" %f;\n", i_i,it);}
	/*<b>InSingle</b> is the "Value" component of Input (see above).*/
	void setInSingle(size_t i_i,const FloatID& it){fprintf_s(mFile,"connectAttr \"");it.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].it\";\n",mName.c_str(),i_i);}
	/*<b>inShape</b> in the "Shape" component of Input (see above).*/
	void setInShape(size_t i_i,const MessageID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].is\";\n",mName.c_str(),i_i);}
	/*
	<b>Default</b> is the value used by this node when it is
	not rendering one of the nodes on the Input list..
	*/
	void setDefault(float def){if(def == 0.0) return; fprintf_s(mFile, "setAttr \".def\" %f;\n", def);}
	/*
	<b>Default</b> is the value used by this node when it is
	not rendering one of the nodes on the Input list..
	*/
	void setDefault(const FloatID& def){fprintf_s(mFile,"connectAttr \"");def.write(mFile);fprintf_s(mFile,"\" \"%s.def\";\n",mName.c_str());}
	/*
	<b>Output</b> is the Output value of the switch.  This
	value depends on what shape is being rendered.  When one of
	the objects in the Input
	list is being rendered, then Output is set to its
	corresponding value.  When none of the objects in the list
	is being rendered, Output is set to equal Default.
	*/
	void setOutput(const FloatID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out\";\n",mName.c_str());}
	/*
	<b>Input</b> is a combination of two attributes, a value
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
	/*<b>InSingle</b> is the "Value" component of Input (see above).*/
	const FloatID& getInSingle(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].it",mName.c_str(),i_i);return (const char*)buffer;}
	/*<b>inShape</b> in the "Shape" component of Input (see above).*/
	const MessageID& getInShape(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].is",mName.c_str(),i_i);return (const char*)buffer;}
	/*
	<b>Default</b> is the value used by this node when it is
	not rendering one of the nodes on the Input list..
	*/
	FloatID getDefault(){char buffer[4096];sprintf_s (buffer, "%s.def",mName.c_str());return (const char*)buffer;}
	/*
	<b>Output</b> is the Output value of the switch.  This
	value depends on what shape is being rendered.  When one of
	the objects in the Input
	list is being rendered, then Output is set to its
	corresponding value.  When none of the objects in the list
	is being rendered, Output is set to equal Default.
	*/
	FloatID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.out",mName.c_str());return (const char*)buffer;}
protected:
	SingleShadingSwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseShadingSwitch(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SINGLESHADINGSWITCH_H__
