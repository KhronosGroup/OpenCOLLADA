/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DROPOFFLOCATOR_H__
#define __MayaDM_DROPOFFLOCATOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLocator.h"
namespace MayaDM
{
/*
<p><pre> This node represents a point on a wire curve where local control
 is needed over the behavior of the wire deformation.
</pre></p>
*/
class DropoffLocator : public Locator
{
public:
public:
	DropoffLocator(FILE* file,const std::string& name,const std::string& parent=""):Locator(file, name, parent, "dropoffLocator"){}
	virtual ~DropoffLocator(){}
	/*The percent value at this point on the wire curve.*/
	void setPercent(float pc){if(pc == 1) return; fprintf_s(mFile, "setAttr \".pc\" %f;\n", pc);}
	/*The percent value at this point on the wire curve.*/
	void setPercent(const FloatID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*The parameter value at which to position this locator along the curve.*/
	void setParam(float pr){if(pr == 0.0) return; fprintf_s(mFile, "setAttr \".pr\" %f;\n", pr);}
	/*The parameter value at which to position this locator along the curve.*/
	void setParam(const FloatID& pr){fprintf_s(mFile,"connectAttr \"");pr.write(mFile);fprintf_s(mFile,"\" \"%s.pr\";\n",mName.c_str());}
	/*The percent value at this point on the wire curve.*/
	FloatID getPercent(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*The parameter value at which to position this locator along the curve.*/
	FloatID getParam(){char buffer[4096];sprintf_s (buffer, "%s.pr",mName.c_str());return (const char*)buffer;}
protected:
	DropoffLocator(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Locator(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DROPOFFLOCATOR_H__
