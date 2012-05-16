/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SNAPSHOTSHAPE_H__
#define __MayaDM_SNAPSHOTSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
class SnapshotShape : public GeometryShape
{
public:
public:

	SnapshotShape():GeometryShape(){}
	SnapshotShape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, "snapshotShape", shared, create){}
	virtual ~SnapshotShape(){}

	void setPoints(const pointArray& pts)
	{
		if(pts.size == 0) return;
		fprintf(mFile,"\tsetAttr \".pts\" -type \"pointArray\" ");
		pts.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFrames(const intArray& f)
	{
		if(f.size == 0) return;
		fprintf(mFile,"\tsetAttr \".f\" -type \"intArray\" ");
		f.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDrawStyle(unsigned int d)
	{
		if(d == 0) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setShowFrames(bool sf)
	{
		if(sf == 0) return;
		fprintf(mFile,"\tsetAttr \".sf\" %i;\n", sf);
	}
	void getPoints()const
	{
		fprintf(mFile,"\"%s.pts\"",mName.c_str());
	}
	void getFrames()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getDrawStyle()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getShowFrames()const
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());
	}
protected:
	SnapshotShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SNAPSHOTSHAPE_H__
