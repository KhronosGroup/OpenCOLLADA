/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class GeometryShape : public Shape
{
public:
	struct CompInstObjGroups{
		struct CompObjectGroups{
			componentList compObjectGrpCompList;
			int compObjectGroupId;
			void write(FILE* file) const
			{
				compObjectGrpCompList.write(file);
				fprintf(file, " ");
				fprintf(file,"%i", compObjectGroupId);
			}
		}* compObjectGroups;
		size_t nbCompObjectGroups;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbCompObjectGroups; ++i)
			{
				compObjectGroups[i].write(file);
				if (i + 1<nbCompObjectGroups) fprintf(file, " ");
			}
		}
	};
public:

	GeometryShape():Shape(){}
	GeometryShape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "geometryShape", shared, create){}
	virtual ~GeometryShape(){}

	void setRenderType(short rt)
	{
		if(rt == 0) return;
		fprintf(mFile,"\tsetAttr \".rt\" %i;\n", rt);
	}
	void setRenderVolume(bool rv)
	{
		if(rv == false) return;
		fprintf(mFile,"\tsetAttr \".rv\" %i;\n", rv);
	}
	void setVisibleFraction(float vf)
	{
		if(vf == 1.0f) return;
		fprintf(mFile,"\tsetAttr \".vf\" %f;\n", vf);
	}
	void setMotionBlur(bool mb)
	{
		if(mb == true) return;
		fprintf(mFile,"\tsetAttr \".mb\" %i;\n", mb);
	}
	void setVisibleInReflections(bool vir)
	{
		if(vir == false) return;
		fprintf(mFile,"\tsetAttr \".vir\" %i;\n", vir);
	}
	void setVisibleInRefractions(bool vif)
	{
		if(vif == false) return;
		fprintf(mFile,"\tsetAttr \".vif\" %i;\n", vif);
	}
	void setCastsShadows(bool csh)
	{
		if(csh == true) return;
		fprintf(mFile,"\tsetAttr \".csh\" %i;\n", csh);
	}
	void setReceiveShadows(bool rcsh)
	{
		if(rcsh == true) return;
		fprintf(mFile,"\tsetAttr \".rcsh\" %i;\n", rcsh);
	}
	void setMaxVisibilitySamplesOverride(bool vbo)
	{
		if(vbo == false) return;
		fprintf(mFile,"\tsetAttr \".vbo\" %i;\n", vbo);
	}
	void setMaxVisibilitySamples(int mvs)
	{
		if(mvs == 1) return;
		fprintf(mFile,"\tsetAttr \".mvs\" %i;\n", mvs);
	}
	void setGeometryAntialiasingOverride(bool gao)
	{
		if(gao == false) return;
		fprintf(mFile,"\tsetAttr \".gao\" %i;\n", gao);
	}
	void setAntialiasingLevel(int gal)
	{
		if(gal == 1) return;
		fprintf(mFile,"\tsetAttr \".gal\" %i;\n", gal);
	}
	void setShadingSamplesOverride(bool sso)
	{
		if(sso == false) return;
		fprintf(mFile,"\tsetAttr \".sso\" %i;\n", sso);
	}
	void setShadingSamples(int ssa)
	{
		if(ssa == 1) return;
		fprintf(mFile,"\tsetAttr \".ssa\" %i;\n", ssa);
	}
	void setMaxShadingSamples(int msa)
	{
		if(msa == 1) return;
		fprintf(mFile,"\tsetAttr \".msa\" %i;\n", msa);
	}
	void setVolumeSamplesOverride(bool vso)
	{
		if(vso == false) return;
		fprintf(mFile,"\tsetAttr \".vso\" %i;\n", vso);
	}
	void setVolumeSamples(int vss)
	{
		if(vss == 1) return;
		fprintf(mFile,"\tsetAttr \".vss\" %i;\n", vss);
	}
	void setDepthJitter(bool dej)
	{
		if(dej == false) return;
		fprintf(mFile,"\tsetAttr \".dej\" %i;\n", dej);
	}
	void setIgnoreSelfShadowing(bool iss)
	{
		if(iss == false) return;
		fprintf(mFile,"\tsetAttr \".iss\" %i;\n", iss);
	}
	void setPrimaryVisibility(bool vis)
	{
		if(vis == true) return;
		fprintf(mFile,"\tsetAttr \".vis\" %i;\n", vis);
	}
	void setCompInstObjGroups(size_t ciog_i,const CompInstObjGroups& ciog)
	{
		fprintf(mFile,"\tsetAttr \".ciog[%i]\" ",ciog_i);
		ciog.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCompInstObjGroups(size_t ciog_start,size_t ciog_end,CompInstObjGroups* ciog)
	{
		fprintf(mFile,"\tsetAttr \".ciog[%i:%i]\" ", ciog_start,ciog_end);
		size_t size = (ciog_end-ciog_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ciog[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCompInstObjGroups(size_t ciog_start,size_t ciog_end)const
	{
		fprintf(mFile,"\tsetAttr \".ciog[%i:%i]\"",ciog_start,ciog_end);
		fprintf(mFile," -type \"CompInstObjGroups\" ");
	}
	void appendCompInstObjGroups(const CompInstObjGroups& ciog)const
	{
		fprintf(mFile," ");
		ciog.write(mFile);
	}
	void endCompInstObjGroups()const
	{
		fprintf(mFile,";\n");
	}
	void setCompObjectGroups(size_t ciog_i,size_t cog_i,const CompInstObjGroups::CompObjectGroups& cog)
	{
		fprintf(mFile,"\tsetAttr \".ciog[%i].cog[%i]\" ",ciog_i,cog_i);
		cog.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCompObjectGroups(size_t ciog_i,size_t cog_start,size_t cog_end,CompInstObjGroups::CompObjectGroups* cog)
	{
		fprintf(mFile,"\tsetAttr \".ciog[%i].cog[%i:%i]\" ", ciog_i,cog_start,cog_end);
		size_t size = (cog_end-cog_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cog[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCompObjectGroups(size_t ciog_i,size_t cog_start,size_t cog_end)const
	{
		fprintf(mFile,"\tsetAttr \".ciog[%i].cog[%i:%i]\"",ciog_i,cog_start,cog_end);
		fprintf(mFile," -type \"CompInstObjGroups::CompObjectGroups\" ");
	}
	void appendCompObjectGroups(const CompInstObjGroups::CompObjectGroups& cog)const
	{
		fprintf(mFile," ");
		cog.write(mFile);
	}
	void endCompObjectGroups()const
	{
		fprintf(mFile,";\n");
	}
	void setCompObjectGrpCompList(size_t ciog_i,size_t cog_i,const componentList& cgcl)
	{
		fprintf(mFile,"\tsetAttr \".ciog[%i].cog[%i].cgcl\" -type \"componentList\" ",ciog_i,cog_i);
		cgcl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCompObjectGroupId(size_t ciog_i,size_t cog_i,int cgid)
	{
		if(cgid == 0) return;
		fprintf(mFile,"\tsetAttr \".ciog[%i].cog[%i].cgid\" %i;\n", ciog_i,cog_i,cgid);
	}
	void getRenderType()const
	{
		fprintf(mFile,"\"%s.rt\"",mName.c_str());
	}
	void getRenderVolume()const
	{
		fprintf(mFile,"\"%s.rv\"",mName.c_str());
	}
	void getVisibleFraction()const
	{
		fprintf(mFile,"\"%s.vf\"",mName.c_str());
	}
	void getMotionBlur()const
	{
		fprintf(mFile,"\"%s.mb\"",mName.c_str());
	}
	void getVisibleInReflections()const
	{
		fprintf(mFile,"\"%s.vir\"",mName.c_str());
	}
	void getVisibleInRefractions()const
	{
		fprintf(mFile,"\"%s.vif\"",mName.c_str());
	}
	void getCastsShadows()const
	{
		fprintf(mFile,"\"%s.csh\"",mName.c_str());
	}
	void getReceiveShadows()const
	{
		fprintf(mFile,"\"%s.rcsh\"",mName.c_str());
	}
	void getMaxVisibilitySamplesOverride()const
	{
		fprintf(mFile,"\"%s.vbo\"",mName.c_str());
	}
	void getMaxVisibilitySamples()const
	{
		fprintf(mFile,"\"%s.mvs\"",mName.c_str());
	}
	void getGeometryAntialiasingOverride()const
	{
		fprintf(mFile,"\"%s.gao\"",mName.c_str());
	}
	void getAntialiasingLevel()const
	{
		fprintf(mFile,"\"%s.gal\"",mName.c_str());
	}
	void getShadingSamplesOverride()const
	{
		fprintf(mFile,"\"%s.sso\"",mName.c_str());
	}
	void getShadingSamples()const
	{
		fprintf(mFile,"\"%s.ssa\"",mName.c_str());
	}
	void getMaxShadingSamples()const
	{
		fprintf(mFile,"\"%s.msa\"",mName.c_str());
	}
	void getVolumeSamplesOverride()const
	{
		fprintf(mFile,"\"%s.vso\"",mName.c_str());
	}
	void getVolumeSamples()const
	{
		fprintf(mFile,"\"%s.vss\"",mName.c_str());
	}
	void getDepthJitter()const
	{
		fprintf(mFile,"\"%s.dej\"",mName.c_str());
	}
	void getIgnoreSelfShadowing()const
	{
		fprintf(mFile,"\"%s.iss\"",mName.c_str());
	}
	void getPrimaryVisibility()const
	{
		fprintf(mFile,"\"%s.vis\"",mName.c_str());
	}
	void getReferenceObject()const
	{
		fprintf(mFile,"\"%s.rob\"",mName.c_str());
	}
	void getCompInstObjGroups(size_t ciog_i)const
	{
		fprintf(mFile,"\"%s.ciog[%i]\"",mName.c_str(),ciog_i);
	}
	void getCompInstObjGroups()const
	{

		fprintf(mFile,"\"%s.ciog\"",mName.c_str());
	}
	void getCompObjectGroups(size_t ciog_i,size_t cog_i)const
	{
		fprintf(mFile,"\"%s.ciog[%i].cog[%i]\"",mName.c_str(),ciog_i,cog_i);
	}
	void getCompObjectGroups(size_t cog_i)const
	{

		fprintf(mFile,"\"%s.ciog.cog[%i]\"",mName.c_str(),cog_i);
	}
	void getCompObjectGroupId(size_t ciog_i,size_t cog_i)const
	{
		fprintf(mFile,"\"%s.ciog[%i].cog[%i].cgid\"",mName.c_str(),ciog_i,cog_i);
	}
	void getCompObjectGroupId(size_t cog_i)const
	{

		fprintf(mFile,"\"%s.ciog.cog[%i].cgid\"",mName.c_str(),cog_i);
	}
protected:
	GeometryShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_GEOMETRYSHAPE_H__
