/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BULGE_H__
#define __MayaDM_BULGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Bulge : public Texture2d
{
public:
public:
	Bulge(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "bulge"){}
	virtual ~Bulge(){}
	void setUWidth(float uw)
	{
		if(uw == 0.1) return;
		fprintf(mFile,"setAttr \".uw\" %f;\n", uw);

	}
	void setVWidth(float vw)
	{
		if(vw == 0.1) return;
		fprintf(mFile,"setAttr \".vw\" %f;\n", vw);

	}
	void getUWidth()
	{
		fprintf(mFile,"\"%s.uw\"",mName.c_str());

	}
	void getVWidth()
	{
		fprintf(mFile,"\"%s.vw\"",mName.c_str());

	}
protected:
	Bulge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BULGE_H__
