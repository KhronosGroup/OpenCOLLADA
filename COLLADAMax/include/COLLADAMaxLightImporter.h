/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_LIGHTIMPORTER_H__
#define __COLLADAMAX_LIGHTIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"

class GenLight;

namespace COLLADAFW
{
	class Light;
};


namespace COLLADAMax
{

    /** Imports a light into the max scene. */
	class LightImporter : public ImporterBase 
	{
	private:
		/** The light to import.*/
		const COLLADAFW::Light* mLight;
	
	public:

        /** Constructor. */
		LightImporter( DocumentImporter* documentImporter, const COLLADAFW::Light* light );

        /** Destructor. */
		virtual ~LightImporter();

		/** Performs the import of the light.
		@return True on success, false otherwise.*/
		bool import();

		/** Creates a new light from @a camera and returns a pointer to it. */
		LightObject* createLight( const COLLADAFW::Light* light );

		/** creates and adds an ambient light to the document. Since such a light is global 
		i does not have to added to the scene.*/
		void createAndAddAmbientLight( const COLLADAFW::Light* light );

	private:

        /** Disable default copy ctor. */
		LightImporter( const LightImporter& pre );

        /** Disable default assignment operator. */
		const LightImporter& operator= ( const LightImporter& pre );

		LightObject* createSkyLight( const COLLADAFW::Light* light, const SkyLightParameters* skyLightParameters );

		GenLight* createGenericLight( const COLLADAFW::Light* light );
	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_LIGHTIMPORTER_H__
