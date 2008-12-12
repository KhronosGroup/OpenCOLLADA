/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTSET_H__
#define __MayaDM_OBJECTSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMEntity.h"
namespace MayaDM
{
/*
This node defines a logical collection of objects, object components,
        and node attributes.  ObjectSets (sets) are very useful and are used
        heavily in the application.  Sets are used to define which parts of an
        object to deform. Sets are used to define which objects should be have
        the same shading properties and are called shading groups or renderable
        sets.  Anything that can be selected using the 'select' command can be
        added to an objectSet. An objectSet is created and edited using the "sets"
        command. <p/>

        ObjectSets may be connected to a partition. Partitions define a
        collection of mutually exclusive sets.  If a set is connected to a
        partition, a member of the set cannot also be a member of another set
        which is also connected to that same partition. Mutual exclusivity is
        maintained by the "sets" and "partition" commands. The shading groups
        mentioned above are connected to the renderPartition. <p/>

        Membership in a set is defined by establishing connections between
        another node's attribute and one of two attributes of the objectSet.
        Connections to an objectSet's "dagSetMembers" attribute should be made
        if the object is a dagNode and the attribute is the "instObjGroups"
        or "objectGroups" attribute. Connecting to the "instObjGroups"
        attribute means the whole object is in the set.  Connecting to the
        "objectGroups" attribute means that a part (component) of
        the object is in the set.  Otherwise, connections to any other
        attribute of any node should be made to the objectSet's "dnSetMembers"
        attribute.  Connections to this attribute simply mean that the
        attribute is a member of the set. <p/>

        An objectSet can have associated with it an index (0-7) to one of the
        user defined display colors.  If the memberWireframeColor attribute has
        a value of 0-7, any components of objects (such as surface CVs) which
        are a member of the set will be displayed in the user defined color
        identified by that index.  If the value is -1, the components will be
        drawn in their normal color.  This is useful for visually identifying
        which parts of an object are in which set. <p/>

        An objectSet can also have an annotation which is a text string
        associated with the set and can be used to describe the purpose or
        contents of the set. <p/>

        Sets are special when it comes to selection.  The MEL command "select
        set1;" causes the members of set1 to be put on the active list instead
        of set1 itself.  To put set1 on the active list, you need to use
        "select -noExpand set1;". <p/>
*/
class ObjectSet : public Entity
{
public:
public:
	ObjectSet(FILE* file,const std::string& name,const std::string& parent=""):Entity(file, name, parent, "objectSet"){}
	virtual ~ObjectSet(){}
	/*
	The index of a user defined color in which the DAG object component
	members should appear. A value of -1 disables use of the color.
	Values outside the range [-1,7] may give unpredictable results.
	*/
	void setMemberWireframeColor(short mwc){if(mwc == -1) return; fprintf_s(mFile, "setAttr \".mwc\" %i;\n", mwc);}
	/*
	The index of a user defined color in which the DAG object component
	members should appear. A value of -1 disables use of the color.
	Values outside the range [-1,7] may give unpredictable results.
	*/
	void setMemberWireframeColor(const ShortID& mwc){fprintf_s(mFile,"connectAttr \"");mwc.write(mFile);fprintf_s(mFile,"\" \"%s.mwc\";\n",mName.c_str());}
	/*
	A text string to annotate the set.<br/>
	The Maya UI uses the annotation attribute to locate various sets
	which are used to hold onto "interesting" objects.  Below is a
	list of current annotations.
	<ul>
	<b>gCharacterSet</b>: Used by the main window's Quick Select Set<br/>
	<b>bookmarkAnimCurves</b>: Used by the Graph Editor and Dope Sheet bookmarks<br/>
	<b>clipSelectSet</b>: Used by Trax's Quick Select Set<br/>
	<b>clipSummarySet</b>: Used by Trax to group clips<br/>
	<b>bookmarkClips</b>: Used by Trax bookmarks<br/>
	<b>bookmarkModelView</b>: Used by the Model View's isolate select bookmarks<br/>
	</ul>
	*/
	void setAnnotation(const string& an){if(an == "NULL") return; fprintf_s(mFile, "setAttr \".an\" -type \"string\" ");an.write(mFile);fprintf_s(mFile,";\n");}
	/*This attribute is obsolete and should no longer be used*/
	void setIsLayer(bool il){if(il == false) return; fprintf_s(mFile, "setAttr \".il\" %i;\n", il);}
	/*
	Is set membership restricted to objects with vertices?
	This attribute should not be explicitly changed by the user.
	*/
	void setVerticesOnlySet(bool vo){if(vo == false) return; fprintf_s(mFile, "setAttr \".vo\" %i;\n", vo);}
	/*
	Is set membership restricted to objects with edges?
	This attribute should not be explicitly changed by the user.
	*/
	void setEdgesOnlySet(bool eo){if(eo == false) return; fprintf_s(mFile, "setAttr \".eo\" %i;\n", eo);}
	/*
	Is set membership restricted to objects with faces?
	This attribute should not be explicitly changed by the user.
	*/
	void setFacetsOnlySet(bool fo){if(fo == false) return; fprintf_s(mFile, "setAttr \".fo\" %i;\n", fo);}
	/*
	Is set membership restricted to objects with edit points?
	This attribute should not be explicitly changed by the user.
	*/
	void setEditPointsOnlySet(bool epo){if(epo == false) return; fprintf_s(mFile, "setAttr \".epo\" %i;\n", epo);}
	/*
	Is set membership restricted to renderable objects only?
	This attribute should not be explicitly changed by the user.
	*/
	void setRenderableOnlySet(bool ro){if(ro == false) return; fprintf_s(mFile, "setAttr \".ro\" %i;\n", ro);}
	/*References to the partition nodes this set is a member of.*/
	void setPartition(const MessageID& pa){fprintf_s(mFile,"connectAttr \"");pa.write(mFile);fprintf_s(mFile,"\" \"%s.pa\";\n",mName.c_str());}
	/*References to nodes that operate upon this set, such as deformers.*/
	void setUsedBy(size_t ub_i,const MessageID& ub){fprintf_s(mFile,"connectAttr \"");ub.write(mFile);fprintf_s(mFile,"\" \"%s.ub[%i]\";\n",mName.c_str(),ub_i);}
	/*
	The index of a user defined color in which the DAG object component
	members should appear. A value of -1 disables use of the color.
	Values outside the range [-1,7] may give unpredictable results.
	*/
	ShortID getMemberWireframeColor(){char buffer[4096];sprintf_s (buffer, "%s.mwc",mName.c_str());return (const char*)buffer;}
	/*References to the partition nodes this set is a member of.*/
	MessageID getPartition(){char buffer[4096];sprintf_s (buffer, "%s.pa",mName.c_str());return (const char*)buffer;}
	/*References to nodes that operate upon this set, such as deformers.*/
	const MessageID& getUsedBy(size_t ub_i){char buffer[4096];sprintf_s (buffer, "%s.ub[%i]",mName.c_str(),ub_i);return (const char*)buffer;}
protected:
	ObjectSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Entity(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTSET_H__
