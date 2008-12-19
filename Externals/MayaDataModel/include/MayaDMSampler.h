/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
		struct Function_Outmap{
			short function_OutmapTo;
			short function_OutmapFrom;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", function_OutmapTo);
				fprintf(file,"%i", function_OutmapFrom);
			}
		}* function_Outmap;
		double function_Default;
		void write(FILE* file) const
		{
			size_t size = sizeof(function_Inmap)/sizeof(Function_Inmap);
			for(size_t i=0; i<size; ++i)
			{
				function_Inmap[i].write(file);
				fprintf(file, " ");
				if(i+1<size) fprintf(file," ");
			}
			size = sizeof(function_Outmap)/sizeof(Function_Outmap);
			for(size_t i=0; i<size; ++i)
			{
				function_Outmap[i].write(file);
				fprintf(file, " ");
				if(i+1<size) fprintf(file," ");
			}
			fprintf(file,"%f", function_Default);
		}
	};
public:
	Sampler(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "sampler"){}
	virtual ~Sampler(){}
	void setMinimum(double min)
	{
		if(min == 0.0) return;
		fprintf(mFile,"setAttr \".min\" %f;\n", min);

	}
	void setMaximum(double max)
	{
		if(max == 0.0) return;
		fprintf(mFile,"setAttr \".max\" %f;\n", max);

	}
	void setStep(double s)
	{
		if(s == 0.0) return;
		fprintf(mFile,"setAttr \".s\" %f;\n", s);

	}
	void setInvert(bool i)
	{
		if(i == false) return;
		fprintf(mFile,"setAttr \".i\" %i;\n", i);

	}
	void setFunction(const Function& f)
	{
		fprintf(mFile,"setAttr \".f\" ");
		f.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFunction_Inmap(size_t fi_i,const Function::Function_Inmap& fi)
	{
		fprintf(mFile,"setAttr \".f.fi[%i]\" ",fi_i);
		fi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFunction_InmapTo(size_t fi_i,short fit)
	{
		if(fit == 0) return;
		fprintf(mFile,"setAttr \".f.fi[%i].fit\" %i;\n", fi_i,fit);

	}
	void setFunction_InmapFrom(size_t fi_i,short fif)
	{
		if(fif == 0) return;
		fprintf(mFile,"setAttr \".f.fi[%i].fif\" %i;\n", fi_i,fif);

	}
	void setFunction_Outmap(size_t fo_i,const Function::Function_Outmap& fo)
	{
		fprintf(mFile,"setAttr \".f.fo[%i]\" ",fo_i);
		fo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFunction_OutmapTo(size_t fo_i,short fot)
	{
		if(fot == 0) return;
		fprintf(mFile,"setAttr \".f.fo[%i].fot\" %i;\n", fo_i,fot);

	}
	void setFunction_OutmapFrom(size_t fo_i,short fof)
	{
		if(fof == 0) return;
		fprintf(mFile,"setAttr \".f.fo[%i].fof\" %i;\n", fo_i,fof);

	}
	void setFunction_Default(double fd)
	{
		if(fd == 0.0) return;
		fprintf(mFile,"setAttr \".f.fd\" %f;\n", fd);

	}
	void getMinimum()
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());

	}
	void getMaximum()
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());

	}
	void getStep()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getInvert()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getValue(size_t v_i)
	{
		fprintf(mFile,"\"%s.v[%i]\"",mName.c_str(),v_i);

	}
	void getFunction()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getFunction_Raw()
	{
		fprintf(mFile,"\"%s.f.fr\"",mName.c_str());

	}
	void getFunction_Inmap(size_t fi_i)
	{
		fprintf(mFile,"\"%s.f.fi[%i]\"",mName.c_str(),fi_i);

	}
	void getFunction_InmapTo(size_t fi_i)
	{
		fprintf(mFile,"\"%s.f.fi[%i].fit\"",mName.c_str(),fi_i);

	}
	void getFunction_InmapFrom(size_t fi_i)
	{
		fprintf(mFile,"\"%s.f.fi[%i].fif\"",mName.c_str(),fi_i);

	}
	void getFunction_Outmap(size_t fo_i)
	{
		fprintf(mFile,"\"%s.f.fo[%i]\"",mName.c_str(),fo_i);

	}
	void getFunction_OutmapTo(size_t fo_i)
	{
		fprintf(mFile,"\"%s.f.fo[%i].fot\"",mName.c_str(),fo_i);

	}
	void getFunction_OutmapFrom(size_t fo_i)
	{
		fprintf(mFile,"\"%s.f.fo[%i].fof\"",mName.c_str(),fo_i);

	}
	void getFunction_Default()
	{
		fprintf(mFile,"\"%s.f.fd\"",mName.c_str());

	}
protected:
	Sampler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SAMPLER_H__
