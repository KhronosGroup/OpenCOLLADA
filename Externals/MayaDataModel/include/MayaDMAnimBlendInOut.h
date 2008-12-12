/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMBLENDINOUT_H__
#define __MayaDM_ANIMBLENDINOUT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAnimBlend.h"
namespace MayaDM
{
/*
This node is used to blend between one clip to another. Rotations are
        handled differently than other types of channels.

        The rotateBlend attribute determines how rotations are handled.
        There are three different ways to blend rotations:
        Quaternion Short is the shortest path between the rotations in
        quaternion space. Quaternion Long takes a longer path between
        the channels being blended. Linear causes the rotations to be
        blended like the other channels. Both quaternion blend types use
        slerp.

        The other channel types are linearly interpolated with the weight attribute
        determining how the interpolation progreses. If the weight is 0.0, then
        the first clip is used. Likewise if the weight is 1.0, then the second
        clip is used.

<p/>
The formula used by the linear interpolation is: o
clip1 + (clip2 - clip1)*weight.
*/
class AnimBlendInOut : public AnimBlend
{
public:
public:
	AnimBlendInOut(FILE* file,const std::string& name,const std::string& parent=""):AnimBlend(file, name, parent, "animBlendInOut"){}
	virtual ~AnimBlendInOut(){}
	/*An Enum to set the interpolation used by the rotation blend.*/
	void setRotationBlend(unsigned int rb){if(rb == 0) return; fprintf_s(mFile, "setAttr \".rb\" %i;\n", rb);}
	/*An Enum to set the interpolation used by the rotation blend.*/
	void setRotationBlend(const UnsignedintID& rb){fprintf_s(mFile,"connectAttr \"");rb.write(mFile);fprintf_s(mFile,"\" \"%s.rb\";\n",mName.c_str());}
	/*An Enum to set the interpolation used by the rotation blend.*/
	UnsignedintID getRotationBlend(){char buffer[4096];sprintf_s (buffer, "%s.rb",mName.c_str());return (const char*)buffer;}
protected:
	AnimBlendInOut(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AnimBlend(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ANIMBLENDINOUT_H__
