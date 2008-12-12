/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GEOMETRYSHAPE_H__
#define __MayaDM_GEOMETRYSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
<p><pre>
        This class describes the attributes of TgeometryShape

</pre></p>
*/
class GeometryShape : public Shape
{
public:
	/*
	An instanced attribute array of compound attributes used to
	represent complement "set" membership information.
	Connections are made to this attribute if the entire
	instance is in a set and connections are made to the children of
	this attribute if portions of this attribute are in sets.
	*/
	struct CompInstObjGroups{
		/*
		An array of compound attributes used to identify the parts of the
		object that are in various sets. Each element in the array refers
		to the membership in one set.
		*/
		struct CompObjectGroups{
			componentList compObjectGrpCompList;
			int compObjectGroupId;
			void write(FILE* file) const
			{
				compObjectGrpCompList.write(file);
				fprintf_s(file, " ");
				fprintf_s(file,"%i", compObjectGroupId);
			}
		}* compObjectGroups;
		void write(FILE* file) const
		{
			size_t size = sizeof(compObjectGroups)/sizeof(CompObjectGroups);
			for(size_t i=0; i<size; ++i)
			{
				compObjectGroups[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	GeometryShape(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "geometryShape"){}
	virtual ~GeometryShape(){}
	/*What type of render geometry is this? 0 = surface, 1 = volume, 2 = glow*/
	void setRenderType(short rt){if(rt == 0) return; fprintf_s(mFile, "setAttr \".rt\" %i;\n", rt);}
	/*What type of render geometry is this? 0 = surface, 1 = volume, 2 = glow*/
	void setRenderType(const ShortID& rt){fprintf_s(mFile,"connectAttr \"");rt.write(mFile);fprintf_s(mFile,"\" \"%s.rt\";\n",mName.c_str());}
	/*Render this node as volume?*/
	void setRenderVolume(bool rv){if(rv == false) return; fprintf_s(mFile, "setAttr \".rv\" %i;\n", rv);}
	/*Render this node as volume?*/
	void setRenderVolume(const BoolID& rv){fprintf_s(mFile,"connectAttr \"");rv.write(mFile);fprintf_s(mFile,"\" \"%s.rv\";\n",mName.c_str());}
	/*visible fraction of the geometry when rendered as glow*/
	void setVisibleFraction(float vf){if(vf == 1.0f) return; fprintf_s(mFile, "setAttr \".vf\" %f;\n", vf);}
	/*visible fraction of the geometry when rendered as glow*/
	void setVisibleFraction(const FloatID& vf){fprintf_s(mFile,"connectAttr \"");vf.write(mFile);fprintf_s(mFile,"\" \"%s.vf\";\n",mName.c_str());}
	/*The flag to control if this object must be motion blurred*/
	void setMotionBlur(bool mb){if(mb == true) return; fprintf_s(mFile, "setAttr \".mb\" %i;\n", mb);}
	/*The flag to control if this object must be motion blurred*/
	void setMotionBlur(const BoolID& mb){fprintf_s(mFile,"connectAttr \"");mb.write(mFile);fprintf_s(mFile,"\" \"%s.mb\";\n",mName.c_str());}
	/*The flag to control if this object is visible in reflections.*/
	void setVisibleInReflections(bool vir){if(vir == false) return; fprintf_s(mFile, "setAttr \".vir\" %i;\n", vir);}
	/*The flag to control if this object is visible in reflections.*/
	void setVisibleInReflections(const BoolID& vir){fprintf_s(mFile,"connectAttr \"");vir.write(mFile);fprintf_s(mFile,"\" \"%s.vir\";\n",mName.c_str());}
	/*The flag to control if this object is visible in refractions.*/
	void setVisibleInRefractions(bool vif){if(vif == false) return; fprintf_s(mFile, "setAttr \".vif\" %i;\n", vif);}
	/*The flag to control if this object is visible in refractions.*/
	void setVisibleInRefractions(const BoolID& vif){fprintf_s(mFile,"connectAttr \"");vif.write(mFile);fprintf_s(mFile,"\" \"%s.vif\";\n",mName.c_str());}
	/*The flag to control if this object casts shadows.*/
	void setCastsShadows(bool csh){if(csh == true) return; fprintf_s(mFile, "setAttr \".csh\" %i;\n", csh);}
	/*The flag to control if this object casts shadows.*/
	void setCastsShadows(const BoolID& csh){fprintf_s(mFile,"connectAttr \"");csh.write(mFile);fprintf_s(mFile,"\" \"%s.csh\";\n",mName.c_str());}
	/*The flag to control if this object casts shadows.*/
	void setReceiveShadows(bool rcsh){if(rcsh == true) return; fprintf_s(mFile, "setAttr \".rcsh\" %i;\n", rcsh);}
	/*The flag to control if this object casts shadows.*/
	void setReceiveShadows(const BoolID& rcsh){fprintf_s(mFile,"connectAttr \"");rcsh.write(mFile);fprintf_s(mFile,"\" \"%s.rcsh\";\n",mName.c_str());}
	/*The flag to control if this surface should override global motion blur max visibility sample settings.*/
	void setMaxVisibilitySamplesOverride(bool vbo){if(vbo == false) return; fprintf_s(mFile, "setAttr \".vbo\" %i;\n", vbo);}
	/*The flag to control if this surface should override global motion blur max visibility sample settings.*/
	void setMaxVisibilitySamplesOverride(const BoolID& vbo){fprintf_s(mFile,"connectAttr \"");vbo.write(mFile);fprintf_s(mFile,"\" \"%s.vbo\";\n",mName.c_str());}
	/*Specifies the max number of motion blur visibility samples to be taken for this surface during rendering.*/
	void setMaxVisibilitySamples(int mvs){if(mvs == 1) return; fprintf_s(mFile, "setAttr \".mvs\" %i;\n", mvs);}
	/*Specifies the max number of motion blur visibility samples to be taken for this surface during rendering.*/
	void setMaxVisibilitySamples(const IntID& mvs){fprintf_s(mFile,"connectAttr \"");mvs.write(mFile);fprintf_s(mFile,"\" \"%s.mvs\";\n",mName.c_str());}
	/*The flag to control if this surface should override geometry anti-aliasing settings.*/
	void setGeometryAntialiasingOverride(bool gao){if(gao == false) return; fprintf_s(mFile, "setAttr \".gao\" %i;\n", gao);}
	/*The flag to control if this surface should override geometry anti-aliasing settings.*/
	void setGeometryAntialiasingOverride(const BoolID& gao){fprintf_s(mFile,"connectAttr \"");gao.write(mFile);fprintf_s(mFile,"\" \"%s.gao\";\n",mName.c_str());}
	/*Specifies the geometry anti-aliasing level that should be taken for this surface during rendering.*/
	void setAntialiasingLevel(int gal){if(gal == 1) return; fprintf_s(mFile, "setAttr \".gal\" %i;\n", gal);}
	/*Specifies the geometry anti-aliasing level that should be taken for this surface during rendering.*/
	void setAntialiasingLevel(const IntID& gal){fprintf_s(mFile,"connectAttr \"");gal.write(mFile);fprintf_s(mFile,"\" \"%s.gal\";\n",mName.c_str());}
	/*The flag to control if this surface should override global shading sample settings.*/
	void setShadingSamplesOverride(bool sso){if(sso == false) return; fprintf_s(mFile, "setAttr \".sso\" %i;\n", sso);}
	/*The flag to control if this surface should override global shading sample settings.*/
	void setShadingSamplesOverride(const BoolID& sso){fprintf_s(mFile,"connectAttr \"");sso.write(mFile);fprintf_s(mFile,"\" \"%s.sso\";\n",mName.c_str());}
	/*Specifies the minimum number of shading samples should be taken for this surface during rendering.*/
	void setShadingSamples(int ssa){if(ssa == 1) return; fprintf_s(mFile, "setAttr \".ssa\" %i;\n", ssa);}
	/*Specifies the minimum number of shading samples should be taken for this surface during rendering.*/
	void setShadingSamples(const IntID& ssa){fprintf_s(mFile,"connectAttr \"");ssa.write(mFile);fprintf_s(mFile,"\" \"%s.ssa\";\n",mName.c_str());}
	/*Specifies the max number of shading samples can be taken for this surface during rendering.*/
	void setMaxShadingSamples(int msa){if(msa == 1) return; fprintf_s(mFile, "setAttr \".msa\" %i;\n", msa);}
	/*Specifies the max number of shading samples can be taken for this surface during rendering.*/
	void setMaxShadingSamples(const IntID& msa){fprintf_s(mFile,"connectAttr \"");msa.write(mFile);fprintf_s(mFile,"\" \"%s.msa\";\n",mName.c_str());}
	/*The flag to control if this object should override global volume shading settings.*/
	void setVolumeSamplesOverride(bool vso){if(vso == false) return; fprintf_s(mFile, "setAttr \".vso\" %i;\n", vso);}
	/*The flag to control if this object should override global volume shading settings.*/
	void setVolumeSamplesOverride(const BoolID& vso){fprintf_s(mFile,"connectAttr \"");vso.write(mFile);fprintf_s(mFile,"\" \"%s.vso\";\n",mName.c_str());}
	/*Specifies the number of volume samples to be taken when rendering this volume.*/
	void setVolumeSamples(int vss){if(vss == 1) return; fprintf_s(mFile, "setAttr \".vss\" %i;\n", vss);}
	/*Specifies the number of volume samples to be taken when rendering this volume.*/
	void setVolumeSamples(const IntID& vss){fprintf_s(mFile,"connectAttr \"");vss.write(mFile);fprintf_s(mFile,"\" \"%s.vss\";\n",mName.c_str());}
	/*
	Depth jitter randomizes the samples of the volume with depth. This
	replaces banding artifacts in volume renders with noise. The noise can then be
	dramatically reduced by increasing the volume samples and aa levels.
	*/
	void setDepthJitter(bool dej){if(dej == false) return; fprintf_s(mFile, "setAttr \".dej\" %i;\n", dej);}
	/*
	Depth jitter randomizes the samples of the volume with depth. This
	replaces banding artifacts in volume renders with noise. The noise can then be
	dramatically reduced by increasing the volume samples and aa levels.
	*/
	void setDepthJitter(const BoolID& dej){fprintf_s(mFile,"connectAttr \"");dej.write(mFile);fprintf_s(mFile,"\" \"%s.dej\";\n",mName.c_str());}
	/*Specified whether or not an object casts shadows onto itself.*/
	void setIgnoreSelfShadowing(bool iss){if(iss == false) return; fprintf_s(mFile, "setAttr \".iss\" %i;\n", iss);}
	/*Specified whether or not an object casts shadows onto itself.*/
	void setIgnoreSelfShadowing(const BoolID& iss){fprintf_s(mFile,"connectAttr \"");iss.write(mFile);fprintf_s(mFile,"\" \"%s.iss\";\n",mName.c_str());}
	/*Specifies if this surface should be visible to EAS (Maya's primary visibility solver)*/
	void setPrimaryVisibility(bool vis){if(vis == true) return; fprintf_s(mFile, "setAttr \".vis\" %i;\n", vis);}
	/*Specifies if this surface should be visible to EAS (Maya's primary visibility solver)*/
	void setPrimaryVisibility(const BoolID& vis){fprintf_s(mFile,"connectAttr \"");vis.write(mFile);fprintf_s(mFile,"\" \"%s.vis\";\n",mName.c_str());}
	/*Connection to the reference object.*/
	void setReferenceObject(const MessageID& rob){fprintf_s(mFile,"connectAttr \"");rob.write(mFile);fprintf_s(mFile,"\" \"%s.rob\";\n",mName.c_str());}
	/*
	An instanced attribute array of compound attributes used to
	represent complement "set" membership information.
	Connections are made to this attribute if the entire
	instance is in a set and connections are made to the children of
	this attribute if portions of this attribute are in sets.
	*/
	void setCompInstObjGroups(size_t ciog_i,const CompInstObjGroups& ciog){fprintf_s(mFile, "setAttr \".ciog[%i]\" ",ciog_i);ciog.write(mFile);fprintf_s(mFile,";\n");}
	/*
	An instanced attribute array of compound attributes used to
	represent complement "set" membership information.
	Connections are made to this attribute if the entire
	instance is in a set and connections are made to the children of
	this attribute if portions of this attribute are in sets.
	*/
	void setCompInstObjGroups(size_t ciog_i,const CompInstObjGroupsID& ciog){fprintf_s(mFile,"connectAttr \"");ciog.write(mFile);fprintf_s(mFile,"\" \"%s.ciog[%i]\";\n",mName.c_str(),ciog_i);}
	/*
	An array of compound attributes used to identify the parts of the
	object that are in various sets. Each element in the array refers
	to the membership in one set.
	*/
	void setCompObjectGroups(size_t ciog_i,size_t cog_i,const CompInstObjGroups::CompObjectGroups& cog){fprintf_s(mFile, "setAttr \".ciog[%i].cog[%i]\" ",ciog_i,cog_i);cog.write(mFile);fprintf_s(mFile,";\n");}
	/*
	An array of compound attributes used to identify the parts of the
	object that are in various sets. Each element in the array refers
	to the membership in one set.
	*/
	void setCompObjectGroups(size_t ciog_i,size_t cog_i,const CompObjectGroupsID& cog){fprintf_s(mFile,"connectAttr \"");cog.write(mFile);fprintf_s(mFile,"\" \"%s.ciog[%i].cog[%i]\";\n",mName.c_str(),ciog_i,cog_i);}
	/*Specifies the portion of the object that is in the set.*/
	void setCompObjectGrpCompList(size_t ciog_i,size_t cog_i,const componentList& cgcl){fprintf_s(mFile, "setAttr \".ciog[%i].cog[%i].cgcl\" -type \"componentList\" ",ciog_i,cog_i);cgcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Group Id
	Integer that identifies the object group in the object.
	*/
	void setCompObjectGroupId(size_t ciog_i,size_t cog_i,int cgid){if(cgid == 0) return; fprintf_s(mFile, "setAttr \".ciog[%i].cog[%i].cgid\" %i;\n", ciog_i,cog_i,cgid);}
	/*
	Group Id
	Integer that identifies the object group in the object.
	*/
	void setCompObjectGroupId(size_t ciog_i,size_t cog_i,const IntID& cgid){fprintf_s(mFile,"connectAttr \"");cgid.write(mFile);fprintf_s(mFile,"\" \"%s.ciog[%i].cog[%i].cgid\";\n",mName.c_str(),ciog_i,cog_i);}
	/*What type of render geometry is this? 0 = surface, 1 = volume, 2 = glow*/
	ShortID getRenderType(){char buffer[4096];sprintf_s (buffer, "%s.rt",mName.c_str());return (const char*)buffer;}
	/*Render this node as volume?*/
	BoolID getRenderVolume(){char buffer[4096];sprintf_s (buffer, "%s.rv",mName.c_str());return (const char*)buffer;}
	/*visible fraction of the geometry when rendered as glow*/
	FloatID getVisibleFraction(){char buffer[4096];sprintf_s (buffer, "%s.vf",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this object must be motion blurred*/
	BoolID getMotionBlur(){char buffer[4096];sprintf_s (buffer, "%s.mb",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this object is visible in reflections.*/
	BoolID getVisibleInReflections(){char buffer[4096];sprintf_s (buffer, "%s.vir",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this object is visible in refractions.*/
	BoolID getVisibleInRefractions(){char buffer[4096];sprintf_s (buffer, "%s.vif",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this object casts shadows.*/
	BoolID getCastsShadows(){char buffer[4096];sprintf_s (buffer, "%s.csh",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this object casts shadows.*/
	BoolID getReceiveShadows(){char buffer[4096];sprintf_s (buffer, "%s.rcsh",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this surface should override global motion blur max visibility sample settings.*/
	BoolID getMaxVisibilitySamplesOverride(){char buffer[4096];sprintf_s (buffer, "%s.vbo",mName.c_str());return (const char*)buffer;}
	/*Specifies the max number of motion blur visibility samples to be taken for this surface during rendering.*/
	IntID getMaxVisibilitySamples(){char buffer[4096];sprintf_s (buffer, "%s.mvs",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this surface should override geometry anti-aliasing settings.*/
	BoolID getGeometryAntialiasingOverride(){char buffer[4096];sprintf_s (buffer, "%s.gao",mName.c_str());return (const char*)buffer;}
	/*Specifies the geometry anti-aliasing level that should be taken for this surface during rendering.*/
	IntID getAntialiasingLevel(){char buffer[4096];sprintf_s (buffer, "%s.gal",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this surface should override global shading sample settings.*/
	BoolID getShadingSamplesOverride(){char buffer[4096];sprintf_s (buffer, "%s.sso",mName.c_str());return (const char*)buffer;}
	/*Specifies the minimum number of shading samples should be taken for this surface during rendering.*/
	IntID getShadingSamples(){char buffer[4096];sprintf_s (buffer, "%s.ssa",mName.c_str());return (const char*)buffer;}
	/*Specifies the max number of shading samples can be taken for this surface during rendering.*/
	IntID getMaxShadingSamples(){char buffer[4096];sprintf_s (buffer, "%s.msa",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this object should override global volume shading settings.*/
	BoolID getVolumeSamplesOverride(){char buffer[4096];sprintf_s (buffer, "%s.vso",mName.c_str());return (const char*)buffer;}
	/*Specifies the number of volume samples to be taken when rendering this volume.*/
	IntID getVolumeSamples(){char buffer[4096];sprintf_s (buffer, "%s.vss",mName.c_str());return (const char*)buffer;}
	/*
	Depth jitter randomizes the samples of the volume with depth. This
	replaces banding artifacts in volume renders with noise. The noise can then be
	dramatically reduced by increasing the volume samples and aa levels.
	*/
	BoolID getDepthJitter(){char buffer[4096];sprintf_s (buffer, "%s.dej",mName.c_str());return (const char*)buffer;}
	/*Specified whether or not an object casts shadows onto itself.*/
	BoolID getIgnoreSelfShadowing(){char buffer[4096];sprintf_s (buffer, "%s.iss",mName.c_str());return (const char*)buffer;}
	/*Specifies if this surface should be visible to EAS (Maya's primary visibility solver)*/
	BoolID getPrimaryVisibility(){char buffer[4096];sprintf_s (buffer, "%s.vis",mName.c_str());return (const char*)buffer;}
	/*Connection to the reference object.*/
	MessageID getReferenceObject(){char buffer[4096];sprintf_s (buffer, "%s.rob",mName.c_str());return (const char*)buffer;}
	/*
	An instanced attribute array of compound attributes used to
	represent complement "set" membership information.
	Connections are made to this attribute if the entire
	instance is in a set and connections are made to the children of
	this attribute if portions of this attribute are in sets.
	*/
	const CompInstObjGroupsID& getCompInstObjGroups(size_t ciog_i){char buffer[4096];sprintf_s (buffer, "%s.ciog[%i]",mName.c_str(),ciog_i);return (const char*)buffer;}
	/*
	An array of compound attributes used to identify the parts of the
	object that are in various sets. Each element in the array refers
	to the membership in one set.
	*/
	const CompObjectGroupsID& getCompObjectGroups(size_t ciog_i,size_t cog_i){char buffer[4096];sprintf_s (buffer, "%s.ciog[%i].cog[%i]",mName.c_str(),ciog_i,cog_i);return (const char*)buffer;}
	/*
	Group Id
	Integer that identifies the object group in the object.
	*/
	const IntID& getCompObjectGroupId(size_t ciog_i,size_t cog_i){char buffer[4096];sprintf_s (buffer, "%s.ciog[%i].cog[%i].cgid",mName.c_str(),ciog_i,cog_i);return (const char*)buffer;}
protected:
	GeometryShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GEOMETRYSHAPE_H__
