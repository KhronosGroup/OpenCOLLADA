/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMCLIP_H__
#define __MayaDM_ANIMCLIP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Maya uses animation clips as the building block of its non-linear
  animation system, "Trax". An animation clip allows the user to
  bundle a set of animation curves independent of time so that they
  can be reused multiple times, with different timing than the
  original clip.
<p/>
  Character sets are integral to Maya's use of clips,
  since a clip contains whatever attributes of the character were animated
  when the clip was created. For more information on character sets, refer
  to the character node documentation.
<p/>
  Clips in maya can be of two types: source clips and scheduled
  clips. Scheduled clips are also referred to as instanced clips.
  In the Maya UI, source clips are visible in the Visor while
  scheduled clips are visible in Trax. A source clip maintains the
  animation curves for the clip. A scheduled clip contains data about
  the placement of an instance of a source clip in the Maya
  timeline. In this context, an "instance" means that the animation
  curves from the source clip are shared by the scheduled
  clip. Scheduled clips never contain their own animation curves, they
  always refer to a source clip's curves.
<p/>
  For example, if you create a clip called "run" in maya that lasts
  from frames 1-20, a source clip node will be created with a start of
  1, a duration of 19, and dependency graph connections to all of the
  animation curves that make up the "run". If you then place an
  instance of the run clip at frame 5 and another instance of the run
  clip at frame 20, you have 2 scheduled clips: one with a start frame
  of 5 and one with a start frame of 20. As mentioned in the previous
  paragraph, only a single set of animation curves exist for the
  run regardless of the number of times the run is scheduled.
<p/>
  Trax also allows you to create "blends" between clips, which enable you to
  control the transition between the clips. A blend is represented in the
  dependency graph by an "animBlendInOut" node, which uses an animation curve
  to determine the transition type.
<p/>
  In the dependency graph, when a character has animation clips, the
  character node will always be connected to a "clipLibrary" node and
  a "clipScheduler" node. The clipLibrary node is connected to all of
  the source clips and their animation curves. The clipScheduler node
  is connected to the scheduled clips and blends. It is the clipScheduler
  that computes the final animation by looking at the placement and overlap
  of the clips and feeding the attribute data back into the character set.
