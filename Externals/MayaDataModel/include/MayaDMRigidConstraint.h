/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RIGIDCONSTRAINT_H__
#define __MayaDM_RIGIDCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class RigidConstraint : public Transform
{
public:
public:

	RigidConstraint():Transform(){}
	RigidConstraint(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Transform(file, name, parent, "rigidConstraint", shared, create){}
	virtual ~RigidConstraint(){}

	void setConstraintType(unsigned int typ)
	{
		if(typ == 1) return;
		fprintf(mFile,"\tsetAttr \".typ\" %i;\n", typ);
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
	void setInitialOrientation(const double3& ino)
	{
		if(ino == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".ino\" -type \"double3\" ");
		ino.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInitialOrientationX(double iox)
	{
		if(iox == 0) return;
		fprintf(mFile,"\tsetAttr \".ino.iox\" %f;\n", iox);
	}
	void setInitialOrientationY(double ioy)
	{
		if(ioy == 0) return;
		fprintf(mFile,"\tsetAttr \".ino.ioy\" %f;\n", ioy);
	}
	void setInitialOrientationZ(double ioz)
	{
		if(ioz == 0) return;
		fprintf(mFile,"\tsetAttr \".ino.ioz\" %f;\n", ioz);
	}
	void setSpringStiffness(double sst)
	{
		if(sst == 5.0) return;
		fprintf(mFile,"\tsetAttr \".sst\" %f;\n", sst);
	}
	void setSpringDamping(double dmp)
	{
		if(dmp == 0.1) return;
		fprintf(mFile,"\tsetAttr \".dmp\" %f;\n", dmp);
	}
	void setSpringRestLength(double srl)
	{
		if(srl == 1.0) return;
		fprintf(mFile,"\tsetAttr \".srl\" %f;\n", srl);
	}
	void setInterpenetrate(bool int_)
	{
		if(int_ == false) return;
		fprintf(mFile,"\tsetAttr \".int\" %i;\n", int_);
	}
	void setIsParented(bool par)
	{
		if(par == false) return;
		fprintf(mFile,"\tsetAttr \".par\" %i;\n", par);
	}
	void setSolverId(int sid)
	{
		if(sid == -1) return;
		fprintf(mFile,"\tsetAttr \".sid\" %i;\n", sid);
	}
	void setConstrain(bool con)
	{
		if(con == true) return;
		fprintf(mFile,"\tsetAttr \".con\" %i;\n", con);
	}
	void setRelativeTo(unsigned int rlt)
	{
		if(rlt == 0) return;
		fprintf(mFile,"\tsetAttr \".rlt\" %i;\n", rlt);
	}
	void setUserDefinedPosition(const double3& udp)
	{
		if(udp == double3(0, 0, 0)) return;
		fprintf(mFile,"\tsetAttr \".udp\" -type \"double3\" ");
		udp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUserDefinedPositionX(double upx)
	{
		if(upx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".udp.upx\" %f;\n", upx);
	}
	void setUserDefinedPositionY(double upy)
	{
		if(upy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".udp.upy\" %f;\n", upy);
	}
	void setUserDefinedPositionZ(double upz)
	{
		if(upz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".udp.upz\" %f;\n", upz);
	}
	void getRigidBody1()const
	{
		fprintf(mFile,"\"%s.rb1\"",mName.c_str());
	}
	void getRigidBody2()const
	{
		fprintf(mFile,"\"%s.rb2\"",mName.c_str());
	}
	void getConstraintType()const
	{
		fprintf(mFile,"\"%s.typ\"",mName.c_str());
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
	void getVelocity()const
	{
		fprintf(mFile,"\"%s.vel\"",mName.c_str());
	}
	void getVelocityX()const
	{
		fprintf(mFile,"\"%s.vel.vlx\"",mName.c_str());
	}
	void getVelocityY()const
	{
		fprintf(mFile,"\"%s.vel.vly\"",mName.c_str());
	}
	void getVelocityZ()const
	{
		fprintf(mFile,"\"%s.vel.vlz\"",mName.c_str());
	}
	void getAngularVelocity()const
	{
		fprintf(mFile,"\"%s.avl\"",mName.c_str());
	}
	void getAngularVelocityX()const
	{
		fprintf(mFile,"\"%s.avl.avx\"",mName.c_str());
	}
	void getAngularVelocityY()const
	{
		fprintf(mFile,"\"%s.avl.avy\"",mName.c_str());
	}
	void getAngularVelocityZ()const
	{
		fprintf(mFile,"\"%s.avl.avz\"",mName.c_str());
	}
	void getInitialOrientationX()const
	{
		fprintf(mFile,"\"%s.ino.iox\"",mName.c_str());
	}
	void getInitialOrientationY()const
	{
		fprintf(mFile,"\"%s.ino.ioy\"",mName.c_str());
	}
	void getInitialOrientationZ()const
	{
		fprintf(mFile,"\"%s.ino.ioz\"",mName.c_str());
	}
	void getSpringStiffness()const
	{
		fprintf(mFile,"\"%s.sst\"",mName.c_str());
	}
	void getSpringDamping()const
	{
		fprintf(mFile,"\"%s.dmp\"",mName.c_str());
	}
	void getSpringRestLength()const
	{
		fprintf(mFile,"\"%s.srl\"",mName.c_str());
	}
	void getInterpenetrate()const
	{
		fprintf(mFile,"\"%s.int\"",mName.c_str());
	}
	void getIsParented()const
	{
		fprintf(mFile,"\"%s.par\"",mName.c_str());
	}
	void getIsBounded()const
	{
		fprintf(mFile,"\"%s.bon\"",mName.c_str());
	}
	void getSolverId()const
	{
		fprintf(mFile,"\"%s.sid\"",mName.c_str());
	}
	void getConstrain()const
	{
		fprintf(mFile,"\"%s.con\"",mName.c_str());
	}
	void getRelativeTo()const
	{
		fprintf(mFile,"\"%s.rlt\"",mName.c_str());
	}
	void getUserDefinedPositionX()const
	{
		fprintf(mFile,"\"%s.udp.upx\"",mName.c_str());
	}
	void getUserDefinedPositionY()const
	{
		fprintf(mFile,"\"%s.udp.upy\"",mName.c_str());
	}
	void getUserDefinedPositionZ()const
	{
		fprintf(mFile,"\"%s.udp.upz\"",mName.c_str());
	}
protected:
	RigidConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Transform(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RIGIDCONSTRAINT_H__
