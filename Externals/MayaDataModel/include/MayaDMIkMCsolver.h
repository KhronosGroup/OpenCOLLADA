/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKMCSOLVER_H__
#define __MayaDM_IKMCSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkSolver.h"
namespace MayaDM
{
/*
ikMCsolver works on multiple ikHandle's simultaneously. All the
 ikHandle's that use this solver and share the same value of the
 priority attribute will be solved simultaneousely.<p/>

 ikMCsolver is history dependent, meaning that it may produce
 different solutions after the ikHandle is moved, or rotated, away
 and put back again. <p/>

 It uses the rotation attributes of all the joints from the
 startJoint to the endEffector specified by the ikHandle's. In order
 for a specific rotation attribute, say rotateX, to be used, it must
 be in the jointType attribute (of string type) of the corresponding
 joint. For example, rotateX will not be used if the jointType
 attribute has value "yz". <p/>

 For each ikHandle, the objective of this solver is to put the
 position and orientation of the effector in the world space to
 where the ikHandle is. The poWeight attribute is used to balance
 the requirements on the position and orientation. poWeight being
 1.0 means that the orientation requirement is completely
 ignored. The values of the weight attribute of the ikHandle's to be
 solved together are used to negotiate the final solution if it is
 not possible to meet the objectives of all the ikHandle's
 simultaneously. <p/>
*/
class IkMCsolver : public IkSolver
{
public:
public:
	IkMCsolver(FILE* file,const std::string& name,const std::string& parent=""):IkSolver(file, name, parent, "ikMCsolver"){}
	virtual ~IkMCsolver(){}
protected:
	IkMCsolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):IkSolver(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IKMCSOLVER_H__
