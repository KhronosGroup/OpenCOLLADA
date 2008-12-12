/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSMOOTH_H__
#define __MayaDM_POLYSMOOTH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
This node has been phased out and replaced by the
 polySmoothFacet node. It remains for backwards
 compatibility only.<p/>
*/
class PolySmooth : public PolyModifier
{
public:
public:
	PolySmooth(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polySmooth"){}
	virtual ~PolySmooth(){}
	/*The smoothness parameter.*/
	void setSmoothness(short sm){if(sm == 1) return; fprintf_s(mFile, "setAttr \".sm\" %i;\n", sm);}
	/*The smoothness parameter.*/
	void setSmoothness(const ShortID& sm){fprintf_s(mFile,"connectAttr \"");sm.write(mFile);fprintf_s(mFile,"\" \"%s.sm\";\n",mName.c_str());}
	/*The smoothness parameter.*/
	ShortID getSmoothness(){char buffer[4096];sprintf_s (buffer, "%s.sm",mName.c_str());return (const char*)buffer;}
protected:
	PolySmooth(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSMOOTH_H__
