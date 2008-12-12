/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AUDIO_H__
#define __MayaDM_AUDIO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node contains information about a sound used in the
 system.  Audio nodes are used for interactive sound scrubbing,
 playback with sound, etc., and can be created
 through the "sound" command.  An audio node contains a path to a sound file
 in AIFF or AIFF-C format, and a start time for the sound.<p/>
*/
class Audio : public DependNode
{
public:
public:
	Audio(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "audio"){}
	virtual ~Audio(){}
	/*The time the sound file begins*/
	void setOffset(const TimeID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The path name to the actual sound file.*/
	void setFilename(const string& f){if(f == "NULL") return; fprintf_s(mFile, "setAttr \".f\" -type \"string\" ");f.write(mFile);fprintf_s(mFile,";\n");}
	/*The path name to the actual sound file.*/
	void setFilename(const StringID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Playback order*/
	void setOrder(int r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %i;\n", r);}
	/*Playback order*/
	void setOrder(const IntID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The time the sound file begins*/
	TimeID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The path name to the actual sound file.*/
	StringID getFilename(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*Playback order*/
	IntID getOrder(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
protected:
	Audio(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_AUDIO_H__
