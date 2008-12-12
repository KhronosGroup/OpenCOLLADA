/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CONDITION_H__
#define __MayaDM_CONDITION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Condition</b> is a utility node that allows you to switch
 between two colors or textures, depending on a simple mathematical
 relationship between two input values.  If the relationship
 (Greater Than, Less Than, Equals, Is Not Equal To, etc) is
 true, then the first color or texture is output.  If the relationship
 is false, then the second color or texture is output.
<p/>
 You can use Condition nodes for many different purposes.
 Some examples:
 <ul>
 <li>You could create a shader that changes to a different
 color when an object goes above a certain height. To do this,
 connect the Translate Y attribute of the object to First Term,
 set Second Term to the desired height, and set Operation to
 "Greater Than".  Set ColorIfTrue to red and ColorIfFalse to blue,
 and connect the OutColor attribute to the object's shader.  Now, when the
 Y value of the object goes above the desired height, it will change
 color from blue to red.
</li>
<li>In a slight variation, you can create a texture where
 the parts of the texture above a certain height are one color,
 and the parts below are another color. Create a Sampler
 Info utility node, and connect its Point World Y attribute to
 First Term.
 This will give you the position of each point on
 the texture, rather than the position of the whole object.
 Set Second Term to the desired height, and set
 Operation to "Greater Than".
</li>
 <li>You could create a texture that is like a marble texture, but
 turns black in all the areas where the marble is too red.  To do this,
 connect the Marble's Out Color R attribute to First Term, and set
 Second term to the desired red threshold value (say, 0.75).
 Connect the Out Color attribute of a marble texture to
 ColorIfFalse, and set ColorIfTrue to black. Set Operation to
 "Greater Than". Connect the OutColor of the Condition
 node to your shader.
</li>
</ul>
 See the Rendering Book for more in-depth examples.
<p/>
 <b>Note:</b> The Condition node is completely unrelated to the
 "condition" command found in the MEL scripting language.
<p/>
 In general, the operation of the Condition Node is this:
<p/><pre>
     IF ( First Term OPERATION Second Term ) THEN
         Out Color = Color If True
     ELSE
         Out Color = Color If False
