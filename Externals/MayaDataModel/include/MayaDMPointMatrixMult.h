/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POINTMATRIXMULT_H__
#define __MayaDM_POINTMATRIXMULT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
    The dependency graph node to multiply a point by a matrix.

</pre></p>
*/
class PointMatrixMult : public DependNode
{
public:
public:
	PointMatrixMult(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "pointMatrixMult"){}
	virtual ~PointMatrixMult(){}
	/*Input point*/
	void setInPoint(const double3& ip){fprintf_s(mFile, "setAttr \".ip\" -type \"double3\" ");ip.write(mFile);fprintf_s(mFile,";\n");}
	/*X of input point*/
	void setInPointX(double ipx){if(ipx == 0) return; fprintf_s(mFile, "setAttr \".ip.ipx\" %f;\n", ipx);}
	/*Y of input point*/
	void setInPointY(double ipy){if(ipy == 0) return; fprintf_s(mFile, "setAttr \".ip.ipy\" %f;\n", ipy);}
	/*Z of input point*/
	void setInPointZ(double ipz){if(ipz == 0) return; fprintf_s(mFile, "setAttr \".ip.ipz\" %f;\n", ipz);}
	/*Matrix to be multiplied*/
	void setInMatrix(const matrix& im){if(im == identity) return; fprintf_s(mFile, "setAttr \".im\" -type \"matrix\" ");im.write(mFile);fprintf_s(mFile,";\n");}
	/*Perform vector multiplication.*/
	void setVectorMultiply(bool vm){if(vm == false) return; fprintf_s(mFile, "setAttr \".vm\" %i;\n", vm);}
	/*The product the point and matrix*/
	void setOutput(const Double3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Output X orientation*/
	void setOutputX(const DoubleID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*Output Y orientation*/
	void setOutputY(const DoubleID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*Output Z orientation*/
	void setOutputZ(const DoubleID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*The product the point and matrix*/
	Double3ID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*Output X orientation*/
	DoubleID getOutputX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*Output Y orientation*/
	DoubleID getOutputY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*Output Z orientation*/
	DoubleID getOutputZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
protected:
	PointMatrixMult(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POINTMATRIXMULT_H__
