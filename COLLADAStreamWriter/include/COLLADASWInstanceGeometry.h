/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_INSTANCE_GEOMETRY_H__
#define __COLLADASTREAMWRITER_INSTANCE_GEOMETRY_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWBindMaterial.h"
#include "COLLADABUURI.h"

#include <string>

namespace COLLADASW
{

    /** Class to write an @a \<instance_geometry\> element to the stream*/
	class InstanceGeometry : public ElementWriter
    {

    private:

        /** To bind the materials. */
        BindMaterial mBindMaterial;

        /** The URL of the location of the object to instantiate.*/
        URI mUrl;

		/** A text string containing the name of the <instance_geometry> element. Optional. */
		String mName;

		/** A text string containing the unique identifier of the <instance_geometry>
		element. This value must be unique within the instance document.
		Optional. */
		String mId;

	public:

		/** Constructor
		@param The stream the instance geometry should be written to
		*/
		InstanceGeometry ( StreamWriter * streamWriter ) 
            : ElementWriter ( streamWriter ), mBindMaterial ( streamWriter ) {}

		/** Destructor*/
		~InstanceGeometry(){}

        /** Sets the url of the instance geometry*/
        void setUrl ( const URI& url )
        {
            mUrl=url;
        }

        /** Returns the url of the instance geometry*/
        const URI& getUrl()
        {
            return mUrl;
        }

		/** Returns a reference to the instance geometry id*/
		const String& getId() const 
		{
			return mId;
		}

		/** Sets the id of the element*/
		void setId(const String& id)
		{
			mId = id;
		}

		/** A text string containing the name of the <instance_geometry> element. Optional. */
		const String getName() const 
		{ 
			return mName; 
		}

		/** A text string containing the name of the <instance_geometry> element. Optional. */
		void setName(const String name) 
		{ 
			mName = name; 
		}

        BindMaterial& getBindMaterial()
        {
            return mBindMaterial;
        }

        /** Adds the instance geometry to the stream*/
        void add();

    };


} //namespace COLLADASW




#endif //__COLLADASTREAMWRITER_INSTANCE_GEOMETRY_H__

