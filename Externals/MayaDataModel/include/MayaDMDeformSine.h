/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class DeformSine : public DeformFunc
{
public:
public:

	DeformSine():DeformFunc(){}
	DeformSine(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, "deformSine", shared, create){}
	virtual ~DeformSine(){}

	void setLowBound(double lb)
	{
		if(lb == -1.0) return;
		fprintf(mFile,"\tsetAttr \".lb\" %f;\n", lb);
	}
	void setHighBound(double hb)
	{
		if(hb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hb\" %f;\n", hb);
	}
	void setAmplitude(double amp)
	{
		if(amp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".amp\" %f;\n", amp);
	}
	void setWavelength(double wav)
	{
		if(wav == 2.0) return;
		fprintf(mFile,"\tsetAttr \".wav\" %f;\n", wav);
	}
	void setDropoff(double dr)
	{
		if(dr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dr\" %f;\n", dr);
	}
	void setOffset(double off)
	{
		if(off == 0.0) return;
		fprintf(mFile,"\tsetAttr \".off\" %f;\n", off);
	}
	void getLowBound()const
	{
		fprintf(mFile,"\"%s.lb\"",mName.c_str());
	}
	void getHighBound()const
	{
		fprintf(mFile,"\"%s.hb\"",mName.c_str());
	}
	void getAmplitude()const
	{
		fprintf(mFile,"\"%s.amp\"",mName.c_str());
	}
	void getWavelength()const
	{
		fprintf(mFile,"\"%s.wav\"",mName.c_str());
	}
	void getDropoff()const
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.off\"",mName.c_str());
	}
protected:
	DeformSine(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMSINE_H__
