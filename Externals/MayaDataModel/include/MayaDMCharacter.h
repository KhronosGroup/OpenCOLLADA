/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHARACTER_H__
#define __MayaDM_CHARACTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectSet.h"
namespace MayaDM
{
class Character : public ObjectSet
{
public:
	struct ClipEvaluate{
		struct ClipEvaluate_Inmap{
			short clipEvaluate_InmapTo;
			short clipEvaluate_InmapFrom;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", clipEvaluate_InmapTo);
				fprintf(file,"%i", clipEvaluate_InmapFrom);
			}
		}* clipEvaluate_Inmap;
		size_t nbClipEvaluate_Inmap;
		struct ClipEvaluate_Outmap{
			short clipEvaluate_OutmapTo;
			short clipEvaluate_OutmapFrom;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", clipEvaluate_OutmapTo);
				fprintf(file,"%i", clipEvaluate_OutmapFrom);
			}
		}* clipEvaluate_Outmap;
		size_t nbClipEvaluate_Outmap;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbClipEvaluate_Inmap; ++i)
			{
				clipEvaluate_Inmap[i].write(file);
				fprintf(file, " ");
				if (i + 1<nbClipEvaluate_Inmap) fprintf(file, " ");
			}
			for (size_t i = 0; i<nbClipEvaluate_Outmap; ++i)
			{
				clipEvaluate_Outmap[i].write(file);
				if (i + 1<nbClipEvaluate_Outmap) fprintf(file, " ");
			}
		}
	};
