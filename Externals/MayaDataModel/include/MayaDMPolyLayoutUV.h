/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYLAYOUTUV_H__
#define __MayaDM_POLYLAYOUTUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
class PolyLayoutUV : public PolyModifierUV
{
public:
public:
	PolyLayoutUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyLayoutUV"){}
	virtual ~PolyLayoutUV(){}
	void setSeparate(unsigned int se)
	{
		if(se == 0) return;
		fprintf(mFile,"setAttr \".se\" %i;\n", se);

	}
	void setFlipReversed(bool fr)
	{
		if(fr == true) return;
		fprintf(mFile,"setAttr \".fr\" %i;\n", fr);

	}
	void setLayout(unsigned int l)
	{
		if(l == 2) return;
		fprintf(mFile,"setAttr \".l\" %i;\n", l);

	}
	void setPercentageSpace(float ps)
	{
		if(ps == 0) return;
		fprintf(mFile,"setAttr \".ps\" %f;\n", ps);

	}
	void setScale(unsigned int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"setAttr \".sc\" %i;\n", sc);

	}
	void setDenseLayout(bool dl)
	{
		if(dl == false) return;
		fprintf(mFile,"setAttr \".dl\" %i;\n", dl);

	}
	void setRotateForBestFit(unsigned int rbf)
	{
		if(rbf == 0) return;
		fprintf(mFile,"setAttr \".rbf\" %i;\n", rbf);

	}
	void setLayoutMethod(unsigned int lm)
	{
		if(lm == 0) return;
		fprintf(mFile,"setAttr \".lm\" %i;\n", lm);

	}
	void getSeparate()
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());

	}
	void getFlipReversed()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getLayout()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getPercentageSpace()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getDenseLayout()
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());

	}
	void getRotateForBestFit()
	{
		fprintf(mFile,"\"%s.rbf\"",mName.c_str());

	}
	void getLayoutMethod()
	{
		fprintf(mFile,"\"%s.lm\"",mName.c_str());

	}
protected:
	PolyLayoutUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYLAYOUTUV_H__
