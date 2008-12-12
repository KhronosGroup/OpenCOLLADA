/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STITCHSRF_H__
#define __MayaDM_STITCHSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The 'stitchSrf' node modifies the positions of the first (second )
 row (column) of control vertices on a NURBS surface such that the
 required G0 ( position continuity ), G1 continuity are achieved.
 The surface control vertices are modified to match one or more curve
 and point constraints.
 <p/>
 The attribute 'inSurface' specifies the NURBS surface to be modified.
 <p/>
 The attribute 'inputReferenceCOS[i]' specifies the i-th boundary
 curve in the 2D parameter space of the input surface.
 <p/>
 The attribute 'inputMatchCurve[i]' specifies the 3D curve that
 is to be matched by the surface.
 <p/>
 The attribute 'pc[i]' could be used to specify whether G0 continuity
 is desired on the surface along the edge that is modified to match
 the 3D curve at 'inputMatchCurve[i]'.
 <p/>
 The attribute 'tc[i]' could be used to specify whether G1 continuity
 is desired on the surface along the edge that is modified to match the
 3D curve at 'inputMatchCurve[i]'.
 <p/>
 The attribute 'fixboundary' keeps the boundary row(column) of control
 points fixed while solving for tangent continuity.
 <p/>
 The attribute 'tt[i]' is used to specify as to whether 'tolerance[i]'
 or 'sc[i]' is to be used for discretization done internally while
 matching 'inputMatchCurve[i]'.
 <p/>
 The attribute 'sc[i]' specifies the exact number of discretizations
 to be carried out while matching 'inputMatchCurve[i]'.
 <p/>
 The attribute 'tolerance[i]' specifies the step size as a fraction of the
 length of the curve at 'inputMatchCurve[i]'.
 <p/>
 The attributes 'pu[i]', 'pv[i]', 'p[i]', 'n[i]' specify the point
 constraints. The point constraint specifies the uv location on the
 surface and the desired 3d space position and normal at that point.
 <p/>
 The attribute 'tpp' can be used to turn on and off the solving for
 the position at point constraints.
 <p/>
 The attribute 'tpn' can be used to turn on and off the solving for
 the normals at point constraints.
 <p/>
 The attributes 'cvIthIndex[i]', 'cvJthIndex[i]', 'cvPosition[i]' can be used
 to explicitly set the position of control vertices on the surface
 being output.
 <p/>
 The attribute 'bias' is a blend factor to blend the control vertices
 between the input surface and the surface computed internally before
 the surface is output. A value of 0.0 implies the input surface is
 returned as output.
 <p/>
 CAUTION : No additional knots are inserted in to the NURBS surface.
 At times all the constraints cannot be met because the surface
 does not have the required number of control vertices.
