/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POSITIONMARKER_H__
#define __MayaDM_POSITIONMARKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLocator.h"
namespace MayaDM
{
/*
This is the positionMarker node which is a dag object that lives
 in the under world of a curve shape. In the context of motionPath
 animation, a positionMarker represents a keyframe stored in the
 animCurve connected to the uValue attribute of the motionPath node
 connected to this positionMarker.<p/>

 The position of a positionMarker (with respect to the parent geometry)
 is stored in its parentclass. The positionMarker contains information
 about time assigned to it.<p/>

 When the position or the time of a positionMarker is changed,
 the corresponding keyframe will be updated, and vice versa.<p/>

 When a positionMarker is disconnected from the motionPath node,
 its corresponding keyframe will be removed as well.<p/>
*/
class PositionMarker : public Locator
{
public:
public:
	PositionMarker(FILE* file,const std::string& name,const std::string& parent=""):Locator(file, name, parent, "positionMarker"){}
	virtual ~PositionMarker(){}
	/*time of this positionMarker*/
	void setTime(const TimeID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*time of this positionMarker*/
	TimeID getTime(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
protected:
	PositionMarker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Locator(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POSITIONMARKER_H__
