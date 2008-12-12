/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNIFORMFIELD_H__
#define __MayaDM_UNIFORMFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
/*
<p><pre> The uniform field implements a constant force acting in
 a fixed direction in the scene.    The direction x/y/z
 attributes determine the direction.
</pre></p>
*/
class UniformField : public Field
{
public:
	/*direction of uniform*/
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
	UniformField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "uniformField"){}
	virtual ~UniformField(){}
	/*direction of uniform*/
	void setDirection(const Direction& d){fprintf_s(mFile, "setAttr \".d\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*direction of uniform*/
	void setDirection(const DirectionID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*x-direction of uniform*/
	void setDirectionX(double dx){if(dx == 0.0) return; fprintf_s(mFile, "setAttr \".d.dx\" %f;\n", dx);}
	/*x-direction of uniform*/
	void setDirectionX(const DoubleID& dx){fprintf_s(mFile,"connectAttr \"");dx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dx\";\n",mName.c_str());}
	/*y-direction of uniform*/
	void setDirectionY(double dy){if(dy == 0.0) return; fprintf_s(mFile, "setAttr \".d.dy\" %f;\n", dy);}
	/*y-direction of uniform*/
	void setDirectionY(const DoubleID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.d.dy\";\n",mName.c_str());}
	/*z-direction of uniform*/
	void setDirectionZ(double dz){if(dz == 0.0) return; fprintf_s(mFile, "setAttr \".d.dz\" %f;\n", dz);}
	/*z-direction of uniform*/
	void setDirectionZ(const DoubleID& dz){fprintf_s(mFile,"connectAttr \"");dz.write(mFile);fprintf_s(mFile,"\" \"%s.d.dz\";\n",mName.c_str());}
	/*Obsolete. To be removed when no longer need to read beta 3 files.*/
	void setInheritFactor(const DoubleID& inh){fprintf_s(mFile,"connectAttr \"");inh.write(mFile);fprintf_s(mFile,"\" \"%s.inh\";\n",mName.c_str());}
	/*direction of uniform*/
	DirectionID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*x-direction of uniform*/
	DoubleID getDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.d.dx",mName.c_str());return (const char*)buffer;}
	/*y-direction of uniform*/
	DoubleID getDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.d.dy",mName.c_str());return (const char*)buffer;}
	/*z-direction of uniform*/
	DoubleID getDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.d.dz",mName.c_str());return (const char*)buffer;}
	/*Obsolete. To be removed when no longer need to read beta 3 files.*/
	DoubleID getInheritFactor(){char buffer[4096];sprintf_s (buffer, "%s.inh",mName.c_str());return (const char*)buffer;}
protected:
	UniformField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_UNIFORMFIELD_H__
