/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISPLACEMENTSHADER_H__
#define __MayaDM_DISPLACEMENTSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
  Intermediate displacement node connecting the shading group
  and the shader/texture.


</pre></p>
*/
class DisplacementShader : public DependNode
{
public:
public:
	DisplacementShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "displacementShader"){}
	virtual ~DisplacementShader(){}
	/*The output displacement value for the current sample*/
	void setDisplacement(float d){if(d == 0.0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*The output displacement value for the current sample*/
	void setDisplacement(const FloatID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The output displacement value for the current sample*/
	FloatID getDisplacement(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
protected:
	DisplacementShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DISPLACEMENTSHADER_H__
