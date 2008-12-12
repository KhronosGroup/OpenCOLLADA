/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GEOMETRYFILTER_H__
#define __MayaDM_GEOMETRYFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> This node provides the attributes common to all deformations.
 Deformations can deform multiple pieces of input geometry
 (or component parts of geometry).
 Each distinct piece of input geometry (or part thereof) has an
 associated output.
</pre></p>
*/
class GeometryFilter : public DependNode
{
public:
	/*The geometry/groupId bundled input array*/
	struct Input{
		int groupId;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i", groupId);
		}
	};
public:
	GeometryFilter(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "geometryFilter"){}
	virtual ~GeometryFilter(){}
	/*The geometry/groupId bundled input array*/
	void setInput(size_t ip_i,const Input& ip){fprintf_s(mFile, "setAttr \".ip[%i]\" ",ip_i);ip.write(mFile);fprintf_s(mFile,";\n");}
	/*The geometry/groupId bundled input array*/
	void setInput(size_t ip_i,const InputID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip[%i]\";\n",mName.c_str(),ip_i);}
	/*The geometry input*/
	void setInputGeometry(size_t ip_i,const GeometryID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ip[%i].ig\";\n",mName.c_str(),ip_i);}
	/*The group id input*/
	void setGroupId(size_t ip_i,int gi){if(gi == 0) return; fprintf_s(mFile, "setAttr \".ip[%i].gi\" %i;\n", ip_i,gi);}
	/*The group id input*/
	void setGroupId(size_t ip_i,const IntID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.ip[%i].gi\";\n",mName.c_str(),ip_i);}
	/*The geometry output array*/
	void setOutputGeometry(size_t og_i,const GeometryID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og[%i]\";\n",mName.c_str(),og_i);}
	/*
	How much of the deformation should be applied.
	0.0 means no deformation at all; 1.0 means the full deformation.
	*/
	void setEnvelope(float en){if(en == 1) return; fprintf_s(mFile, "setAttr \".en\" %f;\n", en);}
	/*
	How much of the deformation should be applied.
	0.0 means no deformation at all; 1.0 means the full deformation.
	*/
	void setEnvelope(const FloatID& en){fprintf_s(mFile,"connectAttr \"");en.write(mFile);fprintf_s(mFile,"\" \"%s.en\";\n",mName.c_str());}
	/*
	This is a mapping of single 32 bit indices to 64 bit values.
	Currently only used where a 64 bit value is
	needed to uniquely specify a vertex, which is rare.
	For most objects whose vertices are 32 bit values, such as NURBS
	curves, NURBS surfaces, poly meshes, and lattices, this attribute is empty.
	*/
	void setMap64BitIndices(const LongArrayID& map){fprintf_s(mFile,"connectAttr \"");map.write(mFile);fprintf_s(mFile,"\" \"%s.map\";\n",mName.c_str());}
	/*The geometry/groupId bundled input array*/
	const InputID& getInput(size_t ip_i){char buffer[4096];sprintf_s (buffer, "%s.ip[%i]",mName.c_str(),ip_i);return (const char*)buffer;}
	/*The geometry input*/
	const GeometryID& getInputGeometry(size_t ip_i){char buffer[4096];sprintf_s (buffer, "%s.ip[%i].ig",mName.c_str(),ip_i);return (const char*)buffer;}
	/*The group id input*/
	const IntID& getGroupId(size_t ip_i){char buffer[4096];sprintf_s (buffer, "%s.ip[%i].gi",mName.c_str(),ip_i);return (const char*)buffer;}
	/*The geometry output array*/
	const GeometryID& getOutputGeometry(size_t og_i){char buffer[4096];sprintf_s (buffer, "%s.og[%i]",mName.c_str(),og_i);return (const char*)buffer;}
	/*
	How much of the deformation should be applied.
	0.0 means no deformation at all; 1.0 means the full deformation.
	*/
	FloatID getEnvelope(){char buffer[4096];sprintf_s (buffer, "%s.en",mName.c_str());return (const char*)buffer;}
	/*
	This is a mapping of single 32 bit indices to 64 bit values.
	Currently only used where a 64 bit value is
	needed to uniquely specify a vertex, which is rare.
	For most objects whose vertices are 32 bit values, such as NURBS
	curves, NURBS surfaces, poly meshes, and lattices, this attribute is empty.
	*/
	LongArrayID getMap64BitIndices(){char buffer[4096];sprintf_s (buffer, "%s.map",mName.c_str());return (const char*)buffer;}
protected:
	GeometryFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GEOMETRYFILTER_H__
