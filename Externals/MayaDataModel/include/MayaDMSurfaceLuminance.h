/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACELUMINANCE_H__
#define __MayaDM_SURFACELUMINANCE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SurfaceLuminance : public DependNode
{
public:
public:
	SurfaceLuminance():DependNode(){}
	SurfaceLuminance(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "surfaceLuminance"){}
	virtual ~SurfaceLuminance(){}
	void getNormalCamera()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getNormalCameraX()
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());

	}
	void getNormalCameraY()
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());

	}
	void getNormalCameraZ()
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());

	}
	void getLightDataArray(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i]\"",mName.c_str(),ltd_i);

	}
	void getLightDirection(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld\"",mName.c_str(),ltd_i);

	}
	void getLightDirectionX(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldx\"",mName.c_str(),ltd_i);

	}
	void getLightDirectionY(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldy\"",mName.c_str(),ltd_i);

	}
	void getLightDirectionZ(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldz\"",mName.c_str(),ltd_i);

	}
	void getLightIntensity(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li\"",mName.c_str(),ltd_i);

	}
	void getLightIntensityR(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lir\"",mName.c_str(),ltd_i);

	}
	void getLightIntensityG(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lig\"",mName.c_str(),ltd_i);

	}
	void getLightIntensityB(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lib\"",mName.c_str(),ltd_i);

	}
	void getLightAmbient(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].la\"",mName.c_str(),ltd_i);

	}
	void getLightDiffuse(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ldf\"",mName.c_str(),ltd_i);

	}
	void getLightSpecular(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ls\"",mName.c_str(),ltd_i);

	}
	void getLightShadowFraction(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].lsf\"",mName.c_str(),ltd_i);

	}
	void getPreShadowIntensity(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].psi\"",mName.c_str(),ltd_i);

	}
	void getLightBlindData(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].lbd\"",mName.c_str(),ltd_i);

	}
	void getOutValue()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	SurfaceLuminance(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SURFACELUMINANCE_H__
