/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_JOINT_H__
#define __MayaDM_JOINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class Joint : public Transform
{
public:
public:
	Joint(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "joint"){}
	virtual ~Joint(){}
	void setJointOrientType(const string& jot)
	{
		if(jot == "xyz") return;
		fprintf(mFile,"setAttr \".jot\" -type \"string\" ");
		jot.write(mFile);
		fprintf(mFile,";\n");

	}
	void setJointTypeX(bool jtx)
	{
		if(jtx == true) return;
		fprintf(mFile,"setAttr \".jtx\" %i;\n", jtx);

	}
	void setJointTypeY(bool jty)
	{
		if(jty == true) return;
		fprintf(mFile,"setAttr \".jty\" %i;\n", jty);

	}
	void setJointTypeZ(bool jtz)
	{
		if(jtz == true) return;
		fprintf(mFile,"setAttr \".jtz\" %i;\n", jtz);

	}
	void setJointOrient(const double3& jo)
	{
		fprintf(mFile,"setAttr \".jo\" -type \"double3\" ");
		jo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setJointOrientX(double jox)
	{
		if(jox == 0) return;
		fprintf(mFile,"setAttr \".jo.jox\" %f;\n", jox);

	}
	void setJointOrientY(double joy)
	{
		if(joy == 0) return;
		fprintf(mFile,"setAttr \".jo.joy\" %f;\n", joy);

	}
	void setJointOrientZ(double joz)
	{
		if(joz == 0) return;
		fprintf(mFile,"setAttr \".jo.joz\" %f;\n", joz);

	}
	void setSegmentScaleCompensate(bool ssc)
	{
		if(ssc == true) return;
		fprintf(mFile,"setAttr \".ssc\" %i;\n", ssc);

	}
	void setInverseScale(const double3& is)
	{
		fprintf(mFile,"setAttr \".is\" -type \"double3\" ");
		is.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInverseScaleX(double isx)
	{
		if(isx == 1.0) return;
		fprintf(mFile,"setAttr \".is.isx\" %f;\n", isx);

	}
	void setInverseScaleY(double isy)
	{
		if(isy == 1.0) return;
		fprintf(mFile,"setAttr \".is.isy\" %f;\n", isy);

	}
	void setInverseScaleZ(double isz)
	{
		if(isz == 1.0) return;
		fprintf(mFile,"setAttr \".is.isz\" %f;\n", isz);

	}
	void setStiffness(const double3& st)
	{
		fprintf(mFile,"setAttr \".st\" -type \"double3\" ");
		st.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStiffnessX(double stx)
	{
		if(stx == 0.0) return;
		fprintf(mFile,"setAttr \".st.stx\" %f;\n", stx);

	}
	void setStiffnessY(double sty)
	{
		if(sty == 0.0) return;
		fprintf(mFile,"setAttr \".st.sty\" %f;\n", sty);

	}
	void setStiffnessZ(double stz)
	{
		if(stz == 0.0) return;
		fprintf(mFile,"setAttr \".st.stz\" %f;\n", stz);

	}
	void setPreferredAngle(const double3& pa)
	{
		fprintf(mFile,"setAttr \".pa\" -type \"double3\" ");
		pa.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPreferredAngleX(double pax)
	{
		if(pax == 0) return;
		fprintf(mFile,"setAttr \".pa.pax\" %f;\n", pax);

	}
	void setPreferredAngleY(double pay)
	{
		if(pay == 0) return;
		fprintf(mFile,"setAttr \".pa.pay\" %f;\n", pay);

	}
	void setPreferredAngleZ(double paz)
	{
		if(paz == 0) return;
		fprintf(mFile,"setAttr \".pa.paz\" %f;\n", paz);

	}
	void setMinRotateDampRange(const double3& ndr)
	{
		fprintf(mFile,"setAttr \".ndr\" -type \"double3\" ");
		ndr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinRotateDampRangeX(double ndx)
	{
		if(ndx == 0) return;
		fprintf(mFile,"setAttr \".ndr.ndx\" %f;\n", ndx);

	}
	void setMinRotateDampRangeY(double ndy)
	{
		if(ndy == 0) return;
		fprintf(mFile,"setAttr \".ndr.ndy\" %f;\n", ndy);

	}
	void setMinRotateDampRangeZ(double ndz)
	{
		if(ndz == 0) return;
		fprintf(mFile,"setAttr \".ndr.ndz\" %f;\n", ndz);

	}
	void setMinRotateDampStrength(const double3& nst)
	{
		fprintf(mFile,"setAttr \".nst\" -type \"double3\" ");
		nst.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinRotateDampStrengthX(double nstx)
	{
		if(nstx == 0.0) return;
		fprintf(mFile,"setAttr \".nst.nstx\" %f;\n", nstx);

	}
	void setMinRotateDampStrengthY(double nsty)
	{
		if(nsty == 0.0) return;
		fprintf(mFile,"setAttr \".nst.nsty\" %f;\n", nsty);

	}
	void setMinRotateDampStrengthZ(double nstz)
	{
		if(nstz == 0.0) return;
		fprintf(mFile,"setAttr \".nst.nstz\" %f;\n", nstz);

	}
	void setMaxRotateDampRange(const double3& xdr)
	{
		fprintf(mFile,"setAttr \".xdr\" -type \"double3\" ");
		xdr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxRotateDampRangeX(double xdx)
	{
		if(xdx == 0) return;
		fprintf(mFile,"setAttr \".xdr.xdx\" %f;\n", xdx);

	}
	void setMaxRotateDampRangeY(double xdy)
	{
		if(xdy == 0) return;
		fprintf(mFile,"setAttr \".xdr.xdy\" %f;\n", xdy);

	}
	void setMaxRotateDampRangeZ(double xdz)
	{
		if(xdz == 0) return;
		fprintf(mFile,"setAttr \".xdr.xdz\" %f;\n", xdz);

	}
	void setMaxRotateDampStrength(const double3& xst)
	{
		fprintf(mFile,"setAttr \".xst\" -type \"double3\" ");
		xst.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxRotateDampStrengthX(double xstx)
	{
		if(xstx == 0.0) return;
		fprintf(mFile,"setAttr \".xst.xstx\" %f;\n", xstx);

	}
	void setMaxRotateDampStrengthY(double xsty)
	{
		if(xsty == 0.0) return;
		fprintf(mFile,"setAttr \".xst.xsty\" %f;\n", xsty);

	}
	void setMaxRotateDampStrengthZ(double xstz)
	{
		if(xstz == 0.0) return;
		fprintf(mFile,"setAttr \".xst.xstz\" %f;\n", xstz);

	}
	void setBindPose(const matrix& bps)
	{
		if(bps == identity) return;
		fprintf(mFile,"setAttr \".bps\" -type \"matrix\" ");
		bps.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDrawStyle(unsigned int ds)
	{
		if(ds == 0) return;
		fprintf(mFile,"setAttr \".ds\" %i;\n", ds);

	}
	void setDrawLabel(bool dl)
	{
		if(dl == false) return;
		fprintf(mFile,"setAttr \".dl\" %i;\n", dl);

	}
	void setSide(unsigned int sd)
	{
		if(sd == 0) return;
		fprintf(mFile,"setAttr \".sd\" %i;\n", sd);

	}
	void setType(unsigned int typ)
	{
		if(typ == 0) return;
		fprintf(mFile,"setAttr \".typ\" %i;\n", typ);

	}
	void setOtherType(const string& otp)
	{
		if(otp == "jaw") return;
		fprintf(mFile,"setAttr \".otp\" -type \"string\" ");
		otp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRadius(double radi)
	{
		if(radi == 1.0) return;
		fprintf(mFile,"setAttr \".radi\" %f;\n", radi);

	}
	void setHikNodeID(int hni)
	{
		if(hni == -1) return;
		fprintf(mFile,"setAttr \".hni\" %i;\n", hni);

	}
	void getJointTypeX()
	{
		fprintf(mFile,"\"%s.jtx\"",mName.c_str());

	}
	void getJointTypeY()
	{
		fprintf(mFile,"\"%s.jty\"",mName.c_str());

	}
	void getJointTypeZ()
	{
		fprintf(mFile,"\"%s.jtz\"",mName.c_str());

	}
	void getJointOrient()
	{
		fprintf(mFile,"\"%s.jo\"",mName.c_str());

	}
	void getJointOrientX()
	{
		fprintf(mFile,"\"%s.jo.jox\"",mName.c_str());

	}
	void getJointOrientY()
	{
		fprintf(mFile,"\"%s.jo.joy\"",mName.c_str());

	}
	void getJointOrientZ()
	{
		fprintf(mFile,"\"%s.jo.joz\"",mName.c_str());

	}
	void getSegmentScaleCompensate()
	{
		fprintf(mFile,"\"%s.ssc\"",mName.c_str());

	}
	void getInverseScale()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getInverseScaleX()
	{
		fprintf(mFile,"\"%s.is.isx\"",mName.c_str());

	}
	void getInverseScaleY()
	{
		fprintf(mFile,"\"%s.is.isy\"",mName.c_str());

	}
	void getInverseScaleZ()
	{
		fprintf(mFile,"\"%s.is.isz\"",mName.c_str());

	}
	void getStiffness()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getStiffnessX()
	{
		fprintf(mFile,"\"%s.st.stx\"",mName.c_str());

	}
	void getStiffnessY()
	{
		fprintf(mFile,"\"%s.st.sty\"",mName.c_str());

	}
	void getStiffnessZ()
	{
		fprintf(mFile,"\"%s.st.stz\"",mName.c_str());

	}
	void getPreferredAngle()
	{
		fprintf(mFile,"\"%s.pa\"",mName.c_str());

	}
	void getPreferredAngleX()
	{
		fprintf(mFile,"\"%s.pa.pax\"",mName.c_str());

	}
	void getPreferredAngleY()
	{
		fprintf(mFile,"\"%s.pa.pay\"",mName.c_str());

	}
	void getPreferredAngleZ()
	{
		fprintf(mFile,"\"%s.pa.paz\"",mName.c_str());

	}
	void getMinRotateDampRange()
	{
		fprintf(mFile,"\"%s.ndr\"",mName.c_str());

	}
	void getMinRotateDampRangeX()
	{
		fprintf(mFile,"\"%s.ndr.ndx\"",mName.c_str());

	}
	void getMinRotateDampRangeY()
	{
		fprintf(mFile,"\"%s.ndr.ndy\"",mName.c_str());

	}
	void getMinRotateDampRangeZ()
	{
		fprintf(mFile,"\"%s.ndr.ndz\"",mName.c_str());

	}
	void getMinRotateDampStrength()
	{
		fprintf(mFile,"\"%s.nst\"",mName.c_str());

	}
	void getMinRotateDampStrengthX()
	{
		fprintf(mFile,"\"%s.nst.nstx\"",mName.c_str());

	}
	void getMinRotateDampStrengthY()
	{
		fprintf(mFile,"\"%s.nst.nsty\"",mName.c_str());

	}
	void getMinRotateDampStrengthZ()
	{
		fprintf(mFile,"\"%s.nst.nstz\"",mName.c_str());

	}
	void getMaxRotateDampRange()
	{
		fprintf(mFile,"\"%s.xdr\"",mName.c_str());

	}
	void getMaxRotateDampRangeX()
	{
		fprintf(mFile,"\"%s.xdr.xdx\"",mName.c_str());

	}
	void getMaxRotateDampRangeY()
	{
		fprintf(mFile,"\"%s.xdr.xdy\"",mName.c_str());

	}
	void getMaxRotateDampRangeZ()
	{
		fprintf(mFile,"\"%s.xdr.xdz\"",mName.c_str());

	}
	void getMaxRotateDampStrength()
	{
		fprintf(mFile,"\"%s.xst\"",mName.c_str());

	}
	void getMaxRotateDampStrengthX()
	{
		fprintf(mFile,"\"%s.xst.xstx\"",mName.c_str());

	}
	void getMaxRotateDampStrengthY()
	{
		fprintf(mFile,"\"%s.xst.xsty\"",mName.c_str());

	}
	void getMaxRotateDampStrengthZ()
	{
		fprintf(mFile,"\"%s.xst.xstz\"",mName.c_str());

	}
	void getBindPose()
	{
		fprintf(mFile,"\"%s.bps\"",mName.c_str());

	}
	void getDrawLabel()
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.radi\"",mName.c_str());

	}
	void getHikNodeID()
	{
		fprintf(mFile,"\"%s.hni\"",mName.c_str());

	}
protected:
	Joint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_JOINT_H__
