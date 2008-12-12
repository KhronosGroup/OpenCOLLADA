/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TOONLINEATTRIBUTES_H__
#define __MayaDM_TOONLINEATTRIBUTES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Toon Line Attributes</b> is a simple attribute collection node. It does not compute
 anything directly, but simply hold attributes that are connected to toon line offset surfaces.
*/
class ToonLineAttributes : public DependNode
{
public:
public:
	ToonLineAttributes(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "toonLineAttributes"){}
	virtual ~ToonLineAttributes(){}
	/*This is the general width for lines created by offset surfaces.*/
	void setLineWidth(float lwd){if(lwd == 1) return; fprintf_s(mFile, "setAttr \".lwd\" %f;\n", lwd);}
	/*This is the general width for lines created by offset surfaces.*/
	void setLineWidth(const FloatID& lwd){fprintf_s(mFile,"connectAttr \"");lwd.write(mFile);fprintf_s(mFile,"\" \"%s.lwd\";\n",mName.c_str());}
	/*Toggle for visibility on offset toonline surfaces.*/
	void setLineVisibility(bool lv){if(lv == true) return; fprintf_s(mFile, "setAttr \".lv\" %i;\n", lv);}
	/*Toggle for visibility on offset toonline surfaces.*/
	void setLineVisibility(const BoolID& lv){fprintf_s(mFile,"connectAttr \"");lv.write(mFile);fprintf_s(mFile,"\" \"%s.lv\";\n",mName.c_str());}
	/*
	Toggle for view based updating on offset toonline surfaces. This
	updating happens when lines are fixed in size in screenspace and the
	camera position changes. Turning it off will speed up tumbling the view.
	*/
	void setViewUpdate(unsigned int vu){if(vu == 1) return; fprintf_s(mFile, "setAttr \".vu\" %i;\n", vu);}
	/*
	Toggle for view based updating on offset toonline surfaces. This
	updating happens when lines are fixed in size in screenspace and the
	camera position changes. Turning it off will speed up tumbling the view.
	*/
	void setViewUpdate(const UnsignedintID& vu){fprintf_s(mFile,"connectAttr \"");vu.write(mFile);fprintf_s(mFile,"\" \"%s.vu\";\n",mName.c_str());}
	/*This is the general width for lines created by offset surfaces.*/
	FloatID getLineWidth(){char buffer[4096];sprintf_s (buffer, "%s.lwd",mName.c_str());return (const char*)buffer;}
	/*Toggle for visibility on offset toonline surfaces.*/
	BoolID getLineVisibility(){char buffer[4096];sprintf_s (buffer, "%s.lv",mName.c_str());return (const char*)buffer;}
	/*
	Toggle for view based updating on offset toonline surfaces. This
	updating happens when lines are fixed in size in screenspace and the
	camera position changes. Turning it off will speed up tumbling the view.
	*/
	UnsignedintID getViewUpdate(){char buffer[4096];sprintf_s (buffer, "%s.vu",mName.c_str());return (const char*)buffer;}
protected:
	ToonLineAttributes(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TOONLINEATTRIBUTES_H__
