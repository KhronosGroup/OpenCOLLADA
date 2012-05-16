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
#include "COLLADASaxFWLInstanceKinematicsModelLoader.h"



namespace COLLADASaxFWL
{
	class KinematicsScene;

	/** Stores data of library kinematics scenes in intermediate model. This data is used in a post process to fill
	the framework kinematics scene.*/
	class LibraryKinematicsScenesLoader : public FilePartLoader
	{
	private:
		enum ValueElementParentType
		{
			VALUE_ELEMENT_NONE,
			VALUE_ELEMENT_NEWPARAM,
		};

	private:
		/** The KinematicsScene currently being parsed.*/
		KinematicsScene* mCurrentKinematicsScene;

		InstanceArticulatedSystemLoader mInstanceArticulatedSystemLoader;

		InstanceKinematicsModelLoader mInstanceKinematicsModelLoader;

		/** Specifies the type of the parent of a value type element <bool>, <int>, <float>, <SIDREF>.*/
		ValueElementParentType mValueElementParentType;

	public:

        /** Constructor. */
		LibraryKinematicsScenesLoader(IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryKinematicsScenesLoader();

		virtual bool end__library_kinematics_scenes();

		bool begin__kinematics_scene( const kinematics_scene__AttributeData& attributeData );
		bool end__kinematics_scene();

		bool begin__instance_articulated_system( const instance_articulated_system__AttributeData& attributeData );
		bool end__instance_articulated_system();

		virtual bool begin__bind____kinematics_bind_type( const bind____kinematics_bind_type__AttributeData& attributeData );
		virtual bool end__bind____kinematics_bind_type();

		virtual bool begin__param____kinematics_param_type( const param____kinematics_param_type__AttributeData& attributeData );
		virtual bool end__param____kinematics_param_type();

		virtual bool begin__instance_kinematics_model( const instance_kinematics_model__AttributeData& attributeData );
		virtual bool end__instance_kinematics_model();

		virtual bool begin__newparam____kinematics_newparam_type( const newparam____kinematics_newparam_type__AttributeData& attributeData );
		virtual bool end__newparam____kinematics_newparam_type();

		virtual bool begin__float();
		virtual bool end__float();
		virtual bool data__float( float value );

		virtual bool begin__int();
		virtual bool end__int();
		virtual bool data__int( int value );

		virtual bool begin__bool();
		virtual bool end__bool();
		virtual bool data__bool( bool value );

		virtual bool begin__SIDREF();
		virtual bool end__SIDREF();
		virtual bool data__SIDREF( const ParserChar* value, size_t length );


	private:

        /** Disable default copy ctor. */
		LibraryKinematicsScenesLoader( const LibraryKinematicsScenesLoader& pre );

        /** Disable default assignment operator. */
		const LibraryKinematicsScenesLoader& operator= ( const LibraryKinematicsScenesLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYKINEMATICSSCENESLOADER_H__
