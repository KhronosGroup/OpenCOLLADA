/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CACHEBASE_H__
#define __MayaDM_CACHEBASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
 The cacheBase node is an abstract node that serves as the base class
 for caching-related operations.


</pre></p>
*/
class CacheBase : public DependNode
{
public:
public:
	CacheBase(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "cacheBase"){}
	virtual ~CacheBase(){}
	/*The vector array read from disk for this frame for the associated channel.*/
	void setOutCacheData(size_t ocd_i,const GenericID& ocd){fprintf_s(mFile,"connectAttr \"");ocd.write(mFile);fprintf_s(mFile,"\" \"%s.ocd[%i]\";\n",mName.c_str(),ocd_i);}
	/*
	Returns true if the currentTime is within the start and end of the
	cache.
	*/
	void setInRange(const BoolID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.ir\";\n",mName.c_str());}
	/*The vector array read from disk for this frame for the associated channel.*/
	const GenericID& getOutCacheData(size_t ocd_i){char buffer[4096];sprintf_s (buffer, "%s.ocd[%i]",mName.c_str(),ocd_i);return (const char*)buffer;}
	/*
	Returns true if the currentTime is within the start and end of the
	cache.
	*/
	BoolID getInRange(){char buffer[4096];sprintf_s (buffer, "%s.ir",mName.c_str());return (const char*)buffer;}
protected:
	CacheBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CACHEBASE_H__
