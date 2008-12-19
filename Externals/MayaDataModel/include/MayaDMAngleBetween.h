/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	AngleBetween(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "angleBetween"){}
	virtual ~AngleBetween(){}
	void setVector1(const double3& v1)
	{
		fprintf(mFile,"setAttr \".v1\" -type \"double3\" ");
		v1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVector1X(double v1x)
	{
		if(v1x == 0) return;
		fprintf(mFile,"setAttr \".v1.v1x\" %f;\n", v1x);

	}
	void setVector1Y(double v1y)
	{
		if(v1y == 1) return;
		fprintf(mFile,"setAttr \".v1.v1y\" %f;\n", v1y);

	}
	void setVector1Z(double v1z)
	{
		if(v1z == 0) return;
		fprintf(mFile,"setAttr \".v1.v1z\" %f;\n", v1z);

	}
	void setVector2(const double3& v2)
	{
		fprintf(mFile,"setAttr \".v2\" -type \"double3\" ");
		v2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVector2X(double v2x)
	{
		if(v2x == 0) return;
		fprintf(mFile,"setAttr \".v2.v2x\" %f;\n", v2x);

	}
	void setVector2Y(double v2y)
	{
		if(v2y == 0) return;
		fprintf(mFile,"setAttr \".v2.v2y\" %f;\n", v2y);

	}
	void setVector2Z(double v2z)
	{
		if(v2z == 1) return;
		fprintf(mFile,"setAttr \".v2.v2z\" %f;\n", v2z);

	}
	void getVector1()
	{
		fprintf(mFile,"\"%s.v1\"",mName.c_str());

	}
	void getVector1X()
	{
		fprintf(mFile,"\"%s.v1.v1x\"",mName.c_str());

	}
	void getVector1Y()
	{
		fprintf(mFile,"\"%s.v1.v1y\"",mName.c_str());

	}
	void getVector1Z()
	{
		fprintf(mFile,"\"%s.v1.v1z\"",mName.c_str());

	}
	void getVector2()
	{
		fprintf(mFile,"\"%s.v2\"",mName.c_str());

	}
	void getVector2X()
	{
		fprintf(mFile,"\"%s.v2.v2x\"",mName.c_str());

	}
	void getVector2Y()
	{
		fprintf(mFile,"\"%s.v2.v2y\"",mName.c_str());

	}
	void getVector2Z()
	{
		fprintf(mFile,"\"%s.v2.v2z\"",mName.c_str());

	}
	void getEuler()
	{
		fprintf(mFile,"\"%s.eu\"",mName.c_str());

	}
	void getEulerX()
	{
		fprintf(mFile,"\"%s.eu.eux\"",mName.c_str());

	}
	void getEulerY()
	{
		fprintf(mFile,"\"%s.eu.euy\"",mName.c_str());

	}
	void getEulerZ()
	{
		fprintf(mFile,"\"%s.eu.euz\"",mName.c_str());

	}
	void getAxisAngle()
	{
		fprintf(mFile,"\"%s.axa\"",mName.c_str());

	}
	void getAxis()
	{
		fprintf(mFile,"\"%s.axa.ax\"",mName.c_str());

	}
	void getAxisX()
	{
		fprintf(mFile,"\"%s.axa.ax.axx\"",mName.c_str());

	}
	void getAxisY()
	{
		fprintf(mFile,"\"%s.axa.ax.axy\"",mName.c_str());

	}
	void getAxisZ()
	{
		fprintf(mFile,"\"%s.axa.ax.axz\"",mName.c_str());

	}
	void getAngle()
	{
		fprintf(mFile,"\"%s.axa.a\"",mName.c_str());

	}
protected:
	AngleBetween(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANGLEBETWEEN_H__
