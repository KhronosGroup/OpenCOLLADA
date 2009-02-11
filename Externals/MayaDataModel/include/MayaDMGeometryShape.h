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
		void write(FILE* file) const
		{
			size_t size = sizeof(compObjectGroups)/sizeof(CompObjectGroups);
			for(size_t i=0; i<size; ++i)
			{
				compObjectGroups[i].write(file);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
public:
	GeometryShape():Shape(){}
	GeometryShape(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "geometryShape"){}
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
	void setCompObjectGroups(size_t ciog_i,size_t cog_i,const CompInstObjGroups::CompObjectGroups& cog)
	{
		fprintf(mFile,"\tsetAttr \".ciog[%i].cog[%i]\" ",ciog_i,cog_i);
		cog.write(mFile);
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
	void getRenderType()
	{
		fprintf(mFile,"\"%s.rt\"",mName.c_str());

	}
	void getRenderVolume()
	{
		fprintf(mFile,"\"%s.rv\"",mName.c_str());

	}
	void getVisibleFraction()
	{
		fprintf(mFile,"\"%s.vf\"",mName.c_str());

	}
	void getMotionBlur()
	{
		fprintf(mFile,"\"%s.mb\"",mName.c_str());

	}
	void getVisibleInReflections()
	{
		fprintf(mFile,"\"%s.vir\"",mName.c_str());

	}
	void getVisibleInRefractions()
	{
		fprintf(mFile,"\"%s.vif\"",mName.c_str());

	}
	void getCastsShadows()
	{
		fprintf(mFile,"\"%s.csh\"",mName.c_str());

	}
	void getReceiveShadows()
	{
		fprintf(mFile,"\"%s.rcsh\"",mName.c_str());

	}
	void getMaxVisibilitySamplesOverride()
	{
		fprintf(mFile,"\"%s.vbo\"",mName.c_str());

	}
	void getMaxVisibilitySamples()
	{
		fprintf(mFile,"\"%s.mvs\"",mName.c_str());

	}
	void getGeometryAntialiasingOverride()
	{
		fprintf(mFile,"\"%s.gao\"",mName.c_str());

	}
	void getAntialiasingLevel()
	{
		fprintf(mFile,"\"%s.gal\"",mName.c_str());

	}
	void getShadingSamplesOverride()
	{
		fprintf(mFile,"\"%s.sso\"",mName.c_str());

	}
	void getShadingSamples()
	{
		fprintf(mFile,"\"%s.ssa\"",mName.c_str());

	}
	void getMaxShadingSamples()
	{
		fprintf(mFile,"\"%s.msa\"",mName.c_str());

	}
	void getVolumeSamplesOverride()
	{
		fprintf(mFile,"\"%s.vso\"",mName.c_str());

	}
	void getVolumeSamples()
	{
		fprintf(mFile,"\"%s.vss\"",mName.c_str());

	}
	void getDepthJitter()
	{
		fprintf(mFile,"\"%s.dej\"",mName.c_str());

	}
	void getIgnoreSelfShadowing()
	{
		fprintf(mFile,"\"%s.iss\"",mName.c_str());

	}
	void getPrimaryVisibility()
	{
		fprintf(mFile,"\"%s.vis\"",mName.c_str());

	}
	void getReferenceObject()
	{
		fprintf(mFile,"\"%s.rob\"",mName.c_str());

	}
	void getCompInstObjGroups(size_t ciog_i)
	{
		fprintf(mFile,"\"%s.ciog[%i]\"",mName.c_str(),ciog_i);

	}
	void getCompObjectGroups(size_t ciog_i,size_t cog_i)
	{
		fprintf(mFile,"\"%s.ciog[%i].cog[%i]\"",mName.c_str(),ciog_i,cog_i);

	}
	void getCompObjectGroupId(size_t ciog_i,size_t cog_i)
	{
		fprintf(mFile,"\"%s.ciog[%i].cog[%i].cgid\"",mName.c_str(),ciog_i,cog_i);

	}
protected:
	GeometryShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_GEOMETRYSHAPE_H__
