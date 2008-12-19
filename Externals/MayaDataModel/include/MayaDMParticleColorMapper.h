/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLECOLORMAPPER_H__
#define __MayaDM_PARTICLECOLORMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ParticleColorMapper : public DependNode
{
public:
public:
	ParticleColorMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleColorMapper"){}
	virtual ~ParticleColorMapper(){}
	void setParticleColor(const float3& pc)
	{
		fprintf(mFile,"setAttr \".pc\" -type \"float3\" ");
		pc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setParticleColorR(float pcr)
	{
		if(pcr == 0.0) return;
		fprintf(mFile,"setAttr \".pc.pcr\" %f;\n", pcr);

	}
	void setParticleColorG(float pcg)
	{
		if(pcg == 0.0) return;
		fprintf(mFile,"setAttr \".pc.pcg\" %f;\n", pcg);

	}
	void setParticleColorB(float pcb)
	{
		if(pcb == 0.0) return;
		fprintf(mFile,"setAttr \".pc.pcb\" %f;\n", pcb);

	}
	void getParticleColor()
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());

	}
	void getParticleColorR()
	{
		fprintf(mFile,"\"%s.pc.pcr\"",mName.c_str());

	}
	void getParticleColorG()
	{
		fprintf(mFile,"\"%s.pc.pcg\"",mName.c_str());

	}
	void getParticleColorB()
	{
		fprintf(mFile,"\"%s.pc.pcb\"",mName.c_str());

	}
protected:
	ParticleColorMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLECOLORMAPPER_H__
