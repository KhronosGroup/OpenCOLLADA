/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SCULPT_H__
#define __MayaDM_SCULPT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class Sculpt : public GeometryFilter
{
public:
public:
	Sculpt(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "sculpt"){}
	virtual ~Sculpt(){}
	void setSculptObjectMatrix(const matrix& sm)
	{
		if(sm == identity) return;
		fprintf(mFile,"setAttr \".sm\" -type \"matrix\" ");
		sm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMode(unsigned int mo)
	{
		if(mo == 2) return;
		fprintf(mFile,"setAttr \".mo\" %i;\n", mo);

	}
	void setInsideMode(unsigned int im)
	{
		if(im == 1) return;
		fprintf(mFile,"setAttr \".im\" %i;\n", im);

	}
	void setMaximumDisplacement(double md)
	{
		if(md == 1) return;
		fprintf(mFile,"setAttr \".md\" %f;\n", md);

	}
	void setDropoffDistance(double dd)
	{
		if(dd == 1) return;
		fprintf(mFile,"setAttr \".dd\" %f;\n", dd);

	}
	void setDropoffType(unsigned int dt)
	{
		if(dt == 1) return;
		fprintf(mFile,"setAttr \".dt\" %i;\n", dt);

	}
	void setStartPosition(const float3& sp)
	{
		fprintf(mFile,"setAttr \".sp\" -type \"float3\" ");
		sp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStartPosX(float sx)
	{
		if(sx == 0) return;
		fprintf(mFile,"setAttr \".sp.sx\" %f;\n", sx);

	}
	void setStartPosY(float sy)
	{
		if(sy == 0) return;
		fprintf(mFile,"setAttr \".sp.sy\" %f;\n", sy);

	}
	void setStartPosZ(float sz)
	{
		if(sz == 0) return;
		fprintf(mFile,"setAttr \".sp.sz\" %f;\n", sz);

	}
	void setExtendedEnd(bool exd)
	{
		if(exd == false) return;
		fprintf(mFile,"setAttr \".exd\" %i;\n", exd);

	}
	void getSculptObjectMatrix()
	{
		fprintf(mFile,"\"%s.sm\"",mName.c_str());

	}
	void getSculptObjectGeometry()
	{
		fprintf(mFile,"\"%s.sg\"",mName.c_str());

	}
	void getMode()
	{
		fprintf(mFile,"\"%s.mo\"",mName.c_str());

	}
	void getInsideMode()
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());

	}
	void getMaximumDisplacement()
	{
		fprintf(mFile,"\"%s.md\"",mName.c_str());

	}
	void getDropoffDistance()
	{
		fprintf(mFile,"\"%s.dd\"",mName.c_str());

	}
	void getDropoffType()
	{
		fprintf(mFile,"\"%s.dt\"",mName.c_str());

	}
	void getStartPosition()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getStartPosX()
	{
		fprintf(mFile,"\"%s.sp.sx\"",mName.c_str());

	}
	void getStartPosY()
	{
		fprintf(mFile,"\"%s.sp.sy\"",mName.c_str());

	}
	void getStartPosZ()
	{
		fprintf(mFile,"\"%s.sp.sz\"",mName.c_str());

	}
	void getExtendedEnd()
	{
		fprintf(mFile,"\"%s.exd\"",mName.c_str());

	}
protected:
	Sculpt(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SCULPT_H__