*/
class StitchSrf : public AbstractBaseCreate
{
public:
public:
	StitchSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "stitchSrf"){}
	virtual ~StitchSrf(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*The input boundary curve. Not recommended to be used.*/
	void setInputCurve(size_t ic_i,const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i]\";\n",mName.c_str(),ic_i);}
	/*The space curve to matched.*/
	void setInputMatchCurve(size_t imc_i,const NurbsCurveID& imc){fprintf_s(mFile,"connectAttr \"");imc.write(mFile);fprintf_s(mFile,"\" \"%s.imc[%i]\";\n",mName.c_str(),imc_i);}
	/*The reference curve on surface around which the surface is modified.*/
	void setInputReferenceCOS(size_t ir_i,const NurbsCurveID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.ir[%i]\";\n",mName.c_str(),ir_i);}
	/*Toggle on(off) G0 continuous at edge corresponding to multi index.*/
	void setPositionalContinuity(size_t pc_i,bool pc){if(pc == true) return; fprintf_s(mFile, "setAttr \".pc[%i]\" %i;\n", pc_i,pc);}
	/*Toggle on(off) G0 continuous at edge corresponding to multi index.*/
	void setPositionalContinuity(size_t pc_i,const BoolID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc[%i]\";\n",mName.c_str(),pc_i);}
	/*Toggle on(off) G1 continuity across edge corresponding to multi index.*/
	void setTangentialContinuity(size_t tc_i,bool tc){if(tc == false) return; fprintf_s(mFile, "setAttr \".tc[%i]\" %i;\n", tc_i,tc);}
	/*Toggle on(off) G1 continuity across edge corresponding to multi index.*/
	void setTangentialContinuity(size_t tc_i,const BoolID& tc){fprintf_s(mFile,"connectAttr \"");tc.write(mFile);fprintf_s(mFile,"\" \"%s.tc[%i]\";\n",mName.c_str(),tc_i);}
	/*Toggle on(off) so as to use Tolerance or specified steps for discretization.*/
	void setToggleTolerance(size_t tt_i,bool tt){if(tt == false) return; fprintf_s(mFile, "setAttr \".tt[%i]\" %i;\n", tt_i,tt);}
	/*Toggle on(off) so as to use Tolerance or specified steps for discretization.*/
	void setToggleTolerance(size_t tt_i,const BoolID& tt){fprintf_s(mFile,"connectAttr \"");tt.write(mFile);fprintf_s(mFile,"\" \"%s.tt[%i]\";\n",mName.c_str(),tt_i);}
	/*Tolerance to use while discretizing the edge*/
	void setTolerance(size_t tol_i,double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol[%i]\" %f;\n", tol_i,tol);}
	/*Tolerance to use while discretizing the edge*/
	void setTolerance(size_t tol_i,const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol[%i]\";\n",mName.c_str(),tol_i);}
	/*Step count for the number of discretizations.*/
	void setStepCount(size_t sc_i,int sc){if(sc == 20) return; fprintf_s(mFile, "setAttr \".sc[%i]\" %i;\n", sc_i,sc);}
	/*Step count for the number of discretizations.*/
	void setStepCount(size_t sc_i,const IntID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i]\";\n",mName.c_str(),sc_i);}
	/*The U parameter value on surface for a point constraint.*/
	void setParameterU(size_t u_i,double u){if(u == -10000) return; fprintf_s(mFile, "setAttr \".u[%i]\" %f;\n", u_i,u);}
	/*The U parameter value on surface for a point constraint.*/
	void setParameterU(size_t u_i,const DoubleID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u[%i]\";\n",mName.c_str(),u_i);}
	/*The V parameter value on surface for a point constraint*/
	void setParameterV(size_t v_i,double v){if(v == -10000) return; fprintf_s(mFile, "setAttr \".v[%i]\" %f;\n", v_i,v);}
	/*The V parameter value on surface for a point constraint*/
	void setParameterV(size_t v_i,const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i]\";\n",mName.c_str(),v_i);}
	/*Desired 3D position at the corresponding (u,v) multi index.*/
	void setPosition(size_t p_i,const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*Desired position in X at the corresponding (u,v) multi index.*/
	void setPositionX(size_t p_i,const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].px\";\n",mName.c_str(),p_i);}
	/*Desired position in Y at the corresponding (u,v) multi index.*/
	void setPositionY(size_t p_i,const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].py\";\n",mName.c_str(),p_i);}
	/*Desired position in Z at the corresponding (u,v) multi index.*/
	void setPositionZ(size_t p_i,const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].pz\";\n",mName.c_str(),p_i);}
	/*Desired normal at the corresponding (u,v) index on the surface*/
	void setNormal(size_t n_i,const Double3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n[%i]\";\n",mName.c_str(),n_i);}
	/*Desired normal in X at the corresponding (u,v) index on the surface*/
	void setNormalX(size_t n_i,const DoubleID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n[%i].nx\";\n",mName.c_str(),n_i);}
	/*Desired normal in Y at the corresponding (u,v) index on the surface*/
	void setNormalY(size_t n_i,const DoubleID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n[%i].ny\";\n",mName.c_str(),n_i);}
	/*Desired normal in Z at the corresponding (u,v) index on the surface*/
	void setNormalZ(size_t n_i,const DoubleID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n[%i].nz\";\n",mName.c_str(),n_i);}
	/*Toggle on(off) normal point constraints on the surface.*/
	void setTogglePointNormals(bool tpn){if(tpn == false) return; fprintf_s(mFile, "setAttr \".tpn\" %i;\n", tpn);}
	/*Toggle on(off) normal point constraints on the surface.*/
	void setTogglePointNormals(const BoolID& tpn){fprintf_s(mFile,"connectAttr \"");tpn.write(mFile);fprintf_s(mFile,"\" \"%s.tpn\";\n",mName.c_str());}
	/*Toggle on(off) position point constraints on the surface.*/
	void setTogglePointPosition(bool tpp){if(tpp == true) return; fprintf_s(mFile, "setAttr \".tpp\" %i;\n", tpp);}
	/*Toggle on(off) position point constraints on the surface.*/
	void setTogglePointPosition(const BoolID& tpp){fprintf_s(mFile,"connectAttr \"");tpp.write(mFile);fprintf_s(mFile,"\" \"%s.tpp\";\n",mName.c_str());}
	/*The ith  boundary cv index on the input surface*/
	void setCvIthIndex(size_t ci_i,int ci){if(ci == -1) return; fprintf_s(mFile, "setAttr \".ci[%i]\" %i;\n", ci_i,ci);}
	/*The ith  boundary cv index on the input surface*/
	void setCvIthIndex(size_t ci_i,const IntID& ci){fprintf_s(mFile,"connectAttr \"");ci.write(mFile);fprintf_s(mFile,"\" \"%s.ci[%i]\";\n",mName.c_str(),ci_i);}
	/*The jth  boundary cv index on the input surface*/
	void setCvJthIndex(size_t cj_i,int cj){if(cj == -1) return; fprintf_s(mFile, "setAttr \".cj[%i]\" %i;\n", cj_i,cj);}
	/*The jth  boundary cv index on the input surface*/
	void setCvJthIndex(size_t cj_i,const IntID& cj){fprintf_s(mFile,"connectAttr \"");cj.write(mFile);fprintf_s(mFile,"\" \"%s.cj[%i]\";\n",mName.c_str(),cj_i);}
	/*Desired CV position at the cv (i,j) index. Overrides that computed during stitch.*/
	void setCvPosition(size_t cv_i,const Double3ID& cv){fprintf_s(mFile,"connectAttr \"");cv.write(mFile);fprintf_s(mFile,"\" \"%s.cv[%i]\";\n",mName.c_str(),cv_i);}
	/*Desired CV position in X at the cv (i,j) index. Overrides that computed during stitch.*/
	void setCvpositionX(size_t cv_i,const DoubleID& cvx){fprintf_s(mFile,"connectAttr \"");cvx.write(mFile);fprintf_s(mFile,"\" \"%s.cv[%i].cvx\";\n",mName.c_str(),cv_i);}
	/*Desired CV position in Y at the cv (i,j) index. Overrides that computed during stitch.*/
	void setCvpositionY(size_t cv_i,const DoubleID& cvy){fprintf_s(mFile,"connectAttr \"");cvy.write(mFile);fprintf_s(mFile,"\" \"%s.cv[%i].cvy\";\n",mName.c_str(),cv_i);}
	/*Desired CV position in Z at the cv (i,j) index. Overrides that computed during stitch.*/
	void setCvpositionZ(size_t cv_i,const DoubleID& cvz){fprintf_s(mFile,"connectAttr \"");cvz.write(mFile);fprintf_s(mFile,"\" \"%s.cv[%i].cvz\";\n",mName.c_str(),cv_i);}
	/*Blend Cvs in between input surface and result from stitch. A value of 0.0 returns the input surface*/
	void setBias(double b){if(b == 1.0) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*Blend Cvs in between input surface and result from stitch. A value of 0.0 returns the input surface*/
	void setBias(const DoubleID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*Fix Boundary Cvs while Solving for any G1 constraints.*/
	void setFixBoundary(bool fb){if(fb == false) return; fprintf_s(mFile, "setAttr \".fb\" %i;\n", fb);}
	/*Fix Boundary Cvs while Solving for any G1 constraints.*/
	void setFixBoundary(const BoolID& fb){fprintf_s(mFile,"connectAttr \"");fb.write(mFile);fprintf_s(mFile,"\" \"%s.fb\";\n",mName.c_str());}
	/*Deformers will let it be last*/
	void setShouldBeLast(const BoolID& sbl){fprintf_s(mFile,"connectAttr \"");sbl.write(mFile);fprintf_s(mFile,"\" \"%s.sbl\";\n",mName.c_str());}
	/*Output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*The input boundary curve. Not recommended to be used.*/
	const NurbsCurveID& getInputCurve(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i]",mName.c_str(),ic_i);return (const char*)buffer;}
	/*The space curve to matched.*/
	const NurbsCurveID& getInputMatchCurve(size_t imc_i){char buffer[4096];sprintf_s (buffer, "%s.imc[%i]",mName.c_str(),imc_i);return (const char*)buffer;}
	/*The reference curve on surface around which the surface is modified.*/
	const NurbsCurveID& getInputReferenceCOS(size_t ir_i){char buffer[4096];sprintf_s (buffer, "%s.ir[%i]",mName.c_str(),ir_i);return (const char*)buffer;}
	/*Toggle on(off) G0 continuous at edge corresponding to multi index.*/
	const BoolID& getPositionalContinuity(size_t pc_i){char buffer[4096];sprintf_s (buffer, "%s.pc[%i]",mName.c_str(),pc_i);return (const char*)buffer;}
	/*Toggle on(off) G1 continuity across edge corresponding to multi index.*/
	const BoolID& getTangentialContinuity(size_t tc_i){char buffer[4096];sprintf_s (buffer, "%s.tc[%i]",mName.c_str(),tc_i);return (const char*)buffer;}
	/*Toggle on(off) so as to use Tolerance or specified steps for discretization.*/
	const BoolID& getToggleTolerance(size_t tt_i){char buffer[4096];sprintf_s (buffer, "%s.tt[%i]",mName.c_str(),tt_i);return (const char*)buffer;}
	/*Tolerance to use while discretizing the edge*/
	const DoubleID& getTolerance(size_t tol_i){char buffer[4096];sprintf_s (buffer, "%s.tol[%i]",mName.c_str(),tol_i);return (const char*)buffer;}
	/*Step count for the number of discretizations.*/
	const IntID& getStepCount(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i]",mName.c_str(),sc_i);return (const char*)buffer;}
	/*The U parameter value on surface for a point constraint.*/
	const DoubleID& getParameterU(size_t u_i){char buffer[4096];sprintf_s (buffer, "%s.u[%i]",mName.c_str(),u_i);return (const char*)buffer;}
	/*The V parameter value on surface for a point constraint*/
	const DoubleID& getParameterV(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i]",mName.c_str(),v_i);return (const char*)buffer;}
	/*Desired 3D position at the corresponding (u,v) multi index.*/
	const Double3ID& getPosition(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*Desired position in X at the corresponding (u,v) multi index.*/
	const DoubleID& getPositionX(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].px",mName.c_str(),p_i);return (const char*)buffer;}
	/*Desired position in Y at the corresponding (u,v) multi index.*/
	const DoubleID& getPositionY(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].py",mName.c_str(),p_i);return (const char*)buffer;}
	/*Desired position in Z at the corresponding (u,v) multi index.*/
	const DoubleID& getPositionZ(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].pz",mName.c_str(),p_i);return (const char*)buffer;}
	/*Desired normal at the corresponding (u,v) index on the surface*/
	const Double3ID& getNormal(size_t n_i){char buffer[4096];sprintf_s (buffer, "%s.n[%i]",mName.c_str(),n_i);return (const char*)buffer;}
	/*Desired normal in X at the corresponding (u,v) index on the surface*/
	const DoubleID& getNormalX(size_t n_i){char buffer[4096];sprintf_s (buffer, "%s.n[%i].nx",mName.c_str(),n_i);return (const char*)buffer;}
	/*Desired normal in Y at the corresponding (u,v) index on the surface*/
	const DoubleID& getNormalY(size_t n_i){char buffer[4096];sprintf_s (buffer, "%s.n[%i].ny",mName.c_str(),n_i);return (const char*)buffer;}
	/*Desired normal in Z at the corresponding (u,v) index on the surface*/
	const DoubleID& getNormalZ(size_t n_i){char buffer[4096];sprintf_s (buffer, "%s.n[%i].nz",mName.c_str(),n_i);return (const char*)buffer;}
	/*Toggle on(off) normal point constraints on the surface.*/
	BoolID getTogglePointNormals(){char buffer[4096];sprintf_s (buffer, "%s.tpn",mName.c_str());return (const char*)buffer;}
	/*Toggle on(off) position point constraints on the surface.*/
	BoolID getTogglePointPosition(){char buffer[4096];sprintf_s (buffer, "%s.tpp",mName.c_str());return (const char*)buffer;}
	/*The ith  boundary cv index on the input surface*/
	const IntID& getCvIthIndex(size_t ci_i){char buffer[4096];sprintf_s (buffer, "%s.ci[%i]",mName.c_str(),ci_i);return (const char*)buffer;}
	/*The jth  boundary cv index on the input surface*/
	const IntID& getCvJthIndex(size_t cj_i){char buffer[4096];sprintf_s (buffer, "%s.cj[%i]",mName.c_str(),cj_i);return (const char*)buffer;}
	/*Desired CV position at the cv (i,j) index. Overrides that computed during stitch.*/
	const Double3ID& getCvPosition(size_t cv_i){char buffer[4096];sprintf_s (buffer, "%s.cv[%i]",mName.c_str(),cv_i);return (const char*)buffer;}
	/*Desired CV position in X at the cv (i,j) index. Overrides that computed during stitch.*/
	const DoubleID& getCvpositionX(size_t cv_i){char buffer[4096];sprintf_s (buffer, "%s.cv[%i].cvx",mName.c_str(),cv_i);return (const char*)buffer;}
	/*Desired CV position in Y at the cv (i,j) index. Overrides that computed during stitch.*/
	const DoubleID& getCvpositionY(size_t cv_i){char buffer[4096];sprintf_s (buffer, "%s.cv[%i].cvy",mName.c_str(),cv_i);return (const char*)buffer;}
	/*Desired CV position in Z at the cv (i,j) index. Overrides that computed during stitch.*/
	const DoubleID& getCvpositionZ(size_t cv_i){char buffer[4096];sprintf_s (buffer, "%s.cv[%i].cvz",mName.c_str(),cv_i);return (const char*)buffer;}
	/*Blend Cvs in between input surface and result from stitch. A value of 0.0 returns the input surface*/
	DoubleID getBias(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*Fix Boundary Cvs while Solving for any G1 constraints.*/
	BoolID getFixBoundary(){char buffer[4096];sprintf_s (buffer, "%s.fb",mName.c_str());return (const char*)buffer;}
	/*Deformers will let it be last*/
	BoolID getShouldBeLast(){char buffer[4096];sprintf_s (buffer, "%s.sbl",mName.c_str());return (const char*)buffer;}
	/*Output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	StitchSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_STITCHSRF_H__
