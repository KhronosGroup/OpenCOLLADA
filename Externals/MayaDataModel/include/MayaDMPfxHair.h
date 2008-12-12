/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PFXHAIR_H__
#define __MayaDM_PFXHAIR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPfxGeometry.h"
namespace MayaDM
{
/*
<p><pre>
        This node contains attributes
        that are common to all pfx shape nodes.
        It cannot be used directly, but rather should be derived from.

</pre></p>
*/
class PfxHair : public PfxGeometry
{
public:
public:
	PfxHair(FILE* file,const std::string& name,const std::string& parent=""):PfxGeometry(file, name, parent, "pfxHair"){}
	virtual ~PfxHair(){}
	/*Input from brush node*/
	void setRenderHairs(const HairRenderInfoID& rhs){fprintf_s(mFile,"connectAttr \"");rhs.write(mFile);fprintf_s(mFile,"\" \"%s.rhs\";\n",mName.c_str());}
	/*Input from brush node*/
	HairRenderInfoID getRenderHairs(){char buffer[4096];sprintf_s (buffer, "%s.rhs",mName.c_str());return (const char*)buffer;}
protected:
	PfxHair(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PfxGeometry(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PFXHAIR_H__
