/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	DragField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "dragField"){}
	virtual ~DragField(){}
	void setDirection(const Direction& d)
	{
		fprintf(mFile,"setAttr \".d\" ");
		d.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDirectionX(double dx)
	{
		if(dx == 0.0) return;
		fprintf(mFile,"setAttr \".d.dx\" %f;\n", dx);

	}
	void setDirectionY(double dy)
	{
		if(dy == 0.0) return;
		fprintf(mFile,"setAttr \".d.dy\" %f;\n", dy);

	}
	void setDirectionZ(double dz)
	{
		if(dz == 0.0) return;
		fprintf(mFile,"setAttr \".d.dz\" %f;\n", dz);

	}
	void setUseDirection(bool ud)
	{
		if(ud == false) return;
		fprintf(mFile,"setAttr \".ud\" %i;\n", ud);

	}
	void setInheritVelocity(double iv)
	{
		if(iv == 0) return;
		fprintf(mFile,"setAttr \".iv\" %f;\n", iv);

	}
	void setMotionAttenuation(double mna)
	{
		if(mna == 0.0) return;
		fprintf(mFile,"setAttr \".mna\" %f;\n", mna);

	}
	void setSpeedAttenuation(double spa)
	{
		if(spa == 0.0) return;
		fprintf(mFile,"setAttr \".spa\" %f;\n", spa);

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getDirectionX()
	{
		fprintf(mFile,"\"%s.d.dx\"",mName.c_str());

	}
	void getDirectionY()
	{
		fprintf(mFile,"\"%s.d.dy\"",mName.c_str());

	}
	void getDirectionZ()
	{
		fprintf(mFile,"\"%s.d.dz\"",mName.c_str());

	}
	void getUseDirection()
	{
		fprintf(mFile,"\"%s.ud\"",mName.c_str());

	}
	void getInheritVelocity()
	{
		fprintf(mFile,"\"%s.iv\"",mName.c_str());

	}
	void getMotionAttenuation()
	{
		fprintf(mFile,"\"%s.mna\"",mName.c_str());

	}
	void getSpeedAttenuation()
	{
		fprintf(mFile,"\"%s.spa\"",mName.c_str());

	}
	void getCurrentTime()
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());

	}
protected:
	DragField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DRAGFIELD_H__
