/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RIGIDBODY_H__
#define __MayaDM_RIGIDBODY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class RigidBody : public Shape
{
public:
	struct FieldData{
		void write(FILE* file) const
		{
		}
	};
	struct GeneralForce{
		void write(FILE* file) const
		{
		}
	};
public:
	RigidBody(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "rigidBody"){}
	virtual ~RigidBody(){}
	void setRunUpCache(const doubleArray& rc)
	{
		if(rc.size == 0) return;
		fprintf(mFile,"setAttr \".rc\" -type \"doubleArray\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDataCache(const doubleArray& dc)
	{
		if(dc.size == 0) return;
		fprintf(mFile,"setAttr \".dc\" -type \"doubleArray\" ");
		dc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFirstCachedFrame(int fcf)
	{
		if(fcf == 0) return;
		fprintf(mFile,"setAttr \".fcf\" %i;\n", fcf);

	}
	void setLastCachedFrame(int lcf)
	{
		if(lcf == 0) return;
		fprintf(mFile,"setAttr \".lcf\" %i;\n", lcf);

	}
	void setCachedFrameCount(int cfc)
	{
		if(cfc == 0) return;
		fprintf(mFile,"setAttr \".cfc\" %i;\n", cfc);

	}
	void setInitialPosition(const double3& ip)
	{
		if(ip == double3(0, 0, 0)) return;
		fprintf(mFile,"setAttr \".ip\" -type \"double3\" ");
		ip.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInitialPositionX(double ipx)
	{
		if(ipx == 0.0) return;
		fprintf(mFile,"setAttr \".ip.ipx\" %f;\n", ipx);

	}
	void setInitialPositionY(double ipy)
	{
		if(ipy == 0.0) return;
		fprintf(mFile,"setAttr \".ip.ipy\" %f;\n", ipy);

	}
	void setInitialPositionZ(double ipz)
	{
		if(ipz == 0.0) return;
		fprintf(mFile,"setAttr \".ip.ipz\" %f;\n", ipz);

	}
	void setInitialOrientation(const double3& ior)
	{
		if(ior == double3(0, 0, 0)) return;
		fprintf(mFile,"setAttr \".ior\" -type \"double3\" ");
		ior.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInitialOrientationX(double iox)
	{
		if(iox == 0) return;
		fprintf(mFile,"setAttr \".ior.iox\" %f;\n", iox);

	}
	void setInitialOrientationY(double ioy)
	{
		if(ioy == 0) return;
		fprintf(mFile,"setAttr \".ior.ioy\" %f;\n", ioy);

	}
	void setInitialOrientationZ(double ioz)
	{
		if(ioz == 0) return;
		fprintf(mFile,"setAttr \".ior.ioz\" %f;\n", ioz);

	}
	void setInitialVelocity(const double3& iv)
	{
		if(iv == double3(0, 0, 0)) return;
		fprintf(mFile,"setAttr \".iv\" -type \"double3\" ");
		iv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInitialVelocityX(double ivx)
	{
		if(ivx == 0.0) return;
		fprintf(mFile,"setAttr \".iv.ivx\" %f;\n", ivx);

	}
	void setInitialVelocityY(double ivy)
	{
		if(ivy == 0.0) return;
		fprintf(mFile,"setAttr \".iv.ivy\" %f;\n", ivy);

	}
	void setInitialVelocityZ(double ivz)
	{
		if(ivz == 0.0) return;
		fprintf(mFile,"setAttr \".iv.ivz\" %f;\n", ivz);

	}
	void setInitialSpin(const double3& is)
	{
		if(is == double3(0, 0, 0)) return;
		fprintf(mFile,"setAttr \".is\" -type \"double3\" ");
		is.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInitialSpinX(double isx)
	{
		if(isx == 0) return;
		fprintf(mFile,"setAttr \".is.isx\" %f;\n", isx);

	}
	void setInitialSpinY(double isy)
	{
		if(isy == 0) return;
		fprintf(mFile,"setAttr \".is.isy\" %f;\n", isy);

	}
	void setInitialSpinZ(double isz)
	{
		if(isz == 0) return;
		fprintf(mFile,"setAttr \".is.isz\" %f;\n", isz);

	}
	void setCenterOfMass(const double3& com)
	{
		if(com == double3(0, 0, 0)) return;
		fprintf(mFile,"setAttr \".com\" -type \"double3\" ");
		com.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCenterOfMassX(double cmx)
	{
		if(cmx == 0.0) return;
		fprintf(mFile,"setAttr \".com.cmx\" %f;\n", cmx);

	}
	void setCenterOfMassY(double cmy)
	{
		if(cmy == 0.0) return;
		fprintf(mFile,"setAttr \".com.cmy\" %f;\n", cmy);

	}
	void setCenterOfMassZ(double cmz)
	{
		if(cmz == 0.0) return;
		fprintf(mFile,"setAttr \".com.cmz\" %f;\n", cmz);

	}
	void setImpulse(const double3& imp)
	{
		if(imp == double3(0, 0, 0)) return;
		fprintf(mFile,"setAttr \".imp\" -type \"double3\" ");
		imp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImpulseX(double imx)
	{
		if(imx == 0.0) return;
		fprintf(mFile,"setAttr \".imp.imx\" %f;\n", imx);

	}
	void setImpulseY(double imy)
	{
		if(imy == 0.0) return;
		fprintf(mFile,"setAttr \".imp.imy\" %f;\n", imy);

	}
	void setImpulseZ(double imz)
	{
		if(imz == 0.0) return;
		fprintf(mFile,"setAttr \".imp.imz\" %f;\n", imz);

	}
	void setImpulsePosition(const double3& ipo)
	{
		if(ipo == double3(0, 0, 0)) return;
		fprintf(mFile,"setAttr \".ipo\" -type \"double3\" ");
		ipo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImpulsePositionX(double pix)
	{
		if(pix == 0.0) return;
		fprintf(mFile,"setAttr \".ipo.pix\" %f;\n", pix);

	}
	void setImpulsePositionY(double piy)
	{
		if(piy == 0.0) return;
		fprintf(mFile,"setAttr \".ipo.piy\" %f;\n", piy);

	}
	void setImpulsePositionZ(double piz)
	{
		if(piz == 0.0) return;
		fprintf(mFile,"setAttr \".ipo.piz\" %f;\n", piz);

	}
	void setSpinImpulse(const double3& sim)
	{
		if(sim == double3(0, 0, 0)) return;
		fprintf(mFile,"setAttr \".sim\" -type \"double3\" ");
		sim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpinImpulseX(double six)
	{
		if(six == 0.0) return;
		fprintf(mFile,"setAttr \".sim.six\" %f;\n", six);

	}
	void setSpinImpulseY(double siy)
	{
		if(siy == 0.0) return;
		fprintf(mFile,"setAttr \".sim.siy\" %f;\n", siy);

	}
	void setSpinImpulseZ(double siz)
	{
		if(siz == 0.0) return;
		fprintf(mFile,"setAttr \".sim.siz\" %f;\n", siz);

	}
	void setMass(double mas)
	{
		if(mas == 1.0) return;
		fprintf(mFile,"setAttr \".mas\" %f;\n", mas);

	}
	void setBounciness(double b)
	{
		if(b == 0.6) return;
		fprintf(mFile,"setAttr \".b\" %f;\n", b);

	}
	void setDamping(double dp)
	{
		if(dp == 0.0) return;
		fprintf(mFile,"setAttr \".dp\" %f;\n", dp);

	}
	void setStaticFriction(double sf)
	{
		if(sf == 0.2) return;
		fprintf(mFile,"setAttr \".sf\" %f;\n", sf);

	}
	void setDynamicFriction(double df)
	{
		if(df == 0.2) return;
		fprintf(mFile,"setAttr \".df\" %f;\n", df);

	}
	void setCollisionLayer(int cl)
	{
		if(cl == 0) return;
		fprintf(mFile,"setAttr \".cl\" %i;\n", cl);

	}
	void setStandIn(unsigned int si)
	{
		if(si == 0) return;
		fprintf(mFile,"setAttr \".si\" %i;\n", si);

	}
	void setInputGeometryCnt(int igc)
	{
		if(igc == 0) return;
		fprintf(mFile,"setAttr \".igc\" %i;\n", igc);

	}
	void setActive(bool act)
	{
		if(act == true) return;
		fprintf(mFile,"setAttr \".act\" %i;\n", act);

	}
	void setChoice(int chc)
	{
		if(chc == 0) return;
		fprintf(mFile,"setAttr \".chc\" %i;\n", chc);

	}
	void setIsKinematic(bool kin)
	{
		if(kin == false) return;
		fprintf(mFile,"setAttr \".kin\" %i;\n", kin);

	}
	void setIsKeyframed(bool key)
	{
		if(key == false) return;
		fprintf(mFile,"setAttr \".key\" %i;\n", key);

	}
	void setIsParented(bool par)
	{
		if(par == false) return;
		fprintf(mFile,"setAttr \".par\" %i;\n", par);

	}
	void setParticleCollision(bool pc)
	{
		if(pc == false) return;
		fprintf(mFile,"setAttr \".pc\" %i;\n", pc);

	}
	void setAutoInit(bool ai)
	{
		if(ai == true) return;
		fprintf(mFile,"setAttr \".ai\" %i;\n", ai);

	}
	void setAllowDisconnection(bool ad)
	{
		if(ad == false) return;
		fprintf(mFile,"setAttr \".ad\" %i;\n", ad);

	}
	void setCacheData(bool idc)
	{
		if(idc == false) return;
		fprintf(mFile,"setAttr \".idc\" %i;\n", idc);

	}
	void setTessellationFactor(int tes)
	{
		if(tes == 200) return;
		fprintf(mFile,"setAttr \".tes\" %i;\n", tes);

	}
	void setInputForceType(size_t ift_i,bool ift)
	{
		if(ift == false) return;
		fprintf(mFile,"setAttr \".ift[%i]\" %i;\n", ift_i,ift);

	}
	void setInputForceType(size_t ift_start,size_t ift_end,bool* ift)
	{
		fprintf(mFile,"setAttr \".ift[%i:%i]\" ", ift_start,ift_end);
		size_t size = (ift_end-ift_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ift[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startInputForceType(size_t ift_start,size_t ift_end)
	{
		fprintf(mFile,"setAttr \".ift[%i:%i]\"",ift_start,ift_end);

	}
	void appendInputForceType(bool ift)
	{
		fprintf(mFile," %i",ift);

	}
	void endInputForceType()
	{
		fprintf(mFile,";\n");

	}
	void setSolverId(int sid)
	{
		if(sid == -1) return;
		fprintf(mFile,"setAttr \".sid\" %i;\n", sid);

	}
	void setBakeSimulationIndex(int bsi)
	{
		if(bsi == -1) return;
		fprintf(mFile,"setAttr \".bsi\" %i;\n", bsi);

	}
	void setLockCenterOfMass(bool lcm)
	{
		if(lcm == false) return;
		fprintf(mFile,"setAttr \".lcm\" %i;\n", lcm);

	}
	void setIgnore(bool ign)
	{
		if(ign == false) return;
		fprintf(mFile,"setAttr \".ign\" %i;\n", ign);

	}
	void setCollisions(bool col)
	{
		if(col == true) return;
		fprintf(mFile,"setAttr \".col\" %i;\n", col);

	}
	void setApplyForceAt(unsigned int afa)
	{
		if(afa == 1) return;
		fprintf(mFile,"setAttr \".afa\" %i;\n", afa);

	}
	void setDebugDraw(bool dd)
	{
		if(dd == false) return;
		fprintf(mFile,"setAttr \".dd\" %i;\n", dd);

	}
	void getCurrentTime()
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());

	}
	void getRigidWorldMatrix()
	{
		fprintf(mFile,"\"%s.rmx\"",mName.c_str());

	}
	void getFieldConnections(size_t fc_i)
	{
		fprintf(mFile,"\"%s.fc[%i]\"",mName.c_str(),fc_i);

	}
	void getRunUpCache()
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());

	}
	void getDataCache()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getFirstCachedFrame()
	{
		fprintf(mFile,"\"%s.fcf\"",mName.c_str());

	}
	void getLastCachedFrame()
	{
		fprintf(mFile,"\"%s.lcf\"",mName.c_str());

	}
	void getCachedFrameCount()
	{
		fprintf(mFile,"\"%s.cfc\"",mName.c_str());

	}
	void getCacheDirtyArray()
	{
		fprintf(mFile,"\"%s.cda\"",mName.c_str());

	}
	void getContactName(size_t cnn_i)
	{
		fprintf(mFile,"\"%s.cnn[%i]\"",mName.c_str(),cnn_i);

	}
	void getInterpenetrateWith(size_t itw_i)
	{
		fprintf(mFile,"\"%s.itw[%i]\"",mName.c_str(),itw_i);

	}
	void getInitialPositionX()
	{
		fprintf(mFile,"\"%s.ip.ipx\"",mName.c_str());

	}
	void getInitialPositionY()
	{
		fprintf(mFile,"\"%s.ip.ipy\"",mName.c_str());

	}
	void getInitialPositionZ()
	{
		fprintf(mFile,"\"%s.ip.ipz\"",mName.c_str());

	}
	void getLastPositionX()
	{
		fprintf(mFile,"\"%s.lp.lpx\"",mName.c_str());

	}
	void getLastPositionY()
	{
		fprintf(mFile,"\"%s.lp.lpy\"",mName.c_str());

	}
	void getLastPositionZ()
	{
		fprintf(mFile,"\"%s.lp.lpz\"",mName.c_str());

	}
	void getLastRotationX()
	{
		fprintf(mFile,"\"%s.lr.lrx\"",mName.c_str());

	}
	void getLastRotationY()
	{
		fprintf(mFile,"\"%s.lr.lry\"",mName.c_str());

	}
	void getLastRotationZ()
	{
		fprintf(mFile,"\"%s.lr.lrz\"",mName.c_str());

	}
	void getInitialOrientationX()
	{
		fprintf(mFile,"\"%s.ior.iox\"",mName.c_str());

	}
	void getInitialOrientationY()
	{
		fprintf(mFile,"\"%s.ior.ioy\"",mName.c_str());

	}
	void getInitialOrientationZ()
	{
		fprintf(mFile,"\"%s.ior.ioz\"",mName.c_str());

	}
	void getInitialVelocity()
	{
		fprintf(mFile,"\"%s.iv\"",mName.c_str());

	}
	void getInitialVelocityX()
	{
		fprintf(mFile,"\"%s.iv.ivx\"",mName.c_str());

	}
	void getInitialVelocityY()
	{
		fprintf(mFile,"\"%s.iv.ivy\"",mName.c_str());

	}
	void getInitialVelocityZ()
	{
		fprintf(mFile,"\"%s.iv.ivz\"",mName.c_str());

	}
	void getInitialSpin()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getInitialSpinX()
	{
		fprintf(mFile,"\"%s.is.isx\"",mName.c_str());

	}
	void getInitialSpinY()
	{
		fprintf(mFile,"\"%s.is.isy\"",mName.c_str());

	}
	void getInitialSpinZ()
	{
		fprintf(mFile,"\"%s.is.isz\"",mName.c_str());

	}
	void getCenterOfMass()
	{
		fprintf(mFile,"\"%s.com\"",mName.c_str());

	}
	void getCenterOfMassX()
	{
		fprintf(mFile,"\"%s.com.cmx\"",mName.c_str());

	}
	void getCenterOfMassY()
	{
		fprintf(mFile,"\"%s.com.cmy\"",mName.c_str());

	}
	void getCenterOfMassZ()
	{
		fprintf(mFile,"\"%s.com.cmz\"",mName.c_str());

	}
	void getImpulse()
	{
		fprintf(mFile,"\"%s.imp\"",mName.c_str());

	}
	void getImpulseX()
	{
		fprintf(mFile,"\"%s.imp.imx\"",mName.c_str());

	}
	void getImpulseY()
	{
		fprintf(mFile,"\"%s.imp.imy\"",mName.c_str());

	}
	void getImpulseZ()
	{
		fprintf(mFile,"\"%s.imp.imz\"",mName.c_str());

	}
	void getImpulsePosition()
	{
		fprintf(mFile,"\"%s.ipo\"",mName.c_str());

	}
	void getImpulsePositionX()
	{
		fprintf(mFile,"\"%s.ipo.pix\"",mName.c_str());

	}
	void getImpulsePositionY()
	{
		fprintf(mFile,"\"%s.ipo.piy\"",mName.c_str());

	}
	void getImpulsePositionZ()
	{
		fprintf(mFile,"\"%s.ipo.piz\"",mName.c_str());

	}
	void getSpinImpulse()
	{
		fprintf(mFile,"\"%s.sim\"",mName.c_str());

	}
	void getSpinImpulseX()
	{
		fprintf(mFile,"\"%s.sim.six\"",mName.c_str());

	}
	void getSpinImpulseY()
	{
		fprintf(mFile,"\"%s.sim.siy\"",mName.c_str());

	}
	void getSpinImpulseZ()
	{
		fprintf(mFile,"\"%s.sim.siz\"",mName.c_str());

	}
	void getMass()
	{
		fprintf(mFile,"\"%s.mas\"",mName.c_str());

	}
	void getVolume()
	{
		fprintf(mFile,"\"%s.vol\"",mName.c_str());

	}
	void getBounciness()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getDamping()
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());

	}
	void getStaticFriction()
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());

	}
	void getDynamicFriction()
	{
		fprintf(mFile,"\"%s.df\"",mName.c_str());

	}
	void getCollisionLayer()
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());

	}
	void getStandIn()
	{
		fprintf(mFile,"\"%s.si\"",mName.c_str());

	}
	void getInputGeometryCnt()
	{
		fprintf(mFile,"\"%s.igc\"",mName.c_str());

	}
	void getActive()
	{
		fprintf(mFile,"\"%s.act\"",mName.c_str());

	}
	void getChoice()
	{
		fprintf(mFile,"\"%s.chc\"",mName.c_str());

	}
	void getIsKinematic()
	{
		fprintf(mFile,"\"%s.kin\"",mName.c_str());

	}
	void getIsKeyframed()
	{
		fprintf(mFile,"\"%s.key\"",mName.c_str());

	}
	void getIsParented()
	{
		fprintf(mFile,"\"%s.par\"",mName.c_str());

	}
	void getParticleCollision()
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());

	}
	void getAutoInit()
	{
		fprintf(mFile,"\"%s.ai\"",mName.c_str());

	}
	void getAllowDisconnection()
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());

	}
	void getCacheData()
	{
		fprintf(mFile,"\"%s.idc\"",mName.c_str());

	}
	void getVelocity()
	{
		fprintf(mFile,"\"%s.vel\"",mName.c_str());

	}
	void getVelocityX()
	{
		fprintf(mFile,"\"%s.vel.vx\"",mName.c_str());

	}
	void getVelocityY()
	{
		fprintf(mFile,"\"%s.vel.vy\"",mName.c_str());

	}
	void getVelocityZ()
	{
		fprintf(mFile,"\"%s.vel.vz\"",mName.c_str());

	}
	void getSpin()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getSpinX()
	{
		fprintf(mFile,"\"%s.sp.spx\"",mName.c_str());

	}
	void getSpinY()
	{
		fprintf(mFile,"\"%s.sp.spy\"",mName.c_str());

	}
	void getSpinZ()
	{
		fprintf(mFile,"\"%s.sp.spz\"",mName.c_str());

	}
	void getContactCount()
	{
		fprintf(mFile,"\"%s.cct\"",mName.c_str());

	}
	void getContactPosition(size_t cnp_i)
	{
		fprintf(mFile,"\"%s.cnp[%i]\"",mName.c_str(),cnp_i);

	}
	void getContactX(size_t cnp_i)
	{
		fprintf(mFile,"\"%s.cnp[%i].cnx\"",mName.c_str(),cnp_i);

	}
	void getContactY(size_t cnp_i)
	{
		fprintf(mFile,"\"%s.cnp[%i].cny\"",mName.c_str(),cnp_i);

	}
	void getContactZ(size_t cnp_i)
	{
		fprintf(mFile,"\"%s.cnp[%i].cnz\"",mName.c_str(),cnp_i);

	}
	void getForce()
	{
		fprintf(mFile,"\"%s.for\"",mName.c_str());

	}
	void getForceX()
	{
		fprintf(mFile,"\"%s.for.fx\"",mName.c_str());

	}
	void getForceY()
	{
		fprintf(mFile,"\"%s.for.fy\"",mName.c_str());

	}
	void getForceZ()
	{
		fprintf(mFile,"\"%s.for.fz\"",mName.c_str());

	}
	void getTorque()
	{
		fprintf(mFile,"\"%s.tor\"",mName.c_str());

	}
	void getTorqueX()
	{
		fprintf(mFile,"\"%s.tor.trx\"",mName.c_str());

	}
	void getTorqueY()
	{
		fprintf(mFile,"\"%s.tor.try\"",mName.c_str());

	}
	void getTorqueZ()
	{
		fprintf(mFile,"\"%s.tor.trz\"",mName.c_str());

	}
	void getFieldData()
	{
		fprintf(mFile,"\"%s.fld\"",mName.c_str());

	}
	void getFieldDataPosition()
	{
		fprintf(mFile,"\"%s.fld.fdp\"",mName.c_str());

	}
	void getFieldDataVelocity()
	{
		fprintf(mFile,"\"%s.fld.fdv\"",mName.c_str());

	}
	void getFieldDataMass()
	{
		fprintf(mFile,"\"%s.fld.fdm\"",mName.c_str());

	}
	void getDeltaTime()
	{
		fprintf(mFile,"\"%s.fld.dt\"",mName.c_str());

	}
	void getInputForce(size_t ifr_i)
	{
		fprintf(mFile,"\"%s.ifr[%i]\"",mName.c_str(),ifr_i);

	}
	void getInputForceType(size_t ift_i)
	{
		fprintf(mFile,"\"%s.ift[%i]\"",mName.c_str(),ift_i);

	}
	void getCollisionRecords(size_t crc_i)
	{
		fprintf(mFile,"\"%s.crc[%i]\"",mName.c_str(),crc_i);

	}
	void getGeneralForce()
	{
		fprintf(mFile,"\"%s.gfr\"",mName.c_str());

	}
	void getOutputForce()
	{
		fprintf(mFile,"\"%s.gfr.ofr\"",mName.c_str());

	}
	void getOutputTorque()
	{
		fprintf(mFile,"\"%s.gfr.otr\"",mName.c_str());

	}
	void getSolverId()
	{
		fprintf(mFile,"\"%s.sid\"",mName.c_str());

	}
	void getBakeSimulationIndex()
	{
		fprintf(mFile,"\"%s.bsi\"",mName.c_str());

	}
	void getShapeChanged()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getLockCenterOfMass()
	{
		fprintf(mFile,"\"%s.lcm\"",mName.c_str());

	}
	void getIgnore()
	{
		fprintf(mFile,"\"%s.ign\"",mName.c_str());

	}
	void getCollisions()
	{
		fprintf(mFile,"\"%s.col\"",mName.c_str());

	}
	void getApplyForceAt()
	{
		fprintf(mFile,"\"%s.afa\"",mName.c_str());

	}
	void getDebugDraw()
	{
		fprintf(mFile,"\"%s.dd\"",mName.c_str());

	}
protected:
	RigidBody(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RIGIDBODY_H__
