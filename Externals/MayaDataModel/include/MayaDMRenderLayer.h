/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERLAYER_H__
#define __MayaDM_RENDERLAYER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> Objects can be grouped together and have their render controlled by a
 single renderLayer node.  The attributes of this node are parameters to
 the drawing of objects that are connected to it as members.
</pre></p>
*/
class RenderLayer : public DependNode
{
public:
	/*
	Parent attribute encapsulating per-object render layer
	information. When objects are added to the layer a connection
	will be made from this attribute to the object.
	*/
	struct RenderInfo{
		short identification;
		bool renderable;
		unsigned char drawColor;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", identification);
			fprintf_s(file,"%i ", renderable);
			fprintf_s(file,"%i", drawColor);
		}
	};
	/*Parent attribute encapsulating all render pass information*/
	struct RenderPassInfo{
		bool beauty;
		bool color;
		bool ambient;
		bool diffuse;
		bool specular;
		bool shadow;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", beauty);
			fprintf_s(file,"%i ", color);
			fprintf_s(file,"%i ", ambient);
			fprintf_s(file,"%i ", diffuse);
			fprintf_s(file,"%i ", specular);
			fprintf_s(file,"%i", shadow);
		}
	};
	/*This is a root of following mental ray attributes.*/
	struct MentalRayControls{
		bool globalIllum;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i", globalIllum);
		}
	};
	/*
	Collection of attribute value and input connection adjustments
	to be applied when the layer is active.
	*/
	struct Adjustments{
		void write(FILE* file) const
		{
		}
	};
	/*
	Collection of output connection adjustments to be applied when
	the layer is active.
	*/
	struct OutAdjustments{
		void write(FILE* file) const
		{
		}
	};
