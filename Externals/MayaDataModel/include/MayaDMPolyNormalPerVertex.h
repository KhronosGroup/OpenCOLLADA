/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class PolyNormalPerVertex : public PolyModifier
{
public:
	struct NormalPerVertex{
		struct VertexNormal{
			float3 vertexNormalXYZ;
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
				fprintf(file, " ");
				size_t size = sizeof(vertexFaceNormal)/sizeof(VertexFaceNormal);
				for(size_t i=0; i<size; ++i)
				{
					vertexFaceNormal[i].write(file);
					if(i+1<size) fprintf(file," ");
				}
			}
		}* vertexNormal;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertexNormal)/sizeof(VertexNormal);
			for(size_t i=0; i<size; ++i)
			{
				vertexNormal[i].write(file);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
public:
	PolyNormalPerVertex():PolyModifier(){}
	PolyNormalPerVertex(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyNormalPerVertex"){}
	virtual ~PolyNormalPerVertex(){}
	void setNormalPerVertex(const NormalPerVertex& npvx)
	{
		fprintf(mFile,"\tsetAttr \".npvx\" ");
		npvx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexNormal(size_t vn_i,const NormalPerVertex::VertexNormal& vn)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i]\" ",vn_i);
		vn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexNormalXYZ(size_t vn_i,const float3& nxyz)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].nxyz\" -type \"float3\" ",vn_i);
		nxyz.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexNormalX(size_t vn_i,float vxnx)
	{
		if(vxnx == -999) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].nxyz.vxnx\" %f;\n", vn_i,vxnx);

	}
	void setVertexNormalY(size_t vn_i,float vxny)
	{
		if(vxny == -999) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].nxyz.vxny\" %f;\n", vn_i,vxny);

	}
	void setVertexNormalZ(size_t vn_i,float vxnz)
	{
		if(vxnz == -999) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].nxyz.vxnz\" %f;\n", vn_i,vxnz);

	}
	void setVertexFaceNormal(size_t vn_i,size_t vfnl_i,const NormalPerVertex::VertexNormal::VertexFaceNormal& vfnl)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i]\" ",vn_i,vfnl_i);
		vfnl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexFaceNormalXYZ(size_t vn_i,size_t vfnl_i,const float3& fnxy)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i].fnxy\" -type \"float3\" ",vn_i,vfnl_i);
		fnxy.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexFaceNormalX(size_t vn_i,size_t vfnl_i,float vfnx)
	{
		if(vfnx == -999) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnx\" %f;\n", vn_i,vfnl_i,vfnx);

	}
	void setVertexFaceNormalY(size_t vn_i,size_t vfnl_i,float vfny)
	{
		if(vfny == -999) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfny\" %f;\n", vn_i,vfnl_i,vfny);

	}
	void setVertexFaceNormalZ(size_t vn_i,size_t vfnl_i,float vfnz)
	{
		if(vfnz == -999) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnz\" %f;\n", vn_i,vfnl_i,vfnz);

	}
	void setNormalDeform(bool npvd)
	{
		if(npvd == true) return;
		fprintf(mFile,"\tsetAttr \".npvd\" %i;\n", npvd);

	}
	void setNormalAdd(bool npva)
	{
		if(npva == false) return;
		fprintf(mFile,"\tsetAttr \".npva\" %i;\n", npva);

	}
	void getNormalDeform()
	{
		fprintf(mFile,"\"%s.npvd\"",mName.c_str());

	}
	void getNormalAdd()
	{
		fprintf(mFile,"\"%s.npva\"",mName.c_str());

	}
protected:
	PolyNormalPerVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:PolyModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYNORMALPERVERTEX_H__
