/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMSINE_H__
#define __MayaDM_DEFORMSINE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
/*
This node provides a deformation function for the sine deformation and
 stores the attributes specifically related to it.  For more information
 on using this node, see the parent class documentation.
 <p/>
*/
class DeformSine : public DeformFunc
{
public:
public:
	DeformSine(FILE* file,const std::string& name,const std::string& parent=""):DeformFunc(file, name, parent, "deformSine"){}
	virtual ~DeformSine(){}
	/*Low bound of the deformation*/
	void setLowBound(double lb){if(lb == -1.0) return; fprintf_s(mFile, "setAttr \".lb\" %f;\n", lb);}
	/*Low bound of the deformation*/
	void setLowBound(const DoubleID& lb){fprintf_s(mFile,"connectAttr \"");lb.write(mFile);fprintf_s(mFile,"\" \"%s.lb\";\n",mName.c_str());}
	/*High bound of the deformation*/
	void setHighBound(double hb){if(hb == 1.0) return; fprintf_s(mFile, "setAttr \".hb\" %f;\n", hb);}
	/*High bound of the deformation*/
	void setHighBound(const DoubleID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.hb\";\n",mName.c_str());}
	/*Sine wave amplitude*/
	void setAmplitude(double amp){if(amp == 0.0) return; fprintf_s(mFile, "setAttr \".amp\" %f;\n", amp);}
	/*Sine wave amplitude*/
	void setAmplitude(const DoubleID& amp){fprintf_s(mFile,"connectAttr \"");amp.write(mFile);fprintf_s(mFile,"\" \"%s.amp\";\n",mName.c_str());}
	/*Sine wave wavelength*/
	void setWavelength(double wav){if(wav == 2.0) return; fprintf_s(mFile, "setAttr \".wav\" %f;\n", wav);}
	/*Sine wave wavelength*/
	void setWavelength(const DoubleID& wav){fprintf_s(mFile,"connectAttr \"");wav.write(mFile);fprintf_s(mFile,"\" \"%s.wav\";\n",mName.c_str());}
	/*Attenuation of the sine wave amplitude*/
	void setDropoff(double dr){if(dr == 0.0) return; fprintf_s(mFile, "setAttr \".dr\" %f;\n", dr);}
	/*Attenuation of the sine wave amplitude*/
	void setDropoff(const DoubleID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr\";\n",mName.c_str());}
	/*Offset of the sine wave*/
	void setOffset(double off){if(off == 0.0) return; fprintf_s(mFile, "setAttr \".off\" %f;\n", off);}
	/*Offset of the sine wave*/
	void setOffset(const DoubleID& off){fprintf_s(mFile,"connectAttr \"");off.write(mFile);fprintf_s(mFile,"\" \"%s.off\";\n",mName.c_str());}
	/*Low bound of the deformation*/
	DoubleID getLowBound(){char buffer[4096];sprintf_s (buffer, "%s.lb",mName.c_str());return (const char*)buffer;}
	/*High bound of the deformation*/
	DoubleID getHighBound(){char buffer[4096];sprintf_s (buffer, "%s.hb",mName.c_str());return (const char*)buffer;}
	/*Sine wave amplitude*/
	DoubleID getAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.amp",mName.c_str());return (const char*)buffer;}
	/*Sine wave wavelength*/
	DoubleID getWavelength(){char buffer[4096];sprintf_s (buffer, "%s.wav",mName.c_str());return (const char*)buffer;}
	/*Attenuation of the sine wave amplitude*/
	DoubleID getDropoff(){char buffer[4096];sprintf_s (buffer, "%s.dr",mName.c_str());return (const char*)buffer;}
	/*Offset of the sine wave*/
	DoubleID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.off",mName.c_str());return (const char*)buffer;}
protected:
	DeformSine(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DeformFunc(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMSINE_H__
