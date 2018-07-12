/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_INTERMEDIATETARGETABLE_H__
#define __COLLADASAXFWL_INTERMEDIATETARGETABLE_H__

#include "COLLADASaxFWLPrerequisites.h"


namespace COLLADASaxFWL
{

	typedef size_t ClassId;

	namespace INTERMEDIATETARGETABLE_TYPE
	{
		const ClassId
			NO_TYPE = 0,
			KINEMATICS_INSTANCE = 1,
			KINEMATICATTACHMENT = 2,
			KINEMATICLINK = 3,
			KINEMATICMODEL = 4,
			KINEMATICCONTROLLER = 5,
			KINEMATICSCENE = 6
			;
	}

	/** Use this as base class for all classes that can appear in the sid tree and that are not derived from 
	framework Animatable, Object or Targetable. It should only be used for Loader specific classes that store
	intermediate data.*/
	class IntermediateTargetable
	{
	public:
		virtual ~IntermediateTargetable(){};

		/** Returns the class id of the targetable.*/
		virtual ClassId getClassId() const =0;
	};


	/** Base class of all classes that can be referenced in the model.*/
	template<ClassId classId>
	class IntermediateTargetableTemplate : public IntermediateTargetable
	{
	public:
		IntermediateTargetableTemplate() {}
		virtual ~IntermediateTargetableTemplate(){};

		/** Returns the class id of the targetable.*/
		static ClassId ID() { return classId; }

		/** Returns the class id of the targetable.*/
		ClassId getClassId() const { return ID(); }
	};

	template<class IntermediateTargetableType>
	IntermediateTargetableType* intermediateTargetableSafeCast(IntermediateTargetable* targetable)
	{
		if ( !targetable)
			return 0;

		if ( targetable->getClassId() == IntermediateTargetableType::ID() )
			return (IntermediateTargetableType*)targetable;
		else
			return 0;
	}

	template<class IntermediateTargetableType>
	const IntermediateTargetableType* intermediateTargetableSafeCast( const IntermediateTargetable* targetable)
	{
		if ( !targetable)
			return 0;

		if ( targetable->getClassId() == IntermediateTargetableType::ID() )
			return (IntermediateTargetableType*)targetable;
		else
			return 0;
	}

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_INTERMEDIATETARGETABLE_H__
