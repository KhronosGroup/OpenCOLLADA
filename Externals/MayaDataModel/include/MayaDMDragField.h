/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DRAGFIELD_H__
#define __MayaDM_DRAGFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
/*
The dragField node implements a simple drag force similar to wind resistance.
It creates a force proportional to the velocity of the object being affected.
The drag node has directonX/Y/Z attributes and a useDirection attribute.
If useDirection is false, the drag pushes back in the oppsite of whatever
direction the affected object is moving.  If useDirection is true, the
drag node uses the component of the object's velocity along the specified
direction in place of the object's original velocity.<p/>
*/
class DragField : public Field
{
public:
	/*direction of drag*/
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
	DragField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "dragField"){}
	virtual ~DragField(){}
	/*direction of drag*/
	void setDirection(const Direction& d){fprintf_s(mFile, "setAttr \".d\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*direction of drag*/
	void setDirection(const DirectionID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*x-direction of drag*/
	void setDirectionX(double dx){if(dx == 0.0) return; fprintf_s(mFile, "setAttr \".d.dx\" %f;\n", dx);}
	/*x-direction of drag*/
	void setDirectionX(const DoubleID& dx){fprintf_s(mFile,"connectAttr \"");dx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dx\";\n",mName.c_str());}
	/*y-direction of drag*/
	void setDirectionY(double dy){if(dy == 0.0) return; fprintf_s(mFile, "setAttr \".d.dy\" %f;\n", dy);}
	/*y-direction of drag*/
	void setDirectionY(const DoubleID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.d.dy\";\n",mName.c_str());}
	/*z-direction of drag*/
	void setDirectionZ(double dz){if(dz == 0.0) return; fprintf_s(mFile, "setAttr \".d.dz\" %f;\n", dz);}
	/*z-direction of drag*/
	void setDirectionZ(const DoubleID& dz){fprintf_s(mFile,"connectAttr \"");dz.write(mFile);fprintf_s(mFile,"\" \"%s.d.dz\";\n",mName.c_str());}
	/*use direction parm yes/no*/
	void setUseDirection(bool ud){if(ud == false) return; fprintf_s(mFile, "setAttr \".ud\" %i;\n", ud);}
	/*use direction parm yes/no*/
	void setUseDirection(const BoolID& ud){fprintf_s(mFile,"connectAttr \"");ud.write(mFile);fprintf_s(mFile,"\" \"%s.ud\";\n",mName.c_str());}
	/*the amount that drag is relative to movement of the drag field*/
	void setInheritVelocity(double iv){if(iv == 0) return; fprintf_s(mFile, "setAttr \".iv\" %f;\n", iv);}
	/*the amount that drag is relative to movement of the drag field*/
	void setInheritVelocity(const DoubleID& iv){fprintf_s(mFile,"connectAttr \"");iv.write(mFile);fprintf_s(mFile,"\" \"%s.iv\";\n",mName.c_str());}
	/*
	This reduces the effect of drag when the field is
	moving slowly. When motion attenuation is greater than zero there will
	be no drag when the field is stationary. When the speed of the
	the field is equal to or greater than the motion attenuation
	value then the full magnitude setting of the drag will be applied.
	This field requires that inheritVelocity be non-zero to have an effect.
	*/
	void setMotionAttenuation(double mna){if(mna == 0.0) return; fprintf_s(mFile, "setAttr \".mna\" %f;\n", mna);}
	/*
	This reduces the effect of drag when the field is
	moving slowly. When motion attenuation is greater than zero there will
	be no drag when the field is stationary. When the speed of the
	the field is equal to or greater than the motion attenuation
	value then the full magnitude setting of the drag will be applied.
	This field requires that inheritVelocity be non-zero to have an effect.
	*/
	void setMotionAttenuation(const DoubleID& mna){fprintf_s(mFile,"connectAttr \"");mna.write(mFile);fprintf_s(mFile,"\" \"%s.mna\";\n",mName.c_str());}
	/*
	This attenuates the amount of drag when the speed of the particle is
	less than the speed attenuation value. This allows slow moving particles
	to not be affected much by the drag while still heavily damping fast moving ones.
	*/
	void setSpeedAttenuation(double spa){if(spa == 0.0) return; fprintf_s(mFile, "setAttr \".spa\" %f;\n", spa);}
	/*
	This attenuates the amount of drag when the speed of the particle is
	less than the speed attenuation value. This allows slow moving particles
	to not be affected much by the drag while still heavily damping fast moving ones.
	*/
	void setSpeedAttenuation(const DoubleID& spa){fprintf_s(mFile,"connectAttr \"");spa.write(mFile);fprintf_s(mFile,"\" \"%s.spa\";\n",mName.c_str());}
	/*
	This is the current time used to compute the velocity of the drag
	field, which affects the force applied.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.
	*/
	void setCurrentTime(const TimeID& cti){fprintf_s(mFile,"connectAttr \"");cti.write(mFile);fprintf_s(mFile,"\" \"%s.cti\";\n",mName.c_str());}
	/*direction of drag*/
	DirectionID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*x-direction of drag*/
	DoubleID getDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.d.dx",mName.c_str());return (const char*)buffer;}
	/*y-direction of drag*/
	DoubleID getDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.d.dy",mName.c_str());return (const char*)buffer;}
	/*z-direction of drag*/
	DoubleID getDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.d.dz",mName.c_str());return (const char*)buffer;}
	/*use direction parm yes/no*/
	BoolID getUseDirection(){char buffer[4096];sprintf_s (buffer, "%s.ud",mName.c_str());return (const char*)buffer;}
	/*the amount that drag is relative to movement of the drag field*/
	DoubleID getInheritVelocity(){char buffer[4096];sprintf_s (buffer, "%s.iv",mName.c_str());return (const char*)buffer;}
	/*
	This reduces the effect of drag when the field is
	moving slowly. When motion attenuation is greater than zero there will
	be no drag when the field is stationary. When the speed of the
	the field is equal to or greater than the motion attenuation
	value then the full magnitude setting of the drag will be applied.
	This field requires that inheritVelocity be non-zero to have an effect.
	*/
	DoubleID getMotionAttenuation(){char buffer[4096];sprintf_s (buffer, "%s.mna",mName.c_str());return (const char*)buffer;}
	/*
	This attenuates the amount of drag when the speed of the particle is
	less than the speed attenuation value. This allows slow moving particles
	to not be affected much by the drag while still heavily damping fast moving ones.
	*/
	DoubleID getSpeedAttenuation(){char buffer[4096];sprintf_s (buffer, "%s.spa",mName.c_str());return (const char*)buffer;}
	/*
	This is the current time used to compute the velocity of the drag
	field, which affects the force applied.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.
	*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.cti",mName.c_str());return (const char*)buffer;}
protected:
	DragField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DRAGFIELD_H__
