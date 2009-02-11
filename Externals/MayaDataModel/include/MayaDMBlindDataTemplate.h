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
		void write(FILE* file) const
		{
			bdPresetName.write(file);
			fprintf(file, " ");
			size_t size = sizeof(bdPresetElements)/sizeof(BdPresetElements);
			for(size_t i=0; i<size; ++i)
			{
				bdPresetElements[i].write(file);
				if(i+1<size) fprintf(file," ");
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
	BlindDataTemplate(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "blindDataTemplate"){}
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
	BlindDataTemplate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLINDDATATEMPLATE_H__
