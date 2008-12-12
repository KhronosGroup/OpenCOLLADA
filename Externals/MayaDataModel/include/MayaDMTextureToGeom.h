/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TEXTURETOGEOM_H__
#define __MayaDM_TEXTURETOGEOM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
 Converts an image into planar geometry.

</pre></p>
*/
class TextureToGeom : public DependNode
{
public:
	/*Output attribute for color information.*/
	struct OutColorData{
		void write(FILE* file) const
		{
		}
	};
public:
	TextureToGeom(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "textureToGeom"){}
	virtual ~TextureToGeom(){}
	/*Output attribute indicates the number of segments found.*/
	void setSegmentCount(const IntID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*Output mesh data.*/
	void setOutput(const MeshID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out\";\n",mName.c_str());}
	/*Output attribute for color information.*/
	void setOutColorData(size_t ocd_i,const OutColorDataID& ocd){fprintf_s(mFile,"connectAttr \"");ocd.write(mFile);fprintf_s(mFile,"\" \"%s.ocd[%i]\";\n",mName.c_str(),ocd_i);}
	/*Colors from the segmented mesh*/
	void setOutColor(size_t ocd_i,const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.ocd[%i].oc\";\n",mName.c_str(),ocd_i);}
	/*Output color R component*/
	void setOutColorR(size_t ocd_i,const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.ocd[%i].oc.ocr\";\n",mName.c_str(),ocd_i);}
	/*Output color G component*/
	void setOutColorG(size_t ocd_i,const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.ocd[%i].oc.ocg\";\n",mName.c_str(),ocd_i);}
	/*Output color B component*/
	void setOutColorB(size_t ocd_i,const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.ocd[%i].oc.ocb\";\n",mName.c_str(),ocd_i);}
	/*Output alpha component*/
	void setOutAlpha(size_t ocd_i,const FloatID& oa){fprintf_s(mFile,"connectAttr \"");oa.write(mFile);fprintf_s(mFile,"\" \"%s.ocd[%i].oa\";\n",mName.c_str(),ocd_i);}
	/*
	Maps the segments to the faces of the generated mesh.
	Index i corresponds to segment i in aOutColor.
	*/
	void setOutSegFace(size_t ofm_i,const IntArrayID& ofm){fprintf_s(mFile,"connectAttr \"");ofm.write(mFile);fprintf_s(mFile,"\" \"%s.ofm[%i]\";\n",mName.c_str(),ofm_i);}
	/*
	Used to map segments to shaders. We need input component
	ids to properly assign the shaders.
	*/
	void setSegGroupIds(size_t sgi_i,int sgi){if(sgi == -1) return; fprintf_s(mFile, "setAttr \".sgi[%i]\" %i;\n", sgi_i,sgi);}
	/*
	Used to map segments to shaders. We need input component
	ids to properly assign the shaders.
	*/
	void setSegGroupIds(size_t sgi_i,const IntID& sgi){fprintf_s(mFile,"connectAttr \"");sgi.write(mFile);fprintf_s(mFile,"\" \"%s.sgi[%i]\";\n",mName.c_str(),sgi_i);}
	/*
	Used to drive the tessellation. Since the objective is to
	place the converted geometry onto the surface. We need to
	tessellate the geometry so that when we lift the surface
	to 3d it will be exactly on it without intersections.
	*/
	void setInputMesh(const mesh& im){fprintf_s(mFile, "setAttr \".im\" -type \"mesh\" ");im.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Used to drive the tessellation. Since the objective is to
	place the converted geometry onto the surface. We need to
	tessellate the geometry so that when we lift the surface
	to 3d it will be exactly on it without intersections.
	*/
	void setInputMesh(const MeshID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im\";\n",mName.c_str());}
	/*Specifies the UVset to use when an input mesh is specified.*/
	void setInputMeshUVSet(const string& iuv){if(iuv == "NULL") return; fprintf_s(mFile, "setAttr \".iuv\" -type \"string\" ");iuv.write(mFile);fprintf_s(mFile,";\n");}
	/*Specifies the UVset to use when an input mesh is specified.*/
	void setInputMeshUVSet(const StringID& iuv){fprintf_s(mFile,"connectAttr \"");iuv.write(mFile);fprintf_s(mFile,"\" \"%s.iuv\";\n",mName.c_str());}
	/*
	Forces a quantization of the image before segmentation.
	This helps find segments in gradient shaded areas.  If
	this attribute is set to true then quantizeLevels is used
	to determine the number of levels the image should quantized
	into.
	*/
	void setQuantize(bool qut){if(qut == 0) return; fprintf_s(mFile, "setAttr \".qut\" %i;\n", qut);}
	/*
	Forces a quantization of the image before segmentation.
	This helps find segments in gradient shaded areas.  If
	this attribute is set to true then quantizeLevels is used
	to determine the number of levels the image should quantized
	into.
	*/
	void setQuantize(const BoolID& qut){fprintf_s(mFile,"connectAttr \"");qut.write(mFile);fprintf_s(mFile,"\" \"%s.qut\";\n",mName.c_str());}
	/*
	If 'quantize' is set to true then quantizeLevels attribute
	is used to determine the number of levels of quantization.
	*/
	void setQuantizeLevels(unsigned char qutl){if(qutl == 10) return; fprintf_s(mFile, "setAttr \".qutl\" %i;\n", qutl);}
	/*
	If 'quantize' is set to true then quantizeLevels attribute
	is used to determine the number of levels of quantization.
	*/
	void setQuantizeLevels(const UnsignedcharID& qutl){fprintf_s(mFile,"connectAttr \"");qutl.write(mFile);fprintf_s(mFile,"\" \"%s.qutl\";\n",mName.c_str());}
	/*
	The maximum color difference between two pixels.  This value
	is used to determine if a new pixel should be added to a segment.
	*/
	void setMaxColorDiff(float mcd){if(mcd == 0.125) return; fprintf_s(mFile, "setAttr \".mcd\" %f;\n", mcd);}
	/*
	The maximum color difference between two pixels.  This value
	is used to determine if a new pixel should be added to a segment.
	*/
	void setMaxColorDiff(const FloatID& mcd){fprintf_s(mFile,"connectAttr \"");mcd.write(mFile);fprintf_s(mFile,"\" \"%s.mcd\";\n",mName.c_str());}
	/*
	The minimum segment size expressed as a percentage of a total
	image size.
	*/
	void setMinSegmentSize(float msz){if(msz == 0.005) return; fprintf_s(mFile, "setAttr \".msz\" %f;\n", msz);}
	/*
	The minimum segment size expressed as a percentage of a total
	image size.
	*/
	void setMinSegmentSize(const FloatID& msz){fprintf_s(mFile,"connectAttr \"");msz.write(mFile);fprintf_s(mFile,"\" \"%s.msz\";\n",mName.c_str());}
	/*The search radius used to detect features in the image.*/
	void setSpatialRadius(int spr){if(spr == 7) return; fprintf_s(mFile, "setAttr \".spr\" %i;\n", spr);}
	/*The search radius used to detect features in the image.*/
	void setSpatialRadius(const IntID& spr){fprintf_s(mFile,"connectAttr \"");spr.write(mFile);fprintf_s(mFile,"\" \"%s.spr\";\n",mName.c_str());}
	/*The range of colors we admit into a feature.*/
	void setColorRange(float crng){if(crng == 4.5) return; fprintf_s(mFile, "setAttr \".crng\" %f;\n", crng);}
	/*The range of colors we admit into a feature.*/
	void setColorRange(const FloatID& crng){fprintf_s(mFile,"connectAttr \"");crng.write(mFile);fprintf_s(mFile,"\" \"%s.crng\";\n",mName.c_str());}
	/*Image file to extract geometry from.*/
	void setImageFile(const string& if_){if(if_ == "NULL") return; fprintf_s(mFile, "setAttr \".if\" -type \"string\" ");if_.write(mFile);fprintf_s(mFile,";\n");}
	/*Image file to extract geometry from.*/
	void setImageFile(const StringID& if_){fprintf_s(mFile,"connectAttr \"");if_.write(mFile);fprintf_s(mFile,"\" \"%s.if\";\n",mName.c_str());}
	/*
	Determines the quality of the mesh produced.  Zero is the
	poorest quality and one represents the highest quality.
	*/
	void setMeshQuality(double mq){if(mq == 0.1) return; fprintf_s(mFile, "setAttr \".mq\" %f;\n", mq);}
	/*
	Determines the quality of the mesh produced.  Zero is the
	poorest quality and one represents the highest quality.
	*/
	void setMeshQuality(const DoubleID& mq){fprintf_s(mFile,"connectAttr \"");mq.write(mFile);fprintf_s(mFile,"\" \"%s.mq\";\n",mName.c_str());}
	/*
	If a constraint mesh is defined, then this will offset the
	wrapped surface by using the surface normals of the constraint
	mesh.
	*/
	void setSurfaceOffset(float so){if(so == 0.01) return; fprintf_s(mFile, "setAttr \".so\" %f;\n", so);}
	/*
	If a constraint mesh is defined, then this will offset the
	wrapped surface by using the surface normals of the constraint
	mesh.
	*/
	void setSurfaceOffset(const FloatID& so){fprintf_s(mFile,"connectAttr \"");so.write(mFile);fprintf_s(mFile,"\" \"%s.so\";\n",mName.c_str());}
	/*
	Toggles the smoothing of the mesh boundary. Smoothing is
	done by averaging the points together.
	*/
	void setSmoothBoundary(bool smbd){if(smbd == 1) return; fprintf_s(mFile, "setAttr \".smbd\" %i;\n", smbd);}
	/*
	Toggles the smoothing of the mesh boundary. Smoothing is
	done by averaging the points together.
	*/
	void setSmoothBoundary(const BoolID& smbd){fprintf_s(mFile,"connectAttr \"");smbd.write(mFile);fprintf_s(mFile,"\" \"%s.smbd\";\n",mName.c_str());}
	/*
	If smoothBoundary is toggled then the value in smooth factor
	is used to determine how much the boundary of each segment
	is smoothed. A value of 0.5 would half the number of points
	along a mesh segment.
	*/
	void setSmoothFactor(float smf){if(smf == 0.5) return; fprintf_s(mFile, "setAttr \".smf\" %f;\n", smf);}
	/*
	If smoothBoundary is toggled then the value in smooth factor
	is used to determine how much the boundary of each segment
	is smoothed. A value of 0.5 would half the number of points
	along a mesh segment.
	*/
	void setSmoothFactor(const FloatID& smf){fprintf_s(mFile,"connectAttr \"");smf.write(mFile);fprintf_s(mFile,"\" \"%s.smf\";\n",mName.c_str());}
	/*
	Attempts to fit lines to the gathered pixel data.  This
	tolerance value indicates how closely lines much match.
	This value corresponds to the pixel size.  The tolerance
	is pixelSize * fitTolerance
	*/
	void setFitTolerance(float ft){if(ft == 0.007) return; fprintf_s(mFile, "setAttr \".ft\" %f;\n", ft);}
	/*
	Attempts to fit lines to the gathered pixel data.  This
	tolerance value indicates how closely lines much match.
	This value corresponds to the pixel size.  The tolerance
	is pixelSize * fitTolerance
	*/
	void setFitTolerance(const FloatID& ft){fprintf_s(mFile,"connectAttr \"");ft.write(mFile);fprintf_s(mFile,"\" \"%s.ft\";\n",mName.c_str());}
	/*
	Attempts to detect sharp corners in segments before
	simplification and smoothing. It finds hard corners by
	walking around a segment boundary and finding a group of
	points whose slope does not change and length is equal to
	hardCornerMaxLength/100.0 * MAX(imgWidth,imgHeight).
	*/
	void setHardCornerDetect(bool hcd){if(hcd == 1) return; fprintf_s(mFile, "setAttr \".hcd\" %i;\n", hcd);}
	/*
	Attempts to detect sharp corners in segments before
	simplification and smoothing. It finds hard corners by
	walking around a segment boundary and finding a group of
	points whose slope does not change and length is equal to
	hardCornerMaxLength/100.0 * MAX(imgWidth,imgHeight).
	*/
	void setHardCornerDetect(const BoolID& hcd){fprintf_s(mFile,"connectAttr \"");hcd.write(mFile);fprintf_s(mFile,"\" \"%s.hcd\";\n",mName.c_str());}
	/*Used when hardCornerDetect is enabled.*/
	void setHardCornerMaxLength(float hcml){if(hcml == 10.0) return; fprintf_s(mFile, "setAttr \".hcml\" %f;\n", hcml);}
	/*Used when hardCornerDetect is enabled.*/
	void setHardCornerMaxLength(const FloatID& hcml){fprintf_s(mFile,"connectAttr \"");hcml.write(mFile);fprintf_s(mFile,"\" \"%s.hcml\";\n",mName.c_str());}
	/*
	Tries to remove points along segment boundary that have similar
	slope. That is, if the slope of line xy is equivalent to the slope
	of the line to line xz then y can be removed.
	*/
	void setSimplifyBoundary(bool smpl){if(smpl == 1) return; fprintf_s(mFile, "setAttr \".smpl\" %i;\n", smpl);}
	/*
	Tries to remove points along segment boundary that have similar
	slope. That is, if the slope of line xy is equivalent to the slope
	of the line to line xz then y can be removed.
	*/
	void setSimplifyBoundary(const BoolID& smpl){fprintf_s(mFile,"connectAttr \"");smpl.write(mFile);fprintf_s(mFile,"\" \"%s.smpl\";\n",mName.c_str());}
	/*Used when simplifyBoundary is enabled.*/
	void setSimplifyThreshold(double smpt){if(smpt == 0) return; fprintf_s(mFile, "setAttr \".smpt\" %f;\n", smpt);}
	/*Used when simplifyBoundary is enabled.*/
	void setSimplifyThreshold(const DoubleID& smpt){fprintf_s(mFile,"connectAttr \"");smpt.write(mFile);fprintf_s(mFile,"\" \"%s.smpt\";\n",mName.c_str());}
	/*
	The mesh generating can insert points to acheive a higher
	quality tessellation.  This flag allows the point inserter
	to add points on segment boundaries.
	*/
	void setPointsOnBoundary(bool pob){if(pob == 0) return; fprintf_s(mFile, "setAttr \".pob\" %i;\n", pob);}
	/*
	The mesh generating can insert points to acheive a higher
	quality tessellation.  This flag allows the point inserter
	to add points on segment boundaries.
	*/
	void setPointsOnBoundary(const BoolID& pob){fprintf_s(mFile,"connectAttr \"");pob.write(mFile);fprintf_s(mFile,"\" \"%s.pob\";\n",mName.c_str());}
	/*
	The mesh generator can insert points to acheive a higher
	quality tessellation (i.e. a tessellation without skinny
	triangles). This attribute controls how many points are
	allowed to be added.  This attribute can also be used
	to control the number of triangles.
	*/
	void setMaxPointsAdded(int mpa){if(mpa == 0) return; fprintf_s(mFile, "setAttr \".mpa\" %i;\n", mpa);}
	/*
	The mesh generator can insert points to acheive a higher
	quality tessellation (i.e. a tessellation without skinny
	triangles). This attribute controls how many points are
	allowed to be added.  This attribute can also be used
	to control the number of triangles.
	*/
	void setMaxPointsAdded(const IntID& mpa){fprintf_s(mFile,"connectAttr \"");mpa.write(mFile);fprintf_s(mFile,"\" \"%s.mpa\";\n",mName.c_str());}
	/*Script to be called when shader assignment needs to be done.*/
	void setShaderScript(const string& shs){if(shs == "NULL") return; fprintf_s(mFile, "setAttr \".shs\" -type \"string\" ");shs.write(mFile);fprintf_s(mFile,";\n");}
	/*Script to be called when shader assignment needs to be done.*/
	void setShaderScript(const StringID& shs){fprintf_s(mFile,"connectAttr \"");shs.write(mFile);fprintf_s(mFile,"\" \"%s.shs\";\n",mName.c_str());}
	/*Output attribute indicates the number of segments found.*/
	IntID getSegmentCount(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*Output mesh data.*/
	MeshID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.out",mName.c_str());return (const char*)buffer;}
	/*Output attribute for color information.*/
	const OutColorDataID& getOutColorData(size_t ocd_i){char buffer[4096];sprintf_s (buffer, "%s.ocd[%i]",mName.c_str(),ocd_i);return (const char*)buffer;}
	/*Colors from the segmented mesh*/
	const Float3ID& getOutColor(size_t ocd_i){char buffer[4096];sprintf_s (buffer, "%s.ocd[%i].oc",mName.c_str(),ocd_i);return (const char*)buffer;}
	/*Output color R component*/
	const FloatID& getOutColorR(size_t ocd_i){char buffer[4096];sprintf_s (buffer, "%s.ocd[%i].oc.ocr",mName.c_str(),ocd_i);return (const char*)buffer;}
	/*Output color G component*/
	const FloatID& getOutColorG(size_t ocd_i){char buffer[4096];sprintf_s (buffer, "%s.ocd[%i].oc.ocg",mName.c_str(),ocd_i);return (const char*)buffer;}
	/*Output color B component*/
	const FloatID& getOutColorB(size_t ocd_i){char buffer[4096];sprintf_s (buffer, "%s.ocd[%i].oc.ocb",mName.c_str(),ocd_i);return (const char*)buffer;}
	/*Output alpha component*/
	const FloatID& getOutAlpha(size_t ocd_i){char buffer[4096];sprintf_s (buffer, "%s.ocd[%i].oa",mName.c_str(),ocd_i);return (const char*)buffer;}
	/*
	Maps the segments to the faces of the generated mesh.
	Index i corresponds to segment i in aOutColor.
	*/
	const IntArrayID& getOutSegFace(size_t ofm_i){char buffer[4096];sprintf_s (buffer, "%s.ofm[%i]",mName.c_str(),ofm_i);return (const char*)buffer;}
	/*
	Used to map segments to shaders. We need input component
	ids to properly assign the shaders.
	*/
	const IntID& getSegGroupIds(size_t sgi_i){char buffer[4096];sprintf_s (buffer, "%s.sgi[%i]",mName.c_str(),sgi_i);return (const char*)buffer;}
	/*
	Used to drive the tessellation. Since the objective is to
	place the converted geometry onto the surface. We need to
	tessellate the geometry so that when we lift the surface
	to 3d it will be exactly on it without intersections.
	*/
	MeshID getInputMesh(){char buffer[4096];sprintf_s (buffer, "%s.im",mName.c_str());return (const char*)buffer;}
	/*Specifies the UVset to use when an input mesh is specified.*/
	StringID getInputMeshUVSet(){char buffer[4096];sprintf_s (buffer, "%s.iuv",mName.c_str());return (const char*)buffer;}
	/*
	Forces a quantization of the image before segmentation.
	This helps find segments in gradient shaded areas.  If
	this attribute is set to true then quantizeLevels is used
	to determine the number of levels the image should quantized
	into.
	*/
	BoolID getQuantize(){char buffer[4096];sprintf_s (buffer, "%s.qut",mName.c_str());return (const char*)buffer;}
	/*
	If 'quantize' is set to true then quantizeLevels attribute
	is used to determine the number of levels of quantization.
	*/
	UnsignedcharID getQuantizeLevels(){char buffer[4096];sprintf_s (buffer, "%s.qutl",mName.c_str());return (const char*)buffer;}
	/*
	The maximum color difference between two pixels.  This value
	is used to determine if a new pixel should be added to a segment.
	*/
	FloatID getMaxColorDiff(){char buffer[4096];sprintf_s (buffer, "%s.mcd",mName.c_str());return (const char*)buffer;}
	/*
	The minimum segment size expressed as a percentage of a total
	image size.
	*/
	FloatID getMinSegmentSize(){char buffer[4096];sprintf_s (buffer, "%s.msz",mName.c_str());return (const char*)buffer;}
	/*The search radius used to detect features in the image.*/
	IntID getSpatialRadius(){char buffer[4096];sprintf_s (buffer, "%s.spr",mName.c_str());return (const char*)buffer;}
	/*The range of colors we admit into a feature.*/
	FloatID getColorRange(){char buffer[4096];sprintf_s (buffer, "%s.crng",mName.c_str());return (const char*)buffer;}
	/*Image file to extract geometry from.*/
	StringID getImageFile(){char buffer[4096];sprintf_s (buffer, "%s.if",mName.c_str());return (const char*)buffer;}
	/*
	Determines the quality of the mesh produced.  Zero is the
	poorest quality and one represents the highest quality.
	*/
	DoubleID getMeshQuality(){char buffer[4096];sprintf_s (buffer, "%s.mq",mName.c_str());return (const char*)buffer;}
	/*
	If a constraint mesh is defined, then this will offset the
	wrapped surface by using the surface normals of the constraint
	mesh.
	*/
	FloatID getSurfaceOffset(){char buffer[4096];sprintf_s (buffer, "%s.so",mName.c_str());return (const char*)buffer;}
	/*
	Toggles the smoothing of the mesh boundary. Smoothing is
	done by averaging the points together.
	*/
	BoolID getSmoothBoundary(){char buffer[4096];sprintf_s (buffer, "%s.smbd",mName.c_str());return (const char*)buffer;}
	/*
	If smoothBoundary is toggled then the value in smooth factor
	is used to determine how much the boundary of each segment
	is smoothed. A value of 0.5 would half the number of points
	along a mesh segment.
	*/
	FloatID getSmoothFactor(){char buffer[4096];sprintf_s (buffer, "%s.smf",mName.c_str());return (const char*)buffer;}
	/*
	Attempts to fit lines to the gathered pixel data.  This
	tolerance value indicates how closely lines much match.
	This value corresponds to the pixel size.  The tolerance
	is pixelSize * fitTolerance
	*/
	FloatID getFitTolerance(){char buffer[4096];sprintf_s (buffer, "%s.ft",mName.c_str());return (const char*)buffer;}
	/*
	Attempts to detect sharp corners in segments before
	simplification and smoothing. It finds hard corners by
	walking around a segment boundary and finding a group of
	points whose slope does not change and length is equal to
	hardCornerMaxLength/100.0 * MAX(imgWidth,imgHeight).
	*/
	BoolID getHardCornerDetect(){char buffer[4096];sprintf_s (buffer, "%s.hcd",mName.c_str());return (const char*)buffer;}
	/*Used when hardCornerDetect is enabled.*/
	FloatID getHardCornerMaxLength(){char buffer[4096];sprintf_s (buffer, "%s.hcml",mName.c_str());return (const char*)buffer;}
	/*
	Tries to remove points along segment boundary that have similar
	slope. That is, if the slope of line xy is equivalent to the slope
	of the line to line xz then y can be removed.
	*/
	BoolID getSimplifyBoundary(){char buffer[4096];sprintf_s (buffer, "%s.smpl",mName.c_str());return (const char*)buffer;}
	/*Used when simplifyBoundary is enabled.*/
	DoubleID getSimplifyThreshold(){char buffer[4096];sprintf_s (buffer, "%s.smpt",mName.c_str());return (const char*)buffer;}
	/*
	The mesh generating can insert points to acheive a higher
	quality tessellation.  This flag allows the point inserter
	to add points on segment boundaries.
	*/
	BoolID getPointsOnBoundary(){char buffer[4096];sprintf_s (buffer, "%s.pob",mName.c_str());return (const char*)buffer;}
	/*
	The mesh generator can insert points to acheive a higher
	quality tessellation (i.e. a tessellation without skinny
	triangles). This attribute controls how many points are
	allowed to be added.  This attribute can also be used
	to control the number of triangles.
	*/
	IntID getMaxPointsAdded(){char buffer[4096];sprintf_s (buffer, "%s.mpa",mName.c_str());return (const char*)buffer;}
	/*Script to be called when shader assignment needs to be done.*/
	StringID getShaderScript(){char buffer[4096];sprintf_s (buffer, "%s.shs",mName.c_str());return (const char*)buffer;}
protected:
	TextureToGeom(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TEXTURETOGEOM_H__
