/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYANIMATIONSLOADER_H__
#define __COLLADASAXFWL_LIBRARYANIMATIONSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSourceArrayLoader.h"

namespace COLLADAFW
{
    class AnimationCurve;
    class AnimationList;
}


namespace COLLADASaxFWL
{

    /** Loads all the animations the the library animations */
	class LibraryAnimationsLoader : public SourceArrayLoader
	{
	private:

		/** Maps strings to unique ids.*/
		typedef std::map< String /*samplerId*/,AnimationInfo > StringAnimationInfoMap;

	private:

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

        /** Pretty-print name for this animation. Optional. */
        String mName; 

        /** The animation curve currently being filled. Is not null only inside a sampler element.*/
		COLLADAFW::AnimationCurve* mCurrentAnimationCurve;

		/** Maps the id of sampler to the unique id of the frame work animation created for this sampler.*/
		StringAnimationInfoMap mSamplerIdAnimationInfoMap;
	
		/** True, if the array currently parsed is an IDREF_array, supposed to contain the interpolation data.*/
		bool mCurrentlyParsingInterpolationArray;

		/** The animation info of the currently being parsed sampler.*/
		AnimationInfo* mCurrentAnimationInfo;

		/** True, if at least one interpolation type of the current animation curve is bezier or hermite, 
		false otherwise. Use this to decide if we can clear the tangents. Is set to true when starting
		to parse a sampler. This allows to not store tangents, if set to false.*/
		bool mCurrentAnimationCurveRequiresTangents;

		/** Used to control if validate function should report errors
		or do its job silently */
		bool mVerboseValidate;

        /* internal count of animation processed, used to build up a default id */
        size_t mProcessedCount;
	public:

        /** Constructor. */
		LibraryAnimationsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryAnimationsLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

		/** Searches for the animation info of animation created for the COLLADA sampler with id @a samplerId.
		If it could not be found, an invalid Unique id is returned.*/
		AnimationInfo* getAnimationInfoBySamplerId( const String& samplerId);

        /** Determines the interpolation with @a name.*/
        static COLLADAFW::AnimationCurve::InterpolationType getInterpolationTypeByString( const ParserString& string);

		/** Cleans up everything and gives control to calling file part loader.*/
		bool end__library_animations();

		bool begin__source( const source__AttributeData& attributes );

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
		bool end__input____InputLocal() {return true;}

		virtual bool begin__Name_array( const Name_array__AttributeData& attributeData );
		virtual bool end__Name_array();
		virtual bool data__Name_array( const ParserString* data, size_t length );

	private:

        /**
        * The original object id, if it in the original file format exist. 
        */
        const COLLADAFW::String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const COLLADAFW::String& val ) { mOriginalId = val; }

        /** Pretty-print name for this animation. Optional. */
        const COLLADAFW::String& getName () const { return mName; }

        /** Pretty-print name for this animation. Optional. */
        void setName ( const COLLADAFW::String& val ) { mName = val; }

        /** Disable default copy ctor. */
		LibraryAnimationsLoader( const LibraryAnimationsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryAnimationsLoader& operator= ( const LibraryAnimationsLoader& pre );
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYANIMATIONSLOADER_H__
