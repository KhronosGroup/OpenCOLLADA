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
			struct ClipEval_Outmap{
				short clipEval_OutmapTo;
				short clipEval_OutmapFrom;
				void write(FILE* file) const
				{
					fprintf(file,"%i ", clipEval_OutmapTo);
					fprintf(file,"%i", clipEval_OutmapFrom);
				}
			}* clipEval_Outmap;
			void write(FILE* file) const
			{
				size_t size = sizeof(clipEval_Inmap)/sizeof(ClipEval_Inmap);
				for(size_t i=0; i<size; ++i)
				{
					clipEval_Inmap[i].write(file);
					fprintf(file, " ");
					if(i+1<size) fprintf(file," ");
				}
				size = sizeof(clipEval_Outmap)/sizeof(ClipEval_Outmap);
				for(size_t i=0; i<size; ++i)
				{
					clipEval_Outmap[i].write(file);
					if(i+1<size) fprintf(file," ");
				}
			}
		}* clipEval;
		void write(FILE* file) const
		{
			size_t size = sizeof(clipEval)/sizeof(ClipEval);
			for(size_t i=0; i<size; ++i)
			{
				clipEval[i].write(file);
				if(i+1<size) fprintf(file," ");
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
	ClipLibrary(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:DependNode(file, name, parent, "clipLibrary", create){}
	virtual ~ClipLibrary(){}
	void setClipEvalList(size_t cel_i,const ClipEvalList& cel)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i]\" ",cel_i);
		cel.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClipEval(size_t cel_i,size_t cev_i,const ClipEvalList::ClipEval& cev)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i]\" ",cel_i,cev_i);
		cev.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClipEval_Inmap(size_t cel_i,size_t cev_i,size_t cevi_i,const ClipEvalList::ClipEval::ClipEval_Inmap& cevi)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i].cev[%i].cevi[%i]\" ",cel_i,cev_i,cevi_i);
		cevi.write(mFile);
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
	void getClipEval(size_t cel_i,size_t cev_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i]\"",mName.c_str(),cel_i,cev_i);

	}
	void getClipEval_Raw(size_t cel_i,size_t cev_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevr\"",mName.c_str(),cel_i,cev_i);

	}
	void getClipEval_Inmap(size_t cel_i,size_t cev_i,size_t cevi_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevi[%i]\"",mName.c_str(),cel_i,cev_i,cevi_i);

	}
	void getClipEval_InmapTo(size_t cel_i,size_t cev_i,size_t cevi_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevi[%i].cevit\"",mName.c_str(),cel_i,cev_i,cevi_i);

	}
	void getClipEval_InmapFrom(size_t cel_i,size_t cev_i,size_t cevi_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevi[%i].cevif\"",mName.c_str(),cel_i,cev_i,cevi_i);

	}
	void getClipEval_Outmap(size_t cel_i,size_t cev_i,size_t cevo_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevo[%i]\"",mName.c_str(),cel_i,cev_i,cevo_i);

	}
	void getClipEval_OutmapTo(size_t cel_i,size_t cev_i,size_t cevo_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevo[%i].cevot\"",mName.c_str(),cel_i,cev_i,cevo_i);

	}
	void getClipEval_OutmapFrom(size_t cel_i,size_t cev_i,size_t cevo_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].cev[%i].cevo[%i].cevof\"",mName.c_str(),cel_i,cev_i,cevo_i);

	}
	void getClipFunction()const
	{
		fprintf(mFile,"\"%s.cf\"",mName.c_str());

	}
	void getCharacterdata(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i]\"",mName.c_str(),cd_i);

	}
	void getCharacterMapping(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i].cm\"",mName.c_str(),cd_i);

	}
	void getClipIndexMapping(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i].cim\"",mName.c_str(),cd_i);

	}
	void getClipName(size_t cn_i)const
	{
		fprintf(mFile,"\"%s.cn[%i]\"",mName.c_str(),cn_i);

	}
	void getStart(size_t st_i)const
	{
		fprintf(mFile,"\"%s.st[%i]\"",mName.c_str(),st_i);

	}
	void getDuration(size_t du_i)const
	{
		fprintf(mFile,"\"%s.du[%i]\"",mName.c_str(),du_i);

	}
	void getSourceClip(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i]\"",mName.c_str(),sc_i);

	}
	void getClip(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i]\"",mName.c_str(),cl_i);

	}
protected:
	ClipLibrary(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:DependNode(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLIPLIBRARY_H__
