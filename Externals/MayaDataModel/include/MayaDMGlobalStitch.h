/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GLOBALSTITCH_H__
#define __MayaDM_GLOBALSTITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The 'globalStitch' node modifies the positions of the outer rows and
 columns of control vertices on a set of NURBS surface to achieve a
 required position or smoothness continuity condition.

 <p/> The attribute 'inputSurface' specifies a list of NURBS surfaces
 to be modified.

 <p/> The attribute 'sc' requires corners of matching edges to be
 stitched. This operation will be performed before any of the other
 stitching options. The option matchKnots forces the ends of matching
 curve segments to be positioned exactly at knot values the
 alternative is to use the closest point will be used instead.

 <p/> The attribute 'se' controls whether edges are stitched with
 positional continuity. The closest point option causes the edges to
 be stitched by matching a point on one edge to the closest point on
 the other edge. The alternative is for points separated by equal
 parameter intervals on each edge will be stitched together.

 <p/> The attribute 'ssw' controls higher orders of stitching. Options
 are off, tangent (C1 continuity at common surface edges) and normal
 (surface normals on each edge are aligned, but the isoparms are not
 necessarily perpendicular.)

 <p/> The attribute 'spe' specifies that partial surface edges are
 to be stitched. This means joins whose start or end points are not
 at surface corners on either edge.

 <p/> The attribute 'maxSeparation' specifies the maximum separaion
 between two surfaces that will still be stitched.

 <p/> The attribute 'sampling' specifies how densely the edge is
 sampled. A sampling of 1 means that each span on each surface is
 sampled at least 'degree' times. Higher values are a
 multiple of this sampling rate. A value of 1 is guaranteed always
 to be enough to ensure a solution, but the value can be increased to get
 a better fit in some cases.

 <p/> The attribute 'modificationResistance' specifies how closely
 the CVs should match their original positions. A high value
 constrains the CV to be harder to move from its original position.


 <p/> The attribute 'lock' can be used to ensure specific surfaces do
 not change at all during the fitting process.

 <p/>
 CAUTION : No additional knots are inserted in to the NURBS surface.
 At times all the constraints cannot be met because the surface
 does not have the required number of control vertices.
