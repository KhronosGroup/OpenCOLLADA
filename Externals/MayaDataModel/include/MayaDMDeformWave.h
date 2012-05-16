/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class DeformWave : public DeformFunc
{
public:
public:

	DeformWave():DeformFunc(){}
	DeformWave(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, "deformWave", shared, create){}
	virtual ~DeformWave(){}

	void setMaxRadius(double mxr)
	{
		if(mxr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mxr\" %f;\n", mxr);
	}
	void setMinRadius(double mnr)
	{
		if(mnr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mnr\" %f;\n", mnr);
	}
	void setAmplitude(double amp)
	{
		if(amp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".amp\" %f;\n", amp);
	}
	void setWavelength(double wav)
	{
		if(wav == 1.0) return;
		fprintf(mFile,"\tsetAttr \".wav\" %f;\n", wav);
	}
	void setDropoff(double dr)
	{
		if(dr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dr\" %f;\n", dr);
	}
	void setDropoffPosition(double dp)
	{
		if(dp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dp\" %f;\n", dp);
	}
	void setOffset(double off)
	{
		if(off == 0.0) return;
		fprintf(mFile,"\tsetAttr \".off\" %f;\n", off);
	}
	void getMaxRadius()const
	{
		fprintf(mFile,"\"%s.mxr\"",mName.c_str());
	}
	void getMinRadius()const
	{
		fprintf(mFile,"\"%s.mnr\"",mName.c_str());
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
	void getDropoffPosition()const
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.off\"",mName.c_str());
	}
protected:
	DeformWave(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMWAVE_H__
