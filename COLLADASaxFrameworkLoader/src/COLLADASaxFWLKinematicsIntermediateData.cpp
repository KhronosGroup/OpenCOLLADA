/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLKinematicsIntermediateData.h"
#include "COLLADASaxFWLUtils.h"

#include "COLLADAFWJoint.h"


namespace COLLADASaxFWL
{

	//------------------------------
	KinematicsModel::KinematicsModel( const char* id, const char* name )
	{
		if ( id )
		{
			mId = id;
		}

		if ( name )
		{
			mName = name;
		}
		else if ( id )
		{
			mName = id;
		}
	}

	//------------------------------
	KinematicsModel::~KinematicsModel()
	{
		// delete base links
		deleteVector(mBaseLinks);
	}

	//------------------------------
	KinematicsIntermediateData::KinematicsIntermediateData()
	{
	}
	
    //------------------------------
	KinematicsIntermediateData::~KinematicsIntermediateData()
	{
		// delete joints
		deleteVectorFW(mJoints);

		// delete joint instances
		deleteVectorFW(mInstanceJoints);

		// delete kinematic models
		deleteVector(mKinematicsModels);
	}


} // namespace COLLADASaxFWL
