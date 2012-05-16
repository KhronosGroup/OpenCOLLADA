/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLESAMPLERINFO_H__
#define __MayaDM_PARTICLESAMPLERINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ParticleSamplerInfo : public DependNode
{
public:
public:

	ParticleSamplerInfo():DependNode(){}
	ParticleSamplerInfo(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "particleSamplerInfo", shared, create){}
	virtual ~ParticleSamplerInfo(){}

	void setOutUvType(unsigned int ouvt)
	{
		if(ouvt == 0) return;
		fprintf(mFile,"\tsetAttr \".ouvt\" %i;\n", ouvt);
	}
	void setNormalizationValue(float nlv)
	{
		if(nlv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nlv\" %f;\n", nlv);
	}
	void setNormalizationMethod(unsigned int nlm)
	{
		if(nlm == 0) return;
		fprintf(mFile,"\tsetAttr \".nlm\" %i;\n", nlm);
	}
	void setInverseOutUv(bool iouv)
	{
		if(iouv == false) return;
		fprintf(mFile,"\tsetAttr \".iouv\" %i;\n", iouv);
	}
	void getParticleAttrArray()const
	{
		fprintf(mFile,"\"%s.paa\"",mName.c_str());
	}
	void getParticleOrder()const
	{
		fprintf(mFile,"\"%s.podr\"",mName.c_str());
	}
	void getObjectType()const
	{
		fprintf(mFile,"\"%s.otyp\"",mName.c_str());
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
	void getParticleTransparency()const
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());
	}
	void getParticleTransparencyR()const
	{
		fprintf(mFile,"\"%s.pt.ptr\"",mName.c_str());
	}
	void getParticleTransparencyG()const
	{
		fprintf(mFile,"\"%s.pt.ptg\"",mName.c_str());
	}
	void getParticleTransparencyB()const
	{
		fprintf(mFile,"\"%s.pt.ptb\"",mName.c_str());
	}
	void getParticleIncandescence()const
	{
		fprintf(mFile,"\"%s.pi\"",mName.c_str());
	}
	void getParticleIncandescenceR()const
	{
		fprintf(mFile,"\"%s.pi.pir\"",mName.c_str());
	}
	void getParticleIncandescenceG()const
	{
		fprintf(mFile,"\"%s.pi.pig\"",mName.c_str());
	}
	void getParticleIncandescenceB()const
	{
		fprintf(mFile,"\"%s.pi.pib\"",mName.c_str());
	}
	void getParticleAge()const
	{
		fprintf(mFile,"\"%s.pa\"",mName.c_str());
	}
	void getParticleLifespan()const
	{
		fprintf(mFile,"\"%s.pls\"",mName.c_str());
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
	void getOutUvType()const
	{
		fprintf(mFile,"\"%s.ouvt\"",mName.c_str());
	}
	void getNormalizationValue()const
	{
		fprintf(mFile,"\"%s.nlv\"",mName.c_str());
	}
	void getNormalizationMethod()const
	{
		fprintf(mFile,"\"%s.nlm\"",mName.c_str());
	}
	void getInverseOutUv()const
	{
		fprintf(mFile,"\"%s.iouv\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());
	}
	void getOutTransparency()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getOutTransparencyR()const
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());
	}
	void getOutTransparencyG()const
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());
	}
	void getOutTransparencyB()const
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());
	}
	void getOutIncandescence()const
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());
	}
	void getOutIncandescenceR()const
	{
		fprintf(mFile,"\"%s.oi.oicr\"",mName.c_str());
	}
	void getOutIncandescenceG()const
	{
		fprintf(mFile,"\"%s.oi.oicg\"",mName.c_str());
	}
	void getOutIncandescenceB()const
	{
		fprintf(mFile,"\"%s.oi.oicb\"",mName.c_str());
	}
	void getFinalLifespanPP()const
	{
		fprintf(mFile,"\"%s.flp\"",mName.c_str());
	}
	void getAgeNormalized()const
	{
		fprintf(mFile,"\"%s.anl\"",mName.c_str());
	}
	void getParticleId()const
	{
		fprintf(mFile,"\"%s.pid\"",mName.c_str());
	}
	void getAge()const
	{
		fprintf(mFile,"\"%s.ag\"",mName.c_str());
	}
	void getLifespan()const
	{
		fprintf(mFile,"\"%s.lsp\"",mName.c_str());
	}
	void getLifespanPP()const
	{
		fprintf(mFile,"\"%s.lpp\"",mName.c_str());
	}
	void getAcceleration()const
	{
		fprintf(mFile,"\"%s.acc\"",mName.c_str());
	}
	void getAccelerationX()const
	{
		fprintf(mFile,"\"%s.acc.accx\"",mName.c_str());
	}
	void getAccelerationY()const
	{
		fprintf(mFile,"\"%s.acc.accy\"",mName.c_str());
	}
	void getAccelerationZ()const
	{
		fprintf(mFile,"\"%s.acc.accz\"",mName.c_str());
	}
	void getBirthTime()const
	{
		fprintf(mFile,"\"%s.bt\"",mName.c_str());
	}
	void getForce()const
	{
		fprintf(mFile,"\"%s.frc\"",mName.c_str());
	}
	void getForceX()const
	{
		fprintf(mFile,"\"%s.frc.frx\"",mName.c_str());
	}
	void getForceY()const
	{
		fprintf(mFile,"\"%s.frc.fry\"",mName.c_str());
	}
	void getForceZ()const
	{
		fprintf(mFile,"\"%s.frc.frz\"",mName.c_str());
	}
	void getPosition()const
	{
		fprintf(mFile,"\"%s.pos\"",mName.c_str());
	}
	void getPositionX()const
	{
		fprintf(mFile,"\"%s.pos.posx\"",mName.c_str());
	}
	void getPositionY()const
	{
		fprintf(mFile,"\"%s.pos.posy\"",mName.c_str());
	}
	void getPositionZ()const
	{
		fprintf(mFile,"\"%s.pos.posz\"",mName.c_str());
	}
	void getBirthPosition()const
	{
		fprintf(mFile,"\"%s.bpos\"",mName.c_str());
	}
	void getBirthPositionX()const
	{
		fprintf(mFile,"\"%s.bpos.bpox\"",mName.c_str());
	}
	void getBirthPositionY()const
	{
		fprintf(mFile,"\"%s.bpos.bpoy\"",mName.c_str());
	}
	void getBirthPositionZ()const
	{
		fprintf(mFile,"\"%s.bpos.bpoz\"",mName.c_str());
	}
	void getBirthWorldPosition()const
	{
		fprintf(mFile,"\"%s.bwpo\"",mName.c_str());
	}
	void getBirthWorldPositionX()const
	{
		fprintf(mFile,"\"%s.bwpo.bwpx\"",mName.c_str());
	}
	void getBirthWorldPositionY()const
	{
		fprintf(mFile,"\"%s.bwpo.bwpy\"",mName.c_str());
	}
	void getBirthWorldPositionZ()const
	{
		fprintf(mFile,"\"%s.bwpo.bwpz\"",mName.c_str());
	}
	void getVelocity()const
	{
		fprintf(mFile,"\"%s.vel\"",mName.c_str());
	}
	void getVelocityX()const
	{
		fprintf(mFile,"\"%s.vel.velx\"",mName.c_str());
	}
	void getVelocityY()const
	{
		fprintf(mFile,"\"%s.vel.vely\"",mName.c_str());
	}
	void getVelocityZ()const
	{
		fprintf(mFile,"\"%s.vel.velz\"",mName.c_str());
	}
	void getWorldPosition()const
	{
		fprintf(mFile,"\"%s.wps\"",mName.c_str());
	}
	void getWorldPositionX()const
	{
		fprintf(mFile,"\"%s.wps.wpsx\"",mName.c_str());
	}
	void getWorldPositionY()const
	{
		fprintf(mFile,"\"%s.wps.wpsy\"",mName.c_str());
	}
	void getWorldPositionZ()const
	{
		fprintf(mFile,"\"%s.wps.wpsz\"",mName.c_str());
	}
	void getWorldVelocity()const
	{
		fprintf(mFile,"\"%s.wvl\"",mName.c_str());
	}
	void getWorldVelocityX()const
	{
		fprintf(mFile,"\"%s.wvl.wvlx\"",mName.c_str());
	}
	void getWorldVelocityY()const
	{
		fprintf(mFile,"\"%s.wvl.wvly\"",mName.c_str());
	}
	void getWorldVelocityZ()const
	{
		fprintf(mFile,"\"%s.wvl.wvlz\"",mName.c_str());
	}
	void getParentU()const
	{
		fprintf(mFile,"\"%s.pau\"",mName.c_str());
	}
	void getParentV()const
	{
		fprintf(mFile,"\"%s.pav\"",mName.c_str());
	}
	void getCollisionU()const
	{
		fprintf(mFile,"\"%s.clu\"",mName.c_str());
	}
	void getCollisionV()const
	{
		fprintf(mFile,"\"%s.clv\"",mName.c_str());
	}
	void getColorRed()const
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getColorGreen()const
	{
		fprintf(mFile,"\"%s.cg\"",mName.c_str());
	}
	void getColorBlue()const
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());
	}
	void getRgbPP()const
	{
		fprintf(mFile,"\"%s.rgb\"",mName.c_str());
	}
	void getRPP()const
	{
		fprintf(mFile,"\"%s.rgb.rpp\"",mName.c_str());
	}
	void getGPP()const
	{
		fprintf(mFile,"\"%s.rgb.gpp\"",mName.c_str());
	}
	void getBPP()const
	{
		fprintf(mFile,"\"%s.rgb.bpp\"",mName.c_str());
	}
	void getIncandescencePP()const
	{
		fprintf(mFile,"\"%s.oipp\"",mName.c_str());
	}
	void getIncandescencePPR()const
	{
		fprintf(mFile,"\"%s.oipp.ippr\"",mName.c_str());
	}
	void getIncandescencePPG()const
	{
		fprintf(mFile,"\"%s.oipp.ippg\"",mName.c_str());
	}
	void getIncandescencePPB()const
	{
		fprintf(mFile,"\"%s.oipp.ippb\"",mName.c_str());
	}
	void getIncandescence()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getIncandescenceR()const
	{
		fprintf(mFile,"\"%s.in.inr\"",mName.c_str());
	}
	void getIncandescenceG()const
	{
		fprintf(mFile,"\"%s.in.ing\"",mName.c_str());
	}
	void getIncandescenceB()const
	{
		fprintf(mFile,"\"%s.in.inb\"",mName.c_str());
	}
	void getOpacity()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getOpacityPP()const
	{
		fprintf(mFile,"\"%s.opp\"",mName.c_str());
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.rds\"",mName.c_str());
	}
	void getRadiusPP()const
	{
		fprintf(mFile,"\"%s.rdp\"",mName.c_str());
	}
	void getUserScalar1PP()const
	{
		fprintf(mFile,"\"%s.uds1\"",mName.c_str());
	}
	void getUserScalar2PP()const
	{
		fprintf(mFile,"\"%s.uds2\"",mName.c_str());
	}
	void getUserScalar3PP()const
	{
		fprintf(mFile,"\"%s.uds3\"",mName.c_str());
	}
	void getUserScalar4PP()const
	{
		fprintf(mFile,"\"%s.uds4\"",mName.c_str());
	}
	void getUserScalar5PP()const
	{
		fprintf(mFile,"\"%s.uds5\"",mName.c_str());
	}
	void getUserVector1PP()const
	{
		fprintf(mFile,"\"%s.udv1\"",mName.c_str());
	}
	void getUserVector1PPX()const
	{
		fprintf(mFile,"\"%s.udv1.uv1x\"",mName.c_str());
	}
	void getUserVector1PPY()const
	{
		fprintf(mFile,"\"%s.udv1.uv1y\"",mName.c_str());
	}
	void getUserVector1PPZ()const
	{
		fprintf(mFile,"\"%s.udv1.uv1z\"",mName.c_str());
	}
	void getUserVector2PP()const
	{
		fprintf(mFile,"\"%s.udv2\"",mName.c_str());
	}
	void getUserVector2PPX()const
	{
		fprintf(mFile,"\"%s.udv2.uv2x\"",mName.c_str());
	}
	void getUserVector2PPY()const
	{
		fprintf(mFile,"\"%s.udv2.uv2y\"",mName.c_str());
	}
	void getUserVector2PPZ()const
	{
		fprintf(mFile,"\"%s.udv2.uv2z\"",mName.c_str());
	}
	void getUserVector3PP()const
	{
		fprintf(mFile,"\"%s.udv3\"",mName.c_str());
	}
	void getUserVector3PPX()const
	{
		fprintf(mFile,"\"%s.udv3.uv3x\"",mName.c_str());
	}
	void getUserVector3PPY()const
	{
		fprintf(mFile,"\"%s.udv3.uv3y\"",mName.c_str());
	}
	void getUserVector3PPZ()const
	{
		fprintf(mFile,"\"%s.udv3.uv3z\"",mName.c_str());
	}
	void getUserVector4PP()const
	{
		fprintf(mFile,"\"%s.udv4\"",mName.c_str());
	}
	void getUserVector4PPX()const
	{
		fprintf(mFile,"\"%s.udv4.uv4x\"",mName.c_str());
	}
	void getUserVector4PPY()const
	{
		fprintf(mFile,"\"%s.udv4.uv4y\"",mName.c_str());
	}
	void getUserVector4PPZ()const
	{
		fprintf(mFile,"\"%s.udv4.uv4z\"",mName.c_str());
	}
	void getUserVector5PP()const
	{
		fprintf(mFile,"\"%s.udv5\"",mName.c_str());
	}
	void getUserVector5PPX()const
	{
		fprintf(mFile,"\"%s.udv5.uv5x\"",mName.c_str());
	}
	void getUserVector5PPY()const
	{
		fprintf(mFile,"\"%s.udv5.uv5y\"",mName.c_str());
	}
	void getUserVector5PPZ()const
	{
		fprintf(mFile,"\"%s.udv5.uv5z\"",mName.c_str());
	}
protected:
	ParticleSamplerInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLESAMPLERINFO_H__
