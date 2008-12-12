/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OFFSETCOS_H__
#define __MayaDM_OFFSETCOS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Create a new curve on surface which is an offset of an existing
 curve on surface.  The 'distance' attribute defines how far the
 offset curve should be from the original curve, and the 'tolerance'
 attribute sets the accuracy required. 'subdivisionDensity' defines
 how many times the offset curve spans can be subdivided in order to
 match the required tolerance. If there are sharp corners on the
 original curve, the offset curve may break into separate sections
 at these points. The attribute 'connectBreaks' can be set to ensure
 such breaks are filled, either with a linear or a circular curve
 section. In some cases the offset curve may contain a loop. The
 attribute 'cutLoop' can be set to cut off such loops.
*/
class OffsetCos : public AbstractBaseCreate
{
public:
public:
	OffsetCos(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "offsetCos"){}
	virtual ~OffsetCos(){}
	/*The input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*Do loop cutting?*/
	void setCutLoop(bool cl){if(cl == false) return; fprintf_s(mFile, "setAttr \".cl\" %i;\n", cl);}
	/*Do loop cutting?*/
	void setCutLoop(const BoolID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl\";\n",mName.c_str());}
	/*
	Connect breaks method (between gaps):
	0 - off,
	1 - circular,
	2 - linear
	*/
	void setConnectBreaks(unsigned int cb){if(cb == 2) return; fprintf_s(mFile, "setAttr \".cb\" %i;\n", cb);}
	/*
	Connect breaks method (between gaps):
	0 - off,
	1 - circular,
	2 - linear
	*/
	void setConnectBreaks(const UnsignedintID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cb\";\n",mName.c_str());}
	/*Offset distance*/
	void setDistance(double d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*Offset distance*/
	void setDistance(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Tolerance*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*Tolerance*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*Maximum subdivision density per span*/
	void setSubdivisionDensity(int sd){if(sd == 5) return; fprintf_s(mFile, "setAttr \".sd\" %i;\n", sd);}
	/*Maximum subdivision density per span*/
	void setSubdivisionDensity(const IntID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd\";\n",mName.c_str());}
	/*Checkpoints for fit quality per span. Not advisable to change this value.*/
	void setCheckPoints(short cp){if(cp == 3) return; fprintf_s(mFile, "setAttr \".cp\" %i;\n", cp);}
	/*Checkpoints for fit quality per span. Not advisable to change this value.*/
	void setCheckPoints(const ShortID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp\";\n",mName.c_str());}
	/*Stitch curve segments together. Not advisable to change this value.*/
	void setStitch(bool st){if(st == true) return; fprintf_s(mFile, "setAttr \".st\" %i;\n", st);}
	/*Stitch curve segments together. Not advisable to change this value.*/
	void setStitch(const BoolID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*Output curves*/
	void setOutputCurve(size_t oc_i,const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc[%i]\";\n",mName.c_str(),oc_i);}
	/*The input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*Do loop cutting?*/
	BoolID getCutLoop(){char buffer[4096];sprintf_s (buffer, "%s.cl",mName.c_str());return (const char*)buffer;}
	/*
	Connect breaks method (between gaps):
	0 - off,
	1 - circular,
	2 - linear
	*/
	UnsignedintID getConnectBreaks(){char buffer[4096];sprintf_s (buffer, "%s.cb",mName.c_str());return (const char*)buffer;}
	/*Offset distance*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Tolerance*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*Maximum subdivision density per span*/
	IntID getSubdivisionDensity(){char buffer[4096];sprintf_s (buffer, "%s.sd",mName.c_str());return (const char*)buffer;}
	/*Checkpoints for fit quality per span. Not advisable to change this value.*/
	ShortID getCheckPoints(){char buffer[4096];sprintf_s (buffer, "%s.cp",mName.c_str());return (const char*)buffer;}
	/*Stitch curve segments together. Not advisable to change this value.*/
	BoolID getStitch(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*Output curves*/
	const NurbsCurveID& getOutputCurve(size_t oc_i){char buffer[4096];sprintf_s (buffer, "%s.oc[%i]",mName.c_str(),oc_i);return (const char*)buffer;}
protected:
	OffsetCos(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OFFSETCOS_H__
