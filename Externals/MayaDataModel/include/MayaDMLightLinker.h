/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHTLINKER_H__
#define __MayaDM_LIGHTLINKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class LightLinker : public DependNode
{
public:
	struct Link{
		void write(FILE* file) const
		{
		}
	};
	struct Ignore{
		void write(FILE* file) const
		{
		}
	};
	struct ShadowLink{
		void write(FILE* file) const
		{
		}
	};
	struct ShadowIgnore{
		void write(FILE* file) const
		{
		}
	};
public:

	LightLinker():DependNode(){}
	LightLinker(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "lightLinker", shared, create){}
	virtual ~LightLinker(){}

	void setLink(size_t lnk_i,const Link& lnk)
	{
		fprintf(mFile,"\tsetAttr \".lnk[%i]\" ",lnk_i);
		lnk.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLink(size_t lnk_start,size_t lnk_end,Link* lnk)
	{
		fprintf(mFile,"\tsetAttr \".lnk[%i:%i]\" ", lnk_start,lnk_end);
		size_t size = (lnk_end-lnk_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			lnk[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startLink(size_t lnk_start,size_t lnk_end)const
	{
		fprintf(mFile,"\tsetAttr \".lnk[%i:%i]\"",lnk_start,lnk_end);
		fprintf(mFile," -type \"Link\" ");
	}
	void appendLink(const Link& lnk)const
	{
		fprintf(mFile," ");
		lnk.write(mFile);
	}
	void endLink()const
	{
		fprintf(mFile,";\n");
	}
	void setIgnore(size_t ign_i,const Ignore& ign)
	{
		fprintf(mFile,"\tsetAttr \".ign[%i]\" ",ign_i);
		ign.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIgnore(size_t ign_start,size_t ign_end,Ignore* ign)
	{
		fprintf(mFile,"\tsetAttr \".ign[%i:%i]\" ", ign_start,ign_end);
		size_t size = (ign_end-ign_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ign[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startIgnore(size_t ign_start,size_t ign_end)const
	{
		fprintf(mFile,"\tsetAttr \".ign[%i:%i]\"",ign_start,ign_end);
		fprintf(mFile," -type \"Ignore\" ");
	}
	void appendIgnore(const Ignore& ign)const
	{
		fprintf(mFile," ");
		ign.write(mFile);
	}
	void endIgnore()const
	{
		fprintf(mFile,";\n");
	}
	void setShadowLink(size_t slnk_i,const ShadowLink& slnk)
	{
		fprintf(mFile,"\tsetAttr \".slnk[%i]\" ",slnk_i);
		slnk.write(mFile);
		fprintf(mFile,";\n");
	}
	void setShadowLink(size_t slnk_start,size_t slnk_end,ShadowLink* slnk)
	{
		fprintf(mFile,"\tsetAttr \".slnk[%i:%i]\" ", slnk_start,slnk_end);
		size_t size = (slnk_end-slnk_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			slnk[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startShadowLink(size_t slnk_start,size_t slnk_end)const
	{
		fprintf(mFile,"\tsetAttr \".slnk[%i:%i]\"",slnk_start,slnk_end);
		fprintf(mFile," -type \"ShadowLink\" ");
	}
	void appendShadowLink(const ShadowLink& slnk)const
	{
		fprintf(mFile," ");
		slnk.write(mFile);
	}
	void endShadowLink()const
	{
		fprintf(mFile,";\n");
	}
	void setShadowIgnore(size_t sign_i,const ShadowIgnore& sign)
	{
		fprintf(mFile,"\tsetAttr \".sign[%i]\" ",sign_i);
		sign.write(mFile);
		fprintf(mFile,";\n");
	}
	void setShadowIgnore(size_t sign_start,size_t sign_end,ShadowIgnore* sign)
	{
		fprintf(mFile,"\tsetAttr \".sign[%i:%i]\" ", sign_start,sign_end);
		size_t size = (sign_end-sign_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			sign[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startShadowIgnore(size_t sign_start,size_t sign_end)const
	{
		fprintf(mFile,"\tsetAttr \".sign[%i:%i]\"",sign_start,sign_end);
		fprintf(mFile," -type \"ShadowIgnore\" ");
	}
	void appendShadowIgnore(const ShadowIgnore& sign)const
	{
		fprintf(mFile," ");
		sign.write(mFile);
	}
	void endShadowIgnore()const
	{
		fprintf(mFile,";\n");
	}
	void getLink(size_t lnk_i)const
	{
		fprintf(mFile,"\"%s.lnk[%i]\"",mName.c_str(),lnk_i);
	}
	void getLink()const
	{

		fprintf(mFile,"\"%s.lnk\"",mName.c_str());
	}
	void getLight(size_t lnk_i)const
	{
		fprintf(mFile,"\"%s.lnk[%i].llnk\"",mName.c_str(),lnk_i);
	}
	void getLight()const
	{

		fprintf(mFile,"\"%s.lnk.llnk\"",mName.c_str());
	}
	void getObject(size_t lnk_i)const
	{
		fprintf(mFile,"\"%s.lnk[%i].olnk\"",mName.c_str(),lnk_i);
	}
	void getObject()const
	{

		fprintf(mFile,"\"%s.lnk.olnk\"",mName.c_str());
	}
	void getIgnore(size_t ign_i)const
	{
		fprintf(mFile,"\"%s.ign[%i]\"",mName.c_str(),ign_i);
	}
	void getIgnore()const
	{

		fprintf(mFile,"\"%s.ign\"",mName.c_str());
	}
	void getLightIgnored(size_t ign_i)const
	{
		fprintf(mFile,"\"%s.ign[%i].lign\"",mName.c_str(),ign_i);
	}
	void getLightIgnored()const
	{

		fprintf(mFile,"\"%s.ign.lign\"",mName.c_str());
	}
	void getObjectIgnored(size_t ign_i)const
	{
		fprintf(mFile,"\"%s.ign[%i].oign\"",mName.c_str(),ign_i);
	}
	void getObjectIgnored()const
	{

		fprintf(mFile,"\"%s.ign.oign\"",mName.c_str());
	}
	void getShadowLink(size_t slnk_i)const
	{
		fprintf(mFile,"\"%s.slnk[%i]\"",mName.c_str(),slnk_i);
	}
	void getShadowLink()const
	{

		fprintf(mFile,"\"%s.slnk\"",mName.c_str());
	}
	void getShadowLight(size_t slnk_i)const
	{
		fprintf(mFile,"\"%s.slnk[%i].sllk\"",mName.c_str(),slnk_i);
	}
	void getShadowLight()const
	{

		fprintf(mFile,"\"%s.slnk.sllk\"",mName.c_str());
	}
	void getShadowObject(size_t slnk_i)const
	{
		fprintf(mFile,"\"%s.slnk[%i].solk\"",mName.c_str(),slnk_i);
	}
	void getShadowObject()const
	{

		fprintf(mFile,"\"%s.slnk.solk\"",mName.c_str());
	}
	void getShadowIgnore(size_t sign_i)const
	{
		fprintf(mFile,"\"%s.sign[%i]\"",mName.c_str(),sign_i);
	}
	void getShadowIgnore()const
	{

		fprintf(mFile,"\"%s.sign\"",mName.c_str());
	}
	void getShadowLightIgnored(size_t sign_i)const
	{
		fprintf(mFile,"\"%s.sign[%i].slig\"",mName.c_str(),sign_i);
	}
	void getShadowLightIgnored()const
	{

		fprintf(mFile,"\"%s.sign.slig\"",mName.c_str());
	}
	void getShadowObjectIgnored(size_t sign_i)const
	{
		fprintf(mFile,"\"%s.sign[%i].soig\"",mName.c_str(),sign_i);
	}
	void getShadowObjectIgnored()const
	{

		fprintf(mFile,"\"%s.sign.soig\"",mName.c_str());
	}
protected:
	LightLinker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LIGHTLINKER_H__
