/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HIKGROUNDPLANE_H__
#define __MayaDM_HIKGROUNDPLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
<p><pre>
 The hikGroundPlane node can be used to tell Human IK where the ground plane

</pre></p>
*/
class HikGroundPlane : public Transform
{
public:
public:
	HikGroundPlane(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "hikGroundPlane"){}
	virtual ~HikGroundPlane(){}
	/*Draw length for the ground plane.*/
	void setLength(double leng){if(leng == 1.0) return; fprintf_s(mFile, "setAttr \".leng\" %f;\n", leng);}
	/*Draw length for the ground plane.*/
	void setLength(const DoubleID& leng){fprintf_s(mFile,"connectAttr \"");leng.write(mFile);fprintf_s(mFile,"\" \"%s.leng\";\n",mName.c_str());}
	/*Draw length for the ground plane.*/
	DoubleID getLength(){char buffer[4096];sprintf_s (buffer, "%s.leng",mName.c_str());return (const char*)buffer;}
protected:
	HikGroundPlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HIKGROUNDPLANE_H__
