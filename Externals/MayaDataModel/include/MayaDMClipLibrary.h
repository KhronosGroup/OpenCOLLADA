/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLIPLIBRARY_H__
#define __MayaDM_CLIPLIBRARY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The clipLibrary node manages the source clips and their animation
  curves for a single character. The clipLibrary's compute method is
  able to evaluate the attached clips to obtain their attribute
  values at any time, independent of the current scene time.
<p/>
  While the clipLibrary node manages source clips, the clipScheduler node
  manages instanced clips. In other words, the clipLibrary handles the
  raw clip data, and the clipScheduler manages the placement of the clips
  on the timeline (clips placed in Trax).
<p/>
  Each character will be associated with at most a single clipLibrary and
  a single clipScheduler.
<p/>
  The clipLibrary node is able to keep track of source clips and their
  associated animCurves by connections in the dependency graph. Each source
  clip is represented by an <em>animClip</em> node which is connected to
  the clipLibrary's <b>sourceClip</b> attribute. The index of the array
  attribute where the sourceClip attribute is connected is used as an
  unique index to identify the connected source clip.
<p/>
  Animation curves are connected to the clipLibrary using
  function attributes. The function attributes
  allow the library to evaluate the curves at times other than the current
  scene time. The indices of the attributes where the animation curves are
  connected are used to correlate the curve to its associated clip and
  channel, as follows:
<p/>
<ul>
   <li>The <b>clipEvalList</b> attribute index correlates
   to the attribute index of the <b>sourceClip</b> of the
   animCurves related source clip (an <em>animClip</em> node).</li>
   <li>The <b>clipEval</b> attribute index for a connection correlates
   to the character index of the channel being driven by the
   connected animCurve.</li>
</ul>
<p/>
  Since the clipLibrary manages its associated clips via connections, it
  is important that all required connections are made when setting up clips.
  The API contains two function sets: <em>MFnClip</em> and
  <em>MFnCharacter</em>, which will make the proper clipLibrary connections
  when you create clips using the API.
