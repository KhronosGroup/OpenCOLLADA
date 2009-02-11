/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class Resolution : public DependNode
{
public:
public:
	Resolution():DependNode(){}
	Resolution(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "resolution"){}
	virtual ~Resolution(){}
	void setWidth(int w)
	{
		if(w == 640) return;
		fprintf(mFile,"\tsetAttr \".w\" %i;\n", w);

	}
	void setHeight(int h)
	{
		if(h == 480) return;
		fprintf(mFile,"\tsetAttr \".h\" %i;\n", h);

	}
	void setPixelAspect(float pa)
	{
		if(pa == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pa\" %f;\n", pa);

	}
	void setAspectLock(bool al)
	{
		if(al == false) return;
		fprintf(mFile,"\tsetAttr \".al\" %i;\n", al);

	}
	void setDeviceAspectRatio(float dar)
	{
		if(dar == 1.33333) return;
		fprintf(mFile,"\tsetAttr \".dar\" %f;\n", dar);

	}
	void setLockDeviceAspectRatio(bool ldar)
	{
		if(ldar == false) return;
		fprintf(mFile,"\tsetAttr \".ldar\" %i;\n", ldar);

	}
	void setDotsPerInch(float dpi)
	{
		if(dpi == 72.0) return;
		fprintf(mFile,"\tsetAttr \".dpi\" %f;\n", dpi);

	}
	void setOddFieldFirst(bool off)
	{
		if(off == true) return;
		fprintf(mFile,"\tsetAttr \".off\" %i;\n", off);

	}
	void setFields(unsigned int fld)
	{
		if(fld == 0) return;
		fprintf(mFile,"\tsetAttr \".fld\" %i;\n", fld);

	}
	void setZerothScanline(unsigned int zsl)
	{
		if(zsl == 0) return;
		fprintf(mFile,"\tsetAttr \".zsl\" %i;\n", zsl);

	}
	void setImageSizeUnits(unsigned int isu)
	{
		if(isu == 0) return;
		fprintf(mFile,"\tsetAttr \".isu\" %i;\n", isu);

	}
	void setPixelDensityUnits(unsigned int pdu)
	{
		if(pdu == 0) return;
		fprintf(mFile,"\tsetAttr \".pdu\" %i;\n", pdu);

	}
	void getWidth()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getHeight()
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());

	}
	void getPixelAspect()
	{
		fprintf(mFile,"\"%s.pa\"",mName.c_str());

	}
	void getAspectLock()
	{
		fprintf(mFile,"\"%s.al\"",mName.c_str());

	}
	void getDeviceAspectRatio()
	{
		fprintf(mFile,"\"%s.dar\"",mName.c_str());

	}
	void getLockDeviceAspectRatio()
	{
		fprintf(mFile,"\"%s.ldar\"",mName.c_str());

	}
	void getDotsPerInch()
	{
		fprintf(mFile,"\"%s.dpi\"",mName.c_str());

	}
	void getOddFieldFirst()
	{
		fprintf(mFile,"\"%s.off\"",mName.c_str());

	}
	void getFields()
	{
		fprintf(mFile,"\"%s.fld\"",mName.c_str());

	}
	void getZerothScanline()
	{
		fprintf(mFile,"\"%s.zsl\"",mName.c_str());

	}
	void getImageSizeUnits()
	{
		fprintf(mFile,"\"%s.isu\"",mName.c_str());

	}
	void getPixelDensityUnits()
	{
		fprintf(mFile,"\"%s.pdu\"",mName.c_str());

	}
protected:
	Resolution(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RESOLUTION_H__
