/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
The character node is a special type of set. It is used to gather together
  animatable attributes. These attributes can then be animated in unison
  when the character is current. Character sets are also used to define a
  set of attributes that a user wishes to animate using nonlinear animation clips.
  <p/>
  Character sets may only contain animatable attributes and other
  characters (called "subcharacters").  Using subcharacters, it is
  possible to build hierarchical characters.
  <p/>
  The character node manages all animation data for the attributes it
  contains.  When a key is set on a character, the animation curves
  are connected to the character node.  The
  character node passes this animation data through to the character's
  attributes via connections.
  <p/>
  When animation clips are created, the character is connected to a
  <em>clipScheduler</em> node and a <em>clipLibrary</em> node that manage
  and evaluate the clip data. The clipScheduler node is attached
  to the character via the clipEvaluate function attribute.
  <p/>
  When a clip is created on a character, all of the animation curves
  connected to the character are considered part of the new clip. The animation curves
  are disconnected from the character and connected to the character's associated
  clipLibrary node. The clipLibrary acts as a repository where all of the available
  source clips are held. To move a clip's animation curves back onto the character,
  the clip can be "activated".
  <p/>
*/
class Character : public ObjectSet
{
public:
	/*
	The clip function gets connected to the clip manager who controls it.
	The character calls the clip function to evaluate the clip.
	If there is no clip manager, the character plays the default clip.
	*/
	struct ClipEvaluate{
		/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
		struct ClipEvaluate_Inmap{
			short clipEvaluate_InmapTo;
			short clipEvaluate_InmapFrom;
			void write(FILE* file) const
			{
				fprintf_s(file,"%i ", clipEvaluate_InmapTo);
				fprintf_s(file,"%i", clipEvaluate_InmapFrom);
			}
		}* clipEvaluate_Inmap;
		/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
		struct ClipEvaluate_Outmap{
			short clipEvaluate_OutmapTo;
			short clipEvaluate_OutmapFrom;
			void write(FILE* file) const
			{
				fprintf_s(file,"%i ", clipEvaluate_OutmapTo);
				fprintf_s(file,"%i", clipEvaluate_OutmapFrom);
			}
		}* clipEvaluate_Outmap;
		void write(FILE* file) const
		{
			size_t size = sizeof(clipEvaluate_Inmap)/sizeof(ClipEvaluate_Inmap);
			for(size_t i=0; i<size; ++i)
			{
				clipEvaluate_Inmap[i].write(file);
				fprintf_s(file, " ");
				if(i+1<size) fprintf_s(file," ");
			}
			size = sizeof(clipEvaluate_Outmap)/sizeof(ClipEvaluate_Outmap);
			for(size_t i=0; i<size; ++i)
			{
				clipEvaluate_Outmap[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	Character(FILE* file,const std::string& name,const std::string& parent=""):ObjectSet(file, name, parent, "character"){}
	virtual ~Character(){}
	/*
	The clip function gets connected to the clip manager who controls it.
	The character calls the clip function to evaluate the clip.
	If there is no clip manager, the character plays the default clip.
	*/
	void setClipEvaluate(const ClipEvaluate& ce){fprintf_s(mFile, "setAttr \".ce\" ");ce.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The clip function gets connected to the clip manager who controls it.
	The character calls the clip function to evaluate the clip.
	If there is no clip manager, the character plays the default clip.
	*/
	void setClipEvaluate(const ClipEvaluateID& ce){fprintf_s(mFile,"connectAttr \"");ce.write(mFile);fprintf_s(mFile,"\" \"%s.ce\";\n",mName.c_str());}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	void setClipEvaluate_Raw(const FunctionID& cer){fprintf_s(mFile,"connectAttr \"");cer.write(mFile);fprintf_s(mFile,"\" \"%s.ce.cer\";\n",mName.c_str());}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setClipEvaluate_Inmap(size_t cei_i,const ClipEvaluate::ClipEvaluate_Inmap& cei){fprintf_s(mFile, "setAttr \".ce.cei[%i]\" ",cei_i);cei.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	void setClipEvaluate_Inmap(size_t cei_i,const ClipEvaluate_InmapID& cei){fprintf_s(mFile,"connectAttr \"");cei.write(mFile);fprintf_s(mFile,"\" \"%s.ce.cei[%i]\";\n",mName.c_str(),cei_i);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setClipEvaluate_InmapTo(size_t cei_i,short ceit){if(ceit == 0) return; fprintf_s(mFile, "setAttr \".ce.cei[%i].ceit\" %i;\n", cei_i,ceit);}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	void setClipEvaluate_InmapTo(size_t cei_i,const ShortID& ceit){fprintf_s(mFile,"connectAttr \"");ceit.write(mFile);fprintf_s(mFile,"\" \"%s.ce.cei[%i].ceit\";\n",mName.c_str(),cei_i);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setClipEvaluate_InmapFrom(size_t cei_i,short ceif){if(ceif == 0) return; fprintf_s(mFile, "setAttr \".ce.cei[%i].ceif\" %i;\n", cei_i,ceif);}
	/*For Internal Use Only<br/>Function data input parameter index*/
	void setClipEvaluate_InmapFrom(size_t cei_i,const ShortID& ceif){fprintf_s(mFile,"connectAttr \"");ceif.write(mFile);fprintf_s(mFile,"\" \"%s.ce.cei[%i].ceif\";\n",mName.c_str(),cei_i);}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setClipEvaluate_Outmap(size_t ceo_i,const ClipEvaluate::ClipEvaluate_Outmap& ceo){fprintf_s(mFile, "setAttr \".ce.ceo[%i]\" ",ceo_i);ceo.write(mFile);fprintf_s(mFile,";\n");}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	void setClipEvaluate_Outmap(size_t ceo_i,const ClipEvaluate_OutmapID& ceo){fprintf_s(mFile,"connectAttr \"");ceo.write(mFile);fprintf_s(mFile,"\" \"%s.ce.ceo[%i]\";\n",mName.c_str(),ceo_i);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setClipEvaluate_OutmapTo(size_t ceo_i,short ceot){if(ceot == 0) return; fprintf_s(mFile, "setAttr \".ce.ceo[%i].ceot\" %i;\n", ceo_i,ceot);}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	void setClipEvaluate_OutmapTo(size_t ceo_i,const ShortID& ceot){fprintf_s(mFile,"connectAttr \"");ceot.write(mFile);fprintf_s(mFile,"\" \"%s.ce.ceo[%i].ceot\";\n",mName.c_str(),ceo_i);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setClipEvaluate_OutmapFrom(size_t ceo_i,short ceof){if(ceof == 0) return; fprintf_s(mFile, "setAttr \".ce.ceo[%i].ceof\" %i;\n", ceo_i,ceof);}
	/*For Internal Use Only<br/>Function data output parameter index*/
	void setClipEvaluate_OutmapFrom(size_t ceo_i,const ShortID& ceof){fprintf_s(mFile,"connectAttr \"");ceof.write(mFile);fprintf_s(mFile,"\" \"%s.ce.ceo[%i].ceof\";\n",mName.c_str(),ceo_i);}
	/*stores the character's animation data that is of type double*/
	void setUnitlessValues(size_t uv_i,double uv){if(uv == 0.0) return; fprintf_s(mFile, "setAttr \".uv[%i]\" %f;\n", uv_i,uv);}
	/*stores the character's animation data that is of type double*/
	void setUnitlessValues(size_t uv_i,const DoubleID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv[%i]\";\n",mName.c_str(),uv_i);}
	/*stores the character's animation data that is of type linear*/
	void setLinearValues(size_t lv_i,double lv){if(lv == 0) return; fprintf_s(mFile, "setAttr \".lv[%i]\" %f;\n", lv_i,lv);}
	/*stores the character's animation data that is of type linear*/
	void setLinearValues(size_t lv_i,const DoubleID& lv){fprintf_s(mFile,"connectAttr \"");lv.write(mFile);fprintf_s(mFile,"\" \"%s.lv[%i]\";\n",mName.c_str(),lv_i);}
	/*stores the character's animation data that is of type angle*/
	void setAngularValues(size_t av_i,double av){if(av == 0) return; fprintf_s(mFile, "setAttr \".av[%i]\" %f;\n", av_i,av);}
	/*stores the character's animation data that is of type angle*/
	void setAngularValues(size_t av_i,const DoubleID& av){fprintf_s(mFile,"connectAttr \"");av.write(mFile);fprintf_s(mFile,"\" \"%s.av[%i]\";\n",mName.c_str(),av_i);}
	/*stores the character's animation data that is of type time*/
	void setTimeValues(size_t tv_i,const TimeID& tv){fprintf_s(mFile,"connectAttr \"");tv.write(mFile);fprintf_s(mFile,"\" \"%s.tv[%i]\";\n",mName.c_str(),tv_i);}
	/*stores the mapping of set members to their animation data*/
	void setAnimationMapping(const CharacterMappingID& am){fprintf_s(mFile,"connectAttr \"");am.write(mFile);fprintf_s(mFile,"\" \"%s.am\";\n",mName.c_str());}
	/*
	Stores the mapping of set members to their animation data when the character
	was referenced.  This is used so that if the character contents change later,
	the animation can be connected to the proper location.
	*/
	void setReferenceMapping(const CharacterMappingID& rm){fprintf_s(mFile,"connectAttr \"");rm.write(mFile);fprintf_s(mFile,"\" \"%s.rm\";\n",mName.c_str());}
	/*
	Stores a map between the internal character member index and the
	index used by the clip scheduler.
	This attribute is only used when the character is clip-driven.
	*/
	void setClipIndexMap(const intArray& cim){if(cim.size == 0) return; fprintf_s(mFile, "setAttr \".cim\" -type \"intArray\" ");cim.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When this attribute is on, the character is driven only by the clips.
	Any keyframes connected to the character, are assumed to be from the
	active clip.
	*/
	void setActiveClipConnected(bool acc){if(acc == 0) return; fprintf_s(mFile, "setAttr \".acc\" %i;\n", acc);}
	/*A connection to the characterOffset node (if there is one).*/
	void setOffsetNode(const MessageID& ofn){fprintf_s(mFile,"connectAttr \"");ofn.write(mFile);fprintf_s(mFile,"\" \"%s.ofn\";\n",mName.c_str());}
	/*
	The clip function gets connected to the clip manager who controls it.
	The character calls the clip function to evaluate the clip.
	If there is no clip manager, the character plays the default clip.
	*/
	ClipEvaluateID getClipEvaluate(){char buffer[4096];sprintf_s (buffer, "%s.ce",mName.c_str());return (const char*)buffer;}
	/*For Internal Use Only<br/>Actual function being applied at this attribute*/
	FunctionID getClipEvaluate_Raw(){char buffer[4096];sprintf_s (buffer, "%s.ce.cer",mName.c_str());return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function input parameters to function data input parameters*/
	const ClipEvaluate_InmapID& getClipEvaluate_Inmap(size_t cei_i){char buffer[4096];sprintf_s (buffer, "%s.ce.cei[%i]",mName.c_str(),cei_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function input parameter index*/
	const ShortID& getClipEvaluate_InmapTo(size_t cei_i){char buffer[4096];sprintf_s (buffer, "%s.ce.cei[%i].ceit",mName.c_str(),cei_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data input parameter index*/
	const ShortID& getClipEvaluate_InmapFrom(size_t cei_i){char buffer[4096];sprintf_s (buffer, "%s.ce.cei[%i].ceif",mName.c_str(),cei_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Mapping of node's function output parameters to function data output parameters*/
	const ClipEvaluate_OutmapID& getClipEvaluate_Outmap(size_t ceo_i){char buffer[4096];sprintf_s (buffer, "%s.ce.ceo[%i]",mName.c_str(),ceo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Node's internal function output parameter index*/
	const ShortID& getClipEvaluate_OutmapTo(size_t ceo_i){char buffer[4096];sprintf_s (buffer, "%s.ce.ceo[%i].ceot",mName.c_str(),ceo_i);return (const char*)buffer;}
	/*For Internal Use Only<br/>Function data output parameter index*/
	const ShortID& getClipEvaluate_OutmapFrom(size_t ceo_i){char buffer[4096];sprintf_s (buffer, "%s.ce.ceo[%i].ceof",mName.c_str(),ceo_i);return (const char*)buffer;}
	/*stores the character's animation data that is of type double*/
	const DoubleID& getUnitlessValues(size_t uv_i){char buffer[4096];sprintf_s (buffer, "%s.uv[%i]",mName.c_str(),uv_i);return (const char*)buffer;}
	/*stores the character's animation data that is of type linear*/
	const DoubleID& getLinearValues(size_t lv_i){char buffer[4096];sprintf_s (buffer, "%s.lv[%i]",mName.c_str(),lv_i);return (const char*)buffer;}
	/*stores the character's animation data that is of type angle*/
	const DoubleID& getAngularValues(size_t av_i){char buffer[4096];sprintf_s (buffer, "%s.av[%i]",mName.c_str(),av_i);return (const char*)buffer;}
	/*stores the character's animation data that is of type time*/
	const TimeID& getTimeValues(size_t tv_i){char buffer[4096];sprintf_s (buffer, "%s.tv[%i]",mName.c_str(),tv_i);return (const char*)buffer;}
	/*stores the mapping of set members to their animation data*/
	CharacterMappingID getAnimationMapping(){char buffer[4096];sprintf_s (buffer, "%s.am",mName.c_str());return (const char*)buffer;}
	/*
	Stores the mapping of set members to their animation data when the character
	was referenced.  This is used so that if the character contents change later,
	the animation can be connected to the proper location.
	*/
	CharacterMappingID getReferenceMapping(){char buffer[4096];sprintf_s (buffer, "%s.rm",mName.c_str());return (const char*)buffer;}
	/*A connection to the characterOffset node (if there is one).*/
	MessageID getOffsetNode(){char buffer[4096];sprintf_s (buffer, "%s.ofn",mName.c_str());return (const char*)buffer;}
protected:
	Character(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectSet(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CHARACTER_H__
