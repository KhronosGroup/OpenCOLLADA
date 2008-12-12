/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKSCSOLVER_H__
#define __MayaDM_IKSCSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkSolver.h"
namespace MayaDM
{
/*
ikSCsolver works on one ikHandle at a time. Therefore, the weight
 attribute of the ikHandle is ignored by this solver.
 <p/>
 ikSCsolver is history independent, meaning that it will produce the
 same solution after the ikHandle is moved, or rotated, away and put
 back again.
 <p/>
 Since it is history independent, if an assignment of values to the
 rotation attributes makes a solution, it is always the solution
 provided it can meet the objective. The assignment by the
 corresponding preferred angles is guaranteed to be a solution.<p/>

 Following attributes of the joint node would affect the solution:
 <I>stiffness, minRotateDampRange, minRotateDampStrength,
 maxRotateDampRange, maxRotateDampStrength</I>. See the document on
 the joint node for their meanings.<p/>

 It uses the rotation attributes of all the joints from the
 startJoint to the endEffector specified by the ikHandle. In order
 for a specific rotation attribute, say rotateX, to be used, it must
 be in the jointType attribute (of string type) of the corresponding
 joint. For example, rotateX will not be used if the jointType
 attribute has value "yz". <p/>

 The objective of this solver is to put the position and
 orientation of the effector in the world space to where the
 ikHandle is. It puts the position first and then adjusts the
 orientation by rotating the start joint about the line from the
 start joint to the effector. This may not make the effector's
 orientation match the ikHandle's exactly, but it will put them as
 close as possible. The poWeight attribute of the ikHandle is not
 used. <p/>
*/
class IkSCsolver : public IkSolver
{
public:
public:
	IkSCsolver(FILE* file,const std::string& name,const std::string& parent=""):IkSolver(file, name, parent, "ikSCsolver"){}
	virtual ~IkSCsolver(){}
protected:
	IkSCsolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):IkSolver(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IKSCSOLVER_H__
