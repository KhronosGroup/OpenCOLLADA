/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FFD_H__
#define __MayaDM_FFD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
/*
This node deforms the components of an input object or
objects according to the freeform deformation (FFD) algorithm.
The algorithm is a spatial deformation which takes objects located
within the base (undeformed) lattice and maps them into the space of the
deformed lattice shape.
<p/>
If the input object is not located within the base lattice, no deformation
will occur, unless the freezeGeometry attribute is set to <em>on</em>, and
the object was within the lattice when the freezing was turned on.
<p/>
The local axes of the lattice are referred to below as "s", "t" and "u".
*/
class Ffd : public GeometryFilter
{
public:
	/*Bundled lattice points and lattice world matrix.*/
	struct DeformedLattice{
		lattice deformedLatticePoints;
		matrix deformedLatticeMatrix;
		void write(FILE* file) const
		{
			deformedLatticePoints.write(file);
			fprintf_s(file, " ");
			deformedLatticeMatrix.write(file);
		}
	};
	/*Bundled base lattice points and base lattice world matrix.*/
	struct BaseLattice{
		lattice baseLatticePoints;
		matrix baseLatticeMatrix;
		void write(FILE* file) const
		{
			baseLatticePoints.write(file);
			fprintf_s(file, " ");
			baseLatticeMatrix.write(file);
		}
	};
	/*List of stu caches, one per geometry.*/
	struct StuCacheList{
		double* stuCache;
		void write(FILE* file) const
		{
			size_t size = sizeof(stuCache)/sizeof(double);
			for(size_t i=0; i<size; ++i)
			{
				fprintf_s(file,"%f", stuCache[i]);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	Ffd(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "ffd"){}
	virtual ~Ffd(){}
	/*Bundled lattice points and lattice world matrix.*/
	void setDeformedLattice(const DeformedLattice& dl){fprintf_s(mFile, "setAttr \".dl\" ");dl.write(mFile);fprintf_s(mFile,";\n");}
	/*Bundled lattice points and lattice world matrix.*/
	void setDeformedLattice(const DeformedLatticeID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*The points of the deformed lattice.*/
	void setDeformedLatticePoints(const lattice& dlp){fprintf_s(mFile, "setAttr \".dl.dlp\" -type \"lattice\" ");dlp.write(mFile);fprintf_s(mFile,";\n");}
	/*The points of the deformed lattice.*/
	void setDeformedLatticePoints(const LatticeID& dlp){fprintf_s(mFile,"connectAttr \"");dlp.write(mFile);fprintf_s(mFile,"\" \"%s.dl.dlp\";\n",mName.c_str());}
	/*The world matrix of the deformed lattice.*/
	void setDeformedLatticeMatrix(const matrix& dlm){if(dlm == identity) return; fprintf_s(mFile, "setAttr \".dl.dlm\" -type \"matrix\" ");dlm.write(mFile);fprintf_s(mFile,";\n");}
	/*The world matrix of the deformed lattice.*/
	void setDeformedLatticeMatrix(const MatrixID& dlm){fprintf_s(mFile,"connectAttr \"");dlm.write(mFile);fprintf_s(mFile,"\" \"%s.dl.dlm\";\n",mName.c_str());}
	/*Bundled base lattice points and base lattice world matrix.*/
	void setBaseLattice(const BaseLattice& bl){fprintf_s(mFile, "setAttr \".bl\" ");bl.write(mFile);fprintf_s(mFile,";\n");}
	/*Bundled base lattice points and base lattice world matrix.*/
	void setBaseLattice(const BaseLatticeID& bl){fprintf_s(mFile,"connectAttr \"");bl.write(mFile);fprintf_s(mFile,"\" \"%s.bl\";\n",mName.c_str());}
	/*The points of the base lattice.*/
	void setBaseLatticePoints(const lattice& blp){fprintf_s(mFile, "setAttr \".bl.blp\" -type \"lattice\" ");blp.write(mFile);fprintf_s(mFile,";\n");}
	/*The points of the base lattice.*/
	void setBaseLatticePoints(const LatticeID& blp){fprintf_s(mFile,"connectAttr \"");blp.write(mFile);fprintf_s(mFile,"\" \"%s.bl.blp\";\n",mName.c_str());}
	/*The world matrix of the base lattice.*/
	void setBaseLatticeMatrix(const matrix& blm){if(blm == identity) return; fprintf_s(mFile, "setAttr \".bl.blm\" -type \"matrix\" ");blm.write(mFile);fprintf_s(mFile,";\n");}
	/*The world matrix of the base lattice.*/
	void setBaseLatticeMatrix(const MatrixID& blm){fprintf_s(mFile,"connectAttr \"");blm.write(mFile);fprintf_s(mFile,"\" \"%s.bl.blm\";\n",mName.c_str());}
	/*List of stu caches, one per geometry.*/
	void setStuCacheList(size_t scl_i,const StuCacheList& scl){fprintf_s(mFile, "setAttr \".scl[%i]\" ",scl_i);scl.write(mFile);fprintf_s(mFile,";\n");}
	/*List of stu caches, one per geometry.*/
	void setStuCacheList(size_t scl_i,const StuCacheListID& scl){fprintf_s(mFile,"connectAttr \"");scl.write(mFile);fprintf_s(mFile,"\" \"%s.scl[%i]\";\n",mName.c_str(),scl_i);}
	/*
	Cache of the stu points at lattice creation time.
	This is used internally by this node when freezeGeometry is turned on,
	to remember where each component of each deforming object was
	when the freezing was turned on.
	Any attempt to modify this attribute can cause unpredictable results.
	*/
	void setStuCache(size_t scl_i,size_t stu_i,double stu){if(stu == 0) return; fprintf_s(mFile, "setAttr \".scl[%i].stu[%i]\" %f;\n", scl_i,stu_i,stu);}
	/*
	Cache of the stu points at lattice creation time.
	This is used internally by this node when freezeGeometry is turned on,
	to remember where each component of each deforming object was
	when the freezing was turned on.
	Any attempt to modify this attribute can cause unpredictable results.
	*/
	void setStuCache(size_t scl_i,size_t stu_i,const DoubleID& stu){fprintf_s(mFile,"connectAttr \"");stu.write(mFile);fprintf_s(mFile,"\" \"%s.scl[%i].stu[%i]\";\n",mName.c_str(),scl_i,stu_i);}
	/*
	Partial resolution to use.
	If usePartialResolution is turned on, this attribute controls
	the extent to which the accuracy of the deformation should be
	compromised in favor of achieving a faster result.
	*/
	void setPartialResolution(double ptr){if(ptr == 0.01) return; fprintf_s(mFile, "setAttr \".ptr\" %f;\n", ptr);}
	/*
	Partial resolution to use.
	If usePartialResolution is turned on, this attribute controls
	the extent to which the accuracy of the deformation should be
	compromised in favor of achieving a faster result.
	*/
	void setPartialResolution(const DoubleID& ptr){fprintf_s(mFile,"connectAttr \"");ptr.write(mFile);fprintf_s(mFile,"\" \"%s.ptr\";\n",mName.c_str());}
	/*
	If localCompute is turned on, this is the extent of the region
	of effect in the s direction
	*/
	void setLocalInfluenceS(short lis){if(lis == 2) return; fprintf_s(mFile, "setAttr \".lis\" %i;\n", lis);}
	/*
	If localCompute is turned on, this is the extent of the region
	of effect in the s direction
	*/
	void setLocalInfluenceS(const ShortID& lis){fprintf_s(mFile,"connectAttr \"");lis.write(mFile);fprintf_s(mFile,"\" \"%s.lis\";\n",mName.c_str());}
	/*
	If localCompute is turned on, this is the extent of the region
	of effect in the t direction
	*/
	void setLocalInfluenceT(short lit){if(lit == 2) return; fprintf_s(mFile, "setAttr \".lit\" %i;\n", lit);}
	/*
	If localCompute is turned on, this is the extent of the region
	of effect in the t direction
	*/
	void setLocalInfluenceT(const ShortID& lit){fprintf_s(mFile,"connectAttr \"");lit.write(mFile);fprintf_s(mFile,"\" \"%s.lit\";\n",mName.c_str());}
	/*
	If localCompute is turned on, this is the extent of the region
	of effect in the u direction
	*/
	void setLocalInfluenceU(short liu){if(liu == 2) return; fprintf_s(mFile, "setAttr \".liu\" %i;\n", liu);}
	/*
	If localCompute is turned on, this is the extent of the region
	of effect in the u direction
	*/
	void setLocalInfluenceU(const ShortID& liu){fprintf_s(mFile,"connectAttr \"");liu.write(mFile);fprintf_s(mFile,"\" \"%s.liu\";\n",mName.c_str());}
	/*
	Lattice mapping is frozen when the state of this variable is toggled on.
	This means that movement of the deforming geometry relative
	to the base lattice will be ignored for purposes of determining how
	the lattice affects the geometry.
	*/
	void setFreezeGeometry(bool fg){if(fg == 0) return; fprintf_s(mFile, "setAttr \".fg\" %i;\n", fg);}
	/*
	Lattice mapping is frozen when the state of this variable is toggled on.
	This means that movement of the deforming geometry relative
	to the base lattice will be ignored for purposes of determining how
	the lattice affects the geometry.
	*/
	void setFreezeGeometry(const BoolID& fg){fprintf_s(mFile,"connectAttr \"");fg.write(mFile);fprintf_s(mFile,"\" \"%s.fg\";\n",mName.c_str());}
	/*
	Controls whether movement of each lattice point has a global effect
	(all deforming components are affected to some extent by every
	lattice point) or a local effect (only those components "near" the
	moved lattice points are affected). When local mode is turned on,
	the attributes localInfluenceS, localInfluenceT and localInfluenceU
	control the extent of the local effect along each of the axes
	of the lattice.
	*/
	void setLocal(bool lo){if(lo == 0) return; fprintf_s(mFile, "setAttr \".lo\" %i;\n", lo);}
	/*
	Controls whether movement of each lattice point has a global effect
	(all deforming components are affected to some extent by every
	lattice point) or a local effect (only those components "near" the
	moved lattice points are affected). When local mode is turned on,
	the attributes localInfluenceS, localInfluenceT and localInfluenceU
	control the extent of the local effect along each of the axes
	of the lattice.
	*/
	void setLocal(const BoolID& lo){fprintf_s(mFile,"connectAttr \"");lo.write(mFile);fprintf_s(mFile,"\" \"%s.lo\";\n",mName.c_str());}
	/*
	Whether or not to use the partial resolution.
	When this is off, the deformation is computed exactly.
	Valid values are 0 = "full", 1 = "partial".
	*/
	void setUsePartialResolution(unsigned int upr){if(upr == 0) return; fprintf_s(mFile, "setAttr \".upr\" %i;\n", upr);}
	/*
	Whether or not to use the partial resolution.
	When this is off, the deformation is computed exactly.
	Valid values are 0 = "full", 1 = "partial".
	*/
	void setUsePartialResolution(const UnsignedintID& upr){fprintf_s(mFile,"connectAttr \"");upr.write(mFile);fprintf_s(mFile,"\" \"%s.upr\";\n",mName.c_str());}
	/*
	Whether or not to transform geometry which falls outside of the
	base lattice. If 0 (the default), points outside the base lattice
	are not transformed, thus if an animated point happens to stray outside
	the base lattice, it will suddenly stop being deformed. If 1, then
	all points outside the base lattice are transformed. If 2, then all
	points outside the lattice but within the outsideFalloffDist
	distance are transformed using a linear falloff as distance increases
	from the base lattice.
	*/
	void setOutsideLattice(unsigned int ot){if(ot == 0) return; fprintf_s(mFile, "setAttr \".ot\" %i;\n", ot);}
	/*
	Whether or not to transform geometry which falls outside of the
	base lattice. If 0 (the default), points outside the base lattice
	are not transformed, thus if an animated point happens to stray outside
	the base lattice, it will suddenly stop being deformed. If 1, then
	all points outside the base lattice are transformed. If 2, then all
	points outside the lattice but within the outsideFalloffDist
	distance are transformed using a linear falloff as distance increases
	from the base lattice.
	*/
	void setOutsideLattice(const UnsignedintID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*
	When outsideLattice is 2, this parameter provides a distance
	within which points outside of the base lattice are transformed.
	The distance is a multiple of the width of the base lattice, thus a value
	of 0.0 causes no points outside the base lattice to be transformed,
	a value of 1.0 affects points up to the width of the base lattice to
	be transformed, and so on.
	*/
	void setOutsideFalloffDist(double ofd){if(ofd == 1.0) return; fprintf_s(mFile, "setAttr \".ofd\" %f;\n", ofd);}
	/*
	When outsideLattice is 2, this parameter provides a distance
	within which points outside of the base lattice are transformed.
	The distance is a multiple of the width of the base lattice, thus a value
	of 0.0 causes no points outside the base lattice to be transformed,
	a value of 1.0 affects points up to the width of the base lattice to
	be transformed, and so on.
	*/
	void setOutsideFalloffDist(const DoubleID& ofd){fprintf_s(mFile,"connectAttr \"");ofd.write(mFile);fprintf_s(mFile,"\" \"%s.ofd\";\n",mName.c_str());}
	/*Bundled lattice points and lattice world matrix.*/
	DeformedLatticeID getDeformedLattice(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*The points of the deformed lattice.*/
	LatticeID getDeformedLatticePoints(){char buffer[4096];sprintf_s (buffer, "%s.dl.dlp",mName.c_str());return (const char*)buffer;}
	/*The world matrix of the deformed lattice.*/
	MatrixID getDeformedLatticeMatrix(){char buffer[4096];sprintf_s (buffer, "%s.dl.dlm",mName.c_str());return (const char*)buffer;}
	/*Bundled base lattice points and base lattice world matrix.*/
	BaseLatticeID getBaseLattice(){char buffer[4096];sprintf_s (buffer, "%s.bl",mName.c_str());return (const char*)buffer;}
	/*The points of the base lattice.*/
	LatticeID getBaseLatticePoints(){char buffer[4096];sprintf_s (buffer, "%s.bl.blp",mName.c_str());return (const char*)buffer;}
	/*The world matrix of the base lattice.*/
	MatrixID getBaseLatticeMatrix(){char buffer[4096];sprintf_s (buffer, "%s.bl.blm",mName.c_str());return (const char*)buffer;}
	/*List of stu caches, one per geometry.*/
	const StuCacheListID& getStuCacheList(size_t scl_i){char buffer[4096];sprintf_s (buffer, "%s.scl[%i]",mName.c_str(),scl_i);return (const char*)buffer;}
	/*
	Cache of the stu points at lattice creation time.
	This is used internally by this node when freezeGeometry is turned on,
	to remember where each component of each deforming object was
	when the freezing was turned on.
	Any attempt to modify this attribute can cause unpredictable results.
	*/
	const DoubleID& getStuCache(size_t scl_i,size_t stu_i){char buffer[4096];sprintf_s (buffer, "%s.scl[%i].stu[%i]",mName.c_str(),scl_i,stu_i);return (const char*)buffer;}
	/*
	Partial resolution to use.
	If usePartialResolution is turned on, this attribute controls
	the extent to which the accuracy of the deformation should be
	compromised in favor of achieving a faster result.
	*/
	DoubleID getPartialResolution(){char buffer[4096];sprintf_s (buffer, "%s.ptr",mName.c_str());return (const char*)buffer;}
	/*
	If localCompute is turned on, this is the extent of the region
	of effect in the s direction
	*/
	ShortID getLocalInfluenceS(){char buffer[4096];sprintf_s (buffer, "%s.lis",mName.c_str());return (const char*)buffer;}
	/*
	If localCompute is turned on, this is the extent of the region
	of effect in the t direction
	*/
	ShortID getLocalInfluenceT(){char buffer[4096];sprintf_s (buffer, "%s.lit",mName.c_str());return (const char*)buffer;}
	/*
	If localCompute is turned on, this is the extent of the region
	of effect in the u direction
	*/
	ShortID getLocalInfluenceU(){char buffer[4096];sprintf_s (buffer, "%s.liu",mName.c_str());return (const char*)buffer;}
	/*
	Lattice mapping is frozen when the state of this variable is toggled on.
	This means that movement of the deforming geometry relative
	to the base lattice will be ignored for purposes of determining how
	the lattice affects the geometry.
	*/
	BoolID getFreezeGeometry(){char buffer[4096];sprintf_s (buffer, "%s.fg",mName.c_str());return (const char*)buffer;}
	/*
	Controls whether movement of each lattice point has a global effect
	(all deforming components are affected to some extent by every
	lattice point) or a local effect (only those components "near" the
	moved lattice points are affected). When local mode is turned on,
	the attributes localInfluenceS, localInfluenceT and localInfluenceU
	control the extent of the local effect along each of the axes
	of the lattice.
	*/
	BoolID getLocal(){char buffer[4096];sprintf_s (buffer, "%s.lo",mName.c_str());return (const char*)buffer;}
	/*
	Whether or not to use the partial resolution.
	When this is off, the deformation is computed exactly.
	Valid values are 0 = "full", 1 = "partial".
	*/
	UnsignedintID getUsePartialResolution(){char buffer[4096];sprintf_s (buffer, "%s.upr",mName.c_str());return (const char*)buffer;}
	/*
	Whether or not to transform geometry which falls outside of the
	base lattice. If 0 (the default), points outside the base lattice
	are not transformed, thus if an animated point happens to stray outside
	the base lattice, it will suddenly stop being deformed. If 1, then
	all points outside the base lattice are transformed. If 2, then all
	points outside the lattice but within the outsideFalloffDist
	distance are transformed using a linear falloff as distance increases
	from the base lattice.
	*/
	UnsignedintID getOutsideLattice(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*
	When outsideLattice is 2, this parameter provides a distance
	within which points outside of the base lattice are transformed.
	The distance is a multiple of the width of the base lattice, thus a value
	of 0.0 causes no points outside the base lattice to be transformed,
	a value of 1.0 affects points up to the width of the base lattice to
	be transformed, and so on.
	*/
	DoubleID getOutsideFalloffDist(){char buffer[4096];sprintf_s (buffer, "%s.ofd",mName.c_str());return (const char*)buffer;}
protected:
	Ffd(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FFD_H__