*/
class ClipLibrary : public DependNode
{
public:
	/*An array of clipEvals, one entry per clip.*/
	struct ClipEvalList{
		/*
		An array of function attributes. The animation curves and expressions
		that drive this clip get connected to the _Raw attribute that is a
		child of this attribute.
		*/
		struct ClipEval{
			/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
			struct ClipEval_Inmap{
				short clipEval_InmapTo;
				short clipEval_InmapFrom;
				void write(FILE* file) const
				{
					fprintf_s(file,"%i ", clipEval_InmapTo);
					fprintf_s(file,"%i", clipEval_InmapFrom);
				}
			}* clipEval_Inmap;
			/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
			struct ClipEval_Outmap{
				short clipEval_OutmapTo;
				short clipEval_OutmapFrom;
				void write(FILE* file) const
				{
					fprintf_s(file,"%i ", clipEval_OutmapTo);
					fprintf_s(file,"%i", clipEval_OutmapFrom);
				}
			}* clipEval_Outmap;
			void write(FILE* file) const
			{
				size_t size = sizeof(clipEval_Inmap)/sizeof(ClipEval_Inmap);
				for(size_t i=0; i<size; ++i)
				{
					clipEval_Inmap[i].write(file);
					fprintf_s(file, " ");
					if(i+1<size) fprintf_s(file," ");
				}
				size = sizeof(clipEval_Outmap)/sizeof(ClipEval_Outmap);
				for(size_t i=0; i<size; ++i)
				{
					clipEval_Outmap[i].write(file);
					if(i+1<size) fprintf_s(file," ");
				}
			}
		}* clipEval;
		void write(FILE* file) const
		{
			size_t size = sizeof(clipEval)/sizeof(ClipEval);
			for(size_t i=0; i<size; ++i)
			{
				clipEval[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*
	An array of character data for the characters managed by this library.
	The character data allows the clipLibrary to correlate the animCurves
	of each clip to their associated character channel.
	*/
	struct Characterdata{
		intArray clipIndexMapping;
		void write(FILE* file) const
		{
			clipIndexMapping.write(file);
		}
	};
public:
	ClipLibrary(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "clipLibrary"){}
	virtual ~ClipLibrary(){}
	/*An array of clipEvals, one entry per clip.*/
	void setClipEvalList(size_t cel_i,const ClipEvalList& cel){fprintf_s(mFile, "setAttr \".cel[%i]\" ",cel_i);cel.write(mFile);fprintf_s(mFile,";\n");}
	/*An array of clipEvals, one entry per clip.*/
	void setClipEvalList(size_t cel_i,const ClipEvalListID& cel){fprintf_s(mFile,"connectAttr \"");cel.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i]\";\n",mName.c_str(),cel_i);}
	/*
	An array of function attributes. The animation curves and expressions
	that drive this clip get connected to the _Raw attribute that is a
	child of this attribute.
	*/
	void setClipEval(size_t cel_i,size_t cev_i,const ClipEvalList::ClipEval& cev){fprintf_s(mFile, "setAttr \".cel[%i].cev[%i]\" ",cel_i,cev_i);cev.write(mFile);fprintf_s(mFile,";\n");}
	/*
	An array of function attributes. The animation curves and expressions
	that drive this clip get connected to the _Raw attribute that is a
	child of this attribute.
	*/
	void setClipEval(size_t cel_i,size_t cev_i,const ClipEvalID& cev){fprintf_s(mFile,"connectAttr \"");cev.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].cev[%i]\";\n",mName.c_str(),cel_i,cev_i);}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	void setClipEval_Raw(size_t cel_i,size_t cev_i,const FunctionID& cevr){fprintf_s(mFile,"connectAttr \"");cevr.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].cev[%i].cevr\";\n",mName.c_str(),cel_i,cev_i);}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setClipEval_Inmap(size_t cel_i,size_t cev_i,size_t cevi_i,const ClipEvalList::ClipEval::ClipEval_Inmap& cevi){fprintf_s(mFile, "setAttr \".cel[%i].cev[%i].cevi[%i]\" ",cel_i,cev_i,cevi_i);cevi.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setClipEval_Inmap(size_t cel_i,size_t cev_i,size_t cevi_i,const ClipEval_InmapID& cevi){fprintf_s(mFile,"connectAttr \"");cevi.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].cev[%i].cevi[%i]\";\n",mName.c_str(),cel_i,cev_i,cevi_i);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setClipEval_InmapTo(size_t cel_i,size_t cev_i,size_t cevi_i,short cevit){if(cevit == 0) return; fprintf_s(mFile, "setAttr \".cel[%i].cev[%i].cevi[%i].cevit\" %i;\n", cel_i,cev_i,cevi_i,cevit);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setClipEval_InmapTo(size_t cel_i,size_t cev_i,size_t cevi_i,const ShortID& cevit){fprintf_s(mFile,"connectAttr \"");cevit.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].cev[%i].cevi[%i].cevit\";\n",mName.c_str(),cel_i,cev_i,cevi_i);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setClipEval_InmapFrom(size_t cel_i,size_t cev_i,size_t cevi_i,short cevif){if(cevif == 0) return; fprintf_s(mFile, "setAttr \".cel[%i].cev[%i].cevi[%i].cevif\" %i;\n", cel_i,cev_i,cevi_i,cevif);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setClipEval_InmapFrom(size_t cel_i,size_t cev_i,size_t cevi_i,const ShortID& cevif){fprintf_s(mFile,"connectAttr \"");cevif.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].cev[%i].cevi[%i].cevif\";\n",mName.c_str(),cel_i,cev_i,cevi_i);}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setClipEval_Outmap(size_t cel_i,size_t cev_i,size_t cevo_i,const ClipEvalList::ClipEval::ClipEval_Outmap& cevo){fprintf_s(mFile, "setAttr \".cel[%i].cev[%i].cevo[%i]\" ",cel_i,cev_i,cevo_i);cevo.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setClipEval_Outmap(size_t cel_i,size_t cev_i,size_t cevo_i,const ClipEval_OutmapID& cevo){fprintf_s(mFile,"connectAttr \"");cevo.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].cev[%i].cevo[%i]\";\n",mName.c_str(),cel_i,cev_i,cevo_i);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setClipEval_OutmapTo(size_t cel_i,size_t cev_i,size_t cevo_i,short cevot){if(cevot == 0) return; fprintf_s(mFile, "setAttr \".cel[%i].cev[%i].cevo[%i].cevot\" %i;\n", cel_i,cev_i,cevo_i,cevot);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setClipEval_OutmapTo(size_t cel_i,size_t cev_i,size_t cevo_i,const ShortID& cevot){fprintf_s(mFile,"connectAttr \"");cevot.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].cev[%i].cevo[%i].cevot\";\n",mName.c_str(),cel_i,cev_i,cevo_i);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setClipEval_OutmapFrom(size_t cel_i,size_t cev_i,size_t cevo_i,short cevof){if(cevof == 0) return; fprintf_s(mFile, "setAttr \".cel[%i].cev[%i].cevo[%i].cevof\" %i;\n", cel_i,cev_i,cevo_i,cevof);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setClipEval_OutmapFrom(size_t cel_i,size_t cev_i,size_t cevo_i,const ShortID& cevof){fprintf_s(mFile,"connectAttr \"");cevof.write(mFile);fprintf_s(mFile,"\" \"%s.cel[%i].cev[%i].cevo[%i].cevof\";\n",mName.c_str(),cel_i,cev_i,cevo_i);}
	/*
	The clip function gets connected to a scheduler that manages
	the placement, scale and blending of the clips. The scheduler
	evaluates the clip function to determine the clip.
	*/
	void setClipFunction(const FunctionID& cf){fprintf_s(mFile,"connectAttr \"");cf.write(mFile);fprintf_s(mFile,"\" \"%s.cf\";\n",mName.c_str());}
	/*
	An array of character data for the characters managed by this library.
	The character data allows the clipLibrary to correlate the animCurves
	of each clip to their associated character channel.
	*/
	void setCharacterdata(size_t cd_i,const Characterdata& cd){fprintf_s(mFile, "setAttr \".cd[%i]\" ",cd_i);cd.write(mFile);fprintf_s(mFile,";\n");}
	/*
	An array of character data for the characters managed by this library.
	The character data allows the clipLibrary to correlate the animCurves
	of each clip to their associated character channel.
	*/
	void setCharacterdata(size_t cd_i,const CharacterdataID& cd){fprintf_s(mFile,"connectAttr \"");cd.write(mFile);fprintf_s(mFile,"\" \"%s.cd[%i]\";\n",mName.c_str(),cd_i);}
	/*Stores the mapping of clip data to character attributes*/
	void setCharacterMapping(size_t cd_i,const CharacterMappingID& cm){fprintf_s(mFile,"connectAttr \"");cm.write(mFile);fprintf_s(mFile,"\" \"%s.cd[%i].cm\";\n",mName.c_str(),cd_i);}
	/*Stores a unique index for each channel in the character.*/
	void setClipIndexMapping(size_t cd_i,const intArray& cim){if(cim.size == 0) return; fprintf_s(mFile, "setAttr \".cd[%i].cim\" -type \"intArray\" ",cd_i);cim.write(mFile);fprintf_s(mFile,";\n");}
	/*Stores a unique index for each channel in the character.*/
	void setClipIndexMapping(size_t cd_i,const IntArrayID& cim){fprintf_s(mFile,"connectAttr \"");cim.write(mFile);fprintf_s(mFile,"\" \"%s.cd[%i].cim\";\n",mName.c_str(),cd_i);}
	/*
	The index of the clip which is active. Keyframes set onto a
	character go into the active clip. An active value of -1
	indicates that the "default" clip is active. The default
	clip is not stored in the clip library, but is instead
	hooked directly to the character. The clip command is used
	to name the default clip and move it into the clip library.
	When a default clip is moved into the clip library, the
	active clip remains -1 and new keys go into the new default clip.
	*/
	void setActiveClip(int act){if(act == -1) return; fprintf_s(mFile, "setAttr \".act\" %i;\n", act);}
	/*This attribute is not used.*/
	void setClipName(size_t cn_i,const StringID& cn){fprintf_s(mFile,"connectAttr \"");cn.write(mFile);fprintf_s(mFile,"\" \"%s.cn[%i]\";\n",mName.c_str(),cn_i);}
	/*This attribute is obsolete.*/
	void setStart(size_t st_i,const TimeID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st[%i]\";\n",mName.c_str(),st_i);}
	/*This attribute is obsolete.*/
	void setDuration(size_t du_i,const TimeID& du){fprintf_s(mFile,"connectAttr \"");du.write(mFile);fprintf_s(mFile,"\" \"%s.du[%i]\";\n",mName.c_str(),du_i);}
	/*
	The source clips associated with this library are
	connected to this attribute.
	Array indices for the sourceClip attribute line up
	with those for the clip attribute.
	*/
	void setSourceClip(size_t sc_i,const MessageID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i]\";\n",mName.c_str(),sc_i);}
	/*
	The clip message is connected to any schedulers that use
	the clip. Array indices for the clip attribute line up
	with those for the sourceClip attribute.
	*/
	void setClip(size_t cl_i,const MessageID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i]\";\n",mName.c_str(),cl_i);}
	/*An array of clipEvals, one entry per clip.*/
	const ClipEvalListID& getClipEvalList(size_t cel_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i]",mName.c_str(),cel_i);return (const char*)buffer;}
	/*
	An array of function attributes. The animation curves and expressions
	that drive this clip get connected to the _Raw attribute that is a
	child of this attribute.
	*/
	const ClipEvalID& getClipEval(size_t cel_i,size_t cev_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].cev[%i]",mName.c_str(),cel_i,cev_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	const FunctionID& getClipEval_Raw(size_t cel_i,size_t cev_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].cev[%i].cevr",mName.c_str(),cel_i,cev_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	const ClipEval_InmapID& getClipEval_Inmap(size_t cel_i,size_t cev_i,size_t cevi_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].cev[%i].cevi[%i]",mName.c_str(),cel_i,cev_i,cevi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	const ShortID& getClipEval_InmapTo(size_t cel_i,size_t cev_i,size_t cevi_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].cev[%i].cevi[%i].cevit",mName.c_str(),cel_i,cev_i,cevi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data input parameter index*/
	const ShortID& getClipEval_InmapFrom(size_t cel_i,size_t cev_i,size_t cevi_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].cev[%i].cevi[%i].cevif",mName.c_str(),cel_i,cev_i,cevi_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	const ClipEval_OutmapID& getClipEval_Outmap(size_t cel_i,size_t cev_i,size_t cevo_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].cev[%i].cevo[%i]",mName.c_str(),cel_i,cev_i,cevo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	const ShortID& getClipEval_OutmapTo(size_t cel_i,size_t cev_i,size_t cevo_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].cev[%i].cevo[%i].cevot",mName.c_str(),cel_i,cev_i,cevo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data output parameter index*/
	const ShortID& getClipEval_OutmapFrom(size_t cel_i,size_t cev_i,size_t cevo_i){char buffer[4096];sprintf_s (buffer, "%s.cel[%i].cev[%i].cevo[%i].cevof",mName.c_str(),cel_i,cev_i,cevo_i);return (const char*)buffer;}
	/*
	The clip function gets connected to a scheduler that manages
	the placement, scale and blending of the clips. The scheduler
	evaluates the clip function to determine the clip.
	*/
	FunctionID getClipFunction(){char buffer[4096];sprintf_s (buffer, "%s.cf",mName.c_str());return (const char*)buffer;}
	/*
	An array of character data for the characters managed by this library.
	The character data allows the clipLibrary to correlate the animCurves
	of each clip to their associated character channel.
	*/
	const CharacterdataID& getCharacterdata(size_t cd_i){char buffer[4096];sprintf_s (buffer, "%s.cd[%i]",mName.c_str(),cd_i);return (const char*)buffer;}
	/*Stores the mapping of clip data to character attributes*/
	const CharacterMappingID& getCharacterMapping(size_t cd_i){char buffer[4096];sprintf_s (buffer, "%s.cd[%i].cm",mName.c_str(),cd_i);return (const char*)buffer;}
	/*Stores a unique index for each channel in the character.*/
	const IntArrayID& getClipIndexMapping(size_t cd_i){char buffer[4096];sprintf_s (buffer, "%s.cd[%i].cim",mName.c_str(),cd_i);return (const char*)buffer;}
	/*This attribute is not used.*/
	const StringID& getClipName(size_t cn_i){char buffer[4096];sprintf_s (buffer, "%s.cn[%i]",mName.c_str(),cn_i);return (const char*)buffer;}
	/*This attribute is obsolete.*/
	const TimeID& getStart(size_t st_i){char buffer[4096];sprintf_s (buffer, "%s.st[%i]",mName.c_str(),st_i);return (const char*)buffer;}
	/*This attribute is obsolete.*/
	const TimeID& getDuration(size_t du_i){char buffer[4096];sprintf_s (buffer, "%s.du[%i]",mName.c_str(),du_i);return (const char*)buffer;}
	/*
	The source clips associated with this library are
	connected to this attribute.
	Array indices for the sourceClip attribute line up
	with those for the clip attribute.
	*/
	const MessageID& getSourceClip(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i]",mName.c_str(),sc_i);return (const char*)buffer;}
	/*
	The clip message is connected to any schedulers that use
	the clip. Array indices for the clip attribute line up
	with those for the sourceClip attribute.
	*/
	const MessageID& getClip(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i]",mName.c_str(),cl_i);return (const char*)buffer;}
protected:
	ClipLibrary(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLIPLIBRARY_H__
