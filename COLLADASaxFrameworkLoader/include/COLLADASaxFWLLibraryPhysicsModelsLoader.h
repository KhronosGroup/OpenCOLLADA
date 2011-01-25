/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYPHYSICSMODELSLOADER_H__
#define __COLLADASAXFWL_LIBRARYPHYSICSMODELSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLPhysicsModelLoader.h"
#include "COLLADASaxFWLXmlTypes.h"


namespace COLLADAFW
{	
	class PhysicsModel;
}

namespace COLLADASaxFWL
{

	/** Stores data of library Physics Models in intermediate model. This data is used in a post process to fill
	the framework physics Model.*/
	class LibraryPhysicsModelsLoader : public PhysicsModelLoader , public FilePartLoader
	{
	private:
		/** The physicsModel currently being parsed.*/
		//COLLADAFW::PhysicsModel* mCurrentPhysicsModel;

			
	public:

        /** Constructor. */
		LibraryPhysicsModelsLoader(IFilePartLoader* callingFilePartLoader);

        /** Destructor. */
		virtual ~LibraryPhysicsModelsLoader();

		/** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

		/** finishes loading a library physics Models*/
		virtual bool end__library_physics_models();

		virtual bool begin__physics_model( const physics_model__AttributeData& attributeData );
		
		virtual bool end__physics_model();

		
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
		LibraryPhysicsModelsLoader( const LibraryPhysicsModelsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryPhysicsModelsLoader& operator= ( const LibraryPhysicsModelsLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYPHYSICSModelSLOADER_H__
