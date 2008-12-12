/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERLAYERMANAGER_H__
#define __MayaDM_RENDERLAYERMANAGER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> The render layer manager node manages the list of render layers currently
 available, including keeping track which one is the current one, and
 enforcing a unique number per render layer.

 The current render layer is the one whos number matches the "current"
 input attribute's value.  It is an error to have no match, although this
 condition will default the current render layer to the default layer.

 The default layer is always number 0, and is always connected at
 multi-index 0 of the 'renderLayers' multi-attribute.  Other render layers
 are connected in order of their compositing priority
</pre></p>
*/
class RenderLayerManager : public DependNode
{
public:
public:
	RenderLayerManager(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "renderLayerManager"){}
	virtual ~RenderLayerManager(){}
	/*Number of the render layer that is the "current" one*/
	void setCurrentRenderLayer(short crl){if(crl == 0) return; fprintf_s(mFile, "setAttr \".crl\" %i;\n", crl);}
	/*Number of the render layer that is the "current" one*/
	void setCurrentRenderLayer(const ShortID& crl){fprintf_s(mFile,"connectAttr \"");crl.write(mFile);fprintf_s(mFile,"\" \"%s.crl\";\n",mName.c_str());}
	/*Render layer id.  Connections here indicate render layer existence.*/
	void setRenderLayerId(size_t rlmi_i,short rlmi){if(rlmi == 0) return; fprintf_s(mFile, "setAttr \".rlmi[%i]\" %i;\n", rlmi_i,rlmi);}
	/*Render layer id.  Connections here indicate render layer existence.*/
	void setRenderLayerId(size_t rlmi_i,const ShortID& rlmi){fprintf_s(mFile,"connectAttr \"");rlmi.write(mFile);fprintf_s(mFile,"\" \"%s.rlmi[%i]\";\n",mName.c_str(),rlmi_i);}
	/*Number of the render layer that is the "current" one*/
	ShortID getCurrentRenderLayer(){char buffer[4096];sprintf_s (buffer, "%s.crl",mName.c_str());return (const char*)buffer;}
	/*Render layer id.  Connections here indicate render layer existence.*/
	const ShortID& getRenderLayerId(size_t rlmi_i){char buffer[4096];sprintf_s (buffer, "%s.rlmi[%i]",mName.c_str(),rlmi_i);return (const char*)buffer;}
protected:
	RenderLayerManager(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RENDERLAYERMANAGER_H__
