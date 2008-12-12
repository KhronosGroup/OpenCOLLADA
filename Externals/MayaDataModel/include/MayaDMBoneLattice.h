/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BONELATTICE_H__
#define __MayaDM_BONELATTICE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
/*
This node takes lattice points as input and deforms them
based on the high-level parameter settings controlling how the
lattice bulges along a bone.
*/
class BoneLattice : public GeometryFilter
{
public:
public:
	BoneLattice(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "boneLattice"){}
	virtual ~BoneLattice(){}
	/*The amount of bicep (front of bone) bulging to apply.*/
	void setBicep(double bi){if(bi == 0) return; fprintf_s(mFile, "setAttr \".bi\" %f;\n", bi);}
	/*The amount of bicep (front of bone) bulging to apply.*/
	void setBicep(const DoubleID& bi){fprintf_s(mFile,"connectAttr \"");bi.write(mFile);fprintf_s(mFile,"\" \"%s.bi\";\n",mName.c_str());}
	/*The amount of tricep (back of bone) bulging to apply.*/
	void setTricep(double tr){if(tr == 0) return; fprintf_s(mFile, "setAttr \".tr\" %f;\n", tr);}
	/*The amount of tricep (back of bone) bulging to apply.*/
	void setTricep(const DoubleID& tr){fprintf_s(mFile,"connectAttr \"");tr.write(mFile);fprintf_s(mFile,"\" \"%s.tr\";\n",mName.c_str());}
	/*Controls how far the bulge extends toward the upper joint.*/
	void setLengthIn(double li){if(li == 0) return; fprintf_s(mFile, "setAttr \".li\" %f;\n", li);}
	/*Controls how far the bulge extends toward the upper joint.*/
	void setLengthIn(const DoubleID& li){fprintf_s(mFile,"connectAttr \"");li.write(mFile);fprintf_s(mFile,"\" \"%s.li\";\n",mName.c_str());}
	/*Controls how far the bulge extends toward the lower joint.*/
	void setLengthOut(double lo){if(lo == 0) return; fprintf_s(mFile, "setAttr \".lo\" %f;\n", lo);}
	/*Controls how far the bulge extends toward the lower joint.*/
	void setLengthOut(const DoubleID& lo){fprintf_s(mFile,"connectAttr \"");lo.write(mFile);fprintf_s(mFile,"\" \"%s.lo\";\n",mName.c_str());}
	/*Controls how far the bulge extends to the left side of the bone.*/
	void setWidthLeft(double wl){if(wl == 0) return; fprintf_s(mFile, "setAttr \".wl\" %f;\n", wl);}
	/*Controls how far the bulge extends to the left side of the bone.*/
	void setWidthLeft(const DoubleID& wl){fprintf_s(mFile,"connectAttr \"");wl.write(mFile);fprintf_s(mFile,"\" \"%s.wl\";\n",mName.c_str());}
	/*Controls how far the bulge extends to the right side of the bone.*/
	void setWidthRight(double wr){if(wr == 0) return; fprintf_s(mFile, "setAttr \".wr\" %f;\n", wr);}
	/*Controls how far the bulge extends to the right side of the bone.*/
	void setWidthRight(const DoubleID& wr){fprintf_s(mFile,"connectAttr \"");wr.write(mFile);fprintf_s(mFile,"\" \"%s.wr\";\n",mName.c_str());}
	/*The world matrix of the upper bone.*/
	void setUpperMatrix(const matrix& um){if(um == identity) return; fprintf_s(mFile, "setAttr \".um\" -type \"matrix\" ");um.write(mFile);fprintf_s(mFile,";\n");}
	/*The world matrix of the upper bone.*/
	void setUpperMatrix(const MatrixID& um){fprintf_s(mFile,"connectAttr \"");um.write(mFile);fprintf_s(mFile,"\" \"%s.um\";\n",mName.c_str());}
	/*The bind pose world matrix of the upper bone.*/
	void setInitialUpperMatrix(const matrix& ui){if(ui == identity) return; fprintf_s(mFile, "setAttr \".ui\" -type \"matrix\" ");ui.write(mFile);fprintf_s(mFile,";\n");}
	/*The bind pose world matrix of the upper bone.*/
	void setInitialUpperMatrix(const MatrixID& ui){fprintf_s(mFile,"connectAttr \"");ui.write(mFile);fprintf_s(mFile,"\" \"%s.ui\";\n",mName.c_str());}
	/*The "bind pose" world matrix of the deformed lattice.*/
	void setDeformedLatticeMatrix(const matrix& md){if(md == identity) return; fprintf_s(mFile, "setAttr \".md\" -type \"matrix\" ");md.write(mFile);fprintf_s(mFile,";\n");}
	/*The "bind pose" world matrix of the deformed lattice.*/
	void setDeformedLatticeMatrix(const MatrixID& md){fprintf_s(mFile,"connectAttr \"");md.write(mFile);fprintf_s(mFile,"\" \"%s.md\";\n",mName.c_str());}
	/*The "bind pose" world matrix of the base lattice.*/
	void setBaseLatticeMatrix(const matrix& mb){if(mb == identity) return; fprintf_s(mFile, "setAttr \".mb\" -type \"matrix\" ");mb.write(mFile);fprintf_s(mFile,";\n");}
	/*The "bind pose" world matrix of the base lattice.*/
	void setBaseLatticeMatrix(const MatrixID& mb){fprintf_s(mFile,"connectAttr \"");mb.write(mFile);fprintf_s(mFile,"\" \"%s.mb\";\n",mName.c_str());}
	/*Repositions base lattice to keep it aligned with the upper bone*/
	void setAdjustedUpperBaseLatticeMatrix(const MatrixID& au){fprintf_s(mFile,"connectAttr \"");au.write(mFile);fprintf_s(mFile,"\" \"%s.au\";\n",mName.c_str());}
	/*Bisector of a vector representation of the upper/lower bones.*/
	void setBendVector(const float3& bv){fprintf_s(mFile, "setAttr \".bv\" -type \"float3\" ");bv.write(mFile);fprintf_s(mFile,";\n");}
	/*Bisector of a vector representation of the upper/lower bones.*/
	void setBendVector(const Float3ID& bv){fprintf_s(mFile,"connectAttr \"");bv.write(mFile);fprintf_s(mFile,"\" \"%s.bv\";\n",mName.c_str());}
	/*Bend vector X value.*/
	void setBendVectorX(float bx){if(bx == 0.0) return; fprintf_s(mFile, "setAttr \".bv.bx\" %f;\n", bx);}
	/*Bend vector X value.*/
	void setBendVectorX(const FloatID& bx){fprintf_s(mFile,"connectAttr \"");bx.write(mFile);fprintf_s(mFile,"\" \"%s.bv.bx\";\n",mName.c_str());}
	/*Bend vector Y value.*/
	void setBendVectorY(float by){if(by == 0.0) return; fprintf_s(mFile, "setAttr \".bv.by\" %f;\n", by);}
	/*Bend vector Y value.*/
	void setBendVectorY(const FloatID& by){fprintf_s(mFile,"connectAttr \"");by.write(mFile);fprintf_s(mFile,"\" \"%s.bv.by\";\n",mName.c_str());}
	/*Bend vector Z value.*/
	void setBendVectorZ(float bz){if(bz == 0.0) return; fprintf_s(mFile, "setAttr \".bv.bz\" %f;\n", bz);}
	/*Bend vector Z value.*/
	void setBendVectorZ(const FloatID& bz){fprintf_s(mFile,"connectAttr \"");bz.write(mFile);fprintf_s(mFile,"\" \"%s.bv.bz\";\n",mName.c_str());}
	/*Specifies how much effect the 6 high level behavior parameters have.*/
	void setBendMagnitude(double bm){if(bm == 0) return; fprintf_s(mFile, "setAttr \".bm\" %f;\n", bm);}
	/*Specifies how much effect the 6 high level behavior parameters have.*/
	void setBendMagnitude(const DoubleID& bm){fprintf_s(mFile,"connectAttr \"");bm.write(mFile);fprintf_s(mFile,"\" \"%s.bm\";\n",mName.c_str());}
	/*The amount of bicep (front of bone) bulging to apply.*/
	DoubleID getBicep(){char buffer[4096];sprintf_s (buffer, "%s.bi",mName.c_str());return (const char*)buffer;}
	/*The amount of tricep (back of bone) bulging to apply.*/
	DoubleID getTricep(){char buffer[4096];sprintf_s (buffer, "%s.tr",mName.c_str());return (const char*)buffer;}
	/*Controls how far the bulge extends toward the upper joint.*/
	DoubleID getLengthIn(){char buffer[4096];sprintf_s (buffer, "%s.li",mName.c_str());return (const char*)buffer;}
	/*Controls how far the bulge extends toward the lower joint.*/
	DoubleID getLengthOut(){char buffer[4096];sprintf_s (buffer, "%s.lo",mName.c_str());return (const char*)buffer;}
	/*Controls how far the bulge extends to the left side of the bone.*/
	DoubleID getWidthLeft(){char buffer[4096];sprintf_s (buffer, "%s.wl",mName.c_str());return (const char*)buffer;}
	/*Controls how far the bulge extends to the right side of the bone.*/
	DoubleID getWidthRight(){char buffer[4096];sprintf_s (buffer, "%s.wr",mName.c_str());return (const char*)buffer;}
	/*The world matrix of the upper bone.*/
	MatrixID getUpperMatrix(){char buffer[4096];sprintf_s (buffer, "%s.um",mName.c_str());return (const char*)buffer;}
	/*The bind pose world matrix of the upper bone.*/
	MatrixID getInitialUpperMatrix(){char buffer[4096];sprintf_s (buffer, "%s.ui",mName.c_str());return (const char*)buffer;}
	/*The "bind pose" world matrix of the deformed lattice.*/
	MatrixID getDeformedLatticeMatrix(){char buffer[4096];sprintf_s (buffer, "%s.md",mName.c_str());return (const char*)buffer;}
	/*The "bind pose" world matrix of the base lattice.*/
	MatrixID getBaseLatticeMatrix(){char buffer[4096];sprintf_s (buffer, "%s.mb",mName.c_str());return (const char*)buffer;}
	/*Repositions base lattice to keep it aligned with the upper bone*/
	MatrixID getAdjustedUpperBaseLatticeMatrix(){char buffer[4096];sprintf_s (buffer, "%s.au",mName.c_str());return (const char*)buffer;}
	/*Bisector of a vector representation of the upper/lower bones.*/
	Float3ID getBendVector(){char buffer[4096];sprintf_s (buffer, "%s.bv",mName.c_str());return (const char*)buffer;}
	/*Bend vector X value.*/
	FloatID getBendVectorX(){char buffer[4096];sprintf_s (buffer, "%s.bv.bx",mName.c_str());return (const char*)buffer;}
	/*Bend vector Y value.*/
	FloatID getBendVectorY(){char buffer[4096];sprintf_s (buffer, "%s.bv.by",mName.c_str());return (const char*)buffer;}
	/*Bend vector Z value.*/
	FloatID getBendVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.bv.bz",mName.c_str());return (const char*)buffer;}
	/*Specifies how much effect the 6 high level behavior parameters have.*/
	DoubleID getBendMagnitude(){char buffer[4096];sprintf_s (buffer, "%s.bm",mName.c_str());return (const char*)buffer;}
protected:
	BoneLattice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BONELATTICE_H__
