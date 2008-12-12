/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PSDFILETEX_H__
#define __MayaDM_PSDFILETEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFile.h"
namespace MayaDM
{
/*
<p><pre>

</pre></p>
*/
class PsdFileTex : public File
{
public:
public:
	PsdFileTex(FILE* file,const std::string& name,const std::string& parent=""):File(file, name, parent, "psdFileTex"){}
	virtual ~PsdFileTex(){}
	/*
	<b>Layer Set Name</b> is the name of a layer set in the image file. The
	composite image in this layer set will be used as the texture.
	*/
	void setLayerSetName(const string& lsn){if(lsn == "NULL") return; fprintf_s(mFile, "setAttr \".lsn\" -type \"string\" ");lsn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Layer Set Name</b> is the name of a layer set in the image file. The
	composite image in this layer set will be used as the texture.
	*/
	void setLayerSetName(const StringID& lsn){fprintf_s(mFile,"connectAttr \"");lsn.write(mFile);fprintf_s(mFile,"\" \"%s.lsn\";\n",mName.c_str());}
	/*List of layer sets contained in the PSD file*/
	void setLayerSets(const StringArrayID& lys){fprintf_s(mFile,"connectAttr \"");lys.write(mFile);fprintf_s(mFile,"\" \"%s.lys\";\n",mName.c_str());}
	/*<b>Alpha</b> is the name of alpha channel in the image file.*/
	void setAlpha(const string& alp){if(alp == "NULL") return; fprintf_s(mFile, "setAttr \".alp\" -type \"string\" ");alp.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Alpha</b> is the name of alpha channel in the image file.*/
	void setAlpha(const StringID& alp){fprintf_s(mFile,"connectAttr \"");alp.write(mFile);fprintf_s(mFile,"\" \"%s.alp\";\n",mName.c_str());}
	/*List of alpha channel names contained in the PSD file*/
	void setAlphaList(const StringArrayID& als){fprintf_s(mFile,"connectAttr \"");als.write(mFile);fprintf_s(mFile,"\" \"%s.als\";\n",mName.c_str());}
	/*
	<b>Layer Set Name</b> is the name of a layer set in the image file. The
	composite image in this layer set will be used as the texture.
	*/
	StringID getLayerSetName(){char buffer[4096];sprintf_s (buffer, "%s.lsn",mName.c_str());return (const char*)buffer;}
	/*List of layer sets contained in the PSD file*/
	StringArrayID getLayerSets(){char buffer[4096];sprintf_s (buffer, "%s.lys",mName.c_str());return (const char*)buffer;}
	/*<b>Alpha</b> is the name of alpha channel in the image file.*/
	StringID getAlpha(){char buffer[4096];sprintf_s (buffer, "%s.alp",mName.c_str());return (const char*)buffer;}
	/*List of alpha channel names contained in the PSD file*/
	StringArrayID getAlphaList(){char buffer[4096];sprintf_s (buffer, "%s.als",mName.c_str());return (const char*)buffer;}
protected:
	PsdFileTex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):File(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PSDFILETEX_H__
