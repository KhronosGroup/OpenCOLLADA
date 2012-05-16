/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANGLEBETWEEN_H__
#define __MayaDM_ANGLEBETWEEN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class AngleBetween : public DependNode
{
public:
	struct AxisAngle{
		void write(FILE* file) const
		{
		}
	};
public:

	AngleBetween():DependNode(){}
	AngleBetween(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "angleBetween", shared, create){}
	virtual ~AngleBetween(){}

	void setVector1(const double3& v1)
	{
		fprintf(mFile,"\tsetAttr \".v1\" -type \"double3\" ");
		v1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVector1X(double v1x)
	{
		if(v1x == 0) return;
		fprintf(mFile,"\tsetAttr \".v1.v1x\" %f;\n", v1x);
	}
	void setVector1Y(double v1y)
	{
		if(v1y == 1) return;
		fprintf(mFile,"\tsetAttr \".v1.v1y\" %f;\n", v1y);
	}
	void setVector1Z(double v1z)
	{
		if(v1z == 0) return;
		fprintf(mFile,"\tsetAttr \".v1.v1z\" %f;\n", v1z);
	}
	void setVector2(const double3& v2)
	{
		fprintf(mFile,"\tsetAttr \".v2\" -type \"double3\" ");
		v2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVector2X(double v2x)
	{
		if(v2x == 0) return;
		fprintf(mFile,"\tsetAttr \".v2.v2x\" %f;\n", v2x);
	}
	void setVector2Y(double v2y)
	{
		if(v2y == 0) return;
		fprintf(mFile,"\tsetAttr \".v2.v2y\" %f;\n", v2y);
	}
	void setVector2Z(double v2z)
	{
		if(v2z == 1) return;
		fprintf(mFile,"\tsetAttr \".v2.v2z\" %f;\n", v2z);
	}
	void getVector1()const
	{
		fprintf(mFile,"\"%s.v1\"",mName.c_str());
	}
	void getVector1X()const
	{
		fprintf(mFile,"\"%s.v1.v1x\"",mName.c_str());
	}
	void getVector1Y()const
	{
		fprintf(mFile,"\"%s.v1.v1y\"",mName.c_str());
	}
	void getVector1Z()const
	{
		fprintf(mFile,"\"%s.v1.v1z\"",mName.c_str());
	}
	void getVector2()const
	{
		fprintf(mFile,"\"%s.v2\"",mName.c_str());
	}
	void getVector2X()const
	{
		fprintf(mFile,"\"%s.v2.v2x\"",mName.c_str());
	}
	void getVector2Y()const
	{
		fprintf(mFile,"\"%s.v2.v2y\"",mName.c_str());
	}
	void getVector2Z()const
	{
		fprintf(mFile,"\"%s.v2.v2z\"",mName.c_str());
	}
	void getEuler()const
	{
		fprintf(mFile,"\"%s.eu\"",mName.c_str());
	}
	void getEulerX()const
	{
		fprintf(mFile,"\"%s.eu.eux\"",mName.c_str());
	}
	void getEulerY()const
	{
		fprintf(mFile,"\"%s.eu.euy\"",mName.c_str());
	}
	void getEulerZ()const
	{
		fprintf(mFile,"\"%s.eu.euz\"",mName.c_str());
	}
	void getAxisAngle()const
	{
		fprintf(mFile,"\"%s.axa\"",mName.c_str());
	}
	void getAxis()const
	{
		fprintf(mFile,"\"%s.axa.ax\"",mName.c_str());
	}
	void getAxisX()const
	{
		fprintf(mFile,"\"%s.axa.ax.axx\"",mName.c_str());
	}
	void getAxisY()const
	{
		fprintf(mFile,"\"%s.axa.ax.axy\"",mName.c_str());
	}
	void getAxisZ()const
	{
		fprintf(mFile,"\"%s.axa.ax.axz\"",mName.c_str());
	}
	void getAngle()const
	{
		fprintf(mFile,"\"%s.axa.a\"",mName.c_str());
	}
protected:
	AngleBetween(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANGLEBETWEEN_H__
