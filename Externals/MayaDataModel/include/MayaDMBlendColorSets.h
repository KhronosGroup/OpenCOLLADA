/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDCOLORSETS_H__
#define __MayaDM_BLENDCOLORSETS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
<p><pre> Blend copy of color sets.
</pre></p>
*/
class BlendColorSets : public PolyModifier
{
public:
public:
	BlendColorSets(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "blendColorSets"){}
	virtual ~BlendColorSets(){}
	/*Name of the color set to copy from*/
	void setBaseColorName(const string& bcn){if(bcn == "NULL") return; fprintf_s(mFile, "setAttr \".bcn\" -type \"string\" ");bcn.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the color set to copy from*/
	void setBaseColorName(const StringID& bcn){fprintf_s(mFile,"connectAttr \"");bcn.write(mFile);fprintf_s(mFile,"\" \"%s.bcn\";\n",mName.c_str());}
	/*Name of the color set to copy from*/
	void setSrcColorName(const string& src){if(src == "NULL") return; fprintf_s(mFile, "setAttr \".src\" -type \"string\" ");src.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the color set to copy from*/
	void setSrcColorName(const StringID& src){fprintf_s(mFile,"connectAttr \"");src.write(mFile);fprintf_s(mFile,"\" \"%s.src\";\n",mName.c_str());}
	/*Name of the color set to copy to*/
	void setDstColorName(const string& dst){if(dst == "NULL") return; fprintf_s(mFile, "setAttr \".dst\" -type \"string\" ");dst.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the color set to copy to*/
	void setDstColorName(const StringID& dst){fprintf_s(mFile,"connectAttr \"");dst.write(mFile);fprintf_s(mFile,"\" \"%s.dst\";\n",mName.c_str());}
	/*Type of blending function to use*/
	void setBlendFunc(unsigned int bfn){if(bfn == 0) return; fprintf_s(mFile, "setAttr \".bfn\" %i;\n", bfn);}
	/*Type of blending function to use*/
	void setBlendFunc(const UnsignedintID& bfn){fprintf_s(mFile,"connectAttr \"");bfn.write(mFile);fprintf_s(mFile,"\" \"%s.bfn\";\n",mName.c_str());}
	/*blend weight for linear and bilinear blending functions*/
	void setBlendWeightA(float bwa){if(bwa == 0.0) return; fprintf_s(mFile, "setAttr \".bwa\" %f;\n", bwa);}
	/*blend weight for linear and bilinear blending functions*/
	void setBlendWeightA(const FloatID& bwa){fprintf_s(mFile,"connectAttr \"");bwa.write(mFile);fprintf_s(mFile,"\" \"%s.bwa\";\n",mName.c_str());}
	/*blend weight for bilinear and channel blending functions*/
	void setBlendWeightB(float bwb){if(bwb == 0.0) return; fprintf_s(mFile, "setAttr \".bwb\" %f;\n", bwb);}
	/*blend weight for bilinear and channel blending functions*/
	void setBlendWeightB(const FloatID& bwb){fprintf_s(mFile,"connectAttr \"");bwb.write(mFile);fprintf_s(mFile,"\" \"%s.bwb\";\n",mName.c_str());}
	/*blend weight for channel functions*/
	void setBlendWeightC(float bwc){if(bwc == 0.5) return; fprintf_s(mFile, "setAttr \".bwc\" %f;\n", bwc);}
	/*blend weight for channel functions*/
	void setBlendWeightC(const FloatID& bwc){fprintf_s(mFile,"connectAttr \"");bwc.write(mFile);fprintf_s(mFile,"\" \"%s.bwc\";\n",mName.c_str());}
	/*blend weight for channel functions*/
	void setBlendWeightD(float bwd){if(bwd == 0.5) return; fprintf_s(mFile, "setAttr \".bwd\" %f;\n", bwd);}
	/*blend weight for channel functions*/
	void setBlendWeightD(const FloatID& bwd){fprintf_s(mFile,"connectAttr \"");bwd.write(mFile);fprintf_s(mFile,"\" \"%s.bwd\";\n",mName.c_str());}
	/*Name of the color set to copy from*/
	StringID getBaseColorName(){char buffer[4096];sprintf_s (buffer, "%s.bcn",mName.c_str());return (const char*)buffer;}
	/*Name of the color set to copy from*/
	StringID getSrcColorName(){char buffer[4096];sprintf_s (buffer, "%s.src",mName.c_str());return (const char*)buffer;}
	/*Name of the color set to copy to*/
	StringID getDstColorName(){char buffer[4096];sprintf_s (buffer, "%s.dst",mName.c_str());return (const char*)buffer;}
	/*Type of blending function to use*/
	UnsignedintID getBlendFunc(){char buffer[4096];sprintf_s (buffer, "%s.bfn",mName.c_str());return (const char*)buffer;}
	/*blend weight for linear and bilinear blending functions*/
	FloatID getBlendWeightA(){char buffer[4096];sprintf_s (buffer, "%s.bwa",mName.c_str());return (const char*)buffer;}
	/*blend weight for bilinear and channel blending functions*/
	FloatID getBlendWeightB(){char buffer[4096];sprintf_s (buffer, "%s.bwb",mName.c_str());return (const char*)buffer;}
	/*blend weight for channel functions*/
	FloatID getBlendWeightC(){char buffer[4096];sprintf_s (buffer, "%s.bwc",mName.c_str());return (const char*)buffer;}
	/*blend weight for channel functions*/
	FloatID getBlendWeightD(){char buffer[4096];sprintf_s (buffer, "%s.bwd",mName.c_str());return (const char*)buffer;}
protected:
	BlendColorSets(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BLENDCOLORSETS_H__
