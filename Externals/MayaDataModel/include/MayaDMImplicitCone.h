/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IMPLICITCONE_H__
#define __MayaDM_IMPLICITCONE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
/*
<p><pre>
 This contains the shape for the spot light's fog.

</pre></p>
*/
class ImplicitCone : public GeometryShape
{
public:
public:
	ImplicitCone(FILE* file,const std::string& name,const std::string& parent=""):GeometryShape(file, name, parent, "implicitCone"){}
	virtual ~ImplicitCone(){}
	/*node type is a cone*/
	void setCone(const GeometryID& cn){fprintf_s(mFile,"connectAttr \"");cn.write(mFile);fprintf_s(mFile,"\" \"%s.cn\";\n",mName.c_str());}
	/*default is 40 degree*/
	void setConeAngle(double ca){if(ca == 4) return; fprintf_s(mFile, "setAttr \".ca\" %f;\n", ca);}
	/*default is 40 degree*/
	void setConeAngle(const DoubleID& ca){fprintf_s(mFile,"connectAttr \"");ca.write(mFile);fprintf_s(mFile,"\" \"%s.ca\";\n",mName.c_str());}
	/*cone length to define a truncated cone*/
	void setConeCap(double cap){if(cap == 10.0) return; fprintf_s(mFile, "setAttr \".cap\" %f;\n", cap);}
	/*cone length to define a truncated cone*/
	void setConeCap(const DoubleID& cap){fprintf_s(mFile,"connectAttr \"");cap.write(mFile);fprintf_s(mFile,"\" \"%s.cap\";\n",mName.c_str());}
	/*node type is a cone*/
	GeometryID getCone(){char buffer[4096];sprintf_s (buffer, "%s.cn",mName.c_str());return (const char*)buffer;}
	/*default is 40 degree*/
	DoubleID getConeAngle(){char buffer[4096];sprintf_s (buffer, "%s.ca",mName.c_str());return (const char*)buffer;}
	/*cone length to define a truncated cone*/
	DoubleID getConeCap(){char buffer[4096];sprintf_s (buffer, "%s.cap",mName.c_str());return (const char*)buffer;}
protected:
	ImplicitCone(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IMPLICITCONE_H__
