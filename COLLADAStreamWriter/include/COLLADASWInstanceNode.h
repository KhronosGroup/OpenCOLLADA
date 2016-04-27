/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_NODE_H__
#define __COLLADASTREAMWRITER_INSTANCE_NODE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADABUURI.h"
#include "COLLADASWExtraTechnique.h"

namespace COLLADASW
{

    /** A class that holds informations of an @a \<instance_node\> element and writes it to stream. */
	class InstanceNode : public ElementWriter, public BaseExtraTechnique
    {

    private:

        /** The url to the node information (library_nodes) */
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
        InstanceNode ( StreamWriter* streamWriter, const URI& url, String sid="", String name="" )  
        : ElementWriter ( streamWriter )
        , mUrl ( url )
        , mSid ( sid ) 
        , mName ( name )
        {}

        /** Returns the url */
        const URI& getUrl() const
        {
            return mUrl;
        }

        /** Returns the sid */
        const String& getSid() const
        {
            return mSid;
        }

        /** Returns the name */
        const String& getName() const
        {
            return mName;
        }

        /** Write the instance node to the stream*/
        void add();

		/** Add Extra Techniques for LOD */
		void addExtraTechnique();

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_INSTANCE_NODE_H__
