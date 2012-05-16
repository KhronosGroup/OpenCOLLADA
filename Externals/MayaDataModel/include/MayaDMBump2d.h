/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BUMP2D_H__
#define __MayaDM_BUMP2D_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Bump2d : public DependNode
{
public:
public:

	Bump2d():DependNode(){}
	Bump2d(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "bump2d", shared, create){}
	virtual ~Bump2d(){}

	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"\tsetAttr \".xpa\" %f;\n", xpa);
	}
	void setAdjustEdges(bool ae)
	{
		if(ae == false) return;
		fprintf(mFile,"\tsetAttr \".ae\" %i;\n", ae);
	}
	void setBumpDepth(float bd)
	{
		if(bd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bd\" %f;\n", bd);
	}
	void setBumpInterp(unsigned int bi)
	{
		if(bi == 0) return;
		fprintf(mFile,"\tsetAttr \".bi\" %i;\n", bi);
	}
	void setBumpFilter(float bf)
	{
		if(bf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bf\" %f;\n", bf);
	}
	void setBumpFilterOffset(float bfo)
	{
		if(bfo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bfo\" %f;\n", bfo);
	}
	void setBumpValue(float bv)
	{
		if(bv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bv\" %f;\n", bv);
	}
	void setProvide3dInfo(bool p3d)
	{
		if(p3d == false) return;
		fprintf(mFile,"\tsetAttr \".p3d\" %i;\n", p3d);
	}
	void setVertexUvOne(const float2& vt1)
	{
		fprintf(mFile,"\tsetAttr \".vt1\" -type \"float2\" ");
		vt1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexUvOneU(float t1u)
	{
		if(t1u == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt1.t1u\" %f;\n", t1u);
	}
	void setVertexUvOneV(float t1v)
	{
		if(t1v == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt1.t1v\" %f;\n", t1v);
	}
	void setVertexUvTwo(const float2& vt2)
	{
		fprintf(mFile,"\tsetAttr \".vt2\" -type \"float2\" ");
		vt2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexUvTwoU(float t2u)
	{
		if(t2u == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt2.t2u\" %f;\n", t2u);
	}
	void setVertexUvTwoV(float t2v)
	{
		if(t2v == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt2.t2v\" %f;\n", t2v);
	}
	void setVertexCameraOne(const float3& vc1)
	{
		fprintf(mFile,"\tsetAttr \".vc1\" -type \"float3\" ");
		vc1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexCameraOneX(float c1x)
	{
		if(c1x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc1.c1x\" %f;\n", c1x);
	}
	void setVertexCameraOneY(float c1y)
	{
		if(c1y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc1.c1y\" %f;\n", c1y);
	}
	void setVertexCameraOneZ(float c1z)
	{
		if(c1z == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc1.c1z\" %f;\n", c1z);
	}
	void setVertexCameraTwo(const float3& vc2)
	{
		fprintf(mFile,"\tsetAttr \".vc2\" -type \"float3\" ");
		vc2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexCameraTwoX(float c2x)
	{
		if(c2x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc2.c2x\" %f;\n", c2x);
	}
	void setVertexCameraTwoY(float c2y)
	{
		if(c2y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc2.c2y\" %f;\n", c2y);
	}
	void setVertexCameraTwoZ(float c2z)
	{
		if(c2z == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc2.c2z\" %f;\n", c2z);
	}
	void getPointCamera()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPointCameraX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPointCameraY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPointCameraZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getPointObj()const
	{
		fprintf(mFile,"\"%s.po\"",mName.c_str());
	}
	void getPointObjX()const
	{
		fprintf(mFile,"\"%s.po.pox\"",mName.c_str());
	}
	void getPointObjY()const
	{
		fprintf(mFile,"\"%s.po.poy\"",mName.c_str());
	}
	void getPointObjZ()const
	{
		fprintf(mFile,"\"%s.po.poz\"",mName.c_str());
	}
	void getRefPointObj()const
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());
	}
	void getRefPointObjX()const
	{
		fprintf(mFile,"\"%s.rpo.rpox\"",mName.c_str());
	}
	void getRefPointObjY()const
	{
		fprintf(mFile,"\"%s.rpo.rpoy\"",mName.c_str());
	}
	void getRefPointObjZ()const
	{
		fprintf(mFile,"\"%s.rpo.rpoz\"",mName.c_str());
	}
	void getRefPointCamera()const
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());
	}
	void getRefPointCameraX()const
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());
	}
	void getRefPointCameraY()const
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());
	}
	void getRefPointCameraZ()const
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());
	}
	void getRayOrigin()const
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());
	}
	void getRayOriginX()const
	{
		fprintf(mFile,"\"%s.ro.rox\"",mName.c_str());
	}
	void getRayOriginY()const
	{
		fprintf(mFile,"\"%s.ro.roy\"",mName.c_str());
	}
	void getRayOriginZ()const
	{
		fprintf(mFile,"\"%s.ro.roz\"",mName.c_str());
	}
	void getXPixelAngle()const
	{
		fprintf(mFile,"\"%s.xpa\"",mName.c_str());
	}
	void getUvCoord()const
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());
	}
	void getUCoord()const
	{
		fprintf(mFile,"\"%s.uv.u\"",mName.c_str());
	}
	void getVCoord()const
	{
		fprintf(mFile,"\"%s.uv.v\"",mName.c_str());
	}
	void getUvFilterSize()const
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getUvFilterSizeX()const
	{
		fprintf(mFile,"\"%s.fs.fsx\"",mName.c_str());
	}
	void getUvFilterSizeY()const
	{
		fprintf(mFile,"\"%s.fs.fsy\"",mName.c_str());
	}
	void getInfoBits()const
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());
	}
	void getNormalCamera()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNormalCameraX()const
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());
	}
	void getNormalCameraY()const
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());
	}
	void getNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());
	}
	void getTangentUCamera()const
	{
		fprintf(mFile,"\"%s.tu\"",mName.c_str());
	}
	void getTangentUx()const
	{
		fprintf(mFile,"\"%s.tu.tux\"",mName.c_str());
	}
	void getTangentUy()const
	{
		fprintf(mFile,"\"%s.tu.tuy\"",mName.c_str());
	}
	void getTangentUz()const
	{
		fprintf(mFile,"\"%s.tu.tuz\"",mName.c_str());
	}
	void getTangentVCamera()const
	{
		fprintf(mFile,"\"%s.tv\"",mName.c_str());
	}
	void getTangentVx()const
	{
		fprintf(mFile,"\"%s.tv.tvx\"",mName.c_str());
	}
	void getTangentVy()const
	{
		fprintf(mFile,"\"%s.tv.tvy\"",mName.c_str());
	}
	void getTangentVz()const
	{
		fprintf(mFile,"\"%s.tv.tvz\"",mName.c_str());
	}
	void getAdjustEdges()const
	{
		fprintf(mFile,"\"%s.ae\"",mName.c_str());
	}
	void getBumpDepth()const
	{
		fprintf(mFile,"\"%s.bd\"",mName.c_str());
	}
	void getBumpInterp()const
	{
		fprintf(mFile,"\"%s.bi\"",mName.c_str());
	}
	void getBumpFilter()const
	{
		fprintf(mFile,"\"%s.bf\"",mName.c_str());
	}
	void getBumpFilterOffset()const
	{
		fprintf(mFile,"\"%s.bfo\"",mName.c_str());
	}
	void getBumpValue()const
	{
		fprintf(mFile,"\"%s.bv\"",mName.c_str());
	}
	void getProvide3dInfo()const
	{
		fprintf(mFile,"\"%s.p3d\"",mName.c_str());
	}
	void getOutNormal()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getOutNormalX()const
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());
	}
	void getOutNormalY()const
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());
	}
	void getOutNormalZ()const
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());
	}
	void getVertexUvOne()const
	{
		fprintf(mFile,"\"%s.vt1\"",mName.c_str());
	}
	void getVertexUvOneU()const
	{
		fprintf(mFile,"\"%s.vt1.t1u\"",mName.c_str());
	}
	void getVertexUvOneV()const
	{
		fprintf(mFile,"\"%s.vt1.t1v\"",mName.c_str());
	}
	void getVertexUvTwo()const
	{
		fprintf(mFile,"\"%s.vt2\"",mName.c_str());
	}
	void getVertexUvTwoU()const
	{
		fprintf(mFile,"\"%s.vt2.t2u\"",mName.c_str());
	}
	void getVertexUvTwoV()const
	{
		fprintf(mFile,"\"%s.vt2.t2v\"",mName.c_str());
	}
	void getVertexCameraOne()const
	{
		fprintf(mFile,"\"%s.vc1\"",mName.c_str());
	}
	void getVertexCameraOneX()const
	{
		fprintf(mFile,"\"%s.vc1.c1x\"",mName.c_str());
	}
	void getVertexCameraOneY()const
	{
		fprintf(mFile,"\"%s.vc1.c1y\"",mName.c_str());
	}
	void getVertexCameraOneZ()const
	{
		fprintf(mFile,"\"%s.vc1.c1z\"",mName.c_str());
	}
	void getVertexCameraTwo()const
	{
		fprintf(mFile,"\"%s.vc2\"",mName.c_str());
	}
	void getVertexCameraTwoX()const
	{
		fprintf(mFile,"\"%s.vc2.c2x\"",mName.c_str());
	}
	void getVertexCameraTwoY()const
	{
		fprintf(mFile,"\"%s.vc2.c2y\"",mName.c_str());
	}
	void getVertexCameraTwoZ()const
	{
		fprintf(mFile,"\"%s.vc2.c2z\"",mName.c_str());
	}
protected:
	Bump2d(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BUMP2D_H__
