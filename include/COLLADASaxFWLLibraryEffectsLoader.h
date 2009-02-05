/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYEFFECTSSLOADER_H__
#define __COLLADASAXFWL_LIBRARYEFFECTSSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"

namespace COLLADAFW
{
	class Effect;
}



namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class LibraryEffectsLoader : public FilePartLoader 
	{
	private:
		enum Profile
		{
			PROFILE_BRIDGE,
			PROFILE_CG,
			PROFILE_GLES,
			PROFILE_GLES2,
			PROFILE_GLSL,
			PROFILE_COMMON,
			PROFILE_UNKNOWN
		};

	private:
		/** The effect currently being imported.*/
		COLLADAFW::Effect* mCurrentEffect;

		/** The current profile.*/
		Profile mCurrentProfile;
	
	public:

        /** Constructor. */
		LibraryEffectsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryEffectsLoader();

		/** Creates a new current effect.*/
		virtual bool begin__effect( const effect__AttributeData& attributeData );

		/** Sends current material to the writer an deletes it afterwards.*/
		virtual bool end__effect();

		/** Finishes loading a library effects.*/
		virtual bool end__library_effects();


	private:

        /** Disable default copy ctor. */
		LibraryEffectsLoader( const LibraryEffectsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryEffectsLoader& operator= ( const LibraryEffectsLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYEFFECTSSLOADER_H__
