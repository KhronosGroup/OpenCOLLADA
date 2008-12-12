/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RECORD_H__
#define __MayaDM_RECORD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> This node allows recording of changes to an attribute during playback.
 When the play -record command is issued, all record nodes capture
 the value of their target attribute for every frame that Maya displays
 during playback.  When recording stops, this information is turned into
 keyframes.

</pre></p>
*/
class Record : public DependNode
{
public:
public:
	Record(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "record"){}
	virtual ~Record(){}
	/*Input from attribute being recorded*/
	void setInput(double i){if(i == 0.0) return; fprintf_s(mFile, "setAttr \".i\" %f;\n", i);}
protected:
	Record(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RECORD_H__
