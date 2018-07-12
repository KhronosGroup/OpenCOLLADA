/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LODTHRESHOLDS_H__
#define __MayaDM_LODTHRESHOLDS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class LodThresholds : public DependNode
{
public:
public:

	LodThresholds():DependNode(){}
	LodThresholds(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "lodThresholds", shared, create){}
	virtual ~LodThresholds(){}

	void setInBoxMin(const double3& bmn)
	{
		fprintf(mFile,"\tsetAttr \".bmn\" -type \"double3\" ");
		bmn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInBoxMinX(double bmix)
	{
		if(bmix == 0) return;
		fprintf(mFile,"\tsetAttr \".bmn.bmix\" %f;\n", bmix);
	}
	void setInBoxMinY(double bmiy)
	{
		if(bmiy == 0) return;
		fprintf(mFile,"\tsetAttr \".bmn.bmiy\" %f;\n", bmiy);
	}
	void setInBoxMinZ(double bmiz)
	{
		if(bmiz == 0) return;
		fprintf(mFile,"\tsetAttr \".bmn.bmiz\" %f;\n", bmiz);
	}
	void setInBoxMax(const double3& bmx)
	{
		fprintf(mFile,"\tsetAttr \".bmx\" -type \"double3\" ");
		bmx.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInBoxMaxX(double bmax)
	{
		if(bmax == 0) return;
		fprintf(mFile,"\tsetAttr \".bmx.bmax\" %f;\n", bmax);
	}
	void setInBoxMaxY(double bmay)
	{
		if(bmay == 0) return;
		fprintf(mFile,"\tsetAttr \".bmx.bmay\" %f;\n", bmay);
	}
	void setInBoxMaxZ(double bmaz)
	{
		if(bmaz == 0) return;
		fprintf(mFile,"\tsetAttr \".bmx.bmaz\" %f;\n", bmaz);
	}
	void setCamera(const double3& cam)
	{
		fprintf(mFile,"\tsetAttr \".cam\" -type \"double3\" ");
		cam.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCameraX(double cax)
	{
		if(cax == 0) return;
		fprintf(mFile,"\tsetAttr \".cam.cax\" %f;\n", cax);
	}
	void setCameraY(double cay)
	{
		if(cay == 0) return;
		fprintf(mFile,"\tsetAttr \".cam.cay\" %f;\n", cay);
	}
	void setCameraZ(double caz)
	{
		if(caz == 0) return;
		fprintf(mFile,"\tsetAttr \".cam.caz\" %f;\n", caz);
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
	void getInBoxMin()const
	{
		fprintf(mFile,"\"%s.bmn\"",mName.c_str());
	}
	void getInBoxMinX()const
	{
		fprintf(mFile,"\"%s.bmn.bmix\"",mName.c_str());
	}
	void getInBoxMinY()const
	{
		fprintf(mFile,"\"%s.bmn.bmiy\"",mName.c_str());
	}
	void getInBoxMinZ()const
	{
		fprintf(mFile,"\"%s.bmn.bmiz\"",mName.c_str());
	}
	void getInBoxMax()const
	{
		fprintf(mFile,"\"%s.bmx\"",mName.c_str());
	}
	void getInBoxMaxX()const
	{
		fprintf(mFile,"\"%s.bmx.bmax\"",mName.c_str());
	}
	void getInBoxMaxY()const
	{
		fprintf(mFile,"\"%s.bmx.bmay\"",mName.c_str());
	}
	void getInBoxMaxZ()const
	{
		fprintf(mFile,"\"%s.bmx.bmaz\"",mName.c_str());
	}
	void getCamera()const
	{
		fprintf(mFile,"\"%s.cam\"",mName.c_str());
	}
	void getCameraX()const
	{
		fprintf(mFile,"\"%s.cam.cax\"",mName.c_str());
	}
	void getCameraY()const
	{
		fprintf(mFile,"\"%s.cam.cay\"",mName.c_str());
	}
	void getCameraZ()const
	{
		fprintf(mFile,"\"%s.cam.caz\"",mName.c_str());
	}
	void getThreshold(size_t th_i)const
	{
		fprintf(mFile,"\"%s.th[%i]\"",mName.c_str(),th_i);
	}
	void getThreshold()const
	{

		fprintf(mFile,"\"%s.th\"",mName.c_str());
	}
	void getDistance()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getActiveLevel()const
	{
		fprintf(mFile,"\"%s.al\"",mName.c_str());
	}
	void getOutLevel(size_t ol_i)const
	{
		fprintf(mFile,"\"%s.ol[%i]\"",mName.c_str(),ol_i);
	}
	void getOutLevel()const
	{

		fprintf(mFile,"\"%s.ol\"",mName.c_str());
	}
protected:
	LodThresholds(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LODTHRESHOLDS_H__
