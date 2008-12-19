/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BAKESET_H__
#define __MayaDM_BAKESET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectSet.h"
namespace MayaDM
{
class BakeSet : public ObjectSet
{
public:
public:
	BakeSet(FILE* file,const std::string& name,const std::string& parent=""):ObjectSet(file, name, parent, "bakeSet"){}
	virtual ~BakeSet(){}
	void setBakeAlpha(bool alpha)
	{
		if(alpha == 0) return;
		fprintf(mFile,"setAttr \".alpha\" %i;\n", alpha);

	}
	void setAlphaMode(unsigned int mode)
	{
		if(mode == 1) return;
		fprintf(mFile,"setAttr \".mode\" %i;\n", mode);

	}
	void setOcclusionRays(int mor)
	{
		if(mor == 64) return;
		fprintf(mFile,"setAttr \".mor\" %i;\n", mor);

	}
	void setOcclusionFalloff(float mof)
	{
		if(mof == 0) return;
		fprintf(mFile,"setAttr \".mof\" %f;\n", mof);

	}
	void setColorMode(unsigned int clm)
	{
		if(clm == 0) return;
		fprintf(mFile,"setAttr \".clm\" %i;\n", clm);

	}
	void setOrthogonalReflection(bool orf)
	{
		if(orf == 0) return;
		fprintf(mFile,"setAttr \".orf\" %i;\n", orf);

	}
	void setNormalDirection(unsigned int ndr)
	{
		if(ndr == 1) return;
		fprintf(mFile,"setAttr \".ndr\" %i;\n", ndr);

	}
	void getBakeAlpha()
	{
		fprintf(mFile,"\"%s.alpha\"",mName.c_str());

	}
	void getAlphaMode()
	{
		fprintf(mFile,"\"%s.mode\"",mName.c_str());

	}
	void getOcclusionRays()
	{
		fprintf(mFile,"\"%s.mor\"",mName.c_str());

	}
	void getOcclusionFalloff()
	{
		fprintf(mFile,"\"%s.mof\"",mName.c_str());

	}
	void getColorMode()
	{
		fprintf(mFile,"\"%s.clm\"",mName.c_str());

	}
	void getOrthogonalReflection()
	{
		fprintf(mFile,"\"%s.orf\"",mName.c_str());

	}
	void getNormalDirection()
	{
		fprintf(mFile,"\"%s.ndr\"",mName.c_str());

	}
	void getCustomShader()
	{
		fprintf(mFile,"\"%s.csh\"",mName.c_str());

	}
protected:
	BakeSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectSet(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BAKESET_H__
