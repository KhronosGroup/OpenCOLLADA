/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISPLAYLAYERMANAGER_H__
#define __MayaDM_DISPLAYLAYERMANAGER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> The display layer manager node manages the list of display layers currently
 available, including keeping track which one is the current one, and
 enforcing a unique number per display layer.

 The current display layer is the one whos number matches the "current"
 input attribute's value.  It is an error to have no match, although this
 condition will default the current display layer to the default layer.

 The default layer is always number 0, and is always connected at
 multi-index 0 of the 'displayLayers' multi-attribute.  Other display layers
 are connected in order of their priority (which is currently only used for
 the layerbar display ordering).
</pre></p>
*/
class DisplayLayerManager : public DependNode
{
public:
public:
	DisplayLayerManager(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "displayLayerManager"){}
	virtual ~DisplayLayerManager(){}
	/*Number of the display layer that is the "current" one*/
	void setCurrentDisplayLayer(short cdl){if(cdl == 0) return; fprintf_s(mFile, "setAttr \".cdl\" %i;\n", cdl);}
	/*Number of the display layer that is the "current" one*/
	void setCurrentDisplayLayer(const ShortID& cdl){fprintf_s(mFile,"connectAttr \"");cdl.write(mFile);fprintf_s(mFile,"\" \"%s.cdl\";\n",mName.c_str());}
	/*Display layer id.  Connections here indicate display layer existence.*/
	void setDisplayLayerId(size_t dli_i,short dli){if(dli == 0) return; fprintf_s(mFile, "setAttr \".dli[%i]\" %i;\n", dli_i,dli);}
	/*Display layer id.  Connections here indicate display layer existence.*/
	void setDisplayLayerId(size_t dli_i,const ShortID& dli){fprintf_s(mFile,"connectAttr \"");dli.write(mFile);fprintf_s(mFile,"\" \"%s.dli[%i]\";\n",mName.c_str(),dli_i);}
	/*Number of the display layer that is the "current" one*/
	ShortID getCurrentDisplayLayer(){char buffer[4096];sprintf_s (buffer, "%s.cdl",mName.c_str());return (const char*)buffer;}
	/*Display layer id.  Connections here indicate display layer existence.*/
	const ShortID& getDisplayLayerId(size_t dli_i){char buffer[4096];sprintf_s (buffer, "%s.dli[%i]",mName.c_str(),dli_i);return (const char*)buffer;}
protected:
	DisplayLayerManager(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DISPLAYLAYERMANAGER_H__
