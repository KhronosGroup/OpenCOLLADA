/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMBLEND_H__
#define __MayaDM_ANIMBLEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
A base node used in blending between two clips. The nodes deriving from this
one actually perform the blend.
*/
class AnimBlend : public DependNode
{
public:
public:
	AnimBlend(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "animBlend"){}
	virtual ~AnimBlend(){}
	/*
	The function attribute that is used to pass data used in the blend.
	A connection between an element in the blendList multi on the
	clipScheduler node is made to the _Raw attribute that is a child
	of this attribute.
	*/
	void setBlend(const FunctionID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*
	The weight attribute is used to determine what influence a clip has
	during the blend. If the weight is 0.0, then the first clip in the
	blend has all of the influence. If the weight is 1.0, then the second
	clip is the only one used. How the influence is calculated for other
	values is up to the specific blend node.
	Only the values between times 0.0 and 1.0 will be used by the blend.
	The blend node will calculate how far along the blend it is and get
	the corresponding weight between the times 0.0 and 1.0.
	*/
	void setWeight(double w){if(w == 0.0) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*
	The weight attribute is used to determine what influence a clip has
	during the blend. If the weight is 0.0, then the first clip in the
	blend has all of the influence. If the weight is 1.0, then the second
	clip is the only one used. How the influence is calculated for other
	values is up to the specific blend node.
	Only the values between times 0.0 and 1.0 will be used by the blend.
	The blend node will calculate how far along the blend it is and get
	the corresponding weight between the times 0.0 and 1.0.
	*/
	void setWeight(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*
	The function attribute that is used to pass data used in the blend.
	A connection between an element in the blendList multi on the
	clipScheduler node is made to the _Raw attribute that is a child
	of this attribute.
	*/
	FunctionID getBlend(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*
	The weight attribute is used to determine what influence a clip has
	during the blend. If the weight is 0.0, then the first clip in the
	blend has all of the influence. If the weight is 1.0, then the second
	clip is the only one used. How the influence is calculated for other
	values is up to the specific blend node.
	Only the values between times 0.0 and 1.0 will be used by the blend.
	The blend node will calculate how far along the blend it is and get
	the corresponding weight between the times 0.0 and 1.0.
	*/
	DoubleID getWeight(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
protected:
	AnimBlend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ANIMBLEND_H__
