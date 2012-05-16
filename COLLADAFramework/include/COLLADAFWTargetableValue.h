/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TARGETABLEVALUE_H__
#define __COLLADAFW_TARGETABLEVALUE_H__

#include "COLLADAFWPrerequisites.h"

#include "COLLADAFWTypes.h"

namespace COLLADAFW
{

    /** A value type element that can be referenced. */
	template<class _ValueType, ClassId classId>
	class TargetableValue : public ObjectTemplate<classId>
	{
	public:
		typedef _ValueType ValueType;
	private:
		/** The value of the element.*/
		ValueType mValue;
	
	public:

        /** Constructor. */
		TargetableValue(ObjectId objectId)
			: ObjectTemplate<classId>(objectId) {}

        /** Destructor. */
		virtual ~TargetableValue();

		/** Returns the value of the element.*/
		const ValueType& getValue() const { return mValue; }
		
		/** Sets the value of the element.*/
		void setValue(ValueType value) { mValue = value; }

	};

	typedef TargetableValue<double, COLLADA_TYPE::TARGETABLEFLOAT> TargetableFloat;

} // namespace COLLADAFW

#endif // __COLLADAFW_TARGETABLEVALUE_H__
