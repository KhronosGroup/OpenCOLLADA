/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GEOCONNECTABLE_H__
#define __MayaDM_GEOCONNECTABLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class GeoConnectable : public Shape
{
public:
public:

	GeoConnectable():Shape(){}
	GeoConnectable(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "geoConnectable", shared, create){}
	virtual ~GeoConnectable(){}

	void getConnectionsToMe(size_t ct_i)const
	{
		fprintf(mFile,"\"%s.ct[%i]\"",mName.c_str(),ct_i);
	}
	void getConnectionsToMe()const
	{

		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getAuxiliariesOwned()const
	{
		fprintf(mFile,"\"%s.ao\"",mName.c_str());
	}
	void getVelocityValid()const
	{
		fprintf(mFile,"\"%s.vv\"",mName.c_str());
	}
	void getDoVelocity()const
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());
	}
	void getPrevTime()const
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());
	}
	void getCachedPositions()const
	{
		fprintf(mFile,"\"%s.cpo\"",mName.c_str());
	}
	void getCachedVelocities()const
	{
		fprintf(mFile,"\"%s.cve\"",mName.c_str());
	}
	void getComponentPositions(size_t cpp_i)const
	{
		fprintf(mFile,"\"%s.cpp[%i]\"",mName.c_str(),cpp_i);
	}
	void getComponentPositions()const
	{

		fprintf(mFile,"\"%s.cpp\"",mName.c_str());
	}
	void getGroupId(size_t gri_i)const
	{
		fprintf(mFile,"\"%s.gri[%i]\"",mName.c_str(),gri_i);
	}
	void getGroupId()const
	{

		fprintf(mFile,"\"%s.gri\"",mName.c_str());
	}
	void getInputGeometryMsg()const
	{
		fprintf(mFile,"\"%s.igm\"",mName.c_str());
	}
	void getSurfaceGeometry()const
	{
		fprintf(mFile,"\"%s.sge\"",mName.c_str());
	}
	void getLocalSurfaceGeometry()const
	{
		fprintf(mFile,"\"%s.lsg\"",mName.c_str());
	}
protected:
	GeoConnectable(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_GEOCONNECTABLE_H__
