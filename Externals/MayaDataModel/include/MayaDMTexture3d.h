/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TEXTURE3D_H__
#define __MayaDM_TEXTURE3D_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Texture3d : public DependNode
{
public:
public:
	Texture3d(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "texture3d"){}
	virtual ~Texture3d(){}
	void setFilter(float f)
	{
		if(f == 1.0) return;
		fprintf(mFile,"setAttr \".f\" %f;\n", f);

	}
	void setFilterOffset(float fo)
	{
		if(fo == 0.0) return;
		fprintf(mFile,"setAttr \".fo\" %f;\n", fo);

	}
	void setBlend(float b)
	{
		if(b == 0.0) return;
		fprintf(mFile,"setAttr \".b\" %f;\n", b);

	}
	void setLocal(bool lo)
	{
		if(lo == false) return;
		fprintf(mFile,"setAttr \".lo\" %i;\n", lo);

	}
	void setWrap(bool w)
	{
		if(w == true) return;
		fprintf(mFile,"setAttr \".w\" %i;\n", w);

	}
	void setInvert(bool i_)
	{
		if(i_ == false) return;
		fprintf(mFile,"setAttr \".i\" %i;\n", i_);

	}
	void setAlphaIsLuminance(bool ail)
	{
		if(ail == false) return;
		fprintf(mFile,"setAttr \".ail\" %i;\n", ail);

	}
	void setColorGain(const float3& cg)
	{
		if(cg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".cg\" -type \"float3\" ");
		cg.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorGainR(float cgr)
	{
		if(cgr == 0.0) return;
		fprintf(mFile,"setAttr \".cg.cgr\" %f;\n", cgr);

	}
	void setColorGainG(float cgg)
	{
		if(cgg == 0.0) return;
		fprintf(mFile,"setAttr \".cg.cgg\" %f;\n", cgg);

	}
	void setColorGainB(float cgb)
	{
		if(cgb == 0.0) return;
		fprintf(mFile,"setAttr \".cg.cgb\" %f;\n", cgb);

	}
	void setColorOffset(const float3& co)
	{
		if(co == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".co\" -type \"float3\" ");
		co.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorOffsetR(float cor)
	{
		if(cor == 0.0) return;
		fprintf(mFile,"setAttr \".co.cor\" %f;\n", cor);

	}
	void setColorOffsetG(float cog)
	{
		if(cog == 0.0) return;
		fprintf(mFile,"setAttr \".co.cog\" %f;\n", cog);

	}
	void setColorOffsetB(float cob)
	{
		if(cob == 0.0) return;
		fprintf(mFile,"setAttr \".co.cob\" %f;\n", cob);

	}
	void setAlphaGain(float ag)
	{
		if(ag == 1.0) return;
		fprintf(mFile,"setAttr \".ag\" %f;\n", ag);

	}
	void setAlphaOffset(float ao)
	{
		if(ao == 0.0) return;
		fprintf(mFile,"setAttr \".ao\" %f;\n", ao);

	}
	void setDefaultColor(const float3& dc)
	{
		if(dc == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"setAttr \".dc\" -type \"float3\" ");
		dc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDefaultColorR(float dcr)
	{
		if(dcr == 0.0) return;
		fprintf(mFile,"setAttr \".dc.dcr\" %f;\n", dcr);

	}
	void setDefaultColorG(float dcg)
	{
		if(dcg == 0.0) return;
		fprintf(mFile,"setAttr \".dc.dcg\" %f;\n", dcg);

	}
	void setDefaultColorB(float dcb)
	{
		if(dcb == 0.0) return;
		fprintf(mFile,"setAttr \".dc.dcb\" %f;\n", dcb);

	}
	void getPointObj()
	{
		fprintf(mFile,"\"%s.po\"",mName.c_str());

	}
	void getPointObjX()
	{
		fprintf(mFile,"\"%s.po.pox\"",mName.c_str());

	}
	void getPointObjY()
	{
		fprintf(mFile,"\"%s.po.poy\"",mName.c_str());

	}
	void getPointObjZ()
	{
		fprintf(mFile,"\"%s.po.poz\"",mName.c_str());

	}
	void getPointCamera()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getPointCameraX()
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());

	}
	void getPointCameraY()
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());

	}
	void getPointCameraZ()
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());

	}
	void getFilterSize()
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());

	}
	void getFilterSizeX()
	{
		fprintf(mFile,"\"%s.fs.fsx\"",mName.c_str());

	}
	void getFilterSizeY()
	{
		fprintf(mFile,"\"%s.fs.fsy\"",mName.c_str());

	}
	void getFilterSizeZ()
	{
		fprintf(mFile,"\"%s.fs.fsz\"",mName.c_str());

	}
	void getPlacementMatrix()
	{
		fprintf(mFile,"\"%s.pm\"",mName.c_str());

	}
	void getMatrixEyeToWorld()
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());

	}
	void getFilter()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getFilterOffset()
	{
		fprintf(mFile,"\"%s.fo\"",mName.c_str());

	}
	void getBlend()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getWrap()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getInvert()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getAlphaIsLuminance()
	{
		fprintf(mFile,"\"%s.ail\"",mName.c_str());

	}
	void getColorGain()
	{
		fprintf(mFile,"\"%s.cg\"",mName.c_str());

	}
	void getColorGainR()
	{
		fprintf(mFile,"\"%s.cg.cgr\"",mName.c_str());

	}
	void getColorGainG()
	{
		fprintf(mFile,"\"%s.cg.cgg\"",mName.c_str());

	}
	void getColorGainB()
	{
		fprintf(mFile,"\"%s.cg.cgb\"",mName.c_str());

	}
	void getColorOffset()
	{
		fprintf(mFile,"\"%s.co\"",mName.c_str());

	}
	void getColorOffsetR()
	{
		fprintf(mFile,"\"%s.co.cor\"",mName.c_str());

	}
	void getColorOffsetG()
	{
		fprintf(mFile,"\"%s.co.cog\"",mName.c_str());

	}
	void getColorOffsetB()
	{
		fprintf(mFile,"\"%s.co.cob\"",mName.c_str());

	}
	void getAlphaGain()
	{
		fprintf(mFile,"\"%s.ag\"",mName.c_str());

	}
	void getAlphaOffset()
	{
		fprintf(mFile,"\"%s.ao\"",mName.c_str());

	}
	void getDefaultColor()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getDefaultColorR()
	{
		fprintf(mFile,"\"%s.dc.dcr\"",mName.c_str());

	}
	void getDefaultColorG()
	{
		fprintf(mFile,"\"%s.dc.dcg\"",mName.c_str());

	}
	void getDefaultColorB()
	{
		fprintf(mFile,"\"%s.dc.dcb\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());

	}
	void getOutAlpha()
	{
		fprintf(mFile,"\"%s.oa\"",mName.c_str());

	}
protected:
	Texture3d(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TEXTURE3D_H__
