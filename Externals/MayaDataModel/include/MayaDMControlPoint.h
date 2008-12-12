/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
<p><pre>
    Description:
        Abstract class for objects that contain control/mesh/lattice points.

</pre></p>
*/
class ControlPoint : public DeformableShape
{
public:
	/*
	Compound attribute that corresponds to uv set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aUVSetName)
	*/
	struct UvSet{
		string uvSetName;
		float2* uvSetPoints;
		void write(FILE* file) const
		{
			uvSetName.write(file);
			fprintf_s(file, " ");
			size_t size = sizeof(uvSetPoints)/sizeof(float2);
			for(size_t i=0; i<size; ++i)
			{
				uvSetPoints[i].write(file);
				fprintf_s(file, " ");
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*
	Compound attribute that corresponds to color set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aColorSetName)
	*/
	struct ColorSet{
		string colorName;
		bool clamped;
		unsigned int representation;
		/*
		This is a color set color point
		Red value of a color point
		*/
		struct ColorSetPoints{
			float colorSetPointsR;
			float colorSetPointsG;
			float colorSetPointsB;
			float colorSetPointsA;
			void write(FILE* file) const
			{
				fprintf_s(file,"%f ", colorSetPointsR);
				fprintf_s(file,"%f ", colorSetPointsG);
				fprintf_s(file,"%f ", colorSetPointsB);
				fprintf_s(file,"%f", colorSetPointsA);
			}
		}* colorSetPoints;
		void write(FILE* file) const
		{
			colorName.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i ", clamped);
			fprintf_s(file,"%i ", representation);
			size_t size = sizeof(colorSetPoints)/sizeof(ColorSetPoints);
			for(size_t i=0; i<size; ++i)
			{
				colorSetPoints[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	ControlPoint(FILE* file,const std::string& name,const std::string& parent=""):DeformableShape(file, name, parent, "controlPoint"){}
	virtual ~ControlPoint(){}
	/*
	If true, the object has history and the control point attribute
	values are tweaks, not the actual values.
	*/
	void setTweak(bool tw){if(tw == false) return; fprintf_s(mFile, "setAttr \".tw\" %i;\n", tw);}
	/*
	If true, the object has history and the control point attribute
	values are tweaks, not the actual values.
	*/
	void setTweak(const BoolID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tw\";\n",mName.c_str());}
	/*If set, the tweaks are relative, otherwise absolute.*/
	void setRelativeTweak(bool rtw){if(rtw == true) return; fprintf_s(mFile, "setAttr \".rtw\" %i;\n", rtw);}
	/*If set, the tweaks are relative, otherwise absolute.*/
	void setRelativeTweak(const BoolID& rtw){fprintf_s(mFile,"connectAttr \"");rtw.write(mFile);fprintf_s(mFile,"\" \"%s.rtw\";\n",mName.c_str());}
	/*control points for the derived shapes*/
	void setControlPoints(size_t cp_i,const double3& cp){fprintf_s(mFile, "setAttr \".cp[%i]\" -type \"double3\" ",cp_i);cp.write(mFile);fprintf_s(mFile,";\n");}
	/*control points for the derived shapes*/
	void setControlPoints(size_t cp_start,size_t cp_end,double* cp){fprintf_s(mFile,"setAttr \".cp[%i:%i]\" ", cp_start,cp_end);size_t size = (cp_end-cp_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",cp[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*control points for the derived shapes*/
	void setControlPoints(size_t cp_i,const Double3ID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i]\";\n",mName.c_str(),cp_i);}
	/*X value of a control point*/
	void setXValue(size_t cp_i,double xv){if(xv == 0) return; fprintf_s(mFile, "setAttr \".cp[%i].xv\" %f;\n", cp_i,xv);}
	/*X value of a control point*/
	void setXValue(size_t cp_i,const DoubleID& xv){fprintf_s(mFile,"connectAttr \"");xv.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i].xv\";\n",mName.c_str(),cp_i);}
	/*Y value of a control point*/
	void setYValue(size_t cp_i,double yv){if(yv == 0) return; fprintf_s(mFile, "setAttr \".cp[%i].yv\" %f;\n", cp_i,yv);}
	/*Y value of a control point*/
	void setYValue(size_t cp_i,const DoubleID& yv){fprintf_s(mFile,"connectAttr \"");yv.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i].yv\";\n",mName.c_str(),cp_i);}
	/*Z value of a control point*/
	void setZValue(size_t cp_i,double zv){if(zv == 0) return; fprintf_s(mFile, "setAttr \".cp[%i].zv\" %f;\n", cp_i,zv);}
	/*Z value of a control point*/
	void setZValue(size_t cp_i,const DoubleID& zv){fprintf_s(mFile,"connectAttr \"");zv.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i].zv\";\n",mName.c_str(),cp_i);}
	/*CV weights values for nurbs, else unused*/
	void setWeights(size_t wt_i,const DoubleID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.wt[%i]\";\n",mName.c_str(),wt_i);}
	/*
	Compound attribute that corresponds to uv set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aUVSetName)
	*/
	void setUvSet(size_t uvst_i,const UvSet& uvst){fprintf_s(mFile, "setAttr \".uvst[%i]\" ",uvst_i);uvst.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Compound attribute that corresponds to uv set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aUVSetName)
	*/
	void setUvSet(size_t uvst_i,const UvSetID& uvst){fprintf_s(mFile,"connectAttr \"");uvst.write(mFile);fprintf_s(mFile,"\" \"%s.uvst[%i]\";\n",mName.c_str(),uvst_i);}
	/*
	This is a string which identifies a given uv set.
	If an entry for a name exist, the name cannot
	be an empty string
	*/
	void setUvSetName(size_t uvst_i,const string& uvsn){if(uvsn == "NULL") return; fprintf_s(mFile, "setAttr \".uvst[%i].uvsn\" -type \"string\" ",uvst_i);uvsn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is a string which identifies a given uv set.
	If an entry for a name exist, the name cannot
	be an empty string
	*/
	void setUvSetName(size_t uvst_i,const StringID& uvsn){fprintf_s(mFile,"connectAttr \"");uvsn.write(mFile);fprintf_s(mFile,"\" \"%s.uvst[%i].uvsn\";\n",mName.c_str(),uvst_i);}
	/*This is a uvset uv point*/
	void setUvSetPoints(size_t uvst_i,size_t uvsp_i,const float2& uvsp){fprintf_s(mFile, "setAttr \".uvst[%i].uvsp[%i]\" -type \"float2\" ",uvst_i,uvsp_i);uvsp.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a uvset uv point*/
	void setUvSetPoints(size_t uvst_i,size_t uvsp_start,size_t uvsp_end,float* uvsp){fprintf_s(mFile,"setAttr \".uvst[%i].uvsp[%i:%i]\" ", uvst_i,uvsp_start,uvsp_end);size_t size = (uvsp_end-uvsp_start)*2+2;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",uvsp[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*This is a uvset uv point*/
	void setUvSetPoints(size_t uvst_i,size_t uvsp_i,const Float2ID& uvsp){fprintf_s(mFile,"connectAttr \"");uvsp.write(mFile);fprintf_s(mFile,"\" \"%s.uvst[%i].uvsp[%i]\";\n",mName.c_str(),uvst_i,uvsp_i);}
	/*U value of a uvset uv point*/
	void setUvSetPointsU(size_t uvst_i,size_t uvsp_i,float uvpu){if(uvpu == 0.0) return; fprintf_s(mFile, "setAttr \".uvst[%i].uvsp[%i].uvpu\" %f;\n", uvst_i,uvsp_i,uvpu);}
	/*U value of a uvset uv point*/
	void setUvSetPointsU(size_t uvst_i,size_t uvsp_i,const FloatID& uvpu){fprintf_s(mFile,"connectAttr \"");uvpu.write(mFile);fprintf_s(mFile,"\" \"%s.uvst[%i].uvsp[%i].uvpu\";\n",mName.c_str(),uvst_i,uvsp_i);}
	/*V value of a uvset uv point*/
	void setUvSetPointsV(size_t uvst_i,size_t uvsp_i,float uvpv){if(uvpv == 0.0) return; fprintf_s(mFile, "setAttr \".uvst[%i].uvsp[%i].uvpv\" %f;\n", uvst_i,uvsp_i,uvpv);}
	/*V value of a uvset uv point*/
	void setUvSetPointsV(size_t uvst_i,size_t uvsp_i,const FloatID& uvpv){fprintf_s(mFile,"connectAttr \"");uvpv.write(mFile);fprintf_s(mFile,"\" \"%s.uvst[%i].uvsp[%i].uvpv\";\n",mName.c_str(),uvst_i,uvsp_i);}
	/*
	This is a string which identifies the "current" uv
	set, or the "working" uv set
	*/
	void setCurrentUVSet(const string& cuvs){if(cuvs == "NULL") return; fprintf_s(mFile, "setAttr \".cuvs\" -type \"string\" ");cuvs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is a string which identifies the "current" uv
	set, or the "working" uv set
	*/
	void setCurrentUVSet(const StringID& cuvs){fprintf_s(mFile,"connectAttr \"");cuvs.write(mFile);fprintf_s(mFile,"\" \"%s.cuvs\";\n",mName.c_str());}
	/*
	Turns on immediate drawing, which is efficient for animated shapes.
	For static shapes, this control should be left to its default value
	(false) which will use the fast vertex buffered mode of drawing.
	*/
	void setDisplayImmediate(bool di){if(di == false) return; fprintf_s(mFile, "setAttr \".di\" %i;\n", di);}
	/*
	Turns on immediate drawing, which is efficient for animated shapes.
	For static shapes, this control should be left to its default value
	(false) which will use the fast vertex buffered mode of drawing.
	*/
	void setDisplayImmediate(const BoolID& di){fprintf_s(mFile,"connectAttr \"");di.write(mFile);fprintf_s(mFile,"\" \"%s.di\";\n",mName.c_str());}
	/*Controls explicit color per vertex display.*/
	void setDisplayColors(bool dcol){if(dcol == false) return; fprintf_s(mFile, "setAttr \".dcol\" %i;\n", dcol);}
	/*Controls explicit color per vertex display.*/
	void setDisplayColors(const BoolID& dcol){fprintf_s(mFile,"connectAttr \"");dcol.write(mFile);fprintf_s(mFile,"\" \"%s.dcol\";\n",mName.c_str());}
	/*Controls explicit color channel for CPV display.*/
	void setDisplayColorChannel(const string& dcc){if(dcc == "color") return; fprintf_s(mFile, "setAttr \".dcc\" -type \"string\" ");dcc.write(mFile);fprintf_s(mFile,";\n");}
	/*Controls explicit color channel for CPV display.*/
	void setDisplayColorChannel(const StringID& dcc){fprintf_s(mFile,"connectAttr \"");dcc.write(mFile);fprintf_s(mFile,"\" \"%s.dcc\";\n",mName.c_str());}
	/*
	This is a string which identifies the "current" color
	set, or the "working" color set
	*/
	void setCurrentColorSet(const string& ccls){if(ccls == "NULL") return; fprintf_s(mFile, "setAttr \".ccls\" -type \"string\" ");ccls.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is a string which identifies the "current" color
	set, or the "working" color set
	*/
	void setCurrentColorSet(const StringID& ccls){fprintf_s(mFile,"connectAttr \"");ccls.write(mFile);fprintf_s(mFile,"\" \"%s.ccls\";\n",mName.c_str());}
	/*
	Compound attribute that corresponds to color set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aColorSetName)
	*/
	void setColorSet(size_t clst_i,const ColorSet& clst){fprintf_s(mFile, "setAttr \".clst[%i]\" ",clst_i);clst.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Compound attribute that corresponds to color set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aColorSetName)
	*/
	void setColorSet(size_t clst_i,const ColorSetID& clst){fprintf_s(mFile,"connectAttr \"");clst.write(mFile);fprintf_s(mFile,"\" \"%s.clst[%i]\";\n",mName.c_str(),clst_i);}
	/*
	This is a string which identifies a given color set.
	If an entry for a name exist, the name cannot
	be an empty string
	*/
	void setColorName(size_t clst_i,const string& clsn){if(clsn == "NULL") return; fprintf_s(mFile, "setAttr \".clst[%i].clsn\" -type \"string\" ",clst_i);clsn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is a string which identifies a given color set.
	If an entry for a name exist, the name cannot
	be an empty string
	*/
	void setColorName(size_t clst_i,const StringID& clsn){fprintf_s(mFile,"connectAttr \"");clsn.write(mFile);fprintf_s(mFile,"\" \"%s.clst[%i].clsn\";\n",mName.c_str(),clst_i);}
	/*This tells if all the color values should be clamped in 0 to 1 range*/
	void setClamped(size_t clst_i,bool clam){if(clam == false) return; fprintf_s(mFile, "setAttr \".clst[%i].clam\" %i;\n", clst_i,clam);}
	/*This tells if all the color values should be clamped in 0 to 1 range*/
	void setClamped(size_t clst_i,const BoolID& clam){fprintf_s(mFile,"connectAttr \"");clam.write(mFile);fprintf_s(mFile,"\" \"%s.clst[%i].clam\";\n",mName.c_str(),clst_i);}
	/*This identifies both the number of channels and the type of channels*/
	void setRepresentation(size_t clst_i,unsigned int rprt){if(rprt == 3) return; fprintf_s(mFile, "setAttr \".clst[%i].rprt\" %i;\n", clst_i,rprt);}
	/*This identifies both the number of channels and the type of channels*/
	void setRepresentation(size_t clst_i,const UnsignedintID& rprt){fprintf_s(mFile,"connectAttr \"");rprt.write(mFile);fprintf_s(mFile,"\" \"%s.clst[%i].rprt\";\n",mName.c_str(),clst_i);}
	/*
	This is a color set color point
	Red value of a color point
	*/
	void setColorSetPoints(size_t clst_i,size_t clsp_i,const ColorSet::ColorSetPoints& clsp){fprintf_s(mFile, "setAttr \".clst[%i].clsp[%i]\" ",clst_i,clsp_i);clsp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is a color set color point
	Red value of a color point
	*/
	void setColorSetPoints(size_t clst_i,size_t clsp_i,const ColorSetPointsID& clsp){fprintf_s(mFile,"connectAttr \"");clsp.write(mFile);fprintf_s(mFile,"\" \"%s.clst[%i].clsp[%i]\";\n",mName.c_str(),clst_i,clsp_i);}
	/*Red value of a color point*/
	void setColorSetPointsR(size_t clst_i,size_t clsp_i,float clpr){if(clpr == 0.0) return; fprintf_s(mFile, "setAttr \".clst[%i].clsp[%i].clpr\" %f;\n", clst_i,clsp_i,clpr);}
	/*Red value of a color point*/
	void setColorSetPointsR(size_t clst_i,size_t clsp_i,const FloatID& clpr){fprintf_s(mFile,"connectAttr \"");clpr.write(mFile);fprintf_s(mFile,"\" \"%s.clst[%i].clsp[%i].clpr\";\n",mName.c_str(),clst_i,clsp_i);}
	/*Green value of a color point*/
	void setColorSetPointsG(size_t clst_i,size_t clsp_i,float clpg){if(clpg == 0.0) return; fprintf_s(mFile, "setAttr \".clst[%i].clsp[%i].clpg\" %f;\n", clst_i,clsp_i,clpg);}
	/*Green value of a color point*/
	void setColorSetPointsG(size_t clst_i,size_t clsp_i,const FloatID& clpg){fprintf_s(mFile,"connectAttr \"");clpg.write(mFile);fprintf_s(mFile,"\" \"%s.clst[%i].clsp[%i].clpg\";\n",mName.c_str(),clst_i,clsp_i);}
	/*Blue value of a color point*/
	void setColorSetPointsB(size_t clst_i,size_t clsp_i,float clpb){if(clpb == 0.0) return; fprintf_s(mFile, "setAttr \".clst[%i].clsp[%i].clpb\" %f;\n", clst_i,clsp_i,clpb);}
	/*Blue value of a color point*/
	void setColorSetPointsB(size_t clst_i,size_t clsp_i,const FloatID& clpb){fprintf_s(mFile,"connectAttr \"");clpb.write(mFile);fprintf_s(mFile,"\" \"%s.clst[%i].clsp[%i].clpb\";\n",mName.c_str(),clst_i,clsp_i);}
	/*Alpha value of a color point*/
	void setColorSetPointsA(size_t clst_i,size_t clsp_i,float clpa){if(clpa == 0.0) return; fprintf_s(mFile, "setAttr \".clst[%i].clsp[%i].clpa\" %f;\n", clst_i,clsp_i,clpa);}
	/*Alpha value of a color point*/
	void setColorSetPointsA(size_t clst_i,size_t clsp_i,const FloatID& clpa){fprintf_s(mFile,"connectAttr \"");clpa.write(mFile);fprintf_s(mFile,"\" \"%s.clst[%i].clsp[%i].clpa\";\n",mName.c_str(),clst_i,clsp_i);}
	/*
	If true, the object has history and the control point attribute
	values are tweaks, not the actual values.
	*/
	BoolID getTweak(){char buffer[4096];sprintf_s (buffer, "%s.tw",mName.c_str());return (const char*)buffer;}
	/*If set, the tweaks are relative, otherwise absolute.*/
	BoolID getRelativeTweak(){char buffer[4096];sprintf_s (buffer, "%s.rtw",mName.c_str());return (const char*)buffer;}
	/*control points for the derived shapes*/
	const Double3ID& getControlPoints(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i]",mName.c_str(),cp_i);return (const char*)buffer;}
	/*X value of a control point*/
	const DoubleID& getXValue(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i].xv",mName.c_str(),cp_i);return (const char*)buffer;}
	/*Y value of a control point*/
	const DoubleID& getYValue(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i].yv",mName.c_str(),cp_i);return (const char*)buffer;}
	/*Z value of a control point*/
	const DoubleID& getZValue(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i].zv",mName.c_str(),cp_i);return (const char*)buffer;}
	/*CV weights values for nurbs, else unused*/
	const DoubleID& getWeights(size_t wt_i){char buffer[4096];sprintf_s (buffer, "%s.wt[%i]",mName.c_str(),wt_i);return (const char*)buffer;}
	/*
	Compound attribute that corresponds to uv set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aUVSetName)
	*/
	const UvSetID& getUvSet(size_t uvst_i){char buffer[4096];sprintf_s (buffer, "%s.uvst[%i]",mName.c_str(),uvst_i);return (const char*)buffer;}
	/*
	This is a string which identifies a given uv set.
	If an entry for a name exist, the name cannot
	be an empty string
	*/
	const StringID& getUvSetName(size_t uvst_i){char buffer[4096];sprintf_s (buffer, "%s.uvst[%i].uvsn",mName.c_str(),uvst_i);return (const char*)buffer;}
	/*This is a uvset uv point*/
	const Float2ID& getUvSetPoints(size_t uvst_i,size_t uvsp_i){char buffer[4096];sprintf_s (buffer, "%s.uvst[%i].uvsp[%i]",mName.c_str(),uvst_i,uvsp_i);return (const char*)buffer;}
	/*U value of a uvset uv point*/
	const FloatID& getUvSetPointsU(size_t uvst_i,size_t uvsp_i){char buffer[4096];sprintf_s (buffer, "%s.uvst[%i].uvsp[%i].uvpu",mName.c_str(),uvst_i,uvsp_i);return (const char*)buffer;}
	/*V value of a uvset uv point*/
	const FloatID& getUvSetPointsV(size_t uvst_i,size_t uvsp_i){char buffer[4096];sprintf_s (buffer, "%s.uvst[%i].uvsp[%i].uvpv",mName.c_str(),uvst_i,uvsp_i);return (const char*)buffer;}
	/*
	This is a string which identifies the "current" uv
	set, or the "working" uv set
	*/
	StringID getCurrentUVSet(){char buffer[4096];sprintf_s (buffer, "%s.cuvs",mName.c_str());return (const char*)buffer;}
	/*
	Turns on immediate drawing, which is efficient for animated shapes.
	For static shapes, this control should be left to its default value
	(false) which will use the fast vertex buffered mode of drawing.
	*/
	BoolID getDisplayImmediate(){char buffer[4096];sprintf_s (buffer, "%s.di",mName.c_str());return (const char*)buffer;}
	/*Controls explicit color per vertex display.*/
	BoolID getDisplayColors(){char buffer[4096];sprintf_s (buffer, "%s.dcol",mName.c_str());return (const char*)buffer;}
	/*Controls explicit color channel for CPV display.*/
	StringID getDisplayColorChannel(){char buffer[4096];sprintf_s (buffer, "%s.dcc",mName.c_str());return (const char*)buffer;}
	/*
	This is a string which identifies the "current" color
	set, or the "working" color set
	*/
	StringID getCurrentColorSet(){char buffer[4096];sprintf_s (buffer, "%s.ccls",mName.c_str());return (const char*)buffer;}
	/*
	Compound attribute that corresponds to color set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aColorSetName)
	*/
	const ColorSetID& getColorSet(size_t clst_i){char buffer[4096];sprintf_s (buffer, "%s.clst[%i]",mName.c_str(),clst_i);return (const char*)buffer;}
	/*
	This is a string which identifies a given color set.
	If an entry for a name exist, the name cannot
	be an empty string
	*/
	const StringID& getColorName(size_t clst_i){char buffer[4096];sprintf_s (buffer, "%s.clst[%i].clsn",mName.c_str(),clst_i);return (const char*)buffer;}
	/*This tells if all the color values should be clamped in 0 to 1 range*/
	const BoolID& getClamped(size_t clst_i){char buffer[4096];sprintf_s (buffer, "%s.clst[%i].clam",mName.c_str(),clst_i);return (const char*)buffer;}
	/*This identifies both the number of channels and the type of channels*/
	const UnsignedintID& getRepresentation(size_t clst_i){char buffer[4096];sprintf_s (buffer, "%s.clst[%i].rprt",mName.c_str(),clst_i);return (const char*)buffer;}
	/*
	This is a color set color point
	Red value of a color point
	*/
	const ColorSetPointsID& getColorSetPoints(size_t clst_i,size_t clsp_i){char buffer[4096];sprintf_s (buffer, "%s.clst[%i].clsp[%i]",mName.c_str(),clst_i,clsp_i);return (const char*)buffer;}
	/*Red value of a color point*/
	const FloatID& getColorSetPointsR(size_t clst_i,size_t clsp_i){char buffer[4096];sprintf_s (buffer, "%s.clst[%i].clsp[%i].clpr",mName.c_str(),clst_i,clsp_i);return (const char*)buffer;}
	/*Green value of a color point*/
	const FloatID& getColorSetPointsG(size_t clst_i,size_t clsp_i){char buffer[4096];sprintf_s (buffer, "%s.clst[%i].clsp[%i].clpg",mName.c_str(),clst_i,clsp_i);return (const char*)buffer;}
	/*Blue value of a color point*/
	const FloatID& getColorSetPointsB(size_t clst_i,size_t clsp_i){char buffer[4096];sprintf_s (buffer, "%s.clst[%i].clsp[%i].clpb",mName.c_str(),clst_i,clsp_i);return (const char*)buffer;}
	/*Alpha value of a color point*/
	const FloatID& getColorSetPointsA(size_t clst_i,size_t clsp_i){char buffer[4096];sprintf_s (buffer, "%s.clst[%i].clsp[%i].clpa",mName.c_str(),clst_i,clsp_i);return (const char*)buffer;}
protected:
	ControlPoint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DeformableShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CONTROLPOINT_H__
