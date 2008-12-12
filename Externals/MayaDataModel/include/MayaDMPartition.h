/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTITION_H__
#define __MayaDM_PARTITION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMEntity.h"
namespace MayaDM
{
/*
This node defines a collection of objectSet nodes which are mutually
  exclusive of each other with respect to membership.  That is, no member
  of an objectSet which is in a partition will also be a member of
  another objectSet if that objectSet is also in the same partition.
  Partitions are created and edited using the "partition" command.
  Mutual exclusivity is enforced by both the "sets" and "partition"
  commands.<p/>

  The "renderPartition" defines the collection of shading groups which
  define which objects should be rendered.  If an object or part of an
  object is not in a shading group, it will not be rendered.<p/>

  A partition can have an annotation which is a text string associated
  with the partition. It can be used to describe the purpose of the
  partition.<p/>
*/
class Partition : public Entity
{
public:
public:
	Partition(FILE* file,const std::string& name,const std::string& parent=""):Entity(file, name, parent, "partition"){}
	virtual ~Partition(){}
	/*A text string to annotate the partition.*/
	void setAnnotation(const string& an){if(an == "NULL") return; fprintf_s(mFile, "setAttr \".an\" -type \"string\" ");an.write(mFile);fprintf_s(mFile,";\n");}
	/*Partitions can be of type: 0 = regular, 1 = render partition*/
	void setPartitionType(unsigned int pt){if(pt == 0) return; fprintf_s(mFile, "setAttr \".pt\" %i;\n", pt);}
	/*Only used by ViCE for connection to the environment facade*/
	void setEnvironment(const MessageID& envr){fprintf_s(mFile,"connectAttr \"");envr.write(mFile);fprintf_s(mFile,"\" \"%s.envr\";\n",mName.c_str());}
	/*Only used by ViCE for connection to the environment facade*/
	MessageID getEnvironment(){char buffer[4096];sprintf_s (buffer, "%s.envr",mName.c_str());return (const char*)buffer;}
protected:
	Partition(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Entity(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARTITION_H__
