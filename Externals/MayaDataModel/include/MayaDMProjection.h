/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PROJECTION_H__
#define __MayaDM_PROJECTION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class Projection : public Texture3d
{
public:
public:

	Projection():Texture3d(){}
	Projection(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture3d(file, name, parent, "projection", shared, create){}
	virtual ~Projection(){}

	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"\tsetAttr \".xpa\" %f;\n", xpa);
	}
	void setImage(const float3& im)
	{
		if(im == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".im\" -type \"float3\" ");
		im.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImageR(float imr)
	{
		if(imr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".im.imr\" %f;\n", imr);
	}
	void setImageG(float img)
	{
		if(img == 0.0) return;
		fprintf(mFile,"\tsetAttr \".im.img\" %f;\n", img);
	}
	void setImageB(float imb)
	{
		if(imb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".im.imb\" %f;\n", imb);
	}
	void setUAngle(double ua)
	{
		if(ua == 1) return;
		fprintf(mFile,"\tsetAttr \".ua\" %f;\n", ua);
	}
	void setVAngle(double va)
	{
		if(va == 9) return;
		fprintf(mFile,"\tsetAttr \".va\" %f;\n", va);
	}
	void setProjType(unsigned int t)
	{
		if(t == 1) return;
		fprintf(mFile,"\tsetAttr \".t\" %i;\n", t);
	}
	void setFitType(unsigned int ft)
	{
		if(ft == 1) return;
		fprintf(mFile,"\tsetAttr \".ft\" %i;\n", ft);
	}
	void setFitFill(unsigned int ff)
	{
		if(ff == 0) return;
		fprintf(mFile,"\tsetAttr \".ff\" %i;\n", ff);
	}
	void setRipples(const float3& r)
	{
		if(r == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".r\" -type \"float3\" ");
		r.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRipplesX(float rx)
	{
		if(rx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r.rx\" %f;\n", rx);
	}
	void setRipplesY(float ry)
	{
		if(ry == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r.ry\" %f;\n", ry);
	}
	void setRipplesZ(float rz)
	{
		if(rz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r.rz\" %f;\n", rz);
	}
	void setDepth(const float2& d)
	{
		if(d == float2(0.0f,10.0f)) return;
		fprintf(mFile,"\tsetAttr \".d\" -type \"float2\" ");
		d.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDepthMin(float dmn)
	{
		if(dmn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d.dmn\" %f;\n", dmn);
	}
	void setDepthMax(float dmx)
	{
		if(dmx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d.dmx\" %f;\n", dmx);
	}
	void setAmplitudeX(float ax)
	{
		if(ax == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ax\" %f;\n", ax);
	}
	void setAmplitudeY(float ay)
	{
		if(ay == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ay\" %f;\n", ay);
	}
	void setRatio(float ra)
	{
		if(ra == 0.3) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
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
	void setVertexCameraThree(const float3& vc3)
	{
		fprintf(mFile,"\tsetAttr \".vc3\" -type \"float3\" ");
		vc3.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexCameraThreeX(float c3x)
	{
		if(c3x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc3.c3x\" %f;\n", c3x);
	}
	void setVertexCameraThreeY(float c3y)
	{
		if(c3y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc3.c3y\" %f;\n", c3y);
	}
	void setVertexCameraThreeZ(float c3z)
	{
		if(c3z == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc3.c3z\" %f;\n", c3z);
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
	void setVertexUvThree(const float2& vt3)
	{
		fprintf(mFile,"\tsetAttr \".vt3\" -type \"float2\" ");
		vt3.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexUvThreeU(float t3u)
	{
		if(t3u == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt3.t3u\" %f;\n", t3u);
	}
	void setVertexUvThreeV(float t3v)
	{
		if(t3v == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt3.t3v\" %f;\n", t3v);
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
	void getSrfNormal()const
	{
		fprintf(mFile,"\"%s.srn\"",mName.c_str());
	}
	void getSrfNormalX()const
	{
		fprintf(mFile,"\"%s.srn.snx\"",mName.c_str());
	}
	void getSrfNormalY()const
	{
		fprintf(mFile,"\"%s.srn.sny\"",mName.c_str());
	}
	void getSrfNormalZ()const
	{
		fprintf(mFile,"\"%s.srn.snz\"",mName.c_str());
	}
	void getRefPointObj()const
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());
	}
	void getRefPointObjX()const
	{
		fprintf(mFile,"\"%s.rpo.rox\"",mName.c_str());
	}
	void getRefPointObjY()const
	{
		fprintf(mFile,"\"%s.rpo.roy\"",mName.c_str());
	}
	void getRefPointObjZ()const
	{
		fprintf(mFile,"\"%s.rpo.roz\"",mName.c_str());
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
	void getXPixelAngle()const
	{
		fprintf(mFile,"\"%s.xpa\"",mName.c_str());
	}
	void getImage()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getImageR()const
	{
		fprintf(mFile,"\"%s.im.imr\"",mName.c_str());
	}
	void getImageG()const
	{
		fprintf(mFile,"\"%s.im.img\"",mName.c_str());
	}
	void getImageB()const
	{
		fprintf(mFile,"\"%s.im.imb\"",mName.c_str());
	}
	void getUAngle()const
	{
		fprintf(mFile,"\"%s.ua\"",mName.c_str());
	}
	void getVAngle()const
	{
		fprintf(mFile,"\"%s.va\"",mName.c_str());
	}
	void getProjType()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getLinkedCamera()const
	{
		fprintf(mFile,"\"%s.lc\"",mName.c_str());
	}
	void getFitType()const
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());
	}
	void getFitFill()const
	{
		fprintf(mFile,"\"%s.ff\"",mName.c_str());
	}
	void getRipples()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getRipplesX()const
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());
	}
	void getRipplesY()const
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());
	}
	void getRipplesZ()const
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());
	}
	void getDepth()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getDepthMin()const
	{
		fprintf(mFile,"\"%s.d.dmn\"",mName.c_str());
	}
	void getDepthMax()const
	{
		fprintf(mFile,"\"%s.d.dmx\"",mName.c_str());
	}
	void getAmplitudeX()const
	{
		fprintf(mFile,"\"%s.ax\"",mName.c_str());
	}
	void getAmplitudeY()const
	{
		fprintf(mFile,"\"%s.ay\"",mName.c_str());
	}
	void getRatio()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getInfoBits()const
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());
	}
	void getDepWts()const
	{
		fprintf(mFile,"\"%s.dwt\"",mName.c_str());
	}
	void getAngWts()const
	{
		fprintf(mFile,"\"%s.awt\"",mName.c_str());
	}
	void getCamPos()const
	{
		fprintf(mFile,"\"%s.cpo\"",mName.c_str());
	}
	void getCamPsX()const
	{
		fprintf(mFile,"\"%s.cpo.cpx\"",mName.c_str());
	}
	void getCamPsY()const
	{
		fprintf(mFile,"\"%s.cpo.cpy\"",mName.c_str());
	}
	void getCamPsZ()const
	{
		fprintf(mFile,"\"%s.cpo.cpz\"",mName.c_str());
	}
	void getCamAg()const
	{
		fprintf(mFile,"\"%s.cag\"",mName.c_str());
	}
	void getCamAngX()const
	{
		fprintf(mFile,"\"%s.cag.cax\"",mName.c_str());
	}
	void getCamAngY()const
	{
		fprintf(mFile,"\"%s.cag.cay\"",mName.c_str());
	}
	void getCamAngZ()const
	{
		fprintf(mFile,"\"%s.cag.caz\"",mName.c_str());
	}
	void getPassTr()const
	{
		fprintf(mFile,"\"%s.pst\"",mName.c_str());
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
	void getVertexCameraThree()const
	{
		fprintf(mFile,"\"%s.vc3\"",mName.c_str());
	}
	void getVertexCameraThreeX()const
	{
		fprintf(mFile,"\"%s.vc3.c3x\"",mName.c_str());
	}
	void getVertexCameraThreeY()const
	{
		fprintf(mFile,"\"%s.vc3.c3y\"",mName.c_str());
	}
	void getVertexCameraThreeZ()const
	{
		fprintf(mFile,"\"%s.vc3.c3z\"",mName.c_str());
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
	void getVertexUvThree()const
	{
		fprintf(mFile,"\"%s.vt3\"",mName.c_str());
	}
	void getVertexUvThreeU()const
	{
		fprintf(mFile,"\"%s.vt3.t3u\"",mName.c_str());
	}
	void getVertexUvThreeV()const
	{
		fprintf(mFile,"\"%s.vt3.t3v\"",mName.c_str());
	}
	void getUvFilterSize()const
	{
		fprintf(mFile,"\"%s.uf\"",mName.c_str());
	}
	void getUvFilterSizeX()const
	{
		fprintf(mFile,"\"%s.uf.ufx\"",mName.c_str());
	}
	void getUvFilterSizeY()const
	{
		fprintf(mFile,"\"%s.uf.ufy\"",mName.c_str());
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
protected:
	Projection(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture3d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PROJECTION_H__
