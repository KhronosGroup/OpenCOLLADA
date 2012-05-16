/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	MentalrayTexture():DependNode(){}
	MentalrayTexture(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "mentalrayTexture", shared, create){}
	virtual ~MentalrayTexture(){}

	void setMiTextureType(unsigned int mitt)
	{
		if(mitt == 1) return;
		fprintf(mFile,"\tsetAttr \".mitt\" %i;\n", mitt);
	}
	void setFileTextureName(const string& ftn)
	{
		if(ftn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ftn\" -type \"string\" ");
		ftn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiLocal(bool mil)
	{
		if(mil == false) return;
		fprintf(mFile,"\tsetAttr \".mil\" %i;\n", mil);
	}
	void setMiWritable(bool miw)
	{
		if(miw == false) return;
		fprintf(mFile,"\tsetAttr \".miw\" %i;\n", miw);
	}
	void setMiFilter(bool mift)
	{
		if(mift == false) return;
		fprintf(mFile,"\tsetAttr \".mift\" %i;\n", mift);
	}
	void setMiFilterSize(float mifs)
	{
		if(mifs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mifs\" %f;\n", mifs);
	}
	void setMiFileSize(const MiFileSize& mifr)
	{
		fprintf(mFile,"\tsetAttr \".mifr\" ");
		mifr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiWidth(int miwd)
	{
		if(miwd == 100) return;
		fprintf(mFile,"\tsetAttr \".mifr.miwd\" %i;\n", miwd);
	}
	void setMiHeight(int mihg)
	{
		if(mihg == 100) return;
		fprintf(mFile,"\tsetAttr \".mifr.mihg\" %i;\n", mihg);
	}
	void setMiDepth(unsigned int midp)
	{
		if(midp == 0) return;
		fprintf(mFile,"\tsetAttr \".mifr.midp\" %i;\n", midp);
	}
	void getMiTextureType()const
	{
		fprintf(mFile,"\"%s.mitt\"",mName.c_str());
	}
	void getFileTextureName()const
	{
		fprintf(mFile,"\"%s.ftn\"",mName.c_str());
	}
	void getMiLocal()const
	{
		fprintf(mFile,"\"%s.mil\"",mName.c_str());
	}
	void getMiWritable()const
	{
		fprintf(mFile,"\"%s.miw\"",mName.c_str());
	}
	void getMiFilter()const
	{
		fprintf(mFile,"\"%s.mift\"",mName.c_str());
	}
	void getMiFilterSize()const
	{
		fprintf(mFile,"\"%s.mifs\"",mName.c_str());
	}
	void getMiFileSize()const
	{
		fprintf(mFile,"\"%s.mifr\"",mName.c_str());
	}
	void getMiWidth()const
	{
		fprintf(mFile,"\"%s.mifr.miwd\"",mName.c_str());
	}
	void getMiHeight()const
	{
		fprintf(mFile,"\"%s.mifr.mihg\"",mName.c_str());
	}
	void getMiDepth()const
	{
		fprintf(mFile,"\"%s.mifr.midp\"",mName.c_str());
	}
protected:
	MentalrayTexture(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MENTALRAYTEXTURE_H__
