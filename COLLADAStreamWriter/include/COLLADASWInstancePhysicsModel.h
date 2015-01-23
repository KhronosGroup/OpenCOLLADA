/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_PHYSICS_MODEL_H__
#define __COLLADASTREAMWRITER_INSTANCE_PHYSICS_MODEL_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADABUURI.h"

namespace COLLADASW
{

    /** A class that holds informations of an @a \<instance_physics_model\> element and writes it to stream. */
    class InstancePhysicsModel : public ElementWriter
    {

    private:

        /** The url to the physic model information (library_physics_models) */
        URI mUrl;
        String mSid;
        String mName;

    public:
        /** 
         * Constructor
         * @param url The url
         * @param sid The sid
         * @param name The name
        */
		InstancePhysicsModel(StreamWriter* streamWriter, const URI& url, String sid = "", String name = "")
        : ElementWriter ( streamWriter )
        , mUrl ( url )
        , mSid ( sid ) 
        , mName ( name )
        {}

		/** Writes the opening @a \<instance_physic_model\> tag.
		closeInstancePhysicsModel() must be use to close the opened tags.
		@param id the id of the visual scene*/
		void openInstancePhysicsModel(const String& nodeId = EMPTY_STRING, const String& nodeName = EMPTY_STRING);

		/** Closes the tag opened by openInstancePhysicModel()*/
		void closeInstancePhysicsModel();

	private:
		TagCloser mCurrentInstancePhysicsModelCloser;  //!< Used to close the current InstancePhysicsModel

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_INSTANCE_PHYSICS_MODEL_H__
