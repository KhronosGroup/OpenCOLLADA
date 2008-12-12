/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BOOLEAN_H__
#define __MayaDM_BOOLEAN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The "boolean" node perform a union or subtract or intersect
 type of operation given a pair of nurbs shell data type. The
 two input shells are provided using the attributes "isa" and
 "isb" respectively. The type of operation is specified using
 the attribute "operation".
 The result, a nurbs shell, is avilable using the attribute
 ".osh".
 <p/>
*/
class Boolean : public AbstractBaseCreate
{
public:
public:
	Boolean(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "boolean"){}
	virtual ~Boolean(){}
	/*The input NURBS shell A.*/
	void setInputShellA(const NurbsShellID& isa){fprintf_s(mFile,"connectAttr \"");isa.write(mFile);fprintf_s(mFile,"\" \"%s.isa\";\n",mName.c_str());}
	/*The input NURBS shell B.*/
	void setInputShellB(const NurbsShellID& isb){fprintf_s(mFile,"connectAttr \"");isb.write(mFile);fprintf_s(mFile,"\" \"%s.isb\";\n",mName.c_str());}
	/*Type of Boolean operation.*/
	void setOperation(unsigned int op){if(op == 0) return; fprintf_s(mFile, "setAttr \".op\" %i;\n", op);}
	/*Type of Boolean operation.*/
	void setOperation(const UnsignedintID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*fitting tolerance.*/
	void setTolerance(double tlb){if(tlb == 0) return; fprintf_s(mFile, "setAttr \".tlb\" %f;\n", tlb);}
	/*fitting tolerance.*/
	void setTolerance(const DoubleID& tlb){fprintf_s(mFile,"connectAttr \"");tlb.write(mFile);fprintf_s(mFile,"\" \"%s.tlb\";\n",mName.c_str());}
	/*Output Nurbs Shell*/
	void setOutputShell(const NurbsShellID& osh){fprintf_s(mFile,"connectAttr \"");osh.write(mFile);fprintf_s(mFile,"\" \"%s.osh\";\n",mName.c_str());}
	/*The input NURBS shell A.*/
	NurbsShellID getInputShellA(){char buffer[4096];sprintf_s (buffer, "%s.isa",mName.c_str());return (const char*)buffer;}
	/*The input NURBS shell B.*/
	NurbsShellID getInputShellB(){char buffer[4096];sprintf_s (buffer, "%s.isb",mName.c_str());return (const char*)buffer;}
	/*Type of Boolean operation.*/
	UnsignedintID getOperation(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*fitting tolerance.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tlb",mName.c_str());return (const char*)buffer;}
	/*Output Nurbs Shell*/
	NurbsShellID getOutputShell(){char buffer[4096];sprintf_s (buffer, "%s.osh",mName.c_str());return (const char*)buffer;}
protected:
	Boolean(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BOOLEAN_H__
