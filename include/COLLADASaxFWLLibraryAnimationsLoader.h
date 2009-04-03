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
#include "COLLADAFWAnimationList.h"


namespace COLLADASaxFWL
{

    /** Loads all the animations the the library animations */
	class LibraryAnimationsLoader 	: public SourceArrayLoader
	{
	private:

		struct AnimationInfo
		{
			static const AnimationInfo INVALID;
			/** The unique id of the animation*/
			COLLADAFW::UniqueId uniqueId;

			COLLADAFW::AnimationList::AnimationClass animationClass;
		};

		/** Maps strings to unique ids.*/
		typedef std::map< String /*samplerId*/,AnimationInfo > StringAnimationInfoMap;

	private:
		/** The animation curve currently being filled. Is none null only inside a sampler element.*/
		COLLADAFW::AnimationCurve* mCurrentAnimationCurve;

		/** Maps the id of sampler to the unique id of the frame work animation created for this sampler.*/
		StringAnimationInfoMap mSamplerIdAnimationInfoMap;
	
		/** True, if the array currently parsed is an IDREF_array, supposed to contain the interpolation data.*/
		bool mCurrentlyParsingInterpolationArray;

		/** The animation info of the currently being parsed sampler.*/
		AnimationInfo* mCurrentAnimationInfo;

	public:
		/** Determines the interpolation with @a name.*/
		static COLLADAFW::AnimationCurve::InterpolationType getInterpolationTypeByString( const ParserString& string);

	public:

        /** Constructor. */
		LibraryAnimationsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryAnimationsLoader();

		/** Searches for the animation info of animation created for the COLLADA sampler with id @a samplerId.
		If it could not be found, an invalid Unique id is returned.*/
		LibraryAnimationsLoader::AnimationInfo* getAnimationInfoBySamplerId( const String& samplerId);


		/** Cleans up everything and gives control to calling file part loader.*/
		bool end__library_animations();

		bool begin__source( const source__AttributeData& attributes );

		//------------------------------
		bool end__source();

		/** .*/
		bool begin__animation( const animation__AttributeData& attributeData );

		/** .*/
		bool end__animation();

		/** Create new animation.*/
		bool begin__sampler( const sampler__AttributeData& attributeData );
		
		/** .*/
		bool end__sampler();

		virtual bool begin__channel( const channel__AttributeData& attributeData );

		virtual bool end__channel();

		/** Evaluate the semantic and assign the corresponding sources to the current animation curve.*/
		bool begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData );

		/** We don't need to do anything here.*/
		bool end__input____InputLocal() { SaxVirtualFunctionTest(end__input____InputLocal()); return true;}

		virtual bool begin__Name_array( const Name_array__AttributeData& attributeData );
		virtual bool end__Name_array();
		virtual bool data__Name_array( const ParserString* data, size_t length );




	private:

        /** Disable default copy ctor. */
		LibraryAnimationsLoader( const LibraryAnimationsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryAnimationsLoader& operator= ( const LibraryAnimationsLoader& pre );
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYANIMATIONSLOADER_H__
