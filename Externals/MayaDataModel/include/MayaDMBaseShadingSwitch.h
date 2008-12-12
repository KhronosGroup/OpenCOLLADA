/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BASESHADINGSWITCH_H__
#define __MayaDM_BASESHADINGSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Base class for switch nodes. <p/>

      The switch has pairs of shape and shade connections. The
      output corresponds to a shade such that objectId (an implicit
      attribute resolved at sampling time) matches the shape. If
      there is no match the default is output. Using this node,
      object specific shaders, textures, or placements can be
      created. <p/>

      The base switch is not meant to be used in shading
      networks. See singleShadingSwitch, doubleShadingSwitch, and
      tripleShadingSwitch. <p/>
*/
class BaseShadingSwitch : public DependNode
{
public:
public:
	BaseShadingSwitch(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "baseShadingSwitch"){}
	virtual ~BaseShadingSwitch(){}
	/*The objectId of the sample points object*/
	void setObjectId(const AddrID& id){fprintf_s(mFile,"connectAttr \"");id.write(mFile);fprintf_s(mFile,"\" \"%s.id\";\n",mName.c_str());}
	/*The objectId of the sample points object*/
	AddrID getObjectId(){char buffer[4096];sprintf_s (buffer, "%s.id",mName.c_str());return (const char*)buffer;}
protected:
	BaseShadingSwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BASESHADINGSWITCH_H__
