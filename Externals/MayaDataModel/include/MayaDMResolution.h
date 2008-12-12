/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RESOLUTION_H__
#define __MayaDM_RESOLUTION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
*/
class Resolution : public DependNode
{
public:
public:
	Resolution(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "resolution"){}
	virtual ~Resolution(){}
	/*The image resolution width (X).*/
	void setWidth(int w){if(w == 640) return; fprintf_s(mFile, "setAttr \".w\" %i;\n", w);}
	/*The image resolution width (X).*/
	void setWidth(const IntID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*The image resolution height (Y).*/
	void setHeight(int h){if(h == 480) return; fprintf_s(mFile, "setAttr \".h\" %i;\n", h);}
	/*The image resolution height (Y).*/
	void setHeight(const IntID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*
	The currently locked X/Y aspect ratio between X and Y resolution.
	This attribute is only used for internal computations, and is
	not the same thing as the render globals window' "pixel aspect
	ratio" field.  Please refer to "device aspect ratio" for this.
	*/
	void setPixelAspect(float pa){if(pa == 0.0) return; fprintf_s(mFile, "setAttr \".pa\" %f;\n", pa);}
	/*
	The currently locked X/Y aspect ratio between X and Y resolution.
	This attribute is only used for internal computations, and is
	not the same thing as the render globals window' "pixel aspect
	ratio" field.  Please refer to "device aspect ratio" for this.
	*/
	void setPixelAspect(const FloatID& pa){fprintf_s(mFile,"connectAttr \"");pa.write(mFile);fprintf_s(mFile,"\" \"%s.pa\";\n",mName.c_str());}
	/*When true, lock the aspect ratio so that if X is modified, Y maintains the proper aspect, and visa-versa.*/
	void setAspectLock(bool al){if(al == false) return; fprintf_s(mFile, "setAttr \".al\" %i;\n", al);}
	/*When true, lock the aspect ratio so that if X is modified, Y maintains the proper aspect, and visa-versa.*/
	void setAspectLock(const BoolID& al){fprintf_s(mFile,"connectAttr \"");al.write(mFile);fprintf_s(mFile,"\" \"%s.al\";\n",mName.c_str());}
	/*
	Device aspect ratio: the resolution must squeeze the image into
	this aspect ratio.  Eg., device aspect ratio for NTSC is 4/3.
	In the render globals window, there is a "pixel aspect ratio"
	field, which is not an attribute, and is made available to allow
	users familiar with pixel aspect ratio to set non-square pixel
	sizes (value of 1 indicating square).  When this value is set,
	the device aspect ratio is modified.  There is a relationship
	between these two items: pixel_aspect_ratio = (height / width) *
	device_aspect_ratio.
	*/
	void setDeviceAspectRatio(float dar){if(dar == 1.33333) return; fprintf_s(mFile, "setAttr \".dar\" %f;\n", dar);}
	/*
	Device aspect ratio: the resolution must squeeze the image into
	this aspect ratio.  Eg., device aspect ratio for NTSC is 4/3.
	In the render globals window, there is a "pixel aspect ratio"
	field, which is not an attribute, and is made available to allow
	users familiar with pixel aspect ratio to set non-square pixel
	sizes (value of 1 indicating square).  When this value is set,
	the device aspect ratio is modified.  There is a relationship
	between these two items: pixel_aspect_ratio = (height / width) *
	device_aspect_ratio.
	*/
	void setDeviceAspectRatio(const FloatID& dar){fprintf_s(mFile,"connectAttr \"");dar.write(mFile);fprintf_s(mFile,"\" \"%s.dar\";\n",mName.c_str());}
	/*Lock device aspect ratio.  If the lock is off, then the device aspect ratio will make sure that there is no squeeze in the image.*/
	void setLockDeviceAspectRatio(bool ldar){if(ldar == false) return; fprintf_s(mFile, "setAttr \".ldar\" %i;\n", ldar);}
	/*Lock device aspect ratio.  If the lock is off, then the device aspect ratio will make sure that there is no squeeze in the image.*/
	void setLockDeviceAspectRatio(const BoolID& ldar){fprintf_s(mFile,"connectAttr \"");ldar.write(mFile);fprintf_s(mFile,"\" \"%s.ldar\";\n",mName.c_str());}
	/*The image pixel density in dots per inch (DPI).*/
	void setDotsPerInch(float dpi){if(dpi == 72.0) return; fprintf_s(mFile, "setAttr \".dpi\" %f;\n", dpi);}
	/*The image pixel density in dots per inch (DPI).*/
	void setDotsPerInch(const FloatID& dpi){fprintf_s(mFile,"connectAttr \"");dpi.write(mFile);fprintf_s(mFile,"\" \"%s.dpi\";\n",mName.c_str());}
	/*if odd field comes first*/
	void setOddFieldFirst(bool off){if(off == true) return; fprintf_s(mFile, "setAttr \".off\" %i;\n", off);}
	/*if odd field comes first*/
	void setOddFieldFirst(const BoolID& off){fprintf_s(mFile,"connectAttr \"");off.write(mFile);fprintf_s(mFile,"\" \"%s.off\";\n",mName.c_str());}
	/*if fields are to be done*/
	void setFields(unsigned int fld){if(fld == 0) return; fprintf_s(mFile, "setAttr \".fld\" %i;\n", fld);}
	/*if fields are to be done*/
	void setFields(const UnsignedintID& fld){fprintf_s(mFile,"connectAttr \"");fld.write(mFile);fprintf_s(mFile,"\" \"%s.fld\";\n",mName.c_str());}
	/*if top/bottom is the 0th field*/
	void setZerothScanline(unsigned int zsl){if(zsl == 0) return; fprintf_s(mFile, "setAttr \".zsl\" %i;\n", zsl);}
	/*if top/bottom is the 0th field*/
	void setZerothScanline(const UnsignedintID& zsl){fprintf_s(mFile,"connectAttr \"");zsl.write(mFile);fprintf_s(mFile,"\" \"%s.zsl\";\n",mName.c_str());}
	/*The units for the image size.*/
	void setImageSizeUnits(unsigned int isu){if(isu == 0) return; fprintf_s(mFile, "setAttr \".isu\" %i;\n", isu);}
	/*The units for the image size.*/
	void setImageSizeUnits(const UnsignedintID& isu){fprintf_s(mFile,"connectAttr \"");isu.write(mFile);fprintf_s(mFile,"\" \"%s.isu\";\n",mName.c_str());}
	/*The units for the pixel density.*/
	void setPixelDensityUnits(unsigned int pdu){if(pdu == 0) return; fprintf_s(mFile, "setAttr \".pdu\" %i;\n", pdu);}
	/*The units for the pixel density.*/
	void setPixelDensityUnits(const UnsignedintID& pdu){fprintf_s(mFile,"connectAttr \"");pdu.write(mFile);fprintf_s(mFile,"\" \"%s.pdu\";\n",mName.c_str());}
	/*The image resolution width (X).*/
	IntID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*The image resolution height (Y).*/
	IntID getHeight(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*
	The currently locked X/Y aspect ratio between X and Y resolution.
	This attribute is only used for internal computations, and is
	not the same thing as the render globals window' "pixel aspect
	ratio" field.  Please refer to "device aspect ratio" for this.
	*/
	FloatID getPixelAspect(){char buffer[4096];sprintf_s (buffer, "%s.pa",mName.c_str());return (const char*)buffer;}
	/*When true, lock the aspect ratio so that if X is modified, Y maintains the proper aspect, and visa-versa.*/
	BoolID getAspectLock(){char buffer[4096];sprintf_s (buffer, "%s.al",mName.c_str());return (const char*)buffer;}
	/*
	Device aspect ratio: the resolution must squeeze the image into
	this aspect ratio.  Eg., device aspect ratio for NTSC is 4/3.
	In the render globals window, there is a "pixel aspect ratio"
	field, which is not an attribute, and is made available to allow
	users familiar with pixel aspect ratio to set non-square pixel
	sizes (value of 1 indicating square).  When this value is set,
	the device aspect ratio is modified.  There is a relationship
	between these two items: pixel_aspect_ratio = (height / width) *
	device_aspect_ratio.
	*/
	FloatID getDeviceAspectRatio(){char buffer[4096];sprintf_s (buffer, "%s.dar",mName.c_str());return (const char*)buffer;}
	/*Lock device aspect ratio.  If the lock is off, then the device aspect ratio will make sure that there is no squeeze in the image.*/
	BoolID getLockDeviceAspectRatio(){char buffer[4096];sprintf_s (buffer, "%s.ldar",mName.c_str());return (const char*)buffer;}
	/*The image pixel density in dots per inch (DPI).*/
	FloatID getDotsPerInch(){char buffer[4096];sprintf_s (buffer, "%s.dpi",mName.c_str());return (const char*)buffer;}
	/*if odd field comes first*/
	BoolID getOddFieldFirst(){char buffer[4096];sprintf_s (buffer, "%s.off",mName.c_str());return (const char*)buffer;}
	/*if fields are to be done*/
	UnsignedintID getFields(){char buffer[4096];sprintf_s (buffer, "%s.fld",mName.c_str());return (const char*)buffer;}
	/*if top/bottom is the 0th field*/
	UnsignedintID getZerothScanline(){char buffer[4096];sprintf_s (buffer, "%s.zsl",mName.c_str());return (const char*)buffer;}
	/*The units for the image size.*/
	UnsignedintID getImageSizeUnits(){char buffer[4096];sprintf_s (buffer, "%s.isu",mName.c_str());return (const char*)buffer;}
	/*The units for the pixel density.*/
	UnsignedintID getPixelDensityUnits(){char buffer[4096];sprintf_s (buffer, "%s.pdu",mName.c_str());return (const char*)buffer;}
protected:
	Resolution(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RESOLUTION_H__
