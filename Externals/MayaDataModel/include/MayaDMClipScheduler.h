/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLIPSCHEDULER_H__
#define __MayaDM_CLIPSCHEDULER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ClipScheduler : public DependNode
{
public:
	struct BlendList{
		struct BlendList_Inmap{
			short blendList_InmapTo;
			short blendList_InmapFrom;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", blendList_InmapTo);
				fprintf(file,"%i", blendList_InmapFrom);
			}
		}* blendList_Inmap;
		size_t nbBlendList_Inmap;
		struct BlendList_Outmap{
			short blendList_OutmapTo;
			short blendList_OutmapFrom;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", blendList_OutmapTo);
				fprintf(file,"%i", blendList_OutmapFrom);
			}
		}* blendList_Outmap;
		size_t nbBlendList_Outmap;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbBlendList_Inmap; ++i)
			{
				blendList_Inmap[i].write(file);
				fprintf(file, " ");
				if (i + 1<nbBlendList_Inmap) fprintf(file, " ");
			}
			for (size_t i = 0; i<nbBlendList_Outmap; ++i)
			{
				blendList_Outmap[i].write(file);
				if (i + 1<nbBlendList_Outmap) fprintf(file, " ");
			}
		}
	};
	struct BlendClips{
		int firstClip;
		int secondClip;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", firstClip);
			fprintf(file,"%i", secondClip);
		}
	};
	struct ClipFunction{
		struct ClipFunction_Inmap{
			short clipFunction_InmapTo;
			short clipFunction_InmapFrom;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", clipFunction_InmapTo);
				fprintf(file,"%i", clipFunction_InmapFrom);
			}
		}* clipFunction_Inmap;
		size_t nbClipFunction_Inmap;
		struct ClipFunction_Outmap{
			short clipFunction_OutmapTo;
			short clipFunction_OutmapFrom;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", clipFunction_OutmapTo);
				fprintf(file,"%i", clipFunction_OutmapFrom);
			}
		}* clipFunction_Outmap;
		size_t nbClipFunction_Outmap;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbClipFunction_Inmap; ++i)
			{
				clipFunction_Inmap[i].write(file);
				fprintf(file, " ");
				if (i + 1<nbClipFunction_Inmap) fprintf(file, " ");
			}
			for (size_t i = 0; i<nbClipFunction_Outmap; ++i)
			{
				clipFunction_Outmap[i].write(file);
				if (i + 1<nbClipFunction_Outmap) fprintf(file, " ");
			}
		}
	};
