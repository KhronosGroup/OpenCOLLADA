/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	TextureEnv():DependNode(){}
	TextureEnv(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "textureEnv", shared, create){}
	virtual ~TextureEnv(){}

	void setObjectType(char ot)
	{
		if(ot == 1) return;
		fprintf(mFile,"\tsetAttr \".ot\" %;\n", ot);
	}
	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"\tsetAttr \".xpa\" %f;\n", xpa);
	}
	void getObjectType()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getPlacementMatrix()const
	{
		fprintf(mFile,"\"%s.pm\"",mName.c_str());
	}
	void getMatrixEyeToWorld()const
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());
	}
	void getXPixelAngle()const
	{
		fprintf(mFile,"\"%s.xpa\"",mName.c_str());
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
	void getRayDirection()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getRayDirectionX()const
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());
	}
	void getRayDirectionY()const
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());
	}
	void getRayDirectionZ()const
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());
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
	void getFilterSize()const
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getFilterSizeX()const
	{
		fprintf(mFile,"\"%s.fs.fsx\"",mName.c_str());
	}
	void getFilterSizeY()const
	{
		fprintf(mFile,"\"%s.fs.fsy\"",mName.c_str());
	}
	void getFilterSizeZ()const
	{
		fprintf(mFile,"\"%s.fs.fsz\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());
	}
	void getOutAlpha()const
	{
		fprintf(mFile,"\"%s.oa\"",mName.c_str());
	}
protected:
	TextureEnv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_TEXTUREENV_H__
