/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURGLOBALS_H__
#define __MayaDM_FURGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
"FurGlobals" node is used to define how the fur renders in addition to the render global.
  User must define fur-specific render global before rendering.
*/
class FurGlobals : public DependNode
{
public:
public:
	FurGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "FurGlobals"){}
	virtual ~FurGlobals(){}
	/*To enable or disable fur rendering. True: Enable Fur Rendering, False: Disable Fur Rendering.*/
	void setRenderFur(bool rh){if(rh == true) return; fprintf_s(mFile, "setAttr \".rh\" %i;\n", rh);}
	/*To enable or disable fur rendering. True: Enable Fur Rendering, False: Disable Fur Rendering.*/
	void setRenderFur(const BoolID& rh){fprintf_s(mFile,"connectAttr \"");rh.write(mFile);fprintf_s(mFile,"\" \"%s.rh\";\n",mName.c_str());}
	/*
	Defines the distribution of hair.
	Off-(0) Each surface receives the same number of hairs specified by the Density value for the fur description.
	Globally-(1) The density of each fur description is distributed evenly over all surfaces with fur descriptions attached, regardless of which fur description is attached.
	Per Fur Description-(2) Distributes hairs evenly across multiple different sized surfaces. The distribution of hair for one fur description does not affect the distribution for another fur description, unlike the Globally option.
	*/
	void setAreaValue(unsigned int av){if(av == 2) return; fprintf_s(mFile, "setAttr \".av\" %i;\n", av);}
	/*
	Defines the distribution of hair.
	Off-(0) Each surface receives the same number of hairs specified by the Density value for the fur description.
	Globally-(1) The density of each fur description is distributed evenly over all surfaces with fur descriptions attached, regardless of which fur description is attached.
	Per Fur Description-(2) Distributes hairs evenly across multiple different sized surfaces. The distribution of hair for one fur description does not affect the distribution for another fur description, unlike the Globally option.
	*/
	void setAreaValue(const UnsignedintID& av){fprintf_s(mFile,"connectAttr \"");av.write(mFile);fprintf_s(mFile,"\" \"%s.av\";\n",mName.c_str());}
	/*
	Defines equalizer maps for fur render.
	No Equalizer Maps-(0) Uses no equalizer maps. Fur is distributed according to the parameterization of the surface. If the parameterization is uneven (for example, at the poles of a sphere), the distribution will not be even.
	Default Equalizer Maps-(1) Uses the equalization maps automatically created by fur.
	Read Equalizer Maps-(2) User can modify the equalization map using the Artisan Paint Fur Attributes Tool or pre-generate it using Advanced Fur Rendering.
	*/
	void setEqualMap(short em){if(em == 1) return; fprintf_s(mFile, "setAttr \".em\" %i;\n", em);}
	/*
	Defines equalizer maps for fur render.
	No Equalizer Maps-(0) Uses no equalizer maps. Fur is distributed according to the parameterization of the surface. If the parameterization is uneven (for example, at the poles of a sphere), the distribution will not be even.
	Default Equalizer Maps-(1) Uses the equalization maps automatically created by fur.
	Read Equalizer Maps-(2) User can modify the equalization map using the Artisan Paint Fur Attributes Tool or pre-generate it using Advanced Fur Rendering.
	*/
	void setEqualMap(const ShortID& em){fprintf_s(mFile,"connectAttr \"");em.write(mFile);fprintf_s(mFile,"\" \"%s.em\";\n",mName.c_str());}
	/*Defines to cast fur shadows on geometry but not on fur for shadow map lights.*/
	void setShadowFur(bool sh){if(sh == true) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*Defines to cast fur shadows on geometry but not on fur for shadow map lights.*/
	void setShadowFur(const BoolID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*Defines whether composite the rendered fur and the rendered models or not.*/
	void setCompFur(bool ch){if(ch == true) return; fprintf_s(mFile, "setAttr \".ch\" %i;\n", ch);}
	/*Defines whether composite the rendered fur and the rendered models or not.*/
	void setCompFur(const BoolID& ch){fprintf_s(mFile,"connectAttr \"");ch.write(mFile);fprintf_s(mFile,"\" \"%s.ch\";\n",mName.c_str());}
	/*
	true: Read the fur files created using Advanced Fur Rendering rather than creating new ones at the time of rendering.
	false: Create new fur files at the time of rendering.
	*/
	void setReadFurFiles(bool rff){if(rff == false) return; fprintf_s(mFile, "setAttr \".rff\" %i;\n", rff);}
	/*
	true: Read the fur files created using Advanced Fur Rendering rather than creating new ones at the time of rendering.
	false: Create new fur files at the time of rendering.
	*/
	void setReadFurFiles(const BoolID& rff){fprintf_s(mFile,"connectAttr \"");rff.write(mFile);fprintf_s(mFile,"\" \"%s.rff\";\n",mName.c_str());}
	/*This path is used to read fur files if "readFurFiles" attribute value is true.*/
	void setReadFurFilesPath(const string& rfp){if(rfp == "n/a") return; fprintf_s(mFile, "setAttr \".rfp\" -type \"string\" ");rfp.write(mFile);fprintf_s(mFile,";\n");}
	/*This path is used to read equalizer maps.*/
	void setReadEqualMapPath(const string& rep){if(rep == "n/a") return; fprintf_s(mFile, "setAttr \".rep\" -type \"string\" ");rep.write(mFile);fprintf_s(mFile,";\n");}
	/*
	true: Read the shadow maps created using Advanced Fur Rendering rather than creating new ones at the time of rendering.
	false: Create new shadow maps at the time of rendering.
	*/
	void setReadShadowMap(bool rsm){if(rsm == false) return; fprintf_s(mFile, "setAttr \".rsm\" %i;\n", rsm);}
	/*
	true: Read the shadow maps created using Advanced Fur Rendering rather than creating new ones at the time of rendering.
	false: Create new shadow maps at the time of rendering.
	*/
	void setReadShadowMap(const BoolID& rsm){fprintf_s(mFile,"connectAttr \"");rsm.write(mFile);fprintf_s(mFile,"\" \"%s.rsm\";\n",mName.c_str());}
	/*This path is used to read shadow files if "readShadowMap" attribure value is true.*/
	void setReadShadowMapPath(const string& rsp){if(rsp == "n/a") return; fprintf_s(mFile, "setAttr \".rsp\" -type \"string\" ");rsp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	true: Read the fur images created using Advanced Fur Rendering rather than creating new ones at the time of rendering.
	false: Create new fur images at the time of rendering.
	*/
	void setReadFurImage(bool rhi){if(rhi == false) return; fprintf_s(mFile, "setAttr \".rhi\" %i;\n", rhi);}
	/*
	true: Read the fur images created using Advanced Fur Rendering rather than creating new ones at the time of rendering.
	false: Create new fur images at the time of rendering.
	*/
	void setReadFurImage(const BoolID& rhi){fprintf_s(mFile,"connectAttr \"");rhi.write(mFile);fprintf_s(mFile,"\" \"%s.rhi\";\n",mName.c_str());}
	/*This path is used to read fur image files if "readFurImage" attrbute value is true.*/
	void setReadFurImagePath(const string& rhp){if(rhp == "n/a") return; fprintf_s(mFile, "setAttr \".rhp\" -type \"string\" ");rhp.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the project location*/
	void setProjectLocation(const string& pjl){if(pjl == "n/a") return; fprintf_s(mFile, "setAttr \".pjl\" -type \"string\" ");pjl.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the project location*/
	void setProjectLocation(const StringID& pjl){fprintf_s(mFile,"connectAttr \"");pjl.write(mFile);fprintf_s(mFile,"\" \"%s.pjl\";\n",mName.c_str());}
	/*
	true: Keeps the intermediate fur files built by Fur in the process of creating the final fur images.
	These intermediate files (fur files and shadow maps) are in the furFiles directory and the furShadowMap directory.
	false: The intermediate files are deleted when the render is complete. The equalizer maps are not deleted.
	*/
	void setKeepIntermediateFiles(bool kif){if(kif == false) return; fprintf_s(mFile, "setAttr \".kif\" %i;\n", kif);}
	/*
	true: Keeps the intermediate fur files built by Fur in the process of creating the final fur images.
	These intermediate files (fur files and shadow maps) are in the furFiles directory and the furShadowMap directory.
	false: The intermediate files are deleted when the render is complete. The equalizer maps are not deleted.
	*/
	void setKeepIntermediateFiles(const BoolID& kif){fprintf_s(mFile,"connectAttr \"");kif.write(mFile);fprintf_s(mFile,"\" \"%s.kif\";\n",mName.c_str());}
	/*
	true: Keeps the fur image files created by Fur.
	These files are useful when you turn on Comp. Fur, but still want to see the rendered fur without the model.
	false: Delete fur image files that are created by Fur.
	*/
	void setKeepFurImages(bool kfi){if(kfi == true) return; fprintf_s(mFile, "setAttr \".kfi\" %i;\n", kfi);}
	/*
	true: Keeps the fur image files created by Fur.
	These files are useful when you turn on Comp. Fur, but still want to see the rendered fur without the model.
	false: Delete fur image files that are created by Fur.
	*/
	void setKeepFurImages(const BoolID& kfi){fprintf_s(mFile,"connectAttr \"");kfi.write(mFile);fprintf_s(mFile,"\" \"%s.kfi\";\n",mName.c_str());}
	/*
	Defines the way of saving fur maps when you save a scene.
	Unless Referenced-(0) Saves fur maps only if the fur character is not referenced.
	Always-(1) Saves different versions of the fur maps when you save different versions of a scene.
	Never-(2) Does not save a new fur map.
	*/
	void setCopyAttrMaps(short cam){if(cam == 0) return; fprintf_s(mFile, "setAttr \".cam\" %i;\n", cam);}
	/*
	Defines the way of saving fur maps when you save a scene.
	Unless Referenced-(0) Saves fur maps only if the fur character is not referenced.
	Always-(1) Saves different versions of the fur maps when you save different versions of a scene.
	Never-(2) Does not save a new fur map.
	*/
	void setCopyAttrMaps(const ShortID& cam){fprintf_s(mFile,"connectAttr \"");cam.write(mFile);fprintf_s(mFile,"\" \"%s.cam\";\n",mName.c_str());}
	/*Defines the number of hairs per pixel that are tracked for fur images. Lower values use less memory while higher values produce better quality renders. The upper limit is 10.*/
	void setFurPixelBufferSize(short fpsz){if(fpsz == 5) return; fprintf_s(mFile, "setAttr \".fpsz\" %i;\n", fpsz);}
	/*Defines the number of hairs per pixel that are tracked for fur images. Lower values use less memory while higher values produce better quality renders. The upper limit is 10.*/
	void setFurPixelBufferSize(const ShortID& fpsz){fprintf_s(mFile,"connectAttr \"");fpsz.write(mFile);fprintf_s(mFile,"\" \"%s.fpsz\";\n",mName.c_str());}
	/*Defines the number of hairs per pixel that are tracked for shadow maps. Lower values use less memory while higher values produce better quality renders. The upper limit is 10.*/
	void setShadowPixelBufferSize(short shsz){if(shsz == 5) return; fprintf_s(mFile, "setAttr \".shsz\" %i;\n", shsz);}
	/*Defines the number of hairs per pixel that are tracked for shadow maps. Lower values use less memory while higher values produce better quality renders. The upper limit is 10.*/
	void setShadowPixelBufferSize(const ShortID& shsz){fprintf_s(mFile,"connectAttr \"");shsz.write(mFile);fprintf_s(mFile,"\" \"%s.shsz\";\n",mName.c_str());}
	/*Defines the tessellation factor of the NURBS surface used by the fur render.*/
	void setNurbsTesselation(short nts){if(nts == 4) return; fprintf_s(mFile, "setAttr \".nts\" %i;\n", nts);}
	/*Defines the tessellation factor of the NURBS surface used by the fur render.*/
	void setNurbsTesselation(const ShortID& nts){fprintf_s(mFile,"connectAttr \"");nts.write(mFile);fprintf_s(mFile,"\" \"%s.nts\";\n",mName.c_str());}
	/*
	false: Do not include process id in fur image file name.
	true: Include process id in fur image file name.
	*/
	void setIncludePidInFilesName(bool ipid){if(ipid == false) return; fprintf_s(mFile, "setAttr \".ipid\" %i;\n", ipid);}
	/*
	false: Do not include process id in fur image file name.
	true: Include process id in fur image file name.
	*/
	void setIncludePidInFilesName(const BoolID& ipid){fprintf_s(mFile,"connectAttr \"");ipid.write(mFile);fprintf_s(mFile,"\" \"%s.ipid\";\n",mName.c_str());}
	/*false - Render only the geometry and fur shadows on geometry (no fur images).*/
	void setRenderFurImages(bool rfi){if(rfi == true) return; fprintf_s(mFile, "setAttr \".rfi\" %i;\n", rfi);}
	/*false - Render only the geometry and fur shadows on geometry (no fur images).*/
	void setRenderFurImages(const BoolID& rfi){fprintf_s(mFile,"connectAttr \"");rfi.write(mFile);fprintf_s(mFile,"\" \"%s.rfi\";\n",mName.c_str());}
	/*false - Render the fur and geometry as if the lights in the scene had no fur shadowing attributes.*/
	void setRenderShadowMaps(bool rnsm){if(rnsm == true) return; fprintf_s(mFile, "setAttr \".rnsm\" %i;\n", rnsm);}
	/*false - Render the fur and geometry as if the lights in the scene had no fur shadowing attributes.*/
	void setRenderShadowMaps(const BoolID& rnsm){fprintf_s(mFile,"connectAttr \"");rnsm.write(mFile);fprintf_s(mFile,"\" \"%s.rnsm\";\n",mName.c_str());}
	/*true - Render only the fur images during distributed or batch render.*/
	void setDisableGeometryRendering(bool dgr){if(dgr == false) return; fprintf_s(mFile, "setAttr \".dgr\" %i;\n", dgr);}
	/*true - Render only the fur images during distributed or batch render.*/
	void setDisableGeometryRendering(const BoolID& dgr){fprintf_s(mFile,"connectAttr \"");dgr.write(mFile);fprintf_s(mFile,"\" \"%s.dgr\";\n",mName.c_str());}
	/*To enable or disable fur rendering. True: Enable Fur Rendering, False: Disable Fur Rendering.*/
	BoolID getRenderFur(){char buffer[4096];sprintf_s (buffer, "%s.rh",mName.c_str());return (const char*)buffer;}
	/*
	Defines the distribution of hair.
	Off-(0) Each surface receives the same number of hairs specified by the Density value for the fur description.
	Globally-(1) The density of each fur description is distributed evenly over all surfaces with fur descriptions attached, regardless of which fur description is attached.
	Per Fur Description-(2) Distributes hairs evenly across multiple different sized surfaces. The distribution of hair for one fur description does not affect the distribution for another fur description, unlike the Globally option.
	*/
	UnsignedintID getAreaValue(){char buffer[4096];sprintf_s (buffer, "%s.av",mName.c_str());return (const char*)buffer;}
	/*
	Defines equalizer maps for fur render.
	No Equalizer Maps-(0) Uses no equalizer maps. Fur is distributed according to the parameterization of the surface. If the parameterization is uneven (for example, at the poles of a sphere), the distribution will not be even.
	Default Equalizer Maps-(1) Uses the equalization maps automatically created by fur.
	Read Equalizer Maps-(2) User can modify the equalization map using the Artisan Paint Fur Attributes Tool or pre-generate it using Advanced Fur Rendering.
	*/
	ShortID getEqualMap(){char buffer[4096];sprintf_s (buffer, "%s.em",mName.c_str());return (const char*)buffer;}
	/*Defines to cast fur shadows on geometry but not on fur for shadow map lights.*/
	BoolID getShadowFur(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*Defines whether composite the rendered fur and the rendered models or not.*/
	BoolID getCompFur(){char buffer[4096];sprintf_s (buffer, "%s.ch",mName.c_str());return (const char*)buffer;}
	/*
	true: Read the fur files created using Advanced Fur Rendering rather than creating new ones at the time of rendering.
	false: Create new fur files at the time of rendering.
	*/
	BoolID getReadFurFiles(){char buffer[4096];sprintf_s (buffer, "%s.rff",mName.c_str());return (const char*)buffer;}
	/*
	true: Read the shadow maps created using Advanced Fur Rendering rather than creating new ones at the time of rendering.
	false: Create new shadow maps at the time of rendering.
	*/
	BoolID getReadShadowMap(){char buffer[4096];sprintf_s (buffer, "%s.rsm",mName.c_str());return (const char*)buffer;}
	/*
	true: Read the fur images created using Advanced Fur Rendering rather than creating new ones at the time of rendering.
	false: Create new fur images at the time of rendering.
	*/
	BoolID getReadFurImage(){char buffer[4096];sprintf_s (buffer, "%s.rhi",mName.c_str());return (const char*)buffer;}
	/*Defines the project location*/
	StringID getProjectLocation(){char buffer[4096];sprintf_s (buffer, "%s.pjl",mName.c_str());return (const char*)buffer;}
	/*
	true: Keeps the intermediate fur files built by Fur in the process of creating the final fur images.
	These intermediate files (fur files and shadow maps) are in the furFiles directory and the furShadowMap directory.
	false: The intermediate files are deleted when the render is complete. The equalizer maps are not deleted.
	*/
	BoolID getKeepIntermediateFiles(){char buffer[4096];sprintf_s (buffer, "%s.kif",mName.c_str());return (const char*)buffer;}
	/*
	true: Keeps the fur image files created by Fur.
	These files are useful when you turn on Comp. Fur, but still want to see the rendered fur without the model.
	false: Delete fur image files that are created by Fur.
	*/
	BoolID getKeepFurImages(){char buffer[4096];sprintf_s (buffer, "%s.kfi",mName.c_str());return (const char*)buffer;}
	/*
	Defines the way of saving fur maps when you save a scene.
	Unless Referenced-(0) Saves fur maps only if the fur character is not referenced.
	Always-(1) Saves different versions of the fur maps when you save different versions of a scene.
	Never-(2) Does not save a new fur map.
	*/
	ShortID getCopyAttrMaps(){char buffer[4096];sprintf_s (buffer, "%s.cam",mName.c_str());return (const char*)buffer;}
	/*Defines the number of hairs per pixel that are tracked for fur images. Lower values use less memory while higher values produce better quality renders. The upper limit is 10.*/
	ShortID getFurPixelBufferSize(){char buffer[4096];sprintf_s (buffer, "%s.fpsz",mName.c_str());return (const char*)buffer;}
	/*Defines the number of hairs per pixel that are tracked for shadow maps. Lower values use less memory while higher values produce better quality renders. The upper limit is 10.*/
	ShortID getShadowPixelBufferSize(){char buffer[4096];sprintf_s (buffer, "%s.shsz",mName.c_str());return (const char*)buffer;}
	/*Defines the tessellation factor of the NURBS surface used by the fur render.*/
	ShortID getNurbsTesselation(){char buffer[4096];sprintf_s (buffer, "%s.nts",mName.c_str());return (const char*)buffer;}
	/*
	false: Do not include process id in fur image file name.
	true: Include process id in fur image file name.
	*/
	BoolID getIncludePidInFilesName(){char buffer[4096];sprintf_s (buffer, "%s.ipid",mName.c_str());return (const char*)buffer;}
	/*false - Render only the geometry and fur shadows on geometry (no fur images).*/
	BoolID getRenderFurImages(){char buffer[4096];sprintf_s (buffer, "%s.rfi",mName.c_str());return (const char*)buffer;}
	/*false - Render the fur and geometry as if the lights in the scene had no fur shadowing attributes.*/
	BoolID getRenderShadowMaps(){char buffer[4096];sprintf_s (buffer, "%s.rnsm",mName.c_str());return (const char*)buffer;}
	/*true - Render only the fur images during distributed or batch render.*/
	BoolID getDisableGeometryRendering(){char buffer[4096];sprintf_s (buffer, "%s.dgr",mName.c_str());return (const char*)buffer;}
protected:
	FurGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FURGLOBALS_H__
