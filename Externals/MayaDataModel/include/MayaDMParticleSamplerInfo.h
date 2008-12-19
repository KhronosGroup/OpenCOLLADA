/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	ParticleSamplerInfo(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleSamplerInfo"){}
	virtual ~ParticleSamplerInfo(){}
	void setOutUvType(unsigned int ouvt)
	{
		if(ouvt == 0) return;
		fprintf(mFile,"setAttr \".ouvt\" %i;\n", ouvt);

	}
	void setNormalizationValue(float nlv)
	{
		if(nlv == 1.0) return;
		fprintf(mFile,"setAttr \".nlv\" %f;\n", nlv);

	}
	void setNormalizationMethod(unsigned int nlm)
	{
		if(nlm == 0) return;
		fprintf(mFile,"setAttr \".nlm\" %i;\n", nlm);

	}
	void setInverseOutUv(bool iouv)
	{
		if(iouv == false) return;
		fprintf(mFile,"setAttr \".iouv\" %i;\n", iouv);

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
	void getOutUvType()
	{
		fprintf(mFile,"\"%s.ouvt\"",mName.c_str());

	}
	void getNormalizationValue()
	{
		fprintf(mFile,"\"%s.nlv\"",mName.c_str());

	}
	void getNormalizationMethod()
	{
		fprintf(mFile,"\"%s.nlm\"",mName.c_str());

	}
	void getInverseOutUv()
	{
		fprintf(mFile,"\"%s.iouv\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());

	}
	void getOutTransparency()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getOutTransparencyR()
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());

	}
	void getOutTransparencyG()
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());

	}
	void getOutTransparencyB()
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());

	}
	void getOutIncandescence()
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());

	}
	void getOutIncandescenceR()
	{
		fprintf(mFile,"\"%s.oi.oicr\"",mName.c_str());

	}
	void getOutIncandescenceG()
	{
		fprintf(mFile,"\"%s.oi.oicg\"",mName.c_str());

	}
	void getOutIncandescenceB()
	{
		fprintf(mFile,"\"%s.oi.oicb\"",mName.c_str());

	}
	void getFinalLifespanPP()
	{
		fprintf(mFile,"\"%s.flp\"",mName.c_str());

	}
	void getAgeNormalized()
	{
		fprintf(mFile,"\"%s.anl\"",mName.c_str());

	}
	void getParticleId()
	{
		fprintf(mFile,"\"%s.pid\"",mName.c_str());

	}
	void getAge()
	{
		fprintf(mFile,"\"%s.ag\"",mName.c_str());

	}
	void getLifespan()
	{
		fprintf(mFile,"\"%s.lsp\"",mName.c_str());

	}
	void getLifespanPP()
	{
		fprintf(mFile,"\"%s.lpp\"",mName.c_str());

	}
	void getAcceleration()
	{
		fprintf(mFile,"\"%s.acc\"",mName.c_str());

	}
	void getAccelerationX()
	{
		fprintf(mFile,"\"%s.acc.accx\"",mName.c_str());

	}
	void getAccelerationY()
	{
		fprintf(mFile,"\"%s.acc.accy\"",mName.c_str());

	}
	void getAccelerationZ()
	{
		fprintf(mFile,"\"%s.acc.accz\"",mName.c_str());

	}
	void getBirthTime()
	{
		fprintf(mFile,"\"%s.bt\"",mName.c_str());

	}
	void getForce()
	{
		fprintf(mFile,"\"%s.frc\"",mName.c_str());

	}
	void getForceX()
	{
		fprintf(mFile,"\"%s.frc.frx\"",mName.c_str());

	}
	void getForceY()
	{
		fprintf(mFile,"\"%s.frc.fry\"",mName.c_str());

	}
	void getForceZ()
	{
		fprintf(mFile,"\"%s.frc.frz\"",mName.c_str());

	}
	void getPosition()
	{
		fprintf(mFile,"\"%s.pos\"",mName.c_str());

	}
	void getPositionX()
	{
		fprintf(mFile,"\"%s.pos.posx\"",mName.c_str());

	}
	void getPositionY()
	{
		fprintf(mFile,"\"%s.pos.posy\"",mName.c_str());

	}
	void getPositionZ()
	{
		fprintf(mFile,"\"%s.pos.posz\"",mName.c_str());

	}
	void getBirthPosition()
	{
		fprintf(mFile,"\"%s.bpos\"",mName.c_str());

	}
	void getBirthPositionX()
	{
		fprintf(mFile,"\"%s.bpos.bpox\"",mName.c_str());

	}
	void getBirthPositionY()
	{
		fprintf(mFile,"\"%s.bpos.bpoy\"",mName.c_str());

	}
	void getBirthPositionZ()
	{
		fprintf(mFile,"\"%s.bpos.bpoz\"",mName.c_str());

	}
	void getBirthWorldPosition()
	{
		fprintf(mFile,"\"%s.bwpo\"",mName.c_str());

	}
	void getBirthWorldPositionX()
	{
		fprintf(mFile,"\"%s.bwpo.bwpx\"",mName.c_str());

	}
	void getBirthWorldPositionY()
	{
		fprintf(mFile,"\"%s.bwpo.bwpy\"",mName.c_str());

	}
	void getBirthWorldPositionZ()
	{
		fprintf(mFile,"\"%s.bwpo.bwpz\"",mName.c_str());

	}
	void getVelocity()
	{
		fprintf(mFile,"\"%s.vel\"",mName.c_str());

	}
	void getVelocityX()
	{
		fprintf(mFile,"\"%s.vel.velx\"",mName.c_str());

	}
	void getVelocityY()
	{
		fprintf(mFile,"\"%s.vel.vely\"",mName.c_str());

	}
	void getVelocityZ()
	{
		fprintf(mFile,"\"%s.vel.velz\"",mName.c_str());

	}
	void getWorldPosition()
	{
		fprintf(mFile,"\"%s.wps\"",mName.c_str());

	}
	void getWorldPositionX()
	{
		fprintf(mFile,"\"%s.wps.wpsx\"",mName.c_str());

	}
	void getWorldPositionY()
	{
		fprintf(mFile,"\"%s.wps.wpsy\"",mName.c_str());

	}
	void getWorldPositionZ()
	{
		fprintf(mFile,"\"%s.wps.wpsz\"",mName.c_str());

	}
	void getWorldVelocity()
	{
		fprintf(mFile,"\"%s.wvl\"",mName.c_str());

	}
	void getWorldVelocityX()
	{
		fprintf(mFile,"\"%s.wvl.wvlx\"",mName.c_str());

	}
	void getWorldVelocityY()
	{
		fprintf(mFile,"\"%s.wvl.wvly\"",mName.c_str());

	}
	void getWorldVelocityZ()
	{
		fprintf(mFile,"\"%s.wvl.wvlz\"",mName.c_str());

	}
	void getParentU()
	{
		fprintf(mFile,"\"%s.pau\"",mName.c_str());

	}
	void getParentV()
	{
		fprintf(mFile,"\"%s.pav\"",mName.c_str());

	}
	void getCollisionU()
	{
		fprintf(mFile,"\"%s.clu\"",mName.c_str());

	}
	void getCollisionV()
	{
		fprintf(mFile,"\"%s.clv\"",mName.c_str());

	}
	void getColorRed()
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());

	}
	void getColorGreen()
	{
		fprintf(mFile,"\"%s.cg\"",mName.c_str());

	}
	void getColorBlue()
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());

	}
	void getRgbPP()
	{
		fprintf(mFile,"\"%s.rgb\"",mName.c_str());

	}
	void getRPP()
	{
		fprintf(mFile,"\"%s.rgb.rpp\"",mName.c_str());

	}
	void getGPP()
	{
		fprintf(mFile,"\"%s.rgb.gpp\"",mName.c_str());

	}
	void getBPP()
	{
		fprintf(mFile,"\"%s.rgb.bpp\"",mName.c_str());

	}
	void getIncandescencePP()
	{
		fprintf(mFile,"\"%s.oipp\"",mName.c_str());

	}
	void getIncandescencePPR()
	{
		fprintf(mFile,"\"%s.oipp.ippr\"",mName.c_str());

	}
	void getIncandescencePPG()
	{
		fprintf(mFile,"\"%s.oipp.ippg\"",mName.c_str());

	}
	void getIncandescencePPB()
	{
		fprintf(mFile,"\"%s.oipp.ippb\"",mName.c_str());

	}
	void getIncandescence()
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());

	}
	void getIncandescenceR()
	{
		fprintf(mFile,"\"%s.in.inr\"",mName.c_str());

	}
	void getIncandescenceG()
	{
		fprintf(mFile,"\"%s.in.ing\"",mName.c_str());

	}
	void getIncandescenceB()
	{
		fprintf(mFile,"\"%s.in.inb\"",mName.c_str());

	}
	void getOpacity()
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());

	}
	void getOpacityPP()
	{
		fprintf(mFile,"\"%s.opp\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.rds\"",mName.c_str());

	}
	void getRadiusPP()
	{
		fprintf(mFile,"\"%s.rdp\"",mName.c_str());

	}
	void getUserScalar1PP()
	{
		fprintf(mFile,"\"%s.uds1\"",mName.c_str());

	}
	void getUserScalar2PP()
	{
		fprintf(mFile,"\"%s.uds2\"",mName.c_str());

	}
	void getUserScalar3PP()
	{
		fprintf(mFile,"\"%s.uds3\"",mName.c_str());

	}
	void getUserScalar4PP()
	{
		fprintf(mFile,"\"%s.uds4\"",mName.c_str());

	}
	void getUserScalar5PP()
	{
		fprintf(mFile,"\"%s.uds5\"",mName.c_str());

	}
	void getUserVector1PP()
	{
		fprintf(mFile,"\"%s.udv1\"",mName.c_str());

	}
	void getUserVector1PPX()
	{
		fprintf(mFile,"\"%s.udv1.uv1x\"",mName.c_str());

	}
	void getUserVector1PPY()
	{
		fprintf(mFile,"\"%s.udv1.uv1y\"",mName.c_str());

	}
	void getUserVector1PPZ()
	{
		fprintf(mFile,"\"%s.udv1.uv1z\"",mName.c_str());

	}
	void getUserVector2PP()
	{
		fprintf(mFile,"\"%s.udv2\"",mName.c_str());

	}
	void getUserVector2PPX()
	{
		fprintf(mFile,"\"%s.udv2.uv2x\"",mName.c_str());

	}
	void getUserVector2PPY()
	{
		fprintf(mFile,"\"%s.udv2.uv2y\"",mName.c_str());

	}
	void getUserVector2PPZ()
	{
		fprintf(mFile,"\"%s.udv2.uv2z\"",mName.c_str());

	}
	void getUserVector3PP()
	{
		fprintf(mFile,"\"%s.udv3\"",mName.c_str());

	}
	void getUserVector3PPX()
	{
		fprintf(mFile,"\"%s.udv3.uv3x\"",mName.c_str());

	}
	void getUserVector3PPY()
	{
		fprintf(mFile,"\"%s.udv3.uv3y\"",mName.c_str());

	}
	void getUserVector3PPZ()
	{
		fprintf(mFile,"\"%s.udv3.uv3z\"",mName.c_str());

	}
	void getUserVector4PP()
	{
		fprintf(mFile,"\"%s.udv4\"",mName.c_str());

	}
	void getUserVector4PPX()
	{
		fprintf(mFile,"\"%s.udv4.uv4x\"",mName.c_str());

	}
	void getUserVector4PPY()
	{
		fprintf(mFile,"\"%s.udv4.uv4y\"",mName.c_str());

	}
	void getUserVector4PPZ()
	{
		fprintf(mFile,"\"%s.udv4.uv4z\"",mName.c_str());

	}
	void getUserVector5PP()
	{
		fprintf(mFile,"\"%s.udv5\"",mName.c_str());

	}
	void getUserVector5PPX()
	{
		fprintf(mFile,"\"%s.udv5.uv5x\"",mName.c_str());

	}
	void getUserVector5PPY()
	{
		fprintf(mFile,"\"%s.udv5.uv5y\"",mName.c_str());

	}
	void getUserVector5PPZ()
	{
		fprintf(mFile,"\"%s.udv5.uv5z\"",mName.c_str());

	}
protected:
	ParticleSamplerInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLESAMPLERINFO_H__
