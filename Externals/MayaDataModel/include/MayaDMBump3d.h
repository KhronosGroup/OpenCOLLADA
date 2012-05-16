/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BUMP3D_H__
#define __MayaDM_BUMP3D_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Bump3d : public DependNode
{
public:
public:

	Bump3d():DependNode(){}
	Bump3d(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "bump3d", shared, create){}
	virtual ~Bump3d(){}

	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"\tsetAttr \".xpa\" %f;\n", xpa);
	}
	void setBumpDepth(float bd)
	{
		if(bd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bd\" %f;\n", bd);
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
	void getBumpDepth()const
	{
		fprintf(mFile,"\"%s.bd\"",mName.c_str());
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
protected:
	Bump3d(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BUMP3D_H__
