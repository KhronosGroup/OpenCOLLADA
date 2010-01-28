/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYKINEMATICSSCENESLOADER_H__
#define __COLLADASAXFWL_LIBRARYKINEMATICSSCENESLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLInstanceArticulatedSystemLoader.h"


namespace COLLADASaxFWL
{
	class KinematicsScene;

	/** Stores data of library kinematics scenes in intermediate model. This data is used in a post process to fill
	the framework kinematics scene.*/
	class LibraryKinematicsScenesLoader : public FilePartLoader
	{
	private:
		/** The KinematicsScene currently being parsed.*/
		KinematicsScene* mCurrentKinematicsScene;

		InstanceArticulatedSystemLoader mInstanceArticulatedSystemLoader;

	public:

        /** Constructor. */
		LibraryKinematicsScenesLoader(IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryKinematicsScenesLoader();

		bool begin__kinematics_scene( const kinematics_scene__AttributeData& attributeData );
		bool end__kinematics_scene();

		bool begin__instance_articulated_system( const instance_articulated_system__AttributeData& attributeData );
		bool end__instance_articulated_system();

		virtual bool begin__bind____kinematics_bind_type( const bind____kinematics_bind_type__AttributeData& attributeData );
		virtual bool end__bind____kinematics_bind_type();

		virtual bool begin__param____kinematics_param_type( const param____kinematics_param_type__AttributeData& attributeData );
		virtual bool end__param____kinematics_param_type();
	private:

        /** Disable default copy ctor. */
		LibraryKinematicsScenesLoader( const LibraryKinematicsScenesLoader& pre );

        /** Disable default assignment operator. */
		const LibraryKinematicsScenesLoader& operator= ( const LibraryKinematicsScenesLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYKINEMATICSSCENESLOADER_H__
