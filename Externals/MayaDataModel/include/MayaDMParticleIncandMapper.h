/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLEINCANDMAPPER_H__
#define __MayaDM_PARTICLEINCANDMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ParticleIncandMapper : public DependNode
{
public:
public:
	ParticleIncandMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleIncandMapper"){}
	virtual ~ParticleIncandMapper(){}
	void setParticleIncandescence(const float3& pi)
	{
		fprintf(mFile,"setAttr \".pi\" -type \"float3\" ");
		pi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setParticleIncandescenceR(float pir)
	{
		if(pir == 0.0) return;
		fprintf(mFile,"setAttr \".pi.pir\" %f;\n", pir);

	}
	void setParticleIncandescenceG(float pig)
	{
		if(pig == 0.0) return;
		fprintf(mFile,"setAttr \".pi.pig\" %f;\n", pig);

	}
	void setParticleIncandescenceB(float pib)
	{
		if(pib == 0.0) return;
		fprintf(mFile,"setAttr \".pi.pib\" %f;\n", pib);

	}
	void getParticleIncandescence()
	{
		fprintf(mFile,"\"%s.pi\"",mName.c_str());

	}
	void getParticleIncandescenceR()
	{
		fprintf(mFile,"\"%s.pi.pir\"",mName.c_str());

	}
	void getParticleIncandescenceG()
	{
		fprintf(mFile,"\"%s.pi.pig\"",mName.c_str());

	}
	void getParticleIncandescenceB()
	{
		fprintf(mFile,"\"%s.pi.pib\"",mName.c_str());

	}
protected:
	ParticleIncandMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLEINCANDMAPPER_H__
