/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TARGET_H__
#define __COLLADAFW_TARGET_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** Target that defines the path to a value that can be referenced.*/
	class Target
	{
	private:
		/** The class Id of the object that is referenced.*/
		ClassId mClassId;

		/** The id of the attribute. This is defined as an enum for each class that has referencable members.*/
		unsigned int mAttributeId;

		/** The next target in the path or null if the end has been reached. In this case the attribute is 
		the member to override.*/
		Target* mTarget;
	
	public:

        /** Constructor. */
		Target()
			: mClassId(0)
			, mAttributeId(0)
			, mTarget(0)
		{}

		/** Constructor. 
		@param classId the class id of the target
		@param attributeId the attribute id of the targeted parameter
		@param target the next target in the path or null if there is no next target. If it is not null, 
		it will be delete at destruction.*/
		Target( ClassId classId, unsigned int attributeId, Target* target = 0)
			: mClassId(classId)
			, mAttributeId(attributeId)
			, mTarget(0)
		{}

		/** Disable default copy ctor. */
		Target( const Target& pre )
			: mClassId(pre.mClassId)
			, mAttributeId(pre.mAttributeId)
			, mTarget( pre.mTarget ? pre.mTarget->deepCopyChildTarget() : 0)
		{}

        /** Destructor. */
		virtual ~Target()
		{
			FW_DELETE mTarget;
		}

		/** The class Id of the object that is referenced.*/
		ClassId getClassId() const { return mClassId; }

		/** The class Id of the object that is referenced.*/
		void setClassId( ClassId classId) { mClassId = classId; }

		/** The id of the attribute. This is defined as an enum for each class that has referencable members.*/
		unsigned int getAttributeId() const { return mAttributeId; }

		/** The id of the attribute. This is defined as an enum for each class that has referencable members.*/
		void setAttributeId(unsigned int attributeId) { mAttributeId = attributeId; }

		/** The next target in the path or null if the end has been reached. In this case the attribute is 
		the member to override.*/
		Target* getTarget() const { return mTarget; }

		/** Sets the next target in the path. @a target has to created using  FW_NEW and is deleted in the destructor.*/
		void setTarget(Target* target) { mTarget = target; }


        /** Disable default assignment operator. */
		const Target& operator= ( const Target& pre )
		{
			mClassId = pre.mClassId;
			mAttributeId = pre.mAttributeId;
			FW_DELETE mTarget;
			mTarget = pre.mTarget ? pre.mTarget->deepCopyChildTarget() : 0;
			return *this;
		}

	private:
		/** Makes a deep copy of the child target and returns a pointer.*/
		Target* deepCopyChildTarget() const
		{
			if ( !mTarget )
			{
				return 0;
			}
			return FW_NEW Target( mClassId, mAttributeId, mTarget->deepCopyChildTarget());
		}

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_TARGET_H__
