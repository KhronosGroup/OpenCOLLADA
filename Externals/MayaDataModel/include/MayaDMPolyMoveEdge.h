/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMOVEEDGE_H__
#define __MayaDM_POLYMOVEEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyMoveVertex.h"
namespace MayaDM
{
class PolyMoveEdge : public PolyMoveVertex
{
public:
public:

	PolyMoveEdge():PolyMoveVertex(){}
	PolyMoveEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyMoveVertex(file, name, parent, "polyMoveEdge", shared, create){}
	virtual ~PolyMoveEdge(){}

	void setLocalRotate(const double3& lr)
	{
		if(lr == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".lr\" -type \"double3\" ");
		lr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocalRotateX(double lrx)
	{
		if(lrx == 0) return;
		fprintf(mFile,"\tsetAttr \".lr.lrx\" %f;\n", lrx);
	}
	void setLocalRotateY(double lry)
	{
		if(lry == 0) return;
		fprintf(mFile,"\tsetAttr \".lr.lry\" %f;\n", lry);
	}
	void setLocalRotateZ(double lrz)
	{
		if(lrz == 0) return;
		fprintf(mFile,"\tsetAttr \".lr.lrz\" %f;\n", lrz);
	}
	void setLocalScale(const double3& ls)
	{
		if(ls == double3(1.0, 1.0, 1.0)) return;
		fprintf(mFile,"\tsetAttr \".ls\" -type \"double3\" ");
		ls.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocalScaleX(double lsx)
	{
		if(lsx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ls.lsx\" %f;\n", lsx);
	}
	void setLocalScaleY(double lsy)
	{
		if(lsy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ls.lsy\" %f;\n", lsy);
	}
	void setLocalScaleZ(double lsz)
	{
		if(lsz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ls.lsz\" %f;\n", lsz);
	}
	void setLocalCenter(unsigned int lc)
	{
		if(lc == 0) return;
		fprintf(mFile,"\tsetAttr \".lc\" %i;\n", lc);
	}
	void getLocalRotate()const
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());
	}
	void getLocalRotateX()const
	{
		fprintf(mFile,"\"%s.lr.lrx\"",mName.c_str());
	}
	void getLocalRotateY()const
	{
		fprintf(mFile,"\"%s.lr.lry\"",mName.c_str());
	}
	void getLocalRotateZ()const
	{
		fprintf(mFile,"\"%s.lr.lrz\"",mName.c_str());
	}
	void getLocalScale()const
	{
		fprintf(mFile,"\"%s.ls\"",mName.c_str());
	}
	void getLocalScaleX()const
	{
		fprintf(mFile,"\"%s.ls.lsx\"",mName.c_str());
	}
	void getLocalScaleY()const
	{
		fprintf(mFile,"\"%s.ls.lsy\"",mName.c_str());
	}
	void getLocalScaleZ()const
	{
		fprintf(mFile,"\"%s.ls.lsz\"",mName.c_str());
	}
	void getLocalCenter()const
	{
		fprintf(mFile,"\"%s.lc\"",mName.c_str());
	}
protected:
	PolyMoveEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyMoveVertex(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMOVEEDGE_H__
