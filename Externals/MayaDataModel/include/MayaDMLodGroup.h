/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	LodGroup(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "lodGroup"){}
	virtual ~LodGroup(){}
	void setCameraMatrix(const matrix& cm)
	{
		if(cm == identity) return;
		fprintf(mFile,"setAttr \".cm\" -type \"matrix\" ");
		cm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setThreshold(size_t th_i,double th)
	{
		if(th == 0) return;
		fprintf(mFile,"setAttr \".th[%i]\" %f;\n", th_i,th);

	}
	void setDisplayLevel(size_t dl_i,unsigned int dl)
	{
		if(dl == 0) return;
		fprintf(mFile,"setAttr \".dl[%i]\" %i;\n", dl_i,dl);

	}
	void setMinMaxDistance(bool mmd)
	{
		if(mmd == 0) return;
		fprintf(mFile,"setAttr \".mmd\" %i;\n", mmd);

	}
	void setMinDistance(double mid)
	{
		if(mid == -100.0) return;
		fprintf(mFile,"setAttr \".mid\" %f;\n", mid);

	}
	void setMaxDistance(double mxd)
	{
		if(mxd == 100.0) return;
		fprintf(mFile,"setAttr \".mxd\" %f;\n", mxd);

	}
	void getCameraMatrix()
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());

	}
	void getThreshold(size_t th_i)
	{
		fprintf(mFile,"\"%s.th[%i]\"",mName.c_str(),th_i);

	}
	void getDisplayLevel(size_t dl_i)
	{
		fprintf(mFile,"\"%s.dl[%i]\"",mName.c_str(),dl_i);

	}
	void getMinMaxDistance()
	{
		fprintf(mFile,"\"%s.mmd\"",mName.c_str());

	}
	void getMinDistance()
	{
		fprintf(mFile,"\"%s.mid\"",mName.c_str());

	}
	void getMaxDistance()
	{
		fprintf(mFile,"\"%s.mxd\"",mName.c_str());

	}
	void getDistance()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getActiveLevel()
	{
		fprintf(mFile,"\"%s.al\"",mName.c_str());

	}
	void getOutput(size_t o_i)
	{
		fprintf(mFile,"\"%s.o[%i]\"",mName.c_str(),o_i);

	}
protected:
	LodGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_LODGROUP_H__
