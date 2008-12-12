/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NCOMPONENT_H__
#define __MayaDM_NCOMPONENT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
*/
class NComponent : public DependNode
{
public:
public:
	NComponent(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "nComponent"){}
	virtual ~NComponent(){}
	/*Input mesh*/
	void setSurface(const MeshID& srf){fprintf_s(mFile,"connectAttr \"");srf.write(mFile);fprintf_s(mFile,"\" \"%s.srf\";\n",mName.c_str());}
	/*
	Group Id
	Integer that idenifies the object group in the object
	*/
	void setComponentGroupId(int cid){if(cid == 0) return; fprintf_s(mFile, "setAttr \".cid\" %i;\n", cid);}
	/*
	Group Id
	Integer that idenifies the object group in the object
	*/
	void setComponentGroupId(const IntID& cid){fprintf_s(mFile,"connectAttr \"");cid.write(mFile);fprintf_s(mFile,"\" \"%s.cid\";\n",mName.c_str());}
	/*This specifies what kind of component is defined.*/
	void setComponentType(unsigned int ct){if(ct == 0) return; fprintf_s(mFile, "setAttr \".ct\" %i;\n", ct);}
	/*This specifies what kind of component is defined.*/
	void setComponentType(const UnsignedintID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*
	This specifies how to define the individual elements to use.
	If fromIndiceList is used then the ids of the points/edges or faces
	are explicitly defined in the componentIndice array, or come from a set
	if a set is connectected to this node. Borders is the full set of cvs, edges or
	faces that are on a border. (borders are edges that are only shared by one face)
	The component type determines if it is cvs,edges or faces.
	If all is used then the set of all cvs, edges or faces is used.
	*/
	void setElements(unsigned int el){if(el == 0) return; fprintf_s(mFile, "setAttr \".el\" %i;\n", el);}
	/*
	This specifies how to define the individual elements to use.
	If fromIndiceList is used then the ids of the points/edges or faces
	are explicitly defined in the componentIndice array, or come from a set
	if a set is connectected to this node. Borders is the full set of cvs, edges or
	faces that are on a border. (borders are edges that are only shared by one face)
	The component type determines if it is cvs,edges or faces.
	If all is used then the set of all cvs, edges or faces is used.
	*/
	void setElements(const UnsignedintID& el){fprintf_s(mFile,"connectAttr \"");el.write(mFile);fprintf_s(mFile,"\" \"%s.el\";\n",mName.c_str());}
	/*
	This constraints the overall strength of the constraint links created between this component
	and other components. If it is zero then all links to this component will have
	no effect. The strength of a particular link is scaled, or multiplied, by the strength of the two components
	it links. Note that if both components have a strength of 0.5 then the constraint link will have a strength
	of 0.25 (0.5*0.5). If either of the components have a strength of zero then the link will have no effect.
	*/
	void setStrength(double stn){if(stn == 1.0) return; fprintf_s(mFile, "setAttr \".stn\" %f;\n", stn);}
	/*
	This constraints the overall strength of the constraint links created between this component
	and other components. If it is zero then all links to this component will have
	no effect. The strength of a particular link is scaled, or multiplied, by the strength of the two components
	it links. Note that if both components have a strength of 0.5 then the constraint link will have a strength
	of 0.25 (0.5*0.5). If either of the components have a strength of zero then the link will have no effect.
	*/
	void setStrength(const DoubleID& stn){fprintf_s(mFile,"connectAttr \"");stn.write(mFile);fprintf_s(mFile,"\" \"%s.stn\";\n",mName.c_str());}
	/*
	Map the strength based on uv texture. The texture value scales the strength attribute value.
	Where the texture is black links to components will have no effect.
	*/
	void setStrengthMap(float stnm){if(stnm == 1.0) return; fprintf_s(mFile, "setAttr \".stnm\" %f;\n", stnm);}
	/*
	Map the strength based on uv texture. The texture value scales the strength attribute value.
	Where the texture is black links to components will have no effect.
	*/
	void setStrengthMap(const FloatID& stnm){fprintf_s(mFile,"connectAttr \"");stnm.write(mFile);fprintf_s(mFile,"\" \"%s.stnm\";\n",mName.c_str());}
	/*Per-vertex strength for the nComponent*/
	void setStrengthPerVertex(const doubleArray& spv){if(spv.size == 0) return; fprintf_s(mFile, "setAttr \".spv\" -type \"doubleArray\" ");spv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex strength for the nComponent*/
	void setStrengthPerVertex(const DoubleArrayID& spv){fprintf_s(mFile,"connectAttr \"");spv.write(mFile);fprintf_s(mFile,"\" \"%s.spv\";\n",mName.c_str());}
	/*
	This scales the constraint glue strength value used for links with this component.
	When this value is 1.0 then links formed will not break, providing that the glue strength
	on the constraint node is also 1.0. For values lower than 1.0 a link may break during simulation
	if sufficient strain is applied to the link.
	*/
	void setGlueStrength(double gst){if(gst == 1.0) return; fprintf_s(mFile, "setAttr \".gst\" %f;\n", gst);}
	/*
	This scales the constraint glue strength value used for links with this component.
	When this value is 1.0 then links formed will not break, providing that the glue strength
	on the constraint node is also 1.0. For values lower than 1.0 a link may break during simulation
	if sufficient strain is applied to the link.
	*/
	void setGlueStrength(const DoubleID& gst){fprintf_s(mFile,"connectAttr \"");gst.write(mFile);fprintf_s(mFile,"\" \"%s.gst\";\n",mName.c_str());}
	/*
	Map the glue strength based on uv texture. The texture value scales the glue strength attribute value.
	Where the texture is black the links to components will have no effect.
	*/
	void setGlueStrengthMap(float gstm){if(gstm == 1.0) return; fprintf_s(mFile, "setAttr \".gstm\" %f;\n", gstm);}
	/*
	Map the glue strength based on uv texture. The texture value scales the glue strength attribute value.
	Where the texture is black the links to components will have no effect.
	*/
	void setGlueStrengthMap(const FloatID& gstm){fprintf_s(mFile,"connectAttr \"");gstm.write(mFile);fprintf_s(mFile,"\" \"%s.gstm\";\n",mName.c_str());}
	/*Per-vertex glue strength for the nComponent*/
	void setGlueStrengthPerVertex(const doubleArray& gspv){if(gspv.size == 0) return; fprintf_s(mFile, "setAttr \".gspv\" -type \"doubleArray\" ");gspv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex glue strength for the nComponent*/
	void setGlueStrengthPerVertex(const DoubleArrayID& gspv){fprintf_s(mFile,"connectAttr \"");gspv.write(mFile);fprintf_s(mFile,"\" \"%s.gspv\";\n",mName.c_str());}
	/*
	This controls how much this component influences or pushes other components
	constrainted to it. If the value is zero then this component can be
	pushed by other components but does not influence the motion of the objects
	constraint to it.
	*/
	void setWeight(double wgh){if(wgh == 1.0) return; fprintf_s(mFile, "setAttr \".wgh\" %f;\n", wgh);}
	/*
	This controls how much this component influences or pushes other components
	constrainted to it. If the value is zero then this component can be
	pushed by other components but does not influence the motion of the objects
	constraint to it.
	*/
	void setWeight(const DoubleID& wgh){fprintf_s(mFile,"connectAttr \"");wgh.write(mFile);fprintf_s(mFile,"\" \"%s.wgh\";\n",mName.c_str());}
	/*
	Map the weight based on uv texture. The texture value scales the weight attribute value.
	Where the texture is black the components will have no influence.
	*/
	void setWeightMap(float wemp){if(wemp == 1.0) return; fprintf_s(mFile, "setAttr \".wemp\" %f;\n", wemp);}
	/*
	Map the weight based on uv texture. The texture value scales the weight attribute value.
	Where the texture is black the components will have no influence.
	*/
	void setWeightMap(const FloatID& wemp){fprintf_s(mFile,"connectAttr \"");wemp.write(mFile);fprintf_s(mFile,"\" \"%s.wemp\";\n",mName.c_str());}
	/*Per-vertex weight for the nComponent*/
	void setWeightPerVertex(const doubleArray& wpv){if(wpv.size == 0) return; fprintf_s(mFile, "setAttr \".wpv\" -type \"doubleArray\" ");wpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex weight for the nComponent*/
	void setWeightPerVertex(const DoubleArrayID& wpv){fprintf_s(mFile,"connectAttr \"");wpv.write(mFile);fprintf_s(mFile,"\" \"%s.wpv\";\n",mName.c_str());}
	/*
	When this component is a face, this controls how stiff the constraint
	is to the angle of the link with the face. For component types other
	than faces it has no effect.
	*/
	void setTangentStrength(double tst){if(tst == 0.5) return; fprintf_s(mFile, "setAttr \".tst\" %f;\n", tst);}
	/*
	When this component is a face, this controls how stiff the constraint
	is to the angle of the link with the face. For component types other
	than faces it has no effect.
	*/
	void setTangentStrength(const DoubleID& tst){fprintf_s(mFile,"connectAttr \"");tst.write(mFile);fprintf_s(mFile,"\" \"%s.tst\";\n",mName.c_str());}
	/*This is the id of the nucleus object that has the components.*/
	void setObjectId(const GenericID& obid){fprintf_s(mFile,"connectAttr \"");obid.write(mFile);fprintf_s(mFile,"\" \"%s.obid\";\n",mName.c_str());}
	/*Array of indices of the nobject component.*/
	void setComponentIndices(size_t ci_i,int ci){if(ci == 0) return; fprintf_s(mFile, "setAttr \".ci[%i]\" %i;\n", ci_i,ci);}
	/*Array of indices of the nobject component.*/
	void setComponentIndices(size_t ci_i,const IntID& ci){fprintf_s(mFile,"connectAttr \"");ci.write(mFile);fprintf_s(mFile,"\" \"%s.ci[%i]\";\n",mName.c_str(),ci_i);}
	/*This is the id of the nucleus component created by this node.*/
	void setOutComponent(const NIdID& ocp){fprintf_s(mFile,"connectAttr \"");ocp.write(mFile);fprintf_s(mFile,"\" \"%s.ocp\";\n",mName.c_str());}
	/*What type of strength map to use: per-vertex, texture or none.*/
	void setStrengthMapType(unsigned int smt){if(smt == 2) return; fprintf_s(mFile, "setAttr \".smt\" %i;\n", smt);}
	/*What type of strength map to use: per-vertex, texture or none.*/
	void setStrengthMapType(const UnsignedintID& smt){fprintf_s(mFile,"connectAttr \"");smt.write(mFile);fprintf_s(mFile,"\" \"%s.smt\";\n",mName.c_str());}
	/*What type of glue strength map to use: per-vertex, texture or none.*/
	void setGlueStrengthMapType(unsigned int gsmt){if(gsmt == 2) return; fprintf_s(mFile, "setAttr \".gsmt\" %i;\n", gsmt);}
	/*What type of glue strength map to use: per-vertex, texture or none.*/
	void setGlueStrengthMapType(const UnsignedintID& gsmt){fprintf_s(mFile,"connectAttr \"");gsmt.write(mFile);fprintf_s(mFile,"\" \"%s.gsmt\";\n",mName.c_str());}
	/*What type of weight map to use: per-vertex, texture or none.*/
	void setWeightMapType(unsigned int wmt){if(wmt == 2) return; fprintf_s(mFile, "setAttr \".wmt\" %i;\n", wmt);}
	/*What type of weight map to use: per-vertex, texture or none.*/
	void setWeightMapType(const UnsignedintID& wmt){fprintf_s(mFile,"connectAttr \"");wmt.write(mFile);fprintf_s(mFile,"\" \"%s.wmt\";\n",mName.c_str());}
	/*Input mesh*/
	MeshID getSurface(){char buffer[4096];sprintf_s (buffer, "%s.srf",mName.c_str());return (const char*)buffer;}
	/*
	Group Id
	Integer that idenifies the object group in the object
	*/
	IntID getComponentGroupId(){char buffer[4096];sprintf_s (buffer, "%s.cid",mName.c_str());return (const char*)buffer;}
	/*This specifies what kind of component is defined.*/
	UnsignedintID getComponentType(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*
	This specifies how to define the individual elements to use.
	If fromIndiceList is used then the ids of the points/edges or faces
	are explicitly defined in the componentIndice array, or come from a set
	if a set is connectected to this node. Borders is the full set of cvs, edges or
	faces that are on a border. (borders are edges that are only shared by one face)
	The component type determines if it is cvs,edges or faces.
	If all is used then the set of all cvs, edges or faces is used.
	*/
	UnsignedintID getElements(){char buffer[4096];sprintf_s (buffer, "%s.el",mName.c_str());return (const char*)buffer;}
	/*
	This constraints the overall strength of the constraint links created between this component
	and other components. If it is zero then all links to this component will have
	no effect. The strength of a particular link is scaled, or multiplied, by the strength of the two components
	it links. Note that if both components have a strength of 0.5 then the constraint link will have a strength
	of 0.25 (0.5*0.5). If either of the components have a strength of zero then the link will have no effect.
	*/
	DoubleID getStrength(){char buffer[4096];sprintf_s (buffer, "%s.stn",mName.c_str());return (const char*)buffer;}
	/*
	Map the strength based on uv texture. The texture value scales the strength attribute value.
	Where the texture is black links to components will have no effect.
	*/
	FloatID getStrengthMap(){char buffer[4096];sprintf_s (buffer, "%s.stnm",mName.c_str());return (const char*)buffer;}
	/*Per-vertex strength for the nComponent*/
	DoubleArrayID getStrengthPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.spv",mName.c_str());return (const char*)buffer;}
	/*
	This scales the constraint glue strength value used for links with this component.
	When this value is 1.0 then links formed will not break, providing that the glue strength
	on the constraint node is also 1.0. For values lower than 1.0 a link may break during simulation
	if sufficient strain is applied to the link.
	*/
	DoubleID getGlueStrength(){char buffer[4096];sprintf_s (buffer, "%s.gst",mName.c_str());return (const char*)buffer;}
	/*
	Map the glue strength based on uv texture. The texture value scales the glue strength attribute value.
	Where the texture is black the links to components will have no effect.
	*/
	FloatID getGlueStrengthMap(){char buffer[4096];sprintf_s (buffer, "%s.gstm",mName.c_str());return (const char*)buffer;}
	/*Per-vertex glue strength for the nComponent*/
	DoubleArrayID getGlueStrengthPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.gspv",mName.c_str());return (const char*)buffer;}
	/*
	This controls how much this component influences or pushes other components
	constrainted to it. If the value is zero then this component can be
	pushed by other components but does not influence the motion of the objects
	constraint to it.
	*/
	DoubleID getWeight(){char buffer[4096];sprintf_s (buffer, "%s.wgh",mName.c_str());return (const char*)buffer;}
	/*
	Map the weight based on uv texture. The texture value scales the weight attribute value.
	Where the texture is black the components will have no influence.
	*/
	FloatID getWeightMap(){char buffer[4096];sprintf_s (buffer, "%s.wemp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex weight for the nComponent*/
	DoubleArrayID getWeightPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.wpv",mName.c_str());return (const char*)buffer;}
	/*
	When this component is a face, this controls how stiff the constraint
	is to the angle of the link with the face. For component types other
	than faces it has no effect.
	*/
	DoubleID getTangentStrength(){char buffer[4096];sprintf_s (buffer, "%s.tst",mName.c_str());return (const char*)buffer;}
	/*This is the id of the nucleus object that has the components.*/
	GenericID getObjectId(){char buffer[4096];sprintf_s (buffer, "%s.obid",mName.c_str());return (const char*)buffer;}
	/*Array of indices of the nobject component.*/
	const IntID& getComponentIndices(size_t ci_i){char buffer[4096];sprintf_s (buffer, "%s.ci[%i]",mName.c_str(),ci_i);return (const char*)buffer;}
	/*This is the id of the nucleus component created by this node.*/
	NIdID getOutComponent(){char buffer[4096];sprintf_s (buffer, "%s.ocp",mName.c_str());return (const char*)buffer;}
	/*What type of strength map to use: per-vertex, texture or none.*/
	UnsignedintID getStrengthMapType(){char buffer[4096];sprintf_s (buffer, "%s.smt",mName.c_str());return (const char*)buffer;}
	/*What type of glue strength map to use: per-vertex, texture or none.*/
	UnsignedintID getGlueStrengthMapType(){char buffer[4096];sprintf_s (buffer, "%s.gsmt",mName.c_str());return (const char*)buffer;}
	/*What type of weight map to use: per-vertex, texture or none.*/
	UnsignedintID getWeightMapType(){char buffer[4096];sprintf_s (buffer, "%s.wmt",mName.c_str());return (const char*)buffer;}
protected:
	NComponent(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NCOMPONENT_H__
