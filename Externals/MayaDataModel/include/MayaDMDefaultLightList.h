/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFAULTLIGHTLIST_H__
#define __MayaDM_DEFAULTLIGHTLIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DefaultLightList : public DependNode
{
public:
public:
	DefaultLightList():DependNode(){}
	DefaultLightList(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "defaultLightList"){}
	virtual ~DefaultLightList(){}
	void getLightDataArray(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i]\"",mName.c_str(),lda_i);

	}
	void getLightDirection(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].ld\"",mName.c_str(),lda_i);

	}
	void getLightDirectionX(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].ld.ldx\"",mName.c_str(),lda_i);

	}
	void getLightDirectionY(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].ld.ldy\"",mName.c_str(),lda_i);

	}
	void getLightDirectionZ(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].ld.ldz\"",mName.c_str(),lda_i);

	}
	void getLightIntensity(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].li\"",mName.c_str(),lda_i);

	}
	void getLightIntensityR(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].li.lir\"",mName.c_str(),lda_i);

	}
	void getLightIntensityG(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].li.lig\"",mName.c_str(),lda_i);

	}
	void getLightIntensityB(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].li.lib\"",mName.c_str(),lda_i);

	}
	void getLightAmbient(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].la\"",mName.c_str(),lda_i);

	}
	void getLightDiffuse(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].ldf\"",mName.c_str(),lda_i);

	}
	void getLightSpecular(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].ls\"",mName.c_str(),lda_i);

	}
	void getLightShadowFraction(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].lsf\"",mName.c_str(),lda_i);

	}
	void getPreShadowIntensity(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].psi\"",mName.c_str(),lda_i);

	}
	void getLightBlindData(size_t lda_i)
	{
		fprintf(mFile,"\"%s.lda[%i].lbd\"",mName.c_str(),lda_i);

	}
	void getLightData()
	{
		fprintf(mFile,"\"%s.ltd\"",mName.c_str());

	}
	void getLightDirectionOut()
	{
		fprintf(mFile,"\"%s.ltd.ldo\"",mName.c_str());

	}
	void getLightDirectionOutX()
	{
		fprintf(mFile,"\"%s.ltd.ldo.lqx\"",mName.c_str());

	}
	void getLightDirectionOutY()
	{
		fprintf(mFile,"\"%s.ltd.ldo.lqy\"",mName.c_str());

	}
	void getLightDirectionOutZ()
	{
		fprintf(mFile,"\"%s.ltd.ldo.lqz\"",mName.c_str());

	}
	void getLightIntensityOut()
	{
		fprintf(mFile,"\"%s.ltd.lw\"",mName.c_str());

	}
	void getLightIntensityOutR()
	{
		fprintf(mFile,"\"%s.ltd.lw.lwr\"",mName.c_str());

	}
	void getLightIntensityOutG()
	{
		fprintf(mFile,"\"%s.ltd.lw.lwg\"",mName.c_str());

	}
	void getLightIntensityOutB()
	{
		fprintf(mFile,"\"%s.ltd.lw.lwb\"",mName.c_str());

	}
	void getLightAmbientOut()
	{
		fprintf(mFile,"\"%s.ltd.lya\"",mName.c_str());

	}
	void getLightDiffuseOut()
	{
		fprintf(mFile,"\"%s.ltd.lyf\"",mName.c_str());

	}
	void getLightSpecularOut()
	{
		fprintf(mFile,"\"%s.ltd.lys\"",mName.c_str());

	}
	void getLightShadowFractionOut()
	{
		fprintf(mFile,"\"%s.ltd.sfo\"",mName.c_str());

	}
	void getPreShadowIntensityOut()
	{
		fprintf(mFile,"\"%s.ltd.psio\"",mName.c_str());

	}
	void getLightBlindDataOut()
	{
		fprintf(mFile,"\"%s.ltd.lbdo\"",mName.c_str());

	}
protected:
	DefaultLightList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFAULTLIGHTLIST_H__
