/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AIRFIELD_H__
#define __MayaDM_AIRFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
/*
<p><pre>    This is the air field node.  THe air field is meant to simulate
    the effects of air or wind on a dynamic object (particle or rigid
    body).
</pre></p>
*/
class AirField : public Field
{
public:
	/*The direction that the air is 'blowing'*/
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
	AirField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "airField"){}
	virtual ~AirField(){}
	/*The direction that the air is 'blowing'*/
	void setDirection(const Direction& d){fprintf_s(mFile, "setAttr \".d\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*The direction that the air is 'blowing'*/
	void setDirection(const DirectionID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The amount in X that the air is blowing*/
	void setDirectionX(double dx){if(dx == 0) return; fprintf_s(mFile, "setAttr \".d.dx\" %f;\n", dx);}
	/*The amount in X that the air is blowing*/
	void setDirectionX(const DoubleID& dx){fprintf_s(mFile,"connectAttr \"");dx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dx\";\n",mName.c_str());}
	/*The amount in Y that the air is blowing*/
	void setDirectionY(double dy){if(dy == 0) return; fprintf_s(mFile, "setAttr \".d.dy\" %f;\n", dy);}
	/*The amount in Y that the air is blowing*/
	void setDirectionY(const DoubleID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.d.dy\";\n",mName.c_str());}
	/*The amount in Z that the air is blowing*/
	void setDirectionZ(double dz){if(dz == 0) return; fprintf_s(mFile, "setAttr \".d.dz\" %f;\n", dz);}
	/*The amount in Z that the air is blowing*/
	void setDirectionZ(const DoubleID& dz){fprintf_s(mFile,"connectAttr \"");dz.write(mFile);fprintf_s(mFile,"\" \"%s.d.dz\";\n",mName.c_str());}
	/*The speed that the air is moving, and thus will attempt to make other objects move.*/
	void setSpeed(double spd){if(spd == 0) return; fprintf_s(mFile, "setAttr \".spd\" %f;\n", spd);}
	/*The speed that the air is moving, and thus will attempt to make other objects move.*/
	void setSpeed(const DoubleID& spd){fprintf_s(mFile,"connectAttr \"");spd.write(mFile);fprintf_s(mFile,"\" \"%s.spd\";\n",mName.c_str());}
	/*The amount(0-1) of the owner's velocity that the air will inherit in its speed*/
	void setInheritVelocity(double iv){if(iv == 0) return; fprintf_s(mFile, "setAttr \".iv\" %f;\n", iv);}
	/*The amount(0-1) of the owner's velocity that the air will inherit in its speed*/
	void setInheritVelocity(const DoubleID& iv){fprintf_s(mFile,"connectAttr \"");iv.write(mFile);fprintf_s(mFile,"\" \"%s.iv\";\n",mName.c_str());}
	/*Make new target velocity a function of wind AND original velocity.*/
	void setComponentOnly(bool co){if(co == false) return; fprintf_s(mFile, "setAttr \".co\" %i;\n", co);}
	/*Make new target velocity a function of wind AND original velocity.*/
	void setComponentOnly(const BoolID& co){fprintf_s(mFile,"connectAttr \"");co.write(mFile);fprintf_s(mFile,"\" \"%s.co\";\n",mName.c_str());}
	/*The amount of a hemisphere that will be the cone of spread*/
	void setSpread(double spr){if(spr == 0) return; fprintf_s(mFile, "setAttr \".spr\" %f;\n", spr);}
	/*The amount of a hemisphere that will be the cone of spread*/
	void setSpread(const DoubleID& spr){fprintf_s(mFile,"connectAttr \"");spr.write(mFile);fprintf_s(mFile,"\" \"%s.spr\";\n",mName.c_str());}
	/*Whether or not the field is using the spread feature*/
	void setEnableSpread(bool es){if(es == false) return; fprintf_s(mFile, "setAttr \".es\" %i;\n", es);}
	/*Whether or not the field is using the spread feature*/
	void setEnableSpread(const BoolID& es){fprintf_s(mFile,"connectAttr \"");es.write(mFile);fprintf_s(mFile,"\" \"%s.es\";\n",mName.c_str());}
	/*Whether or not the field is using the spread feature*/
	void setInheritRotation(bool ir){if(ir == false) return; fprintf_s(mFile, "setAttr \".ir\" %i;\n", ir);}
	/*Whether or not the field is using the spread feature*/
	void setInheritRotation(const BoolID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.ir\";\n",mName.c_str());}
	/*The direction that the air is 'blowing'*/
	DirectionID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The amount in X that the air is blowing*/
	DoubleID getDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.d.dx",mName.c_str());return (const char*)buffer;}
	/*The amount in Y that the air is blowing*/
	DoubleID getDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.d.dy",mName.c_str());return (const char*)buffer;}
	/*The amount in Z that the air is blowing*/
	DoubleID getDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.d.dz",mName.c_str());return (const char*)buffer;}
	/*The speed that the air is moving, and thus will attempt to make other objects move.*/
	DoubleID getSpeed(){char buffer[4096];sprintf_s (buffer, "%s.spd",mName.c_str());return (const char*)buffer;}
	/*The amount(0-1) of the owner's velocity that the air will inherit in its speed*/
	DoubleID getInheritVelocity(){char buffer[4096];sprintf_s (buffer, "%s.iv",mName.c_str());return (const char*)buffer;}
	/*Make new target velocity a function of wind AND original velocity.*/
	BoolID getComponentOnly(){char buffer[4096];sprintf_s (buffer, "%s.co",mName.c_str());return (const char*)buffer;}
	/*The amount of a hemisphere that will be the cone of spread*/
	DoubleID getSpread(){char buffer[4096];sprintf_s (buffer, "%s.spr",mName.c_str());return (const char*)buffer;}
	/*Whether or not the field is using the spread feature*/
	BoolID getEnableSpread(){char buffer[4096];sprintf_s (buffer, "%s.es",mName.c_str());return (const char*)buffer;}
	/*Whether or not the field is using the spread feature*/
	BoolID getInheritRotation(){char buffer[4096];sprintf_s (buffer, "%s.ir",mName.c_str());return (const char*)buffer;}
protected:
	AirField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_AIRFIELD_H__
