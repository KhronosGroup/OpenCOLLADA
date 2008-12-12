/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMBEND_H__
#define __MayaDM_DEFORMBEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
/*
This node provides a deformation function for the bend deformation and
 stores the attributes specifically related to it.  For more information
 on using this node, see the parent class documentation.
 <p/>
*/
class DeformBend : public DeformFunc
{
public:
public:
	DeformBend(FILE* file,const std::string& name,const std::string& parent=""):DeformFunc(file, name, parent, "deformBend"){}
	virtual ~DeformBend(){}
	/*Low bound of the deformation*/
	void setLowBound(double lb){if(lb == -1.0) return; fprintf_s(mFile, "setAttr \".lb\" %f;\n", lb);}
	/*Low bound of the deformation*/
	void setLowBound(const DoubleID& lb){fprintf_s(mFile,"connectAttr \"");lb.write(mFile);fprintf_s(mFile,"\" \"%s.lb\";\n",mName.c_str());}
	/*High bound of the deformation*/
	void setHighBound(double hb){if(hb == 1.0) return; fprintf_s(mFile, "setAttr \".hb\" %f;\n", hb);}
	/*High bound of the deformation*/
	void setHighBound(const DoubleID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.hb\";\n",mName.c_str());}
	/*The bending curvature*/
	void setCurvature(double cur){if(cur == 0.0) return; fprintf_s(mFile, "setAttr \".cur\" %f;\n", cur);}
	/*The bending curvature*/
	void setCurvature(const DoubleID& cur){fprintf_s(mFile,"connectAttr \"");cur.write(mFile);fprintf_s(mFile,"\" \"%s.cur\";\n",mName.c_str());}
	/*Low bound of the deformation*/
	DoubleID getLowBound(){char buffer[4096];sprintf_s (buffer, "%s.lb",mName.c_str());return (const char*)buffer;}
	/*High bound of the deformation*/
	DoubleID getHighBound(){char buffer[4096];sprintf_s (buffer, "%s.hb",mName.c_str());return (const char*)buffer;}
	/*The bending curvature*/
	DoubleID getCurvature(){char buffer[4096];sprintf_s (buffer, "%s.cur",mName.c_str());return (const char*)buffer;}
protected:
	DeformBend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DeformFunc(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMBEND_H__
