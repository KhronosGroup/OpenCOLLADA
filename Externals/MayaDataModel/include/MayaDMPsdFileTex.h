/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PSDFILETEX_H__
#define __MayaDM_PSDFILETEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFile.h"
namespace MayaDM
{
class PsdFileTex : public File
{
public:
public:
	PsdFileTex():File(){}
	PsdFileTex(FILE* file,const std::string& name,const std::string& parent=""):File(file, name, parent, "psdFileTex"){}
	virtual ~PsdFileTex(){}
	void setLayerSetName(const string& lsn)
	{
		if(lsn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".lsn\" -type \"string\" ");
		lsn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAlpha(const string& alp)
	{
		if(alp == "NULL") return;
		fprintf(mFile,"\tsetAttr \".alp\" -type \"string\" ");
		alp.write(mFile);
		fprintf(mFile,";\n");

	}
	void getLayerSetName()
	{
		fprintf(mFile,"\"%s.lsn\"",mName.c_str());

	}
	void getLayerSets()
	{
		fprintf(mFile,"\"%s.lys\"",mName.c_str());

	}
	void getAlpha()
	{
		fprintf(mFile,"\"%s.alp\"",mName.c_str());

	}
	void getAlphaList()
	{
		fprintf(mFile,"\"%s.als\"",mName.c_str());

	}
protected:
	PsdFileTex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:File(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PSDFILETEX_H__
