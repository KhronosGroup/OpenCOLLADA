/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISPLAYLAYER_H__
#define __MayaDM_DISPLAYLAYER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DisplayLayer : public DependNode
{
public:
	struct DrawInfo{
		unsigned int displayType;
		unsigned int levelOfDetail;
		bool shading;
		bool texturing;
		bool playback;
		bool enabled;
		bool visibility;
		unsigned char color;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", displayType);
			fprintf(file,"%i ", levelOfDetail);
			fprintf(file,"%i ", shading);
			fprintf(file,"%i ", texturing);
			fprintf(file,"%i ", playback);
			fprintf(file,"%i ", enabled);
			fprintf(file,"%i ", visibility);
			fprintf(file,"%i", color);
		}
	};
public:

	DisplayLayer():DependNode(){}
	DisplayLayer(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "displayLayer", shared, create){}
	virtual ~DisplayLayer(){}

	void setIdentification(short id)
	{
		if(id == 0) return;
		fprintf(mFile,"\tsetAttr \".id\" %i;\n", id);
	}
	void setDrawInfo(const DrawInfo& di)
	{
		fprintf(mFile,"\tsetAttr \".di\" ");
		di.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDisplayType(unsigned int dt)
	{
		if(dt == 0) return;
		fprintf(mFile,"\tsetAttr \".di.dt\" %i;\n", dt);
	}
	void setLevelOfDetail(unsigned int lod)
	{
		if(lod == 0) return;
		fprintf(mFile,"\tsetAttr \".di.lod\" %i;\n", lod);
	}
	void setShading(bool s)
	{
		if(s == true) return;
		fprintf(mFile,"\tsetAttr \".di.s\" %i;\n", s);
	}
	void setTexturing(bool t)
	{
		if(t == true) return;
		fprintf(mFile,"\tsetAttr \".di.t\" %i;\n", t);
	}
	void setPlayback(bool p)
	{
		if(p == true) return;
		fprintf(mFile,"\tsetAttr \".di.p\" %i;\n", p);
	}
	void setEnabled(bool e)
	{
		if(e == true) return;
		fprintf(mFile,"\tsetAttr \".di.e\" %i;\n", e);
	}
	void setVisibility(bool v)
	{
		if(v == true) return;
		fprintf(mFile,"\tsetAttr \".di.v\" %i;\n", v);
	}
	void setColor(unsigned char c)
	{
		if(c == 0) return;
		fprintf(mFile,"\tsetAttr \".di.c\" %i;\n", c);
	}
	void setDisplayOrder(short do_)
	{
		if(do_ == 0) return;
		fprintf(mFile,"\tsetAttr \".do\" %i;\n", do_);
	}
	void getIdentification()const
	{
		fprintf(mFile,"\"%s.id\"",mName.c_str());
	}
	void getDrawInfo()const
	{
		fprintf(mFile,"\"%s.di\"",mName.c_str());
	}
	void getDisplayType()const
	{
		fprintf(mFile,"\"%s.di.dt\"",mName.c_str());
	}
	void getLevelOfDetail()const
	{
		fprintf(mFile,"\"%s.di.lod\"",mName.c_str());
	}
	void getShading()const
	{
		fprintf(mFile,"\"%s.di.s\"",mName.c_str());
	}
	void getTexturing()const
	{
		fprintf(mFile,"\"%s.di.t\"",mName.c_str());
	}
	void getPlayback()const
	{
		fprintf(mFile,"\"%s.di.p\"",mName.c_str());
	}
	void getEnabled()const
	{
		fprintf(mFile,"\"%s.di.e\"",mName.c_str());
	}
	void getVisibility()const
	{
		fprintf(mFile,"\"%s.di.v\"",mName.c_str());
	}
	void getColor()const
	{
		fprintf(mFile,"\"%s.di.c\"",mName.c_str());
	}
	void getDisplayOrder()const
	{
		fprintf(mFile,"\"%s.do\"",mName.c_str());
	}
protected:
	DisplayLayer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DISPLAYLAYER_H__
