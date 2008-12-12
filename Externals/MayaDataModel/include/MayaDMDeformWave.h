/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMWAVE_H__
#define __MayaDM_DEFORMWAVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
/*
<p><pre>
 This node provides the implemetation of the wave deformation algorithm and
 stores the attributes specifically related to it.

</pre></p>
*/
class DeformWave : public DeformFunc
{
public:
public:
	DeformWave(FILE* file,const std::string& name,const std::string& parent=""):DeformFunc(file, name, parent, "deformWave"){}
	virtual ~DeformWave(){}
	/*Maximum radius of influence*/
	void setMaxRadius(double mxr){if(mxr == 1.0) return; fprintf_s(mFile, "setAttr \".mxr\" %f;\n", mxr);}
	/*Maximum radius of influence*/
	void setMaxRadius(const DoubleID& mxr){fprintf_s(mFile,"connectAttr \"");mxr.write(mFile);fprintf_s(mFile,"\" \"%s.mxr\";\n",mName.c_str());}
	/*Minimum radius of influence*/
	void setMinRadius(double mnr){if(mnr == 0.0) return; fprintf_s(mFile, "setAttr \".mnr\" %f;\n", mnr);}
	/*Minimum radius of influence*/
	void setMinRadius(const DoubleID& mnr){fprintf_s(mFile,"connectAttr \"");mnr.write(mFile);fprintf_s(mFile,"\" \"%s.mnr\";\n",mName.c_str());}
	/*Sine wave amplitude*/
	void setAmplitude(double amp){if(amp == 0.0) return; fprintf_s(mFile, "setAttr \".amp\" %f;\n", amp);}
	/*Sine wave amplitude*/
	void setAmplitude(const DoubleID& amp){fprintf_s(mFile,"connectAttr \"");amp.write(mFile);fprintf_s(mFile,"\" \"%s.amp\";\n",mName.c_str());}
	/*Sine wave wavelength*/
	void setWavelength(double wav){if(wav == 1.0) return; fprintf_s(mFile, "setAttr \".wav\" %f;\n", wav);}
	/*Sine wave wavelength*/
	void setWavelength(const DoubleID& wav){fprintf_s(mFile,"connectAttr \"");wav.write(mFile);fprintf_s(mFile,"\" \"%s.wav\";\n",mName.c_str());}
	/*Attenuation of the sine wave amplitude*/
	void setDropoff(double dr){if(dr == 0.0) return; fprintf_s(mFile, "setAttr \".dr\" %f;\n", dr);}
	/*Attenuation of the sine wave amplitude*/
	void setDropoff(const DoubleID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr\";\n",mName.c_str());}
	/*Relative position of dropoff between the min and the max radius*/
	void setDropoffPosition(double dp){if(dp == 0.0) return; fprintf_s(mFile, "setAttr \".dp\" %f;\n", dp);}
	/*Relative position of dropoff between the min and the max radius*/
	void setDropoffPosition(const DoubleID& dp){fprintf_s(mFile,"connectAttr \"");dp.write(mFile);fprintf_s(mFile,"\" \"%s.dp\";\n",mName.c_str());}
	/*Offset of the wave*/
	void setOffset(double off){if(off == 0.0) return; fprintf_s(mFile, "setAttr \".off\" %f;\n", off);}
	/*Offset of the wave*/
	void setOffset(const DoubleID& off){fprintf_s(mFile,"connectAttr \"");off.write(mFile);fprintf_s(mFile,"\" \"%s.off\";\n",mName.c_str());}
	/*Maximum radius of influence*/
	DoubleID getMaxRadius(){char buffer[4096];sprintf_s (buffer, "%s.mxr",mName.c_str());return (const char*)buffer;}
	/*Minimum radius of influence*/
	DoubleID getMinRadius(){char buffer[4096];sprintf_s (buffer, "%s.mnr",mName.c_str());return (const char*)buffer;}
	/*Sine wave amplitude*/
	DoubleID getAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.amp",mName.c_str());return (const char*)buffer;}
	/*Sine wave wavelength*/
	DoubleID getWavelength(){char buffer[4096];sprintf_s (buffer, "%s.wav",mName.c_str());return (const char*)buffer;}
	/*Attenuation of the sine wave amplitude*/
	DoubleID getDropoff(){char buffer[4096];sprintf_s (buffer, "%s.dr",mName.c_str());return (const char*)buffer;}
	/*Relative position of dropoff between the min and the max radius*/
	DoubleID getDropoffPosition(){char buffer[4096];sprintf_s (buffer, "%s.dp",mName.c_str());return (const char*)buffer;}
	/*Offset of the wave*/
	DoubleID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.off",mName.c_str());return (const char*)buffer;}
protected:
	DeformWave(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DeformFunc(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMWAVE_H__
