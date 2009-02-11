/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HAIRTUBESHADER_H__
#define __MayaDM_HAIRTUBESHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMReflect.h"
namespace MayaDM
{
class HairTubeShader : public Reflect
{
public:
	struct ColorScale{
		float colorScale_Position;
		float3 colorScale_Color;
		unsigned int colorScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", colorScale_Position);
			colorScale_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", colorScale_Interp);
		}
	};
public:
	HairTubeShader():Reflect(){}
	HairTubeShader(FILE* file,const std::string& name,const std::string& parent=""):Reflect(file, name, parent, "hairTubeShader"){}
	virtual ~HairTubeShader(){}
	void setTubeDirection(unsigned int tdr)
	{
		if(tdr == 0) return;
		fprintf(mFile,"\tsetAttr \".tdr\" %i;\n", tdr);

	}
	void setColorScale(size_t cls_i,const ColorScale& cls)
	{
		fprintf(mFile,"\tsetAttr \".cls[%i]\" ",cls_i);
		cls.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorScale_Position(size_t cls_i,float clsp)
	{
		if(clsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cls[%i].clsp\" %f;\n", cls_i,clsp);

	}
	void setColorScale_Color(size_t cls_i,const float3& clsc)
	{
		fprintf(mFile,"\tsetAttr \".cls[%i].clsc\" -type \"float3\" ",cls_i);
		clsc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorScale_ColorR(size_t cls_i,float clscr)
	{
		if(clscr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cls[%i].clsc.clscr\" %f;\n", cls_i,clscr);

	}
	void setColorScale_ColorG(size_t cls_i,float clscg)
	{
		if(clscg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cls[%i].clsc.clscg\" %f;\n", cls_i,clscg);

	}
	void setColorScale_ColorB(size_t cls_i,float clscb)
	{
		if(clscb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cls[%i].clsc.clscb\" %f;\n", cls_i,clscb);

	}
	void setColorScale_Interp(size_t cls_i,unsigned int clsi)
	{
		if(clsi == 0) return;
		fprintf(mFile,"\tsetAttr \".cls[%i].clsi\" %i;\n", cls_i,clsi);

	}
	void setSpecularPower(float sp)
	{
		if(sp == 20.0) return;
		fprintf(mFile,"\tsetAttr \".sp\" %f;\n", sp);

	}
	void setSpecularShift(float ssh)
	{
		if(ssh == 5.0) return;
		fprintf(mFile,"\tsetAttr \".ssh\" %f;\n", ssh);

	}
	void setScatterPower(float scp)
	{
		if(scp == 5.0) return;
		fprintf(mFile,"\tsetAttr \".scp\" %f;\n", scp);

	}
	void setScatter(float sct)
	{
		if(sct == 0.2) return;
		fprintf(mFile,"\tsetAttr \".sct\" %f;\n", sct);

	}
	void setMiReflectionBlur(float mircb)
	{
		if(mircb == 0) return;
		fprintf(mFile,"\tsetAttr \".mircb\" %f;\n", mircb);

	}
	void setMiReflectionRays(short mircr)
	{
		if(mircr == 1) return;
		fprintf(mFile,"\tsetAttr \".mircr\" %i;\n", mircr);

	}
	void setMiAngle(float mia)
	{
		if(mia == 0) return;
		fprintf(mFile,"\tsetAttr \".mia\" %f;\n", mia);

	}
	void setMiSpreadX(float misx)
	{
		if(misx == 10) return;
		fprintf(mFile,"\tsetAttr \".misx\" %f;\n", misx);

	}
	void setMiSpreadY(float misy)
	{
		if(misy == 5) return;
		fprintf(mFile,"\tsetAttr \".misy\" %f;\n", misy);

	}
	void setMiSpecularColor(const float3& misc)
	{
		fprintf(mFile,"\tsetAttr \".misc\" -type \"float3\" ");
		misc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiSpecularColorR(float miscr)
	{
		if(miscr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscr\" %f;\n", miscr);

	}
	void setMiSpecularColorG(float miscg)
	{
		if(miscg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscg\" %f;\n", miscg);

	}
	void setMiSpecularColorB(float miscb)
	{
		if(miscb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscb\" %f;\n", miscb);

	}
	void setMiReflectivity(float mirf)
	{
		if(mirf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mirf\" %f;\n", mirf);

	}
	void getTangentUCamera()
	{
		fprintf(mFile,"\"%s.utan\"",mName.c_str());

	}
	void getTangentUCameraX()
	{
		fprintf(mFile,"\"%s.utan.utnx\"",mName.c_str());

	}
	void getTangentUCameraY()
	{
		fprintf(mFile,"\"%s.utan.utny\"",mName.c_str());

	}
	void getTangentUCameraZ()
	{
		fprintf(mFile,"\"%s.utan.utnz\"",mName.c_str());

	}
	void getTangentVCamera()
	{
		fprintf(mFile,"\"%s.vtan\"",mName.c_str());

	}
	void getTangentVCameraX()
	{
		fprintf(mFile,"\"%s.vtan.vtnx\"",mName.c_str());

	}
	void getTangentVCameraY()
	{
		fprintf(mFile,"\"%s.vtan.vtny\"",mName.c_str());

	}
	void getTangentVCameraZ()
	{
		fprintf(mFile,"\"%s.vtan.vtnz\"",mName.c_str());

	}
	void getUvCoord()
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());

	}
	void getUCoord()
	{
		fprintf(mFile,"\"%s.uv.uvu\"",mName.c_str());

	}
	void getVCoord()
	{
		fprintf(mFile,"\"%s.uv.uvv\"",mName.c_str());

	}
	void getTubeDirection()
	{
		fprintf(mFile,"\"%s.tdr\"",mName.c_str());

	}
	void getColorScale(size_t cls_i)
	{
		fprintf(mFile,"\"%s.cls[%i]\"",mName.c_str(),cls_i);

	}
	void getColorScale_Position(size_t cls_i)
	{
		fprintf(mFile,"\"%s.cls[%i].clsp\"",mName.c_str(),cls_i);

	}
	void getColorScale_Color(size_t cls_i)
	{
		fprintf(mFile,"\"%s.cls[%i].clsc\"",mName.c_str(),cls_i);

	}
	void getColorScale_ColorR(size_t cls_i)
	{
		fprintf(mFile,"\"%s.cls[%i].clsc.clscr\"",mName.c_str(),cls_i);

	}
	void getColorScale_ColorG(size_t cls_i)
	{
		fprintf(mFile,"\"%s.cls[%i].clsc.clscg\"",mName.c_str(),cls_i);

	}
	void getColorScale_ColorB(size_t cls_i)
	{
		fprintf(mFile,"\"%s.cls[%i].clsc.clscb\"",mName.c_str(),cls_i);

	}
	void getColorScale_Interp(size_t cls_i)
	{
		fprintf(mFile,"\"%s.cls[%i].clsi\"",mName.c_str(),cls_i);

	}
	void getSpecularPower()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getSpecularShift()
	{
		fprintf(mFile,"\"%s.ssh\"",mName.c_str());

	}
	void getScatterPower()
	{
		fprintf(mFile,"\"%s.scp\"",mName.c_str());

	}
	void getScatter()
	{
		fprintf(mFile,"\"%s.sct\"",mName.c_str());

	}
	void getMiReflectionBlur()
	{
		fprintf(mFile,"\"%s.mircb\"",mName.c_str());

	}
	void getMiReflectionRays()
	{
		fprintf(mFile,"\"%s.mircr\"",mName.c_str());

	}
	void getMiAngle()
	{
		fprintf(mFile,"\"%s.mia\"",mName.c_str());

	}
	void getMiSpreadX()
	{
		fprintf(mFile,"\"%s.misx\"",mName.c_str());

	}
	void getMiSpreadY()
	{
		fprintf(mFile,"\"%s.misy\"",mName.c_str());

	}
	void getMiSpecularColor()
	{
		fprintf(mFile,"\"%s.misc\"",mName.c_str());

	}
	void getMiSpecularColorR()
	{
		fprintf(mFile,"\"%s.misc.miscr\"",mName.c_str());

	}
	void getMiSpecularColorG()
	{
		fprintf(mFile,"\"%s.misc.miscg\"",mName.c_str());

	}
	void getMiSpecularColorB()
	{
		fprintf(mFile,"\"%s.misc.miscb\"",mName.c_str());

	}
	void getMiReflectivity()
	{
		fprintf(mFile,"\"%s.mirf\"",mName.c_str());

	}
protected:
	HairTubeShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Reflect(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HAIRTUBESHADER_H__
