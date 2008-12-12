/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_INSERTKNOTSURFACE_H__
#define __MayaDM_INSERTKNOTSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
This node will insert a knot, (aka isoparm) at a particular parameter
 value(s) in either the U or V direction.  As a result, the number of
 spans and CVs in that surface direction will increase in the area where
 the knot is inserted.  You can insert up to "degree" knots at a
 parameter value that isn't already an isoparm.  eg. for a degree 3
 surface, you can insert up to 3 knots.  The more knots inserted
 at a parameter (default is 1), the more "pull" the new CVs have.
 eg. if you insert 3 knots into a degree 3 surface, a row of CVs
 will have the surface passing directly through it.
 <p/>
 Use this operation if you need more CVs in a local area of the surface.
 Use this operation if you want to create a corner in the surface.
 This node is also useful if you have aligned an edge of the surface
 at a specific tangent and you want the ability to change the shape
 of the surface in that area, while maintaining the tangent.
 In this case, you can insert an isoparm near (but not at) the edge,
 then leave the last two rows of CVs (which define the edge tangent)
 where they are, and modify any other CV to change the surface shape.
 <p/>
 Note: A single insertKnotSurface node cannot insert in both directions
 at once; you must use two nodes to do this.
*/
class InsertKnotSurface : public AbstractBaseCreate
{
public:
public:
	InsertKnotSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "insertKnotSurface"){}
	virtual ~InsertKnotSurface(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Parameter value(s) where knots are added*/
	void setParameter(size_t p_i,double p){if(p == 0.0) return; fprintf_s(mFile, "setAttr \".p[%i]\" %f;\n", p_i,p);}
	/*Parameter value(s) where knots are added*/
	void setParameter(size_t p_i,const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*How many knots to insert*/
	void setNumberOfKnots(size_t nk_i,int nk){if(nk == 1) return; fprintf_s(mFile, "setAttr \".nk[%i]\" %i;\n", nk_i,nk);}
	/*How many knots to insert*/
	void setNumberOfKnots(size_t nk_i,const IntID& nk){fprintf_s(mFile,"connectAttr \"");nk.write(mFile);fprintf_s(mFile,"\" \"%s.nk[%i]\";\n",mName.c_str(),nk_i);}
	/*Whether to add knots or complement.  Complement means knots will be added to reach the specified number of knots.*/
	void setAddKnots(bool add){if(add == true) return; fprintf_s(mFile, "setAttr \".add\" %i;\n", add);}
	/*Whether to add knots or complement.  Complement means knots will be added to reach the specified number of knots.*/
	void setAddKnots(const BoolID& add){fprintf_s(mFile,"connectAttr \"");add.write(mFile);fprintf_s(mFile,"\" \"%s.add\";\n",mName.c_str());}
	/*
	If set to true, and there is more than one parameter value specified,
	the knots will get inserted at equally spaced intervals between
	the given parameter values, rather than at the parameter values
	themselves.
	*/
	void setInsertBetween(bool ib){if(ib == false) return; fprintf_s(mFile, "setAttr \".ib\" %i;\n", ib);}
	/*
	If set to true, and there is more than one parameter value specified,
	the knots will get inserted at equally spaced intervals between
	the given parameter values, rather than at the parameter values
	themselves.
	*/
	void setInsertBetween(const BoolID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
	/*
	Direction in which to insert knot:
	0 - V direction,
	1 - U direction
	*/
	void setDirection(unsigned int d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	Direction in which to insert knot:
	0 - V direction,
	1 - U direction
	*/
	void setDirection(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Parameter value(s) where knots are added*/
	const DoubleID& getParameter(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*How many knots to insert*/
	const IntID& getNumberOfKnots(size_t nk_i){char buffer[4096];sprintf_s (buffer, "%s.nk[%i]",mName.c_str(),nk_i);return (const char*)buffer;}
	/*Whether to add knots or complement.  Complement means knots will be added to reach the specified number of knots.*/
	BoolID getAddKnots(){char buffer[4096];sprintf_s (buffer, "%s.add",mName.c_str());return (const char*)buffer;}
	/*
	If set to true, and there is more than one parameter value specified,
	the knots will get inserted at equally spaced intervals between
	the given parameter values, rather than at the parameter values
	themselves.
	*/
	BoolID getInsertBetween(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
	/*
	Direction in which to insert knot:
	0 - V direction,
	1 - U direction
	*/
	UnsignedintID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	InsertKnotSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_INSERTKNOTSURFACE_H__
