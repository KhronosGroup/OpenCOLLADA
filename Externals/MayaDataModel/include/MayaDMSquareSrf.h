/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SQUARESRF_H__
#define __MayaDM_SQUARESRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBoundaryBase.h"
namespace MayaDM
{
/*
Creates a square surface from three or four input curves.
 <p/>
 The order of the selected input curves is important and they must intersect
 or meet at the ends.
 <p/>
 Note that if surface curves (such as isoparms or trim edges) are used to
 form the square surface, the resulting surface has continuity if the
 tangent type was used.
*/
class SquareSrf : public BoundaryBase
{
public:
public:
	SquareSrf(FILE* file,const std::string& name,const std::string& parent=""):BoundaryBase(file, name, parent, "squareSrf"){}
	virtual ~SquareSrf(){}
	/*The number of points per span to check the tangency deviation between the boundary curve and the created tangent square surface. Only available for the tangent continuity type.*/
	void setCurveFitCheckpoints(int cfc){if(cfc == 5) return; fprintf_s(mFile, "setAttr \".cfc\" %i;\n", cfc);}
	/*The number of points per span to check the tangency deviation between the boundary curve and the created tangent square surface. Only available for the tangent continuity type.*/
	void setCurveFitCheckpoints(const IntID& cfc){fprintf_s(mFile,"connectAttr \"");cfc.write(mFile);fprintf_s(mFile,"\" \"%s.cfc\";\n",mName.c_str());}
	/*
	Continuity type legal values for curve 1:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	void setContinuityType1(unsigned int ct1){if(ct1 == 2) return; fprintf_s(mFile, "setAttr \".ct1\" %i;\n", ct1);}
	/*
	Continuity type legal values for curve 1:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	void setContinuityType1(const UnsignedintID& ct1){fprintf_s(mFile,"connectAttr \"");ct1.write(mFile);fprintf_s(mFile,"\" \"%s.ct1\";\n",mName.c_str());}
	/*
	Continuity type legal values for curve 2:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	void setContinuityType2(unsigned int ct2){if(ct2 == 2) return; fprintf_s(mFile, "setAttr \".ct2\" %i;\n", ct2);}
	/*
	Continuity type legal values for curve 2:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	void setContinuityType2(const UnsignedintID& ct2){fprintf_s(mFile,"connectAttr \"");ct2.write(mFile);fprintf_s(mFile,"\" \"%s.ct2\";\n",mName.c_str());}
	/*
	Continuity type legal values for curve 3:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	void setContinuityType3(unsigned int ct3){if(ct3 == 2) return; fprintf_s(mFile, "setAttr \".ct3\" %i;\n", ct3);}
	/*
	Continuity type legal values for curve 3:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	void setContinuityType3(const UnsignedintID& ct3){fprintf_s(mFile,"connectAttr \"");ct3.write(mFile);fprintf_s(mFile,"\" \"%s.ct3\";\n",mName.c_str());}
	/*
	Continuity type legal values for curve 4:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	void setContinuityType4(unsigned int ct4){if(ct4 == 2) return; fprintf_s(mFile, "setAttr \".ct4\" %i;\n", ct4);}
	/*
	Continuity type legal values for curve 4:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	void setContinuityType4(const UnsignedintID& ct4){fprintf_s(mFile,"connectAttr \"");ct4.write(mFile);fprintf_s(mFile,"\" \"%s.ct4\";\n",mName.c_str());}
	/*A boolean to determine if input curve 1 should be rebuilt (with curvature continuity).*/
	void setRebuildCurve1(bool rc1){if(rc1 == false) return; fprintf_s(mFile, "setAttr \".rc1\" %i;\n", rc1);}
	/*A boolean to determine if input curve 1 should be rebuilt (with curvature continuity).*/
	void setRebuildCurve1(const BoolID& rc1){fprintf_s(mFile,"connectAttr \"");rc1.write(mFile);fprintf_s(mFile,"\" \"%s.rc1\";\n",mName.c_str());}
	/*A boolean to determine if input curve 2 should be rebuilt (with curvature continuity).*/
	void setRebuildCurve2(bool rc2){if(rc2 == false) return; fprintf_s(mFile, "setAttr \".rc2\" %i;\n", rc2);}
	/*A boolean to determine if input curve 2 should be rebuilt (with curvature continuity).*/
	void setRebuildCurve2(const BoolID& rc2){fprintf_s(mFile,"connectAttr \"");rc2.write(mFile);fprintf_s(mFile,"\" \"%s.rc2\";\n",mName.c_str());}
	/*A boolean to determine if input curve 3 should be rebuilt (with curvature continuity).*/
	void setRebuildCurve3(bool rc3){if(rc3 == false) return; fprintf_s(mFile, "setAttr \".rc3\" %i;\n", rc3);}
	/*A boolean to determine if input curve 3 should be rebuilt (with curvature continuity).*/
	void setRebuildCurve3(const BoolID& rc3){fprintf_s(mFile,"connectAttr \"");rc3.write(mFile);fprintf_s(mFile,"\" \"%s.rc3\";\n",mName.c_str());}
	/*A boolean to determine if input curve 4 should be rebuilt (with curvature continuity).*/
	void setRebuildCurve4(bool rc4){if(rc4 == false) return; fprintf_s(mFile, "setAttr \".rc4\" %i;\n", rc4);}
	/*A boolean to determine if input curve 4 should be rebuilt (with curvature continuity).*/
	void setRebuildCurve4(const BoolID& rc4){fprintf_s(mFile,"connectAttr \"");rc4.write(mFile);fprintf_s(mFile,"\" \"%s.rc4\";\n",mName.c_str());}
	/*True if the continuity for boundary curve 1 passed.*/
	void setContinuityPassed1(const BoolID& cp1){fprintf_s(mFile,"connectAttr \"");cp1.write(mFile);fprintf_s(mFile,"\" \"%s.cp1\";\n",mName.c_str());}
	/*True if the continuity for boundary curve 2 passed.*/
	void setContinuityPassed2(const BoolID& cp2){fprintf_s(mFile,"connectAttr \"");cp2.write(mFile);fprintf_s(mFile,"\" \"%s.cp2\";\n",mName.c_str());}
	/*True if the continuity for boundary curve 3 passed.*/
	void setContinuityPassed3(const BoolID& cp3){fprintf_s(mFile,"connectAttr \"");cp3.write(mFile);fprintf_s(mFile,"\" \"%s.cp3\";\n",mName.c_str());}
	/*True if the continuity for boundary curve 4 passed.*/
	void setContinuityPassed4(const BoolID& cp4){fprintf_s(mFile,"connectAttr \"");cp4.write(mFile);fprintf_s(mFile,"\" \"%s.cp4\";\n",mName.c_str());}
	/*The number of points per span to check the tangency deviation between the boundary curve and the created tangent square surface. Only available for the tangent continuity type.*/
	IntID getCurveFitCheckpoints(){char buffer[4096];sprintf_s (buffer, "%s.cfc",mName.c_str());return (const char*)buffer;}
	/*
	Continuity type legal values for curve 1:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	UnsignedintID getContinuityType1(){char buffer[4096];sprintf_s (buffer, "%s.ct1",mName.c_str());return (const char*)buffer;}
	/*
	Continuity type legal values for curve 2:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	UnsignedintID getContinuityType2(){char buffer[4096];sprintf_s (buffer, "%s.ct2",mName.c_str());return (const char*)buffer;}
	/*
	Continuity type legal values for curve 3:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	UnsignedintID getContinuityType3(){char buffer[4096];sprintf_s (buffer, "%s.ct3",mName.c_str());return (const char*)buffer;}
	/*
	Continuity type legal values for curve 4:
	1 - fixed boundary
	2 - tangent continuity
	3 - implied tangent continuity
	*/
	UnsignedintID getContinuityType4(){char buffer[4096];sprintf_s (buffer, "%s.ct4",mName.c_str());return (const char*)buffer;}
	/*A boolean to determine if input curve 1 should be rebuilt (with curvature continuity).*/
	BoolID getRebuildCurve1(){char buffer[4096];sprintf_s (buffer, "%s.rc1",mName.c_str());return (const char*)buffer;}
	/*A boolean to determine if input curve 2 should be rebuilt (with curvature continuity).*/
	BoolID getRebuildCurve2(){char buffer[4096];sprintf_s (buffer, "%s.rc2",mName.c_str());return (const char*)buffer;}
	/*A boolean to determine if input curve 3 should be rebuilt (with curvature continuity).*/
	BoolID getRebuildCurve3(){char buffer[4096];sprintf_s (buffer, "%s.rc3",mName.c_str());return (const char*)buffer;}
	/*A boolean to determine if input curve 4 should be rebuilt (with curvature continuity).*/
	BoolID getRebuildCurve4(){char buffer[4096];sprintf_s (buffer, "%s.rc4",mName.c_str());return (const char*)buffer;}
	/*True if the continuity for boundary curve 1 passed.*/
	BoolID getContinuityPassed1(){char buffer[4096];sprintf_s (buffer, "%s.cp1",mName.c_str());return (const char*)buffer;}
	/*True if the continuity for boundary curve 2 passed.*/
	BoolID getContinuityPassed2(){char buffer[4096];sprintf_s (buffer, "%s.cp2",mName.c_str());return (const char*)buffer;}
	/*True if the continuity for boundary curve 3 passed.*/
	BoolID getContinuityPassed3(){char buffer[4096];sprintf_s (buffer, "%s.cp3",mName.c_str());return (const char*)buffer;}
	/*True if the continuity for boundary curve 4 passed.*/
	BoolID getContinuityPassed4(){char buffer[4096];sprintf_s (buffer, "%s.cp4",mName.c_str());return (const char*)buffer;}
protected:
	SquareSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BoundaryBase(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SQUARESRF_H__
