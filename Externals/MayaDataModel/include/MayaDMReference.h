/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REFERENCE_H__
#define __MayaDM_REFERENCE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
    When a reference is unloaded, a reference node keeps track of the changes
    made to objects in the reference file. When the reference is reloaded,
    the changes stored in the reference node are retored to the reference.

    Reference nodes store connections between attributes in a scene and
    attributes in the reference; connections between attributes contained
    in the reference, but that are not part of the reference file; dynamic
    attributes on node in the reference file, but where the attributes
    were not defined in the reference file; setAttrs made after the file
    was referenced; and internal broken reference connections.

    There are four lists of changes that are saved: Connections, setAttrs,
    addAttrs, and broken connections.

    The connections list is a compound
    multi, with one child being a generic attributes which can be connected
    and the other being the name of the attribute in the reference file that
    used to be connected.

    The setAttr list is a multi with a command which sets an attribute to
    its state before the reference was unloaded.

    The addAttr list is a multi of strings, where each string is a command
    to add an attribute to a referenced node.

    The brokenConnection list is a multi of strings, when each string is a
    command to break a referenced connection.

</pre></p>
*/
class Reference : public DependNode
{
public:
	/*
	This multi compound stores a connection and a string with the name
	of the attribute that used to be on this end of the connection.
	*/
	struct ConnectionList{
		void write(FILE* file) const
		{
		}
	};
	/*
	A generic attribute used to keep a connection between multi parents
	when the reference is unloaded. This is a multi compound containing
	a multi (aMultiParent) as its compound child. aMultiParent is actually
	used to stored the connection.
	*/
	struct MultiParentList{
		void write(FILE* file) const
		{
		}
	};
public:
	Reference(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "reference"){}
	virtual ~Reference(){}
	/*
	This attribute is a list of files used by the reference. The purpose
	is to maintain a list to quickly swap maya files without needing
	a file browser.
	*/
	void setFileNames(size_t fn_i,const string& fn){if(fn == "NULL") return; fprintf_s(mFile, "setAttr \".fn[%i]\" -type \"string\" ",fn_i);fn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute is a list of files used by the reference. The purpose
	is to maintain a list to quickly swap maya files without needing
	a file browser.
	*/
	void setFileNames(size_t fn_i,const StringID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn[%i]\";\n",mName.c_str(),fn_i);}
	/*
	This multi compound stores a connection and a string with the name
	of the attribute that used to be on this end of the connection.
	*/
	void setConnectionList(size_t cl_i,const ConnectionListID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i]\";\n",mName.c_str(),cl_i);}
	/*
	The name of the attribute that used to be connected before the
	reference was unloaded.
	*/
	void setConnectionAttr(size_t cl_i,const StringID& ca){fprintf_s(mFile,"connectAttr \"");ca.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].ca\";\n",mName.c_str(),cl_i);}
	/*
	A generic attribute used to keep a connection when the reference is
	unloaded.
	*/
	void setConnection(size_t cl_i,const GenericID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].c\";\n",mName.c_str(),cl_i);}
	/*A list of setAttr commands.*/
	void setSetAttrList(size_t sl_i,const StringID& sl){fprintf_s(mFile,"connectAttr \"");sl.write(mFile);fprintf_s(mFile,"\" \"%s.sl[%i]\";\n",mName.c_str(),sl_i);}
	/*A list of addAttr commands.*/
	void setAddAttrList(size_t al_i,const StringID& al){fprintf_s(mFile,"connectAttr \"");al.write(mFile);fprintf_s(mFile,"\" \"%s.al[%i]\";\n",mName.c_str(),al_i);}
	/*A list of deleteAttr commands.*/
	void setDeleteAttrList(size_t dl_i,const StringID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl[%i]\";\n",mName.c_str(),dl_i);}
	/*
	A multi containing strings which are executed to break internal
	connections in a reference file.
	*/
	void setBrokenConnectionList(size_t bl_i,const StringID& bl){fprintf_s(mFile,"connectAttr \"");bl.write(mFile);fprintf_s(mFile,"\" \"%s.bl[%i]\";\n",mName.c_str(),bl_i);}
	/*A list of parent commands.*/
	void setParentList(size_t pl_i,const StringID& pl){fprintf_s(mFile,"connectAttr \"");pl.write(mFile);fprintf_s(mFile,"\" \"%s.pl[%i]\";\n",mName.c_str(),pl_i);}
	/*
	A generic attribute used to keep a connection when the reference is
	unloaded.
	*/
	void setPlaceHolderList(size_t phl_i,const GenericID& phl){fprintf_s(mFile,"connectAttr \"");phl.write(mFile);fprintf_s(mFile,"\" \"%s.phl[%i]\";\n",mName.c_str(),phl_i);}
	/*
	A generic attribute used to keep a connection between multi parents
	when the reference is unloaded. This is a multi compound containing
	a multi (aMultiParent) as its compound child. aMultiParent is actually
	used to stored the connection.
	*/
	void setMultiParentList(size_t mpl_i,const MultiParentList& mpl){fprintf_s(mFile, "setAttr \".mpl[%i]\" ",mpl_i);mpl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	A generic attribute used to keep a connection between multi parents
	when the reference is unloaded. This is a multi compound containing
	a multi (aMultiParent) as its compound child. aMultiParent is actually
	used to stored the connection.
	*/
	void setMultiParentList(size_t mpl_i,const MultiParentListID& mpl){fprintf_s(mFile,"connectAttr \"");mpl.write(mFile);fprintf_s(mFile,"\" \"%s.mpl[%i]\";\n",mName.c_str(),mpl_i);}
	/*
	A generic multi attribute used to keep a connection between multi
	parents when the reference is unloaded.
	*/
	void setMultiParent(size_t mpl_i,size_t mp_i,const GenericID& mp){fprintf_s(mFile,"connectAttr \"");mp.write(mFile);fprintf_s(mFile,"\" \"%s.mpl[%i].mp[%i]\";\n",mName.c_str(),mpl_i,mp_i);}
	/*
	This attribute stores information about the modifications ("edits")
	that have been made to nodes in thereference. This attribute
	should not be accessed directly - please use the
	"List Reference Edits..." window, referenceEdit command, and
	referenceQuery command instead.
	*/
	void setEdits(const ReferenceEditsID& ed){fprintf_s(mFile,"connectAttr \"");ed.write(mFile);fprintf_s(mFile,"\" \"%s.ed\";\n",mName.c_str());}
	/*This string is the proxy tag associated with this reference.*/
	void setProxyTag(const string& ptag){if(ptag == "NULL") return; fprintf_s(mFile, "setAttr \".ptag\" -type \"string\" ");ptag.write(mFile);fprintf_s(mFile,";\n");}
	/*This string is the proxy tag associated with this reference.*/
	void setProxyTag(const StringID& ptag){fprintf_s(mFile,"connectAttr \"");ptag.write(mFile);fprintf_s(mFile,"\" \"%s.ptag\";\n",mName.c_str());}
	/*
	This message attribute allows a connection from the proxy manager
	to the reference node when the reference node is being used as a
	proxy.
	*/
	void setProxyMsg(const MessageID& pmsg){fprintf_s(mFile,"connectAttr \"");pmsg.write(mFile);fprintf_s(mFile,"\" \"%s.pmsg\";\n",mName.c_str());}
	/*
	This message attribute is used to connect a particular scenefile's
	unknown reference node to all the other reference nodes in that
	scenefile.
	*/
	void setUnknownReference(const MessageID& ur){fprintf_s(mFile,"connectAttr \"");ur.write(mFile);fprintf_s(mFile,"\" \"%s.ur\";\n",mName.c_str());}
	/*
	This message attribute is used to connect a particular scenefile's
	shared reference node to all reference nodes in that
	scenefile which contain shared nodes.
	*/
	void setSharedReference(const MessageID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	This attribute is set when bringing in a reference file and is
	not editable after that.
	*/
	void setLocked(bool lk){if(lk == false) return; fprintf_s(mFile, "setAttr \".lk\" %i;\n", lk);}
	/*
	This attribute is set when bringing in a reference file and is
	not editable after that.
	*/
	void setLocked(const BoolID& lk){fprintf_s(mFile,"connectAttr \"");lk.write(mFile);fprintf_s(mFile,"\" \"%s.lk\";\n",mName.c_str());}
	/*
	This attribute is a list of files used by the reference. The purpose
	is to maintain a list to quickly swap maya files without needing
	a file browser.
	*/
	const StringID& getFileNames(size_t fn_i){char buffer[4096];sprintf_s (buffer, "%s.fn[%i]",mName.c_str(),fn_i);return (const char*)buffer;}
	/*
	This multi compound stores a connection and a string with the name
	of the attribute that used to be on this end of the connection.
	*/
	const ConnectionListID& getConnectionList(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i]",mName.c_str(),cl_i);return (const char*)buffer;}
	/*
	The name of the attribute that used to be connected before the
	reference was unloaded.
	*/
	const StringID& getConnectionAttr(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].ca",mName.c_str(),cl_i);return (const char*)buffer;}
	/*
	A generic attribute used to keep a connection when the reference is
	unloaded.
	*/
	const GenericID& getConnection(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].c",mName.c_str(),cl_i);return (const char*)buffer;}
	/*A list of setAttr commands.*/
	const StringID& getSetAttrList(size_t sl_i){char buffer[4096];sprintf_s (buffer, "%s.sl[%i]",mName.c_str(),sl_i);return (const char*)buffer;}
	/*A list of addAttr commands.*/
	const StringID& getAddAttrList(size_t al_i){char buffer[4096];sprintf_s (buffer, "%s.al[%i]",mName.c_str(),al_i);return (const char*)buffer;}
	/*A list of deleteAttr commands.*/
	const StringID& getDeleteAttrList(size_t dl_i){char buffer[4096];sprintf_s (buffer, "%s.dl[%i]",mName.c_str(),dl_i);return (const char*)buffer;}
	/*
	A multi containing strings which are executed to break internal
	connections in a reference file.
	*/
	const StringID& getBrokenConnectionList(size_t bl_i){char buffer[4096];sprintf_s (buffer, "%s.bl[%i]",mName.c_str(),bl_i);return (const char*)buffer;}
	/*A list of parent commands.*/
	const StringID& getParentList(size_t pl_i){char buffer[4096];sprintf_s (buffer, "%s.pl[%i]",mName.c_str(),pl_i);return (const char*)buffer;}
	/*
	A generic attribute used to keep a connection when the reference is
	unloaded.
	*/
	const GenericID& getPlaceHolderList(size_t phl_i){char buffer[4096];sprintf_s (buffer, "%s.phl[%i]",mName.c_str(),phl_i);return (const char*)buffer;}
	/*
	A generic attribute used to keep a connection between multi parents
	when the reference is unloaded. This is a multi compound containing
	a multi (aMultiParent) as its compound child. aMultiParent is actually
	used to stored the connection.
	*/
	const MultiParentListID& getMultiParentList(size_t mpl_i){char buffer[4096];sprintf_s (buffer, "%s.mpl[%i]",mName.c_str(),mpl_i);return (const char*)buffer;}
	/*
	A generic multi attribute used to keep a connection between multi
	parents when the reference is unloaded.
	*/
	const GenericID& getMultiParent(size_t mpl_i,size_t mp_i){char buffer[4096];sprintf_s (buffer, "%s.mpl[%i].mp[%i]",mName.c_str(),mpl_i,mp_i);return (const char*)buffer;}
	/*
	This attribute stores information about the modifications ("edits")
	that have been made to nodes in thereference. This attribute
	should not be accessed directly - please use the
	"List Reference Edits..." window, referenceEdit command, and
	referenceQuery command instead.
	*/
	ReferenceEditsID getEdits(){char buffer[4096];sprintf_s (buffer, "%s.ed",mName.c_str());return (const char*)buffer;}
	/*This string is the proxy tag associated with this reference.*/
	StringID getProxyTag(){char buffer[4096];sprintf_s (buffer, "%s.ptag",mName.c_str());return (const char*)buffer;}
	/*
	This message attribute allows a connection from the proxy manager
	to the reference node when the reference node is being used as a
	proxy.
	*/
	MessageID getProxyMsg(){char buffer[4096];sprintf_s (buffer, "%s.pmsg",mName.c_str());return (const char*)buffer;}
	/*
	This message attribute is used to connect a particular scenefile's
	unknown reference node to all the other reference nodes in that
	scenefile.
	*/
	MessageID getUnknownReference(){char buffer[4096];sprintf_s (buffer, "%s.ur",mName.c_str());return (const char*)buffer;}
	/*
	This message attribute is used to connect a particular scenefile's
	shared reference node to all reference nodes in that
	scenefile which contain shared nodes.
	*/
	MessageID getSharedReference(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is set when bringing in a reference file and is
	not editable after that.
	*/
	BoolID getLocked(){char buffer[4096];sprintf_s (buffer, "%s.lk",mName.c_str());return (const char*)buffer;}
protected:
	Reference(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REFERENCE_H__
