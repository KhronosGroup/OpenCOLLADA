/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VECTORRENDERGLOBALS_H__
#define __MayaDM_VECTORRENDERGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class VectorRenderGlobals : public DependNode
{
public:
public:
	VectorRenderGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "vectorRenderGlobals"){}
	virtual ~VectorRenderGlobals(){}
	void setCurrentFrame(bool cf)
	{
		if(cf == false) return;
		fprintf(mFile,"setAttr \".cf\" %i;\n", cf);

	}
	void setFrameRate(int fr)
	{
		if(fr == 12) return;
		fprintf(mFile,"setAttr \".fr\" %i;\n", fr);

	}
	void setSvgAnimation(unsigned int sa)
	{
		if(sa == 0) return;
		fprintf(mFile,"setAttr \".sa\" %i;\n", sa);

	}
	void setSvgCompression(bool sc)
	{
		if(sc == false) return;
		fprintf(mFile,"setAttr \".sc\" %i;\n", sc);

	}
	void setFlashVersion(unsigned int fv)
	{
		if(fv == 2) return;
		fprintf(mFile,"setAttr \".fv\" %i;\n", fv);

	}
	void setBrowserView(bool bv)
	{
		if(bv == false) return;
		fprintf(mFile,"setAttr \".bv\" %i;\n", bv);

	}
	void setShowBackFaces(bool sb)
	{
		if(sb == true) return;
		fprintf(mFile,"setAttr \".sb\" %i;\n", sb);

	}
	void setShadows(bool sh)
	{
		if(sh == false) return;
		fprintf(mFile,"setAttr \".sh\" %i;\n", sh);

	}
	void setHighlights(bool hi)
	{
		if(hi == false) return;
		fprintf(mFile,"setAttr \".hi\" %i;\n", hi);

	}
	void setHighlightLevel(short hl)
	{
		if(hl == 4) return;
		fprintf(mFile,"setAttr \".hl\" %i;\n", hl);

	}
	void setReflections(bool rf)
	{
		if(rf == false) return;
		fprintf(mFile,"setAttr \".rf\" %i;\n", rf);

	}
	void setReflectionDepth(short rd)
	{
		if(rd == 2) return;
		fprintf(mFile,"setAttr \".rd\" %i;\n", rd);

	}
	void setCombineFillsEdges(bool cfe)
	{
		if(cfe == false) return;
		fprintf(mFile,"setAttr \".cfe\" %i;\n", cfe);

	}
	void setCurveTolerance(double ct)
	{
		if(ct == 7.5) return;
		fprintf(mFile,"setAttr \".ct\" %f;\n", ct);

	}
	void setSecondaryCF(bool scf)
	{
		if(scf == false) return;
		fprintf(mFile,"setAttr \".scf\" %i;\n", scf);

	}
	void setDetailLevel(short dl)
	{
		if(dl == 0) return;
		fprintf(mFile,"setAttr \".dl\" %i;\n", dl);

	}
	void setIncludeEdges(bool ie)
	{
		if(ie == false) return;
		fprintf(mFile,"setAttr \".ie\" %i;\n", ie);

	}
	void setRenderOptimization(const string& rno)
	{
		if(rno == "Safe") return;
		fprintf(mFile,"setAttr \".rno\" -type \"string\" ");
		rno.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFillObjects(bool fo)
	{
		if(fo == true) return;
		fprintf(mFile,"setAttr \".fo\" %i;\n", fo);

	}
	void setFillStyle(unsigned int fs)
	{
		if(fs == 0) return;
		fprintf(mFile,"setAttr \".fs\" %i;\n", fs);

	}
	void setEdgeStyle(unsigned int es)
	{
		if(es == 0) return;
		fprintf(mFile,"setAttr \".es\" %i;\n", es);

	}
	void setHiddenEdges(bool he)
	{
		if(he == false) return;
		fprintf(mFile,"setAttr \".he\" %i;\n", he);

	}
	void setEdgeDetail(bool ed)
	{
		if(ed == false) return;
		fprintf(mFile,"setAttr \".ed\" %i;\n", ed);

	}
	void setOutlinesAtIntersections(bool oai)
	{
		if(oai == true) return;
		fprintf(mFile,"setAttr \".oai\" %i;\n", oai);

	}
	void setMinEdgeAngle(double mea)
	{
		if(mea == 90.0) return;
		fprintf(mFile,"setAttr \".mea\" %f;\n", mea);

	}
	void setEdgeColor(const float3& ec)
	{
		fprintf(mFile,"setAttr \".ec\" -type \"float3\" ");
		ec.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEdgeColorR(float ecr)
	{
		if(ecr == 0) return;
		fprintf(mFile,"setAttr \".ec.ecr\" %f;\n", ecr);

	}
	void setEdgeColorG(float ecg)
	{
		if(ecg == 0) return;
		fprintf(mFile,"setAttr \".ec.ecg\" %f;\n", ecg);

	}
	void setEdgeColorB(float ecb)
	{
		if(ecb == 0) return;
		fprintf(mFile,"setAttr \".ec.ecb\" %f;\n", ecb);

	}
	void setEdgeWeight(double ew)
	{
		if(ew == 0.0) return;
		fprintf(mFile,"setAttr \".ew\" %f;\n", ew);

	}
	void getImageNamePrefix()
	{
		fprintf(mFile,"\"%s.inp\"",mName.c_str());

	}
	void getImageFormat()
	{
		fprintf(mFile,"\"%s.if\"",mName.c_str());

	}
	void getPixelAspectRatio()
	{
		fprintf(mFile,"\"%s.par\"",mName.c_str());

	}
	void getFilenameFormat()
	{
		fprintf(mFile,"\"%s.ff\"",mName.c_str());

	}
protected:
	VectorRenderGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_VECTORRENDERGLOBALS_H__
