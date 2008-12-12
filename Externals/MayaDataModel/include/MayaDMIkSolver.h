/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKSOLVER_H__
#define __MayaDM_IKSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Inverse kinematics solver node. It is the base class for all the ik
 solvers.
 <p/>
 An ikSolver node contains an inverse kinematics algorithm. It is
 used by the ikHandle node. The (is-used) association between an
 ikSolver node and an ikHandle node is made through the connection
 from the message attribute (derived) of the ikSolver node to the
 ikSolver attribute of the ikHandle node.
 <p/>
 ikHandle nodes include the objectives and resources for the ik
 solver.
 <p/>
 The startJoint and endEffector attributes of the ikHandle defines
 the resource: all the joints in the DAG from the joint connected
 with the startJoint and the ikEffector connected with the
 endEffector. Most ik solvers use the rotation attributes to meet
 the objective. As an exception, ikSplineSolve may use the
 translation attribute of the start joint.
 <p/>
 Objectives may vary from solver to solver. Most solvers attempts to
 find values for the resource attributes so that the endEffector's
 world position/orientation coincides with that of the
 ikHandle. ikSplineSolver, However, attempts to place the joint
 chain on a curve associated with the ikHandle.
 <p/>
 Details will be given on individual types of solvers.
 <p/>
*/
class IkSolver : public DependNode
{
public:
public:
	IkSolver(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "ikSolver"){}
	virtual ~IkSolver(){}
	/*
	Max number of iterations for the numerical algorithm contained in
	the solver if the algorithm is iterative. A very large number
	implies termination by tolerance.
	*/
	void setMaxIterations(int mxi){if(mxi == 2147483647) return; fprintf_s(mFile, "setAttr \".mxi\" %i;\n", mxi);}
	/*Numerical tolerance used to terminate an iterative algorithm.*/
	void setTolerance(double tol){if(tol == 0.00001) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
protected:
	IkSolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IKSOLVER_H__
