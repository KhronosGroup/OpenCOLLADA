/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYJOINTSLOADER_H__
#define __COLLADASAXFWL_LIBRARYJOINTSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLXmlTypes.h"
#include "COLLADASaxFWLJointsLoader.h"
#include "COLLADASaxFWLFilePartLoader.h"


namespace COLLADAFW
{
	class Joint;
}


namespace COLLADASaxFWL
{

	/** Loads all the joints in a library joints. The joints are stored in the loader and are
	precess later when the kinematics is build up.*/
	class LibraryJointsLoader : public FilePartLoader
	{
	private:
		/** handles all joint related elements.*/
		JointsLoader mJointsLoader;

	public:

        /** Constructor. */
		LibraryJointsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryJointsLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();


		virtual bool end__library_joints();

		/** Joint methods begin.*/
		virtual bool begin__joint( const joint__AttributeData& attributeData ) { return mJointsLoader.begin__joint(attributeData); }
		virtual bool end__joint() { return mJointsLoader.end__joint(); }

		virtual bool begin__prismatic( const prismatic__AttributeData& attributeData ) { return mJointsLoader.begin__prismatic(attributeData); }
		virtual bool end__prismatic() { return mJointsLoader.end__prismatic(); }

		virtual bool begin__revolute( const revolute__AttributeData& attributeData ) { return mJointsLoader.begin__revolute(attributeData); }
		virtual bool end__revolute() { return mJointsLoader.end__revolute(); }

		virtual bool begin__axis____axis_type( const axis____axis_type__AttributeData& attributeData ) { return mJointsLoader.begin__axis____axis_type(attributeData); }
		virtual bool end__axis____axis_type() { return mJointsLoader.end__axis____axis_type(); }
		virtual bool data__axis____axis_type( const float* value, size_t length ) { return mJointsLoader.data__axis____axis_type(value, length); }

		virtual bool begin__limits____joint_limits_type(){ { return mJointsLoader.begin__limits____joint_limits_type(); }}
		virtual bool end__limits____joint_limits_type(){ { return mJointsLoader.end__limits____joint_limits_type(); }}

		virtual bool begin__min____minmax_type( const min____minmax_type__AttributeData& attributeData ){ { return mJointsLoader.begin__min____minmax_type(attributeData); }}
		virtual bool end__min____minmax_type(){ { return mJointsLoader.end__min____minmax_type(); }}
		virtual bool data__min____minmax_type( float value ) { return mJointsLoader.data__min____minmax_type(value); }

		virtual bool begin__max____minmax_type( const max____minmax_type__AttributeData& attributeData ){ { return mJointsLoader.begin__max____minmax_type(attributeData); }}
		virtual bool end__max____minmax_type(){ { return mJointsLoader.end__max____minmax_type(); }}
		virtual bool data__max____minmax_type( float value ) { return mJointsLoader.data__max____minmax_type(value); }


		/** Joint methods end.*/


	private:

        /** Disable default copy ctor. */
		LibraryJointsLoader( const LibraryJointsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryJointsLoader& operator= ( const LibraryJointsLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYJOINTSLOADER_H__