public:

	Character():ObjectSet(){}
	Character(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ObjectSet(file, name, parent, "character", shared, create){}
	virtual ~Character(){}

	void setClipEvaluate(const ClipEvaluate& ce)
	{
		fprintf(mFile,"\tsetAttr \".ce\" ");
		ce.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClipEvaluate_Inmap(size_t cei_i,const ClipEvaluate::ClipEvaluate_Inmap& cei)
	{
		fprintf(mFile,"\tsetAttr \".ce.cei[%i]\" ",cei_i);
		cei.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClipEvaluate_Inmap(size_t cei_start,size_t cei_end,ClipEvaluate::ClipEvaluate_Inmap* cei)
	{
		fprintf(mFile,"\tsetAttr \".ce.cei[%i:%i]\" ", cei_start,cei_end);
		size_t size = (cei_end-cei_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cei[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startClipEvaluate_Inmap(size_t cei_start,size_t cei_end)const
	{
		fprintf(mFile,"\tsetAttr \".ce.cei[%i:%i]\"",cei_start,cei_end);
		fprintf(mFile," -type \"ClipEvaluate::ClipEvaluate_Inmap\" ");
	}
	void appendClipEvaluate_Inmap(const ClipEvaluate::ClipEvaluate_Inmap& cei)const
	{
		fprintf(mFile," ");
		cei.write(mFile);
	}
	void endClipEvaluate_Inmap()const
	{
		fprintf(mFile,";\n");
	}
	void setClipEvaluate_InmapTo(size_t cei_i,short ceit)
	{
		if(ceit == 0) return;
		fprintf(mFile,"\tsetAttr \".ce.cei[%i].ceit\" %i;\n", cei_i,ceit);
	}
	void setClipEvaluate_InmapFrom(size_t cei_i,short ceif)
	{
		if(ceif == 0) return;
		fprintf(mFile,"\tsetAttr \".ce.cei[%i].ceif\" %i;\n", cei_i,ceif);
	}
	void setClipEvaluate_Outmap(size_t ceo_i,const ClipEvaluate::ClipEvaluate_Outmap& ceo)
	{
		fprintf(mFile,"\tsetAttr \".ce.ceo[%i]\" ",ceo_i);
		ceo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClipEvaluate_Outmap(size_t ceo_start,size_t ceo_end,ClipEvaluate::ClipEvaluate_Outmap* ceo)
	{
		fprintf(mFile,"\tsetAttr \".ce.ceo[%i:%i]\" ", ceo_start,ceo_end);
		size_t size = (ceo_end-ceo_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ceo[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startClipEvaluate_Outmap(size_t ceo_start,size_t ceo_end)const
	{
		fprintf(mFile,"\tsetAttr \".ce.ceo[%i:%i]\"",ceo_start,ceo_end);
		fprintf(mFile," -type \"ClipEvaluate::ClipEvaluate_Outmap\" ");
	}
	void appendClipEvaluate_Outmap(const ClipEvaluate::ClipEvaluate_Outmap& ceo)const
	{
		fprintf(mFile," ");
		ceo.write(mFile);
	}
	void endClipEvaluate_Outmap()const
	{
		fprintf(mFile,";\n");
	}
	void setClipEvaluate_OutmapTo(size_t ceo_i,short ceot)
	{
		if(ceot == 0) return;
		fprintf(mFile,"\tsetAttr \".ce.ceo[%i].ceot\" %i;\n", ceo_i,ceot);
	}
	void setClipEvaluate_OutmapFrom(size_t ceo_i,short ceof)
	{
		if(ceof == 0) return;
		fprintf(mFile,"\tsetAttr \".ce.ceo[%i].ceof\" %i;\n", ceo_i,ceof);
	}
	void setUnitlessValues(size_t uv_i,double uv)
	{
		if(uv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uv[%i]\" %f;\n", uv_i,uv);
	}
	void setUnitlessValues(size_t uv_start,size_t uv_end,double* uv)
	{
		fprintf(mFile,"\tsetAttr \".uv[%i:%i]\" ", uv_start,uv_end);
		size_t size = (uv_end-uv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uv[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startUnitlessValues(size_t uv_start,size_t uv_end)const
	{
		fprintf(mFile,"\tsetAttr \".uv[%i:%i]\"",uv_start,uv_end);
	}
	void appendUnitlessValues(double uv)const
	{
		fprintf(mFile," %f",uv);
	}
	void endUnitlessValues()const
	{
		fprintf(mFile,";\n");
	}
	void setLinearValues(size_t lv_i,double lv)
	{
		if(lv == 0) return;
		fprintf(mFile,"\tsetAttr \".lv[%i]\" %f;\n", lv_i,lv);
	}
	void setLinearValues(size_t lv_start,size_t lv_end,double* lv)
	{
		fprintf(mFile,"\tsetAttr \".lv[%i:%i]\" ", lv_start,lv_end);
		size_t size = (lv_end-lv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",lv[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startLinearValues(size_t lv_start,size_t lv_end)const
	{
		fprintf(mFile,"\tsetAttr \".lv[%i:%i]\"",lv_start,lv_end);
	}
	void appendLinearValues(double lv)const
	{
		fprintf(mFile," %f",lv);
	}
	void endLinearValues()const
	{
		fprintf(mFile,";\n");
	}
	void setAngularValues(size_t av_i,double av)
	{
		if(av == 0) return;
		fprintf(mFile,"\tsetAttr \".av[%i]\" %f;\n", av_i,av);
	}
	void setAngularValues(size_t av_start,size_t av_end,double* av)
	{
		fprintf(mFile,"\tsetAttr \".av[%i:%i]\" ", av_start,av_end);
		size_t size = (av_end-av_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",av[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startAngularValues(size_t av_start,size_t av_end)const
	{
		fprintf(mFile,"\tsetAttr \".av[%i:%i]\"",av_start,av_end);
	}
	void appendAngularValues(double av)const
	{
		fprintf(mFile," %f",av);
	}
	void endAngularValues()const
	{
		fprintf(mFile,";\n");
	}
	void setTimeValues(size_t tv_i,double tv)
	{
		if(tv == 0) return;
		fprintf(mFile,"\tsetAttr \".tv[%i]\" %f;\n", tv_i,tv);
	}
	void setTimeValues(size_t tv_start,size_t tv_end,double* tv)
	{
		fprintf(mFile,"\tsetAttr \".tv[%i:%i]\" ", tv_start,tv_end);
		size_t size = (tv_end-tv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",tv[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startTimeValues(size_t tv_start,size_t tv_end)const
	{
		fprintf(mFile,"\tsetAttr \".tv[%i:%i]\"",tv_start,tv_end);
	}
	void appendTimeValues(double tv)const
	{
		fprintf(mFile," %f",tv);
	}
	void endTimeValues()const
	{
		fprintf(mFile,";\n");
	}
	void setClipIndexMap(const intArray& cim)
	{
		if(cim.size == 0) return;
		fprintf(mFile,"\tsetAttr \".cim\" -type \"intArray\" ");
		cim.write(mFile);
		fprintf(mFile,";\n");
	}
	void setActiveClipConnected(bool acc)
	{
		if(acc == 0) return;
		fprintf(mFile,"\tsetAttr \".acc\" %i;\n", acc);
	}
	void setTimelineClipStart(double tcs)
	{
		if(tcs == 0) return;
		fprintf(mFile,"\tsetAttr \".tcs\" %f;\n", tcs);
	}
	void setTimelineClipEnd(double tce)
	{
		if(tce == 0) return;
		fprintf(mFile,"\tsetAttr \".tce\" %f;\n", tce);
	}
	void getClipEvaluate()const
	{
		fprintf(mFile,"\"%s.ce\"",mName.c_str());
	}
	void getClipEvaluate_Raw()const
	{
		fprintf(mFile,"\"%s.ce.cer\"",mName.c_str());
	}
	void getClipEvaluate_Inmap(size_t cei_i)const
	{
		fprintf(mFile,"\"%s.ce.cei[%i]\"",mName.c_str(),cei_i);
	}
	void getClipEvaluate_InmapTo(size_t cei_i)const
	{
		fprintf(mFile,"\"%s.ce.cei[%i].ceit\"",mName.c_str(),cei_i);
	}
	void getClipEvaluate_InmapFrom(size_t cei_i)const
	{
		fprintf(mFile,"\"%s.ce.cei[%i].ceif\"",mName.c_str(),cei_i);
	}
	void getClipEvaluate_Outmap(size_t ceo_i)const
	{
		fprintf(mFile,"\"%s.ce.ceo[%i]\"",mName.c_str(),ceo_i);
	}
	void getClipEvaluate_OutmapTo(size_t ceo_i)const
	{
		fprintf(mFile,"\"%s.ce.ceo[%i].ceot\"",mName.c_str(),ceo_i);
	}
	void getClipEvaluate_OutmapFrom(size_t ceo_i)const
	{
		fprintf(mFile,"\"%s.ce.ceo[%i].ceof\"",mName.c_str(),ceo_i);
	}
	void getUnitlessValues(size_t uv_i)const
	{
		fprintf(mFile,"\"%s.uv[%i]\"",mName.c_str(),uv_i);
	}
	void getUnitlessValues()const
	{

		fprintf(mFile,"\"%s.uv\"",mName.c_str());
	}
	void getLinearValues(size_t lv_i)const
	{
		fprintf(mFile,"\"%s.lv[%i]\"",mName.c_str(),lv_i);
	}
	void getLinearValues()const
	{

		fprintf(mFile,"\"%s.lv\"",mName.c_str());
	}
	void getAngularValues(size_t av_i)const
	{
		fprintf(mFile,"\"%s.av[%i]\"",mName.c_str(),av_i);
	}
	void getAngularValues()const
	{

		fprintf(mFile,"\"%s.av\"",mName.c_str());
	}
	void getTimeValues(size_t tv_i)const
	{
		fprintf(mFile,"\"%s.tv[%i]\"",mName.c_str(),tv_i);
	}
	void getTimeValues()const
	{

		fprintf(mFile,"\"%s.tv\"",mName.c_str());
	}
	void getAnimationMapping()const
	{
		fprintf(mFile,"\"%s.am\"",mName.c_str());
	}
	void getReferenceMapping()const
	{
		fprintf(mFile,"\"%s.rm\"",mName.c_str());
	}
	void getOffsetNode()const
	{
		fprintf(mFile,"\"%s.ofn\"",mName.c_str());
	}
protected:
	Character(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ObjectSet(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CHARACTER_H__
