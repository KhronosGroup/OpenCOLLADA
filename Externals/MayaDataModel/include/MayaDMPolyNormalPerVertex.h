/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYNORMALPERVERTEX_H__
#define __MayaDM_POLYNORMALPERVERTEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
<p><pre> Node to edit normals per vertex or per vertexFace of polygonal objects.
</pre></p>
*/
class PolyNormalPerVertex : public PolyModifier
{
public:
	/*
	Attribute to specify the normal of a vertex, either on the entire
	vertex on a per face basis.
	*/
	struct NormalPerVertex{
		/*
		A compound attribute that corresponds to the normal of the vertex.
		It is a multi attribute and the index of the multi identifies the
		vertex that the normal applies to.
		*/
		struct VertexNormal{
			float3 vertexNormalXYZ;
			/*
			A compound attribute that corresponds to the normal of the vertex
			attached to a particular face. It is a multi attribute and the index
			of the multi identifies the face that the normal applies to. The index
			of the parent attribute (aVertexNormal) already identifies the vertex
			that normal is being attached to.
			*/
			struct VertexFaceNormal{
				float3 vertexFaceNormalXYZ;
				void write(FILE* file) const
				{
					vertexFaceNormalXYZ.write(file);
				}
			}* vertexFaceNormal;
			void write(FILE* file) const
			{
				vertexNormalXYZ.write(file);
				fprintf_s(file, " ");
				size_t size = sizeof(vertexFaceNormal)/sizeof(VertexFaceNormal);
				for(size_t i=0; i<size; ++i)
				{
					vertexFaceNormal[i].write(file);
					if(i+1<size) fprintf_s(file," ");
				}
			}
		}* vertexNormal;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertexNormal)/sizeof(VertexNormal);
			for(size_t i=0; i<size; ++i)
			{
				vertexNormal[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	PolyNormalPerVertex(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyNormalPerVertex"){}
	virtual ~PolyNormalPerVertex(){}
	/*
	Attribute to specify the normal of a vertex, either on the entire
	vertex on a per face basis.
	*/
	void setNormalPerVertex(const NormalPerVertex& npvx){fprintf_s(mFile, "setAttr \".npvx\" ");npvx.write(mFile);fprintf_s(mFile,";\n");}
	/*
	A compound attribute that corresponds to the normal of the vertex.
	It is a multi attribute and the index of the multi identifies the
	vertex that the normal applies to.
	*/
	void setVertexNormal(size_t vn_i,const NormalPerVertex::VertexNormal& vn){fprintf_s(mFile, "setAttr \".npvx.vn[%i]\" ",vn_i);vn.write(mFile);fprintf_s(mFile,";\n");}
	/*Vertex normal - XYZ.*/
	void setVertexNormalXYZ(size_t vn_i,const float3& nxyz){fprintf_s(mFile, "setAttr \".npvx.vn[%i].nxyz\" -type \"float3\" ",vn_i);nxyz.write(mFile);fprintf_s(mFile,";\n");}
	/*Vertex normal x value*/
	void setVertexNormalX(size_t vn_i,float vxnx){if(vxnx == -999) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].nxyz.vxnx\" %f;\n", vn_i,vxnx);}
	/*Vertex normal y value*/
	void setVertexNormalY(size_t vn_i,float vxny){if(vxny == -999) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].nxyz.vxny\" %f;\n", vn_i,vxny);}
	/*Vertex normal z value*/
	void setVertexNormalZ(size_t vn_i,float vxnz){if(vxnz == -999) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].nxyz.vxnz\" %f;\n", vn_i,vxnz);}
	/*
	A compound attribute that corresponds to the normal of the vertex
	attached to a particular face. It is a multi attribute and the index
	of the multi identifies the face that the normal applies to. The index
	of the parent attribute (aVertexNormal) already identifies the vertex
	that normal is being attached to.
	*/
	void setVertexFaceNormal(size_t vn_i,size_t vfnl_i,const NormalPerVertex::VertexNormal::VertexFaceNormal& vfnl){fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i]\" ",vn_i,vfnl_i);vfnl.write(mFile);fprintf_s(mFile,";\n");}
	/*VertexFace normal - XYZ.*/
	void setVertexFaceNormalXYZ(size_t vn_i,size_t vfnl_i,const float3& fnxy){fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i].fnxy\" -type \"float3\" ",vn_i,vfnl_i);fnxy.write(mFile);fprintf_s(mFile,";\n");}
	/*Vertex face normal x value*/
	void setVertexFaceNormalX(size_t vn_i,size_t vfnl_i,float vfnx){if(vfnx == -999) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnx\" %f;\n", vn_i,vfnl_i,vfnx);}
	/*Vertex face normal y value*/
	void setVertexFaceNormalY(size_t vn_i,size_t vfnl_i,float vfny){if(vfny == -999) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfny\" %f;\n", vn_i,vfnl_i,vfny);}
	/*Vertex face normal z value*/
	void setVertexFaceNormalZ(size_t vn_i,size_t vfnl_i,float vfnz){if(vfnz == -999) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnz\" %f;\n", vn_i,vfnl_i,vfnz);}
	/*OBSOLETE ATTRIBUTE.  No effect.*/
	void setNormalDeform(bool npvd){if(npvd == true) return; fprintf_s(mFile, "setAttr \".npvd\" %i;\n", npvd);}
	/*OBSOLETE ATTRIBUTE.  No effect.*/
	void setNormalDeform(const BoolID& npvd){fprintf_s(mFile,"connectAttr \"");npvd.write(mFile);fprintf_s(mFile,"\" \"%s.npvd\";\n",mName.c_str());}
	/*Attribute controls weither or not the normal to replace or add*/
	void setNormalAdd(bool npva){if(npva == false) return; fprintf_s(mFile, "setAttr \".npva\" %i;\n", npva);}
	/*Attribute controls weither or not the normal to replace or add*/
	void setNormalAdd(const BoolID& npva){fprintf_s(mFile,"connectAttr \"");npva.write(mFile);fprintf_s(mFile,"\" \"%s.npva\";\n",mName.c_str());}
	/*OBSOLETE ATTRIBUTE.  No effect.*/
	BoolID getNormalDeform(){char buffer[4096];sprintf_s (buffer, "%s.npvd",mName.c_str());return (const char*)buffer;}
	/*Attribute controls weither or not the normal to replace or add*/
	BoolID getNormalAdd(){char buffer[4096];sprintf_s (buffer, "%s.npva",mName.c_str());return (const char*)buffer;}
protected:
	PolyNormalPerVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYNORMALPERVERTEX_H__
