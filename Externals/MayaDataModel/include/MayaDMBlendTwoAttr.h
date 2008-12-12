/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDTWOATTR_H__
#define __MayaDM_BLENDTWOATTR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBlend.h"
namespace MayaDM
{
/*
<p><pre>
    The blendTwoAttr node blends the values of the input(0) and input(1)
    attributes of the node using a blending function specified by the
    attributesBlender attribute. The value of the output attribute of
    this blend node is computed by:

    output = (1 - attributesBlender) * input(0)  +  attributesBlender * input(1)

</pre></p>
*/
class BlendTwoAttr : public Blend
{
public:
public:
	BlendTwoAttr(FILE* file,const std::string& name,const std::string& parent=""):Blend(file, name, parent, "blendTwoAttr"){}
	virtual ~BlendTwoAttr(){}
	/*blend function controlling how much to blend of each of 2 inputs*/
	void setAttributesBlender(float ab){if(ab == 0.0) return; fprintf_s(mFile, "setAttr \".ab\" %f;\n", ab);}
	/*blend function controlling how much to blend of each of 2 inputs*/
	void setAttributesBlender(const FloatID& ab){fprintf_s(mFile,"connectAttr \"");ab.write(mFile);fprintf_s(mFile,"\" \"%s.ab\";\n",mName.c_str());}
	/*blend function controlling how much to blend of each of 2 inputs*/
	FloatID getAttributesBlender(){char buffer[4096];sprintf_s (buffer, "%s.ab",mName.c_str());return (const char*)buffer;}
protected:
	BlendTwoAttr(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Blend(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BLENDTWOATTR_H__
