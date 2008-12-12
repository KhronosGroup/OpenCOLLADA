/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKEFFECTOR_H__
#define __MayaDM_IKEFFECTOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
An ikEffector is the end-effector of a skeleton.<p/>

        An ikEffector is created automatically when an ikHandle is created, and
        connected with that ikHandle. It has the same parent as the end joint has,
        and is located at the same position as the end joint. Its translate attribute
        has a connection with the translate attribute of the end joint by default.
        The ik solution will drive the ikEffector to match where the ikHandle is.<p/>

        The handlePath attribute indicates the ikEffector has an ikHandle attached.
        An ikEffector can not be connected with more than one ikHandle.<p/>

        The hideDisplay attribute indicates the display status. If hideDisplay is
        true, the ikEffector will not be drawn in the 3D view. The ikEffector will
        be hidden by default, if there is an ikHandle attached.<p/>
*/
class IkEffector : public Transform
{
public:
public:
	IkEffector(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "ikEffector"){}
	virtual ~IkEffector(){}
	/*hide the end-effector if it is true.*/
	void setHideDisplay(bool hd){if(hd == false) return; fprintf_s(mFile, "setAttr \".hd\" %i;\n", hd);}
	/*hide the end-effector if it is true.*/
	void setHideDisplay(const BoolID& hd){fprintf_s(mFile,"connectAttr \"");hd.write(mFile);fprintf_s(mFile,"\" \"%s.hd\";\n",mName.c_str());}
	/*ikHandle's end-effector path.*/
	void setHandlePath(size_t hp_i,const MessageID& hp){fprintf_s(mFile,"connectAttr \"");hp.write(mFile);fprintf_s(mFile,"\" \"%s.hp[%i]\";\n",mName.c_str(),hp_i);}
	/*hide the end-effector if it is true.*/
	BoolID getHideDisplay(){char buffer[4096];sprintf_s (buffer, "%s.hd",mName.c_str());return (const char*)buffer;}
	/*ikHandle's end-effector path.*/
	const MessageID& getHandlePath(size_t hp_i){char buffer[4096];sprintf_s (buffer, "%s.hp[%i]",mName.c_str(),hp_i);return (const char*)buffer;}
protected:
	IkEffector(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IKEFFECTOR_H__
