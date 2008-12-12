/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MENTALRAYTEXTURE_H__
#define __MayaDM_MENTALRAYTEXTURE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>mentalray texture</b> is special kind of texture file node used in mental ray shaders.
        This node is connectable to
        "color texture", "scalar texture", "vector texture" params of mental ray shaders.
        <p/>
        Example :
        connects to mib_texture_lookup1.tex
*/
class MentalrayTexture : public DependNode
{
public:
	/*
	The file size are read from the file.
	If the file is writable, ie) <b>miWritable</b> is true,
	<b>miFileSize</b> should be set to proper values.
	*/
	struct MiFileSize{
		int miWidth;
		int miHeight;
		unsigned int miDepth;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", miWidth);
			fprintf_s(file,"%i ", miHeight);
			fprintf_s(file,"%i", miDepth);
		}
	};
public:
	MentalrayTexture(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "mentalrayTexture"){}
	virtual ~MentalrayTexture(){}
	/*
	Texture type.
	There are three type of textures : scalar, color, vector
	*/
	void setMiTextureType(unsigned int mitt){if(mitt == 1) return; fprintf_s(mFile, "setAttr \".mitt\" %i;\n", mitt);}
	/*
	Texture type.
	There are three type of textures : scalar, color, vector
	*/
	void setMiTextureType(const UnsignedintID& mitt){fprintf_s(mFile,"connectAttr \"");mitt.write(mFile);fprintf_s(mFile,"\" \"%s.mitt\";\n",mName.c_str());}
	/*
	<b>File Texture Name</b> is the name of an image file.  The
	image in this file will be used as the texture.
	<p/>
	*/
	void setFileTextureName(const string& ftn){if(ftn == "NULL") return; fprintf_s(mFile, "setAttr \".ftn\" -type \"string\" ");ftn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>File Texture Name</b> is the name of an image file.  The
	image in this file will be used as the texture.
	<p/>
	*/
	void setFileTextureName(const StringID& ftn){fprintf_s(mFile,"connectAttr \"");ftn.write(mFile);fprintf_s(mFile,"\" \"%s.ftn\";\n",mName.c_str());}
	/*
	<b>miLocal</b> is a flag to tell mental ray
	whether or not to transfer this file to other machines for network rendering
	If <b>miLocal</b> is false, the file is read once on the master host and then
	transmitted over the network to all slave hosts that participate in the rendering.
	If <b>miLocal</b> is true, only the file name is transmitted to the slave hosts;
	this requires the file exists locally on all slave hosts
	but reduces network transfer times drastically
	if many texture files or very large texture files are used.
	*/
	void setMiLocal(bool mil){if(mil == false) return; fprintf_s(mFile, "setAttr \".mil\" %i;\n", mil);}
	/*
	<b>miLocal</b> is a flag to tell mental ray
	whether or not to transfer this file to other machines for network rendering
	If <b>miLocal</b> is false, the file is read once on the master host and then
	transmitted over the network to all slave hosts that participate in the rendering.
	If <b>miLocal</b> is true, only the file name is transmitted to the slave hosts;
	this requires the file exists locally on all slave hosts
	but reduces network transfer times drastically
	if many texture files or very large texture files are used.
	*/
	void setMiLocal(const BoolID& mil){fprintf_s(mFile,"connectAttr \"");mil.write(mFile);fprintf_s(mFile,"\" \"%s.mil\";\n",mName.c_str());}
	/*
	If the <b>miWritable</b> flag is set, the texture is written to a file
	after it was written by a shader.
	This kind of texture is used by lightmap shaders to write back to light mapping result.
	If <b>miWritable</b> is set, <b>miLocal</b> should be specified as well
	because the file should be written to disk on the master host only.
	*/
	void setMiWritable(bool miw){if(miw == false) return; fprintf_s(mFile, "setAttr \".miw\" %i;\n", miw);}
	/*
	If the <b>miWritable</b> flag is set, the texture is written to a file
	after it was written by a shader.
	This kind of texture is used by lightmap shaders to write back to light mapping result.
	If <b>miWritable</b> is set, <b>miLocal</b> should be specified as well
	because the file should be written to disk on the master host only.
	*/
	void setMiWritable(const BoolID& miw){fprintf_s(mFile,"connectAttr \"");miw.write(mFile);fprintf_s(mFile,"\" \"%s.miw\";\n",mName.c_str());}
	/*
	If <b>MiFilter</b> is set, a texture filtering based on texture pyramids,
	a technique comparable to mip-map textures, is enabled.
	Filtered textures are preprocessed before rendering begins
	and use approximately 30% more memory.
	Filtering should be used when the texture is large and seen at a distance,
	such that every sample covers many texture pixels.
	*/
	void setMiFilter(bool mift){if(mift == false) return; fprintf_s(mFile, "setAttr \".mift\" %i;\n", mift);}
	/*
	If <b>MiFilter</b> is set, a texture filtering based on texture pyramids,
	a technique comparable to mip-map textures, is enabled.
	Filtered textures are preprocessed before rendering begins
	and use approximately 30% more memory.
	Filtering should be used when the texture is large and seen at a distance,
	such that every sample covers many texture pixels.
	*/
	void setMiFilter(const BoolID& mift){fprintf_s(mFile,"connectAttr \"");mift.write(mFile);fprintf_s(mFile,"\" \"%s.mift\";\n",mName.c_str());}
	/*The compression of the texture on the viewing plane is scaled by <b>miFilterSize</b>.*/
	void setMiFilterSize(float mifs){if(mifs == 1.0) return; fprintf_s(mFile, "setAttr \".mifs\" %f;\n", mifs);}
	/*The compression of the texture on the viewing plane is scaled by <b>miFilterSize</b>.*/
	void setMiFilterSize(const FloatID& mifs){fprintf_s(mFile,"connectAttr \"");mifs.write(mFile);fprintf_s(mFile,"\" \"%s.mifs\";\n",mName.c_str());}
	/*
	The file size are read from the file.
	If the file is writable, ie) <b>miWritable</b> is true,
	<b>miFileSize</b> should be set to proper values.
	*/
	void setMiFileSize(const MiFileSize& mifr){fprintf_s(mFile, "setAttr \".mifr\" ");mifr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The file size are read from the file.
	If the file is writable, ie) <b>miWritable</b> is true,
	<b>miFileSize</b> should be set to proper values.
	*/
	void setMiFileSize(const MiFileSizeID& mifr){fprintf_s(mFile,"connectAttr \"");mifr.write(mFile);fprintf_s(mFile,"\" \"%s.mifr\";\n",mName.c_str());}
	/*Width part of miFileSize*/
	void setMiWidth(int miwd){if(miwd == 100) return; fprintf_s(mFile, "setAttr \".mifr.miwd\" %i;\n", miwd);}
	/*Width part of miFileSize*/
	void setMiWidth(const IntID& miwd){fprintf_s(mFile,"connectAttr \"");miwd.write(mFile);fprintf_s(mFile,"\" \"%s.mifr.miwd\";\n",mName.c_str());}
	/*Height part of miFileSize*/
	void setMiHeight(int mihg){if(mihg == 100) return; fprintf_s(mFile, "setAttr \".mifr.mihg\" %i;\n", mihg);}
	/*Height part of miFileSize*/
	void setMiHeight(const IntID& mihg){fprintf_s(mFile,"connectAttr \"");mihg.write(mFile);fprintf_s(mFile,"\" \"%s.mifr.mihg\";\n",mName.c_str());}
	/*
	Bytes per component. 1,2, or 4. default is 1.
	1 = 8 bits per component.
	2 = 16 bits per component.
	4 = 32 bits per component for floating-point texture.
	*/
	void setMiDepth(unsigned int midp){if(midp == 0) return; fprintf_s(mFile, "setAttr \".mifr.midp\" %i;\n", midp);}
	/*
	Bytes per component. 1,2, or 4. default is 1.
	1 = 8 bits per component.
	2 = 16 bits per component.
	4 = 32 bits per component for floating-point texture.
	*/
	void setMiDepth(const UnsignedintID& midp){fprintf_s(mFile,"connectAttr \"");midp.write(mFile);fprintf_s(mFile,"\" \"%s.mifr.midp\";\n",mName.c_str());}
	/*
	Texture type.
	There are three type of textures : scalar, color, vector
	*/
	UnsignedintID getMiTextureType(){char buffer[4096];sprintf_s (buffer, "%s.mitt",mName.c_str());return (const char*)buffer;}
	/*
	<b>File Texture Name</b> is the name of an image file.  The
	image in this file will be used as the texture.
	<p/>
	*/
	StringID getFileTextureName(){char buffer[4096];sprintf_s (buffer, "%s.ftn",mName.c_str());return (const char*)buffer;}
	/*
	<b>miLocal</b> is a flag to tell mental ray
	whether or not to transfer this file to other machines for network rendering
	If <b>miLocal</b> is false, the file is read once on the master host and then
	transmitted over the network to all slave hosts that participate in the rendering.
	If <b>miLocal</b> is true, only the file name is transmitted to the slave hosts;
	this requires the file exists locally on all slave hosts
	but reduces network transfer times drastically
	if many texture files or very large texture files are used.
	*/
	BoolID getMiLocal(){char buffer[4096];sprintf_s (buffer, "%s.mil",mName.c_str());return (const char*)buffer;}
	/*
	If the <b>miWritable</b> flag is set, the texture is written to a file
	after it was written by a shader.
	This kind of texture is used by lightmap shaders to write back to light mapping result.
	If <b>miWritable</b> is set, <b>miLocal</b> should be specified as well
	because the file should be written to disk on the master host only.
	*/
	BoolID getMiWritable(){char buffer[4096];sprintf_s (buffer, "%s.miw",mName.c_str());return (const char*)buffer;}
	/*
	If <b>MiFilter</b> is set, a texture filtering based on texture pyramids,
	a technique comparable to mip-map textures, is enabled.
	Filtered textures are preprocessed before rendering begins
	and use approximately 30% more memory.
	Filtering should be used when the texture is large and seen at a distance,
	such that every sample covers many texture pixels.
	*/
	BoolID getMiFilter(){char buffer[4096];sprintf_s (buffer, "%s.mift",mName.c_str());return (const char*)buffer;}
	/*The compression of the texture on the viewing plane is scaled by <b>miFilterSize</b>.*/
	FloatID getMiFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.mifs",mName.c_str());return (const char*)buffer;}
	/*
	The file size are read from the file.
	If the file is writable, ie) <b>miWritable</b> is true,
	<b>miFileSize</b> should be set to proper values.
	*/
	MiFileSizeID getMiFileSize(){char buffer[4096];sprintf_s (buffer, "%s.mifr",mName.c_str());return (const char*)buffer;}
	/*Width part of miFileSize*/
	IntID getMiWidth(){char buffer[4096];sprintf_s (buffer, "%s.mifr.miwd",mName.c_str());return (const char*)buffer;}
	/*Height part of miFileSize*/
	IntID getMiHeight(){char buffer[4096];sprintf_s (buffer, "%s.mifr.mihg",mName.c_str());return (const char*)buffer;}
	/*
	Bytes per component. 1,2, or 4. default is 1.
	1 = 8 bits per component.
	2 = 16 bits per component.
	4 = 32 bits per component for floating-point texture.
	*/
	UnsignedintID getMiDepth(){char buffer[4096];sprintf_s (buffer, "%s.mifr.midp",mName.c_str());return (const char*)buffer;}
protected:
	MentalrayTexture(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MENTALRAYTEXTURE_H__
