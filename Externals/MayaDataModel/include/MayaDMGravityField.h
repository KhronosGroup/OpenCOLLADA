/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GRAVITYFIELD_H__
#define __MayaDM_GRAVITYFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
/*
The gravityField node implements a simple gravity force.  It exerts
a gravitational pull with gravitational constant equal to
the magnitude attribute, in the direction specified by the
direction X/Y/Z attributes.<p/>
*/
class GravityField : public Field
{
public:
	/*direction of gravity*/
	struct Direction{
		double directionX;
		double directionY;
		double directionZ;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", directionX);
			fprintf_s(file,"%f ", directionY);
			fprintf_s(file,"%f", directionZ);
		}
	};
public:
	GravityField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "gravityField"){}
	virtual ~GravityField(){}
	/*direction of gravity*/
	void setDirection(const Direction& d){fprintf_s(mFile, "setAttr \".d\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*direction of gravity*/
	void setDirection(const DirectionID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*x-direction of gravity*/
	void setDirectionX(double dx){if(dx == 0.0) return; fprintf_s(mFile, "setAttr \".d.dx\" %f;\n", dx);}
	/*x-direction of gravity*/
	void setDirectionX(const DoubleID& dx){fprintf_s(mFile,"connectAttr \"");dx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dx\";\n",mName.c_str());}
	/*y-direction of gravity*/
	void setDirectionY(double dy){if(dy == 0.0) return; fprintf_s(mFile, "setAttr \".d.dy\" %f;\n", dy);}
	/*y-direction of gravity*/
	void setDirectionY(const DoubleID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.d.dy\";\n",mName.c_str());}
	/*z-direction of gravity*/
	void setDirectionZ(double dz){if(dz == 0.0) return; fprintf_s(mFile, "setAttr \".d.dz\" %f;\n", dz);}
	/*z-direction of gravity*/
	void setDirectionZ(const DoubleID& dz){fprintf_s(mFile,"connectAttr \"");dz.write(mFile);fprintf_s(mFile,"\" \"%s.d.dz\";\n",mName.c_str());}
	/*direction of gravity*/
	DirectionID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*x-direction of gravity*/
	DoubleID getDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.d.dx",mName.c_str());return (const char*)buffer;}
	/*y-direction of gravity*/
	DoubleID getDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.d.dy",mName.c_str());return (const char*)buffer;}
	/*z-direction of gravity*/
	DoubleID getDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.d.dz",mName.c_str());return (const char*)buffer;}
protected:
	GravityField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GRAVITYFIELD_H__
