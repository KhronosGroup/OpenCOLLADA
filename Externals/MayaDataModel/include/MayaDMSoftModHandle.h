/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SOFTMODHANDLE_H__
#define __MayaDM_SOFTMODHANDLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
This node represents the handle by which a softMod's transformations
 can be manipulated.
 It is primarily just a way of selecting the softMod in the scene,
 though it also stores the transformation information needed for
 the softMod's deformation.
*/
class SoftModHandle : public Shape
{
public:
	/*Bundled transformation matrices for the softMod deformation.*/
	struct SoftModTransforms{
		void write(FILE* file) const
		{
		}
	};
public:
	SoftModHandle(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "softModHandle"){}
	virtual ~SoftModHandle(){}
	/*Bundled transformation matrices for the softMod deformation.*/
	void setSoftModTransforms(size_t x_i,const SoftModTransformsID& x){fprintf_s(mFile,"connectAttr \"");x.write(mFile);fprintf_s(mFile,"\" \"%s.x[%i]\";\n",mName.c_str(),x_i);}
	/*Represents the transformation in the DAG above the weighted node.*/
	void setPreWeightedMatrixTransform(size_t x_i,const MatrixID& pre){fprintf_s(mFile,"connectAttr \"");pre.write(mFile);fprintf_s(mFile,"\" \"%s.x[%i].pre\";\n",mName.c_str(),x_i);}
	/*The transformation of the weighted node.*/
	void setWeightedMatrixTransform(size_t x_i,const MatrixID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.x[%i].wt\";\n",mName.c_str(),x_i);}
	/*Represents the transformation in the DAG below the weighted node.*/
	void setPostWeightedMatrixTransform(size_t x_i,const MatrixID& post){fprintf_s(mFile,"connectAttr \"");post.write(mFile);fprintf_s(mFile,"\" \"%s.x[%i].post\";\n",mName.c_str(),x_i);}
	/*The location in local space of the displayed 'C' icon.*/
	void setOrigin(const double3& or){fprintf_s(mFile, "setAttr \".or\" -type \"double3\" ");or.write(mFile);fprintf_s(mFile,";\n");}
	/*The location in local space of the displayed 'C' icon.*/
	void setOrigin(const Double3ID& or){fprintf_s(mFile,"connectAttr \"");or.write(mFile);fprintf_s(mFile,"\" \"%s.or\";\n",mName.c_str());}
	/*X position of the displayed 'C' icon.*/
	void setOriginX(double ox){if(ox == 0) return; fprintf_s(mFile, "setAttr \".or.ox\" %f;\n", ox);}
	/*X position of the displayed 'C' icon.*/
	void setOriginX(const DoubleID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.or.ox\";\n",mName.c_str());}
	/*Y position of the displayed 'C' icon.*/
	void setOriginY(double oy){if(oy == 0) return; fprintf_s(mFile, "setAttr \".or.oy\" %f;\n", oy);}
	/*Y position of the displayed 'C' icon.*/
	void setOriginY(const DoubleID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.or.oy\";\n",mName.c_str());}
	/*Z position of the displayed 'C' icon.*/
	void setOriginZ(double oz){if(oz == 0) return; fprintf_s(mFile, "setAttr \".or.oz\" %f;\n", oz);}
	/*Z position of the displayed 'C' icon.*/
	void setOriginZ(const DoubleID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.or.oz\";\n",mName.c_str());}
	/*Bundled transformation matrices for the softMod deformation.*/
	const SoftModTransformsID& getSoftModTransforms(size_t x_i){char buffer[4096];sprintf_s (buffer, "%s.x[%i]",mName.c_str(),x_i);return (const char*)buffer;}
	/*Represents the transformation in the DAG above the weighted node.*/
	const MatrixID& getPreWeightedMatrixTransform(size_t x_i){char buffer[4096];sprintf_s (buffer, "%s.x[%i].pre",mName.c_str(),x_i);return (const char*)buffer;}
	/*The transformation of the weighted node.*/
	const MatrixID& getWeightedMatrixTransform(size_t x_i){char buffer[4096];sprintf_s (buffer, "%s.x[%i].wt",mName.c_str(),x_i);return (const char*)buffer;}
	/*Represents the transformation in the DAG below the weighted node.*/
	const MatrixID& getPostWeightedMatrixTransform(size_t x_i){char buffer[4096];sprintf_s (buffer, "%s.x[%i].post",mName.c_str(),x_i);return (const char*)buffer;}
	/*The location in local space of the displayed 'C' icon.*/
	Double3ID getOrigin(){char buffer[4096];sprintf_s (buffer, "%s.or",mName.c_str());return (const char*)buffer;}
	/*X position of the displayed 'C' icon.*/
	DoubleID getOriginX(){char buffer[4096];sprintf_s (buffer, "%s.or.ox",mName.c_str());return (const char*)buffer;}
	/*Y position of the displayed 'C' icon.*/
	DoubleID getOriginY(){char buffer[4096];sprintf_s (buffer, "%s.or.oy",mName.c_str());return (const char*)buffer;}
	/*Z position of the displayed 'C' icon.*/
	DoubleID getOriginZ(){char buffer[4096];sprintf_s (buffer, "%s.or.oz",mName.c_str());return (const char*)buffer;}
protected:
	SoftModHandle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SOFTMODHANDLE_H__
