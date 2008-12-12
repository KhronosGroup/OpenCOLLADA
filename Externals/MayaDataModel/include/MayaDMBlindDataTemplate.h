/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
This node is used to maintain information on blindData types that have
        been created by users. <p/>

        It holds on to the typeId which is used to identify the blindData. <p/>
        Information on the actual data types that constitute blindData of this
        type is stored as dynamic attributes on the node. <p/>
*/
class BlindDataTemplate : public DependNode
{
public:
	/*Attribute to specify the preset parameters for blind data attributes*/
	struct BlindDataPresets{
		string bdPresetName;
		/*Attribute to specify the preset parameters for blind data attributes*/
		struct BdPresetElements{
			string bdPresetAttr;
			string bdPresetValue;
			void write(FILE* file) const
			{
				bdPresetAttr.write(file);
				fprintf_s(file, " ");
				bdPresetValue.write(file);
			}
		}* bdPresetElements;
		void write(FILE* file) const
		{
			bdPresetName.write(file);
			fprintf_s(file, " ");
			size_t size = sizeof(bdPresetElements)/sizeof(BdPresetElements);
			for(size_t i=0; i<size; ++i)
			{
				bdPresetElements[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*Attribute to allow user defined data to be associated with this template*/
	struct BdUserInfo{
		string bdUserInfoName;
		string bdUserInfoValue;
		void write(FILE* file) const
		{
			bdUserInfoName.write(file);
			fprintf_s(file, " ");
			bdUserInfoValue.write(file);
		}
	};
public:
	BlindDataTemplate(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "blindDataTemplate"){}
	virtual ~BlindDataTemplate(){}
	/*TypeId of the BlindData type specified by this node*/
	void setTypeId(int tid){if(tid == 0) return; fprintf_s(mFile, "setAttr \".tid\" %i;\n", tid);}
	/*Attribute to specify the preset parameters for blind data attributes*/
	void setBlindDataPresets(size_t bdps_i,const BlindDataPresets& bdps){fprintf_s(mFile, "setAttr \".bdps[%i]\" ",bdps_i);bdps.write(mFile);fprintf_s(mFile,";\n");}
	/*An attribute that holds the name of the Preset definition.*/
	void setBdPresetName(size_t bdps_i,const string& bdpn){if(bdpn == "NULL") return; fprintf_s(mFile, "setAttr \".bdps[%i].bdpn\" -type \"string\" ",bdps_i);bdpn.write(mFile);fprintf_s(mFile,";\n");}
	/*Attribute to specify the preset parameters for blind data attributes*/
	void setBdPresetElements(size_t bdps_i,size_t bdpe_i,const BlindDataPresets::BdPresetElements& bdpe){fprintf_s(mFile, "setAttr \".bdps[%i].bdpe[%i]\" ",bdps_i,bdpe_i);bdpe.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Preset Attribute name, gives the name of the attribute to assign a value to
	can be used in conjunction with blind data editors
	*/
	void setBdPresetAttr(size_t bdps_i,size_t bdpe_i,const string& bdpa){if(bdpa == "NULL") return; fprintf_s(mFile, "setAttr \".bdps[%i].bdpe[%i].bdpa\" -type \"string\" ",bdps_i,bdpe_i);bdpa.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Preset Attribute value, gives the value of the attribute to assign a value to
	can be used in conjunction with blind data editors
	*/
	void setBdPresetValue(size_t bdps_i,size_t bdpe_i,const string& bdpv){if(bdpv == "NULL") return; fprintf_s(mFile, "setAttr \".bdps[%i].bdpe[%i].bdpv\" -type \"string\" ",bdps_i,bdpe_i);bdpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Attribute to allow user defined data to be associated with this template*/
	void setBdUserInfo(size_t bdui_i,const BdUserInfo& bdui){fprintf_s(mFile, "setAttr \".bdui[%i]\" ",bdui_i);bdui.write(mFile);fprintf_s(mFile,";\n");}
	/*
	User Information name, gives the name of the user defined tag to assign a value to
	can be used in conjunction with blind data editors
	*/
	void setBdUserInfoName(size_t bdui_i,const string& bdun){if(bdun == "NULL") return; fprintf_s(mFile, "setAttr \".bdui[%i].bdun\" -type \"string\" ",bdui_i);bdun.write(mFile);fprintf_s(mFile,";\n");}
	/*
	User Information value, gives the value of the user defined tag to assign a value to
	can be used in conjunction with blind data editors
	*/
	void setBdUserInfoValue(size_t bdui_i,const string& bduv){if(bduv == "NULL") return; fprintf_s(mFile, "setAttr \".bdui[%i].bduv\" -type \"string\" ",bdui_i);bduv.write(mFile);fprintf_s(mFile,";\n");}
protected:
	BlindDataTemplate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BLINDDATATEMPLATE_H__
