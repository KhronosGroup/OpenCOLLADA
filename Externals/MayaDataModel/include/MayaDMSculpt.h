/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Sculpt():GeometryFilter(){}
	Sculpt(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, "sculpt", shared, create){}
	virtual ~Sculpt(){}

	void setSculptObjectMatrix(const matrix& sm)
	{
		if(sm == identity) return;
		fprintf(mFile,"\tsetAttr \".sm\" -type \"matrix\" ");
		sm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMode(unsigned int mo)
	{
		if(mo == 2) return;
		fprintf(mFile,"\tsetAttr \".mo\" %i;\n", mo);
	}
	void setInsideMode(unsigned int im)
	{
		if(im == 1) return;
		fprintf(mFile,"\tsetAttr \".im\" %i;\n", im);
	}
	void setMaximumDisplacement(double md)
	{
		if(md == 1) return;
		fprintf(mFile,"\tsetAttr \".md\" %f;\n", md);
	}
	void setDropoffDistance(double dd)
	{
		if(dd == 1) return;
		fprintf(mFile,"\tsetAttr \".dd\" %f;\n", dd);
	}
	void setDropoffType(unsigned int dt)
	{
		if(dt == 1) return;
		fprintf(mFile,"\tsetAttr \".dt\" %i;\n", dt);
	}
	void setStartPosition(const float3& sp)
	{
		fprintf(mFile,"\tsetAttr \".sp\" -type \"float3\" ");
		sp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStartPosX(float sx)
	{
		if(sx == 0) return;
		fprintf(mFile,"\tsetAttr \".sp.sx\" %f;\n", sx);
	}
	void setStartPosY(float sy)
	{
		if(sy == 0) return;
		fprintf(mFile,"\tsetAttr \".sp.sy\" %f;\n", sy);
	}
	void setStartPosZ(float sz)
	{
		if(sz == 0) return;
		fprintf(mFile,"\tsetAttr \".sp.sz\" %f;\n", sz);
	}
	void setExtendedEnd(bool exd)
	{
		if(exd == false) return;
		fprintf(mFile,"\tsetAttr \".exd\" %i;\n", exd);
	}
	void getSculptObjectMatrix()const
	{
		fprintf(mFile,"\"%s.sm\"",mName.c_str());
	}
	void getSculptObjectGeometry()const
	{
		fprintf(mFile,"\"%s.sg\"",mName.c_str());
	}
	void getMode()const
	{
		fprintf(mFile,"\"%s.mo\"",mName.c_str());
	}
	void getInsideMode()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getMaximumDisplacement()const
	{
		fprintf(mFile,"\"%s.md\"",mName.c_str());
	}
	void getDropoffDistance()const
	{
		fprintf(mFile,"\"%s.dd\"",mName.c_str());
	}
	void getDropoffType()const
	{
		fprintf(mFile,"\"%s.dt\"",mName.c_str());
	}
	void getStartPosition()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getStartPosX()const
	{
		fprintf(mFile,"\"%s.sp.sx\"",mName.c_str());
	}
	void getStartPosY()const
	{
		fprintf(mFile,"\"%s.sp.sy\"",mName.c_str());
	}
	void getStartPosZ()const
	{
		fprintf(mFile,"\"%s.sp.sz\"",mName.c_str());
	}
	void getExtendedEnd()const
	{
		fprintf(mFile,"\"%s.exd\"",mName.c_str());
	}
protected:
	Sculpt(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SCULPT_H__
