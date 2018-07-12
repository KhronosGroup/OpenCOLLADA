/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HYPERLAYOUT_H__
#define __MayaDM_HYPERLAYOUT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class HyperLayout : public DependNode
{
public:
	struct HyperPosition{
		float positionX;
		float positionY;
		bool isCollapsed;
		bool isFreeform;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", positionX);
			fprintf(file,"%f ", positionY);
			fprintf(file,"%i ", isCollapsed);
			fprintf(file,"%i ", isFreeform);
		}
	};
public:

	HyperLayout():DependNode(){}
	HyperLayout(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "hyperLayout", shared, create){}
	virtual ~HyperLayout(){}

	void setHyperPosition(size_t hyp_i,const HyperPosition& hyp)
	{
		fprintf(mFile,"\tsetAttr \".hyp[%i]\" ",hyp_i);
		hyp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHyperPosition(size_t hyp_start,size_t hyp_end,HyperPosition* hyp)
	{
		fprintf(mFile,"\tsetAttr \".hyp[%i:%i]\" ", hyp_start,hyp_end);
		size_t size = (hyp_end-hyp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			hyp[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startHyperPosition(size_t hyp_start,size_t hyp_end)const
	{
		fprintf(mFile,"\tsetAttr \".hyp[%i:%i]\"",hyp_start,hyp_end);
		fprintf(mFile," -type \"HyperPosition\" ");
	}
	void appendHyperPosition(const HyperPosition& hyp)const
	{
		fprintf(mFile," ");
		hyp.write(mFile);
	}
	void endHyperPosition()const
	{
		fprintf(mFile,";\n");
	}
	void setPositionX(size_t hyp_i,float x)
	{
		if(x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hyp[%i].x\" %f;\n", hyp_i,x);
	}
	void setPositionY(size_t hyp_i,float y)
	{
		if(y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hyp[%i].y\" %f;\n", hyp_i,y);
	}
	void setIsCollapsed(size_t hyp_i,bool isc)
	{
		if(isc == false) return;
		fprintf(mFile,"\tsetAttr \".hyp[%i].isc\" %i;\n", hyp_i,isc);
	}
	void setIsFreeform(size_t hyp_i,bool isf)
	{
		if(isf == false) return;
		fprintf(mFile,"\tsetAttr \".hyp[%i].isf\" %i;\n", hyp_i,isf);
	}
	void setImageName(const string& img)
	{
		if(img == "") return;
		fprintf(mFile,"\tsetAttr \".img\" -type \"string\" ");
		img.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImagePosition(const double2& imp)
	{
		if(imp == double2(0, 0)) return;
		fprintf(mFile,"\tsetAttr \".imp\" -type \"double2\" ");
		imp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImagePositionX(double ipx)
	{
		if(ipx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imp.ipx\" %f;\n", ipx);
	}
	void setImagePositionY(double ipy)
	{
		if(ipy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imp.ipy\" %f;\n", ipy);
	}
	void setImageScale(float ims)
	{
		if(ims == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ims\" %f;\n", ims);
	}
	void setAllNodesFreeform(bool anf)
	{
		if(anf == false) return;
		fprintf(mFile,"\tsetAttr \".anf\" %i;\n", anf);
	}
	void getHyperPosition(size_t hyp_i)const
	{
		fprintf(mFile,"\"%s.hyp[%i]\"",mName.c_str(),hyp_i);
	}
	void getHyperPosition()const
	{

		fprintf(mFile,"\"%s.hyp\"",mName.c_str());
	}
	void getPositionX(size_t hyp_i)const
	{
		fprintf(mFile,"\"%s.hyp[%i].x\"",mName.c_str(),hyp_i);
	}
	void getPositionX()const
	{

		fprintf(mFile,"\"%s.hyp.x\"",mName.c_str());
	}
	void getPositionY(size_t hyp_i)const
	{
		fprintf(mFile,"\"%s.hyp[%i].y\"",mName.c_str(),hyp_i);
	}
	void getPositionY()const
	{

		fprintf(mFile,"\"%s.hyp.y\"",mName.c_str());
	}
	void getIsCollapsed(size_t hyp_i)const
	{
		fprintf(mFile,"\"%s.hyp[%i].isc\"",mName.c_str(),hyp_i);
	}
	void getIsCollapsed()const
	{

		fprintf(mFile,"\"%s.hyp.isc\"",mName.c_str());
	}
	void getIsFreeform(size_t hyp_i)const
	{
		fprintf(mFile,"\"%s.hyp[%i].isf\"",mName.c_str(),hyp_i);
	}
	void getIsFreeform()const
	{

		fprintf(mFile,"\"%s.hyp.isf\"",mName.c_str());
	}
	void getDependNode(size_t hyp_i)const
	{
		fprintf(mFile,"\"%s.hyp[%i].dn\"",mName.c_str(),hyp_i);
	}
	void getDependNode()const
	{

		fprintf(mFile,"\"%s.hyp.dn\"",mName.c_str());
	}
	void getImageName()const
	{
		fprintf(mFile,"\"%s.img\"",mName.c_str());
	}
	void getImagePosition()const
	{
		fprintf(mFile,"\"%s.imp\"",mName.c_str());
	}
	void getImagePositionX()const
	{
		fprintf(mFile,"\"%s.imp.ipx\"",mName.c_str());
	}
	void getImagePositionY()const
	{
		fprintf(mFile,"\"%s.imp.ipy\"",mName.c_str());
	}
	void getImageScale()const
	{
		fprintf(mFile,"\"%s.ims\"",mName.c_str());
	}
	void getAllNodesFreeform()const
	{
		fprintf(mFile,"\"%s.anf\"",mName.c_str());
	}
protected:
	HyperLayout(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HYPERLAYOUT_H__
