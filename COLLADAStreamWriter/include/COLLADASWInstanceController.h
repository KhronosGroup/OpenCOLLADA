/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_CONTROLLER_H__
#define __COLLADASTREAMWRITER_INSTANCE_CONTROLLER_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWBindMaterial.h"
#include "COLLADABUURI.h"

#include <string>
#include <vector>

namespace COLLADASW
{

    /** Class to write an @a \<instance_geometry\> element to the stream*/
    class InstanceController : public ElementWriter
    {

	public:
		typedef std::vector<URI> SkeletonUrlList;

    private:

        /** The material to bind. */
        BindMaterial mBindMaterial;

        /** The URL of the location of the object to instantiate.*/
        URI mUrl;

        /** List of the URLs in the \<skeleton\> elements. */
		SkeletonUrlList mSkeletonUrlList;

    public:

        /** Constructor
        @param The stream the instance controller should be written to
        */
        InstanceController ( StreamWriter* streamWriter ) 
            : ElementWriter ( streamWriter )
            , mBindMaterial ( streamWriter ) 
            , mUrl()
        {}

        /** Destructor*/
        ~InstanceController(){}

        /** Sets the url of the instance geometry*/
        void setUrl ( const URI& url )
        {
            mUrl=url;
        }

        /** Returns the url of the instance geometry*/
        const URI& getUrl()const
        {
            return mUrl;
        }

        BindMaterial& getBindMaterial()
        {
            return mBindMaterial;
        }

        /**
         * Get the id of the skeleton.
         * @return COLLADASW::String The skeleton id.
         */
        const SkeletonUrlList& getSkeletonUrlList() const { return mSkeletonUrlList; }
        /**
         * Adds a skeleton to the \<instance_controller\> element.
         * @param url The url the skeleton points to.
         */
        void addSkeleton(const URI& url) { mSkeletonUrlList.push_back(url); }

        /** Adds the instance geometry to the stream*/
        void add();

    };


} //namespace COLLADASW




#endif //__COLLADASTREAMWRITER_INSTANCE_CONTROLLER_H__

