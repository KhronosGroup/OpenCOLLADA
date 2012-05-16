/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FRACTAL_H__
#define __MayaDM_FRACTAL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Fractal : public Texture2d
{
public:
public:

	Fractal():Texture2d(){}
	Fractal(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture2d(file, name, parent, "fractal", shared, create){}
	virtual ~Fractal(){}

	void setAmplitude(float a)
	{
		if(a == 1.0) return;
		fprintf(mFile,"\tsetAttr \".a\" %f;\n", a);
	}
	void setRatio(float ra)
	{
		if(ra == 0.707) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
	}
	void setThreshold(float th)
	{
		if(th == 0.0) return;
		fprintf(mFile,"\tsetAttr \".th\" %f;\n", th);
	}
	void setLevelMin(float lmn)
	{
		if(lmn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lmn\" %f;\n", lmn);
	}
	void setLevelMax(float lmx)
	{
		if(lmx == 9.0) return;
		fprintf(mFile,"\tsetAttr \".lmx\" %f;\n", lmx);
	}
	void setFrequencyRatio(float fr)
	{
		if(fr == 2.0) return;
		fprintf(mFile,"\tsetAttr \".fr\" %f;\n", fr);
	}
	void setBias(float bs)
	{
		if(bs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bs\" %f;\n", bs);
	}
	void setInflection(bool in)
	{
		if(in == false) return;
		fprintf(mFile,"\tsetAttr \".in\" %i;\n", in);
	}
	void setAnimated(bool an)
	{
		if(an == false) return;
		fprintf(mFile,"\tsetAttr \".an\" %i;\n", an);
	}
	void setTimeRatio(float tr)
	{
		if(tr == 2.0) return;
		fprintf(mFile,"\tsetAttr \".tr\" %f;\n", tr);
	}
	void setTime(float ti)
	{
		if(ti == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ti\" %f;\n", ti);
	}
	void getAmplitude()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getRatio()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getThreshold()const
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());
	}
	void getLevelMin()const
	{
		fprintf(mFile,"\"%s.lmn\"",mName.c_str());
	}
	void getLevelMax()const
	{
		fprintf(mFile,"\"%s.lmx\"",mName.c_str());
	}
	void getFrequencyRatio()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
	void getBias()const
	{
		fprintf(mFile,"\"%s.bs\"",mName.c_str());
	}
	void getInflection()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getAnimated()const
	{
		fprintf(mFile,"\"%s.an\"",mName.c_str());
	}
	void getTimeRatio()const
	{
		fprintf(mFile,"\"%s.tr\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.ti\"",mName.c_str());
	}
protected:
	Fractal(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture2d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FRACTAL_H__
