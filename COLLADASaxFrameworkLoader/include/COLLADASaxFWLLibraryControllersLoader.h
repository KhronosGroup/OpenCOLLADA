/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYCONTROLLERSLOADER_H__
#define __COLLADASAXFWL_LIBRARYCONTROLLERSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSourceArrayLoader.h"


namespace COLLADAFW
{
	class SkinControllerData;
}

namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class LibraryControllersLoader : public SourceArrayLoader 
	{
	private:
		/** Specifies the parent of a possible input element.*/
		enum InputParent
		{
			INPUT_PARENT_UNKNOWN,
			INPUT_PARENT_JOINTS,
			INPUT_PARENT_VERTEX_WEIGHTS
		};

		typedef std::map< String /*Id of the name array*/,  StringList> StringListMap;

	private:
		/** The original object id, if it in the original file format exist. */
		String mOriginalId;

		/** The id of the current controller.*/
		String mCurrentControllerId;

		/** The name of the current controller.*/
		String mCurrentControllerName;

		/** The SkinControllerData currently being filled. */
		COLLADAFW::SkinControllerData* mCurrentSkinControllerData;

		/** The current parent element of a possible input element. Unknown if input is 
		currently not allowed.*/
		InputParent mCurrentInputParent;

		/** The sids of the joints of the current skin controller.*/
		StringList *mJointSids;

		/** Maps ids of name array to the list of name in the name array.*/
		StringListMap mJointSidsMap;

		/** The expected joints/vertex pair count of the current skin data.*/
		size_t mCurrentJointsVertexPairCount;

		/** The offset of the joints in the current vertex_weights element.*/
		uint64 mJointOffset;

		/** The offset of the weights in the current vertex_weights element.*/
		uint64 mWeightsOffset;

		/** The largest offset of the inputs in the current vertex_weights element.*/
		uint64 mCurrentMaxOffset;

		/** The current offset while parsing a v element.*/
		uint64 mCurrentOffset;

	public:

        /** Constructor. */
		LibraryControllersLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryControllersLoader();

		/** Write the indices of the v element into the framework.*/
		bool writeVIndices ( const sint64* data, size_t length );

		virtual bool end__library_controllers( );


		virtual bool begin__controller( const controller__AttributeData& attributeData );
		virtual bool end__controller();


		virtual bool begin__skin( const skin__AttributeData& attributeData );
		virtual bool end__skin();

		bool begin__source( const source__AttributeData& attributes );
		bool end__source();


		virtual bool begin__joints();
		virtual bool end__joints();

		/** Evaluate the semantic and assign the corresponding sources to the current animation curve.*/
		bool begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData );

		/** We don't need to do anything here.*/
		bool end__input____InputLocal() { SaxVirtualFunctionTest(end__input____InputLocal()); return true;}


		virtual bool begin__vertex_weights( const vertex_weights__AttributeData& attributeData );
		virtual bool end__vertex_weights();

		virtual bool begin__input____InputLocalOffset( const input____InputLocalOffset__AttributeData& attributeData );
		virtual bool end__input____InputLocalOffset();

		virtual bool begin__vcount();
		virtual bool end__vcount();
		virtual bool data__vcount( const unsigned long long*, size_t length );


		virtual bool begin__v();
		virtual bool end__v();
		virtual bool data__v( const sint64* data, size_t length );


		virtual bool begin__Name_array( const Name_array__AttributeData& attributeData );
		virtual bool end__Name_array();
		virtual bool data__Name_array( const ParserString* data, size_t length );


	private:

        /** Disable default copy ctor. */
		LibraryControllersLoader( const LibraryControllersLoader& pre );

        /** Disable default assignment operator. */
		const LibraryControllersLoader& operator= ( const LibraryControllersLoader& pre );
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYCONTROLLERSLOADER_H__
