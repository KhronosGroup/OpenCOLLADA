/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_KINEMATICSSCENE_H__
#define __COLLADAFW_KINEMATICSSCENE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWKinematicsModel.h"
#include "COLLADAFWKinematicsController.h"
#include "COLLADAFWInstanceKinematicsScene.h"


namespace COLLADAFW
{

    /** Contains the entire kinematics information of a COLLADA file. */
	class KinematicsScene 	
	{
	private:
		/** All kinematics models.*/
		KinematicsModelArray mKinematicsModels;

		/** All kinematics controllers.*/
		KinematicsControllerArray mKinematicsControllerArray;

		/** All the instance kinematics scenes in the model.*/
		InstanceKinematicsSceneArray mInstanceKinematicsScenes;

	public:

        /** Constructor. */
		KinematicsScene();

        /** Destructor. */
		virtual ~KinematicsScene();

		/** Returns all kinematics models.*/
		const KinematicsModelArray& getKinematicsModels() const { return mKinematicsModels; }

		/** Returns all kinematics models.*/
		KinematicsModelArray& getKinematicsModels() { return mKinematicsModels; }

		/** Returns all kinematics models.*/
		const KinematicsControllerArray& getKinematicsControllers() const { return mKinematicsControllerArray; }

		/** Returns all kinematics models.*/
		KinematicsControllerArray& getKinematicsControllers() { return mKinematicsControllerArray; }

		/** All the instance kinematics scenes in the model.*/
		InstanceKinematicsSceneArray InstanceKinematicsScenes;

		/** Returns all kinematics models.*/
		const InstanceKinematicsSceneArray& getInstanceKinematicsScenes() const { return mInstanceKinematicsScenes; }

		/** Returns all kinematics models.*/
		InstanceKinematicsSceneArray& getInstanceKinematicsScenes() { return mInstanceKinematicsScenes; }

	private:

//         /** Disable default copy ctor. */
// 		KinematicsScene( const KinematicsScene& pre );
// 
//         /** Disable default assignment operator. */
// 		const KinematicsScene& operator= ( const KinematicsScene& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_KINEMATICSSCENE_H__
