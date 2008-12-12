/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HISTORYSWITCH_H__
#define __MayaDM_HISTORYSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
/*
The historySwitch node allows the user to play back either the
 history of the shape or the vectorArray data coming in through the
 inPositions array. When used in conjunction with the cacheFile node,
 the historySwitch node can be used to play back cache data from disk.
 <p/>
 The historySwitch node also has an outPositions array which can be
 used in conjunction with the cacheFile command to cache the deformed
 point positions to disk.
 <p/>
*/
class HistorySwitch : public GeometryFilter
{
public:
public:
	HistorySwitch(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "historySwitch"){}
	virtual ~HistorySwitch(){}
	/*
	The undeformed geometry input. When playing back the vectorArray
	data, the node uses this input to define the output geometry topology.
	*/
	void setUndeformedGeometry(size_t ug_i,const GeometryID& ug){fprintf_s(mFile,"connectAttr \"");ug.write(mFile);fprintf_s(mFile,"\" \"%s.ug[%i]\";\n",mName.c_str(),ug_i);}
	/*
	When enabled, it plays back from the vector array input,
	disabling evaluation of the history input.
	*/
	void setPlayFromCache(bool pfc){if(pfc == false) return; fprintf_s(mFile, "setAttr \".pfc\" %i;\n", pfc);}
	/*
	When enabled, it plays back from the vector array input,
	disabling evaluation of the history input.
	*/
	void setPlayFromCache(const BoolID& pfc){fprintf_s(mFile,"connectAttr \"");pfc.write(mFile);fprintf_s(mFile,"\" \"%s.pfc\";\n",mName.c_str());}
	/*cached positions for a specific geometry*/
	void setInPositions(size_t inp_i,const GenericID& inp){fprintf_s(mFile,"connectAttr \"");inp.write(mFile);fprintf_s(mFile,"\" \"%s.inp[%i]\";\n",mName.c_str(),inp_i);}
	/*positions of the points of the inputGeometry, determined by evaluating the history of the node*/
	void setOutPositions(size_t op_i,const VectorArrayID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op[%i]\";\n",mName.c_str(),op_i);}
	/*
	The undeformed geometry input. When playing back the vectorArray
	data, the node uses this input to define the output geometry topology.
	*/
	const GeometryID& getUndeformedGeometry(size_t ug_i){char buffer[4096];sprintf_s (buffer, "%s.ug[%i]",mName.c_str(),ug_i);return (const char*)buffer;}
	/*
	When enabled, it plays back from the vector array input,
	disabling evaluation of the history input.
	*/
	BoolID getPlayFromCache(){char buffer[4096];sprintf_s (buffer, "%s.pfc",mName.c_str());return (const char*)buffer;}
	/*cached positions for a specific geometry*/
	const GenericID& getInPositions(size_t inp_i){char buffer[4096];sprintf_s (buffer, "%s.inp[%i]",mName.c_str(),inp_i);return (const char*)buffer;}
	/*positions of the points of the inputGeometry, determined by evaluating the history of the node*/
	const VectorArrayID& getOutPositions(size_t op_i){char buffer[4096];sprintf_s (buffer, "%s.op[%i]",mName.c_str(),op_i);return (const char*)buffer;}
protected:
	HistorySwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HISTORYSWITCH_H__
