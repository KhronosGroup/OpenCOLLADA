/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GLOBALCACHECONTROL_H__
#define __MayaDM_GLOBALCACHECONTROL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> The globalCacheControl node has a control to enable and
 disable all disk caches.  It also keeps track of all the
 disk caches in the scene.
</pre></p>
*/
class GlobalCacheControl : public DependNode
{
public:
public:
	GlobalCacheControl(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "globalCacheControl"){}
	virtual ~GlobalCacheControl(){}
	/*Global control to turn on and off all disk caches*/
	void setEnableStatus(unsigned int ebls){if(ebls == 0) return; fprintf_s(mFile, "setAttr \".ebls\" %i;\n", ebls);}
	/*Global control to turn on and off all disk caches*/
	void setEnableStatus(const UnsignedintID& ebls){fprintf_s(mFile,"connectAttr \"");ebls.write(mFile);fprintf_s(mFile,"\" \"%s.ebls\";\n",mName.c_str());}
	/*
	Flag to tell if we are in writing mode or reading mode
	It is in reading mode all the time except during the
	runup for creation of disk caches.
	*/
	void setWriteEnable(bool webl){if(webl == false) return; fprintf_s(mFile, "setAttr \".webl\" %i;\n", webl);}
	/*
	Flag to tell if we are in writing mode or reading mode
	It is in reading mode all the time except during the
	runup for creation of disk caches.
	*/
	void setWriteEnable(const BoolID& webl){fprintf_s(mFile,"connectAttr \"");webl.write(mFile);fprintf_s(mFile,"\" \"%s.webl\";\n",mName.c_str());}
	/*Global control to turn on and off all disk caches*/
	UnsignedintID getEnableStatus(){char buffer[4096];sprintf_s (buffer, "%s.ebls",mName.c_str());return (const char*)buffer;}
	/*
	Flag to tell if we are in writing mode or reading mode
	It is in reading mode all the time except during the
	runup for creation of disk caches.
	*/
	BoolID getWriteEnable(){char buffer[4096];sprintf_s (buffer, "%s.webl",mName.c_str());return (const char*)buffer;}
protected:
	GlobalCacheControl(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GLOBALCACHECONTROL_H__
