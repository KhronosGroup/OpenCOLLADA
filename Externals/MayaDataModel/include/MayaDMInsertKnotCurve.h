/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_INSERTKNOTCURVE_H__
#define __MayaDM_INSERTKNOTCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
This node will insert knots at a particular parameter value(s).
 An edit point will appear where you insert the knot.  Also, the
 number of spans and CVs in the curve will increase in the area where
 the knot is inserted.  You can insert up to "degree" knots at a
 curve parameter that isn't already an edit point. eg. for a
 degree three curve, you can insert up to 3 knots.  The more
 knots inserted at a parameter (default is 1), the more "pull"
 the new CVs have.  eg. if you insert 3 knots into a degree 3 curve,
 one of the new CVs will have the curve passing directly through it.
 <p/>
 Use this operation if you need more CVs in a local area of the curve.
 Use this operation (or "hardenPoint") if you want to create a corner
 in a curve.
 <p/>
 This node is also useful if you have aligned an end of the curve at a
 specific tangent and you want the ability to change the curve shape
 near the end, while still maintaining the tangent.  In this case,
 you can insert a knot near (but not at) the end, then leave last two
 CVs (which define the tangent) where they are, and modify any other
 CV to change the curve shape.
*/
class InsertKnotCurve : public AbstractBaseCreate
{
public:
public:
	InsertKnotCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "insertKnotCurve"){}
	virtual ~InsertKnotCurve(){}
	/*The input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*Parameter value(s) where knots are added*/
	void setParameter(size_t p_i,double p){if(p == 0.0) return; fprintf_s(mFile, "setAttr \".p[%i]\" %f;\n", p_i,p);}
	/*Parameter value(s) where knots are added*/
	void setParameter(size_t p_i,const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*
	How many knots to insert.  At any point on the curve, there can
	be a maximum of "degree" knots.
	*/
	void setNumberOfKnots(size_t nk_i,int nk){if(nk == 1) return; fprintf_s(mFile, "setAttr \".nk[%i]\" %i;\n", nk_i,nk);}
	/*
	How many knots to insert.  At any point on the curve, there can
	be a maximum of "degree" knots.
	*/
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
	/*The output curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*Parameter value(s) where knots are added*/
	const DoubleID& getParameter(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*
	How many knots to insert.  At any point on the curve, there can
	be a maximum of "degree" knots.
	*/
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
	/*The output curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	InsertKnotCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_INSERTKNOTCURVE_H__
