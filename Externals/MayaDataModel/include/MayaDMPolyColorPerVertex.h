/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCOLORPERVERTEX_H__
#define __MayaDM_POLYCOLORPERVERTEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyColorPerVertex : public PolyModifier
{
public:
	struct ColorPerVertex{
		struct VertexColor{
			float3 vertexColorRGB;
			float vertexAlpha;
			struct VertexFaceColor{
				float3 vertexFaceColorRGB;
				float vertexFaceAlpha;
				void write(FILE* file) const
				{
					vertexFaceColorRGB.write(file);
					fprintf(file, " ");
					fprintf(file,"%f", vertexFaceAlpha);
				}
			}* vertexFaceColor;
			void write(FILE* file) const
			{
				vertexColorRGB.write(file);
				fprintf(file, " ");
				fprintf(file,"%f ", vertexAlpha);
				size_t size = sizeof(vertexFaceColor)/sizeof(VertexFaceColor);
				for(size_t i=0; i<size; ++i)
				{
					vertexFaceColor[i].write(file);
					if(i+1<size) fprintf(file," ");
				}
			}
		}* vertexColor;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertexColor)/sizeof(VertexColor);
			for(size_t i=0; i<size; ++i)
			{
				vertexColor[i].write(file);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
public:

	PolyColorPerVertex():PolyModifier(){}
	PolyColorPerVertex(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyColorPerVertex", shared, create){}
	virtual ~PolyColorPerVertex(){}

	void setColorPerVertex(const ColorPerVertex& cpvx)
	{
		fprintf(mFile,"\tsetAttr \".cpvx\" ");
		cpvx.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexColor(size_t vclr_i,const ColorPerVertex::VertexColor& vclr)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i]\" ",vclr_i);
		vclr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexColor(size_t vclr_start,size_t vclr_end,ColorPerVertex::VertexColor* vclr)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i:%i]\" ", vclr_start,vclr_end);
		size_t size = (vclr_end-vclr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			vclr[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startVertexColor(size_t vclr_start,size_t vclr_end)const
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i:%i]\"",vclr_start,vclr_end);
		fprintf(mFile," -type \"ColorPerVertex::VertexColor\" ");
	}
	void appendVertexColor(const ColorPerVertex::VertexColor& vclr)const
	{
		fprintf(mFile," ");
		vclr.write(mFile);
	}
	void endVertexColor()const
	{
		fprintf(mFile,";\n");
	}
	void setVertexColorRGB(size_t vclr_i,const float3& vrgb)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vrgb\" -type \"float3\" ",vclr_i);
		vrgb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexColorR(size_t vclr_i,float vxcr)
	{
		if(vxcr == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vrgb.vxcr\" %f;\n", vclr_i,vxcr);
	}
	void setVertexColorG(size_t vclr_i,float vxcg)
	{
		if(vxcg == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vrgb.vxcg\" %f;\n", vclr_i,vxcg);
	}
	void setVertexColorB(size_t vclr_i,float vxcb)
	{
		if(vxcb == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vrgb.vxcb\" %f;\n", vclr_i,vxcb);
	}
	void setVertexAlpha(size_t vclr_i,float vxal)
	{
		if(vxal == 1) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vxal\" %f;\n", vclr_i,vxal);
	}
	void setVertexFaceColor(size_t vclr_i,size_t vfcl_i,const ColorPerVertex::VertexColor::VertexFaceColor& vfcl)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i]\" ",vclr_i,vfcl_i);
		vfcl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexFaceColor(size_t vclr_i,size_t vfcl_start,size_t vfcl_end,ColorPerVertex::VertexColor::VertexFaceColor* vfcl)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i:%i]\" ", vclr_i,vfcl_start,vfcl_end);
		size_t size = (vfcl_end-vfcl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			vfcl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startVertexFaceColor(size_t vclr_i,size_t vfcl_start,size_t vfcl_end)const
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i:%i]\"",vclr_i,vfcl_start,vfcl_end);
		fprintf(mFile," -type \"ColorPerVertex::VertexColor::VertexFaceColor\" ");
	}
	void appendVertexFaceColor(const ColorPerVertex::VertexColor::VertexFaceColor& vfcl)const
	{
		fprintf(mFile," ");
		vfcl.write(mFile);
	}
	void endVertexFaceColor()const
	{
		fprintf(mFile,";\n");
	}
	void setVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i,const float3& frgb)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].frgb\" -type \"float3\" ",vclr_i,vfcl_i);
		frgb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexFaceColorR(size_t vclr_i,size_t vfcl_i,float vfcr)
	{
		if(vfcr == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcr\" %f;\n", vclr_i,vfcl_i,vfcr);
	}
	void setVertexFaceColorG(size_t vclr_i,size_t vfcl_i,float vfcg)
	{
		if(vfcg == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcg\" %f;\n", vclr_i,vfcl_i,vfcg);
	}
	void setVertexFaceColorB(size_t vclr_i,size_t vfcl_i,float vfcb)
	{
		if(vfcb == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcb\" %f;\n", vclr_i,vfcl_i,vfcb);
	}
	void setVertexFaceAlpha(size_t vclr_i,size_t vfcl_i,float vfal)
	{
		if(vfal == 1) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].vfal\" %f;\n", vclr_i,vfcl_i,vfal);
	}
	void setColorSetName(const string& cn)
	{
		if(cn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cn\" -type \"string\" ");
		cn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClamped(bool clam)
	{
		if(clam == true) return;
		fprintf(mFile,"\tsetAttr \".clam\" %i;\n", clam);
	}
	void setRepresentation(unsigned int rprt)
	{
		if(rprt == 3) return;
		fprintf(mFile,"\tsetAttr \".rprt\" %i;\n", rprt);
	}
	void getColorPerVertex()const
	{
		fprintf(mFile,"\"%s.cpvx\"",mName.c_str());
	}
	void getVertexColor(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i]\"",mName.c_str(),vclr_i);
	}
	void getVertexColorRGB(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb\"",mName.c_str(),vclr_i);
	}
	void getVertexColorR(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb.vxcr\"",mName.c_str(),vclr_i);
	}
	void getVertexColorG(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb.vxcg\"",mName.c_str(),vclr_i);
	}
	void getVertexColorB(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb.vxcb\"",mName.c_str(),vclr_i);
	}
	void getVertexAlpha(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vxal\"",mName.c_str(),vclr_i);
	}
	void getVertexFaceColor(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i]\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceColorR(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcr\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceColorG(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcg\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceColorB(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcb\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceAlpha(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].vfal\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getColorSetName()const
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());
	}
	void getClamped()const
	{
		fprintf(mFile,"\"%s.clam\"",mName.c_str());
	}
	void getRepresentation()const
	{
		fprintf(mFile,"\"%s.rprt\"",mName.c_str());
	}
protected:
	PolyColorPerVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOLORPERVERTEX_H__
