/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYEXTRUDEFACE_H__
#define __MayaDM_POLYEXTRUDEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyMoveFace.h"
namespace MayaDM
{
class PolyExtrudeFace : public PolyMoveFace
{
public:
	struct TaperCurve{
		float taperCurve_Position;
		float taperCurve_FloatValue;
		unsigned int taperCurve_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", taperCurve_Position);
			fprintf(file,"%f ", taperCurve_FloatValue);
			fprintf(file,"%i", taperCurve_Interp);
		}
	};
public:

	PolyExtrudeFace():PolyMoveFace(){}
	PolyExtrudeFace(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyMoveFace(file, name, parent, "polyExtrudeFace", shared, create){}
	virtual ~PolyExtrudeFace(){}

	void setKeepFacesTogether(bool kft)
	{
		if(kft == true) return;
		fprintf(mFile,"\tsetAttr \".kft\" %i;\n", kft);
	}
	void setDivisions(int d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setTwist(double twt)
	{
		if(twt == 0) return;
		fprintf(mFile,"\tsetAttr \".twt\" %f;\n", twt);
	}
	void setTaper(double tp)
	{
		if(tp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tp\" %f;\n", tp);
	}
	void setTaperCurve(size_t c_i,const TaperCurve& c)
	{
		fprintf(mFile,"\tsetAttr \".c[%i]\" ",c_i);
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTaperCurve(size_t c_start,size_t c_end,TaperCurve* c)
	{
		fprintf(mFile,"\tsetAttr \".c[%i:%i]\" ", c_start,c_end);
		size_t size = (c_end-c_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			c[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startTaperCurve(size_t c_start,size_t c_end)const
	{
		fprintf(mFile,"\tsetAttr \".c[%i:%i]\"",c_start,c_end);
		fprintf(mFile," -type \"TaperCurve\" ");
	}
	void appendTaperCurve(const TaperCurve& c)const
	{
		fprintf(mFile," ");
		c.write(mFile);
	}
	void endTaperCurve()const
	{
		fprintf(mFile,";\n");
	}
	void setTaperCurve_Position(size_t c_i,float cp)
	{
		if(cp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c[%i].cp\" %f;\n", c_i,cp);
	}
	void setTaperCurve_FloatValue(size_t c_i,float cfv)
	{
		if(cfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c[%i].cfv\" %f;\n", c_i,cfv);
	}
	void setTaperCurve_Interp(size_t c_i,unsigned int ci)
	{
		if(ci == 0) return;
		fprintf(mFile,"\tsetAttr \".c[%i].ci\" %i;\n", c_i,ci);
	}
	void setSmoothingAngle(double sma)
	{
		if(sma == 3) return;
		fprintf(mFile,"\tsetAttr \".sma\" %f;\n", sma);
	}
	void getKeepFacesTogether()const
	{
		fprintf(mFile,"\"%s.kft\"",mName.c_str());
	}
	void getDivisions()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getInputProfile()const
	{
		fprintf(mFile,"\"%s.ipc\"",mName.c_str());
	}
	void getTwist()const
	{
		fprintf(mFile,"\"%s.twt\"",mName.c_str());
	}
	void getTaper()const
	{
		fprintf(mFile,"\"%s.tp\"",mName.c_str());
	}
	void getTaperCurve(size_t c_i)const
	{
		fprintf(mFile,"\"%s.c[%i]\"",mName.c_str(),c_i);
	}
	void getTaperCurve()const
	{

		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getTaperCurve_Position(size_t c_i)const
	{
		fprintf(mFile,"\"%s.c[%i].cp\"",mName.c_str(),c_i);
	}
	void getTaperCurve_Position()const
	{

		fprintf(mFile,"\"%s.c.cp\"",mName.c_str());
	}
	void getTaperCurve_FloatValue(size_t c_i)const
	{
		fprintf(mFile,"\"%s.c[%i].cfv\"",mName.c_str(),c_i);
	}
	void getTaperCurve_FloatValue()const
	{

		fprintf(mFile,"\"%s.c.cfv\"",mName.c_str());
	}
	void getTaperCurve_Interp(size_t c_i)const
	{
		fprintf(mFile,"\"%s.c[%i].ci\"",mName.c_str(),c_i);
	}
	void getTaperCurve_Interp()const
	{

		fprintf(mFile,"\"%s.c.ci\"",mName.c_str());
	}
	void getSmoothingAngle()const
	{
		fprintf(mFile,"\"%s.sma\"",mName.c_str());
	}
protected:
	PolyExtrudeFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyMoveFace(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYEXTRUDEFACE_H__
