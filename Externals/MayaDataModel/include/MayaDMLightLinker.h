/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHTLINKER_H__
#define __MayaDM_LIGHTLINKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node defines light linking relationships between lights and objects.
 Connecting a light to the "light" child of the "link" compound will cause
 it to illuminate the object connected to the "object" child of the same
 index of the "link" compound. For example, if you connect a light to
 link[4].light and an object to link[4].object, then the light will
 illuminate the object.
 Similarly the "ignore" compound can be used to create ignore relationships
 between lights and objects. For example, if you connect a light to
 ignore[6].lightIgnored and an object to ignore[6].objectIgnored, then the
 object will ignore illumination from the light.
 Note that the entity used as a light may be a light shape, or a set
 containing light shapes, or a set containing transforms which are above
 light shapes in a hierarchy. An object may be an object shape (NURBS,
 polygon, particle...), a set containing object shapes, or a set containing
 transforms which are above object shapes in a hierarchy. Shading groups are
 an example of set containing object shapes.
 In all situations, a connection is made using the "message" attribute of
 the light or object.
*/
class LightLinker : public DependNode
{
public:
	/*This attribute is used to make lights illuminate objects.*/
	struct Link{
		void write(FILE* file) const
		{
		}
	};
	/*This attribute is used to make lights not illuminate objects.*/
	struct Ignore{
		void write(FILE* file) const
		{
		}
	};
	/*This attribute is used to make lights shadow objects.*/
	struct ShadowLink{
		void write(FILE* file) const
		{
		}
	};
	/*This attribute is used to prevent lights from shadowing objects.*/
	struct ShadowIgnore{
		void write(FILE* file) const
		{
		}
	};
public:
	LightLinker(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "lightLinker"){}
	virtual ~LightLinker(){}
	/*This attribute is used to make lights illuminate objects.*/
	void setLink(size_t lnk_i,const Link& lnk){fprintf_s(mFile, "setAttr \".lnk[%i]\" ",lnk_i);lnk.write(mFile);fprintf_s(mFile,";\n");}
	/*This attribute is used to make lights illuminate objects.*/
	void setLink(size_t lnk_i,const LinkID& lnk){fprintf_s(mFile,"connectAttr \"");lnk.write(mFile);fprintf_s(mFile,"\" \"%s.lnk[%i]\";\n",mName.c_str(),lnk_i);}
	/*
	A light connected to this node illuminates an object connected to the
	"object" child of the same index of the "link" attribute.
	*/
	void setLight(size_t lnk_i,const MessageID& llnk){fprintf_s(mFile,"connectAttr \"");llnk.write(mFile);fprintf_s(mFile,"\" \"%s.lnk[%i].llnk\";\n",mName.c_str(),lnk_i);}
	/*
	An object connected to this node is illuminated by a light connected to
	the "light" child of the same index of the "link" attribute.
	*/
	void setObject(size_t lnk_i,const MessageID& olnk){fprintf_s(mFile,"connectAttr \"");olnk.write(mFile);fprintf_s(mFile,"\" \"%s.lnk[%i].olnk\";\n",mName.c_str(),lnk_i);}
	/*This attribute is used to make lights not illuminate objects.*/
	void setIgnore(size_t ign_i,const Ignore& ign){fprintf_s(mFile, "setAttr \".ign[%i]\" ",ign_i);ign.write(mFile);fprintf_s(mFile,";\n");}
	/*This attribute is used to make lights not illuminate objects.*/
	void setIgnore(size_t ign_i,const IgnoreID& ign){fprintf_s(mFile,"connectAttr \"");ign.write(mFile);fprintf_s(mFile,"\" \"%s.ign[%i]\";\n",mName.c_str(),ign_i);}
	/*
	A light connected to this node is ignored by an object connected to the
	"object" child of the same index of the "ignore" attribute.
	*/
	void setLightIgnored(size_t ign_i,const MessageID& lign){fprintf_s(mFile,"connectAttr \"");lign.write(mFile);fprintf_s(mFile,"\" \"%s.ign[%i].lign\";\n",mName.c_str(),ign_i);}
	/*
	An object connected to this node ignores a light connected to
	the "light" child of the same index of the "ignore" attribute.
	*/
	void setObjectIgnored(size_t ign_i,const MessageID& oign){fprintf_s(mFile,"connectAttr \"");oign.write(mFile);fprintf_s(mFile,"\" \"%s.ign[%i].oign\";\n",mName.c_str(),ign_i);}
	/*This attribute is used to make lights shadow objects.*/
	void setShadowLink(size_t slnk_i,const ShadowLink& slnk){fprintf_s(mFile, "setAttr \".slnk[%i]\" ",slnk_i);slnk.write(mFile);fprintf_s(mFile,";\n");}
	/*This attribute is used to make lights shadow objects.*/
	void setShadowLink(size_t slnk_i,const ShadowLinkID& slnk){fprintf_s(mFile,"connectAttr \"");slnk.write(mFile);fprintf_s(mFile,"\" \"%s.slnk[%i]\";\n",mName.c_str(),slnk_i);}
	/*
	A light connected to this node shadows an object connected to the
	"shadowObject" child of the same index of the "shadowLink" attribute.
	*/
	void setShadowLight(size_t slnk_i,const MessageID& sllk){fprintf_s(mFile,"connectAttr \"");sllk.write(mFile);fprintf_s(mFile,"\" \"%s.slnk[%i].sllk\";\n",mName.c_str(),slnk_i);}
	/*
	An object connected to this node is shadowed by a light connected to
	the "shadowLight" child of the same index of the "shadowLink" attribute.
	*/
	void setShadowObject(size_t slnk_i,const MessageID& solk){fprintf_s(mFile,"connectAttr \"");solk.write(mFile);fprintf_s(mFile,"\" \"%s.slnk[%i].solk\";\n",mName.c_str(),slnk_i);}
	/*This attribute is used to prevent lights from shadowing objects.*/
	void setShadowIgnore(size_t sign_i,const ShadowIgnore& sign){fprintf_s(mFile, "setAttr \".sign[%i]\" ",sign_i);sign.write(mFile);fprintf_s(mFile,";\n");}
	/*This attribute is used to prevent lights from shadowing objects.*/
	void setShadowIgnore(size_t sign_i,const ShadowIgnoreID& sign){fprintf_s(mFile,"connectAttr \"");sign.write(mFile);fprintf_s(mFile,"\" \"%s.sign[%i]\";\n",mName.c_str(),sign_i);}
	/*
	A light connected to this node ignores an object, connected to the
	"shadowObject" child of the same index of the "shadowIgnore" attribute,
	when calculating shadows.
	*/
	void setShadowLightIgnored(size_t sign_i,const MessageID& slig){fprintf_s(mFile,"connectAttr \"");slig.write(mFile);fprintf_s(mFile,"\" \"%s.sign[%i].slig\";\n",mName.c_str(),sign_i);}
	/*
	An object connected to this node ignores a light, connected to
	the "shadowLight" child of the same index of the "shadowIgnore"
	attribute, when calculating shadows.
	*/
	void setShadowObjectIgnored(size_t sign_i,const MessageID& soig){fprintf_s(mFile,"connectAttr \"");soig.write(mFile);fprintf_s(mFile,"\" \"%s.sign[%i].soig\";\n",mName.c_str(),sign_i);}
	/*This attribute is used to make lights illuminate objects.*/
	const LinkID& getLink(size_t lnk_i){char buffer[4096];sprintf_s (buffer, "%s.lnk[%i]",mName.c_str(),lnk_i);return (const char*)buffer;}
	/*
	A light connected to this node illuminates an object connected to the
	"object" child of the same index of the "link" attribute.
	*/
	const MessageID& getLight(size_t lnk_i){char buffer[4096];sprintf_s (buffer, "%s.lnk[%i].llnk",mName.c_str(),lnk_i);return (const char*)buffer;}
	/*
	An object connected to this node is illuminated by a light connected to
	the "light" child of the same index of the "link" attribute.
	*/
	const MessageID& getObject(size_t lnk_i){char buffer[4096];sprintf_s (buffer, "%s.lnk[%i].olnk",mName.c_str(),lnk_i);return (const char*)buffer;}
	/*This attribute is used to make lights not illuminate objects.*/
	const IgnoreID& getIgnore(size_t ign_i){char buffer[4096];sprintf_s (buffer, "%s.ign[%i]",mName.c_str(),ign_i);return (const char*)buffer;}
	/*
	A light connected to this node is ignored by an object connected to the
	"object" child of the same index of the "ignore" attribute.
	*/
	const MessageID& getLightIgnored(size_t ign_i){char buffer[4096];sprintf_s (buffer, "%s.ign[%i].lign",mName.c_str(),ign_i);return (const char*)buffer;}
	/*
	An object connected to this node ignores a light connected to
	the "light" child of the same index of the "ignore" attribute.
	*/
	const MessageID& getObjectIgnored(size_t ign_i){char buffer[4096];sprintf_s (buffer, "%s.ign[%i].oign",mName.c_str(),ign_i);return (const char*)buffer;}
	/*This attribute is used to make lights shadow objects.*/
	const ShadowLinkID& getShadowLink(size_t slnk_i){char buffer[4096];sprintf_s (buffer, "%s.slnk[%i]",mName.c_str(),slnk_i);return (const char*)buffer;}
	/*
	A light connected to this node shadows an object connected to the
	"shadowObject" child of the same index of the "shadowLink" attribute.
	*/
	const MessageID& getShadowLight(size_t slnk_i){char buffer[4096];sprintf_s (buffer, "%s.slnk[%i].sllk",mName.c_str(),slnk_i);return (const char*)buffer;}
	/*
	An object connected to this node is shadowed by a light connected to
	the "shadowLight" child of the same index of the "shadowLink" attribute.
	*/
	const MessageID& getShadowObject(size_t slnk_i){char buffer[4096];sprintf_s (buffer, "%s.slnk[%i].solk",mName.c_str(),slnk_i);return (const char*)buffer;}
	/*This attribute is used to prevent lights from shadowing objects.*/
	const ShadowIgnoreID& getShadowIgnore(size_t sign_i){char buffer[4096];sprintf_s (buffer, "%s.sign[%i]",mName.c_str(),sign_i);return (const char*)buffer;}
	/*
	A light connected to this node ignores an object, connected to the
	"shadowObject" child of the same index of the "shadowIgnore" attribute,
	when calculating shadows.
	*/
	const MessageID& getShadowLightIgnored(size_t sign_i){char buffer[4096];sprintf_s (buffer, "%s.sign[%i].slig",mName.c_str(),sign_i);return (const char*)buffer;}
	/*
	An object connected to this node ignores a light, connected to
	the "shadowLight" child of the same index of the "shadowIgnore"
	attribute, when calculating shadows.
	*/
	const MessageID& getShadowObjectIgnored(size_t sign_i){char buffer[4096];sprintf_s (buffer, "%s.sign[%i].soig",mName.c_str(),sign_i);return (const char*)buffer;}
protected:
	LightLinker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LIGHTLINKER_H__
