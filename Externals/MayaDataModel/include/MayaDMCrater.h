/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CRATER_H__
#define __MayaDM_CRATER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class Crater : public Texture3d
{
public:
public:
	Crater():Texture3d(){}
	Crater(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "crater"){}
	virtual ~Crater(){}
	void setShaker(float sh)
	{
		if(sh == 1.5) return;
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
		if(c2 == float3(0.0f,1.0f,0.0f)) return;
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
	void setChannel3(const float3& c3)
	{
		if(c3 == float3(0.0f,0.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".c3\" -type \"float3\" ");
		c3.write(mFile);
		fprintf(mFile,";\n");

	}
	void setChannel3R(float c3r)
	{
		if(c3r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c3.c3r\" %f;\n", c3r);

	}
	void setChannel3G(float c3g)
	{
		if(c3g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c3.c3g\" %f;\n", c3g);

	}
	void setChannel3B(float c3b)
	{
		if(c3b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c3.c3b\" %f;\n", c3b);

	}
	void setMelt(float m)
	{
		if(m == 0.0) return;
		fprintf(mFile,"\tsetAttr \".m\" %f;\n", m);

	}
	void setBalance(float ba)
	{
		if(ba == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ba\" %f;\n", ba);

	}
	void setFrequency(float fr)
	{
		if(fr == 2.0) return;
		fprintf(mFile,"\tsetAttr \".fr\" %f;\n", fr);

	}
	void setNormDepth(float nd)
	{
		if(nd == 5.0) return;
		fprintf(mFile,"\tsetAttr \".nd\" %f;\n", nd);

	}
	void setNormMelt(float nm)
	{
		if(nm == 0.0) return;
		fprintf(mFile,"\tsetAttr \".nm\" %f;\n", nm);

	}
	void setNormBalance(float nb)
	{
		if(nb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nb\" %f;\n", nb);

	}
	void setNormFrequency(float nf)
	{
		if(nf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nf\" %f;\n", nf);

	}
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
	void getRefPointObj()
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());

	}
	void getRefPointObjX()
	{
		fprintf(mFile,"\"%s.rpo.rox\"",mName.c_str());

	}
	void getRefPointObjY()
	{
		fprintf(mFile,"\"%s.rpo.roy\"",mName.c_str());

	}
	void getRefPointObjZ()
	{
		fprintf(mFile,"\"%s.rpo.roz\"",mName.c_str());

	}
	void getRefPointCamera()
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());

	}
	void getRefPointCameraX()
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());

	}
	void getRefPointCameraY()
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());

	}
	void getRefPointCameraZ()
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());

	}
	void getShaker()
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());

	}
	void getChannel1()
	{
		fprintf(mFile,"\"%s.c1\"",mName.c_str());

	}
	void getChannel1R()
	{
		fprintf(mFile,"\"%s.c1.c1r\"",mName.c_str());

	}
	void getChannel1G()
	{
		fprintf(mFile,"\"%s.c1.c1g\"",mName.c_str());

	}
	void getChannel1B()
	{
		fprintf(mFile,"\"%s.c1.c1b\"",mName.c_str());

	}
	void getChannel2()
	{
		fprintf(mFile,"\"%s.c2\"",mName.c_str());

	}
	void getChannel2R()
	{
		fprintf(mFile,"\"%s.c2.c2r\"",mName.c_str());

	}
	void getChannel2G()
	{
		fprintf(mFile,"\"%s.c2.c2g\"",mName.c_str());

	}
	void getChannel2B()
	{
		fprintf(mFile,"\"%s.c2.c2b\"",mName.c_str());

	}
	void getChannel3()
	{
		fprintf(mFile,"\"%s.c3\"",mName.c_str());

	}
	void getChannel3R()
	{
		fprintf(mFile,"\"%s.c3.c3r\"",mName.c_str());

	}
	void getChannel3G()
	{
		fprintf(mFile,"\"%s.c3.c3g\"",mName.c_str());

	}
	void getChannel3B()
	{
		fprintf(mFile,"\"%s.c3.c3b\"",mName.c_str());

	}
	void getMelt()
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());

	}
	void getBalance()
	{
		fprintf(mFile,"\"%s.ba\"",mName.c_str());

	}
	void getFrequency()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getNormDepth()
	{
		fprintf(mFile,"\"%s.nd\"",mName.c_str());

	}
	void getNormMelt()
	{
		fprintf(mFile,"\"%s.nm\"",mName.c_str());

	}
	void getNormBalance()
	{
		fprintf(mFile,"\"%s.nb\"",mName.c_str());

	}
	void getNormFrequency()
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());

	}
	void getOutNormal()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOutNormalX()
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());

	}
	void getOutNormalY()
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());

	}
	void getOutNormalZ()
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());

	}
protected:
	Crater(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Texture3d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CRATER_H__
