/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	HyperLayout(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hyperLayout"){}
	virtual ~HyperLayout(){}
	void setHyperPosition(size_t hyp_i,const HyperPosition& hyp)
	{
		fprintf(mFile,"setAttr \".hyp[%i]\" ",hyp_i);
		hyp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPositionX(size_t hyp_i,float x)
	{
		if(x == 0.0) return;
		fprintf(mFile,"setAttr \".hyp[%i].x\" %f;\n", hyp_i,x);

	}
	void setPositionY(size_t hyp_i,float y)
	{
		if(y == 0.0) return;
		fprintf(mFile,"setAttr \".hyp[%i].y\" %f;\n", hyp_i,y);

	}
	void setIsCollapsed(size_t hyp_i,bool isc)
	{
		if(isc == false) return;
		fprintf(mFile,"setAttr \".hyp[%i].isc\" %i;\n", hyp_i,isc);

	}
	void setIsFreeform(size_t hyp_i,bool isf)
	{
		if(isf == false) return;
		fprintf(mFile,"setAttr \".hyp[%i].isf\" %i;\n", hyp_i,isf);

	}
	void setImageName(const string& img)
	{
		if(img == "") return;
		fprintf(mFile,"setAttr \".img\" -type \"string\" ");
		img.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImagePosition(const double2& imp)
	{
		if(imp == double2(0, 0)) return;
		fprintf(mFile,"setAttr \".imp\" -type \"double2\" ");
		imp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImagePositionX(double ipx)
	{
		if(ipx == 0.0) return;
		fprintf(mFile,"setAttr \".imp.ipx\" %f;\n", ipx);

	}
	void setImagePositionY(double ipy)
	{
		if(ipy == 0.0) return;
		fprintf(mFile,"setAttr \".imp.ipy\" %f;\n", ipy);

	}
	void setImageScale(float ims)
	{
		if(ims == 1.0) return;
		fprintf(mFile,"setAttr \".ims\" %f;\n", ims);

	}
	void setAllNodesFreeform(bool anf)
	{
		if(anf == false) return;
		fprintf(mFile,"setAttr \".anf\" %i;\n", anf);

	}
	void getHyperPosition(size_t hyp_i)
	{
		fprintf(mFile,"\"%s.hyp[%i]\"",mName.c_str(),hyp_i);

	}
	void getPositionX(size_t hyp_i)
	{
		fprintf(mFile,"\"%s.hyp[%i].x\"",mName.c_str(),hyp_i);

	}
	void getPositionY(size_t hyp_i)
	{
		fprintf(mFile,"\"%s.hyp[%i].y\"",mName.c_str(),hyp_i);

	}
	void getIsCollapsed(size_t hyp_i)
	{
		fprintf(mFile,"\"%s.hyp[%i].isc\"",mName.c_str(),hyp_i);

	}
	void getIsFreeform(size_t hyp_i)
	{
		fprintf(mFile,"\"%s.hyp[%i].isf\"",mName.c_str(),hyp_i);

	}
	void getDependNode(size_t hyp_i)
	{
		fprintf(mFile,"\"%s.hyp[%i].dn\"",mName.c_str(),hyp_i);

	}
	void getImageName()
	{
		fprintf(mFile,"\"%s.img\"",mName.c_str());

	}
	void getImagePosition()
	{
		fprintf(mFile,"\"%s.imp\"",mName.c_str());

	}
	void getImagePositionX()
	{
		fprintf(mFile,"\"%s.imp.ipx\"",mName.c_str());

	}
	void getImagePositionY()
	{
		fprintf(mFile,"\"%s.imp.ipy\"",mName.c_str());

	}
	void getImageScale()
	{
		fprintf(mFile,"\"%s.ims\"",mName.c_str());

	}
	void getAllNodesFreeform()
	{
		fprintf(mFile,"\"%s.anf\"",mName.c_str());

	}
protected:
	HyperLayout(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HYPERLAYOUT_H__
