/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVCOLLAPSE_H__
#define __MayaDM_SUBDIVCOLLAPSE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
*/
class SubdivCollapse : public DependNode
{
public:
public:
	SubdivCollapse(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdivCollapse"){}
	virtual ~SubdivCollapse(){}
	/*The input subdivision surface to be collapsed*/
	void setInSubdiv(const SubdivisionSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*The resulting subdivision surface*/
	void setOutSubdiv(const SubdivisionSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The level which will now become the base mesh*/
	void setLevel(int l){if(l == 0) return; fprintf_s(mFile, "setAttr \".l\" %i;\n", l);}
	/*The level which will now become the base mesh*/
	void setLevel(const IntID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*The input subdivision surface to be collapsed*/
	SubdivisionSurfaceID getInSubdiv(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*The resulting subdivision surface*/
	SubdivisionSurfaceID getOutSubdiv(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*The level which will now become the base mesh*/
	IntID getLevel(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
protected:
	SubdivCollapse(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVCOLLAPSE_H__