</pre><p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class Condition : public DependNode
{
public:
public:
	Condition(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "condition"){}
	virtual ~Condition(){}
	/*
	<b>Operation</b> is the test that is performed between
	the First Term and Second Term attributes.  If the
	test is true, Out Color is set to ColorIfTrue.  If it is false,
	Out Color is set to ColorIfFalse.
	<p/>
	The possible operations are:
	<ul><li>Equal</li>
	<li>Not Equal</li>
	<li>Greater Than</li>
	<li>Greater Or Equal</li>
	<li>Less Than</li>
	<li>Less or Equal</li>
	</ul>
	*/
	void setOperation(unsigned int op){if(op == 0) return; fprintf_s(mFile, "setAttr \".op\" %i;\n", op);}
	/*
	<b>Operation</b> is the test that is performed between
	the First Term and Second Term attributes.  If the
	test is true, Out Color is set to ColorIfTrue.  If it is false,
	Out Color is set to ColorIfFalse.
	<p/>
	The possible operations are:
	<ul><li>Equal</li>
	<li>Not Equal</li>
	<li>Greater Than</li>
	<li>Greater Or Equal</li>
	<li>Less Than</li>
	<li>Less or Equal</li>
	</ul>
	*/
	void setOperation(const UnsignedintID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*
	<b>First Term</b> is the first term of the if condition.
	(See description at top).
	*/
	void setFirstTerm(float ft){if(ft == 0.0) return; fprintf_s(mFile, "setAttr \".ft\" %f;\n", ft);}
	/*
	<b>First Term</b> is the first term of the if condition.
	(See description at top).
	*/
	void setFirstTerm(const FloatID& ft){fprintf_s(mFile,"connectAttr \"");ft.write(mFile);fprintf_s(mFile,"\" \"%s.ft\";\n",mName.c_str());}
	/*
	<b>Second Term</b> is the second term of the if condition.
	(See description at top).
	*/
	void setSecondTerm(float st){if(st == 0.0) return; fprintf_s(mFile, "setAttr \".st\" %f;\n", st);}
	/*
	<b>Second Term</b> is the second term of the if condition.
	(See description at top).
	*/
	void setSecondTerm(const FloatID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*
	<b>ColorIfTrue</b>. The color or texture that will be output
	by this node when the condition is True. See description at top.
	*/
	void setColorIfTrue(const float3& ct){if(ct == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ct\" -type \"float3\" ");ct.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>ColorIfTrue</b>. The color or texture that will be output
	by this node when the condition is True. See description at top.
	*/
	void setColorIfTrue(const Float3ID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*The red component of ColorIfTrue*/
	void setColorIfTrueR(float ctr){if(ctr == 0.0) return; fprintf_s(mFile, "setAttr \".ct.ctr\" %f;\n", ctr);}
	/*The red component of ColorIfTrue*/
	void setColorIfTrueR(const FloatID& ctr){fprintf_s(mFile,"connectAttr \"");ctr.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctr\";\n",mName.c_str());}
	/*The green component of ColorIfTrue*/
	void setColorIfTrueG(float ctg){if(ctg == 0.0) return; fprintf_s(mFile, "setAttr \".ct.ctg\" %f;\n", ctg);}
	/*The green component of ColorIfTrue*/
	void setColorIfTrueG(const FloatID& ctg){fprintf_s(mFile,"connectAttr \"");ctg.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctg\";\n",mName.c_str());}
	/*The blue component of ColorIfTrue*/
	void setColorIfTrueB(float ctb){if(ctb == 0.0) return; fprintf_s(mFile, "setAttr \".ct.ctb\" %f;\n", ctb);}
	/*The blue component of ColorIfTrue*/
	void setColorIfTrueB(const FloatID& ctb){fprintf_s(mFile,"connectAttr \"");ctb.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctb\";\n",mName.c_str());}
	/*
	<b>ColorIfFalse</b>. The color or texture that
	will be output by this node when the condition is
	False.  (See description at top).
	*/
	void setColorIfFalse(const float3& cf){if(cf == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".cf\" -type \"float3\" ");cf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>ColorIfFalse</b>. The color or texture that
	will be output by this node when the condition is
	False.  (See description at top).
	*/
	void setColorIfFalse(const Float3ID& cf){fprintf_s(mFile,"connectAttr \"");cf.write(mFile);fprintf_s(mFile,"\" \"%s.cf\";\n",mName.c_str());}
	/*The red component of ColorIfFalse*/
	void setColorIfFalseR(float cfr){if(cfr == 0.0) return; fprintf_s(mFile, "setAttr \".cf.cfr\" %f;\n", cfr);}
	/*The red component of ColorIfFalse*/
	void setColorIfFalseR(const FloatID& cfr){fprintf_s(mFile,"connectAttr \"");cfr.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfr\";\n",mName.c_str());}
	/*The green component of ColorIfFalse*/
	void setColorIfFalseG(float cfg){if(cfg == 0.0) return; fprintf_s(mFile, "setAttr \".cf.cfg\" %f;\n", cfg);}
	/*The green component of ColorIfFalse*/
	void setColorIfFalseG(const FloatID& cfg){fprintf_s(mFile,"connectAttr \"");cfg.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfg\";\n",mName.c_str());}
	/*The blue component of ColorIfFalse*/
	void setColorIfFalseB(float cfb){if(cfb == 0.0) return; fprintf_s(mFile, "setAttr \".cf.cfb\" %f;\n", cfb);}
	/*The blue component of ColorIfFalse*/
	void setColorIfFalseB(const FloatID& cfb){fprintf_s(mFile,"connectAttr \"");cfb.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfb\";\n",mName.c_str());}
	/*
	<b>Out Color</b>.  This is set to Color IfTrue when the
	condition is True, and to Color IfFalse when the condition is
	False.
	*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The red component of Out Color*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*The green component of Out Color*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*The blue component of Out Color*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*
	<b>Operation</b> is the test that is performed between
	the First Term and Second Term attributes.  If the
	test is true, Out Color is set to ColorIfTrue.  If it is false,
	Out Color is set to ColorIfFalse.
	<p/>
	The possible operations are:
	<ul><li>Equal</li>
	<li>Not Equal</li>
	<li>Greater Than</li>
	<li>Greater Or Equal</li>
	<li>Less Than</li>
	<li>Less or Equal</li>
	</ul>
	*/
	UnsignedintID getOperation(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*
	<b>First Term</b> is the first term of the if condition.
	(See description at top).
	*/
	FloatID getFirstTerm(){char buffer[4096];sprintf_s (buffer, "%s.ft",mName.c_str());return (const char*)buffer;}
	/*
	<b>Second Term</b> is the second term of the if condition.
	(See description at top).
	*/
	FloatID getSecondTerm(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*
	<b>ColorIfTrue</b>. The color or texture that will be output
	by this node when the condition is True. See description at top.
	*/
	Float3ID getColorIfTrue(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*The red component of ColorIfTrue*/
	FloatID getColorIfTrueR(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctr",mName.c_str());return (const char*)buffer;}
	/*The green component of ColorIfTrue*/
	FloatID getColorIfTrueG(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctg",mName.c_str());return (const char*)buffer;}
	/*The blue component of ColorIfTrue*/
	FloatID getColorIfTrueB(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctb",mName.c_str());return (const char*)buffer;}
	/*
	<b>ColorIfFalse</b>. The color or texture that
	will be output by this node when the condition is
	False.  (See description at top).
	*/
	Float3ID getColorIfFalse(){char buffer[4096];sprintf_s (buffer, "%s.cf",mName.c_str());return (const char*)buffer;}
	/*The red component of ColorIfFalse*/
	FloatID getColorIfFalseR(){char buffer[4096];sprintf_s (buffer, "%s.cf.cfr",mName.c_str());return (const char*)buffer;}
	/*The green component of ColorIfFalse*/
	FloatID getColorIfFalseG(){char buffer[4096];sprintf_s (buffer, "%s.cf.cfg",mName.c_str());return (const char*)buffer;}
	/*The blue component of ColorIfFalse*/
	FloatID getColorIfFalseB(){char buffer[4096];sprintf_s (buffer, "%s.cf.cfb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Color</b>.  This is set to Color IfTrue when the
	condition is True, and to Color IfFalse when the condition is
	False.
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*The red component of Out Color*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*The green component of Out Color*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Out Color*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
protected:
	Condition(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CONDITION_H__
