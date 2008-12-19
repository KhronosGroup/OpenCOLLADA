/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLEAGEMAPPER_H__
#define __MayaDM_PARTICLEAGEMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ParticleAgeMapper : public DependNode
{
public:
public:
	ParticleAgeMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleAgeMapper"){}
	virtual ~ParticleAgeMapper(){}
	void setRelativeAge(bool rea)
	{
		if(rea == false) return;
		fprintf(mFile,"setAttr \".rea\" %i;\n", rea);

	}
	void setTimeScale(float ts)
	{
		if(ts == 1) return;
		fprintf(mFile,"setAttr \".ts\" %f;\n", ts);

	}
	void setFoldAtEnd(bool fae)
	{
		if(fae == false) return;
		fprintf(mFile,"setAttr \".fae\" %i;\n", fae);

	}
	void getOutUvCoord()
	{
		fprintf(mFile,"\"%s.ouv\"",mName.c_str());

	}
	void getOutUCoord()
	{
		fprintf(mFile,"\"%s.ouv.ouc\"",mName.c_str());

	}
	void getOutVCoord()
	{
		fprintf(mFile,"\"%s.ouv.ovc\"",mName.c_str());

	}
	void getParticleAge()
	{
		fprintf(mFile,"\"%s.pa\"",mName.c_str());

	}
	void getParticleLifespan()
	{
		fprintf(mFile,"\"%s.pls\"",mName.c_str());

	}
	void getRelativeAge()
	{
		fprintf(mFile,"\"%s.rea\"",mName.c_str());

	}
	void getTimeScale()
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());

	}
	void getFoldAtEnd()
	{
		fprintf(mFile,"\"%s.fae\"",mName.c_str());

	}
protected:
	ParticleAgeMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLEAGEMAPPER_H__
