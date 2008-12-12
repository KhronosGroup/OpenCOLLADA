/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMFLARE_H__
#define __MayaDM_DEFORMFLARE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
/*
This node provides a deformation function for the flare deformation and
 stores the attributes specifically related to it.  For more information
 on using this node, see the parent class documentation.
 <p/>
*/
class DeformFlare : public DeformFunc
{
public:
public:
	DeformFlare(FILE* file,const std::string& name,const std::string& parent=""):DeformFunc(file, name, parent, "deformFlare"){}
	virtual ~DeformFlare(){}
	/*Low bound of deformation*/
	void setLowBound(double lb){if(lb == -1.0) return; fprintf_s(mFile, "setAttr \".lb\" %f;\n", lb);}
	/*Low bound of deformation*/
	void setLowBound(const DoubleID& lb){fprintf_s(mFile,"connectAttr \"");lb.write(mFile);fprintf_s(mFile,"\" \"%s.lb\";\n",mName.c_str());}
	/*High bound of deformation*/
	void setHighBound(double hb){if(hb == 1.0) return; fprintf_s(mFile, "setAttr \".hb\" %f;\n", hb);}
	/*High bound of deformation*/
	void setHighBound(const DoubleID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.hb\";\n",mName.c_str());}
	/*Flare amount at the low bound along the X axis*/
	void setStartFlareX(double sfx){if(sfx == 1.0) return; fprintf_s(mFile, "setAttr \".sfx\" %f;\n", sfx);}
	/*Flare amount at the low bound along the X axis*/
	void setStartFlareX(const DoubleID& sfx){fprintf_s(mFile,"connectAttr \"");sfx.write(mFile);fprintf_s(mFile,"\" \"%s.sfx\";\n",mName.c_str());}
	/*Flare amount at the low bound along the Z axis*/
	void setStartFlareZ(double sfz){if(sfz == 1.0) return; fprintf_s(mFile, "setAttr \".sfz\" %f;\n", sfz);}
	/*Flare amount at the low bound along the Z axis*/
	void setStartFlareZ(const DoubleID& sfz){fprintf_s(mFile,"connectAttr \"");sfz.write(mFile);fprintf_s(mFile,"\" \"%s.sfz\";\n",mName.c_str());}
	/*Flare amount at the high bound along the X axis*/
	void setEndFlareX(double efx){if(efx == 1.0) return; fprintf_s(mFile, "setAttr \".efx\" %f;\n", efx);}
	/*Flare amount at the high bound along the X axis*/
	void setEndFlareX(const DoubleID& efx){fprintf_s(mFile,"connectAttr \"");efx.write(mFile);fprintf_s(mFile,"\" \"%s.efx\";\n",mName.c_str());}
	/*Flare amount at the high bound along the Z axis*/
	void setEndFlareZ(double efz){if(efz == 1.0) return; fprintf_s(mFile, "setAttr \".efz\" %f;\n", efz);}
	/*Flare amount at the high bound along the Z axis*/
	void setEndFlareZ(const DoubleID& efz){fprintf_s(mFile,"connectAttr \"");efz.write(mFile);fprintf_s(mFile,"\" \"%s.efz\";\n",mName.c_str());}
	/*Curvature of the flare*/
	void setCurve(double crv){if(crv == 0.0) return; fprintf_s(mFile, "setAttr \".crv\" %f;\n", crv);}
	/*Curvature of the flare*/
	void setCurve(const DoubleID& crv){fprintf_s(mFile,"connectAttr \"");crv.write(mFile);fprintf_s(mFile,"\" \"%s.crv\";\n",mName.c_str());}
	/*Low bound of deformation*/
	DoubleID getLowBound(){char buffer[4096];sprintf_s (buffer, "%s.lb",mName.c_str());return (const char*)buffer;}
	/*High bound of deformation*/
	DoubleID getHighBound(){char buffer[4096];sprintf_s (buffer, "%s.hb",mName.c_str());return (const char*)buffer;}
	/*Flare amount at the low bound along the X axis*/
	DoubleID getStartFlareX(){char buffer[4096];sprintf_s (buffer, "%s.sfx",mName.c_str());return (const char*)buffer;}
	/*Flare amount at the low bound along the Z axis*/
	DoubleID getStartFlareZ(){char buffer[4096];sprintf_s (buffer, "%s.sfz",mName.c_str());return (const char*)buffer;}
	/*Flare amount at the high bound along the X axis*/
	DoubleID getEndFlareX(){char buffer[4096];sprintf_s (buffer, "%s.efx",mName.c_str());return (const char*)buffer;}
	/*Flare amount at the high bound along the Z axis*/
	DoubleID getEndFlareZ(){char buffer[4096];sprintf_s (buffer, "%s.efz",mName.c_str());return (const char*)buffer;}
	/*Curvature of the flare*/
	DoubleID getCurve(){char buffer[4096];sprintf_s (buffer, "%s.crv",mName.c_str());return (const char*)buffer;}
protected:
	DeformFlare(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DeformFunc(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMFLARE_H__
