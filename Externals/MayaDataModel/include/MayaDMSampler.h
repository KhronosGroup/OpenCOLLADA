/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SAMPLER_H__
#define __MayaDM_SAMPLER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Sampler : public DependNode
{
public:
	struct Function{
		struct Function_Inmap{
			short function_InmapTo;
			short function_InmapFrom;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", function_InmapTo);
				fprintf(file,"%i", function_InmapFrom);
			}
		}* function_Inmap;
		size_t nbFunction_Inmap;
		struct Function_Outmap{
			short function_OutmapTo;
			short function_OutmapFrom;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", function_OutmapTo);
				fprintf(file,"%i", function_OutmapFrom);
			}
		}* function_Outmap;
		size_t nbFunction_Outmap;
		double function_Default;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbFunction_Inmap; ++i)
			{
				function_Inmap[i].write(file);
				fprintf(file, " ");
				if (i + 1<nbFunction_Inmap) fprintf(file, " ");
			}
			for (size_t i = 0; i<nbFunction_Outmap; ++i)
			{
				function_Outmap[i].write(file);
				fprintf(file, " ");
				if (i + 1<nbFunction_Outmap) fprintf(file, " ");
			}
			fprintf(file,"%f", function_Default);
		}
	};
public:

	Sampler():DependNode(){}
	Sampler(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "sampler", shared, create){}
	virtual ~Sampler(){}

	void setMinimum(double min)
	{
		if(min == 0.0) return;
		fprintf(mFile,"\tsetAttr \".min\" %f;\n", min);
	}
	void setMaximum(double max)
	{
		if(max == 0.0) return;
		fprintf(mFile,"\tsetAttr \".max\" %f;\n", max);
	}
	void setStep(double s)
	{
		if(s == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void setInvert(bool i_)
	{
		if(i_ == false) return;
		fprintf(mFile,"\tsetAttr \".i\" %i;\n", i_);
	}
	void setFunction(const Function& f)
	{
		fprintf(mFile,"\tsetAttr \".f\" ");
		f.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFunction_Inmap(size_t fi_i,const Function::Function_Inmap& fi)
	{
		fprintf(mFile,"\tsetAttr \".f.fi[%i]\" ",fi_i);
		fi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFunction_Inmap(size_t fi_start,size_t fi_end,Function::Function_Inmap* fi)
	{
		fprintf(mFile,"\tsetAttr \".f.fi[%i:%i]\" ", fi_start,fi_end);
		size_t size = (fi_end-fi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fi[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startFunction_Inmap(size_t fi_start,size_t fi_end)const
	{
		fprintf(mFile,"\tsetAttr \".f.fi[%i:%i]\"",fi_start,fi_end);
		fprintf(mFile," -type \"Function::Function_Inmap\" ");
	}
	void appendFunction_Inmap(const Function::Function_Inmap& fi)const
	{
		fprintf(mFile," ");
		fi.write(mFile);
	}
	void endFunction_Inmap()const
	{
		fprintf(mFile,";\n");
	}
	void setFunction_InmapTo(size_t fi_i,short fit)
	{
		if(fit == 0) return;
		fprintf(mFile,"\tsetAttr \".f.fi[%i].fit\" %i;\n", fi_i,fit);
	}
	void setFunction_InmapFrom(size_t fi_i,short fif)
	{
		if(fif == 0) return;
		fprintf(mFile,"\tsetAttr \".f.fi[%i].fif\" %i;\n", fi_i,fif);
	}
	void setFunction_Outmap(size_t fo_i,const Function::Function_Outmap& fo)
	{
		fprintf(mFile,"\tsetAttr \".f.fo[%i]\" ",fo_i);
		fo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFunction_Outmap(size_t fo_start,size_t fo_end,Function::Function_Outmap* fo)
	{
		fprintf(mFile,"\tsetAttr \".f.fo[%i:%i]\" ", fo_start,fo_end);
		size_t size = (fo_end-fo_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fo[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startFunction_Outmap(size_t fo_start,size_t fo_end)const
	{
		fprintf(mFile,"\tsetAttr \".f.fo[%i:%i]\"",fo_start,fo_end);
		fprintf(mFile," -type \"Function::Function_Outmap\" ");
	}
	void appendFunction_Outmap(const Function::Function_Outmap& fo)const
	{
		fprintf(mFile," ");
		fo.write(mFile);
	}
	void endFunction_Outmap()const
	{
		fprintf(mFile,";\n");
	}
	void setFunction_OutmapTo(size_t fo_i,short fot)
	{
		if(fot == 0) return;
		fprintf(mFile,"\tsetAttr \".f.fo[%i].fot\" %i;\n", fo_i,fot);
	}
	void setFunction_OutmapFrom(size_t fo_i,short fof)
	{
		if(fof == 0) return;
		fprintf(mFile,"\tsetAttr \".f.fo[%i].fof\" %i;\n", fo_i,fof);
	}
	void setFunction_Default(double fd)
	{
		if(fd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".f.fd\" %f;\n", fd);
	}
	void getMinimum()const
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());
	}
	void getMaximum()const
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());
	}
	void getStep()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getInvert()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getValue(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i]\"",mName.c_str(),v_i);
	}
	void getValue()const
	{

		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getFunction()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getFunction_Raw()const
	{
		fprintf(mFile,"\"%s.f.fr\"",mName.c_str());
	}
	void getFunction_Inmap(size_t fi_i)const
	{
		fprintf(mFile,"\"%s.f.fi[%i]\"",mName.c_str(),fi_i);
	}
	void getFunction_InmapTo(size_t fi_i)const
	{
		fprintf(mFile,"\"%s.f.fi[%i].fit\"",mName.c_str(),fi_i);
	}
	void getFunction_InmapFrom(size_t fi_i)const
	{
		fprintf(mFile,"\"%s.f.fi[%i].fif\"",mName.c_str(),fi_i);
	}
	void getFunction_Outmap(size_t fo_i)const
	{
		fprintf(mFile,"\"%s.f.fo[%i]\"",mName.c_str(),fo_i);
	}
	void getFunction_OutmapTo(size_t fo_i)const
	{
		fprintf(mFile,"\"%s.f.fo[%i].fot\"",mName.c_str(),fo_i);
	}
	void getFunction_OutmapFrom(size_t fo_i)const
	{
		fprintf(mFile,"\"%s.f.fo[%i].fof\"",mName.c_str(),fo_i);
	}
	void getFunction_Default()const
	{
		fprintf(mFile,"\"%s.f.fd\"",mName.c_str());
	}
protected:
	Sampler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SAMPLER_H__
