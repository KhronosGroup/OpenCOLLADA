/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRANSFERATTRIBUTES_H__
#define __MayaDM_TRANSFERATTRIBUTES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
class TransferAttributes : public WeightGeometryFilter
{
public:
public:

	TransferAttributes():WeightGeometryFilter(){}
	TransferAttributes(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:WeightGeometryFilter(file, name, parent, "transferAttributes", shared, create){}
	virtual ~TransferAttributes(){}

	void setTransferPositions(unsigned int pos)
	{
		if(pos == 0) return;
		fprintf(mFile,"\tsetAttr \".pos\" %i;\n", pos);
	}
	void setTransferNormals(unsigned int nml)
	{
		if(nml == 0) return;
		fprintf(mFile,"\tsetAttr \".nml\" %i;\n", nml);
	}
	void setTransferUVs(unsigned int uvs)
	{
		if(uvs == 0) return;
		fprintf(mFile,"\tsetAttr \".uvs\" %i;\n", uvs);
	}
	void setSourceUVSet(const string& suv)
	{
		if(suv == "NULL") return;
		fprintf(mFile,"\tsetAttr \".suv\" -type \"string\" ");
		suv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetUVSet(const string& tuv)
	{
		if(tuv == "NULL") return;
		fprintf(mFile,"\tsetAttr \".tuv\" -type \"string\" ");
		tuv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransferColors(unsigned int col)
	{
		if(col == 0) return;
		fprintf(mFile,"\tsetAttr \".col\" %i;\n", col);
	}
	void setSourceColorSet(const string& scs)
	{
		if(scs == "NULL") return;
		fprintf(mFile,"\tsetAttr \".scs\" -type \"string\" ");
		scs.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetColorSet(const string& tcs)
	{
		if(tcs == "NULL") return;
		fprintf(mFile,"\tsetAttr \".tcs\" -type \"string\" ");
		tcs.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSampleSpace(unsigned int spa)
	{
		if(spa == 0) return;
		fprintf(mFile,"\tsetAttr \".spa\" %i;\n", spa);
	}
	void setSourceUVSpace(const string& sus)
	{
		if(sus == "NULL") return;
		fprintf(mFile,"\tsetAttr \".sus\" -type \"string\" ");
		sus.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetUVSpace(const string& tus)
	{
		if(tus == "NULL") return;
		fprintf(mFile,"\tsetAttr \".tus\" -type \"string\" ");
		tus.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSearchMethod(unsigned int mtd)
	{
		if(mtd == 1) return;
		fprintf(mFile,"\tsetAttr \".mtd\" %i;\n", mtd);
	}
	void setSearchDistance(double dis)
	{
		if(dis == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dis\" %f;\n", dis);
	}
	void setSearchTolerance(double tol)
	{
		if(tol == 1.3) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void setSearchScale(const double3& ss)
	{
		if(ss == double3(1.0, 1.0, 1.0)) return;
		fprintf(mFile,"\tsetAttr \".ss\" -type \"double3\" ");
		ss.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSearchScaleX(double ssx)
	{
		if(ssx == 0) return;
		fprintf(mFile,"\tsetAttr \".ss.ssx\" %f;\n", ssx);
	}
	void setSearchScaleY(double ssy)
	{
		if(ssy == 0) return;
		fprintf(mFile,"\tsetAttr \".ss.ssy\" %f;\n", ssy);
	}
	void setSearchScaleZ(double ssz)
	{
		if(ssz == 0) return;
		fprintf(mFile,"\tsetAttr \".ss.ssz\" %f;\n", ssz);
	}
	void setFlipUVs(unsigned int fuv)
	{
		if(fuv == 0) return;
		fprintf(mFile,"\tsetAttr \".fuv\" %i;\n", fuv);
	}
	void setColorBorders(unsigned int clb)
	{
		if(clb == 1) return;
		fprintf(mFile,"\tsetAttr \".clb\" %i;\n", clb);
	}
	void getSource(size_t src_i)const
	{
		fprintf(mFile,"\"%s.src[%i]\"",mName.c_str(),src_i);
	}
	void getSource()const
	{

		fprintf(mFile,"\"%s.src\"",mName.c_str());
	}
	void getTransferPositions()const
	{
		fprintf(mFile,"\"%s.pos\"",mName.c_str());
	}
	void getTransferNormals()const
	{
		fprintf(mFile,"\"%s.nml\"",mName.c_str());
	}
	void getTransferUVs()const
	{
		fprintf(mFile,"\"%s.uvs\"",mName.c_str());
	}
	void getSourceUVSet()const
	{
		fprintf(mFile,"\"%s.suv\"",mName.c_str());
	}
	void getTargetUVSet()const
	{
		fprintf(mFile,"\"%s.tuv\"",mName.c_str());
	}
	void getTransferColors()const
	{
		fprintf(mFile,"\"%s.col\"",mName.c_str());
	}
	void getSourceColorSet()const
	{
		fprintf(mFile,"\"%s.scs\"",mName.c_str());
	}
	void getTargetColorSet()const
	{
		fprintf(mFile,"\"%s.tcs\"",mName.c_str());
	}
	void getSampleSpace()const
	{
		fprintf(mFile,"\"%s.spa\"",mName.c_str());
	}
	void getSourceUVSpace()const
	{
		fprintf(mFile,"\"%s.sus\"",mName.c_str());
	}
	void getTargetUVSpace()const
	{
		fprintf(mFile,"\"%s.tus\"",mName.c_str());
	}
	void getSearchMethod()const
	{
		fprintf(mFile,"\"%s.mtd\"",mName.c_str());
	}
	void getSearchDistance()const
	{
		fprintf(mFile,"\"%s.dis\"",mName.c_str());
	}
	void getSearchTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getSearchScale()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getSearchScaleX()const
	{
		fprintf(mFile,"\"%s.ss.ssx\"",mName.c_str());
	}
	void getSearchScaleY()const
	{
		fprintf(mFile,"\"%s.ss.ssy\"",mName.c_str());
	}
	void getSearchScaleZ()const
	{
		fprintf(mFile,"\"%s.ss.ssz\"",mName.c_str());
	}
	void getFlipUVs()const
	{
		fprintf(mFile,"\"%s.fuv\"",mName.c_str());
	}
	void getColorBorders()const
	{
		fprintf(mFile,"\"%s.clb\"",mName.c_str());
	}
protected:
	TransferAttributes(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:WeightGeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_TRANSFERATTRIBUTES_H__
