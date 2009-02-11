/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CONTROLPOINT_H__
#define __MayaDM_CONTROLPOINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformableShape.h"
namespace MayaDM
{
class ControlPoint : public DeformableShape
{
public:
	struct UvSet{
		string uvSetName;
		float2* uvSetPoints;
		void write(FILE* file) const
		{
			uvSetName.write(file);
			fprintf(file, " ");
			size_t size = sizeof(uvSetPoints)/sizeof(float2);
			for(size_t i=0; i<size; ++i)
			{
				uvSetPoints[i].write(file);
				fprintf(file, " ");
				if(i+1<size) fprintf(file," ");
			}
		}
	};
	struct ColorSet{
		string colorName;
		bool clamped;
		unsigned int representation;
		struct ColorSetPoints{
			float colorSetPointsR;
			float colorSetPointsG;
			float colorSetPointsB;
			float colorSetPointsA;
			void write(FILE* file) const
			{
				fprintf(file,"%f ", colorSetPointsR);
				fprintf(file,"%f ", colorSetPointsG);
				fprintf(file,"%f ", colorSetPointsB);
				fprintf(file,"%f", colorSetPointsA);
			}
		}* colorSetPoints;
		void write(FILE* file) const
		{
			colorName.write(file);
			fprintf(file, " ");
			fprintf(file,"%i ", clamped);
			fprintf(file,"%i ", representation);
			size_t size = sizeof(colorSetPoints)/sizeof(ColorSetPoints);
			for(size_t i=0; i<size; ++i)
			{
				colorSetPoints[i].write(file);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
public:
	ControlPoint():DeformableShape(){}
	ControlPoint(FILE* file,const std::string& name,const std::string& parent=""):DeformableShape(file, name, parent, "controlPoint"){}
	virtual ~ControlPoint(){}
	void setTweak(bool tw)
	{
		if(tw == false) return;
		fprintf(mFile,"\tsetAttr \".tw\" %i;\n", tw);

	}
	void setRelativeTweak(bool rtw)
	{
		if(rtw == true) return;
		fprintf(mFile,"\tsetAttr \".rtw\" %i;\n", rtw);

	}
	void setControlPoints(size_t cp_i,const double3& cp)
	{
		fprintf(mFile,"\tsetAttr \".cp[%i]\" -type \"double3\" ",cp_i);
		cp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setControlPoints(size_t cp_start,size_t cp_end,double* cp)
	{
		fprintf(mFile,"\tsetAttr \".cp[%i:%i]\" ", cp_start,cp_end);
		size_t size = (cp_end-cp_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startControlPoints(size_t cp_start,size_t cp_end)
	{
		fprintf(mFile,"\tsetAttr \".cp[%i:%i]\"",cp_start,cp_end);

	}
	void appendControlPoints(double cp)
	{
		fprintf(mFile," %f",cp);

	}
	void endControlPoints()
	{
		fprintf(mFile,";\n");

	}
	void setXValue(size_t cp_i,double xv)
	{
		if(xv == 0) return;
		fprintf(mFile,"\tsetAttr \".cp[%i].xv\" %f;\n", cp_i,xv);

	}
	void setYValue(size_t cp_i,double yv)
	{
		if(yv == 0) return;
		fprintf(mFile,"\tsetAttr \".cp[%i].yv\" %f;\n", cp_i,yv);

	}
	void setZValue(size_t cp_i,double zv)
	{
		if(zv == 0) return;
		fprintf(mFile,"\tsetAttr \".cp[%i].zv\" %f;\n", cp_i,zv);

	}
	void setUvSet(size_t uvst_i,const UvSet& uvst)
	{
		fprintf(mFile,"\tsetAttr \".uvst[%i]\" ",uvst_i);
		uvst.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvSetName(size_t uvst_i,const string& uvsn)
	{
		if(uvsn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".uvst[%i].uvsn\" -type \"string\" ",uvst_i);
		uvsn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvSetPoints(size_t uvst_i,size_t uvsp_i,const float2& uvsp)
	{
		fprintf(mFile,"\tsetAttr \".uvst[%i].uvsp[%i]\" -type \"float2\" ",uvst_i,uvsp_i);
		uvsp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvSetPoints(size_t uvst_i,size_t uvsp_start,size_t uvsp_end,float* uvsp)
	{
		fprintf(mFile,"\tsetAttr \".uvst[%i].uvsp[%i:%i]\" ", uvst_i,uvsp_start,uvsp_end);
		size_t size = (uvsp_end-uvsp_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uvsp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
    void startColorSetPoints(size_t clst_i,size_t clsp_start,size_t clsp_end)
    {
        fprintf(mFile,"\tsetAttr \".clst[%i].clsp[%i:%i]\"",clst_i,clsp_start,clsp_end);
    }
    void appendColorSetPoints(float clsp)
    {
        fprintf(mFile," %f",clsp);
    }
    void endColorSetPoints()
    {
        fprintf(mFile,";\n");
    }
	void startUvSetPoints(size_t uvst_i,size_t uvsp_start,size_t uvsp_end)
	{
		fprintf(mFile,"\tsetAttr \".uvst[%i].uvsp[%i:%i]\"",uvst_i,uvsp_start,uvsp_end);

	}
	void appendUvSetPoints(float uvsp)
	{
		fprintf(mFile," %f",uvsp);

	}
	void endUvSetPoints()
	{
		fprintf(mFile,";\n");

	}
	void setUvSetPointsU(size_t uvst_i,size_t uvsp_i,float uvpu)
	{
		if(uvpu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uvst[%i].uvsp[%i].uvpu\" %f;\n", uvst_i,uvsp_i,uvpu);

	}
	void setUvSetPointsV(size_t uvst_i,size_t uvsp_i,float uvpv)
	{
		if(uvpv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uvst[%i].uvsp[%i].uvpv\" %f;\n", uvst_i,uvsp_i,uvpv);

	}
	void setCurrentUVSet(const string& cuvs)
	{
		if(cuvs == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cuvs\" -type \"string\" ");
		cuvs.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDisplayImmediate(bool di)
	{
		if(di == false) return;
		fprintf(mFile,"\tsetAttr \".di\" %i;\n", di);

	}
	void setDisplayColors(bool dcol)
	{
		if(dcol == false) return;
		fprintf(mFile,"\tsetAttr \".dcol\" %i;\n", dcol);

	}
	void setDisplayColorChannel(const string& dcc)
	{
		if(dcc == "color") return;
		fprintf(mFile,"\tsetAttr \".dcc\" -type \"string\" ");
		dcc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCurrentColorSet(const string& ccls)
	{
		if(ccls == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ccls\" -type \"string\" ");
		ccls.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorSet(size_t clst_i,const ColorSet& clst)
	{
		fprintf(mFile,"\tsetAttr \".clst[%i]\" ",clst_i);
		clst.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorName(size_t clst_i,const string& clsn)
	{
		if(clsn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".clst[%i].clsn\" -type \"string\" ",clst_i);
		clsn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClamped(size_t clst_i,bool clam)
	{
		if(clam == false) return;
		fprintf(mFile,"\tsetAttr \".clst[%i].clam\" %i;\n", clst_i,clam);

	}
	void setRepresentation(size_t clst_i,unsigned int rprt)
	{
		if(rprt == 3) return;
		fprintf(mFile,"\tsetAttr \".clst[%i].rprt\" %i;\n", clst_i,rprt);

	}
	void setColorSetPoints(size_t clst_i,size_t clsp_i,const ColorSet::ColorSetPoints& clsp)
	{
		fprintf(mFile,"\tsetAttr \".clst[%i].clsp[%i]\" ",clst_i,clsp_i);
		clsp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorSetPointsR(size_t clst_i,size_t clsp_i,float clpr)
	{
		if(clpr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clst[%i].clsp[%i].clpr\" %f;\n", clst_i,clsp_i,clpr);

	}
	void setColorSetPointsG(size_t clst_i,size_t clsp_i,float clpg)
	{
		if(clpg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clst[%i].clsp[%i].clpg\" %f;\n", clst_i,clsp_i,clpg);

	}
	void setColorSetPointsB(size_t clst_i,size_t clsp_i,float clpb)
	{
		if(clpb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clst[%i].clsp[%i].clpb\" %f;\n", clst_i,clsp_i,clpb);

	}
	void setColorSetPointsA(size_t clst_i,size_t clsp_i,float clpa)
	{
		if(clpa == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clst[%i].clsp[%i].clpa\" %f;\n", clst_i,clsp_i,clpa);

	}
	void getTweak()
	{
		fprintf(mFile,"\"%s.tw\"",mName.c_str());

	}
	void getRelativeTweak()
	{
		fprintf(mFile,"\"%s.rtw\"",mName.c_str());

	}
	void getControlPoints(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i]\"",mName.c_str(),cp_i);

	}
	void getXValue(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i].xv\"",mName.c_str(),cp_i);

	}
	void getYValue(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i].yv\"",mName.c_str(),cp_i);

	}
	void getZValue(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i].zv\"",mName.c_str(),cp_i);

	}
	void getWeights(size_t wt_i)
	{
		fprintf(mFile,"\"%s.wt[%i]\"",mName.c_str(),wt_i);

	}
	void getTweakLocation()
	{
		fprintf(mFile,"\"%s.twl\"",mName.c_str());

	}
	void getBlindDataNodes(size_t bn_i)
	{
		fprintf(mFile,"\"%s.bn[%i]\"",mName.c_str(),bn_i);

	}
	void getUvSet(size_t uvst_i)
	{
		fprintf(mFile,"\"%s.uvst[%i]\"",mName.c_str(),uvst_i);

	}
	void getUvSetName(size_t uvst_i)
	{
		fprintf(mFile,"\"%s.uvst[%i].uvsn\"",mName.c_str(),uvst_i);

	}
	void getUvSetPoints(size_t uvst_i,size_t uvsp_i)
	{
		fprintf(mFile,"\"%s.uvst[%i].uvsp[%i]\"",mName.c_str(),uvst_i,uvsp_i);

	}
	void getUvSetPointsU(size_t uvst_i,size_t uvsp_i)
	{
		fprintf(mFile,"\"%s.uvst[%i].uvsp[%i].uvpu\"",mName.c_str(),uvst_i,uvsp_i);

	}
	void getUvSetPointsV(size_t uvst_i,size_t uvsp_i)
	{
		fprintf(mFile,"\"%s.uvst[%i].uvsp[%i].uvpv\"",mName.c_str(),uvst_i,uvsp_i);

	}
	void getUvSetTweakLocation(size_t uvst_i)
	{
		fprintf(mFile,"\"%s.uvst[%i].uvtw\"",mName.c_str(),uvst_i);

	}
	void getCurrentUVSet()
	{
		fprintf(mFile,"\"%s.cuvs\"",mName.c_str());

	}
	void getDisplayImmediate()
	{
		fprintf(mFile,"\"%s.di\"",mName.c_str());

	}
	void getDisplayColors()
	{
		fprintf(mFile,"\"%s.dcol\"",mName.c_str());

	}
	void getDisplayColorChannel()
	{
		fprintf(mFile,"\"%s.dcc\"",mName.c_str());

	}
	void getCurrentColorSet()
	{
		fprintf(mFile,"\"%s.ccls\"",mName.c_str());

	}
	void getColorSet(size_t clst_i)
	{
		fprintf(mFile,"\"%s.clst[%i]\"",mName.c_str(),clst_i);

	}
	void getColorName(size_t clst_i)
	{
		fprintf(mFile,"\"%s.clst[%i].clsn\"",mName.c_str(),clst_i);

	}
	void getClamped(size_t clst_i)
	{
		fprintf(mFile,"\"%s.clst[%i].clam\"",mName.c_str(),clst_i);

	}
	void getRepresentation(size_t clst_i)
	{
		fprintf(mFile,"\"%s.clst[%i].rprt\"",mName.c_str(),clst_i);

	}
	void getColorSetPoints(size_t clst_i,size_t clsp_i)
	{
		fprintf(mFile,"\"%s.clst[%i].clsp[%i]\"",mName.c_str(),clst_i,clsp_i);

	}
	void getColorSetPointsR(size_t clst_i,size_t clsp_i)
	{
		fprintf(mFile,"\"%s.clst[%i].clsp[%i].clpr\"",mName.c_str(),clst_i,clsp_i);

	}
	void getColorSetPointsG(size_t clst_i,size_t clsp_i)
	{
		fprintf(mFile,"\"%s.clst[%i].clsp[%i].clpg\"",mName.c_str(),clst_i,clsp_i);

	}
	void getColorSetPointsB(size_t clst_i,size_t clsp_i)
	{
		fprintf(mFile,"\"%s.clst[%i].clsp[%i].clpb\"",mName.c_str(),clst_i,clsp_i);

	}
	void getColorSetPointsA(size_t clst_i,size_t clsp_i)
	{
		fprintf(mFile,"\"%s.clst[%i].clsp[%i].clpa\"",mName.c_str(),clst_i,clsp_i);

	}
protected:
	ControlPoint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DeformableShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CONTROLPOINT_H__
