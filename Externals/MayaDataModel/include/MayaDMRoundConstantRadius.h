/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ROUNDCONSTANTRADIUS_H__
#define __MayaDM_ROUNDCONSTANTRADIUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class RoundConstantRadius : public AbstractBaseCreate
{
public:
	struct Edge{
		nurbsCurve* inputCurveA;
		size_t nbInputCurveA;
		nurbsCurve* inputCurveB;
		size_t nbInputCurveB;
		int* inSurfIdxA;
		size_t nbInSurfIdxA;
		int* inSurfIdxB;
		size_t nbInSurfIdxB;
		bool edgeValid;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbInputCurveA; ++i)
			{
				inputCurveA[i].write(file);
				fprintf(file, " ");
				if (i + 1<nbInputCurveA) fprintf(file, " ");
			}
			for (size_t i = 0; i<nbInputCurveB; ++i)
			{
				inputCurveB[i].write(file);
				fprintf(file, " ");
				if (i + 1<nbInputCurveB) fprintf(file, " ");
			}
			for (size_t i = 0; i<nbInSurfIdxA; ++i)
			{
				fprintf(file,"%i ", inSurfIdxA[i]);
				if (i + 1<nbInSurfIdxA) fprintf(file, " ");
			}
			for (size_t i = 0; i<nbInSurfIdxB; ++i)
			{
				fprintf(file,"%i ", inSurfIdxB[i]);
				if (i + 1<nbInSurfIdxB) fprintf(file, " ");
			}
			fprintf(file,"%i", edgeValid);
		}
	};
