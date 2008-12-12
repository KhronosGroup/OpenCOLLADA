/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RIGIDSOLVER_H__
#define __MayaDM_RIGIDSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>        This node contains the attributes for the rigid solver.  The attributes
      of the rigid solver control the accuracy of the rigid body solution
      along with some global attributes such as friction, bounciness and
      caching.  The user can change the collision tolerance (a delta distance
      at which two rigid bodies are considered to be "in contact" with one
      another) and step size (the step the rigid solver takes to determine the
      rigid body solution).  Decreasing either of these attributes will cause
      the solver to run slower but more accurately.  This node also
      controls the display of annotations such as the center of mass,
      velocity and constraint indicators.
</pre></p>
*/
class RigidSolver : public DependNode
{
public:
	/*Generalized force on the rigid bodies (forces and torques).*/
	struct GeneralForce{
		vectorArray inputForce;
		vectorArray inputTorque;
		void write(FILE* file) const
		{
			inputForce.write(file);
			fprintf_s(file, " ");
			inputTorque.write(file);
		}
	};
public:
	RigidSolver(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "rigidSolver"){}
	virtual ~RigidSolver(){}
	/*This holds the value for time to be queried.*/
	void setCurrentTime(const TimeID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*The start time of the animation in seconds.*/
	void setStartTime(const TimeID& stm){fprintf_s(mFile,"connectAttr \"");stm.write(mFile);fprintf_s(mFile,"\" \"%s.stm\";\n",mName.c_str());}
	/*Generalized force on the rigid bodies (forces and torques).*/
	void setGeneralForce(size_t gfr_i,const GeneralForce& gfr){fprintf_s(mFile, "setAttr \".gfr[%i]\" ",gfr_i);gfr.write(mFile);fprintf_s(mFile,";\n");}
	/*Generalized force on the rigid bodies (forces and torques).*/
	void setGeneralForce(size_t gfr_i,const GeneralForceID& gfr){fprintf_s(mFile,"connectAttr \"");gfr.write(mFile);fprintf_s(mFile,"\" \"%s.gfr[%i]\";\n",mName.c_str(),gfr_i);}
	/*Forces on the rigid bodies.*/
	void setInputForce(size_t gfr_i,const vectorArray& ifr){if(ifr.size == 0) return; fprintf_s(mFile, "setAttr \".gfr[%i].ifr\" -type \"vectorArray\" ",gfr_i);ifr.write(mFile);fprintf_s(mFile,";\n");}
	/*Forces on the rigid bodies.*/
	void setInputForce(size_t gfr_i,const VectorArrayID& ifr){fprintf_s(mFile,"connectAttr \"");ifr.write(mFile);fprintf_s(mFile,"\" \"%s.gfr[%i].ifr\";\n",mName.c_str(),gfr_i);}
	/*Torques on the rigid bodies.*/
	void setInputTorque(size_t gfr_i,const vectorArray& itr){if(itr.size == 0) return; fprintf_s(mFile, "setAttr \".gfr[%i].itr\" -type \"vectorArray\" ",gfr_i);itr.write(mFile);fprintf_s(mFile,";\n");}
	/*Torques on the rigid bodies.*/
	void setInputTorque(size_t gfr_i,const VectorArrayID& itr){fprintf_s(mFile,"connectAttr \"");itr.write(mFile);fprintf_s(mFile,"\" \"%s.gfr[%i].itr\";\n",mName.c_str(),gfr_i);}
	/*Translation.*/
	void setTranslate(size_t t_i,const double3& t){fprintf_s(mFile, "setAttr \".t[%i]\" -type \"double3\" ",t_i);t.write(mFile);fprintf_s(mFile,";\n");}
	/*Translation.*/
	void setTranslate(size_t t_start,size_t t_end,double* t){fprintf_s(mFile,"setAttr \".t[%i:%i]\" ", t_start,t_end);size_t size = (t_end-t_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",t[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Translation.*/
	void setTranslate(size_t t_i,const Double3ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t[%i]\";\n",mName.c_str(),t_i);}
	/*Translate X.*/
	void setTranslateX(size_t t_i,double tx){if(tx == 0) return; fprintf_s(mFile, "setAttr \".t[%i].tx\" %f;\n", t_i,tx);}
	/*Translate X.*/
	void setTranslateX(size_t t_i,const DoubleID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.t[%i].tx\";\n",mName.c_str(),t_i);}
	/*Translate Y.*/
	void setTranslateY(size_t t_i,double ty){if(ty == 0) return; fprintf_s(mFile, "setAttr \".t[%i].ty\" %f;\n", t_i,ty);}
	/*Translate Y.*/
	void setTranslateY(size_t t_i,const DoubleID& ty){fprintf_s(mFile,"connectAttr \"");ty.write(mFile);fprintf_s(mFile,"\" \"%s.t[%i].ty\";\n",mName.c_str(),t_i);}
	/*Translate Z.*/
	void setTranslateZ(size_t t_i,double tz){if(tz == 0) return; fprintf_s(mFile, "setAttr \".t[%i].tz\" %f;\n", t_i,tz);}
	/*Translate Z.*/
	void setTranslateZ(size_t t_i,const DoubleID& tz){fprintf_s(mFile,"connectAttr \"");tz.write(mFile);fprintf_s(mFile,"\" \"%s.t[%i].tz\";\n",mName.c_str(),t_i);}
	/*Rotation.*/
	void setRotate(size_t r_i,const double3& r){fprintf_s(mFile, "setAttr \".r[%i]\" -type \"double3\" ",r_i);r.write(mFile);fprintf_s(mFile,";\n");}
	/*Rotation.*/
	void setRotate(size_t r_start,size_t r_end,double* r){fprintf_s(mFile,"setAttr \".r[%i:%i]\" ", r_start,r_end);size_t size = (r_end-r_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",r[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Rotation.*/
	void setRotate(size_t r_i,const Double3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i]\";\n",mName.c_str(),r_i);}
	/*Rotate X.*/
	void setRotateX(size_t r_i,double rx){if(rx == 0) return; fprintf_s(mFile, "setAttr \".r[%i].rx\" %f;\n", r_i,rx);}
	/*Rotate X.*/
	void setRotateX(size_t r_i,const DoubleID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i].rx\";\n",mName.c_str(),r_i);}
	/*Rotate Y.*/
	void setRotateY(size_t r_i,double ry){if(ry == 0) return; fprintf_s(mFile, "setAttr \".r[%i].ry\" %f;\n", r_i,ry);}
	/*Rotate Y.*/
	void setRotateY(size_t r_i,const DoubleID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i].ry\";\n",mName.c_str(),r_i);}
	/*Rotate Z.*/
	void setRotateZ(size_t r_i,double rz){if(rz == 0) return; fprintf_s(mFile, "setAttr \".r[%i].rz\" %f;\n", r_i,rz);}
	/*Rotate Z.*/
	void setRotateZ(size_t r_i,const DoubleID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i].rz\";\n",mName.c_str(),r_i);}
	/*Constraint Translation.*/
	void setConstraintTranslate(size_t ctr_i,const double3& ctr){fprintf_s(mFile, "setAttr \".ctr[%i]\" -type \"double3\" ",ctr_i);ctr.write(mFile);fprintf_s(mFile,";\n");}
	/*Constraint Translation.*/
	void setConstraintTranslate(size_t ctr_start,size_t ctr_end,double* ctr){fprintf_s(mFile,"setAttr \".ctr[%i:%i]\" ", ctr_start,ctr_end);size_t size = (ctr_end-ctr_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",ctr[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Constraint Translation.*/
	void setConstraintTranslate(size_t ctr_i,const Double3ID& ctr){fprintf_s(mFile,"connectAttr \"");ctr.write(mFile);fprintf_s(mFile,"\" \"%s.ctr[%i]\";\n",mName.c_str(),ctr_i);}
	/*Constraint Translate X.*/
	void setConstraintTranslateX(size_t ctr_i,double ctx){if(ctx == 0) return; fprintf_s(mFile, "setAttr \".ctr[%i].ctx\" %f;\n", ctr_i,ctx);}
	/*Constraint Translate X.*/
	void setConstraintTranslateX(size_t ctr_i,const DoubleID& ctx){fprintf_s(mFile,"connectAttr \"");ctx.write(mFile);fprintf_s(mFile,"\" \"%s.ctr[%i].ctx\";\n",mName.c_str(),ctr_i);}
	/*Constraint Translate Y.*/
	void setConstraintTranslateY(size_t ctr_i,double cty){if(cty == 0) return; fprintf_s(mFile, "setAttr \".ctr[%i].cty\" %f;\n", ctr_i,cty);}
	/*Constraint Translate Y.*/
	void setConstraintTranslateY(size_t ctr_i,const DoubleID& cty){fprintf_s(mFile,"connectAttr \"");cty.write(mFile);fprintf_s(mFile,"\" \"%s.ctr[%i].cty\";\n",mName.c_str(),ctr_i);}
	/*Constraint Translate Z.*/
	void setConstraintTranslateZ(size_t ctr_i,double ctz){if(ctz == 0) return; fprintf_s(mFile, "setAttr \".ctr[%i].ctz\" %f;\n", ctr_i,ctz);}
	/*Constraint Translate Z.*/
	void setConstraintTranslateZ(size_t ctr_i,const DoubleID& ctz){fprintf_s(mFile,"connectAttr \"");ctz.write(mFile);fprintf_s(mFile,"\" \"%s.ctr[%i].ctz\";\n",mName.c_str(),ctr_i);}
	/*Constraint Rotation.*/
	void setConstraintRotate(size_t cr_i,const double3& cr){fprintf_s(mFile, "setAttr \".cr[%i]\" -type \"double3\" ",cr_i);cr.write(mFile);fprintf_s(mFile,";\n");}
	/*Constraint Rotation.*/
	void setConstraintRotate(size_t cr_start,size_t cr_end,double* cr){fprintf_s(mFile,"setAttr \".cr[%i:%i]\" ", cr_start,cr_end);size_t size = (cr_end-cr_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",cr[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Constraint Rotation.*/
	void setConstraintRotate(size_t cr_i,const Double3ID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr[%i]\";\n",mName.c_str(),cr_i);}
	/*Constraint Rotate X.*/
	void setConstraintRotateX(size_t cr_i,double crx){if(crx == 0) return; fprintf_s(mFile, "setAttr \".cr[%i].crx\" %f;\n", cr_i,crx);}
	/*Constraint Rotate X.*/
	void setConstraintRotateX(size_t cr_i,const DoubleID& crx){fprintf_s(mFile,"connectAttr \"");crx.write(mFile);fprintf_s(mFile,"\" \"%s.cr[%i].crx\";\n",mName.c_str(),cr_i);}
	/*Constraint Rotate Y.*/
	void setConstraintRotateY(size_t cr_i,double cry){if(cry == 0) return; fprintf_s(mFile, "setAttr \".cr[%i].cry\" %f;\n", cr_i,cry);}
	/*Constraint Rotate Y.*/
	void setConstraintRotateY(size_t cr_i,const DoubleID& cry){fprintf_s(mFile,"connectAttr \"");cry.write(mFile);fprintf_s(mFile,"\" \"%s.cr[%i].cry\";\n",mName.c_str(),cr_i);}
	/*Constraint Rotate Z.*/
	void setConstraintRotateZ(size_t cr_i,double crz){if(crz == 0) return; fprintf_s(mFile, "setAttr \".cr[%i].crz\" %f;\n", cr_i,crz);}
	/*Constraint Rotate Z.*/
	void setConstraintRotateZ(size_t cr_i,const DoubleID& crz){fprintf_s(mFile,"connectAttr \"");crz.write(mFile);fprintf_s(mFile,"\" \"%s.cr[%i].crz\";\n",mName.c_str(),cr_i);}
	/*A delta distance at which two rigid bodies are considered to be "in contact" with one another.*/
	void setCollisionTolerance(double ctl){if(ctl == 0.02) return; fprintf_s(mFile, "setAttr \".ctl\" %f;\n", ctl);}
	/*The step the rigid solver takes to determine the rigid body solution.*/
	void setStepSize(double ss){if(ss == 0.03) return; fprintf_s(mFile, "setAttr \".ss\" %f;\n", ss);}
	/*Scale for the velocity vectors.*/
	void setScaleVelocity(double svv){if(svv == 1.0) return; fprintf_s(mFile, "setAttr \".svv\" %f;\n", svv);}
	/*Scale for the velocity vectors.*/
	void setScaleVelocity(const DoubleID& svv){fprintf_s(mFile,"connectAttr \"");svv.write(mFile);fprintf_s(mFile,"\" \"%s.svv\";\n",mName.c_str());}
	/*Rigid body solver method attribute*/
	void setSolverMethod(unsigned int slm){if(slm == 2) return; fprintf_s(mFile, "setAttr \".slm\" %i;\n", slm);}
	/*Rigid body solver method attribute*/
	void setSolverMethod(const UnsignedintID& slm){fprintf_s(mFile,"connectAttr \"");slm.write(mFile);fprintf_s(mFile,"\" \"%s.slm\";\n",mName.c_str());}
	/*Turn friction on/off.*/
	void setFriction(bool f){if(f == true) return; fprintf_s(mFile, "setAttr \".f\" %i;\n", f);}
	/*Turn friction on/off.*/
	void setFriction(const BoolID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Turn bounciness (sometimes referred to as restitution) on/off.*/
	void setBounciness(bool b){if(b == true) return; fprintf_s(mFile, "setAttr \".b\" %i;\n", b);}
	/*Turn bounciness (sometimes referred to as restitution) on/off.*/
	void setBounciness(const BoolID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*Turn dynamics on/off.*/
	void setDynamics(bool dyn){if(dyn == true) return; fprintf_s(mFile, "setAttr \".dyn\" %i;\n", dyn);}
	/*Turn dynamics on/off.*/
	void setDynamics(const BoolID& dyn){fprintf_s(mFile,"connectAttr \"");dyn.write(mFile);fprintf_s(mFile,"\" \"%s.dyn\";\n",mName.c_str());}
	/*Calculate the solver tolerances.*/
	void setAutoSolverTolerances(bool ast){if(ast == false) return; fprintf_s(mFile, "setAttr \".ast\" %i;\n", ast);}
	/*Calculate the solver tolerances.*/
	void setAutoSolverTolerances(const BoolID& ast){fprintf_s(mFile,"connectAttr \"");ast.write(mFile);fprintf_s(mFile,"\" \"%s.ast\";\n",mName.c_str());}
	/*Turn on/off the display velocity vector.*/
	void setDisplayVelocity(bool dv){if(dv == false) return; fprintf_s(mFile, "setAttr \".dv\" %i;\n", dv);}
	/*Turn on/off the display velocity vector.*/
	void setDisplayVelocity(const BoolID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*Turn on/off the display of the center of mass icon.*/
	void setDisplayCenterOfMass(bool dcom){if(dcom == true) return; fprintf_s(mFile, "setAttr \".dcom\" %i;\n", dcom);}
	/*Turn on/off the display of the center of mass icon.*/
	void setDisplayCenterOfMass(const BoolID& dcom){fprintf_s(mFile,"connectAttr \"");dcom.write(mFile);fprintf_s(mFile,"\" \"%s.dcom\";\n",mName.c_str());}
	/*Turn on/off the display of the constraint vector.*/
	void setDisplayConstraint(bool dc){if(dc == true) return; fprintf_s(mFile, "setAttr \".dc\" %i;\n", dc);}
	/*Turn on/off the display of the constraint vector.*/
	void setDisplayConstraint(const BoolID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*Turn on/off labels for the rigid bodies and constraints in the solver.*/
	void setDisplayLabel(bool dl){if(dl == false) return; fprintf_s(mFile, "setAttr \".dl\" %i;\n", dl);}
	/*Turn on/off labels for the rigid bodies and constraints in the solver.*/
	void setDisplayLabel(const BoolID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*Turn on/off the caching of all rigid bodies.*/
	void setCacheData(bool cd){if(cd == false) return; fprintf_s(mFile, "setAttr \".cd\" %i;\n", cd);}
	/*Turn on/off the caching of all rigid bodies.*/
	void setCacheData(const BoolID& cd){fprintf_s(mFile,"connectAttr \"");cd.write(mFile);fprintf_s(mFile,"\" \"%s.cd\";\n",mName.c_str());}
	/*Turn on/off the contact data output of the rigid bodies.*/
	void setContactData(bool ctd){if(ctd == false) return; fprintf_s(mFile, "setAttr \".ctd\" %i;\n", ctd);}
	/*Turn on/off the contact data output of the rigid bodies.*/
	void setContactData(const BoolID& ctd){fprintf_s(mFile,"connectAttr \"");ctd.write(mFile);fprintf_s(mFile,"\" \"%s.ctd\";\n",mName.c_str());}
	/*Turn on/off the solver*/
	void setState(bool stt){if(stt == true) return; fprintf_s(mFile, "setAttr \".stt\" %i;\n", stt);}
	/*Turn on/off the solver*/
	void setState(const BoolID& stt){fprintf_s(mFile,"connectAttr \"");stt.write(mFile);fprintf_s(mFile,"\" \"%s.stt\";\n",mName.c_str());}
	/*Indicates that this is the current solver.  The current solver is the one in which rigid bodies will be added to.*/
	void setCurrent(bool cur){if(cur == false) return; fprintf_s(mFile, "setAttr \".cur\" %i;\n", cur);}
	/*By requesting this attribute, the rigid solver will be forced to evaluate.*/
	void setForceDynamics(bool fdn){if(fdn == false) return; fprintf_s(mFile, "setAttr \".fdn\" %i;\n", fdn);}
	/*
	Allows the user to disconnect the connection made by the solver to
	the time and choice nodes.
	*/
	void setAllowDisconnection(bool ad){if(ad == false) return; fprintf_s(mFile, "setAttr \".ad\" %i;\n", ad);}
	/*This attribute is obsolete and should not be used.*/
	void setStatistics(bool st){if(st == false) return; fprintf_s(mFile, "setAttr \".st\" %i;\n", st);}
	/*This holds the value for time to be queried.*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*The start time of the animation in seconds.*/
	TimeID getStartTime(){char buffer[4096];sprintf_s (buffer, "%s.stm",mName.c_str());return (const char*)buffer;}
	/*Generalized force on the rigid bodies (forces and torques).*/
	const GeneralForceID& getGeneralForce(size_t gfr_i){char buffer[4096];sprintf_s (buffer, "%s.gfr[%i]",mName.c_str(),gfr_i);return (const char*)buffer;}
	/*Forces on the rigid bodies.*/
	const VectorArrayID& getInputForce(size_t gfr_i){char buffer[4096];sprintf_s (buffer, "%s.gfr[%i].ifr",mName.c_str(),gfr_i);return (const char*)buffer;}
	/*Torques on the rigid bodies.*/
	const VectorArrayID& getInputTorque(size_t gfr_i){char buffer[4096];sprintf_s (buffer, "%s.gfr[%i].itr",mName.c_str(),gfr_i);return (const char*)buffer;}
	/*Translation.*/
	const Double3ID& getTranslate(size_t t_i){char buffer[4096];sprintf_s (buffer, "%s.t[%i]",mName.c_str(),t_i);return (const char*)buffer;}
	/*Translate X.*/
	const DoubleID& getTranslateX(size_t t_i){char buffer[4096];sprintf_s (buffer, "%s.t[%i].tx",mName.c_str(),t_i);return (const char*)buffer;}
	/*Translate Y.*/
	const DoubleID& getTranslateY(size_t t_i){char buffer[4096];sprintf_s (buffer, "%s.t[%i].ty",mName.c_str(),t_i);return (const char*)buffer;}
	/*Translate Z.*/
	const DoubleID& getTranslateZ(size_t t_i){char buffer[4096];sprintf_s (buffer, "%s.t[%i].tz",mName.c_str(),t_i);return (const char*)buffer;}
	/*Rotation.*/
	const Double3ID& getRotate(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i]",mName.c_str(),r_i);return (const char*)buffer;}
	/*Rotate X.*/
	const DoubleID& getRotateX(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i].rx",mName.c_str(),r_i);return (const char*)buffer;}
	/*Rotate Y.*/
	const DoubleID& getRotateY(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i].ry",mName.c_str(),r_i);return (const char*)buffer;}
	/*Rotate Z.*/
	const DoubleID& getRotateZ(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i].rz",mName.c_str(),r_i);return (const char*)buffer;}
	/*Constraint Translation.*/
	const Double3ID& getConstraintTranslate(size_t ctr_i){char buffer[4096];sprintf_s (buffer, "%s.ctr[%i]",mName.c_str(),ctr_i);return (const char*)buffer;}
	/*Constraint Translate X.*/
	const DoubleID& getConstraintTranslateX(size_t ctr_i){char buffer[4096];sprintf_s (buffer, "%s.ctr[%i].ctx",mName.c_str(),ctr_i);return (const char*)buffer;}
	/*Constraint Translate Y.*/
	const DoubleID& getConstraintTranslateY(size_t ctr_i){char buffer[4096];sprintf_s (buffer, "%s.ctr[%i].cty",mName.c_str(),ctr_i);return (const char*)buffer;}
	/*Constraint Translate Z.*/
	const DoubleID& getConstraintTranslateZ(size_t ctr_i){char buffer[4096];sprintf_s (buffer, "%s.ctr[%i].ctz",mName.c_str(),ctr_i);return (const char*)buffer;}
	/*Constraint Rotation.*/
	const Double3ID& getConstraintRotate(size_t cr_i){char buffer[4096];sprintf_s (buffer, "%s.cr[%i]",mName.c_str(),cr_i);return (const char*)buffer;}
	/*Constraint Rotate X.*/
	const DoubleID& getConstraintRotateX(size_t cr_i){char buffer[4096];sprintf_s (buffer, "%s.cr[%i].crx",mName.c_str(),cr_i);return (const char*)buffer;}
	/*Constraint Rotate Y.*/
	const DoubleID& getConstraintRotateY(size_t cr_i){char buffer[4096];sprintf_s (buffer, "%s.cr[%i].cry",mName.c_str(),cr_i);return (const char*)buffer;}
	/*Constraint Rotate Z.*/
	const DoubleID& getConstraintRotateZ(size_t cr_i){char buffer[4096];sprintf_s (buffer, "%s.cr[%i].crz",mName.c_str(),cr_i);return (const char*)buffer;}
	/*Scale for the velocity vectors.*/
	DoubleID getScaleVelocity(){char buffer[4096];sprintf_s (buffer, "%s.svv",mName.c_str());return (const char*)buffer;}
	/*Rigid body solver method attribute*/
	UnsignedintID getSolverMethod(){char buffer[4096];sprintf_s (buffer, "%s.slm",mName.c_str());return (const char*)buffer;}
	/*Turn friction on/off.*/
	BoolID getFriction(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*Turn bounciness (sometimes referred to as restitution) on/off.*/
	BoolID getBounciness(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*Turn dynamics on/off.*/
	BoolID getDynamics(){char buffer[4096];sprintf_s (buffer, "%s.dyn",mName.c_str());return (const char*)buffer;}
	/*Calculate the solver tolerances.*/
	BoolID getAutoSolverTolerances(){char buffer[4096];sprintf_s (buffer, "%s.ast",mName.c_str());return (const char*)buffer;}
	/*Turn on/off the display velocity vector.*/
	BoolID getDisplayVelocity(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*Turn on/off the display of the center of mass icon.*/
	BoolID getDisplayCenterOfMass(){char buffer[4096];sprintf_s (buffer, "%s.dcom",mName.c_str());return (const char*)buffer;}
	/*Turn on/off the display of the constraint vector.*/
	BoolID getDisplayConstraint(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*Turn on/off labels for the rigid bodies and constraints in the solver.*/
	BoolID getDisplayLabel(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*Turn on/off the caching of all rigid bodies.*/
	BoolID getCacheData(){char buffer[4096];sprintf_s (buffer, "%s.cd",mName.c_str());return (const char*)buffer;}
	/*Turn on/off the contact data output of the rigid bodies.*/
	BoolID getContactData(){char buffer[4096];sprintf_s (buffer, "%s.ctd",mName.c_str());return (const char*)buffer;}
	/*Turn on/off the solver*/
	BoolID getState(){char buffer[4096];sprintf_s (buffer, "%s.stt",mName.c_str());return (const char*)buffer;}
protected:
	RigidSolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RIGIDSOLVER_H__
