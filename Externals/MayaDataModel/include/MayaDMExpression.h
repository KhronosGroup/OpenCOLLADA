/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXPRESSION_H__
#define __MayaDM_EXPRESSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> This is the expression node.  It takes an arbitrary list of doubles
 as input and performs any legal MEL expression on them to generate
 a list of double outputs.

 Caution:  Use of the 'setAttr' or 'getAttr' statements from within
           an expression node can have unexpected results.  Using
           these statements bypasses the normal dependency graph
           evaluation mechanism and may cause incorrect or incomplete
           evaluation.
</pre></p>
*/
class Expression : public DependNode
{
public:
public:
	Expression(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "expression"){}
	virtual ~Expression(){}
	/*This is the multi that holds the connection as input into the expression.*/
	void setInput(size_t in_i,double in){if(in == 0.0) return; fprintf_s(mFile, "setAttr \".in[%i]\" %f;\n", in_i,in);}
	/*This is the multi that holds the connection as input into the expression.*/
	void setInput(size_t in_i,const DoubleID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in[%i]\";\n",mName.c_str(),in_i);}
	/*This is the multi that holds the connection as output of the expression.*/
	void setOutput(size_t out_i,const DoubleID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out[%i]\";\n",mName.c_str(),out_i);}
	/*Default object for attribute names in expression. Remove when no loner need to read beta4 files.*/
	void setObject(const StringID& ob){fprintf_s(mFile,"connectAttr \"");ob.write(mFile);fprintf_s(mFile,"\" \"%s.ob\";\n",mName.c_str());}
	/*Default attribute if no lvalue in expression*/
	void setAttribute(const StringID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*Evaluated value of the expression*/
	void setExpression(const StringID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e\";\n",mName.c_str());}
	/*number of input and output connections for expressions*/
	void setExprConnCount(const IntID& xcc){fprintf_s(mFile,"connectAttr \"");xcc.write(mFile);fprintf_s(mFile,"\" \"%s.xcc\";\n",mName.c_str());}
	/*This is the internal representation for the expression.*/
	void setInternalExpression(const string& ixp){if(ixp == "NULL") return; fprintf_s(mFile, "setAttr \".ixp\" -type \"string\" ");ixp.write(mFile);fprintf_s(mFile,";\n");}
	/*This is the internal representation for the expression.*/
	void setInternalExpression(const StringID& ixp){fprintf_s(mFile,"connectAttr \"");ixp.write(mFile);fprintf_s(mFile,"\" \"%s.ixp\";\n",mName.c_str());}
	/*This holds the value for time to be queried in seconds.*/
	void setTime(const TimeID& tim){fprintf_s(mFile,"connectAttr \"");tim.write(mFile);fprintf_s(mFile,"\" \"%s.tim\";\n",mName.c_str());}
	/*This holds the value for time to be queried in frames.*/
	void setFrame(const TimeID& frm){fprintf_s(mFile,"connectAttr \"");frm.write(mFile);fprintf_s(mFile,"\" \"%s.frm\";\n",mName.c_str());}
	/*The last time that this expression was evaluated.*/
	void setLastTimeEvaluated(const TimeID& lte){fprintf_s(mFile,"connectAttr \"");lte.write(mFile);fprintf_s(mFile,"\" \"%s.lte\";\n",mName.c_str());}
	/*This attribute depends on aTime.  Dirtying aTime and asking for this will force evaluation.*/
	void setEvaluateNow(const ShortID& xen){fprintf_s(mFile,"connectAttr \"");xen.write(mFile);fprintf_s(mFile,"\" \"%s.xen\";\n",mName.c_str());}
	/*
	This attribute tells whether or not the expression node was forced to be "animated" from the expression command.
	Records the unit conversion option used to create/edit this expression.
	*/
	void setAnimated(unsigned int ani){if(ani == 1) return; fprintf_s(mFile, "setAttr \".ani\" %i;\n", ani);}
	/*
	This attribute tells whether or not the expression node was forced to be "animated" from the expression command.
	Records the unit conversion option used to create/edit this expression.
	*/
	void setAnimated(const UnsignedintID& ani){fprintf_s(mFile,"connectAttr \"");ani.write(mFile);fprintf_s(mFile,"\" \"%s.ani\";\n",mName.c_str());}
	/*This attribute tells the node whether this expression is from the old format.  The default is 0.  New files will write 1 into it. Remove when no longer need to read beta4 files.*/
	void setNewFileFormat(const ShortID& nff){fprintf_s(mFile,"connectAttr \"");nff.write(mFile);fprintf_s(mFile,"\" \"%s.nff\";\n",mName.c_str());}
	/*Identifies the default object.*/
	void setObjectMsg(const MessageID& obm){fprintf_s(mFile,"connectAttr \"");obm.write(mFile);fprintf_s(mFile,"\" \"%s.obm\";\n",mName.c_str());}
	/*Records the unit conversion option used to create/edit this expression.*/
	void setUnitOption(unsigned int uno){if(uno == 0) return; fprintf_s(mFile, "setAttr \".uno\" %i;\n", uno);}
	/*Records the unit conversion option used to create/edit this expression.*/
	void setUnitOption(const UnsignedintID& uno){fprintf_s(mFile,"connectAttr \"");uno.write(mFile);fprintf_s(mFile,"\" \"%s.uno\";\n",mName.c_str());}
	/*This is the multi that holds the connection as input into the expression.*/
	const DoubleID& getInput(size_t in_i){char buffer[4096];sprintf_s (buffer, "%s.in[%i]",mName.c_str(),in_i);return (const char*)buffer;}
	/*This is the multi that holds the connection as output of the expression.*/
	const DoubleID& getOutput(size_t out_i){char buffer[4096];sprintf_s (buffer, "%s.out[%i]",mName.c_str(),out_i);return (const char*)buffer;}
	/*Default object for attribute names in expression. Remove when no loner need to read beta4 files.*/
	StringID getObject(){char buffer[4096];sprintf_s (buffer, "%s.ob",mName.c_str());return (const char*)buffer;}
	/*Default attribute if no lvalue in expression*/
	StringID getAttribute(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*Evaluated value of the expression*/
	StringID getExpression(){char buffer[4096];sprintf_s (buffer, "%s.e",mName.c_str());return (const char*)buffer;}
	/*number of input and output connections for expressions*/
	IntID getExprConnCount(){char buffer[4096];sprintf_s (buffer, "%s.xcc",mName.c_str());return (const char*)buffer;}
	/*This is the internal representation for the expression.*/
	StringID getInternalExpression(){char buffer[4096];sprintf_s (buffer, "%s.ixp",mName.c_str());return (const char*)buffer;}
	/*This holds the value for time to be queried in seconds.*/
	TimeID getTime(){char buffer[4096];sprintf_s (buffer, "%s.tim",mName.c_str());return (const char*)buffer;}
	/*This holds the value for time to be queried in frames.*/
	TimeID getFrame(){char buffer[4096];sprintf_s (buffer, "%s.frm",mName.c_str());return (const char*)buffer;}
	/*The last time that this expression was evaluated.*/
	TimeID getLastTimeEvaluated(){char buffer[4096];sprintf_s (buffer, "%s.lte",mName.c_str());return (const char*)buffer;}
	/*This attribute depends on aTime.  Dirtying aTime and asking for this will force evaluation.*/
	ShortID getEvaluateNow(){char buffer[4096];sprintf_s (buffer, "%s.xen",mName.c_str());return (const char*)buffer;}
	/*
	This attribute tells whether or not the expression node was forced to be "animated" from the expression command.
	Records the unit conversion option used to create/edit this expression.
	*/
	UnsignedintID getAnimated(){char buffer[4096];sprintf_s (buffer, "%s.ani",mName.c_str());return (const char*)buffer;}
	/*This attribute tells the node whether this expression is from the old format.  The default is 0.  New files will write 1 into it. Remove when no longer need to read beta4 files.*/
	ShortID getNewFileFormat(){char buffer[4096];sprintf_s (buffer, "%s.nff",mName.c_str());return (const char*)buffer;}
	/*Identifies the default object.*/
	MessageID getObjectMsg(){char buffer[4096];sprintf_s (buffer, "%s.obm",mName.c_str());return (const char*)buffer;}
	/*Records the unit conversion option used to create/edit this expression.*/
	UnsignedintID getUnitOption(){char buffer[4096];sprintf_s (buffer, "%s.uno",mName.c_str());return (const char*)buffer;}
protected:
	Expression(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_EXPRESSION_H__