public:

	RoundConstantRadius():AbstractBaseCreate(){}
	RoundConstantRadius(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "roundConstantRadius", shared, create){}
	virtual ~RoundConstantRadius(){}

	void setInputSurface(size_t is_i,const nurbsSurface& is)
	{
		fprintf(mFile,"\tsetAttr \".is[%i]\" -type \"nurbsSurface\" ",is_i);
		is.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputSurface(size_t is_start,size_t is_end,nurbsSurface* is)
	{
		fprintf(mFile,"\tsetAttr \".is[%i:%i]\" ", is_start,is_end);
		size_t size = (is_end-is_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			is[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInputSurface(size_t is_start,size_t is_end)const
	{
		fprintf(mFile,"\tsetAttr \".is[%i:%i]\"",is_start,is_end);
		fprintf(mFile," -type \"nurbsSurface\" ");
	}
	void appendInputSurface(const nurbsSurface& is)const
	{
		fprintf(mFile," ");
		is.write(mFile);
	}
	void endInputSurface()const
	{
		fprintf(mFile,";\n");
	}
	void setRadius(size_t r_i,double r)
	{
		if(r == 1) return;
		fprintf(mFile,"\tsetAttr \".r[%i]\" %f;\n", r_i,r);
	}
	void setRadius(size_t r_start,size_t r_end,double* r)
	{
		fprintf(mFile,"\tsetAttr \".r[%i:%i]\" ", r_start,r_end);
		size_t size = (r_end-r_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",r[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startRadius(size_t r_start,size_t r_end)const
	{
		fprintf(mFile,"\tsetAttr \".r[%i:%i]\"",r_start,r_end);
	}
	void appendRadius(double r)const
	{
		fprintf(mFile," %f",r);
	}
	void endRadius()const
	{
		fprintf(mFile,";\n");
	}
	void setEdge(size_t e_i,const Edge& e)
	{
		fprintf(mFile,"\tsetAttr \".e[%i]\" ",e_i);
		e.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEdge(size_t e_start,size_t e_end,Edge* e)
	{
		fprintf(mFile,"\tsetAttr \".e[%i:%i]\" ", e_start,e_end);
		size_t size = (e_end-e_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			e[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startEdge(size_t e_start,size_t e_end)const
	{
		fprintf(mFile,"\tsetAttr \".e[%i:%i]\"",e_start,e_end);
		fprintf(mFile," -type \"Edge\" ");
	}
	void appendEdge(const Edge& e)const
	{
		fprintf(mFile," ");
		e.write(mFile);
	}
	void endEdge()const
	{
		fprintf(mFile,";\n");
	}
	void setInputCurveA(size_t e_i,size_t ica_i,const nurbsCurve& ica)
	{
		fprintf(mFile,"\tsetAttr \".e[%i].ica[%i]\" -type \"nurbsCurve\" ",e_i,ica_i);
		ica.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputCurveA(size_t e_i,size_t ica_start,size_t ica_end,nurbsCurve* ica)
	{
		fprintf(mFile,"\tsetAttr \".e[%i].ica[%i:%i]\" ", e_i,ica_start,ica_end);
		size_t size = (ica_end-ica_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ica[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInputCurveA(size_t e_i,size_t ica_start,size_t ica_end)const
	{
		fprintf(mFile,"\tsetAttr \".e[%i].ica[%i:%i]\"",e_i,ica_start,ica_end);
		fprintf(mFile," -type \"nurbsCurve\" ");
	}
	void appendInputCurveA(const nurbsCurve& ica)const
	{
		fprintf(mFile," ");
		ica.write(mFile);
	}
	void endInputCurveA()const
	{
		fprintf(mFile,";\n");
	}
	void setInputCurveB(size_t e_i,size_t icb_i,const nurbsCurve& icb)
	{
		fprintf(mFile,"\tsetAttr \".e[%i].icb[%i]\" -type \"nurbsCurve\" ",e_i,icb_i);
		icb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputCurveB(size_t e_i,size_t icb_start,size_t icb_end,nurbsCurve* icb)
	{
		fprintf(mFile,"\tsetAttr \".e[%i].icb[%i:%i]\" ", e_i,icb_start,icb_end);
		size_t size = (icb_end-icb_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			icb[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInputCurveB(size_t e_i,size_t icb_start,size_t icb_end)const
	{
		fprintf(mFile,"\tsetAttr \".e[%i].icb[%i:%i]\"",e_i,icb_start,icb_end);
		fprintf(mFile," -type \"nurbsCurve\" ");
	}
	void appendInputCurveB(const nurbsCurve& icb)const
	{
		fprintf(mFile," ");
		icb.write(mFile);
	}
	void endInputCurveB()const
	{
		fprintf(mFile,";\n");
	}
	void setInSurfIdxA(size_t e_i,size_t isa_i,int isa)
	{
		if(isa == 123456) return;
		fprintf(mFile,"\tsetAttr \".e[%i].isa[%i]\" %i;\n", e_i,isa_i,isa);
	}
	void setInSurfIdxA(size_t e_i,size_t isa_start,size_t isa_end,int* isa)
	{
		fprintf(mFile,"\tsetAttr \".e[%i].isa[%i:%i]\" ", e_i,isa_start,isa_end);
		size_t size = (isa_end-isa_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",isa[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInSurfIdxA(size_t e_i,size_t isa_start,size_t isa_end)const
	{
		fprintf(mFile,"\tsetAttr \".e[%i].isa[%i:%i]\"",e_i,isa_start,isa_end);
	}
	void appendInSurfIdxA(int isa)const
	{
		fprintf(mFile," %i",isa);
	}
	void endInSurfIdxA()const
	{
		fprintf(mFile,";\n");
	}
	void setInSurfIdxB(size_t e_i,size_t isb_i,int isb)
	{
		if(isb == 123456) return;
		fprintf(mFile,"\tsetAttr \".e[%i].isb[%i]\" %i;\n", e_i,isb_i,isb);
	}
	void setInSurfIdxB(size_t e_i,size_t isb_start,size_t isb_end,int* isb)
	{
		fprintf(mFile,"\tsetAttr \".e[%i].isb[%i:%i]\" ", e_i,isb_start,isb_end);
		size_t size = (isb_end-isb_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",isb[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInSurfIdxB(size_t e_i,size_t isb_start,size_t isb_end)const
	{
		fprintf(mFile,"\tsetAttr \".e[%i].isb[%i:%i]\"",e_i,isb_start,isb_end);
	}
	void appendInSurfIdxB(int isb)const
	{
		fprintf(mFile," %i",isb);
	}
	void endInSurfIdxB()const
	{
		fprintf(mFile,";\n");
	}
	void setEdgeValid(size_t e_i,bool ev)
	{
		if(ev == 1) return;
		fprintf(mFile,"\tsetAttr \".e[%i].ev\" %i;\n", e_i,ev);
	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void getInputSurface(size_t is_i)const
	{
		fprintf(mFile,"\"%s.is[%i]\"",mName.c_str(),is_i);
	}
	void getInputSurface()const
	{

		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getRadius(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i]\"",mName.c_str(),r_i);
	}
	void getRadius()const
	{

		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getInputCurveA(size_t e_i,size_t ica_i)const
	{
		fprintf(mFile,"\"%s.e[%i].ica[%i]\"",mName.c_str(),e_i,ica_i);
	}
	void getInputCurveA(size_t ica_i)const
	{

		fprintf(mFile,"\"%s.e.ica[%i]\"",mName.c_str(),ica_i);
	}
	void getInputCurveB(size_t e_i,size_t icb_i)const
	{
		fprintf(mFile,"\"%s.e[%i].icb[%i]\"",mName.c_str(),e_i,icb_i);
	}
	void getInputCurveB(size_t icb_i)const
	{

		fprintf(mFile,"\"%s.e.icb[%i]\"",mName.c_str(),icb_i);
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getFilletStatus(size_t fis_i)const
	{
		fprintf(mFile,"\"%s.fis[%i]\"",mName.c_str(),fis_i);
	}
	void getFilletStatus()const
	{

		fprintf(mFile,"\"%s.fis\"",mName.c_str());
	}
	void getOriginalSurface(size_t os_i)const
	{
		fprintf(mFile,"\"%s.os[%i]\"",mName.c_str(),os_i);
	}
	void getOriginalSurface()const
	{

		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getFilletSurface(size_t fs_i)const
	{
		fprintf(mFile,"\"%s.fs[%i]\"",mName.c_str(),fs_i);
	}
	void getFilletSurface()const
	{

		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getCornerSurface(size_t cs_i)const
	{
		fprintf(mFile,"\"%s.cs[%i]\"",mName.c_str(),cs_i);
	}
	void getCornerSurface()const
	{

		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
protected:
	RoundConstantRadius(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ROUNDCONSTANTRADIUS_H__
