/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	IkHandle(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "ikHandle"){}
	virtual ~IkHandle(){}
	void setSnapEnable(bool hsh)
	{
		if(hsh == true) return;
		fprintf(mFile,"setAttr \".hsh\" %i;\n", hsh);

	}
	void setStickiness(unsigned int hs)
	{
		if(hs == 0) return;
		fprintf(mFile,"setAttr \".hs\" %i;\n", hs);

	}
	void setPriority(int hpr)
	{
		if(hpr == 1) return;
		fprintf(mFile,"setAttr \".hpr\" %i;\n", hpr);

	}
	void setWeight(double hw)
	{
		if(hw == 1.0) return;
		fprintf(mFile,"setAttr \".hw\" %f;\n", hw);

	}
	void setPoWeight(double hpo)
	{
		if(hpo == 1.0) return;
		fprintf(mFile,"setAttr \".hpo\" %f;\n", hpo);

	}
	void setPoleVector(const double3& pv)
	{
		fprintf(mFile,"setAttr \".pv\" -type \"double3\" ");
		pv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPoleVectorX(double pvx)
	{
		if(pvx == 0.0) return;
		fprintf(mFile,"setAttr \".pv.pvx\" %f;\n", pvx);

	}
	void setPoleVectorY(double pvy)
	{
		if(pvy == 0.0) return;
		fprintf(mFile,"setAttr \".pv.pvy\" %f;\n", pvy);

	}
	void setPoleVectorZ(double pvz)
	{
		if(pvz == 1.0) return;
		fprintf(mFile,"setAttr \".pv.pvz\" %f;\n", pvz);

	}
	void setOffset(double off)
	{
		if(off == 0.0) return;
		fprintf(mFile,"setAttr \".off\" %f;\n", off);

	}
	void setRoll(double rol)
	{
		if(rol == 0) return;
		fprintf(mFile,"setAttr \".rol\" %f;\n", rol);

	}
	void setTwist(double twi)
	{
		if(twi == 0) return;
		fprintf(mFile,"setAttr \".twi\" %f;\n", twi);

	}
	void setRootOnCurve(bool roc)
	{
		if(roc == false) return;
		fprintf(mFile,"setAttr \".roc\" %i;\n", roc);

	}
	void setTwistType(unsigned int twt)
	{
		if(twt == 0) return;
		fprintf(mFile,"setAttr \".twt\" %i;\n", twt);

	}
	void setRootTwistMode(bool rtm)
	{
		if(rtm == false) return;
		fprintf(mFile,"setAttr \".rtm\" %i;\n", rtm);

	}
	void setIkBlend(double ikb)
	{
		if(ikb == 1.0) return;
		fprintf(mFile,"setAttr \".ikb\" %f;\n", ikb);

	}
	void setIkFkManipulation(bool eik)
	{
		if(eik == false) return;
		fprintf(mFile,"setAttr \".eik\" %i;\n", eik);

	}
	void setDWorldUpType(unsigned int dwut)
	{
		if(dwut == 0) return;
		fprintf(mFile,"setAttr \".dwut\" %i;\n", dwut);

	}
	void setDWorldUpAxis(unsigned int dwua)
	{
		if(dwua == 0) return;
		fprintf(mFile,"setAttr \".dwua\" %i;\n", dwua);

	}
	void setDWorldUpVector(const double3& dwuv)
	{
		fprintf(mFile,"setAttr \".dwuv\" -type \"double3\" ");
		dwuv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDWorldUpVectorX(double dwux)
	{
		if(dwux == 0.0) return;
		fprintf(mFile,"setAttr \".dwuv.dwux\" %f;\n", dwux);

	}
	void setDWorldUpVectorY(double dwuy)
	{
		if(dwuy == 1.0) return;
		fprintf(mFile,"setAttr \".dwuv.dwuy\" %f;\n", dwuy);

	}
	void setDWorldUpVectorZ(double dwuz)
	{
		if(dwuz == 0.0) return;
		fprintf(mFile,"setAttr \".dwuv.dwuz\" %f;\n", dwuz);

	}
	void setDWorldUpVectorEnd(const double3& dwve)
	{
		fprintf(mFile,"setAttr \".dwve\" -type \"double3\" ");
		dwve.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDWorldUpVectorEndX(double dwvx)
	{
		if(dwvx == 0.0) return;
		fprintf(mFile,"setAttr \".dwve.dwvx\" %f;\n", dwvx);

	}
	void setDWorldUpVectorEndY(double dwvy)
	{
		if(dwvy == 1.0) return;
		fprintf(mFile,"setAttr \".dwve.dwvy\" %f;\n", dwvy);

	}
	void setDWorldUpVectorEndZ(double dwvz)
	{
		if(dwvz == 0.0) return;
		fprintf(mFile,"setAttr \".dwve.dwvz\" %f;\n", dwvz);

	}
	void setDWorldUpMatrix(const matrix& dwum)
	{
		if(dwum == identity) return;
		fprintf(mFile,"setAttr \".dwum\" -type \"matrix\" ");
		dwum.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDWorldUpMatrixEnd(const matrix& dwue)
	{
		if(dwue == identity) return;
		fprintf(mFile,"setAttr \".dwue\" -type \"matrix\" ");
		dwue.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDTwistValueType(unsigned int dtvt)
	{
		if(dtvt == 0) return;
		fprintf(mFile,"setAttr \".dtvt\" %i;\n", dtvt);

	}
	void setDTwistStartEnd(const double2& dtse)
	{
		fprintf(mFile,"setAttr \".dtse\" -type \"double2\" ");
		dtse.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDTwistStart(double dtst)
	{
		if(dtst == 0.0) return;
		fprintf(mFile,"setAttr \".dtse.dtst\" %f;\n", dtst);

	}
	void setDTwistEnd(double dten)
	{
		if(dten == 0.0) return;
		fprintf(mFile,"setAttr \".dtse.dten\" %f;\n", dten);

	}
	void setDTwistRamp(const float3& dtra)
	{
		fprintf(mFile,"setAttr \".dtra\" -type \"float3\" ");
		dtra.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDTwistRampR(float dtrr)
	{
		if(dtrr == 0.0) return;
		fprintf(mFile,"setAttr \".dtra.dtrr\" %f;\n", dtrr);

	}
	void setDTwistRampG(float dtrg)
	{
		if(dtrg == 0.0) return;
		fprintf(mFile,"setAttr \".dtra.dtrg\" %f;\n", dtrg);

	}
	void setDTwistRampB(float dtrb)
	{
		if(dtrb == 0.0) return;
		fprintf(mFile,"setAttr \".dtra.dtrb\" %f;\n", dtrb);

	}
	void setDTwistRampMult(double dtrm)
	{
		if(dtrm == 90.0) return;
		fprintf(mFile,"setAttr \".dtrm\" %f;\n", dtrm);

	}
	void setDTwistControlEnable(bool dtce)
	{
		if(dtce == false) return;
		fprintf(mFile,"setAttr \".dtce\" %i;\n", dtce);

	}
	void setSplineIkOldStyle(bool sio)
	{
		if(sio == false) return;
		fprintf(mFile,"setAttr \".sio\" %i;\n", sio);

	}
	void getStartJoint()
	{
		fprintf(mFile,"\"%s.hsj\"",mName.c_str());

	}
	void getEndEffector()
	{
		fprintf(mFile,"\"%s.hee\"",mName.c_str());

	}
	void getIkSolver()
	{
		fprintf(mFile,"\"%s.hsv\"",mName.c_str());

	}
	void getSnapEnable()
	{
		fprintf(mFile,"\"%s.hsh\"",mName.c_str());

	}
	void getStickiness()
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());

	}
	void getPriority()
	{
		fprintf(mFile,"\"%s.hpr\"",mName.c_str());

	}
	void getWeight()
	{
		fprintf(mFile,"\"%s.hw\"",mName.c_str());

	}
	void getPoWeight()
	{
		fprintf(mFile,"\"%s.hpo\"",mName.c_str());

	}
	void getPoleVector()
	{
		fprintf(mFile,"\"%s.pv\"",mName.c_str());

	}
	void getPoleVectorX()
	{
		fprintf(mFile,"\"%s.pv.pvx\"",mName.c_str());

	}
	void getPoleVectorY()
	{
		fprintf(mFile,"\"%s.pv.pvy\"",mName.c_str());

	}
	void getPoleVectorZ()
	{
		fprintf(mFile,"\"%s.pv.pvz\"",mName.c_str());

	}
	void getInCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.off\"",mName.c_str());

	}
	void getRoll()
	{
		fprintf(mFile,"\"%s.rol\"",mName.c_str());

	}
	void getTwist()
	{
		fprintf(mFile,"\"%s.twi\"",mName.c_str());

	}
	void getRootOnCurve()
	{
		fprintf(mFile,"\"%s.roc\"",mName.c_str());

	}
	void getTwistType()
	{
		fprintf(mFile,"\"%s.twt\"",mName.c_str());

	}
	void getRootTwistMode()
	{
		fprintf(mFile,"\"%s.rtm\"",mName.c_str());

	}
	void getIkBlend()
	{
		fprintf(mFile,"\"%s.ikb\"",mName.c_str());

	}
	void getIkFkManipulation()
	{
		fprintf(mFile,"\"%s.eik\"",mName.c_str());

	}
	void getDWorldUpType()
	{
		fprintf(mFile,"\"%s.dwut\"",mName.c_str());

	}
	void getDWorldUpAxis()
	{
		fprintf(mFile,"\"%s.dwua\"",mName.c_str());

	}
	void getDWorldUpVector()
	{
		fprintf(mFile,"\"%s.dwuv\"",mName.c_str());

	}
	void getDWorldUpVectorX()
	{
		fprintf(mFile,"\"%s.dwuv.dwux\"",mName.c_str());

	}
	void getDWorldUpVectorY()
	{
		fprintf(mFile,"\"%s.dwuv.dwuy\"",mName.c_str());

	}
	void getDWorldUpVectorZ()
	{
		fprintf(mFile,"\"%s.dwuv.dwuz\"",mName.c_str());

	}
	void getDWorldUpVectorEnd()
	{
		fprintf(mFile,"\"%s.dwve\"",mName.c_str());

	}
	void getDWorldUpVectorEndX()
	{
		fprintf(mFile,"\"%s.dwve.dwvx\"",mName.c_str());

	}
	void getDWorldUpVectorEndY()
	{
		fprintf(mFile,"\"%s.dwve.dwvy\"",mName.c_str());

	}
	void getDWorldUpVectorEndZ()
	{
		fprintf(mFile,"\"%s.dwve.dwvz\"",mName.c_str());

	}
	void getDWorldUpMatrix()
	{
		fprintf(mFile,"\"%s.dwum\"",mName.c_str());

	}
	void getDWorldUpMatrixEnd()
	{
		fprintf(mFile,"\"%s.dwue\"",mName.c_str());

	}
	void getDTwistValueType()
	{
		fprintf(mFile,"\"%s.dtvt\"",mName.c_str());

	}
	void getDTwistStartEnd()
	{
		fprintf(mFile,"\"%s.dtse\"",mName.c_str());

	}
	void getDTwistStart()
	{
		fprintf(mFile,"\"%s.dtse.dtst\"",mName.c_str());

	}
	void getDTwistEnd()
	{
		fprintf(mFile,"\"%s.dtse.dten\"",mName.c_str());

	}
	void getDTwistRamp()
	{
		fprintf(mFile,"\"%s.dtra\"",mName.c_str());

	}
	void getDTwistRampR()
	{
		fprintf(mFile,"\"%s.dtra.dtrr\"",mName.c_str());

	}
	void getDTwistRampG()
	{
		fprintf(mFile,"\"%s.dtra.dtrg\"",mName.c_str());

	}
	void getDTwistRampB()
	{
		fprintf(mFile,"\"%s.dtra.dtrb\"",mName.c_str());

	}
	void getDTwistRampMult()
	{
		fprintf(mFile,"\"%s.dtrm\"",mName.c_str());

	}
	void getDTwistControlEnable()
	{
		fprintf(mFile,"\"%s.dtce\"",mName.c_str());

	}
	void getSplineIkOldStyle()
	{
		fprintf(mFile,"\"%s.sio\"",mName.c_str());

	}
protected:
	IkHandle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKHANDLE_H__
