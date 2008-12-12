/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYBLINDDATA_H__
#define __MayaDM_POLYBLINDDATA_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node is the instance of BlindData that is created by the user by
        specifying the typeId of the blindData type that this node is to be based
        upon. <p/>
*/
class PolyBlindData : public DependNode
{
public:
public:
	PolyBlindData(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "polyBlindData"){}
	virtual ~PolyBlindData(){}
	/*TypeId of the BlindData type specified by this node*/
	void setTypeId(int tid){if(tid == 0) return; fprintf_s(mFile, "setAttr \".tid\" %i;\n", tid);}
	/*TypeId of the BlindData type specified by this node*/
	void setTypeId(const IntID& tid){fprintf_s(mFile,"connectAttr \"");tid.write(mFile);fprintf_s(mFile,"\" \"%s.tid\";\n",mName.c_str());}
	/*Input dataMesh that BlindData is to be applied to.*/
	void setInMesh(const GeometryID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*The Output dataMesh that has BlindData attached to it.*/
	void setOutMesh(const GeometryID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*
	BlindData entries added by this node are unique - the process of adding
	blind data is faster if this attribute is set to true. This attribute
	is not to be set or modified by the user.
	*/
	void setBlindDataEntriesAreNew(bool bdn){if(bdn == false) return; fprintf_s(mFile, "setAttr \".bdn\" %i;\n", bdn);}
	/*TypeId of the BlindData type specified by this node*/
	IntID getTypeId(){char buffer[4096];sprintf_s (buffer, "%s.tid",mName.c_str());return (const char*)buffer;}
	/*Input dataMesh that BlindData is to be applied to.*/
	GeometryID getInMesh(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*The Output dataMesh that has BlindData attached to it.*/
	GeometryID getOutMesh(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	PolyBlindData(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYBLINDDATA_H__
