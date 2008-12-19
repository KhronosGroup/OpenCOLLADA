/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	StudioClearCoat(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "studioClearCoat"){}
	virtual ~StudioClearCoat(){}
	void setIndex(float ix)
	{
		if(ix == 1.8) return;
		fprintf(mFile,"setAttr \".ix\" %f;\n", ix);

	}
	void setScale(float s)
	{
		if(s == 1.55) return;
		fprintf(mFile,"setAttr \".s\" %f;\n", s);

	}
	void setBias(float b)
	{
		if(b == -0.1) return;
		fprintf(mFile,"setAttr \".b\" %f;\n", b);

	}
	void getIndex()
	{
		fprintf(mFile,"\"%s.ix\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getBias()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

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
	void getOutValue()
	{
		fprintf(mFile,"\"%s.outp\"",mName.c_str());

	}
protected:
	StudioClearCoat(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_STUDIOCLEARCOAT_H__
