/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLIPLIBRARY_H__
#define __MayaDM_CLIPLIBRARY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ClipLibrary : public DependNode
{
public:
	struct ClipEvalList{
		struct ClipEval{
			struct ClipEval_Inmap{
				short clipEval_InmapTo;
				short clipEval_InmapFrom;
				void write(FILE* file) const
				{
					fprintf(file,"%i ", clipEval_InmapTo);
					fprintf(file,"%i", clipEval_InmapFrom);
				}
			}* clipEval_Inmap;
			size_t nbClipEval_Inmap;
			struct ClipEval_Outmap{
				short clipEval_OutmapTo;
				short clipEval_OutmapFrom;
				void write(FILE* file) const
				{
					fprintf(file,"%i ", clipEval_OutmapTo);
					fprintf(file,"%i", clipEval_OutmapFrom);
				}
			}* clipEval_Outmap;
			size_t nbClipEval_Outmap;
			void write(FILE* file) const
			{
				for (size_t i = 0; i<nbClipEval_Inmap; ++i)
				{
					clipEval_Inmap[i].write(file);
					fprintf(file, " ");
					if (i + 1<nbClipEval_Inmap) fprintf(file, " ");
				}
				for (size_t i = 0; i<nbClipEval_Outmap; ++i)
				{
					clipEval_Outmap[i].write(file);
					if (i + 1<nbClipEval_Outmap) fprintf(file, " ");
				}
			}
		}* clipEval;
		size_t nbClipEval;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbClipEval; ++i)
			{
				clipEval[i].write(file);
				if (i + 1<nbClipEval) fprintf(file, " ");
			}
		}
	};
	struct Characterdata{
		intArray clipIndexMapping;
		void write(FILE* file) const
		{
			clipIndexMapping.write(file);
		}
	};
