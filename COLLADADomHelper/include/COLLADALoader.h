/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_LOADER_H__
#define __COLLADA_LOADER_H__

#include "HelperPrerequisites.h"
#include "COLLADAFWILoader.h"
#include "COLLADAFWLoaderUtils.h"

#include <dae.h>
#include <dom/domCOLLADA.h>


namespace COLLADAFW
{
	class IWriter;
}

namespace COLLADADH
{
	class Loader : public COLLADAFW::ILoader 
	{
	private:
		/** The DAE class is the core interface via which you interact with the DOM. */
		DAE mDae;

		/** The collada element of the parsed collada document. */
		domCOLLADA* mDomCollada;

		/** Loader utils that will help us to fill the model.*/
		COLLADAFW::LoaderUtils mLoaderUtil;

		/** The writer that will be fed by this loader.*/
		COLLADAFW::IWriter* mWriter;
	
	public:
		Loader();
		virtual ~Loader();

		/** Starts loading the model and feeds the writer with data.
		@param fileName The name of the fills that should be loaded.
		@param writer The writer that should be fed with data.
		@return True, if loading succeeded, false otherwise.*/
		virtual bool loadDocument(const String& fileName, COLLADAFW::IWriter* writer);


	private:
        /** Disable default copy ctor. */
		Loader( const Loader& pre );
        /** Disable default assignment operator. */
		const Loader& operator= ( const Loader& pre );

		/** Loads the visual scenes of the current document.
		@return True on success, false otherwise.*/
		bool loadVisualScenes();

	};

} // namespace COLLADA

#endif // __COLLADA_LOADER_H__