public:

	ClipScheduler():DependNode(){}
	ClipScheduler(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "clipScheduler", shared, create){}
	virtual ~ClipScheduler(){}

	void setBlendList(size_t bl_i,const BlendList& bl)
	{
		fprintf(mFile,"\tsetAttr \".bl[%i]\" ",bl_i);
		bl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlendList(size_t bl_start,size_t bl_end,BlendList* bl)
	{
		fprintf(mFile,"\tsetAttr \".bl[%i:%i]\" ", bl_start,bl_end);
		size_t size = (bl_end-bl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			bl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBlendList(size_t bl_start,size_t bl_end)const
	{
		fprintf(mFile,"\tsetAttr \".bl[%i:%i]\"",bl_start,bl_end);
		fprintf(mFile," -type \"BlendList\" ");
	}
	void appendBlendList(const BlendList& bl)const
	{
		fprintf(mFile," ");
		bl.write(mFile);
	}
	void endBlendList()const
	{
		fprintf(mFile,";\n");
	}
	void setBlendList_Inmap(size_t bl_i,size_t bli_i,const BlendList::BlendList_Inmap& bli)
	{
		fprintf(mFile,"\tsetAttr \".bl[%i].bli[%i]\" ",bl_i,bli_i);
		bli.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlendList_Inmap(size_t bl_i,size_t bli_start,size_t bli_end,BlendList::BlendList_Inmap* bli)
	{
		fprintf(mFile,"\tsetAttr \".bl[%i].bli[%i:%i]\" ", bl_i,bli_start,bli_end);
		size_t size = (bli_end-bli_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			bli[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBlendList_Inmap(size_t bl_i,size_t bli_start,size_t bli_end)const
	{
		fprintf(mFile,"\tsetAttr \".bl[%i].bli[%i:%i]\"",bl_i,bli_start,bli_end);
		fprintf(mFile," -type \"BlendList::BlendList_Inmap\" ");
	}
	void appendBlendList_Inmap(const BlendList::BlendList_Inmap& bli)const
	{
		fprintf(mFile," ");
		bli.write(mFile);
	}
	void endBlendList_Inmap()const
	{
		fprintf(mFile,";\n");
	}
	void setBlendList_InmapTo(size_t bl_i,size_t bli_i,short blit)
	{
		if(blit == 0) return;
		fprintf(mFile,"\tsetAttr \".bl[%i].bli[%i].blit\" %i;\n", bl_i,bli_i,blit);
	}
	void setBlendList_InmapFrom(size_t bl_i,size_t bli_i,short blif)
	{
		if(blif == 0) return;
		fprintf(mFile,"\tsetAttr \".bl[%i].bli[%i].blif\" %i;\n", bl_i,bli_i,blif);
	}
	void setBlendList_Outmap(size_t bl_i,size_t blo_i,const BlendList::BlendList_Outmap& blo)
	{
		fprintf(mFile,"\tsetAttr \".bl[%i].blo[%i]\" ",bl_i,blo_i);
		blo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlendList_Outmap(size_t bl_i,size_t blo_start,size_t blo_end,BlendList::BlendList_Outmap* blo)
	{
		fprintf(mFile,"\tsetAttr \".bl[%i].blo[%i:%i]\" ", bl_i,blo_start,blo_end);
		size_t size = (blo_end-blo_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			blo[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBlendList_Outmap(size_t bl_i,size_t blo_start,size_t blo_end)const
	{
		fprintf(mFile,"\tsetAttr \".bl[%i].blo[%i:%i]\"",bl_i,blo_start,blo_end);
		fprintf(mFile," -type \"BlendList::BlendList_Outmap\" ");
	}
	void appendBlendList_Outmap(const BlendList::BlendList_Outmap& blo)const
	{
		fprintf(mFile," ");
		blo.write(mFile);
	}
	void endBlendList_Outmap()const
	{
		fprintf(mFile,";\n");
	}
	void setBlendList_OutmapTo(size_t bl_i,size_t blo_i,short blot)
	{
		if(blot == 0) return;
		fprintf(mFile,"\tsetAttr \".bl[%i].blo[%i].blot\" %i;\n", bl_i,blo_i,blot);
	}
	void setBlendList_OutmapFrom(size_t bl_i,size_t blo_i,short blof)
	{
		if(blof == 0) return;
		fprintf(mFile,"\tsetAttr \".bl[%i].blo[%i].blof\" %i;\n", bl_i,blo_i,blof);
	}
	void setBlendClips(size_t bc_i,const BlendClips& bc)
	{
		fprintf(mFile,"\tsetAttr \".bc[%i]\" ",bc_i);
		bc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlendClips(size_t bc_start,size_t bc_end,BlendClips* bc)
	{
		fprintf(mFile,"\tsetAttr \".bc[%i:%i]\" ", bc_start,bc_end);
		size_t size = (bc_end-bc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			bc[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBlendClips(size_t bc_start,size_t bc_end)const
	{
		fprintf(mFile,"\tsetAttr \".bc[%i:%i]\"",bc_start,bc_end);
		fprintf(mFile," -type \"BlendClips\" ");
	}
	void appendBlendClips(const BlendClips& bc)const
	{
		fprintf(mFile," ");
		bc.write(mFile);
	}
	void endBlendClips()const
	{
		fprintf(mFile,";\n");
	}
	void setFirstClip(size_t bc_i,int fcl)
	{
		if(fcl == 0) return;
		fprintf(mFile,"\tsetAttr \".bc[%i].fcl\" %i;\n", bc_i,fcl);
	}
	void setSecondClip(size_t bc_i,int scl)
	{
		if(scl == 0) return;
		fprintf(mFile,"\tsetAttr \".bc[%i].scl\" %i;\n", bc_i,scl);
	}
	void setClipFunction_Inmap(size_t cfi_i,const ClipFunction::ClipFunction_Inmap& cfi)
	{
		fprintf(mFile,"\tsetAttr \".cf.cfi[%i]\" ",cfi_i);
		cfi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClipFunction_Inmap(size_t cfi_start,size_t cfi_end,ClipFunction::ClipFunction_Inmap* cfi)
	{
		fprintf(mFile,"\tsetAttr \".cf.cfi[%i:%i]\" ", cfi_start,cfi_end);
		size_t size = (cfi_end-cfi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cfi[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startClipFunction_Inmap(size_t cfi_start,size_t cfi_end)const
	{
		fprintf(mFile,"\tsetAttr \".cf.cfi[%i:%i]\"",cfi_start,cfi_end);
		fprintf(mFile," -type \"ClipFunction::ClipFunction_Inmap\" ");
	}
	void appendClipFunction_Inmap(const ClipFunction::ClipFunction_Inmap& cfi)const
	{
		fprintf(mFile," ");
		cfi.write(mFile);
	}
	void endClipFunction_Inmap()const
	{
		fprintf(mFile,";\n");
	}
	void setClipFunction_InmapTo(size_t cfi_i,short cfit)
	{
		if(cfit == 0) return;
		fprintf(mFile,"\tsetAttr \".cf.cfi[%i].cfit\" %i;\n", cfi_i,cfit);
	}
	void setClipFunction_InmapFrom(size_t cfi_i,short cfif)
	{
		if(cfif == 0) return;
		fprintf(mFile,"\tsetAttr \".cf.cfi[%i].cfif\" %i;\n", cfi_i,cfif);
	}
	void setClipFunction_Outmap(size_t cfo_i,const ClipFunction::ClipFunction_Outmap& cfo)
	{
		fprintf(mFile,"\tsetAttr \".cf.cfo[%i]\" ",cfo_i);
		cfo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClipFunction_Outmap(size_t cfo_start,size_t cfo_end,ClipFunction::ClipFunction_Outmap* cfo)
	{
		fprintf(mFile,"\tsetAttr \".cf.cfo[%i:%i]\" ", cfo_start,cfo_end);
		size_t size = (cfo_end-cfo_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cfo[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startClipFunction_Outmap(size_t cfo_start,size_t cfo_end)const
	{
		fprintf(mFile,"\tsetAttr \".cf.cfo[%i:%i]\"",cfo_start,cfo_end);
		fprintf(mFile," -type \"ClipFunction::ClipFunction_Outmap\" ");
	}
	void appendClipFunction_Outmap(const ClipFunction::ClipFunction_Outmap& cfo)const
	{
		fprintf(mFile," ");
		cfo.write(mFile);
	}
	void endClipFunction_Outmap()const
	{
		fprintf(mFile,";\n");
	}
	void setClipFunction_OutmapTo(size_t cfo_i,short cfot)
	{
		if(cfot == 0) return;
		fprintf(mFile,"\tsetAttr \".cf.cfo[%i].cfot\" %i;\n", cfo_i,cfot);
	}
	void setClipFunction_OutmapFrom(size_t cfo_i,short cfof)
	{
		if(cfof == 0) return;
		fprintf(mFile,"\tsetAttr \".cf.cfo[%i].cfof\" %i;\n", cfo_i,cfof);
	}
	void setStart(size_t st_i,double st)
	{
		if(st == 0) return;
		fprintf(mFile,"\tsetAttr \".st[%i]\" %f;\n", st_i,st);
	}
	void setStart(size_t st_start,size_t st_end,double* st)
	{
		fprintf(mFile,"\tsetAttr \".st[%i:%i]\" ", st_start,st_end);
		size_t size = (st_end-st_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",st[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startStart(size_t st_start,size_t st_end)const
	{
		fprintf(mFile,"\tsetAttr \".st[%i:%i]\"",st_start,st_end);
	}
	void appendStart(double st)const
	{
		fprintf(mFile," %f",st);
	}
	void endStart()const
	{
		fprintf(mFile,";\n");
	}
	void setSourceStart(size_t ss_i,double ss)
	{
		if(ss == 0) return;
		fprintf(mFile,"\tsetAttr \".ss[%i]\" %f;\n", ss_i,ss);
	}
	void setSourceStart(size_t ss_start,size_t ss_end,double* ss)
	{
		fprintf(mFile,"\tsetAttr \".ss[%i:%i]\" ", ss_start,ss_end);
		size_t size = (ss_end-ss_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ss[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startSourceStart(size_t ss_start,size_t ss_end)const
	{
		fprintf(mFile,"\tsetAttr \".ss[%i:%i]\"",ss_start,ss_end);
	}
	void appendSourceStart(double ss)const
	{
		fprintf(mFile," %f",ss);
	}
	void endSourceStart()const
	{
		fprintf(mFile,";\n");
	}
	void setSourceEnd(size_t se_i,double se)
	{
		if(se == 0) return;
		fprintf(mFile,"\tsetAttr \".se[%i]\" %f;\n", se_i,se);
	}
	void setSourceEnd(size_t se_start,size_t se_end,double* se)
	{
		fprintf(mFile,"\tsetAttr \".se[%i:%i]\" ", se_start,se_end);
		size_t size = (se_end-se_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",se[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startSourceEnd(size_t se_start,size_t se_end)const
	{
		fprintf(mFile,"\tsetAttr \".se[%i:%i]\"",se_start,se_end);
	}
	void appendSourceEnd(double se)const
	{
		fprintf(mFile," %f",se);
	}
	void endSourceEnd()const
	{
		fprintf(mFile,";\n");
	}
	void setScale(size_t sc_i,double sc)
	{
		if(sc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sc[%i]\" %f;\n", sc_i,sc);
	}
	void setScale(size_t sc_start,size_t sc_end,double* sc)
	{
		fprintf(mFile,"\tsetAttr \".sc[%i:%i]\" ", sc_start,sc_end);
		size_t size = (sc_end-sc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",sc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startScale(size_t sc_start,size_t sc_end)const
	{
		fprintf(mFile,"\tsetAttr \".sc[%i:%i]\"",sc_start,sc_end);
	}
	void appendScale(double sc)const
	{
		fprintf(mFile," %f",sc);
	}
	void endScale()const
	{
		fprintf(mFile,";\n");
	}
	void setHold(size_t h_i,double h)
	{
		if(h == 0) return;
		fprintf(mFile,"\tsetAttr \".h[%i]\" %f;\n", h_i,h);
	}
	void setHold(size_t h_start,size_t h_end,double* h)
	{
		fprintf(mFile,"\tsetAttr \".h[%i:%i]\" ", h_start,h_end);
		size_t size = (h_end-h_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",h[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startHold(size_t h_start,size_t h_end)const
	{
		fprintf(mFile,"\tsetAttr \".h[%i:%i]\"",h_start,h_end);
	}
	void appendHold(double h)const
	{
		fprintf(mFile," %f",h);
	}
	void endHold()const
	{
		fprintf(mFile,";\n");
	}
	void setWeight(size_t w_i,double w)
	{
		if(w == 1.0) return;
		fprintf(mFile,"\tsetAttr \".w[%i]\" %f;\n", w_i,w);
	}
	void setWeight(size_t w_start,size_t w_end,double* w)
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
	void appendWeight(double w)const
	{
		fprintf(mFile," %f",w);
	}
	void endWeight()const
	{
		fprintf(mFile,";\n");
	}
	void setWeightStyle(size_t ws_i,unsigned int ws)
	{
		if(ws == 0) return;
		fprintf(mFile,"\tsetAttr \".ws[%i]\" %i;\n", ws_i,ws);
	}
	void setWeightStyle(size_t ws_start,size_t ws_end,unsigned int* ws)
	{
		fprintf(mFile,"\tsetAttr \".ws[%i:%i]\" ", ws_start,ws_end);
		size_t size = (ws_end-ws_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ws[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startWeightStyle(size_t ws_start,size_t ws_end)const
	{
		fprintf(mFile,"\tsetAttr \".ws[%i:%i]\"",ws_start,ws_end);
	}
	void appendWeightStyle(unsigned int ws)const
	{
		fprintf(mFile," %i",ws);
	}
	void endWeightStyle()const
	{
		fprintf(mFile,";\n");
	}
	void setPreCycle(size_t cb_i,double cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cb[%i]\" %f;\n", cb_i,cb);
	}
	void setPreCycle(size_t cb_start,size_t cb_end,double* cb)
	{
		fprintf(mFile,"\tsetAttr \".cb[%i:%i]\" ", cb_start,cb_end);
		size_t size = (cb_end-cb_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cb[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startPreCycle(size_t cb_start,size_t cb_end)const
	{
		fprintf(mFile,"\tsetAttr \".cb[%i:%i]\"",cb_start,cb_end);
	}
	void appendPreCycle(double cb)const
	{
		fprintf(mFile," %f",cb);
	}
	void endPreCycle()const
	{
		fprintf(mFile,";\n");
	}
	void setPostCycle(size_t ca_i,double ca)
	{
		if(ca == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ca[%i]\" %f;\n", ca_i,ca);
	}
	void setPostCycle(size_t ca_start,size_t ca_end,double* ca)
	{
		fprintf(mFile,"\tsetAttr \".ca[%i:%i]\" ", ca_start,ca_end);
		size_t size = (ca_end-ca_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ca[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startPostCycle(size_t ca_start,size_t ca_end)const
	{
		fprintf(mFile,"\tsetAttr \".ca[%i:%i]\"",ca_start,ca_end);
	}
	void appendPostCycle(double ca)const
	{
		fprintf(mFile," %f",ca);
	}
	void endPostCycle()const
	{
		fprintf(mFile,";\n");
	}
	void setEnable(size_t ea_i,bool ea)
	{
		if(ea == 1) return;
		fprintf(mFile,"\tsetAttr \".ea[%i]\" %i;\n", ea_i,ea);
	}
	void setEnable(size_t ea_start,size_t ea_end,bool* ea)
	{
		fprintf(mFile,"\tsetAttr \".ea[%i:%i]\" ", ea_start,ea_end);
		size_t size = (ea_end-ea_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ea[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEnable(size_t ea_start,size_t ea_end)const
	{
		fprintf(mFile,"\tsetAttr \".ea[%i:%i]\"",ea_start,ea_end);
	}
	void appendEnable(bool ea)const
	{
		fprintf(mFile," %i",ea);
	}
	void endEnable()const
	{
		fprintf(mFile,";\n");
	}
	void setTrack(size_t tr_i,short tr)
	{
		if(tr == 0) return;
		fprintf(mFile,"\tsetAttr \".tr[%i]\" %i;\n", tr_i,tr);
	}
	void setTrack(size_t tr_start,size_t tr_end,short* tr)
	{
		fprintf(mFile,"\tsetAttr \".tr[%i:%i]\" ", tr_start,tr_end);
		size_t size = (tr_end-tr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",tr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startTrack(size_t tr_start,size_t tr_end)const
	{
		fprintf(mFile,"\tsetAttr \".tr[%i:%i]\"",tr_start,tr_end);
	}
	void appendTrack(short tr)const
	{
		fprintf(mFile," %i",tr);
	}
	void endTrack()const
	{
		fprintf(mFile,";\n");
	}
	void setTrackState(size_t ts_i,short ts)
	{
		if(ts == 0) return;
		fprintf(mFile,"\tsetAttr \".ts[%i]\" %i;\n", ts_i,ts);
	}
	void setTrackState(size_t ts_start,size_t ts_end,short* ts)
	{
		fprintf(mFile,"\tsetAttr \".ts[%i:%i]\" ", ts_start,ts_end);
		size_t size = (ts_end-ts_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ts[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startTrackState(size_t ts_start,size_t ts_end)const
	{
		fprintf(mFile,"\tsetAttr \".ts[%i:%i]\"",ts_start,ts_end);
	}
	void appendTrackState(short ts)const
	{
		fprintf(mFile," %i",ts);
	}
	void endTrackState()const
	{
		fprintf(mFile,";\n");
	}
	void setNumTracks(short nt)
	{
		if(nt == 0) return;
		fprintf(mFile,"\tsetAttr \".nt\" %i;\n", nt);
	}
	void setCycle(size_t cy_i,double cy)
	{
		if(cy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cy[%i]\" %f;\n", cy_i,cy);
	}
	void setCycle(size_t cy_start,size_t cy_end,double* cy)
	{
		fprintf(mFile,"\tsetAttr \".cy[%i:%i]\" ", cy_start,cy_end);
		size_t size = (cy_end-cy_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cy[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startCycle(size_t cy_start,size_t cy_end)const
	{
		fprintf(mFile,"\tsetAttr \".cy[%i:%i]\"",cy_start,cy_end);
	}
	void appendCycle(double cy)const
	{
		fprintf(mFile," %f",cy);
	}
	void endCycle()const
	{
		fprintf(mFile,";\n");
	}
	void getBlendList(size_t bl_i)const
	{
		fprintf(mFile,"\"%s.bl[%i]\"",mName.c_str(),bl_i);
	}
	void getBlendList()const
	{

		fprintf(mFile,"\"%s.bl\"",mName.c_str());
	}
	void getBlendList_Raw(size_t bl_i)const
	{
		fprintf(mFile,"\"%s.bl[%i].blr\"",mName.c_str(),bl_i);
	}
	void getBlendList_Raw()const
	{

		fprintf(mFile,"\"%s.bl.blr\"",mName.c_str());
	}
	void getBlendList_Inmap(size_t bl_i,size_t bli_i)const
	{
		fprintf(mFile,"\"%s.bl[%i].bli[%i]\"",mName.c_str(),bl_i,bli_i);
	}
	void getBlendList_Inmap(size_t bli_i)const
	{

		fprintf(mFile,"\"%s.bl.bli[%i]\"",mName.c_str(),bli_i);
	}
	void getBlendList_InmapTo(size_t bl_i,size_t bli_i)const
	{
		fprintf(mFile,"\"%s.bl[%i].bli[%i].blit\"",mName.c_str(),bl_i,bli_i);
	}
	void getBlendList_InmapTo(size_t bli_i)const
	{

		fprintf(mFile,"\"%s.bl.bli[%i].blit\"",mName.c_str(),bli_i);
	}
	void getBlendList_InmapFrom(size_t bl_i,size_t bli_i)const
	{
		fprintf(mFile,"\"%s.bl[%i].bli[%i].blif\"",mName.c_str(),bl_i,bli_i);
	}
	void getBlendList_InmapFrom(size_t bli_i)const
	{

		fprintf(mFile,"\"%s.bl.bli[%i].blif\"",mName.c_str(),bli_i);
	}
	void getBlendList_Outmap(size_t bl_i,size_t blo_i)const
	{
		fprintf(mFile,"\"%s.bl[%i].blo[%i]\"",mName.c_str(),bl_i,blo_i);
	}
	void getBlendList_Outmap(size_t blo_i)const
	{

		fprintf(mFile,"\"%s.bl.blo[%i]\"",mName.c_str(),blo_i);
	}
	void getBlendList_OutmapTo(size_t bl_i,size_t blo_i)const
	{
		fprintf(mFile,"\"%s.bl[%i].blo[%i].blot\"",mName.c_str(),bl_i,blo_i);
	}
	void getBlendList_OutmapTo(size_t blo_i)const
	{

		fprintf(mFile,"\"%s.bl.blo[%i].blot\"",mName.c_str(),blo_i);
	}
	void getBlendList_OutmapFrom(size_t bl_i,size_t blo_i)const
	{
		fprintf(mFile,"\"%s.bl[%i].blo[%i].blof\"",mName.c_str(),bl_i,blo_i);
	}
	void getBlendList_OutmapFrom(size_t blo_i)const
	{

		fprintf(mFile,"\"%s.bl.blo[%i].blof\"",mName.c_str(),blo_i);
	}
	void getClipEvaluate()const
	{
		fprintf(mFile,"\"%s.ce\"",mName.c_str());
	}
	void getClipFunction()const
	{
		fprintf(mFile,"\"%s.cf\"",mName.c_str());
	}
	void getClipFunction_Raw()const
	{
		fprintf(mFile,"\"%s.cf.cfr\"",mName.c_str());
	}
	void getClipFunction_Inmap(size_t cfi_i)const
	{
		fprintf(mFile,"\"%s.cf.cfi[%i]\"",mName.c_str(),cfi_i);
	}
	void getClipFunction_InmapTo(size_t cfi_i)const
	{
		fprintf(mFile,"\"%s.cf.cfi[%i].cfit\"",mName.c_str(),cfi_i);
	}
	void getClipFunction_InmapFrom(size_t cfi_i)const
	{
		fprintf(mFile,"\"%s.cf.cfi[%i].cfif\"",mName.c_str(),cfi_i);
	}
	void getClipFunction_Outmap(size_t cfo_i)const
	{
		fprintf(mFile,"\"%s.cf.cfo[%i]\"",mName.c_str(),cfo_i);
	}
	void getClipFunction_OutmapTo(size_t cfo_i)const
	{
		fprintf(mFile,"\"%s.cf.cfo[%i].cfot\"",mName.c_str(),cfo_i);
	}
	void getClipFunction_OutmapFrom(size_t cfo_i)const
	{
		fprintf(mFile,"\"%s.cf.cfo[%i].cfof\"",mName.c_str(),cfo_i);
	}
	void getClip(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i]\"",mName.c_str(),cl_i);
	}
	void getClip()const
	{

		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getStart(size_t st_i)const
	{
		fprintf(mFile,"\"%s.st[%i]\"",mName.c_str(),st_i);
	}
	void getStart()const
	{

		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getSourceStart(size_t ss_i)const
	{
		fprintf(mFile,"\"%s.ss[%i]\"",mName.c_str(),ss_i);
	}
	void getSourceStart()const
	{

		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getSourceEnd(size_t se_i)const
	{
		fprintf(mFile,"\"%s.se[%i]\"",mName.c_str(),se_i);
	}
	void getSourceEnd()const
	{

		fprintf(mFile,"\"%s.se\"",mName.c_str());
	}
	void getScale(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i]\"",mName.c_str(),sc_i);
	}
	void getScale()const
	{

		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getHold(size_t h_i)const
	{
		fprintf(mFile,"\"%s.h[%i]\"",mName.c_str(),h_i);
	}
	void getHold()const
	{

		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getWeight(size_t w_i)const
	{
		fprintf(mFile,"\"%s.w[%i]\"",mName.c_str(),w_i);
	}
	void getWeight()const
	{

		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getWeightStyle(size_t ws_i)const
	{
		fprintf(mFile,"\"%s.ws[%i]\"",mName.c_str(),ws_i);
	}
	void getWeightStyle()const
	{

		fprintf(mFile,"\"%s.ws\"",mName.c_str());
	}
	void getPreCycle(size_t cb_i)const
	{
		fprintf(mFile,"\"%s.cb[%i]\"",mName.c_str(),cb_i);
	}
	void getPreCycle()const
	{

		fprintf(mFile,"\"%s.cb\"",mName.c_str());
	}
	void getPostCycle(size_t ca_i)const
	{
		fprintf(mFile,"\"%s.ca[%i]\"",mName.c_str(),ca_i);
	}
	void getPostCycle()const
	{

		fprintf(mFile,"\"%s.ca\"",mName.c_str());
	}
	void getEnable(size_t ea_i)const
	{
		fprintf(mFile,"\"%s.ea[%i]\"",mName.c_str(),ea_i);
	}
	void getEnable()const
	{

		fprintf(mFile,"\"%s.ea\"",mName.c_str());
	}
	void getCycle(size_t cy_i)const
	{
		fprintf(mFile,"\"%s.cy[%i]\"",mName.c_str(),cy_i);
	}
	void getCycle()const
	{

		fprintf(mFile,"\"%s.cy\"",mName.c_str());
	}
	void getStartPercent(size_t sp_i)const
	{
		fprintf(mFile,"\"%s.sp[%i]\"",mName.c_str(),sp_i);
	}
	void getStartPercent()const
	{

		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getAbsolute(size_t a_i)const
	{
		fprintf(mFile,"\"%s.a[%i]\"",mName.c_str(),a_i);
	}
	void getAbsolute()const
	{

		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getAbsoluteRotations(size_t ar_i)const
	{
		fprintf(mFile,"\"%s.ar[%i]\"",mName.c_str(),ar_i);
	}
	void getAbsoluteRotations()const
	{

		fprintf(mFile,"\"%s.ar\"",mName.c_str());
	}
protected:
	ClipScheduler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLIPSCHEDULER_H__
