/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYPHYSICSSCENESLOADER_H__
#define __COLLADASAXFWL_LIBRARYPHYSICSSCENESLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLPhysicsSceneLoader.h"
#include "COLLADASaxFWLXmlTypes.h"


namespace COLLADAFW
{	
	class PhysicsScene;
}

namespace COLLADASaxFWL
{

	/** Stores data of library Physics scenes in intermediate model. This data is used in a post process to fill
	the framework physics scene.*/
	class LibraryPhysicsScenesLoader : public FilePartLoader, public PhysicsSceneLoader
	{
	private:
		/** The physicsScene currently being parsed.*/
		COLLADAFW::PhysicsScene* mCurrentPhysicsScene;

		/** Specifies the type of the parent of a value type element <bool>, <int>, <float>, <SIDREF>.*/
		//ValueElementParentType mValueElementParentType;

		
	public:

        /** Constructor. */
		LibraryPhysicsScenesLoader(IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryPhysicsScenesLoader();

		/** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

		/** finishes loading a library physics scenes*/
		virtual bool end__library_physics_scenes();

		virtual bool begin__physics_scene( const physics_scene__AttributeData& attributeData );
		
		virtual bool end__physics_scene();

		
		/*virtual bool begin__float();
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
		virtual bool data__SIDREF( const ParserChar* value, size_t length );*/


	private:

        /** Disable default copy ctor. */
		LibraryPhysicsScenesLoader( const LibraryPhysicsScenesLoader& pre );

        /** Disable default assignment operator. */
		const LibraryPhysicsScenesLoader& operator= ( const LibraryPhysicsScenesLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYPHYSICSSCENESLOADER_H__
