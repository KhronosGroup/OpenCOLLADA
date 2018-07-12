/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LODGROUP_H__
#define __MayaDM_LODGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class LodGroup : public Transform
{
public:
public:

	LodGroup():Transform(){}
	LodGroup(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Transform(file, name, parent, "lodGroup", shared, create){}
	virtual ~LodGroup(){}

	void setCameraMatrix(const matrix& cm)
	{
		if(cm == identity) return;
		fprintf(mFile,"\tsetAttr \".cm\" -type \"matrix\" ");
		cm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setThreshold(size_t th_i,double th)
	{
		if(th == 0) return;
		fprintf(mFile,"\tsetAttr \".th[%i]\" %f;\n", th_i,th);
	}
	void setThreshold(size_t th_start,size_t th_end,double* th)
	{
		fprintf(mFile,"\tsetAttr \".th[%i:%i]\" ", th_start,th_end);
		size_t size = (th_end-th_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",th[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startThreshold(size_t th_start,size_t th_end)const
	{
		fprintf(mFile,"\tsetAttr \".th[%i:%i]\"",th_start,th_end);
	}
	void appendThreshold(double th)const
	{
		fprintf(mFile," %f",th);
	}
	void endThreshold()const
	{
		fprintf(mFile,";\n");
	}
	void setDisplayLevel(size_t dl_i,unsigned int dl)
	{
		if(dl == 0) return;
		fprintf(mFile,"\tsetAttr \".dl[%i]\" %i;\n", dl_i,dl);
	}
	void setDisplayLevel(size_t dl_start,size_t dl_end,unsigned int* dl)
	{
		fprintf(mFile,"\tsetAttr \".dl[%i:%i]\" ", dl_start,dl_end);
		size_t size = (dl_end-dl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",dl[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startDisplayLevel(size_t dl_start,size_t dl_end)const
	{
		fprintf(mFile,"\tsetAttr \".dl[%i:%i]\"",dl_start,dl_end);
	}
	void appendDisplayLevel(unsigned int dl)const
	{
		fprintf(mFile," %i",dl);
	}
	void endDisplayLevel()const
	{
		fprintf(mFile,";\n");
	}
	void setMinMaxDistance(bool mmd)
	{
		if(mmd == 0) return;
		fprintf(mFile,"\tsetAttr \".mmd\" %i;\n", mmd);
	}
	void setMinDistance(double mid)
	{
		if(mid == -100.0) return;
		fprintf(mFile,"\tsetAttr \".mid\" %f;\n", mid);
	}
	void setMaxDistance(double mxd)
	{
		if(mxd == 100.0) return;
		fprintf(mFile,"\tsetAttr \".mxd\" %f;\n", mxd);
	}
	void getCameraMatrix()const
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());
	}
	void getThreshold(size_t th_i)const
	{
		fprintf(mFile,"\"%s.th[%i]\"",mName.c_str(),th_i);
	}
	void getThreshold()const
	{

		fprintf(mFile,"\"%s.th\"",mName.c_str());
	}
	void getDisplayLevel(size_t dl_i)const
	{
		fprintf(mFile,"\"%s.dl[%i]\"",mName.c_str(),dl_i);
	}
	void getDisplayLevel()const
	{

		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getMinMaxDistance()const
	{
		fprintf(mFile,"\"%s.mmd\"",mName.c_str());
	}
	void getMinDistance()const
	{
		fprintf(mFile,"\"%s.mid\"",mName.c_str());
	}
	void getMaxDistance()const
	{
		fprintf(mFile,"\"%s.mxd\"",mName.c_str());
	}
	void getDistance()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getActiveLevel()const
	{
		fprintf(mFile,"\"%s.al\"",mName.c_str());
	}
	void getOutput(size_t o_i)const
	{
		fprintf(mFile,"\"%s.o[%i]\"",mName.c_str(),o_i);
	}
	void getOutput()const
	{

		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	LodGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Transform(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LODGROUP_H__
