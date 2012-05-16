/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VOLUMEAXISFIELD_H__
#define __MayaDM_VOLUMEAXISFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
class VolumeAxisField : public Field
{
public:
public:

	VolumeAxisField():Field(){}
	VolumeAxisField(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Field(file, name, parent, "volumeAxisField", shared, create){}
	virtual ~VolumeAxisField(){}

	void setInvertAttenuation(bool ia)
	{
		if(ia == false) return;
		fprintf(mFile,"\tsetAttr \".ia\" %i;\n", ia);
	}
	void setAwayFromCenter(double afc)
	{
		if(afc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".afc\" %f;\n", afc);
	}
	void setAwayFromAxis(double afa)
	{
		if(afa == 1.0) return;
		fprintf(mFile,"\tsetAttr \".afa\" %f;\n", afa);
	}
	void setAlongAxis(double alx)
	{
		if(alx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".alx\" %f;\n", alx);
	}
	void setAroundAxis(double arx)
	{
		if(arx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".arx\" %f;\n", arx);
	}
	void setDirectionalSpeed(double drs)
	{
		if(drs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".drs\" %f;\n", drs);
	}
	void setDirection(const double3& d)
	{
		fprintf(mFile,"\tsetAttr \".d\" -type \"double3\" ");
		d.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDirectionX(double dx)
	{
		if(dx == 1.0) return;
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
	void setDisplaySpeed(bool dss)
	{
		if(dss == true) return;
		fprintf(mFile,"\tsetAttr \".dss\" %i;\n", dss);
	}
	void setTurbulence(double trb)
	{
		if(trb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".trb\" %f;\n", trb);
	}
	void setTurbulenceSpeed(double trs)
	{
		if(trs == 0.2) return;
		fprintf(mFile,"\tsetAttr \".trs\" %f;\n", trs);
	}
	void setTurbulenceFrequency(const double3& tf)
	{
		fprintf(mFile,"\tsetAttr \".tf\" -type \"double3\" ");
		tf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTurbulenceFrequencyX(double tfx)
	{
		if(tfx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tf.tfx\" %f;\n", tfx);
	}
	void setTurbulenceFrequencyY(double tfy)
	{
		if(tfy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tf.tfy\" %f;\n", tfy);
	}
	void setTurbulenceFrequencyZ(double tfz)
	{
		if(tfz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tf.tfz\" %f;\n", tfz);
	}
	void setTurbulenceOffset(const double3& to)
	{
		fprintf(mFile,"\tsetAttr \".to\" -type \"double3\" ");
		to.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTurbulenceOffsetX(double tox)
	{
		if(tox == 0.0) return;
		fprintf(mFile,"\tsetAttr \".to.tox\" %f;\n", tox);
	}
	void setTurbulenceOffsetY(double toy)
	{
		if(toy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".to.toy\" %f;\n", toy);
	}
	void setTurbulenceOffsetZ(double toz)
	{
		if(toz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".to.toz\" %f;\n", toz);
	}
	void setDetailTurbulence(double dtr)
	{
		if(dtr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtr\" %f;\n", dtr);
	}
	void setTime(double tim)
	{
		if(tim == 0) return;
		fprintf(mFile,"\tsetAttr \".tim\" %f;\n", tim);
	}
	void getInvertAttenuation()const
	{
		fprintf(mFile,"\"%s.ia\"",mName.c_str());
	}
	void getAwayFromCenter()const
	{
		fprintf(mFile,"\"%s.afc\"",mName.c_str());
	}
	void getAwayFromAxis()const
	{
		fprintf(mFile,"\"%s.afa\"",mName.c_str());
	}
	void getAlongAxis()const
	{
		fprintf(mFile,"\"%s.alx\"",mName.c_str());
	}
	void getAroundAxis()const
	{
		fprintf(mFile,"\"%s.arx\"",mName.c_str());
	}
	void getDirectionalSpeed()const
	{
		fprintf(mFile,"\"%s.drs\"",mName.c_str());
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
	void getDisplaySpeed()const
	{
		fprintf(mFile,"\"%s.dss\"",mName.c_str());
	}
	void getTurbulence()const
	{
		fprintf(mFile,"\"%s.trb\"",mName.c_str());
	}
	void getTurbulenceSpeed()const
	{
		fprintf(mFile,"\"%s.trs\"",mName.c_str());
	}
	void getTurbulenceFrequency()const
	{
		fprintf(mFile,"\"%s.tf\"",mName.c_str());
	}
	void getTurbulenceFrequencyX()const
	{
		fprintf(mFile,"\"%s.tf.tfx\"",mName.c_str());
	}
	void getTurbulenceFrequencyY()const
	{
		fprintf(mFile,"\"%s.tf.tfy\"",mName.c_str());
	}
	void getTurbulenceFrequencyZ()const
	{
		fprintf(mFile,"\"%s.tf.tfz\"",mName.c_str());
	}
	void getTurbulenceOffset()const
	{
		fprintf(mFile,"\"%s.to\"",mName.c_str());
	}
	void getTurbulenceOffsetX()const
	{
		fprintf(mFile,"\"%s.to.tox\"",mName.c_str());
	}
	void getTurbulenceOffsetY()const
	{
		fprintf(mFile,"\"%s.to.toy\"",mName.c_str());
	}
	void getTurbulenceOffsetZ()const
	{
		fprintf(mFile,"\"%s.to.toz\"",mName.c_str());
	}
	void getDetailTurbulence()const
	{
		fprintf(mFile,"\"%s.dtr\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());
	}
protected:
	VolumeAxisField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Field(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMEAXISFIELD_H__
