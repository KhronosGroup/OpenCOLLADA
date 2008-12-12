/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CREATECOLORSET_H__
#define __MayaDM_CREATECOLORSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> Node to create new empty sets of color (cpv layers).
</pre></p>
*/
class CreateColorSet : public DependNode
{
public:
public:
	CreateColorSet(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "createColorSet"){}
	virtual ~CreateColorSet(){}
	/*The input geometry to be modified*/
	void setInputGeometry(const GeometryID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ig\";\n",mName.c_str());}
	/*The output modified geometry*/
	void setOutputGeometry(const GeometryID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og\";\n",mName.c_str());}
	/*Name of the uv set to create*/
	void setColorSetName(const string& colos){if(colos == "NULL") return; fprintf_s(mFile, "setAttr \".colos\" -type \"string\" ");colos.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the uv set to create*/
	void setColorSetName(const StringID& colos){fprintf_s(mFile,"connectAttr \"");colos.write(mFile);fprintf_s(mFile,"\" \"%s.colos\";\n",mName.c_str());}
	/*If true, color and alpha will be in 0 to 1 range.*/
	void setClamped(bool clam){if(clam == true) return; fprintf_s(mFile, "setAttr \".clam\" %i;\n", clam);}
	/*If true, color and alpha will be in 0 to 1 range.*/
	void setClamped(const BoolID& clam){fprintf_s(mFile,"connectAttr \"");clam.write(mFile);fprintf_s(mFile,"\" \"%s.clam\";\n",mName.c_str());}
	/*This identifies both the number of channels and the type of channels*/
	void setRepresentation(unsigned int rprt){if(rprt == 3) return; fprintf_s(mFile, "setAttr \".rprt\" %i;\n", rprt);}
	/*This identifies both the number of channels and the type of channels*/
	void setRepresentation(const UnsignedintID& rprt){fprintf_s(mFile,"connectAttr \"");rprt.write(mFile);fprintf_s(mFile,"\" \"%s.rprt\";\n",mName.c_str());}
	/*The input geometry to be modified*/
	GeometryID getInputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.ig",mName.c_str());return (const char*)buffer;}
	/*The output modified geometry*/
	GeometryID getOutputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.og",mName.c_str());return (const char*)buffer;}
	/*Name of the uv set to create*/
	StringID getColorSetName(){char buffer[4096];sprintf_s (buffer, "%s.colos",mName.c_str());return (const char*)buffer;}
	/*If true, color and alpha will be in 0 to 1 range.*/
	BoolID getClamped(){char buffer[4096];sprintf_s (buffer, "%s.clam",mName.c_str());return (const char*)buffer;}
	/*This identifies both the number of channels and the type of channels*/
	UnsignedintID getRepresentation(){char buffer[4096];sprintf_s (buffer, "%s.rprt",mName.c_str());return (const char*)buffer;}
protected:
	CreateColorSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CREATECOLORSET_H__
