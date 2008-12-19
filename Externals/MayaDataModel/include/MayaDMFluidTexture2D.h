/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLUIDTEXTURE2D_H__
#define __MayaDM_FLUIDTEXTURE2D_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFluidShape.h"
namespace MayaDM
{
class FluidTexture2D : public FluidShape
{
public:
public:
	FluidTexture2D(FILE* file,const std::string& name,const std::string& parent=""):FluidShape(file, name, parent, "fluidTexture2D"){}
	virtual ~FluidTexture2D(){}
	void setAlphaGain(float ag)
	{
		if(ag == 1.0) return;
		fprintf(mFile,"setAttr \".ag\" %f;\n", ag);

	}
	void setAlphaOffset(float ao)
	{
		if(ao == 0.0) return;
		fprintf(mFile,"setAttr \".ao\" %f;\n", ao);

	}
	void setDefaultColor(const float3& dcl)
	{
		if(dcl == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"setAttr \".dcl\" -type \"float3\" ");
		dcl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDefaultColorR(float dcr)
	{
		if(dcr == 0.0) return;
		fprintf(mFile,"setAttr \".dcl.dcr\" %f;\n", dcr);

	}
	void setDefaultColorG(float dcg)
	{
		if(dcg == 0.0) return;
		fprintf(mFile,"setAttr \".dcl.dcg\" %f;\n", dcg);

	}
	void setDefaultColorB(float dcb)
	{
		if(dcb == 0.0) return;
		fprintf(mFile,"setAttr \".dcl.dcb\" %f;\n", dcb);

	}
	void getUvCoord()
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());

	}
	void getUCoord()
	{
		fprintf(mFile,"\"%s.uv.uvu\"",mName.c_str());

	}
	void getVCoord()
	{
		fprintf(mFile,"\"%s.uv.uvv\"",mName.c_str());

	}
	void getUvFilterSize()
	{
		fprintf(mFile,"\"%s.uvfs\"",mName.c_str());

	}
	void getUvFilterSizeX()
	{
		fprintf(mFile,"\"%s.uvfs.uvfsx\"",mName.c_str());

	}
	void getUvFilterSizeY()
	{
		fprintf(mFile,"\"%s.uvfs.uvfsy\"",mName.c_str());

	}
	void getOutAlpha()
	{
		fprintf(mFile,"\"%s.oa\"",mName.c_str());

	}
	void getOutUV()
	{
		fprintf(mFile,"\"%s.ouv\"",mName.c_str());

	}
	void getOutU()
	{
		fprintf(mFile,"\"%s.ouv.ou\"",mName.c_str());

	}
	void getOutV()
	{
		fprintf(mFile,"\"%s.ouv.ov\"",mName.c_str());

	}
	void getAlphaGain()
	{
		fprintf(mFile,"\"%s.ag\"",mName.c_str());

	}
	void getAlphaOffset()
	{
		fprintf(mFile,"\"%s.ao\"",mName.c_str());

	}
	void getDefaultColor()
	{
		fprintf(mFile,"\"%s.dcl\"",mName.c_str());

	}
	void getDefaultColorR()
	{
		fprintf(mFile,"\"%s.dcl.dcr\"",mName.c_str());

	}
	void getDefaultColorG()
	{
		fprintf(mFile,"\"%s.dcl.dcg\"",mName.c_str());

	}
	void getDefaultColorB()
	{
		fprintf(mFile,"\"%s.dcl.dcb\"",mName.c_str());

	}
protected:
	FluidTexture2D(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):FluidShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FLUIDTEXTURE2D_H__
