/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
The clipScheduler node is used to control the sequencing and blending of
 clips on a character. Clips and blends scheduled on a character can be
 viewed in the UI using the Trax Editor.<p/>
 The clipScheduler is connected to a clipLibrary node that contains
 the source clips that have been defined for the character (source clips can
 be viewed in the UI using the Visor).<p/>

Clips can be instanced any number of times in the scheduler.
Clip instances in the scheduler share the same animation curves as the
source clip stored by the clipLibrary. Data for the clip's
attributes such as start, cycle, enable, weight are controlled by the clip's
associated animClip node. Each clip instance has its own unique animClip node.
*/
class ClipScheduler : public DependNode
{
public:
	/*A list of blends*/
	struct BlendList{
		/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
		struct BlendList_Inmap{
			short blendList_InmapTo;
			short blendList_InmapFrom;
			void write(FILE* file) const
			{
				fprintf_s(file,"%i ", blendList_InmapTo);
				fprintf_s(file,"%i", blendList_InmapFrom);
			}
		}* blendList_Inmap;
		/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
		struct BlendList_Outmap{
			short blendList_OutmapTo;
			short blendList_OutmapFrom;
			void write(FILE* file) const
			{
				fprintf_s(file,"%i ", blendList_OutmapTo);
				fprintf_s(file,"%i", blendList_OutmapFrom);
			}
		}* blendList_Outmap;
		void write(FILE* file) const
		{
			size_t size = sizeof(blendList_Inmap)/sizeof(BlendList_Inmap);
			for(size_t i=0; i<size; ++i)
			{
				blendList_Inmap[i].write(file);
				fprintf_s(file, " ");
				if(i+1<size) fprintf_s(file," ");
			}
			size = sizeof(blendList_Outmap)/sizeof(BlendList_Outmap);
			for(size_t i=0; i<size; ++i)
			{
				blendList_Outmap[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*
	A compound to store the indicies of the clip involved in the
	blend.
	*/
	struct BlendClips{
		int firstClip;
		int secondClip;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", firstClip);
			fprintf_s(file,"%i", secondClip);
		}
	};
	/*
	The clip function gets connected to a library that contains the
	clips being scheduled.
	*/
	struct ClipFunction{
		/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
		struct ClipFunction_Inmap{
			short clipFunction_InmapTo;
			short clipFunction_InmapFrom;
			void write(FILE* file) const
			{
				fprintf_s(file,"%i ", clipFunction_InmapTo);
				fprintf_s(file,"%i", clipFunction_InmapFrom);
			}
		}* clipFunction_Inmap;
		/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
		struct ClipFunction_Outmap{
			short clipFunction_OutmapTo;
			short clipFunction_OutmapFrom;
			void write(FILE* file) const
			{
				fprintf_s(file,"%i ", clipFunction_OutmapTo);
				fprintf_s(file,"%i", clipFunction_OutmapFrom);
			}
		}* clipFunction_Outmap;
		void write(FILE* file) const
		{
			size_t size = sizeof(clipFunction_Inmap)/sizeof(ClipFunction_Inmap);
			for(size_t i=0; i<size; ++i)
			{
				clipFunction_Inmap[i].write(file);
				fprintf_s(file, " ");
				if(i+1<size) fprintf_s(file," ");
			}
			size = sizeof(clipFunction_Outmap)/sizeof(ClipFunction_Outmap);
			for(size_t i=0; i<size; ++i)
			{
				clipFunction_Outmap[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	ClipScheduler(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "clipScheduler"){}
	virtual ~ClipScheduler(){}
	/*A list of blends*/
	void setBlendList(size_t bl_i,const BlendList& bl){fprintf_s(mFile, "setAttr \".bl[%i]\" ",bl_i);bl.write(mFile);fprintf_s(mFile,";\n");}
	/*A list of blends*/
	void setBlendList(size_t bl_i,const BlendListID& bl){fprintf_s(mFile,"connectAttr \"");bl.write(mFile);fprintf_s(mFile,"\" \"%s.bl[%i]\";\n",mName.c_str(),bl_i);}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	void setBlendList_Raw(size_t bl_i,const FunctionID& blr){fprintf_s(mFile,"connectAttr \"");blr.write(mFile);fprintf_s(mFile,"\" \"%s.bl[%i].blr\";\n",mName.c_str(),bl_i);}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setBlendList_Inmap(size_t bl_i,size_t bli_i,const BlendList::BlendList_Inmap& bli){fprintf_s(mFile, "setAttr \".bl[%i].bli[%i]\" ",bl_i,bli_i);bli.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setBlendList_Inmap(size_t bl_i,size_t bli_i,const BlendList_InmapID& bli){fprintf_s(mFile,"connectAttr \"");bli.write(mFile);fprintf_s(mFile,"\" \"%s.bl[%i].bli[%i]\";\n",mName.c_str(),bl_i,bli_i);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setBlendList_InmapTo(size_t bl_i,size_t bli_i,short blit){if(blit == 0) return; fprintf_s(mFile, "setAttr \".bl[%i].bli[%i].blit\" %i;\n", bl_i,bli_i,blit);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setBlendList_InmapTo(size_t bl_i,size_t bli_i,const ShortID& blit){fprintf_s(mFile,"connectAttr \"");blit.write(mFile);fprintf_s(mFile,"\" \"%s.bl[%i].bli[%i].blit\";\n",mName.c_str(),bl_i,bli_i);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setBlendList_InmapFrom(size_t bl_i,size_t bli_i,short blif){if(blif == 0) return; fprintf_s(mFile, "setAttr \".bl[%i].bli[%i].blif\" %i;\n", bl_i,bli_i,blif);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setBlendList_InmapFrom(size_t bl_i,size_t bli_i,const ShortID& blif){fprintf_s(mFile,"connectAttr \"");blif.write(mFile);fprintf_s(mFile,"\" \"%s.bl[%i].bli[%i].blif\";\n",mName.c_str(),bl_i,bli_i);}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setBlendList_Outmap(size_t bl_i,size_t blo_i,const BlendList::BlendList_Outmap& blo){fprintf_s(mFile, "setAttr \".bl[%i].blo[%i]\" ",bl_i,blo_i);blo.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setBlendList_Outmap(size_t bl_i,size_t blo_i,const BlendList_OutmapID& blo){fprintf_s(mFile,"connectAttr \"");blo.write(mFile);fprintf_s(mFile,"\" \"%s.bl[%i].blo[%i]\";\n",mName.c_str(),bl_i,blo_i);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setBlendList_OutmapTo(size_t bl_i,size_t blo_i,short blot){if(blot == 0) return; fprintf_s(mFile, "setAttr \".bl[%i].blo[%i].blot\" %i;\n", bl_i,blo_i,blot);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setBlendList_OutmapTo(size_t bl_i,size_t blo_i,const ShortID& blot){fprintf_s(mFile,"connectAttr \"");blot.write(mFile);fprintf_s(mFile,"\" \"%s.bl[%i].blo[%i].blot\";\n",mName.c_str(),bl_i,blo_i);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setBlendList_OutmapFrom(size_t bl_i,size_t blo_i,short blof){if(blof == 0) return; fprintf_s(mFile, "setAttr \".bl[%i].blo[%i].blof\" %i;\n", bl_i,blo_i,blof);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setBlendList_OutmapFrom(size_t bl_i,size_t blo_i,const ShortID& blof){fprintf_s(mFile,"connectAttr \"");blof.write(mFile);fprintf_s(mFile,"\" \"%s.bl[%i].blo[%i].blof\";\n",mName.c_str(),bl_i,blo_i);}
	/*
	A compound to store the indicies of the clip involved in the
	blend.
	*/
	void setBlendClips(size_t bc_i,const BlendClips& bc){fprintf_s(mFile, "setAttr \".bc[%i]\" ",bc_i);bc.write(mFile);fprintf_s(mFile,";\n");}
	/*The index for the first clip used by the blend.*/
	void setFirstClip(size_t bc_i,int fcl){if(fcl == 0) return; fprintf_s(mFile, "setAttr \".bc[%i].fcl\" %i;\n", bc_i,fcl);}
	/*The index for the second clip used by the blend*/
	void setSecondClip(size_t bc_i,int scl){if(scl == 0) return; fprintf_s(mFile, "setAttr \".bc[%i].scl\" %i;\n", bc_i,scl);}
	/*
	The clip evaluate function gets connected to the character that it
	controls. The character calls the clip function to evaluate the clip.
	*/
	void setClipEvaluate(const FunctionID& ce){fprintf_s(mFile,"connectAttr \"");ce.write(mFile);fprintf_s(mFile,"\" \"%s.ce\";\n",mName.c_str());}
	/*
	The clip function gets connected to a library that contains the
	clips being scheduled.
	*/
	void setClipFunction(const ClipFunctionID& cf){fprintf_s(mFile,"connectAttr \"");cf.write(mFile);fprintf_s(mFile,"\" \"%s.cf\";\n",mName.c_str());}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	void setClipFunction_Raw(const FunctionID& cfr){fprintf_s(mFile,"connectAttr \"");cfr.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfr\";\n",mName.c_str());}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setClipFunction_Inmap(size_t cfi_i,const ClipFunction::ClipFunction_Inmap& cfi){fprintf_s(mFile, "setAttr \".cf.cfi[%i]\" ",cfi_i);cfi.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setClipFunction_Inmap(size_t cfi_i,const ClipFunction_InmapID& cfi){fprintf_s(mFile,"connectAttr \"");cfi.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfi[%i]\";\n",mName.c_str(),cfi_i);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setClipFunction_InmapTo(size_t cfi_i,short cfit){if(cfit == 0) return; fprintf_s(mFile, "setAttr \".cf.cfi[%i].cfit\" %i;\n", cfi_i,cfit);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setClipFunction_InmapTo(size_t cfi_i,const ShortID& cfit){fprintf_s(mFile,"connectAttr \"");cfit.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfi[%i].cfit\";\n",mName.c_str(),cfi_i);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setClipFunction_InmapFrom(size_t cfi_i,short cfif){if(cfif == 0) return; fprintf_s(mFile, "setAttr \".cf.cfi[%i].cfif\" %i;\n", cfi_i,cfif);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setClipFunction_InmapFrom(size_t cfi_i,const ShortID& cfif){fprintf_s(mFile,"connectAttr \"");cfif.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfi[%i].cfif\";\n",mName.c_str(),cfi_i);}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setClipFunction_Outmap(size_t cfo_i,const ClipFunction::ClipFunction_Outmap& cfo){fprintf_s(mFile, "setAttr \".cf.cfo[%i]\" ",cfo_i);cfo.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setClipFunction_Outmap(size_t cfo_i,const ClipFunction_OutmapID& cfo){fprintf_s(mFile,"connectAttr \"");cfo.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfo[%i]\";\n",mName.c_str(),cfo_i);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setClipFunction_OutmapTo(size_t cfo_i,short cfot){if(cfot == 0) return; fprintf_s(mFile, "setAttr \".cf.cfo[%i].cfot\" %i;\n", cfo_i,cfot);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setClipFunction_OutmapTo(size_t cfo_i,const ShortID& cfot){fprintf_s(mFile,"connectAttr \"");cfot.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfo[%i].cfot\";\n",mName.c_str(),cfo_i);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setClipFunction_OutmapFrom(size_t cfo_i,short cfof){if(cfof == 0) return; fprintf_s(mFile, "setAttr \".cf.cfo[%i].cfof\" %i;\n", cfo_i,cfof);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setClipFunction_OutmapFrom(size_t cfo_i,const ShortID& cfof){fprintf_s(mFile,"connectAttr \"");cfof.write(mFile);fprintf_s(mFile,"\" \"%s.cf.cfo[%i].cfof\";\n",mName.c_str(),cfo_i);}
	/*
	The clip message is connected to the associated clip.
	Array indices for the clip attribute line up with those for
	start, sourceStart, sourceEnd, cycle, scale, enabled and track.
	*/
	void setClip(size_t cl_i,const MessageID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i]\";\n",mName.c_str(),cl_i);}
	/*time when the clip starts*/
	void setStart(size_t st_i,const TimeID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st[%i]\";\n",mName.c_str(),st_i);}
	/*Time when the clip starts on the original animation curves*/
	void setSourceStart(size_t ss_i,const TimeID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss[%i]\";\n",mName.c_str(),ss_i);}
	/*Time when the clip ends on the original animation curves*/
	void setSourceEnd(size_t se_i,const TimeID& se){fprintf_s(mFile,"connectAttr \"");se.write(mFile);fprintf_s(mFile,"\" \"%s.se[%i]\";\n",mName.c_str(),se_i);}
	/*Used to scale the clip*/
	void setScale(size_t sc_i,double sc){if(sc == 1.0) return; fprintf_s(mFile, "setAttr \".sc[%i]\" %f;\n", sc_i,sc);}
	/*Used to scale the clip*/
	void setScale(size_t sc_i,const DoubleID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i]\";\n",mName.c_str(),sc_i);}
	/*Length of time that the clip holds its end value.*/
	void setHold(size_t h_i,const TimeID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h[%i]\";\n",mName.c_str(),h_i);}
	/*The weight of the clip*/
	void setWeight(size_t w_i,double w){if(w == 1.0) return; fprintf_s(mFile, "setAttr \".w[%i]\" %f;\n", w_i,w);}
	/*The weight of the clip*/
	void setWeight(size_t w_i,const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w[%i]\";\n",mName.c_str(),w_i);}
	/*
	How the clip weighting is applied. `From Start` indicates that a weight of zero returns the
	clip to its start frame. `From Zero` indicates that a weight of zero sets the attributes
	in the clip to zero. `Rotations From Zero` indicates that a rotations are weighted `From Zero`
	and non-rotations are weighted `From Start`.
	*/
	void setWeightStyle(size_t ws_i,unsigned int ws){if(ws == 0) return; fprintf_s(mFile, "setAttr \".ws[%i]\" %i;\n", ws_i,ws);}
	/*
	How the clip weighting is applied. `From Start` indicates that a weight of zero returns the
	clip to its start frame. `From Zero` indicates that a weight of zero sets the attributes
	in the clip to zero. `Rotations From Zero` indicates that a rotations are weighted `From Zero`
	and non-rotations are weighted `From Start`.
	*/
	void setWeightStyle(size_t ws_i,const UnsignedintID& ws){fprintf_s(mFile,"connectAttr \"");ws.write(mFile);fprintf_s(mFile,"\" \"%s.ws[%i]\";\n",mName.c_str(),ws_i);}
	/*
	The preCycle value is used to repeat the clip, in whole or in part,
	before the beginning of the basic clip.
	*/
	void setPreCycle(size_t cb_i,double cb){if(cb == 0.0) return; fprintf_s(mFile, "setAttr \".cb[%i]\" %f;\n", cb_i,cb);}
	/*
	The preCycle value is used to repeat the clip, in whole or in part,
	before the beginning of the basic clip.
	*/
	void setPreCycle(size_t cb_i,const DoubleID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cb[%i]\";\n",mName.c_str(),cb_i);}
	/*
	The postCycle value is used to repeat the clip, in whole or in part,
	after the end of the basic clip.
	*/
	void setPostCycle(size_t ca_i,double ca){if(ca == 0.0) return; fprintf_s(mFile, "setAttr \".ca[%i]\" %f;\n", ca_i,ca);}
	/*
	The postCycle value is used to repeat the clip, in whole or in part,
	after the end of the basic clip.
	*/
	void setPostCycle(size_t ca_i,const DoubleID& ca){fprintf_s(mFile,"connectAttr \"");ca.write(mFile);fprintf_s(mFile,"\" \"%s.ca[%i]\";\n",mName.c_str(),ca_i);}
	/*whether the clip is enabled*/
	void setEnable(size_t ea_i,bool ea){if(ea == 1) return; fprintf_s(mFile, "setAttr \".ea[%i]\" %i;\n", ea_i,ea);}
	/*whether the clip is enabled*/
	void setEnable(size_t ea_i,const BoolID& ea){fprintf_s(mFile,"connectAttr \"");ea.write(mFile);fprintf_s(mFile,"\" \"%s.ea[%i]\";\n",mName.c_str(),ea_i);}
	/*track index for the clip*/
	void setTrack(size_t tr_i,short tr){if(tr == 0) return; fprintf_s(mFile, "setAttr \".tr[%i]\" %i;\n", tr_i,tr);}
	/*
	Flag bits for the track state.  Current mask values are:
	1: when set means that all the clips on the track are locked
	2: when set means that all the clips on the track are soloed
	4: when set means that all the clips on the track are muted
	8: when set means that all the clips on the track are ghosted
	*/
	void setTrackState(size_t ts_i,short ts){if(ts == 0) return; fprintf_s(mFile, "setAttr \".ts[%i]\" %i;\n", ts_i,ts);}
	/*the number of tracks in the scheduler*/
	void setNumTracks(short nt){if(nt == 0) return; fprintf_s(mFile, "setAttr \".nt\" %i;\n", nt);}
	/*This attribute is obsolete.*/
	void setCycle(size_t cy_i,double cy){if(cy == 1.0) return; fprintf_s(mFile, "setAttr \".cy[%i]\" %f;\n", cy_i,cy);}
	/*This attribute is obsolete.*/
	void setCycle(size_t cy_i,const DoubleID& cy){fprintf_s(mFile,"connectAttr \"");cy.write(mFile);fprintf_s(mFile,"\" \"%s.cy[%i]\";\n",mName.c_str(),cy_i);}
	/*This attribute is obsolete.*/
	void setStartPercent(size_t sp_i,const DoubleID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp[%i]\";\n",mName.c_str(),sp_i);}
	/*This attribute is obsolete.*/
	void setAbsolute(size_t a_i,const BoolID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a[%i]\";\n",mName.c_str(),a_i);}
	/*This attribute is obsolete.*/
	void setAbsoluteRotations(size_t ar_i,const BoolID& ar){fprintf_s(mFile,"connectAttr \"");ar.write(mFile);fprintf_s(mFile,"\" \"%s.ar[%i]\";\n",mName.c_str(),ar_i);}
	/*A list of blends*/
	const BlendListID& getBlendList(size_t bl_i){char buffer[4096];sprintf_s (buffer, "%s.bl[%i]",mName.c_str(),bl_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	const FunctionID& getBlendList_Raw(size_t bl_i){char buffer[4096];sprintf_s (buffer, "%s.bl[%i].blr",mName.c_str(),bl_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	const BlendList_InmapID& getBlendList_Inmap(size_t bl_i,size_t bli_i){char buffer[4096];sprintf_s (buffer, "%s.bl[%i].bli[%i]",mName.c_str(),bl_i,bli_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	const ShortID& getBlendList_InmapTo(size_t bl_i,size_t bli_i){char buffer[4096];sprintf_s (buffer, "%s.bl[%i].bli[%i].blit",mName.c_str(),bl_i,bli_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data input parameter index*/
	const ShortID& getBlendList_InmapFrom(size_t bl_i,size_t bli_i){char buffer[4096];sprintf_s (buffer, "%s.bl[%i].bli[%i].blif",mName.c_str(),bl_i,bli_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	const BlendList_OutmapID& getBlendList_Outmap(size_t bl_i,size_t blo_i){char buffer[4096];sprintf_s (buffer, "%s.bl[%i].blo[%i]",mName.c_str(),bl_i,blo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	const ShortID& getBlendList_OutmapTo(size_t bl_i,size_t blo_i){char buffer[4096];sprintf_s (buffer, "%s.bl[%i].blo[%i].blot",mName.c_str(),bl_i,blo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data output parameter index*/
	const ShortID& getBlendList_OutmapFrom(size_t bl_i,size_t blo_i){char buffer[4096];sprintf_s (buffer, "%s.bl[%i].blo[%i].blof",mName.c_str(),bl_i,blo_i);return (const char*)buffer;}
	/*
	The clip evaluate function gets connected to the character that it
	controls. The character calls the clip function to evaluate the clip.
	*/
	FunctionID getClipEvaluate(){char buffer[4096];sprintf_s (buffer, "%s.ce",mName.c_str());return (const char*)buffer;}
	/*
	The clip function gets connected to a library that contains the
	clips being scheduled.
	*/
	ClipFunctionID getClipFunction(){char buffer[4096];sprintf_s (buffer, "%s.cf",mName.c_str());return (const char*)buffer;}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	FunctionID getClipFunction_Raw(){char buffer[4096];sprintf_s (buffer, "%s.cf.cfr",mName.c_str());return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	const ClipFunction_InmapID& getClipFunction_Inmap(size_t cfi_i){char buffer[4096];sprintf_s (buffer, "%s.cf.cfi[%i]",mName.c_str(),cfi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	const ShortID& getClipFunction_InmapTo(size_t cfi_i){char buffer[4096];sprintf_s (buffer, "%s.cf.cfi[%i].cfit",mName.c_str(),cfi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data input parameter index*/
	const ShortID& getClipFunction_InmapFrom(size_t cfi_i){char buffer[4096];sprintf_s (buffer, "%s.cf.cfi[%i].cfif",mName.c_str(),cfi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	const ClipFunction_OutmapID& getClipFunction_Outmap(size_t cfo_i){char buffer[4096];sprintf_s (buffer, "%s.cf.cfo[%i]",mName.c_str(),cfo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	const ShortID& getClipFunction_OutmapTo(size_t cfo_i){char buffer[4096];sprintf_s (buffer, "%s.cf.cfo[%i].cfot",mName.c_str(),cfo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data output parameter index*/
	const ShortID& getClipFunction_OutmapFrom(size_t cfo_i){char buffer[4096];sprintf_s (buffer, "%s.cf.cfo[%i].cfof",mName.c_str(),cfo_i);return (const char*)buffer;}
	/*
	The clip message is connected to the associated clip.
	Array indices for the clip attribute line up with those for
	start, sourceStart, sourceEnd, cycle, scale, enabled and track.
	*/
	const MessageID& getClip(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i]",mName.c_str(),cl_i);return (const char*)buffer;}
	/*time when the clip starts*/
	const TimeID& getStart(size_t st_i){char buffer[4096];sprintf_s (buffer, "%s.st[%i]",mName.c_str(),st_i);return (const char*)buffer;}
	/*Time when the clip starts on the original animation curves*/
	const TimeID& getSourceStart(size_t ss_i){char buffer[4096];sprintf_s (buffer, "%s.ss[%i]",mName.c_str(),ss_i);return (const char*)buffer;}
	/*Time when the clip ends on the original animation curves*/
	const TimeID& getSourceEnd(size_t se_i){char buffer[4096];sprintf_s (buffer, "%s.se[%i]",mName.c_str(),se_i);return (const char*)buffer;}
	/*Used to scale the clip*/
	const DoubleID& getScale(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i]",mName.c_str(),sc_i);return (const char*)buffer;}
	/*Length of time that the clip holds its end value.*/
	const TimeID& getHold(size_t h_i){char buffer[4096];sprintf_s (buffer, "%s.h[%i]",mName.c_str(),h_i);return (const char*)buffer;}
	/*The weight of the clip*/
	const DoubleID& getWeight(size_t w_i){char buffer[4096];sprintf_s (buffer, "%s.w[%i]",mName.c_str(),w_i);return (const char*)buffer;}
	/*
	How the clip weighting is applied. `From Start` indicates that a weight of zero returns the
	clip to its start frame. `From Zero` indicates that a weight of zero sets the attributes
	in the clip to zero. `Rotations From Zero` indicates that a rotations are weighted `From Zero`
	and non-rotations are weighted `From Start`.
	*/
	const UnsignedintID& getWeightStyle(size_t ws_i){char buffer[4096];sprintf_s (buffer, "%s.ws[%i]",mName.c_str(),ws_i);return (const char*)buffer;}
	/*
	The preCycle value is used to repeat the clip, in whole or in part,
	before the beginning of the basic clip.
	*/
	const DoubleID& getPreCycle(size_t cb_i){char buffer[4096];sprintf_s (buffer, "%s.cb[%i]",mName.c_str(),cb_i);return (const char*)buffer;}
	/*
	The postCycle value is used to repeat the clip, in whole or in part,
	after the end of the basic clip.
	*/
	const DoubleID& getPostCycle(size_t ca_i){char buffer[4096];sprintf_s (buffer, "%s.ca[%i]",mName.c_str(),ca_i);return (const char*)buffer;}
	/*whether the clip is enabled*/
	const BoolID& getEnable(size_t ea_i){char buffer[4096];sprintf_s (buffer, "%s.ea[%i]",mName.c_str(),ea_i);return (const char*)buffer;}
	/*This attribute is obsolete.*/
	const DoubleID& getCycle(size_t cy_i){char buffer[4096];sprintf_s (buffer, "%s.cy[%i]",mName.c_str(),cy_i);return (const char*)buffer;}
	/*This attribute is obsolete.*/
	const DoubleID& getStartPercent(size_t sp_i){char buffer[4096];sprintf_s (buffer, "%s.sp[%i]",mName.c_str(),sp_i);return (const char*)buffer;}
	/*This attribute is obsolete.*/
	const BoolID& getAbsolute(size_t a_i){char buffer[4096];sprintf_s (buffer, "%s.a[%i]",mName.c_str(),a_i);return (const char*)buffer;}
	/*This attribute is obsolete.*/
	const BoolID& getAbsoluteRotations(size_t ar_i){char buffer[4096];sprintf_s (buffer, "%s.ar[%i]",mName.c_str(),ar_i);return (const char*)buffer;}
protected:
	ClipScheduler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLIPSCHEDULER_H__
