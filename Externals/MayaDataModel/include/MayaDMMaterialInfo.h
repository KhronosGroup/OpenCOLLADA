/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MATERIALINFO_H__
#define __MayaDM_MATERIALINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
  Dependency node for hardware shading material information.

</pre></p>
*/
class MaterialInfo : public DependNode
{
public:
public:
	MaterialInfo(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "materialInfo"){}
	virtual ~MaterialInfo(){}
	/*Connection to shading engine group to monitor.*/
	void setShadingGroup(const MessageID& sg){fprintf_s(mFile,"connectAttr \"");sg.write(mFile);fprintf_s(mFile,"\" \"%s.sg\";\n",mName.c_str());}
	/*Connection to material to monitor.*/
	void setMaterial(const MessageID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*
	Connection to the texture plug to sample. In most cases, the
	outColor attribute will be used; but by connecting the desired plug
	(for example, file1.outColor) to this attribute you can override
	which attribute materialInfo will sample.
	*/
	void setTextureChannel(const MessageID& tc){fprintf_s(mFile,"connectAttr \"");tc.write(mFile);fprintf_s(mFile,"\" \"%s.tc\";\n",mName.c_str());}
	/*
	Returns the name of the plug (for example, file1.outColor) being
	sampled by hardware texturing.
	*/
	void setTexturePlug(const StringID& tp){fprintf_s(mFile,"connectAttr \"");tp.write(mFile);fprintf_s(mFile,"\" \"%s.tp\";\n",mName.c_str());}
	/*
	Specifies the filter type to be applied to the single material on the object.
	Default using the view port defined filter.
	*/
	void setTextureFilter(unsigned int tmip){if(tmip == 0) return; fprintf_s(mFile, "setAttr \".tmip\" %i;\n", tmip);}
	/*
	Specifies the filter type to be applied to the single material on the object.
	Default using the view port defined filter.
	*/
	void setTextureFilter(const UnsignedintID& tmip){fprintf_s(mFile,"connectAttr \"");tmip.write(mFile);fprintf_s(mFile,"\" \"%s.tmip\";\n",mName.c_str());}
	/*Connection to shading engine group to monitor.*/
	MessageID getShadingGroup(){char buffer[4096];sprintf_s (buffer, "%s.sg",mName.c_str());return (const char*)buffer;}
	/*Connection to material to monitor.*/
	MessageID getMaterial(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*
	Connection to the texture plug to sample. In most cases, the
	outColor attribute will be used; but by connecting the desired plug
	(for example, file1.outColor) to this attribute you can override
	which attribute materialInfo will sample.
	*/
	MessageID getTextureChannel(){char buffer[4096];sprintf_s (buffer, "%s.tc",mName.c_str());return (const char*)buffer;}
	/*
	Returns the name of the plug (for example, file1.outColor) being
	sampled by hardware texturing.
	*/
	StringID getTexturePlug(){char buffer[4096];sprintf_s (buffer, "%s.tp",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the filter type to be applied to the single material on the object.
	Default using the view port defined filter.
	*/
	UnsignedintID getTextureFilter(){char buffer[4096];sprintf_s (buffer, "%s.tmip",mName.c_str());return (const char*)buffer;}
protected:
	MaterialInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MATERIALINFO_H__
