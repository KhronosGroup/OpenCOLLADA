/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADADH_BASELOADER_H__
#define __COLLADADH_BASELOADER_H__

#include "COLLADADHPrerequisites.h"
#include "COLLADAFWUniqueId.h"

class domCOLLADA;

namespace COLLADADH
{
	class Loader;

    /** Base loader class, which holds a pointer to the dae document. */
	class BaseLoader 	
    {
	private:
	
        /** The collada root element. */
        domCOLLADA* mDomCollada;

		/** The collada loader */
		Loader* mColladaLoader;


	public:

        /** Constructor. */
        BaseLoader ( Loader* colladaLoader, domCOLLADA* colladaRoot );

        /** Destructor. */
        virtual ~BaseLoader();

        /** Returns a pointer to the collada root element. */
        domCOLLADA* getDomCollada ();

        /** Returns a const pointer to the root element. */
        const domCOLLADA* getDomCollada () const;

	protected:
		/** Returns a pointer to the collada loader. */
		Loader* getColladaLoader () { return mColladaLoader; }

		/** Returns a const pointer to the collada document. */
		const Loader* getColladaLoader () const { return mColladaLoader; }

		/** Returns the COLLADAFW::UniqueId of @a element. If it has been passed to this method before, by a 
		loader that belongs to the same Collada Loader, the same 
		COLLADAFW::UniqueId will be returned, if not, a new one is created.
		@param element The element to get the COLLADAFW::UniqueId for
		@param classId The COLLADAFW::ClassId of the object that will be created for @a element.
		@return The elements COLLADAFW::UniqueId */
		const COLLADAFW::UniqueId& getUniqueId(daeElement* element, COLLADAFW::ClassId classId);



    private:

        /** Disable default copy ctor. */
		BaseLoader( const BaseLoader& pre );

        /** Disable default assignment operator. */
		const BaseLoader& operator= ( const BaseLoader& pre );

	};
	
} // namespace COLLADADH

#endif // __COLLADADH_BASELOADER_H__
