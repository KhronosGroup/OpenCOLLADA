/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_KINEMATICSSCENECREATOR_H__
#define __COLLADASAXFWL_KINEMATICSSCENECREATOR_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADAFWKinematicsModel.h"
#include "COLLADAFWKinematicsController.h"

#include <map>
#include <stack>

namespace COLLADAFW
{
	class KinematicsScene;
	class KinematicsModel;
}


namespace COLLADASaxFWL
{
	class DocumentProcessor;
	class KinematicsIntermediateData;
	class KinematicsModel;
	class KinematicLink;
	class KinematicAttachment;
	class KinematicsController;
	class KinematicsInstanceKinematicsModel;
	class AxisInfo;

    /** Creates a kinematics scene from an intermediate kinematics data */
	class KinematicsSceneCreator 	
	{
	public:
		typedef std::map<COLLADAFW::Joint*, size_t> JointIndexMap;

		typedef std::stack<size_t> NumberStack;

		typedef std::map<COLLADAFW::JointPrimitive*, COLLADAFW::JointPrimitive*> JointPrimitiveJointPrimitiveMap;
	private:
		/** The kinematics scene we are about to create.*/
		COLLADAFW::KinematicsScene* mKinematicsScene;

		/** The file loader that has all the information about the kinematics scene.*/
		DocumentProcessor* mDocumentProcessor;

		/** The kinematics intermediate data th kinematics scene will be created from. It is 
		provided by mFileLoader.*/
		const KinematicsIntermediateData& mKinematicsIntermediateData;

		/** Link number of the current link.*/
		size_t mLargestLinkNumber;

		/** Holds the link numbers of the current link and all of its parents.*/
		NumberStack mLinkNumberStack;

		/** Index of the next joint to be added to the current kinematics model.*/
		size_t mLargestJointIndex;
	
		/** Maps the joints in the intermediate data to their index in the current framework 
		kinematics model.*/
		JointIndexMap mJointIndexMap;

		/** We use this to map the joints created during the parse proces to the final nodes in the kinematics model,
		to point to the correct joint in the axis infos.
		TODO: This solution ist to simple for the general case. Requires a much better algo
		*/
		JointPrimitiveJointPrimitiveMap mOriginalClonedJointPrimitiveMap;
	public:

        /** Constructor. */
		KinematicsSceneCreator( DocumentProcessor* documentProcessor);

        /** Destructor. */
		virtual ~KinematicsSceneCreator();

		COLLADAFW::KinematicsScene* createAndGetKinematicsScene();

	private:

        /** Disable default copy ctor. */
		KinematicsSceneCreator( const KinematicsSceneCreator& pre );

        /** Disable default assignment operator. */
		const KinematicsSceneCreator& operator= ( const KinematicsSceneCreator& pre );

		COLLADAFW::KinematicsModel* createFWKinematicsModel(KinematicsModel* kinematicsModel);
	
		void createJointLinkConnections(const KinematicLink* link, COLLADAFW::KinematicsModel* fwKinematicsModel);
		void createJointLinkConnections(const KinematicAttachment* attachment, size_t jointIndex, COLLADAFW::KinematicsModel* fwKinematicsModel);
	
		COLLADAFW::KinematicsController* createFWKinematicsController(KinematicsController* kinematicsController);

		COLLADAFW::AxisInfo createFWAxisInfo( const AxisInfo& axisInfo, bool& success );

		COLLADAFW::UniqueId processInstanceKinematicsModel(const KinematicsInstanceKinematicsModel& instanceKinematicsModel);
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_KINEMATICSSCENECREATOR_H__
