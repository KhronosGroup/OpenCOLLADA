/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FFD_H__
#define __MayaDM_FFD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class Ffd : public GeometryFilter
{
public:
	struct DeformedLattice{
		lattice deformedLatticePoints;
		matrix deformedLatticeMatrix;
		void write(FILE* file) const
		{
			deformedLatticePoints.write(file);
			fprintf(file, " ");
			deformedLatticeMatrix.write(file);
		}
	};
	struct BaseLattice{
		lattice baseLatticePoints;
		matrix baseLatticeMatrix;
		void write(FILE* file) const
		{
			baseLatticePoints.write(file);
			fprintf(file, " ");
			baseLatticeMatrix.write(file);
		}
	};
	struct StuCacheList{
		double* stuCache;
		size_t nbStuCache;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbStuCache; ++i)
			{
				fprintf(file,"%f", stuCache[i]);
				if (i + 1<nbStuCache) fprintf(file, " ");
			}
		}
	};
public:

	Ffd():GeometryFilter(){}
	Ffd(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, "ffd", shared, create){}
	virtual ~Ffd(){}

	void setDeformedLattice(const DeformedLattice& dl)
	{
		fprintf(mFile,"\tsetAttr \".dl\" ");
		dl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDeformedLatticePoints(const lattice& dlp)
	{
		fprintf(mFile,"\tsetAttr \".dl.dlp\" -type \"lattice\" ");
		dlp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDeformedLatticeMatrix(const matrix& dlm)
	{
		if(dlm == identity) return;
		fprintf(mFile,"\tsetAttr \".dl.dlm\" -type \"matrix\" ");
		dlm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBaseLattice(const BaseLattice& bl)
	{
		fprintf(mFile,"\tsetAttr \".bl\" ");
		bl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBaseLatticePoints(const lattice& blp)
	{
		fprintf(mFile,"\tsetAttr \".bl.blp\" -type \"lattice\" ");
		blp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBaseLatticeMatrix(const matrix& blm)
	{
		if(blm == identity) return;
		fprintf(mFile,"\tsetAttr \".bl.blm\" -type \"matrix\" ");
		blm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStuCacheList(size_t scl_i,const StuCacheList& scl)
	{
		fprintf(mFile,"\tsetAttr \".scl[%i]\" ",scl_i);
		scl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStuCacheList(size_t scl_start,size_t scl_end,StuCacheList* scl)
	{
		fprintf(mFile,"\tsetAttr \".scl[%i:%i]\" ", scl_start,scl_end);
		size_t size = (scl_end-scl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			scl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startStuCacheList(size_t scl_start,size_t scl_end)const
	{
		fprintf(mFile,"\tsetAttr \".scl[%i:%i]\"",scl_start,scl_end);
		fprintf(mFile," -type \"StuCacheList\" ");
	}
	void appendStuCacheList(const StuCacheList& scl)const
	{
		fprintf(mFile," ");
		scl.write(mFile);
	}
	void endStuCacheList()const
	{
		fprintf(mFile,";\n");
	}
	void setStuCache(size_t scl_i,size_t stu_i,double stu)
	{
		if(stu == 0) return;
		fprintf(mFile,"\tsetAttr \".scl[%i].stu[%i]\" %f;\n", scl_i,stu_i,stu);
	}
	void setStuCache(size_t scl_i,size_t stu_start,size_t stu_end,double* stu)
	{
		fprintf(mFile,"\tsetAttr \".scl[%i].stu[%i:%i]\" ", scl_i,stu_start,stu_end);
		size_t size = (stu_end-stu_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",stu[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startStuCache(size_t scl_i,size_t stu_start,size_t stu_end)const
	{
		fprintf(mFile,"\tsetAttr \".scl[%i].stu[%i:%i]\"",scl_i,stu_start,stu_end);
	}
	void appendStuCache(double stu)const
	{
		fprintf(mFile," %f",stu);
	}
	void endStuCache()const
	{
		fprintf(mFile,";\n");
	}
	void setPartialResolution(double ptr)
	{
		if(ptr == 0.01) return;
		fprintf(mFile,"\tsetAttr \".ptr\" %f;\n", ptr);
	}
	void setLocalInfluenceS(short lis)
	{
		if(lis == 2) return;
		fprintf(mFile,"\tsetAttr \".lis\" %i;\n", lis);
	}
	void setLocalInfluenceT(short lit)
	{
		if(lit == 2) return;
		fprintf(mFile,"\tsetAttr \".lit\" %i;\n", lit);
	}
	void setLocalInfluenceU(short liu)
	{
		if(liu == 2) return;
		fprintf(mFile,"\tsetAttr \".liu\" %i;\n", liu);
	}
	void setFreezeGeometry(bool fg)
	{
		if(fg == 0) return;
		fprintf(mFile,"\tsetAttr \".fg\" %i;\n", fg);
	}
	void setLocal(bool lo)
	{
		if(lo == 0) return;
		fprintf(mFile,"\tsetAttr \".lo\" %i;\n", lo);
	}
	void setUsePartialResolution(unsigned int upr)
	{
		if(upr == 0) return;
		fprintf(mFile,"\tsetAttr \".upr\" %i;\n", upr);
	}
	void setOutsideLattice(unsigned int ot)
	{
		if(ot == 0) return;
		fprintf(mFile,"\tsetAttr \".ot\" %i;\n", ot);
	}
	void setOutsideFalloffDist(double ofd)
	{
		if(ofd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ofd\" %f;\n", ofd);
	}
	void getDeformedLattice()const
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getDeformedLatticePoints()const
	{
		fprintf(mFile,"\"%s.dl.dlp\"",mName.c_str());
	}
	void getDeformedLatticeMatrix()const
	{
		fprintf(mFile,"\"%s.dl.dlm\"",mName.c_str());
	}
	void getBaseLattice()const
	{
		fprintf(mFile,"\"%s.bl\"",mName.c_str());
	}
	void getBaseLatticePoints()const
	{
		fprintf(mFile,"\"%s.bl.blp\"",mName.c_str());
	}
	void getBaseLatticeMatrix()const
	{
		fprintf(mFile,"\"%s.bl.blm\"",mName.c_str());
	}
	void getStuCacheList(size_t scl_i)const
	{
		fprintf(mFile,"\"%s.scl[%i]\"",mName.c_str(),scl_i);
	}
	void getStuCacheList()const
	{

		fprintf(mFile,"\"%s.scl\"",mName.c_str());
	}
	void getStuCache(size_t scl_i,size_t stu_i)const
	{
		fprintf(mFile,"\"%s.scl[%i].stu[%i]\"",mName.c_str(),scl_i,stu_i);
	}
	void getStuCache(size_t stu_i)const
	{

		fprintf(mFile,"\"%s.scl.stu[%i]\"",mName.c_str(),stu_i);
	}
	void getPartialResolution()const
	{
		fprintf(mFile,"\"%s.ptr\"",mName.c_str());
	}
	void getLocalInfluenceS()const
	{
		fprintf(mFile,"\"%s.lis\"",mName.c_str());
	}
	void getLocalInfluenceT()const
	{
		fprintf(mFile,"\"%s.lit\"",mName.c_str());
	}
	void getLocalInfluenceU()const
	{
		fprintf(mFile,"\"%s.liu\"",mName.c_str());
	}
	void getFreezeGeometry()const
	{
		fprintf(mFile,"\"%s.fg\"",mName.c_str());
	}
	void getLocal()const
	{
		fprintf(mFile,"\"%s.lo\"",mName.c_str());
	}
	void getUsePartialResolution()const
	{
		fprintf(mFile,"\"%s.upr\"",mName.c_str());
	}
	void getOutsideLattice()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getOutsideFalloffDist()const
	{
		fprintf(mFile,"\"%s.ofd\"",mName.c_str());
	}
protected:
	Ffd(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FFD_H__
