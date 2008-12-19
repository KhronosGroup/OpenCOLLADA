/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVCUBE_H__
#define __MayaDM_ENVCUBE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTextureEnv.h"
namespace MayaDM
{
class EnvCube : public TextureEnv
{
public:
public:
	EnvCube(FILE* file,const std::string& name,const std::string& parent=""):TextureEnv(file, name, parent, "envCube"){}
	virtual ~EnvCube(){}
	void setPointWorld(const float3& pw)
	{
		fprintf(mFile,"setAttr \".pw\" -type \"float3\" ");
		pw.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPointWorldX(float pwx)
	{
		if(pwx == 0.0) return;
		fprintf(mFile,"setAttr \".pw.pwx\" %f;\n", pwx);

	}
	void setPointWorldY(float pwy)
	{
		if(pwy == 0.0) return;
		fprintf(mFile,"setAttr \".pw.pwy\" %f;\n", pwy);

	}
	void setPointWorldZ(float pwz)
	{
		if(pwz == 0.0) return;
		fprintf(mFile,"setAttr \".pw.pwz\" %f;\n", pwz);

	}
	void setInfiniteSize(bool ie)
	{
		if(ie == 0) return;
		fprintf(mFile,"setAttr \".ie\" %i;\n", ie);

	}
	void setLookupType(unsigned int lt)
	{
		if(lt == 0) return;
		fprintf(mFile,"setAttr \".lt\" %i;\n", lt);

	}
	void setLeft(const float3& le)
	{
		if(le == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".le\" -type \"float3\" ");
		le.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLeftR(float ler)
	{
		if(ler == 0.0) return;
		fprintf(mFile,"setAttr \".le.ler\" %f;\n", ler);

	}
	void setLeftG(float leg)
	{
		if(leg == 0.0) return;
		fprintf(mFile,"setAttr \".le.leg\" %f;\n", leg);

	}
	void setLeftB(float leb)
	{
		if(leb == 0.0) return;
		fprintf(mFile,"setAttr \".le.leb\" %f;\n", leb);

	}
	void setRight(const float3& ri)
	{
		if(ri == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".ri\" -type \"float3\" ");
		ri.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRightR(float rir)
	{
		if(rir == 0.0) return;
		fprintf(mFile,"setAttr \".ri.rir\" %f;\n", rir);

	}
	void setRightG(float rig)
	{
		if(rig == 0.0) return;
		fprintf(mFile,"setAttr \".ri.rig\" %f;\n", rig);

	}
	void setRightB(float rib)
	{
		if(rib == 0.0) return;
		fprintf(mFile,"setAttr \".ri.rib\" %f;\n", rib);

	}
	void setTop(const float3& to)
	{
		if(to == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".to\" -type \"float3\" ");
		to.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTopR(float tor)
	{
		if(tor == 0.0) return;
		fprintf(mFile,"setAttr \".to.tor\" %f;\n", tor);

	}
	void setTopG(float tog)
	{
		if(tog == 0.0) return;
		fprintf(mFile,"setAttr \".to.tog\" %f;\n", tog);

	}
	void setTopB(float tob)
	{
		if(tob == 0.0) return;
		fprintf(mFile,"setAttr \".to.tob\" %f;\n", tob);

	}
	void setBottom(const float3& bo)
	{
		if(bo == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".bo\" -type \"float3\" ");
		bo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBottomR(float bor)
	{
		if(bor == 0.0) return;
		fprintf(mFile,"setAttr \".bo.bor\" %f;\n", bor);

	}
	void setBottomG(float bog)
	{
		if(bog == 0.0) return;
		fprintf(mFile,"setAttr \".bo.bog\" %f;\n", bog);

	}
	void setBottomB(float bob)
	{
		if(bob == 0.0) return;
		fprintf(mFile,"setAttr \".bo.bob\" %f;\n", bob);

	}
	void setFront(const float3& fr)
	{
		if(fr == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".fr\" -type \"float3\" ");
		fr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFrontR(float frr)
	{
		if(frr == 0.0) return;
		fprintf(mFile,"setAttr \".fr.frr\" %f;\n", frr);

	}
	void setFrontG(float frg)
	{
		if(frg == 0.0) return;
		fprintf(mFile,"setAttr \".fr.frg\" %f;\n", frg);

	}
	void setFrontB(float frb)
	{
		if(frb == 0.0) return;
		fprintf(mFile,"setAttr \".fr.frb\" %f;\n", frb);

	}
	void setBack(const float3& ba)
	{
		if(ba == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".ba\" -type \"float3\" ");
		ba.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBackR(float bar)
	{
		if(bar == 0.0) return;
		fprintf(mFile,"setAttr \".ba.bar\" %f;\n", bar);

	}
	void setBackG(float bag)
	{
		if(bag == 0.0) return;
		fprintf(mFile,"setAttr \".ba.bag\" %f;\n", bag);

	}
	void setBackB(float bab)
	{
		if(bab == 0.0) return;
		fprintf(mFile,"setAttr \".ba.bab\" %f;\n", bab);

	}
	void getPointWorld()
	{
		fprintf(mFile,"\"%s.pw\"",mName.c_str());

	}
	void getPointWorldX()
	{
		fprintf(mFile,"\"%s.pw.pwx\"",mName.c_str());

	}
	void getPointWorldY()
	{
		fprintf(mFile,"\"%s.pw.pwy\"",mName.c_str());

	}
	void getPointWorldZ()
	{
		fprintf(mFile,"\"%s.pw.pwz\"",mName.c_str());

	}
	void getLeft()
	{
		fprintf(mFile,"\"%s.le\"",mName.c_str());

	}
	void getLeftR()
	{
		fprintf(mFile,"\"%s.le.ler\"",mName.c_str());

	}
	void getLeftG()
	{
		fprintf(mFile,"\"%s.le.leg\"",mName.c_str());

	}
	void getLeftB()
	{
		fprintf(mFile,"\"%s.le.leb\"",mName.c_str());

	}
	void getRight()
	{
		fprintf(mFile,"\"%s.ri\"",mName.c_str());

	}
	void getRightR()
	{
		fprintf(mFile,"\"%s.ri.rir\"",mName.c_str());

	}
	void getRightG()
	{
		fprintf(mFile,"\"%s.ri.rig\"",mName.c_str());

	}
	void getRightB()
	{
		fprintf(mFile,"\"%s.ri.rib\"",mName.c_str());

	}
	void getTop()
	{
		fprintf(mFile,"\"%s.to\"",mName.c_str());

	}
	void getTopR()
	{
		fprintf(mFile,"\"%s.to.tor\"",mName.c_str());

	}
	void getTopG()
	{
		fprintf(mFile,"\"%s.to.tog\"",mName.c_str());

	}
	void getTopB()
	{
		fprintf(mFile,"\"%s.to.tob\"",mName.c_str());

	}
	void getBottom()
	{
		fprintf(mFile,"\"%s.bo\"",mName.c_str());

	}
	void getBottomR()
	{
		fprintf(mFile,"\"%s.bo.bor\"",mName.c_str());

	}
	void getBottomG()
	{
		fprintf(mFile,"\"%s.bo.bog\"",mName.c_str());

	}
	void getBottomB()
	{
		fprintf(mFile,"\"%s.bo.bob\"",mName.c_str());

	}
	void getFront()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getFrontR()
	{
		fprintf(mFile,"\"%s.fr.frr\"",mName.c_str());

	}
	void getFrontG()
	{
		fprintf(mFile,"\"%s.fr.frg\"",mName.c_str());

	}
	void getFrontB()
	{
		fprintf(mFile,"\"%s.fr.frb\"",mName.c_str());

	}
	void getBack()
	{
		fprintf(mFile,"\"%s.ba\"",mName.c_str());

	}
	void getBackR()
	{
		fprintf(mFile,"\"%s.ba.bar\"",mName.c_str());

	}
	void getBackG()
	{
		fprintf(mFile,"\"%s.ba.bag\"",mName.c_str());

	}
	void getBackB()
	{
		fprintf(mFile,"\"%s.ba.bab\"",mName.c_str());

	}
	void getInfoBits()
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());

	}
protected:
	EnvCube(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):TextureEnv(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ENVCUBE_H__
