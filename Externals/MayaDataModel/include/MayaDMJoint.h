/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Joint():Transform(){}
	Joint(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Transform(file, name, parent, "joint", shared, create){}
	virtual ~Joint(){}

	void setJointOrientType(const string& jot)
	{
		if(jot == "xyz") return;
		fprintf(mFile,"\tsetAttr \".jot\" -type \"string\" ");
		jot.write(mFile);
		fprintf(mFile,";\n");
	}
	void setJointTypeX(bool jtx)
	{
		if(jtx == true) return;
		fprintf(mFile,"\tsetAttr \".jtx\" %i;\n", jtx);
	}
	void setJointTypeY(bool jty)
	{
		if(jty == true) return;
		fprintf(mFile,"\tsetAttr \".jty\" %i;\n", jty);
	}
	void setJointTypeZ(bool jtz)
	{
		if(jtz == true) return;
		fprintf(mFile,"\tsetAttr \".jtz\" %i;\n", jtz);
	}
	void setJointOrient(const double3& jo)
	{
		fprintf(mFile,"\tsetAttr \".jo\" -type \"double3\" ");
		jo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setJointOrientX(double jox)
	{
		if(jox == 0) return;
		fprintf(mFile,"\tsetAttr \".jo.jox\" %f;\n", jox);
	}
	void setJointOrientY(double joy)
	{
		if(joy == 0) return;
		fprintf(mFile,"\tsetAttr \".jo.joy\" %f;\n", joy);
	}
	void setJointOrientZ(double joz)
	{
		if(joz == 0) return;
		fprintf(mFile,"\tsetAttr \".jo.joz\" %f;\n", joz);
	}
	void setSegmentScaleCompensate(bool ssc)
	{
		if(ssc == true) return;
		fprintf(mFile,"\tsetAttr \".ssc\" %i;\n", ssc);
	}
	void setInverseScale(const double3& is)
	{
		fprintf(mFile,"\tsetAttr \".is\" -type \"double3\" ");
		is.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInverseScaleX(double isx)
	{
		if(isx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".is.isx\" %f;\n", isx);
	}
	void setInverseScaleY(double isy)
	{
		if(isy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".is.isy\" %f;\n", isy);
	}
	void setInverseScaleZ(double isz)
	{
		if(isz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".is.isz\" %f;\n", isz);
	}
	void setStiffness(const double3& st)
	{
		fprintf(mFile,"\tsetAttr \".st\" -type \"double3\" ");
		st.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStiffnessX(double stx)
	{
		if(stx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".st.stx\" %f;\n", stx);
	}
	void setStiffnessY(double sty)
	{
		if(sty == 0.0) return;
		fprintf(mFile,"\tsetAttr \".st.sty\" %f;\n", sty);
	}
	void setStiffnessZ(double stz)
	{
		if(stz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".st.stz\" %f;\n", stz);
	}
	void setPreferredAngle(const double3& pa)
	{
		fprintf(mFile,"\tsetAttr \".pa\" -type \"double3\" ");
		pa.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPreferredAngleX(double pax)
	{
		if(pax == 0) return;
		fprintf(mFile,"\tsetAttr \".pa.pax\" %f;\n", pax);
	}
	void setPreferredAngleY(double pay)
	{
		if(pay == 0) return;
		fprintf(mFile,"\tsetAttr \".pa.pay\" %f;\n", pay);
	}
	void setPreferredAngleZ(double paz)
	{
		if(paz == 0) return;
		fprintf(mFile,"\tsetAttr \".pa.paz\" %f;\n", paz);
	}
	void setMinRotateDampRange(const double3& ndr)
	{
		fprintf(mFile,"\tsetAttr \".ndr\" -type \"double3\" ");
		ndr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinRotateDampRangeX(double ndx)
	{
		if(ndx == 0) return;
		fprintf(mFile,"\tsetAttr \".ndr.ndx\" %f;\n", ndx);
	}
	void setMinRotateDampRangeY(double ndy)
	{
		if(ndy == 0) return;
		fprintf(mFile,"\tsetAttr \".ndr.ndy\" %f;\n", ndy);
	}
	void setMinRotateDampRangeZ(double ndz)
	{
		if(ndz == 0) return;
		fprintf(mFile,"\tsetAttr \".ndr.ndz\" %f;\n", ndz);
	}
	void setMinRotateDampStrength(const double3& nst)
	{
		fprintf(mFile,"\tsetAttr \".nst\" -type \"double3\" ");
		nst.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinRotateDampStrengthX(double nstx)
	{
		if(nstx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".nst.nstx\" %f;\n", nstx);
	}
	void setMinRotateDampStrengthY(double nsty)
	{
		if(nsty == 0.0) return;
		fprintf(mFile,"\tsetAttr \".nst.nsty\" %f;\n", nsty);
	}
	void setMinRotateDampStrengthZ(double nstz)
	{
		if(nstz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".nst.nstz\" %f;\n", nstz);
	}
	void setMaxRotateDampRange(const double3& xdr)
	{
		fprintf(mFile,"\tsetAttr \".xdr\" -type \"double3\" ");
		xdr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxRotateDampRangeX(double xdx)
	{
		if(xdx == 0) return;
		fprintf(mFile,"\tsetAttr \".xdr.xdx\" %f;\n", xdx);
	}
	void setMaxRotateDampRangeY(double xdy)
	{
		if(xdy == 0) return;
		fprintf(mFile,"\tsetAttr \".xdr.xdy\" %f;\n", xdy);
	}
	void setMaxRotateDampRangeZ(double xdz)
	{
		if(xdz == 0) return;
		fprintf(mFile,"\tsetAttr \".xdr.xdz\" %f;\n", xdz);
	}
	void setMaxRotateDampStrength(const double3& xst)
	{
		fprintf(mFile,"\tsetAttr \".xst\" -type \"double3\" ");
		xst.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxRotateDampStrengthX(double xstx)
	{
		if(xstx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".xst.xstx\" %f;\n", xstx);
	}
	void setMaxRotateDampStrengthY(double xsty)
	{
		if(xsty == 0.0) return;
		fprintf(mFile,"\tsetAttr \".xst.xsty\" %f;\n", xsty);
	}
	void setMaxRotateDampStrengthZ(double xstz)
	{
		if(xstz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".xst.xstz\" %f;\n", xstz);
	}
	void setBindPose(const matrix& bps)
	{
		if(bps == identity) return;
		fprintf(mFile,"\tsetAttr \".bps\" -type \"matrix\" ");
		bps.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDrawStyle(unsigned int ds)
	{
		if(ds == 0) return;
		fprintf(mFile,"\tsetAttr \".ds\" %i;\n", ds);
	}
	void setDrawLabel(bool dl)
	{
		if(dl == false) return;
		fprintf(mFile,"\tsetAttr \".dl\" %i;\n", dl);
	}
	void setSide(unsigned int sd)
	{
		if(sd == 0) return;
		fprintf(mFile,"\tsetAttr \".sd\" %i;\n", sd);
	}
	void setType(unsigned int typ)
	{
		if(typ == 0) return;
		fprintf(mFile,"\tsetAttr \".typ\" %i;\n", typ);
	}
	void setOtherType(const string& otp)
	{
		if(otp == "jaw") return;
		fprintf(mFile,"\tsetAttr \".otp\" -type \"string\" ");
		otp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRadius(double radi)
	{
		if(radi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".radi\" %f;\n", radi);
	}
	void setHikNodeID(int hni)
	{
		if(hni == -1) return;
		fprintf(mFile,"\tsetAttr \".hni\" %i;\n", hni);
	}
	void getJointTypeX()const
	{
		fprintf(mFile,"\"%s.jtx\"",mName.c_str());
	}
	void getJointTypeY()const
	{
		fprintf(mFile,"\"%s.jty\"",mName.c_str());
	}
	void getJointTypeZ()const
	{
		fprintf(mFile,"\"%s.jtz\"",mName.c_str());
	}
	void getJointOrient()const
	{
		fprintf(mFile,"\"%s.jo\"",mName.c_str());
	}
	void getJointOrientX()const
	{
		fprintf(mFile,"\"%s.jo.jox\"",mName.c_str());
	}
	void getJointOrientY()const
	{
		fprintf(mFile,"\"%s.jo.joy\"",mName.c_str());
	}
	void getJointOrientZ()const
	{
		fprintf(mFile,"\"%s.jo.joz\"",mName.c_str());
	}
	void getSegmentScaleCompensate()const
	{
		fprintf(mFile,"\"%s.ssc\"",mName.c_str());
	}
	void getInverseScale()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getInverseScaleX()const
	{
		fprintf(mFile,"\"%s.is.isx\"",mName.c_str());
	}
	void getInverseScaleY()const
	{
		fprintf(mFile,"\"%s.is.isy\"",mName.c_str());
	}
	void getInverseScaleZ()const
	{
		fprintf(mFile,"\"%s.is.isz\"",mName.c_str());
	}
	void getStiffness()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getStiffnessX()const
	{
		fprintf(mFile,"\"%s.st.stx\"",mName.c_str());
	}
	void getStiffnessY()const
	{
		fprintf(mFile,"\"%s.st.sty\"",mName.c_str());
	}
	void getStiffnessZ()const
	{
		fprintf(mFile,"\"%s.st.stz\"",mName.c_str());
	}
	void getPreferredAngle()const
	{
		fprintf(mFile,"\"%s.pa\"",mName.c_str());
	}
	void getPreferredAngleX()const
	{
		fprintf(mFile,"\"%s.pa.pax\"",mName.c_str());
	}
	void getPreferredAngleY()const
	{
		fprintf(mFile,"\"%s.pa.pay\"",mName.c_str());
	}
	void getPreferredAngleZ()const
	{
		fprintf(mFile,"\"%s.pa.paz\"",mName.c_str());
	}
	void getMinRotateDampRange()const
	{
		fprintf(mFile,"\"%s.ndr\"",mName.c_str());
	}
	void getMinRotateDampRangeX()const
	{
		fprintf(mFile,"\"%s.ndr.ndx\"",mName.c_str());
	}
	void getMinRotateDampRangeY()const
	{
		fprintf(mFile,"\"%s.ndr.ndy\"",mName.c_str());
	}
	void getMinRotateDampRangeZ()const
	{
		fprintf(mFile,"\"%s.ndr.ndz\"",mName.c_str());
	}
	void getMinRotateDampStrength()const
	{
		fprintf(mFile,"\"%s.nst\"",mName.c_str());
	}
	void getMinRotateDampStrengthX()const
	{
		fprintf(mFile,"\"%s.nst.nstx\"",mName.c_str());
	}
	void getMinRotateDampStrengthY()const
	{
		fprintf(mFile,"\"%s.nst.nsty\"",mName.c_str());
	}
	void getMinRotateDampStrengthZ()const
	{
		fprintf(mFile,"\"%s.nst.nstz\"",mName.c_str());
	}
	void getMaxRotateDampRange()const
	{
		fprintf(mFile,"\"%s.xdr\"",mName.c_str());
	}
	void getMaxRotateDampRangeX()const
	{
		fprintf(mFile,"\"%s.xdr.xdx\"",mName.c_str());
	}
	void getMaxRotateDampRangeY()const
	{
		fprintf(mFile,"\"%s.xdr.xdy\"",mName.c_str());
	}
	void getMaxRotateDampRangeZ()const
	{
		fprintf(mFile,"\"%s.xdr.xdz\"",mName.c_str());
	}
	void getMaxRotateDampStrength()const
	{
		fprintf(mFile,"\"%s.xst\"",mName.c_str());
	}
	void getMaxRotateDampStrengthX()const
	{
		fprintf(mFile,"\"%s.xst.xstx\"",mName.c_str());
	}
	void getMaxRotateDampStrengthY()const
	{
		fprintf(mFile,"\"%s.xst.xsty\"",mName.c_str());
	}
	void getMaxRotateDampStrengthZ()const
	{
		fprintf(mFile,"\"%s.xst.xstz\"",mName.c_str());
	}
	void getBindPose()const
	{
		fprintf(mFile,"\"%s.bps\"",mName.c_str());
	}
	void getDrawLabel()const
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.radi\"",mName.c_str());
	}
	void getHikNodeID()const
	{
		fprintf(mFile,"\"%s.hni\"",mName.c_str());
	}
protected:
	Joint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Transform(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_JOINT_H__
