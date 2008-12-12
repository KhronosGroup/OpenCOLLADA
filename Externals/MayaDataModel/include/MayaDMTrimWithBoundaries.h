/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRIMWITHBOUNDARIES_H__
#define __MayaDM_TRIMWITHBOUNDARIES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Trim a surface with a group of boundaries. Every boundary must be a closed
 non-selfintersective curve. All boundaries must be in the same space,
 in 2D (parameter) space within the surface domain.
 No boundary should intersect with any other boundaries.<p/>
 The first boundary is the outer boundary of the result region. If it is NULL,
 then the surface's native boundary will be used. An outer boundary must go
 counter-clockwise around the surface normal. Any other boundary must be
 inside the outer boundary -- they are inner boundaries. If an inner boundary
 goes clockwise then it defined a hole, otherwise it tries to define an
 island inside a hole.
 <p/>
*/
class TrimWithBoundaries : public AbstractBaseCreate
{
public:
public:
	TrimWithBoundaries(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "trimWithBoundaries"){}
	virtual ~TrimWithBoundaries(){}
	/*The curves to be used for trimming.*/
	void setInputBoundaries(size_t ib_i,const NurbsCurveID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib[%i]\";\n",mName.c_str(),ib_i);}
	/*The surface to be trimmed.*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*should flip the trimmed surface normal*/
	void setFlipNormal(bool fn){if(fn == false) return; fprintf_s(mFile, "setAttr \".fn\" %i;\n", fn);}
	/*should flip the trimmed surface normal*/
	void setFlipNormal(const BoolID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn\";\n",mName.c_str());}
	/*The parameter edge tolerance with which to trim.*/
	void setTolerancePE(double tpe){if(tpe == 0) return; fprintf_s(mFile, "setAttr \".tpe\" %f;\n", tpe);}
	/*The parameter edge tolerance with which to trim.*/
	void setTolerancePE(const DoubleID& tpe){fprintf_s(mFile,"connectAttr \"");tpe.write(mFile);fprintf_s(mFile,"\" \"%s.tpe\";\n",mName.c_str());}
	/*The edge tolerance with which to trim.*/
	void setToleranceE(double te){if(te == 0) return; fprintf_s(mFile, "setAttr \".te\" %f;\n", te);}
	/*The edge tolerance with which to trim.*/
	void setToleranceE(const DoubleID& te){fprintf_s(mFile,"connectAttr \"");te.write(mFile);fprintf_s(mFile,"\" \"%s.te\";\n",mName.c_str());}
	/*The trimmed surface.*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The curves to be used for trimming.*/
	const NurbsCurveID& getInputBoundaries(size_t ib_i){char buffer[4096];sprintf_s (buffer, "%s.ib[%i]",mName.c_str(),ib_i);return (const char*)buffer;}
	/*The surface to be trimmed.*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*should flip the trimmed surface normal*/
	BoolID getFlipNormal(){char buffer[4096];sprintf_s (buffer, "%s.fn",mName.c_str());return (const char*)buffer;}
	/*The parameter edge tolerance with which to trim.*/
	DoubleID getTolerancePE(){char buffer[4096];sprintf_s (buffer, "%s.tpe",mName.c_str());return (const char*)buffer;}
	/*The edge tolerance with which to trim.*/
	DoubleID getToleranceE(){char buffer[4096];sprintf_s (buffer, "%s.te",mName.c_str());return (const char*)buffer;}
	/*The trimmed surface.*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	TrimWithBoundaries(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TRIMWITHBOUNDARIES_H__
