/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYARTICULATEDSYSTEMSLOADER_H__
#define __COLLADASAXFWL_LIBRARYARTICULATEDSYSTEMSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLInstanceKinematicsModelLoader.h"


namespace COLLADASaxFWL
{
	class KinematicsController;
	class KinematicsInstanceKinematicsModel;
	class KinematicsNewParam;
	class AxisInfo;

    /** Stores data of library articulated systems in intermediate model. This data is used in a post process to fill
	the framework kinematics controllers.*/
	class LibraryArticulatedSystemsLoader : public FilePartLoader
	{
	private:
		enum ValueElementParentType
		{
			VALUE_ELEMENT_NONE,
			VALUE_ELEMENT_NEWPARAM,
			VALUE_ELEMENT_AKTIVE,
			VALUE_ELEMENT_LOCKED,
			VALUE_ELEMENT_INDEX,
		};

	private:

		/** The id of the current articulated system.*/
		String mCurrentArticulatedId;

		/** The name of the current articulated system.*/
		String mCurrentArticulatedName;

		/** The kinematics  currently being filled.*/
		KinematicsController* mCurrentKinematicsController;

		/** Specifies the type of the parent of a value type element <bool>, <int>, <float>, <SIDREF>.*/
		ValueElementParentType mValueElementParentType;

		InstanceKinematicsModelLoader mInstanceKinematicsModelLoader;

		/** The current axis info.*/
		AxisInfo* mCurrentAxisInfo;

	public:

        /** Constructor. */
		LibraryArticulatedSystemsLoader(IFilePartLoader* callingFilePartLoader);

        /** Destructor. */
		virtual ~LibraryArticulatedSystemsLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

		virtual bool end__library_articulated_systems();

		virtual bool begin__articulated_system( const articulated_system__AttributeData& attributeData );
		virtual bool end__articulated_system();


		virtual bool begin__kinematics();
		virtual bool end__kinematics();

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

		virtual bool begin__bind____kinematics_bind_type( const bind____kinematics_bind_type__AttributeData& attributeData ){return true;}
		virtual bool end__bind____kinematics_bind_type(){return true;}

		virtual bool begin__param____kinematics_param_type( const param____kinematics_param_type__AttributeData& attributeData ){return true;}
		virtual bool end__param____kinematics_param_type(){return true;}

		virtual bool begin__setparam____kinematics_setparam_type( const setparam____kinematics_setparam_type__AttributeData& attributeData ){return true;}
		virtual bool end__setparam____kinematics_setparam_type(){return true;}

		virtual bool begin__technique_common____kinematics_technique_type(){return true;}
		virtual bool end__technique_common____kinematics_technique_type(){return true;}

		virtual bool begin__axis_info____kinematics_axis_info_type( const axis_info____kinematics_axis_info_type__AttributeData& attributeData );
		virtual bool end__axis_info____kinematics_axis_info_type();

		virtual bool begin__active();
		virtual bool end__active();

		virtual bool begin__locked();
		virtual bool end__locked();

		virtual bool begin__index( const index__AttributeData& attributeData );
		virtual bool end__index();

		virtual bool begin__limits____kinematics_limits_type(){return true;}
		virtual bool end__limits____kinematics_limits_type(){return true;}

		virtual bool begin__min____common_float_or_param_type(){return true;}
		virtual bool end__min____common_float_or_param_type(){return true;}

		virtual bool begin__max____common_float_or_param_type(){return true;}
		virtual bool end__max____common_float_or_param_type(){return true;}

		virtual bool begin__frame_origin( const frame__AttributeData& attributeData ){return true;}
		virtual bool end__frame_origin(){return true;}

		virtual bool begin__frame_tip( const frame__AttributeData& attributeData ){return true;}
		virtual bool end__frame_tip(){return true;}

		virtual bool begin__frame_tcp( const frame__AttributeData& attributeData ){return true;}
		virtual bool end__frame_tcp(){return true;}

		virtual bool begin__frame_object( const frame__AttributeData& attributeData ){return true;}
		virtual bool end__frame_object(){return true;}

		virtual bool begin__motion(){return true;}
		virtual bool end__motion(){return true;}

		virtual bool begin__instance_articulated_system( const instance_articulated_system__AttributeData& attributeData ){return true;}
		virtual bool end__instance_articulated_system(){return true;}

		virtual bool begin__technique_common____motion_technique_type(){return true;}
		virtual bool end__technique_common____motion_technique_type(){return true;}

		virtual bool begin__axis_info____motion_axis_info_type( const axis_info____motion_axis_info_type__AttributeData& attributeData ){return true;}
		virtual bool end__axis_info____motion_axis_info_type(){return true;}

		virtual bool begin__speed____common_float_or_param_type(){return true;}
		virtual bool end__speed____common_float_or_param_type(){return true;}

		virtual bool begin__acceleration____common_float_or_param_type(){return true;}
		virtual bool end__acceleration____common_float_or_param_type(){return true;}

		virtual bool begin__deceleration____common_float_or_param_type(){return true;}
		virtual bool end__deceleration____common_float_or_param_type(){return true;}

		virtual bool begin__jerk____common_float_or_param_type(){return true;}
		virtual bool end__jerk____common_float_or_param_type(){return true;}

		virtual bool begin__effector_info( const effector_info__AttributeData& attributeData ){return true;}
		virtual bool end__effector_info(){return true;}

		virtual bool begin__speed____common_float2_or_param_type(){return true;}
		virtual bool end__speed____common_float2_or_param_type(){return true;}

		virtual bool begin__acceleration____common_float2_or_param_type(){return true;}
		virtual bool end__acceleration____common_float2_or_param_type(){return true;}

		virtual bool begin__deceleration____common_float2_or_param_type(){return true;}
		virtual bool end__deceleration____common_float2_or_param_type(){return true;}

		virtual bool begin__jerk____common_float2_or_param_type(){return true;}
		virtual bool end__jerk____common_float2_or_param_type(){return true;}

	private:

        /** Disable default copy ctor. */
		LibraryArticulatedSystemsLoader( const LibraryArticulatedSystemsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryArticulatedSystemsLoader& operator= ( const LibraryArticulatedSystemsLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYARTICULATEDSYSTEMSLOADER_H__
