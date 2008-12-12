/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ORIENTATIONMARKER_H__
#define __MayaDM_ORIENTATIONMARKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPositionMarker.h"
namespace MayaDM
{
/*
This is the orientationMarker node which is a dag object that lives
 in the under world of a curve shape. In the context of motionPath
 animation, an orientationMarker represents 3 keyframes stored in the
 animCurves connected to the frontTwist, upTwist, and sideTwist
 attributes of the motionPath node connected to this orientationMarker.<p/>

 The position of an orientationMarker (with respect to the parent geometry)
 and the time assigned to it are stored in its parentclass.
 The orientationMarker contains information about twist angles
 assigned to it.<p/>

 When one of the twist angles or the time of an orientationMarker
 is changed, the corresponding keyframe will be updated, and vice versa.<p/>

 When an orientationMarker is disconnected from the motionPath node,
 its corresponding keyframes will be removed as well.<p/>
*/
class OrientationMarker : public PositionMarker
{
public:
public:
	OrientationMarker(FILE* file,const std::string& name,const std::string& parent=""):PositionMarker(file, name, parent, "orientationMarker"){}
	virtual ~OrientationMarker(){}
	/*angle of rotation about the FRONT direction*/
	void setFrontTwist(double ft){if(ft == 0) return; fprintf_s(mFile, "setAttr \".ft\" %f;\n", ft);}
	/*angle of rotation about the FRONT direction*/
	void setFrontTwist(const DoubleID& ft){fprintf_s(mFile,"connectAttr \"");ft.write(mFile);fprintf_s(mFile,"\" \"%s.ft\";\n",mName.c_str());}
	/*angle of rotation about the UP direction*/
	void setUpTwist(double ut){if(ut == 0) return; fprintf_s(mFile, "setAttr \".ut\" %f;\n", ut);}
	/*angle of rotation about the UP direction*/
	void setUpTwist(const DoubleID& ut){fprintf_s(mFile,"connectAttr \"");ut.write(mFile);fprintf_s(mFile,"\" \"%s.ut\";\n",mName.c_str());}
	/*angle of rotation about the SIDE direction*/
	void setSideTwist(double st){if(st == 0) return; fprintf_s(mFile, "setAttr \".st\" %f;\n", st);}
	/*angle of rotation about the SIDE direction*/
	void setSideTwist(const DoubleID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*angle of rotation about the FRONT direction*/
	DoubleID getFrontTwist(){char buffer[4096];sprintf_s (buffer, "%s.ft",mName.c_str());return (const char*)buffer;}
	/*angle of rotation about the UP direction*/
	DoubleID getUpTwist(){char buffer[4096];sprintf_s (buffer, "%s.ut",mName.c_str());return (const char*)buffer;}
	/*angle of rotation about the SIDE direction*/
	DoubleID getSideTwist(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
protected:
	OrientationMarker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PositionMarker(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ORIENTATIONMARKER_H__
