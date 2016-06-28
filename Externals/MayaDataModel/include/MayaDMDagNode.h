/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DAGNODE_H__
#define __MayaDM_DAGNODE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMEntity.h"
namespace MayaDM
{
class DagNode : public Entity
{
public:
	struct BoundingBox{
		void write(FILE* file) const
		{
		}
	};
	struct InstObjGroups{
		struct ObjectGroups{
			componentList objectGrpCompList;
			int objectGroupId;
			short objectGrpColor;
			void write(FILE* file) const
			{
				objectGrpCompList.write(file);
				fprintf(file, " ");
				fprintf(file,"%i ", objectGroupId);
				fprintf(file,"%i", objectGrpColor);
			}
		}* objectGroups;
		size_t nbObjectGroups;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbObjectGroups; ++i)
			{
				objectGroups[i].write(file);
				if (i + 1<nbObjectGroups) fprintf(file, " ");
			}
		}
	};
	struct DrawOverride{
		unsigned int overrideDisplayType;
		unsigned int overrideLevelOfDetail;
		bool overrideShading;
		bool overrideTexturing;
		bool overridePlayback;
		bool overrideEnabled;
		bool overrideVisibility;
		unsigned char overrideColor;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", overrideDisplayType);
			fprintf(file,"%i ", overrideLevelOfDetail);
			fprintf(file,"%i ", overrideShading);
			fprintf(file,"%i ", overrideTexturing);
			fprintf(file,"%i ", overridePlayback);
			fprintf(file,"%i ", overrideEnabled);
			fprintf(file,"%i ", overrideVisibility);
			fprintf(file,"%i", overrideColor);
		}
	};
	struct RenderInfo{
		short identification;
		bool layerRenderable;
		unsigned char layerOverrideColor;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", identification);
			fprintf(file,"%i ", layerRenderable);
			fprintf(file,"%i", layerOverrideColor);
		}
	};
	struct RenderLayerInfo{
		short renderLayerId;
		bool renderLayerRenderable;
		unsigned char renderLayerColor;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", renderLayerId);
			fprintf(file,"%i ", renderLayerRenderable);
			fprintf(file,"%i", renderLayerColor);
		}
	};
	struct GhostCustomSteps{
		int ghostPreSteps;
		int ghostPostSteps;
		int ghostStepSize;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", ghostPreSteps);
			fprintf(file,"%i ", ghostPostSteps);
			fprintf(file,"%i", ghostStepSize);
		}
	};
