/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYANIMATIONSLOADER_H__
#define __COLLADASAXFWL_LIBRARYANIMATIONSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSourceArrayLoader.h"
#include "COLLADAFWAnimationCurve.h"


namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class LibraryAnimationsLoader 	: public SourceArrayLoader
	{
	private:

	private:
		/** The animation curve currently being filled. Is none null only inside a sampler element.*/
		COLLADAFW::AnimationCurve* mCurrentAnimationCurve;
	
	public:

        /** Constructor. */
		LibraryAnimationsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryAnimationsLoader();


		/** Cleans up everything and gives control to calling file part loader.*/
		bool end__library_animations();

		bool begin__animation__source( const animation__source__AttributeData& attributes );

		//------------------------------
		bool end__animation__source(  );

		/** .*/
		bool begin__animation( const animation__AttributeData& attributeData );

		/** .*/
		bool end__animation();

		/** Create new animation.*/
		bool begin__sampler( const sampler__AttributeData& attributeData );
		
		/** .*/
		bool end__sampler();

		/** Evaluate the semantic and assign the corresponding sources to the current animation curve.*/
		bool begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData );

		/** We don't need to do anything here.*/
		bool end__input____InputLocal() { SaxVirtualFunctionTest(end__input____InputLocal()); return true;}



	private:

        /** Disable default copy ctor. */
		LibraryAnimationsLoader( const LibraryAnimationsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryAnimationsLoader& operator= ( const LibraryAnimationsLoader& pre );
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYANIMATIONSLOADER_H__
