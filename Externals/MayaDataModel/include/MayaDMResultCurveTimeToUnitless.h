/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RESULTCURVETIMETOUNITLESS_H__
#define __MayaDM_RESULTCURVETIMETOUNITLESS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMResultCurve.h"
namespace MayaDM
{
class ResultCurveTimeToUnitless : public ResultCurve
{
public:
	struct KeyTimeValue{
		double keyTime;
		double keyValue;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", keyTime);
			fprintf(file,"%f", keyValue);
		}
	};
public:

	ResultCurveTimeToUnitless():ResultCurve(){}
	ResultCurveTimeToUnitless(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ResultCurve(file, name, parent, "resultCurveTimeToUnitless", shared, create){}
	virtual ~ResultCurveTimeToUnitless(){}

	void setKeyTimeValue(size_t ktv_i,const KeyTimeValue& ktv)
	{
		fprintf(mFile,"\tsetAttr \".ktv[%i]\" ",ktv_i);
		ktv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setKeyTimeValue(size_t ktv_start,size_t ktv_end,KeyTimeValue* ktv)
	{
		fprintf(mFile,"\tsetAttr \".ktv[%i:%i]\" ", ktv_start,ktv_end);
		size_t size = (ktv_end-ktv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ktv[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startKeyTimeValue(size_t ktv_start,size_t ktv_end)const
	{
		fprintf(mFile,"\tsetAttr \".ktv[%i:%i]\"",ktv_start,ktv_end);
		fprintf(mFile," -type \"KeyTimeValue\" ");
	}
	void appendKeyTimeValue(const KeyTimeValue& ktv)const
	{
		fprintf(mFile," ");
		ktv.write(mFile);
	}
	void endKeyTimeValue()const
	{
		fprintf(mFile,";\n");
	}
	void setKeyTime(size_t ktv_i,double kt)
	{
		if(kt == 0) return;
		fprintf(mFile,"\tsetAttr \".ktv[%i].kt\" %f;\n", ktv_i,kt);
	}
	void setKeyValue(size_t ktv_i,double kv)
	{
		if(kv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ktv[%i].kv\" %f;\n", ktv_i,kv);
	}
	void getInput()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getInputResult()const
	{
		fprintf(mFile,"\"%s.ir\"",mName.c_str());
	}
protected:
	ResultCurveTimeToUnitless(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ResultCurve(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RESULTCURVETIMETOUNITLESS_H__
