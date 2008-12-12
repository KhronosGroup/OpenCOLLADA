/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRANSFORMGEOMETRY_H__
#define __MayaDM_TRANSFORMGEOMETRY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The 'transformGeometry' node applies the transformation
 at the input attribute 'transform' on to the geometry at
 the attribute 'inputGeometry' and computes as result the
 transformed geometry.
 <p/>
 The input geometry could be a NURBS surface, NURBS curve
 or mesh data.
 <p/>
 Using the attribute 'invertTransform' the user may choose to
 invert the transform before applying it on to the input
 geometry.
*/
class TransformGeometry : public AbstractBaseCreate
{
public:
public:
	TransformGeometry(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "transformGeometry"){}
	virtual ~TransformGeometry(){}
	/*The input geometry to be transformed.*/
	void setInputGeometry(const GenericID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ig\";\n",mName.c_str());}
	/*The transform to be applied on geometry.*/
	void setTransform(const matrix& txf){if(txf == identity) return; fprintf_s(mFile, "setAttr \".txf\" -type \"matrix\" ");txf.write(mFile);fprintf_s(mFile,";\n");}
	/*The transform to be applied on geometry.*/
	void setTransform(const MatrixID& txf){fprintf_s(mFile,"connectAttr \"");txf.write(mFile);fprintf_s(mFile,"\" \"%s.txf\";\n",mName.c_str());}
	/*Invert transform before applying on input geometry.*/
	void setInvertTransform(bool itf){if(itf == false) return; fprintf_s(mFile, "setAttr \".itf\" %i;\n", itf);}
	/*Invert transform before applying on input geometry.*/
	void setInvertTransform(const BoolID& itf){fprintf_s(mFile,"connectAttr \"");itf.write(mFile);fprintf_s(mFile,"\" \"%s.itf\";\n",mName.c_str());}
	/*
	Controls if the normals of the geometry should be frozen or not.
	Applies only to polygonal objects.
	*/
	void setFreezeNormals(unsigned int fn){if(fn == 0) return; fprintf_s(mFile, "setAttr \".fn\" %i;\n", fn);}
	/*
	Controls if the normals of the geometry should be frozen or not.
	Applies only to polygonal objects.
	*/
	void setFreezeNormals(const UnsignedintID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn\";\n",mName.c_str());}
	/*The ouput transformed geometry.*/
	void setOutputGeometry(const GenericID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og\";\n",mName.c_str());}
	/*The input geometry to be transformed.*/
	GenericID getInputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.ig",mName.c_str());return (const char*)buffer;}
	/*The transform to be applied on geometry.*/
	MatrixID getTransform(){char buffer[4096];sprintf_s (buffer, "%s.txf",mName.c_str());return (const char*)buffer;}
	/*Invert transform before applying on input geometry.*/
	BoolID getInvertTransform(){char buffer[4096];sprintf_s (buffer, "%s.itf",mName.c_str());return (const char*)buffer;}
	/*
	Controls if the normals of the geometry should be frozen or not.
	Applies only to polygonal objects.
	*/
	UnsignedintID getFreezeNormals(){char buffer[4096];sprintf_s (buffer, "%s.fn",mName.c_str());return (const char*)buffer;}
	/*The ouput transformed geometry.*/
	GenericID getOutputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.og",mName.c_str());return (const char*)buffer;}
protected:
	TransformGeometry(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TRANSFORMGEOMETRY_H__
