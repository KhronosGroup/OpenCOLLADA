/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PfxGeometry(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "pfxGeometry"){}
	virtual ~PfxGeometry(){}
	void setDisplayPercent(double dpc)
	{
		if(dpc == 0.0) return;
		fprintf(mFile,"setAttr \".dpc\" %f;\n", dpc);

	}
	void setDrawAsMesh(bool dam)
	{
		if(dam == 1) return;
		fprintf(mFile,"setAttr \".dam\" %i;\n", dam);

	}
	void setSeed(int sed)
	{
		if(sed == 0) return;
		fprintf(mFile,"setAttr \".sed\" %i;\n", sed);

	}
	void setDrawOrder(int dro)
	{
		if(dro == 0) return;
		fprintf(mFile,"setAttr \".dro\" %i;\n", dro);

	}
	void setSurfaceOffset(double sof)
	{
		if(sof == 0.0) return;
		fprintf(mFile,"setAttr \".sof\" %f;\n", sof);

	}
	void setMotionBlurred(bool mblr)
	{
		if(mblr == 1) return;
		fprintf(mFile,"setAttr \".mblr\" %i;\n", mblr);

	}
	void setPrimaryVisibility(bool pvs)
	{
		if(pvs == 1) return;
		fprintf(mFile,"setAttr \".pvs\" %i;\n", pvs);

	}
	void setMainVertBufSize(int mvbs)
	{
		if(mvbs == 0) return;
		fprintf(mFile,"setAttr \".mvbs\" %i;\n", mvbs);

	}
	void setFlowerVertBufSize(int fvbs)
	{
		if(fvbs == 0) return;
		fprintf(mFile,"setAttr \".fvbs\" %i;\n", fvbs);

	}
	void setLeafVertBufSize(int lvbs)
	{
		if(lvbs == 0) return;
		fprintf(mFile,"setAttr \".lvbs\" %i;\n", lvbs);

	}
	void setMeshPolyLimit(int mpl)
	{
		if(mpl == 0) return;
		fprintf(mFile,"setAttr \".mpl\" %i;\n", mpl);

	}
	void setMeshVertexColorMode(unsigned int mvc)
	{
		if(mvc == 0) return;
		fprintf(mFile,"setAttr \".mvc\" %i;\n", mvc);

	}
	void setMeshHardEdges(bool mhe)
	{
		if(mhe == false) return;
		fprintf(mFile,"setAttr \".mhe\" %i;\n", mhe);

	}
	void setMeshQuadOutput(bool mqo)
	{
		if(mqo == false) return;
		fprintf(mFile,"setAttr \".mqo\" %i;\n", mqo);

	}
	void setCameraPoint(const double3& cpt)
	{
		fprintf(mFile,"setAttr \".cpt\" -type \"double3\" ");
		cpt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCameraPointX(double cpx)
	{
		if(cpx == 0.0) return;
		fprintf(mFile,"setAttr \".cpt.cpx\" %f;\n", cpx);

	}
	void setCameraPointY(double cpy)
	{
		if(cpy == 0.0) return;
		fprintf(mFile,"setAttr \".cpt.cpy\" %f;\n", cpy);

	}
	void setCameraPointZ(double cpz)
	{
		if(cpz == 0.0) return;
		fprintf(mFile,"setAttr \".cpt.cpz\" %f;\n", cpz);

	}
	void setMaxDrawSegments(int mdsg)
	{
		if(mdsg == 1000000) return;
		fprintf(mFile,"setAttr \".mdsg\" %i;\n", mdsg);

	}
	void setCurveMode(int cmd)
	{
		if(cmd == 0) return;
		fprintf(mFile,"setAttr \".cmd\" %i;\n", cmd);

	}
	void setLeafCurveMode(int lcm)
	{
		if(lcm == 0) return;
		fprintf(mFile,"setAttr \".lcm\" %i;\n", lcm);

	}
	void setFlowerCurveMode(int fcm)
	{
		if(fcm == 0) return;
		fprintf(mFile,"setAttr \".fcm\" %i;\n", fcm);

	}
	void setDegree(int dgr)
	{
		if(dgr == 2) return;
		fprintf(mFile,"setAttr \".dgr\" %i;\n", dgr);

	}
	void setCurveAlign(bool cva)
	{
		if(cva == false) return;
		fprintf(mFile,"setAttr \".cva\" %i;\n", cva);

	}
	void getDisplayPercent()
	{
		fprintf(mFile,"\"%s.dpc\"",mName.c_str());

	}
	void getDrawAsMesh()
	{
		fprintf(mFile,"\"%s.dam\"",mName.c_str());

	}
	void getSeed()
	{
		fprintf(mFile,"\"%s.sed\"",mName.c_str());

	}
	void getDrawOrder()
	{
		fprintf(mFile,"\"%s.dro\"",mName.c_str());

	}
	void getSurfaceOffset()
	{
		fprintf(mFile,"\"%s.sof\"",mName.c_str());

	}
	void getBrush()
	{
		fprintf(mFile,"\"%s.brs\"",mName.c_str());

	}
	void getMotionBlurred()
	{
		fprintf(mFile,"\"%s.mblr\"",mName.c_str());

	}
	void getPrimaryVisibility()
	{
		fprintf(mFile,"\"%s.pvs\"",mName.c_str());

	}
	void getControlCurve(size_t clc_i)
	{
		fprintf(mFile,"\"%s.clc[%i]\"",mName.c_str(),clc_i);

	}
	void getOutMainMesh()
	{
		fprintf(mFile,"\"%s.omm\"",mName.c_str());

	}
	void getOutFlowerMesh()
	{
		fprintf(mFile,"\"%s.ofm\"",mName.c_str());

	}
	void getOutLeafMesh()
	{
		fprintf(mFile,"\"%s.olm\"",mName.c_str());

	}
	void getWorldMainMesh(size_t wmm_i)
	{
		fprintf(mFile,"\"%s.wmm[%i]\"",mName.c_str(),wmm_i);

	}
	void getWorldLeafMesh(size_t wlm_i)
	{
		fprintf(mFile,"\"%s.wlm[%i]\"",mName.c_str(),wlm_i);

	}
	void getWorldFlowerMesh(size_t wfm_i)
	{
		fprintf(mFile,"\"%s.wfm[%i]\"",mName.c_str(),wfm_i);

	}
	void getMainVertBufSize()
	{
		fprintf(mFile,"\"%s.mvbs\"",mName.c_str());

	}
	void getFlowerVertBufSize()
	{
		fprintf(mFile,"\"%s.fvbs\"",mName.c_str());

	}
	void getLeafVertBufSize()
	{
		fprintf(mFile,"\"%s.lvbs\"",mName.c_str());

	}
	void getMeshPolyLimit()
	{
		fprintf(mFile,"\"%s.mpl\"",mName.c_str());

	}
	void getMeshVertexColorMode()
	{
		fprintf(mFile,"\"%s.mvc\"",mName.c_str());

	}
	void getMeshHardEdges()
	{
		fprintf(mFile,"\"%s.mhe\"",mName.c_str());

	}
	void getMeshQuadOutput()
	{
		fprintf(mFile,"\"%s.mqo\"",mName.c_str());

	}
	void getCameraPoint()
	{
		fprintf(mFile,"\"%s.cpt\"",mName.c_str());

	}
	void getCameraPointX()
	{
		fprintf(mFile,"\"%s.cpt.cpx\"",mName.c_str());

	}
	void getCameraPointY()
	{
		fprintf(mFile,"\"%s.cpt.cpy\"",mName.c_str());

	}
	void getCameraPointZ()
	{
		fprintf(mFile,"\"%s.cpt.cpz\"",mName.c_str());

	}
	void getLineModifier(size_t lmd_i)
	{
		fprintf(mFile,"\"%s.lmd[%i]\"",mName.c_str(),lmd_i);

	}
	void getMaxDrawSegments()
	{
		fprintf(mFile,"\"%s.mdsg\"",mName.c_str());

	}
	void getCurveMode()
	{
		fprintf(mFile,"\"%s.cmd\"",mName.c_str());

	}
	void getLeafCurveMode()
	{
		fprintf(mFile,"\"%s.lcm\"",mName.c_str());

	}
	void getFlowerCurveMode()
	{
		fprintf(mFile,"\"%s.fcm\"",mName.c_str());

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.dgr\"",mName.c_str());

	}
	void getCurveAlign()
	{
		fprintf(mFile,"\"%s.cva\"",mName.c_str());

	}
	void getOutMainCurveCount()
	{
		fprintf(mFile,"\"%s.omcc\"",mName.c_str());

	}
	void getOutLeafCurveCount()
	{
		fprintf(mFile,"\"%s.olcc\"",mName.c_str());

	}
	void getOutFlowerCurveCount()
	{
		fprintf(mFile,"\"%s.ofcc\"",mName.c_str());

	}
	void getOutMainCurves(size_t omc_i)
	{
		fprintf(mFile,"\"%s.omc[%i]\"",mName.c_str(),omc_i);

	}
	void getOutLeafCurves(size_t olc_i)
	{
		fprintf(mFile,"\"%s.olc[%i]\"",mName.c_str(),olc_i);

	}
	void getOutFlowerCurves(size_t ofc_i)
	{
		fprintf(mFile,"\"%s.ofc[%i]\"",mName.c_str(),ofc_i);

	}
protected:
	PfxGeometry(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PFXGEOMETRY_H__
