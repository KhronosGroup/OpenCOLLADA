/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMFLARE_H__
#define __MayaDM_DEFORMFLARE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
class DeformFlare : public DeformFunc
{
public:
public:

	DeformFlare():DeformFunc(){}
	DeformFlare(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, "deformFlare", shared, create){}
	virtual ~DeformFlare(){}

	void setLowBound(double lb)
	{
		if(lb == -1.0) return;
		fprintf(mFile,"\tsetAttr \".lb\" %f;\n", lb);
	}
	void setHighBound(double hb)
	{
		if(hb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hb\" %f;\n", hb);
	}
	void setStartFlareX(double sfx)
	{
		if(sfx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sfx\" %f;\n", sfx);
	}
	void setStartFlareZ(double sfz)
	{
		if(sfz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sfz\" %f;\n", sfz);
	}
	void setEndFlareX(double efx)
	{
		if(efx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".efx\" %f;\n", efx);
	}
	void setEndFlareZ(double efz)
	{
		if(efz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".efz\" %f;\n", efz);
	}
	void setCurve(double crv)
	{
		if(crv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crv\" %f;\n", crv);
	}
	void getLowBound()const
	{
		fprintf(mFile,"\"%s.lb\"",mName.c_str());
	}
	void getHighBound()const
	{
		fprintf(mFile,"\"%s.hb\"",mName.c_str());
	}
	void getStartFlareX()const
	{
		fprintf(mFile,"\"%s.sfx\"",mName.c_str());
	}
	void getStartFlareZ()const
	{
		fprintf(mFile,"\"%s.sfz\"",mName.c_str());
	}
	void getEndFlareX()const
	{
		fprintf(mFile,"\"%s.efx\"",mName.c_str());
	}
	void getEndFlareZ()const
	{
		fprintf(mFile,"\"%s.efz\"",mName.c_str());
	}
	void getCurve()const
	{
		fprintf(mFile,"\"%s.crv\"",mName.c_str());
	}
protected:
	DeformFlare(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMFLARE_H__
