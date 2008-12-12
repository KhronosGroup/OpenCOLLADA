/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NONAMBIENTLIGHTSHAPENODE_H__
#define __MayaDM_NONAMBIENTLIGHTSHAPENODE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRenderLight.h"
namespace MayaDM
{
/*
<p><pre>
        This class is the abstract class that describes nonAmbient
        lights.

</pre></p>
*/
class NonAmbientLightShapeNode : public RenderLight
{
public:
public:
	NonAmbientLightShapeNode(FILE* file,const std::string& name,const std::string& parent=""):RenderLight(file, name, parent, "nonAmbientLightShapeNode"){}
	virtual ~NonAmbientLightShapeNode(){}
	/*
	The decay rate with respect to the distance between the
	light and the surface point being shaded.  The decay
	values range from 0 - 3.  The light intensity decays
	according to (I / d ** v), where I is the light intensity,
	d is the distance between the light and the surface point
	being shaded, and v is the decay rate value.  A decay rate
	of 0 means there is no decay in intensity, a value of 1
	indicates linear decay.  A decay rate of 2 is the most
	physically accurate behaviour.
	*/
	void setDecayRate(unsigned int de){if(de == 0) return; fprintf_s(mFile, "setAttr \".de\" %i;\n", de);}
	/*Determine if this light contributes to the diffuse shading.*/
	void setEmitDiffuse(bool edi){if(edi == true) return; fprintf_s(mFile, "setAttr \".edi\" %i;\n", edi);}
	/*Determine if this light contributes to the diffuse shading.*/
	void setEmitDiffuse(const BoolID& edi){fprintf_s(mFile,"connectAttr \"");edi.write(mFile);fprintf_s(mFile,"\" \"%s.edi\";\n",mName.c_str());}
	/*Determine if this light contributes to the specular shading.*/
	void setEmitSpecular(bool esp){if(esp == true) return; fprintf_s(mFile, "setAttr \".esp\" %i;\n", esp);}
	/*Determine if this light contributes to the specular shading.*/
	void setEmitSpecular(const BoolID& esp){fprintf_s(mFile,"connectAttr \"");esp.write(mFile);fprintf_s(mFile,"\" \"%s.esp\";\n",mName.c_str());}
	/*Determine if this light contributes to the diffuse shading.*/
	BoolID getEmitDiffuse(){char buffer[4096];sprintf_s (buffer, "%s.edi",mName.c_str());return (const char*)buffer;}
	/*Determine if this light contributes to the specular shading.*/
	BoolID getEmitSpecular(){char buffer[4096];sprintf_s (buffer, "%s.esp",mName.c_str());return (const char*)buffer;}
protected:
	NonAmbientLightShapeNode(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):RenderLight(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NONAMBIENTLIGHTSHAPENODE_H__
