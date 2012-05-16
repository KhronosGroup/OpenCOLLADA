/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_INSTANCEARTICULATEDSYSTEMLOADER_H__
#define __COLLADASAXFWL_INSTANCEARTICULATEDSYSTEMLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLKinematicsIntermediateData.h"


namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class InstanceArticulatedSystemLoader 	
	{
	private:
		/** The instance articulated system currently being filled.*/
		KinematicsInstanceArticulatedSystem* mInstanceArticulatedSystem; 

		/** The bind currently being filled.*/
		KinematicsBind* mCurrentBind;
	
	public:

        /** Constructor. */
		InstanceArticulatedSystemLoader();

        /** Destructor. */
		virtual ~InstanceArticulatedSystemLoader();

		void setInstanceArticulatedSystem(KinematicsInstanceArticulatedSystem* instanceArticulatedSystem );

		KinematicsInstanceArticulatedSystem* getInstanceArticulatedSystem();

		virtual bool begin__bind____kinematics_bind_type( const bind____kinematics_bind_type__AttributeData& attributeData );
		virtual bool end__bind____kinematics_bind_type();

		virtual bool begin__param____kinematics_param_type( const param____kinematics_param_type__AttributeData& attributeData );
		virtual bool end__param____kinematics_param_type(){return true;}


	private:

        /** Disable default copy ctor. */
		InstanceArticulatedSystemLoader( const InstanceArticulatedSystemLoader& pre );

        /** Disable default assignment operator. */
		const InstanceArticulatedSystemLoader& operator= ( const InstanceArticulatedSystemLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_INSTANCEARTICULATEDSYSTEMLOADER_H__
