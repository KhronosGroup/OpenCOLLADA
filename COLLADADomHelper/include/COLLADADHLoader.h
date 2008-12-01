/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_LOADER_H__
#define __COLLADA_LOADER_H__

#include "COLLADADHPrerequisites.h"

#include "COLLADAFWILoader.h"
#include "COLLADAFWLoaderUtils.h"
#include "COLLADAFWUniqueId.h"

class daeElement;
class domCOLLADA;

namespace COLLADAFW
{
	class IWriter;
}

namespace COLLADADH
{
	class Loader : public COLLADAFW::ILoader 
	{
	private:
		typedef std::map<daeElement*, COLLADAFW::UniqueId> DEAElementUniqueIdMap;

	private:
		/** The collada element of the parsed collada document. */
		domCOLLADA* mDomCollada;

		/** Loader utils that will help us to fill the model.*/
		COLLADAFW::LoaderUtils mLoaderUtil;

		/** The writer that will be fed by this loader.*/
		COLLADAFW::IWriter* mWriter;

		/** Maps each already processed dae element to its COLLADAFW::UniqueId. */
		DEAElementUniqueIdMap mDEAElementUniqueIdMap;
	
	public:

        /** Constructor. */
		Loader();

        /** Destructor. */
		virtual ~Loader();

		/** Starts loading the model and feeds the writer with data.
		@param fileName The name of the fills that should be loaded.
		@param writer The writer that should be fed with data.
		@return True, if loading succeeded, false otherwise.*/
		virtual bool loadDocument(const String& fileName, COLLADAFW::IWriter* writer);

		/** Returns the COLLADAFW::UniqueId of @a element. If it has been passed to this method before, the same 
		COLLADAFW::UniqueId will be returned, if not, a new one is created.
		@param element The element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& getUniqueId(daeElement* element, COLLADAFW::ClassId classId);


	private:

        /** Disable default copy ctor. */
		Loader( const Loader& pre );

        /** Disable default assignment operator. */
		const Loader& operator= ( const Loader& pre );

		/** Loads the visual scenes of the current document.
		@return True on success, false otherwise.*/
		bool loadVisualScenes ();

        /** Loads the geometries of the current document.
        @return True on success, false otherwise.*/
        bool loadGeometries ();

	};

} // namespace COLLADA

#endif // __COLLADA_LOADER_H__
