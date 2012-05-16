/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HWREFLECTIONMAP_H__
#define __MayaDM_HWREFLECTIONMAP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class HwReflectionMap : public DependNode
{
public:
public:

	HwReflectionMap():DependNode(){}
	HwReflectionMap(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "hwReflectionMap", shared, create){}
	virtual ~HwReflectionMap(){}

	void setDecalMode(bool dm)
	{
		if(dm == true) return;
		fprintf(mFile,"\tsetAttr \".dm\" %i;\n", dm);
	}
	void setCubeMap(bool cm)
	{
		if(cm == false) return;
		fprintf(mFile,"\tsetAttr \".cm\" %i;\n", cm);
	}
	void setTextureHasChanged(bool thc)
	{
		if(thc == false) return;
		fprintf(mFile,"\tsetAttr \".thc\" %i;\n", thc);
	}
	void setSphereMapTextureName(const string& smtn)
	{
		if(smtn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".smtn\" -type \"string\" ");
		smtn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCubeFrontTextureName(const string& cftn)
	{
		if(cftn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cftn\" -type \"string\" ");
		cftn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCubeBackTextureName(const string& cbkn)
	{
		if(cbkn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cbkn\" -type \"string\" ");
		cbkn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCubeTopTextureName(const string& ctpn)
	{
		if(ctpn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ctpn\" -type \"string\" ");
		ctpn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCubeBottomTextureName(const string& cbmn)
	{
		if(cbmn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cbmn\" -type \"string\" ");
		cbmn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCubeLeftTextureName(const string& cltn)
	{
		if(cltn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cltn\" -type \"string\" ");
		cltn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCubeRightTextureName(const string& crtn)
	{
		if(crtn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".crtn\" -type \"string\" ");
		crtn.write(mFile);
		fprintf(mFile,";\n");
	}
	void getDecalMode()const
	{
		fprintf(mFile,"\"%s.dm\"",mName.c_str());
	}
	void getCubeMap()const
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());
	}
	void getTextureHasChanged()const
	{
		fprintf(mFile,"\"%s.thc\"",mName.c_str());
	}
	void getSphereMapTextureName()const
	{
		fprintf(mFile,"\"%s.smtn\"",mName.c_str());
	}
	void getCubeFrontTextureName()const
	{
		fprintf(mFile,"\"%s.cftn\"",mName.c_str());
	}
	void getCubeBackTextureName()const
	{
		fprintf(mFile,"\"%s.cbkn\"",mName.c_str());
	}
	void getCubeTopTextureName()const
	{
		fprintf(mFile,"\"%s.ctpn\"",mName.c_str());
	}
	void getCubeBottomTextureName()const
	{
		fprintf(mFile,"\"%s.cbmn\"",mName.c_str());
	}
	void getCubeLeftTextureName()const
	{
		fprintf(mFile,"\"%s.cltn\"",mName.c_str());
	}
	void getCubeRightTextureName()const
	{
		fprintf(mFile,"\"%s.crtn\"",mName.c_str());
	}
protected:
	HwReflectionMap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HWREFLECTIONMAP_H__
