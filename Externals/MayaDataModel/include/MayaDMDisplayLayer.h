/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISPLAYLAYER_H__
#define __MayaDM_DISPLAYLAYER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> Objects can be grouped together and have their display controlled by a
 single displayLayer node.  The attributes of this node are parameters to
 the drawing of objects that are connected to it as members.
</pre></p>
*/
class DisplayLayer : public DependNode
{
public:
	/*Parent attribute encapsulating all draw override information*/
	struct DrawInfo{
		unsigned int displayType;
		unsigned int levelOfDetail;
		bool shading;
		bool texturing;
		bool playback;
		bool enabled;
		bool visibility;
		unsigned char color;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", displayType);
			fprintf_s(file,"%i ", levelOfDetail);
			fprintf_s(file,"%i ", shading);
			fprintf_s(file,"%i ", texturing);
			fprintf_s(file,"%i ", playback);
			fprintf_s(file,"%i ", enabled);
			fprintf_s(file,"%i ", visibility);
			fprintf_s(file,"%i", color);
		}
	};
public:
	DisplayLayer(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "displayLayer"){}
	virtual ~DisplayLayer(){}
	/*Display layer identification number*/
	void setIdentification(short id){if(id == 0) return; fprintf_s(mFile, "setAttr \".id\" %i;\n", id);}
	/*Display layer identification number*/
	void setIdentification(const ShortID& id){fprintf_s(mFile,"connectAttr \"");id.write(mFile);fprintf_s(mFile,"\" \"%s.id\";\n",mName.c_str());}
	/*Parent attribute encapsulating all draw override information*/
	void setDrawInfo(const DrawInfo& di){fprintf_s(mFile, "setAttr \".di\" ");di.write(mFile);fprintf_s(mFile,";\n");}
	/*Parent attribute encapsulating all draw override information*/
	void setDrawInfo(const DrawInfoID& di){fprintf_s(mFile,"connectAttr \"");di.write(mFile);fprintf_s(mFile,"\" \"%s.di\";\n",mName.c_str());}
	/*Methods of drawing*/
	void setDisplayType(unsigned int dt){if(dt == 0) return; fprintf_s(mFile, "setAttr \".di.dt\" %i;\n", dt);}
	/*Methods of drawing*/
	void setDisplayType(const UnsignedintID& dt){fprintf_s(mFile,"connectAttr \"");dt.write(mFile);fprintf_s(mFile,"\" \"%s.di.dt\";\n",mName.c_str());}
	/*Amount of detail to be drawn*/
	void setLevelOfDetail(unsigned int lod){if(lod == 0) return; fprintf_s(mFile, "setAttr \".di.lod\" %i;\n", lod);}
	/*Amount of detail to be drawn*/
	void setLevelOfDetail(const UnsignedintID& lod){fprintf_s(mFile,"connectAttr \"");lod.write(mFile);fprintf_s(mFile,"\" \"%s.di.lod\";\n",mName.c_str());}
	/*Toggle shading state when in shaded display*/
	void setShading(bool s){if(s == true) return; fprintf_s(mFile, "setAttr \".di.s\" %i;\n", s);}
	/*Toggle shading state when in shaded display*/
	void setShading(const BoolID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.di.s\";\n",mName.c_str());}
	/*Toggle texturing state when in shaded display*/
	void setTexturing(bool t){if(t == true) return; fprintf_s(mFile, "setAttr \".di.t\" %i;\n", t);}
	/*Toggle texturing state when in shaded display*/
	void setTexturing(const BoolID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.di.t\";\n",mName.c_str());}
	/*Toggle ability to animate*/
	void setPlayback(bool p){if(p == true) return; fprintf_s(mFile, "setAttr \".di.p\" %i;\n", p);}
	/*Toggle ability to animate*/
	void setPlayback(const BoolID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.di.p\";\n",mName.c_str());}
	/*Turn on/off the effect of the other attributes*/
	void setEnabled(bool e){if(e == true) return; fprintf_s(mFile, "setAttr \".di.e\" %i;\n", e);}
	/*Turn on/off the effect of the other attributes*/
	void setEnabled(const BoolID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.di.e\";\n",mName.c_str());}
	/*Is the layer visible?*/
	void setVisibility(bool v){if(v == true) return; fprintf_s(mFile, "setAttr \".di.v\" %i;\n", v);}
	/*Is the layer visible?*/
	void setVisibility(const BoolID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.di.v\";\n",mName.c_str());}
	/*Color with which to draw*/
	void setColor(unsigned char c){if(c == 0) return; fprintf_s(mFile, "setAttr \".di.c\" %i;\n", c);}
	/*Color with which to draw*/
	void setColor(const UnsignedcharID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.di.c\";\n",mName.c_str());}
	/*Display order number*/
	void setDisplayOrder(short do_){if(do_ == 0) return; fprintf_s(mFile, "setAttr \".do\" %i;\n", do_);}
	/*Display order number*/
	void setDisplayOrder(const ShortID& do_){fprintf_s(mFile,"connectAttr \"");do_.write(mFile);fprintf_s(mFile,"\" \"%s.do\";\n",mName.c_str());}
	/*Display layer identification number*/
	ShortID getIdentification(){char buffer[4096];sprintf_s (buffer, "%s.id",mName.c_str());return (const char*)buffer;}
	/*Parent attribute encapsulating all draw override information*/
	DrawInfoID getDrawInfo(){char buffer[4096];sprintf_s (buffer, "%s.di",mName.c_str());return (const char*)buffer;}
	/*Methods of drawing*/
	UnsignedintID getDisplayType(){char buffer[4096];sprintf_s (buffer, "%s.di.dt",mName.c_str());return (const char*)buffer;}
	/*Amount of detail to be drawn*/
	UnsignedintID getLevelOfDetail(){char buffer[4096];sprintf_s (buffer, "%s.di.lod",mName.c_str());return (const char*)buffer;}
	/*Toggle shading state when in shaded display*/
	BoolID getShading(){char buffer[4096];sprintf_s (buffer, "%s.di.s",mName.c_str());return (const char*)buffer;}
	/*Toggle texturing state when in shaded display*/
	BoolID getTexturing(){char buffer[4096];sprintf_s (buffer, "%s.di.t",mName.c_str());return (const char*)buffer;}
	/*Toggle ability to animate*/
	BoolID getPlayback(){char buffer[4096];sprintf_s (buffer, "%s.di.p",mName.c_str());return (const char*)buffer;}
	/*Turn on/off the effect of the other attributes*/
	BoolID getEnabled(){char buffer[4096];sprintf_s (buffer, "%s.di.e",mName.c_str());return (const char*)buffer;}
	/*Is the layer visible?*/
	BoolID getVisibility(){char buffer[4096];sprintf_s (buffer, "%s.di.v",mName.c_str());return (const char*)buffer;}
	/*Color with which to draw*/
	UnsignedcharID getColor(){char buffer[4096];sprintf_s (buffer, "%s.di.c",mName.c_str());return (const char*)buffer;}
	/*Display order number*/
	ShortID getDisplayOrder(){char buffer[4096];sprintf_s (buffer, "%s.do",mName.c_str());return (const char*)buffer;}
protected:
	DisplayLayer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DISPLAYLAYER_H__
