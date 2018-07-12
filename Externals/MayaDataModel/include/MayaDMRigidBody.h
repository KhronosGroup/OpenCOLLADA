/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	RigidBody():Shape(){}
	RigidBody(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "rigidBody", shared, create){}
	virtual ~RigidBody(){}

	void setRunUpCache(const doubleArray& rc)
	{
		if(rc.size == 0) return;
		fprintf(mFile,"\tsetAttr \".rc\" -type \"doubleArray\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDataCache(const doubleArray& dc)
	{
		if(dc.size == 0) return;
		fprintf(mFile,"\tsetAttr \".dc\" -type \"doubleArray\" ");
		dc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFirstCachedFrame(int fcf)
	{
		if(fcf == 0) return;
		fprintf(mFile,"\tsetAttr \".fcf\" %i;\n", fcf);
	}
	void setLastCachedFrame(int lcf)
	{
		if(lcf == 0) return;
		fprintf(mFile,"\tsetAttr \".lcf\" %i;\n", lcf);
	}
	void setCachedFrameCount(int cfc)
	{
		if(cfc == 0) return;
		fprintf(mFile,"\tsetAttr \".cfc\" %i;\n", cfc);
	}
	void setInitialPosition(const double3& ip)
	{
		if(ip == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".ip\" -type \"double3\" ");
		ip.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInitialPositionX(double ipx)
	{
		if(ipx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ip.ipx\" %f;\n", ipx);
	}
	void setInitialPositionY(double ipy)
	{
		if(ipy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ip.ipy\" %f;\n", ipy);
	}
	void setInitialPositionZ(double ipz)
	{
		if(ipz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ip.ipz\" %f;\n", ipz);
	}
	void setInitialOrientation(const double3& ior)
	{
		if(ior == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".ior\" -type \"double3\" ");
		ior.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInitialOrientationX(double iox)
	{
		if(iox == 0) return;
		fprintf(mFile,"\tsetAttr \".ior.iox\" %f;\n", iox);
	}
	void setInitialOrientationY(double ioy)
	{
		if(ioy == 0) return;
		fprintf(mFile,"\tsetAttr \".ior.ioy\" %f;\n", ioy);
	}
	void setInitialOrientationZ(double ioz)
	{
		if(ioz == 0) return;
		fprintf(mFile,"\tsetAttr \".ior.ioz\" %f;\n", ioz);
	}
	void setInitialVelocity(const double3& iv)
	{
		if(iv == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".iv\" -type \"double3\" ");
		iv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInitialVelocityX(double ivx)
	{
		if(ivx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".iv.ivx\" %f;\n", ivx);
	}
	void setInitialVelocityY(double ivy)
	{
		if(ivy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".iv.ivy\" %f;\n", ivy);
	}
	void setInitialVelocityZ(double ivz)
	{
		if(ivz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".iv.ivz\" %f;\n", ivz);
	}
	void setInitialSpin(const double3& is)
	{
		if(is == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".is\" -type \"double3\" ");
		is.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInitialSpinX(double isx)
	{
		if(isx == 0) return;
		fprintf(mFile,"\tsetAttr \".is.isx\" %f;\n", isx);
	}
	void setInitialSpinY(double isy)
	{
		if(isy == 0) return;
		fprintf(mFile,"\tsetAttr \".is.isy\" %f;\n", isy);
	}
	void setInitialSpinZ(double isz)
	{
		if(isz == 0) return;
		fprintf(mFile,"\tsetAttr \".is.isz\" %f;\n", isz);
	}
	void setCenterOfMass(const double3& com)
	{
		if(com == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".com\" -type \"double3\" ");
		com.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCenterOfMassX(double cmx)
	{
		if(cmx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".com.cmx\" %f;\n", cmx);
	}
	void setCenterOfMassY(double cmy)
	{
		if(cmy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".com.cmy\" %f;\n", cmy);
	}
	void setCenterOfMassZ(double cmz)
	{
		if(cmz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".com.cmz\" %f;\n", cmz);
	}
	void setImpulse(const double3& imp)
	{
		if(imp == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".imp\" -type \"double3\" ");
		imp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImpulseX(double imx)
	{
		if(imx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imp.imx\" %f;\n", imx);
	}
	void setImpulseY(double imy)
	{
		if(imy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imp.imy\" %f;\n", imy);
	}
	void setImpulseZ(double imz)
	{
		if(imz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imp.imz\" %f;\n", imz);
	}
	void setImpulsePosition(const double3& ipo)
	{
		if(ipo == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".ipo\" -type \"double3\" ");
		ipo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImpulsePositionX(double pix)
	{
		if(pix == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ipo.pix\" %f;\n", pix);
	}
	void setImpulsePositionY(double piy)
	{
		if(piy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ipo.piy\" %f;\n", piy);
	}
	void setImpulsePositionZ(double piz)
	{
		if(piz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ipo.piz\" %f;\n", piz);
	}
	void setSpinImpulse(const double3& sim)
	{
		if(sim == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".sim\" -type \"double3\" ");
		sim.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpinImpulseX(double six)
	{
		if(six == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sim.six\" %f;\n", six);
	}
	void setSpinImpulseY(double siy)
	{
		if(siy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sim.siy\" %f;\n", siy);
	}
	void setSpinImpulseZ(double siz)
	{
		if(siz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sim.siz\" %f;\n", siz);
	}
	void setMass(double mas)
	{
		if(mas == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mas\" %f;\n", mas);
	}
	void setBounciness(double b)
	{
		if(b == 0.6) return;
		fprintf(mFile,"\tsetAttr \".b\" %f;\n", b);
	}
	void setDamping(double dp)
	{
		if(dp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dp\" %f;\n", dp);
	}
	void setStaticFriction(double sf)
	{
		if(sf == 0.2) return;
		fprintf(mFile,"\tsetAttr \".sf\" %f;\n", sf);
	}
	void setDynamicFriction(double df)
	{
		if(df == 0.2) return;
		fprintf(mFile,"\tsetAttr \".df\" %f;\n", df);
	}
	void setCollisionLayer(int cl)
	{
		if(cl == 0) return;
		fprintf(mFile,"\tsetAttr \".cl\" %i;\n", cl);
	}
	void setStandIn(unsigned int si)
	{
		if(si == 0) return;
		fprintf(mFile,"\tsetAttr \".si\" %i;\n", si);
	}
	void setInputGeometryCnt(int igc)
	{
		if(igc == 0) return;
		fprintf(mFile,"\tsetAttr \".igc\" %i;\n", igc);
	}
	void setActive(bool act)
	{
		if(act == true) return;
		fprintf(mFile,"\tsetAttr \".act\" %i;\n", act);
	}
	void setChoice(int chc)
	{
		if(chc == 0) return;
		fprintf(mFile,"\tsetAttr \".chc\" %i;\n", chc);
	}
	void setIsKinematic(bool kin)
	{
		if(kin == false) return;
		fprintf(mFile,"\tsetAttr \".kin\" %i;\n", kin);
	}
	void setIsKeyframed(bool key)
	{
		if(key == false) return;
		fprintf(mFile,"\tsetAttr \".key\" %i;\n", key);
	}
	void setIsParented(bool par)
	{
		if(par == false) return;
		fprintf(mFile,"\tsetAttr \".par\" %i;\n", par);
	}
	void setParticleCollision(bool pc)
	{
		if(pc == false) return;
		fprintf(mFile,"\tsetAttr \".pc\" %i;\n", pc);
	}
	void setAutoInit(bool ai)
	{
		if(ai == true) return;
		fprintf(mFile,"\tsetAttr \".ai\" %i;\n", ai);
	}
	void setAllowDisconnection(bool ad)
	{
		if(ad == false) return;
		fprintf(mFile,"\tsetAttr \".ad\" %i;\n", ad);
	}
	void setCacheData(bool idc)
	{
		if(idc == false) return;
		fprintf(mFile,"\tsetAttr \".idc\" %i;\n", idc);
	}
	void setTessellationFactor(int tes)
	{
		if(tes == 200) return;
		fprintf(mFile,"\tsetAttr \".tes\" %i;\n", tes);
	}
	void setInputForceType(size_t ift_i,bool ift)
	{
		if(ift == false) return;
		fprintf(mFile,"\tsetAttr \".ift[%i]\" %i;\n", ift_i,ift);
	}
	void setInputForceType(size_t ift_start,size_t ift_end,bool* ift)
	{
		fprintf(mFile,"\tsetAttr \".ift[%i:%i]\" ", ift_start,ift_end);
		size_t size = (ift_end-ift_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ift[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInputForceType(size_t ift_start,size_t ift_end)const
	{
		fprintf(mFile,"\tsetAttr \".ift[%i:%i]\"",ift_start,ift_end);
	}
	void appendInputForceType(bool ift)const
	{
		fprintf(mFile," %i",ift);
	}
	void endInputForceType()const
	{
		fprintf(mFile,";\n");
	}
	void setSolverId(int sid)
	{
		if(sid == -1) return;
		fprintf(mFile,"\tsetAttr \".sid\" %i;\n", sid);
	}
	void setBakeSimulationIndex(int bsi)
	{
		if(bsi == -1) return;
		fprintf(mFile,"\tsetAttr \".bsi\" %i;\n", bsi);
	}
	void setLockCenterOfMass(bool lcm)
	{
		if(lcm == false) return;
		fprintf(mFile,"\tsetAttr \".lcm\" %i;\n", lcm);
	}
	void setIgnore(bool ign)
	{
		if(ign == false) return;
		fprintf(mFile,"\tsetAttr \".ign\" %i;\n", ign);
	}
	void setCollisions(bool col)
	{
		if(col == true) return;
		fprintf(mFile,"\tsetAttr \".col\" %i;\n", col);
	}
	void setApplyForceAt(unsigned int afa)
	{
		if(afa == 1) return;
		fprintf(mFile,"\tsetAttr \".afa\" %i;\n", afa);
	}
	void setDebugDraw(bool dd)
	{
		if(dd == false) return;
		fprintf(mFile,"\tsetAttr \".dd\" %i;\n", dd);
	}
	void getCurrentTime()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getRigidWorldMatrix()const
	{
		fprintf(mFile,"\"%s.rmx\"",mName.c_str());
	}
	void getInputGeometryMsg(size_t igm_i)const
	{
		fprintf(mFile,"\"%s.igm[%i]\"",mName.c_str(),igm_i);
	}
	void getInputGeometryMsg()const
	{

		fprintf(mFile,"\"%s.igm\"",mName.c_str());
	}
	void getFieldConnections(size_t fc_i)const
	{
		fprintf(mFile,"\"%s.fc[%i]\"",mName.c_str(),fc_i);
	}
	void getFieldConnections()const
	{

		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getRunUpCache()const
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());
	}
	void getDataCache()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getFirstCachedFrame()const
	{
		fprintf(mFile,"\"%s.fcf\"",mName.c_str());
	}
	void getLastCachedFrame()const
	{
		fprintf(mFile,"\"%s.lcf\"",mName.c_str());
	}
	void getCachedFrameCount()const
	{
		fprintf(mFile,"\"%s.cfc\"",mName.c_str());
	}
	void getCacheDirtyArray()const
	{
		fprintf(mFile,"\"%s.cda\"",mName.c_str());
	}
	void getContactName(size_t cnn_i)const
	{
		fprintf(mFile,"\"%s.cnn[%i]\"",mName.c_str(),cnn_i);
	}
	void getContactName()const
	{

		fprintf(mFile,"\"%s.cnn\"",mName.c_str());
	}
	void getInterpenetrateWith(size_t itw_i)const
	{
		fprintf(mFile,"\"%s.itw[%i]\"",mName.c_str(),itw_i);
	}
	void getInterpenetrateWith()const
	{

		fprintf(mFile,"\"%s.itw\"",mName.c_str());
	}
	void getInitialPositionX()const
	{
		fprintf(mFile,"\"%s.ip.ipx\"",mName.c_str());
	}
	void getInitialPositionY()const
	{
		fprintf(mFile,"\"%s.ip.ipy\"",mName.c_str());
	}
	void getInitialPositionZ()const
	{
		fprintf(mFile,"\"%s.ip.ipz\"",mName.c_str());
	}
	void getLastPositionX()const
	{
		fprintf(mFile,"\"%s.lp.lpx\"",mName.c_str());
	}
	void getLastPositionY()const
	{
		fprintf(mFile,"\"%s.lp.lpy\"",mName.c_str());
	}
	void getLastPositionZ()const
	{
		fprintf(mFile,"\"%s.lp.lpz\"",mName.c_str());
	}
	void getLastRotationX()const
	{
		fprintf(mFile,"\"%s.lr.lrx\"",mName.c_str());
	}
	void getLastRotationY()const
	{
		fprintf(mFile,"\"%s.lr.lry\"",mName.c_str());
	}
	void getLastRotationZ()const
	{
		fprintf(mFile,"\"%s.lr.lrz\"",mName.c_str());
	}
	void getInitialOrientationX()const
	{
		fprintf(mFile,"\"%s.ior.iox\"",mName.c_str());
	}
	void getInitialOrientationY()const
	{
		fprintf(mFile,"\"%s.ior.ioy\"",mName.c_str());
	}
	void getInitialOrientationZ()const
	{
		fprintf(mFile,"\"%s.ior.ioz\"",mName.c_str());
	}
	void getInitialVelocity()const
	{
		fprintf(mFile,"\"%s.iv\"",mName.c_str());
	}
	void getInitialVelocityX()const
	{
		fprintf(mFile,"\"%s.iv.ivx\"",mName.c_str());
	}
	void getInitialVelocityY()const
	{
		fprintf(mFile,"\"%s.iv.ivy\"",mName.c_str());
	}
	void getInitialVelocityZ()const
	{
		fprintf(mFile,"\"%s.iv.ivz\"",mName.c_str());
	}
	void getInitialSpin()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getInitialSpinX()const
	{
		fprintf(mFile,"\"%s.is.isx\"",mName.c_str());
	}
	void getInitialSpinY()const
	{
		fprintf(mFile,"\"%s.is.isy\"",mName.c_str());
	}
	void getInitialSpinZ()const
	{
		fprintf(mFile,"\"%s.is.isz\"",mName.c_str());
	}
	void getCenterOfMass()const
	{
		fprintf(mFile,"\"%s.com\"",mName.c_str());
	}
	void getCenterOfMassX()const
	{
		fprintf(mFile,"\"%s.com.cmx\"",mName.c_str());
	}
	void getCenterOfMassY()const
	{
		fprintf(mFile,"\"%s.com.cmy\"",mName.c_str());
	}
	void getCenterOfMassZ()const
	{
		fprintf(mFile,"\"%s.com.cmz\"",mName.c_str());
	}
	void getImpulse()const
	{
		fprintf(mFile,"\"%s.imp\"",mName.c_str());
	}
	void getImpulseX()const
	{
		fprintf(mFile,"\"%s.imp.imx\"",mName.c_str());
	}
	void getImpulseY()const
	{
		fprintf(mFile,"\"%s.imp.imy\"",mName.c_str());
	}
	void getImpulseZ()const
	{
		fprintf(mFile,"\"%s.imp.imz\"",mName.c_str());
	}
	void getImpulsePosition()const
	{
		fprintf(mFile,"\"%s.ipo\"",mName.c_str());
	}
	void getImpulsePositionX()const
	{
		fprintf(mFile,"\"%s.ipo.pix\"",mName.c_str());
	}
	void getImpulsePositionY()const
	{
		fprintf(mFile,"\"%s.ipo.piy\"",mName.c_str());
	}
	void getImpulsePositionZ()const
	{
		fprintf(mFile,"\"%s.ipo.piz\"",mName.c_str());
	}
	void getSpinImpulse()const
	{
		fprintf(mFile,"\"%s.sim\"",mName.c_str());
	}
	void getSpinImpulseX()const
	{
		fprintf(mFile,"\"%s.sim.six\"",mName.c_str());
	}
	void getSpinImpulseY()const
	{
		fprintf(mFile,"\"%s.sim.siy\"",mName.c_str());
	}
	void getSpinImpulseZ()const
	{
		fprintf(mFile,"\"%s.sim.siz\"",mName.c_str());
	}
	void getMass()const
	{
		fprintf(mFile,"\"%s.mas\"",mName.c_str());
	}
	void getVolume()const
	{
		fprintf(mFile,"\"%s.vol\"",mName.c_str());
	}
	void getBounciness()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getDamping()const
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());
	}
	void getStaticFriction()const
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());
	}
	void getDynamicFriction()const
	{
		fprintf(mFile,"\"%s.df\"",mName.c_str());
	}
	void getCollisionLayer()const
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getStandIn()const
	{
		fprintf(mFile,"\"%s.si\"",mName.c_str());
	}
	void getInputGeometryCnt()const
	{
		fprintf(mFile,"\"%s.igc\"",mName.c_str());
	}
	void getActive()const
	{
		fprintf(mFile,"\"%s.act\"",mName.c_str());
	}
	void getChoice()const
	{
		fprintf(mFile,"\"%s.chc\"",mName.c_str());
	}
	void getIsKinematic()const
	{
		fprintf(mFile,"\"%s.kin\"",mName.c_str());
	}
	void getIsKeyframed()const
	{
		fprintf(mFile,"\"%s.key\"",mName.c_str());
	}
	void getIsParented()const
	{
		fprintf(mFile,"\"%s.par\"",mName.c_str());
	}
	void getParticleCollision()const
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getAutoInit()const
	{
		fprintf(mFile,"\"%s.ai\"",mName.c_str());
	}
	void getAllowDisconnection()const
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());
	}
	void getCacheData()const
	{
		fprintf(mFile,"\"%s.idc\"",mName.c_str());
	}
	void getVelocity()const
	{
		fprintf(mFile,"\"%s.vel\"",mName.c_str());
	}
	void getVelocityX()const
	{
		fprintf(mFile,"\"%s.vel.vx\"",mName.c_str());
	}
	void getVelocityY()const
	{
		fprintf(mFile,"\"%s.vel.vy\"",mName.c_str());
	}
	void getVelocityZ()const
	{
		fprintf(mFile,"\"%s.vel.vz\"",mName.c_str());
	}
	void getSpin()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getSpinX()const
	{
		fprintf(mFile,"\"%s.sp.spx\"",mName.c_str());
	}
	void getSpinY()const
	{
		fprintf(mFile,"\"%s.sp.spy\"",mName.c_str());
	}
	void getSpinZ()const
	{
		fprintf(mFile,"\"%s.sp.spz\"",mName.c_str());
	}
	void getContactCount()const
	{
		fprintf(mFile,"\"%s.cct\"",mName.c_str());
	}
	void getContactPosition(size_t cnp_i)const
	{
		fprintf(mFile,"\"%s.cnp[%i]\"",mName.c_str(),cnp_i);
	}
	void getContactPosition()const
	{

		fprintf(mFile,"\"%s.cnp\"",mName.c_str());
	}
	void getContactX(size_t cnp_i)const
	{
		fprintf(mFile,"\"%s.cnp[%i].cnx\"",mName.c_str(),cnp_i);
	}
	void getContactX()const
	{

		fprintf(mFile,"\"%s.cnp.cnx\"",mName.c_str());
	}
	void getContactY(size_t cnp_i)const
	{
		fprintf(mFile,"\"%s.cnp[%i].cny\"",mName.c_str(),cnp_i);
	}
	void getContactY()const
	{

		fprintf(mFile,"\"%s.cnp.cny\"",mName.c_str());
	}
	void getContactZ(size_t cnp_i)const
	{
		fprintf(mFile,"\"%s.cnp[%i].cnz\"",mName.c_str(),cnp_i);
	}
	void getContactZ()const
	{

		fprintf(mFile,"\"%s.cnp.cnz\"",mName.c_str());
	}
	void getForce()const
	{
		fprintf(mFile,"\"%s.for\"",mName.c_str());
	}
	void getForceX()const
	{
		fprintf(mFile,"\"%s.for.fx\"",mName.c_str());
	}
	void getForceY()const
	{
		fprintf(mFile,"\"%s.for.fy\"",mName.c_str());
	}
	void getForceZ()const
	{
		fprintf(mFile,"\"%s.for.fz\"",mName.c_str());
	}
	void getTorque()const
	{
		fprintf(mFile,"\"%s.tor\"",mName.c_str());
	}
	void getTorqueX()const
	{
		fprintf(mFile,"\"%s.tor.trx\"",mName.c_str());
	}
	void getTorqueY()const
	{
		fprintf(mFile,"\"%s.tor.try\"",mName.c_str());
	}
	void getTorqueZ()const
	{
		fprintf(mFile,"\"%s.tor.trz\"",mName.c_str());
	}
	void getFieldData()const
	{
		fprintf(mFile,"\"%s.fld\"",mName.c_str());
	}
	void getFieldDataPosition()const
	{
		fprintf(mFile,"\"%s.fld.fdp\"",mName.c_str());
	}
	void getFieldDataVelocity()const
	{
		fprintf(mFile,"\"%s.fld.fdv\"",mName.c_str());
	}
	void getFieldDataMass()const
	{
		fprintf(mFile,"\"%s.fld.fdm\"",mName.c_str());
	}
	void getDeltaTime()const
	{
		fprintf(mFile,"\"%s.fld.dt\"",mName.c_str());
	}
	void getInputForce(size_t ifr_i)const
	{
		fprintf(mFile,"\"%s.ifr[%i]\"",mName.c_str(),ifr_i);
	}
	void getInputForce()const
	{

		fprintf(mFile,"\"%s.ifr\"",mName.c_str());
	}
	void getInputForceType(size_t ift_i)const
	{
		fprintf(mFile,"\"%s.ift[%i]\"",mName.c_str(),ift_i);
	}
	void getInputForceType()const
	{

		fprintf(mFile,"\"%s.ift\"",mName.c_str());
	}
	void getCollisionRecords(size_t crc_i)const
	{
		fprintf(mFile,"\"%s.crc[%i]\"",mName.c_str(),crc_i);
	}
	void getCollisionRecords()const
	{

		fprintf(mFile,"\"%s.crc\"",mName.c_str());
	}
	void getGeneralForce()const
	{
		fprintf(mFile,"\"%s.gfr\"",mName.c_str());
	}
	void getOutputForce()const
	{
		fprintf(mFile,"\"%s.gfr.ofr\"",mName.c_str());
	}
	void getOutputTorque()const
	{
		fprintf(mFile,"\"%s.gfr.otr\"",mName.c_str());
	}
	void getSolverId()const
	{
		fprintf(mFile,"\"%s.sid\"",mName.c_str());
	}
	void getBakeSimulationIndex()const
	{
		fprintf(mFile,"\"%s.bsi\"",mName.c_str());
	}
	void getShapeChanged()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getLockCenterOfMass()const
	{
		fprintf(mFile,"\"%s.lcm\"",mName.c_str());
	}
	void getIgnore()const
	{
		fprintf(mFile,"\"%s.ign\"",mName.c_str());
	}
	void getCollisions()const
	{
		fprintf(mFile,"\"%s.col\"",mName.c_str());
	}
	void getApplyForceAt()const
	{
		fprintf(mFile,"\"%s.afa\"",mName.c_str());
	}
	void getDebugDraw()const
	{
		fprintf(mFile,"\"%s.dd\"",mName.c_str());
	}
protected:
	RigidBody(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RIGIDBODY_H__
