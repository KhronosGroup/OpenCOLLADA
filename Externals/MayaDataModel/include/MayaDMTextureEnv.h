/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TEXTUREENV_H__
#define __MayaDM_TEXTUREENV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class TextureEnv : public DependNode
{
public:
public:
	TextureEnv(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "textureEnv"){}
	virtual ~TextureEnv(){}
	void setObjectType(char ot)
	{
		if(ot == 1) return;
		fprintf(mFile,"setAttr \".ot\" %;\n", ot);

	}
	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"setAttr \".xpa\" %f;\n", xpa);

	}
	void getObjectType()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getPlacementMatrix()
	{
		fprintf(mFile,"\"%s.pm\"",mName.c_str());

	}
	void getMatrixEyeToWorld()
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());

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
	void getRayDirection()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getRayDirectionX()
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());

	}
	void getRayDirectionY()
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());

	}
	void getRayDirectionZ()
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());

	}
	void getUvCoord()
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());

	}
	void getUCoord()
	{
		fprintf(mFile,"\"%s.uv.u\"",mName.c_str());

	}
	void getVCoord()
	{
		fprintf(mFile,"\"%s.uv.v\"",mName.c_str());

	}
	void getUvFilterSize()
	{
		fprintf(mFile,"\"%s.uf\"",mName.c_str());

	}
	void getUvFilterSizeX()
	{
		fprintf(mFile,"\"%s.uf.ufx\"",mName.c_str());

	}
	void getUvFilterSizeY()
	{
		fprintf(mFile,"\"%s.uf.ufy\"",mName.c_str());

	}
	void getFilterSize()
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());

	}
	void getFilterSizeX()
	{
		fprintf(mFile,"\"%s.fs.fsx\"",mName.c_str());

	}
	void getFilterSizeY()
	{
		fprintf(mFile,"\"%s.fs.fsy\"",mName.c_str());

	}
	void getFilterSizeZ()
	{
		fprintf(mFile,"\"%s.fs.fsz\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());

	}
	void getOutAlpha()
	{
		fprintf(mFile,"\"%s.oa\"",mName.c_str());

	}
protected:
	TextureEnv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TEXTUREENV_H__
