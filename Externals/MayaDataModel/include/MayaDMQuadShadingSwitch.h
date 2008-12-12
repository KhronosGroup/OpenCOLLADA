/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_QUADSHADINGSWITCH_H__
#define __MayaDM_QUADSHADINGSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseShadingSwitch.h"
namespace MayaDM
{
/*
<b>Quad Shading Switch</b> is a utility node that enables
  you to switch between different values based on which surface
  is being shaded.
  <p/>
  The usage of this node is very samilar to TripleShadingSwitch. The
  only different is this works on quadruple-valued attributes, like
  rgb and alpha.
  <b>Note:</b> If you need to switch single attributes (such as Intensity
  of Translucence), use a Single Shading Switch.  If you need to switch
  double attributes, such as UV coordinates, use a Double Shading switch.
  And if you need to switch triple attributes, such as xyz, use a Triple
        Shading switch.
  <p/>
  In the table below, important attributes have their names listed
  in <b>bold</b> in the description column.
*/
class QuadShadingSwitch : public BaseShadingSwitch
{
public:
	/*
	<b>aInput</b> is a combination of two attributes, a quad value
	and the name of a shape.  This is also a multiple attribute, so
	you can specify any number of these pairs.<p/>
	During rendering, the Output attribute is set depending on
	which object is being rendered.  When one of the objects in
	in this list is being rendered, then Output is set to its
	corresponding value.
	*/
	struct Input{
		/*<b>aInQuad</b> is the value component of aInput (see above).*/
		struct InQuad{
			float3 inTriple;
			float inSingle;
			void write(FILE* file) const
			{
				inTriple.write(file);
				fprintf_s(file, " ");
				fprintf_s(file,"%f", inSingle);
			}
		} inQuad;
		void write(FILE* file) const
		{
			inQuad.write(file);
			fprintf_s(file, " ");
		}
	};
	/*
	<b>aDefault</b> is the value used by this node when it is
	not rendering one of the nodes on the aInput list..
	*/
	struct Default{
		float3 defTriple;
		float defSingle;
		void write(FILE* file) const
		{
			defTriple.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f", defSingle);
		}
	};
	/*
	<b>aOutput</b> is the output value of the switch.  This
	value depends on what shape is being rendered.  When one of
	the objects in the Input list is being rendered, then output
	is set to its corresponding value.  When none of the objects
	in the list is being rendered, Output is set to equal to Default.
	*/
	struct Output{
		void write(FILE* file) const
		{
		}
	};
public:
	QuadShadingSwitch(FILE* file,const std::string& name,const std::string& parent=""):BaseShadingSwitch(file, name, parent, "quadShadingSwitch"){}
	virtual ~QuadShadingSwitch(){}
	/*
	<b>aInput</b> is a combination of two attributes, a quad value
	and the name of a shape.  This is also a multiple attribute, so
	you can specify any number of these pairs.<p/>
	During rendering, the Output attribute is set depending on
	which object is being rendered.  When one of the objects in
	in this list is being rendered, then Output is set to its
	corresponding value.
	*/
	void setInput(size_t i_i,const Input& i){fprintf_s(mFile, "setAttr \".i[%i]\" ",i_i);i.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>aInput</b> is a combination of two attributes, a quad value
	and the name of a shape.  This is also a multiple attribute, so
	you can specify any number of these pairs.<p/>
	During rendering, the Output attribute is set depending on
	which object is being rendered.  When one of the objects in
	in this list is being rendered, then Output is set to its
	corresponding value.
	*/
	void setInput(size_t i_i,const InputID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i]\";\n",mName.c_str(),i_i);}
	/*<b>aInQuad</b> is the value component of aInput (see above).*/
	void setInQuad(size_t i_i,const Input::InQuad& iq){fprintf_s(mFile, "setAttr \".i[%i].iq\" ",i_i);iq.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>aInQuad</b> is the value component of aInput (see above).*/
	void setInQuad(size_t i_i,const InQuadID& iq){fprintf_s(mFile,"connectAttr \"");iq.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].iq\";\n",mName.c_str(),i_i);}
	/*<b>aInTriple</b> is the triple "Value" component of aInQuad*/
	void setInTriple(size_t i_i,const float3& itr){fprintf_s(mFile, "setAttr \".i[%i].iq.itr\" -type \"float3\" ",i_i);itr.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>aInTriple</b> is the triple "Value" component of aInQuad*/
	void setInTriple(size_t i_i,const Float3ID& itr){fprintf_s(mFile,"connectAttr \"");itr.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].iq.itr\";\n",mName.c_str(),i_i);}
	/*The first component of aInTriple*/
	void setInComp1(size_t i_i,float ic1){if(ic1 == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].iq.itr.ic1\" %f;\n", i_i,ic1);}
	/*The first component of aInTriple*/
	void setInComp1(size_t i_i,const FloatID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].iq.itr.ic1\";\n",mName.c_str(),i_i);}
	/*The second component of aInTriple*/
	void setInComp2(size_t i_i,float ic2){if(ic2 == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].iq.itr.ic2\" %f;\n", i_i,ic2);}
	/*The second component of aInTriple*/
	void setInComp2(size_t i_i,const FloatID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].iq.itr.ic2\";\n",mName.c_str(),i_i);}
	/*The third component of aInTriple*/
	void setInComp3(size_t i_i,float ic3){if(ic3 == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].iq.itr.ic3\" %f;\n", i_i,ic3);}
	/*The third component of aInTriple*/
	void setInComp3(size_t i_i,const FloatID& ic3){fprintf_s(mFile,"connectAttr \"");ic3.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].iq.itr.ic3\";\n",mName.c_str(),i_i);}
	/*<b>aInSingle</b> is the single "Value" component of aInQuad*/
	void setInSingle(size_t i_i,float isi){if(isi == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].iq.isi\" %f;\n", i_i,isi);}
	/*<b>aInSingle</b> is the single "Value" component of aInQuad*/
	void setInSingle(size_t i_i,const FloatID& isi){fprintf_s(mFile,"connectAttr \"");isi.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].iq.isi\";\n",mName.c_str(),i_i);}
	/*<b>aInShape</b> is the "Shape" component of aInput (see above).*/
	void setInShape(size_t i_i,const MessageID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].is\";\n",mName.c_str(),i_i);}
	/*
	<b>aDefault</b> is the value used by this node when it is
	not rendering one of the nodes on the aInput list..
	*/
	void setDefault(const Default& def){fprintf_s(mFile, "setAttr \".def\" ");def.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>aDefault</b> is the value used by this node when it is
	not rendering one of the nodes on the aInput list..
	*/
	void setDefault(const DefaultID& def){fprintf_s(mFile,"connectAttr \"");def.write(mFile);fprintf_s(mFile,"\" \"%s.def\";\n",mName.c_str());}
	/*<b>aDefTriple</b> is the triple value of the aDefault component.*/
	void setDefTriple(const float3& dtr){if(dtr == float3(0.8, 0.8, 0.8)) return; fprintf_s(mFile, "setAttr \".def.dtr\" -type \"float3\" ");dtr.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>aDefTriple</b> is the triple value of the aDefault component.*/
	void setDefTriple(const Float3ID& dtr){fprintf_s(mFile,"connectAttr \"");dtr.write(mFile);fprintf_s(mFile,"\" \"%s.def.dtr\";\n",mName.c_str());}
	/*The first component of aDefTriple*/
	void setDefComp1(float dc1){if(dc1 == 0.0) return; fprintf_s(mFile, "setAttr \".def.dtr.dc1\" %f;\n", dc1);}
	/*The first component of aDefTriple*/
	void setDefComp1(const FloatID& dc1){fprintf_s(mFile,"connectAttr \"");dc1.write(mFile);fprintf_s(mFile,"\" \"%s.def.dtr.dc1\";\n",mName.c_str());}
	/*The second component of aDefTriple*/
	void setDefComp2(float dc2){if(dc2 == 0.0) return; fprintf_s(mFile, "setAttr \".def.dtr.dc2\" %f;\n", dc2);}
	/*The second component of aDefTriple*/
	void setDefComp2(const FloatID& dc2){fprintf_s(mFile,"connectAttr \"");dc2.write(mFile);fprintf_s(mFile,"\" \"%s.def.dtr.dc2\";\n",mName.c_str());}
	/*The third component of aDefTriple*/
	void setDefComp3(float dc3){if(dc3 == 0.0) return; fprintf_s(mFile, "setAttr \".def.dtr.dc3\" %f;\n", dc3);}
	/*The third component of aDefTriple*/
	void setDefComp3(const FloatID& dc3){fprintf_s(mFile,"connectAttr \"");dc3.write(mFile);fprintf_s(mFile,"\" \"%s.def.dtr.dc3\";\n",mName.c_str());}
	/*<b>aDefSingle</b> is the single value of aDefault component.*/
	void setDefSingle(float dsi){if(dsi == 0.0) return; fprintf_s(mFile, "setAttr \".def.dsi\" %f;\n", dsi);}
	/*<b>aDefSingle</b> is the single value of aDefault component.*/
	void setDefSingle(const FloatID& dsi){fprintf_s(mFile,"connectAttr \"");dsi.write(mFile);fprintf_s(mFile,"\" \"%s.def.dsi\";\n",mName.c_str());}
	/*
	<b>aOutput</b> is the output value of the switch.  This
	value depends on what shape is being rendered.  When one of
	the objects in the Input list is being rendered, then output
	is set to its corresponding value.  When none of the objects
	in the list is being rendered, Output is set to equal to Default.
	*/
	void setOutput(const OutputID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out\";\n",mName.c_str());}
	/*<b>outTriple</b> is the triple value of the output component.*/
	void setOutTriple(const Float3ID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.out.otr\";\n",mName.c_str());}
	/*The first component of aOutTriple.*/
	void setOutComp1(const FloatID& oc1){fprintf_s(mFile,"connectAttr \"");oc1.write(mFile);fprintf_s(mFile,"\" \"%s.out.otr.oc1\";\n",mName.c_str());}
	/*The second component of aOutTriple*/
	void setOutComp2(const FloatID& oc2){fprintf_s(mFile,"connectAttr \"");oc2.write(mFile);fprintf_s(mFile,"\" \"%s.out.otr.oc2\";\n",mName.c_str());}
	/*The third component of aOutTriple*/
	void setOutComp3(const FloatID& oc3){fprintf_s(mFile,"connectAttr \"");oc3.write(mFile);fprintf_s(mFile,"\" \"%s.out.otr.oc3\";\n",mName.c_str());}
	/*<b>aOutSingle</b> is the single value of the output component.*/
	void setOutSingle(const FloatID& osi){fprintf_s(mFile,"connectAttr \"");osi.write(mFile);fprintf_s(mFile,"\" \"%s.out.osi\";\n",mName.c_str());}
	/*
	<b>aInput</b> is a combination of two attributes, a quad value
	and the name of a shape.  This is also a multiple attribute, so
	you can specify any number of these pairs.<p/>
	During rendering, the Output attribute is set depending on
	which object is being rendered.  When one of the objects in
	in this list is being rendered, then Output is set to its
	corresponding value.
	*/
	const InputID& getInput(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i]",mName.c_str(),i_i);return (const char*)buffer;}
	/*<b>aInQuad</b> is the value component of aInput (see above).*/
	const InQuadID& getInQuad(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].iq",mName.c_str(),i_i);return (const char*)buffer;}
	/*<b>aInTriple</b> is the triple "Value" component of aInQuad*/
	const Float3ID& getInTriple(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].iq.itr",mName.c_str(),i_i);return (const char*)buffer;}
	/*The first component of aInTriple*/
	const FloatID& getInComp1(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].iq.itr.ic1",mName.c_str(),i_i);return (const char*)buffer;}
	/*The second component of aInTriple*/
	const FloatID& getInComp2(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].iq.itr.ic2",mName.c_str(),i_i);return (const char*)buffer;}
	/*The third component of aInTriple*/
	const FloatID& getInComp3(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].iq.itr.ic3",mName.c_str(),i_i);return (const char*)buffer;}
	/*<b>aInSingle</b> is the single "Value" component of aInQuad*/
	const FloatID& getInSingle(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].iq.isi",mName.c_str(),i_i);return (const char*)buffer;}
	/*<b>aInShape</b> is the "Shape" component of aInput (see above).*/
	const MessageID& getInShape(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].is",mName.c_str(),i_i);return (const char*)buffer;}
	/*
	<b>aDefault</b> is the value used by this node when it is
	not rendering one of the nodes on the aInput list..
	*/
	DefaultID getDefault(){char buffer[4096];sprintf_s (buffer, "%s.def",mName.c_str());return (const char*)buffer;}
	/*<b>aDefTriple</b> is the triple value of the aDefault component.*/
	Float3ID getDefTriple(){char buffer[4096];sprintf_s (buffer, "%s.def.dtr",mName.c_str());return (const char*)buffer;}
	/*The first component of aDefTriple*/
	FloatID getDefComp1(){char buffer[4096];sprintf_s (buffer, "%s.def.dtr.dc1",mName.c_str());return (const char*)buffer;}
	/*The second component of aDefTriple*/
	FloatID getDefComp2(){char buffer[4096];sprintf_s (buffer, "%s.def.dtr.dc2",mName.c_str());return (const char*)buffer;}
	/*The third component of aDefTriple*/
	FloatID getDefComp3(){char buffer[4096];sprintf_s (buffer, "%s.def.dtr.dc3",mName.c_str());return (const char*)buffer;}
	/*<b>aDefSingle</b> is the single value of aDefault component.*/
	FloatID getDefSingle(){char buffer[4096];sprintf_s (buffer, "%s.def.dsi",mName.c_str());return (const char*)buffer;}
	/*
	<b>aOutput</b> is the output value of the switch.  This
	value depends on what shape is being rendered.  When one of
	the objects in the Input list is being rendered, then output
	is set to its corresponding value.  When none of the objects
	in the list is being rendered, Output is set to equal to Default.
	*/
	OutputID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.out",mName.c_str());return (const char*)buffer;}
	/*<b>outTriple</b> is the triple value of the output component.*/
	Float3ID getOutTriple(){char buffer[4096];sprintf_s (buffer, "%s.out.otr",mName.c_str());return (const char*)buffer;}
	/*The first component of aOutTriple.*/
	FloatID getOutComp1(){char buffer[4096];sprintf_s (buffer, "%s.out.otr.oc1",mName.c_str());return (const char*)buffer;}
	/*The second component of aOutTriple*/
	FloatID getOutComp2(){char buffer[4096];sprintf_s (buffer, "%s.out.otr.oc2",mName.c_str());return (const char*)buffer;}
	/*The third component of aOutTriple*/
	FloatID getOutComp3(){char buffer[4096];sprintf_s (buffer, "%s.out.otr.oc3",mName.c_str());return (const char*)buffer;}
	/*<b>aOutSingle</b> is the single value of the output component.*/
	FloatID getOutSingle(){char buffer[4096];sprintf_s (buffer, "%s.out.osi",mName.c_str());return (const char*)buffer;}
protected:
	QuadShadingSwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseShadingSwitch(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_QUADSHADINGSWITCH_H__
