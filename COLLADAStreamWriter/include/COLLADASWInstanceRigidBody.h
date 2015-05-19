/*
    Copyright (c) 2015 Starbreeze

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_RIGID_BODY_H__
#define __COLLADASTREAMWRITER_INSTANCE_RIGID_BODY_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWConstants.h"

#include "COLLADABUURI.h"


namespace COLLADASW
{

  //  class InstanceRigidBodyList;

    /** A class that holds informations of an @a \<instance_rigid_body\> element*/
	class InstanceRigidBody : public ElementWriter
    {

    private:

        String mBody;
        URI mTarget;

    public:

        /** Constructor
        @param symbol The symbol name
        @param target The target
        */
		InstanceRigidBody(StreamWriter* streamWriter, const String& body, const URI& target)
		: ElementWriter(streamWriter), mBody(body), mTarget(target) {}

		/** Writes the opening @a \<instance_rigidBody\> tag
		closeInstanceRigidBody() must be use to close the opened tags.
		@param id the id of ... */
		void openInstanceRigidBody();

		/** Closes the tag opened by openInstanceRigidBody()*/
		void closeInstanceRigidBody();

	private:
		TagCloser mCurrentInstanceRigidBodycloser;  //!< Used to close the current rigidBody instance


    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_INSTANCE_RIGID_BODY_H__
