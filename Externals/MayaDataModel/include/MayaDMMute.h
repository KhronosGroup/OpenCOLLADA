/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MUTE_H__
#define __MayaDM_MUTE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> This node can be used to mute channels so that they hold their value.
 If mute is enabled, the output is set to the hold value instead of the
 input value. If mute is disabled, the input passes through unchanged.
</pre></p>
*/
class Mute : public DependNode
{
public:
public:
	Mute(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "mute"){}
	virtual ~Mute(){}
	/*Input to be muted*/
	void setInput(const GenericID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Hold value while muted*/
	void setHold(const GenericID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*Hold time when mute is keyed*/
	void setHoldTime(const TimeID& ht){fprintf_s(mFile,"connectAttr \"");ht.write(mFile);fprintf_s(mFile,"\" \"%s.ht\";\n",mName.c_str());}
	/*Mute*/
	void setMute(bool m){if(m == false) return; fprintf_s(mFile, "setAttr \".m\" %i;\n", m);}
	/*Mute*/
	void setMute(const BoolID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*Muted output*/
	void setOutput(const GenericID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Input to be muted*/
	GenericID getInput(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Hold value while muted*/
	GenericID getHold(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*Hold time when mute is keyed*/
	TimeID getHoldTime(){char buffer[4096];sprintf_s (buffer, "%s.ht",mName.c_str());return (const char*)buffer;}
	/*Mute*/
	BoolID getMute(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*Muted output*/
	GenericID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	Mute(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MUTE_H__
