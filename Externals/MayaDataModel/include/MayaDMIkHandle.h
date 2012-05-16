/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKHANDLE_H__
#define __MayaDM_IKHANDLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class IkHandle : public Transform
{
public:
public:

	IkHandle():Transform(){}
	IkHandle(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Transform(file, name, parent, "ikHandle", shared, create){}
	virtual ~IkHandle(){}

	void setSnapEnable(bool hsh)
	{
		if(hsh == true) return;
		fprintf(mFile,"\tsetAttr \".hsh\" %i;\n", hsh);
	}
	void setStickiness(unsigned int hs)
	{
		if(hs == 0) return;
		fprintf(mFile,"\tsetAttr \".hs\" %i;\n", hs);
	}
	void setPriority(int hpr)
	{
		if(hpr == 1) return;
		fprintf(mFile,"\tsetAttr \".hpr\" %i;\n", hpr);
	}
	void setWeight(double hw)
	{
		if(hw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hw\" %f;\n", hw);
	}
	void setPoWeight(double hpo)
	{
		if(hpo == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hpo\" %f;\n", hpo);
	}
	void setPoleVector(const double3& pv)
	{
		fprintf(mFile,"\tsetAttr \".pv\" -type \"double3\" ");
		pv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPoleVectorX(double pvx)
	{
		if(pvx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pv.pvx\" %f;\n", pvx);
	}
	void setPoleVectorY(double pvy)
	{
		if(pvy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pv.pvy\" %f;\n", pvy);
	}
	void setPoleVectorZ(double pvz)
	{
		if(pvz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pv.pvz\" %f;\n", pvz);
	}
	void setOffset(double off)
	{
		if(off == 0.0) return;
		fprintf(mFile,"\tsetAttr \".off\" %f;\n", off);
	}
	void setRoll(double rol)
	{
		if(rol == 0) return;
		fprintf(mFile,"\tsetAttr \".rol\" %f;\n", rol);
	}
	void setTwist(double twi)
	{
		if(twi == 0) return;
		fprintf(mFile,"\tsetAttr \".twi\" %f;\n", twi);
	}
	void setRootOnCurve(bool roc)
	{
		if(roc == false) return;
		fprintf(mFile,"\tsetAttr \".roc\" %i;\n", roc);
	}
	void setTwistType(unsigned int twt)
	{
		if(twt == 0) return;
		fprintf(mFile,"\tsetAttr \".twt\" %i;\n", twt);
	}
	void setRootTwistMode(bool rtm)
	{
		if(rtm == false) return;
		fprintf(mFile,"\tsetAttr \".rtm\" %i;\n", rtm);
	}
	void setIkBlend(double ikb)
	{
		if(ikb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ikb\" %f;\n", ikb);
	}
	void setIkFkManipulation(bool eik)
	{
		if(eik == false) return;
		fprintf(mFile,"\tsetAttr \".eik\" %i;\n", eik);
	}
	void setDWorldUpType(unsigned int dwut)
	{
		if(dwut == 0) return;
		fprintf(mFile,"\tsetAttr \".dwut\" %i;\n", dwut);
	}
	void setDWorldUpAxis(unsigned int dwua)
	{
		if(dwua == 0) return;
		fprintf(mFile,"\tsetAttr \".dwua\" %i;\n", dwua);
	}
	void setDWorldUpVector(const double3& dwuv)
	{
		fprintf(mFile,"\tsetAttr \".dwuv\" -type \"double3\" ");
		dwuv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDWorldUpVectorX(double dwux)
	{
		if(dwux == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dwuv.dwux\" %f;\n", dwux);
	}
	void setDWorldUpVectorY(double dwuy)
	{
		if(dwuy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dwuv.dwuy\" %f;\n", dwuy);
	}
	void setDWorldUpVectorZ(double dwuz)
	{
		if(dwuz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dwuv.dwuz\" %f;\n", dwuz);
	}
	void setDWorldUpVectorEnd(const double3& dwve)
	{
		fprintf(mFile,"\tsetAttr \".dwve\" -type \"double3\" ");
		dwve.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDWorldUpVectorEndX(double dwvx)
	{
		if(dwvx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dwve.dwvx\" %f;\n", dwvx);
	}
	void setDWorldUpVectorEndY(double dwvy)
	{
		if(dwvy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dwve.dwvy\" %f;\n", dwvy);
	}
	void setDWorldUpVectorEndZ(double dwvz)
	{
		if(dwvz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dwve.dwvz\" %f;\n", dwvz);
	}
	void setDWorldUpMatrix(const matrix& dwum)
	{
		if(dwum == identity) return;
		fprintf(mFile,"\tsetAttr \".dwum\" -type \"matrix\" ");
		dwum.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDWorldUpMatrixEnd(const matrix& dwue)
	{
		if(dwue == identity) return;
		fprintf(mFile,"\tsetAttr \".dwue\" -type \"matrix\" ");
		dwue.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDTwistValueType(unsigned int dtvt)
	{
		if(dtvt == 0) return;
		fprintf(mFile,"\tsetAttr \".dtvt\" %i;\n", dtvt);
	}
	void setDTwistStartEnd(const double2& dtse)
	{
		fprintf(mFile,"\tsetAttr \".dtse\" -type \"double2\" ");
		dtse.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDTwistStart(double dtst)
	{
		if(dtst == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtse.dtst\" %f;\n", dtst);
	}
	void setDTwistEnd(double dten)
	{
		if(dten == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtse.dten\" %f;\n", dten);
	}
	void setDTwistRamp(const float3& dtra)
	{
		fprintf(mFile,"\tsetAttr \".dtra\" -type \"float3\" ");
		dtra.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDTwistRampR(float dtrr)
	{
		if(dtrr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtra.dtrr\" %f;\n", dtrr);
	}
	void setDTwistRampG(float dtrg)
	{
		if(dtrg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtra.dtrg\" %f;\n", dtrg);
	}
	void setDTwistRampB(float dtrb)
	{
		if(dtrb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtra.dtrb\" %f;\n", dtrb);
	}
	void setDTwistRampMult(double dtrm)
	{
		if(dtrm == 90.0) return;
		fprintf(mFile,"\tsetAttr \".dtrm\" %f;\n", dtrm);
	}
	void setDTwistControlEnable(bool dtce)
	{
		if(dtce == false) return;
		fprintf(mFile,"\tsetAttr \".dtce\" %i;\n", dtce);
	}
	void setSplineIkOldStyle(bool sio)
	{
		if(sio == false) return;
		fprintf(mFile,"\tsetAttr \".sio\" %i;\n", sio);
	}
	void getStartJoint()const
	{
		fprintf(mFile,"\"%s.hsj\"",mName.c_str());
	}
	void getEndEffector()const
	{
		fprintf(mFile,"\"%s.hee\"",mName.c_str());
	}
	void getIkSolver()const
	{
		fprintf(mFile,"\"%s.hsv\"",mName.c_str());
	}
	void getSnapEnable()const
	{
		fprintf(mFile,"\"%s.hsh\"",mName.c_str());
	}
	void getStickiness()const
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());
	}
	void getPriority()const
	{
		fprintf(mFile,"\"%s.hpr\"",mName.c_str());
	}
	void getWeight()const
	{
		fprintf(mFile,"\"%s.hw\"",mName.c_str());
	}
	void getPoWeight()const
	{
		fprintf(mFile,"\"%s.hpo\"",mName.c_str());
	}
	void getPoleVector()const
	{
		fprintf(mFile,"\"%s.pv\"",mName.c_str());
	}
	void getPoleVectorX()const
	{
		fprintf(mFile,"\"%s.pv.pvx\"",mName.c_str());
	}
	void getPoleVectorY()const
	{
		fprintf(mFile,"\"%s.pv.pvy\"",mName.c_str());
	}
	void getPoleVectorZ()const
	{
		fprintf(mFile,"\"%s.pv.pvz\"",mName.c_str());
	}
	void getInCurve()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.off\"",mName.c_str());
	}
	void getRoll()const
	{
		fprintf(mFile,"\"%s.rol\"",mName.c_str());
	}
	void getTwist()const
	{
		fprintf(mFile,"\"%s.twi\"",mName.c_str());
	}
	void getRootOnCurve()const
	{
		fprintf(mFile,"\"%s.roc\"",mName.c_str());
	}
	void getTwistType()const
	{
		fprintf(mFile,"\"%s.twt\"",mName.c_str());
	}
	void getRootTwistMode()const
	{
		fprintf(mFile,"\"%s.rtm\"",mName.c_str());
	}
	void getIkBlend()const
	{
		fprintf(mFile,"\"%s.ikb\"",mName.c_str());
	}
	void getIkFkManipulation()const
	{
		fprintf(mFile,"\"%s.eik\"",mName.c_str());
	}
	void getDWorldUpType()const
	{
		fprintf(mFile,"\"%s.dwut\"",mName.c_str());
	}
	void getDWorldUpAxis()const
	{
		fprintf(mFile,"\"%s.dwua\"",mName.c_str());
	}
	void getDWorldUpVector()const
	{
		fprintf(mFile,"\"%s.dwuv\"",mName.c_str());
	}
	void getDWorldUpVectorX()const
	{
		fprintf(mFile,"\"%s.dwuv.dwux\"",mName.c_str());
	}
	void getDWorldUpVectorY()const
	{
		fprintf(mFile,"\"%s.dwuv.dwuy\"",mName.c_str());
	}
	void getDWorldUpVectorZ()const
	{
		fprintf(mFile,"\"%s.dwuv.dwuz\"",mName.c_str());
	}
	void getDWorldUpVectorEnd()const
	{
		fprintf(mFile,"\"%s.dwve\"",mName.c_str());
	}
	void getDWorldUpVectorEndX()const
	{
		fprintf(mFile,"\"%s.dwve.dwvx\"",mName.c_str());
	}
	void getDWorldUpVectorEndY()const
	{
		fprintf(mFile,"\"%s.dwve.dwvy\"",mName.c_str());
	}
	void getDWorldUpVectorEndZ()const
	{
		fprintf(mFile,"\"%s.dwve.dwvz\"",mName.c_str());
	}
	void getDWorldUpMatrix()const
	{
		fprintf(mFile,"\"%s.dwum\"",mName.c_str());
	}
	void getDWorldUpMatrixEnd()const
	{
		fprintf(mFile,"\"%s.dwue\"",mName.c_str());
	}
	void getDTwistValueType()const
	{
		fprintf(mFile,"\"%s.dtvt\"",mName.c_str());
	}
	void getDTwistStartEnd()const
	{
		fprintf(mFile,"\"%s.dtse\"",mName.c_str());
	}
	void getDTwistStart()const
	{
		fprintf(mFile,"\"%s.dtse.dtst\"",mName.c_str());
	}
	void getDTwistEnd()const
	{
		fprintf(mFile,"\"%s.dtse.dten\"",mName.c_str());
	}
	void getDTwistRamp()const
	{
		fprintf(mFile,"\"%s.dtra\"",mName.c_str());
	}
	void getDTwistRampR()const
	{
		fprintf(mFile,"\"%s.dtra.dtrr\"",mName.c_str());
	}
	void getDTwistRampG()const
	{
		fprintf(mFile,"\"%s.dtra.dtrg\"",mName.c_str());
	}
	void getDTwistRampB()const
	{
		fprintf(mFile,"\"%s.dtra.dtrb\"",mName.c_str());
	}
	void getDTwistRampMult()const
	{
		fprintf(mFile,"\"%s.dtrm\"",mName.c_str());
	}
	void getDTwistControlEnable()const
	{
		fprintf(mFile,"\"%s.dtce\"",mName.c_str());
	}
	void getSplineIkOldStyle()const
	{
		fprintf(mFile,"\"%s.sio\"",mName.c_str());
	}
protected:
	IkHandle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Transform(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKHANDLE_H__
