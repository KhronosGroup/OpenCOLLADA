/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYDELEDGE_H__
#define __MayaDM_POLYDELEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Deletes edges and merges neighboring faces.
 Only non-border edges can be deleted.
 If deletion leaves winged vertices and cleanVertices is
 set to true, winged vertices will also be deleted.<p/>
*/
class PolyDelEdge : public PolyModifier
{
public:
public:
	PolyDelEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyDelEdge"){}
	virtual ~PolyDelEdge(){}
	/*
	If true : delete resulting vertices if they are winged
	(i.e. connected to exactly two edges).
	*/
	void setCleanVertices(bool cv){if(cv == false) return; fprintf_s(mFile, "setAttr \".cv\" %i;\n", cv);}
	/*
	If true : delete resulting vertices if they are winged
	(i.e. connected to exactly two edges).
	*/
	void setCleanVertices(const BoolID& cv){fprintf_s(mFile,"connectAttr \"");cv.write(mFile);fprintf_s(mFile,"\" \"%s.cv\";\n",mName.c_str());}
	/*
	If true : delete resulting vertices if they are winged
	(i.e. connected to exactly two edges).
	*/
	BoolID getCleanVertices(){char buffer[4096];sprintf_s (buffer, "%s.cv",mName.c_str());return (const char*)buffer;}
protected:
	PolyDelEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYDELEDGE_H__
