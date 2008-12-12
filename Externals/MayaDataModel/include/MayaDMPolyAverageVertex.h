/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYAVERAGEVERTEX_H__
#define __MayaDM_POLYAVERAGEVERTEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
This is a smoothing node that smoothes the object without introducing
 additional vertices (as opposed to smooth). At each step, vertices are
 moved towards the average of its immediate neighbours. <p/>
*/
class PolyAverageVertex : public PolyModifierWorld
{
public:
public:
	PolyAverageVertex(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyAverageVertex"){}
	virtual ~PolyAverageVertex(){}
	/*Alpha coefficient.*/
	void setAlpha(float a){if(a == 0.5) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*Alpha coefficient.*/
	void setAlpha(const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*Beta coefficient.*/
	void setBeta(float b){if(b == 0.7) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*Beta coefficient.*/
	void setBeta(const FloatID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*Maximum iteration number*/
	void setIterations(int i){if(i == 10) return; fprintf_s(mFile, "setAttr \".i\" %i;\n", i);}
	/*Maximum iteration number*/
	void setIterations(const IntID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Alpha coefficient.*/
	FloatID getAlpha(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*Beta coefficient.*/
	FloatID getBeta(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*Maximum iteration number*/
	IntID getIterations(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
protected:
	PolyAverageVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYAVERAGEVERTEX_H__
