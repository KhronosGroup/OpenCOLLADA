/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMOVEFACE_H__
#define __MayaDM_POLYMOVEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyMoveEdge.h"
namespace MayaDM
{
/*
Translate, rotate or scale faces of a polygonal object.<p/>

 This node uses many attributes from its parent nodes
 polyMoveVertex and polyMoveEdge, and also acts as a base
 for the geometry transforming polyChipOff and polyExtrudeFace nodes. <p/>
*/
class PolyMoveFace : public PolyMoveEdge
{
public:
public:
	PolyMoveFace(FILE* file,const std::string& name,const std::string& parent=""):PolyMoveEdge(file, name, parent, "polyMoveFace"){}
	virtual ~PolyMoveFace(){}
	/*Local offset. Faces are moved this distance towards the inside of the face.*/
	void setOffset(float off){if(off == 0.0) return; fprintf_s(mFile, "setAttr \".off\" %f;\n", off);}
	/*Local offset. Faces are moved this distance towards the inside of the face.*/
	void setOffset(const FloatID& off){fprintf_s(mFile,"connectAttr \"");off.write(mFile);fprintf_s(mFile,"\" \"%s.off\";\n",mName.c_str());}
	/*The weight, related to gravity.*/
	void setWeight(double w){if(w == 0.0) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*The weight, related to gravity.*/
	void setWeight(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*The gravity vector.*/
	void setGravity(const double3& g){if(g == double3(0.0, -1.0, 0.0)) return; fprintf_s(mFile, "setAttr \".g\" -type \"double3\" ");g.write(mFile);fprintf_s(mFile,";\n");}
	/*The gravity vector.*/
	void setGravity(const Double3ID& g){fprintf_s(mFile,"connectAttr \"");g.write(mFile);fprintf_s(mFile,"\" \"%s.g\";\n",mName.c_str());}
	/*Gravity X coord.*/
	void setGravityX(double gx){if(gx == 0) return; fprintf_s(mFile, "setAttr \".g.gx\" %f;\n", gx);}
	/*Gravity X coord.*/
	void setGravityX(const DoubleID& gx){fprintf_s(mFile,"connectAttr \"");gx.write(mFile);fprintf_s(mFile,"\" \"%s.g.gx\";\n",mName.c_str());}
	/*Gravity Y coord.*/
	void setGravityY(double gy){if(gy == 0) return; fprintf_s(mFile, "setAttr \".g.gy\" %f;\n", gy);}
	/*Gravity Y coord.*/
	void setGravityY(const DoubleID& gy){fprintf_s(mFile,"connectAttr \"");gy.write(mFile);fprintf_s(mFile,"\" \"%s.g.gy\";\n",mName.c_str());}
	/*Gravity Z coord.*/
	void setGravityZ(double gz){if(gz == 0) return; fprintf_s(mFile, "setAttr \".g.gz\" %f;\n", gz);}
	/*Gravity Z coord.*/
	void setGravityZ(const DoubleID& gz){fprintf_s(mFile,"connectAttr \"");gz.write(mFile);fprintf_s(mFile,"\" \"%s.g.gz\";\n",mName.c_str());}
	/*
	Attraction, related to magnet.
	The range is [-2.0, 2.0].
	*/
	void setAttraction(double att){if(att == 0.0) return; fprintf_s(mFile, "setAttr \".att\" %f;\n", att);}
	/*
	Attraction, related to magnet.
	The range is [-2.0, 2.0].
	*/
	void setAttraction(const DoubleID& att){fprintf_s(mFile,"connectAttr \"");att.write(mFile);fprintf_s(mFile,"\" \"%s.att\";\n",mName.c_str());}
	/*The magnet vector.*/
	void setMagnet(const double3& m){if(m == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".m\" -type \"double3\" ");m.write(mFile);fprintf_s(mFile,";\n");}
	/*The magnet vector.*/
	void setMagnet(const Double3ID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*Magnet X coord.*/
	void setMagnX(double mx){if(mx == 0) return; fprintf_s(mFile, "setAttr \".m.mx\" %f;\n", mx);}
	/*Magnet X coord.*/
	void setMagnX(const DoubleID& mx){fprintf_s(mFile,"connectAttr \"");mx.write(mFile);fprintf_s(mFile,"\" \"%s.m.mx\";\n",mName.c_str());}
	/*Magnet Y coord.*/
	void setMagnY(double my){if(my == 0) return; fprintf_s(mFile, "setAttr \".m.my\" %f;\n", my);}
	/*Magnet Y coord.*/
	void setMagnY(const DoubleID& my){fprintf_s(mFile,"connectAttr \"");my.write(mFile);fprintf_s(mFile,"\" \"%s.m.my\";\n",mName.c_str());}
	/*Magnet Z coord.*/
	void setMagnZ(double mz){if(mz == 0) return; fprintf_s(mFile, "setAttr \".m.mz\" %f;\n", mz);}
	/*Magnet Z coord.*/
	void setMagnZ(const DoubleID& mz){fprintf_s(mFile,"connectAttr \"");mz.write(mFile);fprintf_s(mFile,"\" \"%s.m.mz\";\n",mName.c_str());}
	/*Local offset. Faces are moved this distance towards the inside of the face.*/
	FloatID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.off",mName.c_str());return (const char*)buffer;}
	/*The weight, related to gravity.*/
	DoubleID getWeight(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*The gravity vector.*/
	Double3ID getGravity(){char buffer[4096];sprintf_s (buffer, "%s.g",mName.c_str());return (const char*)buffer;}
	/*Gravity X coord.*/
	DoubleID getGravityX(){char buffer[4096];sprintf_s (buffer, "%s.g.gx",mName.c_str());return (const char*)buffer;}
	/*Gravity Y coord.*/
	DoubleID getGravityY(){char buffer[4096];sprintf_s (buffer, "%s.g.gy",mName.c_str());return (const char*)buffer;}
	/*Gravity Z coord.*/
	DoubleID getGravityZ(){char buffer[4096];sprintf_s (buffer, "%s.g.gz",mName.c_str());return (const char*)buffer;}
	/*
	Attraction, related to magnet.
	The range is [-2.0, 2.0].
	*/
	DoubleID getAttraction(){char buffer[4096];sprintf_s (buffer, "%s.att",mName.c_str());return (const char*)buffer;}
	/*The magnet vector.*/
	Double3ID getMagnet(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*Magnet X coord.*/
	DoubleID getMagnX(){char buffer[4096];sprintf_s (buffer, "%s.m.mx",mName.c_str());return (const char*)buffer;}
	/*Magnet Y coord.*/
	DoubleID getMagnY(){char buffer[4096];sprintf_s (buffer, "%s.m.my",mName.c_str());return (const char*)buffer;}
	/*Magnet Z coord.*/
	DoubleID getMagnZ(){char buffer[4096];sprintf_s (buffer, "%s.m.mz",mName.c_str());return (const char*)buffer;}
protected:
	PolyMoveFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyMoveEdge(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMOVEFACE_H__
