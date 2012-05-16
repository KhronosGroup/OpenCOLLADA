/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_INSTANCEKINEMATICSMODELLOADER_H__
#define __COLLADASAXFWL_INSTANCEKINEMATICSMODELLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"


namespace COLLADASaxFWL
{
	class KinematicsInstanceKinematicsModel;
	class KinematicsNewParam;

    /** TODO Documentation */
	class InstanceKinematicsModelLoader 	
	{
	private:
		/** The instance KinematicsModel currently being filled.*/
		KinematicsInstanceKinematicsModel* mCurrentKinematicsInstanceKinematicsModel; 

		/** The formula new param currently being parsed.*/
		KinematicsNewParam* mCurrentKinematicsNewParam;

		/** The sid of the current new param.*/
		String mCurrentKinematicsNewParamSid;

		/** Used to gather all the characters of a sid ref.*/
		String mSidRefString;


	public:

        /** Constructor. */
		InstanceKinematicsModelLoader();

        /** Destructor. */
		virtual ~InstanceKinematicsModelLoader();

		/** The instance KinematicsModel currently being filled.*/
		void setCurrentInstanceKinematicsModel(KinematicsInstanceKinematicsModel* val) { mCurrentKinematicsInstanceKinematicsModel = val; }
		
		bool begin__newparam____kinematics_newparam_type( const newparam____kinematics_newparam_type__AttributeData& attributeData );
		bool end__newparam____kinematics_newparam_type();

		bool begin__float();
		bool end__float();
		bool data__float( float value );

		bool begin__int();
		bool end__int();
		bool data__int( int value );

		bool begin__bool();
		bool end__bool();
		bool data__bool( bool value );

		bool begin__SIDREF();
		bool end__SIDREF();
		bool data__SIDREF( const ParserChar* value, size_t length );


	private:

        /** Disable default copy ctor. */
		InstanceKinematicsModelLoader( const InstanceKinematicsModelLoader& pre );

        /** Disable default assignment operator. */
		const InstanceKinematicsModelLoader& operator= ( const InstanceKinematicsModelLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_INSTANCEKINEMATICSMODELLOADER_H__
