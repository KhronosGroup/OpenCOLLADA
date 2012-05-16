/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STUDIOCLEARCOAT_H__
#define __MayaDM_STUDIOCLEARCOAT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class StudioClearCoat : public DependNode
{
public:
public:

	StudioClearCoat():DependNode(){}
	StudioClearCoat(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "studioClearCoat", shared, create){}
	virtual ~StudioClearCoat(){}

	void setIndex(float ix)
	{
		if(ix == 1.8) return;
		fprintf(mFile,"\tsetAttr \".ix\" %f;\n", ix);
	}
	void setScale(float s)
	{
		if(s == 1.55) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void setBias(float b)
	{
		if(b == -0.1) return;
		fprintf(mFile,"\tsetAttr \".b\" %f;\n", b);
	}
	void getIndex()const
	{
		fprintf(mFile,"\"%s.ix\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getBias()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
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
	void getOutValue()const
	{
		fprintf(mFile,"\"%s.outp\"",mName.c_str());
	}
protected:
	StudioClearCoat(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_STUDIOCLEARCOAT_H__
