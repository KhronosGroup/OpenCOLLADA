/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AMBIENTLIGHT_H__
#define __MayaDM_AMBIENTLIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRenderLight.h"
namespace MayaDM
{
/*
<p><pre>
        This class contains the "shape" information for ambient lights.

</pre></p>
*/
class AmbientLight : public RenderLight
{
public:
public:
	AmbientLight(FILE* file,const std::string& name,const std::string& parent=""):RenderLight(file, name, parent, "ambientLight"){}
	virtual ~AmbientLight(){}
	/*The ambient shade as used by the material/shader.*/
	void setAmbientShade(float as){if(as == 0.45) return; fprintf_s(mFile, "setAttr \".as\" %f;\n", as);}
	/*The ambient shade as used by the material/shader.*/
	void setAmbientShade(const FloatID& as){fprintf_s(mFile,"connectAttr \"");as.write(mFile);fprintf_s(mFile,"\" \"%s.as\";\n",mName.c_str());}
	/*The type of object being lit (volume or surface).*/
	void setObjectType(char ot){if(ot == 1) return; fprintf_s(mFile, "setAttr \".ot\" %;\n", ot);}
	/*The softshadow light radius.*/
	void setShadowRadius(float sr){if(sr == 0.0) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*The softshadow light radius.*/
	void setShadowRadius(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*Turn on soft shadows (applicable to raytracing only).*/
	void setCastSoftShadows(bool cw){if(cw == false) return; fprintf_s(mFile, "setAttr \".cw\" %i;\n", cw);}
	/*Turn on soft shadows (applicable to raytracing only).*/
	void setCastSoftShadows(const BoolID& cw){fprintf_s(mFile,"connectAttr \"");cw.write(mFile);fprintf_s(mFile,"\" \"%s.cw\";\n",mName.c_str());}
	/*sampleData = geometry receives shadows*/
	void setReceiveShadows(bool gs){if(gs == true) return; fprintf_s(mFile, "setAttr \".gs\" %i;\n", gs);}
	/*sampleData = geometry receives shadows*/
	void setReceiveShadows(const BoolID& gs){fprintf_s(mFile,"connectAttr \"");gs.write(mFile);fprintf_s(mFile,"\" \"%s.gs\";\n",mName.c_str());}
	/*The ambient shade as used by the material/shader.*/
	FloatID getAmbientShade(){char buffer[4096];sprintf_s (buffer, "%s.as",mName.c_str());return (const char*)buffer;}
	/*The softshadow light radius.*/
	FloatID getShadowRadius(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*Turn on soft shadows (applicable to raytracing only).*/
	BoolID getCastSoftShadows(){char buffer[4096];sprintf_s (buffer, "%s.cw",mName.c_str());return (const char*)buffer;}
	/*sampleData = geometry receives shadows*/
	BoolID getReceiveShadows(){char buffer[4096];sprintf_s (buffer, "%s.gs",mName.c_str());return (const char*)buffer;}
protected:
	AmbientLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):RenderLight(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_AMBIENTLIGHT_H__
