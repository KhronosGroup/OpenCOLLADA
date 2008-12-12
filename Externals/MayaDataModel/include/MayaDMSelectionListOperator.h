/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SELECTIONLISTOPERATOR_H__
#define __MayaDM_SELECTIONLISTOPERATOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Dependency node that can do union, intersection or not-intersection
          operations on selection lists.
*/
class SelectionListOperator : public DependNode
{
public:
public:
	SelectionListOperator(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "selectionListOperator"){}
	virtual ~SelectionListOperator(){}
	/*Set operation.  One of: intersection, union, not-intersection, difference*/
	void setOperation(unsigned int op){if(op == 0) return; fprintf_s(mFile, "setAttr \".op\" %i;\n", op);}
	/*Set operation.  One of: intersection, union, not-intersection, difference*/
	void setOperation(const UnsignedintID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*Input list A*/
	void setInputListA(const SelectionListID& ina){fprintf_s(mFile,"connectAttr \"");ina.write(mFile);fprintf_s(mFile,"\" \"%s.ina\";\n",mName.c_str());}
	/*Input list B*/
	void setInputListB(const SelectionListID& inb){fprintf_s(mFile,"connectAttr \"");inb.write(mFile);fprintf_s(mFile,"\" \"%s.inb\";\n",mName.c_str());}
	/*List that results from union, intersection or not-intersection operation.*/
	void setOutputList(const SelectionListID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out\";\n",mName.c_str());}
	/*Need to distinguish between builtin, user and other operators.*/
	void setOperatorClass(unsigned int ocls){if(ocls == 0) return; fprintf_s(mFile, "setAttr \".ocls\" %i;\n", ocls);}
	/*Need to distinguish between builtin, user and other operators.*/
	void setOperatorClass(const UnsignedintID& ocls){fprintf_s(mFile,"connectAttr \"");ocls.write(mFile);fprintf_s(mFile,"\" \"%s.ocls\";\n",mName.c_str());}
	/*Set operation.  One of: intersection, union, not-intersection, difference*/
	UnsignedintID getOperation(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*Input list A*/
	SelectionListID getInputListA(){char buffer[4096];sprintf_s (buffer, "%s.ina",mName.c_str());return (const char*)buffer;}
	/*Input list B*/
	SelectionListID getInputListB(){char buffer[4096];sprintf_s (buffer, "%s.inb",mName.c_str());return (const char*)buffer;}
	/*List that results from union, intersection or not-intersection operation.*/
	SelectionListID getOutputList(){char buffer[4096];sprintf_s (buffer, "%s.out",mName.c_str());return (const char*)buffer;}
	/*Need to distinguish between builtin, user and other operators.*/
	UnsignedintID getOperatorClass(){char buffer[4096];sprintf_s (buffer, "%s.ocls",mName.c_str());return (const char*)buffer;}
protected:
	SelectionListOperator(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SELECTIONLISTOPERATOR_H__
