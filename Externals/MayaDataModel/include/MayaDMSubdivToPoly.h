/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVTOPOLY_H__
#define __MayaDM_SUBDIVTOPOLY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SubdivToPoly : public DependNode
{
public:
public:

	SubdivToPoly():DependNode(){}
	SubdivToPoly(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "subdivToPoly", shared, create){}
	virtual ~SubdivToPoly(){}

	void setFormat(unsigned int f)
	{
		if(f == 0) return;
		fprintf(mFile,"\tsetAttr \".f\" %i;\n", f);
	}
	void setPolygonType(unsigned int pt)
	{
		if(pt == 2) return;
		fprintf(mFile,"\tsetAttr \".pt\" %i;\n", pt);
	}
	void setExtractPointPosition(bool epp)
	{
		if(epp == false) return;
		fprintf(mFile,"\tsetAttr \".epp\" %i;\n", epp);
	}
	void setSampleCount(int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"\tsetAttr \".sc\" %i;\n", sc);
	}
	void setDepth(int d)
	{
		if(d == 0) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setMaxPolys(int mp)
	{
		if(mp == 0) return;
		fprintf(mFile,"\tsetAttr \".mp\" %i;\n", mp);
	}
	void setSubdNormals(bool un)
	{
		if(un == false) return;
		fprintf(mFile,"\tsetAttr \".un\" %i;\n", un);
	}
	void setCopyUVTopology(bool cut)
	{
		if(cut == false) return;
		fprintf(mFile,"\tsetAttr \".cut\" %i;\n", cut);
	}
	void setShareUVs(bool suv)
	{
		if(suv == false) return;
		fprintf(mFile,"\tsetAttr \".suv\" %i;\n", suv);
	}
	void setLevel(int l)
	{
		if(l == 0) return;
		fprintf(mFile,"\tsetAttr \".l\" %i;\n", l);
	}
	void setConvertComp(bool cc)
	{
		if(cc == false) return;
		fprintf(mFile,"\tsetAttr \".cc\" %i;\n", cc);
	}
	void setOutSubdCVId(size_t os_i,const long2& os)
	{
		fprintf(mFile,"\tsetAttr \".os[%i]\" -type \"long2\" ",os_i);
		os.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOutSubdCVId(size_t os_start,size_t os_end,int* os)
	{
		fprintf(mFile,"\tsetAttr \".os[%i:%i]\" ", os_start,os_end);
		size_t size = (os_end-os_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",os[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startOutSubdCVId(size_t os_start,size_t os_end)const
	{
		fprintf(mFile,"\tsetAttr \".os[%i:%i]\"",os_start,os_end);
	}
	void appendOutSubdCVId(int os)const
	{
		fprintf(mFile," %i",os);
	}
	void endOutSubdCVId()const
	{
		fprintf(mFile,";\n");
	}
	void setOutSubdCVIdLeft(size_t os_i,int osl)
	{
		if(osl == 0) return;
		fprintf(mFile,"\tsetAttr \".os[%i].osl\" %i;\n", os_i,osl);
	}
	void setOutSubdCVIdRight(size_t os_i,int osr)
	{
		if(osr == 0) return;
		fprintf(mFile,"\tsetAttr \".os[%i].osr\" %i;\n", os_i,osr);
	}
	void setInSubdCVId(size_t is_i,const long2& is)
	{
		fprintf(mFile,"\tsetAttr \".is[%i]\" -type \"long2\" ",is_i);
		is.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInSubdCVId(size_t is_start,size_t is_end,int* is)
	{
		fprintf(mFile,"\tsetAttr \".is[%i:%i]\" ", is_start,is_end);
		size_t size = (is_end-is_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",is[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInSubdCVId(size_t is_start,size_t is_end)const
	{
		fprintf(mFile,"\tsetAttr \".is[%i:%i]\"",is_start,is_end);
	}
	void appendInSubdCVId(int is)const
	{
		fprintf(mFile," %i",is);
	}
	void endInSubdCVId()const
	{
		fprintf(mFile,";\n");
	}
	void setInSubdCVIdLeft(size_t is_i,int isl)
	{
		if(isl == 0) return;
		fprintf(mFile,"\tsetAttr \".is[%i].isl\" %i;\n", is_i,isl);
	}
	void setInSubdCVIdRight(size_t is_i,int isr)
	{
		if(isr == 0) return;
		fprintf(mFile,"\tsetAttr \".is[%i].isr\" %i;\n", is_i,isr);
	}
	void setPreserveVertexOrdering(bool pvo)
	{
		if(pvo == true) return;
		fprintf(mFile,"\tsetAttr \".pvo\" %i;\n", pvo);
	}
	void setOutv(size_t ov_i,int ov)
	{
		if(ov == 0) return;
		fprintf(mFile,"\tsetAttr \".ov[%i]\" %i;\n", ov_i,ov);
	}
	void setOutv(size_t ov_start,size_t ov_end,int* ov)
	{
		fprintf(mFile,"\tsetAttr \".ov[%i:%i]\" ", ov_start,ov_end);
		size_t size = (ov_end-ov_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ov[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startOutv(size_t ov_start,size_t ov_end)const
	{
		fprintf(mFile,"\tsetAttr \".ov[%i:%i]\"",ov_start,ov_end);
	}
	void appendOutv(int ov)const
	{
		fprintf(mFile," %i",ov);
	}
	void endOutv()const
	{
		fprintf(mFile,";\n");
	}
	void setApplyMatrixToResult(bool amr)
	{
		if(amr == true) return;
		fprintf(mFile,"\tsetAttr \".amr\" %i;\n", amr);
	}
	void getInSubdiv()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutMesh()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getFormat()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getPolygonType()const
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());
	}
	void getExtractPointPosition()const
	{
		fprintf(mFile,"\"%s.epp\"",mName.c_str());
	}
	void getSampleCount()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getDepth()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getMaxPolys()const
	{
		fprintf(mFile,"\"%s.mp\"",mName.c_str());
	}
	void getSubdNormals()const
	{
		fprintf(mFile,"\"%s.un\"",mName.c_str());
	}
	void getCopyUVTopology()const
	{
		fprintf(mFile,"\"%s.cut\"",mName.c_str());
	}
	void getShareUVs()const
	{
		fprintf(mFile,"\"%s.suv\"",mName.c_str());
	}
	void getLevel()const
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getConvertComp()const
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());
	}
	void getOutSubdCVId(size_t os_i)const
	{
		fprintf(mFile,"\"%s.os[%i]\"",mName.c_str(),os_i);
	}
	void getOutSubdCVId()const
	{

		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getOutSubdCVIdLeft(size_t os_i)const
	{
		fprintf(mFile,"\"%s.os[%i].osl\"",mName.c_str(),os_i);
	}
	void getOutSubdCVIdLeft()const
	{

		fprintf(mFile,"\"%s.os.osl\"",mName.c_str());
	}
	void getOutSubdCVIdRight(size_t os_i)const
	{
		fprintf(mFile,"\"%s.os[%i].osr\"",mName.c_str(),os_i);
	}
	void getOutSubdCVIdRight()const
	{

		fprintf(mFile,"\"%s.os.osr\"",mName.c_str());
	}
	void getInSubdCVId(size_t is_i)const
	{
		fprintf(mFile,"\"%s.is[%i]\"",mName.c_str(),is_i);
	}
	void getInSubdCVId()const
	{

		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getInSubdCVIdLeft(size_t is_i)const
	{
		fprintf(mFile,"\"%s.is[%i].isl\"",mName.c_str(),is_i);
	}
	void getInSubdCVIdLeft()const
	{

		fprintf(mFile,"\"%s.is.isl\"",mName.c_str());
	}
	void getInSubdCVIdRight(size_t is_i)const
	{
		fprintf(mFile,"\"%s.is[%i].isr\"",mName.c_str(),is_i);
	}
	void getInSubdCVIdRight()const
	{

		fprintf(mFile,"\"%s.is.isr\"",mName.c_str());
	}
	void getPreserveVertexOrdering()const
	{
		fprintf(mFile,"\"%s.pvo\"",mName.c_str());
	}
	void getOutv(size_t ov_i)const
	{
		fprintf(mFile,"\"%s.ov[%i]\"",mName.c_str(),ov_i);
	}
	void getOutv()const
	{

		fprintf(mFile,"\"%s.ov\"",mName.c_str());
	}
	void getApplyMatrixToResult()const
	{
		fprintf(mFile,"\"%s.amr\"",mName.c_str());
	}
protected:
	SubdivToPoly(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVTOPOLY_H__
