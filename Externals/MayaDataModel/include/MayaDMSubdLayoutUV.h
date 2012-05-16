/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDLAYOUTUV_H__
#define __MayaDM_SUBDLAYOUTUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifierUV.h"
namespace MayaDM
{
class SubdLayoutUV : public SubdModifierUV
{
public:
public:

	SubdLayoutUV():SubdModifierUV(){}
	SubdLayoutUV(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SubdModifierUV(file, name, parent, "subdLayoutUV", shared, create){}
	virtual ~SubdLayoutUV(){}

	void setSeparate(unsigned int se)
	{
		if(se == 0) return;
		fprintf(mFile,"\tsetAttr \".se\" %i;\n", se);
	}
	void setFlipReversed(bool fr)
	{
		if(fr == true) return;
		fprintf(mFile,"\tsetAttr \".fr\" %i;\n", fr);
	}
	void setLayout(unsigned int l)
	{
		if(l == 2) return;
		fprintf(mFile,"\tsetAttr \".l\" %i;\n", l);
	}
	void setPercentageSpace(float ps)
	{
		if(ps == 0) return;
		fprintf(mFile,"\tsetAttr \".ps\" %f;\n", ps);
	}
	void setScale(unsigned int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"\tsetAttr \".sc\" %i;\n", sc);
	}
	void setDenseLayout(bool dl)
	{
		if(dl == false) return;
		fprintf(mFile,"\tsetAttr \".dl\" %i;\n", dl);
	}
	void setRotateForBestFit(unsigned int rbf)
	{
		if(rbf == 0) return;
		fprintf(mFile,"\tsetAttr \".rbf\" %i;\n", rbf);
	}
	void setLayoutMethod(unsigned int lm)
	{
		if(lm == 0) return;
		fprintf(mFile,"\tsetAttr \".lm\" %i;\n", lm);
	}
	void getSeparate()const
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());
	}
	void getFlipReversed()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
	void getLayout()const
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getPercentageSpace()const
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getDenseLayout()const
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getRotateForBestFit()const
	{
		fprintf(mFile,"\"%s.rbf\"",mName.c_str());
	}
	void getLayoutMethod()const
	{
		fprintf(mFile,"\"%s.lm\"",mName.c_str());
	}
protected:
	SubdLayoutUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SubdModifierUV(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDLAYOUTUV_H__
