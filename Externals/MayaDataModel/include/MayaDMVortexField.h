/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VORTEXFIELD_H__
#define __MayaDM_VORTEXFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
class VortexField : public Field
{
public:
	struct Axis{
		double axisX;
		double axisY;
		double axisZ;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", axisX);
			fprintf(file,"%f ", axisY);
			fprintf(file,"%f", axisZ);
		}
	};
public:

	VortexField():Field(){}
	VortexField(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Field(file, name, parent, "vortexField", shared, create){}
	virtual ~VortexField(){}

	void setAxis(const Axis& ax)
	{
		fprintf(mFile,"\tsetAttr \".ax\" ");
		ax.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAxisX(double axx)
	{
		if(axx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ax.axx\" %f;\n", axx);
	}
	void setAxisY(double axy)
	{
		if(axy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ax.axy\" %f;\n", axy);
	}
	void setAxisZ(double axz)
	{
		if(axz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ax.axz\" %f;\n", axz);
	}
	void getAxis()const
	{
		fprintf(mFile,"\"%s.ax\"",mName.c_str());
	}
	void getAxisX()const
	{
		fprintf(mFile,"\"%s.ax.axx\"",mName.c_str());
	}
	void getAxisY()const
	{
		fprintf(mFile,"\"%s.ax.axy\"",mName.c_str());
	}
	void getAxisZ()const
	{
		fprintf(mFile,"\"%s.ax.axz\"",mName.c_str());
	}
protected:
	VortexField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Field(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_VORTEXFIELD_H__
