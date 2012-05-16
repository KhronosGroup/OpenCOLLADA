/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	ParticleAgeMapper():DependNode(){}
	ParticleAgeMapper(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "particleAgeMapper", shared, create){}
	virtual ~ParticleAgeMapper(){}

	void setRelativeAge(bool rea)
	{
		if(rea == false) return;
		fprintf(mFile,"\tsetAttr \".rea\" %i;\n", rea);
	}
	void setTimeScale(float ts)
	{
		if(ts == 1) return;
		fprintf(mFile,"\tsetAttr \".ts\" %f;\n", ts);
	}
	void setFoldAtEnd(bool fae)
	{
		if(fae == false) return;
		fprintf(mFile,"\tsetAttr \".fae\" %i;\n", fae);
	}
	void getOutUvCoord()const
	{
		fprintf(mFile,"\"%s.ouv\"",mName.c_str());
	}
	void getOutUCoord()const
	{
		fprintf(mFile,"\"%s.ouv.ouc\"",mName.c_str());
	}
	void getOutVCoord()const
	{
		fprintf(mFile,"\"%s.ouv.ovc\"",mName.c_str());
	}
	void getParticleAge()const
	{
		fprintf(mFile,"\"%s.pa\"",mName.c_str());
	}
	void getParticleLifespan()const
	{
		fprintf(mFile,"\"%s.pls\"",mName.c_str());
	}
	void getRelativeAge()const
	{
		fprintf(mFile,"\"%s.rea\"",mName.c_str());
	}
	void getTimeScale()const
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());
	}
	void getFoldAtEnd()const
	{
		fprintf(mFile,"\"%s.fae\"",mName.c_str());
	}
protected:
	ParticleAgeMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLEAGEMAPPER_H__
