/*
    Copyright (c) 2015 Starbreeze

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWInstancePhysicsModel.h"
#include "COLLADASWConstants.h"


namespace COLLADASW
{

	//---------------------------------------------------------------
	void InstancePhysicsModel::openInstancePhysicsModel(const String &nodeId, const String &nodeName)
	{
		mCurrentInstancePhysicsModelCloser = mSW->openElement(CSWC::CSW_ELEMENT_INSTANCE_PHYSICS_MODEL);

		mSW->appendURIAttribute(CSWC::CSW_ATTRIBUTE_URL, mUrl);
	}


	//---------------------------------------------------------------
	void InstancePhysicsModel::closeInstancePhysicsModel()
	{
		mCurrentInstancePhysicsModelCloser.close();
	}

} //namespace COLLADASW
