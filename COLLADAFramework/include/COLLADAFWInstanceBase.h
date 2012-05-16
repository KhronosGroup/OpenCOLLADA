/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCEBASE_H__
#define __COLLADAFW_INSTANCEBASE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

    /** Base class for the instance classes. */
    template<ClassId classId>
	class InstanceBase : public ObjectTemplate<classId>
    {
	private:
	
        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        String mName;

        /** The unique id of the instantiated object.*/
        UniqueId mInstanciatedObjectId;

	public:

        /** Constructor. Creates an instance of an object with UniqueId @a instanciatedObjectId.
        @param instanciatedObjectId The UniqueId of the object instantiated.*/ 
        InstanceBase ( const UniqueId& uniqueId, const UniqueId& instanciatedObjectId )
            : ObjectTemplate<classId>(uniqueId)
            , mInstanciatedObjectId (instanciatedObjectId ) 
        {}

        /** Destructor. */
        virtual ~InstanceBase() {}

        /** Returns the name of the node*/
        const String& getName () const { return mName; }

        /** Sets the name of the node*/
        void setName ( const String& name ) { mName = name; }

        /** Returns the unique id of the instantiated object.*/
        const UniqueId& getInstanciatedObjectId() const { return mInstanciatedObjectId; }

        /** Sets the unique id of the instantiated object.*/
        void setInstanciatedObjectId ( const UniqueId& instanciatedObjectId ) { mInstanciatedObjectId = instanciatedObjectId; }

        virtual InstanceBase* clone() const { return new InstanceBase(*this); }
	};

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEBASE_H__
