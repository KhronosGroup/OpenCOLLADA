/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLEND_H__
#define __MayaDM_BLEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
    This node blends one or more numeric inputs.
    Note that this node is a virtual class, and so the blending function
    is defined by the derived blend classes.

    The common thing for all blend nodes is that there is a current driver.
    The current driver attribute is a scalar number specifying which of the
    multi-input attributes is the current driver. The current driver input
    is used by several commands to specify which of the multi-input attributes
    to operate on. For example, the setDrivenKeyframe command will set a
    keyframe on the input with the multi-index specified by the current driver.
</pre></p>
*/
class Blend : public DependNode
{
public:
public:
	Blend(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "blend"){}
	virtual ~Blend(){}
	/*List of inputs which will be blended*/
	void setInput(size_t i_i,double i){if(i == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i]\" %f;\n", i_i,i);}
	/*List of inputs which will be blended*/
	void setInput(size_t i_i,const DoubleID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i]\";\n",mName.c_str(),i_i);}
	/*Blended output computed from inputs*/
	void setOutput(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Index of the current input driver*/
	void setCurrent(int c){if(c == 0) return; fprintf_s(mFile, "setAttr \".c\" %i;\n", c);}
	/*List of inputs which will be blended*/
	const DoubleID& getInput(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i]",mName.c_str(),i_i);return (const char*)buffer;}
	/*Blended output computed from inputs*/
	DoubleID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	Blend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BLEND_H__
