/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PFXGEOMETRY_H__
#define __MayaDM_PFXGEOMETRY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class PfxGeometry : public Shape
{
public:
public:

	PfxGeometry():Shape(){}
	PfxGeometry(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "pfxGeometry", shared, create){}
	virtual ~PfxGeometry(){}

	void setDisplayPercent(double dpc)
	{
		if(dpc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dpc\" %f;\n", dpc);
	}
	void setDrawAsMesh(bool dam)
	{
		if(dam == 1) return;
		fprintf(mFile,"\tsetAttr \".dam\" %i;\n", dam);
	}
	void setSeed(int sed)
	{
		if(sed == 0) return;
		fprintf(mFile,"\tsetAttr \".sed\" %i;\n", sed);
	}
	void setDrawOrder(int dro)
	{
		if(dro == 0) return;
		fprintf(mFile,"\tsetAttr \".dro\" %i;\n", dro);
	}
	void setSurfaceOffset(double sof)
	{
		if(sof == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sof\" %f;\n", sof);
	}
	void setMotionBlurred(bool mblr)
	{
		if(mblr == 1) return;
		fprintf(mFile,"\tsetAttr \".mblr\" %i;\n", mblr);
	}
	void setPrimaryVisibility(bool pvs)
	{
		if(pvs == 1) return;
		fprintf(mFile,"\tsetAttr \".pvs\" %i;\n", pvs);
	}
	void setMainVertBufSize(int mvbs)
	{
		if(mvbs == 0) return;
		fprintf(mFile,"\tsetAttr \".mvbs\" %i;\n", mvbs);
	}
	void setFlowerVertBufSize(int fvbs)
	{
		if(fvbs == 0) return;
		fprintf(mFile,"\tsetAttr \".fvbs\" %i;\n", fvbs);
	}
	void setLeafVertBufSize(int lvbs)
	{
		if(lvbs == 0) return;
		fprintf(mFile,"\tsetAttr \".lvbs\" %i;\n", lvbs);
	}
	void setMeshPolyLimit(int mpl)
	{
		if(mpl == 0) return;
		fprintf(mFile,"\tsetAttr \".mpl\" %i;\n", mpl);
	}
	void setMeshVertexColorMode(unsigned int mvc)
	{
		if(mvc == 0) return;
		fprintf(mFile,"\tsetAttr \".mvc\" %i;\n", mvc);
	}
	void setMeshHardEdges(bool mhe)
	{
		if(mhe == false) return;
		fprintf(mFile,"\tsetAttr \".mhe\" %i;\n", mhe);
	}
	void setMeshQuadOutput(bool mqo)
	{
		if(mqo == false) return;
		fprintf(mFile,"\tsetAttr \".mqo\" %i;\n", mqo);
	}
	void setCameraPoint(const double3& cpt)
	{
		fprintf(mFile,"\tsetAttr \".cpt\" -type \"double3\" ");
		cpt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCameraPointX(double cpx)
	{
		if(cpx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cpt.cpx\" %f;\n", cpx);
	}
	void setCameraPointY(double cpy)
	{
		if(cpy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cpt.cpy\" %f;\n", cpy);
	}
	void setCameraPointZ(double cpz)
	{
		if(cpz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cpt.cpz\" %f;\n", cpz);
	}
	void setMaxDrawSegments(int mdsg)
	{
		if(mdsg == 1000000) return;
		fprintf(mFile,"\tsetAttr \".mdsg\" %i;\n", mdsg);
	}
	void setCurveMode(int cmd)
	{
		if(cmd == 0) return;
		fprintf(mFile,"\tsetAttr \".cmd\" %i;\n", cmd);
	}
	void setLeafCurveMode(int lcm)
	{
		if(lcm == 0) return;
		fprintf(mFile,"\tsetAttr \".lcm\" %i;\n", lcm);
	}
	void setFlowerCurveMode(int fcm)
	{
		if(fcm == 0) return;
		fprintf(mFile,"\tsetAttr \".fcm\" %i;\n", fcm);
	}
	void setDegree(int dgr)
	{
		if(dgr == 2) return;
		fprintf(mFile,"\tsetAttr \".dgr\" %i;\n", dgr);
	}
	void setCurveAlign(bool cva)
	{
		if(cva == false) return;
		fprintf(mFile,"\tsetAttr \".cva\" %i;\n", cva);
	}
	void getDisplayPercent()const
	{
		fprintf(mFile,"\"%s.dpc\"",mName.c_str());
	}
	void getDrawAsMesh()const
	{
		fprintf(mFile,"\"%s.dam\"",mName.c_str());
	}
	void getSeed()const
	{
		fprintf(mFile,"\"%s.sed\"",mName.c_str());
	}
	void getDrawOrder()const
	{
		fprintf(mFile,"\"%s.dro\"",mName.c_str());
	}
	void getSurfaceOffset()const
	{
		fprintf(mFile,"\"%s.sof\"",mName.c_str());
	}
	void getBrush()const
	{
		fprintf(mFile,"\"%s.brs\"",mName.c_str());
	}
	void getMotionBlurred()const
	{
		fprintf(mFile,"\"%s.mblr\"",mName.c_str());
	}
	void getPrimaryVisibility()const
	{
		fprintf(mFile,"\"%s.pvs\"",mName.c_str());
	}
	void getControlCurve(size_t clc_i)const
	{
		fprintf(mFile,"\"%s.clc[%i]\"",mName.c_str(),clc_i);
	}
	void getControlCurve()const
	{

		fprintf(mFile,"\"%s.clc\"",mName.c_str());
	}
	void getOutMainMesh()const
	{
		fprintf(mFile,"\"%s.omm\"",mName.c_str());
	}
	void getOutFlowerMesh()const
	{
		fprintf(mFile,"\"%s.ofm\"",mName.c_str());
	}
	void getOutLeafMesh()const
	{
		fprintf(mFile,"\"%s.olm\"",mName.c_str());
	}
	void getWorldMainMesh(size_t wmm_i)const
	{
		fprintf(mFile,"\"%s.wmm[%i]\"",mName.c_str(),wmm_i);
	}
	void getWorldMainMesh()const
	{

		fprintf(mFile,"\"%s.wmm\"",mName.c_str());
	}
	void getWorldLeafMesh(size_t wlm_i)const
	{
		fprintf(mFile,"\"%s.wlm[%i]\"",mName.c_str(),wlm_i);
	}
	void getWorldLeafMesh()const
	{

		fprintf(mFile,"\"%s.wlm\"",mName.c_str());
	}
	void getWorldFlowerMesh(size_t wfm_i)const
	{
		fprintf(mFile,"\"%s.wfm[%i]\"",mName.c_str(),wfm_i);
	}
	void getWorldFlowerMesh()const
	{

		fprintf(mFile,"\"%s.wfm\"",mName.c_str());
	}
	void getMainVertBufSize()const
	{
		fprintf(mFile,"\"%s.mvbs\"",mName.c_str());
	}
	void getFlowerVertBufSize()const
	{
		fprintf(mFile,"\"%s.fvbs\"",mName.c_str());
	}
	void getLeafVertBufSize()const
	{
		fprintf(mFile,"\"%s.lvbs\"",mName.c_str());
	}
	void getMeshPolyLimit()const
	{
		fprintf(mFile,"\"%s.mpl\"",mName.c_str());
	}
	void getMeshVertexColorMode()const
	{
		fprintf(mFile,"\"%s.mvc\"",mName.c_str());
	}
	void getMeshHardEdges()const
	{
		fprintf(mFile,"\"%s.mhe\"",mName.c_str());
	}
	void getMeshQuadOutput()const
	{
		fprintf(mFile,"\"%s.mqo\"",mName.c_str());
	}
	void getCameraPoint()const
	{
		fprintf(mFile,"\"%s.cpt\"",mName.c_str());
	}
	void getCameraPointX()const
	{
		fprintf(mFile,"\"%s.cpt.cpx\"",mName.c_str());
	}
	void getCameraPointY()const
	{
		fprintf(mFile,"\"%s.cpt.cpy\"",mName.c_str());
	}
	void getCameraPointZ()const
	{
		fprintf(mFile,"\"%s.cpt.cpz\"",mName.c_str());
	}
	void getLineModifier(size_t lmd_i)const
	{
		fprintf(mFile,"\"%s.lmd[%i]\"",mName.c_str(),lmd_i);
	}
	void getLineModifier()const
	{

		fprintf(mFile,"\"%s.lmd\"",mName.c_str());
	}
	void getMaxDrawSegments()const
	{
		fprintf(mFile,"\"%s.mdsg\"",mName.c_str());
	}
	void getCurveMode()const
	{
		fprintf(mFile,"\"%s.cmd\"",mName.c_str());
	}
	void getLeafCurveMode()const
	{
		fprintf(mFile,"\"%s.lcm\"",mName.c_str());
	}
	void getFlowerCurveMode()const
	{
		fprintf(mFile,"\"%s.fcm\"",mName.c_str());
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.dgr\"",mName.c_str());
	}
	void getCurveAlign()const
	{
		fprintf(mFile,"\"%s.cva\"",mName.c_str());
	}
	void getOutMainCurveCount()const
	{
		fprintf(mFile,"\"%s.omcc\"",mName.c_str());
	}
	void getOutLeafCurveCount()const
	{
		fprintf(mFile,"\"%s.olcc\"",mName.c_str());
	}
	void getOutFlowerCurveCount()const
	{
		fprintf(mFile,"\"%s.ofcc\"",mName.c_str());
	}
	void getOutMainCurves(size_t omc_i)const
	{
		fprintf(mFile,"\"%s.omc[%i]\"",mName.c_str(),omc_i);
	}
	void getOutMainCurves()const
	{

		fprintf(mFile,"\"%s.omc\"",mName.c_str());
	}
	void getOutLeafCurves(size_t olc_i)const
	{
		fprintf(mFile,"\"%s.olc[%i]\"",mName.c_str(),olc_i);
	}
	void getOutLeafCurves()const
	{

		fprintf(mFile,"\"%s.olc\"",mName.c_str());
	}
	void getOutFlowerCurves(size_t ofc_i)const
	{
		fprintf(mFile,"\"%s.ofc[%i]\"",mName.c_str(),ofc_i);
	}
	void getOutFlowerCurves()const
	{

		fprintf(mFile,"\"%s.ofc\"",mName.c_str());
	}
protected:
	PfxGeometry(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PFXGEOMETRY_H__
