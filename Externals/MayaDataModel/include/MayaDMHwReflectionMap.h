/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	HwReflectionMap(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hwReflectionMap"){}
	virtual ~HwReflectionMap(){}
	void setDecalMode(bool dm)
	{
		if(dm == true) return;
		fprintf(mFile,"setAttr \".dm\" %i;\n", dm);

	}
	void setCubeMap(bool cm)
	{
		if(cm == false) return;
		fprintf(mFile,"setAttr \".cm\" %i;\n", cm);

	}
	void setTextureHasChanged(bool thc)
	{
		if(thc == false) return;
		fprintf(mFile,"setAttr \".thc\" %i;\n", thc);

	}
	void setSphereMapTextureName(const string& smtn)
	{
		if(smtn == "NULL") return;
		fprintf(mFile,"setAttr \".smtn\" -type \"string\" ");
		smtn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCubeFrontTextureName(const string& cftn)
	{
		if(cftn == "NULL") return;
		fprintf(mFile,"setAttr \".cftn\" -type \"string\" ");
		cftn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCubeBackTextureName(const string& cbkn)
	{
		if(cbkn == "NULL") return;
		fprintf(mFile,"setAttr \".cbkn\" -type \"string\" ");
		cbkn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCubeTopTextureName(const string& ctpn)
	{
		if(ctpn == "NULL") return;
		fprintf(mFile,"setAttr \".ctpn\" -type \"string\" ");
		ctpn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCubeBottomTextureName(const string& cbmn)
	{
		if(cbmn == "NULL") return;
		fprintf(mFile,"setAttr \".cbmn\" -type \"string\" ");
		cbmn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCubeLeftTextureName(const string& cltn)
	{
		if(cltn == "NULL") return;
		fprintf(mFile,"setAttr \".cltn\" -type \"string\" ");
		cltn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCubeRightTextureName(const string& crtn)
	{
		if(crtn == "NULL") return;
		fprintf(mFile,"setAttr \".crtn\" -type \"string\" ");
		crtn.write(mFile);
		fprintf(mFile,";\n");

	}
	void getDecalMode()
	{
		fprintf(mFile,"\"%s.dm\"",mName.c_str());

	}
	void getCubeMap()
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());

	}
	void getTextureHasChanged()
	{
		fprintf(mFile,"\"%s.thc\"",mName.c_str());

	}
	void getSphereMapTextureName()
	{
		fprintf(mFile,"\"%s.smtn\"",mName.c_str());

	}
	void getCubeFrontTextureName()
	{
		fprintf(mFile,"\"%s.cftn\"",mName.c_str());

	}
	void getCubeBackTextureName()
	{
		fprintf(mFile,"\"%s.cbkn\"",mName.c_str());

	}
	void getCubeTopTextureName()
	{
		fprintf(mFile,"\"%s.ctpn\"",mName.c_str());

	}
	void getCubeBottomTextureName()
	{
		fprintf(mFile,"\"%s.cbmn\"",mName.c_str());

	}
	void getCubeLeftTextureName()
	{
		fprintf(mFile,"\"%s.cltn\"",mName.c_str());

	}
	void getCubeRightTextureName()
	{
		fprintf(mFile,"\"%s.crtn\"",mName.c_str());

	}
protected:
	HwReflectionMap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HWREFLECTIONMAP_H__
