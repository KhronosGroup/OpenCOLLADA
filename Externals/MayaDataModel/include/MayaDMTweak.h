/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TWEAK_H__
#define __MayaDM_TWEAK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
/*
This node allows a translation to be associated with some or all of the
components of an input object. A tweak node is placed in the history of
all deformed shapes so that the user can control the ordering of the
CV translation and the deformers.<p/>
For example, consider a user that applies a deformation
to an object and then explicitly manipulates the position of that objects'
components (for example, a sphere's cv's). The transformations normally stored
on the cv's are stored in the tweak node instead. This allows for reordering
both the deformers and the tweak node in the chain of operations.
*/
class Tweak : public GeometryFilter
{
public:
	/*list of 3double points associated with the geometry input of the same index*/
	struct Plist{
		double3* controlPoints;
		void write(FILE* file) const
		{
			size_t size = sizeof(controlPoints)/sizeof(double3);
			for(size_t i=0; i<size; ++i)
			{
				controlPoints[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*list of 3float associated with the geometry input of the same index*/
	struct Vlist{
		float3* vertex;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertex)/sizeof(float3);
			for(size_t i=0; i<size; ++i)
			{
				vertex[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	Tweak(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "tweak"){}
	virtual ~Tweak(){}
	/*If set, the tweaks are relative, otherwise they are constrained to an absolute.*/
	void setRelativeTweak(bool rtw){if(rtw == true) return; fprintf_s(mFile, "setAttr \".rtw\" %i;\n", rtw);}
	/*If set, the tweaks are relative, otherwise they are constrained to an absolute.*/
	void setRelativeTweak(const BoolID& rtw){fprintf_s(mFile,"connectAttr \"");rtw.write(mFile);fprintf_s(mFile,"\" \"%s.rtw\";\n",mName.c_str());}
	/*list of 3double points associated with the geometry input of the same index*/
	void setPlist(size_t pl_i,const Plist& pl){fprintf_s(mFile, "setAttr \".pl[%i]\" ",pl_i);pl.write(mFile);fprintf_s(mFile,";\n");}
	/*list of 3double points associated with the geometry input of the same index*/
	void setPlist(size_t pl_i,const PlistID& pl){fprintf_s(mFile,"connectAttr \"");pl.write(mFile);fprintf_s(mFile,"\" \"%s.pl[%i]\";\n",mName.c_str(),pl_i);}
	/*amounts to move the control points*/
	void setControlPoints(size_t pl_i,size_t cp_i,const double3& cp){fprintf_s(mFile, "setAttr \".pl[%i].cp[%i]\" -type \"double3\" ",pl_i,cp_i);cp.write(mFile);fprintf_s(mFile,";\n");}
	/*amounts to move the control points*/
	void setControlPoints(size_t pl_i,size_t cp_start,size_t cp_end,double* cp){fprintf_s(mFile,"setAttr \".pl[%i].cp[%i:%i]\" ", pl_i,cp_start,cp_end);size_t size = (cp_end-cp_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",cp[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*amounts to move the control points*/
	void setControlPoints(size_t pl_i,size_t cp_i,const Double3ID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.pl[%i].cp[%i]\";\n",mName.c_str(),pl_i,cp_i);}
	/*X value of a control point*/
	void setXValue(size_t pl_i,size_t cp_i,double xv){if(xv == 0) return; fprintf_s(mFile, "setAttr \".pl[%i].cp[%i].xv\" %f;\n", pl_i,cp_i,xv);}
	/*X value of a control point*/
	void setXValue(size_t pl_i,size_t cp_i,const DoubleID& xv){fprintf_s(mFile,"connectAttr \"");xv.write(mFile);fprintf_s(mFile,"\" \"%s.pl[%i].cp[%i].xv\";\n",mName.c_str(),pl_i,cp_i);}
	/*Y value of a control point*/
	void setYValue(size_t pl_i,size_t cp_i,double yv){if(yv == 0) return; fprintf_s(mFile, "setAttr \".pl[%i].cp[%i].yv\" %f;\n", pl_i,cp_i,yv);}
	/*Y value of a control point*/
	void setYValue(size_t pl_i,size_t cp_i,const DoubleID& yv){fprintf_s(mFile,"connectAttr \"");yv.write(mFile);fprintf_s(mFile,"\" \"%s.pl[%i].cp[%i].yv\";\n",mName.c_str(),pl_i,cp_i);}
	/*Z value of a control point*/
	void setZValue(size_t pl_i,size_t cp_i,double zv){if(zv == 0) return; fprintf_s(mFile, "setAttr \".pl[%i].cp[%i].zv\" %f;\n", pl_i,cp_i,zv);}
	/*Z value of a control point*/
	void setZValue(size_t pl_i,size_t cp_i,const DoubleID& zv){fprintf_s(mFile,"connectAttr \"");zv.write(mFile);fprintf_s(mFile,"\" \"%s.pl[%i].cp[%i].zv\";\n",mName.c_str(),pl_i,cp_i);}
	/*list of 3float associated with the geometry input of the same index*/
	void setVlist(size_t vl_i,const Vlist& vl){fprintf_s(mFile, "setAttr \".vl[%i]\" ",vl_i);vl.write(mFile);fprintf_s(mFile,";\n");}
	/*list of 3float associated with the geometry input of the same index*/
	void setVlist(size_t vl_i,const VlistID& vl){fprintf_s(mFile,"connectAttr \"");vl.write(mFile);fprintf_s(mFile,"\" \"%s.vl[%i]\";\n",mName.c_str(),vl_i);}
	/*amounts to move the vertices*/
	void setVertex(size_t vl_i,size_t vt_i,const float3& vt){fprintf_s(mFile, "setAttr \".vl[%i].vt[%i]\" -type \"float3\" ",vl_i,vt_i);vt.write(mFile);fprintf_s(mFile,";\n");}
	/*amounts to move the vertices*/
	void setVertex(size_t vl_i,size_t vt_start,size_t vt_end,float* vt){fprintf_s(mFile,"setAttr \".vl[%i].vt[%i:%i]\" ", vl_i,vt_start,vt_end);size_t size = (vt_end-vt_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",vt[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*amounts to move the vertices*/
	void setVertex(size_t vl_i,size_t vt_i,const Float3ID& vt){fprintf_s(mFile,"connectAttr \"");vt.write(mFile);fprintf_s(mFile,"\" \"%s.vl[%i].vt[%i]\";\n",mName.c_str(),vl_i,vt_i);}
	/*X value of a vertex*/
	void setXVertex(size_t vl_i,size_t vt_i,float vx){if(vx == 0) return; fprintf_s(mFile, "setAttr \".vl[%i].vt[%i].vx\" %f;\n", vl_i,vt_i,vx);}
	/*X value of a vertex*/
	void setXVertex(size_t vl_i,size_t vt_i,const FloatID& vx){fprintf_s(mFile,"connectAttr \"");vx.write(mFile);fprintf_s(mFile,"\" \"%s.vl[%i].vt[%i].vx\";\n",mName.c_str(),vl_i,vt_i);}
	/*Y value of a vertex*/
	void setYVertex(size_t vl_i,size_t vt_i,float vy){if(vy == 0) return; fprintf_s(mFile, "setAttr \".vl[%i].vt[%i].vy\" %f;\n", vl_i,vt_i,vy);}
	/*Y value of a vertex*/
	void setYVertex(size_t vl_i,size_t vt_i,const FloatID& vy){fprintf_s(mFile,"connectAttr \"");vy.write(mFile);fprintf_s(mFile,"\" \"%s.vl[%i].vt[%i].vy\";\n",mName.c_str(),vl_i,vt_i);}
	/*Z value of a vertex*/
	void setZVertex(size_t vl_i,size_t vt_i,float vz){if(vz == 0) return; fprintf_s(mFile, "setAttr \".vl[%i].vt[%i].vz\" %f;\n", vl_i,vt_i,vz);}
	/*Z value of a vertex*/
	void setZVertex(size_t vl_i,size_t vt_i,const FloatID& vz){fprintf_s(mFile,"connectAttr \"");vz.write(mFile);fprintf_s(mFile,"\" \"%s.vl[%i].vt[%i].vz\";\n",mName.c_str(),vl_i,vt_i);}
	/*If set, the tweaks are relative, otherwise they are constrained to an absolute.*/
	BoolID getRelativeTweak(){char buffer[4096];sprintf_s (buffer, "%s.rtw",mName.c_str());return (const char*)buffer;}
	/*list of 3double points associated with the geometry input of the same index*/
	const PlistID& getPlist(size_t pl_i){char buffer[4096];sprintf_s (buffer, "%s.pl[%i]",mName.c_str(),pl_i);return (const char*)buffer;}
	/*amounts to move the control points*/
	const Double3ID& getControlPoints(size_t pl_i,size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.pl[%i].cp[%i]",mName.c_str(),pl_i,cp_i);return (const char*)buffer;}
	/*X value of a control point*/
	const DoubleID& getXValue(size_t pl_i,size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.pl[%i].cp[%i].xv",mName.c_str(),pl_i,cp_i);return (const char*)buffer;}
	/*Y value of a control point*/
	const DoubleID& getYValue(size_t pl_i,size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.pl[%i].cp[%i].yv",mName.c_str(),pl_i,cp_i);return (const char*)buffer;}
	/*Z value of a control point*/
	const DoubleID& getZValue(size_t pl_i,size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.pl[%i].cp[%i].zv",mName.c_str(),pl_i,cp_i);return (const char*)buffer;}
	/*list of 3float associated with the geometry input of the same index*/
	const VlistID& getVlist(size_t vl_i){char buffer[4096];sprintf_s (buffer, "%s.vl[%i]",mName.c_str(),vl_i);return (const char*)buffer;}
	/*amounts to move the vertices*/
	const Float3ID& getVertex(size_t vl_i,size_t vt_i){char buffer[4096];sprintf_s (buffer, "%s.vl[%i].vt[%i]",mName.c_str(),vl_i,vt_i);return (const char*)buffer;}
	/*X value of a vertex*/
	const FloatID& getXVertex(size_t vl_i,size_t vt_i){char buffer[4096];sprintf_s (buffer, "%s.vl[%i].vt[%i].vx",mName.c_str(),vl_i,vt_i);return (const char*)buffer;}
	/*Y value of a vertex*/
	const FloatID& getYVertex(size_t vl_i,size_t vt_i){char buffer[4096];sprintf_s (buffer, "%s.vl[%i].vt[%i].vy",mName.c_str(),vl_i,vt_i);return (const char*)buffer;}
	/*Z value of a vertex*/
	const FloatID& getZVertex(size_t vl_i,size_t vt_i){char buffer[4096];sprintf_s (buffer, "%s.vl[%i].vt[%i].vz",mName.c_str(),vl_i,vt_i);return (const char*)buffer;}
protected:
	Tweak(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TWEAK_H__