*/
class GlobalStitch : public AbstractBaseCreate
{
public:
public:
	GlobalStitch(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "globalStitch"){}
	virtual ~GlobalStitch(){}
	/*The input surfaces*/
	void setInputSurface(size_t is_i,const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is[%i]\";\n",mName.c_str(),is_i);}
	/*
	Stitch corners of surfaces
	0 - off
	1 - closest point
	2 - closest knot
	*/
	void setStitchCorners(unsigned int sc){if(sc == 1) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*
	Stitch corners of surfaces
	0 - off
	1 - closest point
	2 - closest knot
	*/
	void setStitchCorners(const UnsignedintID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*
	Stitch edges of surfaces
	0 - off
	1 - closest point
	2 - matching params
	*/
	void setStitchEdges(unsigned int se){if(se == 1) return; fprintf_s(mFile, "setAttr \".se\" %i;\n", se);}
	/*
	Stitch edges of surfaces
	0 - off
	1 - closest point
	2 - matching params
	*/
	void setStitchEdges(const UnsignedintID& se){fprintf_s(mFile,"connectAttr \"");se.write(mFile);fprintf_s(mFile,"\" \"%s.se\";\n",mName.c_str());}
	/*
	Set type of smoothness of edge join
	0 - off
	1 - tangent
	2 - normal
	*/
	void setStitchSmoothness(unsigned int ss){if(ss == 0) return; fprintf_s(mFile, "setAttr \".ss\" %i;\n", ss);}
	/*
	Set type of smoothness of edge join
	0 - off
	1 - tangent
	2 - normal
	*/
	void setStitchSmoothness(const UnsignedintID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*Toggle on(off) partial edge stitching*/
	void setStitchPartialEdges(bool spe){if(spe == false) return; fprintf_s(mFile, "setAttr \".spe\" %i;\n", spe);}
	/*Toggle on(off) partial edge stitching*/
	void setStitchPartialEdges(const BoolID& spe){fprintf_s(mFile,"connectAttr \"");spe.write(mFile);fprintf_s(mFile,"\" \"%s.spe\";\n",mName.c_str());}
	/*Maximum separation that will still be stitched*/
	void setMaxSeparation(double ms){if(ms == 0) return; fprintf_s(mFile, "setAttr \".ms\" %f;\n", ms);}
	/*Maximum separation that will still be stitched*/
	void setMaxSeparation(const DoubleID& ms){fprintf_s(mFile,"connectAttr \"");ms.write(mFile);fprintf_s(mFile,"\" \"%s.ms\";\n",mName.c_str());}
	/*Sampling when stitching edges*/
	void setSampling(int sam){if(sam == 1) return; fprintf_s(mFile, "setAttr \".sam\" %i;\n", sam);}
	/*Sampling when stitching edges*/
	void setSampling(const IntID& sam){fprintf_s(mFile,"connectAttr \"");sam.write(mFile);fprintf_s(mFile,"\" \"%s.sam\";\n",mName.c_str());}
	/*Modification resistance weight for surface CVs*/
	void setModificationResistance(double mr){if(mr == 1e-1) return; fprintf_s(mFile, "setAttr \".mr\" %f;\n", mr);}
	/*Modification resistance weight for surface CVs*/
	void setModificationResistance(const DoubleID& mr){fprintf_s(mFile,"connectAttr \"");mr.write(mFile);fprintf_s(mFile,"\" \"%s.mr\";\n",mName.c_str());}
	/*Keep the NURBS surface at the specified multi index unchanged by the fitting.*/
	void setLockSurface(size_t lk_i,bool lk){if(lk == false) return; fprintf_s(mFile, "setAttr \".lk[%i]\" %i;\n", lk_i,lk);}
	/*Keep the NURBS surface at the specified multi index unchanged by the fitting.*/
	void setLockSurface(size_t lk_i,const BoolID& lk){fprintf_s(mFile,"connectAttr \"");lk.write(mFile);fprintf_s(mFile,"\" \"%s.lk[%i]\";\n",mName.c_str(),lk_i);}
	/*Deformers will let it be last*/
	void setShouldBeLast(const BoolID& sbl){fprintf_s(mFile,"connectAttr \"");sbl.write(mFile);fprintf_s(mFile,"\" \"%s.sbl\";\n",mName.c_str());}
	/*Output surfaces*/
	void setOutputSurface(size_t os_i,const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os[%i]\";\n",mName.c_str(),os_i);}
	/*Output connected edges*/
	void setConnectedEdges(size_t ce_i,const NurbsCurveID& ce){fprintf_s(mFile,"connectAttr \"");ce.write(mFile);fprintf_s(mFile,"\" \"%s.ce[%i]\";\n",mName.c_str(),ce_i);}
	/*Output unconnected edges*/
	void setUnconnectedEdges(size_t ue_i,const NurbsCurveID& ue){fprintf_s(mFile,"connectAttr \"");ue.write(mFile);fprintf_s(mFile,"\" \"%s.ue[%i]\";\n",mName.c_str(),ue_i);}
	/*The input surfaces*/
	const NurbsSurfaceID& getInputSurface(size_t is_i){char buffer[4096];sprintf_s (buffer, "%s.is[%i]",mName.c_str(),is_i);return (const char*)buffer;}
	/*
	Stitch corners of surfaces
	0 - off
	1 - closest point
	2 - closest knot
	*/
	UnsignedintID getStitchCorners(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*
	Stitch edges of surfaces
	0 - off
	1 - closest point
	2 - matching params
	*/
	UnsignedintID getStitchEdges(){char buffer[4096];sprintf_s (buffer, "%s.se",mName.c_str());return (const char*)buffer;}
	/*
	Set type of smoothness of edge join
	0 - off
	1 - tangent
	2 - normal
	*/
	UnsignedintID getStitchSmoothness(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*Toggle on(off) partial edge stitching*/
	BoolID getStitchPartialEdges(){char buffer[4096];sprintf_s (buffer, "%s.spe",mName.c_str());return (const char*)buffer;}
	/*Maximum separation that will still be stitched*/
	DoubleID getMaxSeparation(){char buffer[4096];sprintf_s (buffer, "%s.ms",mName.c_str());return (const char*)buffer;}
	/*Sampling when stitching edges*/
	IntID getSampling(){char buffer[4096];sprintf_s (buffer, "%s.sam",mName.c_str());return (const char*)buffer;}
	/*Modification resistance weight for surface CVs*/
	DoubleID getModificationResistance(){char buffer[4096];sprintf_s (buffer, "%s.mr",mName.c_str());return (const char*)buffer;}
	/*Keep the NURBS surface at the specified multi index unchanged by the fitting.*/
	const BoolID& getLockSurface(size_t lk_i){char buffer[4096];sprintf_s (buffer, "%s.lk[%i]",mName.c_str(),lk_i);return (const char*)buffer;}
	/*Deformers will let it be last*/
	BoolID getShouldBeLast(){char buffer[4096];sprintf_s (buffer, "%s.sbl",mName.c_str());return (const char*)buffer;}
	/*Output surfaces*/
	const NurbsSurfaceID& getOutputSurface(size_t os_i){char buffer[4096];sprintf_s (buffer, "%s.os[%i]",mName.c_str(),os_i);return (const char*)buffer;}
	/*Output connected edges*/
	const NurbsCurveID& getConnectedEdges(size_t ce_i){char buffer[4096];sprintf_s (buffer, "%s.ce[%i]",mName.c_str(),ce_i);return (const char*)buffer;}
	/*Output unconnected edges*/
	const NurbsCurveID& getUnconnectedEdges(size_t ue_i){char buffer[4096];sprintf_s (buffer, "%s.ue[%i]",mName.c_str(),ue_i);return (const char*)buffer;}
protected:
	GlobalStitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GLOBALSTITCH_H__
