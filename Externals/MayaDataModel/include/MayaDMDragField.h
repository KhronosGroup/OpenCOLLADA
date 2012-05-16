/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DRAGFIELD_H__
#define __MayaDM_DRAGFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
class DragField : public Field
{
public:
	struct Direction{
		double directionX;
		double directionY;
		double directionZ;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", directionX);
			fprintf(file,"%f ", directionY);
			fprintf(file,"%f", directionZ);
		}
	};
public:

	DragField():Field(){}
	DragField(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Field(file, name, parent, "dragField", shared, create){}
	virtual ~DragField(){}

	void setDirection(const Direction& d)
	{
		fprintf(mFile,"\tsetAttr \".d\" ");
		d.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDirectionX(double dx)
	{
		if(dx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d.dx\" %f;\n", dx);
	}
	void setDirectionY(double dy)
	{
		if(dy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d.dy\" %f;\n", dy);
	}
	void setDirectionZ(double dz)
	{
		if(dz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d.dz\" %f;\n", dz);
	}
	void setUseDirection(bool ud)
	{
		if(ud == false) return;
		fprintf(mFile,"\tsetAttr \".ud\" %i;\n", ud);
	}
	void setInheritVelocity(double iv)
	{
		if(iv == 0) return;
		fprintf(mFile,"\tsetAttr \".iv\" %f;\n", iv);
	}
	void setMotionAttenuation(double mna)
	{
		if(mna == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mna\" %f;\n", mna);
	}
	void setSpeedAttenuation(double spa)
	{
		if(spa == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spa\" %f;\n", spa);
	}
	void getDirection()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getDirectionX()const
	{
		fprintf(mFile,"\"%s.d.dx\"",mName.c_str());
	}
	void getDirectionY()const
	{
		fprintf(mFile,"\"%s.d.dy\"",mName.c_str());
	}
	void getDirectionZ()const
	{
		fprintf(mFile,"\"%s.d.dz\"",mName.c_str());
	}
	void getUseDirection()const
	{
		fprintf(mFile,"\"%s.ud\"",mName.c_str());
	}
	void getInheritVelocity()const
	{
		fprintf(mFile,"\"%s.iv\"",mName.c_str());
	}
	void getMotionAttenuation()const
	{
		fprintf(mFile,"\"%s.mna\"",mName.c_str());
	}
	void getSpeedAttenuation()const
	{
		fprintf(mFile,"\"%s.spa\"",mName.c_str());
	}
	void getCurrentTime()const
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());
	}
protected:
	DragField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Field(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DRAGFIELD_H__
