/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKECIRCULARARC_H__
#define __MayaDM_MAKECIRCULARARC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute a non rational circular arc (bspline form).
 <br/>
  The degree of the created arc can be linear or cubic and is controlled
  using the attribute "degree". The number of spans of the curve can be
        controlled using the attribute "sections".
 <br/>
        The computed arc's center, sweep angle and the normal
        of the plane containing the arc can be queried using the output
        attributes "center", "sweep" and "normal" respectively.
  The created arc is available at "outputCurve" and is non-rational.
 <p/>
*/
class MakeCircularArc : public AbstractBaseCreate
{
public:
public:
	MakeCircularArc(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "makeCircularArc"){}
	virtual ~MakeCircularArc(){}
	/*
	The degree of the resulting circular arc.
	1 - linear,
	3 - cubic
	*/
	void setDegree(unsigned int d){if(d == 3) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	The degree of the resulting circular arc.
	1 - linear,
	3 - cubic
	*/
	void setDegree(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The number of sections on the arc.*/
	void setSections(int s){if(s == 8) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*The number of sections on the arc.*/
	void setSections(const IntID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Output, the center point of the circular arc*/
	void setCenter(const Double3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*Output, X coord of the center point.*/
	void setCenterX(const DoubleID& cx){fprintf_s(mFile,"connectAttr \"");cx.write(mFile);fprintf_s(mFile,"\" \"%s.c.cx\";\n",mName.c_str());}
	/*Output, Y of the center point.*/
	void setCenterY(const DoubleID& cy){fprintf_s(mFile,"connectAttr \"");cy.write(mFile);fprintf_s(mFile,"\" \"%s.c.cy\";\n",mName.c_str());}
	/*Output Z of the center point.*/
	void setCenterZ(const DoubleID& cz){fprintf_s(mFile,"connectAttr \"");cz.write(mFile);fprintf_s(mFile,"\" \"%s.c.cz\";\n",mName.c_str());}
	/*Ouput, the normal of the plane in which the circular arc will lie.*/
	void setNormal(const Double3ID& nr){fprintf_s(mFile,"connectAttr \"");nr.write(mFile);fprintf_s(mFile,"\" \"%s.nr\";\n",mName.c_str());}
	/*Output, X of the normal direction.*/
	void setNormalX(const DoubleID& nrx){fprintf_s(mFile,"connectAttr \"");nrx.write(mFile);fprintf_s(mFile,"\" \"%s.nr.nrx\";\n",mName.c_str());}
	/*Output, Y of the normal direction.*/
	void setNormalY(const DoubleID& nry){fprintf_s(mFile,"connectAttr \"");nry.write(mFile);fprintf_s(mFile,"\" \"%s.nr.nry\";\n",mName.c_str());}
	/*Output, Z of the normal direction.*/
	void setNormalZ(const DoubleID& nrz){fprintf_s(mFile,"connectAttr \"");nrz.write(mFile);fprintf_s(mFile,"\" \"%s.nr.nrz\";\n",mName.c_str());}
	/*The  sweep angle of circular arc in radians.*/
	void setSweep(const DoubleID& sw){fprintf_s(mFile,"connectAttr \"");sw.write(mFile);fprintf_s(mFile,"\" \"%s.sw\";\n",mName.c_str());}
	/*Output circular arc curve.*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*
	The degree of the resulting circular arc.
	1 - linear,
	3 - cubic
	*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The number of sections on the arc.*/
	IntID getSections(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*Output, the center point of the circular arc*/
	Double3ID getCenter(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*Output, X coord of the center point.*/
	DoubleID getCenterX(){char buffer[4096];sprintf_s (buffer, "%s.c.cx",mName.c_str());return (const char*)buffer;}
	/*Output, Y of the center point.*/
	DoubleID getCenterY(){char buffer[4096];sprintf_s (buffer, "%s.c.cy",mName.c_str());return (const char*)buffer;}
	/*Output Z of the center point.*/
	DoubleID getCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.c.cz",mName.c_str());return (const char*)buffer;}
	/*Ouput, the normal of the plane in which the circular arc will lie.*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.nr",mName.c_str());return (const char*)buffer;}
	/*Output, X of the normal direction.*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.nr.nrx",mName.c_str());return (const char*)buffer;}
	/*Output, Y of the normal direction.*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.nr.nry",mName.c_str());return (const char*)buffer;}
	/*Output, Z of the normal direction.*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.nr.nrz",mName.c_str());return (const char*)buffer;}
	/*The  sweep angle of circular arc in radians.*/
	DoubleID getSweep(){char buffer[4096];sprintf_s (buffer, "%s.sw",mName.c_str());return (const char*)buffer;}
	/*Output circular arc curve.*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	MakeCircularArc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKECIRCULARARC_H__
