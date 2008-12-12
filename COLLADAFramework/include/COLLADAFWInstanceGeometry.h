/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCEGEOMETRY_H__
#define __COLLADAFW_INSTANCEGEOMETRY_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWArrayPrimitiveType.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAFW
{
	/** Instantiates a geometry within a scene graph*/
	class InstanceGeometry 	
	{
	private:
		/**
		* The name attribute is the text string name of this element. 
		* Optional attribute.
		*/
		String mName;

		/** A text string containing the unique identifier of the element. This value must be
		unique within the instance document. Optional.
		*/
		String mSid;

		/** The unique id of the instantiated geometry.*/
		UniqueId mInstanciatedGeometryId;

	
	public:
		/** Constructor. Creates an instance geometry, that instantiates the geometry with UniqueId @a instanciatedGeometryId.
		@param instanceGeometry The UniqueId of the geometry instantiated.*/ 
		InstanceGeometry(UniqueId instanciatedGeometryId);

		virtual ~InstanceGeometry();

		/** Returns the name of the node*/
		const String& getName() const { return mName; }

		/** Sets the name of the node*/
		void getName(const String& name) { mName = name; }

		/** Returns the sid of the node*/
		const String& getSid() const { return mSid; }

		/** Sets the id of the node*/
		void getSid(const String& sid) { mSid = sid; }

		/** Returns the unique id of the instantiated geometry.*/
		const UniqueId& getInstanciatedGeometryId() const { return mInstanciatedGeometryId; }

	private:
        /** Disable default copy ctor. */
		InstanceGeometry( const InstanceGeometry& pre );
        /** Disable default assignment operator. */
		const InstanceGeometry& operator= ( const InstanceGeometry& pre );

	};

	typedef ArrayPrimitiveType<InstanceGeometry*> InstanceGeometryArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEGEOMETRY_H__
