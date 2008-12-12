/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANNOTATIONSHAPE_H__
#define __MayaDM_ANNOTATIONSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDimensionShape.h"
namespace MayaDM
{
/*
<p><pre>  Node to hold annotation strings placed in the 3d scene.
</pre></p>
*/
class AnnotationShape : public DimensionShape
{
public:
public:
	AnnotationShape(FILE* file,const std::string& name,const std::string& parent=""):DimensionShape(file, name, parent, "annotationShape"){}
	virtual ~AnnotationShape(){}
	/*Annotation text*/
	void setText(const string& txt){if(txt == "NULL") return; fprintf_s(mFile, "setAttr \".txt\" -type \"string\" ");txt.write(mFile);fprintf_s(mFile,";\n");}
	/*Annotation text*/
	void setText(const StringID& txt){fprintf_s(mFile,"connectAttr \"");txt.write(mFile);fprintf_s(mFile,"\" \"%s.txt\";\n",mName.c_str());}
	/*Obsolete; the annotation takes its position from its transform node.*/
	void setPosition(const Double3ID& tp){fprintf_s(mFile,"connectAttr \"");tp.write(mFile);fprintf_s(mFile,"\" \"%s.tp\";\n",mName.c_str());}
	/*Obsolete; the annotation takes its position from its transform node.*/
	void setPositionX(const DoubleID& tpx){fprintf_s(mFile,"connectAttr \"");tpx.write(mFile);fprintf_s(mFile,"\" \"%s.tp.tpx\";\n",mName.c_str());}
	/*Obsolete; the annotation takes its position from its transform node.*/
	void setPositionY(const DoubleID& tpy){fprintf_s(mFile,"connectAttr \"");tpy.write(mFile);fprintf_s(mFile,"\" \"%s.tp.tpy\";\n",mName.c_str());}
	/*Obsolete; the annotation takes its position from its transform node.*/
	void setPositionZ(const DoubleID& tpz){fprintf_s(mFile,"connectAttr \"");tpz.write(mFile);fprintf_s(mFile,"\" \"%s.tp.tpz\";\n",mName.c_str());}
	/*Instance of dag object the annotation is attached to*/
	void setDagObjectMatrix(size_t dom_i,const matrix& dom){if(dom == identity) return; fprintf_s(mFile, "setAttr \".dom[%i]\" -type \"matrix\" ",dom_i);dom.write(mFile);fprintf_s(mFile,";\n");}
	/*The toggle for displaying the line and arrow*/
	void setDisplayArrow(bool daro){if(daro == true) return; fprintf_s(mFile, "setAttr \".daro\" %i;\n", daro);}
	/*The toggle for displaying the line and arrow*/
	void setDisplayArrow(const BoolID& daro){fprintf_s(mFile,"connectAttr \"");daro.write(mFile);fprintf_s(mFile,"\" \"%s.daro\";\n",mName.c_str());}
	/*Annotation text*/
	StringID getText(){char buffer[4096];sprintf_s (buffer, "%s.txt",mName.c_str());return (const char*)buffer;}
	/*Obsolete; the annotation takes its position from its transform node.*/
	Double3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.tp",mName.c_str());return (const char*)buffer;}
	/*Obsolete; the annotation takes its position from its transform node.*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.tp.tpx",mName.c_str());return (const char*)buffer;}
	/*Obsolete; the annotation takes its position from its transform node.*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.tp.tpy",mName.c_str());return (const char*)buffer;}
	/*Obsolete; the annotation takes its position from its transform node.*/
	DoubleID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.tp.tpz",mName.c_str());return (const char*)buffer;}
	/*The toggle for displaying the line and arrow*/
	BoolID getDisplayArrow(){char buffer[4096];sprintf_s (buffer, "%s.daro",mName.c_str());return (const char*)buffer;}
protected:
	AnnotationShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DimensionShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ANNOTATIONSHAPE_H__
