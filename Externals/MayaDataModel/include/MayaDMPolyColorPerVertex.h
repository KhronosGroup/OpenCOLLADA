/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
<p><pre> Node to edit color per vertex or per vertexFace of polygonal objects.
</pre></p>
*/
class PolyColorPerVertex : public PolyModifier
{
public:
	/*
	Attribute to specify the color of a vertex, either on the entire
	vertex on a per face basis.
	*/
	struct ColorPerVertex{
		/*
		A compound attribute that corresponds to the color of the vertex.
		It is a multi attribute and the index of the multi identifies the
		vertex that the color applies to.
		*/
		struct VertexColor{
			float3 vertexColorRGB;
			float vertexAlpha;
			/*
			A compound attribute that corresponds to the color of the vertex
			attached to a particular face. It is a multi attribute and the index
			of the multi identifies the face that the color applies to. The index
			of the parent attribute (aVertexColor) already identifies the vertex
			that color is being attached to.
			*/
			struct VertexFaceColor{
				float3 vertexFaceColorRGB;
				float vertexFaceAlpha;
				void write(FILE* file) const
				{
					vertexFaceColorRGB.write(file);
					fprintf_s(file, " ");
					fprintf_s(file,"%f", vertexFaceAlpha);
				}
			}* vertexFaceColor;
			void write(FILE* file) const
			{
				vertexColorRGB.write(file);
				fprintf_s(file, " ");
				fprintf_s(file,"%f ", vertexAlpha);
				size_t size = sizeof(vertexFaceColor)/sizeof(VertexFaceColor);
				for(size_t i=0; i<size; ++i)
				{
					vertexFaceColor[i].write(file);
					if(i+1<size) fprintf_s(file," ");
				}
			}
		}* vertexColor;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertexColor)/sizeof(VertexColor);
			for(size_t i=0; i<size; ++i)
			{
				vertexColor[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	PolyColorPerVertex(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyColorPerVertex"){}
	virtual ~PolyColorPerVertex(){}
	/*
	Attribute to specify the color of a vertex, either on the entire
	vertex on a per face basis.
	*/
	void setColorPerVertex(const ColorPerVertex& cpvx){fprintf_s(mFile, "setAttr \".cpvx\" ");cpvx.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Attribute to specify the color of a vertex, either on the entire
	vertex on a per face basis.
	*/
	void setColorPerVertex(const ColorPerVertexID& cpvx){fprintf_s(mFile,"connectAttr \"");cpvx.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx\";\n",mName.c_str());}
	/*
	A compound attribute that corresponds to the color of the vertex.
	It is a multi attribute and the index of the multi identifies the
	vertex that the color applies to.
	*/
	void setVertexColor(size_t vclr_i,const ColorPerVertex::VertexColor& vclr){fprintf_s(mFile, "setAttr \".cpvx.vclr[%i]\" ",vclr_i);vclr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	A compound attribute that corresponds to the color of the vertex.
	It is a multi attribute and the index of the multi identifies the
	vertex that the color applies to.
	*/
	void setVertexColor(size_t vclr_i,const VertexColorID& vclr){fprintf_s(mFile,"connectAttr \"");vclr.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i]\";\n",mName.c_str(),vclr_i);}
	/*Vertex color. RGB channels.*/
	void setVertexColorRGB(size_t vclr_i,const float3& vrgb){fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vrgb\" -type \"float3\" ",vclr_i);vrgb.write(mFile);fprintf_s(mFile,";\n");}
	/*Vertex color. RGB channels.*/
	void setVertexColorRGB(size_t vclr_i,const Float3ID& vrgb){fprintf_s(mFile,"connectAttr \"");vrgb.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vrgb\";\n",mName.c_str(),vclr_i);}
	/*Vertex color. R channel.*/
	void setVertexColorR(size_t vclr_i,float vxcr){if(vxcr == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vrgb.vxcr\" %f;\n", vclr_i,vxcr);}
	/*Vertex color. R channel.*/
	void setVertexColorR(size_t vclr_i,const FloatID& vxcr){fprintf_s(mFile,"connectAttr \"");vxcr.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vrgb.vxcr\";\n",mName.c_str(),vclr_i);}
	/*Vertex color. G channel.*/
	void setVertexColorG(size_t vclr_i,float vxcg){if(vxcg == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vrgb.vxcg\" %f;\n", vclr_i,vxcg);}
	/*Vertex color. G channel.*/
	void setVertexColorG(size_t vclr_i,const FloatID& vxcg){fprintf_s(mFile,"connectAttr \"");vxcg.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vrgb.vxcg\";\n",mName.c_str(),vclr_i);}
	/*Vertex color. B channel.*/
	void setVertexColorB(size_t vclr_i,float vxcb){if(vxcb == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vrgb.vxcb\" %f;\n", vclr_i,vxcb);}
	/*Vertex color. B channel.*/
	void setVertexColorB(size_t vclr_i,const FloatID& vxcb){fprintf_s(mFile,"connectAttr \"");vxcb.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vrgb.vxcb\";\n",mName.c_str(),vclr_i);}
	/*Vertex color. Alpha channel.*/
	void setVertexAlpha(size_t vclr_i,float vxal){if(vxal == 1) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vxal\" %f;\n", vclr_i,vxal);}
	/*Vertex color. Alpha channel.*/
	void setVertexAlpha(size_t vclr_i,const FloatID& vxal){fprintf_s(mFile,"connectAttr \"");vxal.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vxal\";\n",mName.c_str(),vclr_i);}
	/*
	A compound attribute that corresponds to the color of the vertex
	attached to a particular face. It is a multi attribute and the index
	of the multi identifies the face that the color applies to. The index
	of the parent attribute (aVertexColor) already identifies the vertex
	that color is being attached to.
	*/
	void setVertexFaceColor(size_t vclr_i,size_t vfcl_i,const ColorPerVertex::VertexColor::VertexFaceColor& vfcl){fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i]\" ",vclr_i,vfcl_i);vfcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	A compound attribute that corresponds to the color of the vertex
	attached to a particular face. It is a multi attribute and the index
	of the multi identifies the face that the color applies to. The index
	of the parent attribute (aVertexColor) already identifies the vertex
	that color is being attached to.
	*/
	void setVertexFaceColor(size_t vclr_i,size_t vfcl_i,const VertexFaceColorID& vfcl){fprintf_s(mFile,"connectAttr \"");vfcl.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i]\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*RGB channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i,const float3& frgb){fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].frgb\" -type \"float3\" ",vclr_i,vfcl_i);frgb.write(mFile);fprintf_s(mFile,";\n");}
	/*RGB channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i,const Float3ID& frgb){fprintf_s(mFile,"connectAttr \"");frgb.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].frgb\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*R channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorR(size_t vclr_i,size_t vfcl_i,float vfcr){if(vfcr == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcr\" %f;\n", vclr_i,vfcl_i,vfcr);}
	/*R channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorR(size_t vclr_i,size_t vfcl_i,const FloatID& vfcr){fprintf_s(mFile,"connectAttr \"");vfcr.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcr\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*G channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorG(size_t vclr_i,size_t vfcl_i,float vfcg){if(vfcg == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcg\" %f;\n", vclr_i,vfcl_i,vfcg);}
	/*G channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorG(size_t vclr_i,size_t vfcl_i,const FloatID& vfcg){fprintf_s(mFile,"connectAttr \"");vfcg.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcg\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*B channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorB(size_t vclr_i,size_t vfcl_i,float vfcb){if(vfcb == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcb\" %f;\n", vclr_i,vfcl_i,vfcb);}
	/*B channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorB(size_t vclr_i,size_t vfcl_i,const FloatID& vfcb){fprintf_s(mFile,"connectAttr \"");vfcb.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcb\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*Alpha channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceAlpha(size_t vclr_i,size_t vfcl_i,float vfal){if(vfal == 1) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].vfal\" %f;\n", vclr_i,vfcl_i,vfal);}
	/*Alpha channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceAlpha(size_t vclr_i,size_t vfcl_i,const FloatID& vfal){fprintf_s(mFile,"connectAttr \"");vfal.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].vfal\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*The name of the color set to work on*/
	void setColorSetName(const string& cn){if(cn == "NULL") return; fprintf_s(mFile, "setAttr \".cn\" -type \"string\" ");cn.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the color set to work on*/
	void setColorSetName(const StringID& cn){fprintf_s(mFile,"connectAttr \"");cn.write(mFile);fprintf_s(mFile,"\" \"%s.cn\";\n",mName.c_str());}
	/*If true, color and alpha will be in 0 to 1 range.*/
	void setClamped(bool clam){if(clam == true) return; fprintf_s(mFile, "setAttr \".clam\" %i;\n", clam);}
	/*If true, color and alpha will be in 0 to 1 range.*/
	void setClamped(const BoolID& clam){fprintf_s(mFile,"connectAttr \"");clam.write(mFile);fprintf_s(mFile,"\" \"%s.clam\";\n",mName.c_str());}
	/*This identifies both the number of channels and the type of channels*/
	void setRepresentation(unsigned int rprt){if(rprt == 3) return; fprintf_s(mFile, "setAttr \".rprt\" %i;\n", rprt);}
	/*This identifies both the number of channels and the type of channels*/
	void setRepresentation(const UnsignedintID& rprt){fprintf_s(mFile,"connectAttr \"");rprt.write(mFile);fprintf_s(mFile,"\" \"%s.rprt\";\n",mName.c_str());}
	/*
	Attribute to specify the color of a vertex, either on the entire
	vertex on a per face basis.
	*/
	ColorPerVertexID getColorPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.cpvx",mName.c_str());return (const char*)buffer;}
	/*
	A compound attribute that corresponds to the color of the vertex.
	It is a multi attribute and the index of the multi identifies the
	vertex that the color applies to.
	*/
	const VertexColorID& getVertexColor(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i]",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color. RGB channels.*/
	const Float3ID& getVertexColorRGB(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vrgb",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color. R channel.*/
	const FloatID& getVertexColorR(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vrgb.vxcr",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color. G channel.*/
	const FloatID& getVertexColorG(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vrgb.vxcg",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color. B channel.*/
	const FloatID& getVertexColorB(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vrgb.vxcb",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color. Alpha channel.*/
	const FloatID& getVertexAlpha(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vxal",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*
	A compound attribute that corresponds to the color of the vertex
	attached to a particular face. It is a multi attribute and the index
	of the multi identifies the face that the color applies to. The index
	of the parent attribute (aVertexColor) already identifies the vertex
	that color is being attached to.
	*/
	const VertexFaceColorID& getVertexFaceColor(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i]",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*RGB channel of Color of a vertex attached to a particular face.*/
	const Float3ID& getVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].frgb",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*R channel of Color of a vertex attached to a particular face.*/
	const FloatID& getVertexFaceColorR(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcr",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*G channel of Color of a vertex attached to a particular face.*/
	const FloatID& getVertexFaceColorG(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcg",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*B channel of Color of a vertex attached to a particular face.*/
	const FloatID& getVertexFaceColorB(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcb",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*Alpha channel of Color of a vertex attached to a particular face.*/
	const FloatID& getVertexFaceAlpha(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].vfal",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*The name of the color set to work on*/
	StringID getColorSetName(){char buffer[4096];sprintf_s (buffer, "%s.cn",mName.c_str());return (const char*)buffer;}
	/*If true, color and alpha will be in 0 to 1 range.*/
	BoolID getClamped(){char buffer[4096];sprintf_s (buffer, "%s.clam",mName.c_str());return (const char*)buffer;}
	/*This identifies both the number of channels and the type of channels*/
	UnsignedintID getRepresentation(){char buffer[4096];sprintf_s (buffer, "%s.rprt",mName.c_str());return (const char*)buffer;}
protected:
	PolyColorPerVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOLORPERVERTEX_H__