public:

	DagNode():Entity(){}
	DagNode(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Entity(file, name, parent, "dagNode", shared, create){}
	virtual ~DagNode(){}

	void setVisibility(bool v)
	{
		if(v == true) return;
		fprintf(mFile,"\tsetAttr \".v\" %i;\n", v);
	}
	void setIntermediateObject(bool io)
	{
		if(io == false) return;
		fprintf(mFile,"\tsetAttr \".io\" %i;\n", io);
	}
	void setTemplate(bool tmp)
	{
		if(tmp == false) return;
		fprintf(mFile,"\tsetAttr \".tmp\" %i;\n", tmp);
	}
	void setGhosting(bool gh)
	{
		if(gh == false) return;
		fprintf(mFile,"\tsetAttr \".gh\" %i;\n", gh);
	}
	void setInstObjGroups(size_t iog_i,const InstObjGroups& iog)
	{
		fprintf(mFile,"\tsetAttr \".iog[%i]\" ",iog_i);
		iog.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInstObjGroups(size_t iog_start,size_t iog_end,InstObjGroups* iog)
	{
		fprintf(mFile,"\tsetAttr \".iog[%i:%i]\" ", iog_start,iog_end);
		size_t size = (iog_end-iog_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			iog[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInstObjGroups(size_t iog_start,size_t iog_end)const
	{
		fprintf(mFile,"\tsetAttr \".iog[%i:%i]\"",iog_start,iog_end);
		fprintf(mFile," -type \"InstObjGroups\" ");
	}
	void appendInstObjGroups(const InstObjGroups& iog)const
	{
		fprintf(mFile," ");
		iog.write(mFile);
	}
	void endInstObjGroups()const
	{
		fprintf(mFile,";\n");
	}
	void setObjectGroups(size_t iog_i,size_t og_i,const InstObjGroups::ObjectGroups& og)
	{
		fprintf(mFile,"\tsetAttr \".iog[%i].og[%i]\" ",iog_i,og_i);
		og.write(mFile);
		fprintf(mFile,";\n");
	}
	void setObjectGroups(size_t iog_i,size_t og_start,size_t og_end,InstObjGroups::ObjectGroups* og)
	{
		fprintf(mFile,"\tsetAttr \".iog[%i].og[%i:%i]\" ", iog_i,og_start,og_end);
		size_t size = (og_end-og_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			og[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startObjectGroups(size_t iog_i,size_t og_start,size_t og_end)const
	{
		fprintf(mFile,"\tsetAttr \".iog[%i].og[%i:%i]\"",iog_i,og_start,og_end);
		fprintf(mFile," -type \"InstObjGroups::ObjectGroups\" ");
	}
	void appendObjectGroups(const InstObjGroups::ObjectGroups& og)const
	{
		fprintf(mFile," ");
		og.write(mFile);
	}
	void endObjectGroups()const
	{
		fprintf(mFile,";\n");
	}
	void setObjectGrpCompList(size_t iog_i,size_t og_i,const componentList& gcl)
	{
		fprintf(mFile,"\tsetAttr \".iog[%i].og[%i].gcl\" -type \"componentList\" ",iog_i,og_i);
		gcl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setObjectGroupId(size_t iog_i,size_t og_i,int gid)
	{
		if(gid == 0) return;
		fprintf(mFile,"\tsetAttr \".iog[%i].og[%i].gid\" %i;\n", iog_i,og_i,gid);
	}
	void setObjectGrpColor(size_t iog_i,size_t og_i,short gco)
	{
		if(gco == -1) return;
		fprintf(mFile,"\tsetAttr \".iog[%i].og[%i].gco\" %i;\n", iog_i,og_i,gco);
	}
	void setUseObjectColor(bool uoc)
	{
		if(uoc == false) return;
		fprintf(mFile,"\tsetAttr \".uoc\" %i;\n", uoc);
	}
	void setObjectColor(short oc)
	{
		if(oc == 0) return;
		fprintf(mFile,"\tsetAttr \".oc\" %i;\n", oc);
	}
	void setDrawOverride(const DrawOverride& do_)
	{
		fprintf(mFile,"\tsetAttr \".do\" ");
		do_.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOverrideDisplayType(unsigned int ovdt)
	{
		if(ovdt == 0) return;
		fprintf(mFile,"\tsetAttr \".do.ovdt\" %i;\n", ovdt);
	}
	void setOverrideLevelOfDetail(unsigned int ovlod)
	{
		if(ovlod == 0) return;
		fprintf(mFile,"\tsetAttr \".do.ovlod\" %i;\n", ovlod);
	}
	void setOverrideShading(bool ovs)
	{
		if(ovs == true) return;
		fprintf(mFile,"\tsetAttr \".do.ovs\" %i;\n", ovs);
	}
	void setOverrideTexturing(bool ovt)
	{
		if(ovt == true) return;
		fprintf(mFile,"\tsetAttr \".do.ovt\" %i;\n", ovt);
	}
	void setOverridePlayback(bool ovp)
	{
		if(ovp == true) return;
		fprintf(mFile,"\tsetAttr \".do.ovp\" %i;\n", ovp);
	}
	void setOverrideEnabled(bool ove)
	{
		if(ove == false) return;
		fprintf(mFile,"\tsetAttr \".do.ove\" %i;\n", ove);
	}
	void setOverrideVisibility(bool ovv)
	{
		if(ovv == true) return;
		fprintf(mFile,"\tsetAttr \".do.ovv\" %i;\n", ovv);
	}
	void setOverrideColor(unsigned char ovc)
	{
		if(ovc == 0) return;
		fprintf(mFile,"\tsetAttr \".do.ovc\" %i;\n", ovc);
	}
	void setLodVisibility(bool lodv)
	{
		if(lodv == true) return;
		fprintf(mFile,"\tsetAttr \".lodv\" %i;\n", lodv);
	}
	void setRenderInfo(const RenderInfo& ri)
	{
		fprintf(mFile,"\tsetAttr \".ri\" ");
		ri.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIdentification(short rlid)
	{
		if(rlid == 0) return;
		fprintf(mFile,"\tsetAttr \".ri.rlid\" %i;\n", rlid);
	}
	void setLayerRenderable(bool rndr)
	{
		if(rndr == true) return;
		fprintf(mFile,"\tsetAttr \".ri.rndr\" %i;\n", rndr);
	}
	void setLayerOverrideColor(unsigned char lovc)
	{
		if(lovc == 0) return;
		fprintf(mFile,"\tsetAttr \".ri.lovc\" %i;\n", lovc);
	}
	void setRenderLayerInfo(size_t rlio_i,const RenderLayerInfo& rlio)
	{
		fprintf(mFile,"\tsetAttr \".rlio[%i]\" ",rlio_i);
		rlio.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRenderLayerInfo(size_t rlio_start,size_t rlio_end,RenderLayerInfo* rlio)
	{
		fprintf(mFile,"\tsetAttr \".rlio[%i:%i]\" ", rlio_start,rlio_end);
		size_t size = (rlio_end-rlio_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			rlio[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startRenderLayerInfo(size_t rlio_start,size_t rlio_end)const
	{
		fprintf(mFile,"\tsetAttr \".rlio[%i:%i]\"",rlio_start,rlio_end);
		fprintf(mFile," -type \"RenderLayerInfo\" ");
	}
	void appendRenderLayerInfo(const RenderLayerInfo& rlio)const
	{
		fprintf(mFile," ");
		rlio.write(mFile);
	}
	void endRenderLayerInfo()const
	{
		fprintf(mFile,";\n");
	}
	void setRenderLayerId(size_t rlio_i,short rli)
	{
		if(rli == 0) return;
		fprintf(mFile,"\tsetAttr \".rlio[%i].rli\" %i;\n", rlio_i,rli);
	}
	void setRenderLayerRenderable(size_t rlio_i,bool rlr)
	{
		if(rlr == true) return;
		fprintf(mFile,"\tsetAttr \".rlio[%i].rlr\" %i;\n", rlio_i,rlr);
	}
	void setRenderLayerColor(size_t rlio_i,unsigned char rlc)
	{
		if(rlc == 0) return;
		fprintf(mFile,"\tsetAttr \".rlio[%i].rlc\" %i;\n", rlio_i,rlc);
	}
	void setGhostingControl(unsigned int gc)
	{
		if(gc == 0) return;
		fprintf(mFile,"\tsetAttr \".gc\" %i;\n", gc);
	}
	void setGhostCustomSteps(const GhostCustomSteps& gcs)
	{
		fprintf(mFile,"\tsetAttr \".gcs\" ");
		gcs.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGhostPreSteps(int gpr)
	{
		if(gpr == 3) return;
		fprintf(mFile,"\tsetAttr \".gcs.gpr\" %i;\n", gpr);
	}
	void setGhostPostSteps(int gps)
	{
		if(gps == 3) return;
		fprintf(mFile,"\tsetAttr \".gcs.gps\" %i;\n", gps);
	}
	void setGhostStepSize(int gss)
	{
		if(gss == 1) return;
		fprintf(mFile,"\tsetAttr \".gcs.gss\" %i;\n", gss);
	}
	void setGhostFrames(const intArray& gf)
	{
		if(gf.size == 0) return;
		fprintf(mFile,"\tsetAttr \".gf\" -type \"intArray\" ");
		gf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGhostRangeStart(double grs)
	{
		if(grs == 0) return;
		fprintf(mFile,"\tsetAttr \".grs\" %f;\n", grs);
	}
	void setGhostRangeEnd(double gre)
	{
		if(gre == 1) return;
		fprintf(mFile,"\tsetAttr \".gre\" %f;\n", gre);
	}
	void getBoundingBox()const
	{
		fprintf(mFile,"\"%s.bb\"",mName.c_str());
	}
	void getBoundingBoxMin()const
	{
		fprintf(mFile,"\"%s.bb.bbmn\"",mName.c_str());
	}
	void getBoundingBoxMinX()const
	{
		fprintf(mFile,"\"%s.bb.bbmn.bbnx\"",mName.c_str());
	}
	void getBoundingBoxMinY()const
	{
		fprintf(mFile,"\"%s.bb.bbmn.bbny\"",mName.c_str());
	}
	void getBoundingBoxMinZ()const
	{
		fprintf(mFile,"\"%s.bb.bbmn.bbnz\"",mName.c_str());
	}
	void getBoundingBoxMax()const
	{
		fprintf(mFile,"\"%s.bb.bbmx\"",mName.c_str());
	}
	void getBoundingBoxMaxX()const
	{
		fprintf(mFile,"\"%s.bb.bbmx.bbxx\"",mName.c_str());
	}
	void getBoundingBoxMaxY()const
	{
		fprintf(mFile,"\"%s.bb.bbmx.bbxy\"",mName.c_str());
	}
	void getBoundingBoxMaxZ()const
	{
		fprintf(mFile,"\"%s.bb.bbmx.bbxz\"",mName.c_str());
	}
	void getBoundingBoxSize()const
	{
		fprintf(mFile,"\"%s.bb.bbsi\"",mName.c_str());
	}
	void getBoundingBoxSizeX()const
	{
		fprintf(mFile,"\"%s.bb.bbsi.bbsx\"",mName.c_str());
	}
	void getBoundingBoxSizeY()const
	{
		fprintf(mFile,"\"%s.bb.bbsi.bbsy\"",mName.c_str());
	}
	void getBoundingBoxSizeZ()const
	{
		fprintf(mFile,"\"%s.bb.bbsi.bbsz\"",mName.c_str());
	}
	void getCenter()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getBoundingBoxCenterX()const
	{
		fprintf(mFile,"\"%s.c.bcx\"",mName.c_str());
	}
	void getBoundingBoxCenterY()const
	{
		fprintf(mFile,"\"%s.c.bcy\"",mName.c_str());
	}
	void getBoundingBoxCenterZ()const
	{
		fprintf(mFile,"\"%s.c.bcz\"",mName.c_str());
	}
	void getMatrix()const
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getInverseMatrix()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getWorldMatrix(size_t wm_i)const
	{
		fprintf(mFile,"\"%s.wm[%i]\"",mName.c_str(),wm_i);
	}
	void getWorldMatrix()const
	{

		fprintf(mFile,"\"%s.wm\"",mName.c_str());
	}
	void getWorldInverseMatrix(size_t wim_i)const
	{
		fprintf(mFile,"\"%s.wim[%i]\"",mName.c_str(),wim_i);
	}
	void getWorldInverseMatrix()const
	{

		fprintf(mFile,"\"%s.wim\"",mName.c_str());
	}
	void getParentMatrix(size_t pm_i)const
	{
		fprintf(mFile,"\"%s.pm[%i]\"",mName.c_str(),pm_i);
	}
	void getParentMatrix()const
	{

		fprintf(mFile,"\"%s.pm\"",mName.c_str());
	}
	void getParentInverseMatrix(size_t pim_i)const
	{
		fprintf(mFile,"\"%s.pim[%i]\"",mName.c_str(),pim_i);
	}
	void getParentInverseMatrix()const
	{

		fprintf(mFile,"\"%s.pim\"",mName.c_str());
	}
	void getVisibility()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getIntermediateObject()const
	{
		fprintf(mFile,"\"%s.io\"",mName.c_str());
	}
	void getTemplate()const
	{
		fprintf(mFile,"\"%s.tmp\"",mName.c_str());
	}
	void getGhosting()const
	{
		fprintf(mFile,"\"%s.gh\"",mName.c_str());
	}
	void getInstObjGroups(size_t iog_i)const
	{
		fprintf(mFile,"\"%s.iog[%i]\"",mName.c_str(),iog_i);
	}
	void getInstObjGroups()const
	{

		fprintf(mFile,"\"%s.iog\"",mName.c_str());
	}
	void getObjectGroups(size_t iog_i,size_t og_i)const
	{
		fprintf(mFile,"\"%s.iog[%i].og[%i]\"",mName.c_str(),iog_i,og_i);
	}
	void getObjectGroups(size_t og_i)const
	{

		fprintf(mFile,"\"%s.iog.og[%i]\"",mName.c_str(),og_i);
	}
	void getObjectGroupId(size_t iog_i,size_t og_i)const
	{
		fprintf(mFile,"\"%s.iog[%i].og[%i].gid\"",mName.c_str(),iog_i,og_i);
	}
	void getObjectGroupId(size_t og_i)const
	{

		fprintf(mFile,"\"%s.iog.og[%i].gid\"",mName.c_str(),og_i);
	}
	void getObjectGrpColor(size_t iog_i,size_t og_i)const
	{
		fprintf(mFile,"\"%s.iog[%i].og[%i].gco\"",mName.c_str(),iog_i,og_i);
	}
	void getObjectGrpColor(size_t og_i)const
	{

		fprintf(mFile,"\"%s.iog.og[%i].gco\"",mName.c_str(),og_i);
	}
	void getUseObjectColor()const
	{
		fprintf(mFile,"\"%s.uoc\"",mName.c_str());
	}
	void getObjectColor()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getDrawOverride()const
	{
		fprintf(mFile,"\"%s.do\"",mName.c_str());
	}
	void getOverrideDisplayType()const
	{
		fprintf(mFile,"\"%s.do.ovdt\"",mName.c_str());
	}
	void getOverrideLevelOfDetail()const
	{
		fprintf(mFile,"\"%s.do.ovlod\"",mName.c_str());
	}
	void getOverrideShading()const
	{
		fprintf(mFile,"\"%s.do.ovs\"",mName.c_str());
	}
	void getOverrideTexturing()const
	{
		fprintf(mFile,"\"%s.do.ovt\"",mName.c_str());
	}
	void getOverridePlayback()const
	{
		fprintf(mFile,"\"%s.do.ovp\"",mName.c_str());
	}
	void getOverrideEnabled()const
	{
		fprintf(mFile,"\"%s.do.ove\"",mName.c_str());
	}
	void getOverrideVisibility()const
	{
		fprintf(mFile,"\"%s.do.ovv\"",mName.c_str());
	}
	void getOverrideColor()const
	{
		fprintf(mFile,"\"%s.do.ovc\"",mName.c_str());
	}
	void getLodVisibility()const
	{
		fprintf(mFile,"\"%s.lodv\"",mName.c_str());
	}
	void getRenderInfo()const
	{
		fprintf(mFile,"\"%s.ri\"",mName.c_str());
	}
	void getIdentification()const
	{
		fprintf(mFile,"\"%s.ri.rlid\"",mName.c_str());
	}
	void getLayerRenderable()const
	{
		fprintf(mFile,"\"%s.ri.rndr\"",mName.c_str());
	}
	void getLayerOverrideColor()const
	{
		fprintf(mFile,"\"%s.ri.lovc\"",mName.c_str());
	}
	void getRenderLayerInfo(size_t rlio_i)const
	{
		fprintf(mFile,"\"%s.rlio[%i]\"",mName.c_str(),rlio_i);
	}
	void getRenderLayerInfo()const
	{

		fprintf(mFile,"\"%s.rlio\"",mName.c_str());
	}
	void getRenderLayerId(size_t rlio_i)const
	{
		fprintf(mFile,"\"%s.rlio[%i].rli\"",mName.c_str(),rlio_i);
	}
	void getRenderLayerId()const
	{

		fprintf(mFile,"\"%s.rlio.rli\"",mName.c_str());
	}
	void getRenderLayerRenderable(size_t rlio_i)const
	{
		fprintf(mFile,"\"%s.rlio[%i].rlr\"",mName.c_str(),rlio_i);
	}
	void getRenderLayerRenderable()const
	{

		fprintf(mFile,"\"%s.rlio.rlr\"",mName.c_str());
	}
	void getRenderLayerColor(size_t rlio_i)const
	{
		fprintf(mFile,"\"%s.rlio[%i].rlc\"",mName.c_str(),rlio_i);
	}
	void getRenderLayerColor()const
	{

		fprintf(mFile,"\"%s.rlio.rlc\"",mName.c_str());
	}
	void getGhostingControl()const
	{
		fprintf(mFile,"\"%s.gc\"",mName.c_str());
	}
	void getGhostCustomSteps()const
	{
		fprintf(mFile,"\"%s.gcs\"",mName.c_str());
	}
	void getGhostPreSteps()const
	{
		fprintf(mFile,"\"%s.gcs.gpr\"",mName.c_str());
	}
	void getGhostPostSteps()const
	{
		fprintf(mFile,"\"%s.gcs.gps\"",mName.c_str());
	}
	void getGhostStepSize()const
	{
		fprintf(mFile,"\"%s.gcs.gss\"",mName.c_str());
	}
	void getGhostFrames()const
	{
		fprintf(mFile,"\"%s.gf\"",mName.c_str());
	}
	void getGhostRangeStart()const
	{
		fprintf(mFile,"\"%s.grs\"",mName.c_str());
	}
	void getGhostRangeEnd()const
	{
		fprintf(mFile,"\"%s.gre\"",mName.c_str());
	}
	void getGhostDriver()const
	{
		fprintf(mFile,"\"%s.gdr\"",mName.c_str());
	}
protected:
	DagNode(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Entity(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DAGNODE_H__
