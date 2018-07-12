/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYREDUCE_H__
#define __MayaDM_POLYREDUCE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyReduce : public PolyModifier
{
public:
public:

	PolyReduce():PolyModifier(){}
	PolyReduce(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyReduce", shared, create){}
	virtual ~PolyReduce(){}

	void setPercentage(double p)
	{
		if(p == 0) return;
		fprintf(mFile,"\tsetAttr \".p\" %f;\n", p);
	}
	void setCompactness(double com)
	{
		if(com == 0.0) return;
		fprintf(mFile,"\tsetAttr \".com\" %f;\n", com);
	}
	void setGeomWeights(double gwt)
	{
		if(gwt == 1) return;
		fprintf(mFile,"\tsetAttr \".gwt\" %f;\n", gwt);
	}
	void setUvWeights(double uwt)
	{
		if(uwt == 0) return;
		fprintf(mFile,"\tsetAttr \".uwt\" %f;\n", uwt);
	}
	void setColorWeights(double cwt)
	{
		if(cwt == 0) return;
		fprintf(mFile,"\tsetAttr \".cwt\" %f;\n", cwt);
	}
	void setKeepQuadsWeight(double kqw)
	{
		if(kqw == 0) return;
		fprintf(mFile,"\tsetAttr \".kqw\" %f;\n", kqw);
	}
	void setWeightCoefficient(double wc)
	{
		if(wc == 10000.0) return;
		fprintf(mFile,"\tsetAttr \".wc\" %f;\n", wc);
	}
	void setVertexWeights(const doubleArray& vwt)
	{
		if(vwt.size == 0) return;
		fprintf(mFile,"\tsetAttr \".vwt\" -type \"doubleArray\" ");
		vwt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setKeepBorder(bool kb)
	{
		if(kb == true) return;
		fprintf(mFile,"\tsetAttr \".kb\" %i;\n", kb);
	}
	void setKeepMapBorder(bool kmb)
	{
		if(kmb == true) return;
		fprintf(mFile,"\tsetAttr \".kmb\" %i;\n", kmb);
	}
	void setKeepHardEdge(bool khe)
	{
		if(khe == true) return;
		fprintf(mFile,"\tsetAttr \".khe\" %i;\n", khe);
	}
	void setKeepOriginalVertices(bool kev)
	{
		if(kev == false) return;
		fprintf(mFile,"\tsetAttr \".kev\" %i;\n", kev);
	}
	void setTriangulate(bool t)
	{
		if(t == true) return;
		fprintf(mFile,"\tsetAttr \".t\" %i;\n", t);
	}
	void setCachingReduce(bool cr)
	{
		if(cr == false) return;
		fprintf(mFile,"\tsetAttr \".cr\" %i;\n", cr);
	}
	void setBorder(double b)
	{
		if(b == .5) return;
		fprintf(mFile,"\tsetAttr \".b\" %f;\n", b);
	}
	void setLine(double l)
	{
		if(l == .5) return;
		fprintf(mFile,"\tsetAttr \".l\" %f;\n", l);
	}
	void setDetail(double d)
	{
		if(d == .5) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void getPercentage()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getCompactness()const
	{
		fprintf(mFile,"\"%s.com\"",mName.c_str());
	}
	void getGeomWeights()const
	{
		fprintf(mFile,"\"%s.gwt\"",mName.c_str());
	}
	void getUvWeights()const
	{
		fprintf(mFile,"\"%s.uwt\"",mName.c_str());
	}
	void getColorWeights()const
	{
		fprintf(mFile,"\"%s.cwt\"",mName.c_str());
	}
	void getKeepQuadsWeight()const
	{
		fprintf(mFile,"\"%s.kqw\"",mName.c_str());
	}
	void getWeightCoefficient()const
	{
		fprintf(mFile,"\"%s.wc\"",mName.c_str());
	}
	void getWeights(size_t wts_i)const
	{
		fprintf(mFile,"\"%s.wts[%i]\"",mName.c_str(),wts_i);
	}
	void getWeights()const
	{

		fprintf(mFile,"\"%s.wts\"",mName.c_str());
	}
	void getVertexWeights()const
	{
		fprintf(mFile,"\"%s.vwt\"",mName.c_str());
	}
	void getKeepBorder()const
	{
		fprintf(mFile,"\"%s.kb\"",mName.c_str());
	}
	void getKeepMapBorder()const
	{
		fprintf(mFile,"\"%s.kmb\"",mName.c_str());
	}
	void getKeepHardEdge()const
	{
		fprintf(mFile,"\"%s.khe\"",mName.c_str());
	}
	void getKeepOriginalVertices()const
	{
		fprintf(mFile,"\"%s.kev\"",mName.c_str());
	}
	void getTriangulate()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getCachingReduce()const
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getBorder()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getLine()const
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getDetail()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
protected:
	PolyReduce(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYREDUCE_H__