public:
	RenderLayer(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "renderLayer"){}
	virtual ~RenderLayer(){}
	/*
	If set every object in the scene is visible at render time. There
	DAG objects connected to the renderInfo attribute will be ignored.
	*/
	void setGlobal(bool g){if(g == false) return; fprintf_s(mFile, "setAttr \".g\" %i;\n", g);}
	/*
	If set every object in the scene is visible at render time. There
	DAG objects connected to the renderInfo attribute will be ignored.
	*/
	void setGlobal(const BoolID& g){fprintf_s(mFile,"connectAttr \"");g.write(mFile);fprintf_s(mFile,"\" \"%s.g\";\n",mName.c_str());}
	/*
	Parent attribute encapsulating per-object render layer
	information. When objects are added to the layer a connection
	will be made from this attribute to the object.
	*/
	void setRenderInfo(const RenderInfo& ri){fprintf_s(mFile, "setAttr \".ri\" ");ri.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Parent attribute encapsulating per-object render layer
	information. When objects are added to the layer a connection
	will be made from this attribute to the object.
	*/
	void setRenderInfo(const RenderInfoID& ri){fprintf_s(mFile,"connectAttr \"");ri.write(mFile);fprintf_s(mFile,"\" \"%s.ri\";\n",mName.c_str());}
	/*Render layer identification number*/
	void setIdentification(short rlid){if(rlid == 0) return; fprintf_s(mFile, "setAttr \".ri.rlid\" %i;\n", rlid);}
	/*Render layer identification number*/
	void setIdentification(const ShortID& rlid){fprintf_s(mFile,"connectAttr \"");rlid.write(mFile);fprintf_s(mFile,"\" \"%s.ri.rlid\";\n",mName.c_str());}
	/*Is this render layer visible when rendered?*/
	void setRenderable(bool rndr){if(rndr == true) return; fprintf_s(mFile, "setAttr \".ri.rndr\" %i;\n", rndr);}
	/*Is this render layer visible when rendered?*/
	void setRenderable(const BoolID& rndr){fprintf_s(mFile,"connectAttr \"");rndr.write(mFile);fprintf_s(mFile,"\" \"%s.ri.rndr\";\n",mName.c_str());}
	/*Color with which to draw*/
	void setDrawColor(unsigned char c){if(c == 0) return; fprintf_s(mFile, "setAttr \".ri.c\" %i;\n", c);}
	/*Color with which to draw*/
	void setDrawColor(const UnsignedcharID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.ri.c\";\n",mName.c_str());}
	/*
	Parent render layers of this render layer.
	This attribute can only be connected to the layerChildren attribute
	of another renderLayer node.
	*/
	void setLayerParent(short rlp){if(rlp == 0) return; fprintf_s(mFile, "setAttr \".rlp\" %i;\n", rlp);}
	/*
	Parent render layers of this render layer.
	This attribute can only be connected to the layerChildren attribute
	of another renderLayer node.
	*/
	void setLayerParent(const ShortID& rlp){fprintf_s(mFile,"connectAttr \"");rlp.write(mFile);fprintf_s(mFile,"\" \"%s.rlp\";\n",mName.c_str());}
	/*
	Child render layers contained within this render layer.
	Note that layer parenting is very restrictive: it should be
	thought of as "containing this layer within another layer". The rules
	regarding layer parenting require that no cycles are allowed,
	and no instancing within the same hierarchy is permitted.
	This attribute can only be connected from the layerParent attribute
	of another renderLayer node.
	*/
	void setLayerChildren(size_t rlc_i,short rlc){if(rlc == 0) return; fprintf_s(mFile, "setAttr \".rlc[%i]\" %i;\n", rlc_i,rlc);}
	/*Parent attribute encapsulating all render pass information*/
	void setRenderPassInfo(const RenderPassInfo& rp){fprintf_s(mFile, "setAttr \".rp\" ");rp.write(mFile);fprintf_s(mFile,";\n");}
	/*Parent attribute encapsulating all render pass information*/
	void setRenderPassInfo(const RenderPassInfoID& rp){fprintf_s(mFile,"connectAttr \"");rp.write(mFile);fprintf_s(mFile,"\" \"%s.rp\";\n",mName.c_str());}
	/*Output everything to one file*/
	void setBeauty(bool b){if(b == true) return; fprintf_s(mFile, "setAttr \".rp.b\" %i;\n", b);}
	/*Output everything to one file*/
	void setBeauty(const BoolID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.rp.b\";\n",mName.c_str());}
	/*Output color w/o shadows to file*/
	void setColor(bool cp){if(cp == false) return; fprintf_s(mFile, "setAttr \".rp.cp\" %i;\n", cp);}
	/*Output color w/o shadows to file*/
	void setColor(const BoolID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.rp.cp\";\n",mName.c_str());}
	/*Output ambient pass info to file*/
	void setAmbient(bool am){if(am == false) return; fprintf_s(mFile, "setAttr \".rp.am\" %i;\n", am);}
	/*Output ambient pass info to file*/
	void setAmbient(const BoolID& am){fprintf_s(mFile,"connectAttr \"");am.write(mFile);fprintf_s(mFile,"\" \"%s.rp.am\";\n",mName.c_str());}
	/*Output diffuse pass info to file*/
	void setDiffuse(bool di){if(di == false) return; fprintf_s(mFile, "setAttr \".rp.di\" %i;\n", di);}
	/*Output diffuse pass info to file*/
	void setDiffuse(const BoolID& di){fprintf_s(mFile,"connectAttr \"");di.write(mFile);fprintf_s(mFile,"\" \"%s.rp.di\";\n",mName.c_str());}
	/*Output specular pass info to file*/
	void setSpecular(bool sp){if(sp == false) return; fprintf_s(mFile, "setAttr \".rp.sp\" %i;\n", sp);}
	/*Output specular pass info to file*/
	void setSpecular(const BoolID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.rp.sp\";\n",mName.c_str());}
	/*Output shadow pass info to file*/
	void setShadow(bool s){if(s == false) return; fprintf_s(mFile, "setAttr \".rp.s\" %i;\n", s);}
	/*Output shadow pass info to file*/
	void setShadow(const BoolID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.rp.s\";\n",mName.c_str());}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*Output global illumination info to file. mental ray only.*/
	void setGlobalIllum(bool gp){if(gp == false) return; fprintf_s(mFile, "setAttr \".mrc.gp\" %i;\n", gp);}
	/*Output global illumination info to file. mental ray only.*/
	void setGlobalIllum(const BoolID& gp){fprintf_s(mFile,"connectAttr \"");gp.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gp\";\n",mName.c_str());}
	/*
	Collection of attribute value and input connection adjustments
	to be applied when the layer is active.
	*/
	void setAdjustments(size_t adjs_i,const Adjustments& adjs){fprintf_s(mFile, "setAttr \".adjs[%i]\" ",adjs_i);adjs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Collection of attribute value and input connection adjustments
	to be applied when the layer is active.
	*/
	void setAdjustments(size_t adjs_i,const AdjustmentsID& adjs){fprintf_s(mFile,"connectAttr \"");adjs.write(mFile);fprintf_s(mFile,"\" \"%s.adjs[%i]\";\n",mName.c_str(),adjs_i);}
	/*
	Value to be applied to the specified plug when the layer is
	active.
	*/
	void setValue(size_t adjs_i,const GenericID& val){fprintf_s(mFile,"connectAttr \"");val.write(mFile);fprintf_s(mFile,"\" \"%s.adjs[%i].val\";\n",mName.c_str(),adjs_i);}
	/*
	Collection of output connection adjustments to be applied when
	the layer is active.
	*/
	void setOutAdjustments(size_t oajs_i,const OutAdjustments& oajs){fprintf_s(mFile, "setAttr \".oajs[%i]\" ",oajs_i);oajs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Collection of output connection adjustments to be applied when
	the layer is active.
	*/
	void setOutAdjustments(size_t oajs_i,const OutAdjustmentsID& oajs){fprintf_s(mFile,"connectAttr \"");oajs.write(mFile);fprintf_s(mFile,"\" \"%s.oajs[%i]\";\n",mName.c_str(),oajs_i);}
	/*
	Output connection to be applied to the reference output plug when
	the layer is active.
	*/
	void setOutValue(size_t oajs_i,const GenericID& ovl){fprintf_s(mFile,"connectAttr \"");ovl.write(mFile);fprintf_s(mFile,"\" \"%s.oajs[%i].ovl\";\n",mName.c_str(),oajs_i);}
	/*
	Connection to shading group to be applied to all members when the
	layer is active. The shading group assignment will be locked and
	new components cannot be created when the layer is active.
	*/
	void setShadingGroupOverride(const MessageID& sgo){fprintf_s(mFile,"connectAttr \"");sgo.write(mFile);fprintf_s(mFile,"\" \"%s.sgo\";\n",mName.c_str());}
	/*
	A space separated <i>"attribute=value"</i> description of the
	DAG member attributes to be overridden when the layer is
	active. The specified attributes will be locked and cannot
	be changed when the layer is active.
	*/
	void setAttributeOverrideScript(const string& aos){if(aos == "NULL") return; fprintf_s(mFile, "setAttr \".aos\" -type \"string\" ");aos.write(mFile);fprintf_s(mFile,";\n");}
	/*
	A space separated <i>"attribute=value"</i> description of the
	DAG member attributes to be overridden when the layer is
	active. The specified attributes will be locked and cannot
	be changed when the layer is active.
	*/
	void setAttributeOverrideScript(const StringID& aos){fprintf_s(mFile,"connectAttr \"");aos.write(mFile);fprintf_s(mFile,"\" \"%s.aos\";\n",mName.c_str());}
	/*
	This attribute is used for interactive preview rendering only.
	Once the render layer is rendered in the render view,
	this attribute is set so that the user can recycle the image.
	*/
	void setImageRendered(const BoolID& ird){fprintf_s(mFile,"connectAttr \"");ird.write(mFile);fprintf_s(mFile,"\" \"%s.ird\";\n",mName.c_str());}
	/*
	This attribute is used for interactive preview rendering only.
	After the render layer is rendered in the render view,
	the user can set this attribute
	so that the image is reused for compositing
	instead of rerendered each time.
	*/
	void setRecycleImage(const BoolID& rci){fprintf_s(mFile,"connectAttr \"");rci.write(mFile);fprintf_s(mFile,"\" \"%s.rci\";\n",mName.c_str());}
	/*Stores the file name of the rendered image for recycling purpose.*/
	void setImageName(const StringID& img){fprintf_s(mFile,"connectAttr \"");img.write(mFile);fprintf_s(mFile,"\" \"%s.img\";\n",mName.c_str());}
	/*Display order number*/
	void setDisplayOrder(short do_){if(do_ == 0) return; fprintf_s(mFile, "setAttr \".do\" %i;\n", do_);}
	/*Display order number*/
	void setDisplayOrder(const ShortID& do_){fprintf_s(mFile,"connectAttr \"");do_.write(mFile);fprintf_s(mFile,"\" \"%s.do\";\n",mName.c_str());}
	/*PSD Blend Mode*/
	void setPsdBlendMode(short bm){if(bm == 0) return; fprintf_s(mFile, "setAttr \".bm\" %i;\n", bm);}
	/*PSD Blend Mode*/
	void setPsdBlendMode(const ShortID& bm){fprintf_s(mFile,"connectAttr \"");bm.write(mFile);fprintf_s(mFile,"\" \"%s.bm\";\n",mName.c_str());}
	/*PSD Alpha Channel*/
	void setPsdAlphaChannel(short ac){if(ac == 0) return; fprintf_s(mFile, "setAttr \".ac\" %i;\n", ac);}
	/*PSD Alpha Channel*/
	void setPsdAlphaChannel(const ShortID& ac){fprintf_s(mFile,"connectAttr \"");ac.write(mFile);fprintf_s(mFile,"\" \"%s.ac\";\n",mName.c_str());}
	/*
	If set every object in the scene is visible at render time. There
	DAG objects connected to the renderInfo attribute will be ignored.
	*/
	BoolID getGlobal(){char buffer[4096];sprintf_s (buffer, "%s.g",mName.c_str());return (const char*)buffer;}
	/*
	Parent attribute encapsulating per-object render layer
	information. When objects are added to the layer a connection
	will be made from this attribute to the object.
	*/
	RenderInfoID getRenderInfo(){char buffer[4096];sprintf_s (buffer, "%s.ri",mName.c_str());return (const char*)buffer;}
	/*Render layer identification number*/
	ShortID getIdentification(){char buffer[4096];sprintf_s (buffer, "%s.ri.rlid",mName.c_str());return (const char*)buffer;}
	/*Is this render layer visible when rendered?*/
	BoolID getRenderable(){char buffer[4096];sprintf_s (buffer, "%s.ri.rndr",mName.c_str());return (const char*)buffer;}
	/*Color with which to draw*/
	UnsignedcharID getDrawColor(){char buffer[4096];sprintf_s (buffer, "%s.ri.c",mName.c_str());return (const char*)buffer;}
	/*
	Parent render layers of this render layer.
	This attribute can only be connected to the layerChildren attribute
	of another renderLayer node.
	*/
	ShortID getLayerParent(){char buffer[4096];sprintf_s (buffer, "%s.rlp",mName.c_str());return (const char*)buffer;}
	/*Parent attribute encapsulating all render pass information*/
	RenderPassInfoID getRenderPassInfo(){char buffer[4096];sprintf_s (buffer, "%s.rp",mName.c_str());return (const char*)buffer;}
	/*Output everything to one file*/
	BoolID getBeauty(){char buffer[4096];sprintf_s (buffer, "%s.rp.b",mName.c_str());return (const char*)buffer;}
	/*Output color w/o shadows to file*/
	BoolID getColor(){char buffer[4096];sprintf_s (buffer, "%s.rp.cp",mName.c_str());return (const char*)buffer;}
	/*Output ambient pass info to file*/
	BoolID getAmbient(){char buffer[4096];sprintf_s (buffer, "%s.rp.am",mName.c_str());return (const char*)buffer;}
	/*Output diffuse pass info to file*/
	BoolID getDiffuse(){char buffer[4096];sprintf_s (buffer, "%s.rp.di",mName.c_str());return (const char*)buffer;}
	/*Output specular pass info to file*/
	BoolID getSpecular(){char buffer[4096];sprintf_s (buffer, "%s.rp.sp",mName.c_str());return (const char*)buffer;}
	/*Output shadow pass info to file*/
	BoolID getShadow(){char buffer[4096];sprintf_s (buffer, "%s.rp.s",mName.c_str());return (const char*)buffer;}
	/*This is a root of following mental ray attributes.*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*Output global illumination info to file. mental ray only.*/
	BoolID getGlobalIllum(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gp",mName.c_str());return (const char*)buffer;}
	/*
	Collection of attribute value and input connection adjustments
	to be applied when the layer is active.
	*/
	const AdjustmentsID& getAdjustments(size_t adjs_i){char buffer[4096];sprintf_s (buffer, "%s.adjs[%i]",mName.c_str(),adjs_i);return (const char*)buffer;}
	/*
	Value to be applied to the specified plug when the layer is
	active.
	*/
	const GenericID& getValue(size_t adjs_i){char buffer[4096];sprintf_s (buffer, "%s.adjs[%i].val",mName.c_str(),adjs_i);return (const char*)buffer;}
	/*
	Collection of output connection adjustments to be applied when
	the layer is active.
	*/
	const OutAdjustmentsID& getOutAdjustments(size_t oajs_i){char buffer[4096];sprintf_s (buffer, "%s.oajs[%i]",mName.c_str(),oajs_i);return (const char*)buffer;}
	/*
	Output connection to be applied to the reference output plug when
	the layer is active.
	*/
	const GenericID& getOutValue(size_t oajs_i){char buffer[4096];sprintf_s (buffer, "%s.oajs[%i].ovl",mName.c_str(),oajs_i);return (const char*)buffer;}
	/*
	Connection to shading group to be applied to all members when the
	layer is active. The shading group assignment will be locked and
	new components cannot be created when the layer is active.
	*/
	MessageID getShadingGroupOverride(){char buffer[4096];sprintf_s (buffer, "%s.sgo",mName.c_str());return (const char*)buffer;}
	/*
	A space separated <i>"attribute=value"</i> description of the
	DAG member attributes to be overridden when the layer is
	active. The specified attributes will be locked and cannot
	be changed when the layer is active.
	*/
	StringID getAttributeOverrideScript(){char buffer[4096];sprintf_s (buffer, "%s.aos",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is used for interactive preview rendering only.
	Once the render layer is rendered in the render view,
	this attribute is set so that the user can recycle the image.
	*/
	BoolID getImageRendered(){char buffer[4096];sprintf_s (buffer, "%s.ird",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is used for interactive preview rendering only.
	After the render layer is rendered in the render view,
	the user can set this attribute
	so that the image is reused for compositing
	instead of rerendered each time.
	*/
	BoolID getRecycleImage(){char buffer[4096];sprintf_s (buffer, "%s.rci",mName.c_str());return (const char*)buffer;}
	/*Stores the file name of the rendered image for recycling purpose.*/
	StringID getImageName(){char buffer[4096];sprintf_s (buffer, "%s.img",mName.c_str());return (const char*)buffer;}
	/*Display order number*/
	ShortID getDisplayOrder(){char buffer[4096];sprintf_s (buffer, "%s.do",mName.c_str());return (const char*)buffer;}
	/*PSD Blend Mode*/
	ShortID getPsdBlendMode(){char buffer[4096];sprintf_s (buffer, "%s.bm",mName.c_str());return (const char*)buffer;}
	/*PSD Alpha Channel*/
	ShortID getPsdAlphaChannel(){char buffer[4096];sprintf_s (buffer, "%s.ac",mName.c_str());return (const char*)buffer;}
protected:
	RenderLayer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RENDERLAYER_H__
