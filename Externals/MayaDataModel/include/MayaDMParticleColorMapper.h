/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	ParticleColorMapper():DependNode(){}
	ParticleColorMapper(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "particleColorMapper", shared, create){}
	virtual ~ParticleColorMapper(){}

	void setParticleColor(const float3& pc)
	{
		fprintf(mFile,"\tsetAttr \".pc\" -type \"float3\" ");
		pc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setParticleColorR(float pcr)
	{
		if(pcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pc.pcr\" %f;\n", pcr);
	}
	void setParticleColorG(float pcg)
	{
		if(pcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pc.pcg\" %f;\n", pcg);
	}
	void setParticleColorB(float pcb)
	{
		if(pcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pc.pcb\" %f;\n", pcb);
	}
	void getParticleColor()const
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getParticleColorR()const
	{
		fprintf(mFile,"\"%s.pc.pcr\"",mName.c_str());
	}
	void getParticleColorG()const
	{
		fprintf(mFile,"\"%s.pc.pcg\"",mName.c_str());
	}
	void getParticleColorB()const
	{
		fprintf(mFile,"\"%s.pc.pcb\"",mName.c_str());
	}
protected:
	ParticleColorMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLECOLORMAPPER_H__
