/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDWEIGHTED_H__
#define __MayaDM_BLENDWEIGHTED_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBlend.h"
namespace MayaDM
{
/*
Performs a weighted sum of its inputs to compute the output.
<br/>
    output = input(0) * weight(0)  + input(1) * weight(1)  + ...
*/
class BlendWeighted : public Blend
{
public:
public:
	BlendWeighted(FILE* file,const std::string& name,const std::string& parent=""):Blend(file, name, parent, "blendWeighted"){}
	virtual ~BlendWeighted(){}
	/*
	List of weights in 1-1 correspondence with elements of "input"
	attribute from blend node.
	*/
	void setWeight(size_t w_i,float w){if(w == 1.0) return; fprintf_s(mFile, "setAttr \".w[%i]\" %f;\n", w_i,w);}
	/*
	List of weights in 1-1 correspondence with elements of "input"
	attribute from blend node.
	*/
	void setWeight(size_t w_i,const FloatID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w[%i]\";\n",mName.c_str(),w_i);}
	/*
	List of weights in 1-1 correspondence with elements of "input"
	attribute from blend node.
	*/
	const FloatID& getWeight(size_t w_i){char buffer[4096];sprintf_s (buffer, "%s.w[%i]",mName.c_str(),w_i);return (const char*)buffer;}
protected:
	BlendWeighted(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Blend(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BLENDWEIGHTED_H__
