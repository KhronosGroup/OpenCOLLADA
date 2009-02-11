/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BROWNIAN_H__
#define __MayaDM_BROWNIAN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class Brownian : public Texture3d
{
public:
public:
	Brownian():Texture3d(){}
	Brownian(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "brownian"){}
	virtual ~Brownian(){}
	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"\tsetAttr \".xpa\" %f;\n", xpa);

	}
	void setLacunarity(float l)
	{
		if(l == 4.0) return;
		fprintf(mFile,"\tsetAttr \".l\" %f;\n", l);

	}
	void setIncrement(float ic)
	{
		if(ic == 0.1) return;
		fprintf(mFile,"\tsetAttr \".ic\" %f;\n", ic);

	}
	void setOctaves(float oct)
	{
		if(oct == 3.0) return;
		fprintf(mFile,"\tsetAttr \".oct\" %f;\n", oct);

	}
	void setWeight3d(const float3& w3)
	{
		if(w3 == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".w3\" -type \"float3\" ");
		w3.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWeight3dX(float w3x)
	{
		if(w3x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".w3.w3x\" %f;\n", w3x);

	}
	void setWeight3dY(float w3y)
	{
		if(w3y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".w3.w3y\" %f;\n", w3y);

	}
	void setWeight3dZ(float w3z)
	{
		if(w3z == 0.0) return;
		fprintf(mFile,"\tsetAttr \".w3.w3z\" %f;\n", w3z);

	}
	void getXPixelAngle()
	{
		fprintf(mFile,"\"%s.xpa\"",mName.c_str());

	}
	void getNormalCamera()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getNormalCameraX()
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());

	}
	void getNormalCameraY()
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());

	}
	void getNormalCameraZ()
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());

	}
	void getRefPointObj()
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());

	}
	void getRefPointObjX()
	{
		fprintf(mFile,"\"%s.rpo.rox\"",mName.c_str());

	}
	void getRefPointObjY()
	{
		fprintf(mFile,"\"%s.rpo.roy\"",mName.c_str());

	}
	void getRefPointObjZ()
	{
		fprintf(mFile,"\"%s.rpo.roz\"",mName.c_str());

	}
	void getRefPointCamera()
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());

	}
	void getRefPointCameraX()
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());

	}
	void getRefPointCameraY()
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());

	}
	void getRefPointCameraZ()
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());

	}
	void getLacunarity()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getIncrement()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getOctaves()
	{
		fprintf(mFile,"\"%s.oct\"",mName.c_str());

	}
	void getWeight3d()
	{
		fprintf(mFile,"\"%s.w3\"",mName.c_str());

	}
	void getWeight3dX()
	{
		fprintf(mFile,"\"%s.w3.w3x\"",mName.c_str());

	}
	void getWeight3dY()
	{
		fprintf(mFile,"\"%s.w3.w3y\"",mName.c_str());

	}
	void getWeight3dZ()
	{
		fprintf(mFile,"\"%s.w3.w3z\"",mName.c_str());

	}
protected:
	Brownian(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Texture3d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BROWNIAN_H__
