/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKRPSOLVER_H__
#define __MayaDM_IKRPSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkSCsolver.h"
namespace MayaDM
{
/*
ikRPsolver works the same as ikSCsolver does except for the
 difference in how it adjusts the orientation.
 <p/>
 It does not look to the orientation of the ikHandle. It adjusts the
 orientation according to the poleVector and twist attributes of the
 ikHandle. Every skeleton, the joint hierarchy from the start joint
 to the end effector, has an intrinsic plane. If all the joints lie
 on the same plane, that plane is the intrinsic plane. The
 ikRPsolver will rotate the start joint so that the plane of the
 skeleton aligns with the plane formed by the line from the start
 joint to the end effector and the poleVector, with an offset given
 by the twist attribute. The poleVector attribute is interpreted in
 the parent space of the ikHandle.
 <p/>
*/
class IkRPsolver : public IkSCsolver
{
public:
public:
	IkRPsolver(FILE* file,const std::string& name,const std::string& parent=""):IkSCsolver(file, name, parent, "ikRPsolver"){}
	virtual ~IkRPsolver(){}
protected:
	IkRPsolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):IkSCsolver(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IKRPSOLVER_H__