public:

	ClipLibrary():DependNode(){}
	ClipLibrary(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "clipLibrary", shared, create){}
	virtual ~ClipLibrary(){}

	void setClipEvalList(size_t cel_i,const ClipEvalList& cel)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i]\" ",cel_i);
		cel.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClipEvalList(size_t cel_start,size_t cel_end,ClipEvalList* cel)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i:%i]\" ", cel_start,cel_end);
		size_t size = (cel_end-cel_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cel[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startClipEvalList(size_t cel_start,size_t cel_end)const
	{
		fprintf(mFile,"\tsetAttr \".cel[%i:%i]\"",cel_start,cel_end);
		fprintf(mFile," -type \"ClipEvalList\" ");
	}
	void appendClipEvalList(const ClipEvalList& cel)const
	{
		fprintf(mFile," ");
		cel.write(mFile);
	}
	void endClipEvalList()const
	{
		fprintf(mFile,";\n");
	}
	void setClipEval(size_t cel_i,size_t cev_i,const ClipEvalList::ClipEval& cev)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i]\" ",cel_i,cev_i);
		cev.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClipEval(size_t cel_i,size_t cev_start,size_t cev_end,ClipEvalList::ClipEval* cev)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i:%i]\" ", cel_i,cev_start,cev_end);
		size_t size = (cev_end-cev_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cev[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startClipEval(size_t cel_i,size_t cev_start,size_t cev_end)const
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i:%i]\"",cel_i,cev_start,cev_end);
		fprintf(mFile," -type \"ClipEvalList::ClipEval\" ");
	}
	void appendClipEval(const ClipEvalList::ClipEval& cev)const
	{
		fprintf(mFile," ");
		cev.write(mFile);
	}
	void endClipEval()const
	{
		fprintf(mFile,";\n");
	}
	void setClipEval_Inmap(size_t cel_i,size_t cev_i,size_t cevi_i,const ClipEvalList::ClipEval::ClipEval_Inmap& cevi)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevi[%i]\" ",cel_i,cev_i,cevi_i);
		cevi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClipEval_Inmap(size_t cel_i,size_t cev_i,size_t cevi_start,size_t cevi_end,ClipEvalList::ClipEval::ClipEval_Inmap* cevi)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevi[%i:%i]\" ", cel_i,cev_i,cevi_start,cevi_end);
		size_t size = (cevi_end-cevi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cevi[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startClipEval_Inmap(size_t cel_i,size_t cev_i,size_t cevi_start,size_t cevi_end)const
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevi[%i:%i]\"",cel_i,cev_i,cevi_start,cevi_end);
		fprintf(mFile," -type \"ClipEvalList::ClipEval::ClipEval_Inmap\" ");
	}
	void appendClipEval_Inmap(const ClipEvalList::ClipEval::ClipEval_Inmap& cevi)const
	{
		fprintf(mFile," ");
		cevi.write(mFile);
	}
	void endClipEval_Inmap()const
	{
		fprintf(mFile,";\n");
	}
	void setClipEval_InmapTo(size_t cel_i,size_t cev_i,size_t cevi_i,short cevit)
	{
		if(cevit == 0) return;
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevi[%i].cevit\" %i;\n", cel_i,cev_i,cevi_i,cevit);
	}
	void setClipEval_InmapFrom(size_t cel_i,size_t cev_i,size_t cevi_i,short cevif)
	{
		if(cevif == 0) return;
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevi[%i].cevif\" %i;\n", cel_i,cev_i,cevi_i,cevif);
	}
	void setClipEval_Outmap(size_t cel_i,size_t cev_i,size_t cevo_i,const ClipEvalList::ClipEval::ClipEval_Outmap& cevo)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevo[%i]\" ",cel_i,cev_i,cevo_i);
		cevo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClipEval_Outmap(size_t cel_i,size_t cev_i,size_t cevo_start,size_t cevo_end,ClipEvalList::ClipEval::ClipEval_Outmap* cevo)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevo[%i:%i]\" ", cel_i,cev_i,cevo_start,cevo_end);
		size_t size = (cevo_end-cevo_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cevo[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startClipEval_Outmap(size_t cel_i,size_t cev_i,size_t cevo_start,size_t cevo_end)const
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevo[%i:%i]\"",cel_i,cev_i,cevo_start,cevo_end);
		fprintf(mFile," -type \"ClipEvalList::ClipEval::ClipEval_Outmap\" ");
	}
	void appendClipEval_Outmap(const ClipEvalList::ClipEval::ClipEval_Outmap& cevo)const
	{
		fprintf(mFile," ");
		cevo.write(mFile);
	}
	void endClipEval_Outmap()const
	{
		fprintf(mFile,";\n");
	}
	void setClipEval_OutmapTo(size_t cel_i,size_t cev_i,size_t cevo_i,short cevot)
	{
		if(cevot == 0) return;
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevo[%i].cevot\" %i;\n", cel_i,cev_i,cevo_i,cevot);
	}
	void setClipEval_OutmapFrom(size_t cel_i,size_t cev_i,size_t cevo_i,short cevof)
	{
		if(cevof == 0) return;
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevo[%i].cevof\" %i;\n", cel_i,cev_i,cevo_i,cevof);
	}
	void setCharacterdata(size_t cd_i,const Characterdata& cd)
	{
		fprintf(mFile,"\tsetAttr \".cd[%i]\" ",cd_i);
		cd.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCharacterdata(size_t cd_start,size_t cd_end,Characterdata* cd)
	{
		fprintf(mFile,"\tsetAttr \".cd[%i:%i]\" ", cd_start,cd_end);
		size_t size = (cd_end-cd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cd[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCharacterdata(size_t cd_start,size_t cd_end)const
	{
		fprintf(mFile,"\tsetAttr \".cd[%i:%i]\"",cd_start,cd_end);
		fprintf(mFile," -type \"Characterdata\" ");
	}
	void appendCharacterdata(const Characterdata& cd)const
	{
		fprintf(mFile," ");
		cd.write(mFile);
	}
	void endCharacterdata()const
	{
		fprintf(mFile,";\n");
	}
	void setClipIndexMapping(size_t cd_i,const intArray& cim)
	{
		if(cim.size == 0) return;
		fprintf(mFile,"\tsetAttr \".cd[%i].cim\" -type \"intArray\" ",cd_i);
		cim.write(mFile);
		fprintf(mFile,";\n");
	}
	void setActiveClip(int act)
	{
		if(act == -1) return;
		fprintf(mFile,"\tsetAttr \".act\" %i;\n", act);
	}
	void getClipEvalList(size_t cel_i)const
	{
		fprintf(mFile,"\"%s.cel[%i]\"",mName.c_str(),cel_i);
	}
	void getClipEvalList()const
	{

		fprintf(mFile,"\"%s.cel\"",mName.c_str());
	}
	void getClipEval(size_t cel_i,size_t cev_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i]\"",mName.c_str(),cel_i,cev_i);
	}
	void getClipEval(size_t cev_i)const
	{

		fprintf(mFile,"\"%s.cel.cev[%i]\"",mName.c_str(),cev_i);
	}
	void getClipEval_Raw(size_t cel_i,size_t cev_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevr\"",mName.c_str(),cel_i,cev_i);
	}
	void getClipEval_Raw(size_t cev_i)const
	{

		fprintf(mFile,"\"%s.cel.cev[%i].cevr\"",mName.c_str(),cev_i);
	}
	void getClipEval_Inmap(size_t cel_i,size_t cev_i,size_t cevi_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevi[%i]\"",mName.c_str(),cel_i,cev_i,cevi_i);
	}
	void getClipEval_Inmap(size_t cev_i,size_t cevi_i)const
	{

		fprintf(mFile,"\"%s.cel.cev[%i].cevi[%i]\"",mName.c_str(),cev_i,cevi_i);
	}
	void getClipEval_InmapTo(size_t cel_i,size_t cev_i,size_t cevi_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevi[%i].cevit\"",mName.c_str(),cel_i,cev_i,cevi_i);
	}
	void getClipEval_InmapTo(size_t cev_i,size_t cevi_i)const
	{

		fprintf(mFile,"\"%s.cel.cev[%i].cevi[%i].cevit\"",mName.c_str(),cev_i,cevi_i);
	}
	void getClipEval_InmapFrom(size_t cel_i,size_t cev_i,size_t cevi_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevi[%i].cevif\"",mName.c_str(),cel_i,cev_i,cevi_i);
	}
	void getClipEval_InmapFrom(size_t cev_i,size_t cevi_i)const
	{

		fprintf(mFile,"\"%s.cel.cev[%i].cevi[%i].cevif\"",mName.c_str(),cev_i,cevi_i);
	}
	void getClipEval_Outmap(size_t cel_i,size_t cev_i,size_t cevo_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevo[%i]\"",mName.c_str(),cel_i,cev_i,cevo_i);
	}
	void getClipEval_Outmap(size_t cev_i,size_t cevo_i)const
	{

		fprintf(mFile,"\"%s.cel.cev[%i].cevo[%i]\"",mName.c_str(),cev_i,cevo_i);
	}
	void getClipEval_OutmapTo(size_t cel_i,size_t cev_i,size_t cevo_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevo[%i].cevot\"",mName.c_str(),cel_i,cev_i,cevo_i);
	}
	void getClipEval_OutmapTo(size_t cev_i,size_t cevo_i)const
	{

		fprintf(mFile,"\"%s.cel.cev[%i].cevo[%i].cevot\"",mName.c_str(),cev_i,cevo_i);
	}
	void getClipEval_OutmapFrom(size_t cel_i,size_t cev_i,size_t cevo_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevo[%i].cevof\"",mName.c_str(),cel_i,cev_i,cevo_i);
	}
	void getClipEval_OutmapFrom(size_t cev_i,size_t cevo_i)const
	{

		fprintf(mFile,"\"%s.cel.cev[%i].cevo[%i].cevof\"",mName.c_str(),cev_i,cevo_i);
	}
	void getClipFunction()const
	{
		fprintf(mFile,"\"%s.cf\"",mName.c_str());
	}
	void getCharacterdata(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i]\"",mName.c_str(),cd_i);
	}
	void getCharacterdata()const
	{

		fprintf(mFile,"\"%s.cd\"",mName.c_str());
	}
	void getCharacterMapping(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i].cm\"",mName.c_str(),cd_i);
	}
	void getCharacterMapping()const
	{

		fprintf(mFile,"\"%s.cd.cm\"",mName.c_str());
	}
	void getClipIndexMapping(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i].cim\"",mName.c_str(),cd_i);
	}
	void getClipIndexMapping()const
	{

		fprintf(mFile,"\"%s.cd.cim\"",mName.c_str());
	}
	void getClipName(size_t cn_i)const
	{
		fprintf(mFile,"\"%s.cn[%i]\"",mName.c_str(),cn_i);
	}
	void getClipName()const
	{

		fprintf(mFile,"\"%s.cn\"",mName.c_str());
	}
	void getStart(size_t st_i)const
	{
		fprintf(mFile,"\"%s.st[%i]\"",mName.c_str(),st_i);
	}
	void getStart()const
	{

		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getDuration(size_t du_i)const
	{
		fprintf(mFile,"\"%s.du[%i]\"",mName.c_str(),du_i);
	}
	void getDuration()const
	{

		fprintf(mFile,"\"%s.du\"",mName.c_str());
	}
	void getSourceClip(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i]\"",mName.c_str(),sc_i);
	}
	void getSourceClip()const
	{

		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getClip(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i]\"",mName.c_str(),cl_i);
	}
	void getClip()const
	{

		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
protected:
	ClipLibrary(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLIPLIBRARY_H__
