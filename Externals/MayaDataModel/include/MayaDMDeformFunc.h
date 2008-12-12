/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMFUNC_H__
#define __MayaDM_DEFORMFUNC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
This node provides the attributes shared in common by all function-based
 deformer handles such as the nonlinear deformer
 handles for  bend, flare, sine, squash, twist and wave.
 <p/>
 The shapes derived from this node serve a dual purpose:
<ul>
 <li> to provide a handle that allows the user to pick the deformer</li>
 <li> to implement a deformation function</li>
</ul>
 The deformerData output of this node should be connected to
 a node that will call the deformation function, such as the nonLinear
 deformation node.
*/
class DeformFunc : public Shape
{
public:
public:
	DeformFunc(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "deformFunc"){}
	virtual ~DeformFunc(){}
	/*
	The array of arguments necessary to perform the deformation function.
	This attribute is connected to the node performing the deformation.
	*/
	void setDeformerData(const doubleArray& dd){if(dd.size == 0) return; fprintf_s(mFile, "setAttr \".dd\" -type \"doubleArray\" ");dd.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The array of arguments necessary to perform the deformation function.
	This attribute is connected to the node performing the deformation.
	*/
	void setDeformerData(const DoubleArrayID& dd){fprintf_s(mFile,"connectAttr \"");dd.write(mFile);fprintf_s(mFile,"\" \"%s.dd\";\n",mName.c_str());}
	/*The width of the handle in world space*/
	void setHandleWidth(double hw){if(hw == 1.0) return; fprintf_s(mFile, "setAttr \".hw\" %f;\n", hw);}
	/*The width of the handle in world space*/
	void setHandleWidth(const DoubleID& hw){fprintf_s(mFile,"connectAttr \"");hw.write(mFile);fprintf_s(mFile,"\" \"%s.hw\";\n",mName.c_str());}
	/*
	The array of arguments necessary to perform the deformation function.
	This attribute is connected to the node performing the deformation.
	*/
	DoubleArrayID getDeformerData(){char buffer[4096];sprintf_s (buffer, "%s.dd",mName.c_str());return (const char*)buffer;}
	/*The width of the handle in world space*/
	DoubleID getHandleWidth(){char buffer[4096];sprintf_s (buffer, "%s.hw",mName.c_str());return (const char*)buffer;}
protected:
	DeformFunc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMFUNC_H__
