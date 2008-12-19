/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	SubdivToPoly(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdivToPoly"){}
	virtual ~SubdivToPoly(){}
	void setFormat(unsigned int f)
	{
		if(f == 0) return;
		fprintf(mFile,"setAttr \".f\" %i;\n", f);

	}
	void setPolygonType(unsigned int pt)
	{
		if(pt == 2) return;
		fprintf(mFile,"setAttr \".pt\" %i;\n", pt);

	}
	void setExtractPointPosition(bool epp)
	{
		if(epp == false) return;
		fprintf(mFile,"setAttr \".epp\" %i;\n", epp);

	}
	void setSampleCount(int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"setAttr \".sc\" %i;\n", sc);

	}
	void setDepth(int d)
	{
		if(d == 0) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setMaxPolys(int mp)
	{
		if(mp == 0) return;
		fprintf(mFile,"setAttr \".mp\" %i;\n", mp);

	}
	void setSubdNormals(bool un)
	{
		if(un == false) return;
		fprintf(mFile,"setAttr \".un\" %i;\n", un);

	}
	void setCopyUVTopology(bool cut)
	{
		if(cut == false) return;
		fprintf(mFile,"setAttr \".cut\" %i;\n", cut);

	}
	void setShareUVs(bool suv)
	{
		if(suv == false) return;
		fprintf(mFile,"setAttr \".suv\" %i;\n", suv);

	}
	void setLevel(int l)
	{
		if(l == 0) return;
		fprintf(mFile,"setAttr \".l\" %i;\n", l);

	}
	void setConvertComp(bool cc)
	{
		if(cc == false) return;
		fprintf(mFile,"setAttr \".cc\" %i;\n", cc);

	}
	void setOutSubdCVId(size_t os_i,const long2& os)
	{
		fprintf(mFile,"setAttr \".os[%i]\" -type \"long2\" ",os_i);
		os.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutSubdCVId(size_t os_start,size_t os_end,long* os)
	{
		fprintf(mFile,"setAttr \".os[%i:%i]\" ", os_start,os_end);
		size_t size = (os_end-os_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",os[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void setOutSubdCVIdLeft(size_t os_i,int osl)
	{
		if(osl == 0) return;
		fprintf(mFile,"setAttr \".os[%i].osl\" %i;\n", os_i,osl);

	}
	void setOutSubdCVIdRight(size_t os_i,int osr)
	{
		if(osr == 0) return;
		fprintf(mFile,"setAttr \".os[%i].osr\" %i;\n", os_i,osr);

	}
	void setInSubdCVId(size_t is_i,const long2& is)
	{
		fprintf(mFile,"setAttr \".is[%i]\" -type \"long2\" ",is_i);
		is.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInSubdCVId(size_t is_start,size_t is_end,long* is)
	{
		fprintf(mFile,"setAttr \".is[%i:%i]\" ", is_start,is_end);
		size_t size = (is_end-is_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",is[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void setInSubdCVIdLeft(size_t is_i,int isl)
	{
		if(isl == 0) return;
		fprintf(mFile,"setAttr \".is[%i].isl\" %i;\n", is_i,isl);

	}
	void setInSubdCVIdRight(size_t is_i,int isr)
	{
		if(isr == 0) return;
		fprintf(mFile,"setAttr \".is[%i].isr\" %i;\n", is_i,isr);

	}
	void setPreserveVertexOrdering(bool pvo)
	{
		if(pvo == true) return;
		fprintf(mFile,"setAttr \".pvo\" %i;\n", pvo);

	}
	void setOutv(size_t ov_i,int ov)
	{
		if(ov == 0) return;
		fprintf(mFile,"setAttr \".ov[%i]\" %i;\n", ov_i,ov);

	}
	void setApplyMatrixToResult(bool amr)
	{
		if(amr == true) return;
		fprintf(mFile,"setAttr \".amr\" %i;\n", amr);

	}
	void getOutMesh()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getFormat()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getPolygonType()
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());

	}
	void getExtractPointPosition()
	{
		fprintf(mFile,"\"%s.epp\"",mName.c_str());

	}
	void getSampleCount()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getDepth()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getMaxPolys()
	{
		fprintf(mFile,"\"%s.mp\"",mName.c_str());

	}
	void getSubdNormals()
	{
		fprintf(mFile,"\"%s.un\"",mName.c_str());

	}
	void getCopyUVTopology()
	{
		fprintf(mFile,"\"%s.cut\"",mName.c_str());

	}
	void getShareUVs()
	{
		fprintf(mFile,"\"%s.suv\"",mName.c_str());

	}
	void getLevel()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getConvertComp()
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());

	}
	void getOutSubdCVId(size_t os_i)
	{
		fprintf(mFile,"\"%s.os[%i]\"",mName.c_str(),os_i);

	}
	void getOutSubdCVIdLeft(size_t os_i)
	{
		fprintf(mFile,"\"%s.os[%i].osl\"",mName.c_str(),os_i);

	}
	void getOutSubdCVIdRight(size_t os_i)
	{
		fprintf(mFile,"\"%s.os[%i].osr\"",mName.c_str(),os_i);

	}
	void getInSubdCVId(size_t is_i)
	{
		fprintf(mFile,"\"%s.is[%i]\"",mName.c_str(),is_i);

	}
	void getInSubdCVIdLeft(size_t is_i)
	{
		fprintf(mFile,"\"%s.is[%i].isl\"",mName.c_str(),is_i);

	}
	void getInSubdCVIdRight(size_t is_i)
	{
		fprintf(mFile,"\"%s.is[%i].isr\"",mName.c_str(),is_i);

	}
	void getPreserveVertexOrdering()
	{
		fprintf(mFile,"\"%s.pvo\"",mName.c_str());

	}
	void getOutv(size_t ov_i)
	{
		fprintf(mFile,"\"%s.ov[%i]\"",mName.c_str(),ov_i);

	}
	void getApplyMatrixToResult()
	{
		fprintf(mFile,"\"%s.amr\"",mName.c_str());

	}
protected:
	SubdivToPoly(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVTOPOLY_H__
