/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MENTALRAYTEXTURE_H__
#define __MayaDM_MENTALRAYTEXTURE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class MentalrayTexture : public DependNode
{
public:
	struct MiFileSize{
		int miWidth;
		int miHeight;
		unsigned int miDepth;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", miWidth);
			fprintf(file,"%i ", miHeight);
			fprintf(file,"%i", miDepth);
		}
	};
public:
	MentalrayTexture(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "mentalrayTexture"){}
	virtual ~MentalrayTexture(){}
	void setMiTextureType(unsigned int mitt)
	{
		if(mitt == 1) return;
		fprintf(mFile,"setAttr \".mitt\" %i;\n", mitt);

	}
	void setFileTextureName(const string& ftn)
	{
		if(ftn == "NULL") return;
		fprintf(mFile,"setAttr \".ftn\" -type \"string\" ");
		ftn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiLocal(bool mil)
	{
		if(mil == false) return;
		fprintf(mFile,"setAttr \".mil\" %i;\n", mil);

	}
	void setMiWritable(bool miw)
	{
		if(miw == false) return;
		fprintf(mFile,"setAttr \".miw\" %i;\n", miw);

	}
	void setMiFilter(bool mift)
	{
		if(mift == false) return;
		fprintf(mFile,"setAttr \".mift\" %i;\n", mift);

	}
	void setMiFilterSize(float mifs)
	{
		if(mifs == 1.0) return;
		fprintf(mFile,"setAttr \".mifs\" %f;\n", mifs);

	}
	void setMiFileSize(const MiFileSize& mifr)
	{
		fprintf(mFile,"setAttr \".mifr\" ");
		mifr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiWidth(int miwd)
	{
		if(miwd == 100) return;
		fprintf(mFile,"setAttr \".mifr.miwd\" %i;\n", miwd);

	}
	void setMiHeight(int mihg)
	{
		if(mihg == 100) return;
		fprintf(mFile,"setAttr \".mifr.mihg\" %i;\n", mihg);

	}
	void setMiDepth(unsigned int midp)
	{
		if(midp == 0) return;
		fprintf(mFile,"setAttr \".mifr.midp\" %i;\n", midp);

	}
	void getMiTextureType()
	{
		fprintf(mFile,"\"%s.mitt\"",mName.c_str());

	}
	void getFileTextureName()
	{
		fprintf(mFile,"\"%s.ftn\"",mName.c_str());

	}
	void getMiLocal()
	{
		fprintf(mFile,"\"%s.mil\"",mName.c_str());

	}
	void getMiWritable()
	{
		fprintf(mFile,"\"%s.miw\"",mName.c_str());

	}
	void getMiFilter()
	{
		fprintf(mFile,"\"%s.mift\"",mName.c_str());

	}
	void getMiFilterSize()
	{
		fprintf(mFile,"\"%s.mifs\"",mName.c_str());

	}
	void getMiFileSize()
	{
		fprintf(mFile,"\"%s.mifr\"",mName.c_str());

	}
	void getMiWidth()
	{
		fprintf(mFile,"\"%s.mifr.miwd\"",mName.c_str());

	}
	void getMiHeight()
	{
		fprintf(mFile,"\"%s.mifr.mihg\"",mName.c_str());

	}
	void getMiDepth()
	{
		fprintf(mFile,"\"%s.mifr.midp\"",mName.c_str());

	}
protected:
	MentalrayTexture(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MENTALRAYTEXTURE_H__
