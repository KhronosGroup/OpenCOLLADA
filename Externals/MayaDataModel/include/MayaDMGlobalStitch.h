/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GLOBALSTITCH_H__
#define __MayaDM_GLOBALSTITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class GlobalStitch : public AbstractBaseCreate
{
public:
public:
	GlobalStitch():AbstractBaseCreate(){}
	GlobalStitch(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "globalStitch"){}
	virtual ~GlobalStitch(){}
	void setStitchCorners(unsigned int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"\tsetAttr \".sc\" %i;\n", sc);

	}
	void setStitchEdges(unsigned int se)
	{
		if(se == 1) return;
		fprintf(mFile,"\tsetAttr \".se\" %i;\n", se);

	}
	void setStitchSmoothness(unsigned int ss)
	{
		if(ss == 0) return;
		fprintf(mFile,"\tsetAttr \".ss\" %i;\n", ss);

	}
	void setStitchPartialEdges(bool spe)
	{
		if(spe == false) return;
		fprintf(mFile,"\tsetAttr \".spe\" %i;\n", spe);

	}
	void setMaxSeparation(double ms)
	{
		if(ms == 0) return;
		fprintf(mFile,"\tsetAttr \".ms\" %f;\n", ms);

	}
	void setSampling(int sam)
	{
		if(sam == 1) return;
		fprintf(mFile,"\tsetAttr \".sam\" %i;\n", sam);

	}
	void setModificationResistance(double mr)
	{
		if(mr == 1e-1) return;
		fprintf(mFile,"\tsetAttr \".mr\" %f;\n", mr);

	}
	void setLockSurface(size_t lk_i,bool lk)
	{
		if(lk == false) return;
		fprintf(mFile,"\tsetAttr \".lk[%i]\" %i;\n", lk_i,lk);

	}
	void setLockSurface(size_t lk_start,size_t lk_end,bool* lk)
	{
		fprintf(mFile,"\tsetAttr \".lk[%i:%i]\" ", lk_start,lk_end);
		size_t size = (lk_end-lk_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",lk[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startLockSurface(size_t lk_start,size_t lk_end)
	{
		fprintf(mFile,"\tsetAttr \".lk[%i:%i]\"",lk_start,lk_end);

	}
	void appendLockSurface(bool lk)
	{
		fprintf(mFile," %i",lk);

	}
	void endLockSurface()
	{
		fprintf(mFile,";\n");

	}
	void getInputSurface(size_t is_i)
	{
		fprintf(mFile,"\"%s.is[%i]\"",mName.c_str(),is_i);

	}
	void getStitchCorners()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getStitchEdges()
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());

	}
	void getStitchSmoothness()
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getStitchPartialEdges()
	{
		fprintf(mFile,"\"%s.spe\"",mName.c_str());

	}
	void getMaxSeparation()
	{
		fprintf(mFile,"\"%s.ms\"",mName.c_str());

	}
	void getSampling()
	{
		fprintf(mFile,"\"%s.sam\"",mName.c_str());

	}
	void getModificationResistance()
	{
		fprintf(mFile,"\"%s.mr\"",mName.c_str());

	}
	void getLockSurface(size_t lk_i)
	{
		fprintf(mFile,"\"%s.lk[%i]\"",mName.c_str(),lk_i);

	}
	void getShouldBeLast()
	{
		fprintf(mFile,"\"%s.sbl\"",mName.c_str());

	}
	void getOutputSurface(size_t os_i)
	{
		fprintf(mFile,"\"%s.os[%i]\"",mName.c_str(),os_i);

	}
	void getConnectedEdges(size_t ce_i)
	{
		fprintf(mFile,"\"%s.ce[%i]\"",mName.c_str(),ce_i);

	}
	void getUnconnectedEdges(size_t ue_i)
	{
		fprintf(mFile,"\"%s.ue[%i]\"",mName.c_str(),ue_i);

	}
protected:
	GlobalStitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_GLOBALSTITCH_H__
