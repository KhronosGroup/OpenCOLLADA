/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MOTIONPATH_H__
#define __MayaDM_MOTIONPATH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This is the motionPath node which is used for the motionPath
 animation to compute the position and orientation, of the
 animated object, by evaluating the curve connected to the
 geometryPath attribute at the value provided by the uValue
 attribute.<p/>

 The basic node configuration for a motionPath animation
 is as follows:
<ol>
 <li>Create a motionPath node.</li>
 <li>Connect its geometryPath attribute to the curve node.</li>
 <li>Connect its allCoordinates attribute to the translate
    attribute of the transform of the animated object.</li>
 <li>Create an animCurveTL node and connect it to the uValue
    attribute of the motionPath node.</li>
 <li>Add some keyframes to the animCurve.</li>
</ol>
<pre>

      (animCurve)
                \
                 \
              (motionPath) --> (transform)
                 /
                /
         (curve)

</pre>
 For each keyframe created in the animCurve, a positionMarker is
 created and connected to the positionMarkerTime attribute of the
 motionPath node, and vice versa.
*/
class MotionPath : public DependNode
{
public:
public:
	MotionPath(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "motionPath"){}
	virtual ~MotionPath(){}
	/*u parameterization value for evaluating the path curve*/
	void setUValue(double u){if(u == 0) return; fprintf_s(mFile, "setAttr \".u\" %f;\n", u);}
	/*u parameterization value for evaluating the path curve*/
	void setUValue(const DoubleID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*Angle of rotation about the FRONT direction*/
	void setFrontTwist(double ft){if(ft == 0) return; fprintf_s(mFile, "setAttr \".ft\" %f;\n", ft);}
	/*Angle of rotation about the FRONT direction*/
	void setFrontTwist(const DoubleID& ft){fprintf_s(mFile,"connectAttr \"");ft.write(mFile);fprintf_s(mFile,"\" \"%s.ft\";\n",mName.c_str());}
	/*Angle of rotation about the UP direction*/
	void setUpTwist(double ut){if(ut == 0) return; fprintf_s(mFile, "setAttr \".ut\" %f;\n", ut);}
	/*Angle of rotation about the UP direction*/
	void setUpTwist(const DoubleID& ut){fprintf_s(mFile,"connectAttr \"");ut.write(mFile);fprintf_s(mFile,"\" \"%s.ut\";\n",mName.c_str());}
	/*Angle of rotation about the SIDE direction*/
	void setSideTwist(double st){if(st == 0) return; fprintf_s(mFile, "setAttr \".st\" %f;\n", st);}
	/*Angle of rotation about the SIDE direction*/
	void setSideTwist(const DoubleID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*The computed world space position*/
	void setAllCoordinates(const Double3ID& ac){fprintf_s(mFile,"connectAttr \"");ac.write(mFile);fprintf_s(mFile,"\" \"%s.ac\";\n",mName.c_str());}
	/*x-component of the current world space position*/
	void setXCoordinate(const DoubleID& xc){fprintf_s(mFile,"connectAttr \"");xc.write(mFile);fprintf_s(mFile,"\" \"%s.ac.xc\";\n",mName.c_str());}
	/*y-component of the current world space position*/
	void setYCoordinate(const DoubleID& yc){fprintf_s(mFile,"connectAttr \"");yc.write(mFile);fprintf_s(mFile,"\" \"%s.ac.yc\";\n",mName.c_str());}
	/*z-component of the current world space position*/
	void setZCoordinate(const DoubleID& zc){fprintf_s(mFile,"connectAttr \"");zc.write(mFile);fprintf_s(mFile,"\" \"%s.ac.zc\";\n",mName.c_str());}
	/*The computed world space orientation vectors*/
	void setOrientMatrix(const MatrixID& om){fprintf_s(mFile,"connectAttr \"");om.write(mFile);fprintf_s(mFile,"\" \"%s.om\";\n",mName.c_str());}
	/*The amount of world space rotations*/
	void setRotate(const Double3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Angle of rotation about the X-axis*/
	void setRotateX(const DoubleID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*Angle of rotation about the Y-axis*/
	void setRotateY(const DoubleID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*Angle of rotation about the Z-axis*/
	void setRotateZ(const DoubleID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*The order of rotations for the rotate attr*/
	void setRotateOrder(unsigned int ro){if(ro == 0) return; fprintf_s(mFile, "setAttr \".ro\" %i;\n", ro);}
	/*The order of rotations for the rotate attr*/
	void setRotateOrder(const UnsignedintID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*For exchanging messages with a flow node during computation of the lattice point positions*/
	void setFlowNode(const MessageID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn\";\n",mName.c_str());}
	/*The curve path data input to use*/
	void setGeometryPath(const GenericID& gp){fprintf_s(mFile,"connectAttr \"");gp.write(mFile);fprintf_s(mFile,"\" \"%s.gp\";\n",mName.c_str());}
	/*Times of the position markers*/
	void setPositionMarkerTime(size_t pmt_i,const TimeID& pmt){fprintf_s(mFile,"connectAttr \"");pmt.write(mFile);fprintf_s(mFile,"\" \"%s.pmt[%i]\";\n",mName.c_str(),pmt_i);}
	/*Times of the orientation markers*/
	void setOrientationMarkerTime(size_t omt_i,const TimeID& omt){fprintf_s(mFile,"connectAttr \"");omt.write(mFile);fprintf_s(mFile,"\" \"%s.omt[%i]\";\n",mName.c_str(),omt_i);}
	/*A flag to determine whether or not the FRONT direction of the animated object(s) be aligned to the tangent of the path*/
	void setFollow(bool f){if(f == false) return; fprintf_s(mFile, "setAttr \".f\" %i;\n", f);}
	/*OBSOLETE*/
	void setNormal(bool nr){if(nr == false) return; fprintf_s(mFile, "setAttr \".nr\" %i;\n", nr);}
	/*OBSOLETE*/
	void setNormal(const BoolID& nr){fprintf_s(mFile,"connectAttr \"");nr.write(mFile);fprintf_s(mFile,"\" \"%s.nr\";\n",mName.c_str());}
	/*A flag to determine whether or not the UP direction of the animated object(s) be aligned to the inverse of the computed up*/
	void setInverseUp(bool iu){if(iu == false) return; fprintf_s(mFile, "setAttr \".iu\" %i;\n", iu);}
	/*A flag to determine whether or not the UP direction of the animated object(s) be aligned to the inverse of the computed up*/
	void setInverseUp(const BoolID& iu){fprintf_s(mFile,"connectAttr \"");iu.write(mFile);fprintf_s(mFile,"\" \"%s.iu\";\n",mName.c_str());}
	/*A flag to determine whether or not the FRONT direction of the animated object(s) be aligned to the inverse of the computed front vector*/
	void setInverseFront(bool if_){if(if_ == false) return; fprintf_s(mFile, "setAttr \".if\" %i;\n", if_);}
	/*A flag to determine whether or not the FRONT direction of the animated object(s) be aligned to the inverse of the computed front vector*/
	void setInverseFront(const BoolID& if_){fprintf_s(mFile,"connectAttr \"");if_.write(mFile);fprintf_s(mFile,"\" \"%s.if\";\n",mName.c_str());}
	/*An index (x=0, y=1, z=2) to specify which local-axis of the animated object is aligned as the front direction*/
	void setFrontAxis(unsigned int fa){if(fa == 1) return; fprintf_s(mFile, "setAttr \".fa\" %i;\n", fa);}
	/*An index (x=0, y=1, z=2) to specify which local-axis of the animated object is aligned as the front direction*/
	void setFrontAxis(const UnsignedintID& fa){fprintf_s(mFile,"connectAttr \"");fa.write(mFile);fprintf_s(mFile,"\" \"%s.fa\";\n",mName.c_str());}
	/*An index (x=0, y=1, z=2) to specify which local-axis of the animated object is aligned as the up direction*/
	void setUpAxis(unsigned int ua){if(ua == 2) return; fprintf_s(mFile, "setAttr \".ua\" %i;\n", ua);}
	/*An index (x=0, y=1, z=2) to specify which local-axis of the animated object is aligned as the up direction*/
	void setUpAxis(const UnsignedintID& ua){fprintf_s(mFile,"connectAttr \"");ua.write(mFile);fprintf_s(mFile,"\" \"%s.ua\";\n",mName.c_str());}
	/*Indicates what to use as the world up vector*/
	void setWorldUpType(unsigned int wut){if(wut == 3) return; fprintf_s(mFile, "setAttr \".wut\" %i;\n", wut);}
	/*Indicates what to use as the world up vector*/
	void setWorldUpType(const UnsignedintID& wut){fprintf_s(mFile,"connectAttr \"");wut.write(mFile);fprintf_s(mFile,"\" \"%s.wut\";\n",mName.c_str());}
	/*World up vector*/
	void setWorldUpVector(const double3& wu){fprintf_s(mFile, "setAttr \".wu\" -type \"double3\" ");wu.write(mFile);fprintf_s(mFile,";\n");}
	/*World up vector*/
	void setWorldUpVector(const Double3ID& wu){fprintf_s(mFile,"connectAttr \"");wu.write(mFile);fprintf_s(mFile,"\" \"%s.wu\";\n",mName.c_str());}
	/*World up vector X component*/
	void setWorldUpVectorX(double wux){if(wux == 0.0) return; fprintf_s(mFile, "setAttr \".wu.wux\" %f;\n", wux);}
	/*World up vector X component*/
	void setWorldUpVectorX(const DoubleID& wux){fprintf_s(mFile,"connectAttr \"");wux.write(mFile);fprintf_s(mFile,"\" \"%s.wu.wux\";\n",mName.c_str());}
	/*World up vector Y component*/
	void setWorldUpVectorY(double wuy){if(wuy == 1.0) return; fprintf_s(mFile, "setAttr \".wu.wuy\" %f;\n", wuy);}
	/*World up vector Y component*/
	void setWorldUpVectorY(const DoubleID& wuy){fprintf_s(mFile,"connectAttr \"");wuy.write(mFile);fprintf_s(mFile,"\" \"%s.wu.wuy\";\n",mName.c_str());}
	/*World up vector Z component*/
	void setWorldUpVectorZ(double wuz){if(wuz == 0.0) return; fprintf_s(mFile, "setAttr \".wu.wuz\" %f;\n", wuz);}
	/*World up vector Z component*/
	void setWorldUpVectorZ(const DoubleID& wuz){fprintf_s(mFile,"connectAttr \"");wuz.write(mFile);fprintf_s(mFile,"\" \"%s.wu.wuz\";\n",mName.c_str());}
	/*World matrix for the up object*/
	void setWorldUpMatrix(const matrix& wum){if(wum == identity) return; fprintf_s(mFile, "setAttr \".wum\" -type \"matrix\" ");wum.write(mFile);fprintf_s(mFile,";\n");}
	/*World matrix for the up object*/
	void setWorldUpMatrix(const MatrixID& wum){fprintf_s(mFile,"connectAttr \"");wum.write(mFile);fprintf_s(mFile,"\" \"%s.wum\";\n",mName.c_str());}
	/*A flag to determine whether or not the UP direction of the animated object(s) be affected by the curvature of the path*/
	void setBank(bool b){if(b == false) return; fprintf_s(mFile, "setAttr \".b\" %i;\n", b);}
	/*A flag to determine whether or not the UP direction of the animated object(s) be affected by the curvature of the path*/
	void setBank(const BoolID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*Scale factor to amplify/reduce the banking angle*/
	void setBankScale(double bs){if(bs == 1.0) return; fprintf_s(mFile, "setAttr \".bs\" %f;\n", bs);}
	/*Scale factor to amplify/reduce the banking angle*/
	void setBankScale(const DoubleID& bs){fprintf_s(mFile,"connectAttr \"");bs.write(mFile);fprintf_s(mFile,"\" \"%s.bs\";\n",mName.c_str());}
	/*Maximum computed bank angle will be limited to this value*/
	void setBankLimit(double bl){if(bl == 9) return; fprintf_s(mFile, "setAttr \".bl\" %f;\n", bl);}
	/*Maximum computed bank angle will be limited to this value*/
	void setBankLimit(const DoubleID& bl){fprintf_s(mFile,"connectAttr \"");bl.write(mFile);fprintf_s(mFile,"\" \"%s.bl\";\n",mName.c_str());}
	/*When it is true the computation is based on the fraction of curve length instead of based on the parameter value*/
	void setFractionMode(bool fm){if(fm == false) return; fprintf_s(mFile, "setAttr \".fm\" %i;\n", fm);}
	/*u parameterization value for evaluating the path curve*/
	DoubleID getUValue(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*Angle of rotation about the FRONT direction*/
	DoubleID getFrontTwist(){char buffer[4096];sprintf_s (buffer, "%s.ft",mName.c_str());return (const char*)buffer;}
	/*Angle of rotation about the UP direction*/
	DoubleID getUpTwist(){char buffer[4096];sprintf_s (buffer, "%s.ut",mName.c_str());return (const char*)buffer;}
	/*Angle of rotation about the SIDE direction*/
	DoubleID getSideTwist(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*The computed world space position*/
	Double3ID getAllCoordinates(){char buffer[4096];sprintf_s (buffer, "%s.ac",mName.c_str());return (const char*)buffer;}
	/*x-component of the current world space position*/
	DoubleID getXCoordinate(){char buffer[4096];sprintf_s (buffer, "%s.ac.xc",mName.c_str());return (const char*)buffer;}
	/*y-component of the current world space position*/
	DoubleID getYCoordinate(){char buffer[4096];sprintf_s (buffer, "%s.ac.yc",mName.c_str());return (const char*)buffer;}
	/*z-component of the current world space position*/
	DoubleID getZCoordinate(){char buffer[4096];sprintf_s (buffer, "%s.ac.zc",mName.c_str());return (const char*)buffer;}
	/*The computed world space orientation vectors*/
	MatrixID getOrientMatrix(){char buffer[4096];sprintf_s (buffer, "%s.om",mName.c_str());return (const char*)buffer;}
	/*The amount of world space rotations*/
	Double3ID getRotate(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Angle of rotation about the X-axis*/
	DoubleID getRotateX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*Angle of rotation about the Y-axis*/
	DoubleID getRotateY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*Angle of rotation about the Z-axis*/
	DoubleID getRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*The order of rotations for the rotate attr*/
	UnsignedintID getRotateOrder(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*For exchanging messages with a flow node during computation of the lattice point positions*/
	MessageID getFlowNode(){char buffer[4096];sprintf_s (buffer, "%s.fn",mName.c_str());return (const char*)buffer;}
	/*The curve path data input to use*/
	GenericID getGeometryPath(){char buffer[4096];sprintf_s (buffer, "%s.gp",mName.c_str());return (const char*)buffer;}
	/*Times of the position markers*/
	const TimeID& getPositionMarkerTime(size_t pmt_i){char buffer[4096];sprintf_s (buffer, "%s.pmt[%i]",mName.c_str(),pmt_i);return (const char*)buffer;}
	/*Times of the orientation markers*/
	const TimeID& getOrientationMarkerTime(size_t omt_i){char buffer[4096];sprintf_s (buffer, "%s.omt[%i]",mName.c_str(),omt_i);return (const char*)buffer;}
	/*OBSOLETE*/
	BoolID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.nr",mName.c_str());return (const char*)buffer;}
	/*A flag to determine whether or not the UP direction of the animated object(s) be aligned to the inverse of the computed up*/
	BoolID getInverseUp(){char buffer[4096];sprintf_s (buffer, "%s.iu",mName.c_str());return (const char*)buffer;}
	/*A flag to determine whether or not the FRONT direction of the animated object(s) be aligned to the inverse of the computed front vector*/
	BoolID getInverseFront(){char buffer[4096];sprintf_s (buffer, "%s.if",mName.c_str());return (const char*)buffer;}
	/*An index (x=0, y=1, z=2) to specify which local-axis of the animated object is aligned as the front direction*/
	UnsignedintID getFrontAxis(){char buffer[4096];sprintf_s (buffer, "%s.fa",mName.c_str());return (const char*)buffer;}
	/*An index (x=0, y=1, z=2) to specify which local-axis of the animated object is aligned as the up direction*/
	UnsignedintID getUpAxis(){char buffer[4096];sprintf_s (buffer, "%s.ua",mName.c_str());return (const char*)buffer;}
	/*Indicates what to use as the world up vector*/
	UnsignedintID getWorldUpType(){char buffer[4096];sprintf_s (buffer, "%s.wut",mName.c_str());return (const char*)buffer;}
	/*World up vector*/
	Double3ID getWorldUpVector(){char buffer[4096];sprintf_s (buffer, "%s.wu",mName.c_str());return (const char*)buffer;}
	/*World up vector X component*/
	DoubleID getWorldUpVectorX(){char buffer[4096];sprintf_s (buffer, "%s.wu.wux",mName.c_str());return (const char*)buffer;}
	/*World up vector Y component*/
	DoubleID getWorldUpVectorY(){char buffer[4096];sprintf_s (buffer, "%s.wu.wuy",mName.c_str());return (const char*)buffer;}
	/*World up vector Z component*/
	DoubleID getWorldUpVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.wu.wuz",mName.c_str());return (const char*)buffer;}
	/*World matrix for the up object*/
	MatrixID getWorldUpMatrix(){char buffer[4096];sprintf_s (buffer, "%s.wum",mName.c_str());return (const char*)buffer;}
	/*A flag to determine whether or not the UP direction of the animated object(s) be affected by the curvature of the path*/
	BoolID getBank(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*Scale factor to amplify/reduce the banking angle*/
	DoubleID getBankScale(){char buffer[4096];sprintf_s (buffer, "%s.bs",mName.c_str());return (const char*)buffer;}
	/*Maximum computed bank angle will be limited to this value*/
	DoubleID getBankLimit(){char buffer[4096];sprintf_s (buffer, "%s.bl",mName.c_str());return (const char*)buffer;}
protected:
	MotionPath(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MOTIONPATH_H__
