/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLINDDATATEMPLATE_H__
#define __MayaDM_BLINDDATATEMPLATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class BlindDataTemplate : public DependNode
{
public:
	struct BlindDataPresets{
		string bdPresetName;
		struct BdPresetElements{
			string bdPresetAttr;
			string bdPresetValue;
			void write(FILE* file) const
			{
				bdPresetAttr.write(file);
				fprintf(file, " ");
				bdPresetValue.write(file);
			}
		}* bdPresetElements;
		size_t nbBdPresetElements;
		void write(FILE* file) const
		{
			bdPresetName.write(file);
			fprintf(file, " ");
			for (size_t i = 0; i<nbBdPresetElements; ++i)
			{
				bdPresetElements[i].write(file);
				if (i + 1<nbBdPresetElements) fprintf(file, " ");
			}
		}
	};
	struct BdUserInfo{
		string bdUserInfoName;
		string bdUserInfoValue;
		void write(FILE* file) const
		{
			bdUserInfoName.write(file);
			fprintf(file, " ");
			bdUserInfoValue.write(file);
		}
	};
public:

	BlindDataTemplate():DependNode(){}
	BlindDataTemplate(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "blindDataTemplate", shared, create){}
	virtual ~BlindDataTemplate(){}

	void setTypeId(int tid)
	{
		if(tid == 0) return;
		fprintf(mFile,"\tsetAttr \".tid\" %i;\n", tid);
	}
	void setBlindDataPresets(size_t bdps_i,const BlindDataPresets& bdps)
	{
		fprintf(mFile,"\tsetAttr \".bdps[%i]\" ",bdps_i);
		bdps.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlindDataPresets(size_t bdps_start,size_t bdps_end,BlindDataPresets* bdps)
	{
		fprintf(mFile,"\tsetAttr \".bdps[%i:%i]\" ", bdps_start,bdps_end);
		size_t size = (bdps_end-bdps_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			bdps[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBlindDataPresets(size_t bdps_start,size_t bdps_end)const
	{
		fprintf(mFile,"\tsetAttr \".bdps[%i:%i]\"",bdps_start,bdps_end);
		fprintf(mFile," -type \"BlindDataPresets\" ");
	}
	void appendBlindDataPresets(const BlindDataPresets& bdps)const
	{
		fprintf(mFile," ");
		bdps.write(mFile);
	}
	void endBlindDataPresets()const
	{
		fprintf(mFile,";\n");
	}
	void setBdPresetName(size_t bdps_i,const string& bdpn)
	{
		if(bdpn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".bdps[%i].bdpn\" -type \"string\" ",bdps_i);
		bdpn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBdPresetElements(size_t bdps_i,size_t bdpe_i,const BlindDataPresets::BdPresetElements& bdpe)
	{
		fprintf(mFile,"\tsetAttr \".bdps[%i].bdpe[%i]\" ",bdps_i,bdpe_i);
		bdpe.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBdPresetElements(size_t bdps_i,size_t bdpe_start,size_t bdpe_end,BlindDataPresets::BdPresetElements* bdpe)
	{
		fprintf(mFile,"\tsetAttr \".bdps[%i].bdpe[%i:%i]\" ", bdps_i,bdpe_start,bdpe_end);
		size_t size = (bdpe_end-bdpe_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			bdpe[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBdPresetElements(size_t bdps_i,size_t bdpe_start,size_t bdpe_end)const
	{
		fprintf(mFile,"\tsetAttr \".bdps[%i].bdpe[%i:%i]\"",bdps_i,bdpe_start,bdpe_end);
		fprintf(mFile," -type \"BlindDataPresets::BdPresetElements\" ");
	}
	void appendBdPresetElements(const BlindDataPresets::BdPresetElements& bdpe)const
	{
		fprintf(mFile," ");
		bdpe.write(mFile);
	}
	void endBdPresetElements()const
	{
		fprintf(mFile,";\n");
	}
	void setBdPresetAttr(size_t bdps_i,size_t bdpe_i,const string& bdpa)
	{
		if(bdpa == "NULL") return;
		fprintf(mFile,"\tsetAttr \".bdps[%i].bdpe[%i].bdpa\" -type \"string\" ",bdps_i,bdpe_i);
		bdpa.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBdPresetValue(size_t bdps_i,size_t bdpe_i,const string& bdpv)
	{
		if(bdpv == "NULL") return;
		fprintf(mFile,"\tsetAttr \".bdps[%i].bdpe[%i].bdpv\" -type \"string\" ",bdps_i,bdpe_i);
		bdpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBdUserInfo(size_t bdui_i,const BdUserInfo& bdui)
	{
		fprintf(mFile,"\tsetAttr \".bdui[%i]\" ",bdui_i);
		bdui.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBdUserInfo(size_t bdui_start,size_t bdui_end,BdUserInfo* bdui)
	{
		fprintf(mFile,"\tsetAttr \".bdui[%i:%i]\" ", bdui_start,bdui_end);
		size_t size = (bdui_end-bdui_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			bdui[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBdUserInfo(size_t bdui_start,size_t bdui_end)const
	{
		fprintf(mFile,"\tsetAttr \".bdui[%i:%i]\"",bdui_start,bdui_end);
		fprintf(mFile," -type \"BdUserInfo\" ");
	}
	void appendBdUserInfo(const BdUserInfo& bdui)const
	{
		fprintf(mFile," ");
		bdui.write(mFile);
	}
	void endBdUserInfo()const
	{
		fprintf(mFile,";\n");
	}
	void setBdUserInfoName(size_t bdui_i,const string& bdun)
	{
		if(bdun == "NULL") return;
		fprintf(mFile,"\tsetAttr \".bdui[%i].bdun\" -type \"string\" ",bdui_i);
		bdun.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBdUserInfoValue(size_t bdui_i,const string& bduv)
	{
		if(bduv == "NULL") return;
		fprintf(mFile,"\tsetAttr \".bdui[%i].bduv\" -type \"string\" ",bdui_i);
		bduv.write(mFile);
		fprintf(mFile,";\n");
	}
protected:
	BlindDataTemplate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLINDDATATEMPLATE_H__
