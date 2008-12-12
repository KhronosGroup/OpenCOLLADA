/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLEXORSHAPE_H__
#define __MayaDM_FLEXORSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
<p><pre> This node contains information about drivers for Set Driven Keyframe
 behavior on a flexor.  It is also used to gather attributes of interest
 to the flexor, so they can be seen and edited from one central place,
 even if they affect several different nodes used in the flexor's
 deformation (these are added dynamically to the node when the flexor
 is created).
</pre></p>
*/
class FlexorShape : public Shape
{
public:
public:
	FlexorShape(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "flexorShape"){}
	virtual ~FlexorShape(){}
	/*Index of the current driver (or -1 if there is no current driver).*/
	void setCurrentDriver(short cdr){if(cdr == -1) return; fprintf_s(mFile, "setAttr \".cdr\" %i;\n", cdr);}
	/*Index of the current driver (or -1 if there is no current driver).*/
	void setCurrentDriver(const ShortID& cdr){fprintf_s(mFile,"connectAttr \"");cdr.write(mFile);fprintf_s(mFile,"\" \"%s.cdr\";\n",mName.c_str());}
	/*Index of the current driver (or -1 if there is no current driver).*/
	ShortID getCurrentDriver(){char buffer[4096];sprintf_s (buffer, "%s.cdr",mName.c_str());return (const char*)buffer;}
protected:
	FlexorShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FLEXORSHAPE_H__
