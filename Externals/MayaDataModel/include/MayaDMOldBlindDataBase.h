/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OLDBLINDDATABASE_H__
#define __MayaDM_OLDBLINDDATABASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This is the base class for BlindData created by the user by specifying
        the typeId of the blindData template that this node is to be based
        upon. <p/>
*/
class OldBlindDataBase : public DependNode
{
public:
public:
	OldBlindDataBase(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "oldBlindDataBase"){}
	virtual ~OldBlindDataBase(){}
	/*TypeId of the BlindData type specified by this node*/
	void setTypeId(int tid){if(tid == 0) return; fprintf_s(mFile, "setAttr \".tid\" %i;\n", tid);}
	/*TypeId of the BlindData type specified by this node*/
	void setTypeId(const IntID& tid){fprintf_s(mFile,"connectAttr \"");tid.write(mFile);fprintf_s(mFile,"\" \"%s.tid\";\n",mName.c_str());}
	/*TypeId of the BlindData type specified by this node*/
	IntID getTypeId(){char buffer[4096];sprintf_s (buffer, "%s.tid",mName.c_str());return (const char*)buffer;}
protected:
	OldBlindDataBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OLDBLINDDATABASE_H__
