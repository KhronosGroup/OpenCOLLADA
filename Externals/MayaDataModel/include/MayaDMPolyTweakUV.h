/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTWEAKUV_H__
#define __MayaDM_POLYTWEAKUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyTweakUV : public PolyModifier
{
public:
	struct NewUV{
		int faceId;
		int vertexId;
		float newUValue;
		float newVValue;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", faceId);
			fprintf(file,"%i ", vertexId);
			fprintf(file,"%f ", newUValue);
			fprintf(file,"%f", newVValue);
		}
	};
public:
	PolyTweakUV():PolyModifier(){}
	PolyTweakUV(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:PolyModifier(file, name, parent, "polyTweakUV", create){}
	virtual ~PolyTweakUV(){}
	void setUvTweak(size_t uvtk_i,const float2& uvtk)
	{
		if(uvtk == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".uvtk[%i]\" -type \"float2\" ",uvtk_i);
		uvtk.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvTweak(size_t uvtk_start,size_t uvtk_end,float* uvtk)
	{
		fprintf(mFile,"\tsetAttr \".uvtk[%i:%i]\" ", uvtk_start,uvtk_end);
		size_t size = (uvtk_end-uvtk_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uvtk[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startUvTweak(size_t uvtk_start,size_t uvtk_end)const
	{
		fprintf(mFile,"\tsetAttr \".uvtk[%i:%i]\"",uvtk_start,uvtk_end);

	}
	void appendUvTweak(float uvtk)const
	{
		fprintf(mFile," %f",uvtk);

	}
	void endUvTweak()const
	{
		fprintf(mFile,";\n");

	}
	void setUvTweakU(size_t uvtk_i,float tu)
	{
		if(tu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uvtk[%i].tu\" %f;\n", uvtk_i,tu);

	}
	void setUvTweakV(size_t uvtk_i,float tv)
	{
		if(tv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uvtk[%i].tv\" %f;\n", uvtk_i,tv);

	}
	void setNewUV(size_t nuv_i,const NewUV& nuv)
	{
		fprintf(mFile,"\tsetAttr \".nuv[%i]\" ",nuv_i);
		nuv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFaceId(size_t nuv_i,int fid)
	{
		if(fid == 0) return;
		fprintf(mFile,"\tsetAttr \".nuv[%i].fid\" %i;\n", nuv_i,fid);

	}
	void setVertexId(size_t nuv_i,int vid)
	{
		if(vid == 0) return;
		fprintf(mFile,"\tsetAttr \".nuv[%i].vid\" %i;\n", nuv_i,vid);

	}
	void setNewUValue(size_t nuv_i,float nu)
	{
		if(nu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".nuv[%i].nu\" %f;\n", nuv_i,nu);

	}
	void setNewVValue(size_t nuv_i,float nv)
	{
		if(nv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".nuv[%i].nv\" %f;\n", nuv_i,nv);

	}
	void setUvSetName(const string& uvs)
	{
		if(uvs == "NULL") return;
		fprintf(mFile,"\tsetAttr \".uvs\" -type \"string\" ");
		uvs.write(mFile);
		fprintf(mFile,";\n");

	}
	void getUvTweak(size_t uvtk_i)const
	{
		fprintf(mFile,"\"%s.uvtk[%i]\"",mName.c_str(),uvtk_i);

	}
	void getUvTweakU(size_t uvtk_i)const
	{
		fprintf(mFile,"\"%s.uvtk[%i].tu\"",mName.c_str(),uvtk_i);

	}
	void getUvTweakV(size_t uvtk_i)const
	{
		fprintf(mFile,"\"%s.uvtk[%i].tv\"",mName.c_str(),uvtk_i);

	}
	void getNewUV(size_t nuv_i)const
	{
		fprintf(mFile,"\"%s.nuv[%i]\"",mName.c_str(),nuv_i);

	}
	void getFaceId(size_t nuv_i)const
	{
		fprintf(mFile,"\"%s.nuv[%i].fid\"",mName.c_str(),nuv_i);

	}
	void getVertexId(size_t nuv_i)const
	{
		fprintf(mFile,"\"%s.nuv[%i].vid\"",mName.c_str(),nuv_i);

	}
	void getNewUValue(size_t nuv_i)const
	{
		fprintf(mFile,"\"%s.nuv[%i].nu\"",mName.c_str(),nuv_i);

	}
	void getNewVValue(size_t nuv_i)const
	{
		fprintf(mFile,"\"%s.nuv[%i].nv\"",mName.c_str(),nuv_i);

	}
	void getUvSetName()const
	{
		fprintf(mFile,"\"%s.uvs\"",mName.c_str());

	}
protected:
	PolyTweakUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:PolyModifier(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYTWEAKUV_H__
