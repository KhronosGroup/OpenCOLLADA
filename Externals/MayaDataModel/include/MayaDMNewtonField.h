/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NEWTONFIELD_H__
#define __MayaDM_NEWTONFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
/*
<p><pre>The newtonField node models Newtonian gravitational attraction
between two objects.   The force exerted is proportional to the
product of the two masses and to the magnitude, and inversely
proportional to the distance.  The minDistance parameter allows
one to turn off the field force within a certain minimum distance
of the field, so as to avoid division by zero.  For geometry
objects, each vertex/cv counts as a mass of 1.  For particles,
the field will use the mass attribute if one is present; if not,
each particle counts 1.
</pre></p>
*/
class NewtonField : public Field
{
public:
public:
	NewtonField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "newtonField"){}
	virtual ~NewtonField(){}
	/*minimum distance at which field takes effect*/
	void setMinDistance(double min){if(min == 0.0) return; fprintf_s(mFile, "setAttr \".min\" %f;\n", min);}
	/*minimum distance at which field takes effect*/
	void setMinDistance(const DoubleID& min){fprintf_s(mFile,"connectAttr \"");min.write(mFile);fprintf_s(mFile,"\" \"%s.min\";\n",mName.c_str());}
	/*if particle object owns this field, need mass sometiems.*/
	void setOwnerMassData(const doubleArray& omd){if(omd.size == 0) return; fprintf_s(mFile, "setAttr \".omd\" -type \"doubleArray\" ");omd.write(mFile);fprintf_s(mFile,";\n");}
	/*if particle object owns this field, need mass sometiems.*/
	void setOwnerMassData(const DoubleArrayID& omd){fprintf_s(mFile,"connectAttr \"");omd.write(mFile);fprintf_s(mFile,"\" \"%s.omd\";\n",mName.c_str());}
	/*minimum distance at which field takes effect*/
	DoubleID getMinDistance(){char buffer[4096];sprintf_s (buffer, "%s.min",mName.c_str());return (const char*)buffer;}
	/*if particle object owns this field, need mass sometiems.*/
	DoubleArrayID getOwnerMassData(){char buffer[4096];sprintf_s (buffer, "%s.omd",mName.c_str());return (const char*)buffer;}
protected:
	NewtonField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NEWTONFIELD_H__
