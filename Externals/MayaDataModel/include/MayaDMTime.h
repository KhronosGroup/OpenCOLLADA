/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TIME_H__
#define __MayaDM_TIME_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    This is the global frame time node.  It manages the flow of time during an
    animation.  There is one time node per graph and the graph gets all of its
    time information from its time node.
</pre></p>
*/
class Time : public DependNode
{
public:
public:
	Time(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "time"){}
	virtual ~Time(){}
	/*Output time.  The current global frame time.*/
	void setOutTime(const TimeID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Output time.  The current global frame time.*/
	TimeID getOutTime(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	Time(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TIME_H__
