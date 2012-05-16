/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDSHAPE_H__
#define __MayaDM_BLENDSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class BlendShape : public GeometryFilter
{
public:
	struct InputTarget{
		struct InputTargetGroup{
			struct InputTargetItem{
				pointArray inputPointsTarget;
				componentList inputComponentsTarget;
				void write(FILE* file) const
				{
					inputPointsTarget.write(file);
					fprintf(file, " ");
					inputComponentsTarget.write(file);
				}
			}* inputTargetItem;
			float* targetWeights;
			void write(FILE* file) const
			{
				size_t size = sizeof(inputTargetItem)/sizeof(InputTargetItem);
				for(size_t i=0; i<size; ++i)
				{
					inputTargetItem[i].write(file);
					fprintf(file, " ");
					if(i+1<size) fprintf(file," ");
				}
				size = sizeof(targetWeights)/sizeof(float);
				for(size_t i=0; i<size; ++i)
				{
					fprintf(file,"%f", targetWeights[i]);
					if(i+1<size) fprintf(file," ");
				}
			}
		}* inputTargetGroup;
		void write(FILE* file) const
		{
			size_t size = sizeof(inputTargetGroup)/sizeof(InputTargetGroup);
			for(size_t i=0; i<size; ++i)
			{
				inputTargetGroup[i].write(file);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
public:

	BlendShape():GeometryFilter(){}
	BlendShape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, "blendShape", shared, create){}
	virtual ~BlendShape(){}

	void setTopologyCheck(bool tc)
	{
		if(tc == true) return;
		fprintf(mFile,"\tsetAttr \".tc\" %i;\n", tc);
	}
	void setWeight(size_t w_i,float w)
	{
		if(w == 0) return;
		fprintf(mFile,"\tsetAttr \".w[%i]\" %f;\n", w_i,w);
	}
	void setWeight(size_t w_start,size_t w_end,float* w)
	{
		fprintf(mFile,"\tsetAttr \".w[%i:%i]\" ", w_start,w_end);
		size_t size = (w_end-w_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",w[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startWeight(size_t w_start,size_t w_end)const
	{
		fprintf(mFile,"\tsetAttr \".w[%i:%i]\"",w_start,w_end);
	}
	void appendWeight(float w)const
	{
		fprintf(mFile," %f",w);
	}
	void endWeight()const
	{
		fprintf(mFile,";\n");
	}
	void setIcon(size_t icn_i,const string& icn)
	{
		if(icn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".icn[%i]\" -type \"string\" ",icn_i);
		icn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIcon(size_t icn_start,size_t icn_end,string* icn)
	{
		fprintf(mFile,"\tsetAttr \".icn[%i:%i]\" ", icn_start,icn_end);
		size_t size = (icn_end-icn_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			icn[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startIcon(size_t icn_start,size_t icn_end)const
	{
		fprintf(mFile,"\tsetAttr \".icn[%i:%i]\"",icn_start,icn_end);
		fprintf(mFile," -type \"string\" ");
	}
	void appendIcon(const string& icn)const
	{
		fprintf(mFile," ");
		icn.write(mFile);
	}
	void endIcon()const
	{
		fprintf(mFile,";\n");
	}
	void setInputTarget(size_t it_i,const InputTarget& it)
	{
		fprintf(mFile,"\tsetAttr \".it[%i]\" ",it_i);
		it.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputTarget(size_t it_start,size_t it_end,InputTarget* it)
	{
		fprintf(mFile,"\tsetAttr \".it[%i:%i]\" ", it_start,it_end);
		size_t size = (it_end-it_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			it[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInputTarget(size_t it_start,size_t it_end)const
	{
		fprintf(mFile,"\tsetAttr \".it[%i:%i]\"",it_start,it_end);
		fprintf(mFile," -type \"InputTarget\" ");
	}
	void appendInputTarget(const InputTarget& it)const
	{
		fprintf(mFile," ");
		it.write(mFile);
	}
	void endInputTarget()const
	{
		fprintf(mFile,";\n");
	}
	void setInputTargetGroup(size_t it_i,size_t itg_i,const InputTarget::InputTargetGroup& itg)
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i]\" ",it_i,itg_i);
		itg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputTargetGroup(size_t it_i,size_t itg_start,size_t itg_end,InputTarget::InputTargetGroup* itg)
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i:%i]\" ", it_i,itg_start,itg_end);
		size_t size = (itg_end-itg_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			itg[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInputTargetGroup(size_t it_i,size_t itg_start,size_t itg_end)const
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i:%i]\"",it_i,itg_start,itg_end);
		fprintf(mFile," -type \"InputTarget::InputTargetGroup\" ");
	}
	void appendInputTargetGroup(const InputTarget::InputTargetGroup& itg)const
	{
		fprintf(mFile," ");
		itg.write(mFile);
	}
	void endInputTargetGroup()const
	{
		fprintf(mFile,";\n");
	}
	void setInputTargetItem(size_t it_i,size_t itg_i,size_t iti_i,const InputTarget::InputTargetGroup::InputTargetItem& iti)
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i].iti[%i]\" ",it_i,itg_i,iti_i);
		iti.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputTargetItem(size_t it_i,size_t itg_i,size_t iti_start,size_t iti_end,InputTarget::InputTargetGroup::InputTargetItem* iti)
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i].iti[%i:%i]\" ", it_i,itg_i,iti_start,iti_end);
		size_t size = (iti_end-iti_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			iti[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInputTargetItem(size_t it_i,size_t itg_i,size_t iti_start,size_t iti_end)const
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i].iti[%i:%i]\"",it_i,itg_i,iti_start,iti_end);
		fprintf(mFile," -type \"InputTarget::InputTargetGroup::InputTargetItem\" ");
	}
	void appendInputTargetItem(const InputTarget::InputTargetGroup::InputTargetItem& iti)const
	{
		fprintf(mFile," ");
		iti.write(mFile);
	}
	void endInputTargetItem()const
	{
		fprintf(mFile,";\n");
	}
	void setInputPointsTarget(size_t it_i,size_t itg_i,size_t iti_i,const pointArray& ipt)
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i].iti[%i].ipt\" -type \"pointArray\" ",it_i,itg_i,iti_i);
		ipt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputComponentsTarget(size_t it_i,size_t itg_i,size_t iti_i,const componentList& ict)
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i].iti[%i].ict\" -type \"componentList\" ",it_i,itg_i,iti_i);
		ict.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetWeights(size_t it_i,size_t itg_i,size_t tw_i,float tw)
	{
		if(tw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i].tw[%i]\" %f;\n", it_i,itg_i,tw_i,tw);
	}
	void setTargetWeights(size_t it_i,size_t itg_i,size_t tw_start,size_t tw_end,float* tw)
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i].tw[%i:%i]\" ", it_i,itg_i,tw_start,tw_end);
		size_t size = (tw_end-tw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",tw[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startTargetWeights(size_t it_i,size_t itg_i,size_t tw_start,size_t tw_end)const
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itg[%i].tw[%i:%i]\"",it_i,itg_i,tw_start,tw_end);
	}
	void appendTargetWeights(float tw)const
	{
		fprintf(mFile," %f",tw);
	}
	void endTargetWeights()const
	{
		fprintf(mFile,";\n");
	}
	void setOrigin(unsigned int ori)
	{
		if(ori == 1) return;
		fprintf(mFile,"\tsetAttr \".or\" %i;\n", ori);
	}
	void setBaseOrigin(const double3& bo)
	{
		fprintf(mFile,"\tsetAttr \".bo\" -type \"double3\" ");
		bo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBaseOriginX(double bx)
	{
		if(bx == 0) return;
		fprintf(mFile,"\tsetAttr \".bo.bx\" %f;\n", bx);
	}
	void setBaseOriginY(double by)
	{
		if(by == 0) return;
		fprintf(mFile,"\tsetAttr \".bo.by\" %f;\n", by);
	}
	void setBaseOriginZ(double bz)
	{
		if(bz == 0) return;
		fprintf(mFile,"\tsetAttr \".bo.bz\" %f;\n", bz);
	}
	void setTargetOrigin(const double3& to)
	{
		fprintf(mFile,"\tsetAttr \".to\" -type \"double3\" ");
		to.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTargetOriginX(double tx)
	{
		if(tx == 0) return;
		fprintf(mFile,"\tsetAttr \".to.tx\" %f;\n", tx);
	}
	void setTargetOriginY(double ty)
	{
		if(ty == 0) return;
		fprintf(mFile,"\tsetAttr \".to.ty\" %f;\n", ty);
	}
	void setTargetOriginZ(double tz)
	{
		if(tz == 0) return;
		fprintf(mFile,"\tsetAttr \".to.tz\" %f;\n", tz);
	}
	void setParallelBlender(bool pb)
	{
		if(pb == 0) return;
		fprintf(mFile,"\tsetAttr \".pb\" %i;\n", pb);
	}
	void getTopologyCheck()const
	{
		fprintf(mFile,"\"%s.tc\"",mName.c_str());
	}
	void getWeight(size_t w_i)const
	{
		fprintf(mFile,"\"%s.w[%i]\"",mName.c_str(),w_i);
	}
	void getWeight()const
	{

		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getIcon(size_t icn_i)const
	{
		fprintf(mFile,"\"%s.icn[%i]\"",mName.c_str(),icn_i);
	}
	void getIcon()const
	{

		fprintf(mFile,"\"%s.icn\"",mName.c_str());
	}
	void getInputTarget(size_t it_i)const
	{
		fprintf(mFile,"\"%s.it[%i]\"",mName.c_str(),it_i);
	}
	void getInputTarget()const
	{

		fprintf(mFile,"\"%s.it\"",mName.c_str());
	}
	void getInputTargetGroup(size_t it_i,size_t itg_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itg[%i]\"",mName.c_str(),it_i,itg_i);
	}
	void getInputTargetGroup(size_t itg_i)const
	{

		fprintf(mFile,"\"%s.it.itg[%i]\"",mName.c_str(),itg_i);
	}
	void getInputTargetItem(size_t it_i,size_t itg_i,size_t iti_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itg[%i].iti[%i]\"",mName.c_str(),it_i,itg_i,iti_i);
	}
	void getInputTargetItem(size_t itg_i,size_t iti_i)const
	{

		fprintf(mFile,"\"%s.it.itg[%i].iti[%i]\"",mName.c_str(),itg_i,iti_i);
	}
	void getInputGeomTarget(size_t it_i,size_t itg_i,size_t iti_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itg[%i].iti[%i].igt\"",mName.c_str(),it_i,itg_i,iti_i);
	}
	void getInputGeomTarget(size_t itg_i,size_t iti_i)const
	{

		fprintf(mFile,"\"%s.it.itg[%i].iti[%i].igt\"",mName.c_str(),itg_i,iti_i);
	}
	void getInputPointsTarget(size_t it_i,size_t itg_i,size_t iti_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itg[%i].iti[%i].ipt\"",mName.c_str(),it_i,itg_i,iti_i);
	}
	void getInputPointsTarget(size_t itg_i,size_t iti_i)const
	{

		fprintf(mFile,"\"%s.it.itg[%i].iti[%i].ipt\"",mName.c_str(),itg_i,iti_i);
	}
	void getInputComponentsTarget(size_t it_i,size_t itg_i,size_t iti_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itg[%i].iti[%i].ict\"",mName.c_str(),it_i,itg_i,iti_i);
	}
	void getInputComponentsTarget(size_t itg_i,size_t iti_i)const
	{

		fprintf(mFile,"\"%s.it.itg[%i].iti[%i].ict\"",mName.c_str(),itg_i,iti_i);
	}
	void getTargetWeights(size_t it_i,size_t itg_i,size_t tw_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itg[%i].tw[%i]\"",mName.c_str(),it_i,itg_i,tw_i);
	}
	void getTargetWeights(size_t itg_i,size_t tw_i)const
	{

		fprintf(mFile,"\"%s.it.itg[%i].tw[%i]\"",mName.c_str(),itg_i,tw_i);
	}
	void getOrigin()const
	{
		fprintf(mFile,"\"%s.or\"",mName.c_str());
	}
	void getBaseOrigin()const
	{
		fprintf(mFile,"\"%s.bo\"",mName.c_str());
	}
	void getBaseOriginX()const
	{
		fprintf(mFile,"\"%s.bo.bx\"",mName.c_str());
	}
	void getBaseOriginY()const
	{
		fprintf(mFile,"\"%s.bo.by\"",mName.c_str());
	}
	void getBaseOriginZ()const
	{
		fprintf(mFile,"\"%s.bo.bz\"",mName.c_str());
	}
	void getTargetOrigin()const
	{
		fprintf(mFile,"\"%s.to\"",mName.c_str());
	}
	void getTargetOriginX()const
	{
		fprintf(mFile,"\"%s.to.tx\"",mName.c_str());
	}
	void getTargetOriginY()const
	{
		fprintf(mFile,"\"%s.to.ty\"",mName.c_str());
	}
	void getTargetOriginZ()const
	{
		fprintf(mFile,"\"%s.to.tz\"",mName.c_str());
	}
protected:
	BlendShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLENDSHAPE_H__
