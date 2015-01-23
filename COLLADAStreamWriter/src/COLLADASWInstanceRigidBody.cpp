/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWInstanceRigidBody.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

	//---------------------------------------------------------------
	void InstanceRigidBody::openInstanceRigidBody()
	{
		mCurrentInstanceRigidBodycloser = mSW->openElement(CSWC::CSW_ELEMENT_INSTANCE_RIGID_BODY);
		mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_BODY, mBody);
		mSW->appendURIAttribute(CSWC::CSW_ATTRIBUTE_TARGET, mTarget);
		mSW->closeElement();
	}

	void InstanceRigidBody::closeInstanceRigidBody()
	{
		mCurrentInstanceRigidBodycloser.close();
	}

} //namespace COLLADASW
