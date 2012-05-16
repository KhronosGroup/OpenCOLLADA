/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STUCCO_H__
#define __MayaDM_STUCCO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class Stucco : public Texture3d
{
public:
public:

	Stucco():Texture3d(){}
	Stucco(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture3d(file, name, parent, "stucco", shared, create){}
	virtual ~Stucco(){}

	void setShaker(float sh)
	{
		if(sh == 20.0) return;
		fprintf(mFile,"\tsetAttr \".sh\" %f;\n", sh);
	}
	void setChannel1(const float3& c1)
	{
		if(c1 == float3(1.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".c1\" -type \"float3\" ");
		c1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setChannel1R(float c1r)
	{
		if(c1r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c1.c1r\" %f;\n", c1r);
	}
	void setChannel1G(float c1g)
	{
		if(c1g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c1.c1g\" %f;\n", c1g);
	}
	void setChannel1B(float c1b)
	{
		if(c1b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c1.c1b\" %f;\n", c1b);
	}
	void setChannel2(const float3& c2)
	{
		if(c2 == float3(0.0f,0.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".c2\" -type \"float3\" ");
		c2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setChannel2R(float c2r)
	{
		if(c2r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c2.c2r\" %f;\n", c2r);
	}
	void setChannel2G(float c2g)
	{
		if(c2g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c2.c2g\" %f;\n", c2g);
	}
	void setChannel2B(float c2b)
	{
		if(c2b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c2.c2b\" %f;\n", c2b);
	}
	void setNormalMelt(float nm)
	{
		if(nm == 0.1) return;
		fprintf(mFile,"\tsetAttr \".nm\" %f;\n", nm);
	}
	void setNormalDepth(float nd)
	{
		if(nd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nd\" %f;\n", nd);
	}
	void getRefPointObj()const
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());
	}
	void getRefPointObjX()const
	{
		fprintf(mFile,"\"%s.rpo.rox\"",mName.c_str());
	}
	void getRefPointObjY()const
	{
		fprintf(mFile,"\"%s.rpo.roy\"",mName.c_str());
	}
	void getRefPointObjZ()const
	{
		fprintf(mFile,"\"%s.rpo.roz\"",mName.c_str());
	}
	void getRefPointCamera()const
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());
	}
	void getRefPointCameraX()const
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());
	}
	void getRefPointCameraY()const
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());
	}
	void getRefPointCameraZ()const
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());
	}
	void getShaker()const
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());
	}
	void getChannel1()const
	{
		fprintf(mFile,"\"%s.c1\"",mName.c_str());
	}
	void getChannel1R()const
	{
		fprintf(mFile,"\"%s.c1.c1r\"",mName.c_str());
	}
	void getChannel1G()const
	{
		fprintf(mFile,"\"%s.c1.c1g\"",mName.c_str());
	}
	void getChannel1B()const
	{
		fprintf(mFile,"\"%s.c1.c1b\"",mName.c_str());
	}
	void getChannel2()const
	{
		fprintf(mFile,"\"%s.c2\"",mName.c_str());
	}
	void getChannel2R()const
	{
		fprintf(mFile,"\"%s.c2.c2r\"",mName.c_str());
	}
	void getChannel2G()const
	{
		fprintf(mFile,"\"%s.c2.c2g\"",mName.c_str());
	}
	void getChannel2B()const
	{
		fprintf(mFile,"\"%s.c2.c2b\"",mName.c_str());
	}
	void getNormalCamera()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNormalCameraX()const
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());
	}
	void getNormalCameraY()const
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());
	}
	void getNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());
	}
	void getNormalMelt()const
	{
		fprintf(mFile,"\"%s.nm\"",mName.c_str());
	}
	void getNormalDepth()const
	{
		fprintf(mFile,"\"%s.nd\"",mName.c_str());
	}
	void getOutNormal()const
	{
		fprintf(mFile,"\"%s.on\"",mName.c_str());
	}
	void getOutNormalX()const
	{
		fprintf(mFile,"\"%s.on.onx\"",mName.c_str());
	}
	void getOutNormalY()const
	{
		fprintf(mFile,"\"%s.on.ony\"",mName.c_str());
	}
	void getOutNormalZ()const
	{
		fprintf(mFile,"\"%s.on.onz\"",mName.c_str());
	}
protected:
	Stucco(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture3d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_STUCCO_H__
