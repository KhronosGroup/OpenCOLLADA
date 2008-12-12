/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMTWIST_H__
#define __MayaDM_DEFORMTWIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
/*
This node provides a deformation function for the twist deformation and
 stores the attributes specifically related to it.  For more information
 on using this node, see the parent class documentation.
 <p/>
*/
class DeformTwist : public DeformFunc
{
public:
public:
	DeformTwist(FILE* file,const std::string& name,const std::string& parent=""):DeformFunc(file, name, parent, "deformTwist"){}
	virtual ~DeformTwist(){}
	/*Low bound of the deformation*/
	void setLowBound(double lb){if(lb == -1.0) return; fprintf_s(mFile, "setAttr \".lb\" %f;\n", lb);}
	/*Low bound of the deformation*/
	void setLowBound(const DoubleID& lb){fprintf_s(mFile,"connectAttr \"");lb.write(mFile);fprintf_s(mFile,"\" \"%s.lb\";\n",mName.c_str());}
	/*High bound of the deformation*/
	void setHighBound(double hb){if(hb == 1.0) return; fprintf_s(mFile, "setAttr \".hb\" %f;\n", hb);}
	/*High bound of the deformation*/
	void setHighBound(const DoubleID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.hb\";\n",mName.c_str());}
	/*The twist angle at the low bound*/
	void setStartAngle(double sa){if(sa == 0) return; fprintf_s(mFile, "setAttr \".sa\" %f;\n", sa);}
	/*The twist angle at the low bound*/
	void setStartAngle(const DoubleID& sa){fprintf_s(mFile,"connectAttr \"");sa.write(mFile);fprintf_s(mFile,"\" \"%s.sa\";\n",mName.c_str());}
	/*The twist angle at the high bound*/
	void setEndAngle(double ea){if(ea == 0) return; fprintf_s(mFile, "setAttr \".ea\" %f;\n", ea);}
	/*The twist angle at the high bound*/
	void setEndAngle(const DoubleID& ea){fprintf_s(mFile,"connectAttr \"");ea.write(mFile);fprintf_s(mFile,"\" \"%s.ea\";\n",mName.c_str());}
	/*Low bound of the deformation*/
	DoubleID getLowBound(){char buffer[4096];sprintf_s (buffer, "%s.lb",mName.c_str());return (const char*)buffer;}
	/*High bound of the deformation*/
	DoubleID getHighBound(){char buffer[4096];sprintf_s (buffer, "%s.hb",mName.c_str());return (const char*)buffer;}
	/*The twist angle at the low bound*/
	DoubleID getStartAngle(){char buffer[4096];sprintf_s (buffer, "%s.sa",mName.c_str());return (const char*)buffer;}
	/*The twist angle at the high bound*/
	DoubleID getEndAngle(){char buffer[4096];sprintf_s (buffer, "%s.ea",mName.c_str());return (const char*)buffer;}
protected:
	DeformTwist(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DeformFunc(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMTWIST_H__