*/
class AnimClip : public DependNode
{
public:
public:
	AnimClip(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "animClip"){}
	virtual ~AnimClip(){}
	/*Whether the clip is enabled*/
	void setEnable(bool ea){if(ea == 1) return; fprintf_s(mFile, "setAttr \".ea\" %i;\n", ea);}
	/*Whether the clip is enabled*/
	void setEnable(const BoolID& ea){fprintf_s(mFile,"connectAttr \"");ea.write(mFile);fprintf_s(mFile,"\" \"%s.ea\";\n",mName.c_str());}
	/*
	When set to true the channel starts at the keyed value (absolute)
	if set to false the channel is treated as an offset (relative)
	to prevent jumps
	*/
	void setAbsoluteChannel(size_t ac_i,bool ac){if(ac == false) return; fprintf_s(mFile, "setAttr \".ac[%i]\" %i;\n", ac_i,ac);}
	/*
	When set to true the channel starts at the keyed value (absolute)
	if set to false the channel is treated as an offset (relative)
	to prevent jumps
	*/
	void setAbsoluteChannel(size_t ac_i,const BoolID& ac){fprintf_s(mFile,"connectAttr \"");ac.write(mFile);fprintf_s(mFile,"\" \"%s.ac[%i]\";\n",mName.c_str(),ac_i);}
	/*
	After all the scaling, pre and post cycles have been determined
	add this value to a channel to tweak its value
	Use this to compensate/adjust for ending/overlapping values
	from previous/simultaneous clips
	*/
	void setChannelOffset(size_t co_i,double co){if(co == 0.0) return; fprintf_s(mFile, "setAttr \".co[%i]\" %f;\n", co_i,co);}
	/*
	After all the scaling, pre and post cycles have been determined
	add this value to a channel to tweak its value
	Use this to compensate/adjust for ending/overlapping values
	from previous/simultaneous clips
	*/
	void setChannelOffset(size_t co_i,const DoubleID& co){fprintf_s(mFile,"connectAttr \"");co.write(mFile);fprintf_s(mFile,"\" \"%s.co[%i]\";\n",mName.c_str(),co_i);}
	/*The actual start frame where the clip is placed for playback.*/
	void setStartFrame(const TimeID& sf){fprintf_s(mFile,"connectAttr \"");sf.write(mFile);fprintf_s(mFile,"\" \"%s.sf\";\n",mName.c_str());}
	/*Used to scale the clip*/
	void setScale(double sc){if(sc == 1.0) return; fprintf_s(mFile, "setAttr \".sc\" %f;\n", sc);}
	/*Used to scale the clip*/
	void setScale(const DoubleID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*Length of time that the clip holds its end value.*/
	void setHold(const TimeID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*
	The preCycle value is used to repeat the clip, in whole or in part,
	before the beginning of the basic clip.
	*/
	void setPreCycle(double cb){if(cb == 0.0) return; fprintf_s(mFile, "setAttr \".cb\" %f;\n", cb);}
	/*
	The preCycle value is used to repeat the clip, in whole or in part,
	before the beginning of the basic clip.
	*/
	void setPreCycle(const DoubleID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cb\";\n",mName.c_str());}
	/*
	The postCycle value is used to repeat the clip, in whole or in part,
	after the end of the basic clip.
	*/
	void setPostCycle(double ca){if(ca == 0.0) return; fprintf_s(mFile, "setAttr \".ca\" %f;\n", ca);}
	/*
	The postCycle value is used to repeat the clip, in whole or in part,
	after the end of the basic clip.
	*/
	void setPostCycle(const DoubleID& ca){fprintf_s(mFile,"connectAttr \"");ca.write(mFile);fprintf_s(mFile,"\" \"%s.ca\";\n",mName.c_str());}
	/*Weight for the clip*/
	void setWeight(double w){if(w == 1.0) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*Weight for the clip*/
	void setWeight(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*
	How the clip weighting is applied. `From Start` indicates that a weight of zero returns the
	clip to its start frame. `From Zero` indicates that a weight of zero sets the attributes
	in the clip to zero. `Absolute From Zero` indicates that absolute channels are weighted
	`From Zero` and relative channels are weighted `From Start`.
	*/
	void setWeightStyle(unsigned int ws){if(ws == 0) return; fprintf_s(mFile, "setAttr \".ws\" %i;\n", ws);}
	/*
	How the clip weighting is applied. `From Start` indicates that a weight of zero returns the
	clip to its start frame. `From Zero` indicates that a weight of zero sets the attributes
	in the clip to zero. `Absolute From Zero` indicates that absolute channels are weighted
	`From Zero` and relative channels are weighted `From Start`.
	*/
	void setWeightStyle(const UnsignedintID& ws){fprintf_s(mFile,"connectAttr \"");ws.write(mFile);fprintf_s(mFile,"\" \"%s.ws\";\n",mName.c_str());}
	/*
	A clip pose is handled like a regular clip,
	but when the pose attribute is set to true, the clip is displayed in
	the pose section of the Visor.
	*/
	void setPose(bool ps){if(ps == false) return; fprintf_s(mFile, "setAttr \".ps\" %i;\n", ps);}
	/*
	A clip pose is handled like a regular clip,
	but when the pose attribute is set to true, the clip is displayed in
	the pose section of the Visor.
	*/
	void setPose(const BoolID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*
	The time on the original animCurve(s) where the clip starts.
	Used to trim the beginning portion of the animCurve(s) to
	the desired starting point.
	Modifying this attribute only affects this instance of the clip.
	See the description of the clipInstance attribute for more
	information about the source clip and clip instances.
	*/
	void setSourceStart(const TimeID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*
	The time on the original animCurve(s) where the clip ends.
	Used to trim the ending portion of the animCurve(s) to
	the desired ending point.
	Modifying this attribute only affects this instance of the clip.
	See the description of the clipInstance attribute for more
	information about the source clip and clip instances.
	*/
	void setSourceEnd(const TimeID& se){fprintf_s(mFile,"connectAttr \"");se.write(mFile);fprintf_s(mFile,"\" \"%s.se\";\n",mName.c_str());}
	/*
	The clip message attributes is used to connect
	instance clip nodes to their source clip node.
	As well it connects source clips to their library node.
	*/
	void setClip(const MessageID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl\";\n",mName.c_str());}
	/*
	If this value is true, the clip is an instanced version of a
	"source clip", meaning that the clip shares the animCurves of
	the source clip but is placed in the clip editor at a different
	position than the original source clip was recorded.
	Deleting an instanced clip removes its instance from the
	schedule (the clip editor).
	If this value is false, the clip is the source clip and
	its animCurves are shared by all instanced version of it.
	Deleting the source clip deletes all instances of the clip.
	*/
	void setClipInstance(bool ci){if(ci == 1) return; fprintf_s(mFile, "setAttr \".ci\" %i;\n", ci);}
	/*
	If this value is true, the clip is an instanced version of a
	"source clip", meaning that the clip shares the animCurves of
	the source clip but is placed in the clip editor at a different
	position than the original source clip was recorded.
	Deleting an instanced clip removes its instance from the
	schedule (the clip editor).
	If this value is false, the clip is the source clip and
	its animCurves are shared by all instanced version of it.
	Deleting the source clip deletes all instances of the clip.
	*/
	void setClipInstance(const BoolID& ci){fprintf_s(mFile,"connectAttr \"");ci.write(mFile);fprintf_s(mFile,"\" \"%s.ci\";\n",mName.c_str());}
	/*
	Input for a timewarp curve or expression. The only values that
	are used are between times 0 and 1.
	*/
	void setTimeWarp(double tw){if(tw == 0.0) return; fprintf_s(mFile, "setAttr \".tw\" %f;\n", tw);}
	/*
	Input for a timewarp curve or expression. The only values that
	are used are between times 0 and 1.
	*/
	void setTimeWarp(const DoubleID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tw\";\n",mName.c_str());}
	/*
	Determines if an animation curve connected to the timeWarp
	attribute is used as a time warp curve.
	*/
	void setTimeWarpEnable(bool twe){if(twe == false) return; fprintf_s(mFile, "setAttr \".twe\" %i;\n", twe);}
	/*
	Determines if an animation curve connected to the timeWarp
	attribute is used as a time warp curve.
	*/
	void setTimeWarpEnable(const BoolID& twe){fprintf_s(mFile,"connectAttr \"");twe.write(mFile);fprintf_s(mFile,"\" \"%s.twe\";\n",mName.c_str());}
	/*
	This attribute is obsolete, it has been replaced
	by the sourceStart and sourceEnd attributes.
	*/
	void setStart(const TimeID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*
	This attribute is obsolete, it has been replaced
	by the sourceStart and sourceEnd attributes.
	*/
	void setDuration(const TimeID& du){fprintf_s(mFile,"connectAttr \"");du.write(mFile);fprintf_s(mFile,"\" \"%s.du\";\n",mName.c_str());}
	/*
	This attribute is obsolete, it has been replaced
	by the absoluteChannel attribute.
	*/
	void setOffset(const UnsignedintID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*
	This attribute is obsolete, it has been replaced
	by the absoluteChannel attribute.
	*/
	void setAbsoluteRotations(const BoolID& abro){fprintf_s(mFile,"connectAttr \"");abro.write(mFile);fprintf_s(mFile,"\" \"%s.abro\";\n",mName.c_str());}
	/*This attribute is obsolete.*/
	void setCycle(double cy){if(cy == 1.0) return; fprintf_s(mFile, "setAttr \".cy\" %f;\n", cy);}
	/*This attribute is obsolete.*/
	void setCycle(const DoubleID& cy){fprintf_s(mFile,"connectAttr \"");cy.write(mFile);fprintf_s(mFile,"\" \"%s.cy\";\n",mName.c_str());}
	/*This attribute is obsolete.*/
	void setStartTrim(const TimeID& str){fprintf_s(mFile,"connectAttr \"");str.write(mFile);fprintf_s(mFile,"\" \"%s.str\";\n",mName.c_str());}
	/*This attribute is obsolete.*/
	void setStartPercent(const DoubleID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*Whether the clip is enabled*/
	BoolID getEnable(){char buffer[4096];sprintf_s (buffer, "%s.ea",mName.c_str());return (const char*)buffer;}
	/*
	When set to true the channel starts at the keyed value (absolute)
	if set to false the channel is treated as an offset (relative)
	to prevent jumps
	*/
	const BoolID& getAbsoluteChannel(size_t ac_i){char buffer[4096];sprintf_s (buffer, "%s.ac[%i]",mName.c_str(),ac_i);return (const char*)buffer;}
	/*
	After all the scaling, pre and post cycles have been determined
	add this value to a channel to tweak its value
	Use this to compensate/adjust for ending/overlapping values
	from previous/simultaneous clips
	*/
	const DoubleID& getChannelOffset(size_t co_i){char buffer[4096];sprintf_s (buffer, "%s.co[%i]",mName.c_str(),co_i);return (const char*)buffer;}
	/*The actual start frame where the clip is placed for playback.*/
	TimeID getStartFrame(){char buffer[4096];sprintf_s (buffer, "%s.sf",mName.c_str());return (const char*)buffer;}
	/*Used to scale the clip*/
	DoubleID getScale(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*Length of time that the clip holds its end value.*/
	TimeID getHold(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*
	The preCycle value is used to repeat the clip, in whole or in part,
	before the beginning of the basic clip.
	*/
	DoubleID getPreCycle(){char buffer[4096];sprintf_s (buffer, "%s.cb",mName.c_str());return (const char*)buffer;}
	/*
	The postCycle value is used to repeat the clip, in whole or in part,
	after the end of the basic clip.
	*/
	DoubleID getPostCycle(){char buffer[4096];sprintf_s (buffer, "%s.ca",mName.c_str());return (const char*)buffer;}
	/*Weight for the clip*/
	DoubleID getWeight(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*
	How the clip weighting is applied. `From Start` indicates that a weight of zero returns the
	clip to its start frame. `From Zero` indicates that a weight of zero sets the attributes
	in the clip to zero. `Absolute From Zero` indicates that absolute channels are weighted
	`From Zero` and relative channels are weighted `From Start`.
	*/
	UnsignedintID getWeightStyle(){char buffer[4096];sprintf_s (buffer, "%s.ws",mName.c_str());return (const char*)buffer;}
	/*
	A clip pose is handled like a regular clip,
	but when the pose attribute is set to true, the clip is displayed in
	the pose section of the Visor.
	*/
	BoolID getPose(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*
	The time on the original animCurve(s) where the clip starts.
	Used to trim the beginning portion of the animCurve(s) to
	the desired starting point.
	Modifying this attribute only affects this instance of the clip.
	See the description of the clipInstance attribute for more
	information about the source clip and clip instances.
	*/
	TimeID getSourceStart(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*
	The time on the original animCurve(s) where the clip ends.
	Used to trim the ending portion of the animCurve(s) to
	the desired ending point.
	Modifying this attribute only affects this instance of the clip.
	See the description of the clipInstance attribute for more
	information about the source clip and clip instances.
	*/
	TimeID getSourceEnd(){char buffer[4096];sprintf_s (buffer, "%s.se",mName.c_str());return (const char*)buffer;}
	/*
	The clip message attributes is used to connect
	instance clip nodes to their source clip node.
	As well it connects source clips to their library node.
	*/
	MessageID getClip(){char buffer[4096];sprintf_s (buffer, "%s.cl",mName.c_str());return (const char*)buffer;}
	/*
	If this value is true, the clip is an instanced version of a
	"source clip", meaning that the clip shares the animCurves of
	the source clip but is placed in the clip editor at a different
	position than the original source clip was recorded.
	Deleting an instanced clip removes its instance from the
	schedule (the clip editor).
	If this value is false, the clip is the source clip and
	its animCurves are shared by all instanced version of it.
	Deleting the source clip deletes all instances of the clip.
	*/
	BoolID getClipInstance(){char buffer[4096];sprintf_s (buffer, "%s.ci",mName.c_str());return (const char*)buffer;}
	/*
	Input for a timewarp curve or expression. The only values that
	are used are between times 0 and 1.
	*/
	DoubleID getTimeWarp(){char buffer[4096];sprintf_s (buffer, "%s.tw",mName.c_str());return (const char*)buffer;}
	/*
	Determines if an animation curve connected to the timeWarp
	attribute is used as a time warp curve.
	*/
	BoolID getTimeWarpEnable(){char buffer[4096];sprintf_s (buffer, "%s.twe",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is obsolete, it has been replaced
	by the sourceStart and sourceEnd attributes.
	*/
	TimeID getStart(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is obsolete, it has been replaced
	by the sourceStart and sourceEnd attributes.
	*/
	TimeID getDuration(){char buffer[4096];sprintf_s (buffer, "%s.du",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is obsolete, it has been replaced
	by the absoluteChannel attribute.
	*/
	UnsignedintID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is obsolete, it has been replaced
	by the absoluteChannel attribute.
	*/
	BoolID getAbsoluteRotations(){char buffer[4096];sprintf_s (buffer, "%s.abro",mName.c_str());return (const char*)buffer;}
	/*This attribute is obsolete.*/
	DoubleID getCycle(){char buffer[4096];sprintf_s (buffer, "%s.cy",mName.c_str());return (const char*)buffer;}
	/*This attribute is obsolete.*/
	TimeID getStartTrim(){char buffer[4096];sprintf_s (buffer, "%s.str",mName.c_str());return (const char*)buffer;}
	/*This attribute is obsolete.*/
	DoubleID getStartPercent(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
protected:
	AnimClip(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCLIP_H__
