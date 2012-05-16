/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_JOINTSLOADER_H__
#define __COLLADASAXFWL_JOINTSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLHelperLoaderBase.h"
#include "COLLADASaxFWLXmlTypes.h"

#include "COLLADAFWJointPrimitive.h"


namespace COLLADAFW
{
	class Joint;
}


namespace COLLADASaxFWL
{

	class FilePartLoader;

    /** TODO Documentation */
	class JointsLoader : public HelperLoaderBase
	{
	private:
		/** The current joint.*/
		COLLADAFW::Joint* mCurrentJoint;

		/** The current joint primitive.*/
		COLLADAFW::JointPrimitive* mCurrentJointPrimitive;

		/** The number of floats that have been received since the last begin__axis____axis_type method 
		by the data__axis____axis_type methods. This is used to know where the next received number must 
		be placed in the axis.*/
		size_t mAxisNumbersReceived;

	public:

        /** Constructor. */
		JointsLoader();

        /** Destructor. */
		virtual ~JointsLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();


		bool beginJointPrimitive( COLLADAFW::JointPrimitive::Type jointPrimitiveType, const char * sid);

		bool endJointPrimitive();

		virtual bool begin__joint( const joint__AttributeData& attributeData );
		virtual bool end__joint();

		virtual bool begin__prismatic( const prismatic__AttributeData& attributeData );
		virtual bool end__prismatic();

		virtual bool begin__revolute( const revolute__AttributeData& attributeData );
		virtual bool end__revolute();

		virtual bool begin__axis____axis_type( const axis____axis_type__AttributeData& attributeData );
		virtual bool end__axis____axis_type();
		virtual bool data__axis____axis_type( const float* value, size_t length );

		virtual bool begin__limits____joint_limits_type(){return true;}
		virtual bool end__limits____joint_limits_type(){return true;}

		virtual bool begin__min____minmax_type( const min____minmax_type__AttributeData& attributeData ){return true;}
		virtual bool end__min____minmax_type(){return true;}
		virtual bool data__min____minmax_type( float value );

		virtual bool begin__max____minmax_type( const max____minmax_type__AttributeData& attributeData ){return true;}
		virtual bool end__max____minmax_type(){return true;}
		virtual bool data__max____minmax_type( float value );

	private:

        /** Disable default copy ctor. */
		JointsLoader( const JointsLoader& pre );

        /** Disable default assignment operator. */
		const JointsLoader& operator= ( const JointsLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_JOINTSLOADER_H__
