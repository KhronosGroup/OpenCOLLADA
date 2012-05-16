/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWAxisInfo.h"

namespace COLLADAFW
{

	const AxisInfo AxisInfo::DEFAULT;

	//---------------------------------------------------------------
	AxisInfo::AxisInfo()
		: mJointPrimitive(0)
		, mIsActive(true)
		, mIsLocked(false)
		, mIndex(0)
	{

	}

	//---------------------------------------------------------------
// 	AxisInfo::AxisInfo( JointPrimitiveRef jointPrimitiveRef )
// 		: mJointPrimitiveRef(jointPrimitiveRef)
// 		, mIsActive(true)
// 		, mIsLocked(false)
// 	{
// 
// 	}

} // namespace COLLADAFW
