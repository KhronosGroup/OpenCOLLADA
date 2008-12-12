/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RIGIDCONSTRAINT_H__
#define __MayaDM_RIGIDCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
<p><pre>        This node contains the attributes for the rigid constraints.  These
        constraints can only be used with rigid bodies.  The constraints include
      the following:

          nail:    Constrains a rigid body to a point in world space.

          pin:     Constrains two rigid bodies together.  By default the
                   constraint is created at the midpoint between the two rigid
                   bodies.

          hinge:   The hinge constrains the rigid body to an arbitrary axis
                   restricting it to two degrees of freedom.  This constraint can
                   act on one or two rigid bodies.  If one rigid body is selected
                   the body is hinged to a point in world space.  If two rigid
                   bodies are selected the two rigid bodies are hinged.  By default
                   the constraint is created at the midpoint between the two rigid bodies.

          spring:  The spring constraint creates a spring which can act on one
                   or two rigid bodies.  If one rigid body is selected a spring is
                   create which will constrain the rigid body to a point in world
                   space.  If two rigid bodies are selected a spring will be
                   created between the two rigid bodies.

          barrier: The barrier constraint limits the position of a rigid body to
                   one side of an arbitrary plane.  The constraint point is the
                   center of mass of the rigid body.

</pre></p>
*/
class RigidConstraint : public Transform
{
public:
public:
	RigidConstraint(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "rigidConstraint"){}
	virtual ~RigidConstraint(){}
	/*The first rigid body to be constrained.*/
	void setRigidBody1(const MessageID& rb1){fprintf_s(mFile,"connectAttr \"");rb1.write(mFile);fprintf_s(mFile,"\" \"%s.rb1\";\n",mName.c_str());}
	/*The second rigid body to be constrained.*/
	void setRigidBody2(const MessageID& rb2){fprintf_s(mFile,"connectAttr \"");rb2.write(mFile);fprintf_s(mFile,"\" \"%s.rb2\";\n",mName.c_str());}
	/*Constraint type.  The enum values are historical.*/
	void setConstraintType(unsigned int typ){if(typ == 1) return; fprintf_s(mFile, "setAttr \".typ\" %i;\n", typ);}
	/*Constraint type.  The enum values are historical.*/
	void setConstraintType(const UnsignedintID& typ){fprintf_s(mFile,"connectAttr \"");typ.write(mFile);fprintf_s(mFile,"\" \"%s.typ\";\n",mName.c_str());}
	/*Initial position of the rigid body constraint.*/
	void setInitialPosition(const double3& ip){if(ip == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".ip\" -type \"double3\" ");ip.write(mFile);fprintf_s(mFile,";\n");}
	/*The X component of the initial position.*/
	void setInitialPositionX(double ipx){if(ipx == 0.0) return; fprintf_s(mFile, "setAttr \".ip.ipx\" %f;\n", ipx);}
	/*The X component of the initial position.*/
	void setInitialPositionX(const DoubleID& ipx){fprintf_s(mFile,"connectAttr \"");ipx.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipx\";\n",mName.c_str());}
	/*The Y component of the initial position.*/
	void setInitialPositionY(double ipy){if(ipy == 0.0) return; fprintf_s(mFile, "setAttr \".ip.ipy\" %f;\n", ipy);}
	/*The Y component of the initial position.*/
	void setInitialPositionY(const DoubleID& ipy){fprintf_s(mFile,"connectAttr \"");ipy.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipy\";\n",mName.c_str());}
	/*The Z component of the initial position.*/
	void setInitialPositionZ(double ipz){if(ipz == 0.0) return; fprintf_s(mFile, "setAttr \".ip.ipz\" %f;\n", ipz);}
	/*The Z component of the initial position.*/
	void setInitialPositionZ(const DoubleID& ipz){fprintf_s(mFile,"connectAttr \"");ipz.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipz\";\n",mName.c_str());}
	/*velocity of the rigid constraint*/
	void setVelocity(const Double3ID& vel){fprintf_s(mFile,"connectAttr \"");vel.write(mFile);fprintf_s(mFile,"\" \"%s.vel\";\n",mName.c_str());}
	/*velocity x of the rigid constraint.*/
	void setVelocityX(const DoubleID& vlx){fprintf_s(mFile,"connectAttr \"");vlx.write(mFile);fprintf_s(mFile,"\" \"%s.vel.vlx\";\n",mName.c_str());}
	/*velocity y of the rigid constraint.*/
	void setVelocityY(const DoubleID& vly){fprintf_s(mFile,"connectAttr \"");vly.write(mFile);fprintf_s(mFile,"\" \"%s.vel.vly\";\n",mName.c_str());}
	/*velocity z of the rigid constraint.*/
	void setVelocityZ(const DoubleID& vlz){fprintf_s(mFile,"connectAttr \"");vlz.write(mFile);fprintf_s(mFile,"\" \"%s.vel.vlz\";\n",mName.c_str());}
	/*angularVelocity of the rigid constraint*/
	void setAngularVelocity(const Double3ID& avl){fprintf_s(mFile,"connectAttr \"");avl.write(mFile);fprintf_s(mFile,"\" \"%s.avl\";\n",mName.c_str());}
	/*angularVelocity x of the rigid constraint.*/
	void setAngularVelocityX(const DoubleID& avx){fprintf_s(mFile,"connectAttr \"");avx.write(mFile);fprintf_s(mFile,"\" \"%s.avl.avx\";\n",mName.c_str());}
	/*angularVelocity y of the rigid constraint.*/
	void setAngularVelocityY(const DoubleID& avy){fprintf_s(mFile,"connectAttr \"");avy.write(mFile);fprintf_s(mFile,"\" \"%s.avl.avy\";\n",mName.c_str());}
	/*angularVelocity z of the rigid constraint.*/
	void setAngularVelocityZ(const DoubleID& avz){fprintf_s(mFile,"connectAttr \"");avz.write(mFile);fprintf_s(mFile,"\" \"%s.avl.avz\";\n",mName.c_str());}
	/*The initial orientation of the rigid body constraint.*/
	void setInitialOrientation(const double3& ino){if(ino == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".ino\" -type \"double3\" ");ino.write(mFile);fprintf_s(mFile,";\n");}
	/*The X component of the initial orientation.*/
	void setInitialOrientationX(double iox){if(iox == 0) return; fprintf_s(mFile, "setAttr \".ino.iox\" %f;\n", iox);}
	/*The X component of the initial orientation.*/
	void setInitialOrientationX(const DoubleID& iox){fprintf_s(mFile,"connectAttr \"");iox.write(mFile);fprintf_s(mFile,"\" \"%s.ino.iox\";\n",mName.c_str());}
	/*The Y component of the initial orientation.*/
	void setInitialOrientationY(double ioy){if(ioy == 0) return; fprintf_s(mFile, "setAttr \".ino.ioy\" %f;\n", ioy);}
	/*The Y component of the initial orientation.*/
	void setInitialOrientationY(const DoubleID& ioy){fprintf_s(mFile,"connectAttr \"");ioy.write(mFile);fprintf_s(mFile,"\" \"%s.ino.ioy\";\n",mName.c_str());}
	/*The Z component of the initial orientation.*/
	void setInitialOrientationZ(double ioz){if(ioz == 0) return; fprintf_s(mFile, "setAttr \".ino.ioz\" %f;\n", ioz);}
	/*The Z component of the initial orientation.*/
	void setInitialOrientationZ(const DoubleID& ioz){fprintf_s(mFile,"connectAttr \"");ioz.write(mFile);fprintf_s(mFile,"\" \"%s.ino.ioz\";\n",mName.c_str());}
	/*spring constraint stiffness*/
	void setSpringStiffness(double sst){if(sst == 5.0) return; fprintf_s(mFile, "setAttr \".sst\" %f;\n", sst);}
	/*spring constraint stiffness*/
	void setSpringStiffness(const DoubleID& sst){fprintf_s(mFile,"connectAttr \"");sst.write(mFile);fprintf_s(mFile,"\" \"%s.sst\";\n",mName.c_str());}
	/*spring damping value.*/
	void setSpringDamping(double dmp){if(dmp == 0.1) return; fprintf_s(mFile, "setAttr \".dmp\" %f;\n", dmp);}
	/*spring damping value.*/
	void setSpringDamping(const DoubleID& dmp){fprintf_s(mFile,"connectAttr \"");dmp.write(mFile);fprintf_s(mFile,"\" \"%s.dmp\";\n",mName.c_str());}
	/*spring rest length.*/
	void setSpringRestLength(double srl){if(srl == 1.0) return; fprintf_s(mFile, "setAttr \".srl\" %f;\n", srl);}
	/*spring rest length.*/
	void setSpringRestLength(const DoubleID& srl){fprintf_s(mFile,"connectAttr \"");srl.write(mFile);fprintf_s(mFile,"\" \"%s.srl\";\n",mName.c_str());}
	/*interpenetration flag.*/
	void setInterpenetrate(bool int_){if(int_ == false) return; fprintf_s(mFile, "setAttr \".int\" %i;\n", int_);}
	/*interpenetration flag.*/
	void setInterpenetrate(const BoolID& int_){fprintf_s(mFile,"connectAttr \"");int_.write(mFile);fprintf_s(mFile,"\" \"%s.int\";\n",mName.c_str());}
	/*set if the rigid constraint is parented.*/
	void setIsParented(bool par){if(par == false) return; fprintf_s(mFile, "setAttr \".par\" %i;\n", par);}
	/*set if the rigid constraint is parented.*/
	void setIsParented(const BoolID& par){fprintf_s(mFile,"connectAttr \"");par.write(mFile);fprintf_s(mFile,"\" \"%s.par\";\n",mName.c_str());}
	/*
	indicates if the constraint is bounded to a bounding box.  Used so
	we do not clip the constraint when part of it is off the screen.
	*/
	void setIsBounded(const BoolID& bon){fprintf_s(mFile,"connectAttr \"");bon.write(mFile);fprintf_s(mFile,"\" \"%s.bon\";\n",mName.c_str());}
	/*this is the index into the solver multi attributes.*/
	void setSolverId(int sid){if(sid == -1) return; fprintf_s(mFile, "setAttr \".sid\" %i;\n", sid);}
	/*this is the index into the solver multi attributes.*/
	void setSolverId(const IntID& sid){fprintf_s(mFile,"connectAttr \"");sid.write(mFile);fprintf_s(mFile,"\" \"%s.sid\";\n",mName.c_str());}
	/*The rigid constraint is on or off in the simulator if true.*/
	void setConstrain(bool con){if(con == true) return; fprintf_s(mFile, "setAttr \".con\" %i;\n", con);}
	/*The rigid constraint is on or off in the simulator if true.*/
	void setConstrain(const BoolID& con){fprintf_s(mFile,"connectAttr \"");con.write(mFile);fprintf_s(mFile,"\" \"%s.con\";\n",mName.c_str());}
	/*Dtermines which rigid body the constraint shoul dbe recreated at.*/
	void setRelativeTo(unsigned int rlt){if(rlt == 0) return; fprintf_s(mFile, "setAttr \".rlt\" %i;\n", rlt);}
	/*Dtermines which rigid body the constraint shoul dbe recreated at.*/
	void setRelativeTo(const UnsignedintID& rlt){fprintf_s(mFile,"connectAttr \"");rlt.write(mFile);fprintf_s(mFile,"\" \"%s.rlt\";\n",mName.c_str());}
	/*position at which the constraint will be recreated at.*/
	void setUserDefinedPosition(const double3& udp){if(udp == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".udp\" -type \"double3\" ");udp.write(mFile);fprintf_s(mFile,";\n");}
	/*user defined position x.*/
	void setUserDefinedPositionX(double upx){if(upx == 0.0) return; fprintf_s(mFile, "setAttr \".udp.upx\" %f;\n", upx);}
	/*user defined position x.*/
	void setUserDefinedPositionX(const DoubleID& upx){fprintf_s(mFile,"connectAttr \"");upx.write(mFile);fprintf_s(mFile,"\" \"%s.udp.upx\";\n",mName.c_str());}
	/*user defined position y.*/
	void setUserDefinedPositionY(double upy){if(upy == 0.0) return; fprintf_s(mFile, "setAttr \".udp.upy\" %f;\n", upy);}
	/*user defined position y.*/
	void setUserDefinedPositionY(const DoubleID& upy){fprintf_s(mFile,"connectAttr \"");upy.write(mFile);fprintf_s(mFile,"\" \"%s.udp.upy\";\n",mName.c_str());}
	/*user defined position z.*/
	void setUserDefinedPositionZ(double upz){if(upz == 0.0) return; fprintf_s(mFile, "setAttr \".udp.upz\" %f;\n", upz);}
	/*user defined position z.*/
	void setUserDefinedPositionZ(const DoubleID& upz){fprintf_s(mFile,"connectAttr \"");upz.write(mFile);fprintf_s(mFile,"\" \"%s.udp.upz\";\n",mName.c_str());}
	/*The first rigid body to be constrained.*/
	MessageID getRigidBody1(){char buffer[4096];sprintf_s (buffer, "%s.rb1",mName.c_str());return (const char*)buffer;}
	/*The second rigid body to be constrained.*/
	MessageID getRigidBody2(){char buffer[4096];sprintf_s (buffer, "%s.rb2",mName.c_str());return (const char*)buffer;}
	/*Constraint type.  The enum values are historical.*/
	UnsignedintID getConstraintType(){char buffer[4096];sprintf_s (buffer, "%s.typ",mName.c_str());return (const char*)buffer;}
	/*The X component of the initial position.*/
	DoubleID getInitialPositionX(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the initial position.*/
	DoubleID getInitialPositionY(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the initial position.*/
	DoubleID getInitialPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipz",mName.c_str());return (const char*)buffer;}
	/*velocity of the rigid constraint*/
	Double3ID getVelocity(){char buffer[4096];sprintf_s (buffer, "%s.vel",mName.c_str());return (const char*)buffer;}
	/*velocity x of the rigid constraint.*/
	DoubleID getVelocityX(){char buffer[4096];sprintf_s (buffer, "%s.vel.vlx",mName.c_str());return (const char*)buffer;}
	/*velocity y of the rigid constraint.*/
	DoubleID getVelocityY(){char buffer[4096];sprintf_s (buffer, "%s.vel.vly",mName.c_str());return (const char*)buffer;}
	/*velocity z of the rigid constraint.*/
	DoubleID getVelocityZ(){char buffer[4096];sprintf_s (buffer, "%s.vel.vlz",mName.c_str());return (const char*)buffer;}
	/*angularVelocity of the rigid constraint*/
	Double3ID getAngularVelocity(){char buffer[4096];sprintf_s (buffer, "%s.avl",mName.c_str());return (const char*)buffer;}
	/*angularVelocity x of the rigid constraint.*/
	DoubleID getAngularVelocityX(){char buffer[4096];sprintf_s (buffer, "%s.avl.avx",mName.c_str());return (const char*)buffer;}
	/*angularVelocity y of the rigid constraint.*/
	DoubleID getAngularVelocityY(){char buffer[4096];sprintf_s (buffer, "%s.avl.avy",mName.c_str());return (const char*)buffer;}
	/*angularVelocity z of the rigid constraint.*/
	DoubleID getAngularVelocityZ(){char buffer[4096];sprintf_s (buffer, "%s.avl.avz",mName.c_str());return (const char*)buffer;}
	/*The X component of the initial orientation.*/
	DoubleID getInitialOrientationX(){char buffer[4096];sprintf_s (buffer, "%s.ino.iox",mName.c_str());return (const char*)buffer;}
	/*The Y component of the initial orientation.*/
	DoubleID getInitialOrientationY(){char buffer[4096];sprintf_s (buffer, "%s.ino.ioy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the initial orientation.*/
	DoubleID getInitialOrientationZ(){char buffer[4096];sprintf_s (buffer, "%s.ino.ioz",mName.c_str());return (const char*)buffer;}
	/*spring constraint stiffness*/
	DoubleID getSpringStiffness(){char buffer[4096];sprintf_s (buffer, "%s.sst",mName.c_str());return (const char*)buffer;}
	/*spring damping value.*/
	DoubleID getSpringDamping(){char buffer[4096];sprintf_s (buffer, "%s.dmp",mName.c_str());return (const char*)buffer;}
	/*spring rest length.*/
	DoubleID getSpringRestLength(){char buffer[4096];sprintf_s (buffer, "%s.srl",mName.c_str());return (const char*)buffer;}
	/*interpenetration flag.*/
	BoolID getInterpenetrate(){char buffer[4096];sprintf_s (buffer, "%s.int",mName.c_str());return (const char*)buffer;}
	/*set if the rigid constraint is parented.*/
	BoolID getIsParented(){char buffer[4096];sprintf_s (buffer, "%s.par",mName.c_str());return (const char*)buffer;}
	/*
	indicates if the constraint is bounded to a bounding box.  Used so
	we do not clip the constraint when part of it is off the screen.
	*/
	BoolID getIsBounded(){char buffer[4096];sprintf_s (buffer, "%s.bon",mName.c_str());return (const char*)buffer;}
	/*this is the index into the solver multi attributes.*/
	IntID getSolverId(){char buffer[4096];sprintf_s (buffer, "%s.sid",mName.c_str());return (const char*)buffer;}
	/*The rigid constraint is on or off in the simulator if true.*/
	BoolID getConstrain(){char buffer[4096];sprintf_s (buffer, "%s.con",mName.c_str());return (const char*)buffer;}
	/*Dtermines which rigid body the constraint shoul dbe recreated at.*/
	UnsignedintID getRelativeTo(){char buffer[4096];sprintf_s (buffer, "%s.rlt",mName.c_str());return (const char*)buffer;}
	/*user defined position x.*/
	DoubleID getUserDefinedPositionX(){char buffer[4096];sprintf_s (buffer, "%s.udp.upx",mName.c_str());return (const char*)buffer;}
	/*user defined position y.*/
	DoubleID getUserDefinedPositionY(){char buffer[4096];sprintf_s (buffer, "%s.udp.upy",mName.c_str());return (const char*)buffer;}
	/*user defined position z.*/
	DoubleID getUserDefinedPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.udp.upz",mName.c_str());return (const char*)buffer;}
protected:
	RigidConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RIGIDCONSTRAINT_H__
